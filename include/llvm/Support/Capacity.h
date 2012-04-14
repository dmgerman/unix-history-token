begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Capacity.h - Generic computation of ADT memory use -----*- C++ -*-===//
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
comment|// This file defines the capacity function that computes the amount of
end_comment

begin_comment
comment|// memory used by an ADT.
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
name|LLVM_SUPPORT_CAPACITY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_CAPACITY_H
end_define

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|size_t
name|capacity_in_bytes
argument_list|(
argument|const T&x
argument_list|)
block|{
comment|// This default definition of capacity should work for things like std::vector
comment|// and friends.  More specialized versions will work for others.
return|return
name|x
operator|.
name|capacity
argument_list|()
operator|*
expr|sizeof
operator|(
name|typename
name|T
operator|::
name|value_type
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

