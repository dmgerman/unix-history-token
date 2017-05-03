begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SymbolFile.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_SymbolFile_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_SymbolFile_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerDecl.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerDeclContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerType.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/Type.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SymbolFile
range|:
name|public
name|PluginInterface
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Symbol file ability bits.
comment|//
comment|// Each symbol file can claim to support one or more symbol file
comment|// abilities. These get returned from SymbolFile::GetAbilities().
comment|// These help us to determine which plug-in will be best to load
comment|// the debug information found in files.
comment|//------------------------------------------------------------------
expr|enum
name|Abilities
block|{
name|CompileUnits
operator|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
block|,
name|LineTables
operator|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
block|,
name|Functions
operator|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
block|,
name|Blocks
operator|=
operator|(
literal|1u
operator|<<
literal|3
operator|)
block|,
name|GlobalVariables
operator|=
operator|(
literal|1u
operator|<<
literal|4
operator|)
block|,
name|LocalVariables
operator|=
operator|(
literal|1u
operator|<<
literal|5
operator|)
block|,
name|VariableTypes
operator|=
operator|(
literal|1u
operator|<<
literal|6
operator|)
block|,
name|kAllAbilities
operator|=
operator|(
operator|(
literal|1u
operator|<<
literal|7
operator|)
operator|-
literal|1u
operator|)
block|}
block|;
specifier|static
name|SymbolFile
operator|*
name|FindPlugin
argument_list|(
name|ObjectFile
operator|*
name|obj_file
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|SymbolFile
argument_list|(
name|ObjectFile
operator|*
name|obj_file
argument_list|)
operator|:
name|m_obj_file
argument_list|(
name|obj_file
argument_list|)
block|,
name|m_abilities
argument_list|(
literal|0
argument_list|)
block|,
name|m_calculated_abilities
argument_list|(
argument|false
argument_list|)
block|{}
operator|~
name|SymbolFile
argument_list|()
name|override
block|{}
comment|//------------------------------------------------------------------
comment|/// Get a mask of what this symbol file supports for the object file
comment|/// that it was constructed with.
comment|///
comment|/// Each symbol file gets to respond with a mask of abilities that
comment|/// it supports for each object file. This happens when we are
comment|/// trying to figure out which symbol file plug-in will get used
comment|/// for a given object file. The plug-in that responds with the
comment|/// best mix of "SymbolFile::Abilities" bits set, will get chosen to
comment|/// be the symbol file parser. This allows each plug-in to check for
comment|/// sections that contain data a symbol file plug-in would need. For
comment|/// example the DWARF plug-in requires DWARF sections in a file that
comment|/// contain debug information. If the DWARF plug-in doesn't find
comment|/// these sections, it won't respond with many ability bits set, and
comment|/// we will probably fall back to the symbol table SymbolFile plug-in
comment|/// which uses any information in the symbol table. Also, plug-ins
comment|/// might check for some specific symbols in a symbol table in the
comment|/// case where the symbol table contains debug information (STABS
comment|/// and COFF). Not a lot of work should happen in these functions
comment|/// as the plug-in might not get selected due to another plug-in
comment|/// having more abilities. Any initialization work should be saved
comment|/// for "void SymbolFile::InitializeObject()" which will get called
comment|/// on the SymbolFile object with the best set of abilities.
comment|///
comment|/// @return
comment|///     A uint32_t mask containing bits from the SymbolFile::Abilities
comment|///     enumeration. Any bits that are set represent an ability that
comment|///     this symbol plug-in can parse from the object file.
comment|///------------------------------------------------------------------
name|uint32_t
name|GetAbilities
argument_list|()
block|{
if|if
condition|(
operator|!
name|m_calculated_abilities
condition|)
block|{
name|m_abilities
operator|=
name|CalculateAbilities
argument_list|()
expr_stmt|;
name|m_calculated_abilities
operator|=
name|true
expr_stmt|;
block|}
return|return
name|m_abilities
return|;
block|}
name|virtual
name|uint32_t
name|CalculateAbilities
argument_list|()
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// Initialize the SymbolFile object.
comment|///
comment|/// The SymbolFile object with the best set of abilities (detected
comment|/// in "uint32_t SymbolFile::GetAbilities()) will have this function
comment|/// called if it is chosen to parse an object file. More complete
comment|/// initialization can happen in this function which will get called
comment|/// prior to any other functions in the SymbolFile protocol.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|InitializeObject
argument_list|()
block|{}
comment|//------------------------------------------------------------------
comment|// Compile Unit function calls
comment|//------------------------------------------------------------------
comment|// Approach 1 - iterator
name|virtual
name|uint32_t
name|GetNumCompileUnits
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|CompUnitSP
name|ParseCompileUnitAtIndex
argument_list|(
argument|uint32_t index
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|LanguageType
name|ParseCompileUnitLanguage
argument_list|(
specifier|const
name|SymbolContext
operator|&
name|sc
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|size_t
name|ParseCompileUnitFunctions
argument_list|(
specifier|const
name|SymbolContext
operator|&
name|sc
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|ParseCompileUnitLineTable
argument_list|(
specifier|const
name|SymbolContext
operator|&
name|sc
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|ParseCompileUnitDebugMacros
argument_list|(
specifier|const
name|SymbolContext
operator|&
name|sc
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|ParseCompileUnitSupportFiles
argument_list|(
specifier|const
name|SymbolContext
operator|&
name|sc
argument_list|,
name|FileSpecList
operator|&
name|support_files
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|ParseCompileUnitIsOptimized
argument_list|(
argument|const lldb_private::SymbolContext&sc
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|ParseImportedModules
argument_list|(
specifier|const
name|SymbolContext
operator|&
name|sc
argument_list|,
name|std
operator|::
name|vector
operator|<
name|ConstString
operator|>
operator|&
name|imported_modules
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|size_t
name|ParseFunctionBlocks
argument_list|(
specifier|const
name|SymbolContext
operator|&
name|sc
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|size_t
name|ParseTypes
argument_list|(
specifier|const
name|SymbolContext
operator|&
name|sc
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|size_t
name|ParseVariablesForContext
argument_list|(
specifier|const
name|SymbolContext
operator|&
name|sc
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|Type
operator|*
name|ResolveTypeUID
argument_list|(
argument|lldb::user_id_t type_uid
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|CompleteType
argument_list|(
name|CompilerType
operator|&
name|compiler_type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|ParseDeclsForContext
argument_list|(
argument|CompilerDeclContext decl_ctx
argument_list|)
block|{}
name|virtual
name|CompilerDecl
name|GetDeclForUID
argument_list|(
argument|lldb::user_id_t uid
argument_list|)
block|{
return|return
name|CompilerDecl
argument_list|()
return|;
block|}
name|virtual
name|CompilerDeclContext
name|GetDeclContextForUID
argument_list|(
argument|lldb::user_id_t uid
argument_list|)
block|{
return|return
name|CompilerDeclContext
argument_list|()
return|;
block|}
name|virtual
name|CompilerDeclContext
name|GetDeclContextContainingUID
argument_list|(
argument|lldb::user_id_t uid
argument_list|)
block|{
return|return
name|CompilerDeclContext
argument_list|()
return|;
block|}
name|virtual
name|uint32_t
name|ResolveSymbolContext
argument_list|(
argument|const Address&so_addr
argument_list|,
argument|uint32_t resolve_scope
argument_list|,
argument|SymbolContext&sc
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|uint32_t
name|ResolveSymbolContext
argument_list|(
argument|const FileSpec&file_spec
argument_list|,
argument|uint32_t line
argument_list|,
argument|bool check_inlines
argument_list|,
argument|uint32_t resolve_scope
argument_list|,
argument|SymbolContextList&sc_list
argument_list|)
block|;
name|virtual
name|uint32_t
name|FindGlobalVariables
argument_list|(
argument|const ConstString&name
argument_list|,
argument|const CompilerDeclContext *parent_decl_ctx
argument_list|,
argument|bool append
argument_list|,
argument|uint32_t max_matches
argument_list|,
argument|VariableList&variables
argument_list|)
block|;
name|virtual
name|uint32_t
name|FindGlobalVariables
argument_list|(
argument|const RegularExpression&regex
argument_list|,
argument|bool append
argument_list|,
argument|uint32_t max_matches
argument_list|,
argument|VariableList&variables
argument_list|)
block|;
name|virtual
name|uint32_t
name|FindFunctions
argument_list|(
argument|const ConstString&name
argument_list|,
argument|const CompilerDeclContext *parent_decl_ctx
argument_list|,
argument|uint32_t name_type_mask
argument_list|,
argument|bool include_inlines
argument_list|,
argument|bool append
argument_list|,
argument|SymbolContextList&sc_list
argument_list|)
block|;
name|virtual
name|uint32_t
name|FindFunctions
argument_list|(
argument|const RegularExpression&regex
argument_list|,
argument|bool include_inlines
argument_list|,
argument|bool append
argument_list|,
argument|SymbolContextList&sc_list
argument_list|)
block|;
name|virtual
name|uint32_t
name|FindTypes
argument_list|(
argument|const SymbolContext&sc
argument_list|,
argument|const ConstString&name
argument_list|,
argument|const CompilerDeclContext *parent_decl_ctx
argument_list|,
argument|bool append
argument_list|,
argument|uint32_t max_matches
argument_list|,
argument|llvm::DenseSet<lldb_private::SymbolFile *>&searched_symbol_files
argument_list|,
argument|TypeMap&types
argument_list|)
block|;
name|virtual
name|size_t
name|FindTypes
argument_list|(
argument|const std::vector<CompilerContext>&context
argument_list|,
argument|bool append
argument_list|,
argument|TypeMap&types
argument_list|)
block|;
name|virtual
name|void
name|GetMangledNamesForFunction
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|scope_qualified_name
argument_list|,
name|std
operator|::
name|vector
operator|<
name|ConstString
operator|>
operator|&
name|mangled_names
argument_list|)
block|;
comment|//  virtual uint32_t        FindTypes (const SymbolContext& sc, const
comment|//  RegularExpression& regex, bool append, uint32_t max_matches, TypeList&
comment|//  types) = 0;
name|virtual
name|TypeList
operator|*
name|GetTypeList
argument_list|()
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
operator|=
literal|0
block|;
name|virtual
name|void
name|PreloadSymbols
argument_list|()
block|;
name|virtual
name|lldb_private
operator|::
name|TypeSystem
operator|*
name|GetTypeSystemForLanguage
argument_list|(
argument|lldb::LanguageType language
argument_list|)
block|;
name|virtual
name|CompilerDeclContext
name|FindNamespace
argument_list|(
argument|const SymbolContext&sc
argument_list|,
argument|const ConstString&name
argument_list|,
argument|const CompilerDeclContext *parent_decl_ctx
argument_list|)
block|{
return|return
name|CompilerDeclContext
argument_list|()
return|;
block|}
name|ObjectFile
operator|*
name|GetObjectFile
argument_list|()
block|{
return|return
name|m_obj_file
return|;
block|}
specifier|const
name|ObjectFile
operator|*
name|GetObjectFile
argument_list|()
specifier|const
block|{
return|return
name|m_obj_file
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Notify the SymbolFile that the file addresses in the Sections
comment|/// for this module have been changed.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|SectionFileAddressesChanged
argument_list|()
block|{}
name|protected
operator|:
name|ObjectFile
operator|*
name|m_obj_file
block|;
comment|// The object file that symbols can be extracted from.
name|uint32_t
name|m_abilities
block|;
name|bool
name|m_calculated_abilities
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|SymbolFile
argument_list|)
block|; }
decl_stmt|;
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
comment|// liblldb_SymbolFile_h_
end_comment

end_unit

