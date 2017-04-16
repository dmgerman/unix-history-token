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
file|"lldb/Core/Address.h"
end_include

begin_comment
comment|// for Address
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

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
file|"lldb/Symbol/SymbolContextScope.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/TypeSystem.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/PathMappingList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_comment
comment|// for ConstString
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

begin_include
include|#
directive|include
file|"lldb/Utility/UUID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for DISALLOW_COPY_AND_ASSIGN
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for LanguageType, SymbolType
end_comment

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

begin_comment
comment|// for addr_t, offset_t
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Chrono.h"
end_include

begin_include
include|#
directive|include
file|<atomic>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_comment
comment|// for enable_shared_from_this
end_comment

begin_include
include|#
directive|include
file|<mutex>
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
comment|// for uint32_t, uint64_t
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CompilerDeclContext
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
name|ObjectFile
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
name|SectionList
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
name|Symbol
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
name|SymbolVendor
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Symtab
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
name|TypeMap
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
name|std
operator|::
name|recursive_mutex
operator|&
name|GetAllocationModuleCollectionMutex
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct with file specification and architecture.
comment|///
comment|/// Clients that wish to share modules with other targets should
comment|/// use ModuleList::GetSharedModule().
comment|///
comment|/// @param[in] file_spec
comment|///     The file specification for the on disk representation of
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
argument|const FileSpec&file_spec
argument_list|,
argument|const ArchSpec&arch
argument_list|,
argument|const ConstString *object_name = nullptr
argument_list|,
argument|lldb::offset_t object_offset =
literal|0
argument_list|,
argument|const llvm::sys::TimePoint<>&object_mod_time = llvm::sys::TimePoint<>()
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
specifier|static
name|lldb
operator|::
name|ModuleSP
name|CreateJITModule
argument_list|(
specifier|const
name|lldb
operator|::
name|ObjectFileJITDelegateSP
operator|&
name|delegate_sp
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|//------------------------------------------------------------------
operator|~
name|Module
argument_list|()
name|override
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
comment|///     The stream to which to dump the object description.
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
name|void
name|DumpSymbolContext
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
name|override
decl_stmt|;
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
comment|///     nullptr otherwise.
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
comment|/// Find a function symbols in the object file's symbol table.
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
name|CompilerDeclContext
modifier|*
name|parent_decl_ctx
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
comment|//------------------------------------------------------------------
comment|/// Find global and static variables by name.
comment|///
comment|/// @param[in] name
comment|///     The name of the global or static variable we are looking
comment|///     for.
comment|///
comment|/// @param[in] parent_decl_ctx
comment|///     If valid, a decl context that results must exist within
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
name|CompilerDeclContext
modifier|*
name|parent_decl_ctx
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
comment|///     or partially qualified type name.
comment|///
comment|/// @param[in] exact_match
comment|///     If \b true, \a type_name is fully qualified and must match
comment|///     exactly. If \b false, \a type_name is a partially qualified
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
argument_list|(
specifier|const
name|SymbolContext
operator|&
name|sc
argument_list|,
specifier|const
name|ConstString
operator|&
name|type_name
argument_list|,
name|bool
name|exact_match
argument_list|,
name|size_t
name|max_matches
argument_list|,
name|llvm
operator|::
name|DenseSet
operator|<
name|lldb_private
operator|::
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
decl_stmt|;
name|lldb
operator|::
name|TypeSP
name|FindFirstType
argument_list|(
argument|const SymbolContext&sc
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
name|CompilerDeclContext
modifier|*
name|parent_decl_ctx
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
name|llvm
operator|::
name|sys
operator|::
name|TimePoint
operator|<
operator|>
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
name|llvm
operator|::
name|sys
operator|::
name|TimePoint
operator|<
operator|>
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
argument_list|(
specifier|const
name|llvm
operator|::
name|sys
operator|::
name|TimePoint
operator|<
operator|>
operator|&
name|mod_time
argument_list|)
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
name|nullptr
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
comment|///     the current architecture in Module::m_arch, nullptr will be
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
comment|//------------------------------------------------------------------
comment|/// Notify the module that the file addresses for the Sections have
comment|/// been updated.
comment|///
comment|/// If the Section file addresses for a module are updated, this
comment|/// method should be called.  Any parts of the module, object file,
comment|/// or symbol file that has cached those file addresses must invalidate
comment|/// or update its cache.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|SectionFileAddressesChanged
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
comment|//------------------------------------------------------------------
comment|/// Load an object file from memory.
comment|///
comment|/// If available, the size of the object file in memory may be
comment|/// passed to avoid additional round trips to process memory.
comment|/// If the size is not provided, a default value is used. This
comment|/// value should be large enough to enable the ObjectFile plugins
comment|/// to read the header of the object file without going back to the
comment|/// process.
comment|///
comment|/// @return
comment|///     The object file loaded from memory or nullptr, if the operation
comment|///     failed (see the `error` for more information in that case).
comment|//------------------------------------------------------------------
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
argument_list|,
name|size_t
name|size_to_read
operator|=
literal|512
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
comment|///     plug-in can be found that can use the object file, nullptr will
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
name|nullptr
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get accessor the type list for this module.
comment|///
comment|/// @return
comment|///     A valid type list pointer, or nullptr if there is no valid
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
comment|/// All compile units will be parsed, along with all globals and
comment|/// static variables and all functions for those compile units.
comment|/// All types, scopes, local variables, static variables, global
comment|/// variables, and line tables will be parsed. This can be used
comment|/// prior to dumping a module to see a complete list of the
comment|/// resulting debug information that gets parsed, or as a debug
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
parameter_list|()
function_decl|;
name|TypeSystem
modifier|*
name|GetTypeSystemForLanguage
argument_list|(
name|lldb
operator|::
name|LanguageType
name|language
argument_list|)
decl_stmt|;
comment|// Special error functions that can do printf style formatting that will
comment|// prepend the message with
comment|// something appropriate for this module (like the architecture, path and
comment|// object name (if any)).
comment|// This centralizes code so that everyone doesn't need to format their error
comment|// and log messages on
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
comment|// module was originally created  since we saved the initial file
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
name|std
operator|::
name|recursive_mutex
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
name|llvm
operator|::
name|StringRef
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

begin_decl_stmt
name|bool
name|RemapSourceFile
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|std
operator|::
name|string
operator|&
argument_list|)
decl|const
init|=
name|delete
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Loads this module to memory.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Loads the bits needed to create an executable image to the memory.
end_comment

begin_comment
comment|/// It is useful with bare-metal targets where target does not have the
end_comment

begin_comment
comment|/// ability to start a process itself.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] target
end_comment

begin_comment
comment|///     Target where to load the module.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|Error
name|LoadInMemory
parameter_list|(
name|Target
modifier|&
name|target
parameter_list|,
name|bool
name|set_pc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// @class LookupInfo Module.h "lldb/Core/Module.h"
end_comment

begin_comment
comment|/// @brief A class that encapsulates name lookup information.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Users can type a wide variety of partial names when setting
end_comment

begin_comment
comment|/// breakpoints by name or when looking for functions by name.
end_comment

begin_comment
comment|/// SymbolVendor and SymbolFile objects are only required to implement
end_comment

begin_comment
comment|/// name lookup for function basenames and for fully mangled names.
end_comment

begin_comment
comment|/// This means if the user types in a partial name, we must reduce this
end_comment

begin_comment
comment|/// to a name lookup that will work with all SymbolFile objects. So we
end_comment

begin_comment
comment|/// might reduce a name lookup to look for a basename, and then prune
end_comment

begin_comment
comment|/// out any results that don't match.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The "m_name" member variable represents the name as it was typed
end_comment

begin_comment
comment|/// by the user. "m_lookup_name" will be the name we actually search
end_comment

begin_comment
comment|/// for through the symbol or objects files. Lanaguage is included in
end_comment

begin_comment
comment|/// case we need to filter results by language at a later date. The
end_comment

begin_comment
comment|/// "m_name_type_mask" member variable tells us what kinds of names we
end_comment

begin_comment
comment|/// are looking for and can help us prune out unwanted results.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Function lookups are done in Module.cpp, ModuleList.cpp and in
end_comment

begin_comment
comment|/// BreakpointResolverName.cpp and they all now use this class to do
end_comment

begin_comment
comment|/// lookups correctly.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|LookupInfo
block|{
name|public
label|:
name|LookupInfo
argument_list|()
operator|:
name|m_name
argument_list|()
operator|,
name|m_lookup_name
argument_list|()
operator|,
name|m_language
argument_list|(
name|lldb
operator|::
name|eLanguageTypeUnknown
argument_list|)
operator|,
name|m_name_type_mask
argument_list|(
literal|0
argument_list|)
operator|,
name|m_match_name_after_lookup
argument_list|(
argument|false
argument_list|)
block|{}
name|LookupInfo
argument_list|(
argument|const ConstString&name
argument_list|,
argument|uint32_t name_type_mask
argument_list|,
argument|lldb::LanguageType language
argument_list|)
expr_stmt|;
specifier|const
name|ConstString
operator|&
name|GetName
argument_list|()
specifier|const
block|{
return|return
name|m_name
return|;
block|}
name|void
name|SetName
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|name
parameter_list|)
block|{
name|m_name
operator|=
name|name
expr_stmt|;
block|}
specifier|const
name|ConstString
operator|&
name|GetLookupName
argument_list|()
specifier|const
block|{
return|return
name|m_lookup_name
return|;
block|}
name|void
name|SetLookupName
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|name
parameter_list|)
block|{
name|m_lookup_name
operator|=
name|name
expr_stmt|;
block|}
name|uint32_t
name|GetNameTypeMask
argument_list|()
specifier|const
block|{
return|return
name|m_name_type_mask
return|;
block|}
name|void
name|SetNameTypeMask
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
block|{
name|m_name_type_mask
operator|=
name|mask
expr_stmt|;
block|}
name|void
name|Prune
argument_list|(
name|SymbolContextList
operator|&
name|sc_list
argument_list|,
name|size_t
name|start_idx
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
name|ConstString
name|m_name
decl_stmt|;
comment|///< What the user originally typed
name|ConstString
name|m_lookup_name
decl_stmt|;
comment|///< The actual name will lookup when calling in
comment|///the object or symbol file
name|lldb
operator|::
name|LanguageType
name|m_language
expr_stmt|;
comment|///< Limit matches to only be for this language
name|uint32_t
name|m_name_type_mask
decl_stmt|;
comment|///< One or more bits from lldb::FunctionNameType
comment|///that indicate what kind of names we are
comment|///looking for
name|bool
name|m_match_name_after_lookup
decl_stmt|;
comment|///< If \b true, then demangled names that
comment|///match will need to contain "m_name" in
comment|///order to be considered a match
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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

begin_expr_stmt
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_mutex
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< A mutex to keep this object happy
end_comment

begin_comment
comment|///in multi-threaded environments.
end_comment

begin_comment
comment|/// The modification time for this module when it was created.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|sys
operator|::
name|TimePoint
operator|<
operator|>
name|m_mod_time
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|ArchSpec
name|m_arch
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The architecture for this module.
end_comment

begin_decl_stmt
name|UUID
name|m_uuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< Each module is assumed to have a unique identifier to help
end_comment

begin_comment
comment|///match it up to debug symbols.
end_comment

begin_decl_stmt
name|FileSpec
name|m_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The file representation on disk for this module (if
end_comment

begin_comment
comment|///there is one).
end_comment

begin_decl_stmt
name|FileSpec
name|m_platform_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The path to the module on the platform on which
end_comment

begin_comment
comment|///it is being debugged
end_comment

begin_decl_stmt
name|FileSpec
name|m_remote_install_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< If set when debugging on remote
end_comment

begin_comment
comment|///platforms, this module will be installed at
end_comment

begin_comment
comment|///this location
end_comment

begin_decl_stmt
name|FileSpec
name|m_symfile_spec
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< If this path is valid, then this is the file
end_comment

begin_comment
comment|///that _will_ be used as the symbol file for this
end_comment

begin_comment
comment|///module
end_comment

begin_decl_stmt
name|ConstString
name|m_object_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The name an object within this module that is
end_comment

begin_comment
comment|///selected, or empty of the module is represented
end_comment

begin_comment
comment|///by \a m_file.
end_comment

begin_decl_stmt
name|uint64_t
name|m_object_offset
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|sys
operator|::
name|TimePoint
operator|<
operator|>
name|m_object_mod_time
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|ObjectFileSP
name|m_objfile_sp
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< A shared pointer to the object file
end_comment

begin_comment
comment|///parser for this module as it may or may
end_comment

begin_comment
comment|///not be shared with the SymbolFile
end_comment

begin_expr_stmt
name|lldb
operator|::
name|SymbolVendorUP
name|m_symfile_ap
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< A pointer to the symbol vendor for this module.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|SymbolVendorUP
operator|>
name|m_old_symfiles
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< If anyone calls Module::SetSymbolFileFileSpec() and
end_comment

begin_comment
comment|///changes the symbol file,
end_comment

begin_comment
comment|///< we need to keep all old symbol files around in case anyone has type
end_comment

begin_comment
comment|///references to them
end_comment

begin_decl_stmt
name|TypeSystemMap
name|m_type_system_map
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< A map of any type systems associated
end_comment

begin_comment
comment|///with this module
end_comment

begin_decl_stmt
name|PathMappingList
name|m_source_mappings
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< Module specific source remappings for
end_comment

begin_comment
comment|///when you have debug info for a module
end_comment

begin_comment
comment|///that doesn't match where the sources
end_comment

begin_comment
comment|///currently are
end_comment

begin_expr_stmt
name|lldb
operator|::
name|SectionListUP
name|m_sections_ap
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< Unified section list for module that
end_comment

begin_comment
comment|///is used by the ObjectFile and and
end_comment

begin_comment
comment|///ObjectFile instances for the debug info
end_comment

begin_expr_stmt
name|std
operator|::
name|atomic
operator|<
name|bool
operator|>
name|m_did_load_objfile
block|{
name|false
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|atomic
operator|<
name|bool
operator|>
name|m_did_load_symbol_vendor
block|{
name|false
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|atomic
operator|<
name|bool
operator|>
name|m_did_parse_uuid
block|{
name|false
block|}
expr_stmt|;
end_expr_stmt

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
comment|/// See if the module was modified after it
end_comment

begin_comment
comment|/// was initially opened.
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

begin_expr_stmt
name|Module
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Only used internally by CreateJITModule ()
end_comment

begin_decl_stmt
name|size_t
name|FindTypes_Impl
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
specifier|const
name|CompilerDeclContext
operator|*
name|parent_decl_ctx
argument_list|,
name|bool
name|append
argument_list|,
name|size_t
name|max_matches
argument_list|,
name|llvm
operator|::
name|DenseSet
operator|<
name|lldb_private
operator|::
name|SymbolFile
operator|*
operator|>
operator|&
name|searched_symbol_files
argument_list|,
name|TypeMap
operator|&
name|types
argument_list|)
decl_stmt|;
end_decl_stmt

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

