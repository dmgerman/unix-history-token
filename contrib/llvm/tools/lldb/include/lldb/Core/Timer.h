begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Timer.h -------------------------------------------------*- C++ -*-===//
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
name|liblldb_Timer_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Timer_h_
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
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/TimeValue.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Timer Timer.h "lldb/Core/Timer.h"
comment|/// @brief A timer class that simplifies common timing metrics.
comment|///
comment|/// A scoped timer class that allows a variety of pthread mutex
comment|/// objects to have a mutex locked when a Timer::Locker
comment|/// object is created, and unlocked when it goes out of scope or
comment|/// when the Timer::Locker::Reset(pthread_mutex_t *)
comment|/// is called. This provides an exception safe way to lock a mutex
comment|/// in a scope.
comment|//----------------------------------------------------------------------
name|class
name|Timer
block|{
name|public
label|:
specifier|static
name|void
name|Initialize
parameter_list|()
function_decl|;
comment|//--------------------------------------------------------------
comment|/// Default constructor.
comment|//--------------------------------------------------------------
name|Timer
argument_list|(
argument|const char *category
argument_list|,
argument|const char *format
argument_list|,
argument|...
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|//--------------------------------------------------------------
comment|/// Desstructor
comment|//--------------------------------------------------------------
operator|~
name|Timer
argument_list|()
expr_stmt|;
name|void
name|Dump
parameter_list|()
function_decl|;
specifier|static
name|void
name|SetDisplayDepth
parameter_list|(
name|uint32_t
name|depth
parameter_list|)
function_decl|;
specifier|static
name|void
name|SetQuiet
parameter_list|(
name|bool
name|value
parameter_list|)
function_decl|;
specifier|static
name|void
name|DumpCategoryTimes
parameter_list|(
name|Stream
modifier|*
name|s
parameter_list|)
function_decl|;
specifier|static
name|void
name|ResetCategoryTimes
parameter_list|()
function_decl|;
name|protected
label|:
name|void
name|ChildStarted
parameter_list|(
specifier|const
name|TimeValue
modifier|&
name|time
parameter_list|)
function_decl|;
name|void
name|ChildStopped
parameter_list|(
specifier|const
name|TimeValue
modifier|&
name|time
parameter_list|)
function_decl|;
name|uint64_t
name|GetTotalElapsedNanoSeconds
parameter_list|()
function_decl|;
name|uint64_t
name|GetTimerElapsedNanoSeconds
parameter_list|()
function_decl|;
comment|//--------------------------------------------------------------
comment|/// Member variables
comment|//--------------------------------------------------------------
specifier|const
name|char
modifier|*
name|m_category
decl_stmt|;
name|TimeValue
name|m_total_start
decl_stmt|;
name|TimeValue
name|m_timer_start
decl_stmt|;
name|uint64_t
name|m_total_ticks
decl_stmt|;
comment|// Total running time for this timer including when other timers below this are running
name|uint64_t
name|m_timer_ticks
decl_stmt|;
comment|// Ticks for this timer that do not include when other timers below this one are running
specifier|static
name|uint32_t
name|g_depth
decl_stmt|;
specifier|static
name|uint32_t
name|g_display_depth
decl_stmt|;
specifier|static
name|FILE
modifier|*
name|g_file
decl_stmt|;
name|private
label|:
name|Timer
argument_list|()
expr_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Timer
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
name|class
name|IntervalTimer
block|{
name|public
label|:
name|IntervalTimer
argument_list|()
operator|:
name|m_start
argument_list|(
argument|TimeValue::Now()
argument_list|)
block|{     }
operator|~
name|IntervalTimer
argument_list|()
block|{     }
name|uint64_t
name|GetElapsedNanoSeconds
argument_list|()
specifier|const
block|{
return|return
name|TimeValue
operator|::
name|Now
argument_list|()
operator|-
name|m_start
return|;
block|}
name|void
name|Reset
parameter_list|()
block|{
name|m_start
operator|=
name|TimeValue
operator|::
name|Now
argument_list|()
expr_stmt|;
block|}
name|int
name|PrintfElapsed
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function|__attribute__
parameter_list|(
function|(format
parameter_list|(
name|printf
parameter_list|,
function|2
operator|,
function|3
block|)
decl_stmt|)
block|)
block|{
name|TimeValue
name|now
argument_list|(
name|TimeValue
operator|::
name|Now
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|uint64_t
name|elapsed_nsec
init|=
name|now
operator|-
name|m_start
decl_stmt|;
specifier|const
name|char
modifier|*
name|unit
init|=
name|NULL
decl_stmt|;
name|float
name|elapsed_value
decl_stmt|;
if|if
condition|(
name|elapsed_nsec
operator|<
literal|1000
condition|)
block|{
name|unit
operator|=
literal|"ns"
expr_stmt|;
name|elapsed_value
operator|=
operator|(
name|float
operator|)
name|elapsed_nsec
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|elapsed_nsec
operator|<
literal|1000000
condition|)
block|{
name|unit
operator|=
literal|"us"
expr_stmt|;
name|elapsed_value
operator|=
operator|(
name|float
operator|)
name|elapsed_nsec
operator|/
literal|1000.0f
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|elapsed_nsec
operator|<
literal|1000000000
condition|)
block|{
name|unit
operator|=
literal|"ms"
expr_stmt|;
name|elapsed_value
operator|=
operator|(
name|float
operator|)
name|elapsed_nsec
operator|/
literal|1000000.0f
expr_stmt|;
block|}
else|else
block|{
name|unit
operator|=
literal|"sec"
expr_stmt|;
name|elapsed_value
operator|=
operator|(
name|float
operator|)
name|elapsed_nsec
operator|/
literal|1000000000.0f
expr_stmt|;
block|}
name|int
name|result
init|=
name|printf
argument_list|(
literal|"%3.2f %s: "
argument_list|,
name|elapsed_value
argument_list|,
name|unit
argument_list|)
decl_stmt|;
name|va_list
name|args
decl_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|result
operator|+=
name|vprintf
argument_list|(
name|format
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|TimeValue
name|m_start
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
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
comment|// #ifndef liblldb_Timer_h_
end_comment

end_unit

