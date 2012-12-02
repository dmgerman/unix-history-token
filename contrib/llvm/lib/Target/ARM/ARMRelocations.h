begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMRelocations.h - ARM Code Relocations -----------------*- C++ -*-===//
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
comment|// This file defines the ARM target-specific relocation types.
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
name|ARMRELOCATIONS_H
end_ifndef

begin_define
define|#
directive|define
name|ARMRELOCATIONS_H
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
name|ARM
block|{
enum|enum
name|RelocationType
block|{
comment|// reloc_arm_absolute - Absolute relocation, just add the relocated value
comment|// to the value already in memory.
name|reloc_arm_absolute
block|,
comment|// reloc_arm_relative - PC relative relocation, add the relocated value to
comment|// the value already in memory, after we adjust it for where the PC is.
name|reloc_arm_relative
block|,
comment|// reloc_arm_cp_entry - PC relative relocation for constpool_entry's whose
comment|// addresses are kept locally in a map.
name|reloc_arm_cp_entry
block|,
comment|// reloc_arm_vfp_cp_entry - Same as reloc_arm_cp_entry except the offset
comment|// should be divided by 4.
name|reloc_arm_vfp_cp_entry
block|,
comment|// reloc_arm_machine_cp_entry - Relocation of a ARM machine constantpool
comment|// entry.
name|reloc_arm_machine_cp_entry
block|,
comment|// reloc_arm_jt_base - PC relative relocation for jump tables whose
comment|// addresses are kept locally in a map.
name|reloc_arm_jt_base
block|,
comment|// reloc_arm_pic_jt - PIC jump table entry relocation: dest bb - jt base.
name|reloc_arm_pic_jt
block|,
comment|// reloc_arm_branch - Branch address relocation.
name|reloc_arm_branch
block|,
comment|// reloc_arm_movt  - MOVT immediate relocation.
name|reloc_arm_movt
block|,
comment|// reloc_arm_movw  - MOVW immediate relocation.
name|reloc_arm_movw
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

