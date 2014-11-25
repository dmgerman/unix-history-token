begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Predicate.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_Predicate_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Predicate_h_
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
file|"lldb/Host/Mutex.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Condition.h"
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|//#define DB_PTHREAD_LOG_EVENTS
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// Enumerations for broadcasting.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
typedef|typedef
enum|enum
block|{
name|eBroadcastNever
block|,
comment|///< No broadcast will be sent when the value is modified.
name|eBroadcastAlways
block|,
comment|///< Always send a broadcast when the value is modified.
name|eBroadcastOnChange
comment|///< Only broadcast if the value changes when the value is modified.
block|}
name|PredicateBroadcastType
typedef|;
comment|//----------------------------------------------------------------------
comment|/// @class Predicate Predicate.h "lldb/Host/Predicate.h"
comment|/// @brief A C++ wrapper class for providing threaded access to a value
comment|/// of type T.
comment|///
comment|/// A templatized class that provides multi-threaded access to a value
comment|/// of type T. Threads can efficiently wait for bits within T to be set
comment|/// or reset, or wait for T to be set to be equal/not equal to a
comment|/// specified values.
comment|//----------------------------------------------------------------------
name|template
operator|<
name|class
name|T
operator|>
name|class
name|Predicate
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// Initializes the mutex, condition and value with their default
comment|/// constructors.
comment|//------------------------------------------------------------------
name|Predicate
argument_list|()
operator|:
name|m_value
argument_list|()
block|,
name|m_mutex
argument_list|()
block|,
name|m_condition
argument_list|()
block|{     }
comment|//------------------------------------------------------------------
comment|/// Construct with initial T value \a initial_value.
comment|///
comment|/// Initializes the mutex and condition with their default
comment|/// constructors, and initializes the value with \a initial_value.
comment|///
comment|/// @param[in] initial_value
comment|///     The initial value for our T object.
comment|//------------------------------------------------------------------
name|Predicate
argument_list|(
argument|T initial_value
argument_list|)
operator|:
name|m_value
argument_list|(
name|initial_value
argument_list|)
block|,
name|m_mutex
argument_list|()
block|,
name|m_condition
argument_list|()
block|{     }
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// Destroy the condition, mutex, and T objects.
comment|//------------------------------------------------------------------
operator|~
name|Predicate
argument_list|()
block|{     }
comment|//------------------------------------------------------------------
comment|/// Value get accessor.
comment|///
comment|/// Copies the current \a m_value in a thread safe manor and returns
comment|/// the copied value.
comment|///
comment|/// @return
comment|///     A copy of the current value.
comment|//------------------------------------------------------------------
name|T
name|GetValue
argument_list|()
specifier|const
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
block|;
name|T
name|value
operator|=
name|m_value
block|;
return|return
name|value
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Value set accessor.
comment|///
comment|/// Set the contained \a m_value to \a new_value in a thread safe
comment|/// way and broadcast if needed.
comment|///
comment|/// @param[in] value
comment|///     The new value to set.
comment|///
comment|/// @param[in] broadcast_type
comment|///     A value indicating when and if to broadcast. See the
comment|///     PredicateBroadcastType enumeration for details.
comment|///
comment|/// @see Predicate::Broadcast()
comment|//------------------------------------------------------------------
name|void
name|SetValue
argument_list|(
argument|T value
argument_list|,
argument|PredicateBroadcastType broadcast_type
argument_list|)
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
block|;
ifdef|#
directive|ifdef
name|DB_PTHREAD_LOG_EVENTS
name|printf
argument_list|(
literal|"%s (value = 0x%8.8x, broadcast_type = %i)\n"
argument_list|,
name|__FUNCTION__
argument_list|,
name|value
argument_list|,
name|broadcast_type
argument_list|)
block|;
endif|#
directive|endif
specifier|const
name|T
name|old_value
operator|=
name|m_value
block|;
name|m_value
operator|=
name|value
block|;
name|Broadcast
argument_list|(
name|old_value
argument_list|,
name|broadcast_type
argument_list|)
block|;     }
comment|//------------------------------------------------------------------
comment|/// Set some bits in \a m_value.
comment|///
comment|/// Logically set the bits \a bits in the contained \a m_value in a
comment|/// thread safe way and broadcast if needed.
comment|///
comment|/// @param[in] bits
comment|///     The bits to set in \a m_value.
comment|///
comment|/// @param[in] broadcast_type
comment|///     A value indicating when and if to broadcast. See the
comment|///     PredicateBroadcastType enumeration for details.
comment|///
comment|/// @see Predicate::Broadcast()
comment|//------------------------------------------------------------------
name|void
name|SetValueBits
argument_list|(
argument|T bits
argument_list|,
argument|PredicateBroadcastType broadcast_type
argument_list|)
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
block|;
ifdef|#
directive|ifdef
name|DB_PTHREAD_LOG_EVENTS
name|printf
argument_list|(
literal|"%s (bits = 0x%8.8x, broadcast_type = %i)\n"
argument_list|,
name|__FUNCTION__
argument_list|,
name|bits
argument_list|,
name|broadcast_type
argument_list|)
block|;
endif|#
directive|endif
specifier|const
name|T
name|old_value
operator|=
name|m_value
block|;
name|m_value
operator||=
name|bits
block|;
name|Broadcast
argument_list|(
name|old_value
argument_list|,
name|broadcast_type
argument_list|)
block|;     }
comment|//------------------------------------------------------------------
comment|/// Reset some bits in \a m_value.
comment|///
comment|/// Logically reset (clear) the bits \a bits in the contained
comment|/// \a m_value in a thread safe way and broadcast if needed.
comment|///
comment|/// @param[in] bits
comment|///     The bits to clear in \a m_value.
comment|///
comment|/// @param[in] broadcast_type
comment|///     A value indicating when and if to broadcast. See the
comment|///     PredicateBroadcastType enumeration for details.
comment|///
comment|/// @see Predicate::Broadcast()
comment|//------------------------------------------------------------------
name|void
name|ResetValueBits
argument_list|(
argument|T bits
argument_list|,
argument|PredicateBroadcastType broadcast_type
argument_list|)
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
block|;
ifdef|#
directive|ifdef
name|DB_PTHREAD_LOG_EVENTS
name|printf
argument_list|(
literal|"%s (bits = 0x%8.8x, broadcast_type = %i)\n"
argument_list|,
name|__FUNCTION__
argument_list|,
name|bits
argument_list|,
name|broadcast_type
argument_list|)
block|;
endif|#
directive|endif
specifier|const
name|T
name|old_value
operator|=
name|m_value
block|;
name|m_value
operator|&=
operator|~
name|bits
block|;
name|Broadcast
argument_list|(
name|old_value
argument_list|,
name|broadcast_type
argument_list|)
block|;     }
comment|//------------------------------------------------------------------
comment|/// Wait for bits to be set in \a m_value.
comment|///
comment|/// Waits in a thread safe way for any bits in \a bits to get
comment|/// logically set in \a m_value. If any bits are already set in
comment|/// \a m_value, this function will return without waiting.
comment|///
comment|/// It is possible for the value to be changed between the time
comment|/// the bits are set and the time the waiting thread wakes up.
comment|/// If the bits are no longer set when the waiting thread wakes
comment|/// up, it will go back into a wait state.  It may be necessary
comment|/// for the calling code to use additional thread synchronization
comment|/// methods to detect transitory states.
comment|///
comment|/// @param[in] bits
comment|///     The bits we are waiting to be set in \a m_value.
comment|///
comment|/// @param[in] abstime
comment|///     If non-NULL, the absolute time at which we should stop
comment|///     waiting, else wait an infinite amount of time.
comment|///
comment|/// @return
comment|///     Any bits of the requested bits that actually were set within
comment|///     the time specified. Zero if a timeout or unrecoverable error
comment|///     occurred.
comment|//------------------------------------------------------------------
name|T
name|WaitForSetValueBits
argument_list|(
argument|T bits
argument_list|,
argument|const TimeValue *abstime = NULL
argument_list|)
block|{
name|int
name|err
operator|=
literal|0
block|;
comment|// pthread_cond_timedwait() or pthread_cond_wait() will atomically
comment|// unlock the mutex and wait for the condition to be set. When either
comment|// function returns, they will re-lock the mutex. We use an auto lock/unlock
comment|// class (Mutex::Locker) to allow us to return at any point in this
comment|// function and not have to worry about unlocking the mutex.
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
block|;
ifdef|#
directive|ifdef
name|DB_PTHREAD_LOG_EVENTS
name|printf
argument_list|(
literal|"%s (bits = 0x%8.8x, abstime = %p), m_value = 0x%8.8x\n"
argument_list|,
name|__FUNCTION__
argument_list|,
name|bits
argument_list|,
name|abstime
argument_list|,
name|m_value
argument_list|)
block|;
endif|#
directive|endif
while|while
condition|(
name|err
operator|==
literal|0
operator|&&
operator|(
operator|(
name|m_value
operator|&
name|bits
operator|)
operator|==
literal|0
operator|)
condition|)
block|{
name|err
operator|=
name|m_condition
operator|.
name|Wait
argument_list|(
name|m_mutex
argument_list|,
name|abstime
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|DB_PTHREAD_LOG_EVENTS
name|printf
argument_list|(
literal|"%s (bits = 0x%8.8x), m_value = 0x%8.8x, returning 0x%8.8x\n"
argument_list|,
name|__FUNCTION__
argument_list|,
name|bits
argument_list|,
name|m_value
argument_list|,
name|m_value
operator|&
name|bits
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|m_value
operator|&
name|bits
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Wait for bits to be reset in \a m_value.
comment|///
comment|/// Waits in a thread safe way for any bits in \a bits to get
comment|/// logically reset in \a m_value. If all bits are already reset in
comment|/// \a m_value, this function will return without waiting.
comment|///
comment|/// It is possible for the value to be changed between the time
comment|/// the bits are reset and the time the waiting thread wakes up.
comment|/// If the bits are no set when the waiting thread wakes up, it will
comment|/// go back into a wait state.  It may be necessary for the calling
comment|/// code to use additional thread synchronization methods to detect
comment|/// transitory states.
comment|///
comment|/// @param[in] bits
comment|///     The bits we are waiting to be reset in \a m_value.
comment|///
comment|/// @param[in] abstime
comment|///     If non-NULL, the absolute time at which we should stop
comment|///     waiting, else wait an infinite amount of time.
comment|///
comment|/// @return
comment|///     Zero on successful waits, or non-zero if a timeout or
comment|///     unrecoverable error occurs.
comment|//------------------------------------------------------------------
name|T
name|WaitForResetValueBits
parameter_list|(
name|T
name|bits
parameter_list|,
specifier|const
name|TimeValue
modifier|*
name|abstime
init|=
name|NULL
parameter_list|)
block|{
name|int
name|err
init|=
literal|0
decl_stmt|;
comment|// pthread_cond_timedwait() or pthread_cond_wait() will atomically
comment|// unlock the mutex and wait for the condition to be set. When either
comment|// function returns, they will re-lock the mutex. We use an auto lock/unlock
comment|// class (Mutex::Locker) to allow us to return at any point in this
comment|// function and not have to worry about unlocking the mutex.
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DB_PTHREAD_LOG_EVENTS
name|printf
argument_list|(
literal|"%s (bits = 0x%8.8x, abstime = %p), m_value = 0x%8.8x\n"
argument_list|,
name|__FUNCTION__
argument_list|,
name|bits
argument_list|,
name|abstime
argument_list|,
name|m_value
argument_list|)
expr_stmt|;
endif|#
directive|endif
while|while
condition|(
name|err
operator|==
literal|0
operator|&&
operator|(
operator|(
name|m_value
operator|&
name|bits
operator|)
operator|!=
literal|0
operator|)
condition|)
block|{
name|err
operator|=
name|m_condition
operator|.
name|Wait
argument_list|(
name|m_mutex
argument_list|,
name|abstime
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|DB_PTHREAD_LOG_EVENTS
name|printf
argument_list|(
literal|"%s (bits = 0x%8.8x), m_value = 0x%8.8x, returning 0x%8.8x\n"
argument_list|,
name|__FUNCTION__
argument_list|,
name|bits
argument_list|,
name|m_value
argument_list|,
name|m_value
operator|&
name|bits
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|m_value
operator|&
name|bits
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Wait for \a m_value to be equal to \a value.
comment|///
comment|/// Waits in a thread safe way for \a m_value to be equal to \a
comment|/// value. If \a m_value is already equal to \a value, this
comment|/// function will return without waiting.
comment|///
comment|/// It is possible for the value to be changed between the time
comment|/// the value is set and the time the waiting thread wakes up.
comment|/// If the value no longer matches the requested value when the
comment|/// waiting thread wakes up, it will go back into a wait state.  It
comment|/// may be necessary for the calling code to use additional thread
comment|/// synchronization methods to detect transitory states.
comment|///
comment|/// @param[in] value
comment|///     The value we want \a m_value to be equal to.
comment|///
comment|/// @param[in] abstime
comment|///     If non-NULL, the absolute time at which we should stop
comment|///     waiting, else wait an infinite amount of time.
comment|///
comment|/// @param[out] timed_out
comment|///     If not null, set to true if we return because of a time out,
comment|///     and false if the value was set.
comment|///
comment|/// @return
comment|///     @li \b true if the \a m_value is equal to \a value
comment|///     @li \b false otherwise
comment|//------------------------------------------------------------------
name|bool
name|WaitForValueEqualTo
parameter_list|(
name|T
name|value
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
block|{
name|int
name|err
init|=
literal|0
decl_stmt|;
comment|// pthread_cond_timedwait() or pthread_cond_wait() will atomically
comment|// unlock the mutex and wait for the condition to be set. When either
comment|// function returns, they will re-lock the mutex. We use an auto lock/unlock
comment|// class (Mutex::Locker) to allow us to return at any point in this
comment|// function and not have to worry about unlocking the mutex.
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DB_PTHREAD_LOG_EVENTS
name|printf
argument_list|(
literal|"%s (value = 0x%8.8x, abstime = %p), m_value = 0x%8.8x\n"
argument_list|,
name|__FUNCTION__
argument_list|,
name|value
argument_list|,
name|abstime
argument_list|,
name|m_value
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|timed_out
condition|)
operator|*
name|timed_out
operator|=
name|false
expr_stmt|;
while|while
condition|(
name|err
operator|==
literal|0
operator|&&
name|m_value
operator|!=
name|value
condition|)
block|{
name|err
operator|=
name|m_condition
operator|.
name|Wait
argument_list|(
name|m_mutex
argument_list|,
name|abstime
argument_list|,
name|timed_out
argument_list|)
expr_stmt|;
block|}
return|return
name|m_value
operator|==
name|value
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Wait for \a m_value to be equal to \a value and then set it to
comment|/// a new value.
comment|///
comment|/// Waits in a thread safe way for \a m_value to be equal to \a
comment|/// value and then sets \a m_value to \a new_value. If \a m_value
comment|/// is already equal to \a value, this function will immediately
comment|/// set \a m_value to \a new_value and return without waiting.
comment|///
comment|/// It is possible for the value to be changed between the time
comment|/// the value is set and the time the waiting thread wakes up.
comment|/// If the value no longer matches the requested value when the
comment|/// waiting thread wakes up, it will go back into a wait state.  It
comment|/// may be necessary for the calling code to use additional thread
comment|/// synchronization methods to detect transitory states.
comment|///
comment|/// @param[in] value
comment|///     The value we want \a m_value to be equal to.
comment|///
comment|/// @param[in] new_value
comment|///     The value to which \a m_value will be set if \b true is
comment|///     returned.
comment|///
comment|/// @param[in] abstime
comment|///     If non-NULL, the absolute time at which we should stop
comment|///     waiting, else wait an infinite amount of time.
comment|///
comment|/// @param[out] timed_out
comment|///     If not null, set to true if we return because of a time out,
comment|///     and false if the value was set.
comment|///
comment|/// @return
comment|///     @li \b true if the \a m_value became equal to \a value
comment|///     @li \b false otherwise
comment|//------------------------------------------------------------------
name|bool
name|WaitForValueEqualToAndSetValueTo
parameter_list|(
name|T
name|wait_value
parameter_list|,
name|T
name|new_value
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
block|{
name|int
name|err
init|=
literal|0
decl_stmt|;
comment|// pthread_cond_timedwait() or pthread_cond_wait() will atomically
comment|// unlock the mutex and wait for the condition to be set. When either
comment|// function returns, they will re-lock the mutex. We use an auto lock/unlock
comment|// class (Mutex::Locker) to allow us to return at any point in this
comment|// function and not have to worry about unlocking the mutex.
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DB_PTHREAD_LOG_EVENTS
name|printf
argument_list|(
literal|"%s (wait_value = 0x%8.8x, new_value = 0x%8.8x, abstime = %p), m_value = 0x%8.8x\n"
argument_list|,
name|__FUNCTION__
argument_list|,
name|wait_value
argument_list|,
name|new_value
argument_list|,
name|abstime
argument_list|,
name|m_value
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|timed_out
condition|)
operator|*
name|timed_out
operator|=
name|false
expr_stmt|;
while|while
condition|(
name|err
operator|==
literal|0
operator|&&
name|m_value
operator|!=
name|wait_value
condition|)
block|{
name|err
operator|=
name|m_condition
operator|.
name|Wait
argument_list|(
name|m_mutex
argument_list|,
name|abstime
argument_list|,
name|timed_out
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|m_value
operator|==
name|wait_value
condition|)
block|{
name|m_value
operator|=
name|new_value
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Wait for \a m_value to not be equal to \a value.
comment|///
comment|/// Waits in a thread safe way for \a m_value to not be equal to \a
comment|/// value. If \a m_value is already not equal to \a value, this
comment|/// function will return without waiting.
comment|///
comment|/// It is possible for the value to be changed between the time
comment|/// the value is set and the time the waiting thread wakes up.
comment|/// If the value is equal to the test value when the waiting thread
comment|/// wakes up, it will go back into a wait state.  It may be
comment|/// necessary for the calling code to use additional thread
comment|/// synchronization methods to detect transitory states.
comment|///
comment|/// @param[in] value
comment|///     The value we want \a m_value to not be equal to.
comment|///
comment|/// @param[out] new_value
comment|///     The new value if \b true is returned.
comment|///
comment|/// @param[in] abstime
comment|///     If non-NULL, the absolute time at which we should stop
comment|///     waiting, else wait an infinite amount of time.
comment|///
comment|/// @return
comment|///     @li \b true if the \a m_value is equal to \a value
comment|///     @li \b false otherwise
comment|//------------------------------------------------------------------
name|bool
name|WaitForValueNotEqualTo
parameter_list|(
name|T
name|value
parameter_list|,
name|T
modifier|&
name|new_value
parameter_list|,
specifier|const
name|TimeValue
modifier|*
name|abstime
init|=
name|NULL
parameter_list|)
block|{
name|int
name|err
init|=
literal|0
decl_stmt|;
comment|// pthread_cond_timedwait() or pthread_cond_wait() will atomically
comment|// unlock the mutex and wait for the condition to be set. When either
comment|// function returns, they will re-lock the mutex. We use an auto lock/unlock
comment|// class (Mutex::Locker) to allow us to return at any point in this
comment|// function and not have to worry about unlocking the mutex.
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DB_PTHREAD_LOG_EVENTS
name|printf
argument_list|(
literal|"%s (value = 0x%8.8x, abstime = %p), m_value = 0x%8.8x\n"
argument_list|,
name|__FUNCTION__
argument_list|,
name|value
argument_list|,
name|abstime
argument_list|,
name|m_value
argument_list|)
expr_stmt|;
endif|#
directive|endif
while|while
condition|(
name|err
operator|==
literal|0
operator|&&
name|m_value
operator|==
name|value
condition|)
block|{
name|err
operator|=
name|m_condition
operator|.
name|Wait
argument_list|(
name|m_mutex
argument_list|,
name|abstime
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|m_value
operator|!=
name|value
condition|)
block|{
name|new_value
operator|=
name|m_value
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|protected
label|:
comment|//----------------------------------------------------------------------
comment|// pthread condition and mutex variable to control access and allow
comment|// blocking between the main thread and the spotlight index thread.
comment|//----------------------------------------------------------------------
name|T
name|m_value
decl_stmt|;
comment|///< The templatized value T that we are protecting access to
name|mutable
name|Mutex
name|m_mutex
decl_stmt|;
comment|///< The mutex to use when accessing the data
name|Condition
name|m_condition
decl_stmt|;
comment|///< The pthread condition variable to use for signaling that data available or changed.
name|private
label|:
comment|//------------------------------------------------------------------
comment|/// Broadcast if needed.
comment|///
comment|/// Check to see if we need to broadcast to our condition variable
comment|/// depending on the \a old_value and on the \a broadcast_type.
comment|///
comment|/// If \a broadcast_type is eBroadcastNever, no broadcast will be
comment|/// sent.
comment|///
comment|/// If \a broadcast_type is eBroadcastAlways, the condition variable
comment|/// will always be broadcast.
comment|///
comment|/// If \a broadcast_type is eBroadcastOnChange, the condition
comment|/// variable be broadcast if the owned value changes.
comment|//------------------------------------------------------------------
name|void
name|Broadcast
parameter_list|(
name|T
name|old_value
parameter_list|,
name|PredicateBroadcastType
name|broadcast_type
parameter_list|)
block|{
name|bool
name|broadcast
init|=
operator|(
name|broadcast_type
operator|==
name|eBroadcastAlways
operator|)
operator|||
operator|(
operator|(
name|broadcast_type
operator|==
name|eBroadcastOnChange
operator|)
operator|&&
name|old_value
operator|!=
name|m_value
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|DB_PTHREAD_LOG_EVENTS
name|printf
argument_list|(
literal|"%s (old_value = 0x%8.8x, broadcast_type = %i) m_value = 0x%8.8x, broadcast = %u\n"
argument_list|,
name|__FUNCTION__
argument_list|,
name|old_value
argument_list|,
name|broadcast_type
argument_list|,
name|m_value
argument_list|,
name|broadcast
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|broadcast
condition|)
name|m_condition
operator|.
name|Broadcast
argument_list|()
expr_stmt|;
block|}
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Predicate
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
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

begin_comment
comment|// #ifndef liblldb_Predicate_h_
end_comment

end_unit

