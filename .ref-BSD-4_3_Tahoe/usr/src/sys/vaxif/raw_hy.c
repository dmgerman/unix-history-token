begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)raw_hy.c	7.1	6/5/86  *  * 4.3 BSD Unix kernel - NSC HYPERchannel support  *  * $Header: raw_hy.c,v 3.1 84/02/15 04:27:44 steveg Exp $  * $Locker:  $  *  * Copyright (c) 1984, Tektronix Inc.  * All Rights Reserved  *  */
end_comment

begin_include
include|#
directive|include
file|"hy.h"
end_include

begin_if
if|#
directive|if
name|NHY
operator|>
literal|0
end_if

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
file|"../net/raw_cb.h"
end_include

begin_include
include|#
directive|include
file|"../netinet/in.h"
end_include

begin_include
include|#
directive|include
file|"../netinet/in_systm.h"
end_include

begin_include
include|#
directive|include
file|"../netinet/in_var.h"
end_include

begin_include
include|#
directive|include
file|"if_hy.h"
end_include

begin_comment
comment|/*  * Raw interface to HYPERchannel.  */
end_comment

begin_comment
comment|/*  * Generate HYPERchannel leader and pass packet to hyoutput.  * The user must create a skeletal leader in order to  * communicate message type, message subtype, etc.  * We don't really check the header supplied by the user.  */
end_comment

begin_expr_stmt
name|rhy_output
argument_list|(
name|m
argument_list|,
name|so
argument_list|)
specifier|register
expr|struct
name|mbuf
operator|*
name|m
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
specifier|register
name|struct
name|sockaddr_in
modifier|*
name|sin
decl_stmt|;
specifier|register
name|struct
name|rawcb
modifier|*
name|rp
init|=
name|sotorawcb
argument_list|(
name|so
argument_list|)
decl_stmt|;
name|struct
name|in_ifaddr
modifier|*
name|ia
decl_stmt|;
comment|/* 	 * Verify user has supplied necessary space 	 * for the header. 	 */
if|if
condition|(
operator|(
name|m
operator|->
name|m_off
operator|>
name|MMAXOFF
operator|||
name|m
operator|->
name|m_len
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|hym_hdr
argument_list|)
operator|)
operator|&&
operator|(
name|m
operator|=
name|m_pullup
argument_list|(
name|m
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|hym_hdr
argument_list|)
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|error
operator|=
name|EMSGSIZE
expr_stmt|;
comment|/* XXX */
goto|goto
name|bad
goto|;
block|}
name|sin
operator|=
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
operator|&
name|rp
operator|->
name|rcb_faddr
expr_stmt|;
comment|/* no routing here */
name|ia
operator|=
name|in_iaonnetof
argument_list|(
name|in_netof
argument_list|(
name|sin
operator|->
name|sin_addr
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ia
condition|)
return|return
operator|(
name|hyoutput
argument_list|(
name|ia
operator|->
name|ia_ifp
argument_list|,
name|m
argument_list|,
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
name|sin
argument_list|)
operator|)
return|;
name|error
operator|=
name|ENETUNREACH
expr_stmt|;
name|bad
label|:
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

