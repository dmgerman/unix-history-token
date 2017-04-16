begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DWARFDebugRangeList.h ------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARF_DWARFDEBUGRANGELIST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARF_DWARFDEBUGRANGELIST_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataExtractor.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<utility>
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
comment|/// DWARFAddressRangesVector - represents a set of absolute address ranges.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|uint64_t
operator|>>
name|DWARFAddressRangesVector
expr_stmt|;
name|class
name|DWARFDebugRangeList
block|{
name|public
label|:
struct|struct
name|RangeListEntry
block|{
comment|// A beginning address offset. This address offset has the size of an
comment|// address and is relative to the applicable base address of the
comment|// compilation unit referencing this range list. It marks the beginning
comment|// of an address range.
name|uint64_t
name|StartAddress
decl_stmt|;
comment|// An ending address offset. This address offset again has the size of
comment|// an address and is relative to the applicable base address of the
comment|// compilation unit referencing this range list. It marks the first
comment|// address past the end of the address range. The ending address must
comment|// be greater than or equal to the beginning address.
name|uint64_t
name|EndAddress
decl_stmt|;
comment|// The end of any given range list is marked by an end of list entry,
comment|// which consists of a 0 for the beginning address offset
comment|// and a 0 for the ending address offset.
name|bool
name|isEndOfListEntry
argument_list|()
specifier|const
block|{
return|return
operator|(
name|StartAddress
operator|==
literal|0
operator|)
operator|&&
operator|(
name|EndAddress
operator|==
literal|0
operator|)
return|;
block|}
comment|// A base address selection entry consists of:
comment|// 1. The value of the largest representable address offset
comment|// (for example, 0xffffffff when the size of an address is 32 bits).
comment|// 2. An address, which defines the appropriate base address for
comment|// use in interpreting the beginning and ending address offsets of
comment|// subsequent entries of the location list.
name|bool
name|isBaseAddressSelectionEntry
argument_list|(
name|uint8_t
name|AddressSize
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|AddressSize
operator|==
literal|4
operator|||
name|AddressSize
operator|==
literal|8
argument_list|)
expr_stmt|;
if|if
condition|(
name|AddressSize
operator|==
literal|4
condition|)
return|return
name|StartAddress
operator|==
operator|-
literal|1U
return|;
else|else
return|return
name|StartAddress
operator|==
operator|-
literal|1ULL
return|;
block|}
block|}
struct|;
name|private
label|:
comment|// Offset in .debug_ranges section.
name|uint32_t
name|Offset
decl_stmt|;
name|uint8_t
name|AddressSize
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|RangeListEntry
operator|>
name|Entries
expr_stmt|;
name|public
label|:
name|DWARFDebugRangeList
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
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
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
specifier|const
name|std
operator|::
name|vector
operator|<
name|RangeListEntry
operator|>
operator|&
name|getEntries
argument_list|()
block|{
return|return
name|Entries
return|;
block|}
comment|/// getAbsoluteRanges - Returns absolute address ranges defined by this range
comment|/// list. Has to be passed base address of the compile unit referencing this
comment|/// range list.
name|DWARFAddressRangesVector
name|getAbsoluteRanges
argument_list|(
name|uint64_t
name|BaseAddress
argument_list|)
decl|const
decl_stmt|;
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
comment|// LLVM_DEBUGINFO_DWARF_DWARFDEBUGRANGELIST_H
end_comment

end_unit

