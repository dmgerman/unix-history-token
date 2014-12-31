begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFDebugLoc.h -----------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARFDEBUGLOC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARFDEBUGLOC_H
end_define

begin_include
include|#
directive|include
file|"DWARFRelocMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataExtractor.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|DWARFDebugLoc
block|{
comment|/// A single location within a location list.
struct|struct
name|Entry
block|{
comment|/// The beginning address of the instruction range.
name|uint64_t
name|Begin
decl_stmt|;
comment|/// The ending address of the instruction range.
name|uint64_t
name|End
decl_stmt|;
comment|/// The location of the variable within the specified range.
name|SmallVector
operator|<
name|unsigned
name|char
operator|,
literal|4
operator|>
name|Loc
expr_stmt|;
block|}
struct|;
comment|/// A list of locations that contain one variable.
struct|struct
name|LocationList
block|{
comment|/// The beginning offset where this location list is stored in the debug_loc
comment|/// section.
name|unsigned
name|Offset
decl_stmt|;
comment|/// All the locations in which the variable is stored.
name|SmallVector
operator|<
name|Entry
operator|,
literal|2
operator|>
name|Entries
expr_stmt|;
block|}
struct|;
typedef|typedef
name|SmallVector
operator|<
name|LocationList
operator|,
literal|4
operator|>
name|LocationLists
expr_stmt|;
comment|/// A list of all the variables in the debug_loc section, each one describing
comment|/// the locations in which the variable is stored.
name|LocationLists
name|Locations
decl_stmt|;
comment|/// A map used to resolve binary relocations.
specifier|const
name|RelocAddrMap
modifier|&
name|RelocMap
decl_stmt|;
name|public
label|:
name|DWARFDebugLoc
argument_list|(
specifier|const
name|RelocAddrMap
operator|&
name|LocRelocMap
argument_list|)
operator|:
name|RelocMap
argument_list|(
argument|LocRelocMap
argument_list|)
block|{}
comment|/// Print the location lists found within the debug_loc section.
name|void
name|dump
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
expr_stmt|;
comment|/// Parse the debug_loc section accessible via the 'data' parameter using the
comment|/// specified address size to interpret the address ranges.
name|void
name|parse
parameter_list|(
name|DataExtractor
name|data
parameter_list|,
name|unsigned
name|AddressSize
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|class
name|DWARFDebugLocDWO
block|{
struct|struct
name|Entry
block|{
name|uint64_t
name|Start
decl_stmt|;
name|uint32_t
name|Length
decl_stmt|;
name|SmallVector
operator|<
name|unsigned
name|char
operator|,
literal|4
operator|>
name|Loc
expr_stmt|;
block|}
struct|;
struct|struct
name|LocationList
block|{
name|unsigned
name|Offset
decl_stmt|;
name|SmallVector
operator|<
name|Entry
operator|,
literal|2
operator|>
name|Entries
expr_stmt|;
block|}
struct|;
typedef|typedef
name|SmallVector
operator|<
name|LocationList
operator|,
literal|4
operator|>
name|LocationLists
expr_stmt|;
name|LocationLists
name|Locations
decl_stmt|;
name|public
label|:
name|void
name|parse
parameter_list|(
name|DataExtractor
name|data
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
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

