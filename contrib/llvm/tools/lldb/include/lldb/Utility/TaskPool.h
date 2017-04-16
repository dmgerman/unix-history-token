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

begin_comment
comment|// Wrapper class around the global TaskPool implementation to make it possible
end_comment

begin_comment
comment|// to create a set of
end_comment

begin_comment
comment|// tasks and then wait for the tasks to be completed by the
end_comment

begin_comment
comment|// WaitForNextCompletedTask call. This
end_comment

begin_comment
comment|// class should be used when WaitForNextCompletedTask is needed because this
end_comment

begin_comment
comment|// class add no other
end_comment

begin_comment
comment|// extra functionality to the TaskPool class and it have a very minor
end_comment

begin_comment
comment|// performance overhead.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
comment|// The return type of the tasks what will be added to this
comment|// task runner
name|class
name|TaskRunner
block|{
name|public
operator|:
comment|// Add a task to the task runner what will also add the task to the global
comment|// TaskPool. The
comment|// function doesn't return the std::future for the task because it will be
comment|// supplied by the
comment|// WaitForNextCompletedTask after the task is completed.
name|template
operator|<
name|typename
name|F
block|,
name|typename
operator|...
name|Args
operator|>
name|void
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
block|;
comment|// Wait for the next task in this task runner to finish and then return the
comment|// std::future what
comment|// belongs to the finished task. If there is no task in this task runner
comment|// (neither pending nor
comment|// comleted) then this function will return an invalid future. Usually this
comment|// function should be
comment|// called in a loop processing the results of the tasks until it returns an
comment|// invalid std::future
comment|// what means that all task in this task runner is completed.
name|std
operator|::
name|future
operator|<
name|T
operator|>
name|WaitForNextCompletedTask
argument_list|()
block|;
comment|// Convenience method to wait for all task in this TaskRunner to finish. Do
comment|// NOT use this class
comment|// just because of this method. Use TaskPool instead and wait for each
comment|// std::future returned by
comment|// AddTask in a loop.
name|void
name|WaitForAllTasks
argument_list|()
block|;
name|private
operator|:
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|future
operator|<
name|T
operator|>>
name|m_ready
block|;
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|future
operator|<
name|T
operator|>>
name|m_pending
block|;
name|std
operator|::
name|mutex
name|m_mutex
block|;
name|std
operator|::
name|condition_variable
name|m_cv
block|; }
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|template
operator|<
name|typename
name|F
operator|,
name|typename
operator|...
name|Args
operator|>
name|void
name|TaskRunner
operator|<
name|T
operator|>
operator|::
name|AddTask
argument_list|(
argument|F&&f
argument_list|,
argument|Args&&... args
argument_list|)
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
name|m_mutex
argument_list|)
block|;
name|auto
name|it
operator|=
name|m_pending
operator|.
name|emplace
argument_list|(
name|m_pending
operator|.
name|end
argument_list|()
argument_list|)
block|;
operator|*
name|it
operator|=
name|std
operator|::
name|move
argument_list|(
name|TaskPool
operator|::
name|AddTask
argument_list|(
index|[
name|this
operator|,
name|it
index|]
operator|(
name|F
name|f
operator|,
name|Args
operator|...
name|args
operator|)
block|{
name|T
operator|&&
name|r
operator|=
name|f
argument_list|(
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
block|;
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
name|this
operator|->
name|m_mutex
argument_list|)
block|;
name|this
operator|->
name|m_ready
operator|.
name|splice
argument_list|(
name|this
operator|->
name|m_ready
operator|.
name|end
argument_list|()
argument_list|,
name|this
operator|->
name|m_pending
argument_list|,
name|it
argument_list|)
block|;
name|lock
operator|.
name|unlock
argument_list|()
block|;
name|this
operator|->
name|m_cv
operator|.
name|notify_one
argument_list|()
block|;
return|return
name|r
return|;
block|}
operator|,
name|std
operator|::
name|forward
operator|<
name|F
operator|>
operator|(
name|f
operator|)
operator|,
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
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_expr_stmt
unit|}  template
operator|<
operator|>
name|template
operator|<
name|typename
name|F
operator|,
name|typename
operator|...
name|Args
operator|>
name|void
name|TaskRunner
operator|<
name|void
operator|>
operator|::
name|AddTask
argument_list|(
argument|F&&f
argument_list|,
argument|Args&&... args
argument_list|)
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
name|m_mutex
argument_list|)
block|;
name|auto
name|it
operator|=
name|m_pending
operator|.
name|emplace
argument_list|(
name|m_pending
operator|.
name|end
argument_list|()
argument_list|)
block|;
operator|*
name|it
operator|=
name|std
operator|::
name|move
argument_list|(
name|TaskPool
operator|::
name|AddTask
argument_list|(
index|[
name|this
operator|,
name|it
index|]
operator|(
name|F
name|f
operator|,
name|Args
operator|...
name|args
operator|)
block|{
name|f
argument_list|(
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
block|;
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
name|this
operator|->
name|m_mutex
argument_list|)
block|;
name|this
operator|->
name|m_ready
operator|.
name|emplace_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
operator|*
name|it
argument_list|)
argument_list|)
block|;
name|this
operator|->
name|m_pending
operator|.
name|erase
argument_list|(
name|it
argument_list|)
block|;
name|lock
operator|.
name|unlock
argument_list|()
block|;
name|this
operator|->
name|m_cv
operator|.
name|notify_one
argument_list|()
block|;       }
argument_list|,
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
argument_list|)
block|; }
name|template
operator|<
name|typename
name|T
operator|>
name|std
operator|::
name|future
operator|<
name|T
operator|>
name|TaskRunner
operator|<
name|T
operator|>
operator|::
name|WaitForNextCompletedTask
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
name|m_mutex
argument_list|)
block|;
if|if
condition|(
name|m_ready
operator|.
name|empty
argument_list|()
operator|&&
name|m_pending
operator|.
name|empty
argument_list|()
condition|)
return|return
name|std
operator|::
name|future
operator|<
name|T
operator|>
operator|(
operator|)
return|;
end_expr_stmt

begin_comment
comment|// No more tasks
end_comment

begin_if
if|if
condition|(
name|m_ready
operator|.
name|empty
argument_list|()
condition|)
name|m_cv
operator|.
name|wait
argument_list|(
name|lock
argument_list|,
index|[
name|this
index|]
operator|(
operator|)
block|{
return|return
operator|!
name|this
operator|->
name|m_ready
operator|.
name|empty
argument_list|()
return|;
block|}
end_if

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|std
operator|::
name|future
operator|<
name|T
operator|>
name|res
operator|=
name|std
operator|::
name|move
argument_list|(
name|m_ready
operator|.
name|front
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|m_ready
operator|.
name|pop_front
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lock
operator|.
name|unlock
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|res
operator|.
name|wait
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|std
operator|::
name|move
argument_list|(
name|res
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
name|void
name|TaskRunner
operator|<
name|T
operator|>
operator|::
name|WaitForAllTasks
argument_list|()
block|{
while|while
condition|(
name|WaitForNextCompletedTask
argument_list|()
operator|.
name|valid
argument_list|()
condition|)
empty_stmt|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef utility_TaskPool_h_
end_comment

end_unit

