begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Variable.h ----------------------------------------------*- C++ -*-===//
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
name|liblldb_Variable_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Variable_h_
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Mangled.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/DWARFExpression.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/Declaration.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Variable
range|:
name|public
name|UserID
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|Variable
argument_list|(
argument|lldb::user_id_t uid
argument_list|,
argument|const char *name
argument_list|,
argument|const char *mangled
argument_list|,
comment|// The mangled variable name for variables in namespaces
argument|const lldb::SymbolFileTypeSP&symfile_type_sp
argument_list|,
argument|lldb::ValueType scope
argument_list|,
argument|SymbolContextScope *owner_scope
argument_list|,
argument|Declaration* decl
argument_list|,
argument|const DWARFExpression& location
argument_list|,
argument|bool external
argument_list|,
argument|bool artificial
argument_list|)
block|;
name|virtual
operator|~
name|Variable
argument_list|()
block|;
name|void
name|Dump
argument_list|(
argument|Stream *s
argument_list|,
argument|bool show_context
argument_list|)
specifier|const
block|;
name|bool
name|DumpDeclaration
argument_list|(
argument|Stream *s
argument_list|,
argument|bool show_fullpaths
argument_list|,
argument|bool show_module
argument_list|)
block|;
specifier|const
name|Declaration
operator|&
name|GetDeclaration
argument_list|()
specifier|const
block|{
return|return
name|m_declaration
return|;
block|}
specifier|const
name|ConstString
operator|&
name|GetName
argument_list|()
specifier|const
block|;
name|SymbolContextScope
operator|*
name|GetSymbolContextScope
argument_list|()
specifier|const
block|{
return|return
name|m_owner_scope
return|;
block|}
comment|// Since a variable can have a basename "i" and also a mangled
comment|// named "_ZN12_GLOBAL__N_11iE" and a demangled mangled name
comment|// "(anonymous namespace)::i", this function will allow a generic match
comment|// function that can be called by commands and expression parsers to make
comment|// sure we match anything we come across.
name|bool
name|NameMatches
argument_list|(
argument|const ConstString&name
argument_list|)
specifier|const
block|{
if|if
condition|(
name|m_name
operator|==
name|name
condition|)
return|return
name|true
return|;
return|return
name|m_mangled
operator|.
name|NameMatches
argument_list|(
name|name
argument_list|)
return|;
block|}
name|bool
name|NameMatches
argument_list|(
specifier|const
name|RegularExpression
operator|&
name|regex
argument_list|)
decl|const
decl_stmt|;
name|Type
modifier|*
name|GetType
parameter_list|()
function_decl|;
name|lldb
operator|::
name|ValueType
name|GetScope
argument_list|()
specifier|const
block|{
return|return
name|m_scope
return|;
block|}
name|bool
name|IsExternal
argument_list|()
specifier|const
block|{
return|return
name|m_external
return|;
block|}
name|bool
name|IsArtificial
argument_list|()
specifier|const
block|{
return|return
name|m_artificial
return|;
block|}
name|DWARFExpression
modifier|&
name|LocationExpression
parameter_list|()
block|{
return|return
name|m_location
return|;
block|}
specifier|const
name|DWARFExpression
operator|&
name|LocationExpression
argument_list|()
specifier|const
block|{
return|return
name|m_location
return|;
block|}
name|bool
name|DumpLocationForAddress
parameter_list|(
name|Stream
modifier|*
name|s
parameter_list|,
specifier|const
name|Address
modifier|&
name|address
parameter_list|)
function_decl|;
name|size_t
name|MemorySize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|CalculateSymbolContext
parameter_list|(
name|SymbolContext
modifier|*
name|sc
parameter_list|)
function_decl|;
name|bool
name|IsInScope
parameter_list|(
name|StackFrame
modifier|*
name|frame
parameter_list|)
function_decl|;
name|bool
name|LocationIsValidForFrame
parameter_list|(
name|StackFrame
modifier|*
name|frame
parameter_list|)
function_decl|;
name|bool
name|LocationIsValidForAddress
parameter_list|(
specifier|const
name|Address
modifier|&
name|address
parameter_list|)
function_decl|;
name|bool
name|GetLocationIsConstantValueData
argument_list|()
specifier|const
block|{
return|return
name|m_loc_is_const_data
return|;
block|}
name|void
name|SetLocationIsConstantValueData
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_loc_is_const_data
operator|=
name|b
expr_stmt|;
block|}
typedef|typedef
name|size_t
function_decl|(
modifier|*
name|GetVariableCallback
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|VariableList
modifier|&
name|var_list
parameter_list|)
function_decl|;
specifier|static
name|Error
name|GetValuesForVariableExpressionPath
parameter_list|(
specifier|const
name|char
modifier|*
name|variable_expr_path
parameter_list|,
name|ExecutionContextScope
modifier|*
name|scope
parameter_list|,
name|GetVariableCallback
name|callback
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
name|VariableList
modifier|&
name|variable_list
parameter_list|,
name|ValueObjectList
modifier|&
name|valobj_list
parameter_list|)
function_decl|;
specifier|static
name|size_t
name|AutoComplete
parameter_list|(
specifier|const
name|ExecutionContext
modifier|&
name|exe_ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|StringList
modifier|&
name|matches
parameter_list|,
name|bool
modifier|&
name|word_complete
parameter_list|)
function_decl|;
name|protected
label|:
name|ConstString
name|m_name
decl_stmt|;
comment|// The basename of the variable (no namespaces)
name|Mangled
name|m_mangled
decl_stmt|;
comment|// The mangled name of the variable
name|lldb
operator|::
name|SymbolFileTypeSP
name|m_symfile_type_sp
expr_stmt|;
comment|// The type pointer of the variable (int, struct, class, etc)
name|lldb
operator|::
name|ValueType
name|m_scope
expr_stmt|;
comment|// global, parameter, local
name|SymbolContextScope
modifier|*
name|m_owner_scope
decl_stmt|;
comment|// The symbol file scope that this variable was defined in
name|Declaration
name|m_declaration
decl_stmt|;
comment|// Declaration location for this item.
name|DWARFExpression
name|m_location
decl_stmt|;
comment|// The location of this variable that can be fed to DWARFExpression::Evaluate()
name|uint8_t
name|m_external
range|:
literal|1
decl_stmt|,
comment|// Visible outside the containing compile unit?
name|m_artificial
range|:
literal|1
decl_stmt|,
comment|// Non-zero if the variable is not explicitly declared in source
name|m_loc_is_const_data
range|:
literal|1
decl_stmt|;
comment|// The m_location expression contains the constant variable value data, not a DWARF location
name|private
label|:
name|Variable
argument_list|(
specifier|const
name|Variable
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|Variable
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Variable
operator|&
name|rhs
operator|)
decl_stmt|;
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
comment|// liblldb_Variable_h_
end_comment

end_unit

