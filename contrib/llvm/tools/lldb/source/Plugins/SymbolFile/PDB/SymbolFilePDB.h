begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SymbolFilePDB.h -------------------------------------*- C++ -*-===//
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
name|lldb_Plugins_SymbolFile_PDB_SymbolFilePDB_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Plugins_SymbolFile_PDB_SymbolFilePDB_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Symbol/SymbolFile.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UserID.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/IPDBSession.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/PDB.h"
end_include

begin_decl_stmt
name|class
name|SymbolFilePDB
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
name|void
name|DebuggerInitialize
argument_list|(
name|lldb_private
operator|::
name|Debugger
operator|&
name|debugger
argument_list|)
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
name|SymbolFilePDB
argument_list|(
name|lldb_private
operator|::
name|ObjectFile
operator|*
name|ofile
argument_list|)
block|;
operator|~
name|SymbolFilePDB
argument_list|()
name|override
block|;
name|uint32_t
name|CalculateAbilities
argument_list|()
name|override
block|;
name|void
name|InitializeObject
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Compile Unit function calls
comment|//------------------------------------------------------------------
name|uint32_t
name|GetNumCompileUnits
argument_list|()
name|override
block|;
name|lldb
operator|::
name|CompUnitSP
name|ParseCompileUnitAtIndex
argument_list|(
argument|uint32_t index
argument_list|)
name|override
block|;
name|lldb
operator|::
name|LanguageType
name|ParseCompileUnitLanguage
argument_list|(
argument|const lldb_private::SymbolContext&sc
argument_list|)
name|override
block|;
name|size_t
name|ParseCompileUnitFunctions
argument_list|(
argument|const lldb_private::SymbolContext&sc
argument_list|)
name|override
block|;
name|bool
name|ParseCompileUnitLineTable
argument_list|(
argument|const lldb_private::SymbolContext&sc
argument_list|)
name|override
block|;
name|bool
name|ParseCompileUnitDebugMacros
argument_list|(
argument|const lldb_private::SymbolContext&sc
argument_list|)
name|override
block|;
name|bool
name|ParseCompileUnitSupportFiles
argument_list|(
argument|const lldb_private::SymbolContext&sc
argument_list|,
argument|lldb_private::FileSpecList&support_files
argument_list|)
name|override
block|;
name|bool
name|ParseImportedModules
argument_list|(
argument|const lldb_private::SymbolContext&sc
argument_list|,
argument|std::vector<lldb_private::ConstString>&imported_modules
argument_list|)
name|override
block|;
name|size_t
name|ParseFunctionBlocks
argument_list|(
argument|const lldb_private::SymbolContext&sc
argument_list|)
name|override
block|;
name|size_t
name|ParseTypes
argument_list|(
argument|const lldb_private::SymbolContext&sc
argument_list|)
name|override
block|;
name|size_t
name|ParseVariablesForContext
argument_list|(
argument|const lldb_private::SymbolContext&sc
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Type
operator|*
name|ResolveTypeUID
argument_list|(
argument|lldb::user_id_t type_uid
argument_list|)
name|override
block|;
name|bool
name|CompleteType
argument_list|(
argument|lldb_private::CompilerType&compiler_type
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|CompilerDecl
name|GetDeclForUID
argument_list|(
argument|lldb::user_id_t uid
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|CompilerDeclContext
name|GetDeclContextForUID
argument_list|(
argument|lldb::user_id_t uid
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|CompilerDeclContext
name|GetDeclContextContainingUID
argument_list|(
argument|lldb::user_id_t uid
argument_list|)
name|override
block|;
name|void
name|ParseDeclsForContext
argument_list|(
argument|lldb_private::CompilerDeclContext decl_ctx
argument_list|)
name|override
block|;
name|uint32_t
name|ResolveSymbolContext
argument_list|(
argument|const lldb_private::Address&so_addr
argument_list|,
argument|uint32_t resolve_scope
argument_list|,
argument|lldb_private::SymbolContext&sc
argument_list|)
name|override
block|;
name|uint32_t
name|ResolveSymbolContext
argument_list|(
argument|const lldb_private::FileSpec&file_spec
argument_list|,
argument|uint32_t line
argument_list|,
argument|bool check_inlines
argument_list|,
argument|uint32_t resolve_scope
argument_list|,
argument|lldb_private::SymbolContextList&sc_list
argument_list|)
name|override
block|;
name|uint32_t
name|FindGlobalVariables
argument_list|(
argument|const lldb_private::ConstString&name
argument_list|,
argument|const lldb_private::CompilerDeclContext *parent_decl_ctx
argument_list|,
argument|bool append
argument_list|,
argument|uint32_t max_matches
argument_list|,
argument|lldb_private::VariableList&variables
argument_list|)
name|override
block|;
name|uint32_t
name|FindGlobalVariables
argument_list|(
argument|const lldb_private::RegularExpression&regex
argument_list|,
argument|bool append
argument_list|,
argument|uint32_t max_matches
argument_list|,
argument|lldb_private::VariableList&variables
argument_list|)
name|override
block|;
name|uint32_t
name|FindFunctions
argument_list|(
argument|const lldb_private::ConstString&name
argument_list|,
argument|const lldb_private::CompilerDeclContext *parent_decl_ctx
argument_list|,
argument|uint32_t name_type_mask
argument_list|,
argument|bool include_inlines
argument_list|,
argument|bool append
argument_list|,
argument|lldb_private::SymbolContextList&sc_list
argument_list|)
name|override
block|;
name|uint32_t
name|FindFunctions
argument_list|(
argument|const lldb_private::RegularExpression&regex
argument_list|,
argument|bool include_inlines
argument_list|,
argument|bool append
argument_list|,
argument|lldb_private::SymbolContextList&sc_list
argument_list|)
name|override
block|;
name|void
name|GetMangledNamesForFunction
argument_list|(
argument|const std::string&scope_qualified_name
argument_list|,
argument|std::vector<lldb_private::ConstString>&mangled_names
argument_list|)
name|override
block|;
name|uint32_t
name|FindTypes
argument_list|(
argument|const lldb_private::SymbolContext&sc
argument_list|,
argument|const lldb_private::ConstString&name
argument_list|,
argument|const lldb_private::CompilerDeclContext *parent_decl_ctx
argument_list|,
argument|bool append
argument_list|,
argument|uint32_t max_matches
argument_list|,
argument|llvm::DenseSet<lldb_private::SymbolFile *>&searched_symbol_files
argument_list|,
argument|lldb_private::TypeMap&types
argument_list|)
name|override
block|;
name|size_t
name|FindTypes
argument_list|(
argument|const std::vector<lldb_private::CompilerContext>&context
argument_list|,
argument|bool append
argument_list|,
argument|lldb_private::TypeMap&types
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|TypeList
operator|*
name|GetTypeList
argument_list|()
name|override
block|;
name|size_t
name|GetTypes
argument_list|(
argument|lldb_private::SymbolContextScope *sc_scope
argument_list|,
argument|uint32_t type_mask
argument_list|,
argument|lldb_private::TypeList&type_list
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|TypeSystem
operator|*
name|GetTypeSystemForLanguage
argument_list|(
argument|lldb::LanguageType language
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|CompilerDeclContext
name|FindNamespace
argument_list|(
argument|const lldb_private::SymbolContext&sc
argument_list|,
argument|const lldb_private::ConstString&name
argument_list|,
argument|const lldb_private::CompilerDeclContext *parent_decl_ctx
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|;
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|;
name|llvm
operator|::
name|pdb
operator|::
name|IPDBSession
operator|&
name|GetPDBSession
argument_list|()
block|;
specifier|const
name|llvm
operator|::
name|pdb
operator|::
name|IPDBSession
operator|&
name|GetPDBSession
argument_list|()
specifier|const
block|;
name|private
operator|:
name|lldb
operator|::
name|CompUnitSP
name|ParseCompileUnitForSymIndex
argument_list|(
argument|uint32_t id
argument_list|)
block|;
name|bool
name|ParseCompileUnitLineTable
argument_list|(
argument|const lldb_private::SymbolContext&sc
argument_list|,
argument|uint32_t match_line
argument_list|)
block|;
name|void
name|BuildSupportFileIdToSupportFileIndexMap
argument_list|(
argument|const llvm::pdb::PDBSymbolCompiland&cu
argument_list|,
argument|llvm::DenseMap<uint32_t
argument_list|,
argument|uint32_t>&index_map
argument_list|)
specifier|const
block|;
name|void
name|FindTypesByRegex
argument_list|(
argument|const std::string&regex
argument_list|,
argument|uint32_t max_matches
argument_list|,
argument|lldb_private::TypeMap&types
argument_list|)
block|;
name|void
name|FindTypesByName
argument_list|(
argument|const std::string&name
argument_list|,
argument|uint32_t max_matches
argument_list|,
argument|lldb_private::TypeMap&types
argument_list|)
block|;
name|llvm
operator|::
name|DenseMap
operator|<
name|uint32_t
block|,
name|lldb
operator|::
name|CompUnitSP
operator|>
name|m_comp_units
block|;
name|llvm
operator|::
name|DenseMap
operator|<
name|uint32_t
block|,
name|lldb
operator|::
name|TypeSP
operator|>
name|m_types
block|;
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|TypeSP
operator|>
name|m_builtin_types
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|pdb
operator|::
name|IPDBSession
operator|>
name|m_session_up
block|;
name|uint32_t
name|m_cached_compile_unit_count
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|CompilerDeclContext
operator|>
name|m_tu_decl_ctx_up
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_Plugins_SymbolFile_PDB_SymbolFilePDB_h_
end_comment

end_unit

