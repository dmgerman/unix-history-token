begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- VariableList.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_VariableList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_VariableList_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/SymbolContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/Variable.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|VariableList
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
comment|//  VariableList(const SymbolContext&symbol_context);
name|VariableList
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|VariableList
argument_list|()
expr_stmt|;
name|void
name|AddVariable
argument_list|(
specifier|const
name|lldb
operator|::
name|VariableSP
operator|&
name|var_sp
argument_list|)
decl_stmt|;
name|bool
name|AddVariableIfUnique
argument_list|(
specifier|const
name|lldb
operator|::
name|VariableSP
operator|&
name|var_sp
argument_list|)
decl_stmt|;
name|void
name|AddVariables
parameter_list|(
name|VariableList
modifier|*
name|variable_list
parameter_list|)
function_decl|;
name|void
name|Clear
parameter_list|()
function_decl|;
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
name|lldb
operator|::
name|VariableSP
name|GetVariableAtIndex
argument_list|(
argument|size_t idx
argument_list|)
specifier|const
expr_stmt|;
name|lldb
operator|::
name|VariableSP
name|RemoveVariableAtIndex
argument_list|(
argument|size_t idx
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|VariableSP
name|FindVariable
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|VariableSP
name|FindVariable
argument_list|(
argument|const ConstString& name
argument_list|,
argument|lldb::ValueType value_type
argument_list|)
expr_stmt|;
name|uint32_t
name|FindVariableIndex
argument_list|(
specifier|const
name|lldb
operator|::
name|VariableSP
operator|&
name|var_sp
argument_list|)
decl_stmt|;
name|size_t
name|AppendVariablesIfUnique
parameter_list|(
name|VariableList
modifier|&
name|var_list
parameter_list|)
function_decl|;
comment|// Returns the actual number of unique variables that were added to the
comment|// list. "total_matches" will get updated with the actualy number of
comment|// matches that were found regardless of whether they were unique or not
comment|// to allow for error conditions when nothing is found, versus conditions
comment|// where any varaibles that match "regex" were already in "var_list".
name|size_t
name|AppendVariablesIfUnique
parameter_list|(
specifier|const
name|RegularExpression
modifier|&
name|regex
parameter_list|,
name|VariableList
modifier|&
name|var_list
parameter_list|,
name|size_t
modifier|&
name|total_matches
parameter_list|)
function_decl|;
name|size_t
name|AppendVariablesWithScope
argument_list|(
name|lldb
operator|::
name|ValueType
name|type
argument_list|,
name|VariableList
operator|&
name|var_list
argument_list|,
name|bool
name|if_unique
operator|=
name|true
argument_list|)
decl_stmt|;
name|uint32_t
name|FindIndexForVariable
parameter_list|(
name|Variable
modifier|*
name|variable
parameter_list|)
function_decl|;
name|size_t
name|MemorySize
argument_list|()
specifier|const
expr_stmt|;
name|size_t
name|GetSize
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|VariableSP
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|collection
name|m_variables
decl_stmt|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For VariableList only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|VariableList
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
comment|// liblldb_VariableList_h_
end_comment

end_unit

