begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/ThreadPool.h - A ThreadPool implementation -*- C++ -*-===//
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
comment|// This file defines a crude C++11 based thread pool.
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
name|LLVM_SUPPORT_THREAD_POOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_THREAD_POOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/thread.h"
end_include

begin_include
include|#
directive|include
file|<future>
end_include

begin_include
include|#
directive|include
file|<atomic>
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
file|<memory>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<queue>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A ThreadPool for asynchronous parallel execution on a defined number of
comment|/// threads.
comment|///
comment|/// The pool keeps a vector of threads alive, waiting on a condition variable
comment|/// for some work to become available.
name|class
name|ThreadPool
block|{
name|public
label|:
name|using
name|TaskTy
init|=
name|std
operator|::
name|function
operator|<
name|void
argument_list|()
operator|>
decl_stmt|;
name|using
name|PackagedTaskTy
init|=
name|std
operator|::
name|packaged_task
operator|<
name|void
argument_list|()
operator|>
decl_stmt|;
comment|/// Construct a pool with the number of core available on the system (or
comment|/// whatever the value returned by std::thread::hardware_concurrency() is).
name|ThreadPool
argument_list|()
expr_stmt|;
comment|/// Construct a pool of \p ThreadCount threads
name|ThreadPool
argument_list|(
argument|unsigned ThreadCount
argument_list|)
empty_stmt|;
comment|/// Blocking destructor: the pool will wait for all the threads to complete.
operator|~
name|ThreadPool
argument_list|()
expr_stmt|;
comment|/// Asynchronous submission of a task to the pool. The returned future can be
comment|/// used to wait for the task to finish and is *non-blocking* on destruction.
name|template
operator|<
name|typename
name|Function
operator|,
name|typename
operator|...
name|Args
operator|>
specifier|inline
name|std
operator|::
name|shared_future
operator|<
name|void
operator|>
name|async
argument_list|(
argument|Function&&F
argument_list|,
argument|Args&&... ArgList
argument_list|)
block|{
name|auto
name|Task
operator|=
name|std
operator|::
name|bind
argument_list|(
name|std
operator|::
name|forward
operator|<
name|Function
operator|>
operator|(
name|F
operator|)
argument_list|,
name|std
operator|::
name|forward
operator|<
name|Args
operator|>
operator|(
name|ArgList
operator|)
operator|...
argument_list|)
block|;
return|return
name|asyncImpl
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Task
argument_list|)
argument_list|)
return|;
block|}
comment|/// Asynchronous submission of a task to the pool. The returned future can be
comment|/// used to wait for the task to finish and is *non-blocking* on destruction.
name|template
operator|<
name|typename
name|Function
operator|>
specifier|inline
name|std
operator|::
name|shared_future
operator|<
name|void
operator|>
name|async
argument_list|(
argument|Function&&F
argument_list|)
block|{
return|return
name|asyncImpl
argument_list|(
name|std
operator|::
name|forward
operator|<
name|Function
operator|>
operator|(
name|F
operator|)
argument_list|)
return|;
block|}
comment|/// Blocking wait for all the threads to complete and the queue to be empty.
comment|/// It is an error to try to add new tasks while blocking on this call.
name|void
name|wait
parameter_list|()
function_decl|;
name|private
label|:
comment|/// Asynchronous submission of a task to the pool. The returned future can be
comment|/// used to wait for the task to finish and is *non-blocking* on destruction.
name|std
operator|::
name|shared_future
operator|<
name|void
operator|>
name|asyncImpl
argument_list|(
argument|TaskTy F
argument_list|)
expr_stmt|;
comment|/// Threads in flight
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|thread
operator|>
name|Threads
expr_stmt|;
comment|/// Tasks waiting for execution in the pool.
name|std
operator|::
name|queue
operator|<
name|PackagedTaskTy
operator|>
name|Tasks
expr_stmt|;
comment|/// Locking and signaling for accessing the Tasks queue.
name|std
operator|::
name|mutex
name|QueueLock
expr_stmt|;
name|std
operator|::
name|condition_variable
name|QueueCondition
expr_stmt|;
comment|/// Locking and signaling for job completion
name|std
operator|::
name|mutex
name|CompletionLock
expr_stmt|;
name|std
operator|::
name|condition_variable
name|CompletionCondition
expr_stmt|;
comment|/// Keep track of the number of thread actually busy
name|std
operator|::
name|atomic
operator|<
name|unsigned
operator|>
name|ActiveThreads
expr_stmt|;
if|#
directive|if
name|LLVM_ENABLE_THREADS
comment|// avoids warning for unused variable
comment|/// Signal for the destruction of the pool, asking thread to exit.
name|bool
name|EnableFlag
decl_stmt|;
endif|#
directive|endif
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_THREAD_POOL_H
end_comment

end_unit

