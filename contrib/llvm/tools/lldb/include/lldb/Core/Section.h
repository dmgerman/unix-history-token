begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Section.h -----------------------------------------------*- C++ -*-===//
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
name|liblldb_Section_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Section_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/ModuleChild.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Flags.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UserID.h"
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
comment|// for SectionType
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for SectionSP, ModuleSP, SectionWP
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_comment
comment|// for addr_t, offset_t, user_id_t
end_comment

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
file|<vector>
end_include

begin_comment
comment|// for vector
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
comment|// for uint32_t, UINT32_MAX
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Address
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|DataExtractor
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
name|Section
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
name|class
name|SectionList
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|SectionSP
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|SectionList
argument_list|()
expr_stmt|;
operator|~
name|SectionList
argument_list|()
expr_stmt|;
name|SectionList
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SectionList
operator|&
name|rhs
operator|)
decl_stmt|;
name|size_t
name|AddSection
argument_list|(
specifier|const
name|lldb
operator|::
name|SectionSP
operator|&
name|section_sp
argument_list|)
decl_stmt|;
name|size_t
name|AddUniqueSection
argument_list|(
specifier|const
name|lldb
operator|::
name|SectionSP
operator|&
name|section_sp
argument_list|)
decl_stmt|;
name|size_t
name|FindSectionIndex
parameter_list|(
specifier|const
name|Section
modifier|*
name|sect
parameter_list|)
function_decl|;
name|bool
name|ContainsSection
argument_list|(
name|lldb
operator|::
name|user_id_t
name|sect_id
argument_list|)
decl|const
decl_stmt|;
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
argument_list|,
name|bool
name|show_header
argument_list|,
name|uint32_t
name|depth
argument_list|)
decl|const
decl_stmt|;
name|lldb
operator|::
name|SectionSP
name|FindSectionByName
argument_list|(
argument|const ConstString&section_dstr
argument_list|)
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SectionSP
name|FindSectionByID
argument_list|(
argument|lldb::user_id_t sect_id
argument_list|)
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SectionSP
name|FindSectionByType
argument_list|(
argument|lldb::SectionType sect_type
argument_list|,
argument|bool check_children
argument_list|,
argument|size_t start_idx =
literal|0
argument_list|)
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SectionSP
name|FindSectionContainingFileAddress
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|uint32_t depth = UINT32_MAX
argument_list|)
specifier|const
expr_stmt|;
comment|// Get the number of sections in this list only
name|size_t
name|GetSize
argument_list|()
specifier|const
block|{
return|return
name|m_sections
operator|.
name|size
argument_list|()
return|;
block|}
comment|// Get the number of sections in this list, and any contained child sections
name|size_t
name|GetNumSections
argument_list|(
name|uint32_t
name|depth
argument_list|)
decl|const
decl_stmt|;
name|bool
name|ReplaceSection
argument_list|(
name|lldb
operator|::
name|user_id_t
name|sect_id
argument_list|,
specifier|const
name|lldb
operator|::
name|SectionSP
operator|&
name|section_sp
argument_list|,
name|uint32_t
name|depth
operator|=
name|UINT32_MAX
argument_list|)
decl_stmt|;
comment|// Warning, this can be slow as it's removing items from a std::vector.
name|bool
name|DeleteSection
parameter_list|(
name|size_t
name|idx
parameter_list|)
function_decl|;
name|lldb
operator|::
name|SectionSP
name|GetSectionAtIndex
argument_list|(
argument|size_t idx
argument_list|)
specifier|const
expr_stmt|;
name|size_t
name|Slide
argument_list|(
name|lldb
operator|::
name|addr_t
name|slide_amount
argument_list|,
name|bool
name|slide_children
argument_list|)
decl_stmt|;
name|void
name|Clear
parameter_list|()
block|{
name|m_sections
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|protected
label|:
name|collection
name|m_sections
decl_stmt|;
block|}
empty_stmt|;
name|class
name|Section
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|Section
operator|>
decl_stmt|,
name|public
name|ModuleChild
decl_stmt|,
name|public
name|UserID
decl_stmt|,
name|public
name|Flags
block|{
name|public
label|:
comment|// Create a root section (one that has no parent)
name|Section
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|ObjectFile *obj_file
argument_list|,
argument|lldb::user_id_t sect_id
argument_list|,
argument|const ConstString&name
argument_list|,
argument|lldb::SectionType sect_type
argument_list|,
argument|lldb::addr_t file_vm_addr
argument_list|,
argument|lldb::addr_t vm_size
argument_list|,
argument|lldb::offset_t file_offset
argument_list|,
argument|lldb::offset_t file_size
argument_list|,
argument|uint32_t log2align
argument_list|,
argument|uint32_t flags
argument_list|,
argument|uint32_t target_byte_size =
literal|1
argument_list|)
empty_stmt|;
comment|// Create a section that is a child of parent_section_sp
name|Section
argument_list|(
argument|const lldb::SectionSP&parent_section_sp
argument_list|,
comment|// NULL for top level
comment|// sections, non-NULL for
comment|// child sections
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|ObjectFile *obj_file
argument_list|,
argument|lldb::user_id_t sect_id
argument_list|,
argument|const ConstString&name
argument_list|,
argument|lldb::SectionType sect_type
argument_list|,
argument|lldb::addr_t file_vm_addr
argument_list|,
argument|lldb::addr_t vm_size
argument_list|,
argument|lldb::offset_t file_offset
argument_list|,
argument|lldb::offset_t file_size
argument_list|,
argument|uint32_t log2align
argument_list|,
argument|uint32_t flags
argument_list|,
argument|uint32_t target_byte_size =
literal|1
argument_list|)
empty_stmt|;
operator|~
name|Section
argument_list|()
expr_stmt|;
specifier|static
name|int
name|Compare
parameter_list|(
specifier|const
name|Section
modifier|&
name|a
parameter_list|,
specifier|const
name|Section
modifier|&
name|b
parameter_list|)
function_decl|;
name|bool
name|ContainsFileAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|vm_addr
argument_list|)
decl|const
decl_stmt|;
name|SectionList
modifier|&
name|GetChildren
parameter_list|()
block|{
return|return
name|m_children
return|;
block|}
specifier|const
name|SectionList
operator|&
name|GetChildren
argument_list|()
specifier|const
block|{
return|return
name|m_children
return|;
block|}
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
argument_list|,
name|uint32_t
name|depth
argument_list|)
decl|const
decl_stmt|;
name|void
name|DumpName
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|GetLoadBaseAddress
argument_list|(
argument|Target *target
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|ResolveContainedAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|offset
argument_list|,
name|Address
operator|&
name|so_addr
argument_list|,
name|bool
name|allow_section_end
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|lldb
operator|::
name|offset_t
name|GetFileOffset
argument_list|()
specifier|const
block|{
return|return
name|m_file_offset
return|;
block|}
name|void
name|SetFileOffset
argument_list|(
name|lldb
operator|::
name|offset_t
name|file_offset
argument_list|)
block|{
name|m_file_offset
operator|=
name|file_offset
expr_stmt|;
block|}
name|lldb
operator|::
name|offset_t
name|GetFileSize
argument_list|()
specifier|const
block|{
return|return
name|m_file_size
return|;
block|}
name|void
name|SetFileSize
argument_list|(
name|lldb
operator|::
name|offset_t
name|file_size
argument_list|)
block|{
name|m_file_size
operator|=
name|file_size
expr_stmt|;
block|}
name|lldb
operator|::
name|addr_t
name|GetFileAddress
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|SetFileAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|file_addr
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|GetOffset
argument_list|()
specifier|const
expr_stmt|;
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
name|bool
name|IsFake
argument_list|()
specifier|const
block|{
return|return
name|m_fake
return|;
block|}
name|void
name|SetIsFake
parameter_list|(
name|bool
name|fake
parameter_list|)
block|{
name|m_fake
operator|=
name|fake
expr_stmt|;
block|}
name|bool
name|IsEncrypted
argument_list|()
specifier|const
block|{
return|return
name|m_encrypted
return|;
block|}
name|void
name|SetIsEncrypted
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_encrypted
operator|=
name|b
expr_stmt|;
block|}
name|bool
name|IsDescendant
parameter_list|(
specifier|const
name|Section
modifier|*
name|section
parameter_list|)
function_decl|;
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
name|bool
name|Slide
argument_list|(
name|lldb
operator|::
name|addr_t
name|slide_amount
argument_list|,
name|bool
name|slide_children
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|SectionType
name|GetType
argument_list|()
specifier|const
block|{
return|return
name|m_type
return|;
block|}
name|lldb
operator|::
name|SectionSP
name|GetParent
argument_list|()
specifier|const
block|{
return|return
name|m_parent_wp
operator|.
name|lock
argument_list|()
return|;
block|}
name|bool
name|IsThreadSpecific
argument_list|()
specifier|const
block|{
return|return
name|m_thread_specific
return|;
block|}
name|void
name|SetIsThreadSpecific
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_thread_specific
operator|=
name|b
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the permissions as OR'ed bits from lldb::Permissions
comment|//------------------------------------------------------------------
name|uint32_t
name|GetPermissions
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set the permissions using bits OR'ed from lldb::Permissions
comment|//------------------------------------------------------------------
name|void
name|SetPermissions
parameter_list|(
name|uint32_t
name|permissions
parameter_list|)
function_decl|;
name|ObjectFile
modifier|*
name|GetObjectFile
parameter_list|()
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
comment|/// Read the section data from the object file that the section
comment|/// resides in.
comment|///
comment|/// @param[in] dst
comment|///     Where to place the data
comment|///
comment|/// @param[in] dst_len
comment|///     How many bytes of section data to read
comment|///
comment|/// @param[in] offset
comment|///     The offset in bytes within this section's data at which to
comment|///     start copying data from.
comment|///
comment|/// @return
comment|///     The number of bytes read from the section, or zero if the
comment|///     section has no data or \a offset is not a valid offset
comment|///     in this section.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|offset_t
name|GetSectionData
argument_list|(
argument|void *dst
argument_list|,
argument|lldb::offset_t dst_len
argument_list|,
argument|lldb::offset_t offset =
literal|0
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the shared reference to the section data from the object
comment|/// file that the section resides in. No copies of the data will be
comment|/// make unless the object file has been read from memory. If the
comment|/// object file is on disk, it will shared the mmap data for the
comment|/// entire object file.
comment|///
comment|/// @param[in] data
comment|///     Where to place the data, address byte size, and byte order
comment|///
comment|/// @return
comment|///     The number of bytes read from the section, or zero if the
comment|///     section has no data or \a offset is not a valid offset
comment|///     in this section.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|offset_t
name|GetSectionData
argument_list|(
argument|DataExtractor&data
argument_list|)
specifier|const
expr_stmt|;
name|uint32_t
name|GetLog2Align
parameter_list|()
block|{
return|return
name|m_log2align
return|;
block|}
name|void
name|SetLog2Align
parameter_list|(
name|uint32_t
name|align
parameter_list|)
block|{
name|m_log2align
operator|=
name|align
expr_stmt|;
block|}
comment|// Get the number of host bytes required to hold a target byte
name|uint32_t
name|GetTargetByteSize
argument_list|()
specifier|const
block|{
return|return
name|m_target_byte_size
return|;
block|}
name|protected
label|:
name|ObjectFile
modifier|*
name|m_obj_file
decl_stmt|;
comment|// The object file that data for this section should
comment|// be read from
name|lldb
operator|::
name|SectionType
name|m_type
expr_stmt|;
comment|// The type of this section
name|lldb
operator|::
name|SectionWP
name|m_parent_wp
expr_stmt|;
comment|// Weak pointer to parent section
name|ConstString
name|m_name
decl_stmt|;
comment|// Name of this section
name|lldb
operator|::
name|addr_t
name|m_file_addr
expr_stmt|;
comment|// The absolute file virtual address range of this
comment|// section if m_parent == NULL,
comment|// offset from parent file virtual address if m_parent != NULL
name|lldb
operator|::
name|addr_t
name|m_byte_size
expr_stmt|;
comment|// Size in bytes that this section will occupy in
comment|// memory at runtime
name|lldb
operator|::
name|offset_t
name|m_file_offset
expr_stmt|;
comment|// Object file offset (if any)
name|lldb
operator|::
name|offset_t
name|m_file_size
expr_stmt|;
comment|// Object file size (can be smaller than
comment|// m_byte_size for zero filled sections...)
name|uint32_t
name|m_log2align
decl_stmt|;
comment|// log_2(align) of the section (i.e. section has to be
comment|// aligned to 2^m_log2align)
name|SectionList
name|m_children
decl_stmt|;
comment|// Child sections
name|bool
name|m_fake
range|:
literal|1
decl_stmt|,
comment|// If true, then this section only can contain the address if
comment|// one of its
comment|// children contains an address. This allows for gaps between the children
comment|// that are contained in the address range for this section, but do not
comment|// produce
comment|// hits unless the children contain the address.
name|m_encrypted
range|:
literal|1
decl_stmt|,
comment|// Set to true if the contents are encrypted
name|m_thread_specific
range|:
literal|1
decl_stmt|,
comment|// This section is thread specific
name|m_readable
range|:
literal|1
decl_stmt|,
comment|// If this section has read permissions
name|m_writable
range|:
literal|1
decl_stmt|,
comment|// If this section has write permissions
name|m_executable
range|:
literal|1
decl_stmt|;
comment|// If this section has executable permissions
name|uint32_t
name|m_target_byte_size
decl_stmt|;
comment|// Some architectures have non-8-bit byte size.
comment|// This is specified as
comment|// as a multiple number of a host bytes
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Section
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
comment|// liblldb_Section_h_
end_comment

end_unit

