begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DNBTimer.h ----------------------------------------------*- C++ -*-===//
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
comment|//  Created by Greg Clayton on 12/13/07.
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
name|__DNBTimer_h__
end_ifndef

begin_define
define|#
directive|define
name|__DNBTimer_h__
end_define

begin_include
include|#
directive|include
file|"DNBDefs.h"
end_include

begin_include
include|#
directive|include
file|"PThreadMutex.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_decl_stmt
name|class
name|DNBTimer
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|DNBTimer
argument_list|(
argument|bool threadSafe
argument_list|)
block|:
name|m_mutexAP
argument_list|()
block|{
if|if
condition|(
name|threadSafe
condition|)
name|m_mutexAP
operator|.
name|reset
argument_list|(
argument|new PThreadMutex(PTHREAD_MUTEX_RECURSIVE)
argument_list|)
expr_stmt|;
name|Reset
argument_list|()
expr_stmt|;
block|}
name|DNBTimer
argument_list|(
specifier|const
name|DNBTimer
operator|&
name|rhs
argument_list|)
operator|:
name|m_mutexAP
argument_list|()
block|{
comment|// Create a new mutex to make this timer thread safe as well if
comment|// the timer we are copying is thread safe
if|if
condition|(
name|rhs
operator|.
name|IsThreadSafe
argument_list|()
condition|)
name|m_mutexAP
operator|.
name|reset
argument_list|(
argument|new PThreadMutex(PTHREAD_MUTEX_RECURSIVE)
argument_list|)
expr_stmt|;
name|m_timeval
operator|=
name|rhs
operator|.
name|m_timeval
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|DNBTimer
modifier|&
name|operator
init|=
operator|(
specifier|const
name|DNBTimer
operator|&
name|rhs
operator|)
block|{
comment|// Create a new mutex to make this timer thread safe as well if
comment|// the timer we are copying is thread safe
if|if
condition|(
name|rhs
operator|.
name|IsThreadSafe
argument_list|()
condition|)
name|m_mutexAP
operator|.
name|reset
argument_list|(
argument|new PThreadMutex(PTHREAD_MUTEX_RECURSIVE)
argument_list|)
expr_stmt|;
name|m_timeval
operator|=
name|rhs
operator|.
name|m_timeval
decl_stmt|;
end_decl_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_macro
unit|}    ~
name|DNBTimer
argument_list|()
end_macro

begin_block
block|{}
end_block

begin_expr_stmt
name|bool
name|IsThreadSafe
argument_list|()
specifier|const
block|{
return|return
name|m_mutexAP
operator|.
name|get
argument_list|()
operator|!=
name|NULL
return|;
block|}
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Reset the time value to now
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function
name|void
name|Reset
parameter_list|()
block|{
name|PTHREAD_MUTEX_LOCKER
argument_list|(
name|locker
argument_list|,
name|m_mutexAP
operator|.
name|get
argument_list|()
argument_list|)
expr_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|m_timeval
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Get the total mircoseconds since Jan 1, 1970
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|uint64_t
name|TotalMicroSeconds
argument_list|()
specifier|const
block|{
name|PTHREAD_MUTEX_LOCKER
argument_list|(
name|locker
argument_list|,
name|m_mutexAP
operator|.
name|get
argument_list|()
argument_list|)
block|;
return|return
call|(
name|uint64_t
call|)
argument_list|(
name|m_timeval
operator|.
name|tv_sec
argument_list|)
operator|*
literal|1000000ull
operator|+
operator|(
name|uint64_t
operator|)
name|m_timeval
operator|.
name|tv_usec
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|GetTime
argument_list|(
name|uint64_t
operator|&
name|sec
argument_list|,
name|uint32_t
operator|&
name|usec
argument_list|)
decl|const
block|{
name|PTHREAD_MUTEX_LOCKER
argument_list|(
name|locker
argument_list|,
name|m_mutexAP
operator|.
name|get
argument_list|()
argument_list|)
expr_stmt|;
name|sec
operator|=
name|m_timeval
operator|.
name|tv_sec
expr_stmt|;
name|usec
operator|=
name|m_timeval
operator|.
name|tv_usec
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Return the number of microseconds elapsed between now and the
end_comment

begin_comment
comment|// m_timeval
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function
name|uint64_t
name|ElapsedMicroSeconds
parameter_list|(
name|bool
name|update
parameter_list|)
block|{
name|PTHREAD_MUTEX_LOCKER
argument_list|(
name|locker
argument_list|,
name|m_mutexAP
operator|.
name|get
argument_list|()
argument_list|)
expr_stmt|;
name|struct
name|timeval
name|now
decl_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|now
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|uint64_t
name|now_usec
init|=
call|(
name|uint64_t
call|)
argument_list|(
name|now
operator|.
name|tv_sec
argument_list|)
operator|*
literal|1000000ull
operator|+
operator|(
name|uint64_t
operator|)
name|now
operator|.
name|tv_usec
decl_stmt|;
name|uint64_t
name|this_usec
init|=
call|(
name|uint64_t
call|)
argument_list|(
name|m_timeval
operator|.
name|tv_sec
argument_list|)
operator|*
literal|1000000ull
operator|+
operator|(
name|uint64_t
operator|)
name|m_timeval
operator|.
name|tv_usec
decl_stmt|;
name|uint64_t
name|elapsed
init|=
name|now_usec
operator|-
name|this_usec
decl_stmt|;
comment|// Update the timer time value if requeseted
if|if
condition|(
name|update
condition|)
name|m_timeval
operator|=
name|now
expr_stmt|;
return|return
name|elapsed
return|;
block|}
end_function

begin_function
specifier|static
name|uint64_t
name|GetTimeOfDay
parameter_list|()
block|{
name|struct
name|timeval
name|now
decl_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|now
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|uint64_t
name|now_usec
init|=
call|(
name|uint64_t
call|)
argument_list|(
name|now
operator|.
name|tv_sec
argument_list|)
operator|*
literal|1000000ull
operator|+
operator|(
name|uint64_t
operator|)
name|now
operator|.
name|tv_usec
decl_stmt|;
return|return
name|now_usec
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|OffsetTimeOfDay
parameter_list|(
name|struct
name|timespec
modifier|*
name|ts
parameter_list|,
name|__darwin_time_t
name|sec_offset
init|=
literal|0
parameter_list|,
name|long
name|nsec_offset
init|=
literal|0
parameter_list|)
block|{
if|if
condition|(
name|ts
operator|==
name|NULL
condition|)
return|return;
comment|// Get the current time in a timeval structure
name|struct
name|timeval
name|now
decl_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|now
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// Morph it into a timespec
name|TIMEVAL_TO_TIMESPEC
argument_list|(
operator|&
name|now
argument_list|,
name|ts
argument_list|)
expr_stmt|;
comment|// Offset the timespec if requested
if|if
condition|(
name|sec_offset
operator|!=
literal|0
operator|||
name|nsec_offset
operator|!=
literal|0
condition|)
block|{
comment|// Offset the nano seconds
name|ts
operator|->
name|tv_nsec
operator|+=
name|nsec_offset
expr_stmt|;
comment|// Offset the seconds taking into account a nano-second overflow
name|ts
operator|->
name|tv_sec
operator|=
name|ts
operator|->
name|tv_sec
operator|+
name|ts
operator|->
name|tv_nsec
operator|/
literal|1000000000
operator|+
name|sec_offset
expr_stmt|;
comment|// Trim the nanoseconds back there was an overflow
name|ts
operator|->
name|tv_nsec
operator|=
name|ts
operator|->
name|tv_nsec
operator|%
literal|1000000000
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|bool
name|TimeOfDayLaterThan
parameter_list|(
name|struct
name|timespec
modifier|&
name|ts
parameter_list|)
block|{
name|struct
name|timespec
name|now
decl_stmt|;
name|OffsetTimeOfDay
argument_list|(
operator|&
name|now
argument_list|)
expr_stmt|;
if|if
condition|(
name|now
operator|.
name|tv_sec
operator|>
name|ts
operator|.
name|tv_sec
condition|)
return|return
name|true
return|;
elseif|else
if|if
condition|(
name|now
operator|.
name|tv_sec
operator|<
name|ts
operator|.
name|tv_sec
condition|)
return|return
name|false
return|;
else|else
block|{
if|if
condition|(
name|now
operator|.
name|tv_nsec
operator|>
name|ts
operator|.
name|tv_nsec
condition|)
return|return
name|true
return|;
else|else
return|return
name|false
return|;
block|}
block|}
end_function

begin_label
name|protected
label|:
end_label

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Classes that inherit from DNBTimer can see and modify these
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|PThreadMutex
operator|>
name|m_mutexAP
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|timeval
name|m_timeval
decl_stmt|;
end_decl_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef __DNBTimer_h__
end_comment

end_unit

