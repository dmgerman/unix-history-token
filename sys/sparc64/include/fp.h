begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2001 by Thomas Moestl<tmm@FreeBSD.org>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_FP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_FP_H_
end_define

begin_define
define|#
directive|define
name|FPRS_DL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|FPRS_DU
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|FPRS_FEF
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|FSR_CEXC_NX
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|FSR_CEXC_DZ
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|FSR_CEXC_UF
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|FSR_CEXC_OF
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|FSR_CEXC_NV
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|FSR_AEXC_NX
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|FSR_AEXC_DZ
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|FSR_AEXC_UF
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|FSR_AEXC_OF
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|FSR_AEXC_NV
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|FSR_QNE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|FSR_NS
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|FSR_TEM_NX
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|FSR_TEM_DZ
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|FSR_TEM_UF
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|FSR_TEM_OF
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|FSR_TEM_NV
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|FSR_FCC0_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|FSR_FCC0
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FSR_FCC0_SHIFT)& 3)
end_define

begin_define
define|#
directive|define
name|FSR_FTT_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|FSR_FTT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FSR_FTT_SHIFT)& 7)
end_define

begin_define
define|#
directive|define
name|FSR_VER_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|FSR_VER
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FSR_VER_SHIFT)& 7)
end_define

begin_define
define|#
directive|define
name|FSR_RD_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|FSR_RD
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FSR_RD_SHIFT)& 3)
end_define

begin_define
define|#
directive|define
name|FSR_FCC1_SHIFT
value|32
end_define

begin_define
define|#
directive|define
name|FSR_FCC1
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FSR_FCC1_SHIFT)& 3)
end_define

begin_define
define|#
directive|define
name|FSR_FCC2_SHIFT
value|34
end_define

begin_define
define|#
directive|define
name|FSR_FCC2
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FSR_FCC2_SHIFT)& 3)
end_define

begin_define
define|#
directive|define
name|FSR_FCC3_SHIFT
value|36
end_define

begin_define
define|#
directive|define
name|FSR_FCC3
parameter_list|(
name|x
parameter_list|)
value|(((x)>> FSR_FCC3_SHIFT)& 3)
end_define

begin_comment
comment|/* A block of 8 double-precision (16 single-precision) FP registers. */
end_comment

begin_struct
struct|struct
name|fpblock
block|{
name|u_long
name|fpq_l
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fpstate
block|{
name|struct
name|fpblock
name|fp_fb
index|[
literal|4
index|]
decl_stmt|;
name|u_long
name|fp_fsr
decl_stmt|;
name|u_long
name|fp_fprs
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|fp_init_pcb
parameter_list|(
name|struct
name|pcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fp_enable_proc
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Note: The pointers passed to the next two functions must be aligned on  * 64 byte boundaries.  */
end_comment

begin_function_decl
name|void
name|savefpctx
parameter_list|(
name|struct
name|fpstate
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|restorefpctx
parameter_list|(
name|struct
name|fpstate
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_FP_H_ */
end_comment

end_unit

