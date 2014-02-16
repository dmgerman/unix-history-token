begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCMachObjectWriter.h - Mach Object Writer -------*- C++ -*-===//
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
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
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
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MachO.h"
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
name|MCSectionData
decl_stmt|;
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
comment|// FIXME: Remove this, we should just always use it once we no longer care
comment|// about Darwin 'as' compatibility.
specifier|const
name|unsigned
name|UseAggressiveSymbolFolding
range|:
literal|1
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
argument_list|,
argument|bool UseAggressiveSymbolFolding_ = false
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
comment|/// @name Lifetime Management
comment|/// @{
name|virtual
name|void
name|reset
parameter_list|()
block|{}
empty_stmt|;
comment|/// @}
comment|/// @name Accessors
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
name|bool
name|useAggressiveSymbolFolding
argument_list|()
specifier|const
block|{
return|return
name|UseAggressiveSymbolFolding
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
comment|/// @name API
comment|/// @{
name|virtual
name|void
name|RecordRelocation
parameter_list|(
name|MachObjectWriter
modifier|*
name|Writer
parameter_list|,
specifier|const
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
comment|/// MachSymbolData - Helper struct for containing some precomputed information
comment|/// on symbols.
block|struct
name|MachSymbolData
block|{
name|MCSymbolData
operator|*
name|SymbolData
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
name|llvm
operator|::
name|OwningPtr
operator|<
name|MCMachObjectTargetWriter
operator|>
name|TargetObjectWriter
block|;
comment|/// @name Relocation Data
comment|/// @{
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|MCSectionData
operator|*
block|,
name|std
operator|::
name|vector
operator|<
name|MachO
operator|::
name|any_relocation_info
operator|>
expr|>
name|Relocations
block|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|MCSectionData
operator|*
block|,
name|unsigned
operator|>
name|IndirectSymBase
block|;
comment|/// @}
comment|/// @name Symbol Table Data
comment|/// @{
name|SmallString
operator|<
literal|256
operator|>
name|StringTable
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
name|public
operator|:
name|MachObjectWriter
argument_list|(
argument|MCMachObjectTargetWriter *MOTW
argument_list|,
argument|raw_ostream&_OS
argument_list|,
argument|bool _IsLittleEndian
argument_list|)
operator|:
name|MCObjectWriter
argument_list|(
name|_OS
argument_list|,
name|_IsLittleEndian
argument_list|)
block|,
name|TargetObjectWriter
argument_list|(
argument|MOTW
argument_list|)
block|{   }
comment|/// @name Lifetime management Methods
comment|/// @{
name|virtual
name|void
name|reset
argument_list|()
block|;
comment|/// @}
comment|/// @name Utility Methods
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
name|SectionAddress
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
argument|const MCSectionData* SD
argument_list|)
specifier|const
block|{
return|return
name|SectionAddress
operator|.
name|lookup
argument_list|(
name|SD
argument_list|)
return|;
block|}
name|uint64_t
name|getSymbolAddress
argument_list|(
argument|const MCSymbolData* SD
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
argument|const MCSectionData *SD
argument_list|,
argument|const MCAsmLayout&Layout
argument_list|)
specifier|const
block|;
name|bool
name|doesSymbolRequireExternRelocation
argument_list|(
specifier|const
name|MCSymbolData
operator|*
name|SD
argument_list|)
block|;
comment|/// @}
comment|/// @name Target Writer Proxy Accessors
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
name|isARM
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
operator|&
operator|~
name|MachO
operator|::
name|CPU_ARCH_MASK
block|;
return|return
name|CPUType
operator|==
name|MachO
operator|::
name|CPU_TYPE_ARM
return|;
block|}
comment|/// @}
name|void
name|WriteHeader
argument_list|(
argument|unsigned NumLoadCommands
argument_list|,
argument|unsigned LoadCommandsSize
argument_list|,
argument|bool SubsectionsViaSymbols
argument_list|)
block|;
comment|/// WriteSegmentLoadCommand - Write a segment load command.
comment|///
comment|/// \param NumSections The number of sections in this segment.
comment|/// \param SectionDataSize The total size of the sections.
name|void
name|WriteSegmentLoadCommand
argument_list|(
argument|unsigned NumSections
argument_list|,
argument|uint64_t VMSize
argument_list|,
argument|uint64_t SectionDataStartOffset
argument_list|,
argument|uint64_t SectionDataSize
argument_list|)
block|;
name|void
name|WriteSection
argument_list|(
argument|const MCAssembler&Asm
argument_list|,
argument|const MCAsmLayout&Layout
argument_list|,
argument|const MCSectionData&SD
argument_list|,
argument|uint64_t FileOffset
argument_list|,
argument|uint64_t RelocationsStart
argument_list|,
argument|unsigned NumRelocations
argument_list|)
block|;
name|void
name|WriteSymtabLoadCommand
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
name|WriteDysymtabLoadCommand
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
name|WriteNlist
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
name|WriteLinkeditLoadCommand
argument_list|(
argument|uint32_t Type
argument_list|,
argument|uint32_t DataOffset
argument_list|,
argument|uint32_t DataSize
argument_list|)
block|;
name|void
name|WriteLinkerOptionsLoadCommand
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
name|void
name|addRelocation
argument_list|(
argument|const MCSectionData *SD
argument_list|,
argument|MachO::any_relocation_info&MRE
argument_list|)
block|{
name|Relocations
index|[
name|SD
index|]
operator|.
name|push_back
argument_list|(
name|MRE
argument_list|)
block|;   }
name|void
name|RecordScatteredRelocation
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
name|RecordTLVPRelocation
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
name|RecordRelocation
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
name|BindIndirectSymbols
argument_list|(
name|MCAssembler
operator|&
name|Asm
argument_list|)
block|;
comment|/// ComputeSymbolTable - Compute the symbol table data
comment|///
comment|/// \param StringTable [out] - The string table data.
name|void
name|ComputeSymbolTable
argument_list|(
name|MCAssembler
operator|&
name|Asm
argument_list|,
name|SmallString
operator|<
literal|256
operator|>
operator|&
name|StringTable
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
name|markAbsoluteVariableSymbols
argument_list|(
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
name|ExecutePostLayoutBinding
argument_list|(
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
name|virtual
name|bool
name|IsSymbolRefDifferenceFullyResolvedImpl
argument_list|(
argument|const MCAssembler&Asm
argument_list|,
argument|const MCSymbolData&DataA
argument_list|,
argument|const MCFragment&FB
argument_list|,
argument|bool InSet
argument_list|,
argument|bool IsPCRel
argument_list|)
specifier|const
block|;
name|void
name|WriteObject
argument_list|(
name|MCAssembler
operator|&
name|Asm
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
block|; }
decl_stmt|;
comment|/// \brief Construct a new Mach-O writer instance.
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
name|raw_ostream
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
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

