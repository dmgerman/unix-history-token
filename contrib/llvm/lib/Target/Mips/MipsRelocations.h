begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsRelocations.h - Mips Code Relocations ---------------*- C++ -*-===//
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
comment|// This file defines the Mips target-specific relocation types
end_comment

begin_comment
comment|// (for relocation-model=static).
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
name|MIPSRELOCATIONS_H_
end_ifndef

begin_define
define|#
directive|define
name|MIPSRELOCATIONS_H_
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineRelocation.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|Mips
block|{
enum|enum
name|RelocationType
block|{
comment|// reloc_mips_pc16 - pc relative relocation for branches. The lower 18
comment|// bits of the difference between the branch target and the branch
comment|// instruction, shifted right by 2.
name|reloc_mips_pc16
init|=
literal|1
block|,
comment|// reloc_mips_hi - upper 16 bits of the address (modified by +1 if the
comment|// lower 16 bits of the address is negative).
name|reloc_mips_hi
init|=
literal|2
block|,
comment|// reloc_mips_lo - lower 16 bits of the address.
name|reloc_mips_lo
init|=
literal|3
block|,
comment|// reloc_mips_26 - lower 28 bits of the address, shifted right by 2.
name|reloc_mips_26
init|=
literal|4
block|}
enum|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MIPSRELOCATIONS_H_ */
end_comment

end_unit

