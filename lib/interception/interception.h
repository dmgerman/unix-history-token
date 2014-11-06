begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- interception.h ------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is a part of AddressSanitizer, an address sanity checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Machinery for providing replacements/wrappers for system functions.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INTERCEPTION_H
end_ifndef

begin_define
define|#
directive|define
name|INTERCEPTION_H
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Interception doesn't work on this operating system."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
end_include

begin_comment
comment|// These typedefs should be used only in the interceptor definitions to replace
end_comment

begin_comment
comment|// the standard system types (e.g. SSIZE_T instead of ssize_t)
end_comment

begin_typedef
typedef|typedef
name|__sanitizer
operator|::
name|uptr
name|SIZE_T
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|__sanitizer
operator|::
name|sptr
name|SSIZE_T
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|__sanitizer
operator|::
name|sptr
name|PTRDIFF_T
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|__sanitizer
operator|::
name|s64
name|INTMAX_T
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|__sanitizer
operator|::
name|OFF_T
name|OFF_T
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|__sanitizer
operator|::
name|OFF64_T
name|OFF64_T
expr_stmt|;
end_typedef

begin_comment
comment|// How to add an interceptor:
end_comment

begin_comment
comment|// Suppose you need to wrap/replace system function (generally, from libc):
end_comment

begin_comment
comment|//      int foo(const char *bar, double baz);
end_comment

begin_comment
comment|// You'll need to:
end_comment

begin_comment
comment|//      1) define INTERCEPTOR(int, foo, const char *bar, double baz) { ... } in
end_comment

begin_comment
comment|//         your source file. See the notes below for cases when
end_comment

begin_comment
comment|//         INTERCEPTOR_WITH_SUFFIX(...) should be used instead.
end_comment

begin_comment
comment|//      2) Call "INTERCEPT_FUNCTION(foo)" prior to the first call of "foo".
end_comment

begin_comment
comment|//         INTERCEPT_FUNCTION(foo) evaluates to "true" iff the function was
end_comment

begin_comment
comment|//         intercepted successfully.
end_comment

begin_comment
comment|// You can access original function by calling REAL(foo)(bar, baz).
end_comment

begin_comment
comment|// By default, REAL(foo) will be visible only inside your interceptor, and if
end_comment

begin_comment
comment|// you want to use it in other parts of RTL, you'll need to:
end_comment

begin_comment
comment|//      3a) add DECLARE_REAL(int, foo, const char*, double) to a
end_comment

begin_comment
comment|//          header file.
end_comment

begin_comment
comment|// However, if the call "INTERCEPT_FUNCTION(foo)" and definition for
end_comment

begin_comment
comment|// INTERCEPTOR(..., foo, ...) are in different files, you'll instead need to:
end_comment

begin_comment
comment|//      3b) add DECLARE_REAL_AND_INTERCEPTOR(int, foo, const char*, double)
end_comment

begin_comment
comment|//          to a header file.
end_comment

begin_comment
comment|// Notes: 1. Things may not work properly if macro INTERCEPTOR(...) {...} or
end_comment

begin_comment
comment|//           DECLARE_REAL(...) are located inside namespaces.
end_comment

begin_comment
comment|//        2. On Mac you can also use: "OVERRIDE_FUNCTION(foo, zoo)" to
end_comment

begin_comment
comment|//           effectively redirect calls from "foo" to "zoo". In this case
end_comment

begin_comment
comment|//           you aren't required to implement
end_comment

begin_comment
comment|//           INTERCEPTOR(int, foo, const char *bar, double baz) {...}
end_comment

begin_comment
comment|//           but instead you'll have to add
end_comment

begin_comment
comment|//           DECLARE_REAL(int, foo, const char *bar, double baz) in your
end_comment

begin_comment
comment|//           source file (to define a pointer to overriden function).
end_comment

begin_comment
comment|//        3. Some Mac functions have symbol variants discriminated by
end_comment

begin_comment
comment|//           additional suffixes, e.g. _$UNIX2003 (see
end_comment

begin_comment
comment|//           https://developer.apple.com/library/mac/#releasenotes/Darwin/SymbolVariantsRelNotes/index.html
end_comment

