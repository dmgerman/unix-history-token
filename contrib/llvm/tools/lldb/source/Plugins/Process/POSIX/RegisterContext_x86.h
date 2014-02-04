begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContext_x86.h -----------------------------------*- C++ -*-===//
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
name|liblldb_RegisterContext_x86_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContext_x86_H_
end_define

begin_comment
comment|//---------------------------------------------------------------------------
end_comment

begin_comment
comment|// i386 gcc, dwarf, gdb enums
end_comment

begin_comment
comment|//---------------------------------------------------------------------------
end_comment

begin_comment
comment|// Register numbers seen in eh_frame (eRegisterKindGCC)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// From Jason Molenda: "gcc registers" is the register numbering used in the eh_frame
end_comment

begin_comment
comment|// CFI.  The only registers that are described in eh_frame CFI are those that are
end_comment

begin_comment
comment|// preserved across function calls aka callee-saved aka non-volatile.  And none
end_comment

begin_comment
comment|// of the floating point registers on x86 are preserved across function calls.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The only reason there is a "gcc register" and a "dwarf register" is because of a
end_comment

begin_comment
comment|// mistake years and years ago with i386 where they got esp and ebp
end_comment

begin_comment
comment|// backwards when they emitted the eh_frame instructions.  Once there were
end_comment

begin_comment
comment|// binaries In The Wild using the reversed numbering, we had to stick with it
end_comment

begin_comment
comment|// forever.
end_comment

begin_enum
enum|enum
block|{
comment|// 2nd parameter in DwarfRegNum() is regnum for exception handling on x86-32.
comment|// See http://llvm.org/docs/WritingAnLLVMBackend.html#defining-a-register
name|gcc_eax_i386
init|=
literal|0
block|,
name|gcc_ecx_i386
block|,
name|gcc_edx_i386
block|,
name|gcc_ebx_i386
block|,
name|gcc_ebp_i386
block|,
comment|// Warning: these are switched from dwarf values
name|gcc_esp_i386
block|,
comment|//
name|gcc_esi_i386
block|,
name|gcc_edi_i386
block|,
name|gcc_eip_i386
block|,
name|gcc_eflags_i386
block|,
name|gcc_st0_i386
init|=
literal|12
block|,
name|gcc_st1_i386
block|,
name|gcc_st2_i386
block|,
name|gcc_st3_i386
block|,
name|gcc_st4_i386
block|,
name|gcc_st5_i386
block|,
name|gcc_st6_i386
block|,
name|gcc_st7_i386
block|,
name|gcc_xmm0_i386
init|=
literal|21
block|,
name|gcc_xmm1_i386
block|,
name|gcc_xmm2_i386
block|,
name|gcc_xmm3_i386
block|,
name|gcc_xmm4_i386
block|,
name|gcc_xmm5_i386
block|,
name|gcc_xmm6_i386
block|,
name|gcc_xmm7_i386
block|,
name|gcc_mm0_i386
init|=
literal|29
block|,
name|gcc_mm1_i386
block|,
name|gcc_mm2_i386
block|,
name|gcc_mm3_i386
block|,
name|gcc_mm4_i386
block|,
name|gcc_mm5_i386
block|,
name|gcc_mm6_i386
block|,
name|gcc_mm7_i386
block|, }
enum|;
end_enum

begin_comment
comment|// DWARF register numbers (eRegisterKindDWARF)
end_comment

begin_comment
comment|// Intel's x86 or IA-32
end_comment

