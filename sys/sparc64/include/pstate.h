begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PSTATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PSTATE_H_
end_define

begin_define
define|#
directive|define
name|PSTATE_AG
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PSTATE_IE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|PSTATE_PRIV
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|PSTATE_AM
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|PSTATE_PEF
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|PSTATE_RED
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|PSTATE_MM_SHIFT
value|(6)
end_define

begin_define
define|#
directive|define
name|PSTATE_MM_SIZE
value|(2)
end_define

begin_define
define|#
directive|define
name|PSTATE_MM_MASK
value|(((1<<PSTATE_MM_SIZE)-1)<<PSTATE_MM_SHIFT)
end_define

begin_define
define|#
directive|define
name|PSTATE_MM_TSO
value|(0<<PSTATE_MM_SHIFT)
end_define

begin_define
define|#
directive|define
name|PSTATE_MM_PSO
value|(1<<PSTATE_MM_SHIFT)
end_define

begin_define
define|#
directive|define
name|PSTATE_MM_RMO
value|(2<<PSTATE_MM_SHIFT)
end_define

begin_define
define|#
directive|define
name|PSTATE_TLE
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|PSTATE_CLE
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|PSTATE_MG
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|PSTATE_IG
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|PSTATE_MM
value|PSTATE_MM_TSO
end_define

begin_define
define|#
directive|define
name|PSTATE_NORMAL
value|(PSTATE_MM | PSTATE_PEF | PSTATE_PRIV)
end_define

begin_define
define|#
directive|define
name|PSTATE_ALT
value|(PSTATE_NORMAL | PSTATE_AG)
end_define

begin_define
define|#
directive|define
name|PSTATE_INTR
value|(PSTATE_NORMAL | PSTATE_IG)
end_define

begin_define
define|#
directive|define
name|PSTATE_MMU
value|(PSTATE_NORMAL | PSTATE_MG)
end_define

begin_define
define|#
directive|define
name|PSTATE_KERNEL
value|(PSTATE_NORMAL | PSTATE_IE)
end_define

begin_define
define|#
directive|define
name|PSTATE_SECURE
parameter_list|(
name|pstate
parameter_list|)
define|\
value|(((pstate)& ~(PSTATE_AM|PSTATE_MM_MASK)) == (PSTATE_IE|PSTATE_PEF))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PSTATE_H_ */
end_comment

end_unit

