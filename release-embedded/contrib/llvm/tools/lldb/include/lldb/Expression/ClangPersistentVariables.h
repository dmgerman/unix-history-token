begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangPersistentVariables.h ------------------------------*- C++ -*-===//
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
name|liblldb_ClangPersistentVariables_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ClangPersistentVariables_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Expression/ClangExpressionVariable.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ClangPersistentVariables ClangPersistentVariables.h "lldb/Expression/ClangPersistentVariables.h"
comment|/// @brief Manages persistent values that need to be preserved between expression invocations.
comment|///
comment|/// A list of variables that can be accessed and updated by any expression.  See
comment|/// ClangPersistentVariable for more discussion.  Also provides an increasing,
comment|/// 0-based counter for naming result variables.
comment|//----------------------------------------------------------------------
name|class
name|ClangPersistentVariables
range|:
name|public
name|ClangExpressionVariableList
block|{
name|public
operator|:
comment|//----------------------------------------------------------------------
comment|/// Constructor
comment|//----------------------------------------------------------------------
name|ClangPersistentVariables
argument_list|()
block|;
name|lldb
operator|::
name|ClangExpressionVariableSP
name|CreatePersistentVariable
argument_list|(
specifier|const
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|valobj_sp
argument_list|)
block|;
name|lldb
operator|::
name|ClangExpressionVariableSP
name|CreatePersistentVariable
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|const ConstString&name
argument_list|,
argument|const TypeFromUser& user_type
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|,
argument|uint32_t addr_byte_size
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Return the next entry in the sequence of strings "$0", "$1", ... for
comment|/// use naming persistent expression convenience variables.
comment|///
comment|/// @return
comment|///     A string that contains the next persistent variable name.
comment|//----------------------------------------------------------------------
name|ConstString
name|GetNextPersistentVariableName
argument_list|()
block|;
name|void
name|RemovePersistentVariable
argument_list|(
argument|lldb::ClangExpressionVariableSP variable
argument_list|)
block|;
name|void
name|RegisterPersistentType
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|,
name|clang
operator|::
name|TypeDecl
operator|*
name|tag_decl
argument_list|)
block|;
name|clang
operator|::
name|TypeDecl
operator|*
name|GetPersistentType
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
block|;
name|private
operator|:
name|uint32_t
name|m_next_persistent_variable_id
block|;
comment|///< The counter used by GetNextResultName().
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|char
operator|*
operator|,
name|clang
operator|::
name|TypeDecl
operator|*
operator|>
name|PersistentTypeMap
expr_stmt|;
name|PersistentTypeMap
name|m_persistent_types
decl_stmt|;
comment|///< The persistent types declared by the user.
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

