begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)af.c	4.13 (Berkeley) %G%"
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
name|inet_hash
argument_list|()
decl_stmt|,
name|inet_netmatch
argument_list|()
decl_stmt|,
name|inet_output
argument_list|()
decl_stmt|,
name|inet_portmatch
argument_list|()
decl_stmt|,
name|inet_portcheck
argument_list|()
decl_stmt|,
name|inet_checkhost
argument_list|()
decl_stmt|,
name|inet_ishost
argument_list|()
decl_stmt|,
name|inet_canon
argument_list|()
decl_stmt|;
end_decl_stmt

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
name|INET
define|\
value|{ inet_hash,		inet_netmatch,		inet_output, \ 	  inet_portmatch,	inet_portcheck,		inet_checkhost, \ 	  inet_ishost,		inet_canon }
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
name|INET
block|,
name|INET
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
name|NIL
block|,
name|NIL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sockaddr_in
name|inet_default
init|=
block|{
name|AF_INET
block|,
name|INADDR_ANY
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|inet_hash
argument_list|(
name|sin
argument_list|,
name|hp
argument_list|)
specifier|register
expr|struct
name|sockaddr_in
operator|*
name|sin
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
name|inet_netof
argument_list|(
name|sin
operator|->
name|sin_addr
argument_list|)
expr_stmt|;
name|hp
operator|->
name|afh_hosthash
operator|=
name|ntohl
argument_list|(
name|sin
operator|->
name|sin_addr
operator|.
name|s_addr
argument_list|)
expr_stmt|;
name|hp
operator|->
name|afh_hosthash
operator|&=
literal|0x7fffffff
expr_stmt|;
block|}
end_block

begin_macro
name|inet_netmatch
argument_list|(
argument|sin1
argument_list|,
argument|sin2
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr_in
modifier|*
name|sin1
decl_stmt|,
modifier|*
name|sin2
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|inet_netof
argument_list|(
name|sin1
operator|->
name|sin_addr
argument_list|)
operator|==
name|inet_netof
argument_list|(
name|sin2
operator|->
name|sin_addr
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Verify the message is from the right port.  */
end_comment

begin_expr_stmt
name|inet_portmatch
argument_list|(
name|sin
argument_list|)
specifier|register
expr|struct
name|sockaddr_in
operator|*
name|sin
expr_stmt|;
end_expr_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|COMPAT
if|if
condition|(
name|ntohs
argument_list|(
name|sin
operator|->
name|sin_port
argument_list|)
operator|==
name|ntohs
argument_list|(
name|sp
operator|->
name|s_port
argument_list|)
operator|+
literal|1
condition|)
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
return|return
operator|(
name|sin
operator|->
name|sin_port
operator|==
name|sp
operator|->
name|s_port
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Verify the message is from a "trusted" port.  */
end_comment

begin_macro
name|inet_portcheck
argument_list|(
argument|sin
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr_in
modifier|*
name|sin
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|ntohs
argument_list|(
name|sin
operator|->
name|sin_port
argument_list|)
operator|<=
name|IPPORT_RESERVED
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Internet output routine.  */
end_comment

begin_macro
name|inet_output
argument_list|(
argument|s
argument_list|,
argument|flags
argument_list|,
argument|sin
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
name|sockaddr_in
modifier|*
name|sin
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
name|sockaddr_in
name|dst
decl_stmt|;
name|dst
operator|=
operator|*
name|sin
expr_stmt|;
name|sin
operator|=
operator|&
name|dst
expr_stmt|;
if|if
condition|(
name|sin
operator|->
name|sin_port
operator|==
literal|0
condition|)
name|sin
operator|->
name|sin_port
operator|=
name|sp
operator|->
name|s_port
expr_stmt|;
if|if
condition|(
name|sendto
argument_list|(
name|s
argument_list|,
name|packet
argument_list|,
name|size
argument_list|,
name|flags
argument_list|,
name|sin
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|sin
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
comment|/*  * Return 1 if the address is believed  * for an Internet host -- THIS IS A KLUDGE.  */
end_comment

begin_macro
name|inet_checkhost
argument_list|(
argument|sin
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr_in
modifier|*
name|sin
decl_stmt|;
end_decl_stmt

begin_block
block|{
define|#
directive|define
name|IN_BADCLASS
parameter_list|(
name|i
parameter_list|)
value|(((long) (i)& 0xe0000000) == 0xe0000000)
if|if
condition|(
name|IN_BADCLASS
argument_list|(
name|ntohl
argument_list|(
name|sin
operator|->
name|sin_addr
argument_list|)
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|sin
operator|->
name|sin_addr
operator|.
name|s_addr
operator|!=
literal|0
operator|&&
name|inet_netof
argument_list|(
name|sin
operator|->
name|sin_addr
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Return 1 if the address is  * for an Internet host, 0 for a network.  */
end_comment

begin_macro
name|inet_ishost
argument_list|(
argument|sin
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr_in
modifier|*
name|sin
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|inet_lnaof
argument_list|(
name|sin
operator|->
name|sin_addr
argument_list|)
operator|!=
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|inet_canon
argument_list|(
argument|sin
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr_in
modifier|*
name|sin
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|sin
operator|->
name|sin_port
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

