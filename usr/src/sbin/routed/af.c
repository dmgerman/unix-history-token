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
literal|"@(#)af.c	4.1 %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/in.h>
end_include

begin_include
include|#
directive|include
file|"router.h"
end_include

begin_include
include|#
directive|include
file|"rip.h"
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
name|null_checkhost
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
name|inet_checkhost
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
value|{ null_hash,		null_netmatch,		null_output, \ 	  null_portmatch,	null_checkhost,		null_canon }
end_define

begin_define
define|#
directive|define
name|INET
define|\
value|{ inet_hash,		inet_netmatch,		inet_output, \ 	  inet_portmatch,	inet_checkhost,		inet_canon }
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
name|sin
operator|->
name|sin_addr
operator|.
name|s_net
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
name|sin1
operator|->
name|sin_addr
operator|.
name|s_net
operator|==
name|sin2
operator|->
name|sin_addr
operator|.
name|s_net
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Verify the message is from the right port.  */
end_comment

begin_macro
name|inet_portmatch
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
name|int
name|port
init|=
name|ntohs
argument_list|(
name|sin
operator|->
name|sin_port
argument_list|)
decl_stmt|;
return|return
operator|(
name|port
operator|==
name|IPPORT_ROUTESERVER
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
argument|sin
argument_list|,
argument|size
argument_list|)
end_macro

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
specifier|extern
name|int
name|s
decl_stmt|;
specifier|extern
name|char
name|packet
index|[
name|MAXPACKETSIZE
index|]
decl_stmt|;
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
name|htons
argument_list|(
name|IPPORT_ROUTESERVER
argument_list|)
expr_stmt|;
if|if
condition|(
name|send
argument_list|(
name|s
argument_list|,
name|sin
argument_list|,
name|packet
argument_list|,
name|size
argument_list|)
operator|<
literal|0
condition|)
name|perror
argument_list|(
literal|"send"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Return 1 if the address is for an Internet host,  * otherwise assume it's a network address (broadcast).  */
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
specifier|extern
name|struct
name|in_addr
name|if_makeaddr
parameter_list|()
function_decl|;
name|struct
name|in_addr
name|netaddr
decl_stmt|;
name|netaddr
operator|=
name|if_makeaddr
argument_list|(
operator|(
name|int
operator|)
name|sin
operator|->
name|sin_addr
operator|.
name|s_net
argument_list|,
name|INADDR_ANY
argument_list|)
expr_stmt|;
return|return
operator|(
name|netaddr
operator|.
name|s_addr
operator|!=
name|sin
operator|->
name|sin_addr
operator|.
name|s_addr
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
argument|a1
argument_list|,
argument|n
argument_list|)
end_macro

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