begin_enum
enum|enum
block|{
comment|// General Purpose Registers.
name|dwarf_eax_i386
init|=
literal|0
block|,
name|dwarf_ecx_i386
block|,
name|dwarf_edx_i386
block|,
name|dwarf_ebx_i386
block|,
name|dwarf_esp_i386
block|,
name|dwarf_ebp_i386
block|,
name|dwarf_esi_i386
block|,
name|dwarf_edi_i386
block|,
name|dwarf_eip_i386
block|,
name|dwarf_eflags_i386
block|,
comment|// Floating Point Registers
name|dwarf_st0_i386
init|=
literal|11
block|,
name|dwarf_st1_i386
block|,
name|dwarf_st2_i386
block|,
name|dwarf_st3_i386
block|,
name|dwarf_st4_i386
block|,
name|dwarf_st5_i386
block|,
name|dwarf_st6_i386
block|,
name|dwarf_st7_i386
block|,
comment|// SSE Registers
name|dwarf_xmm0_i386
init|=
literal|21
block|,
name|dwarf_xmm1_i386
block|,
name|dwarf_xmm2_i386
block|,
name|dwarf_xmm3_i386
block|,
name|dwarf_xmm4_i386
block|,
name|dwarf_xmm5_i386
block|,
name|dwarf_xmm6_i386
block|,
name|dwarf_xmm7_i386
block|,
comment|// MMX Registers
name|dwarf_mm0_i386
init|=
literal|29
block|,
name|dwarf_mm1_i386
block|,
name|dwarf_mm2_i386
block|,
name|dwarf_mm3_i386
block|,
name|dwarf_mm4_i386
block|,
name|dwarf_mm5_i386
block|,
name|dwarf_mm6_i386
block|,
name|dwarf_mm7_i386
block|,
name|dwarf_fctrl_i386
init|=
literal|37
block|,
comment|// x87 control word
name|dwarf_fstat_i386
init|=
literal|38
block|,
comment|// x87 status word
name|dwarf_mxcsr_i386
init|=
literal|39
block|,
name|dwarf_es_i386
init|=
literal|40
block|,
name|dwarf_cs_i386
init|=
literal|41
block|,
name|dwarf_ss_i386
init|=
literal|42
block|,
name|dwarf_ds_i386
init|=
literal|43
block|,
name|dwarf_fs_i386
init|=
literal|44
block|,
name|dwarf_gs_i386
init|=
literal|45
comment|// I believe the ymm registers use the dwarf_xmm%_i386 register numbers and
comment|//  then differentiate based on size of the register.
block|}
enum|;
end_enum

begin_comment
comment|// Register numbers GDB uses (eRegisterKindGDB)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// From Jason Molenda: The "gdb numbers" are what you would see in the stabs debug format.
end_comment

begin_enum
enum|enum
block|{
name|gdb_eax_i386
block|,
name|gdb_ecx_i386
block|,
name|gdb_edx_i386
block|,
name|gdb_ebx_i386
block|,
name|gdb_esp_i386
block|,
name|gdb_ebp_i386
block|,
name|gdb_esi_i386
block|,
name|gdb_edi_i386
block|,
name|gdb_eip_i386
block|,
name|gdb_eflags_i386
block|,
name|gdb_cs_i386
block|,
name|gdb_ss_i386
block|,
name|gdb_ds_i386
block|,
name|gdb_es_i386
block|,
name|gdb_fs_i386
block|,
name|gdb_gs_i386
block|,
name|gdb_st0_i386
init|=
literal|16
block|,
name|gdb_st1_i386
block|,
name|gdb_st2_i386
block|,
name|gdb_st3_i386
block|,
name|gdb_st4_i386
block|,
name|gdb_st5_i386
block|,
name|gdb_st6_i386
block|,
name|gdb_st7_i386
block|,
name|gdb_fctrl_i386
block|,
comment|// FPU Control Word
name|gdb_fstat_i386
block|,
comment|// FPU Status Word
name|gdb_ftag_i386
block|,
comment|// FPU Tag Word
name|gdb_fiseg_i386
block|,
comment|// FPU IP Selector
name|gdb_fioff_i386
block|,
comment|// FPU IP Offset
name|gdb_foseg_i386
block|,
comment|// FPU Operand Pointer Selector
name|gdb_fooff_i386
block|,
comment|// FPU Operand Pointer Offset
name|gdb_fop_i386
block|,
comment|// Last Instruction Opcode
name|gdb_xmm0_i386
init|=
literal|32
block|,
name|gdb_xmm1_i386
block|,
name|gdb_xmm2_i386
block|,
name|gdb_xmm3_i386
block|,
name|gdb_xmm4_i386
block|,
name|gdb_xmm5_i386
block|,
name|gdb_xmm6_i386
block|,
name|gdb_xmm7_i386
block|,
name|gdb_mxcsr_i386
init|=
literal|40
block|,
name|gdb_ymm0h_i386
block|,
name|gdb_ymm1h_i386
block|,
name|gdb_ymm2h_i386
block|,
name|gdb_ymm3h_i386
block|,
name|gdb_ymm4h_i386
block|,
name|gdb_ymm5h_i386
block|,
name|gdb_ymm6h_i386
block|,
name|gdb_ymm7h_i386
block|,
name|gdb_mm0_i386
block|,
name|gdb_mm1_i386
block|,
name|gdb_mm2_i386
block|,
name|gdb_mm3_i386
block|,
name|gdb_mm4_i386
block|,
name|gdb_mm5_i386
block|,
name|gdb_mm6_i386
block|,
name|gdb_mm7_i386
block|, }
enum|;
end_enum

