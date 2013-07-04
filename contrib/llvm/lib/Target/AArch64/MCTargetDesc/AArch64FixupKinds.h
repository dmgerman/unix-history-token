begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- AArch64/AArch64FixupKinds.h - AArch64 Specific Fixup Entries -*- C++ -*-=//
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
comment|// This file describes the LLVM fixups applied to MCInsts in the AArch64
end_comment

begin_comment
comment|// backend.
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
name|LLVM_AARCH64_AARCH64FIXUPKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AARCH64_AARCH64FIXUPKINDS_H
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
name|fixup_a64_ld_prel
init|=
name|FirstTargetFixupKind
block|,
name|fixup_a64_adr_prel
block|,
name|fixup_a64_adr_prel_page
block|,
name|fixup_a64_add_lo12
block|,
name|fixup_a64_ldst8_lo12
block|,
name|fixup_a64_ldst16_lo12
block|,
name|fixup_a64_ldst32_lo12
block|,
name|fixup_a64_ldst64_lo12
block|,
name|fixup_a64_ldst128_lo12
block|,
name|fixup_a64_tstbr
block|,
name|fixup_a64_condbr
block|,
name|fixup_a64_uncondbr
block|,
name|fixup_a64_call
block|,
name|fixup_a64_movw_uabs_g0
block|,
name|fixup_a64_movw_uabs_g0_nc
block|,
name|fixup_a64_movw_uabs_g1
block|,
name|fixup_a64_movw_uabs_g1_nc
block|,
name|fixup_a64_movw_uabs_g2
block|,
name|fixup_a64_movw_uabs_g2_nc
block|,
name|fixup_a64_movw_uabs_g3
block|,
name|fixup_a64_movw_sabs_g0
block|,
name|fixup_a64_movw_sabs_g1
block|,
name|fixup_a64_movw_sabs_g2
block|,
name|fixup_a64_adr_prel_got_page
block|,
name|fixup_a64_ld64_got_lo12_nc
block|,
comment|// Produce offsets relative to the module's dynamic TLS area.
name|fixup_a64_movw_dtprel_g2
block|,
name|fixup_a64_movw_dtprel_g1
block|,
name|fixup_a64_movw_dtprel_g1_nc
block|,
name|fixup_a64_movw_dtprel_g0
block|,
name|fixup_a64_movw_dtprel_g0_nc
block|,
name|fixup_a64_add_dtprel_hi12
block|,
name|fixup_a64_add_dtprel_lo12
block|,
name|fixup_a64_add_dtprel_lo12_nc
block|,
name|fixup_a64_ldst8_dtprel_lo12
block|,
name|fixup_a64_ldst8_dtprel_lo12_nc
block|,
name|fixup_a64_ldst16_dtprel_lo12
block|,
name|fixup_a64_ldst16_dtprel_lo12_nc
block|,
name|fixup_a64_ldst32_dtprel_lo12
block|,
name|fixup_a64_ldst32_dtprel_lo12_nc
block|,
name|fixup_a64_ldst64_dtprel_lo12
block|,
name|fixup_a64_ldst64_dtprel_lo12_nc
block|,
comment|// Produce the GOT entry containing a variable's address in TLS's
comment|// initial-exec mode.
name|fixup_a64_movw_gottprel_g1
block|,
name|fixup_a64_movw_gottprel_g0_nc
block|,
name|fixup_a64_adr_gottprel_page
block|,
name|fixup_a64_ld64_gottprel_lo12_nc
block|,
name|fixup_a64_ld_gottprel_prel19
block|,
comment|// Produce offsets relative to the thread pointer: TPIDR_EL0.
name|fixup_a64_movw_tprel_g2
block|,
name|fixup_a64_movw_tprel_g1
block|,
name|fixup_a64_movw_tprel_g1_nc
block|,
name|fixup_a64_movw_tprel_g0
block|,
name|fixup_a64_movw_tprel_g0_nc
block|,
name|fixup_a64_add_tprel_hi12
block|,
name|fixup_a64_add_tprel_lo12
block|,
name|fixup_a64_add_tprel_lo12_nc
block|,
name|fixup_a64_ldst8_tprel_lo12
block|,
name|fixup_a64_ldst8_tprel_lo12_nc
block|,
name|fixup_a64_ldst16_tprel_lo12
block|,
name|fixup_a64_ldst16_tprel_lo12_nc
block|,
name|fixup_a64_ldst32_tprel_lo12
block|,
name|fixup_a64_ldst32_tprel_lo12_nc
block|,
name|fixup_a64_ldst64_tprel_lo12
block|,
name|fixup_a64_ldst64_tprel_lo12_nc
block|,
comment|// Produce the special fixups used by the general-dynamic TLS model.
name|fixup_a64_tlsdesc_adr_page
block|,
name|fixup_a64_tlsdesc_ld64_lo12_nc
block|,
name|fixup_a64_tlsdesc_add_lo12_nc
block|,
name|fixup_a64_tlsdesc_call
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

