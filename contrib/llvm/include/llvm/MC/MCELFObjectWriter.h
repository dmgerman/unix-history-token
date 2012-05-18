begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCELFObjectWriter.h - ELF Object Writer ---------*- C++ -*-===//
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
name|LLVM_MC_MCELFOBJECTWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCELFOBJECTWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ELF.h"
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
name|MCAssembler
decl_stmt|;
name|class
name|MCFixup
decl_stmt|;
name|class
name|MCFragment
decl_stmt|;
name|class
name|MCObjectWriter
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MCValue
decl_stmt|;
comment|/// @name Relocation Data
comment|/// @{
struct|struct
name|ELFRelocationEntry
block|{
comment|// Make these big enough for both 32-bit and 64-bit
name|uint64_t
name|r_offset
decl_stmt|;
name|int
name|Index
decl_stmt|;
name|unsigned
name|Type
decl_stmt|;
specifier|const
name|MCSymbol
modifier|*
name|Symbol
decl_stmt|;
name|uint64_t
name|r_addend
decl_stmt|;
specifier|const
name|MCFixup
modifier|*
name|Fixup
decl_stmt|;
name|ELFRelocationEntry
argument_list|()
operator|:
name|r_offset
argument_list|(
literal|0
argument_list|)
operator|,
name|Index
argument_list|(
literal|0
argument_list|)
operator|,
name|Type
argument_list|(
literal|0
argument_list|)
operator|,
name|Symbol
argument_list|(
literal|0
argument_list|)
operator|,
name|r_addend
argument_list|(
literal|0
argument_list|)
operator|,
name|Fixup
argument_list|(
literal|0
argument_list|)
block|{}
name|ELFRelocationEntry
argument_list|(
argument|uint64_t RelocOffset
argument_list|,
argument|int Idx
argument_list|,
argument|unsigned RelType
argument_list|,
argument|const MCSymbol *Sym
argument_list|,
argument|uint64_t Addend
argument_list|,
argument|const MCFixup&Fixup
argument_list|)
operator|:
name|r_offset
argument_list|(
name|RelocOffset
argument_list|)
operator|,
name|Index
argument_list|(
name|Idx
argument_list|)
operator|,
name|Type
argument_list|(
name|RelType
argument_list|)
operator|,
name|Symbol
argument_list|(
name|Sym
argument_list|)
operator|,
name|r_addend
argument_list|(
name|Addend
argument_list|)
operator|,
name|Fixup
argument_list|(
argument|&Fixup
argument_list|)
block|{}
comment|// Support lexicographic sorting.
name|bool
name|operator
operator|<
operator|(
specifier|const
name|ELFRelocationEntry
operator|&
name|RE
operator|)
specifier|const
block|{
return|return
name|RE
operator|.
name|r_offset
operator|<
name|r_offset
return|;
block|}
block|}
struct|;
name|class
name|MCELFObjectTargetWriter
block|{
specifier|const
name|uint8_t
name|OSABI
decl_stmt|;
specifier|const
name|uint16_t
name|EMachine
decl_stmt|;
specifier|const
name|unsigned
name|HasRelocationAddend
range|:
literal|1
decl_stmt|;
specifier|const
name|unsigned
name|Is64Bit
range|:
literal|1
decl_stmt|;
name|protected
label|:
name|MCELFObjectTargetWriter
argument_list|(
argument|bool Is64Bit_
argument_list|,
argument|uint8_t OSABI_
argument_list|,
argument|uint16_t EMachine_
argument_list|,
argument|bool HasRelocationAddend_
argument_list|)
empty_stmt|;
name|public
label|:
specifier|static
name|uint8_t
name|getOSABI
argument_list|(
name|Triple
operator|::
name|OSType
name|OSType
argument_list|)
block|{
switch|switch
condition|(
name|OSType
condition|)
block|{
case|case
name|Triple
operator|::
name|FreeBSD
case|:
return|return
name|ELF
operator|::
name|ELFOSABI_FREEBSD
return|;
case|case
name|Triple
operator|::
name|Linux
case|:
return|return
name|ELF
operator|::
name|ELFOSABI_LINUX
return|;
default|default:
return|return
name|ELF
operator|::
name|ELFOSABI_NONE
return|;
block|}
block|}
name|virtual
operator|~
name|MCELFObjectTargetWriter
argument_list|()
block|{}
name|virtual
name|unsigned
name|GetRelocType
argument_list|(
argument|const MCValue&Target
argument_list|,
argument|const MCFixup&Fixup
argument_list|,
argument|bool IsPCRel
argument_list|,
argument|bool IsRelocWithSymbol
argument_list|,
argument|int64_t Addend
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|unsigned
name|getEFlags
argument_list|()
specifier|const
expr_stmt|;
name|virtual
specifier|const
name|MCSymbol
modifier|*
name|ExplicitRelSym
argument_list|(
specifier|const
name|MCAssembler
operator|&
name|Asm
argument_list|,
specifier|const
name|MCValue
operator|&
name|Target
argument_list|,
specifier|const
name|MCFragment
operator|&
name|F
argument_list|,
specifier|const
name|MCFixup
operator|&
name|Fixup
argument_list|,
name|bool
name|IsPCRel
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|adjustFixupOffset
parameter_list|(
specifier|const
name|MCFixup
modifier|&
name|Fixup
parameter_list|,
name|uint64_t
modifier|&
name|RelocOffset
parameter_list|)
function_decl|;
name|virtual
name|void
name|sortRelocs
argument_list|(
specifier|const
name|MCAssembler
operator|&
name|Asm
argument_list|,
name|std
operator|::
name|vector
operator|<
name|ELFRelocationEntry
operator|>
operator|&
name|Relocs
argument_list|)
decl_stmt|;
comment|/// @name Accessors
comment|/// @{
name|uint8_t
name|getOSABI
parameter_list|()
block|{
return|return
name|OSABI
return|;
block|}
name|uint16_t
name|getEMachine
parameter_list|()
block|{
return|return
name|EMachine
return|;
block|}
name|bool
name|hasRelocationAddend
parameter_list|()
block|{
return|return
name|HasRelocationAddend
return|;
block|}
name|bool
name|is64Bit
argument_list|()
specifier|const
block|{
return|return
name|Is64Bit
return|;
block|}
comment|/// @}
block|}
empty_stmt|;
comment|/// \brief Construct a new ELF writer instance.
comment|///
comment|/// \param MOTW - The target specific ELF writer subclass.
comment|/// \param OS - The stream to write to.
comment|/// \returns The constructed object writer.
name|MCObjectWriter
modifier|*
name|createELFObjectWriter
parameter_list|(
name|MCELFObjectTargetWriter
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

