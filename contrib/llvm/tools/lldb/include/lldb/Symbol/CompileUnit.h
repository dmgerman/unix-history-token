begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CompileUnit.h -------------------------------------------*- C++ -*-===//
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
name|liblldb_CompUnit_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CompUnit_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/FileSpecList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ModuleChild.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/DebugMacros.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/Function.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Stream.h"
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

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class CompileUnit CompileUnit.h "lldb/Symbol/CompileUnit.h"
comment|/// @brief A class that describes a compilation unit.
comment|///
comment|/// A representation of a compilation unit, or compiled source file.
comment|/// The UserID of the compile unit is specified by the SymbolFile
comment|/// plug-in and can have any value as long as the value is unique
comment|/// within the Module that owns this compile units.
comment|///
comment|/// Each compile unit has a list of functions, global and static
comment|/// variables, support file list (include files and inlined source
comment|/// files), and a line table.
comment|//----------------------------------------------------------------------
name|class
name|CompileUnit
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|CompileUnit
operator|>
decl_stmt|,
name|public
name|ModuleChild
decl_stmt|,
name|public
name|FileSpec
decl_stmt|,
name|public
name|UserID
decl_stmt|,
name|public
name|SymbolContextScope
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Construct with a module, path, UID and language.
comment|///
comment|/// Initialize the compile unit given the owning \a module, a path
comment|/// to convert into a FileSpec, the SymbolFile plug-in supplied
comment|/// \a uid, and the source language type.
comment|///
comment|/// @param[in] module
comment|///     The parent module that owns this compile unit. This value
comment|///     must be a valid pointer value.
comment|///
comment|/// @param[in] user_data
comment|///     User data where the SymbolFile parser can store data.
comment|///
comment|/// @param[in] pathname
comment|///     The path to the source file for this compile unit.
comment|///
comment|/// @param[in] uid
comment|///     The user ID of the compile unit. This value is supplied by
comment|///     the SymbolFile plug-in and should be a value that allows
comment|///     the SymbolFile plug-in to easily locate and parse additional
comment|///     information for the compile unit.
comment|///
comment|/// @param[in] language
comment|///     A language enumeration type that describes the main language
comment|///     of this compile unit.
comment|///
comment|/// @param[in] is_optimized
comment|///     A value that can initialized with eLazyBoolYes, eLazyBoolNo
comment|///     or eLazyBoolCalculate. If set to eLazyBoolCalculate, then
comment|///     an extra call into SymbolVendor will be made to calculate if
comment|///     the compile unit is optimized will be made when
comment|///     CompileUnit::GetIsOptimized() is called.
comment|///
comment|/// @see lldb::LanguageType
comment|//------------------------------------------------------------------
name|CompileUnit
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|void *user_data
argument_list|,
argument|const char *pathname
argument_list|,
argument|lldb::user_id_t uid
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|lldb_private::LazyBool is_optimized
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct with a module, file spec, UID and language.
comment|///
comment|/// Initialize the compile unit given the owning \a module, a path
comment|/// to convert into a FileSpec, the SymbolFile plug-in supplied
comment|/// \a uid, and the source language type.
comment|///
comment|/// @param[in] module
comment|///     The parent module that owns this compile unit. This value
comment|///     must be a valid pointer value.
comment|///
comment|/// @param[in] user_data
comment|///     User data where the SymbolFile parser can store data.
comment|///
comment|/// @param[in] file_spec
comment|///     The file specification for the source file of this compile
comment|///     unit.
comment|///
comment|/// @param[in] uid
comment|///     The user ID of the compile unit. This value is supplied by
comment|///     the SymbolFile plug-in and should be a value that allows
comment|///     the plug-in to easily locate and parse
comment|///     additional information for the compile unit.
comment|///
comment|/// @param[in] language
comment|///     A language enumeration type that describes the main language
comment|///     of this compile unit.
comment|///
comment|/// @param[in] is_optimized
comment|///     A value that can initialized with eLazyBoolYes, eLazyBoolNo
comment|///     or eLazyBoolCalculate. If set to eLazyBoolCalculate, then
comment|///     an extra call into SymbolVendor will be made to calculate if
comment|///     the compile unit is optimized will be made when
comment|///     CompileUnit::GetIsOptimized() is called.
comment|///
comment|/// @see lldb::LanguageType
comment|//------------------------------------------------------------------
name|CompileUnit
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|void *user_data
argument_list|,
argument|const FileSpec&file_spec
argument_list|,
argument|lldb::user_id_t uid
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|lldb_private::LazyBool is_optimized
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
operator|~
name|CompileUnit
argument_list|()
name|override
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Add a function to this compile unit.
comment|///
comment|/// Typically called by the SymbolFile plug-ins as they partially
comment|/// parse the debug information.
comment|///
comment|/// @param[in] function_sp
comment|///     A shared pointer to the Function object.
comment|//------------------------------------------------------------------
name|void
name|AddFunction
argument_list|(
name|lldb
operator|::
name|FunctionSP
operator|&
name|function_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// @copydoc SymbolContextScope::CalculateSymbolContext(SymbolContext*)
comment|///
comment|/// @see SymbolContextScope
comment|//------------------------------------------------------------------
name|void
name|CalculateSymbolContext
argument_list|(
name|SymbolContext
operator|*
name|sc
argument_list|)
name|override
decl_stmt|;
name|lldb
operator|::
name|ModuleSP
name|CalculateSymbolContextModule
argument_list|()
name|override
expr_stmt|;
name|CompileUnit
operator|*
name|CalculateSymbolContextCompileUnit
argument_list|()
name|override
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// @copydoc SymbolContextScope::DumpSymbolContext(Stream*)
comment|///
comment|/// @see SymbolContextScope
comment|//------------------------------------------------------------------
name|void
name|DumpSymbolContext
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
name|override
decl_stmt|;
name|lldb
operator|::
name|LanguageType
name|GetLanguage
argument_list|()
expr_stmt|;
name|void
name|SetLanguage
argument_list|(
name|lldb
operator|::
name|LanguageType
name|language
argument_list|)
block|{
name|m_flags
operator|.
name|Set
argument_list|(
name|flagsParsedLanguage
argument_list|)
expr_stmt|;
name|m_language
operator|=
name|language
expr_stmt|;
block|}
name|void
name|GetDescription
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|level
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get a shared pointer to a function in this compile unit by
comment|/// index.
comment|///
comment|/// Typically called when iterating though all functions in a
comment|/// compile unit after all functions have been parsed. This provides
comment|/// raw access to the function shared pointer list and will not
comment|/// cause the SymbolFile plug-in to parse any unparsed functions.
comment|///
comment|/// @param[in] idx
comment|///     An index into the function list.
comment|///
comment|/// @return
comment|///     A shared pointer to a function that might contain a NULL
comment|///     Function class pointer.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|FunctionSP
name|GetFunctionAtIndex
argument_list|(
argument|size_t idx
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Dump the compile unit contents to the stream \a s.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|///
comment|/// @param[in] show_context
comment|///     If \b true, variables will dump their symbol context
comment|///     information.
comment|//------------------------------------------------------------------
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
comment|//------------------------------------------------------------------
comment|/// Find the line entry by line and optional inlined file spec.
comment|///
comment|/// Finds the first line entry that has an index greater than
comment|/// \a start_idx that matches \a line. If \a file_spec_ptr
comment|/// is NULL, then the search matches line entries whose file matches
comment|/// the file for the compile unit. If \a file_spec_ptr is
comment|/// not NULL, line entries must match the specified file spec (for
comment|/// inlined line table entries).
comment|///
comment|/// Multiple calls to this function can find all entries that match
comment|/// a given file and line by starting with \a start_idx equal to zero,
comment|/// and calling this function back with the return value + 1.
comment|///
comment|/// @param[in] start_idx
comment|///     The zero based index at which to start looking for matches.
comment|///
comment|/// @param[in] line
comment|///     The line number to search for.
comment|///
comment|/// @param[in] file_spec_ptr
comment|///     If non-NULL search for entries that match this file spec,
comment|///     else if NULL, search for line entries that match the compile
comment|///     unit file.
comment|///
comment|/// @param[in] exact
comment|///     If \btrue match only if there is a line table entry for this line
comment|///     number.
comment|///     If \bfalse, find the line table entry equal to or after this line
comment|///     number.
comment|///
comment|/// @param[out] line_entry
comment|///     If non-NULL, a copy of the line entry that was found.
comment|///
comment|/// @return
comment|///     The zero based index of a matching line entry, or UINT32_MAX
comment|///     if no matching line entry is found.
comment|//------------------------------------------------------------------
name|uint32_t
name|FindLineEntry
parameter_list|(
name|uint32_t
name|start_idx
parameter_list|,
name|uint32_t
name|line
parameter_list|,
specifier|const
name|FileSpec
modifier|*
name|file_spec_ptr
parameter_list|,
name|bool
name|exact
parameter_list|,
name|LineEntry
modifier|*
name|line_entry
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the line table for the compile unit.
comment|///
comment|/// Called by clients and the SymbolFile plug-in. The SymbolFile
comment|/// plug-ins use this function to determine if the line table has
comment|/// be parsed yet. Clients use this function to get the line table
comment|/// from a compile unit.
comment|///
comment|/// @return
comment|///     The line table object pointer, or NULL if this line table
comment|///     hasn't been parsed yet.
comment|//------------------------------------------------------------------
name|LineTable
modifier|*
name|GetLineTable
parameter_list|()
function_decl|;
name|DebugMacros
modifier|*
name|GetDebugMacros
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the compile unit's support file list.
comment|///
comment|/// The support file list is used by the line table, and any objects
comment|/// that have valid Declaration objects.
comment|///
comment|/// @return
comment|///     A support file list object.
comment|//------------------------------------------------------------------
name|FileSpecList
modifier|&
name|GetSupportFiles
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the compile unit's imported module list.
comment|///
comment|/// This reports all the imports that the compile unit made,
comment|/// including the current module.
comment|///
comment|/// @return
comment|///     A list of imported module names.
comment|//------------------------------------------------------------------
specifier|const
name|std
operator|::
name|vector
operator|<
name|ConstString
operator|>
operator|&
name|GetImportedModules
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the SymbolFile plug-in user data.
comment|///
comment|/// SymbolFile plug-ins can store user data to internal state or
comment|/// objects to quickly allow them to parse more information for a
comment|/// given object.
comment|///
comment|/// @return
comment|///     The user data stored with the CompileUnit when it was
comment|///     constructed.
comment|//------------------------------------------------------------------
name|void
operator|*
name|GetUserData
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the variable list for a compile unit.
comment|///
comment|/// Called by clients to get the variable list for a compile unit.
comment|/// The variable list will contain all global and static variables
comment|/// that were defined at the compile unit level.
comment|///
comment|/// @param[in] can_create
comment|///     If \b true, the variable list will be parsed on demand. If
comment|///     \b false, the current variable list will be returned even
comment|///     if it contains a NULL VariableList object (typically
comment|///     called by dumping routines that want to display only what
comment|///     has currently been parsed).
comment|///
comment|/// @return
comment|///     A shared pointer to a variable list, that can contain NULL
comment|///     VariableList pointer if there are no global or static
comment|///     variables.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|VariableListSP
name|GetVariableList
argument_list|(
argument|bool can_create
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Finds a function by user ID.
comment|///
comment|/// Typically used by SymbolFile plug-ins when partially parsing
comment|/// the debug information to see if the function has been parsed
comment|/// yet.
comment|///
comment|/// @param[in] uid
comment|///     The user ID of the function to find. This value is supplied
comment|///     by the SymbolFile plug-in and should be a value that
comment|///     allows the plug-in to easily locate and parse additional
comment|///     information in the function.
comment|///
comment|/// @return
comment|///     A shared pointer to the function object that might contain
comment|///     a NULL Function pointer.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|FunctionSP
name|FindFunctionByUID
argument_list|(
argument|lldb::user_id_t uid
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set the line table for the compile unit.
comment|///
comment|/// Called by the SymbolFile plug-in when if first parses the line
comment|/// table and hands ownership of the line table to this object. The
comment|/// compile unit owns the line table object and will delete the
comment|/// object when it is deleted.
comment|///
comment|/// @param[in] line_table
comment|///     A line table object pointer that this object now owns.
comment|//------------------------------------------------------------------
name|void
name|SetLineTable
parameter_list|(
name|LineTable
modifier|*
name|line_table
parameter_list|)
function_decl|;
name|void
name|SetDebugMacros
parameter_list|(
specifier|const
name|DebugMacrosSP
modifier|&
name|debug_macros
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set accessor for the variable list.
comment|///
comment|/// Called by the SymbolFile plug-ins after they have parsed the
comment|/// variable lists and are ready to hand ownership of the list over
comment|/// to this object.
comment|///
comment|/// @param[in] variable_list_sp
comment|///     A shared pointer to a VariableList.
comment|//------------------------------------------------------------------
name|void
name|SetVariableList
argument_list|(
name|lldb
operator|::
name|VariableListSP
operator|&
name|variable_list_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Resolve symbol contexts by file and line.
comment|///
comment|/// Given a file in \a file_spec, and a line number, find all
comment|/// instances and append them to the supplied symbol context list
comment|/// \a sc_list.
comment|///
comment|/// @param[in] file_spec
comment|///     A file specification. If \a file_spec contains no directory
comment|///     information, only the basename will be used when matching
comment|///     contexts. If the directory in \a file_spec is valid, a
comment|///     complete file specification match will be performed.
comment|///
comment|/// @param[in] line
comment|///     The line number to match against the compile unit's line
comment|///     tables.
comment|///
comment|/// @param[in] check_inlines
comment|///     If \b true this function will also match any inline
comment|///     file and line matches. If \b false, the compile unit's
comment|///     file specification must match \a file_spec for any matches
comment|///     to be returned.
comment|///
comment|/// @param[in] exact
comment|///     If true, only resolve the context if \a line exists in the line table.
comment|///     If false, resolve the context to the closest line greater than \a line
comment|///     in the line table.
comment|///
comment|/// @param[in] resolve_scope
comment|///     For each matching line entry, this bitfield indicates what
comment|///     values within each SymbolContext that gets added to \a
comment|///     sc_list will be resolved. See the SymbolContext::Scope
comment|///     enumeration for a list of all available bits that can be
comment|///     resolved. Only SymbolContext entries that can be resolved
comment|///     using a LineEntry base address will be able to be resolved.
comment|///
comment|/// @param[out] sc_list
comment|///     A SymbolContext list class that will get any matching
comment|///     entries appended to.
comment|///
comment|/// @return
comment|///     The number of new matches that were added to \a sc_list.
comment|///
comment|/// @see enum SymbolContext::Scope
comment|//------------------------------------------------------------------
name|uint32_t
name|ResolveSymbolContext
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|file_spec
parameter_list|,
name|uint32_t
name|line
parameter_list|,
name|bool
name|check_inlines
parameter_list|,
name|bool
name|exact
parameter_list|,
name|uint32_t
name|resolve_scope
parameter_list|,
name|SymbolContextList
modifier|&
name|sc_list
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get whether compiler optimizations were enabled for this compile unit
comment|///
comment|/// "optimized" means that the debug experience may be difficult
comment|/// for the user to understand.  Variables may not be available when
comment|/// the developer would expect them, stepping through the source lines
comment|/// in the function may appear strange, etc.
comment|///
comment|/// @return
comment|///     Returns 'true' if this compile unit was compiled with
comment|///     optimization.  'false' indicates that either the optimization
comment|///     is unknown, or this compile unit was built without optimization.
comment|//------------------------------------------------------------------
name|bool
name|GetIsOptimized
parameter_list|()
function_decl|;
name|protected
label|:
name|void
modifier|*
name|m_user_data
decl_stmt|;
comment|///< User data for the SymbolFile parser to store
comment|///information into.
name|lldb
operator|::
name|LanguageType
name|m_language
expr_stmt|;
comment|///< The programming language enumeration value.
name|Flags
name|m_flags
decl_stmt|;
comment|///< Compile unit flags that help with partial parsing.
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|FunctionSP
operator|>
name|m_functions
expr_stmt|;
comment|///< The sparsely populated list of
comment|///shared pointers to functions
comment|///< that gets populated as functions get partially parsed.
name|std
operator|::
name|vector
operator|<
name|ConstString
operator|>
name|m_imported_modules
expr_stmt|;
comment|///< All modules, including the
comment|///current module, imported by
comment|///this
comment|///< compile unit.
name|FileSpecList
name|m_support_files
decl_stmt|;
comment|///< Files associated with this compile unit's
comment|///line table and declarations.
name|std
operator|::
name|unique_ptr
operator|<
name|LineTable
operator|>
name|m_line_table_ap
expr_stmt|;
comment|///< Line table that will get parsed on demand.
name|DebugMacrosSP
name|m_debug_macros_sp
decl_stmt|;
comment|///< Debug macros that will get parsed on demand.
name|lldb
operator|::
name|VariableListSP
name|m_variables
expr_stmt|;
comment|///< Global and static variable list that
comment|///will get parsed on demand.
name|lldb_private
operator|::
name|LazyBool
name|m_is_optimized
expr_stmt|;
comment|/// eLazyBoolYes if this compile unit
comment|/// was compiled with optimization.
name|private
label|:
enum|enum
block|{
name|flagsParsedAllFunctions
init|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
block|,
comment|///< Have we already parsed all our functions
name|flagsParsedVariables
init|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
block|,
comment|///< Have we already parsed globals and statics?
name|flagsParsedSupportFiles
init|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
block|,
comment|///< Have we already parsed the support
comment|///files for this compile unit?
name|flagsParsedLineTable
init|=
operator|(
literal|1u
operator|<<
literal|3
operator|)
block|,
comment|///< Have we parsed the line table already?
name|flagsParsedLanguage
init|=
operator|(
literal|1u
operator|<<
literal|4
operator|)
block|,
comment|///< Have we parsed the language already?
name|flagsParsedImportedModules
init|=
operator|(
literal|1u
operator|<<
literal|5
operator|)
block|,
comment|///< Have we parsed the imported modules already?
name|flagsParsedDebugMacros
init|=
operator|(
literal|1u
operator|<<
literal|6
operator|)
comment|///< Have we parsed the debug macros already?
block|}
enum|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|CompileUnit
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
comment|// liblldb_CompUnit_h_
end_comment

end_unit

