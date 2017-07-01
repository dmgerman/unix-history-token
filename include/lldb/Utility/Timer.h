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

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for DISALLOW_COPY_AND_ASSIGN
end_comment

begin_include
include|#
directive|include
file|"llvm/Support/Chrono.h"
end_include

begin_include
include|#
directive|include
file|<atomic>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint32_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stream
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class Timer Timer.h "lldb/Utility/Timer.h"
comment|/// @brief A timer class that simplifies common timing metrics.
comment|//----------------------------------------------------------------------
name|class
name|Timer
block|{
name|public
label|:
name|class
name|Category
block|{
name|public
label|:
name|explicit
name|Category
parameter_list|(
specifier|const
name|char
modifier|*
name|category_name
parameter_list|)
function_decl|;
name|private
label|:
name|friend
name|class
name|Timer
decl_stmt|;
specifier|const
name|char
modifier|*
name|m_name
decl_stmt|;
name|std
operator|::
name|atomic
operator|<
name|uint64_t
operator|>
name|m_nanos
expr_stmt|;
name|std
operator|::
name|atomic
operator|<
name|Category
operator|*
operator|>
name|m_next
expr_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Category
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|//--------------------------------------------------------------
comment|/// Default constructor.
comment|//--------------------------------------------------------------
name|Timer
argument_list|(
argument|Category&category
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
comment|/// Destructor
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
name|using
name|TimePoint
init|=
name|std
operator|::
name|chrono
operator|::
name|steady_clock
operator|::
name|time_point
decl_stmt|;
name|void
name|ChildDuration
argument_list|(
name|TimePoint
operator|::
name|duration
name|dur
argument_list|)
block|{
name|m_child_duration
operator|+=
name|dur
expr_stmt|;
block|}
name|Category
modifier|&
name|m_category
decl_stmt|;
name|TimePoint
name|m_total_start
decl_stmt|;
name|TimePoint
operator|::
name|duration
name|m_child_duration
block|{
literal|0
block|}
expr_stmt|;
specifier|static
name|std
operator|::
name|atomic
operator|<
name|bool
operator|>
name|g_quiet
expr_stmt|;
specifier|static
name|std
operator|::
name|atomic
operator|<
name|unsigned
operator|>
name|g_display_depth
expr_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Timer
argument_list|)
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
comment|// liblldb_Timer_h_
end_comment

end_unit

