begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)uipc_pipe.c	6.3 (Berkeley) %G%  */
end_comment

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
file|"unpcb.h"
end_include

begin_define
define|#
directive|define
name|PIPSIZ
value|4096
end_define

begin_comment
comment|/*  * Sneakily connect a pipe from wso to rso.  * This will get cleaned up when socketpair is added.  */
end_comment

begin_macro
name|piconnect
argument_list|(
argument|wso
argument_list|,
argument|rso
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|socket
modifier|*
name|wso
decl_stmt|,
modifier|*
name|rso
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* when we reserve memory this routine may fail */
name|sotounpcb
argument_list|(
name|wso
argument_list|)
operator|->
name|unp_conn
operator|=
name|sotounpcb
argument_list|(
name|rso
argument_list|)
expr_stmt|;
name|sotounpcb
argument_list|(
name|rso
argument_list|)
operator|->
name|unp_conn
operator|=
name|sotounpcb
argument_list|(
name|wso
argument_list|)
expr_stmt|;
name|wso
operator|->
name|so_snd
operator|.
name|sb_hiwat
operator|=
name|PIPSIZ
expr_stmt|;
name|wso
operator|->
name|so_snd
operator|.
name|sb_mbmax
operator|=
literal|2
operator|*
name|PIPSIZ
expr_stmt|;
name|wso
operator|->
name|so_state
operator||=
name|SS_ISCONNECTED
operator||
name|SS_CANTRCVMORE
expr_stmt|;
name|rso
operator|->
name|so_rcv
operator|.
name|sb_hiwat
operator|=
literal|0
expr_stmt|;
name|rso
operator|->
name|so_rcv
operator|.
name|sb_mbmax
operator|=
literal|0
expr_stmt|;
name|rso
operator|->
name|so_state
operator||=
name|SS_ISCONNECTED
operator||
name|SS_CANTSENDMORE
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

end_unit

