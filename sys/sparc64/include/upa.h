begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 by Thomas Moestl<tmm@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_UPA_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_UPA_H_
end_define

begin_define
define|#
directive|define
name|UPA_MEMSTART
value|0x1fc00000000UL
end_define

begin_define
define|#
directive|define
name|UPA_MEMEND
value|0x1ffffffffffUL
end_define

begin_define
define|#
directive|define
name|UPA_CR_MID_SHIFT
value|(17)
end_define

begin_define
define|#
directive|define
name|UPA_CR_MID_SIZE
value|(5)
end_define

begin_define
define|#
directive|define
name|UPA_CR_MID_MASK
define|\
value|(((1<< UPA_CR_MID_SIZE) - 1)<< UPA_CR_MID_SHIFT)
end_define

begin_define
define|#
directive|define
name|UPA_CR_GET_MID
parameter_list|(
name|cr
parameter_list|)
value|((cr& UPA_CR_MID_MASK)>> UPA_CR_MID_SHIFT)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

begin_define
define|#
directive|define
name|UPA_GET_MID
parameter_list|(
name|r1
parameter_list|)
define|\
value|ldxa	[%g0] ASI_UPA_CONFIG_REG, r1 ; \ 	srlx	r1, UPA_CR_MID_SHIFT, r1 ; \ 	and	r1, (1<< UPA_CR_MID_SIZE) - 1, r1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_UPA_H_ */
end_comment

end_unit

