begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCMachOWriterInfo.h - Mach-O Writer Info for PowerPC ---*- C++ -*-===//
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
comment|// This file implements Mach-O writer information for the PowerPC backend.
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
name|PPC_MACHO_WRITER_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|PPC_MACHO_WRITER_INFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachOWriterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Forward declarations
name|class
name|MachineRelocation
decl_stmt|;
name|class
name|OutputBuffer
decl_stmt|;
name|class
name|PPCTargetMachine
decl_stmt|;
name|class
name|PPCMachOWriterInfo
range|:
name|public
name|TargetMachOWriterInfo
block|{
name|public
operator|:
name|PPCMachOWriterInfo
argument_list|(
specifier|const
name|PPCTargetMachine
operator|&
name|TM
argument_list|)
block|;
name|virtual
operator|~
name|PPCMachOWriterInfo
argument_list|()
block|;
name|virtual
name|unsigned
name|GetTargetRelocation
argument_list|(
argument|MachineRelocation&MR
argument_list|,
argument|unsigned FromIdx
argument_list|,
argument|unsigned ToAddr
argument_list|,
argument|unsigned ToIdx
argument_list|,
argument|OutputBuffer&RelocOut
argument_list|,
argument|OutputBuffer&SecOut
argument_list|,
argument|bool Scattered
argument_list|,
argument|bool Extern
argument_list|)
specifier|const
block|;
comment|// Constants for the relocation r_type field.
comment|// See<mach-o/ppc/reloc.h>
block|enum
block|{
name|PPC_RELOC_VANILLA
block|,
comment|// generic relocation
name|PPC_RELOC_PAIR
block|,
comment|// the second relocation entry of a pair
name|PPC_RELOC_BR14
block|,
comment|// 14 bit branch displacement to word address
name|PPC_RELOC_BR24
block|,
comment|// 24 bit branch displacement to word address
name|PPC_RELOC_HI16
block|,
comment|// a PAIR follows with the low 16 bits
name|PPC_RELOC_LO16
block|,
comment|// a PAIR follows with the high 16 bits
name|PPC_RELOC_HA16
block|,
comment|// a PAIR follows, which is sign extended to 32b
name|PPC_RELOC_LO14
comment|// LO16 with low 2 bits implicitly zero
block|}
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
comment|// PPC_MACHO_WRITER_INFO_H
end_comment

end_unit

