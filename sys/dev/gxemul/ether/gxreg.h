begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2012 Juli Mallett<jmallett@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_GXEMUL_ETHER_GXREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_GXEMUL_ETHER_GXREG_H_
end_define

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_BASE
value|(0x14000000)
end_define

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_IRQ
value|(3)
end_define

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_MTU
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_BUFFER
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_STATUS
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_LENGTH
value|(0x4010)
end_define

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_COMMAND
value|(0x4020)
end_define

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_MAC
value|(0x4040)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_LP64
end_ifdef

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_FUNCTION
parameter_list|(
name|f
parameter_list|)
define|\
value|(volatile uint64_t *)MIPS_PHYS_TO_DIRECT_UNCACHED(GXEMUL_ETHER_DEV_BASE + (f))
end_define

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_READ
parameter_list|(
name|f
parameter_list|)
define|\
value|(volatile uint64_t)*GXEMUL_ETHER_DEV_FUNCTION(f)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_FUNCTION
parameter_list|(
name|f
parameter_list|)
define|\
value|(volatile uint32_t *)MIPS_PHYS_TO_DIRECT_UNCACHED(GXEMUL_ETHER_DEV_BASE + (f))
end_define

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_READ
parameter_list|(
name|f
parameter_list|)
define|\
value|(volatile uint32_t)*GXEMUL_ETHER_DEV_FUNCTION(f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_WRITE
parameter_list|(
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|*GXEMUL_ETHER_DEV_FUNCTION(f) = (v)
end_define

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_STATUS_RX_OK
value|(0x01)
end_define

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_STATUS_RX_MORE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_COMMAND_RX
value|(0x00)
end_define

begin_define
define|#
directive|define
name|GXEMUL_ETHER_DEV_COMMAND_TX
value|(0x01)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_GXEMUL_ETHER_GXREG_H_ */
end_comment

end_unit

