begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/Timer.h - Interval Timing Support ----------*- C++ -*-===//
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
comment|// This file defines three classes: Timer, TimeRegion, and TimerGroup,
end_comment

begin_comment
comment|// documented below.
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
name|LLVM_SUPPORT_TIMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_TIMER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Mutex.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TimerGroup
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// Timer - This class is used to track the amount of time spent between
comment|/// invocations of its startTimer()/stopTimer() methods.  Given appropriate OS
comment|/// support it can also keep track of the RSS of the program at various points.
comment|/// By default, the Timer will print the amount of time it has captured to
comment|/// standard error when the laster timer is destroyed, otherwise it is printed
comment|/// when its TimerGroup is destroyed.  Timers do not print their information
comment|/// if they are never started.
comment|///
name|class
name|Timer
block|{
name|double
name|Elapsed
decl_stmt|;
comment|// Wall clock time elapsed in seconds
name|double
name|UserTime
decl_stmt|;
comment|// User time elapsed
name|double
name|SystemTime
decl_stmt|;
comment|// System time elapsed
name|ssize_t
name|MemUsed
decl_stmt|;
comment|// Memory allocated (in bytes)
name|size_t
name|PeakMem
decl_stmt|;
comment|// Peak memory used
name|size_t
name|PeakMemBase
decl_stmt|;
comment|// Temporary for peak calculation...
name|std
operator|::
name|string
name|Name
expr_stmt|;
comment|// The name of this time variable
name|bool
name|Started
decl_stmt|;
comment|// Has this time variable ever been started?
name|TimerGroup
modifier|*
name|TG
decl_stmt|;
comment|// The TimerGroup this Timer is in.
name|mutable
name|sys
operator|::
name|SmartMutex
operator|<
name|true
operator|>
name|Lock
expr_stmt|;
comment|// Mutex for the contents of this Timer.
name|public
label|:
name|explicit
name|Timer
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|N
argument_list|)
decl_stmt|;
name|Timer
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|N
argument_list|,
name|TimerGroup
operator|&
name|tg
argument_list|)
expr_stmt|;
name|Timer
argument_list|(
specifier|const
name|Timer
operator|&
name|T
argument_list|)
expr_stmt|;
operator|~
name|Timer
argument_list|()
expr_stmt|;
name|double
name|getProcessTime
argument_list|()
specifier|const
block|{
return|return
name|UserTime
operator|+
name|SystemTime
return|;
block|}
name|double
name|getWallTime
argument_list|()
specifier|const
block|{
return|return
name|Elapsed
return|;
block|}
name|ssize_t
name|getMemUsed
argument_list|()
specifier|const
block|{
return|return
name|MemUsed
return|;
block|}
name|size_t
name|getPeakMem
argument_list|()
specifier|const
block|{
return|return
name|PeakMem
return|;
block|}
name|std
operator|::
name|string
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
specifier|const
name|Timer
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Timer
operator|&
name|T
operator|)
block|{
if|if
condition|(
operator|&
name|T
operator|<
name|this
condition|)
block|{
name|T
operator|.
name|Lock
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|Lock
operator|.
name|acquire
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|Lock
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|T
operator|.
name|Lock
operator|.
name|acquire
argument_list|()
expr_stmt|;
block|}
name|Elapsed
operator|=
name|T
operator|.
name|Elapsed
expr_stmt|;
name|UserTime
operator|=
name|T
operator|.
name|UserTime
decl_stmt|;
name|SystemTime
operator|=
name|T
operator|.
name|SystemTime
expr_stmt|;
name|MemUsed
operator|=
name|T
operator|.
name|MemUsed
expr_stmt|;
name|PeakMem
operator|=
name|T
operator|.
name|PeakMem
expr_stmt|;
name|PeakMemBase
operator|=
name|T
operator|.
name|PeakMemBase
expr_stmt|;
name|Name
operator|=
name|T
operator|.
name|Name
expr_stmt|;
name|Started
operator|=
name|T
operator|.
name|Started
expr_stmt|;
name|assert
argument_list|(
name|TG
operator|==
name|T
operator|.
name|TG
operator|&&
literal|"Can only assign timers in the same TimerGroup!"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|&
name|T
operator|<
name|this
condition|)
block|{
name|T
operator|.
name|Lock
operator|.
name|release
argument_list|()
expr_stmt|;
name|Lock
operator|.
name|release
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|Lock
operator|.
name|release
argument_list|()
expr_stmt|;
name|T
operator|.
name|Lock
operator|.
name|release
argument_list|()
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
comment|// operator< - Allow sorting...
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Timer
operator|&
name|T
operator|)
specifier|const
block|{
comment|// Sort by Wall Time elapsed, as it is the only thing really accurate
return|return
name|Elapsed
operator|<
name|T
operator|.
name|Elapsed
return|;
block|}
name|bool
name|operator
operator|>
operator|(
specifier|const
name|Timer
operator|&
name|T
operator|)
specifier|const
block|{
return|return
name|T
operator|.
name|operator
operator|<
operator|(
operator|*
name|this
operator|)
return|;
block|}
comment|/// startTimer - Start the timer running.  Time between calls to
comment|/// startTimer/stopTimer is counted by the Timer class.  Note that these calls
comment|/// must be correctly paired.
comment|///
name|void
name|startTimer
parameter_list|()
function_decl|;
comment|/// stopTimer - Stop the timer.
comment|///
name|void
name|stopTimer
parameter_list|()
function_decl|;
comment|/// addPeakMemoryMeasurement - This method should be called whenever memory
comment|/// usage needs to be checked.  It adds a peak memory measurement to the
comment|/// currently active timers, which will be printed when the timer group prints
comment|///
specifier|static
name|void
name|addPeakMemoryMeasurement
parameter_list|()
function_decl|;
comment|/// print - Print the current timer to standard error, and reset the "Started"
comment|/// flag.
name|void
name|print
parameter_list|(
specifier|const
name|Timer
modifier|&
name|Total
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|private
label|:
name|friend
name|class
name|TimerGroup
decl_stmt|;
comment|// Copy ctor, initialize with no TG member.
name|Timer
argument_list|(
name|bool
argument_list|,
specifier|const
name|Timer
operator|&
name|T
argument_list|)
expr_stmt|;
comment|/// sum - Add the time accumulated in the specified timer into this timer.
comment|///
name|void
name|sum
parameter_list|(
specifier|const
name|Timer
modifier|&
name|T
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// The TimeRegion class is used as a helper class to call the startTimer() and
end_comment

begin_comment
comment|/// stopTimer() methods of the Timer class.  When the object is constructed, it
end_comment

begin_comment
comment|/// starts the timer specified as it's argument.  When it is destroyed, it stops
end_comment

begin_comment
comment|/// the relevant timer.  This makes it easy to time a region of code.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|TimeRegion
block|{
name|Timer
modifier|*
name|T
decl_stmt|;
name|TimeRegion
argument_list|(
specifier|const
name|TimeRegion
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|explicit
name|TimeRegion
argument_list|(
name|Timer
operator|&
name|t
argument_list|)
operator|:
name|T
argument_list|(
argument|&t
argument_list|)
block|{
name|T
operator|->
name|startTimer
argument_list|()
block|;   }
name|explicit
name|TimeRegion
argument_list|(
name|Timer
operator|*
name|t
argument_list|)
operator|:
name|T
argument_list|(
argument|t
argument_list|)
block|{
if|if
condition|(
name|T
condition|)
name|T
operator|->
name|startTimer
argument_list|()
expr_stmt|;
block|}
operator|~
name|TimeRegion
argument_list|()
block|{
if|if
condition|(
name|T
condition|)
name|T
operator|->
name|stopTimer
argument_list|()
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// NamedRegionTimer - This class is basically a combination of TimeRegion and
end_comment

begin_comment
comment|/// Timer.  It allows you to declare a new timer, AND specify the region to
end_comment

begin_comment
comment|/// time, all in one statement.  All timers with the same name are merged.  This
end_comment

begin_comment
comment|/// is primarily used for debugging and for hunting performance problems.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|struct
name|NamedRegionTimer
range|:
name|public
name|TimeRegion
block|{
name|explicit
name|NamedRegionTimer
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
block|;
name|explicit
name|NamedRegionTimer
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|GroupName
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The TimerGroup class is used to group together related timers into a single
end_comment

begin_comment
comment|/// report that is printed when the TimerGroup is destroyed.  It is illegal to
end_comment

begin_comment
comment|/// destroy a TimerGroup object before all of the Timers in it are gone.  A
end_comment

begin_comment
comment|/// TimerGroup can be specified for a newly created timer in its constructor.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|TimerGroup
block|{
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|unsigned
name|NumTimers
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|Timer
operator|>
name|TimersToPrint
expr_stmt|;
name|public
label|:
name|explicit
name|TimerGroup
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|)
range|:
name|Name
argument_list|(
name|name
argument_list|)
decl_stmt|,
name|NumTimers
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|TimerGroup
argument_list|()
block|{
name|assert
argument_list|(
name|NumTimers
operator|==
literal|0
operator|&&
literal|"TimerGroup destroyed before all contained timers!"
argument_list|)
block|;   }
name|private
operator|:
name|friend
name|class
name|Timer
expr_stmt|;
name|void
name|addTimer
parameter_list|()
function_decl|;
name|void
name|removeTimer
parameter_list|()
function_decl|;
name|void
name|addTimerToPrint
parameter_list|(
specifier|const
name|Timer
modifier|&
name|T
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

