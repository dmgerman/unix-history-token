begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: XRemoveNode.c,v 10.2 86/02/01 15:39:31 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_include
include|#
directive|include
file|"XlibInternal.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DNETCONN
end_ifdef

begin_include
include|#
directive|include
file|<netdnet/dn.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|XRemoveNode
argument_list|(
argument|node
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|dn_naddr
modifier|*
name|node
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|DNETCONN
specifier|register
name|Display
modifier|*
name|dpy
decl_stmt|;
specifier|register
name|XReq
modifier|*
name|req
decl_stmt|;
name|GetReq
argument_list|(
name|X_RemoveHost
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|req
operator|->
name|func
operator|=
name|XAF_DECnet
expr_stmt|;
name|bcopy
argument_list|(
name|node
argument_list|,
operator|&
operator|(
name|req
operator|->
name|param
operator|.
name|l
index|[
literal|0
index|]
operator|)
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|dn_naddr
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

end_unit

