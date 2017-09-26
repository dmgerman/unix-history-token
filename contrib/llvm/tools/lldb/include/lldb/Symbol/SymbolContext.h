begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SymbolContext.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_SymbolContext_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_SymbolContext_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<memory>
end_include

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

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Mangled.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/LineEntry.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Iterable.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SymbolContextScope
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class SymbolContext SymbolContext.h "lldb/Symbol/SymbolContext.h"
comment|/// @brief Defines a symbol context baton that can be handed other debug
comment|/// core functions.
comment|///
comment|/// Many debugger functions require a context when doing lookups. This
comment|/// class provides a common structure that can be used as the result
comment|/// of a query that can contain a single result. Examples of such
comment|/// queries include
comment|///     @li Looking up a load address.
comment|//----------------------------------------------------------------------
name|class
name|SymbolContext
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// Initialize all pointer members to nullptr and all struct members
comment|/// to their default state.
comment|//------------------------------------------------------------------
name|SymbolContext
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct with an object that knows how to reconstruct its
comment|/// symbol context.
comment|///
comment|/// @param[in] sc_scope
comment|///     A symbol context scope object that knows how to reconstruct
comment|///     it's context.
comment|//------------------------------------------------------------------
name|explicit
name|SymbolContext
parameter_list|(
name|SymbolContextScope
modifier|*
name|sc_scope
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Construct with module, and optional compile unit, function,
comment|/// block, line table, line entry and symbol.
comment|///
comment|/// Initialize all pointer to the specified values.
comment|///
comment|/// @param[in] module
comment|///     A Module pointer to the module for this context.
comment|///
comment|/// @param[in] comp_unit
comment|///     A CompileUnit pointer to the compile unit for this context.
comment|///
comment|/// @param[in] function
comment|///     A Function pointer to the function for this context.
comment|///
comment|/// @param[in] block
comment|///     A Block pointer to the deepest block for this context.
comment|///
comment|/// @param[in] line_entry
comment|///     A LineEntry pointer to the line entry for this context.
comment|///
comment|/// @param[in] symbol
comment|///     A Symbol pointer to the symbol for this context.
comment|//------------------------------------------------------------------
name|explicit
name|SymbolContext
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|,
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
name|CompileUnit
operator|*
name|comp_unit
operator|=
name|nullptr
argument_list|,
name|Function
operator|*
name|function
operator|=
name|nullptr
argument_list|,
name|Block
operator|*
name|block
operator|=
name|nullptr
argument_list|,
name|LineEntry
operator|*
name|line_entry
operator|=
name|nullptr
argument_list|,
name|Symbol
operator|*
name|symbol
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|// This version sets the target to a NULL TargetSP if you don't know it.
name|explicit
name|SymbolContext
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
name|CompileUnit
operator|*
name|comp_unit
operator|=
name|nullptr
argument_list|,
name|Function
operator|*
name|function
operator|=
name|nullptr
argument_list|,
name|Block
operator|*
name|block
operator|=
name|nullptr
argument_list|,
name|LineEntry
operator|*
name|line_entry
operator|=
name|nullptr
argument_list|,
name|Symbol
operator|*
name|symbol
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Copy constructor
comment|///
comment|/// Makes a copy of the another SymbolContext object \a rhs.
comment|///
comment|/// @param[in] rhs
comment|///     A const SymbolContext object reference to copy.
comment|//------------------------------------------------------------------
name|SymbolContext
argument_list|(
specifier|const
name|SymbolContext
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SymbolContext
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Assignment operator.
comment|///
comment|/// Copies the address value from another SymbolContext object \a
comment|/// rhs into \a this object.
comment|///
comment|/// @param[in] rhs
comment|///     A const SymbolContext object reference to copy.
comment|///
comment|/// @return
comment|///     A const SymbolContext object reference to \a this.
comment|//------------------------------------------------------------------
specifier|const
name|SymbolContext
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SymbolContext
operator|&
name|rhs
operator|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Clear the object's state.
comment|///
comment|/// Resets all pointer members to nullptr, and clears any class objects
comment|/// to their default state.
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|(
name|bool
name|clear_target
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Dump a description of this object to a Stream.
comment|///
comment|/// Dump a description of the contents of this object to the
comment|/// supplied stream \a s.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|//------------------------------------------------------------------
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|Target
operator|*
name|target
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Dump the stop context in this object to a Stream.
comment|///
comment|/// Dump the best description of this object to the stream. The
comment|/// information displayed depends on the amount and quality of the
comment|/// information in this context. If a module, function, file and
comment|/// line number are available, they will be dumped. If only a
comment|/// module and function or symbol name with offset is available,
comment|/// that will be output. Else just the address at which the target
comment|/// was stopped will be displayed.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|///
comment|/// @param[in] so_addr
comment|///     The resolved section offset address.
comment|///
comment|/// @param[in] show_fullpaths
comment|///     When printing file paths (with the Module), whether the
comment|///     base name of the Module should be printed or the full path.
comment|///
comment|/// @param[in] show_module
comment|///     Whether the module name should be printed followed by a
comment|///     grave accent "`" character.
comment|///
comment|/// @param[in] show_inlined_frames
comment|///     If a given pc is in inlined function(s), whether the inlined
comment|///     functions should be printed on separate lines in addition to
comment|///     the concrete function containing the pc.
comment|///
comment|/// @param[in] show_function_arguments
comment|///     If false, this method will try to elide the function argument
comment|///     types when printing the function name.  This may be ambiguous
comment|///     for languages that have function overloading - but it may
comment|///     make the "function name" too long to include all the argument
comment|///     types.
comment|///
comment|/// @param[in] show_function_name
comment|///     Normally this should be true - the function/symbol name should
comment|///     be printed.  In disassembly formatting, where we want a format
comment|///     like "<*+36>", this should be false and "*" will be printed
comment|///     instead.
comment|//------------------------------------------------------------------
name|bool
name|DumpStopContext
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|ExecutionContextScope
operator|*
name|exe_scope
argument_list|,
specifier|const
name|Address
operator|&
name|so_addr
argument_list|,
name|bool
name|show_fullpaths
argument_list|,
name|bool
name|show_module
argument_list|,
name|bool
name|show_inlined_frames
argument_list|,
name|bool
name|show_function_arguments
argument_list|,
name|bool
name|show_function_name
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the address range contained within a symbol context.
comment|///
comment|/// Address range priority is as follows:
comment|///     - line_entry address range if line_entry is valid and
comment|///     eSymbolContextLineEntry is set in \a scope
comment|///     - block address range if block is not nullptr and eSymbolContextBlock
comment|///     is set in \a scope
comment|///     - function address range if function is not nullptr and
comment|///     eSymbolContextFunction is set in \a scope
comment|///     - symbol address range if symbol is not nullptr and
comment|///     eSymbolContextSymbol is set in \a scope
comment|///
comment|/// @param[in] scope
comment|///     A mask of symbol context bits telling this function which
comment|///     address ranges it can use when trying to extract one from
comment|///     the valid (non-nullptr) symbol context classes.
comment|///
comment|/// @param[in] range_idx
comment|///     The address range index to grab. Since many functions and
comment|///     blocks are not always contiguous, they may have more than
comment|///     one address range.
comment|///
comment|/// @param[in] use_inline_block_range
comment|///     If \a scope has the eSymbolContextBlock bit set, and there
comment|///     is a valid block in the symbol context, return the block
comment|///     address range for the containing inline function block, not
comment|///     the deepest most block. This allows us to extract information
comment|///     for the address range of the inlined function block, not
comment|///     the deepest lexical block.
comment|///
comment|/// @param[out] range
comment|///     An address range object that will be filled in if \b true
comment|///     is returned.
comment|///
comment|/// @return
comment|///     \b True if this symbol context contains items that describe
comment|///     an address range, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|GetAddressRange
argument_list|(
name|uint32_t
name|scope
argument_list|,
name|uint32_t
name|range_idx
argument_list|,
name|bool
name|use_inline_block_range
argument_list|,
name|AddressRange
operator|&
name|range
argument_list|)
decl|const
decl_stmt|;
name|bool
name|GetAddressRangeFromHereToEndLine
parameter_list|(
name|uint32_t
name|end_line
parameter_list|,
name|AddressRange
modifier|&
name|range
parameter_list|,
name|Status
modifier|&
name|error
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Find the best global data symbol visible from this context.
comment|///
comment|/// Symbol priority is:
comment|///     - extern symbol in the current module if there is one
comment|///     - non-extern symbol in the current module if there is one
comment|///     - extern symbol in the target
comment|///     - non-extern symbol in the target
comment|/// It is an error if the highest-priority result is ambiguous.
comment|///
comment|/// @param[in] name
comment|///     The name of the symbol to search for.
comment|///
comment|/// @param[out] error
comment|///     An error that will be populated with a message if there was an
comment|///     ambiguous result.  The error will not be populated if no result
comment|///     was found.
comment|///
comment|/// @return
comment|///     The symbol that was found, or \b nullptr if none was found.
comment|//------------------------------------------------------------------
specifier|const
name|Symbol
modifier|*
name|FindBestGlobalDataSymbol
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|name
parameter_list|,
name|Status
modifier|&
name|error
parameter_list|)
function_decl|;
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
argument_list|,
name|Target
operator|*
name|target
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|GetResolvedMask
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|LanguageType
name|GetLanguage
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find a block that defines the function represented by this
comment|/// symbol context.
comment|///
comment|/// If this symbol context points to a block that is an inlined
comment|/// function, or is contained within an inlined function, the block
comment|/// that defines the inlined function is returned.
comment|///
comment|/// If this symbol context has no block in it, or the block is not
comment|/// itself an inlined function block or contained within one, we
comment|/// return the top level function block.
comment|///
comment|/// This is a handy function to call when you want to get the block
comment|/// whose variable list will include the arguments for the function
comment|/// that is represented by this symbol context (whether the function
comment|/// is an inline function or not).
comment|///
comment|/// @return
comment|///     The block object pointer that defines the function that is
comment|///     represented by this symbol context object, nullptr otherwise.
comment|//------------------------------------------------------------------
name|Block
modifier|*
name|GetFunctionBlock
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// If this symbol context represents a function that is a method,
comment|/// return true and provide information about the method.
comment|///
comment|/// @param[out] language
comment|///     If \b true is returned, the language for the method.
comment|///
comment|/// @param[out] is_instance_method
comment|///     If \b true is returned, \b true if this is a instance method,
comment|///     \b false if this is a static/class function.
comment|///
comment|/// @param[out] language_object_name
comment|///     If \b true is returned, the name of the artificial variable
comment|///     for the language ("this" for C++, "self" for ObjC).
comment|///
comment|/// @return
comment|///     \b True if this symbol context represents a function that
comment|///     is a method of a class, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|GetFunctionMethodInfo
argument_list|(
name|lldb
operator|::
name|LanguageType
operator|&
name|language
argument_list|,
name|bool
operator|&
name|is_instance_method
argument_list|,
name|ConstString
operator|&
name|language_object_name
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Sorts the types in TypeMap according to SymbolContext
comment|/// to TypeList
comment|///
comment|//------------------------------------------------------------------
name|void
name|SortTypeList
argument_list|(
name|TypeMap
operator|&
name|type_map
argument_list|,
name|TypeList
operator|&
name|type_list
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find a name of the innermost function for the symbol context.
comment|///
comment|/// For instance, if the symbol context contains an inlined block,
comment|/// it will return the inlined function name.
comment|///
comment|/// @param[in] prefer_mangled
comment|///    if \btrue, then the mangled name will be returned if there
comment|///    is one.  Otherwise the unmangled name will be returned if it
comment|///    is available.
comment|///
comment|/// @return
comment|///     The name of the function represented by this symbol context.
comment|//------------------------------------------------------------------
name|ConstString
name|GetFunctionName
argument_list|(
name|Mangled
operator|::
name|NamePreference
name|preference
operator|=
name|Mangled
operator|::
name|ePreferDemangled
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the line entry that corresponds to the function.
comment|///
comment|/// If the symbol context contains an inlined block, the line entry
comment|/// for the start address of the inlined function will be returned,
comment|/// otherwise the line entry for the start address of the function
comment|/// will be returned. This can be used after doing a
comment|/// Module::FindFunctions(...) or ModuleList::FindFunctions(...)
comment|/// call in order to get the correct line table information for
comment|/// the symbol context.
comment|/// it will return the inlined function name.
comment|///
comment|/// @param[in] prefer_mangled
comment|///    if \btrue, then the mangled name will be returned if there
comment|///    is one.  Otherwise the unmangled name will be returned if it
comment|///    is available.
comment|///
comment|/// @return
comment|///     The name of the function represented by this symbol context.
comment|//------------------------------------------------------------------
name|LineEntry
name|GetFunctionStartLineEntry
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find the block containing the inlined block that contains this block.
comment|///
comment|/// For instance, if the symbol context contains an inlined block,
comment|/// it will return the inlined function name.
comment|///
comment|/// @param[in] curr_frame_pc
comment|///    The address within the block of this object.
comment|///
comment|/// @param[out] next_frame_sc
comment|///     A new symbol context that does what the title says it does.
comment|///
comment|/// @param[out] next_frame_addr
comment|///     This is what you should report as the PC in \a next_frame_sc.
comment|///
comment|/// @return
comment|///     \b true if this SymbolContext specifies a block contained in an
comment|///     inlined block.  If this returns \b true, \a next_frame_sc and
comment|///     \a next_frame_addr will be filled in correctly.
comment|//------------------------------------------------------------------
name|bool
name|GetParentOfInlinedScope
argument_list|(
specifier|const
name|Address
operator|&
name|curr_frame_pc
argument_list|,
name|SymbolContext
operator|&
name|next_frame_sc
argument_list|,
name|Address
operator|&
name|inlined_frame_addr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|TargetSP
name|target_sp
expr_stmt|;
comment|///< The Target for a given query
name|lldb
operator|::
name|ModuleSP
name|module_sp
expr_stmt|;
comment|///< The Module for a given query
name|CompileUnit
modifier|*
name|comp_unit
decl_stmt|;
comment|///< The CompileUnit for a given query
name|Function
modifier|*
name|function
decl_stmt|;
comment|///< The Function for a given query
name|Block
modifier|*
name|block
decl_stmt|;
comment|///< The Block for a given query
name|LineEntry
name|line_entry
decl_stmt|;
comment|///< The LineEntry for a given query
name|Symbol
modifier|*
name|symbol
decl_stmt|;
comment|///< The Symbol for a given query
name|Variable
modifier|*
name|variable
decl_stmt|;
comment|///< The global variable matching the given query
block|}
empty_stmt|;
name|class
name|SymbolContextSpecifier
block|{
name|public
label|:
typedef|typedef
enum|enum
name|SpecificationType
block|{
name|eNothingSpecified
init|=
literal|0
block|,
name|eModuleSpecified
init|=
literal|1
operator|<<
literal|0
block|,
name|eFileSpecified
init|=
literal|1
operator|<<
literal|1
block|,
name|eLineStartSpecified
init|=
literal|1
operator|<<
literal|2
block|,
name|eLineEndSpecified
init|=
literal|1
operator|<<
literal|3
block|,
name|eFunctionSpecified
init|=
literal|1
operator|<<
literal|4
block|,
name|eClassOrNamespaceSpecified
init|=
literal|1
operator|<<
literal|5
block|,
name|eAddressRangeSpecified
init|=
literal|1
operator|<<
literal|6
block|}
name|SpecificationType
typedef|;
comment|// This one produces a specifier that matches everything...
name|SymbolContextSpecifier
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|)
expr_stmt|;
operator|~
name|SymbolContextSpecifier
argument_list|()
expr_stmt|;
name|bool
name|AddSpecification
parameter_list|(
specifier|const
name|char
modifier|*
name|spec_string
parameter_list|,
name|SpecificationType
name|type
parameter_list|)
function_decl|;
name|bool
name|AddLineSpecification
parameter_list|(
name|uint32_t
name|line_no
parameter_list|,
name|SpecificationType
name|type
parameter_list|)
function_decl|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|bool
name|SymbolContextMatches
parameter_list|(
name|SymbolContext
modifier|&
name|sc
parameter_list|)
function_decl|;
name|bool
name|AddressMatches
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|)
decl_stmt|;
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
name|private
label|:
name|lldb
operator|::
name|TargetSP
name|m_target_sp
expr_stmt|;
name|std
operator|::
name|string
name|m_module_spec
expr_stmt|;
name|lldb
operator|::
name|ModuleSP
name|m_module_sp
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|FileSpec
operator|>
name|m_file_spec_ap
expr_stmt|;
name|size_t
name|m_start_line
decl_stmt|;
name|size_t
name|m_end_line
decl_stmt|;
name|std
operator|::
name|string
name|m_function_spec
expr_stmt|;
name|std
operator|::
name|string
name|m_class_name
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|AddressRange
operator|>
name|m_address_range_ap
expr_stmt|;
name|uint32_t
name|m_type
decl_stmt|;
comment|// Or'ed bits from SpecificationType
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class SymbolContextList SymbolContext.h "lldb/Symbol/SymbolContext.h"
comment|/// @brief Defines a list of symbol context objects.
comment|///
comment|/// This class provides a common structure that can be used to contain
comment|/// the result of a query that can contain a multiple results. Examples
comment|/// of such queries include:
comment|///     @li Looking up a function by name.
comment|///     @li Finding all addresses for a specified file and line number.
comment|//----------------------------------------------------------------------
name|class
name|SymbolContextList
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// Initialize with an empty list.
comment|//------------------------------------------------------------------
name|SymbolContextList
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|//------------------------------------------------------------------
operator|~
name|SymbolContextList
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Append a new symbol context to the list.
comment|///
comment|/// @param[in] sc
comment|///     A symbol context to append to the list.
comment|//------------------------------------------------------------------
name|void
name|Append
parameter_list|(
specifier|const
name|SymbolContext
modifier|&
name|sc
parameter_list|)
function_decl|;
name|void
name|Append
parameter_list|(
specifier|const
name|SymbolContextList
modifier|&
name|sc_list
parameter_list|)
function_decl|;
name|bool
name|AppendIfUnique
parameter_list|(
specifier|const
name|SymbolContext
modifier|&
name|sc
parameter_list|,
name|bool
name|merge_symbol_into_function
parameter_list|)
function_decl|;
name|bool
name|MergeSymbolContextIntoFunctionContext
parameter_list|(
specifier|const
name|SymbolContext
modifier|&
name|symbol_sc
parameter_list|,
name|uint32_t
name|start_idx
init|=
literal|0
parameter_list|,
name|uint32_t
name|stop_idx
init|=
name|UINT32_MAX
parameter_list|)
function_decl|;
name|uint32_t
name|AppendIfUnique
parameter_list|(
specifier|const
name|SymbolContextList
modifier|&
name|sc_list
parameter_list|,
name|bool
name|merge_symbol_into_function
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Clear the object's state.
comment|///
comment|/// Clears the symbol context list.
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Dump a description of this object to a Stream.
comment|///
comment|/// Dump a description of the contents of each symbol context in
comment|/// the list to the supplied stream \a s.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|//------------------------------------------------------------------
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|Target
operator|*
name|target
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for a symbol context at index \a idx.
comment|///
comment|/// Dump a description of the contents of each symbol context in
comment|/// the list to the supplied stream \a s.
comment|///
comment|/// @param[in] idx
comment|///     The zero based index into the symbol context list.
comment|///
comment|/// @param[out] sc
comment|///     A reference to the symbol context to fill in.
comment|///
comment|/// @return
comment|///     Returns \b true if \a idx was a valid index into this
comment|///     symbol context list and \a sc was filled in, \b false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|bool
name|GetContextAtIndex
argument_list|(
name|size_t
name|idx
argument_list|,
name|SymbolContext
operator|&
name|sc
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Direct reference accessor for a symbol context at index \a idx.
comment|///
comment|/// The index \a idx must be a valid index, no error checking will
comment|/// be done to ensure that it is valid.
comment|///
comment|/// @param[in] idx
comment|///     The zero based index into the symbol context list.
comment|///
comment|/// @return
comment|///     A const reference to the symbol context to fill in.
comment|//------------------------------------------------------------------
name|SymbolContext
modifier|&
name|operator
function|[]
parameter_list|(
name|size_t
name|idx
parameter_list|)
block|{
return|return
name|m_symbol_contexts
index|[
name|idx
index|]
return|;
block|}
specifier|const
name|SymbolContext
modifier|&
name|operator
index|[]
argument_list|(
name|size_t
name|idx
argument_list|)
decl|const
block|{
return|return
name|m_symbol_contexts
index|[
name|idx
index|]
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get accessor for the last symbol context in the list.
comment|///
comment|/// @param[out] sc
comment|///     A reference to the symbol context to fill in.
comment|///
comment|/// @return
comment|///     Returns \b true if \a sc was filled in, \b false if the
comment|///     list is empty.
comment|//------------------------------------------------------------------
name|bool
name|GetLastContext
argument_list|(
name|SymbolContext
operator|&
name|sc
argument_list|)
decl|const
decl_stmt|;
name|bool
name|RemoveContextAtIndex
parameter_list|(
name|size_t
name|idx
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for a symbol context list size.
comment|///
comment|/// @return
comment|///     Returns the number of symbol context objects in the list.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetSize
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|NumLineEntriesWithLine
argument_list|(
name|uint32_t
name|line
argument_list|)
decl|const
decl_stmt|;
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
argument_list|,
name|Target
operator|*
name|target
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|SymbolContext
operator|>
name|collection
expr_stmt|;
comment|///< The collection type for the list.
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|collection
name|m_symbol_contexts
decl_stmt|;
comment|///< The list of symbol contexts.
name|public
label|:
typedef|typedef
name|AdaptedIterable
operator|<
name|collection
operator|,
name|SymbolContext
operator|,
name|vector_adapter
operator|>
name|SymbolContextIterable
expr_stmt|;
name|SymbolContextIterable
name|SymbolContexts
parameter_list|()
block|{
return|return
name|SymbolContextIterable
argument_list|(
name|m_symbol_contexts
argument_list|)
return|;
block|}
block|}
empty_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SymbolContext
operator|&
name|lhs
operator|,
specifier|const
name|SymbolContext
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SymbolContext
operator|&
name|lhs
operator|,
specifier|const
name|SymbolContext
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SymbolContextList
operator|&
name|lhs
operator|,
specifier|const
name|SymbolContextList
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SymbolContextList
operator|&
name|lhs
operator|,
specifier|const
name|SymbolContextList
operator|&
name|rhs
operator|)
expr_stmt|;
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
comment|// liblldb_SymbolContext_h_
end_comment

end_unit

