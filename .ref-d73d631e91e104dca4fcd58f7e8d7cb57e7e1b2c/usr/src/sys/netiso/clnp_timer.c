begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/* $Header: clnp_timer.c,v 4.2 88/06/29 14:59:05 hagens Exp $ */
end_comment

begin_comment
comment|/* $Source: /usr/argo/sys/netiso/RCS/clnp_timer.c,v $ */
end_comment

begin_comment
comment|/*	@(#)clnp_timer.c	7.4 (Berkeley) %G% */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: clnp_timer.c,v 4.2 88/06/29 14:59:05 hagens Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"mbuf.h"
end_include

begin_include
include|#
directive|include
file|"domain.h"
end_include

begin_include
include|#
directive|include
file|"protosw.h"
end_include

begin_include
include|#
directive|include
file|"socket.h"
end_include

begin_include
include|#
directive|include
file|"socketvar.h"
end_include

begin_include
include|#
directive|include
file|"errno.h"
end_include

begin_include
include|#
directive|include
file|"../net/if.h"
end_include

begin_include
include|#
directive|include
file|"../net/route.h"
end_include

begin_include
include|#
directive|include
file|"iso.h"
end_include

begin_include
include|#
directive|include
file|"clnp.h"
end_include

begin_include
include|#
directive|include
file|"clnp_stat.h"
end_include

begin_include
include|#
directive|include
file|"argo_debug.h"
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
comment|/*  * FUNCTION:		clnp_freefrags  *  * PURPOSE:			Free the resources associated with a fragment  *  * RETURNS:			pointer to next fragment in list of fragments  *  * SIDE EFFECTS:	  *  * NOTES:			  *			TODO: send ER back to source  */
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
comment|/*  * FUNCTION:		clnp_slowtimo  *  * PURPOSE:			clnp timer processing; if the ttl expires on a   *					packet on the reassembly queue, discard it.  *  * RETURNS:			none  *  * SIDE EFFECTS:	  *  * NOTES:			  */
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
comment|/*  * FUNCTION:		clnp_drain  *  * PURPOSE:			drain off all datagram fragments  *  * RETURNS:			none  *  * SIDE EFFECTS:	  *  * NOTES:			  *	TODO: should send back ER  */
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

