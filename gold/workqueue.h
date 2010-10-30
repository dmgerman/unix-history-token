begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// workqueue.h -- the work queue for gold   -*- C++ -*-
end_comment

begin_comment
comment|// After processing the command line, everything the linker does is
end_comment

begin_comment
comment|// driven from a work queue.  This permits us to parallelize the
end_comment

begin_comment
comment|// linker where possible.
end_comment

begin_comment
comment|// Task_token
end_comment

begin_comment
comment|//   A simple locking implementation to ensure proper task ordering.
end_comment

begin_comment
comment|// Task_read_token, Task_write_token
end_comment

begin_comment
comment|//   Lock a Task_token for read or write.
end_comment

begin_comment
comment|// Task_locker
end_comment

begin_comment
comment|//   Task locking using RAII.
end_comment

begin_comment
comment|// Task
end_comment

begin_comment
comment|//   An abstract class for jobs to run.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_WORKQUEUE_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_WORKQUEUE_H
end_define

begin_include
include|#
directive|include
file|"gold-threads.h"
end_include

begin_include
include|#
directive|include
file|"fileread.h"
end_include

begin_decl_stmt
name|namespace
name|gold
block|{
name|class
name|General_options
decl_stmt|;
name|class
name|Task
decl_stmt|;
name|class
name|Workqueue
decl_stmt|;
comment|// Some tasks require access to shared data structures, such as the
comment|// symbol table.  Some tasks must be executed in a particular error,
comment|// such as reading input file symbol tables--if we see foo.o -llib, we
comment|// have to read the symbols for foo.o before we read the ones for
comment|// -llib.  To implement this safely and efficiently, we use tokens.
comment|// Task_tokens support shared read/exclusive write access to some
comment|// resource.  Alternatively, they support blockers: blockers implement
comment|// the requirement that some set of tasks must complete before another
comment|// set of tasks can start.  In such a case we increment the block
comment|// count when we create the task, and decrement it when the task
comment|// completes.  Task_tokens are only manipulated by the main thread, so
comment|// they do not themselves require any locking.
name|class
name|Task_token
block|{
name|public
label|:
name|Task_token
argument_list|()
expr_stmt|;
operator|~
name|Task_token
argument_list|()
expr_stmt|;
comment|// A read/write token uses these methods.
name|bool
name|is_readable
argument_list|()
specifier|const
expr_stmt|;
name|void
name|add_reader
parameter_list|()
function_decl|;
name|void
name|remove_reader
parameter_list|()
function_decl|;
name|bool
name|is_writable
argument_list|()
specifier|const
expr_stmt|;
name|void
name|add_writer
parameter_list|(
specifier|const
name|Task
modifier|*
parameter_list|)
function_decl|;
name|void
name|remove_writer
parameter_list|(
specifier|const
name|Task
modifier|*
parameter_list|)
function_decl|;
name|bool
name|has_write_lock
parameter_list|(
specifier|const
name|Task
modifier|*
parameter_list|)
function_decl|;
comment|// A blocker token uses these methods.
name|void
name|add_blocker
parameter_list|()
function_decl|;
comment|// Returns true if block count drops to zero.
name|bool
name|remove_blocker
parameter_list|()
function_decl|;
name|bool
name|is_blocked
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|// It makes no sense to copy these.
name|Task_token
argument_list|(
specifier|const
name|Task_token
operator|&
argument_list|)
expr_stmt|;
name|Task_token
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Task_token
operator|&
operator|)
decl_stmt|;
name|bool
name|is_blocker_
decl_stmt|;
name|int
name|readers_
decl_stmt|;
specifier|const
name|Task
modifier|*
name|writer_
decl_stmt|;
block|}
empty_stmt|;
comment|// In order to support tokens more reliably, we provide objects which
comment|// handle them using RAII.
name|class
name|Task_read_token
block|{
name|public
label|:
name|Task_read_token
argument_list|(
name|Task_token
operator|&
name|token
argument_list|)
operator|:
name|token_
argument_list|(
argument|token
argument_list|)
block|{
name|this
operator|->
name|token_
operator|.
name|add_reader
argument_list|()
block|; }
operator|~
name|Task_read_token
argument_list|()
block|{
name|this
operator|->
name|token_
operator|.
name|remove_reader
argument_list|()
block|; }
name|private
operator|:
name|Task_read_token
argument_list|(
specifier|const
name|Task_read_token
operator|&
argument_list|)
expr_stmt|;
name|Task_read_token
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Task_read_token
operator|&
operator|)
decl_stmt|;
name|Task_token
modifier|&
name|token_
decl_stmt|;
block|}
empty_stmt|;
name|class
name|Task_write_token
block|{
name|public
label|:
name|Task_write_token
argument_list|(
name|Task_token
operator|&
name|token
argument_list|,
specifier|const
name|Task
operator|*
name|task
argument_list|)
operator|:
name|token_
argument_list|(
name|token
argument_list|)
operator|,
name|task_
argument_list|(
argument|task
argument_list|)
block|{
name|this
operator|->
name|token_
operator|.
name|add_writer
argument_list|(
name|this
operator|->
name|task_
argument_list|)
block|; }
operator|~
name|Task_write_token
argument_list|()
block|{
name|this
operator|->
name|token_
operator|.
name|remove_writer
argument_list|(
name|this
operator|->
name|task_
argument_list|)
block|; }
name|private
operator|:
name|Task_write_token
argument_list|(
specifier|const
name|Task_write_token
operator|&
argument_list|)
expr_stmt|;
name|Task_write_token
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Task_write_token
operator|&
operator|)
decl_stmt|;
name|Task_token
modifier|&
name|token_
decl_stmt|;
specifier|const
name|Task
modifier|*
name|task_
decl_stmt|;
block|}
empty_stmt|;
name|class
name|Task_block_token
block|{
name|public
label|:
comment|// The blocker count must be incremented when the task is created.
comment|// This object is created when the task is run.  When we unblock the
comment|// last task, we notify the workqueue.
name|Task_block_token
argument_list|(
name|Task_token
operator|&
name|token
argument_list|,
name|Workqueue
operator|*
name|workqueue
argument_list|)
expr_stmt|;
operator|~
name|Task_block_token
argument_list|()
expr_stmt|;
name|private
label|:
name|Task_block_token
argument_list|(
specifier|const
name|Task_block_token
operator|&
argument_list|)
expr_stmt|;
name|Task_block_token
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Task_block_token
operator|&
operator|)
decl_stmt|;
name|Task_token
modifier|&
name|token_
decl_stmt|;
name|Workqueue
modifier|*
name|workqueue_
decl_stmt|;
block|}
empty_stmt|;
comment|// An object which implements an RAII lock for any object which
comment|// supports lock and unlock methods.
name|template
operator|<
name|typename
name|Obj
operator|>
name|class
name|Task_lock_obj
block|{
name|public
operator|:
name|Task_lock_obj
argument_list|(
name|Obj
operator|&
name|obj
argument_list|)
operator|:
name|obj_
argument_list|(
argument|obj
argument_list|)
block|{
name|this
operator|->
name|obj_
operator|.
name|lock
argument_list|()
block|; }
operator|~
name|Task_lock_obj
argument_list|()
block|{
name|this
operator|->
name|obj_
operator|.
name|unlock
argument_list|()
block|; }
name|private
operator|:
name|Task_lock_obj
argument_list|(
specifier|const
name|Task_lock_obj
operator|&
argument_list|)
block|;
name|Task_lock_obj
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Task_lock_obj
operator|&
operator|)
block|;
name|Obj
operator|&
name|obj_
block|; }
expr_stmt|;
comment|// An abstract class used to lock Task_tokens using RAII.  A typical
comment|// implementation would simply have a set of members of type
comment|// Task_read_token, Task_write_token, and Task_block_token.
name|class
name|Task_locker
block|{
name|public
label|:
name|Task_locker
argument_list|()
block|{ }
name|virtual
operator|~
name|Task_locker
argument_list|()
block|{ }
block|}
empty_stmt|;
comment|// A version of Task_locker which may be used for a single read lock.
name|class
name|Task_locker_read
range|:
name|public
name|Task_locker
block|{
name|public
operator|:
name|Task_locker_read
argument_list|(
name|Task_token
operator|&
name|token
argument_list|)
operator|:
name|read_token_
argument_list|(
argument|token
argument_list|)
block|{ }
name|private
operator|:
name|Task_locker_read
argument_list|(
specifier|const
name|Task_locker_read
operator|&
argument_list|)
block|;
name|Task_locker_read
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Task_locker_read
operator|&
operator|)
block|;
name|Task_read_token
name|read_token_
block|; }
decl_stmt|;
comment|// A version of Task_locker which may be used for a single write lock.
name|class
name|Task_locker_write
range|:
name|public
name|Task_locker
block|{
name|public
operator|:
name|Task_locker_write
argument_list|(
name|Task_token
operator|&
name|token
argument_list|,
specifier|const
name|Task
operator|*
name|task
argument_list|)
operator|:
name|write_token_
argument_list|(
argument|token
argument_list|,
argument|task
argument_list|)
block|{ }
name|private
operator|:
name|Task_locker_write
argument_list|(
specifier|const
name|Task_locker_write
operator|&
argument_list|)
block|;
name|Task_locker_write
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Task_locker_write
operator|&
operator|)
block|;
name|Task_write_token
name|write_token_
block|; }
decl_stmt|;
comment|// A version of Task_locker which may be used for a single blocker
comment|// lock.
name|class
name|Task_locker_block
range|:
name|public
name|Task_locker
block|{
name|public
operator|:
name|Task_locker_block
argument_list|(
name|Task_token
operator|&
name|token
argument_list|,
name|Workqueue
operator|*
name|workqueue
argument_list|)
operator|:
name|block_token_
argument_list|(
argument|token
argument_list|,
argument|workqueue
argument_list|)
block|{ }
name|private
operator|:
name|Task_locker_block
argument_list|(
specifier|const
name|Task_locker_block
operator|&
argument_list|)
block|;
name|Task_locker_block
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Task_locker_block
operator|&
operator|)
block|;
name|Task_block_token
name|block_token_
block|; }
decl_stmt|;
comment|// A version of Task_locker which may be used to hold a lock on any
comment|// object which supports lock() and unlock() methods.
name|template
operator|<
name|typename
name|Obj
operator|>
name|class
name|Task_locker_obj
operator|:
name|public
name|Task_locker
block|{
name|public
operator|:
name|Task_locker_obj
argument_list|(
name|Obj
operator|&
name|obj
argument_list|)
operator|:
name|obj_lock_
argument_list|(
argument|obj
argument_list|)
block|{ }
name|private
operator|:
name|Task_locker_obj
argument_list|(
specifier|const
name|Task_locker_obj
operator|&
argument_list|)
block|;
name|Task_locker_obj
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Task_locker_obj
operator|&
operator|)
block|;
name|Task_lock_obj
operator|<
name|Obj
operator|>
name|obj_lock_
block|; }
expr_stmt|;
comment|// The superclass for tasks to be placed on the workqueue.  Each
comment|// specific task class will inherit from this one.
name|class
name|Task
block|{
name|public
label|:
name|Task
argument_list|()
block|{ }
name|virtual
operator|~
name|Task
argument_list|()
block|{ }
comment|// Type returned by Is_runnable.
expr|enum
name|Is_runnable_type
block|{
comment|// Task is runnable.
name|IS_RUNNABLE
block|,
comment|// Task is waiting for a block to clear.
name|IS_BLOCKED
block|,
comment|// Task is not waiting for a block, but is not runnable--i.e., is
comment|// waiting for a lock.
name|IS_LOCKED
block|}
expr_stmt|;
comment|// Return whether the task can be run now.  This method is only
comment|// called from the main thread.
name|virtual
name|Is_runnable_type
name|is_runnable
parameter_list|(
name|Workqueue
modifier|*
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Return a pointer to a Task_locker which locks all the resources
comment|// required by the task.  We delete the pointer when the task is
comment|// complete.  This method can return NULL if no locks are required.
comment|// This method is only called from the main thread.
name|virtual
name|Task_locker
modifier|*
name|locks
parameter_list|(
name|Workqueue
modifier|*
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Run the task.
name|virtual
name|void
name|run
parameter_list|(
name|Workqueue
modifier|*
parameter_list|)
init|=
literal|0
function_decl|;
name|private
label|:
name|Task
argument_list|(
specifier|const
name|Task
operator|&
argument_list|)
expr_stmt|;
name|Task
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Task
operator|&
operator|)
decl_stmt|;
block|}
empty_stmt|;
comment|// A simple task which waits for a blocker and then runs a function.
name|class
name|Task_function_runner
block|{
name|public
label|:
name|virtual
operator|~
name|Task_function_runner
argument_list|()
block|{ }
name|virtual
name|void
name|run
argument_list|(
name|Workqueue
operator|*
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
name|class
name|Task_function
range|:
name|public
name|Task
block|{
name|public
operator|:
comment|// Both points should be allocated using new, and will be deleted
comment|// after the task runs.
name|Task_function
argument_list|(
name|Task_function_runner
operator|*
name|runner
argument_list|,
name|Task_token
operator|*
name|blocker
argument_list|)
operator|:
name|runner_
argument_list|(
name|runner
argument_list|)
block|,
name|blocker_
argument_list|(
argument|blocker
argument_list|)
block|{ }
operator|~
name|Task_function
argument_list|()
block|{
name|delete
name|this
operator|->
name|runner_
block|;
name|delete
name|this
operator|->
name|blocker_
block|;   }
comment|// The standard task methods.
comment|// Wait until the task is unblocked.
name|Is_runnable_type
name|is_runnable
argument_list|(
argument|Workqueue*
argument_list|)
block|{
return|return
name|this
operator|->
name|blocker_
operator|->
name|is_blocked
argument_list|()
operator|?
name|IS_BLOCKED
operator|:
name|IS_RUNNABLE
return|;
block|}
comment|// This type of task does not normally hold any locks.
name|virtual
name|Task_locker
operator|*
name|locks
argument_list|(
argument|Workqueue*
argument_list|)
block|{
return|return
name|NULL
return|;
block|}
comment|// Run the action.
name|void
name|run
argument_list|(
argument|Workqueue* workqueue
argument_list|)
block|{
name|this
operator|->
name|runner_
operator|->
name|run
argument_list|(
name|workqueue
argument_list|)
block|; }
name|private
operator|:
name|Task_function
argument_list|(
specifier|const
name|Task_function
operator|&
argument_list|)
block|;
name|Task_function
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Task_function
operator|&
operator|)
block|;
name|Task_function_runner
operator|*
name|runner_
block|;
name|Task_token
operator|*
name|blocker_
block|; }
decl_stmt|;
comment|// The workqueue
name|class
name|Workqueue_runner
decl_stmt|;
name|class
name|Workqueue
block|{
name|public
label|:
name|Workqueue
argument_list|(
specifier|const
name|General_options
operator|&
argument_list|)
expr_stmt|;
operator|~
name|Workqueue
argument_list|()
expr_stmt|;
comment|// Add a new task to the work queue.
name|void
name|queue
parameter_list|(
name|Task
modifier|*
parameter_list|)
function_decl|;
comment|// Add a new task to the front of the work queue.  It will be the
comment|// next task to run if it is ready.
name|void
name|queue_front
parameter_list|(
name|Task
modifier|*
parameter_list|)
function_decl|;
comment|// Process all the tasks on the work queue.
name|void
name|process
parameter_list|()
function_decl|;
comment|// A complete set of blocking tasks has completed.
name|void
name|cleared_blocker
parameter_list|()
function_decl|;
name|private
label|:
comment|// This class can not be copied.
name|Workqueue
argument_list|(
specifier|const
name|Workqueue
operator|&
argument_list|)
expr_stmt|;
name|Workqueue
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Workqueue
operator|&
operator|)
decl_stmt|;
typedef|typedef
name|std
operator|::
name|list
operator|<
name|Task
operator|*
operator|>
name|Task_list
expr_stmt|;
comment|// Run a task.
name|void
name|run
parameter_list|(
name|Task
modifier|*
parameter_list|)
function_decl|;
name|friend
name|class
name|Workqueue_runner
decl_stmt|;
comment|// Find a runnable task.
name|Task
modifier|*
name|find_runnable
parameter_list|(
name|Task_list
modifier|&
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
comment|// Add a lock to the completed queue.
name|void
name|completed
parameter_list|(
name|Task
modifier|*
parameter_list|,
name|Task_locker
modifier|*
parameter_list|)
function_decl|;
comment|// Clear the completed queue.
name|bool
name|clear_completed
parameter_list|()
function_decl|;
comment|// How to run a task.  Only accessed from main thread.
name|Workqueue_runner
modifier|*
name|runner_
decl_stmt|;
comment|// Lock for access to tasks_ members.
name|Lock
name|tasks_lock_
decl_stmt|;
comment|// List of tasks to execute at each link level.
name|Task_list
name|tasks_
decl_stmt|;
comment|// Lock for access to completed_ and running_ members.
name|Lock
name|completed_lock_
decl_stmt|;
comment|// List of Task_locker objects for main thread to free.
name|std
operator|::
name|list
operator|<
name|Task_locker
operator|*
operator|>
name|completed_
expr_stmt|;
comment|// Number of tasks currently running.
name|int
name|running_
decl_stmt|;
comment|// Condition variable signalled when a new entry is added to completed_.
name|Condvar
name|completed_condvar_
decl_stmt|;
comment|// Number of blocker tokens which were fully cleared.  Only accessed
comment|// from main thread.
name|int
name|cleared_blockers_
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace gold.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_WORKQUEUE_H)
end_comment

end_unit

