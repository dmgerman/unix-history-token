begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: sa11x0_io.c,v 1.12 2003/07/15 00:24:51 lukem Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997 Mark Brinicombe.  * Copyright (c) 1997 Causality Limited.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Ichiro FUKUHARA.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Mark Brinicombe.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * bus_space I/O functions for sa11x0  */
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
file|<sys/queue.h>
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
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_comment
comment|/* Proto types for all the bus_space structure functions */
end_comment

begin_expr_stmt
name|bs_protos
argument_list|(
name|generic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bs_protos
argument_list|(
name|sa11x0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Declare the sa11x0 bus space tag */
end_comment

begin_decl_stmt
name|struct
name|bus_space
name|sa11x0_bs_tag
init|=
block|{
comment|/* cookie */
name|NULL
block|,
comment|/* mapping/unmapping */
name|generic_bs_map
block|,
name|generic_bs_unmap
block|,
name|generic_bs_subregion
block|,
comment|/* allocation/deallocation */
name|generic_bs_alloc
block|,
name|generic_bs_free
block|,
comment|/* barrier */
name|generic_bs_barrier
block|,
comment|/* read (single) */
name|sa11x0_bs_r_1
block|,
name|sa11x0_bs_r_2
block|,
name|sa11x0_bs_r_4
block|,
name|NULL
block|,
comment|/* read multiple */
name|sa11x0_bs_rm_1
block|,
name|sa11x0_bs_rm_2
block|,
name|sa11x0_bs_rm_4
block|,
name|NULL
block|,
comment|/* read region */
name|NULL
block|,
name|sa11x0_bs_rr_2
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* write (single) */
name|sa11x0_bs_w_1
block|,
name|sa11x0_bs_w_2
block|,
name|sa11x0_bs_w_4
block|,
name|NULL
block|,
comment|/* write multiple */
name|sa11x0_bs_wm_1
block|,
name|sa11x0_bs_wm_2
block|,
name|sa11x0_bs_wm_4
block|,
name|NULL
block|,
comment|/* write region */
name|NULL
block|,
name|sa11x0_bs_wr_2
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* set multiple */
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* set region */
name|NULL
block|,
name|sa11x0_bs_sr_2
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* copy */
name|NULL
block|,
name|sa11x0_bs_c_2
block|,
name|NULL
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* End of sa11x0_io.c */
end_comment

end_unit

