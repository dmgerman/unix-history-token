begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/Core/TaskGroup.h - Task Group ----------------------------------===//
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
name|LLD_CORE_TASKGROUP_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_TASKGROUP_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|<condition_variable>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
comment|/// \brief Allows one or more threads to wait on a potentially unknown number of
comment|///   events.
comment|///
comment|/// A latch starts at \p count. inc() increments this, and dec() decrements it.
comment|/// All calls to sync() will block while the count is not 0.
comment|///
comment|/// Calling dec() on a Latch with a count of 0 has undefined behaivor.
name|class
name|Latch
block|{
name|uint32_t
name|_count
decl_stmt|;
name|mutable
name|std
operator|::
name|mutex
name|_condMut
expr_stmt|;
name|mutable
name|std
operator|::
name|condition_variable
name|_cond
expr_stmt|;
name|public
label|:
name|explicit
name|Latch
argument_list|(
argument|uint32_t count =
literal|0
argument_list|)
block|:
name|_count
argument_list|(
argument|count
argument_list|)
block|{}
operator|~
name|Latch
argument_list|()
block|{
name|sync
argument_list|()
block|; }
name|void
name|inc
argument_list|()
block|{
name|std
operator|::
name|unique_lock
operator|<
name|std
operator|::
name|mutex
operator|>
name|lock
argument_list|(
name|_condMut
argument_list|)
block|;
operator|++
name|_count
block|;   }
name|void
name|dec
argument_list|()
block|{
name|std
operator|::
name|unique_lock
operator|<
name|std
operator|::
name|mutex
operator|>
name|lock
argument_list|(
name|_condMut
argument_list|)
block|;
if|if
condition|(
operator|--
name|_count
operator|==
literal|0
condition|)
name|_cond
operator|.
name|notify_all
argument_list|()
expr_stmt|;
block|}
name|void
name|sync
argument_list|()
specifier|const
block|{
name|std
operator|::
name|unique_lock
operator|<
name|std
operator|::
name|mutex
operator|>
name|lock
argument_list|(
name|_condMut
argument_list|)
block|;
name|_cond
operator|.
name|wait
argument_list|(
name|lock
argument_list|,
index|[
operator|&
index|]
block|{
return|return
name|_count
operator|==
literal|0
return|;
block|}
argument_list|)
block|;   }
block|}
empty_stmt|;
comment|/// \brief Allows launching a number of tasks and waiting for them to finish
comment|///   either explicitly via sync() or implicitly on destruction.
name|class
name|TaskGroup
block|{
name|Latch
name|_latch
decl_stmt|;
name|public
label|:
name|void
name|spawn
argument_list|(
name|std
operator|::
name|function
operator|<
name|void
argument_list|()
operator|>
name|f
argument_list|)
decl_stmt|;
name|void
name|sync
argument_list|()
specifier|const
block|{
name|_latch
operator|.
name|sync
argument_list|()
block|; }
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

