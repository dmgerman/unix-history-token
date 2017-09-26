begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextLLDB.h --------------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|lldb_RegisterContextLLDB_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_RegisterContextLLDB_h_
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
file|"UnwindLLDB.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/SymbolContext.h"
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
file|"lldb/Target/RegisterNumber.h"
end_include

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
name|UnwindLLDB
decl_stmt|;
name|class
name|RegisterContextLLDB
range|:
name|public
name|lldb_private
operator|::
name|RegisterContext
block|{
name|public
operator|:
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|RegisterContextLLDB
operator|>
name|SharedPtr
expr_stmt|;
name|RegisterContextLLDB
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|const SharedPtr&next_frame
argument_list|,
argument|lldb_private::SymbolContext&sym_ctx
argument_list|,
argument|uint32_t frame_number
argument_list|,
argument|lldb_private::UnwindLLDB&unwind_lldb
argument_list|)
decl_stmt|;
operator|~
name|RegisterContextLLDB
argument_list|()
name|override
operator|=
expr|default
expr_stmt|;
name|void
name|InvalidateAllRegisters
argument_list|()
name|override
expr_stmt|;
name|size_t
name|GetRegisterCount
argument_list|()
name|override
expr_stmt|;
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfoAtIndex
argument_list|(
argument|size_t reg
argument_list|)
name|override
expr_stmt|;
name|size_t
name|GetRegisterSetCount
argument_list|()
name|override
expr_stmt|;
specifier|const
name|lldb_private
operator|::
name|RegisterSet
operator|*
name|GetRegisterSet
argument_list|(
argument|size_t reg_set
argument_list|)
name|override
expr_stmt|;
name|bool
name|ReadRegister
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
name|lldb_private
operator|::
name|RegisterValue
operator|&
name|value
argument_list|)
name|override
decl_stmt|;
name|bool
name|WriteRegister
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
specifier|const
name|lldb_private
operator|::
name|RegisterValue
operator|&
name|value
argument_list|)
name|override
decl_stmt|;
name|bool
name|ReadAllRegisterValues
argument_list|(
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_sp
argument_list|)
name|override
decl_stmt|;
name|bool
name|WriteAllRegisterValues
argument_list|(
specifier|const
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_sp
argument_list|)
name|override
decl_stmt|;
name|uint32_t
name|ConvertRegisterKindToRegisterNumber
argument_list|(
name|lldb
operator|::
name|RegisterKind
name|kind
argument_list|,
name|uint32_t
name|num
argument_list|)
name|override
decl_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsTrapHandlerFrame
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|GetCFA
argument_list|(
name|lldb
operator|::
name|addr_t
operator|&
name|cfa
argument_list|)
decl_stmt|;
name|bool
name|GetStartPC
argument_list|(
name|lldb
operator|::
name|addr_t
operator|&
name|start_pc
argument_list|)
decl_stmt|;
name|bool
name|ReadPC
argument_list|(
name|lldb
operator|::
name|addr_t
operator|&
name|start_pc
argument_list|)
decl_stmt|;
name|private
label|:
enum|enum
name|FrameType
block|{
name|eNormalFrame
block|,
name|eTrapHandlerFrame
block|,
name|eDebuggerFrame
block|,
comment|// a debugger inferior function call frame; we get caller's
comment|// registers from debugger
name|eSkipFrame
block|,
comment|// The unwind resulted in a bogus frame but may get back on
comment|// track so we don't want to give up yet
name|eNotAValidFrame
comment|// this frame is invalid for some reason - most likely it is
comment|// past the top (end) of the stack
block|}
enum|;
comment|// UnwindLLDB needs to pass around references to RegisterLocations
name|friend
name|class
name|UnwindLLDB
decl_stmt|;
comment|// Returns true if we have an unwind loop -- the same stack frame unwinding
comment|// multiple times.
name|bool
name|CheckIfLoopingStack
parameter_list|()
function_decl|;
comment|// Indicates whether this frame is frame zero -- the currently
comment|// executing frame -- or not.
name|bool
name|IsFrameZero
argument_list|()
specifier|const
expr_stmt|;
name|void
name|InitializeZerothFrame
parameter_list|()
function_decl|;
name|void
name|InitializeNonZerothFrame
parameter_list|()
function_decl|;
name|SharedPtr
name|GetNextFrame
argument_list|()
specifier|const
expr_stmt|;
name|SharedPtr
name|GetPrevFrame
argument_list|()
specifier|const
expr_stmt|;
comment|// A SkipFrame occurs when the unwind out of frame 0 didn't go right -- we've
comment|// got one bogus frame at frame #1.
comment|// There is a good chance we'll get back on track if we follow the frame
comment|// pointer chain (or whatever is appropriate
comment|// on this ABI) so we allow one invalid frame to be in the stack.  Ideally
comment|// we'll mark this frame specially at some
comment|// point and indicate to the user that the unwinder had a hiccup.  Often when
comment|// this happens we will miss a frame of
comment|// the program's actual stack in the unwind and we want to flag that for the
comment|// user somehow.
name|bool
name|IsSkipFrame
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Determines if a SymbolContext is a trap handler or not
comment|///
comment|/// Given a SymbolContext, determines if this is a trap handler function
comment|/// aka asynchronous signal handler.
comment|///
comment|/// @return
comment|///     Returns true if the SymbolContext is a trap handler.
comment|//------------------------------------------------------------------
name|bool
name|IsTrapHandlerSymbol
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|,
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|m_sym_ctx
argument_list|)
decl|const
decl_stmt|;
comment|// Provide a location for where THIS function saved the CALLER's register
comment|// value
comment|// Or a frame "below" this one saved it, i.e. a function called by this one,
comment|// preserved a register that this
comment|// function didn't modify/use.
comment|//
comment|// The RegisterLocation type may be set to eRegisterNotAvailable -- this will
comment|// happen for a volatile register
comment|// being queried mid-stack.  Instead of floating frame 0's contents of that
comment|// register up the stack (which may
comment|// or may not be the value of that reg when the function was executing), we
comment|// won't return any value.
comment|//
comment|// If a non-volatile register (a "preserved" register) is requested mid-stack
comment|// and no frames "below" the requested
comment|// stack have saved the register anywhere, it is safe to assume that frame 0's
comment|// register values are still the same
comment|// as the requesting frame's.
name|lldb_private
operator|::
name|UnwindLLDB
operator|::
name|RegisterSearchResult
name|SavedLocationForRegister
argument_list|(
argument|uint32_t lldb_regnum
argument_list|,
argument|lldb_private::UnwindLLDB::RegisterLocation&regloc
argument_list|)
expr_stmt|;
name|bool
name|ReadRegisterValueFromRegisterLocation
argument_list|(
name|lldb_private
operator|::
name|UnwindLLDB
operator|::
name|RegisterLocation
name|regloc
argument_list|,
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
name|lldb_private
operator|::
name|RegisterValue
operator|&
name|value
argument_list|)
decl_stmt|;
name|bool
name|WriteRegisterValueToRegisterLocation
argument_list|(
name|lldb_private
operator|::
name|UnwindLLDB
operator|::
name|RegisterLocation
name|regloc
argument_list|,
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
specifier|const
name|lldb_private
operator|::
name|RegisterValue
operator|&
name|value
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// If the unwind has to the caller frame has failed, try something else
comment|///
comment|/// If lldb is using an assembly language based UnwindPlan for a frame and
comment|/// the unwind to the caller frame fails, try falling back to a generic
comment|/// UnwindPlan (architecture default unwindplan) to see if that might work
comment|/// better.  This is mostly helping to work around problems where the
comment|/// assembly language inspection fails on hand-written assembly code.
comment|///
comment|/// @return
comment|///     Returns true if a fallback unwindplan was found& was installed.
comment|//------------------------------------------------------------------
name|bool
name|TryFallbackUnwindPlan
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Switch to the fallback unwind plan unconditionally without any safety
comment|/// checks that it is providing better results than the normal unwind plan.
comment|///
comment|/// The only time it is valid to call this method is if the full unwindplan is
comment|/// found to be fundamentally incorrect/impossible.
comment|///
comment|/// Returns true if it was able to install the fallback unwind plan.
comment|//------------------------------------------------------------------
name|bool
name|ForceSwitchToFallbackUnwindPlan
parameter_list|()
function_decl|;
comment|// Get the contents of a general purpose (address-size) register for this
comment|// frame
comment|// (usually retrieved from the next frame)
name|bool
name|ReadGPRValue
argument_list|(
name|lldb
operator|::
name|RegisterKind
name|register_kind
argument_list|,
name|uint32_t
name|regnum
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|value
argument_list|)
decl_stmt|;
name|bool
name|ReadGPRValue
argument_list|(
specifier|const
name|RegisterNumber
operator|&
name|reg_num
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|value
argument_list|)
decl_stmt|;
comment|// Get the CFA register for a given frame.
name|bool
name|ReadCFAValueForRow
argument_list|(
name|lldb
operator|::
name|RegisterKind
name|register_kind
argument_list|,
specifier|const
name|UnwindPlan
operator|::
name|RowSP
operator|&
name|row
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|value
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|GetFastUnwindPlanForFrame
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|UnwindPlanSP
name|GetFullUnwindPlanForFrame
argument_list|()
expr_stmt|;
name|void
name|UnwindLogMsg
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
block|)
decl_stmt|)
end_decl_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|UnwindLogMsgVerbose
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|bool
name|IsUnwindPlanValidForCurrentPC
argument_list|(
name|lldb
operator|::
name|UnwindPlanSP
name|unwind_plan_sp
argument_list|,
name|int
operator|&
name|valid_pc_offset
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Thread
operator|&
name|m_thread
expr_stmt|;
end_expr_stmt

begin_comment
comment|///
end_comment

begin_comment
comment|// The following tell us how to retrieve the CALLER's register values (ie the
end_comment

begin_comment
comment|// "previous" frame, aka the frame above)
end_comment

begin_comment
comment|// i.e. where THIS frame saved them
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|lldb
operator|::
name|UnwindPlanSP
name|m_fast_unwind_plan_sp
expr_stmt|;
end_expr_stmt

begin_comment
comment|// may be NULL
end_comment

begin_expr_stmt
name|lldb
operator|::
name|UnwindPlanSP
name|m_full_unwind_plan_sp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|UnwindPlanSP
name|m_fallback_unwind_plan_sp
expr_stmt|;
end_expr_stmt

begin_comment
comment|// may be NULL
end_comment

begin_decl_stmt
name|bool
name|m_all_registers_available
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Can we retrieve all regs or just
end_comment

begin_comment
comment|// nonvolatile regs?
end_comment

begin_decl_stmt
name|int
name|m_frame_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|// enum FrameType
end_comment

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|m_cfa
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Address
name|m_start_pc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Address
name|m_current_pc
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|m_current_offset
decl_stmt|;
end_decl_stmt

begin_comment
comment|// how far into the function we've executed; -1 if
end_comment

begin_comment
comment|// unknown
end_comment

begin_comment
comment|// 0 if no instructions have been executed yet.
end_comment

begin_decl_stmt
name|int
name|m_current_offset_backed_up_one
decl_stmt|;
end_decl_stmt

begin_comment
comment|// how far into the function we've
end_comment

begin_comment
comment|// executed; -1 if unknown
end_comment

begin_comment
comment|// 0 if no instructions have been executed yet.
end_comment

begin_comment
comment|// On architectures where the return address on the stack points
end_comment

begin_comment
comment|// to the instruction after the CALL, this value will have 1
end_comment

begin_comment
comment|// subtracted from it.  Else a function that ends in a CALL will
end_comment

begin_comment
comment|// have an offset pointing into the next function's address range.
end_comment

begin_comment
comment|// m_current_pc has the actual address of the "current" pc.
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|m_sym_ctx
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|m_sym_ctx_valid
decl_stmt|;
end_decl_stmt

begin_comment
comment|// if ResolveSymbolContextForAddress fails, don't try to
end_comment

begin_comment
comment|// use m_sym_ctx
end_comment

begin_decl_stmt
name|uint32_t
name|m_frame_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|// What stack frame this RegisterContext is
end_comment

begin_expr_stmt
name|std
operator|::
name|map
operator|<
name|uint32_t
operator|,
name|lldb_private
operator|::
name|UnwindLLDB
operator|::
name|RegisterLocation
operator|>
name|m_registers
expr_stmt|;
end_expr_stmt

begin_comment
comment|// where to find reg values for this frame
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|UnwindLLDB
operator|&
name|m_parent_unwind
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The UnwindLLDB that is creating
end_comment

begin_comment
comment|// this RegisterContextLLDB
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// For RegisterContextLLDB only
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|RegisterContextLLDB
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_RegisterContextLLDB_h_
end_comment

end_unit

