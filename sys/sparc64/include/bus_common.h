begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	form: @(#)sbusreg.h	8.1 (Berkeley) 6/11/93  *	from: NetBSD: iommureg.h,v 1.6 2001/07/20 00:07:13 eeh Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_BUS_COMMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_BUS_COMMON_H_
end_define

begin_define
define|#
directive|define
name|INTMAP_V
value|0x080000000LL
end_define

begin_comment
comment|/* Interrupt valid (enabled) */
end_comment

begin_define
define|#
directive|define
name|INTMAP_TID
value|0x07c000000LL
end_define

begin_comment
comment|/* UPA target ID mask */
end_comment

begin_define
define|#
directive|define
name|INTMAP_IGN
value|0x0000007c0LL
end_define

begin_comment
comment|/* Interrupt group no (sbus only). */
end_comment

begin_define
define|#
directive|define
name|INTMAP_INO
value|0x00000003fLL
end_define

begin_comment
comment|/* Interrupt number */
end_comment

begin_define
define|#
directive|define
name|INTMAP_INR
value|(INTMAP_IGN | INTMAP_INO)
end_define

begin_define
define|#
directive|define
name|INTMAP_SBUSSLOT
value|0x000000018LL
end_define

begin_comment
comment|/* SBUS slot # */
end_comment

begin_define
define|#
directive|define
name|INTMAP_PCIBUS
value|0x000000010LL
end_define

begin_comment
comment|/* PCI bus number (A or B) */
end_comment

begin_define
define|#
directive|define
name|INTMAP_PCISLOT
value|0x00000000cLL
end_define

begin_comment
comment|/* PCI slot # */
end_comment

begin_define
define|#
directive|define
name|INTMAP_PCIINT
value|0x000000003LL
end_define

begin_comment
comment|/* PCI interrupt #A,#B,#C,#D */
end_comment

begin_define
define|#
directive|define
name|INTMAP_OBIO
value|0x000000020LL
end_define

begin_comment
comment|/* Onboard device */
end_comment

begin_define
define|#
directive|define
name|INTMAP_LSHIFT
value|11
end_define

begin_comment
comment|/* Encode level in vector */
end_comment

begin_define
define|#
directive|define
name|INTLEVENCODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x0f)<< INTMAP_LSHIFT)
end_define

begin_define
define|#
directive|define
name|INTLEV
parameter_list|(
name|x
parameter_list|)
value|(((x)>> INTMAP_LSHIFT)& 0x0f)
end_define

begin_define
define|#
directive|define
name|INTVEC
parameter_list|(
name|x
parameter_list|)
value|((x)& INTMAP_INR)
end_define

begin_define
define|#
directive|define
name|INTSLOT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x7)
end_define

begin_define
define|#
directive|define
name|INTPRI
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7)
end_define

begin_define
define|#
directive|define
name|INTINO
parameter_list|(
name|x
parameter_list|)
value|((x)& INTMAP_INO)
end_define

begin_comment
comment|/* counter-timer support. */
end_comment

begin_function_decl
name|void
name|sparc64_counter_init
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|handle
parameter_list|,
name|bus_addr_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_BUS_COMMON_H_ */
end_comment

end_unit

