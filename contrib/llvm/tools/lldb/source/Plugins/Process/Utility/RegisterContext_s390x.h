begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContext_s390x.h ---------------------------------*- C++ -*-===//
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
name|liblldb_RegisterContext_s390x_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContext_s390x_h_
end_define

begin_comment
comment|//---------------------------------------------------------------------------
end_comment

begin_comment
comment|// SystemZ ehframe, dwarf regnums
end_comment

begin_comment
comment|//---------------------------------------------------------------------------
end_comment

begin_comment
comment|// EHFrame and DWARF Register numbers (eRegisterKindEHFrame&
end_comment

begin_comment
comment|// eRegisterKindDWARF)
end_comment

begin_enum
enum|enum
block|{
comment|// General Purpose Registers
name|dwarf_r0_s390x
init|=
literal|0
block|,
name|dwarf_r1_s390x
block|,
name|dwarf_r2_s390x
block|,
name|dwarf_r3_s390x
block|,
name|dwarf_r4_s390x
block|,
name|dwarf_r5_s390x
block|,
name|dwarf_r6_s390x
block|,
name|dwarf_r7_s390x
block|,
name|dwarf_r8_s390x
block|,
name|dwarf_r9_s390x
block|,
name|dwarf_r10_s390x
block|,
name|dwarf_r11_s390x
block|,
name|dwarf_r12_s390x
block|,
name|dwarf_r13_s390x
block|,
name|dwarf_r14_s390x
block|,
name|dwarf_r15_s390x
block|,
comment|// Floating Point Registers / Vector Registers 0-15
name|dwarf_f0_s390x
init|=
literal|16
block|,
name|dwarf_f2_s390x
block|,
name|dwarf_f4_s390x
block|,
name|dwarf_f6_s390x
block|,
name|dwarf_f1_s390x
block|,
name|dwarf_f3_s390x
block|,
name|dwarf_f5_s390x
block|,
name|dwarf_f7_s390x
block|,
name|dwarf_f8_s390x
block|,
name|dwarf_f10_s390x
block|,
name|dwarf_f12_s390x
block|,
name|dwarf_f14_s390x
block|,
name|dwarf_f9_s390x
block|,
name|dwarf_f11_s390x
block|,
name|dwarf_f13_s390x
block|,
name|dwarf_f15_s390x
block|,
comment|// Access Registers
name|dwarf_acr0_s390x
init|=
literal|48
block|,
name|dwarf_acr1_s390x
block|,
name|dwarf_acr2_s390x
block|,
name|dwarf_acr3_s390x
block|,
name|dwarf_acr4_s390x
block|,
name|dwarf_acr5_s390x
block|,
name|dwarf_acr6_s390x
block|,
name|dwarf_acr7_s390x
block|,
name|dwarf_acr8_s390x
block|,
name|dwarf_acr9_s390x
block|,
name|dwarf_acr10_s390x
block|,
name|dwarf_acr11_s390x
block|,
name|dwarf_acr12_s390x
block|,
name|dwarf_acr13_s390x
block|,
name|dwarf_acr14_s390x
block|,
name|dwarf_acr15_s390x
block|,
comment|// Program Status Word
name|dwarf_pswm_s390x
init|=
literal|64
block|,
name|dwarf_pswa_s390x
block|,
comment|// Vector Registers 16-31
name|dwarf_v16_s390x
init|=
literal|68
block|,
name|dwarf_v18_s390x
block|,
name|dwarf_v20_s390x
block|,
name|dwarf_v22_s390x
block|,
name|dwarf_v17_s390x
block|,
name|dwarf_v19_s390x
block|,
name|dwarf_v21_s390x
block|,
name|dwarf_v23_s390x
block|,
name|dwarf_v24_s390x
block|,
name|dwarf_v26_s390x
block|,
name|dwarf_v28_s390x
block|,
name|dwarf_v30_s390x
block|,
name|dwarf_v25_s390x
block|,
name|dwarf_v27_s390x
block|,
name|dwarf_v29_s390x
block|,
name|dwarf_v31_s390x
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

end_unit

