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

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"ClangExpressionVariable.h"
end_include

begin_include
include|#
directive|include
file|"ClangModulesDeclVendor.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/ExpressionVariable.h"
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
name|PersistentExpressionState
block|{
name|public
operator|:
name|ClangPersistentVariables
argument_list|()
block|;
operator|~
name|ClangPersistentVariables
argument_list|()
name|override
operator|=
expr|default
block|;
comment|//------------------------------------------------------------------
comment|// llvm casting support
comment|//------------------------------------------------------------------
specifier|static
name|bool
name|classof
argument_list|(
argument|const PersistentExpressionState *pv
argument_list|)
block|{
return|return
name|pv
operator|->
name|getKind
argument_list|()
operator|==
name|PersistentExpressionState
operator|::
name|eKindClang
return|;
block|}
name|lldb
operator|::
name|ExpressionVariableSP
name|CreatePersistentVariable
argument_list|(
argument|const lldb::ValueObjectSP&valobj_sp
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ExpressionVariableSP
name|CreatePersistentVariable
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|const ConstString&name
argument_list|,
argument|const CompilerType& compiler_type
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|,
argument|uint32_t addr_byte_size
argument_list|)
name|override
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
name|override
block|;
name|void
name|RemovePersistentVariable
argument_list|(
argument|lldb::ExpressionVariableSP variable
argument_list|)
name|override
block|;
name|lldb
operator|::
name|addr_t
name|LookupSymbol
argument_list|(
argument|const ConstString&name
argument_list|)
name|override
block|{
return|return
name|LLDB_INVALID_ADDRESS
return|;
block|}
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
name|void
name|AddHandLoadedClangModule
argument_list|(
argument|ClangModulesDeclVendor::ModuleID module
argument_list|)
block|{
name|m_hand_loaded_clang_modules
operator|.
name|push_back
argument_list|(
name|module
argument_list|)
block|;     }
specifier|const
name|ClangModulesDeclVendor
operator|::
name|ModuleVector
operator|&
name|GetHandLoadedClangModules
argument_list|()
block|{
return|return
name|m_hand_loaded_clang_modules
return|;
block|}
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
name|ClangModulesDeclVendor
operator|::
name|ModuleVector
name|m_hand_loaded_clang_modules
expr_stmt|;
comment|///< These are Clang modules we hand-loaded; these are the highest-
comment|///< priority source for macros.
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
comment|// liblldb_ClangPersistentVariables_h_
end_comment

end_unit

