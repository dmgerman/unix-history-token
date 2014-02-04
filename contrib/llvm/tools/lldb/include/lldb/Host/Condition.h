begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Condition.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_DBCondition_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DBCondition_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|TimeValue
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class Condition Condition.h "lldb/Host/Condition.h"
comment|/// @brief A C++ wrapper class for pthread condition variables.
comment|///
comment|/// A class that wraps up a pthread condition (pthread_cond_t). The
comment|/// class will create a pthread condition when an instance is
comment|/// constructed, and detroy it when it is destructed. It also provides
comment|/// access to the standard pthread condition calls.
comment|//----------------------------------------------------------------------
name|class
name|Condition
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Default constructor
comment|///
comment|/// The default constructor will initialize a new pthread condition
comment|/// and maintain the condition in the object state.
comment|//------------------------------------------------------------------
name|Condition
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|///
comment|/// Destroys the pthread condition that the object owns.
comment|//------------------------------------------------------------------
operator|~
name|Condition
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Unblock all threads waiting for a condition variable
comment|///
comment|/// @return
comment|///     The return value from \c pthread_cond_broadcast()
comment|//------------------------------------------------------------------
name|int
name|Broadcast
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Unblocks one thread waiting for the condition variable
comment|///
comment|/// @return
comment|///     The return value from \c pthread_cond_signal()
comment|//------------------------------------------------------------------
name|int
name|Signal
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Wait for the condition variable to be signaled.
comment|///
comment|/// The Wait() function atomically blocks the current thread
comment|/// waiting on this object's condition variable, and unblocks
comment|/// \a mutex. The waiting thread unblocks only after another thread
comment|/// signals or broadcasts this object's condition variable.
comment|///
comment|/// If \a abstime is non-NULL, this function will return when the
comment|/// system time reaches the time specified in \a abstime if the
comment|/// condition variable doesn't get unblocked. If \a abstime is NULL
comment|/// this function will wait for an infinite amount of time for the
comment|/// condition variable to be unblocked.
comment|///
comment|/// The current thread re-acquires the lock on \a mutex following
comment|/// the wait.
comment|///
comment|/// @param[in] mutex
comment|///     The mutex to use in the \c pthread_cond_timedwait() or
comment|///     \c pthread_cond_wait() calls.
comment|///
comment|/// @param[in] abstime
comment|///     An absolute time at which to stop waiting if non-NULL, else
comment|///     wait an infinite amount of time for the condition variable
comment|///     toget signaled.
comment|///
comment|/// @param[out] timed_out
comment|///     If not NULL, will be set to true if the wait timed out, and
comment|//      false otherwise.
comment|///
comment|/// @see Condition::Broadcast()
comment|/// @see Condition::Signal()
comment|//------------------------------------------------------------------
name|int
name|Wait
parameter_list|(
name|Mutex
modifier|&
name|mutex
parameter_list|,
specifier|const
name|TimeValue
modifier|*
name|abstime
init|=
name|NULL
parameter_list|,
name|bool
modifier|*
name|timed_out
init|=
name|NULL
parameter_list|)
function_decl|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|condition_t
name|m_condition
expr_stmt|;
comment|///< The condition variable.
comment|//------------------------------------------------------------------
comment|/// Get accessor to the pthread condition object.
comment|///
comment|/// @return
comment|///     A pointer to the condition variable owned by this object.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|condition_t
operator|*
name|GetCondition
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

