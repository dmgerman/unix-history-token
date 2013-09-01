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

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Flags.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Scalar.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StreamString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/UserID.h"
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

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|StackFrame
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|StackFrame
operator|>
decl_stmt|,
name|public
name|ExecutionContextScope
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
block|}
enum|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
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
argument|const Address& pc
argument_list|,
argument|const SymbolContext *sc_ptr
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|StackFrame
argument_list|()
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
specifier|const
name|Address
modifier|&
name|GetFrameCodeAddress
parameter_list|()
function_decl|;
name|void
name|ChangePC
argument_list|(
name|lldb
operator|::
name|addr_t
name|pc
argument_list|)
decl_stmt|;
specifier|const
name|SymbolContext
modifier|&
name|GetSymbolContext
parameter_list|(
name|uint32_t
name|resolve_scope
parameter_list|)
function_decl|;
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
name|Block
modifier|*
name|GetFrameBlock
parameter_list|()
function_decl|;
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
name|VariableList
modifier|*
name|GetVariableList
parameter_list|(
name|bool
name|get_file_globals
parameter_list|)
function_decl|;
name|lldb
operator|::
name|VariableListSP
name|GetInScopeVariableList
argument_list|(
argument|bool get_file_globals
argument_list|)
expr_stmt|;
comment|// See ExpressionPathOption enumeration for "options" values
name|lldb
operator|::
name|ValueObjectSP
name|GetValueForVariableExpressionPath
argument_list|(
argument|const char *var_expr
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
name|bool
name|HasDebugInformation
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|Disassemble
parameter_list|()
function_decl|;
name|void
name|DumpUsingSettingsFormat
parameter_list|(
name|Stream
modifier|*
name|strm
parameter_list|)
function_decl|;
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
name|bool
name|IsInlined
parameter_list|()
function_decl|;
name|uint32_t
name|GetFrameIndex
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetConcreteFrameIndex
argument_list|()
specifier|const
block|{
return|return
name|m_concrete_frame_index
return|;
block|}
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
comment|// lldb::ExecutionContextScope pure virtual functions
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|TargetSP
name|CalculateTarget
argument_list|()
expr_stmt|;
name|virtual
name|lldb
operator|::
name|ProcessSP
name|CalculateProcess
argument_list|()
expr_stmt|;
name|virtual
name|lldb
operator|::
name|ThreadSP
name|CalculateThread
argument_list|()
expr_stmt|;
name|virtual
name|lldb
operator|::
name|StackFrameSP
name|CalculateStackFrame
argument_list|()
expr_stmt|;
name|virtual
name|void
name|CalculateExecutionContext
parameter_list|(
name|ExecutionContext
modifier|&
name|exe_ctx
parameter_list|)
function_decl|;
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
parameter_list|)
function_decl|;
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
comment|// The frame code address (might not be the same as the actual PC for inlined frames) as a section/offset address
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
name|lldb
operator|::
name|VariableListSP
name|m_variable_list_sp
expr_stmt|;
name|ValueObjectList
name|m_variable_list_value_objects
decl_stmt|;
comment|// Value objects for each variable in m_variable_list_sp
name|StreamString
name|m_disassembly
decl_stmt|;
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

