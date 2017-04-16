begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Variable.h -----------------------------------------------*- C++-*-===//
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
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Mangled.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/RangeMap.h"
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

begin_include
include|#
directive|include
file|"lldb/Utility/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
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
name|Variable
range|:
name|public
name|UserID
decl_stmt|,
name|public
name|std
decl|::
name|enable_shared_from_this
decl|<
name|Variable
decl|>
block|{
name|public
label|:
typedef|typedef
name|RangeVector
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|addr_t
operator|>
name|RangeList
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|Variable
argument_list|(
argument|lldb::user_id_t uid
argument_list|,
argument|const char *name
argument_list|,
argument|const char                *mangled
argument_list|,
comment|// The mangled or fully qualified name of the variable.
argument|const lldb::SymbolFileTypeSP&symfile_type_sp
argument_list|,
argument|lldb::ValueType scope
argument_list|,
argument|SymbolContextScope *owner_scope
argument_list|,
argument|const RangeList&scope_range
argument_list|,
argument|Declaration *decl
argument_list|,
argument|const DWARFExpression&location
argument_list|,
argument|bool external
argument_list|,
argument|bool artificial
argument_list|,
argument|bool static_member = false
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|Variable
argument_list|()
expr_stmt|;
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|bool
name|show_context
argument_list|)
decl|const
decl_stmt|;
name|bool
name|DumpDeclaration
parameter_list|(
name|Stream
modifier|*
name|s
parameter_list|,
name|bool
name|show_fullpaths
parameter_list|,
name|bool
name|show_module
parameter_list|)
function_decl|;
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
name|ConstString
name|GetName
argument_list|()
specifier|const
expr_stmt|;
name|ConstString
name|GetUnqualifiedName
argument_list|()
specifier|const
expr_stmt|;
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
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
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
name|LanguageType
name|GetLanguage
argument_list|()
specifier|const
expr_stmt|;
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
name|bool
name|IsStaticMember
argument_list|()
specifier|const
block|{
return|return
name|m_static_member
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
argument_list|(
name|llvm
operator|::
name|StringRef
name|variable_expr_path
argument_list|,
name|ExecutionContextScope
operator|*
name|scope
argument_list|,
name|GetVariableCallback
name|callback
argument_list|,
name|void
operator|*
name|baton
argument_list|,
name|VariableList
operator|&
name|variable_list
argument_list|,
name|ValueObjectList
operator|&
name|valobj_list
argument_list|)
decl_stmt|;
specifier|static
name|size_t
name|AutoComplete
argument_list|(
specifier|const
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|llvm
operator|::
name|StringRef
name|name
argument_list|,
name|StringList
operator|&
name|matches
argument_list|,
name|bool
operator|&
name|word_complete
argument_list|)
decl_stmt|;
name|CompilerDeclContext
name|GetDeclContext
parameter_list|()
function_decl|;
name|CompilerDecl
name|GetDecl
parameter_list|()
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
comment|// The type pointer of the variable
comment|// (int, struct, class, etc)
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
name|RangeList
name|m_scope_range
decl_stmt|;
comment|// The list of ranges inside the owner's scope where
comment|// this variable is valid
name|Declaration
name|m_declaration
decl_stmt|;
comment|// Declaration location for this item.
name|DWARFExpression
name|m_location
decl_stmt|;
comment|// The location of this variable that can be fed
comment|// to DWARFExpression::Evaluate()
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
comment|// Non-zero if the variable is not explicitly declared
comment|// in source
name|m_loc_is_const_data
range|:
literal|1
decl_stmt|,
comment|// The m_location expression contains the
comment|// constant variable value data, not a DWARF
comment|// location
name|m_static_member
range|:
literal|1
decl_stmt|;
comment|// Non-zero if variable is static member of a class
comment|// or struct.
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
comment|// liblldb_Variable_h_
end_comment

end_unit

