begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContext_mips64.h --------------------------------*- C++ -*-===//
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
name|liblldb_RegisterContext_mips64_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContext_mips64_H_
end_define

begin_comment
comment|// GCC and DWARF Register numbers (eRegisterKindGCC& eRegisterKindDWARF)
end_comment

begin_enum
enum|enum
block|{
comment|// GP Registers
name|gcc_dwarf_zero_mips64
init|=
literal|0
block|,
name|gcc_dwarf_r1_mips64
block|,
name|gcc_dwarf_r2_mips64
block|,
name|gcc_dwarf_r3_mips64
block|,
name|gcc_dwarf_r4_mips64
block|,
name|gcc_dwarf_r5_mips64
block|,
name|gcc_dwarf_r6_mips64
block|,
name|gcc_dwarf_r7_mips64
block|,
name|gcc_dwarf_r8_mips64
block|,
name|gcc_dwarf_r9_mips64
block|,
name|gcc_dwarf_r10_mips64
block|,
name|gcc_dwarf_r11_mips64
block|,
name|gcc_dwarf_r12_mips64
block|,
name|gcc_dwarf_r13_mips64
block|,
name|gcc_dwarf_r14_mips64
block|,
name|gcc_dwarf_r15_mips64
block|,
name|gcc_dwarf_r16_mips64
block|,
name|gcc_dwarf_r17_mips64
block|,
name|gcc_dwarf_r18_mips64
block|,
name|gcc_dwarf_r19_mips64
block|,
name|gcc_dwarf_r20_mips64
block|,
name|gcc_dwarf_r21_mips64
block|,
name|gcc_dwarf_r22_mips64
block|,
name|gcc_dwarf_r23_mips64
block|,
name|gcc_dwarf_r24_mips64
block|,
name|gcc_dwarf_r25_mips64
block|,
name|gcc_dwarf_r26_mips64
block|,
name|gcc_dwarf_r27_mips64
block|,
name|gcc_dwarf_gp_mips64
block|,
name|gcc_dwarf_sp_mips64
block|,
name|gcc_dwarf_r30_mips64
block|,
name|gcc_dwarf_ra_mips64
block|,
name|gcc_dwarf_sr_mips64
block|,
name|gcc_dwarf_lo_mips64
block|,
name|gcc_dwarf_hi_mips64
block|,
name|gcc_dwarf_bad_mips64
block|,
name|gcc_dwarf_cause_mips64
block|,
name|gcc_dwarf_pc_mips64
block|,
name|gcc_dwarf_ic_mips64
block|,
name|gcc_dwarf_dummy_mips64
block|}
enum|;
end_enum

begin_comment
comment|// GDB Register numbers (eRegisterKindGDB)
end_comment

begin_enum
enum|enum
block|{
name|gdb_zero_mips64
init|=
literal|0
block|,
name|gdb_r1_mips64
block|,
name|gdb_r2_mips64
block|,
name|gdb_r3_mips64
block|,
name|gdb_r4_mips64
block|,
name|gdb_r5_mips64
block|,
name|gdb_r6_mips64
block|,
name|gdb_r7_mips64
block|,
name|gdb_r8_mips64
block|,
name|gdb_r9_mips64
block|,
name|gdb_r10_mips64
block|,
name|gdb_r11_mips64
block|,
name|gdb_r12_mips64
block|,
name|gdb_r13_mips64
block|,
name|gdb_r14_mips64
block|,
name|gdb_r15_mips64
block|,
name|gdb_r16_mips64
block|,
name|gdb_r17_mips64
block|,
name|gdb_r18_mips64
block|,
name|gdb_r19_mips64
block|,
name|gdb_r20_mips64
block|,
name|gdb_r21_mips64
block|,
name|gdb_r22_mips64
block|,
name|gdb_r23_mips64
block|,
name|gdb_r24_mips64
block|,
name|gdb_r25_mips64
block|,
name|gdb_r26_mips64
block|,
name|gdb_r27_mips64
block|,
name|gdb_gp_mips64
block|,
name|gdb_sp_mips64
block|,
name|gdb_r30_mips64
block|,
name|gdb_ra_mips64
block|,
name|gdb_sr_mips64
block|,
name|gdb_lo_mips64
block|,
name|gdb_hi_mips64
block|,
name|gdb_bad_mips64
block|,
name|gdb_cause_mips64
block|,
name|gdb_pc_mips64
block|,
name|gdb_ic_mips64
block|,
name|gdb_dummy_mips64
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_RegisterContext_mips64_H_
end_comment

end_unit

