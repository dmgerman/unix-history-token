begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------------------- TaskPool.h ---------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|utility_TaskPool_h_
end_ifndef

begin_define
define|#
directive|define
name|utility_TaskPool_h_
end_define

begin_include
include|#
directive|include
file|<functional>
end_include

begin_comment
comment|// for bind, function
end_comment

begin_include
include|#
directive|include
file|<future>
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_comment
comment|// for make_shared
end_comment

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_comment
comment|// for mutex, unique_lock, condition_variable
end_comment

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_comment
comment|// for forward, result_of, move
end_comment

begin_comment
comment|// Global TaskPool class for running tasks in parallel on a set of worker thread
end_comment

begin_comment
comment|// created the first
end_comment

begin_comment
comment|// time the task pool is used. The TaskPool provide no guarantee about the order
end_comment

begin_comment
comment|// the task will be run
end_comment

begin_comment
comment|// and about what tasks will run in parallel. None of the task added to the task
end_comment

begin_comment
comment|// pool should block
end_comment

begin_comment
comment|// on something (mutex, future, condition variable) what will be set only by the
end_comment

begin_comment
comment|// completion of an
end_comment

begin_comment
comment|// other task on the task pool as they may run on the same thread sequentally.
end_comment

begin_decl_stmt
name|class
name|TaskPool
block|{
name|public
label|:
comment|// Add a new task to the task pool and return a std::future belonging to the
comment|// newly created task.
comment|// The caller of this function has to wait on the future for this task to
comment|// complete.
name|template
operator|<
name|typename
name|F
operator|,
name|typename
operator|...
name|Args
operator|>
specifier|static
name|std
operator|::
name|future
operator|<
name|typename
name|std
operator|::
name|result_of
operator|<
name|F
argument_list|(
name|Args
operator|...
argument_list|)
operator|>
operator|::
name|type
operator|>
name|AddTask
argument_list|(
name|F
operator|&&
name|f
argument_list|,
name|Args
operator|&&
operator|...
name|args
argument_list|)
expr_stmt|;
comment|// Run all of the specified tasks on the task pool and wait until all of them
comment|// are finished
comment|// before returning. This method is intended to be used for small number tasks
comment|// where listing
comment|// them as function arguments is acceptable. For running large number of tasks
comment|// you should use
comment|// AddTask for each task and then call wait() on each returned future.
name|template
operator|<
name|typename
operator|...
name|T
operator|>
specifier|static
name|void
name|RunTasks
argument_list|(
name|T
operator|&&
operator|...
name|tasks
argument_list|)
expr_stmt|;
name|private
label|:
name|TaskPool
argument_list|()
operator|=
name|delete
expr_stmt|;
name|template
operator|<
name|typename
operator|...
name|T
operator|>
expr|struct
name|RunTaskImpl
expr_stmt|;
specifier|static
name|void
name|AddTaskImpl
argument_list|(
name|std
operator|::
name|function
operator|<
name|void
argument_list|()
operator|>
operator|&&
name|task_fn
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|F
operator|,
name|typename
operator|...
name|Args
operator|>
name|std
operator|::
name|future
operator|<
name|typename
name|std
operator|::
name|result_of
operator|<
name|F
argument_list|(
name|Args
operator|...
argument_list|)
operator|>
operator|::
name|type
operator|>
name|TaskPool
operator|::
name|AddTask
argument_list|(
argument|F&&f
argument_list|,
argument|Args&&... args
argument_list|)
block|{
name|auto
name|task_sp
operator|=
name|std
operator|::
name|make_shared
operator|<
name|std
operator|::
name|packaged_task
operator|<
name|typename
name|std
operator|::
name|result_of
operator|<
name|F
argument_list|(
name|Args
operator|...
argument_list|)
operator|>
operator|::
name|type
argument_list|()
operator|>>
operator|(
name|std
operator|::
name|bind
argument_list|(
name|std
operator|::
name|forward
operator|<
name|F
operator|>
operator|(
name|f
operator|)
argument_list|,
name|std
operator|::
name|forward
operator|<
name|Args
operator|>
operator|(
name|args
operator|)
operator|...
argument_list|)
operator|)
block|;
name|AddTaskImpl
argument_list|(
index|[
name|task_sp
index|]
operator|(
operator|)
block|{
call|(
modifier|*
name|task_sp
call|)
argument_list|()
block|; }
argument_list|)
block|;
return|return
name|task_sp
operator|->
name|get_future
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|T
operator|>
name|void
name|TaskPool
operator|::
name|RunTasks
argument_list|(
argument|T&&... tasks
argument_list|)
block|{
name|RunTaskImpl
operator|<
name|T
operator|...
operator|>
operator|::
name|Run
argument_list|(
name|std
operator|::
name|forward
operator|<
name|T
operator|>
operator|(
name|tasks
operator|)
operator|...
argument_list|)
block|; }
name|template
operator|<
name|typename
name|Head
operator|,
name|typename
operator|...
name|Tail
operator|>
expr|struct
name|TaskPool
operator|::
name|RunTaskImpl
operator|<
name|Head
operator|,
name|Tail
operator|...
operator|>
block|{
specifier|static
name|void
name|Run
argument_list|(
argument|Head&&h
argument_list|,
argument|Tail&&... t
argument_list|)
block|{
name|auto
name|f
operator|=
name|AddTask
argument_list|(
name|std
operator|::
name|forward
operator|<
name|Head
operator|>
operator|(
name|h
operator|)
argument_list|)
block|;
name|RunTaskImpl
operator|<
name|Tail
operator|...
operator|>
operator|::
name|Run
argument_list|(
name|std
operator|::
name|forward
operator|<
name|Tail
operator|>
operator|(
name|t
operator|)
operator|...
argument_list|)
block|;
name|f
operator|.
name|wait
argument_list|()
block|;   }
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|TaskPool
operator|::
name|RunTaskImpl
operator|<
operator|>
block|{
specifier|static
name|void
name|Run
argument_list|()
block|{}
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Run 'func' on every value from begin .. end-1.  Each worker will grab
end_comment

begin_comment
comment|// 'batch_size' numbers at a time to work on, so for very fast functions, batch
end_comment

begin_comment
comment|// should be large enough to avoid too much cache line contention.
end_comment

begin_decl_stmt
name|void
name|TaskMapOverInt
argument_list|(
name|size_t
name|begin
argument_list|,
name|size_t
name|end
argument_list|,
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|size_t
argument_list|)
operator|>
specifier|const
operator|&
name|func
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef utility_TaskPool_h_
end_comment

end_unit

