begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TimeValue.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_TimeValue_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_TimeValue_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_MSC_VER
end_ifndef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|// BEGIN: MinGW work around
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_STRUCT_TIMESPEC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_STRUCT_TIMESPEC
argument_list|)
end_if

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// END: MinGW work around
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|TimeValue
block|{
name|public
label|:
specifier|static
specifier|const
name|uint64_t
name|MicroSecPerSec
init|=
literal|1000000UL
decl_stmt|;
specifier|static
specifier|const
name|uint64_t
name|NanoSecPerSec
init|=
literal|1000000000UL
decl_stmt|;
specifier|static
specifier|const
name|uint64_t
name|NanoSecPerMicroSec
init|=
literal|1000U
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|TimeValue
argument_list|()
expr_stmt|;
name|TimeValue
argument_list|(
specifier|const
name|TimeValue
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|TimeValue
argument_list|(
specifier|const
expr|struct
name|timespec
operator|&
name|ts
argument_list|)
expr_stmt|;
name|explicit
name|TimeValue
parameter_list|(
name|uint32_t
name|seconds
parameter_list|,
name|uint32_t
name|nanos
init|=
literal|0
parameter_list|)
function_decl|;
operator|~
name|TimeValue
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Operators
comment|//------------------------------------------------------------------
specifier|const
name|TimeValue
modifier|&
name|operator
init|=
operator|(
specifier|const
name|TimeValue
operator|&
name|rhs
operator|)
decl_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|uint64_t
name|GetAsNanoSecondsSinceJan1_1970
argument_list|()
specifier|const
expr_stmt|;
name|uint64_t
name|GetAsMicroSecondsSinceJan1_1970
argument_list|()
specifier|const
expr_stmt|;
name|uint64_t
name|GetAsSecondsSinceJan1_1970
argument_list|()
specifier|const
decl_stmt|;
block|struct
name|timespec
name|GetAsTimeSpec
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|void
name|OffsetWithSeconds
parameter_list|(
name|uint64_t
name|sec
parameter_list|)
function_decl|;
name|void
name|OffsetWithMicroSeconds
parameter_list|(
name|uint64_t
name|usec
parameter_list|)
function_decl|;
name|void
name|OffsetWithNanoSeconds
parameter_list|(
name|uint64_t
name|nsec
parameter_list|)
function_decl|;
specifier|static
name|TimeValue
name|Now
parameter_list|()
function_decl|;
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|uint32_t
name|width
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns only the seconds component of the TimeValue. The nanoseconds
comment|/// portion is ignored. No rounding is performed.
comment|/// @brief Retrieve the seconds component
name|uint32_t
name|seconds
argument_list|()
specifier|const
block|{
return|return
name|m_nano_seconds
operator|/
name|NanoSecPerSec
return|;
block|}
comment|/// Returns only the nanoseconds component of the TimeValue. The seconds
comment|/// portion is ignored.
comment|/// @brief Retrieve the nanoseconds component.
name|uint32_t
name|nanoseconds
argument_list|()
specifier|const
block|{
return|return
name|m_nano_seconds
operator|%
name|NanoSecPerSec
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
operator|(
name|m_nano_seconds
operator|%
name|NanoSecPerSec
operator|)
operator|/
name|NanoSecPerMicroSec
return|;
block|}
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from TimeValue can see and modify these
comment|//------------------------------------------------------------------
name|uint64_t
name|m_nano_seconds
decl_stmt|;
block|}
empty_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|TimeValue
operator|&
name|lhs
operator|,
specifier|const
name|TimeValue
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|TimeValue
operator|&
name|lhs
operator|,
specifier|const
name|TimeValue
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|TimeValue
operator|&
name|lhs
operator|,
specifier|const
name|TimeValue
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|TimeValue
operator|&
name|lhs
operator|,
specifier|const
name|TimeValue
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|>
operator|(
specifier|const
name|TimeValue
operator|&
name|lhs
operator|,
specifier|const
name|TimeValue
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|TimeValue
operator|&
name|lhs
operator|,
specifier|const
name|TimeValue
operator|&
name|rhs
operator|)
expr_stmt|;
name|uint64_t
name|operator
operator|-
operator|(
specifier|const
name|TimeValue
operator|&
name|lhs
operator|,
specifier|const
name|TimeValue
operator|&
name|rhs
operator|)
expr_stmt|;
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
comment|// liblldb_TimeValue_h_
end_comment

end_unit

