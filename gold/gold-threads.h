begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// gold-threads.h -- thread support for gold  -*- C++ -*-
end_comment

begin_comment
comment|// gold can be configured to support threads.  If threads are
end_comment

begin_comment
comment|// supported, the user can specify at runtime whether or not to
end_comment

begin_comment
comment|// support them.  This provides an interface to manage locking
end_comment

begin_comment
comment|// accordingly.
end_comment

begin_comment
comment|// Lock
end_comment

begin_comment
comment|//   A simple lock class.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_THREADS_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_THREADS_H
end_define

begin_decl_stmt
name|namespace
name|gold
block|{
name|class
name|Lock_impl
decl_stmt|;
name|class
name|Condvar
decl_stmt|;
comment|// A simple lock class.
name|class
name|Lock
block|{
name|public
label|:
name|Lock
argument_list|()
expr_stmt|;
operator|~
name|Lock
argument_list|()
expr_stmt|;
comment|// Acquire the lock.
name|void
name|acquire
parameter_list|()
function_decl|;
comment|// Release the lock.
name|void
name|release
parameter_list|()
function_decl|;
name|private
label|:
comment|// This class can not be copied.
name|Lock
argument_list|(
specifier|const
name|Lock
operator|&
argument_list|)
expr_stmt|;
name|Lock
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Lock
operator|&
operator|)
decl_stmt|;
name|friend
name|class
name|Condvar
decl_stmt|;
name|Lock_impl
operator|*
name|get_impl
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|lock_
return|;
block|}
name|Lock_impl
modifier|*
name|lock_
decl_stmt|;
block|}
empty_stmt|;
comment|// RAII for Lock.
name|class
name|Hold_lock
block|{
name|public
label|:
name|Hold_lock
argument_list|(
name|Lock
operator|&
name|lock
argument_list|)
operator|:
name|lock_
argument_list|(
argument|lock
argument_list|)
block|{
name|this
operator|->
name|lock_
operator|.
name|acquire
argument_list|()
block|; }
operator|~
name|Hold_lock
argument_list|()
block|{
name|this
operator|->
name|lock_
operator|.
name|release
argument_list|()
block|; }
name|private
operator|:
comment|// This class can not be copied.
name|Hold_lock
argument_list|(
specifier|const
name|Hold_lock
operator|&
argument_list|)
expr_stmt|;
name|Hold_lock
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Hold_lock
operator|&
operator|)
decl_stmt|;
name|Lock
modifier|&
name|lock_
decl_stmt|;
block|}
empty_stmt|;
name|class
name|Condvar_impl
decl_stmt|;
comment|// A simple condition variable class.  It is always associated with a
comment|// specific lock.
name|class
name|Condvar
block|{
name|public
label|:
name|Condvar
argument_list|(
name|Lock
operator|&
name|lock
argument_list|)
expr_stmt|;
operator|~
name|Condvar
argument_list|()
expr_stmt|;
comment|// Wait for the condition variable to be signalled.  This should
comment|// only be called when the lock is held.
name|void
name|wait
parameter_list|()
function_decl|;
comment|// Signal the condition variable.  This should only be called when
comment|// the lock is held.
name|void
name|signal
parameter_list|()
function_decl|;
name|private
label|:
comment|// This class can not be copied.
name|Condvar
argument_list|(
specifier|const
name|Condvar
operator|&
argument_list|)
expr_stmt|;
name|Condvar
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Condvar
operator|&
operator|)
decl_stmt|;
name|Lock
modifier|&
name|lock_
decl_stmt|;
name|Condvar_impl
modifier|*
name|condvar_
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
comment|// !defined(GOLD_THREADS_H)
end_comment

end_unit

