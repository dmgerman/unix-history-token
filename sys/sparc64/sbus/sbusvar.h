begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Paul Kranenburg.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)sbusvar.h	8.1 (Berkeley) 6/11/93  *	from: NetBSD: sbusvar.h,v 1.7 1999/06/05 05:30:43 mrg Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC64_SBUS_SBUSVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPARC64_SBUS_SBUSVAR_H_
end_define

begin_comment
comment|/*  * PROM-reported DMA burst sizes for the SBus  */
end_comment

begin_define
define|#
directive|define
name|SBUS_BURST_1
value|0x1
end_define

begin_define
define|#
directive|define
name|SBUS_BURST_2
value|0x2
end_define

begin_define
define|#
directive|define
name|SBUS_BURST_4
value|0x4
end_define

begin_define
define|#
directive|define
name|SBUS_BURST_8
value|0x8
end_define

begin_define
define|#
directive|define
name|SBUS_BURST_16
value|0x10
end_define

begin_define
define|#
directive|define
name|SBUS_BURST_32
value|0x20
end_define

begin_define
define|#
directive|define
name|SBUS_BURST_64
value|0x40
end_define

begin_comment
comment|/* Used if no burst sizes are specified for the bus. */
end_comment

begin_define
define|#
directive|define
name|SBUS_BURST_DEF
define|\
value|(SBUS_BURST_1 | SBUS_BURST_2 | SBUS_BURST_4 | SBUS_BURST_8 | 	\ 	SBUS_BURST_16)
end_define

begin_enum
enum|enum
name|sbus_device_ivars
block|{
name|SBUS_IVAR_BURSTSZ
block|,
name|SBUS_IVAR_CLOCKFREQ
block|,
name|SBUS_IVAR_COMPAT
block|,
name|SBUS_IVAR_NAME
block|,
name|SBUS_IVAR_NODE
block|,
name|SBUS_IVAR_SLOT
block|,
name|SBUS_IVAR_DEVICE_TYPE
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Simplified accessors for sbus devices  */
end_comment

begin_define
define|#
directive|define
name|SBUS_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(sbus, var, SBUS, ivar, type)
end_define

begin_macro
name|SBUS_ACCESSOR
argument_list|(
argument|burstsz
argument_list|,
argument|BURSTSZ
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|SBUS_ACCESSOR
argument_list|(
argument|clockfreq
argument_list|,
argument|CLOCKFREQ
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|SBUS_ACCESSOR
argument_list|(
argument|compat
argument_list|,
argument|COMPAT
argument_list|,
argument|char *
argument_list|)
end_macro

begin_macro
name|SBUS_ACCESSOR
argument_list|(
argument|name
argument_list|,
argument|NAME
argument_list|,
argument|char *
argument_list|)
end_macro

begin_macro
name|SBUS_ACCESSOR
argument_list|(
argument|node
argument_list|,
argument|NODE
argument_list|,
argument|phandle_t
argument_list|)
end_macro

begin_macro
name|SBUS_ACCESSOR
argument_list|(
argument|slot
argument_list|,
argument|SLOT
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|SBUS_ACCESSOR
argument_list|(
argument|device_type
argument_list|,
argument|DEVICE_TYPE
argument_list|,
argument|char *
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|EBUS_ACCESSOR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SPARC64_SBUS_SBUSVAR_H_ */
end_comment

end_unit

