begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1994, Massachusetts Institute of Technology.  All Rights Reserved.  *  * You may copy this file verbatim until I find the official   * Institute boilerplate.  *  * $Id: in_rmx.c,v 1.1 1994/11/02 04:42:14 wollman Exp $  */
end_comment

begin_comment
comment|/*  * This code does two things necessary for the enhanced TCP metrics to  * function in a useful manner:  *  1) It marks all non-host routes as `cloning', thus ensuring that  *     every actual reference to such a route actually gets turned  *     into a reference to a host route to the specific destination  *     requested.  *  2) When such routes lose all their references, it arranges for them  *     to be deleted in some random collection of circumstances, so that  *     a large quantity of stale routing data is not kept in kernel memory  *     indefinitely.  See in_rtqtimo() below for the exact mechanism.  *  * At least initially, we think that this should have lower overhead than  * using the existing `expire' mechanism and walking the radix tree  * periodically, deleting things as we go.  That method would be relatively  * easy to implement within the framework used here, and in the future  * we made code both ways, so that folks with large routing tables can use  * the external queue, and the majority with small routing tables can do  * the tree-walk.  */
end_comment

begin_comment
comment|/*  * XXX - look for races  */
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
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
file|<sys/mbuf.h>
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
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_var.h>
end_include

begin_define
define|#
directive|define
name|RTPRF_OURS
value|0x10000
end_define

begin_comment
comment|/* set on routes we manage */
end_comment

begin_comment
comment|/*  * Do what we need to do when inserting a route.  */
end_comment

