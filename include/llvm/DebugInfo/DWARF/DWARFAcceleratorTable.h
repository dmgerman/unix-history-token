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
file|"llvm/DebugInfo/DWARF/DWARFRelocMap.h"
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
typedef|typedef
name|uint16_t
name|AtomType
typedef|;
typedef|typedef
name|dwarf
operator|::
name|Form
name|Form
expr_stmt|;
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
name|DataExtractor
name|AccelSection
decl_stmt|;
name|DataExtractor
name|StringSection
decl_stmt|;
specifier|const
name|RelocAddrMap
modifier|&
name|Relocs
decl_stmt|;
name|public
label|:
name|DWARFAcceleratorTable
argument_list|(
argument|DataExtractor AccelSection
argument_list|,
argument|DataExtractor StringSection
argument_list|,
argument|const RelocAddrMap&Relocs
argument_list|)
block|:
name|AccelSection
argument_list|(
name|AccelSection
argument_list|)
operator|,
name|StringSection
argument_list|(
name|StringSection
argument_list|)
operator|,
name|Relocs
argument_list|(
argument|Relocs
argument_list|)
block|{}
name|bool
name|extract
argument_list|()
expr_stmt|;
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

