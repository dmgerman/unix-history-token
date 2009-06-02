begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/ADT/VectorExtras.h - Helpers for std::vector -------*- C++ -*-===//
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
comment|// This file contains helper functions which are useful for working with the
end_comment

begin_comment
comment|// std::vector class.
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
name|LLVM_ADT_VECTOREXTRAS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_VECTOREXTRAS_H
end_define

begin_include
include|#
directive|include
file|<cstdarg>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// make_vector - Helper function which is useful for building temporary vectors
comment|/// to pass into type construction of CallInst ctors.  This turns a null
comment|/// terminated list of pointers (or other value types) into a real live vector.
comment|///
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|std
operator|::
name|vector
operator|<
name|T
operator|>
name|make_vector
argument_list|(
argument|T A
argument_list|,
argument|...
argument_list|)
block|{
name|va_list
name|Args
block|;
name|va_start
argument_list|(
name|Args
argument_list|,
name|A
argument_list|)
block|;
name|std
operator|::
name|vector
operator|<
name|T
operator|>
name|Result
block|;
name|Result
operator|.
name|push_back
argument_list|(
name|A
argument_list|)
block|;
while|while
condition|(
name|T
name|Val
init|=
name|va_arg
argument_list|(
name|Args
argument_list|,
name|T
argument_list|)
condition|)
name|Result
operator|.
name|push_back
argument_list|(
name|Val
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|Args
argument_list|)
expr_stmt|;
return|return
name|Result
return|;
block|}
end_decl_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

