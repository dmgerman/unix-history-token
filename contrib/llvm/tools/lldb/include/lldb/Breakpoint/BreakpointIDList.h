begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BreakpointIDList.h --------------------------------------*- C++ -*-===//
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
name|liblldb_BreakpointIDList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_BreakpointIDList_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<vector>
end_include

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

begin_include
include|#
directive|include
file|"lldb/Breakpoint/BreakpointID.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// class BreakpointIDList
comment|//----------------------------------------------------------------------
name|class
name|BreakpointIDList
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|BreakpointID
operator|>
name|BreakpointIDArray
expr_stmt|;
name|BreakpointIDList
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|BreakpointIDList
argument_list|()
expr_stmt|;
name|size_t
name|GetSize
parameter_list|()
function_decl|;
name|BreakpointID
modifier|&
name|GetBreakpointIDAtIndex
parameter_list|(
name|size_t
name|index
parameter_list|)
function_decl|;
name|bool
name|RemoveBreakpointIDAtIndex
parameter_list|(
name|size_t
name|index
parameter_list|)
function_decl|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|bool
name|AddBreakpointID
parameter_list|(
name|BreakpointID
name|bp_id
parameter_list|)
function_decl|;
name|bool
name|AddBreakpointID
parameter_list|(
specifier|const
name|char
modifier|*
name|bp_id
parameter_list|)
function_decl|;
name|bool
name|FindBreakpointID
parameter_list|(
name|BreakpointID
modifier|&
name|bp_id
parameter_list|,
name|size_t
modifier|*
name|position
parameter_list|)
function_decl|;
name|bool
name|FindBreakpointID
parameter_list|(
specifier|const
name|char
modifier|*
name|bp_id
parameter_list|,
name|size_t
modifier|*
name|position
parameter_list|)
function_decl|;
name|void
name|InsertStringArray
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|string_array
parameter_list|,
name|size_t
name|array_size
parameter_list|,
name|CommandReturnObject
modifier|&
name|result
parameter_list|)
function_decl|;
specifier|static
name|bool
name|StringContainsIDRangeExpression
parameter_list|(
specifier|const
name|char
modifier|*
name|in_string
parameter_list|,
name|size_t
modifier|*
name|range_start_len
parameter_list|,
name|size_t
modifier|*
name|range_end_pos
parameter_list|)
function_decl|;
specifier|static
name|void
name|FindAndReplaceIDRanges
parameter_list|(
name|Args
modifier|&
name|old_args
parameter_list|,
name|Target
modifier|*
name|target
parameter_list|,
name|bool
name|allow_locations
parameter_list|,
name|CommandReturnObject
modifier|&
name|result
parameter_list|,
name|Args
modifier|&
name|new_args
parameter_list|)
function_decl|;
name|private
label|:
name|BreakpointIDArray
name|m_breakpoint_ids
decl_stmt|;
name|BreakpointID
name|m_invalid_id
decl_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|BreakpointIDList
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
comment|// liblldb_BreakpointIDList_h_
end_comment

end_unit

