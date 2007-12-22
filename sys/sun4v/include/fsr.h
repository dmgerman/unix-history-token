begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2001 by Thomas Moestl<tmm@FreeBSD.org>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_FSR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_FSR_H_
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

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_define
define|#
directive|define
name|FSR_EXC_BITS
value|5
end_define

begin_define
define|#
directive|define
name|FSR_EXC_MASK
value|((1UL<< FSR_EXC_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|FSR_CEXC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FSR_CEXC_MASK
value|(FSR_EXC_MASK<< FSR_CEXC_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_CEXC
parameter_list|(
name|b
parameter_list|)
value|((unsigned long)(b)<< FSR_CEXC_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_GET_CEXC
parameter_list|(
name|x
parameter_list|)
value|(((x)& FSR_CEXC_MASK)>> FSR_CEXC_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_AEXC_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|FSR_AEXC_MASK
value|(FSR_EXC_MASK<< FSR_AEXC_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_AEXC
parameter_list|(
name|b
parameter_list|)
value|((unsigned long)(b)<< FSR_AEXC_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_GET_AEXC
parameter_list|(
name|x
parameter_list|)
value|(((x)& FSR_AEXC_MASK)>> FSR_AEXC_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_QNE
value|(1UL<< 13)
end_define

begin_define
define|#
directive|define
name|FSR_NS
value|(1UL<< 22)
end_define

begin_define
define|#
directive|define
name|FSR_TEM_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|FSR_TEM_MASK
value|(FSR_EXC_MASK<< FSR_TEM_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_TEM
parameter_list|(
name|b
parameter_list|)
value|((unsigned long)(b)<< FSR_TEM_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_GET_TEM
parameter_list|(
name|x
parameter_list|)
value|(((x)& FSR_TEM_MASK)>> FSR_TEM_SHIFT)
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
name|FSR_FCC0_BITS
value|2
end_define

begin_define
define|#
directive|define
name|FSR_FCC0_MASK
value|(((1UL<< FSR_FCC0_BITS) - 1)<< FSR_FCC0_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_FCC0
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)<< FSR_FCC0_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_GET_FCC0
parameter_list|(
name|x
parameter_list|)
value|(((x)& FSR_FCC0_MASK)>> FSR_FCC0_SHIFT)
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
name|FSR_FTT_BITS
value|3
end_define

begin_define
define|#
directive|define
name|FSR_FTT_MASK
value|(((1UL<< FSR_FTT_BITS) - 1)<< FSR_FTT_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_FTT
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)<< FSR_FTT_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_GET_FTT
parameter_list|(
name|x
parameter_list|)
value|(((x)& FSR_FTT_MASK)>> FSR_FTT_SHIFT)
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
name|FSR_GET_VER
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
name|FSR_RD_BITS
value|2
end_define

begin_define
define|#
directive|define
name|FSR_RD_MASK
value|(((1UL<< FSR_RD_BITS) - 1)<< FSR_RD_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_RD
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)<< FSR_RD_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_GET_RD
parameter_list|(
name|x
parameter_list|)
value|(((x)& FSR_RD_MASK)>> FSR_RD_SHIFT)
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
name|FSR_FCC1_BITS
value|2
end_define

begin_define
define|#
directive|define
name|FSR_FCC1_MASK
value|(((1UL<< FSR_FCC1_BITS) - 1)<< FSR_FCC1_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_FCC1
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)<< FSR_FCC1_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_GET_FCC1
parameter_list|(
name|x
parameter_list|)
value|(((x)& FSR_FCC1_MASK)>> FSR_FCC1_SHIFT)
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
name|FSR_FCC2_BITS
value|2
end_define

begin_define
define|#
directive|define
name|FSR_FCC2_MASK
value|(((1UL<< FSR_FCC2_BITS) - 1)<< FSR_FCC2_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_FCC2
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)<< FSR_FCC2_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_GET_FCC2
parameter_list|(
name|x
parameter_list|)
value|(((x)& FSR_FCC2_MASK)>> FSR_FCC2_SHIFT)
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
name|FSR_FCC3_BITS
value|2
end_define

begin_define
define|#
directive|define
name|FSR_FCC3_MASK
value|(((1UL<< FSR_FCC3_BITS) - 1)<< FSR_FCC3_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_FCC3
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)<< FSR_FCC3_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSR_GET_FCC3
parameter_list|(
name|x
parameter_list|)
value|(((x)& FSR_FCC3_MASK)>> FSR_FCC3_SHIFT)
end_define

begin_comment
comment|/* CEXC/AEXC/TEM exception values */
end_comment

begin_define
define|#
directive|define
name|FSR_NX
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|FSR_DZ
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|FSR_UF
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|FSR_OF
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|FSR_NV
value|(1<< 4)
end_define

begin_comment
comment|/* FTT values. */
end_comment

begin_define
define|#
directive|define
name|FSR_FTT_NONE
value|0
end_define

begin_define
define|#
directive|define
name|FSR_FTT_IEEE
value|1
end_define

begin_define
define|#
directive|define
name|FSR_FTT_UNFIN
value|2
end_define

begin_define
define|#
directive|define
name|FSR_FTT_UNIMP
value|3
end_define

begin_define
define|#
directive|define
name|FSR_FTT_SEQERR
value|4
end_define

begin_define
define|#
directive|define
name|FSR_FTT_HWERR
value|5
end_define

begin_define
define|#
directive|define
name|FSR_FTT_INVREG
value|6
end_define

begin_comment
comment|/* RD values */
end_comment

begin_define
define|#
directive|define
name|FSR_RD_N
value|0
end_define

begin_comment
comment|/* nearest */
end_comment

begin_define
define|#
directive|define
name|FSR_RD_Z
value|1
end_define

begin_comment
comment|/* zero */
end_comment

begin_define
define|#
directive|define
name|FSR_RD_PINF
value|2
end_define

begin_comment
comment|/* +infinity */
end_comment

begin_define
define|#
directive|define
name|FSR_RD_NINF
value|3
end_define

begin_comment
comment|/* -infinity */
end_comment

begin_comment
comment|/* condition codes */
end_comment

begin_define
define|#
directive|define
name|FSR_CC_EQ
value|0
end_define

begin_comment
comment|/* a = b */
end_comment

begin_define
define|#
directive|define
name|FSR_CC_LT
value|1
end_define

begin_comment
comment|/* a< b */
end_comment

begin_define
define|#
directive|define
name|FSR_CC_GT
value|2
end_define

begin_comment
comment|/* a> b */
end_comment

begin_define
define|#
directive|define
name|FSR_CC_UO
value|3
end_define

begin_comment
comment|/* unordered */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_FSR_H_ */
end_comment

end_unit

