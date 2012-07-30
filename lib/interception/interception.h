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

begin_comment
comment|// How to use this library:
end_comment

begin_comment
comment|//      1) Include this header to define your own interceptors
end_comment

begin_comment
comment|//         (see details below).
end_comment

begin_comment
comment|//      2) Build all *.cc files and link against them.
end_comment

begin_comment
comment|// On Mac you will also need to:
end_comment

begin_comment
comment|//      3) Provide your own implementation for the following functions:
end_comment

begin_comment
comment|//           mach_error_t __interception::allocate_island(void **ptr,
end_comment

begin_comment
comment|//                                                      size_t size,
end_comment

begin_comment
comment|//                                                      void *hint);
end_comment

begin_comment
comment|//           mach_error_t __interception::deallocate_island(void *ptr);
end_comment

begin_comment
comment|//         See "interception_mac.h" for more details.
end_comment

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
comment|//         your source file.
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
comment|// Notes: 1. Things may not work properly if macro INTERCEPT(...) {...} or
end_comment

begin_comment
comment|//           DECLARE_REAL(...) are located inside namespaces.
end_comment

begin_comment
comment|//        2. On Mac you can also use: "OVERRIDE_FUNCTION(foo, zoo);" to
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
comment|//           DEFINE_REAL(int, foo, const char *bar, double baz) in your
end_comment

begin_comment
comment|//           source file (to define a pointer to overriden function).
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
comment|// This is not so on Mac OS, where the two-level namespace makes
end_comment

begin_comment
comment|// our replacement functions invisible to other libraries. This may be overcomed
end_comment

begin_comment
comment|// using the DYLD_FORCE_FLAT_NAMESPACE, but some errors loading the shared
end_comment

begin_comment
comment|// libraries in Chromium were noticed when doing so. Instead we use
end_comment

begin_comment
comment|// mach_override, a handy framework for patching functions at runtime.
end_comment

begin_comment
comment|// To avoid possible name clashes, our replacement functions have
end_comment

begin_comment
comment|// the "wrap_" prefix on Mac.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

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
name|convention
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
name|convention
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
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
name|convention
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|extern "C" ret_type convention func(__VA_ARGS__) \     __attribute__((weak, alias("__interceptor_" #func), visibility("default")));
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|typedef ret_type (*FUNC_TYPE(func))(__VA_ARGS__); \   namespace __interception { \     extern FUNC_TYPE(func) PTR_TO_REAL(func); \   }
end_define

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
value|DECLARE_REAL(ret_type, func, ##__VA_ARGS__) \   extern "C" ret_type WRAP(func)(__VA_ARGS__);
end_define

begin_comment
comment|// FIXME(timurrrr): We might need to add DECLARE_REAL_EX etc to support
end_comment

begin_comment
comment|// different calling conventions later.
end_comment

begin_define
define|#
directive|define
name|DEFINE_REAL_EX
parameter_list|(
name|ret_type
parameter_list|,
name|convention
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|typedef ret_type (convention *FUNC_TYPE(func))(__VA_ARGS__); \   namespace __interception { \     FUNC_TYPE(func) PTR_TO_REAL(func); \   }
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

begin_define
define|#
directive|define
name|DEFAULT_CONVENTION
end_define

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
value|DEFINE_REAL_EX(ret_type, DEFAULT_CONVENTION, func, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|INTERCEPTOR_EX
parameter_list|(
name|ret_type
parameter_list|,
name|convention
parameter_list|,
name|func
parameter_list|,
modifier|...
parameter_list|)
define|\
value|DEFINE_REAL_EX(ret_type, convention, func, __VA_ARGS__) \   DECLARE_WRAPPER(ret_type, convention, func, __VA_ARGS__) \   extern "C" \   INTERCEPTOR_ATTRIBUTE \   ret_type convention WRAP(func)(__VA_ARGS__)
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
value|INTERCEPTOR_EX(ret_type, DEFAULT_CONVENTION, func, __VA_ARGS__)
end_define

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
value|INTERCEPTOR_EX(ret_type, __stdcall, func, __VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|OVERRIDE_FUNCTION
parameter_list|(
name|old_func
parameter_list|,
name|new_func
parameter_list|)
define|\
value|OVERRIDE_FUNCTION_MAC(old_func, new_func)
end_define

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION
parameter_list|(
name|func
parameter_list|)
value|INTERCEPT_FUNCTION_MAC(func)
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

