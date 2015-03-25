begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AArch64FixupKinds.h - AArch64 Specific Fixup Entries ----*- C++ -*-===//
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
name|LLVM_LIB_TARGET_AARCH64_MCTARGETDESC_AARCH64FIXUPKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AARCH64_MCTARGETDESC_AARCH64FIXUPKINDS_H
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
name|AArch64
block|{
enum|enum
name|Fixups
block|{
comment|// fixup_aarch64_pcrel_adr_imm21 - A 21-bit pc-relative immediate inserted into
comment|// an ADR instruction.
name|fixup_aarch64_pcrel_adr_imm21
init|=
name|FirstTargetFixupKind
block|,
comment|// fixup_aarch64_pcrel_adrp_imm21 - A 21-bit pc-relative immediate inserted into
comment|// an ADRP instruction.
name|fixup_aarch64_pcrel_adrp_imm21
block|,
comment|// fixup_aarch64_imm12 - 12-bit fixup for add/sub instructions.
comment|//     No alignment adjustment. All value bits are encoded.
name|fixup_aarch64_add_imm12
block|,
comment|// fixup_aarch64_ldst_imm12_* - unsigned 12-bit fixups for load and
comment|// store instructions.
name|fixup_aarch64_ldst_imm12_scale1
block|,
name|fixup_aarch64_ldst_imm12_scale2
block|,
name|fixup_aarch64_ldst_imm12_scale4
block|,
name|fixup_aarch64_ldst_imm12_scale8
block|,
name|fixup_aarch64_ldst_imm12_scale16
block|,
comment|// fixup_aarch64_ldr_pcrel_imm19 - The high 19 bits of a 21-bit pc-relative
comment|// immediate. Same encoding as fixup_aarch64_pcrel_adrhi, except this is used by
comment|// pc-relative loads and generates relocations directly when necessary.
name|fixup_aarch64_ldr_pcrel_imm19
block|,
comment|// FIXME: comment
name|fixup_aarch64_movw
block|,
comment|// fixup_aarch64_pcrel_imm14 - The high 14 bits of a 21-bit pc-relative
comment|// immediate.
name|fixup_aarch64_pcrel_branch14
block|,
comment|// fixup_aarch64_pcrel_branch19 - The high 19 bits of a 21-bit pc-relative
comment|// immediate. Same encoding as fixup_aarch64_pcrel_adrhi, except this is use by
comment|// b.cc and generates relocations directly when necessary.
name|fixup_aarch64_pcrel_branch19
block|,
comment|// fixup_aarch64_pcrel_branch26 - The high 26 bits of a 28-bit pc-relative
comment|// immediate.
name|fixup_aarch64_pcrel_branch26
block|,
comment|// fixup_aarch64_pcrel_call26 - The high 26 bits of a 28-bit pc-relative
comment|// immediate. Distinguished from branch26 only on ELF.
name|fixup_aarch64_pcrel_call26
block|,
comment|// fixup_aarch64_tlsdesc_call - zero-space placeholder for the ELF
comment|// R_AARCH64_TLSDESC_CALL relocation.
name|fixup_aarch64_tlsdesc_call
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
comment|// end namespace AArch64
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

