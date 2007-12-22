begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2001 by Thomas Moestl<tmm@FreeBSD.org>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TSTATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TSTATE_H_
end_define

begin_include
include|#
directive|include
file|<machine/pstate.h>
end_include

begin_include
include|#
directive|include
file|<machine/ccr.h>
end_include

begin_define
define|#
directive|define
name|TSTATE_CWP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TSTATE_CWP_BITS
value|5
end_define

begin_define
define|#
directive|define
name|TSTATE_CWP_MASK
define|\
value|(((1<< TSTATE_CWP_BITS) - 1)<< TSTATE_CWP_SHIFT)
end_define

begin_define
define|#
directive|define
name|TSTATE_CWP
parameter_list|(
name|x
parameter_list|)
value|((x& TSTATE_CWP_MASK)>> TSTATE_CWP_SHIFT)
end_define

begin_define
define|#
directive|define
name|TSTATE_PSTATE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|TSTATE_PSTATE_BITS
value|12
end_define

begin_define
define|#
directive|define
name|TSTATE_PSTATE_MASK
define|\
value|(((1<< TSTATE_PSTATE_BITS) - 1)<< TSTATE_PSTATE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TSTATE_PSTATE
parameter_list|(
name|x
parameter_list|)
value|((x)<< TSTATE_PSTATE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TSTATE_AG
value|TSTATE_PSTATE(PSTATE_AG)
end_define

begin_define
define|#
directive|define
name|TSTATE_IE
value|TSTATE_PSTATE(PSTATE_IE)
end_define

begin_define
define|#
directive|define
name|TSTATE_PRIV
value|TSTATE_PSTATE(PSTATE_PRIV)
end_define

begin_define
define|#
directive|define
name|TSTATE_AM
value|TSTATE_PSTATE(PSTATE_AM)
end_define

begin_define
define|#
directive|define
name|TSTATE_PEF
value|TSTATE_PSTATE(PSTATE_PEF)
end_define

begin_define
define|#
directive|define
name|TSTATE_RED
value|TSTATE_PSTATE(PSTATE_RED)
end_define

begin_define
define|#
directive|define
name|TSTATE_MM_TSO
value|TSTATE_PSTATE(PSTATE_MM_TSO)
end_define

begin_define
define|#
directive|define
name|TSTATE_MM_PSO
value|TSTATE_PSTATE(PSTATE_MM_PSO)
end_define

begin_define
define|#
directive|define
name|TSTATE_MM_RMO
value|TSTATE_PSTATE(PSTATE_MM_RMO)
end_define

begin_define
define|#
directive|define
name|TSTATE_TLE
value|TSTATE_PSTATE(PSTATE_TLE)
end_define

begin_define
define|#
directive|define
name|TSTATE_CLE
value|TSTATE_PSTATE(PSTATE_CLE)
end_define

begin_define
define|#
directive|define
name|TSTATE_MG
value|TSTATE_PSTATE(PSTATE_MG)
end_define

begin_define
define|#
directive|define
name|TSTATE_IG
value|TSTATE_PSTATE(PSTATE_IG)
end_define

begin_define
define|#
directive|define
name|TSTATE_ASI_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|TSTATE_ASI_BITS
value|8
end_define

begin_define
define|#
directive|define
name|TSTATE_ASI_MASK
define|\
value|(((1<< TSTATE_ASI_BITS) - 1)<< TSTATE_ASI_SHIFT)
end_define

begin_define
define|#
directive|define
name|TSTATE_ASI
parameter_list|(
name|x
parameter_list|)
value|((x& TSTATE_ASI_MASK)>> TSTATE_ASI_SHIFT)
end_define

begin_define
define|#
directive|define
name|TSTATE_CCR_SHIFT
value|32
end_define

begin_define
define|#
directive|define
name|TSTATE_ICC_SHIFT
value|(TSTATE_CCR_SHIFT + ICC_SHIFT)
end_define

begin_define
define|#
directive|define
name|TSTATE_ICC_MASK
value|(ICC_MASK<< TSTATE_CCR_SHIFT)
end_define

begin_define
define|#
directive|define
name|TSTATE_XCC_SHIFT
value|(TSTATE_CCR_SHIFT + XCC_SHIFT)
end_define

begin_define
define|#
directive|define
name|TSTATE_XCC_MASK
value|(XCC_MASK<< TSTATE_CCR_SHIFT)
end_define

begin_define
define|#
directive|define
name|TSTATE_CCR
parameter_list|(
name|x
parameter_list|)
value|((x)<< TSTATE_CCR_SHIFT)
end_define

begin_define
define|#
directive|define
name|TSTATE_ICC_C
value|TSTATE_CCR(ICC_C)
end_define

begin_define
define|#
directive|define
name|TSTATE_ICC_V
value|TSTATE_CCR(ICC_V)
end_define

begin_define
define|#
directive|define
name|TSTATE_ICC_Z
value|TSTATE_CCR(ICC_Z)
end_define

begin_define
define|#
directive|define
name|TSTATE_ICC_N
value|TSTATE_CCR(ICC_N)
end_define

begin_define
define|#
directive|define
name|TSTATE_XCC_C
value|TSTATE_CCR(XCC_C)
end_define

begin_define
define|#
directive|define
name|TSTATE_XCC_V
value|TSTATE_CCR(XCC_V)
end_define

begin_define
define|#
directive|define
name|TSTATE_XCC_Z
value|TSTATE_CCR(XCC_Z)
end_define

begin_define
define|#
directive|define
name|TSTATE_XCC_N
value|TSTATE_CCR(XCC_N)
end_define

begin_define
define|#
directive|define
name|TSTATE_SECURE
parameter_list|(
name|tstate
parameter_list|)
define|\
value|PSTATE_SECURE(((tstate)>> TSTATE_PSTATE_SHIFT)& ((1<< TSTATE_PSTATE_BITS) - 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_TSTATE_H_ */
end_comment

end_unit

