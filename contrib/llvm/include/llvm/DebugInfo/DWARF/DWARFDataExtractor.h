begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DWARFDataExtractor.h -------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARFDATAEXTRACTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARFDATAEXTRACTOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DWARF/DWARFSection.h"
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
comment|/// A DataExtractor (typically for an in-memory copy of an object-file section)
comment|/// plus a relocation map for that section, if there is one.
name|class
name|DWARFDataExtractor
range|:
name|public
name|DataExtractor
block|{
specifier|const
name|RelocAddrMap
operator|*
name|RelocMap
operator|=
name|nullptr
block|;
name|public
operator|:
comment|/// Constructor for the normal case of extracting data from a DWARF section.
comment|/// The DWARFSection's lifetime must be at least as long as the extractor's.
name|DWARFDataExtractor
argument_list|(
argument|const DWARFSection&Section
argument_list|,
argument|bool IsLittleEndian
argument_list|,
argument|uint8_t AddressSize
argument_list|)
operator|:
name|DataExtractor
argument_list|(
name|Section
operator|.
name|Data
argument_list|,
name|IsLittleEndian
argument_list|,
name|AddressSize
argument_list|)
block|,
name|RelocMap
argument_list|(
argument|&Section.Relocs
argument_list|)
block|{}
comment|/// Constructor for cases when there are no relocations.
name|DWARFDataExtractor
argument_list|(
argument|StringRef Data
argument_list|,
argument|bool IsLittleEndian
argument_list|,
argument|uint8_t AddressSize
argument_list|)
operator|:
name|DataExtractor
argument_list|(
argument|Data
argument_list|,
argument|IsLittleEndian
argument_list|,
argument|AddressSize
argument_list|)
block|{}
comment|/// Extracts a value and applies a relocation to the result if
comment|/// one exists for the given offset.
name|uint64_t
name|getRelocatedValue
argument_list|(
argument|uint32_t Size
argument_list|,
argument|uint32_t *Off
argument_list|,
argument|uint64_t *SectionIndex = nullptr
argument_list|)
specifier|const
block|;
comment|/// Extracts an address-sized value and applies a relocation to the result if
comment|/// one exists for the given offset.
name|uint64_t
name|getRelocatedAddress
argument_list|(
argument|uint32_t *Off
argument_list|,
argument|uint64_t *SecIx = nullptr
argument_list|)
specifier|const
block|{
return|return
name|getRelocatedValue
argument_list|(
name|getAddressSize
argument_list|()
argument_list|,
name|Off
argument_list|,
name|SecIx
argument_list|)
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_DWARFDATAEXTRACTOR_H
end_comment

end_unit

