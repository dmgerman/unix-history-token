begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/FEnv.h - Host floating-point exceptions ------*- C++ -*-===//
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
comment|// This file provides an operating system independent interface to
end_comment

begin_comment
comment|// floating-point exception interfaces.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_FENV_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_FENV_H
end_define

begin_include
include|#
directive|include
file|"llvm/Config/config.h"
end_include

begin_include
include|#
directive|include
file|<cerrno>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FENV_H
end_ifdef

begin_include
include|#
directive|include
file|<fenv.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// FIXME: Clang's #include handling apparently doesn't work for libstdc++'s
end_comment

begin_comment
comment|// fenv.h; see PR6907 for details.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|&&
name|defined
argument_list|(
name|_GLIBCXX_FENV_H
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_FENV_H
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|/// llvm_fenv_clearexcept - Clear the floating-point exception state.
specifier|static
specifier|inline
name|void
name|llvm_fenv_clearexcept
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|HAVE_FENV_H
argument_list|)
operator|&&
name|HAVE_DECL_FE_ALL_EXCEPT
name|feclearexcept
argument_list|(
name|FE_ALL_EXCEPT
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|errno
operator|=
literal|0
expr_stmt|;
block|}
comment|/// llvm_fenv_testexcept - Test if a floating-point exception was raised.
specifier|static
specifier|inline
name|bool
name|llvm_fenv_testexcept
parameter_list|()
block|{
name|int
name|errno_val
init|=
name|errno
decl_stmt|;
if|if
condition|(
name|errno_val
operator|==
name|ERANGE
operator|||
name|errno_val
operator|==
name|EDOM
condition|)
return|return
name|true
return|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_FENV_H
argument_list|)
operator|&&
name|HAVE_DECL_FE_ALL_EXCEPT
operator|&&
name|HAVE_DECL_FE_INEXACT
if|if
condition|(
name|fetestexcept
argument_list|(
name|FE_ALL_EXCEPT
operator|&
operator|~
name|FE_INEXACT
argument_list|)
condition|)
return|return
name|true
return|;
endif|#
directive|endif
return|return
name|false
return|;
block|}
block|}
comment|// End sys namespace
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