begin_comment
comment|//---------------------------------------------------------------------------
end_comment

begin_comment
comment|// AMD x86_64, AMD64, Intel EM64T, or Intel 64 gcc, dwarf, gdb enums
end_comment

begin_comment
comment|//---------------------------------------------------------------------------
end_comment

begin_comment
comment|// GCC and DWARF Register numbers (eRegisterKindGCC& eRegisterKindDWARF)
end_comment

begin_comment
comment|//  This is the spec I used (as opposed to x86-64-abi-0.99.pdf):
end_comment

begin_comment
comment|//  http://software.intel.com/sites/default/files/article/402129/mpx-linux64-abi.pdf
end_comment

begin_enum
enum|enum
block|{
comment|// GP Registers
name|gcc_dwarf_rax_x86_64
init|=
literal|0
block|,
name|gcc_dwarf_rdx_x86_64
block|,
name|gcc_dwarf_rcx_x86_64
block|,
name|gcc_dwarf_rbx_x86_64
block|,
name|gcc_dwarf_rsi_x86_64
block|,
name|gcc_dwarf_rdi_x86_64
block|,
name|gcc_dwarf_rbp_x86_64
block|,
name|gcc_dwarf_rsp_x86_64
block|,
comment|// Extended GP Registers
name|gcc_dwarf_r8_x86_64
init|=
literal|8
block|,
name|gcc_dwarf_r9_x86_64
block|,
name|gcc_dwarf_r10_x86_64
block|,
name|gcc_dwarf_r11_x86_64
block|,
name|gcc_dwarf_r12_x86_64
block|,
name|gcc_dwarf_r13_x86_64
block|,
name|gcc_dwarf_r14_x86_64
block|,
name|gcc_dwarf_r15_x86_64
block|,
comment|// Return Address (RA) mapped to RIP
name|gcc_dwarf_rip_x86_64
init|=
literal|16
block|,
comment|// SSE Vector Registers
name|gcc_dwarf_xmm0_x86_64
init|=
literal|17
block|,
name|gcc_dwarf_xmm1_x86_64
block|,
name|gcc_dwarf_xmm2_x86_64
block|,
name|gcc_dwarf_xmm3_x86_64
block|,
name|gcc_dwarf_xmm4_x86_64
block|,
name|gcc_dwarf_xmm5_x86_64
block|,
name|gcc_dwarf_xmm6_x86_64
block|,
name|gcc_dwarf_xmm7_x86_64
block|,
name|gcc_dwarf_xmm8_x86_64
block|,
name|gcc_dwarf_xmm9_x86_64
block|,
name|gcc_dwarf_xmm10_x86_64
block|,
name|gcc_dwarf_xmm11_x86_64
block|,
name|gcc_dwarf_xmm12_x86_64
block|,
name|gcc_dwarf_xmm13_x86_64
block|,
name|gcc_dwarf_xmm14_x86_64
block|,
name|gcc_dwarf_xmm15_x86_64
block|,
comment|// Floating Point Registers
name|gcc_dwarf_st0_x86_64
init|=
literal|33
block|,
name|gcc_dwarf_st1_x86_64
block|,
name|gcc_dwarf_st2_x86_64
block|,
name|gcc_dwarf_st3_x86_64
block|,
name|gcc_dwarf_st4_x86_64
block|,
name|gcc_dwarf_st5_x86_64
block|,
name|gcc_dwarf_st6_x86_64
block|,
name|gcc_dwarf_st7_x86_64
block|,
comment|// MMX Registers
name|gcc_dwarf_mm0_x86_64
init|=
literal|41
block|,
name|gcc_dwarf_mm1_x86_64
block|,
name|gcc_dwarf_mm2_x86_64
block|,
name|gcc_dwarf_mm3_x86_64
block|,
name|gcc_dwarf_mm4_x86_64
block|,
name|gcc_dwarf_mm5_x86_64
block|,
name|gcc_dwarf_mm6_x86_64
block|,
name|gcc_dwarf_mm7_x86_64
block|,
comment|// Control and Status Flags Register
name|gcc_dwarf_rflags_x86_64
init|=
literal|49
block|,
comment|//  selector registers
name|gcc_dwarf_es_x86_64
init|=
literal|50
block|,
name|gcc_dwarf_cs_x86_64
block|,
name|gcc_dwarf_ss_x86_64
block|,
name|gcc_dwarf_ds_x86_64
block|,
name|gcc_dwarf_fs_x86_64
block|,
name|gcc_dwarf_gs_x86_64
block|,
comment|// Floating point control registers
name|gcc_dwarf_mxcsr_x86_64
init|=
literal|64
block|,
comment|// Media Control and Status
name|gcc_dwarf_fctrl_x86_64
block|,
comment|// x87 control word
name|gcc_dwarf_fstat_x86_64
block|,
comment|// x87 status word
comment|// Upper Vector Registers
name|gcc_dwarf_ymm0h_x86_64
init|=
literal|67
block|,
name|gcc_dwarf_ymm1h_x86_64
block|,
name|gcc_dwarf_ymm2h_x86_64
block|,
name|gcc_dwarf_ymm3h_x86_64
block|,
name|gcc_dwarf_ymm4h_x86_64
block|,
name|gcc_dwarf_ymm5h_x86_64
block|,
name|gcc_dwarf_ymm6h_x86_64
block|,
name|gcc_dwarf_ymm7h_x86_64
block|,
name|gcc_dwarf_ymm8h_x86_64
block|,
name|gcc_dwarf_ymm9h_x86_64
block|,
name|gcc_dwarf_ymm10h_x86_64
block|,
name|gcc_dwarf_ymm11h_x86_64
block|,
name|gcc_dwarf_ymm12h_x86_64
block|,
name|gcc_dwarf_ymm13h_x86_64
block|,
name|gcc_dwarf_ymm14h_x86_64
block|,
name|gcc_dwarf_ymm15h_x86_64
block|,
comment|// AVX2 Vector Mask Registers
comment|// gcc_dwarf_k0_x86_64 = 118,
comment|// gcc_dwarf_k1_x86_64,
comment|// gcc_dwarf_k2_x86_64,
comment|// gcc_dwarf_k3_x86_64,
comment|// gcc_dwarf_k4_x86_64,
comment|// gcc_dwarf_k5_x86_64,
comment|// gcc_dwarf_k6_x86_64,
comment|// gcc_dwarf_k7_x86_64,
block|}
enum|;
end_enum

