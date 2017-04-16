begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StackFrame.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_StackFrame_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_StackFrame_h_
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
file|<memory>
end_include

begin_include
include|#
directive|include
file|<mutex>
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
file|"lldb/Utility/Flags.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Scalar.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ValueObjectList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/SymbolContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContextScope.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/StackID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StreamString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UserID.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|/// @class StackFrame StackFrame.h "lldb/Target/StackFrame.h"
comment|///
comment|/// @brief This base class provides an interface to stack frames.
comment|///
comment|/// StackFrames may have a Canonical Frame Address (CFA) or not.
comment|/// A frame may have a plain pc value or it may have a pc value + stop_id
comment|/// to indicate a specific point in the debug session so the correct section
comment|/// load list is used for symbolication.
comment|///
comment|/// Local variables may be available, or not.  A register context may be
comment|/// available, or not.
name|class
name|StackFrame
range|:
name|public
name|ExecutionContextScope
decl_stmt|,
name|public
name|std
decl|::
name|enable_shared_from_this
decl|<
name|StackFrame
decl|>
block|{
name|public
label|:
enum|enum
name|ExpressionPathOption
block|{
name|eExpressionPathOptionCheckPtrVsMember
init|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
block|,
name|eExpressionPathOptionsNoFragileObjcIvar
init|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
block|,
name|eExpressionPathOptionsNoSyntheticChildren
init|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
block|,
name|eExpressionPathOptionsNoSyntheticArrayRange
init|=
operator|(
literal|1u
operator|<<
literal|3
operator|)
block|,
name|eExpressionPathOptionsAllowDirectIVarAccess
init|=
operator|(
literal|1u
operator|<<
literal|4
operator|)
block|,
name|eExpressionPathOptionsInspectAnonymousUnions
init|=
operator|(
literal|1u
operator|<<
literal|5
operator|)
block|}
enum|;
comment|//------------------------------------------------------------------
comment|/// Construct a StackFrame object without supplying a RegisterContextSP.
comment|///
comment|/// This is the one constructor that doesn't take a RegisterContext
comment|/// parameter.  This ctor may be called when creating a history StackFrame;
comment|/// these are used if we've collected a stack trace of pc addresses at
comment|/// some point in the past.  We may only have pc values.  We may have pc
comment|/// values and the stop_id when the stack trace was recorded.  We may have a
comment|/// CFA, or more likely, we won't.
comment|///
comment|/// @param [in] thread_sp
comment|///   The Thread that this frame belongs to.
comment|///
comment|/// @param [in] frame_idx
comment|///   This StackFrame's frame index number in the Thread.  If inlined stack
comment|///   frames are being created, this may differ from the concrete_frame_idx
comment|///   which is the frame index without any inlined stack frames.
comment|///
comment|/// @param [in] concrete_frame_idx
comment|///   The StackFrame's frame index number in the Thread without any inlined
comment|///   stack frames being included in the index.
comment|///
comment|/// @param [in] cfa
comment|///   The Canonical Frame Address (this terminology from DWARF) for this
comment|///   stack frame.  The CFA for a stack frame does not change over the
comment|///   span of the stack frame's existence.  It is often the value of the
comment|///   caller's stack pointer before the call instruction into this frame's
comment|///   function.  It is usually not the same as the frame pointer register's
comment|///   value.
comment|///
comment|/// @param [in] cfa_is_valid
comment|///   A history stack frame may not have a CFA value collected.  We want to
comment|///   distinguish between "no CFA available" and a CFA of
comment|///   LLDB_INVALID_ADDRESS.
comment|///
comment|/// @param [in] pc
comment|///   The current pc value of this stack frame.
comment|///
comment|/// @param [in] stop_id
comment|///   The stop_id which should be used when looking up symbols for the pc
comment|///   value,
comment|///   if appropriate.  This argument is ignored if stop_id_is_valid is false.
comment|///
comment|/// @param [in] stop_id_is_valid
comment|///   If the stop_id argument provided is not needed for this StackFrame, this
comment|///   should be false.  If this is a history stack frame and we know the
comment|///   stop_id
comment|///   when the pc value was collected, that stop_id should be provided and
comment|///   this
comment|///   will be true.
comment|///
comment|/// @param [in] is_history_frame
comment|///   If this is a historical stack frame -- possibly without CFA or registers
comment|///   or
comment|///   local variables -- then this should be set to true.
comment|///
comment|/// @param [in] sc_ptr
comment|///   Optionally seed the StackFrame with the SymbolContext information that
comment|///   has
comment|///   already been discovered.
comment|//------------------------------------------------------------------
name|StackFrame
argument_list|(
argument|const lldb::ThreadSP&thread_sp
argument_list|,
argument|lldb::user_id_t frame_idx
argument_list|,
argument|lldb::user_id_t concrete_frame_idx
argument_list|,
argument|lldb::addr_t cfa
argument_list|,
argument|bool cfa_is_valid
argument_list|,
argument|lldb::addr_t pc
argument_list|,
argument|uint32_t stop_id
argument_list|,
argument|bool stop_id_is_valid
argument_list|,
argument|bool is_history_frame
argument_list|,
argument|const SymbolContext *sc_ptr
argument_list|)
empty_stmt|;
name|StackFrame
argument_list|(
argument|const lldb::ThreadSP&thread_sp
argument_list|,
argument|lldb::user_id_t frame_idx
argument_list|,
argument|lldb::user_id_t concrete_frame_idx
argument_list|,
argument|const lldb::RegisterContextSP&reg_context_sp
argument_list|,
argument|lldb::addr_t cfa
argument_list|,
argument|lldb::addr_t pc
argument_list|,
argument|const SymbolContext *sc_ptr
argument_list|)
empty_stmt|;
name|StackFrame
argument_list|(
argument|const lldb::ThreadSP&thread_sp
argument_list|,
argument|lldb::user_id_t frame_idx
argument_list|,
argument|lldb::user_id_t concrete_frame_idx
argument_list|,
argument|const lldb::RegisterContextSP&reg_context_sp
argument_list|,
argument|lldb::addr_t cfa
argument_list|,
argument|const Address&pc
argument_list|,
argument|const SymbolContext *sc_ptr
argument_list|)
empty_stmt|;
operator|~
name|StackFrame
argument_list|()
name|override
expr_stmt|;
name|lldb
operator|::
name|ThreadSP
name|GetThread
argument_list|()
specifier|const
block|{
return|return
name|m_thread_wp
operator|.
name|lock
argument_list|()
return|;
block|}
name|StackID
modifier|&
name|GetStackID
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get an Address for the current pc value in this StackFrame.
comment|///
comment|/// May not be the same as the actual PC value for inlined stack frames.
comment|///
comment|/// @return
comment|///   The Address object set to the current PC value.
comment|//------------------------------------------------------------------
specifier|const
name|Address
modifier|&
name|GetFrameCodeAddress
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Change the pc value for a given thread.
comment|///
comment|/// Change the current pc value for the frame on this thread.
comment|///
comment|/// @param[in] pc
comment|///     The load address that the pc will be set to.
comment|///
comment|/// @return
comment|///     true if the pc was changed.  false if this failed -- possibly
comment|///     because this frame is not a live StackFrame.
comment|//------------------------------------------------------------------
name|bool
name|ChangePC
argument_list|(
name|lldb
operator|::
name|addr_t
name|pc
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Provide a SymbolContext for this StackFrame's current pc value.
comment|///
comment|/// The StackFrame maintains this SymbolContext and adds additional
comment|/// information
comment|/// to it on an as-needed basis.  This helps to avoid different functions
comment|/// looking up symbolic information for a given pc value multiple times.
comment|///
comment|/// @params [in] resolve_scope
comment|///   Flags from the SymbolContextItem enumerated type which specify what
comment|///   type of symbol context is needed by this caller.
comment|///
comment|/// @return
comment|///   A SymbolContext reference which includes the types of information
comment|///   requested by resolve_scope, if they are available.
comment|//------------------------------------------------------------------
specifier|const
name|SymbolContext
modifier|&
name|GetSymbolContext
parameter_list|(
name|uint32_t
name|resolve_scope
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Return the Canonical Frame Address (DWARF term) for this frame.
comment|///
comment|/// The CFA is typically the value of the stack pointer register before
comment|/// the call invocation is made.  It will not change during the lifetime
comment|/// of a stack frame.  It is often not the same thing as the frame pointer
comment|/// register value.
comment|///
comment|/// Live StackFrames will always have a CFA but other types of frames may
comment|/// not be able to supply one.
comment|///
comment|/// @param [out] value
comment|///   The address of the CFA for this frame, if available.
comment|///
comment|/// @param [out] error_ptr
comment|///   If there is an error determining the CFA address, this may contain a
comment|///   string explaining the failure.
comment|///
comment|/// @return
comment|///   Returns true if the CFA value was successfully set in value.  Some
comment|///   frames may be unable to provide this value; they will return false.
comment|//------------------------------------------------------------------
name|bool
name|GetFrameBaseValue
parameter_list|(
name|Scalar
modifier|&
name|value
parameter_list|,
name|Error
modifier|*
name|error_ptr
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the DWARFExpression corresponding to the Canonical Frame Address.
comment|///
comment|/// Often a register (bp), but sometimes a register + offset.
comment|///
comment|/// @param [out] error_ptr
comment|///   If there is an error determining the CFA address, this may contain a
comment|///   string explaining the failure.
comment|///
comment|/// @return
comment|///   Returns the corresponding DWARF expression, or NULL.
comment|//------------------------------------------------------------------
name|DWARFExpression
modifier|*
name|GetFrameBaseExpression
parameter_list|(
name|Error
modifier|*
name|error_ptr
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the current lexical scope block for this StackFrame, if possible.
comment|///
comment|/// If debug information is available for this stack frame, return a
comment|/// pointer to the innermost lexical Block that the frame is currently
comment|/// executing.
comment|///
comment|/// @return
comment|///   A pointer to the current Block.  nullptr is returned if this can
comment|///   not be provided.
comment|//------------------------------------------------------------------
name|Block
modifier|*
name|GetFrameBlock
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the RegisterContext for this frame, if possible.
comment|///
comment|/// Returns a shared pointer to the RegisterContext for this stack frame.
comment|/// Only a live StackFrame object will be able to return a RegisterContext -
comment|/// callers must be prepared for an empty shared pointer being returned.
comment|///
comment|/// Even a live StackFrame RegisterContext may not be able to provide all
comment|/// registers.  Only the currently executing frame (frame 0) can reliably
comment|/// provide every register in the register context.
comment|///
comment|/// @return
comment|///   The RegisterContext shared point for this frame.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|RegisterContextSP
name|GetRegisterContext
argument_list|()
expr_stmt|;
specifier|const
name|lldb
operator|::
name|RegisterContextSP
operator|&
name|GetRegisterContextSP
argument_list|()
specifier|const
block|{
return|return
name|m_reg_context_sp
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Retrieve the list of variables that are in scope at this StackFrame's pc.
comment|///
comment|/// A frame that is not live may return an empty VariableList for a given
comment|/// pc value even though variables would be available at this point if
comment|/// it were a live stack frame.
comment|///
comment|/// @param[in] get_file_globals
comment|///     Whether to also retrieve compilation-unit scoped variables
comment|///     that are visible to the entire compilation unit (e.g. file
comment|///     static in C, globals that are homed in this CU).
comment|///
comment|/// @return
comment|///     A pointer to a list of variables.
comment|//------------------------------------------------------------------
name|VariableList
modifier|*
name|GetVariableList
parameter_list|(
name|bool
name|get_file_globals
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Retrieve the list of variables that are in scope at this StackFrame's pc.
comment|///
comment|/// A frame that is not live may return an empty VariableListSP for a
comment|/// given pc value even though variables would be available at this point
comment|/// if it were a live stack frame.
comment|///
comment|/// @param[in] get_file_globals
comment|///     Whether to also retrieve compilation-unit scoped variables
comment|///     that are visible to the entire compilation unit (e.g. file
comment|///     static in C, globals that are homed in this CU).
comment|///
comment|/// @return
comment|///     A pointer to a list of variables.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|VariableListSP
name|GetInScopeVariableList
argument_list|(
argument|bool get_file_globals
argument_list|,
argument|bool must_have_valid_location = false
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Create a ValueObject for a variable name / pathname, possibly
comment|/// including simple dereference/child selection syntax.
comment|///
comment|/// @param[in] var_expr
comment|///     The string specifying a variable to base the VariableObject off
comment|///     of.
comment|///
comment|/// @param[in] use_dynamic
comment|///     Whether the correct dynamic type of an object pointer should be
comment|///     determined before creating the object, or if the static type is
comment|///     sufficient.  One of the DynamicValueType enumerated values.
comment|///
comment|/// @param[in] options
comment|///     An unsigned integer of flags, values from
comment|///     StackFrame::ExpressionPathOption
comment|///     enum.
comment|/// @param[in] var_sp
comment|///     A VariableSP that will be set to the variable described in the
comment|///     var_expr path.
comment|///
comment|/// @param[in] error
comment|///     Record any errors encountered while evaluating var_expr.
comment|///
comment|/// @return
comment|///     A shared pointer to the ValueObject described by var_expr.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ValueObjectSP
name|GetValueForVariableExpressionPath
argument_list|(
argument|llvm::StringRef var_expr
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|,
argument|uint32_t options
argument_list|,
argument|lldb::VariableSP&var_sp
argument_list|,
argument|Error&error
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Determine whether this StackFrame has debug information available or not
comment|///
comment|/// @return
comment|//    true if debug information is available for this frame (function,
comment|//    compilation unit, block, etc.)
comment|//------------------------------------------------------------------
name|bool
name|HasDebugInformation
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Return the disassembly for the instructions of this StackFrame's function
comment|/// as a single C string.
comment|///
comment|/// @return
comment|//    C string with the assembly instructions for this function.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|Disassemble
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Print a description for this frame using the frame-format formatter
comment|/// settings.
comment|///
comment|/// @param [in] strm
comment|///   The Stream to print the description to.
comment|///
comment|/// @param [in] frame_marker
comment|///   Optional string that will be prepended to the frame output description.
comment|//------------------------------------------------------------------
name|void
name|DumpUsingSettingsFormat
parameter_list|(
name|Stream
modifier|*
name|strm
parameter_list|,
specifier|const
name|char
modifier|*
name|frame_marker
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Print a description for this frame using a default format.
comment|///
comment|/// @param [in] strm
comment|///   The Stream to print the description to.
comment|///
comment|/// @param [in] show_frame_index
comment|///   Whether to print the frame number or not.
comment|///
comment|/// @param [in] show_fullpaths
comment|///   Whether to print the full source paths or just the file base name.
comment|//------------------------------------------------------------------
name|void
name|Dump
parameter_list|(
name|Stream
modifier|*
name|strm
parameter_list|,
name|bool
name|show_frame_index
parameter_list|,
name|bool
name|show_fullpaths
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Print a description of this stack frame and/or the source context/assembly
comment|/// for this stack frame.
comment|///
comment|/// @param[in] strm
comment|///   The Stream to send the output to.
comment|///
comment|/// @param[in] show_frame_info
comment|///   If true, print the frame info by calling DumpUsingSettingsFormat().
comment|///
comment|/// @param[in] show_source
comment|///   If true, print source or disassembly as per the user's settings.
comment|///
comment|/// @param[in] frame_marker
comment|///   Passed to DumpUsingSettingsFormat() for the frame info printing.
comment|///
comment|/// @return
comment|///   Returns true if successful.
comment|//------------------------------------------------------------------
name|bool
name|GetStatus
parameter_list|(
name|Stream
modifier|&
name|strm
parameter_list|,
name|bool
name|show_frame_info
parameter_list|,
name|bool
name|show_source
parameter_list|,
specifier|const
name|char
modifier|*
name|frame_marker
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Query whether this frame is a concrete frame on the call stack,
comment|/// or if it is an inlined frame derived from the debug information
comment|/// and presented by the debugger.
comment|///
comment|/// @return
comment|///   true if this is an inlined frame.
comment|//------------------------------------------------------------------
name|bool
name|IsInlined
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Query this frame to find what frame it is in this Thread's StackFrameList.
comment|///
comment|/// @return
comment|///   StackFrame index 0 indicates the currently-executing function.  Inline
comment|///   frames are included in this frame index count.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetFrameIndex
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Query this frame to find what frame it is in this Thread's StackFrameList,
comment|/// not counting inlined frames.
comment|///
comment|/// @return
comment|///   StackFrame index 0 indicates the currently-executing function.  Inline
comment|///   frames are not included in this frame index count; their concrete
comment|///   frame index will be the same as the concrete frame that they are
comment|///   derived from.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetConcreteFrameIndex
argument_list|()
specifier|const
block|{
return|return
name|m_concrete_frame_index
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Create a ValueObject for a given Variable in this StackFrame.
comment|///
comment|/// @params [in] variable_sp
comment|///   The Variable to base this ValueObject on
comment|///
comment|/// @params [in] use_dynamic
comment|///     Whether the correct dynamic type of the variable should be
comment|///     determined before creating the ValueObject, or if the static type
comment|///     is sufficient.  One of the DynamicValueType enumerated values.
comment|///
comment|/// @return
comment|//    A ValueObject for this variable.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ValueObjectSP
name|GetValueObjectForFrameVariable
argument_list|(
argument|const lldb::VariableSP&variable_sp
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Add an arbitrary Variable object (e.g. one that specifics a global or
comment|/// static)
comment|/// to a StackFrame's list of ValueObjects.
comment|///
comment|/// @params [in] variable_sp
comment|///   The Variable to base this ValueObject on
comment|///
comment|/// @params [in] use_dynamic
comment|///     Whether the correct dynamic type of the variable should be
comment|///     determined before creating the ValueObject, or if the static type
comment|///     is sufficient.  One of the DynamicValueType enumerated values.
comment|///
comment|/// @return
comment|//    A ValueObject for this variable.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ValueObjectSP
name|TrackGlobalVariable
argument_list|(
argument|const lldb::VariableSP&variable_sp
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Query this frame to determine what the default language should be
comment|/// when parsing expressions given the execution context.
comment|///
comment|/// @return
comment|///   The language of the frame if known, else lldb::eLanguageTypeUnknown.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|LanguageType
name|GetLanguage
argument_list|()
expr_stmt|;
comment|// similar to GetLanguage(), but is allowed to take a potentially incorrect
comment|// guess
comment|// if exact information is not available
name|lldb
operator|::
name|LanguageType
name|GuessLanguage
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Attempt to econstruct the ValueObject for a given raw address touched by
comment|/// the current instruction.  The ExpressionPath should indicate how to get
comment|/// to this value using "frame variable."
comment|///
comment|/// @params [in] addr
comment|///   The raw address.
comment|///
comment|/// @return
comment|///   The ValueObject if found.  If valid, it has a valid ExpressionPath.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ValueObjectSP
name|GuessValueForAddress
argument_list|(
argument|lldb::addr_t addr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Attempt to reconstruct the ValueObject for the address contained in a
comment|/// given register plus an offset.  The ExpressionPath should indicate how to
comment|/// get to this value using "frame variable."
comment|///
comment|/// @params [in] reg
comment|///   The name of the register.
comment|///
comment|/// @params [in] offset
comment|///   The offset from the register.  Particularly important for sp...
comment|///
comment|/// @return
comment|///   The ValueObject if found.  If valid, it has a valid ExpressionPath.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ValueObjectSP
name|GuessValueForRegisterAndOffset
argument_list|(
argument|ConstString reg
argument_list|,
argument|int64_t offset
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// lldb::ExecutionContextScope pure virtual functions
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|TargetSP
name|CalculateTarget
argument_list|()
name|override
expr_stmt|;
name|lldb
operator|::
name|ProcessSP
name|CalculateProcess
argument_list|()
name|override
expr_stmt|;
name|lldb
operator|::
name|ThreadSP
name|CalculateThread
argument_list|()
name|override
expr_stmt|;
name|lldb
operator|::
name|StackFrameSP
name|CalculateStackFrame
argument_list|()
name|override
expr_stmt|;
name|void
name|CalculateExecutionContext
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|)
name|override
decl_stmt|;
name|protected
label|:
name|friend
name|class
name|StackFrameList
decl_stmt|;
name|void
name|SetSymbolContextScope
parameter_list|(
name|SymbolContextScope
modifier|*
name|symbol_scope
parameter_list|)
function_decl|;
name|void
name|UpdateCurrentFrameFromPreviousFrame
parameter_list|(
name|StackFrame
modifier|&
name|prev_frame
parameter_list|)
function_decl|;
name|void
name|UpdatePreviousFrameFromCurrentFrame
parameter_list|(
name|StackFrame
modifier|&
name|curr_frame
parameter_list|)
function_decl|;
name|bool
name|HasCachedData
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For StackFrame only
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ThreadWP
name|m_thread_wp
expr_stmt|;
name|uint32_t
name|m_frame_index
decl_stmt|;
name|uint32_t
name|m_concrete_frame_index
decl_stmt|;
name|lldb
operator|::
name|RegisterContextSP
name|m_reg_context_sp
expr_stmt|;
name|StackID
name|m_id
decl_stmt|;
name|Address
name|m_frame_code_addr
decl_stmt|;
comment|// The frame code address (might not be the same as
comment|// the actual PC for inlined frames) as a
comment|// section/offset address
name|SymbolContext
name|m_sc
decl_stmt|;
name|Flags
name|m_flags
decl_stmt|;
name|Scalar
name|m_frame_base
decl_stmt|;
name|Error
name|m_frame_base_error
decl_stmt|;
name|bool
name|m_cfa_is_valid
decl_stmt|;
comment|// Does this frame have a CFA?  Different from CFA ==
comment|// LLDB_INVALID_ADDRESS
name|uint32_t
name|m_stop_id
decl_stmt|;
name|bool
name|m_stop_id_is_valid
decl_stmt|;
comment|// Does this frame have a stop_id?  Use it when
comment|// referring to the m_frame_code_addr.
name|bool
name|m_is_history_frame
decl_stmt|;
name|lldb
operator|::
name|VariableListSP
name|m_variable_list_sp
expr_stmt|;
name|ValueObjectList
name|m_variable_list_value_objects
decl_stmt|;
comment|// Value objects for each
comment|// variable in
comment|// m_variable_list_sp
name|StreamString
name|m_disassembly
decl_stmt|;
name|std
operator|::
name|recursive_mutex
name|m_mutex
expr_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|StackFrame
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
comment|// liblldb_StackFrame_h_
end_comment

end_unit

