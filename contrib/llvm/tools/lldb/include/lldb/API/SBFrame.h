begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBFrame.h -----------------------------------------------*- C++ -*-===//
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
name|LLDB_SBFrame_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBFrame_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBValueList.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|LLDB_API
name|SBFrame
block|{
name|public
label|:
name|SBFrame
argument_list|()
expr_stmt|;
name|SBFrame
argument_list|(
specifier|const
name|lldb
operator|::
name|SBFrame
operator|&
name|rhs
argument_list|)
expr_stmt|;
specifier|const
name|lldb
operator|::
name|SBFrame
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBFrame
operator|&
name|rhs
operator|)
expr_stmt|;
operator|~
name|SBFrame
argument_list|()
expr_stmt|;
name|bool
name|IsEqual
argument_list|(
specifier|const
name|lldb
operator|::
name|SBFrame
operator|&
name|that
argument_list|)
decl|const
decl_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetFrameID
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|GetCFA
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|GetPC
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|SetPC
argument_list|(
name|lldb
operator|::
name|addr_t
name|new_pc
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|GetSP
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|GetFP
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBAddress
name|GetPCAddress
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBSymbolContext
name|GetSymbolContext
argument_list|(
argument|uint32_t resolve_scope
argument_list|)
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBModule
name|GetModule
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBCompileUnit
name|GetCompileUnit
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBFunction
name|GetFunction
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBSymbol
name|GetSymbol
argument_list|()
specifier|const
expr_stmt|;
comment|/// Gets the deepest block that contains the frame PC.
comment|///
comment|/// See also GetFrameBlock().
name|lldb
operator|::
name|SBBlock
name|GetBlock
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get the appropriate function name for this frame. Inlined functions in
comment|/// LLDB are represented by Blocks that have inlined function information, so
comment|/// just looking at the SBFunction or SBSymbol for a frame isn't enough.
comment|/// This function will return the appropriate function, symbol or inlined
comment|/// function name for the frame.
comment|///
comment|/// This function returns:
comment|/// - the name of the inlined function (if there is one)
comment|/// - the name of the concrete function (if there is one)
comment|/// - the name of the symbol (if there is one)
comment|/// - NULL
comment|///
comment|/// See also IsInlined().
specifier|const
name|char
modifier|*
name|GetFunctionName
parameter_list|()
function_decl|;
comment|// Get an appropriate function name for this frame that is suitable for
comment|// display to a user
specifier|const
name|char
modifier|*
name|GetDisplayFunctionName
parameter_list|()
function_decl|;
specifier|const
name|char
operator|*
name|GetFunctionName
argument_list|()
specifier|const
expr_stmt|;
comment|// Return the frame function's language.  If there isn't a function, then
comment|// guess the language type from the mangled name.
name|lldb
operator|::
name|LanguageType
name|GuessLanguage
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return true if this frame represents an inlined function.
comment|///
comment|/// See also GetFunctionName().
name|bool
name|IsInlined
parameter_list|()
function_decl|;
name|bool
name|IsInlined
argument_list|()
specifier|const
expr_stmt|;
comment|/// The version that doesn't supply a 'use_dynamic' value will use the
comment|/// target's default.
name|lldb
operator|::
name|SBValue
name|EvaluateExpression
argument_list|(
specifier|const
name|char
operator|*
name|expr
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|EvaluateExpression
argument_list|(
argument|const char *expr
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|EvaluateExpression
argument_list|(
argument|const char *expr
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|,
argument|bool unwind_on_error
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|EvaluateExpression
argument_list|(
specifier|const
name|char
operator|*
name|expr
argument_list|,
specifier|const
name|SBExpressionOptions
operator|&
name|options
argument_list|)
expr_stmt|;
comment|/// Gets the lexical block that defines the stack frame. Another way to think
comment|/// of this is it will return the block that contains all of the variables
comment|/// for a stack frame. Inlined functions are represented as SBBlock objects
comment|/// that have inlined function information: the name of the inlined function,
comment|/// where it was called from. The block that is returned will be the first
comment|/// block at or above the block for the PC (SBFrame::GetBlock()) that defines
comment|/// the scope of the frame. When a function contains no inlined functions,
comment|/// this will be the top most lexical block that defines the function.
comment|/// When a function has inlined functions and the PC is currently
comment|/// in one of those inlined functions, this method will return the inlined
comment|/// block that defines this frame. If the PC isn't currently in an inlined
comment|/// function, the lexical block that defines the function is returned.
name|lldb
operator|::
name|SBBlock
name|GetFrameBlock
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBLineEntry
name|GetLineEntry
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBThread
name|GetThread
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|Disassemble
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|lldb
operator|::
name|SBFrame
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|lldb
operator|::
name|SBFrame
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
comment|/// The version that doesn't supply a 'use_dynamic' value will use the
comment|/// target's default.
name|lldb
operator|::
name|SBValueList
name|GetVariables
argument_list|(
argument|bool arguments
argument_list|,
argument|bool locals
argument_list|,
argument|bool statics
argument_list|,
argument|bool in_scope_only
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValueList
name|GetVariables
argument_list|(
argument|bool arguments
argument_list|,
argument|bool locals
argument_list|,
argument|bool statics
argument_list|,
argument|bool in_scope_only
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValueList
name|GetVariables
argument_list|(
specifier|const
name|lldb
operator|::
name|SBVariablesOptions
operator|&
name|options
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValueList
name|GetRegisters
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|FindRegister
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
expr_stmt|;
comment|/// The version that doesn't supply a 'use_dynamic' value will use the
comment|/// target's default.
name|lldb
operator|::
name|SBValue
name|FindVariable
argument_list|(
specifier|const
name|char
operator|*
name|var_name
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|FindVariable
argument_list|(
argument|const char *var_name
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|)
expr_stmt|;
comment|// Find a value for a variable expression path like "rect.origin.x" or
comment|// "pt_ptr->x", "*self", "*this->obj_ptr". The returned value is _not_
comment|// and expression result and is not a constant object like
comment|// SBFrame::EvaluateExpression(...) returns, but a child object of
comment|// the variable value.
name|lldb
operator|::
name|SBValue
name|GetValueForVariablePath
argument_list|(
argument|const char *var_expr_cstr
argument_list|,
argument|DynamicValueType use_dynamic
argument_list|)
expr_stmt|;
comment|/// The version that doesn't supply a 'use_dynamic' value will use the
comment|/// target's default.
name|lldb
operator|::
name|SBValue
name|GetValueForVariablePath
argument_list|(
specifier|const
name|char
operator|*
name|var_path
argument_list|)
expr_stmt|;
comment|/// Find variables, register sets, registers, or persistent variables using
comment|/// the frame as the scope.
comment|///
comment|/// NB. This function does not look up ivars in the function object pointer.
comment|/// To do that use GetValueForVariablePath.
comment|///
comment|/// The version that doesn't supply a 'use_dynamic' value will use the
comment|/// target's default.
name|lldb
operator|::
name|SBValue
name|FindValue
argument_list|(
argument|const char *name
argument_list|,
argument|ValueType value_type
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValue
name|FindValue
argument_list|(
argument|const char *name
argument_list|,
argument|ValueType value_type
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|)
expr_stmt|;
name|bool
name|GetDescription
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|)
decl_stmt|;
name|SBFrame
argument_list|(
specifier|const
name|lldb
operator|::
name|StackFrameSP
operator|&
name|lldb_object_sp
argument_list|)
expr_stmt|;
name|protected
label|:
name|friend
name|class
name|SBBlock
decl_stmt|;
name|friend
name|class
name|SBExecutionContext
decl_stmt|;
name|friend
name|class
name|SBInstruction
decl_stmt|;
name|friend
name|class
name|SBThread
decl_stmt|;
name|friend
name|class
name|SBValue
decl_stmt|;
name|lldb
operator|::
name|StackFrameSP
name|GetFrameSP
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetFrameSP
argument_list|(
specifier|const
name|lldb
operator|::
name|StackFrameSP
operator|&
name|lldb_object_sp
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|ExecutionContextRefSP
name|m_opaque_sp
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBFrame_h_
end_comment

end_unit

