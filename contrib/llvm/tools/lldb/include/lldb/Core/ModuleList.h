begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ModuleList.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_ModuleList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ModuleList_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_comment
comment|// for Address
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/ModuleSpec.h"
end_include

begin_comment
comment|// for ModuleSpec
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/Error.h"
end_include

begin_comment
comment|// for Error
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_comment
comment|// for FileSpec
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/Iterable.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint32_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ConstString
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|FileSpecList
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Function
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Log
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Module
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|RegularExpression
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SymbolContext
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SymbolContextList
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SymbolFile
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Target
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|TypeList
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|UUID
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|VariableList
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ModuleList ModuleList.h "lldb/Core/ModuleList.h"
comment|/// @brief A collection class for Module objects.
comment|///
comment|/// Modules in the module collection class are stored as reference
comment|/// counted shared pointers to Module objects.
comment|//----------------------------------------------------------------------
name|class
name|ModuleList
block|{
name|public
label|:
name|class
name|Notifier
block|{
name|public
label|:
name|virtual
operator|~
name|Notifier
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|void
name|ModuleAdded
argument_list|(
specifier|const
name|ModuleList
operator|&
name|module_list
argument_list|,
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|ModuleRemoved
argument_list|(
specifier|const
name|ModuleList
operator|&
name|module_list
argument_list|,
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|ModuleUpdated
argument_list|(
specifier|const
name|ModuleList
operator|&
name|module_list
argument_list|,
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|old_module_sp
argument_list|,
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|new_module_sp
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|WillClearList
parameter_list|(
specifier|const
name|ModuleList
modifier|&
name|module_list
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// Creates an empty list of Module objects.
comment|//------------------------------------------------------------------
name|ModuleList
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Copy Constructor.
comment|///
comment|/// Creates a new module list object with a copy of the modules from
comment|/// \a rhs.
comment|///
comment|/// @param[in] rhs
comment|///     Another module list object.
comment|//------------------------------------------------------------------
name|ModuleList
argument_list|(
specifier|const
name|ModuleList
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|ModuleList
argument_list|(
name|ModuleList
operator|::
name|Notifier
operator|*
name|notifier
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|//------------------------------------------------------------------
operator|~
name|ModuleList
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Assignment operator.
comment|///
comment|/// Copies the module list from \a rhs into this list.
comment|///
comment|/// @param[in] rhs
comment|///     Another module list object.
comment|///
comment|/// @return
comment|///     A const reference to this object.
comment|//------------------------------------------------------------------
specifier|const
name|ModuleList
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ModuleList
operator|&
name|rhs
operator|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Append a module to the module list.
comment|///
comment|/// Appends the module to the collection.
comment|///
comment|/// @param[in] module_sp
comment|///     A shared pointer to a module to add to this collection.
comment|//------------------------------------------------------------------
name|void
name|Append
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Append a module to the module list and remove any equivalent
comment|/// modules. Equivalent modules are ones whose file, platform file
comment|/// and architecture matches.
comment|///
comment|/// Replaces the module to the collection.
comment|///
comment|/// @param[in] module_sp
comment|///     A shared pointer to a module to replace in this collection.
comment|//------------------------------------------------------------------
name|void
name|ReplaceEquivalent
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
decl_stmt|;
name|bool
name|AppendIfNeeded
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
decl_stmt|;
name|void
name|Append
parameter_list|(
specifier|const
name|ModuleList
modifier|&
name|module_list
parameter_list|)
function_decl|;
name|bool
name|AppendIfNeeded
parameter_list|(
specifier|const
name|ModuleList
modifier|&
name|module_list
parameter_list|)
function_decl|;
name|bool
name|ReplaceModule
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|old_module_sp
argument_list|,
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|new_module_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Clear the object's state.
comment|///
comment|/// Clears the list of modules and releases a reference to each
comment|/// module object and if the reference count goes to zero, the
comment|/// module will be deleted.
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Clear the object's state.
comment|///
comment|/// Clears the list of modules and releases a reference to each
comment|/// module object and if the reference count goes to zero, the
comment|/// module will be deleted. Also release all memory that might be
comment|/// held by any collection classes (like std::vector)
comment|//------------------------------------------------------------------
name|void
name|Destroy
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Dump the description of each module contained in this list.
comment|///
comment|/// Dump the description of each module contained in this list to
comment|/// the supplied stream \a s.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|///
comment|/// @see Module::Dump(Stream *) const
comment|//------------------------------------------------------------------
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
name|void
name|LogUUIDAndPaths
parameter_list|(
name|Log
modifier|*
name|log
parameter_list|,
specifier|const
name|char
modifier|*
name|prefix_cstr
parameter_list|)
function_decl|;
name|std
operator|::
name|recursive_mutex
operator|&
name|GetMutex
argument_list|()
specifier|const
block|{
return|return
name|m_modules_mutex
return|;
block|}
name|size_t
name|GetIndexForModule
argument_list|(
specifier|const
name|Module
operator|*
name|module
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the module shared pointer for the module at index \a idx.
comment|///
comment|/// @param[in] idx
comment|///     An index into this module collection.
comment|///
comment|/// @return
comment|///     A shared pointer to a Module which can contain NULL if
comment|///     \a idx is out of range.
comment|///
comment|/// @see ModuleList::GetSize()
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ModuleSP
name|GetModuleAtIndex
argument_list|(
argument|size_t idx
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the module shared pointer for the module at index \a idx without
comment|/// acquiring the ModuleList mutex.  This MUST already have been
comment|/// acquired with ModuleList::GetMutex and locked for this call to be safe.
comment|///
comment|/// @param[in] idx
comment|///     An index into this module collection.
comment|///
comment|/// @return
comment|///     A shared pointer to a Module which can contain NULL if
comment|///     \a idx is out of range.
comment|///
comment|/// @see ModuleList::GetSize()
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ModuleSP
name|GetModuleAtIndexUnlocked
argument_list|(
argument|size_t idx
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the module pointer for the module at index \a idx.
comment|///
comment|/// @param[in] idx
comment|///     An index into this module collection.
comment|///
comment|/// @return
comment|///     A pointer to a Module which can by nullptr if \a idx is out
comment|///     of range.
comment|///
comment|/// @see ModuleList::GetSize()
comment|//------------------------------------------------------------------
name|Module
modifier|*
name|GetModulePointerAtIndex
argument_list|(
name|size_t
name|idx
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the module pointer for the module at index \a idx without
comment|/// acquiring the ModuleList mutex.  This MUST already have been
comment|/// acquired with ModuleList::GetMutex and locked for this call to be safe.
comment|///
comment|/// @param[in] idx
comment|///     An index into this module collection.
comment|///
comment|/// @return
comment|///     A pointer to a Module which can by nullptr if \a idx is out
comment|///     of range.
comment|///
comment|/// @see ModuleList::GetSize()
comment|//------------------------------------------------------------------
name|Module
modifier|*
name|GetModulePointerAtIndexUnlocked
argument_list|(
name|size_t
name|idx
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find compile units by partial or full path.
comment|///
comment|/// Finds all compile units that match \a path in all of the modules
comment|/// and returns the results in \a sc_list.
comment|///
comment|/// @param[in] path
comment|///     The name of the compile unit we are looking for.
comment|///
comment|/// @param[in] append
comment|///     If \b true, then append any compile units that were found
comment|///     to \a sc_list. If \b false, then the \a sc_list is cleared
comment|///     and the contents of \a sc_list are replaced.
comment|///
comment|/// @param[out] sc_list
comment|///     A symbol context list that gets filled in with all of the
comment|///     matches.
comment|///
comment|/// @return
comment|///     The number of matches added to \a sc_list.
comment|//------------------------------------------------------------------
name|size_t
name|FindCompileUnits
argument_list|(
specifier|const
name|FileSpec
operator|&
name|path
argument_list|,
name|bool
name|append
argument_list|,
name|SymbolContextList
operator|&
name|sc_list
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// @see Module::FindFunctions ()
comment|//------------------------------------------------------------------
name|size_t
name|FindFunctions
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|,
name|uint32_t
name|name_type_mask
argument_list|,
name|bool
name|include_symbols
argument_list|,
name|bool
name|include_inlines
argument_list|,
name|bool
name|append
argument_list|,
name|SymbolContextList
operator|&
name|sc_list
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// @see Module::FindFunctionSymbols ()
comment|//------------------------------------------------------------------
name|size_t
name|FindFunctionSymbols
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|name
parameter_list|,
name|uint32_t
name|name_type_mask
parameter_list|,
name|SymbolContextList
modifier|&
name|sc_list
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// @see Module::FindFunctions ()
comment|//------------------------------------------------------------------
name|size_t
name|FindFunctions
parameter_list|(
specifier|const
name|RegularExpression
modifier|&
name|name
parameter_list|,
name|bool
name|include_symbols
parameter_list|,
name|bool
name|include_inlines
parameter_list|,
name|bool
name|append
parameter_list|,
name|SymbolContextList
modifier|&
name|sc_list
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Find global and static variables by name.
comment|///
comment|/// @param[in] name
comment|///     The name of the global or static variable we are looking
comment|///     for.
comment|///
comment|/// @param[in] append
comment|///     If \b true, any matches will be appended to \a
comment|///     variable_list, else matches replace the contents of
comment|///     \a variable_list.
comment|///
comment|/// @param[in] max_matches
comment|///     Allow the number of matches to be limited to \a
comment|///     max_matches. Specify UINT32_MAX to get all possible matches.
comment|///
comment|/// @param[in] variable_list
comment|///     A list of variables that gets the matches appended to (if
comment|///     \a append it \b true), or replace (if \a append is \b false).
comment|///
comment|/// @return
comment|///     The number of matches added to \a variable_list.
comment|//------------------------------------------------------------------
name|size_t
name|FindGlobalVariables
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|,
name|bool
name|append
argument_list|,
name|size_t
name|max_matches
argument_list|,
name|VariableList
operator|&
name|variable_list
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find global and static variables by regular expression.
comment|///
comment|/// @param[in] regex
comment|///     A regular expression to use when matching the name.
comment|///
comment|/// @param[in] append
comment|///     If \b true, any matches will be appended to \a
comment|///     variable_list, else matches replace the contents of
comment|///     \a variable_list.
comment|///
comment|/// @param[in] max_matches
comment|///     Allow the number of matches to be limited to \a
comment|///     max_matches. Specify UINT32_MAX to get all possible matches.
comment|///
comment|/// @param[in] variable_list
comment|///     A list of variables that gets the matches appended to (if
comment|///     \a append it \b true), or replace (if \a append is \b false).
comment|///
comment|/// @return
comment|///     The number of matches added to \a variable_list.
comment|//------------------------------------------------------------------
name|size_t
name|FindGlobalVariables
argument_list|(
specifier|const
name|RegularExpression
operator|&
name|regex
argument_list|,
name|bool
name|append
argument_list|,
name|size_t
name|max_matches
argument_list|,
name|VariableList
operator|&
name|variable_list
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Finds the first module whose file specification matches \a
comment|/// file_spec.
comment|///
comment|/// @param[in] file_spec_ptr
comment|///     A file specification object to match against the Module's
comment|///     file specifications. If \a file_spec does not have
comment|///     directory information, matches will occur by matching only
comment|///     the basename of any modules in this list. If this value is
comment|///     NULL, then file specifications won't be compared when
comment|///     searching for matching modules.
comment|///
comment|/// @param[in] arch_ptr
comment|///     The architecture to search for if non-NULL. If this value
comment|///     is NULL no architecture matching will be performed.
comment|///
comment|/// @param[in] uuid_ptr
comment|///     The uuid to search for if non-NULL. If this value is NULL
comment|///     no uuid matching will be performed.
comment|///
comment|/// @param[in] object_name
comment|///     An optional object name that must match as well. This value
comment|///     can be NULL.
comment|///
comment|/// @param[out] matching_module_list
comment|///     A module list that gets filled in with any modules that
comment|///     match the search criteria.
comment|///
comment|/// @return
comment|///     The number of matching modules found by the search.
comment|//------------------------------------------------------------------
name|size_t
name|FindModules
argument_list|(
specifier|const
name|ModuleSpec
operator|&
name|module_spec
argument_list|,
name|ModuleList
operator|&
name|matching_module_list
argument_list|)
decl|const
decl_stmt|;
name|lldb
operator|::
name|ModuleSP
name|FindModule
argument_list|(
argument|const Module *module_ptr
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Find a module by UUID
comment|//
comment|// The UUID value for a module is extracted from the ObjectFile and
comment|// is the MD5 checksum, or a smarter object file equivalent, so
comment|// finding modules by UUID values is very efficient and accurate.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ModuleSP
name|FindModule
argument_list|(
argument|const UUID&uuid
argument_list|)
specifier|const
expr_stmt|;
name|lldb
operator|::
name|ModuleSP
name|FindFirstModule
argument_list|(
argument|const ModuleSpec&module_spec
argument_list|)
specifier|const
expr_stmt|;
name|size_t
name|FindSymbolsWithNameAndType
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|,
name|lldb
operator|::
name|SymbolType
name|symbol_type
argument_list|,
name|SymbolContextList
operator|&
name|sc_list
argument_list|,
name|bool
name|append
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|size_t
name|FindSymbolsMatchingRegExAndType
argument_list|(
specifier|const
name|RegularExpression
operator|&
name|regex
argument_list|,
name|lldb
operator|::
name|SymbolType
name|symbol_type
argument_list|,
name|SymbolContextList
operator|&
name|sc_list
argument_list|,
name|bool
name|append
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find types by name.
comment|///
comment|/// @param[in] sc
comment|///     A symbol context that scopes where to extract a type list
comment|///     from.
comment|///
comment|/// @param[in] name
comment|///     The name of the type we are looking for.
comment|///
comment|/// @param[in] append
comment|///     If \b true, any matches will be appended to \a
comment|///     variable_list, else matches replace the contents of
comment|///     \a variable_list.
comment|///
comment|/// @param[in] max_matches
comment|///     Allow the number of matches to be limited to \a
comment|///     max_matches. Specify UINT32_MAX to get all possible matches.
comment|///
comment|/// @param[in] encoding
comment|///     Limit the search to specific types, or get all types if
comment|///     set to Type::invalid.
comment|///
comment|/// @param[in] udt_name
comment|///     If the encoding is a user defined type, specify the name
comment|///     of the user defined type ("struct", "union", "class", etc).
comment|///
comment|/// @param[out] type_list
comment|///     A type list gets populated with any matches.
comment|///
comment|/// @return
comment|///     The number of matches added to \a type_list.
comment|//------------------------------------------------------------------
name|size_t
name|FindTypes
argument_list|(
specifier|const
name|SymbolContext
operator|&
name|sc
argument_list|,
specifier|const
name|ConstString
operator|&
name|name
argument_list|,
name|bool
name|name_is_fully_qualified
argument_list|,
name|size_t
name|max_matches
argument_list|,
name|llvm
operator|::
name|DenseSet
operator|<
name|SymbolFile
operator|*
operator|>
operator|&
name|searched_symbol_files
argument_list|,
name|TypeList
operator|&
name|types
argument_list|)
decl|const
decl_stmt|;
name|bool
name|FindSourceFile
argument_list|(
specifier|const
name|FileSpec
operator|&
name|orig_spec
argument_list|,
name|FileSpec
operator|&
name|new_spec
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find addresses by file/line
comment|///
comment|/// @param[in] target_sp
comment|///     The target the addresses are desired for.
comment|///
comment|/// @param[in] file
comment|///     Source file to locate.
comment|///
comment|/// @param[in] line
comment|///     Source line to locate.
comment|///
comment|/// @param[in] function
comment|///     Optional filter function. Addresses within this function will be
comment|///     added to the 'local' list. All others will be added to the 'extern'
comment|///     list.
comment|///
comment|/// @param[out] output_local
comment|///     All matching addresses within 'function'
comment|///
comment|/// @param[out] output_extern
comment|///     All matching addresses not within 'function'
name|void
name|FindAddressesForLine
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
name|target_sp
argument_list|,
specifier|const
name|FileSpec
operator|&
name|file
argument_list|,
name|uint32_t
name|line
argument_list|,
name|Function
operator|*
name|function
argument_list|,
name|std
operator|::
name|vector
operator|<
name|Address
operator|>
operator|&
name|output_local
argument_list|,
name|std
operator|::
name|vector
operator|<
name|Address
operator|>
operator|&
name|output_extern
argument_list|)
decl_stmt|;
name|bool
name|Remove
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
decl_stmt|;
name|size_t
name|Remove
parameter_list|(
name|ModuleList
modifier|&
name|module_list
parameter_list|)
function_decl|;
name|bool
name|RemoveIfOrphaned
parameter_list|(
specifier|const
name|Module
modifier|*
name|module_ptr
parameter_list|)
function_decl|;
name|size_t
name|RemoveOrphans
parameter_list|(
name|bool
name|mandatory
parameter_list|)
function_decl|;
name|bool
name|ResolveFileAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|vm_addr
argument_list|,
name|Address
operator|&
name|so_addr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// @copydoc Module::ResolveSymbolContextForAddress (const Address
comment|///&,uint32_t,SymbolContext&)
comment|//------------------------------------------------------------------
name|uint32_t
name|ResolveSymbolContextForAddress
argument_list|(
specifier|const
name|Address
operator|&
name|so_addr
argument_list|,
name|uint32_t
name|resolve_scope
argument_list|,
name|SymbolContext
operator|&
name|sc
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// @copydoc Module::ResolveSymbolContextForFilePath (const char
comment|/// *,uint32_t,bool,uint32_t,SymbolContextList&)
comment|//------------------------------------------------------------------
name|uint32_t
name|ResolveSymbolContextForFilePath
argument_list|(
specifier|const
name|char
operator|*
name|file_path
argument_list|,
name|uint32_t
name|line
argument_list|,
name|bool
name|check_inlines
argument_list|,
name|uint32_t
name|resolve_scope
argument_list|,
name|SymbolContextList
operator|&
name|sc_list
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// @copydoc Module::ResolveSymbolContextsForFileSpec (const FileSpec
comment|///&,uint32_t,bool,uint32_t,SymbolContextList&)
comment|//------------------------------------------------------------------
name|uint32_t
name|ResolveSymbolContextsForFileSpec
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file_spec
argument_list|,
name|uint32_t
name|line
argument_list|,
name|bool
name|check_inlines
argument_list|,
name|uint32_t
name|resolve_scope
argument_list|,
name|SymbolContextList
operator|&
name|sc_list
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Gets the size of the module list.
comment|///
comment|/// @return
comment|///     The number of modules in the module list.
comment|//------------------------------------------------------------------
name|size_t
name|GetSize
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|LoadScriptingResourcesInTarget
argument_list|(
name|Target
operator|*
name|target
argument_list|,
name|std
operator|::
name|list
operator|<
name|Error
operator|>
operator|&
name|errors
argument_list|,
name|Stream
operator|*
name|feedback_stream
operator|=
name|nullptr
argument_list|,
name|bool
name|continue_on_error
operator|=
name|true
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|ModuleIsInCache
parameter_list|(
specifier|const
name|Module
modifier|*
name|module_ptr
parameter_list|)
function_decl|;
specifier|static
name|Error
name|GetSharedModule
argument_list|(
specifier|const
name|ModuleSpec
operator|&
name|module_spec
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
specifier|const
name|FileSpecList
operator|*
name|module_search_paths_ptr
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|*
name|old_module_sp_ptr
argument_list|,
name|bool
operator|*
name|did_create_ptr
argument_list|,
name|bool
name|always_create
operator|=
name|false
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|RemoveSharedModule
argument_list|(
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
decl_stmt|;
specifier|static
name|size_t
name|FindSharedModules
parameter_list|(
specifier|const
name|ModuleSpec
modifier|&
name|module_spec
parameter_list|,
name|ModuleList
modifier|&
name|matching_module_list
parameter_list|)
function_decl|;
specifier|static
name|size_t
name|RemoveOrphanSharedModules
parameter_list|(
name|bool
name|mandatory
parameter_list|)
function_decl|;
specifier|static
name|bool
name|RemoveSharedModuleIfOrphaned
parameter_list|(
specifier|const
name|Module
modifier|*
name|module_ptr
parameter_list|)
function_decl|;
name|void
name|ForEach
argument_list|(
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
operator|>
specifier|const
operator|&
name|callback
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Class typedefs.
comment|//------------------------------------------------------------------
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|ModuleSP
operator|>
name|collection
expr_stmt|;
comment|///< The module collection type.
name|void
name|AppendImpl
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
name|bool
name|use_notifier
operator|=
name|true
argument_list|)
decl_stmt|;
name|bool
name|RemoveImpl
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
name|bool
name|use_notifier
operator|=
name|true
argument_list|)
decl_stmt|;
name|collection
operator|::
name|iterator
name|RemoveImpl
argument_list|(
argument|collection::iterator pos
argument_list|,
argument|bool use_notifier = true
argument_list|)
expr_stmt|;
name|void
name|ClearImpl
parameter_list|(
name|bool
name|use_notifier
init|=
name|true
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|collection
name|m_modules
decl_stmt|;
comment|///< The collection of modules.
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_modules_mutex
expr_stmt|;
name|Notifier
modifier|*
name|m_notifier
decl_stmt|;
name|public
label|:
typedef|typedef
name|LockingAdaptedIterable
operator|<
name|collection
operator|,
name|lldb
operator|::
name|ModuleSP
operator|,
name|vector_adapter
operator|,
name|std
operator|::
name|recursive_mutex
operator|>
name|ModuleIterable
expr_stmt|;
name|ModuleIterable
name|Modules
parameter_list|()
block|{
return|return
name|ModuleIterable
argument_list|(
name|m_modules
argument_list|,
name|GetMutex
argument_list|()
argument_list|)
return|;
block|}
typedef|typedef
name|AdaptedIterable
operator|<
name|collection
operator|,
name|lldb
operator|::
name|ModuleSP
operator|,
name|vector_adapter
operator|>
name|ModuleIterableNoLocking
expr_stmt|;
name|ModuleIterableNoLocking
name|ModulesNoLocking
parameter_list|()
block|{
return|return
name|ModuleIterableNoLocking
argument_list|(
name|m_modules
argument_list|)
return|;
block|}
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
comment|// liblldb_ModuleList_h_
end_comment

end_unit

