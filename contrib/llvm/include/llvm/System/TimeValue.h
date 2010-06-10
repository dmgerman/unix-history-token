begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TimeValue.h - Declare OS TimeValue Concept --------------*- C++ -*-===//
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
comment|//  This header file declares the operating system TimeValue concept.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SYSTEM_TIMEVALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEM_TIMEVALUE_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|/// This class is used where a precise fixed point in time is required. The
comment|/// range of TimeValue spans many hundreds of billions of years both past and
comment|/// present.  The precision of TimeValue is to the nanosecond. However, the
comment|/// actual precision of its values will be determined by the resolution of
comment|/// the system clock. The TimeValue class is used in conjunction with several
comment|/// other lib/System interfaces to specify the time at which a call should
comment|/// timeout, etc.
comment|/// @since 1.4
comment|/// @brief Provides an abstraction for a fixed point in time.
name|class
name|TimeValue
block|{
comment|/// @name Constants
comment|/// @{
name|public
label|:
comment|/// A constant TimeValue representing the smallest time
comment|/// value permissable by the class. MinTime is some point
comment|/// in the distant past, about 300 billion years BCE.
comment|/// @brief The smallest possible time value.
specifier|static
specifier|const
name|TimeValue
name|MinTime
decl_stmt|;
comment|/// A constant TimeValue representing the largest time
comment|/// value permissable by the class. MaxTime is some point
comment|/// in the distant future, about 300 billion years AD.
comment|/// @brief The largest possible time value.
specifier|static
specifier|const
name|TimeValue
name|MaxTime
decl_stmt|;
comment|/// A constant TimeValue representing the base time,
comment|/// or zero time of 00:00:00 (midnight) January 1st, 2000.
comment|/// @brief 00:00:00 Jan 1, 2000 UTC.
specifier|static
specifier|const
name|TimeValue
name|ZeroTime
decl_stmt|;
comment|/// A constant TimeValue for the Posix base time which is
comment|/// 00:00:00 (midnight) January 1st, 1970.
comment|/// @brief 00:00:00 Jan 1, 1970 UTC.
specifier|static
specifier|const
name|TimeValue
name|PosixZeroTime
decl_stmt|;
comment|/// A constant TimeValue for the Win32 base time which is
comment|/// 00:00:00 (midnight) January 1st, 1601.
comment|/// @brief 00:00:00 Jan 1, 1601 UTC.
specifier|static
specifier|const
name|TimeValue
name|Win32ZeroTime
decl_stmt|;
comment|/// @}
comment|/// @name Types
comment|/// @{
name|public
label|:
typedef|typedef
name|int64_t
name|SecondsType
typedef|;
comment|///< Type used for representing seconds.
typedef|typedef
name|int32_t
name|NanoSecondsType
typedef|;
comment|///< Type used for representing nanoseconds.
enum|enum
name|TimeConversions
block|{
name|NANOSECONDS_PER_SECOND
init|=
literal|1000000000
block|,
comment|///< One Billion
name|MICROSECONDS_PER_SECOND
init|=
literal|1000000
block|,
comment|///< One Million
name|MILLISECONDS_PER_SECOND
init|=
literal|1000
block|,
comment|///< One Thousand
name|NANOSECONDS_PER_MICROSECOND
init|=
literal|1000
block|,
comment|///< One Thousand
name|NANOSECONDS_PER_MILLISECOND
init|=
literal|1000000
block|,
comment|///< One Million
name|NANOSECONDS_PER_POSIX_TICK
init|=
literal|100
block|,
comment|///< Posix tick is 100 Hz (10ms)
name|NANOSECONDS_PER_WIN32_TICK
init|=
literal|100
comment|///< Win32 tick is 100 Hz (10ms)
block|}
enum|;
comment|/// @}
comment|/// @name Constructors
comment|/// @{
name|public
label|:
comment|/// Caller provides the exact value in seconds and nanoseconds. The
comment|/// \p nanos argument defaults to zero for convenience.
comment|/// @brief Explicit constructor
name|explicit
name|TimeValue
argument_list|(
argument|SecondsType seconds
argument_list|,
argument|NanoSecondsType nanos =
literal|0
argument_list|)
block|:
name|seconds_
argument_list|(
name|seconds
argument_list|)
operator|,
name|nanos_
argument_list|(
argument|nanos
argument_list|)
block|{
name|this
operator|->
name|normalize
argument_list|()
block|; }
comment|/// Caller provides the exact value as a double in seconds with the
comment|/// fractional part representing nanoseconds.
comment|/// @brief Double Constructor.
name|explicit
name|TimeValue
argument_list|(
argument|double new_time
argument_list|)
operator|:
name|seconds_
argument_list|(
literal|0
argument_list|)
operator|,
name|nanos_
argument_list|(
literal|0
argument_list|)
block|{
name|SecondsType
name|integer_part
operator|=
name|static_cast
operator|<
name|SecondsType
operator|>
operator|(
name|new_time
operator|)
block|;
name|seconds_
operator|=
name|integer_part
block|;
name|nanos_
operator|=
name|static_cast
operator|<
name|NanoSecondsType
operator|>
operator|(
operator|(
name|new_time
operator|-
name|static_cast
operator|<
name|double
operator|>
operator|(
name|integer_part
operator|)
operator|)
operator|*
name|NANOSECONDS_PER_SECOND
operator|)
block|;
name|this
operator|->
name|normalize
argument_list|()
block|;     }
comment|/// This is a static constructor that returns a TimeValue that represents
comment|/// the current time.
comment|/// @brief Creates a TimeValue with the current time (UTC).
specifier|static
name|TimeValue
name|now
argument_list|()
expr_stmt|;
comment|/// @}
comment|/// @name Operators
comment|/// @{
name|public
label|:
comment|/// Add \p that to \p this.
comment|/// @returns this
comment|/// @brief Incrementing assignment operator.
name|TimeValue
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|TimeValue
operator|&
name|that
operator|)
block|{
name|this
operator|->
name|seconds_
operator|+=
name|that
operator|.
name|seconds_
block|;
name|this
operator|->
name|nanos_
operator|+=
name|that
operator|.
name|nanos_
block|;
name|this
operator|->
name|normalize
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// Subtract \p that from \p this.
comment|/// @returns this
comment|/// @brief Decrementing assignment operator.
name|TimeValue
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|TimeValue
operator|&
name|that
operator|)
block|{
name|this
operator|->
name|seconds_
operator|-=
name|that
operator|.
name|seconds_
block|;
name|this
operator|->
name|nanos_
operator|-=
name|that
operator|.
name|nanos_
block|;
name|this
operator|->
name|normalize
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// Determine if \p this is less than \p that.
comment|/// @returns True iff *this< that.
comment|/// @brief True if this< that.
name|int
name|operator
operator|<
operator|(
specifier|const
name|TimeValue
operator|&
name|that
operator|)
specifier|const
block|{
return|return
name|that
operator|>
operator|*
name|this
return|;
block|}
comment|/// Determine if \p this is greather than \p that.
comment|/// @returns True iff *this> that.
comment|/// @brief True if this> that.
name|int
name|operator
operator|>
operator|(
specifier|const
name|TimeValue
operator|&
name|that
operator|)
specifier|const
block|{
if|if
condition|(
name|this
operator|->
name|seconds_
operator|>
name|that
operator|.
name|seconds_
condition|)
block|{
return|return
literal|1
return|;
block|}
elseif|else
if|if
condition|(
name|this
operator|->
name|seconds_
operator|==
name|that
operator|.
name|seconds_
condition|)
block|{
if|if
condition|(
name|this
operator|->
name|nanos_
operator|>
name|that
operator|.
name|nanos_
condition|)
return|return
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
comment|/// Determine if \p this is less than or equal to \p that.
comment|/// @returns True iff *this<= that.
comment|/// @brief True if this<= that.
name|int
name|operator
operator|<=
operator|(
specifier|const
name|TimeValue
operator|&
name|that
operator|)
specifier|const
block|{
return|return
name|that
operator|>=
operator|*
name|this
return|;
block|}
comment|/// Determine if \p this is greater than or equal to \p that.
comment|/// @returns True iff *this>= that.
comment|/// @brief True if this>= that.
name|int
name|operator
operator|>=
operator|(
specifier|const
name|TimeValue
operator|&
name|that
operator|)
specifier|const
block|{
if|if
condition|(
name|this
operator|->
name|seconds_
operator|>
name|that
operator|.
name|seconds_
condition|)
block|{
return|return
literal|1
return|;
block|}
elseif|else
if|if
condition|(
name|this
operator|->
name|seconds_
operator|==
name|that
operator|.
name|seconds_
condition|)
block|{
if|if
condition|(
name|this
operator|->
name|nanos_
operator|>=
name|that
operator|.
name|nanos_
condition|)
return|return
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
comment|/// Determines if two TimeValue objects represent the same moment in time.
comment|/// @brief True iff *this == that.
comment|/// @brief True if this == that.
name|int
name|operator
operator|==
operator|(
specifier|const
name|TimeValue
operator|&
name|that
operator|)
specifier|const
block|{
return|return
operator|(
name|this
operator|->
name|seconds_
operator|==
name|that
operator|.
name|seconds_
operator|)
operator|&&
operator|(
name|this
operator|->
name|nanos_
operator|==
name|that
operator|.
name|nanos_
operator|)
return|;
block|}
comment|/// Determines if two TimeValue objects represent times that are not the
comment|/// same.
comment|/// @return True iff *this != that.
comment|/// @brief True if this != that.
name|int
name|operator
operator|!=
operator|(
specifier|const
name|TimeValue
operator|&
name|that
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|that
operator|)
return|;
block|}
comment|/// Adds two TimeValue objects together.
comment|/// @returns The sum of the two operands as a new TimeValue
comment|/// @brief Addition operator.
name|friend
name|TimeValue
name|operator
operator|+
operator|(
specifier|const
name|TimeValue
operator|&
name|tv1
operator|,
specifier|const
name|TimeValue
operator|&
name|tv2
operator|)
expr_stmt|;
comment|/// Subtracts two TimeValue objects.
comment|/// @returns The difference of the two operands as a new TimeValue
comment|/// @brief Subtraction operator.
name|friend
name|TimeValue
name|operator
operator|-
operator|(
specifier|const
name|TimeValue
operator|&
name|tv1
operator|,
specifier|const
name|TimeValue
operator|&
name|tv2
operator|)
expr_stmt|;
comment|/// @}
comment|/// @name Accessors
comment|/// @{
name|public
label|:
comment|/// Returns only the seconds component of the TimeValue. The nanoseconds
comment|/// portion is ignored. No rounding is performed.
comment|/// @brief Retrieve the seconds component
name|SecondsType
name|seconds
argument_list|()
specifier|const
block|{
return|return
name|seconds_
return|;
block|}
comment|/// Returns only the nanoseconds component of the TimeValue. The seconds
comment|/// portion is ignored.
comment|/// @brief Retrieve the nanoseconds component.
name|NanoSecondsType
name|nanoseconds
argument_list|()
specifier|const
block|{
return|return
name|nanos_
return|;
block|}
comment|/// Returns only the fractional portion of the TimeValue rounded down to the
comment|/// nearest microsecond (divide by one thousand).
comment|/// @brief Retrieve the fractional part as microseconds;
name|uint32_t
name|microseconds
argument_list|()
specifier|const
block|{
return|return
name|nanos_
operator|/
name|NANOSECONDS_PER_MICROSECOND
return|;
block|}
comment|/// Returns only the fractional portion of the TimeValue rounded down to the
comment|/// nearest millisecond (divide by one million).
comment|/// @brief Retrieve the fractional part as milliseconds;
name|uint32_t
name|milliseconds
argument_list|()
specifier|const
block|{
return|return
name|nanos_
operator|/
name|NANOSECONDS_PER_MILLISECOND
return|;
block|}
comment|/// Returns the TimeValue as a number of microseconds. Note that the value
comment|/// returned can overflow because the range of a uint64_t is smaller than
comment|/// the range of a TimeValue. Nevertheless, this is useful on some operating
comment|/// systems and is therefore provided.
comment|/// @brief Convert to a number of microseconds (can overflow)
name|uint64_t
name|usec
argument_list|()
specifier|const
block|{
return|return
name|seconds_
operator|*
name|MICROSECONDS_PER_SECOND
operator|+
operator|(
name|nanos_
operator|/
name|NANOSECONDS_PER_MICROSECOND
operator|)
return|;
block|}
comment|/// Returns the TimeValue as a number of milliseconds. Note that the value
comment|/// returned can overflow because the range of a uint64_t is smaller than
comment|/// the range of a TimeValue. Nevertheless, this is useful on some operating
comment|/// systems and is therefore provided.
comment|/// @brief Convert to a number of milliseconds (can overflow)
name|uint64_t
name|msec
argument_list|()
specifier|const
block|{
return|return
name|seconds_
operator|*
name|MILLISECONDS_PER_SECOND
operator|+
operator|(
name|nanos_
operator|/
name|NANOSECONDS_PER_MILLISECOND
operator|)
return|;
block|}
comment|/// Converts the TimeValue into the corresponding number of "ticks" for
comment|/// Posix, correcting for the difference in Posix zero time.
comment|/// @brief Convert to unix time (100 nanoseconds since 12:00:00a Jan 1,1970)
name|uint64_t
name|toPosixTime
argument_list|()
specifier|const
block|{
name|uint64_t
name|result
operator|=
name|seconds_
operator|-
name|PosixZeroTime
operator|.
name|seconds_
block|;
name|result
operator|+=
name|nanos_
operator|/
name|NANOSECONDS_PER_POSIX_TICK
block|;
return|return
name|result
return|;
block|}
comment|/// Converts the TimeValue into the corresponding number of seconds
comment|/// since the epoch (00:00:00 Jan 1,1970).
name|uint64_t
name|toEpochTime
argument_list|()
specifier|const
block|{
return|return
name|seconds_
operator|-
name|PosixZeroTime
operator|.
name|seconds_
return|;
block|}
comment|/// Converts the TimeValue into the corresponding number of "ticks" for
comment|/// Win32 platforms, correcting for the difference in Win32 zero time.
comment|/// @brief Convert to windows time (seconds since 12:00:00a Jan 1, 1601)
name|uint64_t
name|toWin32Time
argument_list|()
specifier|const
block|{
name|uint64_t
name|result
operator|=
name|seconds_
operator|-
name|Win32ZeroTime
operator|.
name|seconds_
block|;
name|result
operator|+=
name|nanos_
operator|/
name|NANOSECONDS_PER_WIN32_TICK
block|;
return|return
name|result
return|;
block|}
comment|/// Provides the seconds and nanoseconds as results in its arguments after
comment|/// correction for the Posix zero time.
comment|/// @brief Convert to timespec time (ala POSIX.1b)
name|void
name|getTimespecTime
argument_list|(
name|uint64_t
operator|&
name|seconds
argument_list|,
name|uint32_t
operator|&
name|nanos
argument_list|)
decl|const
block|{
name|seconds
operator|=
name|seconds_
operator|-
name|PosixZeroTime
operator|.
name|seconds_
expr_stmt|;
name|nanos
operator|=
name|nanos_
expr_stmt|;
block|}
comment|/// Provides conversion of the TimeValue into a readable time& date.
comment|/// @returns std::string containing the readable time value
comment|/// @brief Convert time to a string.
name|std
operator|::
name|string
name|str
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
comment|/// @name Mutators
comment|/// @{
name|public
label|:
comment|/// The seconds component of the TimeValue is set to \p sec without
comment|/// modifying the nanoseconds part.  This is useful for whole second
comment|/// arithmetic.
comment|/// @brief Set the seconds component.
name|void
name|seconds
parameter_list|(
name|SecondsType
name|sec
parameter_list|)
block|{
name|this
operator|->
name|seconds_
operator|=
name|sec
expr_stmt|;
name|this
operator|->
name|normalize
argument_list|()
expr_stmt|;
block|}
comment|/// The nanoseconds component of the TimeValue is set to \p nanos without
comment|/// modifying the seconds part. This is useful for basic computations
comment|/// involving just the nanoseconds portion. Note that the TimeValue will be
comment|/// normalized after this call so that the fractional (nanoseconds) portion
comment|/// will have the smallest equivalent value.
comment|/// @brief Set the nanoseconds component using a number of nanoseconds.
name|void
name|nanoseconds
parameter_list|(
name|NanoSecondsType
name|nanos
parameter_list|)
block|{
name|this
operator|->
name|nanos_
operator|=
name|nanos
expr_stmt|;
name|this
operator|->
name|normalize
argument_list|()
expr_stmt|;
block|}
comment|/// The seconds component remains unchanged.
comment|/// @brief Set the nanoseconds component using a number of microseconds.
name|void
name|microseconds
parameter_list|(
name|int32_t
name|micros
parameter_list|)
block|{
name|this
operator|->
name|nanos_
operator|=
name|micros
operator|*
name|NANOSECONDS_PER_MICROSECOND
expr_stmt|;
name|this
operator|->
name|normalize
argument_list|()
expr_stmt|;
block|}
comment|/// The seconds component remains unchanged.
comment|/// @brief Set the nanoseconds component using a number of milliseconds.
name|void
name|milliseconds
parameter_list|(
name|int32_t
name|millis
parameter_list|)
block|{
name|this
operator|->
name|nanos_
operator|=
name|millis
operator|*
name|NANOSECONDS_PER_MILLISECOND
expr_stmt|;
name|this
operator|->
name|normalize
argument_list|()
expr_stmt|;
block|}
comment|/// @brief Converts from microsecond format to TimeValue format
name|void
name|usec
parameter_list|(
name|int64_t
name|microseconds
parameter_list|)
block|{
name|this
operator|->
name|seconds_
operator|=
name|microseconds
operator|/
name|MICROSECONDS_PER_SECOND
expr_stmt|;
name|this
operator|->
name|nanos_
operator|=
name|NanoSecondsType
argument_list|(
name|microseconds
operator|%
name|MICROSECONDS_PER_SECOND
argument_list|)
operator|*
name|NANOSECONDS_PER_MICROSECOND
expr_stmt|;
name|this
operator|->
name|normalize
argument_list|()
expr_stmt|;
block|}
comment|/// @brief Converts from millisecond format to TimeValue format
name|void
name|msec
parameter_list|(
name|int64_t
name|milliseconds
parameter_list|)
block|{
name|this
operator|->
name|seconds_
operator|=
name|milliseconds
operator|/
name|MILLISECONDS_PER_SECOND
expr_stmt|;
name|this
operator|->
name|nanos_
operator|=
name|NanoSecondsType
argument_list|(
name|milliseconds
operator|%
name|MILLISECONDS_PER_SECOND
argument_list|)
operator|*
name|NANOSECONDS_PER_MILLISECOND
expr_stmt|;
name|this
operator|->
name|normalize
argument_list|()
expr_stmt|;
block|}
comment|/// Converts the \p seconds argument from PosixTime to the corresponding
comment|/// TimeValue and assigns that value to \p this.
comment|/// @brief Convert seconds form PosixTime to TimeValue
name|void
name|fromEpochTime
parameter_list|(
name|SecondsType
name|seconds
parameter_list|)
block|{
name|seconds_
operator|=
name|seconds
operator|+
name|PosixZeroTime
operator|.
name|seconds_
expr_stmt|;
name|nanos_
operator|=
literal|0
expr_stmt|;
name|this
operator|->
name|normalize
argument_list|()
expr_stmt|;
block|}
comment|/// Converts the \p win32Time argument from Windows FILETIME to the
comment|/// corresponding TimeValue and assigns that value to \p this.
comment|/// @brief Convert seconds form Windows FILETIME to TimeValue
name|void
name|fromWin32Time
parameter_list|(
name|uint64_t
name|win32Time
parameter_list|)
block|{
name|this
operator|->
name|seconds_
operator|=
name|win32Time
operator|/
literal|10000000
operator|+
name|Win32ZeroTime
operator|.
name|seconds_
expr_stmt|;
name|this
operator|->
name|nanos_
operator|=
name|NanoSecondsType
argument_list|(
name|win32Time
operator|%
literal|10000000
argument_list|)
operator|*
literal|100
expr_stmt|;
block|}
comment|/// @}
comment|/// @name Implementation
comment|/// @{
name|private
label|:
comment|/// This causes the values to be represented so that the fractional
comment|/// part is minimized, possibly incrementing the seconds part.
comment|/// @brief Normalize to canonical form.
name|void
name|normalize
parameter_list|()
function_decl|;
comment|/// @}
comment|/// @name Data
comment|/// @{
name|private
label|:
comment|/// Store the values as a<timeval>.
name|SecondsType
name|seconds_
decl_stmt|;
comment|///< Stores the seconds part of the TimeVal
name|NanoSecondsType
name|nanos_
decl_stmt|;
comment|///< Stores the nanoseconds part of the TimeVal
comment|/// @}
block|}
empty_stmt|;
specifier|inline
name|TimeValue
name|operator
operator|+
operator|(
specifier|const
name|TimeValue
operator|&
name|tv1
operator|,
specifier|const
name|TimeValue
operator|&
name|tv2
operator|)
block|{
name|TimeValue
name|sum
argument_list|(
name|tv1
operator|.
name|seconds_
operator|+
name|tv2
operator|.
name|seconds_
argument_list|,
name|tv1
operator|.
name|nanos_
operator|+
name|tv2
operator|.
name|nanos_
argument_list|)
block|;
name|sum
operator|.
name|normalize
argument_list|()
block|;
return|return
name|sum
return|;
block|}
specifier|inline
name|TimeValue
name|operator
operator|-
operator|(
specifier|const
name|TimeValue
operator|&
name|tv1
operator|,
specifier|const
name|TimeValue
operator|&
name|tv2
operator|)
block|{
name|TimeValue
name|difference
argument_list|(
name|tv1
operator|.
name|seconds_
operator|-
name|tv2
operator|.
name|seconds_
argument_list|,
name|tv1
operator|.
name|nanos_
operator|-
name|tv2
operator|.
name|nanos_
argument_list|)
block|;
name|difference
operator|.
name|normalize
argument_list|()
block|;
return|return
name|difference
return|;
block|}
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

