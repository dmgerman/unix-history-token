begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UnwindLLDB.h --------------------------------------------*- C++ -*-===//
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
name|lldb_UnwindLLDB_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_UnwindLLDB_h_
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
file|"lldb/Symbol/FuncUnwinders.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/UnwindPlan.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/RegisterContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Unwind.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|RegisterContextLLDB
decl_stmt|;
name|class
name|UnwindLLDB
range|:
name|public
name|lldb_private
operator|::
name|Unwind
block|{
name|public
operator|:
name|UnwindLLDB
argument_list|(
name|lldb_private
operator|::
name|Thread
operator|&
name|thread
argument_list|)
block|;
operator|~
name|UnwindLLDB
argument_list|()
name|override
operator|=
expr|default
block|;    enum
name|RegisterSearchResult
block|{
name|eRegisterFound
operator|=
literal|0
block|,
name|eRegisterNotFound
block|,
name|eRegisterIsVolatile
block|}
block|;
name|protected
operator|:
name|friend
name|class
name|lldb_private
operator|::
name|RegisterContextLLDB
block|;    struct
name|RegisterLocation
block|{     enum
name|RegisterLocationTypes
block|{
name|eRegisterNotSaved
operator|=
literal|0
block|,
comment|// register was not preserved by callee.  If
comment|// volatile reg, is unavailable
name|eRegisterSavedAtMemoryLocation
block|,
comment|// register is saved at a specific word of
comment|// target mem (target_memory_location)
name|eRegisterInRegister
block|,
comment|// register is available in a (possible other)
comment|// register (register_number)
name|eRegisterSavedAtHostMemoryLocation
block|,
comment|// register is saved at a word in
comment|// lldb's address space
name|eRegisterValueInferred
block|,
comment|// register val was computed (and is in
comment|// inferred_value)
name|eRegisterInLiveRegisterContext
comment|// register value is in a live (stack frame
comment|// #0) register
block|}
block|;
name|int
name|type
block|;
expr|union
block|{
name|lldb
operator|::
name|addr_t
name|target_memory_location
block|;
name|uint32_t
name|register_number
block|;
comment|// in eRegisterKindLLDB register numbering system
name|void
operator|*
name|host_memory_location
block|;
name|uint64_t
name|inferred_value
block|;
comment|// eRegisterValueInferred - e.g. stack pointer ==
comment|// cfa + offset
block|}
name|location
block|;   }
block|;
name|void
name|DoClear
argument_list|()
name|override
block|{
name|m_frames
operator|.
name|clear
argument_list|()
block|;
name|m_candidate_frame
operator|.
name|reset
argument_list|()
block|;
name|m_unwind_complete
operator|=
name|false
block|;   }
name|uint32_t
name|DoGetFrameCount
argument_list|()
name|override
block|;
name|bool
name|DoGetFrameInfoAtIndex
argument_list|(
argument|uint32_t frame_idx
argument_list|,
argument|lldb::addr_t&cfa
argument_list|,
argument|lldb::addr_t&start_pc
argument_list|)
name|override
block|;
name|lldb
operator|::
name|RegisterContextSP
name|DoCreateRegisterContextForFrame
argument_list|(
argument|lldb_private::StackFrame *frame
argument_list|)
name|override
block|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|RegisterContextLLDB
operator|>
name|RegisterContextLLDBSP
expr_stmt|;
comment|// Needed to retrieve the "next" frame (e.g. frame 2 needs to retrieve frame
comment|// 1's RegisterContextLLDB)
comment|// The RegisterContext for frame_num must already exist or this returns an
comment|// empty shared pointer.
name|RegisterContextLLDBSP
name|GetRegisterContextForFrameNum
argument_list|(
argument|uint32_t frame_num
argument_list|)
decl_stmt|;
comment|// Iterate over the RegisterContextLLDB's in our m_frames vector, look for the
comment|// first one that
comment|// has a saved location for this reg.
name|bool
name|SearchForSavedLocationForRegister
argument_list|(
name|uint32_t
name|lldb_regnum
argument_list|,
name|lldb_private
operator|::
name|UnwindLLDB
operator|::
name|RegisterLocation
operator|&
name|regloc
argument_list|,
name|uint32_t
name|starting_frame_num
argument_list|,
name|bool
name|pc_register
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Provide the list of user-specified trap handler functions
comment|///
comment|/// The Platform is one source of trap handler function names; that
comment|/// may be augmented via a setting.  The setting needs to be converted
comment|/// into an array of ConstStrings before it can be used - we only want
comment|/// to do that once per thread so it's here in the UnwindLLDB object.
comment|///
comment|/// @return
comment|///     Vector of ConstStrings of trap handler function names.  May be
comment|///     empty.
comment|//------------------------------------------------------------------
specifier|const
name|std
operator|::
name|vector
operator|<
name|ConstString
operator|>
operator|&
name|GetUserSpecifiedTrapHandlerFunctionNames
argument_list|()
block|{
return|return
name|m_user_supplied_trap_handler_functions
return|;
block|}
name|private
label|:
struct|struct
name|Cursor
block|{
name|lldb
operator|::
name|addr_t
name|start_pc
expr_stmt|;
comment|// The start address of the function/symbol for this
comment|// frame - current pc if unknown
name|lldb
operator|::
name|addr_t
name|cfa
expr_stmt|;
comment|// The canonical frame address for this stack frame
name|lldb_private
operator|::
name|SymbolContext
name|sctx
expr_stmt|;
comment|// A symbol context we'll contribute to&
comment|// provide to the StackFrame creation
name|RegisterContextLLDBSP
name|reg_ctx_lldb_sp
decl_stmt|;
comment|// These are all RegisterContextLLDB's
name|Cursor
argument_list|()
operator|:
name|start_pc
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
operator|,
name|cfa
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
operator|,
name|sctx
argument_list|()
operator|,
name|reg_ctx_lldb_sp
argument_list|()
block|{}
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Cursor
argument_list|)
expr_stmt|;
block|}
struct|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|Cursor
operator|>
name|CursorSP
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|CursorSP
operator|>
name|m_frames
expr_stmt|;
name|CursorSP
name|m_candidate_frame
decl_stmt|;
name|bool
name|m_unwind_complete
decl_stmt|;
comment|// If this is true, we've enumerated all the frames in
comment|// the stack, and m_frames.size() is the
comment|// number of frames, etc.  Otherwise we've only gone as far as directly asked,
comment|// and m_frames.size()
comment|// is how far we've currently gone.
name|std
operator|::
name|vector
operator|<
name|ConstString
operator|>
name|m_user_supplied_trap_handler_functions
expr_stmt|;
comment|//-----------------------------------------------------------------
comment|// Check if Full UnwindPlan of First frame is valid or not.
comment|// If not then try Fallback UnwindPlan of the frame. If Fallback
comment|// UnwindPlan succeeds then update the Full UnwindPlan with the
comment|// Fallback UnwindPlan.
comment|//-----------------------------------------------------------------
name|void
name|UpdateUnwindPlanForFirstFrameIfInvalid
parameter_list|(
name|ABI
modifier|*
name|abi
parameter_list|)
function_decl|;
name|CursorSP
name|GetOneMoreFrame
parameter_list|(
name|ABI
modifier|*
name|abi
parameter_list|)
function_decl|;
name|bool
name|AddOneMoreFrame
parameter_list|(
name|ABI
modifier|*
name|abi
parameter_list|)
function_decl|;
name|bool
name|AddFirstFrame
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|// For UnwindLLDB only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|UnwindLLDB
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_UnwindLLDB_h_
end_comment

end_unit

