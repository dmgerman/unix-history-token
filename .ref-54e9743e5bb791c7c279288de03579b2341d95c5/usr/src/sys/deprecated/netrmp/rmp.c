begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: rmp.c 1.3 89/06/07$  *  *	@(#)rmp.c	7.1 (Berkeley) %G%  */
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
file|"../netrmp/rmp.h"
end_include

begin_include
include|#
directive|include
file|"../netrmp/rmp_var.h"
end_include

begin_comment
comment|/* **  rmp_output: route packet to proper network interface. */
end_comment

begin_macro
name|rmp_output
argument_list|(
argument|m
argument_list|,
argument|so
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
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
name|rmp_packet
modifier|*
name|rmp
decl_stmt|;
comment|/* 	 *  Convert the mbuf back to an RMP packet so we can get the 	 *  address of the "ifnet struct" specifying the interface it 	 *  should go out on. 	 */
name|rmp
operator|=
name|mtod
argument_list|(
name|m
argument_list|,
expr|struct
name|rmp_packet
operator|*
argument_list|)
expr_stmt|;
name|ifp
operator|=
name|rmp
operator|->
name|ifp
expr_stmt|;
comment|/* 	 *  Strip off the "ifnet struct ptr" from the packet leaving 	 *  us with a complete IEEE 802.2 packet. 	 */
name|m_adj
argument_list|(
name|m
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ifnet
operator|*
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 *  Send the packet. 	 */
return|return
operator|(
call|(
modifier|*
name|ifp
operator|->
name|if_output
call|)
argument_list|(
name|ifp
argument_list|,
name|m
argument_list|,
operator|&
name|rp
operator|->
name|rcb_faddr
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

