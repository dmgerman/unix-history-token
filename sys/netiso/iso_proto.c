begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)iso_proto.c	7.8 (Berkeley) 5/6/91  *	$Id: iso_proto.c,v 1.2 1993/10/16 21:05:25 rgrimes Exp $  */
end_comment

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*  * iso_proto.c : protocol switch tables in the ISO domain  *  * ISO protocol family includes TP, CLTP, CLNP, 8208  * TP and CLNP are implemented here.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISO
end_ifdef

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"socket.h"
end_include

begin_include
include|#
directive|include
file|"protosw.h"
end_include

begin_include
include|#
directive|include
file|"domain.h"
end_include

begin_include
include|#
directive|include
file|"mbuf.h"
end_include

begin_include
include|#
directive|include
file|"iso.h"
end_include

begin_function_decl
name|int
name|clnp_output
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|clnp_init
argument_list|()
decl_stmt|,
name|clnp_slowtimo
argument_list|()
decl_stmt|,
name|clnp_drain
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rclnp_input
argument_list|()
decl_stmt|,
name|rclnp_output
argument_list|()
decl_stmt|,
name|rclnp_ctloutput
argument_list|()
decl_stmt|,
name|raw_usrreq
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|clnp_usrreq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tp_ctloutput
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tpclnp_ctlinput
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tpclnp_input
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tp_usrreq
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|tp_init
argument_list|()
decl_stmt|,
name|tp_slowtimo
argument_list|()
decl_stmt|,
name|tp_drain
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|cons_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tpcons_input
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|esis_input
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|esis_ctlinput
argument_list|()
decl_stmt|,
name|esis_init
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|esis_usrreq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cltp_input
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|cltp_ctlinput
argument_list|()
decl_stmt|,
name|cltp_init
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cltp_usrreq
argument_list|()
decl_stmt|,
name|cltp_output
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|isis_input
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|protosw
name|isosw
index|[]
init|=
block|{
comment|/*  *  We need a datagram entry through which net mgmt programs can get  *	to the iso_control procedure (iso ioctls). Thus, a minimal  *	SOCK_DGRAM interface is provided here.  *  THIS ONE MUST BE FIRST: Kludge city : socket() says if(!proto) call  *  pffindtype, which gets the first entry that matches the type.  *  sigh.  */
block|{
name|SOCK_DGRAM
block|,
operator|&
name|isodomain
block|,
name|ISOPROTO_CLTP
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
literal|0
block|,
name|cltp_output
block|,
literal|0
block|,
literal|0
block|,
name|cltp_usrreq
block|,
name|cltp_init
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/*  *	A datagram interface for clnp cannot co-exist with TP/CLNP  *  because CLNP has no way to discriminate incoming TP packets from  *  packets coming in for any other higher layer protocol.  *  Old way: set it up so that pffindproto(... dgm, clnp) fails.  *  New way: let pffindproto work (for x.25, thank you) but create  *  	a clnp_usrreq() that returns error on PRU_ATTACH.  */
block|{
name|SOCK_DGRAM
block|,
operator|&
name|isodomain
block|,
name|ISOPROTO_CLNP
block|,
literal|0
block|,
literal|0
block|,
name|clnp_output
block|,
literal|0
block|,
literal|0
block|,
name|clnp_usrreq
block|,
name|clnp_init
block|,
literal|0
block|,
name|clnp_slowtimo
block|,
name|clnp_drain
block|, }
block|,
comment|/* raw clnp */
block|{
name|SOCK_RAW
block|,
operator|&
name|isodomain
block|,
name|ISOPROTO_RAW
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|rclnp_input
block|,
name|rclnp_output
block|,
literal|0
block|,
name|rclnp_ctloutput
block|,
name|clnp_usrreq
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* ES-IS protocol */
block|{
name|SOCK_DGRAM
block|,
operator|&
name|isodomain
block|,
name|ISOPROTO_ESIS
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|esis_input
block|,
literal|0
block|,
name|esis_ctlinput
block|,
literal|0
block|,
name|esis_usrreq
block|,
name|esis_init
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* ISOPROTO_INTRAISIS */
block|{
name|SOCK_DGRAM
block|,
operator|&
name|isodomain
block|,
name|ISOPROTO_INTRAISIS
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|isis_input
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|esis_usrreq
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* ISOPROTO_TP */
block|{
name|SOCK_SEQPACKET
block|,
operator|&
name|isodomain
block|,
name|ISOPROTO_TP
block|,
name|PR_CONNREQUIRED
operator||
name|PR_WANTRCVD
block|,
name|tpclnp_input
block|,
literal|0
block|,
name|tpclnp_ctlinput
block|,
name|tp_ctloutput
block|,
name|tp_usrreq
block|,
name|tp_init
block|,
literal|0
block|,
name|tp_slowtimo
block|,
name|tp_drain
block|, }
block|,
ifdef|#
directive|ifdef
name|TPCONS
comment|/* ISOPROTO_TP */
block|{
name|SOCK_SEQPACKET
block|,
operator|&
name|isodomain
block|,
name|ISOPROTO_TP0
block|,
name|PR_CONNREQUIRED
operator||
name|PR_WANTRCVD
block|,
name|tpcons_input
block|,
literal|0
block|,
literal|0
block|,
name|tp_ctloutput
block|,
name|tp_usrreq
block|,
name|cons_init
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
block|,
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|iso_init
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|domain
name|isodomain
init|=
block|{
name|AF_ISO
block|,
comment|/* family */
literal|"iso-domain"
block|,
comment|/* name */
name|iso_init
block|,
comment|/* initialize routine */
literal|0
block|,
comment|/* externalize access rights */
literal|0
block|,
comment|/* dispose of internalized rights */
name|isosw
block|,
comment|/* protosw */
operator|&
name|isosw
index|[
sizeof|sizeof
argument_list|(
name|isosw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|isosw
index|[
literal|0
index|]
argument_list|)
index|]
comment|/* NPROTOSW */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISO */
end_comment

end_unit

