begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: $Hdr: if_en.h,v 4.300 91/06/09 06:25:56 root Rel41 $ SONY  *  *	@(#)if_en.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_comment
comment|/*  * Structure of an Ethernet header -- receive format  */
end_comment

begin_struct
struct|struct
name|en_rheader
block|{
name|u_char
name|enr_dhost
index|[
literal|6
index|]
decl_stmt|;
comment|/* Destination Host */
name|u_char
name|enr_shost
index|[
literal|6
index|]
decl_stmt|;
comment|/* Source Host */
name|u_short
name|enr_type
decl_stmt|;
comment|/* Type of packet */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Ethernet software status per interface.  *  * Each interface is referenced by a network interface structure,  * es_if, which the routing code uses to locate the interface.  * This structure contains the output queue for the interface, its address, ...  * We also have, for each interface, a IOP interface structure, which  * contains information about the IOP resources held by the interface:  * map registers, buffered data paths, etc.  Information is cached in this  * structure for use by the if_iop.c routines in running the interface  * efficiently.  */
end_comment

begin_struct
struct|struct
name|en_softc
block|{
name|struct
name|arpcom
name|es_ac
decl_stmt|;
comment|/* Ethernet common part */
name|struct
name|ifnews
name|es_ifnews
decl_stmt|;
comment|/* IOP resources */
name|int
name|es_flags
decl_stmt|;
ifdef|#
directive|ifdef
name|NOTDEF
comment|/* KU:XXX */
name|int
name|es_oactive
decl_stmt|;
comment|/* # of active output buffers */
endif|#
directive|endif
name|int
name|es_interval
decl_stmt|;
comment|/* interval of watchdog */
name|caddr_t
name|es_bpf
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|es_if
value|es_ac.ac_if
end_define

begin_comment
comment|/* network-visible interface */
end_comment

begin_define
define|#
directive|define
name|es_addr
value|es_ac.ac_enaddr
end_define

begin_comment
comment|/* hardware Ethernet address */
end_comment

begin_define
define|#
directive|define
name|ENF_RUNNING
value|0x01
end_define

begin_comment
comment|/* board is running */
end_comment

begin_define
define|#
directive|define
name|ENF_SETADDR
value|0x02
end_define

begin_comment
comment|/* physical address is changed */
end_comment

begin_define
define|#
directive|define
name|ENWATCHINTERVAL
value|60
end_define

begin_comment
comment|/* once every 60 seconds */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

