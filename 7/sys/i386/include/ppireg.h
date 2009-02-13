begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2005 TAKAHASHI Yoshihiro. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PPIREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PPIREG_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IO_PPI
value|0x61
end_define

begin_comment
comment|/* Programmable Peripheral Interface */
end_comment

begin_comment
comment|/*  * PPI speaker control values  */
end_comment

begin_define
define|#
directive|define
name|PIT_ENABLETMR2
value|0x01
end_define

begin_comment
comment|/* Enable timer/counter 2 */
end_comment

begin_define
define|#
directive|define
name|PIT_SPKRDATA
value|0x02
end_define

begin_comment
comment|/* Direct to speaker */
end_comment

begin_define
define|#
directive|define
name|PIT_SPKR
value|(PIT_ENABLETMR2 | PIT_SPKRDATA)
end_define

begin_define
define|#
directive|define
name|ppi_spkr_on
parameter_list|()
value|outb(IO_PPI, inb(IO_PPI) | PIT_SPKR)
end_define

begin_define
define|#
directive|define
name|ppi_spkr_off
parameter_list|()
value|outb(IO_PPI, inb(IO_PPI)& ~PIT_SPKR)
end_define

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
comment|/* _MACHINE_PPIREG_H_ */
end_comment

end_unit