begin_function
specifier|static
name|struct
name|radix_node
modifier|*
name|in_addroute
parameter_list|(
name|void
modifier|*
name|v_arg
parameter_list|,
name|void
modifier|*
name|n_arg
parameter_list|,
name|struct
name|radix_node_head
modifier|*
name|head
parameter_list|,
name|struct
name|radix_node
modifier|*
name|treenodes
parameter_list|)
block|{
name|struct
name|rtentry
modifier|*
name|rt
init|=
operator|(
expr|struct
name|rtentry
operator|*
operator|)
name|treenodes
decl_stmt|;
name|struct
name|in_rtq
modifier|*
name|inr
decl_stmt|;
comment|/* 	 * For IP, all non-host routes are automatically cloning. 	 */
if|if
condition|(
operator|!
operator|(
name|rt
operator|->
name|rt_flags
operator|&
name|RTF_HOST
operator|)
condition|)
name|rt
operator|->
name|rt_flags
operator||=
name|RTF_CLONING
expr_stmt|;
return|return
name|rn_addroute
argument_list|(
name|v_arg
argument_list|,
name|n_arg
argument_list|,
name|head
argument_list|,
name|treenodes
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * This code is the inverse of in_clsroute: on first reference, if we  * were managing the route, stop doing so and set the expiration timer  * back off again.  */
end_comment

begin_function
specifier|static
name|struct
name|radix_node
modifier|*
name|in_matroute
parameter_list|(
name|void
modifier|*
name|v_arg
parameter_list|,
name|struct
name|radix_node_head
modifier|*
name|head
parameter_list|)
block|{
name|struct
name|radix_node
modifier|*
name|rn
init|=
name|rn_match
argument_list|(
name|v_arg
argument_list|,
name|head
argument_list|)
decl_stmt|;
name|struct
name|rtentry
modifier|*
name|rt
init|=
operator|(
expr|struct
name|rtentry
operator|*
operator|)
name|rn
decl_stmt|;
if|if
condition|(
name|rt
operator|&&
name|rt
operator|->
name|rt_refcnt
operator|==
literal|0
condition|)
block|{
comment|/* this is first reference */
if|if
condition|(
name|rt
operator|->
name|rt_prflags
operator|&
name|RTPRF_OURS
condition|)
block|{
name|rt
operator|->
name|rt_prflags
operator|&=
operator|~
name|RTPRF_OURS
expr_stmt|;
name|rt
operator|->
name|rt_rmx
operator|.
name|rmx_expire
operator|=
literal|0
expr_stmt|;
block|}
block|}
return|return
name|rn
return|;
block|}
end_function

begin_define
define|#
directive|define
name|RTQ_REALLYOLD
value|4*60*60
end_define

begin_comment
comment|/* four hours is ``really old'' */
end_comment

begin_comment
comment|/*  * On last reference drop, add the route to the queue so that it can be  * timed out.  */
end_comment

begin_function
specifier|static
name|void
name|in_clsroute
parameter_list|(
name|struct
name|radix_node
modifier|*
name|rn
parameter_list|,
name|struct
name|radix_node_head
modifier|*
name|head
parameter_list|)
block|{
name|struct
name|rtentry
modifier|*
name|rt
init|=
operator|(
expr|struct
name|rtentry
operator|*
operator|)
name|rn
decl_stmt|;
name|struct
name|in_rtq
modifier|*
name|inr
decl_stmt|;
if|if
condition|(
operator|(
name|rt
operator|->
name|rt_flags
operator|&
operator|(
name|RTF_LLINFO
operator||
name|RTF_HOST
operator|)
operator|)
operator|!=
name|RTF_HOST
condition|)
return|return;
if|if
condition|(
operator|(
name|rt
operator|->
name|rt_prflags
operator|&
operator|(
name|RTPRF_WASCLONED
operator||
name|RTPRF_OURS
operator|)
operator|)
operator|!=
name|RTPRF_WASCLONED
condition|)
return|return;
name|rt
operator|->
name|rt_prflags
operator||=
name|RTPRF_OURS
expr_stmt|;
name|rt
operator|->
name|rt_rmx
operator|.
name|rmx_expire
operator|=
name|time
operator|.
name|tv_sec
operator|+
name|RTQ_REALLYOLD
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Get rid of everything in the queue, we are short on memory.  * Although this looks like an infinite loop, it really isn't;  * rtrequest() eventually calls in_delroute() which ends up deleting  * the node at the head (or so we hope).  This should be called from  * ip_drain().  */
end_comment

begin_function
name|void
name|in_rtqdrain
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* write me! */
empty_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|RTQ_TIMEOUT
value|(60*hz)
end_define

begin_comment
comment|/* run once a minute */
end_comment

begin_comment
comment|/*  * Get rid of old routes.  */
end_comment

begin_function
specifier|static
name|void
name|in_rtqtimo
parameter_list|(
name|void
modifier|*
name|rock
parameter_list|)
block|{
comment|/* write me! */
name|timeout
argument_list|(
name|in_rtqtimo
argument_list|,
name|rock
argument_list|,
name|RTQ_TIMEOUT
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Initialize our routing tree.  */
end_comment

begin_function
name|int
name|in_inithead
parameter_list|(
name|void
modifier|*
modifier|*
name|head
parameter_list|,
name|int
name|off
parameter_list|)
block|{
name|struct
name|radix_node_head
modifier|*
name|rnh
decl_stmt|;
if|if
condition|(
operator|!
name|rn_inithead
argument_list|(
name|head
argument_list|,
name|off
argument_list|)
condition|)
return|return
literal|0
return|;
name|rnh
operator|=
operator|*
name|head
expr_stmt|;
name|rnh
operator|->
name|rnh_addaddr
operator|=
name|in_addroute
expr_stmt|;
name|rnh
operator|->
name|rnh_matchaddr
operator|=
name|in_matroute
expr_stmt|;
name|rnh
operator|->
name|rnh_close
operator|=
name|in_clsroute
expr_stmt|;
name|in_rtqtimo
argument_list|(
name|rnh
argument_list|)
expr_stmt|;
comment|/* kick off timeout first time */
return|return
literal|1
return|;
block|}
end_function

end_unit

