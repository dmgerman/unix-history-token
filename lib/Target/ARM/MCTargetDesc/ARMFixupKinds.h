begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMFixupKinds.h - ARM Specific Fixup Entries ------------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_ARM_MCTARGETDESC_ARMFIXUPKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_MCTARGETDESC_ARMFIXUPKINDS_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCFixup.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|ARM
block|{
enum|enum
name|Fixups
block|{
comment|// fixup_arm_ldst_pcrel_12 - 12-bit PC relative relocation for symbol
comment|// addresses
name|fixup_arm_ldst_pcrel_12
init|=
name|FirstTargetFixupKind
block|,
comment|// fixup_t2_ldst_pcrel_12 - Equivalent to fixup_arm_ldst_pcrel_12, with
comment|// the 16-bit halfwords reordered.
name|fixup_t2_ldst_pcrel_12
block|,
comment|// fixup_arm_pcrel_10_unscaled - 10-bit PC relative relocation for symbol
comment|// addresses used in LDRD/LDRH/LDRB/etc. instructions. All bits are encoded.
name|fixup_arm_pcrel_10_unscaled
block|,
comment|// fixup_arm_pcrel_10 - 10-bit PC relative relocation for symbol addresses
comment|// used in VFP instructions where the lower 2 bits are not encoded
comment|// (so it's encoded as an 8-bit immediate).
name|fixup_arm_pcrel_10
block|,
comment|// fixup_t2_pcrel_10 - Equivalent to fixup_arm_pcrel_10, accounting for
comment|// the short-swapped encoding of Thumb2 instructions.
name|fixup_t2_pcrel_10
block|,
comment|// fixup_arm_pcrel_9 - 9-bit PC relative relocation for symbol addresses
comment|// used in VFP instructions where bit 0 not encoded (so it's encoded as an
comment|// 8-bit immediate).
name|fixup_arm_pcrel_9
block|,
comment|// fixup_t2_pcrel_9 - Equivalent to fixup_arm_pcrel_9, accounting for
comment|// the short-swapped encoding of Thumb2 instructions.
name|fixup_t2_pcrel_9
block|,
comment|// fixup_thumb_adr_pcrel_10 - 10-bit PC relative relocation for symbol
comment|// addresses where the lower 2 bits are not encoded (so it's encoded as an
comment|// 8-bit immediate).
name|fixup_thumb_adr_pcrel_10
block|,
comment|// fixup_arm_adr_pcrel_12 - 12-bit PC relative relocation for the ADR
comment|// instruction.
name|fixup_arm_adr_pcrel_12
block|,
comment|// fixup_t2_adr_pcrel_12 - 12-bit PC relative relocation for the ADR
comment|// instruction.
name|fixup_t2_adr_pcrel_12
block|,
comment|// fixup_arm_condbranch - 24-bit PC relative relocation for conditional branch
comment|// instructions.
name|fixup_arm_condbranch
block|,
comment|// fixup_arm_uncondbranch - 24-bit PC relative relocation for
comment|// branch instructions. (unconditional)
name|fixup_arm_uncondbranch
block|,
comment|// fixup_t2_condbranch - 20-bit PC relative relocation for Thumb2 direct
comment|// uconditional branch instructions.
name|fixup_t2_condbranch
block|,
comment|// fixup_t2_uncondbranch - 20-bit PC relative relocation for Thumb2 direct
comment|// branch unconditional branch instructions.
name|fixup_t2_uncondbranch
block|,
comment|// fixup_arm_thumb_br - 12-bit fixup for Thumb B instructions.
name|fixup_arm_thumb_br
block|,
comment|// The following fixups handle the ARM BL instructions. These can be
comment|// conditionalised; however, the ARM ELF ABI requires a different relocation
comment|// in that case: R_ARM_JUMP24 instead of R_ARM_CALL. The difference is that
comment|// R_ARM_CALL is allowed to change the instruction to a BLX inline, which has
comment|// no conditional version; R_ARM_JUMP24 would have to insert a veneer.
comment|//
comment|// MachO does not draw a distinction between the two cases, so it will treat
comment|// fixup_arm_uncondbl and fixup_arm_condbl as identical fixups.
comment|// fixup_arm_uncondbl - Fixup for unconditional ARM BL instructions.
name|fixup_arm_uncondbl
block|,
comment|// fixup_arm_condbl - Fixup for ARM BL instructions with nontrivial
comment|// conditionalisation.
name|fixup_arm_condbl
block|,
comment|// fixup_arm_blx - Fixup for ARM BLX instructions.
name|fixup_arm_blx
block|,
comment|// fixup_arm_thumb_bl - Fixup for Thumb BL instructions.
name|fixup_arm_thumb_bl
block|,
comment|// fixup_arm_thumb_blx - Fixup for Thumb BLX instructions.
name|fixup_arm_thumb_blx
block|,
comment|// fixup_arm_thumb_cb - Fixup for Thumb branch instructions.
name|fixup_arm_thumb_cb
block|,
comment|// fixup_arm_thumb_cp - Fixup for Thumb load/store from constant pool instrs.
name|fixup_arm_thumb_cp
block|,
comment|// fixup_arm_thumb_bcc - Fixup for Thumb conditional branching instructions.
name|fixup_arm_thumb_bcc
block|,
comment|// The next two are for the movt/movw pair
comment|// the 16bit imm field are split into imm{15-12} and imm{11-0}
name|fixup_arm_movt_hi16
block|,
comment|// :upper16:
name|fixup_arm_movw_lo16
block|,
comment|// :lower16:
name|fixup_t2_movt_hi16
block|,
comment|// :upper16:
name|fixup_t2_movw_lo16
block|,
comment|// :lower16:
comment|// fixup_arm_mod_imm - Fixup for mod_imm
name|fixup_arm_mod_imm
block|,
comment|// fixup_t2_so_imm - Fixup for Thumb2 8-bit rotated operand
name|fixup_t2_so_imm
block|,
comment|// Marker
name|LastTargetFixupKind
block|,
name|NumTargetFixupKinds
init|=
name|LastTargetFixupKind
operator|-
name|FirstTargetFixupKind
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

