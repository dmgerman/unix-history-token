begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Mutex.h -------------------------------------------------*- C++ -*-===//
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
name|liblldb_Mutex_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Mutex_h_
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
file|<assert.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|LLDB_CONFIGURATION_DEBUG
end_ifdef

begin_include
include|#
directive|include
file|<string>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Mutex Mutex.h "lldb/Host/Mutex.h"
comment|/// @brief A C++ wrapper class for pthread mutexes.
comment|//----------------------------------------------------------------------
name|class
name|Mutex
block|{
name|public
label|:
name|friend
name|class
name|Locker
decl_stmt|;
name|friend
name|class
name|Condition
decl_stmt|;
enum|enum
name|Type
block|{
name|eMutexTypeNormal
block|,
comment|///< Mutex that can't recursively entered by the same thread
name|eMutexTypeRecursive
comment|///< Mutex can be recursively entered by the same thread
block|}
enum|;
comment|//------------------------------------------------------------------
comment|/// @class Mutex::Locker
comment|///
comment|/// A scoped locking class that allows a variety of pthread mutex
comment|/// objects to have a mutex locked when an Mutex::Locker
comment|/// object is created, and unlocked when it goes out of scope or
comment|/// when the Mutex::Locker::Reset(pthread_mutex_t *)
comment|/// is called. This provides an exception safe way to lock a mutex
comment|/// in a scope.
comment|//------------------------------------------------------------------
name|class
name|Locker
block|{
name|public
label|:
comment|//--------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// This will create a scoped mutex locking object that doesn't
comment|/// have a mutex to lock. One will need to be provided using the
comment|/// Mutex::Locker::Reset(pthread_mutex_t *) method.
comment|///
comment|/// @see Mutex::Locker::Reset(pthread_mutex_t *)
comment|//--------------------------------------------------------------
name|Locker
argument_list|()
expr_stmt|;
comment|//--------------------------------------------------------------
comment|/// Constructor with a Mutex object.
comment|///
comment|/// This will create a scoped mutex locking object that extracts
comment|/// the mutex owned by \a m and locks it.
comment|///
comment|/// @param[in] m
comment|///     An instance of a Mutex object that contains a
comment|///     valid mutex object.
comment|//--------------------------------------------------------------
name|Locker
argument_list|(
name|Mutex
operator|&
name|m
argument_list|)
expr_stmt|;
comment|//--------------------------------------------------------------
comment|/// Constructor with a Mutex object pointer.
comment|///
comment|/// This will create a scoped mutex locking object that extracts
comment|/// the mutex owned by a m and locks it.
comment|///
comment|/// @param[in] m
comment|///     A pointer to instance of a Mutex object that
comment|///     contains a valid mutex object.
comment|//--------------------------------------------------------------
name|Locker
argument_list|(
name|Mutex
operator|*
name|m
argument_list|)
expr_stmt|;
comment|//--------------------------------------------------------------
comment|/// Desstructor
comment|///
comment|/// Unlocks any valid pthread_mutex_t that this object may
comment|/// contain.
comment|//--------------------------------------------------------------
operator|~
name|Locker
argument_list|()
expr_stmt|;
comment|//--------------------------------------------------------------
comment|/// Change the contained mutex.
comment|///
comment|/// Unlock the current mutex in this object (if it contains a
comment|/// valid mutex) and lock the new \a mutex object if it is
comment|/// non-NULL.
comment|//--------------------------------------------------------------
name|void
name|Lock
parameter_list|(
name|Mutex
modifier|&
name|mutex
parameter_list|)
function_decl|;
name|void
name|Lock
parameter_list|(
name|Mutex
modifier|*
name|mutex
parameter_list|)
block|{
if|if
condition|(
name|mutex
condition|)
name|Lock
argument_list|(
operator|*
name|mutex
argument_list|)
expr_stmt|;
block|}
comment|//--------------------------------------------------------------
comment|/// Change the contained mutex only if the mutex can be locked.
comment|///
comment|/// Unlock the current mutex in this object (if it contains a
comment|/// valid mutex) and try to lock \a mutex. If \a mutex can be
comment|/// locked this object will take ownership of the lock and will
comment|/// unlock it when it goes out of scope or Reset or TryLock are
comment|/// called again. If the mutex is already locked, this object
comment|/// will not take ownership of the mutex.
comment|///
comment|/// @return
comment|///     Returns \b true if the lock was aquired and the this
comment|///     object will unlock the mutex when it goes out of scope,
comment|///     returns \b false otherwise.
comment|//--------------------------------------------------------------
name|bool
name|TryLock
parameter_list|(
name|Mutex
modifier|&
name|mutex
parameter_list|,
specifier|const
name|char
modifier|*
name|failure_message
init|=
name|NULL
parameter_list|)
function_decl|;
name|bool
name|TryLock
parameter_list|(
name|Mutex
modifier|*
name|mutex
parameter_list|,
specifier|const
name|char
modifier|*
name|failure_message
init|=
name|NULL
parameter_list|)
block|{
if|if
condition|(
name|mutex
condition|)
return|return
name|TryLock
argument_list|(
operator|*
name|mutex
argument_list|,
name|failure_message
argument_list|)
return|;
else|else
return|return
name|false
return|;
block|}
name|void
name|Unlock
parameter_list|()
function_decl|;
name|protected
label|:
comment|//--------------------------------------------------------------
comment|/// Member variables
comment|//--------------------------------------------------------------
name|Mutex
modifier|*
name|m_mutex_ptr
decl_stmt|;
name|private
label|:
name|Locker
argument_list|(
specifier|const
name|Locker
operator|&
argument_list|)
expr_stmt|;
specifier|const
name|Locker
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Locker
operator|&
operator|)
decl_stmt|;
block|}
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// Creates a pthread mutex with no attributes.
comment|//------------------------------------------------------------------
name|Mutex
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// Creates a pthread mutex with \a type as the mutex type.
comment|/// Valid values for \a type include:
comment|///     @li Mutex::Type::eMutexTypeNormal
comment|///     @li Mutex::Type::eMutexTypeRecursive
comment|///
comment|/// @param[in] type
comment|///     The type of the mutex.
comment|///
comment|/// @see ::pthread_mutexattr_settype()
comment|//------------------------------------------------------------------
name|Mutex
argument_list|(
argument|Mutex::Type type
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// Destroys the mutex owned by this object.
comment|//------------------------------------------------------------------
ifdef|#
directive|ifdef
name|LLDB_CONFIGURATION_DEBUG
name|virtual
endif|#
directive|endif
operator|~
name|Mutex
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Lock the mutex.
comment|///
comment|/// Locks the mutex owned by this object. If the mutex is already
comment|/// locked, the calling thread will block until the mutex becomes
comment|/// available.
comment|///
comment|/// @return
comment|///     The error code from \c pthread_mutex_lock().
comment|//------------------------------------------------------------------
ifdef|#
directive|ifdef
name|LLDB_CONFIGURATION_DEBUG
name|virtual
endif|#
directive|endif
name|int
name|Lock
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Try to lock the mutex.
comment|///
comment|/// Attempts to lock the mutex owned by this object without blocking.
comment|/// If the mutex is already locked, TryLock() will not block waiting
comment|/// for the mutex, but will return an error condition.
comment|///
comment|/// @return
comment|///     The error code from \c pthread_mutex_trylock().
comment|//------------------------------------------------------------------
ifdef|#
directive|ifdef
name|LLDB_CONFIGURATION_DEBUG
name|virtual
endif|#
directive|endif
name|int
name|TryLock
parameter_list|(
specifier|const
name|char
modifier|*
name|failure_message
init|=
name|NULL
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Unlock the mutex.
comment|///
comment|/// If the current thread holds the lock on the owned mutex, then
comment|/// Unlock() will unlock the mutex. Calling Unlock() on this object
comment|/// when the calling thread does not hold the lock will result in
comment|/// undefined behavior.
comment|///
comment|/// @return
comment|///     The error code from \c pthread_mutex_unlock().
comment|//------------------------------------------------------------------
ifdef|#
directive|ifdef
name|LLDB_CONFIGURATION_DEBUG
name|virtual
endif|#
directive|endif
name|int
name|Unlock
parameter_list|()
function_decl|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
comment|// TODO: Hide the mutex in the implementation file in case we ever need to port to an
comment|// architecture that doesn't have pthread mutexes.
name|lldb
operator|::
name|mutex_t
name|m_mutex
expr_stmt|;
comment|///< The OS mutex object.
name|private
label|:
comment|//------------------------------------------------------------------
comment|/// Mutex get accessor.
comment|///
comment|/// @return
comment|///     A pointer to the pthread mutex object owned by this object.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|mutex_t
operator|*
name|GetMutex
argument_list|()
expr_stmt|;
name|Mutex
argument_list|(
specifier|const
name|Mutex
operator|&
argument_list|)
expr_stmt|;
specifier|const
name|Mutex
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Mutex
operator|&
operator|)
decl_stmt|;
block|}
empty_stmt|;
ifdef|#
directive|ifdef
name|LLDB_CONFIGURATION_DEBUG
name|class
name|TrackingMutex
range|:
name|public
name|Mutex
block|{
name|public
operator|:
name|TrackingMutex
argument_list|()
operator|:
name|Mutex
argument_list|()
block|{}
name|TrackingMutex
argument_list|(
argument|Mutex::Type type
argument_list|)
operator|:
name|Mutex
argument_list|(
argument|type
argument_list|)
block|{}
name|virtual
operator|~
name|TrackingMutex
argument_list|()
block|{}
name|virtual
name|int
name|Unlock
argument_list|()
block|;
name|virtual
name|int
name|TryLock
argument_list|(
argument|const char *failure_message = NULL
argument_list|)
block|{
name|int
name|return_value
operator|=
name|Mutex
operator|::
name|TryLock
argument_list|()
block|;
if|if
condition|(
name|return_value
operator|!=
literal|0
operator|&&
name|failure_message
operator|!=
name|NULL
condition|)
block|{
name|m_failure_message
operator|.
name|assign
argument_list|(
name|failure_message
argument_list|)
expr_stmt|;
name|m_thread_that_tried
operator|=
name|pthread_self
argument_list|()
expr_stmt|;
block|}
return|return
name|return_value
return|;
block|}
name|protected
operator|:
name|pthread_t
name|m_thread_that_tried
block|;
name|std
operator|::
name|string
name|m_failure_message
block|; }
decl_stmt|;
name|class
name|LoggingMutex
range|:
name|public
name|Mutex
block|{
name|public
operator|:
name|LoggingMutex
argument_list|()
operator|:
name|Mutex
argument_list|()
block|,
name|m_locked
argument_list|(
argument|false
argument_list|)
block|{}
name|LoggingMutex
argument_list|(
argument|Mutex::Type type
argument_list|)
operator|:
name|Mutex
argument_list|(
name|type
argument_list|)
block|,
name|m_locked
argument_list|(
argument|false
argument_list|)
block|{}
name|virtual
operator|~
name|LoggingMutex
argument_list|()
block|{}
name|virtual
name|int
name|Lock
argument_list|()
block|;
name|virtual
name|int
name|Unlock
argument_list|()
block|;
name|virtual
name|int
name|TryLock
argument_list|(
specifier|const
name|char
operator|*
name|failure_message
operator|=
name|NULL
argument_list|)
block|;
name|protected
operator|:
name|bool
name|m_locked
block|; }
decl_stmt|;
endif|#
directive|endif
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

