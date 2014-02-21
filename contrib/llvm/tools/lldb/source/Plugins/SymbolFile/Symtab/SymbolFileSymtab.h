begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SymbolFileSymtab.h --------------------------------------*- C++ -*-===//
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
name|liblldb_SymbolFileSymtab_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_SymbolFileSymtab_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Symbol/SymbolFile.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/Symtab.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|class
name|SymbolFileSymtab
range|:
name|public
name|lldb_private
operator|::
name|SymbolFile
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Static Functions
comment|//------------------------------------------------------------------
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetPluginDescriptionStatic
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|SymbolFile
operator|*
name|CreateInstance
argument_list|(
name|lldb_private
operator|::
name|ObjectFile
operator|*
name|obj_file
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|SymbolFileSymtab
argument_list|(
name|lldb_private
operator|::
name|ObjectFile
operator|*
name|obj_file
argument_list|)
block|;
name|virtual
operator|~
name|SymbolFileSymtab
argument_list|()
block|;
name|virtual
name|uint32_t
name|CalculateAbilities
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// Compile Unit function calls
comment|//------------------------------------------------------------------
name|virtual
name|uint32_t
name|GetNumCompileUnits
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|CompUnitSP
name|ParseCompileUnitAtIndex
argument_list|(
argument|uint32_t index
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|LanguageType
name|ParseCompileUnitLanguage
argument_list|(
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|)
block|;
name|virtual
name|size_t
name|ParseCompileUnitFunctions
argument_list|(
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|)
block|;
name|virtual
name|bool
name|ParseCompileUnitLineTable
argument_list|(
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|)
block|;
name|virtual
name|bool
name|ParseCompileUnitSupportFiles
argument_list|(
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|,
name|lldb_private
operator|::
name|FileSpecList
operator|&
name|support_files
argument_list|)
block|;
name|virtual
name|size_t
name|ParseFunctionBlocks
argument_list|(
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|)
block|;
name|virtual
name|size_t
name|ParseTypes
argument_list|(
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|)
block|;
name|virtual
name|size_t
name|ParseVariablesForContext
argument_list|(
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Type
operator|*
name|ResolveTypeUID
argument_list|(
argument|lldb::user_id_t type_uid
argument_list|)
block|;
name|virtual
name|bool
name|ResolveClangOpaqueTypeDefinition
argument_list|(
name|lldb_private
operator|::
name|ClangASTType
operator|&
name|clang_type
argument_list|)
block|;
name|virtual
name|uint32_t
name|ResolveSymbolContext
argument_list|(
argument|const lldb_private::Address& so_addr
argument_list|,
argument|uint32_t resolve_scope
argument_list|,
argument|lldb_private::SymbolContext& sc
argument_list|)
block|;
name|virtual
name|uint32_t
name|ResolveSymbolContext
argument_list|(
argument|const lldb_private::FileSpec& file_spec
argument_list|,
argument|uint32_t line
argument_list|,
argument|bool check_inlines
argument_list|,
argument|uint32_t resolve_scope
argument_list|,
argument|lldb_private::SymbolContextList& sc_list
argument_list|)
block|;
name|virtual
name|uint32_t
name|FindGlobalVariables
argument_list|(
argument|const lldb_private::ConstString&name
argument_list|,
argument|const lldb_private::ClangNamespaceDecl *namespace_decl
argument_list|,
argument|bool append
argument_list|,
argument|uint32_t max_matches
argument_list|,
argument|lldb_private::VariableList& variables
argument_list|)
block|;
name|virtual
name|uint32_t
name|FindGlobalVariables
argument_list|(
argument|const lldb_private::RegularExpression& regex
argument_list|,
argument|bool append
argument_list|,
argument|uint32_t max_matches
argument_list|,
argument|lldb_private::VariableList& variables
argument_list|)
block|;
name|virtual
name|uint32_t
name|FindFunctions
argument_list|(
argument|const lldb_private::ConstString&name
argument_list|,
argument|const lldb_private::ClangNamespaceDecl *namespace_decl
argument_list|,
argument|uint32_t name_type_mask
argument_list|,
argument|bool include_inlines
argument_list|,
argument|bool append
argument_list|,
argument|lldb_private::SymbolContextList& sc_list
argument_list|)
block|;
name|virtual
name|uint32_t
name|FindFunctions
argument_list|(
argument|const lldb_private::RegularExpression& regex
argument_list|,
argument|bool include_inlines
argument_list|,
argument|bool append
argument_list|,
argument|lldb_private::SymbolContextList& sc_list
argument_list|)
block|;
name|virtual
name|uint32_t
name|FindTypes
argument_list|(
argument|const lldb_private::SymbolContext& sc
argument_list|,
argument|const lldb_private::ConstString&name
argument_list|,
argument|const lldb_private::ClangNamespaceDecl *namespace_decl
argument_list|,
argument|bool append
argument_list|,
argument|uint32_t max_matches
argument_list|,
argument|lldb_private::TypeList& types
argument_list|)
block|;
name|virtual
name|size_t
name|GetTypes
argument_list|(
argument|lldb_private::SymbolContextScope *sc_scope
argument_list|,
argument|uint32_t type_mask
argument_list|,
argument|lldb_private::TypeList&type_list
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|ClangNamespaceDecl
name|FindNamespace
argument_list|(
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|,
specifier|const
name|lldb_private
operator|::
name|ConstString
operator|&
name|name
argument_list|,
specifier|const
name|lldb_private
operator|::
name|ClangNamespaceDecl
operator|*
name|parent_namespace_decl
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
block|;
name|virtual
name|uint32_t
name|GetPluginVersion
argument_list|()
block|;
name|protected
operator|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb_private
operator|::
name|ConstString
operator|,
name|lldb
operator|::
name|TypeSP
operator|>
name|TypeMap
expr_stmt|;
name|lldb_private
operator|::
name|Symtab
operator|::
name|IndexCollection
name|m_source_indexes
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Symtab
operator|::
name|IndexCollection
name|m_func_indexes
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Symtab
operator|::
name|IndexCollection
name|m_code_indexes
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Symtab
operator|::
name|IndexCollection
name|m_data_indexes
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Symtab
operator|::
name|NameToIndexMap
name|m_objc_class_name_to_index
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|TypeMap
name|m_objc_class_types
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|ClangASTContext
operator|&
name|GetClangASTContext
argument_list|()
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|SymbolFileSymtab
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_SymbolFileSymtab_h_
end_comment

end_unit

