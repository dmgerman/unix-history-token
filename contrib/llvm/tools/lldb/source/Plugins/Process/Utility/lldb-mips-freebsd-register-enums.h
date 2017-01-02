begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lldb-mips-freebsd-register-enums.h ----------------------*- C++ -*-===//
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
name|lldb_mips_freebsd_register_enums_h
end_ifndef

begin_define
define|#
directive|define
name|lldb_mips_freebsd_register_enums_h
end_define

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// LLDB register codes (e.g. RegisterKind == eRegisterKindLLDB)
comment|//---------------------------------------------------------------------------
comment|// Internal codes for all mips registers.
comment|//---------------------------------------------------------------------------
enum|enum
block|{
name|k_first_gpr_mips64
block|,
name|gpr_zero_mips64
init|=
name|k_first_gpr_mips64
block|,
name|gpr_r1_mips64
block|,
name|gpr_r2_mips64
block|,
name|gpr_r3_mips64
block|,
name|gpr_r4_mips64
block|,
name|gpr_r5_mips64
block|,
name|gpr_r6_mips64
block|,
name|gpr_r7_mips64
block|,
name|gpr_r8_mips64
block|,
name|gpr_r9_mips64
block|,
name|gpr_r10_mips64
block|,
name|gpr_r11_mips64
block|,
name|gpr_r12_mips64
block|,
name|gpr_r13_mips64
block|,
name|gpr_r14_mips64
block|,
name|gpr_r15_mips64
block|,
name|gpr_r16_mips64
block|,
name|gpr_r17_mips64
block|,
name|gpr_r18_mips64
block|,
name|gpr_r19_mips64
block|,
name|gpr_r20_mips64
block|,
name|gpr_r21_mips64
block|,
name|gpr_r22_mips64
block|,
name|gpr_r23_mips64
block|,
name|gpr_r24_mips64
block|,
name|gpr_r25_mips64
block|,
name|gpr_r26_mips64
block|,
name|gpr_r27_mips64
block|,
name|gpr_gp_mips64
block|,
name|gpr_sp_mips64
block|,
name|gpr_r30_mips64
block|,
name|gpr_ra_mips64
block|,
name|gpr_sr_mips64
block|,
name|gpr_mullo_mips64
block|,
name|gpr_mulhi_mips64
block|,
name|gpr_badvaddr_mips64
block|,
name|gpr_cause_mips64
block|,
name|gpr_pc_mips64
block|,
name|gpr_ic_mips64
block|,
name|gpr_dummy_mips64
block|,
name|k_last_gpr_mips64
init|=
name|gpr_dummy_mips64
block|,
name|k_num_registers_mips64
block|,
name|k_num_gpr_registers_mips64
init|=
name|k_last_gpr_mips64
operator|-
name|k_first_gpr_mips64
operator|+
literal|1
block|}
enum|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef lldb_mips_freebsd_register_enums_h
end_comment

end_unit

