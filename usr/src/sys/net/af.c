begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	af.c	6.1	83/07/29	*/
end_comment

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/mbuf.h"
end_include

begin_include
include|#
directive|include
file|"../h/protosw.h"
end_include

begin_include
include|#
directive|include
file|"../h/socket.h"
end_include

begin_include
include|#
directive|include
file|"../h/socketvar.h"
end_include

begin_include
include|#
directive|include
file|"../net/af.h"
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
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AFNULL
define|\
value|{ null_hash,	null_netmatch }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|inet_hash
argument_list|()
decl_stmt|,
name|inet_netmatch
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AFINET
define|\
value|{ inet_hash,	inet_netmatch }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AFINET
value|AFNULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PUP
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|pup_hash
argument_list|()
decl_stmt|,
name|pup_netmatch
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AFPUP
define|\
value|{ pup_hash,	pup_netmatch }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AFPUP
value|AFNULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|afswitch
name|afswitch
index|[
name|AF_MAX
index|]
init|=
block|{
name|AFNULL
block|,
name|AFNULL
block|,
name|AFINET
block|,
name|AFINET
block|,
name|AFPUP
block|,
name|AFNULL
block|,
name|AFNULL
block|,
name|AFNULL
block|,
name|AFNULL
block|,
name|AFNULL
block|,
name|AFNULL
block|}
decl_stmt|;
end_decl_stmt

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

end_unit

