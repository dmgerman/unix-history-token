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

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_comment
comment|//---------------------------------------------------------------------------
end_comment

begin_comment
comment|// i386 ehframe, dwarf regnums
end_comment

begin_comment
comment|//---------------------------------------------------------------------------
end_comment

begin_comment
comment|// Register numbers seen in eh_frame (eRegisterKindEHFrame) on i386 systems
end_comment

begin_comment
comment|// (non-Darwin)
end_comment

begin_comment
comment|//
end_comment

begin_enum
enum|enum
block|{
name|ehframe_eax_i386
init|=
literal|0
block|,
name|ehframe_ecx_i386
block|,
name|ehframe_edx_i386
block|,
name|ehframe_ebx_i386
block|,
comment|// on Darwin esp& ebp are reversed in the eh_frame section for i386 (versus
comment|// dwarf's reg numbering).
comment|// To be specific:
comment|//    i386+darwin eh_frame:        4 is ebp, 5 is esp
comment|//    i386+everyone else eh_frame: 4 is esp, 5 is ebp
comment|//    i386 dwarf:                  4 is esp, 5 is ebp
comment|// lldb will get the darwin-specific eh_frame reg numberings from debugserver,
comment|// or the ABI, so we
comment|// only encode the generally correct 4 == esp, 5 == ebp numbers in this
comment|// generic header.
name|ehframe_esp_i386
block|,
name|ehframe_ebp_i386
block|,
name|ehframe_esi_i386
block|,
name|ehframe_edi_i386
block|,
name|ehframe_eip_i386
block|,
name|ehframe_eflags_i386
block|,
name|ehframe_st0_i386
init|=
literal|12
block|,
name|ehframe_st1_i386
block|,
name|ehframe_st2_i386
block|,
name|ehframe_st3_i386
block|,
name|ehframe_st4_i386
block|,
name|ehframe_st5_i386
block|,
name|ehframe_st6_i386
block|,
name|ehframe_st7_i386
block|,
name|ehframe_xmm0_i386
init|=
literal|21
block|,
name|ehframe_xmm1_i386
block|,
name|ehframe_xmm2_i386
block|,
name|ehframe_xmm3_i386
block|,
name|ehframe_xmm4_i386
block|,
name|ehframe_xmm5_i386
block|,
name|ehframe_xmm6_i386
block|,
name|ehframe_xmm7_i386
block|,
name|ehframe_mm0_i386
init|=
literal|29
block|,
name|ehframe_mm1_i386
block|,
name|ehframe_mm2_i386
block|,
name|ehframe_mm3_i386
block|,
name|ehframe_mm4_i386
block|,
name|ehframe_mm5_i386
block|,
name|ehframe_mm6_i386
block|,
name|ehframe_mm7_i386
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
block|,
comment|// I believe the ymm registers use the dwarf_xmm%_i386 register numbers and
comment|//  then differentiate based on size of the register.
name|dwarf_bnd0_i386
init|=
literal|101
block|,
name|dwarf_bnd1_i386
block|,
name|dwarf_bnd2_i386
block|,
name|dwarf_bnd3_i386
block|, }
enum|;
end_enum

begin_comment
comment|//---------------------------------------------------------------------------
end_comment

