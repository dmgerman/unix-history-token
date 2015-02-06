begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterInfos_powerpc.h ---------------------------------*- C++ -*-===//
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
comment|//===---------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// Computes the offset of the given GPR in the user data area.
end_comment

begin_define
define|#
directive|define
name|GPR_OFFSET
parameter_list|(
name|regname
parameter_list|)
define|\
value|(offsetof(GPR, regname))
end_define

begin_define
define|#
directive|define
name|FPR_OFFSET
parameter_list|(
name|regname
parameter_list|)
define|\
value|(offsetof(FPR, regname))
end_define

begin_define
define|#
directive|define
name|GPR_SIZE
parameter_list|(
name|regname
parameter_list|)
define|\
value|(sizeof(((GPR*)NULL)->regname))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DECLARE_REGISTER_INFOS_POWERPC_STRUCT
end_ifdef

begin_comment
comment|// Note that the size and offset will be updated by platform-specific classes.
end_comment

begin_define
define|#
directive|define
name|DEFINE_GPR
parameter_list|(
name|reg
parameter_list|,
name|alt
parameter_list|,
name|lldb_kind
parameter_list|)
define|\
value|{ #reg, alt, GPR_SIZE(reg), GPR_OFFSET(reg), eEncodingUint, \       eFormatHex, { gcc_dwarf_##reg##_powerpc, gcc_dwarf_##reg##_powerpc, lldb_kind, gdb_##reg##_powerpc, gpr_##reg##_powerpc }, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|DEFINE_FPR
parameter_list|(
name|reg
parameter_list|,
name|lldb_kind
parameter_list|)
define|\
value|{ #reg, NULL, 8, FPR_OFFSET(reg), eEncodingIEEE754, \       eFormatFloat, { gcc_dwarf_##reg##_powerpc, gcc_dwarf_##reg##_powerpc, lldb_kind, gdb_##reg##_powerpc, fpr_##reg##_powerpc }, NULL, NULL }
end_define

begin_comment
comment|// General purpose registers.                 GCC,                  DWARF,              Generic,                GDB
end_comment

begin_define
define|#
directive|define
name|POWERPC_REGS
define|\
value|DEFINE_GPR(r0,       NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r1,       "sp",  LLDB_REGNUM_GENERIC_SP), \     DEFINE_GPR(r2,       NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r3,       "arg1",LLDB_REGNUM_GENERIC_ARG1), \     DEFINE_GPR(r4,       "arg2",LLDB_REGNUM_GENERIC_ARG2), \     DEFINE_GPR(r5,       "arg3",LLDB_REGNUM_GENERIC_ARG3), \     DEFINE_GPR(r6,       "arg4",LLDB_REGNUM_GENERIC_ARG4), \     DEFINE_GPR(r7,       "arg5",LLDB_REGNUM_GENERIC_ARG5), \     DEFINE_GPR(r8,       "arg6",LLDB_REGNUM_GENERIC_ARG6), \     DEFINE_GPR(r9,       "arg7",LLDB_REGNUM_GENERIC_ARG7), \     DEFINE_GPR(r10,      "arg8",LLDB_REGNUM_GENERIC_ARG8), \     DEFINE_GPR(r11,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r12,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r13,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r14,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r15,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r16,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r17,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r18,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r19,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r20,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r21,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r22,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r23,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r24,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r25,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r26,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r27,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r28,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r29,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r30,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(r31,      NULL,  LLDB_INVALID_REGNUM), \     DEFINE_GPR(lr,       "lr",  LLDB_REGNUM_GENERIC_RA), \     DEFINE_GPR(cr,       "cr",  LLDB_REGNUM_GENERIC_FLAGS), \     DEFINE_GPR(xer,      "xer", LLDB_INVALID_REGNUM), \     DEFINE_GPR(ctr,      "ctr", LLDB_INVALID_REGNUM), \     DEFINE_GPR(pc,       "pc",  LLDB_REGNUM_GENERIC_PC), \     DEFINE_FPR(f0,       LLDB_INVALID_REGNUM), \     DEFINE_FPR(f1,       LLDB_INVALID_REGNUM), \     DEFINE_FPR(f2,       LLDB_INVALID_REGNUM), \     DEFINE_FPR(f3,       LLDB_INVALID_REGNUM), \     DEFINE_FPR(f4,       LLDB_INVALID_REGNUM), \     DEFINE_FPR(f5,       LLDB_INVALID_REGNUM), \     DEFINE_FPR(f6,       LLDB_INVALID_REGNUM), \     DEFINE_FPR(f7,       LLDB_INVALID_REGNUM), \     DEFINE_FPR(f8,       LLDB_INVALID_REGNUM), \     DEFINE_FPR(f9,       LLDB_INVALID_REGNUM), \     DEFINE_FPR(f10,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f11,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f12,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f13,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f14,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f15,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f16,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f17,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f18,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f19,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f20,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f21,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f22,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f23,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f24,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f25,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f26,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f27,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f28,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f29,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f30,      LLDB_INVALID_REGNUM), \     DEFINE_FPR(f31,      LLDB_INVALID_REGNUM), \     { "fpscr", NULL, 8, FPR_OFFSET(fpscr), eEncodingUint, eFormatHex, { gcc_dwarf_fpscr_powerpc, gcc_dwarf_fpscr_powerpc, LLDB_INVALID_REGNUM, gdb_fpscr_powerpc, fpr_fpscr_powerpc }, NULL, NULL },
end_define

begin_decl_stmt
specifier|static
name|RegisterInfo
name|g_register_infos_powerpc64
index|[]
init|=
block|{
define|#
directive|define
name|GPR
value|GPR64
name|POWERPC_REGS
undef|#
directive|undef
name|GPR
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|RegisterInfo
name|g_register_infos_powerpc32
index|[]
init|=
block|{
define|#
directive|define
name|GPR
value|GPR32
name|POWERPC_REGS
undef|#
directive|undef
name|GPR
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|RegisterInfo
name|g_register_infos_powerpc64_32
index|[]
init|=
block|{
define|#
directive|define
name|GPR
value|GPR64
undef|#
directive|undef
name|GPR_SIZE
define|#
directive|define
name|GPR_SIZE
parameter_list|(
name|reg
parameter_list|)
value|(sizeof(uint32_t))
undef|#
directive|undef
name|GPR_OFFSET
define|#
directive|define
name|GPR_OFFSET
parameter_list|(
name|regname
parameter_list|)
define|\
value|(offsetof(GPR, regname) + (sizeof(((GPR *)NULL)->regname) - GPR_SIZE(reg)))
name|POWERPC_REGS
undef|#
directive|undef
name|GPR
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|static_assert
argument_list|(
operator|(
sizeof|sizeof
argument_list|(
name|g_register_infos_powerpc32
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|g_register_infos_powerpc32
index|[
literal|0
index|]
argument_list|)
operator|)
operator|==
name|k_num_registers_powerpc
argument_list|,
literal|"g_register_infos_powerpc32 has wrong number of register infos"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|static_assert
argument_list|(
operator|(
sizeof|sizeof
argument_list|(
name|g_register_infos_powerpc64
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|g_register_infos_powerpc64
index|[
literal|0
index|]
argument_list|)
operator|)
operator|==
name|k_num_registers_powerpc
argument_list|,
literal|"g_register_infos_powerpc64 has wrong number of register infos"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|g_register_infos_powerpc64_32
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|g_register_infos_powerpc64
argument_list|)
argument_list|,
literal|"g_register_infos_powerpc64_32 doesn't match size of g_register_infos_powerpc64"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|DEFINE_FPR
end_undef

begin_undef
undef|#
directive|undef
name|DEFINE_GPR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// DECLARE_REGISTER_INFOS_POWERPC_STRUCT
end_comment

begin_undef
undef|#
directive|undef
name|GPR_OFFSET
end_undef

end_unit

