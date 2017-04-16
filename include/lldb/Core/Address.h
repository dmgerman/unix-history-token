begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Address.h -----------------------------------------------*- C++ -*-===//
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
name|liblldb_Address_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Address_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for LLDB_INVALID_ADDRESS
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for AddressClass::eAddressClassInvalid
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for SectionWP, SectionSP, ModuleSP
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_comment
comment|// for addr_t
end_comment

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
comment|// for uint32_t, UINT32_MAX, int64_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Block
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CompileUnit
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ExecutionContextScope
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
name|Target
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
struct_decl|struct
name|LineEntry
struct_decl|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Address Address.h "lldb/Core/Address.h"
comment|/// @brief A section + offset based address class.
comment|///
comment|/// The Address class allows addresses to be relative to a section
comment|/// that can move during runtime due to images (executables, shared
comment|/// libraries, bundles, frameworks) being loaded at different
comment|/// addresses than the addresses found in the object file that
comment|/// represents them on disk. There are currently two types of addresses
comment|/// for a section:
comment|///     @li file addresses
comment|///     @li load addresses
comment|///
comment|/// File addresses represent the virtual addresses that are in the "on
comment|/// disk" object files. These virtual addresses are converted to be
comment|/// relative to unique sections scoped to the object file so that
comment|/// when/if the addresses slide when the images are loaded/unloaded
comment|/// in memory, we can easily track these changes without having to
comment|/// update every object (compile unit ranges, line tables, function
comment|/// address ranges, lexical block and inlined subroutine address
comment|/// ranges, global and static variables) each time an image is loaded or
comment|/// unloaded.
comment|///
comment|/// Load addresses represent the virtual addresses where each section
comment|/// ends up getting loaded at runtime. Before executing a program, it
comment|/// is common for all of the load addresses to be unresolved. When a
comment|/// DynamicLoader plug-in receives notification that shared libraries
comment|/// have been loaded/unloaded, the load addresses of the main executable
comment|/// and any images (shared libraries) will be  resolved/unresolved. When
comment|/// this happens, breakpoints that are in one of these sections can be
comment|/// set/cleared.
comment|//----------------------------------------------------------------------
name|class
name|Address
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Dump styles allow the Address::Dump(Stream *,DumpStyle) const
comment|/// function to display Address contents in a variety of ways.
comment|//------------------------------------------------------------------
typedef|typedef
enum|enum
block|{
name|DumpStyleInvalid
block|,
comment|///< Invalid dump style
name|DumpStyleSectionNameOffset
block|,
comment|///< Display as the section name + offset.
comment|///< \code
comment|/// // address for printf in libSystem.B.dylib as a section name + offset
comment|/// libSystem.B.dylib.__TEXT.__text + 0x0005cfdf
comment|/// \endcode
name|DumpStyleSectionPointerOffset
block|,
comment|///< Display as the section pointer + offset
comment|///(debug output).
comment|///< \code
comment|/// // address for printf in libSystem.B.dylib as a section pointer + offset
comment|/// (lldb::Section *)0x35cc50 + 0x000000000005cfdf \endcode
name|DumpStyleFileAddress
block|,
comment|///< Display as the file address (if any).
comment|///< \code
comment|/// // address for printf in libSystem.B.dylib as a file address
comment|/// 0x000000000005dcff \endcode
name|DumpStyleModuleWithFileAddress
block|,
comment|///< Display as the file address with the
comment|///module name prepended (if any).
comment|///< \code
comment|/// // address for printf in libSystem.B.dylib as a file address
comment|/// libSystem.B.dylib[0x000000000005dcff] \endcode
name|DumpStyleLoadAddress
block|,
comment|///< Display as the load address (if resolved).
comment|///< \code
comment|/// // address for printf in libSystem.B.dylib as a load address
comment|/// 0x00007fff8306bcff \endcode
name|DumpStyleResolvedDescription
block|,
comment|///< Display the details about what an address
comment|///resolves to. This can
comment|///< be anything from a symbol context summary (module, function/symbol,
comment|///< and file and line), to information about what the pointer points to
comment|///< if the address is in a section (section of pointers, c strings, etc).
name|DumpStyleResolvedDescriptionNoModule
block|,
name|DumpStyleResolvedDescriptionNoFunctionArguments
block|,
name|DumpStyleNoFunctionName
block|,
comment|///< Elide the function name; display an offset
comment|///into the current function.
comment|///< Used primarily in disassembly symbolication
name|DumpStyleDetailedSymbolContext
block|,
comment|///< Detailed symbol context information for
comment|///an address for all symbol
comment|///< context members.
name|DumpStyleResolvedPointerDescription
comment|///< Dereference a pointer at the
comment|///current address and then lookup the
comment|///< dereferenced address using DumpStyleResolvedDescription
block|}
name|DumpStyle
typedef|;
comment|//------------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// Initialize with a invalid section (NULL) and an invalid
comment|/// offset (LLDB_INVALID_ADDRESS).
comment|//------------------------------------------------------------------
name|Address
argument_list|()
operator|:
name|m_section_wp
argument_list|()
operator|,
name|m_offset
argument_list|(
argument|LLDB_INVALID_ADDRESS
argument_list|)
block|{}
comment|//------------------------------------------------------------------
comment|/// Copy constructor
comment|///
comment|/// Makes a copy of the another Address object \a rhs.
comment|///
comment|/// @param[in] rhs
comment|///     A const Address object reference to copy.
comment|//------------------------------------------------------------------
name|Address
argument_list|(
specifier|const
name|Address
operator|&
name|rhs
argument_list|)
operator|:
name|m_section_wp
argument_list|(
name|rhs
operator|.
name|m_section_wp
argument_list|)
operator|,
name|m_offset
argument_list|(
argument|rhs.m_offset
argument_list|)
block|{}
comment|//------------------------------------------------------------------
comment|/// Construct with a section pointer and offset.
comment|///
comment|/// Initialize the address with the supplied \a section and \a
comment|/// offset.
comment|///
comment|/// @param[in] section
comment|///     A section pointer to a valid lldb::Section, or NULL if the
comment|///     address doesn't have a section or will get resolved later.
comment|///
comment|/// @param[in] offset
comment|///     The offset in bytes into \a section.
comment|//------------------------------------------------------------------
name|Address
argument_list|(
argument|const lldb::SectionSP&section_sp
argument_list|,
argument|lldb::addr_t offset
argument_list|)
operator|:
name|m_section_wp
argument_list|()
operator|,
comment|// Don't init with section_sp in case section_sp is
comment|// invalid (the weak_ptr will throw)
name|m_offset
argument_list|(
argument|offset
argument_list|)
block|{
if|if
condition|(
name|section_sp
condition|)
name|m_section_wp
operator|=
name|section_sp
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Construct with a virtual address and section list.
comment|///
comment|/// Initialize and resolve the address with the supplied virtual
comment|/// address \a file_addr.
comment|///
comment|/// @param[in] file_addr
comment|///     A virtual file address.
comment|///
comment|/// @param[in] section_list
comment|///     A list of sections, one of which may contain the \a file_addr.
comment|//------------------------------------------------------------------
name|Address
argument_list|(
argument|lldb::addr_t file_addr
argument_list|,
argument|const SectionList *section_list
argument_list|)
empty_stmt|;
name|Address
argument_list|(
argument|lldb::addr_t abs_addr
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Assignment operator.
comment|///
comment|/// Copies the address value from another Address object \a rhs
comment|/// into \a this object.
comment|///
comment|/// @param[in] rhs
comment|///     A const Address object reference to copy.
comment|///
comment|/// @return
comment|///     A const Address object reference to \a this.
comment|//------------------------------------------------------------------
ifndef|#
directive|ifndef
name|SWIG
specifier|const
name|Address
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Address
operator|&
name|rhs
operator|)
decl_stmt|;
endif|#
directive|endif
comment|//------------------------------------------------------------------
comment|/// Clear the object's state.
comment|///
comment|/// Sets the section to an invalid value (NULL) and an invalid
comment|/// offset (LLDB_INVALID_ADDRESS).
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
block|{
name|m_section_wp
operator|.
name|reset
argument_list|()
expr_stmt|;
name|m_offset
operator|=
name|LLDB_INVALID_ADDRESS
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Compare two Address objects.
comment|///
comment|/// @param[in] lhs
comment|///     The Left Hand Side const Address object reference.
comment|///
comment|/// @param[in] rhs
comment|///     The Right Hand Side const Address object reference.
comment|///
comment|/// @return
comment|///     @li -1 if lhs< rhs
comment|///     @li 0 if lhs == rhs
comment|///     @li 1 if lhs> rhs
comment|//------------------------------------------------------------------
specifier|static
name|int
name|CompareFileAddress
parameter_list|(
specifier|const
name|Address
modifier|&
name|lhs
parameter_list|,
specifier|const
name|Address
modifier|&
name|rhs
parameter_list|)
function_decl|;
specifier|static
name|int
name|CompareLoadAddress
parameter_list|(
specifier|const
name|Address
modifier|&
name|lhs
parameter_list|,
specifier|const
name|Address
modifier|&
name|rhs
parameter_list|,
name|Target
modifier|*
name|target
parameter_list|)
function_decl|;
specifier|static
name|int
name|CompareModulePointerAndOffset
parameter_list|(
specifier|const
name|Address
modifier|&
name|lhs
parameter_list|,
specifier|const
name|Address
modifier|&
name|rhs
parameter_list|)
function_decl|;
comment|// For use with std::map, std::multi_map
name|class
name|ModulePointerAndOffsetLessThanFunctionObject
block|{
name|public
label|:
name|ModulePointerAndOffsetLessThanFunctionObject
argument_list|()
operator|=
expr|default
expr_stmt|;
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|Address
operator|&
name|a
operator|,
specifier|const
name|Address
operator|&
name|b
operator|)
specifier|const
block|{
return|return
name|Address
operator|::
name|CompareModulePointerAndOffset
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
operator|<
literal|0
return|;
block|}
block|}
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Dump a description of this object to a Stream.
comment|///
comment|/// Dump a description of the contents of this object to the
comment|/// supplied stream \a s. There are many ways to display a section
comment|/// offset based address, and \a style lets the user choose.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|///
comment|/// @param[in] style
comment|///     The display style for the address.
comment|///
comment|/// @param[in] fallback_style
comment|///     The display style for the address.
comment|///
comment|/// @return
comment|///     Returns \b true if the address was able to be displayed.
comment|///     File and load addresses may be unresolved and it may not be
comment|///     possible to display a valid value, \b false will be returned
comment|///     in such cases.
comment|///
comment|/// @see Address::DumpStyle
comment|//------------------------------------------------------------------
name|bool
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|ExecutionContextScope
operator|*
name|exe_scope
argument_list|,
name|DumpStyle
name|style
argument_list|,
name|DumpStyle
name|fallback_style
operator|=
name|DumpStyleInvalid
argument_list|,
name|uint32_t
name|addr_byte_size
operator|=
name|UINT32_MAX
argument_list|)
decl|const
decl_stmt|;
name|lldb
operator|::
name|AddressClass
name|GetAddressClass
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the file address.
comment|///
comment|/// If an address comes from a file on disk that has section
comment|/// relative addresses, then it has a virtual address that is
comment|/// relative to unique section in the object file.
comment|///
comment|/// @return
comment|///     The valid file virtual address, or LLDB_INVALID_ADDRESS if
comment|///     the address doesn't have a file virtual address (image is
comment|///     from memory only with no representation on disk).
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetFileAddress
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the load address.
comment|///
comment|/// If an address comes from a file on disk that has section
comment|/// relative addresses, then it has a virtual address that is
comment|/// relative to unique section in the object file. Sections get
comment|/// resolved at runtime by DynamicLoader plug-ins as images
comment|/// (executables and shared libraries) get loaded/unloaded. If a
comment|/// section is loaded, then the load address can be resolved.
comment|///
comment|/// @return
comment|///     The valid load virtual address, or LLDB_INVALID_ADDRESS if
comment|///     the address is currently not loaded.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetLoadAddress
argument_list|(
argument|Target *target
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the load address as a callable code load address.
comment|///
comment|/// This function will first resolve its address to a load address.
comment|/// Then, if the address turns out to be in code address, return the
comment|/// load address that would be required to call or return to. The
comment|/// address might have extra bits set (bit zero will be set to Thumb
comment|/// functions for an ARM target) that are required when changing the
comment|/// program counter to setting a return address.
comment|///
comment|/// @return
comment|///     The valid load virtual address, or LLDB_INVALID_ADDRESS if
comment|///     the address is currently not loaded.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetCallableLoadAddress
argument_list|(
argument|Target *target
argument_list|,
argument|bool is_indirect = false
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the load address as an opcode load address.
comment|///
comment|/// This function will first resolve its address to a load address.
comment|/// Then, if the address turns out to be in code address, return the
comment|/// load address for an opcode. This address object might have
comment|/// extra bits set (bit zero will be set to Thumb functions for an
comment|/// ARM target) that are required for changing the program counter
comment|/// and this function will remove any bits that are intended for
comment|/// these special purposes. The result of this function can be used
comment|/// to safely write a software breakpoint trap to memory.
comment|///
comment|/// @return
comment|///     The valid load virtual address with extra callable bits
comment|///     removed, or LLDB_INVALID_ADDRESS if the address is currently
comment|///     not loaded.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetOpcodeLoadAddress
argument_list|(
argument|Target *target
argument_list|,
argument|lldb::AddressClass addr_class = lldb::eAddressClassInvalid
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the section relative offset value.
comment|///
comment|/// @return
comment|///     The current offset, or LLDB_INVALID_ADDRESS if this address
comment|///     doesn't contain a valid offset.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetOffset
argument_list|()
specifier|const
block|{
return|return
name|m_offset
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Check if an address is section offset.
comment|///
comment|/// When converting a virtual file or load address into a section
comment|/// offset based address, we often need to know if, given a section
comment|/// list, if the address was able to be converted to section offset.
comment|/// This function returns true if the current value contained in
comment|/// this object is section offset based.
comment|///
comment|/// @return
comment|///     Returns \b true if the address has a valid section and
comment|///     offset, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsSectionOffset
argument_list|()
specifier|const
block|{
return|return
name|IsValid
argument_list|()
operator|&&
operator|(
name|GetSection
argument_list|()
operator|.
name|get
argument_list|()
operator|!=
name|nullptr
operator|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Check if the object state is valid.
comment|///
comment|/// A valid Address object contains either a section pointer and
comment|/// and offset (for section offset based addresses), or just a valid
comment|/// offset (for absolute addresses that have no section).
comment|///
comment|/// @return
comment|///     Returns \b true if the offset is valid, \b false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|m_offset
operator|!=
name|LLDB_INVALID_ADDRESS
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the memory cost of this object.
comment|///
comment|/// @return
comment|///     The number of bytes that this object occupies in memory.
comment|//------------------------------------------------------------------
name|size_t
name|MemorySize
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Resolve a file virtual address using a section list.
comment|///
comment|/// Given a list of sections, attempt to resolve \a addr as a
comment|/// an offset into one of the file sections.
comment|///
comment|/// @return
comment|///     Returns \b true if \a addr was able to be resolved, \b false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ResolveAddressUsingFileSections
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
specifier|const
name|SectionList
operator|*
name|sections
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set the address to represent \a load_addr.
comment|///
comment|/// The address will attempt to find a loaded section within
comment|/// \a target that contains \a load_addr. If successful, this
comment|/// address object will have a valid section and offset. Else this
comment|/// address object will have no section (NULL) and the offset will
comment|/// be \a load_addr.
comment|///
comment|/// @param[in] load_addr
comment|///     A load address from a current process.
comment|///
comment|/// @param[in] target
comment|///     The target to use when trying resolve the address into
comment|///     a section + offset. The Target's SectionLoadList object
comment|///     is used to resolve the address.
comment|///
comment|/// @return
comment|///     Returns \b true if the load address was resolved to be
comment|///     section/offset, \b false otherwise. It is often ok for an
comment|///     address no not resolve to a section in a module, this often
comment|///     happens for JIT'ed code, or any load addresses on the stack
comment|///     or heap.
comment|//------------------------------------------------------------------
name|bool
name|SetLoadAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|,
name|Target
operator|*
name|target
argument_list|)
decl_stmt|;
name|bool
name|SetOpcodeLoadAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|,
name|Target
operator|*
name|target
argument_list|,
name|lldb
operator|::
name|AddressClass
name|addr_class
operator|=
name|lldb
operator|::
name|eAddressClassInvalid
argument_list|)
decl_stmt|;
name|bool
name|SetCallableLoadAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|,
name|Target
operator|*
name|target
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for the module for this address.
comment|///
comment|/// @return
comment|///     Returns the Module pointer that this address is an offset
comment|///     in, or NULL if this address doesn't belong in a module, or
comment|///     isn't resolved yet.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ModuleSP
name|GetModule
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get const accessor for the section.
comment|///
comment|/// @return
comment|///     Returns the const lldb::Section pointer that this address is an
comment|///     offset in, or NULL if this address is absolute.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SectionSP
name|GetSection
argument_list|()
specifier|const
block|{
return|return
name|m_section_wp
operator|.
name|lock
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Set accessor for the offset.
comment|///
comment|/// @param[in] offset
comment|///     A new offset value for this object.
comment|///
comment|/// @return
comment|///     Returns \b true if the offset changed, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|SetOffset
argument_list|(
name|lldb
operator|::
name|addr_t
name|offset
argument_list|)
block|{
name|bool
name|changed
init|=
name|m_offset
operator|!=
name|offset
decl_stmt|;
name|m_offset
operator|=
name|offset
expr_stmt|;
return|return
name|changed
return|;
block|}
name|void
name|SetRawAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|)
block|{
name|m_section_wp
operator|.
name|reset
argument_list|()
expr_stmt|;
name|m_offset
operator|=
name|addr
expr_stmt|;
block|}
name|bool
name|Slide
parameter_list|(
name|int64_t
name|offset
parameter_list|)
block|{
if|if
condition|(
name|m_offset
operator|!=
name|LLDB_INVALID_ADDRESS
condition|)
block|{
name|m_offset
operator|+=
name|offset
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Set accessor for the section.
comment|///
comment|/// @param[in] section
comment|///     A new lldb::Section pointer to use as the section base. Can
comment|///     be NULL for absolute addresses that are not relative to
comment|///     any section.
comment|//------------------------------------------------------------------
name|void
name|SetSection
argument_list|(
specifier|const
name|lldb
operator|::
name|SectionSP
operator|&
name|section_sp
argument_list|)
block|{
name|m_section_wp
operator|=
name|section_sp
expr_stmt|;
block|}
name|void
name|ClearSection
parameter_list|()
block|{
name|m_section_wp
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Reconstruct a symbol context from an address.
comment|///
comment|/// This class doesn't inherit from SymbolContextScope because many
comment|/// address objects have short lifespans. Address objects that are
comment|/// section offset can reconstruct their symbol context by looking
comment|/// up the address in the module found in the section.
comment|///
comment|/// @see SymbolContextScope::CalculateSymbolContext(SymbolContext*)
comment|//------------------------------------------------------------------
name|uint32_t
name|CalculateSymbolContext
argument_list|(
name|SymbolContext
operator|*
name|sc
argument_list|,
name|uint32_t
name|resolve_scope
operator|=
name|lldb
operator|::
name|eSymbolContextEverything
argument_list|)
decl|const
decl_stmt|;
name|lldb
operator|::
name|ModuleSP
name|CalculateSymbolContextModule
argument_list|()
specifier|const
expr_stmt|;
name|CompileUnit
operator|*
name|CalculateSymbolContextCompileUnit
argument_list|()
specifier|const
expr_stmt|;
name|Function
operator|*
name|CalculateSymbolContextFunction
argument_list|()
specifier|const
expr_stmt|;
name|Block
operator|*
name|CalculateSymbolContextBlock
argument_list|()
specifier|const
expr_stmt|;
name|Symbol
operator|*
name|CalculateSymbolContextSymbol
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|CalculateSymbolContextLineEntry
argument_list|(
name|LineEntry
operator|&
name|line_entry
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Returns true if the section should be valid, but isn't because
comment|// the shared pointer to the section can't be reconstructed from
comment|// a weak pointer that contains a valid weak reference to a section.
comment|// Returns false if the section weak pointer has no reference to
comment|// a section, or if the section is still valid
comment|//------------------------------------------------------------------
name|bool
name|SectionWasDeleted
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SectionWP
name|m_section_wp
expr_stmt|;
comment|///< The section for the address, can be NULL.
name|lldb
operator|::
name|addr_t
name|m_offset
expr_stmt|;
comment|///< Offset into section if \a m_section_wp is valid...
comment|//------------------------------------------------------------------
comment|// Returns true if the m_section_wp once had a reference to a valid
comment|// section shared pointer, but no longer does. This can happen if
comment|// we have an address from a module that gets unloaded and deleted.
comment|// This function should only be called if GetSection() returns an
comment|// empty shared pointer and you want to know if this address used to
comment|// have a valid section.
comment|//------------------------------------------------------------------
name|bool
name|SectionWasDeletedPrivate
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|// NOTE: Be careful using this operator. It can correctly compare two
comment|// addresses from the same Module correctly. It can't compare two
comment|// addresses from different modules in any meaningful way, but it will
comment|// compare the module pointers.
comment|//
comment|// To sum things up:
comment|// - works great for addresses within the same module
comment|// - it works for addresses across multiple modules, but don't expect the
comment|//   address results to make much sense
comment|//
comment|// This basically lets Address objects be used in ordered collection
comment|// classes.
comment|//----------------------------------------------------------------------
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Address
operator|&
name|lhs
operator|,
specifier|const
name|Address
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|>
operator|(
specifier|const
name|Address
operator|&
name|lhs
operator|,
specifier|const
name|Address
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Address
operator|&
name|lhs
operator|,
specifier|const
name|Address
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Address
operator|&
name|lhs
operator|,
specifier|const
name|Address
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
comment|// liblldb_Address_h_
end_comment

end_unit

