begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- interception_linux.h ------------------------------------*- C++ -*-===//
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
comment|// Windows-specific interception methods.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INCLUDED_FROM_INTERCEPTION_LIB
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"interception_win.h should be included from interception library only"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INTERCEPTION_WIN_H
end_ifndef

begin_define
define|#
directive|define
name|INTERCEPTION_WIN_H
end_define

begin_decl_stmt
name|namespace
name|__interception
block|{
comment|// All the functions in the OverrideFunction() family return true on success,
comment|// false on failure (including "couldn't find the function").
comment|// Overrides a function by its address.
name|bool
name|OverrideFunction
parameter_list|(
name|uptr
name|old_func
parameter_list|,
name|uptr
name|new_func
parameter_list|,
name|uptr
modifier|*
name|orig_old_func
init|=
literal|0
parameter_list|)
function_decl|;
comment|// Overrides a function in a system DLL or DLL CRT by its exported name.
name|bool
name|OverrideFunction
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uptr
name|new_func
parameter_list|,
name|uptr
modifier|*
name|orig_old_func
init|=
literal|0
parameter_list|)
function_decl|;
comment|// Windows-only replacement for GetProcAddress. Useful for some sanitizers.
name|uptr
name|InternalGetProcAddress
parameter_list|(
name|void
modifier|*
name|module
parameter_list|,
specifier|const
name|char
modifier|*
name|func_name
parameter_list|)
function_decl|;
comment|// Overrides a function only when it is called from a specific DLL. For example,
comment|// this is used to override calls to HeapAlloc/HeapFree from ucrtbase without
comment|// affecting other third party libraries.
name|bool
name|OverrideImportedFunction
parameter_list|(
specifier|const
name|char
modifier|*
name|module_to_patch
parameter_list|,
specifier|const
name|char
modifier|*
name|imported_module
parameter_list|,
specifier|const
name|char
modifier|*
name|function_name
parameter_list|,
name|uptr
name|new_function
parameter_list|,
name|uptr
modifier|*
name|orig_old_func
parameter_list|)
function_decl|;
if|#
directive|if
operator|!
name|SANITIZER_WINDOWS64
comment|// Exposed for unittests
name|bool
name|OverrideFunctionWithDetour
parameter_list|(
name|uptr
name|old_func
parameter_list|,
name|uptr
name|new_func
parameter_list|,
name|uptr
modifier|*
name|orig_old_func
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// Exposed for unittests
name|bool
name|OverrideFunctionWithRedirectJump
parameter_list|(
name|uptr
name|old_func
parameter_list|,
name|uptr
name|new_func
parameter_list|,
name|uptr
modifier|*
name|orig_old_func
parameter_list|)
function_decl|;
name|bool
name|OverrideFunctionWithHotPatch
parameter_list|(
name|uptr
name|old_func
parameter_list|,
name|uptr
name|new_func
parameter_list|,
name|uptr
modifier|*
name|orig_old_func
parameter_list|)
function_decl|;
name|bool
name|OverrideFunctionWithTrampoline
parameter_list|(
name|uptr
name|old_func
parameter_list|,
name|uptr
name|new_func
parameter_list|,
name|uptr
modifier|*
name|orig_old_func
parameter_list|)
function_decl|;
comment|// Exposed for unittests
name|void
name|TestOnlyReleaseTrampolineRegions
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __interception
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INTERCEPTION_DYNAMIC_CRT
argument_list|)
end_if

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION_WIN
parameter_list|(
name|func
parameter_list|)
define|\
value|::__interception::OverrideFunction(#func,                                    \                                      (::__interception::uptr)WRAP(func),       \                                      (::__interception::uptr *)&REAL(func))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION_WIN
parameter_list|(
name|func
parameter_list|)
define|\
value|::__interception::OverrideFunction((::__interception::uptr)func,             \                                      (::__interception::uptr)WRAP(func),       \                                      (::__interception::uptr *)&REAL(func))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION_VER_WIN
parameter_list|(
name|func
parameter_list|,
name|symver
parameter_list|)
value|INTERCEPT_FUNCTION_WIN(func)
end_define

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION_DLLIMPORT
parameter_list|(
name|user_dll
parameter_list|,
name|provider_dll
parameter_list|,
name|func
parameter_list|)
define|\
value|::__interception::OverrideImportedFunction(                            \       user_dll, provider_dll, #func, (::__interception::uptr)WRAP(func), \       (::__interception::uptr *)&REAL(func))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// INTERCEPTION_WIN_H
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _WIN32
end_comment

end_unit

