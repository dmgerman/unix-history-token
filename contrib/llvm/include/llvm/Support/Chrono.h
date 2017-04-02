begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/Chrono.h - Utilities for Timing Manipulation-*- C++ -*-===//
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
name|LLVM_SUPPORT_CHRONO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_CHRONO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<chrono>
end_include

begin_include
include|#
directive|include
file|<ctime>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|namespace
name|sys
block|{
comment|/// A time point on the system clock. This is provided for two reasons:
comment|/// - to insulate us agains subtle differences in behavoir to differences in
comment|///   system clock precision (which is implementation-defined and differs between
comment|///   platforms).
comment|/// - to shorten the type name
comment|/// The default precision is nanoseconds. If need a specific precision specify
comment|/// it explicitly. If unsure, use the default. If you need a time point on a
comment|/// clock other than the system_clock, use std::chrono directly.
name|template
operator|<
name|typename
name|D
operator|=
name|std
operator|::
name|chrono
operator|::
name|nanoseconds
operator|>
name|using
name|TimePoint
operator|=
name|std
operator|::
name|chrono
operator|::
name|time_point
operator|<
name|std
operator|::
name|chrono
operator|::
name|system_clock
operator|,
name|D
operator|>
expr_stmt|;
comment|/// Convert a TimePoint to std::time_t
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
specifier|inline
name|std
operator|::
name|time_t
name|toTimeT
argument_list|(
argument|TimePoint<> TP
argument_list|)
block|{
name|using
name|namespace
name|std
operator|::
name|chrono
block|;
return|return
name|system_clock
operator|::
name|to_time_t
argument_list|(
name|time_point_cast
operator|<
name|system_clock
operator|::
name|time_point
operator|::
name|duration
operator|>
operator|(
name|TP
operator|)
argument_list|)
return|;
block|}
comment|/// Convert a std::time_t to a TimePoint
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
specifier|inline
name|TimePoint
operator|<
name|std
operator|::
name|chrono
operator|::
name|seconds
operator|>
name|toTimePoint
argument_list|(
argument|std::time_t T
argument_list|)
block|{
name|using
name|namespace
name|std
operator|::
name|chrono
block|;
return|return
name|time_point_cast
operator|<
name|seconds
operator|>
operator|(
name|system_clock
operator|::
name|from_time_t
argument_list|(
name|T
argument_list|)
operator|)
return|;
block|}
block|}
comment|// namespace sys
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
name|sys
operator|::
name|TimePoint
operator|<
operator|>
name|TP
operator|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_CHRONO_H
end_comment

end_unit

