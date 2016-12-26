begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lldb-s390x-register-enums.h -----------------------------*- C++ -*-===//
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
name|lldb_s390x_register_enums_h
end_ifndef

begin_define
define|#
directive|define
name|lldb_s390x_register_enums_h
end_define

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// LLDB register codes (e.g. RegisterKind == eRegisterKindLLDB)
comment|//---------------------------------------------------------------------------
comment|// Internal codes for all s390x registers.
comment|//---------------------------------------------------------------------------
enum|enum
block|{
name|k_first_gpr_s390x
block|,
name|lldb_r0_s390x
init|=
name|k_first_gpr_s390x
block|,
name|lldb_r1_s390x
block|,
name|lldb_r2_s390x
block|,
name|lldb_r3_s390x
block|,
name|lldb_r4_s390x
block|,
name|lldb_r5_s390x
block|,
name|lldb_r6_s390x
block|,
name|lldb_r7_s390x
block|,
name|lldb_r8_s390x
block|,
name|lldb_r9_s390x
block|,
name|lldb_r10_s390x
block|,
name|lldb_r11_s390x
block|,
name|lldb_r12_s390x
block|,
name|lldb_r13_s390x
block|,
name|lldb_r14_s390x
block|,
name|lldb_r15_s390x
block|,
name|lldb_acr0_s390x
block|,
name|lldb_acr1_s390x
block|,
name|lldb_acr2_s390x
block|,
name|lldb_acr3_s390x
block|,
name|lldb_acr4_s390x
block|,
name|lldb_acr5_s390x
block|,
name|lldb_acr6_s390x
block|,
name|lldb_acr7_s390x
block|,
name|lldb_acr8_s390x
block|,
name|lldb_acr9_s390x
block|,
name|lldb_acr10_s390x
block|,
name|lldb_acr11_s390x
block|,
name|lldb_acr12_s390x
block|,
name|lldb_acr13_s390x
block|,
name|lldb_acr14_s390x
block|,
name|lldb_acr15_s390x
block|,
name|lldb_pswm_s390x
block|,
name|lldb_pswa_s390x
block|,
name|k_last_gpr_s390x
init|=
name|lldb_pswa_s390x
block|,
name|k_first_fpr_s390x
block|,
name|lldb_f0_s390x
init|=
name|k_first_fpr_s390x
block|,
name|lldb_f1_s390x
block|,
name|lldb_f2_s390x
block|,
name|lldb_f3_s390x
block|,
name|lldb_f4_s390x
block|,
name|lldb_f5_s390x
block|,
name|lldb_f6_s390x
block|,
name|lldb_f7_s390x
block|,
name|lldb_f8_s390x
block|,
name|lldb_f9_s390x
block|,
name|lldb_f10_s390x
block|,
name|lldb_f11_s390x
block|,
name|lldb_f12_s390x
block|,
name|lldb_f13_s390x
block|,
name|lldb_f14_s390x
block|,
name|lldb_f15_s390x
block|,
name|lldb_fpc_s390x
block|,
name|k_last_fpr_s390x
init|=
name|lldb_fpc_s390x
block|,
comment|// These are only available on Linux.
name|k_first_linux_s390x
block|,
name|lldb_orig_r2_s390x
init|=
name|k_first_linux_s390x
block|,
name|lldb_last_break_s390x
block|,
name|lldb_system_call_s390x
block|,
name|k_last_linux_s390x
init|=
name|lldb_system_call_s390x
block|,
name|k_num_registers_s390x
block|,
name|k_num_gpr_registers_s390x
init|=
name|k_last_gpr_s390x
operator|-
name|k_first_gpr_s390x
operator|+
literal|1
block|,
name|k_num_fpr_registers_s390x
init|=
name|k_last_fpr_s390x
operator|-
name|k_first_fpr_s390x
operator|+
literal|1
block|,
name|k_num_linux_registers_s390x
init|=
name|k_last_linux_s390x
operator|-
name|k_first_linux_s390x
operator|+
literal|1
block|,
name|k_num_user_registers_s390x
init|=
name|k_num_gpr_registers_s390x
operator|+
name|k_num_fpr_registers_s390x
block|, }
enum|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef lldb_s390x_register_enums_h
end_comment

end_unit

