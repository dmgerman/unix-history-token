begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	pup.c	6.2	84/08/29	*/
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
file|"../net/af.h"
end_include

begin_include
include|#
directive|include
file|"../netpup/pup.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PUP
end_ifdef

begin_macro
name|pup_hash
argument_list|(
argument|spup
argument_list|,
argument|hp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr_pup
modifier|*
name|spup
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
name|spup
operator|->
name|spup_net
expr_stmt|;
name|hp
operator|->
name|afh_hosthash
operator|=
name|spup
operator|->
name|spup_host
expr_stmt|;
block|}
end_block

begin_macro
name|pup_netmatch
argument_list|(
argument|spup1
argument_list|,
argument|spup2
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr_pup
modifier|*
name|spup1
decl_stmt|,
modifier|*
name|spup2
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|spup1
operator|->
name|spup_net
operator|==
name|spup2
operator|->
name|spup_net
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

