begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2008 MARVELL INTERNATIONAL LTD.  * All rights reserved.  *  * Developed by Semihalf.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of MARVELL nor the names of contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<machine/bus.h>
end_include

begin_comment
comment|/* Prototypes for all the bus_space structure functions */
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
name|generic_armv4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * The bus space tag.  This is constant for all instances, so  * we never have to explicitly "create" it.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|bus_space
name|_base_tag
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
name|NULL
block|,
comment|/* bs_r_1, Use inline code in bus.h */
name|NULL
block|,
comment|/* bs_r_2, Use inline code in bus.h */
name|NULL
block|,
comment|/* bs_r_4, Use inline code in bus.h */
name|NULL
block|,
comment|/* bs_r_8, Use inline code in bus.h */
comment|/* read multiple */
name|generic_bs_rm_1
block|,
name|generic_armv4_bs_rm_2
block|,
name|generic_bs_rm_4
block|,
name|NULL
block|,
comment|/* read region */
name|generic_bs_rr_1
block|,
name|generic_armv4_bs_rr_2
block|,
name|generic_bs_rr_4
block|,
name|NULL
block|,
comment|/* write (single) */
name|NULL
block|,
comment|/* bs_w_1, Use inline code in bus.h */
name|NULL
block|,
comment|/* bs_w_2, Use inline code in bus.h */
name|NULL
block|,
comment|/* bs_w_4, Use inline code in bus.h */
name|NULL
block|,
comment|/* bs_w_8, Use inline code in bus.h */
comment|/* write multiple */
name|generic_bs_wm_1
block|,
name|generic_armv4_bs_wm_2
block|,
name|generic_bs_wm_4
block|,
name|NULL
block|,
comment|/* write region */
name|generic_bs_wr_1
block|,
name|generic_armv4_bs_wr_2
block|,
name|generic_bs_wr_4
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
name|generic_bs_sr_1
block|,
name|generic_armv4_bs_sr_2
block|,
name|generic_bs_sr_4
block|,
name|NULL
block|,
comment|/* copy */
name|NULL
block|,
name|generic_armv4_bs_c_2
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* read stream (single) */
name|NULL
block|,
comment|/* bs_r_1_s, Use inline code in bus.h */
name|NULL
block|,
comment|/* bs_r_2_s, Use inline code in bus.h */
name|NULL
block|,
comment|/* bs_r_4_s, Use inline code in bus.h */
name|NULL
block|,
comment|/* bs_r_8_s, Use inline code in bus.h */
comment|/* read multiple stream */
name|NULL
block|,
name|generic_armv4_bs_rm_2
block|,
comment|/* bus_space_read_multi_stream_2 */
name|NULL
block|,
name|NULL
block|,
comment|/* read region stream */
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* write stream (single) */
name|NULL
block|,
comment|/* bs_w_1_s, Use inline code in bus.h */
name|NULL
block|,
comment|/* bs_w_2_s, Use inline code in bus.h */
name|NULL
block|,
comment|/* bs_w_4_s, Use inline code in bus.h */
name|NULL
block|,
comment|/* bs_w_8_s, Use inline code in bus.h */
comment|/* write multiple stream */
name|NULL
block|,
name|generic_armv4_bs_wm_2
block|,
comment|/* bus_space_write_multi_stream_2 */
name|NULL
block|,
name|NULL
block|,
comment|/* write region stream */
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_space_tag_t
name|fdtbus_bs_tag
init|=
operator|&
name|_base_tag
decl_stmt|;
end_decl_stmt

end_unit

