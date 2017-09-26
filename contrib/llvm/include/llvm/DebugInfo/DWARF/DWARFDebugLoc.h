begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DWARFDebugLoc.h ------------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARF_DWARFDEBUGLOC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARF_DWARFDEBUGLOC_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DWARF/DWARFDataExtractor.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DWARF/DWARFRelocMap.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
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
name|using
name|LocationLists
init|=
name|SmallVector
operator|<
name|LocationList
decl_stmt|, 4>;
comment|/// A list of all the variables in the debug_loc section, each one describing
comment|/// the locations in which the variable is stored.
name|LocationLists
name|Locations
decl_stmt|;
name|public
label|:
comment|/// Print the location lists found within the debug_loc section.
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// Parse the debug_loc section accessible via the 'data' parameter using the
comment|/// address size also given in 'data' to interpret the address ranges.
name|void
name|parse
parameter_list|(
specifier|const
name|DWARFDataExtractor
modifier|&
name|data
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
name|using
name|LocationLists
init|=
name|SmallVector
operator|<
name|LocationList
decl_stmt|, 4>;
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

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_DWARF_DWARFDEBUGLOC_H
end_comment

end_unit

