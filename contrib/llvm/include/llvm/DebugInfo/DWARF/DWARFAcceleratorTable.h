begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DWARFAcceleratorTable.h ----------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARFACCELERATORTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARFACCELERATORTABLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/BinaryFormat/Dwarf.h"
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

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|DWARFAcceleratorTable
block|{
struct|struct
name|Header
block|{
name|uint32_t
name|Magic
decl_stmt|;
name|uint16_t
name|Version
decl_stmt|;
name|uint16_t
name|HashFunction
decl_stmt|;
name|uint32_t
name|NumBuckets
decl_stmt|;
name|uint32_t
name|NumHashes
decl_stmt|;
name|uint32_t
name|HeaderDataLength
decl_stmt|;
block|}
struct|;
struct|struct
name|HeaderData
block|{
name|using
name|AtomType
init|=
name|uint16_t
decl_stmt|;
name|using
name|Form
init|=
name|dwarf
operator|::
name|Form
decl_stmt|;
name|uint32_t
name|DIEOffsetBase
decl_stmt|;
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|AtomType
operator|,
name|Form
operator|>
operator|,
literal|3
operator|>
name|Atoms
expr_stmt|;
block|}
struct|;
name|struct
name|Header
name|Hdr
decl_stmt|;
name|struct
name|HeaderData
name|HdrData
decl_stmt|;
name|DWARFDataExtractor
name|AccelSection
decl_stmt|;
name|DataExtractor
name|StringSection
decl_stmt|;
name|public
label|:
name|DWARFAcceleratorTable
argument_list|(
argument|const DWARFDataExtractor&AccelSection
argument_list|,
argument|DataExtractor StringSection
argument_list|)
block|:
name|AccelSection
argument_list|(
name|AccelSection
argument_list|)
operator|,
name|StringSection
argument_list|(
argument|StringSection
argument_list|)
block|{}
name|bool
name|extract
argument_list|()
expr_stmt|;
name|uint32_t
name|getNumBuckets
parameter_list|()
function_decl|;
name|uint32_t
name|getNumHashes
parameter_list|()
function_decl|;
name|uint32_t
name|getSizeHdr
parameter_list|()
function_decl|;
name|uint32_t
name|getHeaderDataLength
parameter_list|()
function_decl|;
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|HeaderData
operator|::
name|AtomType
operator|,
name|HeaderData
operator|::
name|Form
operator|>>
name|getAtomsDesc
argument_list|()
expr_stmt|;
name|bool
name|validateForms
parameter_list|()
function_decl|;
comment|/// Return information related to the DWARF DIE we're looking for when
comment|/// performing a lookup by name.
comment|///
comment|/// \param HashDataOffset an offset into the hash data table
comment|/// \returns DIEOffset the offset into the .debug_info section for the DIE
comment|/// related to the input hash data offset. Currently this function returns
comment|/// only the DIEOffset but it can be modified to return more data regarding
comment|/// the DIE
name|uint32_t
name|readAtoms
parameter_list|(
name|uint32_t
modifier|&
name|HashDataOffset
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
comment|// LLVM_DEBUGINFO_DWARFACCELERATORTABLE_H
end_comment

end_unit

