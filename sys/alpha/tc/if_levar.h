begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: if_levar.h,v 1.4 1997/03/15 18:12:07 is Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell and Rick Macklem.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_lereg.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/* Local Area Network Controller for Ethernet (LANCE) registers */
end_comment

begin_struct
struct|struct
name|lereg1
block|{
specifier|volatile
name|u_int16_t
name|ler1_rdp
decl_stmt|;
comment|/* data port */
name|int16_t
name|pad0
decl_stmt|;
ifdef|#
directive|ifdef
name|__alpha__
name|int32_t
name|pad1
decl_stmt|;
endif|#
directive|endif
specifier|volatile
name|u_int16_t
name|ler1_rap
decl_stmt|;
comment|/* register select port */
name|int16_t
name|pad2
decl_stmt|;
ifdef|#
directive|ifdef
name|__alpha__
name|int32_t
name|pad3
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ethernet software status per interface.  *  * Each interface is referenced by a network interface structure,  * ethercom.ec_if, which the routing code uses to locate the interface.  * This structure contains the output queue for the interface, its address, ...  */
end_comment

begin_struct
struct|struct
name|le_softc
block|{
name|struct
name|am7990_softc
name|sc_am7990
decl_stmt|;
comment|/* glue to MI code */
name|struct
name|lereg1
modifier|*
name|sc_r1
decl_stmt|;
comment|/* LANCE registers */
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|dec_le_common_attach
name|__P
argument_list|(
operator|(
expr|struct
name|am7990_softc
operator|*
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

