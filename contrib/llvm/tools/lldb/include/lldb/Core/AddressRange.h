begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AddressRange.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_AddressRange_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_AddressRange_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for SectionSP
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
name|Target
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class AddressRange AddressRange.h "lldb/Core/AddressRange.h"
comment|/// @brief A section + offset based address range class.
comment|//----------------------------------------------------------------------
name|class
name|AddressRange
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// Initialize with a invalid section (NULL), an invalid
comment|/// offset (LLDB_INVALID_ADDRESS), and zero byte size.
comment|//------------------------------------------------------------------
name|AddressRange
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct with a section pointer, offset, and byte_size.
comment|///
comment|/// Initialize the address with the supplied \a section, \a
comment|/// offset and \a byte_size.
comment|///
comment|/// @param[in] section
comment|///     A section pointer to a valid lldb::Section, or NULL if the
comment|///     address doesn't have a section or will get resolved later.
comment|///
comment|/// @param[in] offset
comment|///     The offset in bytes into \a section.
comment|///
comment|/// @param[in] byte_size
comment|///     The size in bytes of the address range.
comment|//------------------------------------------------------------------
name|AddressRange
argument_list|(
argument|const lldb::SectionSP&section
argument_list|,
argument|lldb::addr_t offset
argument_list|,
argument|lldb::addr_t byte_size
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct with a virtual address, section list and byte size.
comment|///
comment|/// Initialize and resolve the address with the supplied virtual
comment|/// address \a file_addr, and byte size \a byte_size.
comment|///
comment|/// @param[in] file_addr
comment|///     A virtual address.
comment|///
comment|/// @param[in] byte_size
comment|///     The size in bytes of the address range.
comment|///
comment|/// @param[in] section_list
comment|///     A list of sections, one of which may contain the \a vaddr.
comment|//------------------------------------------------------------------
name|AddressRange
argument_list|(
argument|lldb::addr_t file_addr
argument_list|,
argument|lldb::addr_t byte_size
argument_list|,
argument|const SectionList *section_list = nullptr
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct with a Address object address and byte size.
comment|///
comment|/// Initialize by copying the section offset address in \a so_addr,
comment|/// and setting the byte size to \a byte_size.
comment|///
comment|/// @param[in] so_addr
comment|///     A section offset address object.
comment|///
comment|/// @param[in] byte_size
comment|///     The size in bytes of the address range.
comment|//------------------------------------------------------------------
name|AddressRange
argument_list|(
argument|const Address&so_addr
argument_list|,
argument|lldb::addr_t byte_size
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// The destructor is virtual in case this class is subclassed.
comment|//------------------------------------------------------------------
operator|~
name|AddressRange
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Clear the object's state.
comment|///
comment|/// Sets the section to an invalid value (NULL), an invalid offset
comment|/// (LLDB_INVALID_ADDRESS) and a zero byte size.
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Check if a section offset address is contained in this range.
comment|///
comment|/// @param[in] so_addr
comment|///     A section offset address object reference.
comment|///
comment|/// @return
comment|///     Returns \b true if \a so_addr is contained in this range,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
comment|//    bool
comment|//    Contains (const Address&so_addr) const;
comment|//------------------------------------------------------------------
comment|/// Check if a section offset address is contained in this range.
comment|///
comment|/// @param[in] so_addr_ptr
comment|///     A section offset address object pointer.
comment|///
comment|/// @return
comment|///     Returns \b true if \a so_addr is contained in this range,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
comment|//    bool
comment|//    Contains (const Address *so_addr_ptr) const;
comment|//------------------------------------------------------------------
comment|/// Check if a section offset \a so_addr when represented as a file
comment|/// address is contained within this object's file address range.
comment|///
comment|/// @param[in] so_addr
comment|///     A section offset address object reference.
comment|///
comment|/// @return
comment|///     Returns \b true if both \a this and \a so_addr have
comment|///     resolvable file address values and \a so_addr is contained
comment|///     in the address range, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ContainsFileAddress
argument_list|(
specifier|const
name|Address
operator|&
name|so_addr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Check if the resolved file address \a file_addr is contained
comment|/// within this object's file address range.
comment|///
comment|/// @param[in] so_addr
comment|///     A section offset address object reference.
comment|///
comment|/// @return
comment|///     Returns \b true if both \a this has a resolvable file
comment|///     address value and \a so_addr is contained in the address
comment|///     range, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ContainsFileAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|file_addr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Check if a section offset \a so_addr when represented as a load
comment|/// address is contained within this object's load address range.
comment|///
comment|/// @param[in] so_addr
comment|///     A section offset address object reference.
comment|///
comment|/// @return
comment|///     Returns \b true if both \a this and \a so_addr have
comment|///     resolvable load address values and \a so_addr is contained
comment|///     in the address range, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ContainsLoadAddress
argument_list|(
specifier|const
name|Address
operator|&
name|so_addr
argument_list|,
name|Target
operator|*
name|target
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Check if the resolved load address \a load_addr is contained
comment|/// within this object's load address range.
comment|///
comment|/// @param[in] so_addr
comment|///     A section offset address object reference.
comment|///
comment|/// @return
comment|///     Returns \b true if both \a this has a resolvable load
comment|///     address value and \a so_addr is contained in the address
comment|///     range, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ContainsLoadAddress
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
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Dump a description of this object to a Stream.
comment|///
comment|/// Dump a description of the contents of this object to the
comment|/// supplied stream \a s. There are many ways to display a section
comment|/// offset based address range, and \a style lets the user choose
comment|/// how the base address gets displayed.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|///
comment|/// @param[in] style
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
name|Target
operator|*
name|target
argument_list|,
name|Address
operator|::
name|DumpStyle
name|style
argument_list|,
name|Address
operator|::
name|DumpStyle
name|fallback_style
operator|=
name|Address
operator|::
name|DumpStyleInvalid
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Dump a debug description of this object to a Stream.
comment|///
comment|/// Dump a debug description of the contents of this object to the
comment|/// supplied stream \a s.
comment|///
comment|/// The debug description contains verbose internal state such
comment|/// and pointer values, reference counts, etc.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|//------------------------------------------------------------------
name|void
name|DumpDebug
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for the base address of the range.
comment|///
comment|/// @return
comment|///     A reference to the base address object.
comment|//------------------------------------------------------------------
name|Address
modifier|&
name|GetBaseAddress
parameter_list|()
block|{
return|return
name|m_base_addr
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get const accessor for the base address of the range.
comment|///
comment|/// @return
comment|///     A const reference to the base address object.
comment|//------------------------------------------------------------------
specifier|const
name|Address
operator|&
name|GetBaseAddress
argument_list|()
specifier|const
block|{
return|return
name|m_base_addr
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get accessor for the byte size of this range.
comment|///
comment|/// @return
comment|///     The size in bytes of this address range.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetByteSize
argument_list|()
specifier|const
block|{
return|return
name|m_byte_size
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
block|{
comment|// Noting special for the memory size of a single AddressRange object,
comment|// it is just the size of itself.
return|return
sizeof|sizeof
argument_list|(
name|AddressRange
argument_list|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Set accessor for the byte size of this range.
comment|///
comment|/// @param[in] byte_size
comment|///     The new size in bytes of this address range.
comment|//------------------------------------------------------------------
name|void
name|SetByteSize
argument_list|(
name|lldb
operator|::
name|addr_t
name|byte_size
argument_list|)
block|{
name|m_byte_size
operator|=
name|byte_size
expr_stmt|;
block|}
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
name|Address
name|m_base_addr
decl_stmt|;
comment|///< The section offset base address of this range.
name|lldb
operator|::
name|addr_t
name|m_byte_size
expr_stmt|;
comment|///< The size in bytes of this address range.
block|}
empty_stmt|;
comment|// bool operator== (const AddressRange& lhs, const AddressRange& rhs);
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
comment|// liblldb_AddressRange_h_
end_comment

end_unit

