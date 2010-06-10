begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86ELFWriterInfo.h - ELF Writer Info for X86 ------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file implements ELF writer information for the X86 backend.
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
name|X86_ELF_WRITER_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|X86_ELF_WRITER_INFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetELFWriterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|X86ELFWriterInfo
range|:
name|public
name|TargetELFWriterInfo
block|{
comment|// ELF Relocation types for X86
block|enum
name|X86RelocationType
block|{
name|R_386_NONE
operator|=
literal|0
block|,
name|R_386_32
operator|=
literal|1
block|,
name|R_386_PC32
operator|=
literal|2
block|}
block|;
comment|// ELF Relocation types for X86_64
block|enum
name|X86_64RelocationType
block|{
name|R_X86_64_NONE
operator|=
literal|0
block|,
name|R_X86_64_64
operator|=
literal|1
block|,
name|R_X86_64_PC32
operator|=
literal|2
block|,
name|R_X86_64_32
operator|=
literal|10
block|,
name|R_X86_64_32S
operator|=
literal|11
block|,
name|R_X86_64_PC64
operator|=
literal|24
block|}
block|;
name|public
operator|:
name|X86ELFWriterInfo
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
name|virtual
operator|~
name|X86ELFWriterInfo
argument_list|()
block|;
comment|/// getRelocationType - Returns the target specific ELF Relocation type.
comment|/// 'MachineRelTy' contains the object code independent relocation type
name|virtual
name|unsigned
name|getRelocationType
argument_list|(
argument|unsigned MachineRelTy
argument_list|)
specifier|const
block|;
comment|/// hasRelocationAddend - True if the target uses an addend in the
comment|/// ELF relocation entry.
name|virtual
name|bool
name|hasRelocationAddend
argument_list|()
specifier|const
block|{
return|return
name|is64Bit
operator|?
name|true
operator|:
name|false
return|;
block|}
comment|/// getDefaultAddendForRelTy - Gets the default addend value for a
comment|/// relocation entry based on the target ELF relocation type.
name|virtual
name|long
name|int
name|getDefaultAddendForRelTy
argument_list|(
argument|unsigned RelTy
argument_list|,
argument|long int Modifier =
literal|0
argument_list|)
specifier|const
block|;
comment|/// getRelTySize - Returns the size of relocatable field in bits
name|virtual
name|unsigned
name|getRelocationTySize
argument_list|(
argument|unsigned RelTy
argument_list|)
specifier|const
block|;
comment|/// isPCRelativeRel - True if the relocation type is pc relative
name|virtual
name|bool
name|isPCRelativeRel
argument_list|(
argument|unsigned RelTy
argument_list|)
specifier|const
block|;
comment|/// getJumpTableRelocationTy - Returns the machine relocation type used
comment|/// to reference a jumptable.
name|virtual
name|unsigned
name|getAbsoluteLabelMachineRelTy
argument_list|()
specifier|const
block|;
comment|/// computeRelocation - Some relocatable fields could be relocated
comment|/// directly, avoiding the relocation symbol emission, compute the
comment|/// final relocation value for this symbol.
name|virtual
name|long
name|int
name|computeRelocation
argument_list|(
argument|unsigned SymOffset
argument_list|,
argument|unsigned RelOffset
argument_list|,
argument|unsigned RelTy
argument_list|)
specifier|const
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// X86_ELF_WRITER_INFO_H
end_comment

end_unit

