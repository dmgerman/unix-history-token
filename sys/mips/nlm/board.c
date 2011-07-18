begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<mips/nlm/hal/mips-extns.h>
end_include

begin_include
include|#
directive|include
file|<mips/nlm/hal/mmio.h>
end_include

begin_include
include|#
directive|include
file|<mips/nlm/hal/iomap.h>
end_include

begin_include
include|#
directive|include
file|<mips/nlm/hal/fmn.h>
end_include

begin_include
include|#
directive|include
file|<mips/nlm/hal/pic.h>
end_include

begin_include
include|#
directive|include
file|<mips/nlm/hal/uart.h>
end_include

begin_include
include|#
directive|include
file|<mips/nlm/board.h>
end_include

begin_decl_stmt
name|struct
name|xlp_board_info
name|xlp_board_info
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|nlm_setup_xlp_board
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * All our knowledge of chip and board that cannot be detected by probing  * at run-time goes here  */
end_comment

begin_function
name|int
name|nlm_setup_xlp_board
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|xlp_board_info
modifier|*
name|boardp
decl_stmt|;
name|int
name|node
decl_stmt|;
comment|/* start with a clean slate */
name|boardp
operator|=
operator|&
name|xlp_board_info
expr_stmt|;
name|memset
argument_list|(
name|boardp
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|xlp_board_info
argument_list|)
argument_list|)
expr_stmt|;
name|boardp
operator|->
name|nodemask
operator|=
literal|0x1
expr_stmt|;
comment|/* only node 0 */
for|for
control|(
name|node
operator|=
literal|0
init|;
name|node
operator|<
name|XLP_MAX_NODES
condition|;
name|node
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|boardp
operator|->
name|nodemask
operator|&
operator|(
literal|1
operator|<<
name|node
operator|)
operator|)
operator|==
literal|0
condition|)
continue|continue;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|nlm_board_info_setup
parameter_list|()
block|{
name|nlm_setup_xlp_board
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

