begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)clnp_er.c	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/clnp_er.c,v $ */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/domain.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<netiso/iso.h>
end_include

begin_include
include|#
directive|include
file|<netiso/iso_var.h>
end_include

begin_include
include|#
directive|include
file|<netiso/iso_pcb.h>
end_include

begin_define
define|#
directive|define
name|CLNP_ER_CODES
end_define

begin_include
include|#
directive|include
file|<netiso/clnp.h>
end_include

begin_include
include|#
directive|include
file|<netiso/clnp_stat.h>
end_include

begin_include
include|#
directive|include
file|<netiso/argo_debug.h>
end_include

begin_decl_stmt
specifier|static
name|struct
name|clnp_fixed
name|er_template
init|=
block|{
name|ISO8473_CLNP
block|,
comment|/* network identifier */
literal|0
block|,
comment|/* length */
name|ISO8473_V1
block|,
comment|/* version */
name|CLNP_TTL
block|,
comment|/* ttl */
name|CLNP_ER
block|,
comment|/* type */
literal|0
block|,
comment|/* segment length */
literal|0
comment|/* checksum */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * FUNCTION:		clnp_er_input  *  * PURPOSE:			Process an ER pdu.  *  * RETURNS:  *  * SIDE EFFECTS:  *  * NOTES:  */
end_comment

begin_macro
name|clnp_er_input
argument_list|(
argument|m
argument_list|,
argument|src
argument_list|,
argument|reason
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to packet itself */
end_comment

begin_decl_stmt
name|struct
name|iso_addr
modifier|*
name|src
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to src of er */
end_comment

begin_decl_stmt
name|u_char
name|reason
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reason code of er */
end_comment

begin_block
block|{
name|int
name|cmd
init|=
operator|-
literal|1
decl_stmt|;
specifier|extern
name|u_char
name|clnp_protox
index|[]
decl_stmt|;
name|IFDEBUG
argument_list|(
argument|D_CTLINPUT
argument_list|)
name|printf
argument_list|(
literal|"clnp_er_input: m x%x, src %s, reason x%x\n"
argument_list|,
name|m
argument_list|,
name|clnp_iso_addrp
argument_list|(
name|src
argument_list|)
argument_list|,
name|reason
argument_list|)
expr_stmt|;
name|ENDDEBUG
name|INCSTAT
parameter_list|(
name|cns_er_inhist
index|[
name|clnp_er_index
argument_list|(
name|reason
argument_list|)
index|]
parameter_list|)
function_decl|;
switch|switch
condition|(
name|reason
condition|)
block|{
case|case
name|GEN_NOREAS
case|:
case|case
name|GEN_PROTOERR
case|:
break|break;
case|case
name|GEN_BADCSUM
case|:
name|cmd
operator|=
name|PRC_PARAMPROB
expr_stmt|;
break|break;
case|case
name|GEN_CONGEST
case|:
name|cmd
operator|=
name|PRC_QUENCH
expr_stmt|;
break|break;
case|case
name|GEN_HDRSYNTAX
case|:
name|cmd
operator|=
name|PRC_PARAMPROB
expr_stmt|;
break|break;
case|case
name|GEN_SEGNEEDED
case|:
name|cmd
operator|=
name|PRC_MSGSIZE
expr_stmt|;
break|break;
case|case
name|GEN_INCOMPLETE
case|:
name|cmd
operator|=
name|PRC_PARAMPROB
expr_stmt|;
break|break;
case|case
name|GEN_DUPOPT
case|:
name|cmd
operator|=
name|PRC_PARAMPROB
expr_stmt|;
break|break;
case|case
name|ADDR_DESTUNREACH
case|:
name|cmd
operator|=
name|PRC_UNREACH_HOST
expr_stmt|;
break|break;
case|case
name|ADDR_DESTUNKNOWN
case|:
name|cmd
operator|=
name|PRC_UNREACH_PROTOCOL
expr_stmt|;
break|break;
case|case
name|SRCRT_UNSPECERR
case|:
case|case
name|SRCRT_SYNTAX
case|:
case|case
name|SRCRT_UNKNOWNADDR
case|:
case|case
name|SRCRT_BADPATH
case|:
name|cmd
operator|=
name|PRC_UNREACH_SRCFAIL
expr_stmt|;
break|break;
case|case
name|TTL_EXPTRANSIT
case|:
name|cmd
operator|=
name|PRC_TIMXCEED_INTRANS
expr_stmt|;
break|break;
case|case
name|TTL_EXPREASS
case|:
name|cmd
operator|=
name|PRC_TIMXCEED_REASS
expr_stmt|;
break|break;
case|case
name|DISC_UNSUPPOPT
case|:
case|case
name|DISC_UNSUPPVERS
case|:
case|case
name|DISC_UNSUPPSECURE
case|:
case|case
name|DISC_UNSUPPSRCRT
case|:
case|case
name|DISC_UNSUPPRECRT
case|:
name|cmd
operator|=
name|PRC_PARAMPROB
expr_stmt|;
break|break;
case|case
name|REASS_INTERFERE
case|:
name|cmd
operator|=
name|PRC_TIMXCEED_REASS
expr_stmt|;
break|break;
block|}
comment|/* 	 *	tpclnp_ctlinput1 is called directly so that we don't 	 *	have to build an iso_sockaddr out of src. 	 */
if|if
condition|(
name|cmd
operator|>=
literal|0
condition|)
name|tpclnp_ctlinput1
argument_list|(
name|cmd
argument_list|,
name|src
argument_list|)
expr_stmt|;
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * FUNCTION:		clnp_discard  *  * PURPOSE:			Discard a clnp datagram  *  * RETURNS:			nothing  *  * SIDE EFFECTS:	Will emit an ER pdu if possible  *  * NOTES:			This code assumes that we have previously tried to pull  *					up the header of the datagram into one mbuf.  */
end_comment

begin_macro
name|clnp_discard
argument_list|(
argument|m
argument_list|,
argument|reason
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* header of packet to discard */
end_comment

begin_decl_stmt
name|char
name|reason
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reason for discard */
end_comment

begin_block
block|{
name|IFDEBUG
argument_list|(
argument|D_DISCARD
argument_list|)
name|printf
argument_list|(
literal|"clnp_discard: m x%x, reason x%x\n"
argument_list|,
name|m
argument_list|,
name|reason
argument_list|)
expr_stmt|;
name|ENDDEBUG
if|if
condition|(
name|m
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|m
operator|->
name|m_len
operator|>=
sizeof|sizeof
argument_list|(
expr|struct
name|clnp_fixed
argument_list|)
condition|)
block|{
specifier|register
name|struct
name|clnp_fixed
modifier|*
name|clnp
init|=
name|mtod
argument_list|(
name|m
argument_list|,
expr|struct
name|clnp_fixed
operator|*
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
operator|(
name|clnp
operator|->
name|cnf_type
operator|&
name|CNF_TYPE
operator|)
operator|!=
name|CLNP_ER
operator|)
operator|&&
operator|(
name|clnp
operator|->
name|cnf_type
operator|&
name|CNF_ERR_OK
operator|)
condition|)
block|{
name|clnp_emit_er
argument_list|(
name|m
argument_list|,
name|reason
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  * FUNCTION:		clnp_emit_er  *  * PURPOSE:			Send an ER pdu.  *					The src of the of the ER pdu is the host that is sending  *					the ER (ie. us), *not* the original destination of the  *					packet.  *  * RETURNS:			nothing  *  * SIDE EFFECTS:  *  * NOTES:			Takes responsibility for freeing mbuf passed  *					This function may be called with a packet that  *					was created by us; in this case, do not send  *					an ER.  */
end_comment

begin_macro
name|clnp_emit_er
argument_list|(
argument|m
argument_list|,
argument|reason
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* header of packet to discard */
end_comment

begin_decl_stmt
name|char
name|reason
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reason for discard */
end_comment

begin_block
block|{
specifier|register
name|struct
name|clnp_fixed
modifier|*
name|clnp
init|=
name|mtod
argument_list|(
name|m
argument_list|,
expr|struct
name|clnp_fixed
operator|*
argument_list|)
decl_stmt|;
specifier|register
name|struct
name|clnp_fixed
modifier|*
name|er
decl_stmt|;
name|struct
name|route_iso
name|route
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|first_hop
decl_stmt|;
name|struct
name|iso_addr
name|src
decl_stmt|,
name|dst
decl_stmt|,
modifier|*
name|our_addr
decl_stmt|;
name|caddr_t
name|hoff
decl_stmt|,
name|hend
decl_stmt|;
name|int
name|total_len
decl_stmt|;
comment|/* total len of dg */
name|struct
name|mbuf
modifier|*
name|m0
decl_stmt|;
comment|/* contains er pdu hdr */
name|struct
name|iso_ifaddr
modifier|*
name|ia
init|=
literal|0
decl_stmt|;
name|IFDEBUG
argument_list|(
argument|D_DISCARD
argument_list|)
name|printf
argument_list|(
literal|"clnp_emit_er: m x%x, hdr len %d\n"
argument_list|,
name|m
argument_list|,
name|clnp
operator|->
name|cnf_hdr_len
argument_list|)
expr_stmt|;
name|ENDDEBUG
name|bzero
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|route
argument_list|,
sizeof|sizeof
argument_list|(
name|route
argument_list|)
argument_list|)
decl_stmt|;
comment|/* 	 *	If header length is incorrect, or entire header is not contained 	 *	in this mbuf, we punt 	 */
if|if
condition|(
operator|(
name|clnp
operator|->
name|cnf_hdr_len
operator|<
name|CLNP_HDR_MIN
operator|)
operator|||
operator|(
name|clnp
operator|->
name|cnf_hdr_len
operator|>
name|CLNP_HDR_MAX
operator|)
operator|||
operator|(
name|clnp
operator|->
name|cnf_hdr_len
operator|>
name|m
operator|->
name|m_len
operator|)
condition|)
goto|goto
name|bad
goto|;
comment|/* extract src, dest address */
name|hend
operator|=
operator|(
name|caddr_t
operator|)
name|clnp
operator|+
name|clnp
operator|->
name|cnf_hdr_len
expr_stmt|;
name|hoff
operator|=
operator|(
name|caddr_t
operator|)
name|clnp
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|clnp_fixed
argument_list|)
expr_stmt|;
name|CLNP_EXTRACT_ADDR
argument_list|(
name|dst
argument_list|,
name|hoff
argument_list|,
name|hend
argument_list|)
expr_stmt|;
if|if
condition|(
name|hoff
operator|==
operator|(
name|caddr_t
operator|)
literal|0
condition|)
block|{
goto|goto
name|bad
goto|;
block|}
name|CLNP_EXTRACT_ADDR
argument_list|(
name|src
argument_list|,
name|hoff
argument_list|,
name|hend
argument_list|)
expr_stmt|;
if|if
condition|(
name|hoff
operator|==
operator|(
name|caddr_t
operator|)
literal|0
condition|)
block|{
goto|goto
name|bad
goto|;
block|}
comment|/* 	 *	Do not send ER if we generated the packet. 	 */
if|if
condition|(
name|clnp_ours
argument_list|(
operator|&
name|src
argument_list|)
condition|)
goto|goto
name|bad
goto|;
comment|/* 	 *	Trim mbuf to hold only the header. 	 *	This mbuf will be the 'data' of the er pdu 	 */
if|if
condition|(
name|m
operator|->
name|m_next
operator|!=
name|NULL
condition|)
block|{
name|m_freem
argument_list|(
name|m
operator|->
name|m_next
argument_list|)
expr_stmt|;
name|m
operator|->
name|m_next
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|m
operator|->
name|m_len
operator|>
name|clnp
operator|->
name|cnf_hdr_len
condition|)
name|m_adj
argument_list|(
name|m
argument_list|,
operator|(
name|int
operator|)
operator|-
operator|(
name|m
operator|->
name|m_len
operator|-
operator|(
name|int
operator|)
name|clnp
operator|->
name|cnf_hdr_len
operator|)
argument_list|)
expr_stmt|;
comment|/* route er pdu: note we send pkt to src of original packet  */
if|if
condition|(
name|clnp_route
argument_list|(
operator|&
name|src
argument_list|,
operator|&
name|route
argument_list|,
comment|/* flags */
literal|0
argument_list|,
operator|&
name|first_hop
argument_list|,
operator|&
name|ia
argument_list|)
operator|!=
literal|0
condition|)
goto|goto
name|bad
goto|;
comment|/* compute our address based upon firsthop/ifp */
if|if
condition|(
name|ia
condition|)
name|our_addr
operator|=
operator|&
name|ia
operator|->
name|ia_addr
operator|.
name|siso_addr
expr_stmt|;
else|else
goto|goto
name|bad
goto|;
name|ifp
operator|=
name|ia
operator|->
name|ia_ifp
expr_stmt|;
name|IFDEBUG
argument_list|(
argument|D_DISCARD
argument_list|)
name|printf
argument_list|(
literal|"clnp_emit_er: to %s"
argument_list|,
name|clnp_iso_addrp
argument_list|(
operator|&
name|src
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" from %s\n"
argument_list|,
name|clnp_iso_addrp
argument_list|(
name|our_addr
argument_list|)
argument_list|)
expr_stmt|;
name|ENDDEBUG
name|IFDEBUG
parameter_list|(
name|D_DISCARD
parameter_list|)
function_decl|printf
parameter_list|(
function_decl|"clnp_emit_er: packet routed to %s\n"
operator|,
function_decl|clnp_iso_addrp
parameter_list|(
function_decl|&
parameter_list|(
function_decl|(struct sockaddr_iso *
block|)
end_block

begin_expr_stmt
name|first_hop
end_expr_stmt

begin_expr_stmt
unit|)
operator|->
name|siso_addr
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|ENDDEBUG
comment|/* allocate mbuf for er pdu header: punt on no space */
name|MGET
parameter_list|(
name|m0
parameter_list|,
name|M_DONTWAIT
parameter_list|,
name|MT_HEADER
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|if
condition|(
name|m0
operator|==
literal|0
condition|)
goto|goto
name|bad
goto|;
end_if

begin_expr_stmt
name|m0
operator|->
name|m_next
operator|=
name|m
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|er
operator|=
name|mtod
argument_list|(
name|m0
argument_list|,
expr|struct
name|clnp_fixed
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|er
operator|=
name|er_template
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* setup src/dst on er pdu */
end_comment

begin_comment
comment|/* NOTE REVERSAL OF SRC/DST */
end_comment

begin_expr_stmt
name|hoff
operator|=
operator|(
name|caddr_t
operator|)
name|er
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|clnp_fixed
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CLNP_INSERT_ADDR
argument_list|(
name|hoff
argument_list|,
name|src
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CLNP_INSERT_ADDR
argument_list|(
name|hoff
argument_list|,
operator|*
name|our_addr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 *	TODO: if complete src rt was specified, then reverse path, and 	 *	copy into er as option. 	 */
end_comment

begin_comment
comment|/* add er option */
end_comment

begin_expr_stmt
operator|*
name|hoff
operator|++
operator|=
name|CLNPOVAL_ERREAS
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* code */
end_comment

begin_expr_stmt
operator|*
name|hoff
operator|++
operator|=
literal|2
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* length */
end_comment

begin_expr_stmt
operator|*
name|hoff
operator|++
operator|=
name|reason
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* discard reason */
end_comment

begin_expr_stmt
operator|*
name|hoff
operator|++
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* error localization = not specified */
end_comment

begin_comment
comment|/* set length */
end_comment

begin_expr_stmt
name|er
operator|->
name|cnf_hdr_len
operator|=
name|m0
operator|->
name|m_len
operator|=
call|(
name|u_char
call|)
argument_list|(
name|hoff
operator|-
operator|(
name|caddr_t
operator|)
name|er
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|total_len
operator|=
name|m0
operator|->
name|m_len
operator|+
name|m
operator|->
name|m_len
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|HTOC
argument_list|(
name|er
operator|->
name|cnf_seglen_msb
argument_list|,
name|er
operator|->
name|cnf_seglen_lsb
argument_list|,
name|total_len
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* compute checksum (on header only) */
end_comment

begin_expr_stmt
name|iso_gen_csum
argument_list|(
name|m0
argument_list|,
name|CLNP_CKSUM_OFF
argument_list|,
operator|(
name|int
operator|)
name|er
operator|->
name|cnf_hdr_len
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* trim packet if too large for interface */
end_comment

begin_if
if|if
condition|(
name|total_len
operator|>
name|ifp
operator|->
name|if_mtu
condition|)
name|m_adj
argument_list|(
name|m0
argument_list|,
operator|-
operator|(
name|total_len
operator|-
name|ifp
operator|->
name|if_mtu
operator|)
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* send packet */
end_comment

begin_expr_stmt
name|INCSTAT
argument_list|(
name|cns_er_outhist
index|[
name|clnp_er_index
argument_list|(
name|reason
argument_list|)
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
call|(
name|void
call|)
argument_list|(
operator|*
name|ifp
operator|->
name|if_output
argument_list|)
argument_list|(
name|ifp
argument_list|,
name|m0
argument_list|,
name|first_hop
argument_list|,
name|route
operator|.
name|ro_rt
argument_list|)
expr_stmt|;
end_expr_stmt

begin_goto
goto|goto
name|done
goto|;
end_goto

begin_label
name|bad
label|:
end_label

begin_expr_stmt
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|done
label|:
end_label

begin_comment
comment|/* free route if it is a temp */
end_comment

begin_if
if|if
condition|(
name|route
operator|.
name|ro_rt
operator|!=
name|NULL
condition|)
name|RTFREE
argument_list|(
name|route
operator|.
name|ro_rt
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
unit|}  clnp_er_index
operator|(
name|p
operator|)
name|u_char
name|p
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|u_char
modifier|*
name|cp
init|=
name|clnp_er_codes
operator|+
name|CLNP_ERRORS
decl_stmt|;
while|while
condition|(
name|cp
operator|>
name|clnp_er_codes
condition|)
block|{
name|cp
operator|--
expr_stmt|;
if|if
condition|(
operator|*
name|cp
operator|==
name|p
condition|)
return|return
operator|(
name|cp
operator|-
name|clnp_er_codes
operator|)
return|;
block|}
return|return
operator|(
name|CLNP_ERRORS
operator|+
literal|1
operator|)
return|;
block|}
end_block

end_unit

