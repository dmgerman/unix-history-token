begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCRelocations.h - PPC Code Relocations -----------------*- C++ -*-===//
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
comment|// This file defines the PowerPC 32-bit target-specific relocation types.
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
name|PPCRELOCATIONS_H
end_ifndef

begin_define
define|#
directive|define
name|PPCRELOCATIONS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineRelocation.h"
end_include

begin_comment
comment|// Hack to rid us of a PPC pre-processor symbol which is erroneously
end_comment

begin_comment
comment|// defined in a PowerPC header file (bug in Linux/PPC)
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PPC
end_ifdef

begin_undef
undef|#
directive|undef
name|PPC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|PPC
block|{
enum|enum
name|RelocationType
block|{
comment|// reloc_vanilla - A standard relocation, where the address of the
comment|// relocated object completely overwrites the address of the relocation.
name|reloc_vanilla
block|,
comment|// reloc_pcrel_bx - PC relative relocation, for the b or bl instructions.
name|reloc_pcrel_bx
block|,
comment|// reloc_pcrel_bcx - PC relative relocation, for BLT,BLE,BEQ,BGE,BGT,BNE,
comment|// and other bcx instructions.
name|reloc_pcrel_bcx
block|,
comment|// reloc_absolute_high - Absolute relocation, for the loadhi instruction
comment|// (which is really addis).  Add the high 16-bits of the specified global
comment|// address into the low 16-bits of the instruction.
name|reloc_absolute_high
block|,
comment|// reloc_absolute_low - Absolute relocation, for the la instruction (which
comment|// is really an addi).  Add the low 16-bits of the specified global
comment|// address into the low 16-bits of the instruction.
name|reloc_absolute_low
block|,
comment|// reloc_absolute_low_ix - Absolute relocation for the 64-bit load/store
comment|// instruction which have two implicit zero bits.
name|reloc_absolute_low_ix
block|}
enum|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

