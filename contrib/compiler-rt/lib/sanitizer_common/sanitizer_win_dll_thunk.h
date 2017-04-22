begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_win_dll_thunk.h -----------------------------------------===//
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
comment|// This header provide helper macros to delegate calls to the shared runtime
end_comment

begin_comment
comment|// that lives in the main executable. It should be included to dll_thunks that
end_comment

begin_comment
comment|// will be linked to the dlls, when the sanitizer is a static library included
end_comment

begin_comment
comment|// in the main executable.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_WIN_DLL_THUNK_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_WIN_DLL_THUNK_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
name|uptr
name|dllThunkGetRealAddrOrDie
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|int
name|dllThunkIntercept
parameter_list|(
specifier|const
name|char
modifier|*
name|main_function
parameter_list|,
name|uptr
name|dll_function
parameter_list|)
function_decl|;
name|int
name|dllThunkInterceptWhenPossible
parameter_list|(
specifier|const
name|char
modifier|*
name|main_function
parameter_list|,
specifier|const
name|char
modifier|*
name|default_function
parameter_list|,
name|uptr
name|dll_function
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_extern
extern|extern
literal|"C"
name|int
name|__dll_thunk_init
parameter_list|()
function_decl|;
end_extern

begin_comment
comment|// ----------------- Function interception helper macros -------------------- //
end_comment

begin_comment
comment|// Override dll_function with main_function from main executable.
end_comment

begin_define
define|#
directive|define
name|INTERCEPT_OR_DIE
parameter_list|(
name|main_function
parameter_list|,
name|dll_function
parameter_list|)
define|\
value|static int intercept_##dll_function() {                                      \     return __sanitizer::dllThunkIntercept(main_function, (__sanitizer::uptr)   \         dll_function);                                                         \   }                                                                            \   __pragma(section(".DLLTH$M", long, read))                                    \   __declspec(allocate(".DLLTH$M")) int (*__dll_thunk_##dll_function)() =       \     intercept_##dll_function;
end_define

begin_comment
comment|// Try to override dll_function with main_function from main executable.
end_comment

begin_comment
comment|// If main_function is not present, override dll_function with default_function.
end_comment

begin_define
define|#
directive|define
name|INTERCEPT_WHEN_POSSIBLE
parameter_list|(
name|main_function
parameter_list|,
name|default_function
parameter_list|,
name|dll_function
parameter_list|)
define|\
value|static int intercept_##dll_function() {                                      \     return __sanitizer::dllThunkInterceptWhenPossible(main_function,           \         default_function, (__sanitizer::uptr)dll_function);                    \   }                                                                            \   __pragma(section(".DLLTH$M", long, read))                                    \   __declspec(allocate(".DLLTH$M")) int (*__dll_thunk_##dll_function)() =       \     intercept_##dll_function;
end_define

begin_comment
comment|// -------------------- Function interception macros ------------------------ //
end_comment

begin_comment
comment|// Special case of hooks -- ASan own interface functions.  Those are only called
end_comment

begin_comment
comment|// after __asan_init, thus an empty implementation is sufficient.
end_comment

begin_define
define|#
directive|define
name|INTERCEPT_SANITIZER_FUNCTION
parameter_list|(
name|name
parameter_list|)
define|\
value|extern "C" __declspec(noinline) void name() {                                \     volatile int prevent_icf = (__LINE__<< 8) ^ __COUNTER__;                  \     static const char function_name[] = #name;                                 \     for (const char* ptr =&function_name[0]; *ptr; ++ptr)                     \       prevent_icf ^= *ptr;                                                     \     (void)prevent_icf;                                                         \     __debugbreak();                                                            \   }                                                                            \   INTERCEPT_OR_DIE(#name, name)
end_define

begin_comment
comment|// Special case of hooks -- Weak functions, could be redefined in the main
end_comment

begin_comment
comment|// executable, but that is not necessary, so we shouldn't die if we can not find
end_comment

begin_comment
comment|// a reference. Instead, when the function is not present in the main executable
end_comment

begin_comment
comment|// we consider the default impl provided by asan library.
end_comment

begin_define
define|#
directive|define
name|INTERCEPT_SANITIZER_WEAK_FUNCTION
parameter_list|(
name|name
parameter_list|)
define|\
value|extern "C" __declspec(noinline) void name() {                                \     volatile int prevent_icf = (__LINE__<< 8) ^ __COUNTER__;                  \     static const char function_name[] = #name;                                 \     for (const char* ptr =&function_name[0]; *ptr; ++ptr)                     \       prevent_icf ^= *ptr;                                                     \     (void)prevent_icf;                                                         \     __debugbreak();                                                            \   }                                                                            \   INTERCEPT_WHEN_POSSIBLE(#name, STRINGIFY(WEAK_EXPORT_NAME(name)), name)
end_define

begin_comment
comment|// We can't define our own version of strlen etc. because that would lead to
end_comment

begin_comment
comment|// link-time or even type mismatch errors.  Instead, we can declare a function
end_comment

begin_comment
comment|// just to be able to get its address.  Me may miss the first few calls to the
end_comment

begin_comment
comment|// functions since it can be called before __dll_thunk_init, but that would lead
end_comment

begin_comment
comment|// to false negatives in the startup code before user's global initializers,
end_comment

begin_comment
comment|// which isn't a big deal.
end_comment

begin_define
define|#
directive|define
name|INTERCEPT_LIBRARY_FUNCTION
parameter_list|(
name|name
parameter_list|)
define|\
value|extern "C" void name();                                                      \   INTERCEPT_OR_DIE(WRAPPER_NAME(name), name)
end_define

begin_comment
comment|// Use these macros for functions that could be called before __dll_thunk_init()
end_comment

begin_comment
comment|// is executed and don't lead to errors if defined (free, malloc, etc).
end_comment

begin_define
define|#
directive|define
name|INTERCEPT_WRAP_V_V
parameter_list|(
name|name
parameter_list|)
define|\
value|extern "C" void name() {                                                     \     typedef decltype(name) *fntype;                                            \     static fntype fn = (fntype)__sanitizer::dllThunkGetRealAddrOrDie(#name);   \     fn();                                                                      \   }                                                                            \   INTERCEPT_OR_DIE(#name, name);
end_define

begin_define
define|#
directive|define
name|INTERCEPT_WRAP_V_W
parameter_list|(
name|name
parameter_list|)
define|\
value|extern "C" void name(void *arg) {                                            \     typedef decltype(name) *fntype;                                            \     static fntype fn = (fntype)__sanitizer::dllThunkGetRealAddrOrDie(#name);   \     fn(arg);                                                                   \   }                                                                            \   INTERCEPT_OR_DIE(#name, name);
end_define

begin_define
define|#
directive|define
name|INTERCEPT_WRAP_V_WW
parameter_list|(
name|name
parameter_list|)
define|\
value|extern "C" void name(void *arg1, void *arg2) {                               \     typedef decltype(name) *fntype;                                            \     static fntype fn = (fntype)__sanitizer::dllThunkGetRealAddrOrDie(#name);   \     fn(arg1, arg2);                                                            \   }                                                                            \   INTERCEPT_OR_DIE(#name, name);
end_define

begin_define
define|#
directive|define
name|INTERCEPT_WRAP_V_WWW
parameter_list|(
name|name
parameter_list|)
define|\
value|extern "C" void name(void *arg1, void *arg2, void *arg3) {                   \     typedef decltype(name) *fntype;                                            \     static fntype fn = (fntype)__sanitizer::dllThunkGetRealAddrOrDie(#name);   \     fn(arg1, arg2, arg3);                                                      \   }                                                                            \   INTERCEPT_OR_DIE(#name, name);
end_define

begin_define
define|#
directive|define
name|INTERCEPT_WRAP_W_V
parameter_list|(
name|name
parameter_list|)
define|\
value|extern "C" void *name() {                                                    \     typedef decltype(name) *fntype;                                            \     static fntype fn = (fntype)__sanitizer::dllThunkGetRealAddrOrDie(#name);   \     return fn();                                                               \   }                                                                            \   INTERCEPT_OR_DIE(#name, name);
end_define

begin_define
define|#
directive|define
name|INTERCEPT_WRAP_W_W
parameter_list|(
name|name
parameter_list|)
define|\
value|extern "C" void *name(void *arg) {                                           \     typedef decltype(name) *fntype;                                            \     static fntype fn = (fntype)__sanitizer::dllThunkGetRealAddrOrDie(#name);   \     return fn(arg);                                                            \   }                                                                            \   INTERCEPT_OR_DIE(#name, name);
end_define

begin_define
define|#
directive|define
name|INTERCEPT_WRAP_W_WW
parameter_list|(
name|name
parameter_list|)
define|\
value|extern "C" void *name(void *arg1, void *arg2) {                              \     typedef decltype(name) *fntype;                                            \     static fntype fn = (fntype)__sanitizer::dllThunkGetRealAddrOrDie(#name);   \     return fn(arg1, arg2);                                                     \   }                                                                            \   INTERCEPT_OR_DIE(#name, name);
end_define

begin_define
define|#
directive|define
name|INTERCEPT_WRAP_W_WWW
parameter_list|(
name|name
parameter_list|)
define|\
value|extern "C" void *name(void *arg1, void *arg2, void *arg3) {                  \     typedef decltype(name) *fntype;                                            \     static fntype fn = (fntype)__sanitizer::dllThunkGetRealAddrOrDie(#name);   \     return fn(arg1, arg2, arg3);                                               \   }                                                                            \   INTERCEPT_OR_DIE(#name, name);
end_define

begin_define
define|#
directive|define
name|INTERCEPT_WRAP_W_WWWW
parameter_list|(
name|name
parameter_list|)
define|\
value|extern "C" void *name(void *arg1, void *arg2, void *arg3, void *arg4) {      \     typedef decltype(name) *fntype;                                            \     static fntype fn = (fntype)__sanitizer::dllThunkGetRealAddrOrDie(#name);   \     return fn(arg1, arg2, arg3, arg4);                                         \   }                                                                            \   INTERCEPT_OR_DIE(#name, name);
end_define

begin_define
define|#
directive|define
name|INTERCEPT_WRAP_W_WWWWW
parameter_list|(
name|name
parameter_list|)
define|\
value|extern "C" void *name(void *arg1, void *arg2, void *arg3, void *arg4,        \                         void *arg5) {                                          \     typedef decltype(name) *fntype;                                            \     static fntype fn = (fntype)__sanitizer::dllThunkGetRealAddrOrDie(#name);   \     return fn(arg1, arg2, arg3, arg4, arg5);                                   \   }                                                                            \   INTERCEPT_OR_DIE(#name, name);
end_define

begin_define
define|#
directive|define
name|INTERCEPT_WRAP_W_WWWWWW
parameter_list|(
name|name
parameter_list|)
define|\
value|extern "C" void *name(void *arg1, void *arg2, void *arg3, void *arg4,        \                         void *arg5, void *arg6) {                              \     typedef decltype(name) *fntype;                                            \     static fntype fn = (fntype)__sanitizer::dllThunkGetRealAddrOrDie(#name);   \     return fn(arg1, arg2, arg3, arg4, arg5, arg6);                             \   }                                                                            \   INTERCEPT_OR_DIE(#name, name);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_WIN_DLL_THUNK_H
end_comment

end_unit