begin_comment
comment|// GDB Register numbers (eRegisterKindGDB)
end_comment

begin_enum
enum|enum
block|{
comment|// GP Registers
name|gdb_rax_x86_64
init|=
literal|0
block|,
name|gdb_rbx_x86_64
block|,
name|gdb_rcx_x86_64
block|,
name|gdb_rdx_x86_64
block|,
name|gdb_rsi_x86_64
block|,
name|gdb_rdi_x86_64
block|,
name|gdb_rbp_x86_64
block|,
name|gdb_rsp_x86_64
block|,
comment|// Extended GP Registers
name|gdb_r8_x86_64
block|,
name|gdb_r9_x86_64
block|,
name|gdb_r10_x86_64
block|,
name|gdb_r11_x86_64
block|,
name|gdb_r12_x86_64
block|,
name|gdb_r13_x86_64
block|,
name|gdb_r14_x86_64
block|,
name|gdb_r15_x86_64
block|,
comment|// Return Address (RA) mapped to RIP
name|gdb_rip_x86_64
block|,
comment|// Control and Status Flags Register
name|gdb_rflags_x86_64
block|,
name|gdb_cs_x86_64
block|,
name|gdb_ss_x86_64
block|,
name|gdb_ds_x86_64
block|,
name|gdb_es_x86_64
block|,
name|gdb_fs_x86_64
block|,
name|gdb_gs_x86_64
block|,
comment|// Floating Point Registers
name|gdb_st0_x86_64
block|,
name|gdb_st1_x86_64
block|,
name|gdb_st2_x86_64
block|,
name|gdb_st3_x86_64
block|,
name|gdb_st4_x86_64
block|,
name|gdb_st5_x86_64
block|,
name|gdb_st6_x86_64
block|,
name|gdb_st7_x86_64
block|,
name|gdb_fctrl_x86_64
block|,
name|gdb_fstat_x86_64
block|,
name|gdb_ftag_x86_64
block|,
name|gdb_fiseg_x86_64
block|,
name|gdb_fioff_x86_64
block|,
name|gdb_foseg_x86_64
block|,
name|gdb_fooff_x86_64
block|,
name|gdb_fop_x86_64
block|,
comment|// SSE Vector Registers
name|gdb_xmm0_x86_64
init|=
literal|40
block|,
name|gdb_xmm1_x86_64
block|,
name|gdb_xmm2_x86_64
block|,
name|gdb_xmm3_x86_64
block|,
name|gdb_xmm4_x86_64
block|,
name|gdb_xmm5_x86_64
block|,
name|gdb_xmm6_x86_64
block|,
name|gdb_xmm7_x86_64
block|,
name|gdb_xmm8_x86_64
block|,
name|gdb_xmm9_x86_64
block|,
name|gdb_xmm10_x86_64
block|,
name|gdb_xmm11_x86_64
block|,
name|gdb_xmm12_x86_64
block|,
name|gdb_xmm13_x86_64
block|,
name|gdb_xmm14_x86_64
block|,
name|gdb_xmm15_x86_64
block|,
comment|// Floating point control registers
name|gdb_mxcsr_x86_64
init|=
literal|56
block|,
name|gdb_ymm0h_x86_64
block|,
name|gdb_ymm1h_x86_64
block|,
name|gdb_ymm2h_x86_64
block|,
name|gdb_ymm3h_x86_64
block|,
name|gdb_ymm4h_x86_64
block|,
name|gdb_ymm5h_x86_64
block|,
name|gdb_ymm6h_x86_64
block|,
name|gdb_ymm7h_x86_64
block|,
name|gdb_ymm8h_x86_64
block|,
name|gdb_ymm9h_x86_64
block|,
name|gdb_ymm10h_x86_64
block|,
name|gdb_ymm11h_x86_64
block|,
name|gdb_ymm12h_x86_64
block|,
name|gdb_ymm13h_x86_64
block|,
name|gdb_ymm14h_x86_64
block|,
name|gdb_ymm15h_x86_64
block|}
enum|;
end_enum

