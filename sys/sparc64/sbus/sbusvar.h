begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Paul Kranenburg.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)sbusvar.h	8.1 (Berkeley) 6/11/93  *	from: NetBSD: sbusvar.h,v 1.7 1999/06/05 05:30:43 mrg Exp  *  * $FreeBSD$  */
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
comment|/*  * Macros for probe order  */
end_comment

begin_define
define|#
directive|define
name|SBUS_ORDER_FIRST
value|10
end_define

begin_define
define|#
directive|define
name|SBUS_ORDER_NORMAL
value|20
end_define

begin_comment
comment|/*  * PROM-reported DMA burst sizes for the SBus  */
end_comment

begin_define
define|#
directive|define
name|SBUS_BURST_1
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SBUS_BURST_2
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SBUS_BURST_4
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SBUS_BURST_8
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SBUS_BURST_16
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SBUS_BURST_32
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SBUS_BURST_64
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SBUS_BURST_MASK
value|((1<< SBUS_BURST_SIZE) - 1)
end_define

begin_define
define|#
directive|define
name|SBUS_BURST_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|SBUS_BURST64_MASK
value|(SBUS_BURST_MASK<< SBUS_BURST64_SHIFT)
end_define

begin_define
define|#
directive|define
name|SBUS_BURST64_SHIFT
value|16
end_define

begin_comment
comment|/* Used if no burst sizes are specified for the bus. */
end_comment

begin_define
define|#
directive|define
name|SBUS_BURST_DEF
define|\
value|(SBUS_BURST_1 | SBUS_BURST_2 | SBUS_BURST_4 | SBUS_BURST_8 | 	\ 	SBUS_BURST_16 | SBUS_BURST_32 | SBUS_BURST_64)
end_define

begin_define
define|#
directive|define
name|SBUS_BURST64_DEF
define|\
value|(SBUS_BURST_8 | SBUS_BURST_16 | SBUS_BURST_32 | SBUS_BURST_64)
end_define

begin_enum
enum|enum
name|sbus_device_ivars
block|{
name|SBUS_IVAR_BURSTSZ
block|,
name|SBUS_IVAR_CLOCKFREQ
block|,
name|SBUS_IVAR_IGN
block|,
name|SBUS_IVAR_SLOT
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
argument|ign
argument_list|,
argument|IGN
argument_list|,
argument|int
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

begin_undef
undef|#
directive|undef
name|SBUS_ACCESSOR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SPARC64_SBUS_SBUSVAR_H_ */
end_comment

end_unit

