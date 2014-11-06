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
comment|// returns true if a function with the given name was found.
name|bool
name|GetRealFunctionAddress
parameter_list|(
specifier|const
name|char
modifier|*
name|func_name
parameter_list|,
name|uptr
modifier|*
name|func_addr
parameter_list|)
function_decl|;
comment|// returns true if the old function existed, false on failure.
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
parameter_list|)
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
name|_DLL
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
value|::__interception::GetRealFunctionAddress( \         #func, (::__interception::uptr*)&REAL(func))
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
value|::__interception::OverrideFunction( \         (::__interception::uptr)func, \         (::__interception::uptr)WRAP(func), \         (::__interception::uptr*)&REAL(func))
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
define|\
value|INTERCEPT_FUNCTION_WIN(func)
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

