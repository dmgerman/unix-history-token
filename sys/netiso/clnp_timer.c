begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)clnp_timer.c	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
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
comment|/* $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/clnp_timer.c,v $ */
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
specifier|extern
name|struct
name|clnp_fragl
modifier|*
name|clnp_frags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * FUNCTION:		clnp_freefrags  *  * PURPOSE:			Free the resources associated with a fragment  *  * RETURNS:			pointer to next fragment in list of fragments  *  * SIDE EFFECTS:  *  * NOTES:  *			TODO: send ER back to source  */
end_comment

begin_function
name|struct
name|clnp_fragl
modifier|*
name|clnp_freefrags
parameter_list|(
name|cfh
parameter_list|)
specifier|register
name|struct
name|clnp_fragl
modifier|*
name|cfh
decl_stmt|;
comment|/* fragment header to delete */
block|{
name|struct
name|clnp_fragl
modifier|*
name|next
init|=
name|cfh
operator|->
name|cfl_next
decl_stmt|;
name|struct
name|clnp_frag
modifier|*
name|cf
decl_stmt|;
comment|/* free any frags hanging around */
name|cf
operator|=
name|cfh
operator|->
name|cfl_frags
expr_stmt|;
while|while
condition|(
name|cf
operator|!=
name|NULL
condition|)
block|{
name|struct
name|clnp_frag
modifier|*
name|cf_next
init|=
name|cf
operator|->
name|cfr_next
decl_stmt|;
name|INCSTAT
argument_list|(
name|cns_fragdropped
argument_list|)
expr_stmt|;
name|m_freem
argument_list|(
name|cf
operator|->
name|cfr_data
argument_list|)
expr_stmt|;
name|cf
operator|=
name|cf_next
expr_stmt|;
block|}
comment|/* free the copy of the header */
name|INCSTAT
argument_list|(
name|cns_fragdropped
argument_list|)
expr_stmt|;
name|m_freem
argument_list|(
name|cfh
operator|->
name|cfl_orighdr
argument_list|)
expr_stmt|;
if|if
condition|(
name|clnp_frags
operator|==
name|cfh
condition|)
block|{
name|clnp_frags
operator|=
name|cfh
operator|->
name|cfl_next
expr_stmt|;
block|}
else|else
block|{
name|struct
name|clnp_fragl
modifier|*
name|scan
decl_stmt|;
for|for
control|(
name|scan
operator|=
name|clnp_frags
init|;
name|scan
operator|!=
name|NULL
condition|;
name|scan
operator|=
name|scan
operator|->
name|cfl_next
control|)
block|{
if|if
condition|(
name|scan
operator|->
name|cfl_next
operator|==
name|cfh
condition|)
block|{
name|scan
operator|->
name|cfl_next
operator|=
name|cfh
operator|->
name|cfl_next
expr_stmt|;
break|break;
block|}
block|}
block|}
comment|/* free the fragment header */
name|m_freem
argument_list|(
name|dtom
argument_list|(
name|cfh
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|next
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * FUNCTION:		clnp_slowtimo  *  * PURPOSE:			clnp timer processing; if the ttl expires on a  *					packet on the reassembly queue, discard it.  *  * RETURNS:			none  *  * SIDE EFFECTS:  *  * NOTES:  */
end_comment

begin_macro
name|clnp_slowtimo
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|clnp_fragl
modifier|*
name|cfh
init|=
name|clnp_frags
decl_stmt|;
name|int
name|s
init|=
name|splnet
argument_list|()
decl_stmt|;
while|while
condition|(
name|cfh
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
operator|--
name|cfh
operator|->
name|cfl_ttl
operator|==
literal|0
condition|)
block|{
name|cfh
operator|=
name|clnp_freefrags
argument_list|(
name|cfh
argument_list|)
expr_stmt|;
name|INCSTAT
argument_list|(
name|cns_fragtimeout
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|cfh
operator|=
name|cfh
operator|->
name|cfl_next
expr_stmt|;
block|}
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * FUNCTION:		clnp_drain  *  * PURPOSE:			drain off all datagram fragments  *  * RETURNS:			none  *  * SIDE EFFECTS:  *  * NOTES:  *	TODO: should send back ER  */
end_comment

begin_macro
name|clnp_drain
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|clnp_fragl
modifier|*
name|cfh
init|=
name|clnp_frags
decl_stmt|;
while|while
condition|(
name|cfh
operator|!=
name|NULL
condition|)
name|cfh
operator|=
name|clnp_freefrags
argument_list|(
name|cfh
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

