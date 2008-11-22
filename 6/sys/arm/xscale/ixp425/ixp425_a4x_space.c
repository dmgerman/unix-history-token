begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ixp425_a4x_space.c,v 1.2 2005/12/11 12:16:51 christos Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright 2003 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Steve C. Woodford for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed for the NetBSD Project by  *      Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Bus space tag for 8/16-bit devices on 32-bit bus.  * all registers are located at the address of multiple of 4.  *  * Based on pxa2x0_a4x_space.c  */
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
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_comment
comment|/* Prototypes for all the bus_space structure functions */
end_comment

begin_expr_stmt
name|bs_protos
argument_list|(
name|ixp425
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bs_protos
argument_list|(
name|a4x
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|generic_armv4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|bus_space
name|ixp425_a4x_bs_tag
init|=
block|{
comment|/* cookie */
operator|.
name|bs_cookie
operator|=
operator|(
name|void
operator|*
operator|)
literal|0
block|,
comment|/* mapping/unmapping */
operator|.
name|bs_map
operator|=
name|ixp425_bs_map
block|,
operator|.
name|bs_unmap
operator|=
name|ixp425_bs_unmap
block|,
operator|.
name|bs_subregion
operator|=
name|ixp425_bs_subregion
block|,
comment|/* allocation/deallocation */
operator|.
name|bs_alloc
operator|=
name|ixp425_bs_alloc
block|,
comment|/* XXX not implemented */
operator|.
name|bs_free
operator|=
name|ixp425_bs_free
block|,
comment|/* XXX not implemented */
comment|/* barrier */
operator|.
name|bs_barrier
operator|=
name|ixp425_bs_barrier
block|,
comment|/* read (single) */
operator|.
name|bs_r_1
operator|=
name|a4x_bs_r_1
block|,
operator|.
name|bs_r_2
operator|=
name|a4x_bs_r_2
block|,
operator|.
name|bs_r_4
operator|=
name|a4x_bs_r_4
block|,
comment|/* read multiple */
operator|.
name|bs_rm_1
operator|=
name|a4x_bs_rm_1
block|,
operator|.
name|bs_rm_2
operator|=
name|a4x_bs_rm_2
block|,
comment|/* read region */
comment|/* XXX not implemented */
comment|/* write (single) */
operator|.
name|bs_w_1
operator|=
name|a4x_bs_w_1
block|,
operator|.
name|bs_w_2
operator|=
name|a4x_bs_w_2
block|,
operator|.
name|bs_w_4
operator|=
name|a4x_bs_w_4
block|,
comment|/* write multiple */
operator|.
name|bs_wm_1
operator|=
name|a4x_bs_wm_1
block|,
operator|.
name|bs_wm_2
operator|=
name|a4x_bs_wm_2
block|,
comment|/* write region */
comment|/* XXX not implemented */
comment|/* set multiple */
comment|/* XXX not implemented */
comment|/* set region */
comment|/* XXX not implemented */
comment|/* copy */
comment|/* XXX not implemented */
block|}
decl_stmt|;
end_decl_stmt

end_unit

