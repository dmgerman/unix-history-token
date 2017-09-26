begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DWARFDebugArangeSet.h ------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARFDEBUGARANGESET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARFDEBUGARANGESET_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataExtractor.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|DWARFDebugArangeSet
block|{
name|public
label|:
struct|struct
name|Header
block|{
comment|/// The total length of the entries for that set, not including the length
comment|/// field itself.
name|uint32_t
name|Length
decl_stmt|;
comment|/// The offset from the beginning of the .debug_info section of the
comment|/// compilation unit entry referenced by the table.
name|uint32_t
name|CuOffset
decl_stmt|;
comment|/// The DWARF version number.
name|uint16_t
name|Version
decl_stmt|;
comment|/// The size in bytes of an address on the target architecture. For segmented
comment|/// addressing, this is the size of the offset portion of the address.
name|uint8_t
name|AddrSize
decl_stmt|;
comment|/// The size in bytes of a segment descriptor on the target architecture.
comment|/// If the target system uses a flat address space, this value is 0.
name|uint8_t
name|SegSize
decl_stmt|;
block|}
struct|;
struct|struct
name|Descriptor
block|{
name|uint64_t
name|Address
decl_stmt|;
name|uint64_t
name|Length
decl_stmt|;
name|uint64_t
name|getEndAddress
argument_list|()
specifier|const
block|{
return|return
name|Address
operator|+
name|Length
return|;
block|}
block|}
struct|;
name|private
label|:
name|using
name|DescriptorColl
init|=
name|std
operator|::
name|vector
operator|<
name|Descriptor
operator|>
decl_stmt|;
name|using
name|desc_iterator_range
init|=
name|iterator_range
operator|<
name|DescriptorColl
operator|::
name|const_iterator
operator|>
decl_stmt|;
name|uint32_t
name|Offset
decl_stmt|;
name|Header
name|HeaderData
decl_stmt|;
name|DescriptorColl
name|ArangeDescriptors
decl_stmt|;
name|public
label|:
name|DWARFDebugArangeSet
argument_list|()
block|{
name|clear
argument_list|()
expr_stmt|;
block|}
name|void
name|clear
parameter_list|()
function_decl|;
name|bool
name|extract
parameter_list|(
name|DataExtractor
name|data
parameter_list|,
name|uint32_t
modifier|*
name|offset_ptr
parameter_list|)
function_decl|;
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|getCompileUnitDIEOffset
argument_list|()
specifier|const
block|{
return|return
name|HeaderData
operator|.
name|CuOffset
return|;
block|}
specifier|const
name|Header
operator|&
name|getHeader
argument_list|()
specifier|const
block|{
return|return
name|HeaderData
return|;
block|}
name|desc_iterator_range
name|descriptors
argument_list|()
specifier|const
block|{
return|return
name|desc_iterator_range
argument_list|(
name|ArangeDescriptors
operator|.
name|begin
argument_list|()
argument_list|,
name|ArangeDescriptors
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_DWARFDEBUGARANGESET_H
end_comment

end_unit

