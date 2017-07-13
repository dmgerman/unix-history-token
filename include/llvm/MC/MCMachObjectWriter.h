begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/MC/MCMachObjectWriter.h - Mach Object Writer --------*- C++ -*-===//
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
name|LLVM_MC_MCMACHOBJECTWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCMACHOBJECTWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/BinaryFormat/MachO.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCExpr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCObjectWriter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/StringTableBuilder.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
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
name|MachObjectWriter
decl_stmt|;
name|class
name|MCMachObjectTargetWriter
block|{
specifier|const
name|unsigned
name|Is64Bit
range|:
literal|1
decl_stmt|;
specifier|const
name|uint32_t
name|CPUType
decl_stmt|;
specifier|const
name|uint32_t
name|CPUSubtype
decl_stmt|;
name|unsigned
name|LocalDifference_RIT
decl_stmt|;
name|protected
label|:
name|MCMachObjectTargetWriter
argument_list|(
argument|bool Is64Bit_
argument_list|,
argument|uint32_t CPUType_
argument_list|,
argument|uint32_t CPUSubtype_
argument_list|)
empty_stmt|;
name|void
name|setLocalDifferenceRelocationType
parameter_list|(
name|unsigned
name|Type
parameter_list|)
block|{
name|LocalDifference_RIT
operator|=
name|Type
expr_stmt|;
block|}
name|public
label|:
name|virtual
operator|~
name|MCMachObjectTargetWriter
argument_list|()
expr_stmt|;
comment|/// \name Lifetime Management
comment|/// @{
name|virtual
name|void
name|reset
parameter_list|()
block|{}
comment|/// @}
comment|/// \name Accessors
comment|/// @{
name|bool
name|is64Bit
argument_list|()
specifier|const
block|{
return|return
name|Is64Bit
return|;
block|}
name|uint32_t
name|getCPUType
argument_list|()
specifier|const
block|{
return|return
name|CPUType
return|;
block|}
name|uint32_t
name|getCPUSubtype
argument_list|()
specifier|const
block|{
return|return
name|CPUSubtype
return|;
block|}
name|unsigned
name|getLocalDifferenceRelocationType
argument_list|()
specifier|const
block|{
return|return
name|LocalDifference_RIT
return|;
block|}
comment|/// @}
comment|/// \name API
comment|/// @{
name|virtual
name|void
name|recordRelocation
parameter_list|(
name|MachObjectWriter
modifier|*
name|Writer
parameter_list|,
name|MCAssembler
modifier|&
name|Asm
parameter_list|,
specifier|const
name|MCAsmLayout
modifier|&
name|Layout
parameter_list|,
specifier|const
name|MCFragment
modifier|*
name|Fragment
parameter_list|,
specifier|const
name|MCFixup
modifier|&
name|Fixup
parameter_list|,
name|MCValue
name|Target
parameter_list|,
name|uint64_t
modifier|&
name|FixedValue
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// @}
block|}
empty_stmt|;
name|class
name|MachObjectWriter
range|:
name|public
name|MCObjectWriter
block|{
comment|/// Helper struct for containing some precomputed information on symbols.
block|struct
name|MachSymbolData
block|{
specifier|const
name|MCSymbol
operator|*
name|Symbol
block|;
name|uint64_t
name|StringIndex
block|;
name|uint8_t
name|SectionIndex
block|;
comment|// Support lexicographic sorting.
name|bool
name|operator
operator|<
operator|(
specifier|const
name|MachSymbolData
operator|&
name|RHS
operator|)
specifier|const
block|;   }
block|;
comment|/// The target specific Mach-O writer instance.
name|std
operator|::
name|unique_ptr
operator|<
name|MCMachObjectTargetWriter
operator|>
name|TargetObjectWriter
block|;
comment|/// \name Relocation Data
comment|/// @{
block|struct
name|RelAndSymbol
block|{
specifier|const
name|MCSymbol
operator|*
name|Sym
block|;
name|MachO
operator|::
name|any_relocation_info
name|MRE
block|;
name|RelAndSymbol
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|Sym
argument_list|,
specifier|const
name|MachO
operator|::
name|any_relocation_info
operator|&
name|MRE
argument_list|)
operator|:
name|Sym
argument_list|(
name|Sym
argument_list|)
block|,
name|MRE
argument_list|(
argument|MRE
argument_list|)
block|{}
block|}
block|;
name|DenseMap
operator|<
specifier|const
name|MCSection
operator|*
block|,
name|std
operator|::
name|vector
operator|<
name|RelAndSymbol
operator|>>
name|Relocations
block|;
name|DenseMap
operator|<
specifier|const
name|MCSection
operator|*
block|,
name|unsigned
operator|>
name|IndirectSymBase
block|;
name|SectionAddrMap
name|SectionAddress
block|;
comment|/// @}
comment|/// \name Symbol Table Data
comment|/// @{
name|StringTableBuilder
name|StringTable
block|{
name|StringTableBuilder
operator|::
name|MachO
block|}
block|;
name|std
operator|::
name|vector
operator|<
name|MachSymbolData
operator|>
name|LocalSymbolData
block|;
name|std
operator|::
name|vector
operator|<
name|MachSymbolData
operator|>
name|ExternalSymbolData
block|;
name|std
operator|::
name|vector
operator|<
name|MachSymbolData
operator|>
name|UndefinedSymbolData
block|;
comment|/// @}
name|MachSymbolData
operator|*
name|findSymbolData
argument_list|(
specifier|const
name|MCSymbol
operator|&
name|Sym
argument_list|)
block|;
name|public
operator|:
name|MachObjectWriter
argument_list|(
argument|MCMachObjectTargetWriter *MOTW
argument_list|,
argument|raw_pwrite_stream&OS
argument_list|,
argument|bool IsLittleEndian
argument_list|)
operator|:
name|MCObjectWriter
argument_list|(
name|OS
argument_list|,
name|IsLittleEndian
argument_list|)
block|,
name|TargetObjectWriter
argument_list|(
argument|MOTW
argument_list|)
block|{}
specifier|const
name|MCSymbol
operator|&
name|findAliasedSymbol
argument_list|(
argument|const MCSymbol&Sym
argument_list|)
specifier|const
block|;
comment|/// \name Lifetime management Methods
comment|/// @{
name|void
name|reset
argument_list|()
name|override
block|;
comment|/// @}
comment|/// \name Utility Methods
comment|/// @{
name|bool
name|isFixupKindPCRel
argument_list|(
argument|const MCAssembler&Asm
argument_list|,
argument|unsigned Kind
argument_list|)
block|;
name|SectionAddrMap
operator|&
name|getSectionAddressMap
argument_list|()
block|{
return|return
name|SectionAddress
return|;
block|}
name|uint64_t
name|getSectionAddress
argument_list|(
argument|const MCSection *Sec
argument_list|)
specifier|const
block|{
return|return
name|SectionAddress
operator|.
name|lookup
argument_list|(
name|Sec
argument_list|)
return|;
block|}
name|uint64_t
name|getSymbolAddress
argument_list|(
argument|const MCSymbol&S
argument_list|,
argument|const MCAsmLayout&Layout
argument_list|)
specifier|const
block|;
name|uint64_t
name|getFragmentAddress
argument_list|(
argument|const MCFragment *Fragment
argument_list|,
argument|const MCAsmLayout&Layout
argument_list|)
specifier|const
block|;
name|uint64_t
name|getPaddingSize
argument_list|(
argument|const MCSection *SD
argument_list|,
argument|const MCAsmLayout&Layout
argument_list|)
specifier|const
block|;
name|bool
name|doesSymbolRequireExternRelocation
argument_list|(
specifier|const
name|MCSymbol
operator|&
name|S
argument_list|)
block|;
comment|/// @}
comment|/// \name Target Writer Proxy Accessors
comment|/// @{
name|bool
name|is64Bit
argument_list|()
specifier|const
block|{
return|return
name|TargetObjectWriter
operator|->
name|is64Bit
argument_list|()
return|;
block|}
name|bool
name|isX86_64
argument_list|()
specifier|const
block|{
name|uint32_t
name|CPUType
operator|=
name|TargetObjectWriter
operator|->
name|getCPUType
argument_list|()
block|;
return|return
name|CPUType
operator|==
name|MachO
operator|::
name|CPU_TYPE_X86_64
return|;
block|}
comment|/// @}
name|void
name|writeHeader
argument_list|(
argument|MachO::HeaderFileType Type
argument_list|,
argument|unsigned NumLoadCommands
argument_list|,
argument|unsigned LoadCommandsSize
argument_list|,
argument|bool SubsectionsViaSymbols
argument_list|)
block|;
comment|/// Write a segment load command.
comment|///
comment|/// \param NumSections The number of sections in this segment.
comment|/// \param SectionDataSize The total size of the sections.
name|void
name|writeSegmentLoadCommand
argument_list|(
argument|StringRef Name
argument_list|,
argument|unsigned NumSections
argument_list|,
argument|uint64_t VMAddr
argument_list|,
argument|uint64_t VMSize
argument_list|,
argument|uint64_t SectionDataStartOffset
argument_list|,
argument|uint64_t SectionDataSize
argument_list|,
argument|uint32_t MaxProt
argument_list|,
argument|uint32_t InitProt
argument_list|)
block|;
name|void
name|writeSection
argument_list|(
argument|const MCAsmLayout&Layout
argument_list|,
argument|const MCSection&Sec
argument_list|,
argument|uint64_t VMAddr
argument_list|,
argument|uint64_t FileOffset
argument_list|,
argument|unsigned Flags
argument_list|,
argument|uint64_t RelocationsStart
argument_list|,
argument|unsigned NumRelocations
argument_list|)
block|;
name|void
name|writeSymtabLoadCommand
argument_list|(
argument|uint32_t SymbolOffset
argument_list|,
argument|uint32_t NumSymbols
argument_list|,
argument|uint32_t StringTableOffset
argument_list|,
argument|uint32_t StringTableSize
argument_list|)
block|;
name|void
name|writeDysymtabLoadCommand
argument_list|(
argument|uint32_t FirstLocalSymbol
argument_list|,
argument|uint32_t NumLocalSymbols
argument_list|,
argument|uint32_t FirstExternalSymbol
argument_list|,
argument|uint32_t NumExternalSymbols
argument_list|,
argument|uint32_t FirstUndefinedSymbol
argument_list|,
argument|uint32_t NumUndefinedSymbols
argument_list|,
argument|uint32_t IndirectSymbolOffset
argument_list|,
argument|uint32_t NumIndirectSymbols
argument_list|)
block|;
name|void
name|writeNlist
argument_list|(
name|MachSymbolData
operator|&
name|MSD
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
block|;
name|void
name|writeLinkeditLoadCommand
argument_list|(
argument|uint32_t Type
argument_list|,
argument|uint32_t DataOffset
argument_list|,
argument|uint32_t DataSize
argument_list|)
block|;
name|void
name|writeLinkerOptionsLoadCommand
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|Options
argument_list|)
block|;
comment|// FIXME: We really need to improve the relocation validation. Basically, we
comment|// want to implement a separate computation which evaluates the relocation
comment|// entry as the linker would, and verifies that the resultant fixup value is
comment|// exactly what the encoder wanted. This will catch several classes of
comment|// problems:
comment|//
comment|//  - Relocation entry bugs, the two algorithms are unlikely to have the same
comment|//    exact bug.
comment|//
comment|//  - Relaxation issues, where we forget to relax something.
comment|//
comment|//  - Input errors, where something cannot be correctly encoded. 'as' allows
comment|//    these through in many cases.
comment|// Add a relocation to be output in the object file. At the time this is
comment|// called, the symbol indexes are not know, so if the relocation refers
comment|// to a symbol it should be passed as \p RelSymbol so that it can be updated
comment|// afterwards. If the relocation doesn't refer to a symbol, nullptr should be
comment|// used.
name|void
name|addRelocation
argument_list|(
argument|const MCSymbol *RelSymbol
argument_list|,
argument|const MCSection *Sec
argument_list|,
argument|MachO::any_relocation_info&MRE
argument_list|)
block|{
name|RelAndSymbol
name|P
argument_list|(
name|RelSymbol
argument_list|,
name|MRE
argument_list|)
block|;
name|Relocations
index|[
name|Sec
index|]
operator|.
name|push_back
argument_list|(
name|P
argument_list|)
block|;   }
name|void
name|recordScatteredRelocation
argument_list|(
argument|const MCAssembler&Asm
argument_list|,
argument|const MCAsmLayout&Layout
argument_list|,
argument|const MCFragment *Fragment
argument_list|,
argument|const MCFixup&Fixup
argument_list|,
argument|MCValue Target
argument_list|,
argument|unsigned Log2Size
argument_list|,
argument|uint64_t&FixedValue
argument_list|)
block|;
name|void
name|recordTLVPRelocation
argument_list|(
argument|const MCAssembler&Asm
argument_list|,
argument|const MCAsmLayout&Layout
argument_list|,
argument|const MCFragment *Fragment
argument_list|,
argument|const MCFixup&Fixup
argument_list|,
argument|MCValue Target
argument_list|,
argument|uint64_t&FixedValue
argument_list|)
block|;
name|void
name|recordRelocation
argument_list|(
argument|MCAssembler&Asm
argument_list|,
argument|const MCAsmLayout&Layout
argument_list|,
argument|const MCFragment *Fragment
argument_list|,
argument|const MCFixup&Fixup
argument_list|,
argument|MCValue Target
argument_list|,
argument|uint64_t&FixedValue
argument_list|)
name|override
block|;
name|void
name|bindIndirectSymbols
argument_list|(
name|MCAssembler
operator|&
name|Asm
argument_list|)
block|;
comment|/// Compute the symbol table data.
name|void
name|computeSymbolTable
argument_list|(
name|MCAssembler
operator|&
name|Asm
argument_list|,
name|std
operator|::
name|vector
operator|<
name|MachSymbolData
operator|>
operator|&
name|LocalSymbolData
argument_list|,
name|std
operator|::
name|vector
operator|<
name|MachSymbolData
operator|>
operator|&
name|ExternalSymbolData
argument_list|,
name|std
operator|::
name|vector
operator|<
name|MachSymbolData
operator|>
operator|&
name|UndefinedSymbolData
argument_list|)
block|;
name|void
name|computeSectionAddresses
argument_list|(
specifier|const
name|MCAssembler
operator|&
name|Asm
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
block|;
name|void
name|executePostLayoutBinding
argument_list|(
argument|MCAssembler&Asm
argument_list|,
argument|const MCAsmLayout&Layout
argument_list|)
name|override
block|;
name|bool
name|isSymbolRefDifferenceFullyResolvedImpl
argument_list|(
argument|const MCAssembler&Asm
argument_list|,
argument|const MCSymbol&A
argument_list|,
argument|const MCSymbol&B
argument_list|,
argument|bool InSet
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isSymbolRefDifferenceFullyResolvedImpl
argument_list|(
argument|const MCAssembler&Asm
argument_list|,
argument|const MCSymbol&SymA
argument_list|,
argument|const MCFragment&FB
argument_list|,
argument|bool InSet
argument_list|,
argument|bool IsPCRel
argument_list|)
specifier|const
name|override
block|;
name|void
name|writeObject
argument_list|(
argument|MCAssembler&Asm
argument_list|,
argument|const MCAsmLayout&Layout
argument_list|)
name|override
block|; }
decl_stmt|;
comment|/// Construct a new Mach-O writer instance.
comment|///
comment|/// This routine takes ownership of the target writer subclass.
comment|///
comment|/// \param MOTW - The target specific Mach-O writer subclass.
comment|/// \param OS - The stream to write to.
comment|/// \returns The constructed object writer.
name|MCObjectWriter
modifier|*
name|createMachObjectWriter
parameter_list|(
name|MCMachObjectTargetWriter
modifier|*
name|MOTW
parameter_list|,
name|raw_pwrite_stream
modifier|&
name|OS
parameter_list|,
name|bool
name|IsLittleEndian
parameter_list|)
function_decl|;
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
comment|// LLVM_MC_MCMACHOBJECTWRITER_H
end_comment

end_unit