begin_comment
comment|//           for more details). To intercept such functions you need to use the
end_comment

begin_comment
comment|//           INTERCEPTOR_WITH_SUFFIX(...) macro.
end_comment

begin_comment
comment|// How it works:
end_comment

begin_comment
comment|// To replace system functions on Linux we just need to declare functions
end_comment

begin_comment
comment|// with same names in our library and then obtain the real function pointers
end_comment

begin_comment
comment|// using dlsym().
end_comment

begin_comment
comment|// There is one complication. A user may also intercept some of the functions
end_comment

begin_comment
comment|// we intercept. To resolve this we declare our interceptors with __interceptor_
end_comment

begin_comment
comment|// prefix, and then make actual interceptors weak aliases to __interceptor_
end_comment

begin_comment
comment|// functions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This is not so on Mac OS, where the two-level namespace makes
end_comment

begin_comment
comment|// our replacement functions invisible to other libraries. This may be overcomed
end_comment

begin_comment
comment|// using the DYLD_FORCE_FLAT_NAMESPACE, but some errors loading the shared
end_comment

begin_comment
comment|// libraries in Chromium were noticed when doing so.
end_comment

begin_comment
comment|// Instead we create a dylib containing a __DATA,__interpose section that
end_comment

begin_comment
comment|// associates library functions with their wrappers. When this dylib is
end_comment

begin_comment
comment|// preloaded before an executable using DYLD_INSERT_LIBRARIES, it routes all
end_comment

begin_comment
comment|// the calls to interposed functions done through stubs to the wrapper
end_comment

begin_comment
comment|// functions.
end_comment

begin_comment
comment|// As it's decided at compile time which functions are to be intercepted on Mac,
end_comment

begin_comment
comment|// INTERCEPT_FUNCTION() is effectively a no-op on this system.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|// For __DARWIN_ALIAS_C().
end_comment

begin_comment
comment|// Just a pair of pointers.
end_comment

