begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Header$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_comment
comment|/*  * Address family support routines  */
end_comment

begin_decl_stmt
name|int
name|null_hash
argument_list|()
decl_stmt|,
name|null_netmatch
argument_list|()
decl_stmt|,
name|null_output
argument_list|()
decl_stmt|,
name|null_portmatch
argument_list|()
decl_stmt|,
name|null_portcheck
argument_list|()
decl_stmt|,
name|null_checkhost
argument_list|()
decl_stmt|,
name|null_ishost
argument_list|()
decl_stmt|,
name|null_canon
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xnnet_hash
argument_list|()
decl_stmt|,
name|xnnet_netmatch
argument_list|()
decl_stmt|,
name|xnnet_output
argument_list|()
decl_stmt|,
name|xnnet_portmatch
argument_list|()
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|xnnet_checkhost
argument_list|()
operator|,
name|xnnet_ishost
argument_list|()
operator|,
name|xnnet_canon
argument_list|()
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|NIL
define|\
value|{ null_hash,		null_netmatch,		null_output, \ 	  null_portmatch,	null_portcheck,		null_checkhost, \ 	  null_ishost,		null_canon }
end_define

begin_define
define|#
directive|define
name|XNSNET
define|\
value|{ xnnet_hash,		xnnet_netmatch,		xnnet_output, \ 	  xnnet_portmatch,	xnnet_portmatch,	xnnet_checkhost, \ 	  xnnet_ishost,		xnnet_canon }
end_define

begin_decl_stmt
name|struct
name|afswitch
name|afswitch
index|[
name|AF_MAX
index|]
init|=
block|{
name|NIL
block|,
name|NIL
block|,
name|NIL
block|,
name|NIL
block|,
name|NIL
block|,
name|NIL
block|,
name|XNSNET
block|,
name|NIL
block|,
name|NIL
block|,
name|NIL
block|,
name|NIL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sockaddr_xn
name|xnnet_default
init|=
block|{
name|AF_XNS
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|xnnet_hash
argument_list|(
name|sxn
argument_list|,
name|hp
argument_list|)
specifier|register
expr|struct
name|sockaddr_xn
operator|*
name|sxn
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|afhash
modifier|*
name|hp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|hp
operator|->
name|afh_nethash
operator|=
name|xnnet
argument_list|(
name|sxn
operator|->
name|sxn_addr
operator|.
name|xn_net
argument_list|)
expr_stmt|;
name|hp
operator|->
name|afh_hosthash
operator|=
operator|*
operator|(
name|int
operator|*
operator|)
name|sxn
operator|->
name|sxn_addr
operator|.
name|xn_host
expr_stmt|;
block|}
end_block

begin_macro
name|xnnet_netmatch
argument_list|(
argument|sxn1
argument_list|,
argument|sxn2
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr_xn
modifier|*
name|sxn1
decl_stmt|,
modifier|*
name|sxn2
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|xnnet
argument_list|(
name|sxn1
operator|->
name|sxn_addr
operator|.
name|xn_net
argument_list|)
operator|==
name|xnnet
argument_list|(
name|sxn2
operator|->
name|sxn_addr
operator|.
name|xn_net
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Verify the message is from the right port.  */
end_comment

begin_expr_stmt
name|xnnet_portmatch
argument_list|(
name|sxn
argument_list|)
specifier|register
expr|struct
name|sockaddr_xn
operator|*
name|sxn
expr_stmt|;
end_expr_stmt

begin_block
block|{
return|return
operator|(
name|ntohs
argument_list|(
name|sxn
operator|->
name|sxn_addr
operator|.
name|xn_socket
argument_list|)
operator|==
name|IDPPORT_RIF
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * xns output routine.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|int
name|do_output
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|xnnet_output
argument_list|(
argument|s
argument_list|,
argument|flags
argument_list|,
argument|sxn
argument_list|,
argument|size
argument_list|)
end_macro

begin_decl_stmt
name|int
name|s
decl_stmt|,
name|flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sockaddr_xn
modifier|*
name|sxn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|size
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|sockaddr_xn
name|dst
decl_stmt|;
name|dst
operator|=
operator|*
name|sxn
expr_stmt|;
name|sxn
operator|=
operator|&
name|dst
expr_stmt|;
if|if
condition|(
name|sxn
operator|->
name|sxn_addr
operator|.
name|xn_socket
operator|==
literal|0
condition|)
name|sxn
operator|->
name|sxn_addr
operator|.
name|xn_socket
operator|=
name|htons
argument_list|(
name|IDPPORT_RIF
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|do_output
operator|||
name|ntohs
argument_list|(
name|msg
operator|->
name|rip_cmd
argument_list|)
operator|==
name|RIPCMD_REQUEST
condition|)
endif|#
directive|endif
if|if
condition|(
name|sendto
argument_list|(
name|s
argument_list|,
name|msg
argument_list|,
name|size
argument_list|,
name|flags
argument_list|,
name|sxn
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|sxn
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
name|perror
argument_list|(
literal|"sendto"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Return 1 if the address is believed  *  -- THIS IS A KLUDGE.  */
end_comment

begin_macro
name|xnnet_checkhost
argument_list|(
argument|sxn
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr_xn
modifier|*
name|sxn
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Return 1 if the address is  * for a host, 0 for a network.  */
end_comment

begin_macro
name|xnnet_ishost
argument_list|(
argument|sxn
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr_xn
modifier|*
name|sxn
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|6
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|sxn
operator|->
name|sxn_addr
operator|.
name|xn_host
index|[
name|i
index|]
operator|!=
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|xnnet_canon
argument_list|(
argument|sxn
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr_xn
modifier|*
name|sxn
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|sxn
operator|->
name|sxn_addr
operator|.
name|xn_socket
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|null_hash
argument_list|(
argument|addr
argument_list|,
argument|hp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr
modifier|*
name|addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|afhash
modifier|*
name|hp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|hp
operator|->
name|afh_nethash
operator|=
name|hp
operator|->
name|afh_hosthash
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|null_netmatch
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr
modifier|*
name|a1
decl_stmt|,
modifier|*
name|a2
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|null_output
argument_list|(
argument|s
argument_list|,
argument|f
argument_list|,
argument|a1
argument_list|,
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|int
name|s
decl_stmt|,
name|f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sockaddr
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
empty_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|null_portmatch
argument_list|(
argument|a1
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|null_portcheck
argument_list|(
argument|a1
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|null_ishost
argument_list|(
argument|a1
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|null_checkhost
argument_list|(
argument|a1
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|null_canon
argument_list|(
argument|a1
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_block
block|{
empty_stmt|;
block|}
end_block

end_unit

