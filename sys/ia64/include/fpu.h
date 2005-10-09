begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_FPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_FPU_H_
end_define

begin_comment
comment|/*  * Floating point status register bits.  */
end_comment

begin_define
define|#
directive|define
name|IA64_FPSR_TRAP_VD
value|0x0000000000000001L
end_define

begin_define
define|#
directive|define
name|IA64_FPSR_TRAP_DD
value|0x0000000000000002L
end_define

begin_define
define|#
directive|define
name|IA64_FPSR_TRAP_ZD
value|0x0000000000000004L
end_define

begin_define
define|#
directive|define
name|IA64_FPSR_TRAP_OD
value|0x0000000000000008L
end_define

begin_define
define|#
directive|define
name|IA64_FPSR_TRAP_UD
value|0x0000000000000010L
end_define

begin_define
define|#
directive|define
name|IA64_FPSR_TRAP_ID
value|0x0000000000000020L
end_define

begin_define
define|#
directive|define
name|IA64_FPSR_SF
parameter_list|(
name|i
parameter_list|,
name|v
parameter_list|)
value|((v)<< ((i)*13+6))
end_define

begin_define
define|#
directive|define
name|IA64_SF_FTZ
value|0x0001L
end_define

begin_define
define|#
directive|define
name|IA64_SF_WRE
value|0x0002L
end_define

begin_define
define|#
directive|define
name|IA64_SF_PC
value|0x000cL
end_define

begin_define
define|#
directive|define
name|IA64_SF_PC_0
value|0x0000L
end_define

begin_define
define|#
directive|define
name|IA64_SF_PC_1
value|0x0004L
end_define

begin_define
define|#
directive|define
name|IA64_SF_PC_2
value|0x0008L
end_define

begin_define
define|#
directive|define
name|IA64_SF_PC_3
value|0x000cL
end_define

begin_define
define|#
directive|define
name|IA64_SF_RC
value|0x0030L
end_define

begin_define
define|#
directive|define
name|IA64_SF_RC_NEAREST
value|0x0000L
end_define

begin_define
define|#
directive|define
name|IA64_SF_RC_NEGINF
value|0x0010L
end_define

begin_define
define|#
directive|define
name|IA64_SF_RC_POSINF
value|0x0020L
end_define

begin_define
define|#
directive|define
name|IA64_SF_RC_TRUNC
value|0x0030L
end_define

begin_define
define|#
directive|define
name|IA64_SF_TD
value|0x0040L
end_define

begin_define
define|#
directive|define
name|IA64_SF_V
value|0x0080L
end_define

begin_define
define|#
directive|define
name|IA64_SF_D
value|0x0100L
end_define

begin_define
define|#
directive|define
name|IA64_SF_Z
value|0x0200L
end_define

begin_define
define|#
directive|define
name|IA64_SF_O
value|0x0400L
end_define

begin_define
define|#
directive|define
name|IA64_SF_U
value|0x0800L
end_define

begin_define
define|#
directive|define
name|IA64_SF_I
value|0x1000L
end_define

begin_define
define|#
directive|define
name|IA64_SF_DEFAULT
value|(IA64_SF_PC_3 | IA64_SF_RC_NEAREST)
end_define

begin_define
define|#
directive|define
name|IA64_FPSR_DEFAULT
value|(IA64_FPSR_TRAP_VD			\ 				 | IA64_FPSR_TRAP_DD			\ 				 | IA64_FPSR_TRAP_ZD			\ 				 | IA64_FPSR_TRAP_OD			\ 				 | IA64_FPSR_TRAP_UD			\ 				 | IA64_FPSR_TRAP_ID			\ 				 | IA64_FPSR_SF(0, IA64_SF_DEFAULT)	\ 				 | IA64_FPSR_SF(1, (IA64_SF_DEFAULT	\ 						    | IA64_SF_TD	\ 						    | IA64_SF_WRE))	\ 				 | IA64_FPSR_SF(2, (IA64_SF_DEFAULT	\ 						    | IA64_SF_TD))	\ 				 | IA64_FPSR_SF(3, (IA64_SF_DEFAULT	\ 						    | IA64_SF_TD)))
end_define

begin_struct
struct|struct
name|fpswa_ret
block|{
name|unsigned
name|long
name|status
decl_stmt|;
name|unsigned
name|long
name|err1
decl_stmt|;
name|unsigned
name|long
name|err2
decl_stmt|;
name|unsigned
name|long
name|err3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fpswa_bundle
block|{
name|long
name|double
name|bits
decl_stmt|;
comment|/* Force 16-byte alignment. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fpswa_fpctx
block|{
name|unsigned
name|long
name|mask_low
decl_stmt|;
comment|/* f63 - f2 */
name|unsigned
name|long
name|mask_high
decl_stmt|;
comment|/* f127 - f64 */
name|union
name|_ia64_fpreg
modifier|*
name|fp_low_preserved
decl_stmt|;
comment|/* f2 - f5 */
name|union
name|_ia64_fpreg
modifier|*
name|fp_low_volatile
decl_stmt|;
comment|/* f6 - f15 */
name|union
name|_ia64_fpreg
modifier|*
name|fp_high_preserved
decl_stmt|;
comment|/* f16 - f31 */
name|union
name|_ia64_fpreg
modifier|*
name|fp_high_volatile
decl_stmt|;
comment|/* f32 - f127 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fpswa_iface
block|{
name|unsigned
name|int
name|if_rev
decl_stmt|;
name|unsigned
name|int
name|__res
decl_stmt|;
name|struct
name|fpswa_ret
function_decl|(
modifier|*
name|if_fpswa
function_decl|)
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|struct
name|fpswa_bundle
modifier|*
parameter_list|,
name|unsigned
name|long
modifier|*
parameter_list|,
name|unsigned
name|long
modifier|*
parameter_list|,
name|unsigned
name|long
modifier|*
parameter_list|,
name|unsigned
name|long
modifier|*
parameter_list|,
name|unsigned
name|long
modifier|*
parameter_list|,
name|struct
name|fpswa_fpctx
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_FPU_H_ */
end_comment

end_unit