begin_struct
struct|struct
name|interpose_substitution
block|{
specifier|const
name|uptr
name|replacement
decl_stmt|;
specifier|const
name|uptr
name|original
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// For a function foo() create a global pair of pointers { wrap_foo, foo } in
end_comment

begin_comment
comment|// the __DATA,__interpose section.
end_comment

begin_comment
comment|// As a result all the calls to foo() will be routed to wrap_foo() at runtime.
end_comment

begin_define
define|#
directive|define
name|INTERPOSER
parameter_list|(
name|func_name
parameter_list|)
value|__attribute__((used)) \ const interpose_substitution substitution_##func_name[] \     __attribute__((section("__DATA, __interpose"))) = { \     { reinterpret_cast<const uptr>(WRAP(func_name)), \       reinterpret_cast<const uptr>(func_name) } \ }
end_define

begin_comment
comment|// For a function foo() and a wrapper function bar() create a global pair
end_comment

begin_comment
comment|// of pointers { bar, foo } in the __DATA,__interpose section.
end_comment

begin_comment
comment|// As a result all the calls to foo() will be routed to bar() at runtime.
end_comment

begin_define
define|#
directive|define
name|INTERPOSER_2
parameter_list|(
name|func_name
parameter_list|,
name|wrapper_name
parameter_list|)
value|__attribute__((used)) \ const interpose_substitution substitution_##func_name[] \     __attribute__((section("__DATA, __interpose"))) = { \     { reinterpret_cast<const uptr>(wrapper_name), \       reinterpret_cast<const uptr>(func_name) } \ }
end_define

begin_define
define|#
directive|define
name|WRAP
parameter_list|(
name|x
parameter_list|)
value|wrap_##x
end_define

begin_define
define|#
directive|define
name|WRAPPER_NAME
parameter_list|(
name|x
parameter_list|)
value|"wrap_"#x
end_define

begin_define
define|#
directive|define
name|INTERCEPTOR_ATTRIBUTE
end_define

begin_define
define|#
directive|define
name|DECLARE_WRAPPER
parameter_list|(
name|ret_type
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_elif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_DLL
argument_list|)
end_if

begin_comment
comment|// DLL CRT
end_comment

begin_define
define|#
directive|define
name|WRAP
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|WRAPPER_NAME
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_define
define|#
directive|define
name|INTERCEPTOR_ATTRIBUTE
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// Static CRT
end_comment

begin_define
define|#
directive|define
name|WRAP
parameter_list|(
name|x
parameter_list|)
value|wrap_##x
end_define

begin_define
define|#
directive|define
name|WRAPPER_NAME
parameter_list|(
name|x
parameter_list|)
value|"wrap_"#x
end_define

begin_define
define|#
directive|define
name|INTERCEPTOR_ATTRIBUTE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DECLARE_WRAPPER
parameter_list|(
name|ret_type
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|extern "C" ret_type func(__VA_ARGS__);
end_define

begin_define
define|#
directive|define
name|DECLARE_WRAPPER_WINAPI
parameter_list|(
name|ret_type
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|extern "C" __declspec(dllimport) ret_type __stdcall func(__VA_ARGS__);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WRAP
parameter_list|(
name|x
parameter_list|)
value|__interceptor_ ## x
end_define

begin_define
define|#
directive|define
name|WRAPPER_NAME
parameter_list|(
name|x
parameter_list|)
value|"__interceptor_" #x
end_define

begin_define
define|#
directive|define
name|INTERCEPTOR_ATTRIBUTE
value|__attribute__((visibility("default")))
end_define

begin_define
define|#
directive|define
name|DECLARE_WRAPPER
parameter_list|(
name|ret_type
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|extern "C" ret_type func(__VA_ARGS__) \     __attribute__((weak, alias("__interceptor_" #func), visibility("default")));
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_define
define|#
directive|define
name|PTR_TO_REAL
parameter_list|(
name|x
parameter_list|)
value|real_##x
end_define

begin_define
define|#
directive|define
name|REAL
parameter_list|(
name|x
parameter_list|)
value|__interception::PTR_TO_REAL(x)
end_define

begin_define
define|#
directive|define
name|FUNC_TYPE
parameter_list|(
name|x
parameter_list|)
value|x##_f
end_define

begin_define
define|#
directive|define
name|DECLARE_REAL
parameter_list|(
name|ret_type
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|typedef ret_type (*FUNC_TYPE(func))(__VA_ARGS__); \     namespace __interception { \       extern FUNC_TYPE(func) PTR_TO_REAL(func); \     }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// __APPLE__
end_comment

begin_define
define|#
directive|define
name|REAL
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|DECLARE_REAL
parameter_list|(
name|ret_type
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|extern "C" ret_type func(__VA_ARGS__);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __APPLE__
end_comment

begin_define
define|#
directive|define
name|DECLARE_REAL_AND_INTERCEPTOR
parameter_list|(
name|ret_type
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|DECLARE_REAL(ret_type, func, __VA_ARGS__) \   extern "C" ret_type WRAP(func)(__VA_ARGS__);
end_define

begin_comment
comment|// Generally, you don't need to use DEFINE_REAL by itself, as INTERCEPTOR
end_comment

begin_comment
comment|// macros does its job. In exceptional cases you may need to call REAL(foo)
end_comment

begin_comment
comment|// without defining INTERCEPTOR(..., foo, ...). For example, if you override
end_comment

begin_comment
comment|// foo with an interceptor for other function.
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEFINE_REAL
parameter_list|(
name|ret_type
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|typedef ret_type (*FUNC_TYPE(func))(__VA_ARGS__); \     namespace __interception { \       FUNC_TYPE(func) PTR_TO_REAL(func); \     }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEFINE_REAL
parameter_list|(
name|ret_type
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_define
define|#
directive|define
name|INTERCEPTOR
parameter_list|(
name|ret_type
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|DEFINE_REAL(ret_type, func, __VA_ARGS__) \   DECLARE_WRAPPER(ret_type, func, __VA_ARGS__) \   extern "C" \   INTERCEPTOR_ATTRIBUTE \   ret_type WRAP(func)(__VA_ARGS__)
end_define

begin_comment
comment|// We don't need INTERCEPTOR_WITH_SUFFIX on non-Darwin for now.
end_comment

begin_define
define|#
directive|define
name|INTERCEPTOR_WITH_SUFFIX
parameter_list|(
name|ret_type
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|INTERCEPTOR(ret_type, func, __VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// __APPLE__
end_comment

begin_define
define|#
directive|define
name|INTERCEPTOR_ZZZ
parameter_list|(
name|suffix
parameter_list|,
name|ret_type
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|extern "C" ret_type func(__VA_ARGS__) suffix; \   extern "C" ret_type WRAP(func)(__VA_ARGS__); \   INTERPOSER(func); \   extern "C" INTERCEPTOR_ATTRIBUTE ret_type WRAP(func)(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|INTERCEPTOR
parameter_list|(
name|ret_type
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|INTERCEPTOR_ZZZ(
comment|/*no symbol variants*/
value|, ret_type, func, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|INTERCEPTOR_WITH_SUFFIX
parameter_list|(
name|ret_type
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|INTERCEPTOR_ZZZ(__DARWIN_ALIAS_C(func), ret_type, func, __VA_ARGS__)
end_define

begin_comment
comment|// Override |overridee| with |overrider|.
end_comment

begin_define
define|#
directive|define
name|OVERRIDE_FUNCTION
parameter_list|(
name|overridee
parameter_list|,
name|overrider
parameter_list|)
define|\
value|INTERPOSER_2(overridee, WRAP(overrider))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|INTERCEPTOR_WINAPI
parameter_list|(
name|ret_type
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|typedef ret_type (__stdcall *FUNC_TYPE(func))(__VA_ARGS__); \     namespace __interception { \       FUNC_TYPE(func) PTR_TO_REAL(func); \     } \     DECLARE_WRAPPER_WINAPI(ret_type, func, __VA_ARGS__) \     extern "C" \     INTERCEPTOR_ATTRIBUTE \     ret_type __stdcall WRAP(func)(__VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ISO C++ forbids casting between pointer-to-function and pointer-to-object,
end_comment

begin_comment
comment|// so we use casting via an integral type __interception::uptr,
end_comment

begin_comment
comment|// assuming that system is POSIX-compliant. Using other hacks seem
end_comment

begin_comment
comment|// challenging, as we don't even pass function type to
end_comment

begin_comment
comment|// INTERCEPT_FUNCTION macro, only its name.
end_comment

begin_decl_stmt
name|namespace
name|__interception
block|{
if|#
directive|if
name|defined
argument_list|(
name|_WIN64
argument_list|)
typedef|typedef
name|unsigned
name|long
name|long
name|uptr
typedef|;
comment|// NOLINT
else|#
directive|else
typedef|typedef
name|unsigned
name|long
name|uptr
typedef|;
comment|// NOLINT
endif|#
directive|endif
comment|// _WIN64
block|}
end_decl_stmt

begin_comment
comment|// namespace __interception
end_comment

begin_define
define|#
directive|define
name|INCLUDED_FROM_INTERCEPTION_LIB
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"interception_linux.h"
end_include

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION
parameter_list|(
name|func
parameter_list|)
value|INTERCEPT_FUNCTION_LINUX(func)
end_define

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION_VER
parameter_list|(
name|func
parameter_list|,
name|symver
parameter_list|)
define|\
value|INTERCEPT_FUNCTION_VER_LINUX(func, symver)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"interception_mac.h"
end_include

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION
parameter_list|(
name|func
parameter_list|)
value|INTERCEPT_FUNCTION_MAC(func)
end_define

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION_VER
parameter_list|(
name|func
parameter_list|,
name|symver
parameter_list|)
define|\
value|INTERCEPT_FUNCTION_VER_MAC(func, symver)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// defined(_WIN32)
end_comment

begin_include
include|#
directive|include
file|"interception_win.h"
end_include

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION
parameter_list|(
name|func
parameter_list|)
value|INTERCEPT_FUNCTION_WIN(func)
end_define

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION_VER
parameter_list|(
name|func
parameter_list|,
name|symver
parameter_list|)
define|\
value|INTERCEPT_FUNCTION_VER_WIN(func, symver)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|INCLUDED_FROM_INTERCEPTION_LIB
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// INTERCEPTION_H
end_comment

end_unit

