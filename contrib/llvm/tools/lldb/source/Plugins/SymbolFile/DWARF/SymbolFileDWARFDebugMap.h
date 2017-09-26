begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SymbolFileDWARFDebugMap.h ------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_SymbolFileDWARFDebugMap_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_SymbolFileDWARFDebugMap_h_
end_define

begin_include
include|#
directive|include
file|<bitset>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"lldb/Core/RangeMap.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/SymbolFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Chrono.h"
end_include

begin_include
include|#
directive|include
file|"UniqueDWARFASTType.h"
end_include

begin_decl_stmt
name|class
name|SymbolFileDWARF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|DWARFDebugAranges
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|DWARFDeclContext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|SymbolFileDWARFDebugMap
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
name|SymbolFileDWARFDebugMap
argument_list|(
name|lldb_private
operator|::
name|ObjectFile
operator|*
name|ofile
argument_list|)
block|;
operator|~
name|SymbolFileDWARFDebugMap
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
name|ParseCompileUnitIsOptimized
argument_list|(
argument|const lldb_private::SymbolContext&sc
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
name|bool
name|CompleteType
argument_list|(
argument|lldb_private::CompilerType&compiler_type
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
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
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
name|protected
operator|:
expr|enum
block|{
name|kHaveInitializedOSOs
operator|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|kNumFlags
block|}
block|;
name|friend
name|class
name|DebugMapModule
block|;
name|friend
expr|struct
name|DIERef
block|;
name|friend
name|class
name|DWARFASTParserClang
block|;
name|friend
name|class
name|DWARFCompileUnit
block|;
name|friend
name|class
name|SymbolFileDWARF
block|;   struct
name|OSOInfo
block|{
name|lldb
operator|::
name|ModuleSP
name|module_sp
block|;
name|OSOInfo
argument_list|()
operator|:
name|module_sp
argument_list|()
block|{}
block|}
block|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|OSOInfo
operator|>
name|OSOInfoSP
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|lldb_private
operator|::
name|RangeDataVector
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|addr_t
operator|>
name|FileRangeMap
expr_stmt|;
end_typedef

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Class specific types
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_struct
struct|struct
name|CompileUnitInfo
block|{
name|lldb_private
operator|::
name|FileSpec
name|so_file
expr_stmt|;
name|lldb_private
operator|::
name|ConstString
name|oso_path
expr_stmt|;
name|llvm
operator|::
name|sys
operator|::
name|TimePoint
operator|<
operator|>
name|oso_mod_time
expr_stmt|;
name|OSOInfoSP
name|oso_sp
decl_stmt|;
name|lldb
operator|::
name|CompUnitSP
name|compile_unit_sp
expr_stmt|;
name|uint32_t
name|first_symbol_index
decl_stmt|;
name|uint32_t
name|last_symbol_index
decl_stmt|;
name|uint32_t
name|first_symbol_id
decl_stmt|;
name|uint32_t
name|last_symbol_id
decl_stmt|;
name|FileRangeMap
name|file_range_map
decl_stmt|;
name|bool
name|file_range_map_valid
decl_stmt|;
name|CompileUnitInfo
argument_list|()
operator|:
name|so_file
argument_list|()
operator|,
name|oso_path
argument_list|()
operator|,
name|oso_mod_time
argument_list|()
operator|,
name|oso_sp
argument_list|()
operator|,
name|compile_unit_sp
argument_list|()
operator|,
name|first_symbol_index
argument_list|(
name|UINT32_MAX
argument_list|)
operator|,
name|last_symbol_index
argument_list|(
name|UINT32_MAX
argument_list|)
operator|,
name|first_symbol_id
argument_list|(
name|UINT32_MAX
argument_list|)
operator|,
name|last_symbol_id
argument_list|(
name|UINT32_MAX
argument_list|)
operator|,
name|file_range_map
argument_list|()
operator|,
name|file_range_map_valid
argument_list|(
argument|false
argument_list|)
block|{}
specifier|const
name|FileRangeMap
operator|&
name|GetFileRangeMap
argument_list|(
name|SymbolFileDWARFDebugMap
operator|*
name|exe_symfile
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Protected Member Functions
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|void
name|InitOSO
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|uint32_t
name|GetOSOIndexFromUserID
argument_list|(
name|lldb
operator|::
name|user_id_t
name|uid
argument_list|)
block|{
return|return
call|(
name|uint32_t
call|)
argument_list|(
operator|(
name|uid
operator|>>
literal|32ull
operator|)
operator|-
literal|1ull
argument_list|)
return|;
block|}
end_decl_stmt

begin_function_decl
specifier|static
name|SymbolFileDWARF
modifier|*
name|GetSymbolFileAsSymbolFileDWARF
parameter_list|(
name|SymbolFile
modifier|*
name|sym_file
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|GetFileSpecForSO
argument_list|(
name|uint32_t
name|oso_idx
argument_list|,
name|lldb_private
operator|::
name|FileSpec
operator|&
name|file_spec
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CompileUnitInfo
modifier|*
name|GetCompUnitInfo
argument_list|(
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|GetCompUnitInfosForModule
argument_list|(
specifier|const
name|lldb_private
operator|::
name|Module
operator|*
name|oso_module
argument_list|,
name|std
operator|::
name|vector
operator|<
name|CompileUnitInfo
operator|*
operator|>
operator|&
name|cu_infos
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Module
operator|*
name|GetModuleByCompUnitInfo
argument_list|(
name|CompileUnitInfo
operator|*
name|comp_unit_info
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Module
operator|*
name|GetModuleByOSOIndex
argument_list|(
argument|uint32_t oso_idx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|ObjectFile
operator|*
name|GetObjectFileByCompUnitInfo
argument_list|(
name|CompileUnitInfo
operator|*
name|comp_unit_info
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|ObjectFile
operator|*
name|GetObjectFileByOSOIndex
argument_list|(
argument|uint32_t oso_idx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|uint32_t
name|GetCompUnitInfoIndex
parameter_list|(
specifier|const
name|CompileUnitInfo
modifier|*
name|comp_unit_info
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|SymbolFileDWARF
modifier|*
name|GetSymbolFile
argument_list|(
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|SymbolFileDWARF
modifier|*
name|GetSymbolFileByCompUnitInfo
parameter_list|(
name|CompileUnitInfo
modifier|*
name|comp_unit_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SymbolFileDWARF
modifier|*
name|GetSymbolFileByOSOIndex
parameter_list|(
name|uint32_t
name|oso_idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// If closure returns "false", iteration continues.  If it returns
end_comment

begin_comment
comment|// "true", iteration terminates.
end_comment

begin_decl_stmt
name|void
name|ForEachSymbolFile
argument_list|(
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
name|SymbolFileDWARF
operator|*
argument_list|)
operator|>
name|closure
argument_list|)
block|{
for|for
control|(
name|uint32_t
name|oso_idx
init|=
literal|0
init|,
name|num_oso_idxs
init|=
name|m_compile_unit_infos
operator|.
name|size
argument_list|()
init|;
name|oso_idx
operator|<
name|num_oso_idxs
condition|;
operator|++
name|oso_idx
control|)
block|{
if|if
condition|(
name|SymbolFileDWARF
modifier|*
name|oso_dwarf
init|=
name|GetSymbolFileByOSOIndex
argument_list|(
name|oso_idx
argument_list|)
condition|)
block|{
if|if
condition|(
name|closure
argument_list|(
name|oso_dwarf
argument_list|)
condition|)
return|return;
block|}
block|}
block|}
end_decl_stmt

begin_function_decl
name|CompileUnitInfo
modifier|*
name|GetCompileUnitInfoForSymbolWithIndex
parameter_list|(
name|uint32_t
name|symbol_idx
parameter_list|,
name|uint32_t
modifier|*
name|oso_idx_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|CompileUnitInfo
modifier|*
name|GetCompileUnitInfoForSymbolWithID
argument_list|(
name|lldb
operator|::
name|user_id_t
name|symbol_id
argument_list|,
name|uint32_t
operator|*
name|oso_idx_ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|SymbolContainsSymbolWithIndex
parameter_list|(
name|uint32_t
modifier|*
name|symbol_idx_ptr
parameter_list|,
specifier|const
name|CompileUnitInfo
modifier|*
name|comp_unit_info
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|int
name|SymbolContainsSymbolWithID
argument_list|(
name|lldb
operator|::
name|user_id_t
operator|*
name|symbol_idx_ptr
argument_list|,
specifier|const
name|CompileUnitInfo
operator|*
name|comp_unit_info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|PrivateFindGlobalVariables
argument_list|(
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
name|CompilerDeclContext
operator|*
name|parent_decl_ctx
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
operator|&
name|name_symbol_indexes
argument_list|,
name|uint32_t
name|max_matches
argument_list|,
name|lldb_private
operator|::
name|VariableList
operator|&
name|variables
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|SetCompileUnit
argument_list|(
name|SymbolFileDWARF
operator|*
name|oso_dwarf
argument_list|,
specifier|const
name|lldb
operator|::
name|CompUnitSP
operator|&
name|cu_sp
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|CompUnitSP
name|GetCompileUnit
argument_list|(
name|SymbolFileDWARF
operator|*
name|oso_dwarf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|CompileUnitInfo
modifier|*
name|GetCompileUnitInfo
parameter_list|(
name|SymbolFileDWARF
modifier|*
name|oso_dwarf
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|lldb
operator|::
name|TypeSP
name|FindDefinitionTypeForDWARFDeclContext
argument_list|(
specifier|const
name|DWARFDeclContext
operator|&
name|die_decl_ctx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|bool
name|Supports_DW_AT_APPLE_objc_complete_type
parameter_list|(
name|SymbolFileDWARF
modifier|*
name|skip_dwarf_oso
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|lldb
operator|::
name|TypeSP
name|FindCompleteObjCDefinitionTypeForDIE
argument_list|(
argument|const DWARFDIE&die
argument_list|,
argument|const lldb_private::ConstString&type_name
argument_list|,
argument|bool must_be_implementation
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|UniqueDWARFASTTypeMap
modifier|&
name|GetUniqueDWARFASTTypeMap
parameter_list|()
block|{
return|return
name|m_unique_ast_type_map
return|;
block|}
end_function

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// OSOEntry
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|OSOEntry
block|{
name|public
label|:
name|OSOEntry
argument_list|()
operator|:
name|m_exe_sym_idx
argument_list|(
name|UINT32_MAX
argument_list|)
operator|,
name|m_oso_file_addr
argument_list|(
argument|LLDB_INVALID_ADDRESS
argument_list|)
block|{}
name|OSOEntry
argument_list|(
argument|uint32_t exe_sym_idx
argument_list|,
argument|lldb::addr_t oso_file_addr
argument_list|)
operator|:
name|m_exe_sym_idx
argument_list|(
name|exe_sym_idx
argument_list|)
operator|,
name|m_oso_file_addr
argument_list|(
argument|oso_file_addr
argument_list|)
block|{}
name|uint32_t
name|GetExeSymbolIndex
argument_list|()
specifier|const
block|{
return|return
name|m_exe_sym_idx
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|OSOEntry
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|m_exe_sym_idx
operator|<
name|rhs
operator|.
name|m_exe_sym_idx
return|;
block|}
name|lldb
operator|::
name|addr_t
name|GetOSOFileAddress
argument_list|()
specifier|const
block|{
return|return
name|m_oso_file_addr
return|;
block|}
name|void
name|SetOSOFileAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|oso_file_addr
argument_list|)
block|{
name|m_oso_file_addr
operator|=
name|oso_file_addr
expr_stmt|;
block|}
name|protected
label|:
name|uint32_t
name|m_exe_sym_idx
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|m_oso_file_addr
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|lldb_private
operator|::
name|RangeDataVector
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|addr_t
operator|,
name|OSOEntry
operator|>
name|DebugMap
expr_stmt|;
end_typedef

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Member Variables
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|std
operator|::
name|bitset
operator|<
name|kNumFlags
operator|>
name|m_flags
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CompileUnitInfo
operator|>
name|m_compile_unit_infos
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|m_func_indexes
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Sorted by address
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|m_glob_indexes
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|map
operator|<
name|lldb_private
operator|::
name|ConstString
operator|,
name|OSOInfoSP
operator|>
name|m_oso_map
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|UniqueDWARFASTTypeMap
name|m_unique_ast_type_map
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|LazyBool
name|m_supports_DW_AT_APPLE_objc_complete_type
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|DebugMap
name|m_debug_map
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// When an object file from the debug map gets parsed in
end_comment

begin_comment
comment|// SymbolFileDWARF, it needs to tell the debug map about the object
end_comment

begin_comment
comment|// files addresses by calling this function once for each N_FUN,
end_comment

begin_comment
comment|// N_GSYM and N_STSYM and after all entries in the debug map have
end_comment

begin_comment
comment|// been matched up, FinalizeOSOFileRanges() should be called.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
name|bool
name|AddOSOFileRange
argument_list|(
name|CompileUnitInfo
operator|*
name|cu_info
argument_list|,
name|lldb
operator|::
name|addr_t
name|exe_file_addr
argument_list|,
name|lldb
operator|::
name|addr_t
name|exe_byte_size
argument_list|,
name|lldb
operator|::
name|addr_t
name|oso_file_addr
argument_list|,
name|lldb
operator|::
name|addr_t
name|oso_byte_size
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Called after calling AddOSOFileRange() for each object file debug
end_comment

begin_comment
comment|// map entry to finalize the info for the unlinked compile unit.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|void
name|FinalizeOSOFileRanges
parameter_list|(
name|CompileUnitInfo
modifier|*
name|cu_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Convert \a addr from a .o file address, to an executable address.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] addr
end_comment

begin_comment
comment|///     A section offset address from a .o file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     Returns true if \a addr was converted to be an executable
end_comment

begin_comment
comment|///     section/offset address, false otherwise.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
name|bool
name|LinkOSOAddress
argument_list|(
name|lldb_private
operator|::
name|Address
operator|&
name|addr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Convert a .o file "file address" to an executable "file address".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] oso_symfile
end_comment

begin_comment
comment|///     The DWARF symbol file that contains \a oso_file_addr
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] oso_file_addr
end_comment

begin_comment
comment|///     A .o file "file address" to convert.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     LLDB_INVALID_ADDRESS if \a oso_file_addr is not in the
end_comment

begin_comment
comment|///     linked executable, otherwise a valid "file address" from the
end_comment

begin_comment
comment|///     linked executable that contains the debug map.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|LinkOSOFileAddress
argument_list|(
argument|SymbolFileDWARF *oso_symfile
argument_list|,
argument|lldb::addr_t oso_file_addr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Given a line table full of lines with "file addresses" that are
end_comment

begin_comment
comment|/// for a .o file represented by \a oso_symfile, link a new line table
end_comment

begin_comment
comment|/// and return it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] oso_symfile
end_comment

begin_comment
comment|///     The DWARF symbol file that produced the \a line_table
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] addr
end_comment

begin_comment
comment|///     A section offset address from a .o file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     Returns a valid line table full of linked addresses, or NULL
end_comment

begin_comment
comment|///     if none of the line table addresses exist in the main
end_comment

begin_comment
comment|///     executable.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|LineTable
operator|*
name|LinkOSOLineTable
argument_list|(
name|SymbolFileDWARF
operator|*
name|oso_symfile
argument_list|,
name|lldb_private
operator|::
name|LineTable
operator|*
name|line_table
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|size_t
name|AddOSOARanges
parameter_list|(
name|SymbolFileDWARF
modifier|*
name|dwarf2Data
parameter_list|,
name|DWARFDebugAranges
modifier|*
name|debug_aranges
parameter_list|)
function_decl|;
end_function_decl

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef SymbolFileDWARF_SymbolFileDWARFDebugMap_h_
end_comment

end_unit

