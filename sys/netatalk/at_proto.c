begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990,1991 Regents of The University of Michigan.  * All Rights Reserved.  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright notice appears in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation, and that the name of The University  * of Michigan not be used in advertising or publicity pertaining to  * distribution of the software without specific, written prior  * permission. This software is supplied as is without expressed or  * implied warranties of any kind.  *  *	Research Systems Unix Group  *	The University of Michigan  *	c/o Mike Clark  *	535 W. William Street  *	Ann Arbor, Michigan  *	+1-313-763-0525  *	netatalk@itd.umich.edu  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/domain.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<netatalk/at.h>
end_include

begin_include
include|#
directive|include
file|<netatalk/ddp_var.h>
end_include

begin_include
include|#
directive|include
file|<netatalk/at_extern.h>
end_include

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|atalkdomain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|protosw
name|atalksw
index|[]
init|=
block|{
block|{
comment|/* Identifiers */
name|SOCK_DGRAM
block|,
operator|&
name|atalkdomain
block|,
name|ATPROTO_DDP
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
comment|/* 	 * protocol-protocol interface. 	 * fields are pr_input, pr_output, pr_ctlinput, and pr_ctloutput. 	 * pr_input can be called from the udp protocol stack for iptalk 	 * packets bound for a local socket. 	 * pr_output can be used by higher level appletalk protocols, should 	 * they be included in the kernel. 	 */
literal|0
block|,
name|ddp_output
block|,
literal|0
block|,
literal|0
block|,
comment|/* socket-protocol interface. deprecated */
name|NULL
block|,
comment|/* utility routines. */
name|ddp_init
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|&
name|ddp_usrreqs
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|domain
name|atalkdomain
init|=
block|{
name|AF_APPLETALK
block|,
literal|"appletalk"
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|atalksw
block|,
operator|&
name|atalksw
index|[
sizeof|sizeof
argument_list|(
name|atalksw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|atalksw
index|[
literal|0
index|]
argument_list|)
index|]
block|,
literal|0
block|,
name|rn_inithead
block|,
literal|8
operator|*
operator|(
name|u_long
operator|)
operator|&
operator|(
operator|(
expr|struct
name|sockaddr_at
operator|*
operator|)
literal|0
operator|)
operator|->
name|sat_addr
block|,
expr|sizeof
operator|(
expr|struct
name|sockaddr_at
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DOMAIN_SET
argument_list|(
name|atalk
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

