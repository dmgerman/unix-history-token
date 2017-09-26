begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/Errno.h - Portable+convenient errno handling -*- C++ -*-===//
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
comment|// This file declares some portable and convenient functions to deal with errno.
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
name|LLVM_SUPPORT_ERRNO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_ERRNO_H
end_define

begin_include
include|#
directive|include
file|<cerrno>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|/// Returns a string representation of the errno value, using whatever
comment|/// thread-safe variant of strerror() is available.  Be sure to call this
comment|/// immediately after the function that set errno, or errno may have been
comment|/// overwritten by an intervening call.
name|std
operator|::
name|string
name|StrError
argument_list|()
expr_stmt|;
comment|/// Like the no-argument version above, but uses \p errnum instead of errno.
name|std
operator|::
name|string
name|StrError
argument_list|(
argument|int errnum
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|FailT
operator|,
name|typename
name|Fun
operator|,
name|typename
operator|...
name|Args
operator|>
specifier|inline
name|auto
name|RetryAfterSignal
argument_list|(
specifier|const
name|FailT
operator|&
name|Fail
argument_list|,
specifier|const
name|Fun
operator|&
name|F
argument_list|,
specifier|const
name|Args
operator|&
operator|...
name|As
argument_list|)
operator|->
name|decltype
argument_list|(
argument|F(As...)
argument_list|)
block|{
name|decltype
argument_list|(
argument|F(As...)
argument_list|)
name|Res
block|;
do|do
name|Res
operator|=
name|F
argument_list|(
name|As
operator|...
argument_list|)
expr_stmt|;
do|while
condition|(
name|Res
operator|==
name|Fail
operator|&&
name|errno
operator|==
name|EINTR
condition|)
do|;
return|return
name|Res
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace sys
end_comment

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SYSTEM_ERRNO_H
end_comment

end_unit

