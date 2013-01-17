begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      $NetBSD: bus.h,v 1.12 1997/10/01 08:25:15 fvdl Exp $    */
end_comment

begin_comment
comment|/*-  * $Id: bus.h,v 1.6 2007/08/09 11:23:32 katta Exp $  *  * Copyright (c) 1996, 1997 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Charles M. Hannum.  All rights reserved.  * Copyright (c) 1996 Christopher G. Demetriou.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	from: src/sys/alpha/include/bus.h,v 1.5 1999/08/28 00:38:40 peter  * $FreeBSD$  */
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
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
file|<vm/vm_kern.h>
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

begin_include
include|#
directive|include
file|<machine/cache.h>
end_include

begin_function_decl
specifier|static
name|int
name|fdt_bs_map
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_addr_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|int
parameter_list|,
name|bus_space_handle_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|struct
name|bus_space
name|fdt_space
init|=
block|{
comment|/* cookie */
operator|(
name|void
operator|*
operator|)
literal|0
block|,
comment|/* mapping/unmapping */
name|fdt_bs_map
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
name|generic_bs_r_1
block|,
name|generic_bs_r_2
block|,
name|generic_bs_r_4
block|,
name|generic_bs_r_8
block|,
comment|/* read multiple */
name|generic_bs_rm_1
block|,
name|generic_bs_rm_2
block|,
name|generic_bs_rm_4
block|,
name|generic_bs_rm_8
block|,
comment|/* read region */
name|generic_bs_rr_1
block|,
name|generic_bs_rr_2
block|,
name|generic_bs_rr_4
block|,
name|generic_bs_rr_8
block|,
comment|/* write (single) */
name|generic_bs_w_1
block|,
name|generic_bs_w_2
block|,
name|generic_bs_w_4
block|,
name|generic_bs_w_8
block|,
comment|/* write multiple */
name|generic_bs_wm_1
block|,
name|generic_bs_wm_2
block|,
name|generic_bs_wm_4
block|,
name|generic_bs_wm_8
block|,
comment|/* write region */
name|generic_bs_wr_1
block|,
name|generic_bs_wr_2
block|,
name|generic_bs_wr_4
block|,
name|generic_bs_wr_8
block|,
comment|/* set multiple */
name|generic_bs_sm_1
block|,
name|generic_bs_sm_2
block|,
name|generic_bs_sm_4
block|,
name|generic_bs_sm_8
block|,
comment|/* set region */
name|generic_bs_sr_1
block|,
name|generic_bs_sr_2
block|,
name|generic_bs_sr_4
block|,
name|generic_bs_sr_8
block|,
comment|/* copy */
name|generic_bs_c_1
block|,
name|generic_bs_c_2
block|,
name|generic_bs_c_4
block|,
name|generic_bs_c_8
block|,
comment|/* read (single) stream */
name|generic_bs_r_1
block|,
name|generic_bs_r_2
block|,
name|generic_bs_r_4
block|,
name|generic_bs_r_8
block|,
comment|/* read multiple stream */
name|generic_bs_rm_1
block|,
name|generic_bs_rm_2
block|,
name|generic_bs_rm_4
block|,
name|generic_bs_rm_8
block|,
comment|/* read region stream */
name|generic_bs_rr_1
block|,
name|generic_bs_rr_2
block|,
name|generic_bs_rr_4
block|,
name|generic_bs_rr_8
block|,
comment|/* write (single) stream */
name|generic_bs_w_1
block|,
name|generic_bs_w_2
block|,
name|generic_bs_w_4
block|,
name|generic_bs_w_8
block|,
comment|/* write multiple stream */
name|generic_bs_wm_1
block|,
name|generic_bs_wm_2
block|,
name|generic_bs_wm_4
block|,
name|generic_bs_wm_8
block|,
comment|/* write region stream */
name|generic_bs_wr_1
block|,
name|generic_bs_wr_2
block|,
name|generic_bs_wr_4
block|,
name|generic_bs_wr_8
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* generic bus_space tag */
end_comment

begin_decl_stmt
name|bus_space_tag_t
name|mips_bus_space_fdt
init|=
operator|&
name|fdt_space
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|fdt_bs_map
parameter_list|(
name|void
modifier|*
name|t
name|__unused
parameter_list|,
name|bus_addr_t
name|addr
parameter_list|,
name|bus_size_t
name|size
name|__unused
parameter_list|,
name|int
name|flags
name|__unused
parameter_list|,
name|bus_space_handle_t
modifier|*
name|bshp
parameter_list|)
block|{
operator|*
name|bshp
operator|=
name|MIPS_PHYS_TO_DIRECT_UNCACHED
argument_list|(
name|addr
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

