begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* udp_usrreq.c 4.1 81/11/07 */
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
file|"../inet/inet.h"
end_include

begin_include
include|#
directive|include
file|"../inet/inet_systm.h"
end_include

begin_include
include|#
directive|include
file|"../inet/udp.h"
end_include

begin_macro
name|udp_input
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
block|{  }
end_block

begin_macro
name|udp_advise
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
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|udp_output
argument_list|(
argument|xx
argument_list|,
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
block|{  }
end_block

begin_macro
name|udp_usrreq
argument_list|(
argument|up
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
name|up
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
name|struct
name|in_addr
modifier|*
name|addr
decl_stmt|;
end_decl_stmt

begin_block
block|{
switch|switch
condition|(
name|req
condition|)
block|{
case|case
name|PRU_ATTACH
case|:
case|case
name|PRU_DETACH
case|:
case|case
name|PRU_CONNECT
case|:
case|case
name|PRU_DISCONNECT
case|:
case|case
name|PRU_ISCONN
case|:
case|case
name|PRU_ISDISCONN
case|:
break|break;
case|case
name|PRU_RCVD
case|:
break|break;
case|case
name|PRU_SEND
case|:
name|udp_output
argument_list|(
literal|0
argument_list|,
name|m
argument_list|)
expr_stmt|;
break|break;
case|case
name|PRU_ABORT
case|:
case|case
name|PRU_CLEAR
case|:
break|break;
case|case
name|PRU_CONTROL
case|:
break|break;
default|default:
name|panic
argument_list|(
literal|"udp_usrreq"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

