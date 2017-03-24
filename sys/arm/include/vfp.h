begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2012 Mark Tinguely  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE__VFP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE__VFP_H_
end_define

begin_comment
comment|/* fpsid, fpscr, fpexc are defined in the newer gas */
end_comment

begin_define
define|#
directive|define
name|VFPSID
value|cr0
end_define

begin_define
define|#
directive|define
name|VFPSCR
value|cr1
end_define

begin_define
define|#
directive|define
name|VMVFR1
value|cr6
end_define

begin_define
define|#
directive|define
name|VMVFR0
value|cr7
end_define

begin_define
define|#
directive|define
name|VFPEXC
value|cr8
end_define

begin_define
define|#
directive|define
name|VFPINST
value|cr9
end_define

begin_comment
comment|/* vfp 1 and 2 except instruction */
end_comment

begin_define
define|#
directive|define
name|VFPINST2
value|cr10
end_define

begin_comment
comment|/* vfp 2? */
end_comment

begin_comment
comment|/* VFPSID */
end_comment

begin_define
define|#
directive|define
name|VFPSID_IMPLEMENTOR_OFF
value|24
end_define

begin_define
define|#
directive|define
name|VFPSID_IMPLEMENTOR_MASK
value|(0xff000000)
end_define

begin_define
define|#
directive|define
name|VFPSID_HARDSOFT_IMP
value|(0x00800000)
end_define

begin_define
define|#
directive|define
name|VFPSID_SINGLE_PREC
value|20
end_define

begin_comment
comment|/* version 1 and 2 */
end_comment

begin_define
define|#
directive|define
name|VFPSID_SUBVERSION_OFF
value|16
end_define

begin_define
define|#
directive|define
name|VFPSID_SUBVERSION2_MASK
value|(0x000f0000)
end_define

begin_comment
comment|/* version 1 and 2 */
end_comment

begin_define
define|#
directive|define
name|VFPSID_SUBVERSION3_MASK
value|(0x007f0000)
end_define

begin_comment
comment|/* version 3 */
end_comment

begin_define
define|#
directive|define
name|VFP_ARCH1
value|0x0
end_define

begin_define
define|#
directive|define
name|VFP_ARCH2
value|0x1
end_define

begin_define
define|#
directive|define
name|VFP_ARCH3
value|0x2
end_define

begin_define
define|#
directive|define
name|VFPSID_PARTNUMBER_OFF
value|8
end_define

begin_define
define|#
directive|define
name|VFPSID_PARTNUMBER_MASK
value|(0x0000ff00)
end_define

begin_define
define|#
directive|define
name|VFPSID_VARIANT_OFF
value|4
end_define

begin_define
define|#
directive|define
name|VFPSID_VARIANT_MASK
value|(0x000000f0)
end_define

begin_define
define|#
directive|define
name|VFPSID_REVISION_MASK
value|0x0f
end_define

begin_comment
comment|/* VFPSCR */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_CC_N
value|(0x80000000)
end_define

begin_comment
comment|/* comparison less than */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_CC_Z
value|(0x40000000)
end_define

begin_comment
comment|/* comparison equal */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_CC_C
value|(0x20000000)
end_define

begin_comment
comment|/* comparison => unordered */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_CC_V
value|(0x10000000)
end_define

begin_comment
comment|/* comparison unordered */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_QC
value|(0x08000000)
end_define

begin_comment
comment|/* saturation cululative */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_DN
value|(0x02000000)
end_define

begin_comment
comment|/* default NaN enable */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_FZ
value|(0x01000000)
end_define

begin_comment
comment|/* flush to zero enabled */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_RMODE_OFF
value|22
end_define

begin_comment
comment|/* rounding mode offset */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_RMODE_MASK
value|(0x00c00000)
end_define

begin_comment
comment|/* rounding mode mask */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_RMODE_RN
value|(0x00000000)
end_define

begin_comment
comment|/* round nearest */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_RMODE_RPI
value|(0x00400000)
end_define

begin_comment
comment|/* round to plus infinity */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_RMODE_RNI
value|(0x00800000)
end_define

begin_comment
comment|/* round to neg infinity */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_RMODE_RM
value|(0x00c00000)
end_define

begin_comment
comment|/* round to zero */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_STRIDE_OFF
value|20
end_define

begin_comment
comment|/* vector stride -1 */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_STRIDE_MASK
value|(0x00300000)
end_define

begin_define
define|#
directive|define
name|VFPSCR_LEN_OFF
value|16
end_define

begin_comment
comment|/* vector length -1 */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_LEN_MASK
value|(0x00070000)
end_define

begin_define
define|#
directive|define
name|VFPSCR_IDE
value|(0x00008000)
end_define

begin_comment
comment|/* input subnormal exc enable */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_IXE
value|(0x00001000)
end_define

begin_comment
comment|/* inexact exception enable */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_UFE
value|(0x00000800)
end_define

begin_comment
comment|/* underflow exception enable */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_OFE
value|(0x00000400)
end_define

begin_comment
comment|/* overflow exception enable */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_DNZ
value|(0x00000200)
end_define

begin_comment
comment|/* div by zero exception en */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_IOE
value|(0x00000100)
end_define

begin_comment
comment|/* invalid op exec enable */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_IDC
value|(0x00000080)
end_define

begin_comment
comment|/* input subnormal cumul */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_IXC
value|(0x00000010)
end_define

begin_comment
comment|/* Inexact cumulative flag */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_UFC
value|(0x00000008)
end_define

begin_comment
comment|/* underflow cumulative flag */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_OFC
value|(0x00000004)
end_define

begin_comment
comment|/* overflow cumulative flag */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_DZC
value|(0x00000002)
end_define

begin_comment
comment|/* division by zero flag */
end_comment

