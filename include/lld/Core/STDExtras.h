begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/Core/STDExtra.h - Helpers for the stdlib -----------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_CORE_STD_EXTRA_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_STD_EXTRA_H
end_define

begin_decl_stmt
name|namespace
name|lld
block|{
comment|/// \brief Deleter for smart pointers that only calls the destructor. Memory is
comment|/// managed elsewhere. A common use of this is for things allocated with a
comment|/// BumpPtrAllocator.
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|destruct_delete
block|{
name|void
name|operator
argument_list|()
operator|(
name|T
operator|*
name|ptr
operator|)
block|{
name|ptr
operator|->
expr|~
name|T
argument_list|()
block|;   }
block|}
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|using
name|unique_bump_ptr
operator|=
name|std
operator|::
name|unique_ptr
operator|<
name|T
operator|,
name|destruct_delete
operator|<
name|T
operator|>>
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

