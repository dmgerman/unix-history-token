begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	raw_ip.c	4.1	81/11/29	*/
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
file|"../net/in.h"
end_include

begin_include
include|#
directive|include
file|"../net/in_systm.h"
end_include

begin_comment
comment|/*  * Raw protocol interface.  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|rip_input
argument_list|(
argument|m
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|COUNT
argument_list|(
name|RIP_INPUT
argument_list|)
expr_stmt|;
comment|/* call raw_input with prepared parameters */
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|rip_ctlinput
argument_list|(
argument|m
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|COUNT
argument_list|(
name|RIP_CTLINPUT
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|rip_output
argument_list|(
argument|m
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|COUNT
argument_list|(
name|RIP_OUTPUT
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|rip_usrreq
argument_list|(
argument|so
argument_list|,
argument|req
argument_list|,
argument|m
argument_list|,
argument|addr
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|req
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|addr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|COUNT
argument_list|(
name|RAW_USRREQ
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|rip_slowtimo
argument_list|()
end_macro

begin_block
block|{
name|COUNT
argument_list|(
name|RIP_SLOWTIMO
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

