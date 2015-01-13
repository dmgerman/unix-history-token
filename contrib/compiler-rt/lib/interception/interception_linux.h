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
comment|// Linux-specific interception methods.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

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
literal|"interception_linux.h should be included from interception library only"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INTERCEPTION_LINUX_H
end_ifndef

begin_define
define|#
directive|define
name|INTERCEPTION_LINUX_H
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
parameter_list|,
name|uptr
name|real
parameter_list|,
name|uptr
name|wrapper
parameter_list|)
function_decl|;
name|void
modifier|*
name|GetFuncAddrVer
parameter_list|(
specifier|const
name|char
modifier|*
name|func_name
parameter_list|,
specifier|const
name|char
modifier|*
name|ver
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __interception
end_comment

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION_LINUX_OR_FREEBSD
parameter_list|(
name|func
parameter_list|)
define|\
value|::__interception::GetRealFunctionAddress(                                \       #func, (::__interception::uptr *)&__interception::PTR_TO_REAL(func), \       (::__interception::uptr)& (func),                                   \       (::__interception::uptr)& WRAP(func))
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__ANDROID__
argument_list|)
end_if

begin_comment
comment|// android does not have dlvsym
end_comment

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION_VER_LINUX_OR_FREEBSD
parameter_list|(
name|func
parameter_list|,
name|symver
parameter_list|)
define|\
value|::__interception::real_##func = (func##_f)(unsigned long) \          ::__interception::GetFuncAddrVer(#func, symver)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION_VER_LINUX_OR_FREEBSD
parameter_list|(
name|func
parameter_list|,
name|symver
parameter_list|)
define|\
value|INTERCEPT_FUNCTION_LINUX_OR_FREEBSD(func)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(__ANDROID__)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// INTERCEPTION_LINUX_H
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __linux__ || __FreeBSD__
end_comment

end_unit

