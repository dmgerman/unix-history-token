begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*===------- llvm/Config/abi-breaking.h - llvm configuration -------*- C -*-===*/
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*                     The LLVM Compiler Infrastructure                       */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/* This file is distributed under the University of Illinois Open Source      */
end_comment

begin_comment
comment|/* License. See LICENSE.TXT for details.                                      */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*===----------------------------------------------------------------------===*/
end_comment

begin_comment
comment|/* This file controls the C++ ABI break introduced in LLVM public header. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ABI_BREAKING_CHECKS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ABI_BREAKING_CHECKS_H
end_define

begin_comment
comment|/* Define to enable checks that alter the LLVM C++ ABI */
end_comment

begin_define
define|#
directive|define
name|LLVM_ENABLE_ABI_BREAKING_CHECKS
value|1
end_define

begin_comment
comment|/* Define to enable reverse iteration of unordered llvm containers */
end_comment

begin_define
define|#
directive|define
name|LLVM_ENABLE_REVERSE_ITERATION
value|0
end_define

begin_comment
comment|/* Allow selectively disabling link-time mismatch checking so that header-only    ADT content from LLVM can be used without linking libSupport. */
end_comment

begin_if
if|#
directive|if
operator|!
name|LLVM_DISABLE_ABI_BREAKING_CHECKS_ENFORCING
end_if

begin_comment
comment|// ABI_BREAKING_CHECKS protection: provides link-time failure when clients build
end_comment

begin_comment
comment|// mismatch with LLVM
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_comment
comment|// Use pragma with MSVC
end_comment

begin_define
define|#
directive|define
name|LLVM_XSTR
parameter_list|(
name|s
parameter_list|)
value|LLVM_STR(s)
end_define

begin_define
define|#
directive|define
name|LLVM_STR
parameter_list|(
name|s
parameter_list|)
value|#s
end_define

begin_pragma
pragma|#
directive|pragma
name|detect_mismatch
name|(
literal|"LLVM_ENABLE_ABI_BREAKING_CHECKS"
name|,
name|LLVM_XSTR
name|(
name|LLVM_ENABLE_ABI_BREAKING_CHECKS
name|)
name|)
end_pragma

begin_undef
undef|#
directive|undef
name|LLVM_XSTR
end_undef

begin_undef
undef|#
directive|undef
name|LLVM_STR
end_undef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_elif

begin_comment
comment|// Win32 w/o #pragma detect_mismatch
end_comment

begin_comment
comment|// FIXME: Implement checks without weak.
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_elif

begin_decl_stmt
name|namespace
name|llvm
block|{
if|#
directive|if
name|LLVM_ENABLE_ABI_BREAKING_CHECKS
specifier|extern
name|int
name|EnableABIBreakingChecks
decl_stmt|;
name|__attribute__
argument_list|(
argument|(weak, visibility (
literal|"hidden"
argument|))
argument_list|)
name|int
modifier|*
name|VerifyEnableABIBreakingChecks
init|=
operator|&
name|EnableABIBreakingChecks
decl_stmt|;
else|#
directive|else
specifier|extern
name|int
name|DisableABIBreakingChecks
decl_stmt|;
name|__attribute__
argument_list|(
argument|(weak, visibility (
literal|"hidden"
argument|))
argument_list|)
name|int
modifier|*
name|VerifyDisableABIBreakingChecks
init|=
operator|&
name|DisableABIBreakingChecks
decl_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _MSC_VER
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DISABLE_ABI_BREAKING_CHECKS_ENFORCING
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

