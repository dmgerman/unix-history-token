begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if.c	4.1	81/11/18	*/
end_comment

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/systm.h"
end_include

begin_include
include|#
directive|include
file|"../net/inet.h"
end_include

begin_include
include|#
directive|include
file|"../net/inet_systm.h"
end_include

begin_include
include|#
directive|include
file|"../net/if.h"
end_include

begin_macro
name|if_ifwithaddr
argument_list|(
argument|in
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|in_addr
name|in
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
if|#
directive|if
literal|0
block|for (ifp = ifnet; ifp; ifp = ifp->if_next) 		if (ifp->if_addr.s_addr == in.s_addr) 			break;
else|#
directive|else
name|ifp
operator|=
name|ifnet
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|ifp
operator|)
return|;
block|}
end_block

begin_macro
name|if_ifonnetof
argument_list|(
argument|in
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|in_addr
name|in
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
if|#
directive|if
literal|0
block|int net;  	net = 0;
comment|/* XXX */
block|for (ifp = ifnet; ifp; ifp = ifp->if_next) 		if (ifp->if_net == net) 			break;
else|#
directive|else
name|ifp
operator|=
name|ifnet
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|ifp
operator|)
return|;
block|}
end_block

begin_decl_stmt
name|struct
name|ifnet
name|ifen
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|1024
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifnet
modifier|*
name|ifnet
init|=
operator|&
name|ifen
decl_stmt|;
end_decl_stmt

end_unit

