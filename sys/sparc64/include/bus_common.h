begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	form: @(#)sbusreg.h	8.1 (Berkeley) 6/11/93  *	from: NetBSD: iommureg.h,v 1.6 2001/07/20 00:07:13 eeh Exp  *  * $FreeBSD$  */
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
value|0x080000000ULL
end_define

begin_comment
comment|/* Interrupt valid (enabled) */
end_comment

begin_define
define|#
directive|define
name|INTMAP_TID_MASK
value|0x07c000000ULL
end_define

begin_comment
comment|/* UPA target ID */
end_comment

begin_define
define|#
directive|define
name|INTMAP_TID_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|INTMAP_IGN_MASK
value|0x0000007c0ULL
end_define

begin_comment
comment|/* Interrupt group no. */
end_comment

begin_define
define|#
directive|define
name|INTMAP_IGN_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|INTMAP_INO_MASK
value|0x00000003fULL
end_define

begin_comment
comment|/* Interrupt number */
end_comment

begin_define
define|#
directive|define
name|INTMAP_INR_MASK
value|(INTMAP_IGN_MASK | INTMAP_INO_MASK)
end_define

begin_define
define|#
directive|define
name|INTMAP_SBUSSLOT_MASK
value|0x000000018ULL
end_define

begin_comment
comment|/* SBus slot # */
end_comment

begin_define
define|#
directive|define
name|INTMAP_PCIBUS_MASK
value|0x000000010ULL
end_define

begin_comment
comment|/* PCI bus number (A or B) */
end_comment

begin_define
define|#
directive|define
name|INTMAP_PCISLOT_MASK
value|0x00000000cULL
end_define

begin_comment
comment|/* PCI slot # */
end_comment

begin_define
define|#
directive|define
name|INTMAP_PCIINT_MASK
value|0x000000003ULL
end_define

begin_comment
comment|/* PCI interrupt #A,#B,#C,#D */
end_comment

begin_define
define|#
directive|define
name|INTMAP_OBIO_MASK
value|0x000000020ULL
end_define

begin_comment
comment|/* Onboard device */
end_comment

begin_define
define|#
directive|define
name|INTIGN
parameter_list|(
name|x
parameter_list|)
value|(((x)& INTMAP_IGN_MASK)>> INTMAP_IGN_SHIFT)
end_define

begin_define
define|#
directive|define
name|INTVEC
parameter_list|(
name|x
parameter_list|)
value|((x)& INTMAP_INR_MASK)
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
value|((x)& INTMAP_INO_MASK)
end_define

begin_define
define|#
directive|define
name|INTMAP_ENABLE
parameter_list|(
name|mr
parameter_list|,
name|mid
parameter_list|)
define|\
value|(INTMAP_TID((mr), (mid)) | INTMAP_V)
end_define

begin_define
define|#
directive|define
name|INTMAP_TID
parameter_list|(
name|mr
parameter_list|,
name|mid
parameter_list|)
define|\
value|(((mr)& ~INTMAP_TID_MASK) | ((mid)<< INTMAP_TID_SHIFT))
end_define

begin_define
define|#
directive|define
name|INTMAP_VEC
parameter_list|(
name|ign
parameter_list|,
name|inr
parameter_list|)
define|\
value|((((ign)<< INTMAP_IGN_SHIFT)& INTMAP_IGN_MASK) |		\ 	((inr)& INTMAP_INR_MASK))
end_define

begin_comment
comment|/* counter-timer support. */
end_comment

begin_function_decl
name|void
name|sparc64_counter_init
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
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