begin_comment
comment|//---------------------------------------------------------------------------
end_comment

begin_comment
comment|// Generic floating-point registers
end_comment

begin_comment
comment|//---------------------------------------------------------------------------
end_comment

begin_struct
struct|struct
name|MMSReg
block|{
name|uint8_t
name|bytes
index|[
literal|10
index|]
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|XMMReg
block|{
name|uint8_t
name|bytes
index|[
literal|16
index|]
decl_stmt|;
comment|// 128-bits for each XMM register
block|}
struct|;
end_struct

begin_comment
comment|// i387_fxsave_struct
end_comment

begin_struct
struct|struct
name|FXSAVE
block|{
name|uint16_t
name|fctrl
decl_stmt|;
comment|// FPU Control Word (fcw)
name|uint16_t
name|fstat
decl_stmt|;
comment|// FPU Status Word (fsw)
name|uint16_t
name|ftag
decl_stmt|;
comment|// FPU Tag Word (ftw)
name|uint16_t
name|fop
decl_stmt|;
comment|// Last Instruction Opcode (fop)
union|union
block|{
struct|struct
block|{
name|uint64_t
name|fip
decl_stmt|;
comment|// Instruction Pointer
name|uint64_t
name|fdp
decl_stmt|;
comment|// Data Pointer
block|}
name|x86_64
struct|;
struct|struct
block|{
name|uint32_t
name|fioff
decl_stmt|;
comment|// FPU IP Offset (fip)
name|uint32_t
name|fiseg
decl_stmt|;
comment|// FPU IP Selector (fcs)
name|uint32_t
name|fooff
decl_stmt|;
comment|// FPU Operand Pointer Offset (foo)
name|uint32_t
name|foseg
decl_stmt|;
comment|// FPU Operand Pointer Selector (fos)
block|}
name|i386
struct|;
block|}
name|ptr
union|;
name|uint32_t
name|mxcsr
decl_stmt|;
comment|// MXCSR Register State
name|uint32_t
name|mxcsrmask
decl_stmt|;
comment|// MXCSR Mask
name|MMSReg
name|stmm
index|[
literal|8
index|]
decl_stmt|;
comment|// 8*16 bytes for each FP-reg = 128 bytes
name|XMMReg
name|xmm
index|[
literal|16
index|]
decl_stmt|;
comment|// 16*16 bytes for each XMM-reg = 256 bytes
name|uint32_t
name|padding
index|[
literal|24
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|//---------------------------------------------------------------------------
end_comment

begin_comment
comment|// Extended floating-point registers
end_comment

begin_comment
comment|//---------------------------------------------------------------------------
end_comment

begin_struct
struct|struct
name|YMMHReg
block|{
name|uint8_t
name|bytes
index|[
literal|16
index|]
decl_stmt|;
comment|// 16 * 8 bits for the high bytes of each YMM register
block|}
struct|;
end_struct

begin_struct
struct|struct
name|YMMReg
block|{
name|uint8_t
name|bytes
index|[
literal|32
index|]
decl_stmt|;
comment|// 16 * 16 bits for each YMM register
block|}
struct|;
end_struct

begin_struct
struct|struct
name|YMM
block|{
name|YMMReg
name|ymm
index|[
literal|16
index|]
decl_stmt|;
comment|// assembled from ymmh and xmm registers
block|}
struct|;
end_struct

begin_struct
struct|struct
name|XSAVE_HDR
block|{
name|uint64_t
name|xstate_bv
decl_stmt|;
comment|// OS enabled xstate mask to determine the extended states supported by the processor
name|uint64_t
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|reserved2
index|[
literal|5
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|// x86 extensions to FXSAVE (i.e. for AVX processors)
end_comment

begin_struct
struct|struct
name|XSAVE
block|{
name|FXSAVE
name|i387
decl_stmt|;
comment|// floating point registers typical in i387_fxsave_struct
name|XSAVE_HDR
name|header
decl_stmt|;
comment|// The xsave_hdr_struct can be used to determine if the following extensions are usable
name|YMMHReg
name|ymmh
index|[
literal|16
index|]
decl_stmt|;
comment|// High 16 bytes of each of 16 YMM registers (the low bytes are in FXSAVE.xmm for compatibility with SSE)
comment|// Slot any extensions to the register file here
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|,
name|aligned
argument_list|(
literal|64
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|// Floating-point registers
end_comment

begin_struct
struct|struct
name|FPR
block|{
comment|// Thread state for the floating-point unit of the processor read by ptrace.
union|union
name|XSTATE
block|{
name|FXSAVE
name|fxsave
decl_stmt|;
comment|// Generic floating-point registers.
name|XSAVE
name|xsave
decl_stmt|;
comment|// x86 extended processor state.
block|}
name|xstate
union|;
block|}
struct|;
end_struct

begin_comment
comment|//---------------------------------------------------------------------------
end_comment

begin_comment
comment|// ptrace PTRACE_GETREGSET, PTRACE_SETREGSET structure
end_comment

begin_comment
comment|//---------------------------------------------------------------------------
end_comment

begin_struct
struct|struct
name|IOVEC
block|{
name|void
modifier|*
name|iov_base
decl_stmt|;
comment|// pointer to XSAVE
name|size_t
name|iov_len
decl_stmt|;
comment|// sizeof(XSAVE)
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

