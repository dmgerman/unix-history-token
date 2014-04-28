begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Module.h ------------------------------------------------*- C++ -*-===//
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
name|liblldb_Module_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Module_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/UUID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/TimeValue.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/ClangASTContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/SymbolContextScope.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/PathMappingList.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Module Module.h "lldb/Core/Module.h"
comment|/// @brief A class that describes an executable image and its associated
comment|///        object and symbol files.
comment|///
comment|/// The module is designed to be able to select a single slice of an
comment|/// executable image as it would appear on disk and during program
comment|/// execution.
comment|///
comment|/// Modules control when and if information is parsed according to which
comment|/// accessors are called. For example the object file (ObjectFile)
comment|/// representation will only be parsed if the object file is requested
comment|/// using the Module::GetObjectFile() is called. The debug symbols
comment|/// will only be parsed if the symbol vendor (SymbolVendor) is
comment|/// requested using the Module::GetSymbolVendor() is called.
comment|///
comment|/// The module will parse more detailed information as more queries are
comment|/// made.
comment|//----------------------------------------------------------------------
name|class
name|Module
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|Module
operator|>
decl_stmt|,
name|public
name|SymbolContextScope
block|{
name|public
label|:
comment|// Static functions that can track the lifetime of module objects.
comment|// This is handy because we might have Module objects that are in
comment|// shared pointers that aren't in the global module list (from
comment|// ModuleList). If this is the case we need to know about it.
comment|// The modules in the global list maintained by these functions
comment|// can be viewed using the "target modules list" command using the
comment|// "--global" (-g for short).
specifier|static
name|size_t
name|GetNumberAllocatedModules
parameter_list|()
function_decl|;
specifier|static
name|Module
modifier|*
name|GetAllocatedModuleAtIndex
parameter_list|(
name|size_t
name|idx
parameter_list|)
function_decl|;
specifier|static
name|Mutex
modifier|*
name|GetAllocationModuleCollectionMutex
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Construct with file specification and architecture.
comment|///
comment|/// Clients that wish to share modules with other targets should
comment|/// use ModuleList::GetSharedModule().
comment|///
comment|/// @param[in] file_spec
comment|///     The file specification for the on disk repesentation of
comment|///     this executable image.
comment|///
comment|/// @param[in] arch
comment|///     The architecture to set as the current architecture in
comment|///     this module.
comment|///
comment|/// @param[in] object_name
comment|///     The name of an object in a module used to extract a module
comment|///     within a module (.a files and modules that contain multiple
comment|///     architectures).
comment|///
comment|/// @param[in] object_offset
comment|///     The offset within an existing module used to extract a
comment|///     module within a module (.a files and modules that contain
comment|///     multiple architectures).
comment|//------------------------------------------------------------------
name|Module
argument_list|(
argument|const FileSpec& file_spec
argument_list|,
argument|const ArchSpec& arch
argument_list|,
argument|const ConstString *object_name = NULL
argument_list|,
argument|off_t object_offset =
literal|0
argument_list|,
argument|const TimeValue *object_mod_time_ptr = NULL
argument_list|)
empty_stmt|;
name|Module
argument_list|(
specifier|const
name|ModuleSpec
operator|&
name|module_spec
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|Module
argument_list|()
expr_stmt|;
name|bool
name|MatchesModuleSpec
parameter_list|(
specifier|const
name|ModuleSpec
modifier|&
name|module_ref
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set the load address for all sections in a module to be the
comment|/// file address plus \a slide.
comment|///
comment|/// Many times a module will be loaded in a target with a constant
comment|/// offset applied to all top level sections. This function can
comment|/// set the load address for all top level sections to be the
comment|/// section file address + offset.
comment|///
comment|/// @param[in] target
comment|///     The target in which to apply the section load addresses.
comment|///
comment|/// @param[in] value
comment|///     if \a value_is_offset is true, then value is the offset to
comment|///     apply to all file addresses for all top level sections in
comment|///     the object file as each section load address is being set.
comment|///     If \a value_is_offset is false, then "value" is the new
comment|///     absolute base address for the image.
comment|///
comment|/// @param[in] value_is_offset
comment|///     If \b true, then \a value is an offset to apply to each
comment|///     file address of each top level section.
comment|///     If \b false, then \a value is the image base address that
comment|///     will be used to rigidly slide all loadable sections.
comment|///
comment|/// @param[out] changed
comment|///     If any section load addresses were changed in \a target,
comment|///     then \a changed will be set to \b true. Else \a changed
comment|///     will be set to false. This allows this function to be
comment|///     called multiple times on the same module for the same
comment|///     target. If the module hasn't moved, then \a changed will
comment|///     be false and no module updated notification will need to
comment|///     be sent out.
comment|///
comment|/// @return
comment|///     /b True if any sections were successfully loaded in \a target,
comment|///     /b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|SetLoadAddress
argument_list|(
name|Target
operator|&
name|target
argument_list|,
name|lldb
operator|::
name|addr_t
name|value
argument_list|,
name|bool
name|value_is_offset
argument_list|,
name|bool
operator|&
name|changed
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// @copydoc SymbolContextScope::CalculateSymbolContext(SymbolContext*)
comment|///
comment|/// @see SymbolContextScope
comment|//------------------------------------------------------------------
name|virtual
name|void
name|CalculateSymbolContext
parameter_list|(
name|SymbolContext
modifier|*
name|sc
parameter_list|)
function_decl|;
name|virtual
name|lldb
operator|::
name|ModuleSP
name|CalculateSymbolContextModule
argument_list|()
expr_stmt|;
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
operator|=
name|lldb
operator|::
name|eDescriptionLevelFull
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the module path and object name.
comment|///
comment|/// Modules can refer to object files. In this case the specification
comment|/// is simple and would return the path to the file:
comment|///
comment|///     "/usr/lib/foo.dylib"
comment|///
comment|/// Modules can be .o files inside of a BSD archive (.a file). In
comment|/// this case, the object specification will look like:
comment|///
comment|///     "/usr/lib/foo.a(bar.o)"
comment|///
comment|/// There are many places where logging wants to log this fully
comment|/// qualified specification, so we centralize this functionality
comment|/// here.
comment|///
comment|/// @return
comment|///     The object path + object name if there is one.
comment|//------------------------------------------------------------------
name|std
operator|::
name|string
name|GetSpecificationDescription
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Dump a description of this object to a Stream.
comment|///
comment|/// Dump a description of the contents of this object to the
comment|/// supplied stream \a s. The dumped content will be only what has
comment|/// been loaded or parsed up to this point at which this function
comment|/// is called, so this is a good way to see what has been parsed
comment|/// in a module.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object descripton.
comment|//------------------------------------------------------------------
name|void
name|Dump
parameter_list|(
name|Stream
modifier|*
name|s
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// @copydoc SymbolContextScope::DumpSymbolContext(Stream*)
comment|///
comment|/// @see SymbolContextScope
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DumpSymbolContext
parameter_list|(
name|Stream
modifier|*
name|s
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Find a symbol in the object file's symbol table.
comment|///
comment|/// @param[in] name
comment|///     The name of the symbol that we are looking for.
comment|///
comment|/// @param[in] symbol_type
comment|///     If set to eSymbolTypeAny, find a symbol of any type that
comment|///     has a name that matches \a name. If set to any other valid
comment|///     SymbolType enumeration value, then search only for
comment|///     symbols that match \a symbol_type.
comment|///
comment|/// @return
comment|///     Returns a valid symbol pointer if a symbol was found,
comment|///     NULL otherwise.
comment|//------------------------------------------------------------------
specifier|const
name|Symbol
modifier|*
name|FindFirstSymbolWithNameAndType
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
operator|=
name|lldb
operator|::
name|eSymbolTypeAny
argument_list|)
decl_stmt|;
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
argument_list|)
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
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find a funciton symbols in the object file's symbol table.
comment|///
comment|/// @param[in] name
comment|///     The name of the symbol that we are looking for.
comment|///
comment|/// @param[in] name_type_mask
comment|///     A mask that has one or more bitwise OR'ed values from the
comment|///     lldb::FunctionNameType enumeration type that indicate what
comment|///     kind of names we are looking for.
comment|///
comment|/// @param[out] sc_list
comment|///     A list to append any matching symbol contexts to.
comment|///
comment|/// @return
comment|///     The number of symbol contexts that were added to \a sc_list
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
comment|/// Find compile units by partial or full path.
comment|///
comment|/// Finds all compile units that match \a path in all of the modules
comment|/// and returns the results in \a sc_list.
comment|///
comment|/// @param[in] path
comment|///     The name of the function we are looking for.
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
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|path
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
comment|/// Find functions by name.
comment|///
comment|/// If the function is an inlined function, it will have a block,
comment|/// representing the inlined function, and the function will be the
comment|/// containing function.  If it is not inlined, then the block will
comment|/// be NULL.
comment|///
comment|/// @param[in] name
comment|///     The name of the compile unit we are looking for.
comment|///
comment|/// @param[in] namespace_decl
comment|///     If valid, a namespace to search in.
comment|///
comment|/// @param[in] name_type_mask
comment|///     A bit mask of bits that indicate what kind of names should
comment|///     be used when doing the lookup. Bits include fully qualified
comment|///     names, base names, C++ methods, or ObjC selectors.
comment|///     See FunctionNameType for more details.
comment|///
comment|/// @param[in] append
comment|///     If \b true, any matches will be appended to \a sc_list, else
comment|///     matches replace the contents of \a sc_list.
comment|///
comment|/// @param[out] sc_list
comment|///     A symbol context list that gets filled in with all of the
comment|///     matches.
comment|///
comment|/// @return
comment|///     The number of matches added to \a sc_list.
comment|//------------------------------------------------------------------
name|size_t
name|FindFunctions
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|name
parameter_list|,
specifier|const
name|ClangNamespaceDecl
modifier|*
name|namespace_decl
parameter_list|,
name|uint32_t
name|name_type_mask
parameter_list|,
name|bool
name|symbols_ok
parameter_list|,
name|bool
name|inlines_ok
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
comment|/// Find functions by name.
comment|///
comment|/// If the function is an inlined function, it will have a block,
comment|/// representing the inlined function, and the function will be the
comment|/// containing function.  If it is not inlined, then the block will
comment|/// be NULL.
comment|///
comment|/// @param[in] regex
comment|///     A regular expression to use when matching the name.
comment|///
comment|/// @param[in] append
comment|///     If \b true, any matches will be appended to \a sc_list, else
comment|///     matches replace the contents of \a sc_list.
comment|///
comment|/// @param[out] sc_list
comment|///     A symbol context list that gets filled in with all of the
comment|///     matches.
comment|///
comment|/// @return
comment|///     The number of matches added to \a sc_list.
comment|//------------------------------------------------------------------
name|size_t
name|FindFunctions
parameter_list|(
specifier|const
name|RegularExpression
modifier|&
name|regex
parameter_list|,
name|bool
name|symbols_ok
parameter_list|,
name|bool
name|inlines_ok
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
comment|///	    Optional filter function. Addresses within this function will be
comment|///     added to the 'local' list. All others will be added to the 'extern' list.
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
comment|//------------------------------------------------------------------
comment|/// Find global and static variables by name.
comment|///
comment|/// @param[in] name
comment|///     The name of the global or static variable we are looking
comment|///     for.
comment|///
comment|/// @param[in] namespace_decl
comment|///     If valid, a namespace to search in.
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
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|name
parameter_list|,
specifier|const
name|ClangNamespaceDecl
modifier|*
name|namespace_decl
parameter_list|,
name|bool
name|append
parameter_list|,
name|size_t
name|max_matches
parameter_list|,
name|VariableList
modifier|&
name|variable_list
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Find global and static variables by regular exression.
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
parameter_list|(
specifier|const
name|RegularExpression
modifier|&
name|regex
parameter_list|,
name|bool
name|append
parameter_list|,
name|size_t
name|max_matches
parameter_list|,
name|VariableList
modifier|&
name|variable_list
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Find types by name.
comment|///
comment|/// Type lookups in modules go through the SymbolVendor (which will
comment|/// use one or more SymbolFile subclasses). The SymbolFile needs to
comment|/// be able to lookup types by basename and not the fully qualified
comment|/// typename. This allows the type accelerator tables to stay small,
comment|/// even with heavily templatized C++. The type search will then
comment|/// narrow down the search results. If "exact_match" is true, then
comment|/// the type search will only match exact type name matches. If
comment|/// "exact_match" is false, the type will match as long as the base
comment|/// typename matches and as long as any immediate containing
comment|/// namespaces/class scopes that are specified match. So to search
comment|/// for a type "d" in "b::c", the name "b::c::d" can be specified
comment|/// and it will match any class/namespace "b" which contains a
comment|/// class/namespace "c" which contains type "d". We do this to
comment|/// allow users to not always have to specify complete scoping on
comment|/// all expressions, but it also allows for exact matching when
comment|/// required.
comment|///
comment|/// @param[in] sc
comment|///     A symbol context that scopes where to extract a type list
comment|///     from.
comment|///
comment|/// @param[in] type_name
comment|///     The name of the type we are looking for that is a fully
comment|///     or partially qualfieid type name.
comment|///
comment|/// @param[in] exact_match
comment|///     If \b true, \a type_name is fully qualifed and must match
comment|///     exactly. If \b false, \a type_name is a partially qualfied
comment|///     name where the leading namespaces or classes can be
comment|///     omitted to make finding types that a user may type
comment|///     easier.
comment|///
comment|/// @param[out] type_list
comment|///     A type list gets populated with any matches.
comment|///
comment|/// @return
comment|///     The number of matches added to \a type_list.
comment|//------------------------------------------------------------------
name|size_t
name|FindTypes
parameter_list|(
specifier|const
name|SymbolContext
modifier|&
name|sc
parameter_list|,
specifier|const
name|ConstString
modifier|&
name|type_name
parameter_list|,
name|bool
name|exact_match
parameter_list|,
name|size_t
name|max_matches
parameter_list|,
name|TypeList
modifier|&
name|types
parameter_list|)
function_decl|;
name|lldb
operator|::
name|TypeSP
name|FindFirstType
argument_list|(
argument|const SymbolContext& sc
argument_list|,
argument|const ConstString&type_name
argument_list|,
argument|bool exact_match
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find types by name that are in a namespace. This function is
comment|/// used by the expression parser when searches need to happen in
comment|/// an exact namespace scope.
comment|///
comment|/// @param[in] sc
comment|///     A symbol context that scopes where to extract a type list
comment|///     from.
comment|///
comment|/// @param[in] type_name
comment|///     The name of a type within a namespace that should not include
comment|///     any qualifying namespaces (just a type basename).
comment|///
comment|/// @param[in] namespace_decl
comment|///     The namespace declaration that this type must exist in.
comment|///
comment|/// @param[out] type_list
comment|///     A type list gets populated with any matches.
comment|///
comment|/// @return
comment|///     The number of matches added to \a type_list.
comment|//------------------------------------------------------------------
name|size_t
name|FindTypesInNamespace
parameter_list|(
specifier|const
name|SymbolContext
modifier|&
name|sc
parameter_list|,
specifier|const
name|ConstString
modifier|&
name|type_name
parameter_list|,
specifier|const
name|ClangNamespaceDecl
modifier|*
name|namespace_decl
parameter_list|,
name|size_t
name|max_matches
parameter_list|,
name|TypeList
modifier|&
name|type_list
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get const accessor for the module architecture.
comment|///
comment|/// @return
comment|///     A const reference to the architecture object.
comment|//------------------------------------------------------------------
specifier|const
name|ArchSpec
operator|&
name|GetArchitecture
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get const accessor for the module file specification.
comment|///
comment|/// This function returns the file for the module on the host system
comment|/// that is running LLDB. This can differ from the path on the
comment|/// platform since we might be doing remote debugging.
comment|///
comment|/// @return
comment|///     A const reference to the file specification object.
comment|//------------------------------------------------------------------
specifier|const
name|FileSpec
operator|&
name|GetFileSpec
argument_list|()
specifier|const
block|{
return|return
name|m_file
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get accessor for the module platform file specification.
comment|///
comment|/// Platform file refers to the path of the module as it is known on
comment|/// the remote system on which it is being debugged. For local
comment|/// debugging this is always the same as Module::GetFileSpec(). But
comment|/// remote debugging might mention a file "/usr/lib/liba.dylib"
comment|/// which might be locally downloaded and cached. In this case the
comment|/// platform file could be something like:
comment|/// "/tmp/lldb/platform-cache/remote.host.computer/usr/lib/liba.dylib"
comment|/// The file could also be cached in a local developer kit directory.
comment|///
comment|/// @return
comment|///     A const reference to the file specification object.
comment|//------------------------------------------------------------------
specifier|const
name|FileSpec
operator|&
name|GetPlatformFileSpec
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_platform_file
condition|)
return|return
name|m_platform_file
return|;
return|return
name|m_file
return|;
block|}
name|void
name|SetPlatformFileSpec
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|file
parameter_list|)
block|{
name|m_platform_file
operator|=
name|file
expr_stmt|;
block|}
specifier|const
name|FileSpec
operator|&
name|GetRemoteInstallFileSpec
argument_list|()
specifier|const
block|{
return|return
name|m_remote_install_file
return|;
block|}
name|void
name|SetRemoteInstallFileSpec
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|file
parameter_list|)
block|{
name|m_remote_install_file
operator|=
name|file
expr_stmt|;
block|}
specifier|const
name|FileSpec
operator|&
name|GetSymbolFileFileSpec
argument_list|()
specifier|const
block|{
return|return
name|m_symfile_spec
return|;
block|}
name|void
name|SetSymbolFileFileSpec
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|file
parameter_list|)
function_decl|;
specifier|const
name|TimeValue
operator|&
name|GetModificationTime
argument_list|()
specifier|const
block|{
return|return
name|m_mod_time
return|;
block|}
specifier|const
name|TimeValue
operator|&
name|GetObjectModificationTime
argument_list|()
specifier|const
block|{
return|return
name|m_object_mod_time
return|;
block|}
name|void
name|SetObjectModificationTime
parameter_list|(
specifier|const
name|TimeValue
modifier|&
name|mod_time
parameter_list|)
block|{
name|m_mod_time
operator|=
name|mod_time
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Tells whether this module is capable of being the main executable
comment|/// for a process.
comment|///
comment|/// @return
comment|///     \b true if it is, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsExecutable
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Tells whether this module has been loaded in the target passed in.
comment|/// This call doesn't distinguish between whether the module is loaded
comment|/// by the dynamic loader, or by a "target module add" type call.
comment|///
comment|/// @param[in] target
comment|///    The target to check whether this is loaded in.
comment|///
comment|/// @return
comment|///     \b true if it is, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsLoadedInTarget
parameter_list|(
name|Target
modifier|*
name|target
parameter_list|)
function_decl|;
name|bool
name|LoadScriptingResourceInTarget
parameter_list|(
name|Target
modifier|*
name|target
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|,
name|Stream
modifier|*
name|feedback_stream
init|=
name|NULL
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the number of compile units for this module.
comment|///
comment|/// @return
comment|///     The number of compile units that the symbol vendor plug-in
comment|///     finds.
comment|//------------------------------------------------------------------
name|size_t
name|GetNumCompileUnits
parameter_list|()
function_decl|;
name|lldb
operator|::
name|CompUnitSP
name|GetCompileUnitAtIndex
argument_list|(
argument|size_t idx
argument_list|)
expr_stmt|;
specifier|const
name|ConstString
operator|&
name|GetObjectName
argument_list|()
specifier|const
expr_stmt|;
name|uint64_t
name|GetObjectOffset
argument_list|()
specifier|const
block|{
return|return
name|m_object_offset
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the object file representation for the current architecture.
comment|///
comment|/// If the object file has not been located or parsed yet, this
comment|/// function will find the best ObjectFile plug-in that can parse
comment|/// Module::m_file.
comment|///
comment|/// @return
comment|///     If Module::m_file does not exist, or no plug-in was found
comment|///     that can parse the file, or the object file doesn't contain
comment|///     the current architecture in Module::m_arch, NULL will be
comment|///     returned, else a valid object file interface will be
comment|///     returned. The returned pointer is owned by this object and
comment|///     remains valid as long as the object is around.
comment|//------------------------------------------------------------------
name|virtual
name|ObjectFile
modifier|*
name|GetObjectFile
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the unified section list for the module. This is the section
comment|/// list created by the module's object file and any debug info and
comment|/// symbol files created by the symbol vendor.
comment|///
comment|/// If the symbol vendor has not been loaded yet, this function
comment|/// will return the section list for the object file.
comment|///
comment|/// @return
comment|///     Unified module section list.
comment|//------------------------------------------------------------------
name|virtual
name|SectionList
modifier|*
name|GetSectionList
parameter_list|()
function_decl|;
name|uint32_t
name|GetVersion
parameter_list|(
name|uint32_t
modifier|*
name|versions
parameter_list|,
name|uint32_t
name|num_versions
parameter_list|)
function_decl|;
comment|// Load an object file from memory.
name|ObjectFile
modifier|*
name|GetMemoryObjectFile
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|,
name|lldb
operator|::
name|addr_t
name|header_addr
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the symbol vendor interface for the current architecture.
comment|///
comment|/// If the symbol vendor file has not been located yet, this
comment|/// function will find the best SymbolVendor plug-in that can
comment|/// use the current object file.
comment|///
comment|/// @return
comment|///     If this module does not have a valid object file, or no
comment|///     plug-in can be found that can use the object file, NULL will
comment|///     be returned, else a valid symbol vendor plug-in interface
comment|///     will be returned. The returned pointer is owned by this
comment|///     object and remains valid as long as the object is around.
comment|//------------------------------------------------------------------
name|virtual
name|SymbolVendor
modifier|*
name|GetSymbolVendor
argument_list|(
name|bool
name|can_create
operator|=
name|true
argument_list|,
name|lldb_private
operator|::
name|Stream
operator|*
name|feedback_strm
operator|=
name|NULL
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get accessor the type list for this module.
comment|///
comment|/// @return
comment|///     A valid type list pointer, or NULL if there is no valid
comment|///     symbol vendor for this module.
comment|//------------------------------------------------------------------
name|TypeList
modifier|*
name|GetTypeList
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get a pointer to the UUID value contained in this object.
comment|///
comment|/// If the executable image file doesn't not have a UUID value built
comment|/// into the file format, an MD5 checksum of the entire file, or
comment|/// slice of the file for the current architecture should be used.
comment|///
comment|/// @return
comment|///     A const pointer to the internal copy of the UUID value in
comment|///     this module if this module has a valid UUID value, NULL
comment|///     otherwise.
comment|//------------------------------------------------------------------
specifier|const
name|lldb_private
operator|::
name|UUID
operator|&
name|GetUUID
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// A debugging function that will cause everything in a module to
comment|/// be parsed.
comment|///
comment|/// All compile units will be pasred, along with all globals and
comment|/// static variables and all functions for those compile units.
comment|/// All types, scopes, local variables, static variables, global
comment|/// variables, and line tables will be parsed. This can be used
comment|/// prior to dumping a module to see a complete list of the
comment|/// resuling debug information that gets parsed, or as a debug
comment|/// function to ensure that the module can consume all of the
comment|/// debug data the symbol vendor provides.
comment|//------------------------------------------------------------------
name|void
name|ParseAllDebugSymbols
parameter_list|()
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
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Resolve the symbol context for the given address.
comment|///
comment|/// Tries to resolve the matching symbol context based on a lookup
comment|/// from the current symbol vendor.  If the lazy lookup fails,
comment|/// an attempt is made to parse the eh_frame section to handle
comment|/// stripped symbols.  If this fails, an attempt is made to resolve
comment|/// the symbol to the previous address to handle the case of a
comment|/// function with a tail call.
comment|///
comment|/// Use properties of the modified SymbolContext to inspect any
comment|/// resolved target, module, compilation unit, symbol, function,
comment|/// function block or line entry.  Use the return value to determine
comment|/// which of these properties have been modified.
comment|///
comment|/// @param[in] so_addr
comment|///     A load address to resolve.
comment|///
comment|/// @param[in] resolve_scope
comment|///     The scope that should be resolved (see SymbolContext::Scope).
comment|///     A combination of flags from the enumeration SymbolContextItem
comment|///     requesting a resolution depth.  Note that the flags that are
comment|///     actually resolved may be a superset of the requested flags.
comment|///     For instance, eSymbolContextSymbol requires resolution of
comment|///     eSymbolContextModule, and eSymbolContextFunction requires
comment|///     eSymbolContextSymbol.
comment|///
comment|/// @param[out] sc
comment|///     The SymbolContext that is modified based on symbol resolution.
comment|///
comment|/// @param[in] resolve_tail_call_address
comment|///     Determines if so_addr should resolve to a symbol in the case
comment|///     of a function whose last instruction is a call.  In this case,
comment|///     the PC can be one past the address range of the function.
comment|///
comment|/// @return
comment|///     The scope that has been resolved (see SymbolContext::Scope).
comment|///
comment|/// @see SymbolContext::Scope
comment|//------------------------------------------------------------------
name|uint32_t
name|ResolveSymbolContextForAddress
parameter_list|(
specifier|const
name|Address
modifier|&
name|so_addr
parameter_list|,
name|uint32_t
name|resolve_scope
parameter_list|,
name|SymbolContext
modifier|&
name|sc
parameter_list|,
name|bool
name|resolve_tail_call_address
init|=
name|false
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Resolve items in the symbol context for a given file and line.
comment|///
comment|/// Tries to resolve \a file_path and \a line to a list of matching
comment|/// symbol contexts.
comment|///
comment|/// The line table entries contains addresses that can be used to
comment|/// further resolve the values in each match: the function, block,
comment|/// symbol. Care should be taken to minimize the amount of
comment|/// information that is requested to only what is needed --
comment|/// typically the module, compile unit, line table and line table
comment|/// entry are sufficient.
comment|///
comment|/// @param[in] file_path
comment|///     A path to a source file to match. If \a file_path does not
comment|///     specify a directory, then this query will match all files
comment|///     whose base filename matches. If \a file_path does specify
comment|///     a directory, the fullpath to the file must match.
comment|///
comment|/// @param[in] line
comment|///     The source line to match, or zero if just the compile unit
comment|///     should be resolved.
comment|///
comment|/// @param[in] check_inlines
comment|///     Check for inline file and line number matches. This option
comment|///     should be used sparingly as it will cause all line tables
comment|///     for every compile unit to be parsed and searched for
comment|///     matching inline file entries.
comment|///
comment|/// @param[in] resolve_scope
comment|///     The scope that should be resolved (see
comment|///     SymbolContext::Scope).
comment|///
comment|/// @param[out] sc_list
comment|///     A symbol context list that gets matching symbols contexts
comment|///     appended to.
comment|///
comment|/// @return
comment|///     The number of matches that were added to \a sc_list.
comment|///
comment|/// @see SymbolContext::Scope
comment|//------------------------------------------------------------------
name|uint32_t
name|ResolveSymbolContextForFilePath
parameter_list|(
specifier|const
name|char
modifier|*
name|file_path
parameter_list|,
name|uint32_t
name|line
parameter_list|,
name|bool
name|check_inlines
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
comment|/// Resolve items in the symbol context for a given file and line.
comment|///
comment|/// Tries to resolve \a file_spec and \a line to a list of matching
comment|/// symbol contexts.
comment|///
comment|/// The line table entries contains addresses that can be used to
comment|/// further resolve the values in each match: the function, block,
comment|/// symbol. Care should be taken to minimize the amount of
comment|/// information that is requested to only what is needed --
comment|/// typically the module, compile unit, line table and line table
comment|/// entry are sufficient.
comment|///
comment|/// @param[in] file_spec
comment|///     A file spec to a source file to match. If \a file_path does
comment|///     not specify a directory, then this query will match all
comment|///     files whose base filename matches. If \a file_path does
comment|///     specify a directory, the fullpath to the file must match.
comment|///
comment|/// @param[in] line
comment|///     The source line to match, or zero if just the compile unit
comment|///     should be resolved.
comment|///
comment|/// @param[in] check_inlines
comment|///     Check for inline file and line number matches. This option
comment|///     should be used sparingly as it will cause all line tables
comment|///     for every compile unit to be parsed and searched for
comment|///     matching inline file entries.
comment|///
comment|/// @param[in] resolve_scope
comment|///     The scope that should be resolved (see
comment|///     SymbolContext::Scope).
comment|///
comment|/// @param[out] sc_list
comment|///     A symbol context list that gets filled in with all of the
comment|///     matches.
comment|///
comment|/// @return
comment|///     A integer that contains SymbolContext::Scope bits set for
comment|///     each item that was successfully resolved.
comment|///
comment|/// @see SymbolContext::Scope
comment|//------------------------------------------------------------------
name|uint32_t
name|ResolveSymbolContextsForFileSpec
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
name|uint32_t
name|resolve_scope
parameter_list|,
name|SymbolContextList
modifier|&
name|sc_list
parameter_list|)
function_decl|;
name|void
name|SetFileSpecAndObjectName
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|file
parameter_list|,
specifier|const
name|ConstString
modifier|&
name|object_name
parameter_list|)
function_decl|;
name|bool
name|GetIsDynamicLinkEditor
argument_list|()
specifier|const
block|{
return|return
name|m_is_dynamic_loader_module
return|;
block|}
name|void
name|SetIsDynamicLinkEditor
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_is_dynamic_loader_module
operator|=
name|b
expr_stmt|;
block|}
name|ClangASTContext
modifier|&
name|GetClangASTContext
parameter_list|()
function_decl|;
comment|// Special error functions that can do printf style formatting that will prepend the message with
comment|// something appropriate for this module (like the architecture, path and object name (if any)).
comment|// This centralizes code so that everyone doesn't need to format their error and log messages on
comment|// their own and keeps the output a bit more consistent.
name|void
name|LogMessage
parameter_list|(
name|Log
modifier|*
name|log
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
block|)
decl_stmt|)
end_decl_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|LogMessageVerboseBacktrace
parameter_list|(
name|Log
modifier|*
name|log
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|ReportWarning
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|ReportError
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Only report an error once when the module is first detected to be modified
end_comment

begin_comment
comment|// so we don't spam the console with many messages.
end_comment

begin_function_decl
name|void
name|ReportErrorIfModifyDetected
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Return true if the file backing this module has changed since the
end_comment

begin_comment
comment|// module was originally created  since we saved the intial file
end_comment

begin_comment
comment|// modification time when the module first gets created.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|bool
name|FileHasChanged
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// SymbolVendor, SymbolFile and ObjectFile member objects should
end_comment

begin_comment
comment|// lock the module mutex to avoid deadlocks.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|Mutex
operator|&
name|GetMutex
argument_list|()
specifier|const
block|{
return|return
name|m_mutex
return|;
block|}
end_expr_stmt

begin_function
name|PathMappingList
modifier|&
name|GetSourceMappingList
parameter_list|()
block|{
return|return
name|m_source_mappings
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|PathMappingList
operator|&
name|GetSourceMappingList
argument_list|()
specifier|const
block|{
return|return
name|m_source_mappings
return|;
block|}
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Finds a source file given a file spec using the module source
end_comment

begin_comment
comment|/// path remappings (if any).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Tries to resolve \a orig_spec by checking the module source path
end_comment

begin_comment
comment|/// remappings. It makes sure the file exists, so this call can be
end_comment

begin_comment
comment|/// expensive if the remappings are on a network file system, so
end_comment

begin_comment
comment|/// use this function sparingly (not in a tight debug info parsing
end_comment

begin_comment
comment|/// loop).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] orig_spec
end_comment

begin_comment
comment|///     The original source file path to try and remap.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[out] new_spec
end_comment

begin_comment
comment|///     The newly remapped filespec that is guaranteed to exist.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     /b true if \a orig_spec was successfully located and
end_comment

begin_comment
comment|///     \a new_spec is filled in with an existing file spec,
end_comment

begin_comment
comment|///     \b false otherwise.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Remaps a source file given \a path into \a new_path.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Remaps \a path if any source remappings match. This function
end_comment

begin_comment
comment|/// does NOT stat the file system so it can be used in tight loops
end_comment

begin_comment
comment|/// where debug info is being parsed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] path
end_comment

begin_comment
comment|///     The original source file path to try and remap.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[out] new_path
end_comment

begin_comment
comment|///     The newly remapped filespec that is may or may not exist.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     /b true if \a path was successfully located and \a new_path
end_comment

begin_comment
comment|///     is filled in with a new source path, \b false otherwise.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
name|bool
name|RemapSourceFile
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
name|std
operator|::
name|string
operator|&
name|new_path
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Prepare to do a function name lookup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Looking up functions by name can be a tricky thing. LLDB requires
end_comment

begin_comment
comment|/// that accelerator tables contain full names for functions as well
end_comment

begin_comment
comment|/// as function basenames which include functions, class methods and
end_comment

begin_comment
comment|/// class functions. When the user requests that an action use a
end_comment

begin_comment
comment|/// function by name, we are sometimes asked to automatically figure
end_comment

begin_comment
comment|/// out what a name could possibly map to. A user might request a
end_comment

begin_comment
comment|/// breakpoint be set on "count". If no options are supplied to limit
end_comment

begin_comment
comment|/// the scope of where to search for count, we will by default match
end_comment

begin_comment
comment|/// any function names named "count", all class and instance methods
end_comment

begin_comment
comment|/// named "count" (no matter what the namespace or contained context)
end_comment

begin_comment
comment|/// and any selectors named "count". If a user specifies "a::b" we
end_comment

begin_comment
comment|/// will search for the basename "b", and then prune the results that
end_comment

begin_comment
comment|/// don't match "a::b" (note that "c::a::b" and "d::e::a::b" will
end_comment

begin_comment
comment|/// match a query of "a::b".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] name
end_comment

begin_comment
comment|///     The user supplied name to use in the lookup
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] name_type_mask
end_comment

begin_comment
comment|///     The mask of bits from lldb::FunctionNameType enumerations
end_comment

begin_comment
comment|///     that tell us what kind of name we are looking for.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[out] lookup_name
end_comment

begin_comment
comment|///     The actual name that will be used when calling
end_comment

begin_comment
comment|///     SymbolVendor::FindFunctions() or Symtab::FindFunctionSymbols()
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[out] lookup_name_type_mask
end_comment

begin_comment
comment|///     The actual name mask that should be used in the calls to
end_comment

begin_comment
comment|///     SymbolVendor::FindFunctions() or Symtab::FindFunctionSymbols()
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[out] match_name_after_lookup
end_comment

begin_comment
comment|///     A boolean that indicates if we need to iterate through any
end_comment

begin_comment
comment|///     match results obtained from SymbolVendor::FindFunctions() or
end_comment

begin_comment
comment|///     Symtab::FindFunctionSymbols() to see if the name contains
end_comment

begin_comment
comment|///     \a name. For example if \a name is "a::b", this function will
end_comment

begin_comment
comment|///     return a \a lookup_name of "b", with \a match_name_after_lookup
end_comment

begin_comment
comment|///     set to true to indicate any matches will need to be checked
end_comment

begin_comment
comment|///     to make sure they contain \a name.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
specifier|static
name|void
name|PrepareForFunctionNameLookup
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|name
parameter_list|,
name|uint32_t
name|name_type_mask
parameter_list|,
name|ConstString
modifier|&
name|lookup_name
parameter_list|,
name|uint32_t
modifier|&
name|lookup_name_type_mask
parameter_list|,
name|bool
modifier|&
name|match_name_after_lookup
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Member Variables
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
name|mutable
name|Mutex
name|m_mutex
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< A mutex to keep this object happy in multi-threaded environments.
end_comment

begin_decl_stmt
name|TimeValue
name|m_mod_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The modification time for this module when it was created.
end_comment

begin_decl_stmt
name|ArchSpec
name|m_arch
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The architecture for this module.
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|UUID
name|m_uuid
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< Each module is assumed to have a unique identifier to help match it up to debug symbols.
end_comment

begin_decl_stmt
name|FileSpec
name|m_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The file representation on disk for this module (if there is one).
end_comment

begin_decl_stmt
name|FileSpec
name|m_platform_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The path to the module on the platform on which it is being debugged
end_comment

begin_decl_stmt
name|FileSpec
name|m_remote_install_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< If set when debugging on remote platforms, this module will be installed at this location
end_comment

begin_decl_stmt
name|FileSpec
name|m_symfile_spec
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< If this path is valid, then this is the file that _will_ be used as the symbol file for this module
end_comment

begin_decl_stmt
name|ConstString
name|m_object_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The name an object within this module that is selected, or empty of the module is represented by \a m_file.
end_comment

begin_decl_stmt
name|uint64_t
name|m_object_offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TimeValue
name|m_object_mod_time
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|ObjectFileSP
name|m_objfile_sp
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< A shared pointer to the object file parser for this module as it may or may not be shared with the SymbolFile
end_comment

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|SymbolVendor
operator|>
name|m_symfile_ap
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< A pointer to the symbol vendor for this module.
end_comment

begin_decl_stmt
name|ClangASTContext
name|m_ast
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The AST context for this module.
end_comment

begin_decl_stmt
name|PathMappingList
name|m_source_mappings
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< Module specific source remappings for when you have debug info for a module that doesn't match where the sources currently are
end_comment

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|SectionList
operator|>
name|m_sections_ap
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< Unified section list for module that is used by the ObjectFile and and ObjectFile instances for the debug info
end_comment

begin_decl_stmt
name|bool
name|m_did_load_objfile
range|:
literal|1
decl_stmt|,
name|m_did_load_symbol_vendor
range|:
literal|1
decl_stmt|,
name|m_did_parse_uuid
range|:
literal|1
decl_stmt|,
name|m_did_init_ast
range|:
literal|1
decl_stmt|,
name|m_is_dynamic_loader_module
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mutable
name|bool
name|m_file_has_changed
range|:
literal|1
decl_stmt|,
name|m_first_file_changed_log
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// See if the module was modified after it was initially opened.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Resolve a file or load virtual address.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Tries to resolve \a vm_addr as a file address (if \a
end_comment

begin_comment
comment|/// vm_addr_is_file_addr is true) or as a load address if \a
end_comment

begin_comment
comment|/// vm_addr_is_file_addr is false) in the symbol vendor.
end_comment

begin_comment
comment|/// \a resolve_scope indicates what clients wish to resolve
end_comment

begin_comment
comment|/// and can be used to limit the scope of what is parsed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] vm_addr
end_comment

begin_comment
comment|///     The load virtual address to resolve.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] vm_addr_is_file_addr
end_comment

begin_comment
comment|///     If \b true, \a vm_addr is a file address, else \a vm_addr
end_comment

begin_comment
comment|///     if a load address.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] resolve_scope
end_comment

begin_comment
comment|///     The scope that should be resolved (see
end_comment

begin_comment
comment|///     SymbolContext::Scope).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[out] so_addr
end_comment

begin_comment
comment|///     The section offset based address that got resolved if
end_comment

begin_comment
comment|///     any bits are returned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[out] sc
end_comment

begin_comment
comment|//      The symbol context that has objects filled in. Each bit
end_comment

begin_comment
comment|///     in the \a resolve_scope pertains to a member in the \a sc.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A integer that contains SymbolContext::Scope bits set for
end_comment

begin_comment
comment|///     each item that was successfully resolved.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @see SymbolContext::Scope
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
name|uint32_t
name|ResolveSymbolContextForAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|vm_addr
argument_list|,
name|bool
name|vm_addr_is_file_addr
argument_list|,
name|uint32_t
name|resolve_scope
argument_list|,
name|Address
operator|&
name|so_addr
argument_list|,
name|SymbolContext
operator|&
name|sc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|SymbolIndicesToSymbolContextList
argument_list|(
name|Symtab
operator|*
name|symtab
argument_list|,
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
operator|&
name|symbol_indexes
argument_list|,
name|SymbolContextList
operator|&
name|sc_list
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|SetArchitecture
parameter_list|(
specifier|const
name|ArchSpec
modifier|&
name|new_arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SectionList
modifier|*
name|GetUnifiedSectionList
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|friend
name|class
name|ModuleList
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ObjectFile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SymbolFile
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_function_decl
name|size_t
name|FindTypes_Impl
parameter_list|(
specifier|const
name|SymbolContext
modifier|&
name|sc
parameter_list|,
specifier|const
name|ConstString
modifier|&
name|name
parameter_list|,
specifier|const
name|ClangNamespaceDecl
modifier|*
name|namespace_decl
parameter_list|,
name|bool
name|append
parameter_list|,
name|size_t
name|max_matches
parameter_list|,
name|TypeList
modifier|&
name|types
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Module
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Module_h_
end_comment

end_unit

