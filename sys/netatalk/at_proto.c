begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1991 Regents of The University of Michigan.  * All Rights Reserved.  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright notice appears in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation, and that the name of The University  * of Michigan not be used in advertising or publicity pertaining to  * distribution of the software without specific, written prior  * permission. This software is supplied as is without expressed or  * implied warranties of any kind.  *  *	Research Systems Unix Group  *	The University of Michigan  *	c/o Mike Clark  *	535 W. William Street  *	Ann Arbor, Michigan  *	+1-313-763-0525  *	netatalk@itd.umich.edu  *  * $FreeBSD$  */
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
specifier|static
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
operator|.
name|pr_type
operator|=
name|SOCK_DGRAM
block|,
operator|.
name|pr_domain
operator|=
operator|&
name|atalkdomain
block|,
operator|.
name|pr_protocol
operator|=
name|ATPROTO_DDP
block|,
operator|.
name|pr_flags
operator|=
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
operator|.
name|pr_output
operator|=
name|ddp_output
block|,
operator|.
name|pr_init
operator|=
name|ddp_init
block|,
operator|.
name|pr_usrreqs
operator|=
operator|&
name|ddp_usrreqs
block|, 	}
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
operator|.
name|dom_family
operator|=
name|AF_APPLETALK
block|,
operator|.
name|dom_name
operator|=
literal|"appletalk"
block|,
operator|.
name|dom_protosw
operator|=
name|atalksw
block|,
operator|.
name|dom_protoswNPROTOSW
operator|=
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
operator|.
name|dom_rtattach
operator|=
name|rn_inithead
block|,
operator|.
name|dom_rtoffset
operator|=
name|offsetof
argument_list|(
expr|struct
name|sockaddr_at
argument_list|,
name|sat_addr
argument_list|)
operator|<<
literal|3
block|,
operator|.
name|dom_maxrtkey
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|sockaddr_at
argument_list|)
block|, }
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