begin_comment
comment|// AMD x86_64, AMD64, Intel EM64T, or Intel 64 ehframe, dwarf regnums
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
name|dwarf_rax_x86_64
init|=
literal|0
block|,
name|dwarf_rdx_x86_64
block|,
name|dwarf_rcx_x86_64
block|,
name|dwarf_rbx_x86_64
block|,
name|dwarf_rsi_x86_64
block|,
name|dwarf_rdi_x86_64
block|,
name|dwarf_rbp_x86_64
block|,
name|dwarf_rsp_x86_64
block|,
comment|// Extended GP Registers
name|dwarf_r8_x86_64
init|=
literal|8
block|,
name|dwarf_r9_x86_64
block|,
name|dwarf_r10_x86_64
block|,
name|dwarf_r11_x86_64
block|,
name|dwarf_r12_x86_64
block|,
name|dwarf_r13_x86_64
block|,
name|dwarf_r14_x86_64
block|,
name|dwarf_r15_x86_64
block|,
comment|// Return Address (RA) mapped to RIP
name|dwarf_rip_x86_64
init|=
literal|16
block|,
comment|// SSE Vector Registers
name|dwarf_xmm0_x86_64
init|=
literal|17
block|,
name|dwarf_xmm1_x86_64
block|,
name|dwarf_xmm2_x86_64
block|,
name|dwarf_xmm3_x86_64
block|,
name|dwarf_xmm4_x86_64
block|,
name|dwarf_xmm5_x86_64
block|,
name|dwarf_xmm6_x86_64
block|,
name|dwarf_xmm7_x86_64
block|,
name|dwarf_xmm8_x86_64
block|,
name|dwarf_xmm9_x86_64
block|,
name|dwarf_xmm10_x86_64
block|,
name|dwarf_xmm11_x86_64
block|,
name|dwarf_xmm12_x86_64
block|,
name|dwarf_xmm13_x86_64
block|,
name|dwarf_xmm14_x86_64
block|,
name|dwarf_xmm15_x86_64
block|,
comment|// Floating Point Registers
name|dwarf_st0_x86_64
init|=
literal|33
block|,
name|dwarf_st1_x86_64
block|,
name|dwarf_st2_x86_64
block|,
name|dwarf_st3_x86_64
block|,
name|dwarf_st4_x86_64
block|,
name|dwarf_st5_x86_64
block|,
name|dwarf_st6_x86_64
block|,
name|dwarf_st7_x86_64
block|,
comment|// MMX Registers
name|dwarf_mm0_x86_64
init|=
literal|41
block|,
name|dwarf_mm1_x86_64
block|,
name|dwarf_mm2_x86_64
block|,
name|dwarf_mm3_x86_64
block|,
name|dwarf_mm4_x86_64
block|,
name|dwarf_mm5_x86_64
block|,
name|dwarf_mm6_x86_64
block|,
name|dwarf_mm7_x86_64
block|,
comment|// Control and Status Flags Register
name|dwarf_rflags_x86_64
init|=
literal|49
block|,
comment|//  selector registers
name|dwarf_es_x86_64
init|=
literal|50
block|,
name|dwarf_cs_x86_64
block|,
name|dwarf_ss_x86_64
block|,
name|dwarf_ds_x86_64
block|,
name|dwarf_fs_x86_64
block|,
name|dwarf_gs_x86_64
block|,
comment|// Floating point control registers
name|dwarf_mxcsr_x86_64
init|=
literal|64
block|,
comment|// Media Control and Status
name|dwarf_fctrl_x86_64
block|,
comment|// x87 control word
name|dwarf_fstat_x86_64
block|,
comment|// x87 status word
comment|// Upper Vector Registers
name|dwarf_ymm0h_x86_64
init|=
literal|67
block|,
name|dwarf_ymm1h_x86_64
block|,
name|dwarf_ymm2h_x86_64
block|,
name|dwarf_ymm3h_x86_64
block|,
name|dwarf_ymm4h_x86_64
block|,
name|dwarf_ymm5h_x86_64
block|,
name|dwarf_ymm6h_x86_64
block|,
name|dwarf_ymm7h_x86_64
block|,
name|dwarf_ymm8h_x86_64
block|,
name|dwarf_ymm9h_x86_64
block|,
name|dwarf_ymm10h_x86_64
block|,
name|dwarf_ymm11h_x86_64
block|,
name|dwarf_ymm12h_x86_64
block|,
name|dwarf_ymm13h_x86_64
block|,
name|dwarf_ymm14h_x86_64
block|,
name|dwarf_ymm15h_x86_64
block|,
comment|// MPX registers
name|dwarf_bnd0_x86_64
init|=
literal|126
block|,
name|dwarf_bnd1_x86_64
block|,
name|dwarf_bnd2_x86_64
block|,
name|dwarf_bnd3_x86_64
block|,
comment|// AVX2 Vector Mask Registers
comment|// dwarf_k0_x86_64 = 118,
comment|// dwarf_k1_x86_64,
comment|// dwarf_k2_x86_64,
comment|// dwarf_k3_x86_64,
comment|// dwarf_k4_x86_64,
comment|// dwarf_k5_x86_64,
comment|// dwarf_k6_x86_64,
comment|// dwarf_k7_x86_64,
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
name|i386_
struct|;
comment|// Added _ in the end to avoid error with gcc defining i386 in some
comment|// cases
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
name|uint8_t
name|padding1
index|[
literal|48
index|]
decl_stmt|;
name|uint64_t
name|xcr0
decl_stmt|;
name|uint8_t
name|padding2
index|[
literal|40
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
name|MPXReg
block|{
name|uint8_t
name|bytes
index|[
literal|16
index|]
decl_stmt|;
comment|// MPX 128 bit bound registers
block|}
struct|;
end_struct

begin_struct
struct|struct
name|MPXCsr
block|{
name|uint8_t
name|bytes
index|[
literal|8
index|]
decl_stmt|;
comment|// MPX 64 bit bndcfgu and bndstatus registers (collectively
comment|// BNDCSR state)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|MPX
block|{
name|MPXReg
name|mpxr
index|[
literal|4
index|]
decl_stmt|;
name|MPXCsr
name|mpxc
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_macro
name|LLVM_PACKED_START
end_macro

begin_struct
struct|struct
name|XSAVE_HDR
block|{
name|uint64_t
name|xstate_bv
decl_stmt|;
comment|// OS enabled xstate mask to determine the extended states
comment|// supported by the processor
name|uint64_t
name|xcomp_bv
decl_stmt|;
comment|// Mask to indicate the format of the XSAVE area and of
comment|// the XRSTOR instruction
name|uint64_t
name|reserved1
index|[
literal|1
index|]
decl_stmt|;
name|uint64_t
name|reserved2
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|LLVM_PACKED_END
comment|// x86 extensions to FXSAVE (i.e. for AVX and MPX processors)
name|LLVM_PACKED_START
expr|struct
name|LLVM_ALIGNAS
argument_list|(
literal|64
argument_list|)
name|XSAVE
block|{
name|FXSAVE
name|i387
block|;
comment|// floating point registers typical in i387_fxsave_struct
name|XSAVE_HDR
name|header
block|;
comment|// The xsave_hdr_struct can be used to determine if the
comment|// following extensions are usable
name|YMMHReg
name|ymmh
index|[
literal|16
index|]
block|;
comment|// High 16 bytes of each of 16 YMM registers (the low bytes
comment|// are in FXSAVE.xmm for compatibility with SSE)
name|uint64_t
name|reserved3
index|[
literal|16
index|]
block|;
name|MPXReg
name|mpxr
index|[
literal|4
index|]
block|;
comment|// MPX BNDREG state, containing 128-bit bound registers
name|MPXCsr
name|mpxc
index|[
literal|2
index|]
block|;
comment|// MPX BNDCSR state, containing 64-bit BNDCFGU and
comment|// BNDSTATUS registers
block|}
expr_stmt|;
end_expr_stmt

begin_macro
name|LLVM_PACKED_END
end_macro

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