begin_define
define|#
directive|define
name|VFPSCR_IOC
value|(0x00000001)
end_define

begin_comment
comment|/* invalid operation cumul */
end_comment

begin_comment
comment|/* VFPEXC */
end_comment

begin_define
define|#
directive|define
name|VFPEXC_EX
value|(0x80000000)
end_define

begin_comment
comment|/* exception v1 v2 */
end_comment

begin_define
define|#
directive|define
name|VFPEXC_EN
value|(0x40000000)
end_define

begin_comment
comment|/* vfp enable */
end_comment

begin_define
define|#
directive|define
name|VFPEXC_DEX
value|(0x20000000)
end_define

begin_comment
comment|/* Synchronous exception */
end_comment

begin_define
define|#
directive|define
name|VFPEXC_FP2V
value|(0x10000000)
end_define

begin_comment
comment|/* FPINST2 valid */
end_comment

begin_define
define|#
directive|define
name|VFPEXC_INV
value|(0x00000080)
end_define

begin_comment
comment|/* Input exception */
end_comment

begin_define
define|#
directive|define
name|VFPEXC_UFC
value|(0x00000008)
end_define

begin_comment
comment|/* Underflow exception */
end_comment

begin_define
define|#
directive|define
name|VFPEXC_OFC
value|(0x00000004)
end_define

begin_comment
comment|/* Overflow exception */
end_comment

begin_define
define|#
directive|define
name|VFPEXC_IOC
value|(0x00000001)
end_define

begin_comment
comment|/* Invlaid operation */
end_comment

begin_comment
comment|/* version 3 registers */
end_comment

begin_comment
comment|/* VMVFR0 */
end_comment

begin_define
define|#
directive|define
name|VMVFR0_RM_OFF
value|28
end_define

begin_define
define|#
directive|define
name|VMVFR0_RM_MASK
value|(0xf0000000)
end_define

begin_comment
comment|/* VFP rounding modes */
end_comment

begin_define
define|#
directive|define
name|VMVFR0_SV_OFF
value|24
end_define

begin_define
define|#
directive|define
name|VMVFR0_SV_MASK
value|(0x0f000000)
end_define

begin_comment
comment|/* VFP short vector supp */
end_comment

begin_define
define|#
directive|define
name|VMVFR0_SR_OFF
value|20
end_define

begin_define
define|#
directive|define
name|VMVFR0_SR
value|(0x00f00000)
end_define

begin_comment
comment|/* VFP hw sqrt supp */
end_comment

begin_define
define|#
directive|define
name|VMVFR0_D_OFF
value|16
end_define

begin_define
define|#
directive|define
name|VMVFR0_D_MASK
value|(0x000f0000)
end_define

begin_comment
comment|/* VFP divide supp */
end_comment

begin_define
define|#
directive|define
name|VMVFR0_TE_OFF
value|12
end_define

begin_define
define|#
directive|define
name|VMVFR0_TE_MASK
value|(0x0000f000)
end_define

begin_comment
comment|/* VFP trap exception supp */
end_comment

begin_define
define|#
directive|define
name|VMVFR0_DP_OFF
value|8
end_define

begin_define
define|#
directive|define
name|VMVFR0_DP_MASK
value|(0x00000f00)
end_define

begin_comment
comment|/* VFP double prec support */
end_comment

begin_define
define|#
directive|define
name|VMVFR0_SP_OFF
value|4
end_define

begin_define
define|#
directive|define
name|VMVFR0_SP_MASK
value|(0x000000f0)
end_define

begin_comment
comment|/* VFP single prec support */
end_comment

begin_define
define|#
directive|define
name|VMVFR0_RB_MASK
value|(0x0000000f)
end_define

begin_comment
comment|/* VFP 64 bit media support */
end_comment

begin_comment
comment|/* VMVFR1 */
end_comment

begin_define
define|#
directive|define
name|VMVFR1_SP_OFF
value|16
end_define

begin_define
define|#
directive|define
name|VMVFR1_SP_MASK
value|(0x000f0000)
end_define

begin_comment
comment|/* Neon single prec support */
end_comment

begin_define
define|#
directive|define
name|VMVFR1_I_OFF
value|12
end_define

begin_define
define|#
directive|define
name|VMVFR1_I_MASK
value|(0x0000f000)
end_define

begin_comment
comment|/* Neon integer support */
end_comment

begin_define
define|#
directive|define
name|VMVFR1_LS_OFF
value|8
end_define

begin_define
define|#
directive|define
name|VMVFR1_LS_MASK
value|(0x00000f00)
end_define

begin_comment
comment|/* Neon ld/st instr support */
end_comment

begin_define
define|#
directive|define
name|VMVFR1_DN_OFF
value|4
end_define

begin_define
define|#
directive|define
name|VMVFR1_DN_MASK
value|(0x000000f0)
end_define

begin_comment
comment|/* Neon prop NaN support */
end_comment

begin_define
define|#
directive|define
name|VMVFR1_FZ_MASK
value|(0x0000000f)
end_define

begin_comment
comment|/* Neon denormal arith supp */
end_comment

begin_define
define|#
directive|define
name|COPROC10
value|(0x3<< 20)
end_define

begin_define
define|#
directive|define
name|COPROC11
value|(0x3<< 22)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|vfp_state
block|{
name|uint64_t
name|reg
index|[
literal|32
index|]
decl_stmt|;
name|uint32_t
name|fpscr
decl_stmt|;
name|uint32_t
name|fpexec
decl_stmt|;
name|uint32_t
name|fpinst
decl_stmt|;
name|uint32_t
name|fpinst2
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|vfp_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfp_store
parameter_list|(
name|struct
name|vfp_state
modifier|*
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfp_discard
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

