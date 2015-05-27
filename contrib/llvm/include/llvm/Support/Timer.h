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
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Timer
decl_stmt|;
name|class
name|TimerGroup
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|TimeRecord
block|{
name|double
name|WallTime
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
name|public
label|:
name|TimeRecord
argument_list|()
operator|:
name|WallTime
argument_list|(
literal|0
argument_list|)
operator|,
name|UserTime
argument_list|(
literal|0
argument_list|)
operator|,
name|SystemTime
argument_list|(
literal|0
argument_list|)
operator|,
name|MemUsed
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// getCurrentTime - Get the current time and memory usage.  If Start is true
comment|/// we get the memory usage before the time, otherwise we get time before
comment|/// memory usage.  This matters if the time to get the memory usage is
comment|/// significant and shouldn't be counted as part of a duration.
specifier|static
name|TimeRecord
name|getCurrentTime
argument_list|(
argument|bool Start = true
argument_list|)
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
name|getUserTime
argument_list|()
specifier|const
block|{
return|return
name|UserTime
return|;
block|}
name|double
name|getSystemTime
argument_list|()
specifier|const
block|{
return|return
name|SystemTime
return|;
block|}
name|double
name|getWallTime
argument_list|()
specifier|const
block|{
return|return
name|WallTime
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
comment|// operator< - Allow sorting.
name|bool
name|operator
operator|<
operator|(
specifier|const
name|TimeRecord
operator|&
name|T
operator|)
specifier|const
block|{
comment|// Sort by Wall Time elapsed, as it is the only thing really accurate
return|return
name|WallTime
operator|<
name|T
operator|.
name|WallTime
return|;
block|}
name|void
name|operator
operator|+=
operator|(
specifier|const
name|TimeRecord
operator|&
name|RHS
operator|)
block|{
name|WallTime
operator|+=
name|RHS
operator|.
name|WallTime
block|;
name|UserTime
operator|+=
name|RHS
operator|.
name|UserTime
block|;
name|SystemTime
operator|+=
name|RHS
operator|.
name|SystemTime
block|;
name|MemUsed
operator|+=
name|RHS
operator|.
name|MemUsed
block|;   }
name|void
name|operator
operator|-=
operator|(
specifier|const
name|TimeRecord
operator|&
name|RHS
operator|)
block|{
name|WallTime
operator|-=
name|RHS
operator|.
name|WallTime
block|;
name|UserTime
operator|-=
name|RHS
operator|.
name|UserTime
block|;
name|SystemTime
operator|-=
name|RHS
operator|.
name|SystemTime
block|;
name|MemUsed
operator|-=
name|RHS
operator|.
name|MemUsed
block|;   }
comment|/// print - Print the current timer to standard error, and reset the "Started"
comment|/// flag.
name|void
name|print
argument_list|(
argument|const TimeRecord&Total
argument_list|,
argument|raw_ostream&OS
argument_list|)
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|/// Timer - This class is used to track the amount of time spent between
comment|/// invocations of its startTimer()/stopTimer() methods.  Given appropriate OS
comment|/// support it can also keep track of the RSS of the program at various points.
comment|/// By default, the Timer will print the amount of time it has captured to
comment|/// standard error when the last timer is destroyed, otherwise it is printed
comment|/// when its TimerGroup is destroyed.  Timers do not print their information
comment|/// if they are never started.
comment|///
name|class
name|Timer
block|{
name|TimeRecord
name|Time
decl_stmt|;
name|std
operator|::
name|string
name|Name
expr_stmt|;
comment|// The name of this time variable.
name|bool
name|Started
decl_stmt|;
comment|// Has this time variable ever been started?
name|TimerGroup
modifier|*
name|TG
decl_stmt|;
comment|// The TimerGroup this Timer is in.
name|Timer
modifier|*
modifier|*
name|Prev
decl_stmt|,
modifier|*
name|Next
decl_stmt|;
comment|// Doubly linked list of timers in the group.
name|public
label|:
name|explicit
name|Timer
argument_list|(
argument|StringRef N
argument_list|)
block|:
name|TG
argument_list|(
argument|nullptr
argument_list|)
block|{
name|init
argument_list|(
name|N
argument_list|)
expr_stmt|;
block|}
name|Timer
argument_list|(
argument|StringRef N
argument_list|,
argument|TimerGroup&tg
argument_list|)
block|:
name|TG
argument_list|(
argument|nullptr
argument_list|)
block|{
name|init
argument_list|(
name|N
argument_list|,
name|tg
argument_list|)
expr_stmt|;
block|}
name|Timer
argument_list|(
specifier|const
name|Timer
operator|&
name|RHS
argument_list|)
operator|:
name|TG
argument_list|(
argument|nullptr
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|RHS
operator|.
name|TG
operator|&&
literal|"Can only copy uninitialized timers"
argument_list|)
block|;   }
specifier|const
name|Timer
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Timer
operator|&
name|T
operator|)
block|{
name|assert
argument_list|(
operator|!
name|TG
operator|&&
operator|!
name|T
operator|.
name|TG
operator|&&
literal|"Can only assign uninit timers"
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
operator|~
name|Timer
argument_list|()
expr_stmt|;
comment|// Create an uninitialized timer, client must use 'init'.
name|explicit
name|Timer
argument_list|()
operator|:
name|TG
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|void
name|init
argument_list|(
argument|StringRef N
argument_list|)
expr_stmt|;
name|void
name|init
parameter_list|(
name|StringRef
name|N
parameter_list|,
name|TimerGroup
modifier|&
name|tg
parameter_list|)
function_decl|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
name|bool
name|isInitialized
argument_list|()
specifier|const
block|{
return|return
name|TG
operator|!=
name|nullptr
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
name|private
label|:
name|friend
name|class
name|TimerGroup
decl_stmt|;
block|}
empty_stmt|;
comment|/// The TimeRegion class is used as a helper class to call the startTimer() and
comment|/// stopTimer() methods of the Timer class.  When the object is constructed, it
comment|/// starts the timer specified as its argument.  When it is destroyed, it stops
comment|/// the relevant timer.  This makes it easy to time a region of code.
comment|///
name|class
name|TimeRegion
block|{
name|Timer
modifier|*
name|T
decl_stmt|;
name|TimeRegion
argument_list|(
argument|const TimeRegion&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
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
empty_stmt|;
comment|/// NamedRegionTimer - This class is basically a combination of TimeRegion and
comment|/// Timer.  It allows you to declare a new timer, AND specify the region to
comment|/// time, all in one statement.  All timers with the same name are merged.  This
comment|/// is primarily used for debugging and for hunting performance problems.
comment|///
name|struct
name|NamedRegionTimer
range|:
name|public
name|TimeRegion
block|{
name|explicit
name|NamedRegionTimer
argument_list|(
argument|StringRef Name
argument_list|,
argument|bool Enabled = true
argument_list|)
block|;
name|explicit
name|NamedRegionTimer
argument_list|(
argument|StringRef Name
argument_list|,
argument|StringRef GroupName
argument_list|,
argument|bool Enabled = true
argument_list|)
block|; }
decl_stmt|;
comment|/// The TimerGroup class is used to group together related timers into a single
comment|/// report that is printed when the TimerGroup is destroyed.  It is illegal to
comment|/// destroy a TimerGroup object before all of the Timers in it are gone.  A
comment|/// TimerGroup can be specified for a newly created timer in its constructor.
comment|///
name|class
name|TimerGroup
block|{
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|Timer
modifier|*
name|FirstTimer
decl_stmt|;
comment|// First timer in the group.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|TimeRecord
operator|,
name|std
operator|::
name|string
operator|>
expr|>
name|TimersToPrint
expr_stmt|;
name|TimerGroup
modifier|*
modifier|*
name|Prev
decl_stmt|,
modifier|*
name|Next
decl_stmt|;
comment|// Doubly linked list of TimerGroup's.
name|TimerGroup
argument_list|(
argument|const TimerGroup&TG
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|TimerGroup
operator|&
name|TG
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
name|explicit
name|TimerGroup
parameter_list|(
name|StringRef
name|name
parameter_list|)
function_decl|;
operator|~
name|TimerGroup
argument_list|()
expr_stmt|;
name|void
name|setName
parameter_list|(
name|StringRef
name|name
parameter_list|)
block|{
name|Name
operator|.
name|assign
argument_list|(
name|name
operator|.
name|begin
argument_list|()
argument_list|,
name|name
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// print - Print any started timers in this group and zero them.
name|void
name|print
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// printAll - This static method prints all timers and clears them all out.
specifier|static
name|void
name|printAll
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|private
label|:
name|friend
name|class
name|Timer
decl_stmt|;
name|void
name|addTimer
parameter_list|(
name|Timer
modifier|&
name|T
parameter_list|)
function_decl|;
name|void
name|removeTimer
parameter_list|(
name|Timer
modifier|&
name|T
parameter_list|)
function_decl|;
name|void
name|PrintQueuedTimers
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

