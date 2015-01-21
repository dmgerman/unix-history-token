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

begin_function
specifier|static
name|void
name|bs_unimplemented
parameter_list|(
name|void
parameter_list|)
block|{
name|panic
argument_list|(
literal|"unimplemented bus_space function called"
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|BS_UNIMPLEMENTED
value|(void *)bs_unimplemented
end_define

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
comment|/* privdata is whatever the implementer wants; unused in base tag */
operator|.
name|bs_privdata
operator|=
name|NULL
block|,
comment|/* mapping/unmapping */
operator|.
name|bs_map
operator|=
name|generic_bs_map
block|,
operator|.
name|bs_unmap
operator|=
name|generic_bs_unmap
block|,
operator|.
name|bs_subregion
operator|=
name|generic_bs_subregion
block|,
comment|/* allocation/deallocation */
operator|.
name|bs_alloc
operator|=
name|generic_bs_alloc
block|,
operator|.
name|bs_free
operator|=
name|generic_bs_free
block|,
comment|/* barrier */
operator|.
name|bs_barrier
operator|=
name|generic_bs_barrier
block|,
comment|/* read (single) */
operator|.
name|bs_r_1
operator|=
name|NULL
block|,
comment|/* Use inline code in bus.h */
operator|.
name|bs_r_2
operator|=
name|NULL
block|,
comment|/* Use inline code in bus.h */
operator|.
name|bs_r_4
operator|=
name|NULL
block|,
comment|/* Use inline code in bus.h */
operator|.
name|bs_r_8
operator|=
name|NULL
block|,
comment|/* Use inline code in bus.h */
comment|/* read multiple */
operator|.
name|bs_rm_1
operator|=
name|generic_bs_rm_1
block|,
operator|.
name|bs_rm_2
operator|=
name|generic_armv4_bs_rm_2
block|,
operator|.
name|bs_rm_4
operator|=
name|generic_bs_rm_4
block|,
operator|.
name|bs_rm_8
operator|=
name|BS_UNIMPLEMENTED
block|,
comment|/* read region */
operator|.
name|bs_rr_1
operator|=
name|generic_bs_rr_1
block|,
operator|.
name|bs_rr_2
operator|=
name|generic_armv4_bs_rr_2
block|,
operator|.
name|bs_rr_4
operator|=
name|generic_bs_rr_4
block|,
operator|.
name|bs_rr_8
operator|=
name|BS_UNIMPLEMENTED
block|,
comment|/* write (single) */
operator|.
name|bs_w_1
operator|=
name|NULL
block|,
comment|/* Use inline code in bus.h */
operator|.
name|bs_w_2
operator|=
name|NULL
block|,
comment|/* Use inline code in bus.h */
operator|.
name|bs_w_4
operator|=
name|NULL
block|,
comment|/* Use inline code in bus.h */
operator|.
name|bs_w_8
operator|=
name|NULL
block|,
comment|/* Use inline code in bus.h */
comment|/* write multiple */
operator|.
name|bs_wm_1
operator|=
name|generic_bs_wm_1
block|,
operator|.
name|bs_wm_2
operator|=
name|generic_armv4_bs_wm_2
block|,
operator|.
name|bs_wm_4
operator|=
name|generic_bs_wm_4
block|,
operator|.
name|bs_wm_8
operator|=
name|BS_UNIMPLEMENTED
block|,
comment|/* write region */
operator|.
name|bs_wr_1
operator|=
name|generic_bs_wr_1
block|,
operator|.
name|bs_wr_2
operator|=
name|generic_armv4_bs_wr_2
block|,
operator|.
name|bs_wr_4
operator|=
name|generic_bs_wr_4
block|,
operator|.
name|bs_wr_8
operator|=
name|BS_UNIMPLEMENTED
block|,
comment|/* set multiple */
operator|.
name|bs_sm_1
operator|=
name|BS_UNIMPLEMENTED
block|,
operator|.
name|bs_sm_2
operator|=
name|BS_UNIMPLEMENTED
block|,
operator|.
name|bs_sm_4
operator|=
name|BS_UNIMPLEMENTED
block|,
operator|.
name|bs_sm_8
operator|=
name|BS_UNIMPLEMENTED
block|,
comment|/* set region */
operator|.
name|bs_sr_1
operator|=
name|generic_bs_sr_1
block|,
operator|.
name|bs_sr_2
operator|=
name|generic_armv4_bs_sr_2
block|,
operator|.
name|bs_sr_4
operator|=
name|generic_bs_sr_4
block|,
operator|.
name|bs_sr_8
operator|=
name|BS_UNIMPLEMENTED
block|,
comment|/* copy */
operator|.
name|bs_c_1
operator|=
name|BS_UNIMPLEMENTED
block|,
operator|.
name|bs_c_2
operator|=
name|generic_armv4_bs_c_2
block|,
operator|.
name|bs_c_4
operator|=
name|BS_UNIMPLEMENTED
block|,
operator|.
name|bs_c_8
operator|=
name|BS_UNIMPLEMENTED
block|,
comment|/* read stream (single) */
operator|.
name|bs_r_1_s
operator|=
name|NULL
block|,
comment|/* Use inline code in bus.h */
operator|.
name|bs_r_2_s
operator|=
name|NULL
block|,
comment|/* Use inline code in bus.h */
operator|.
name|bs_r_4_s
operator|=
name|NULL
block|,
comment|/* Use inline code in bus.h */
operator|.
name|bs_r_8_s
operator|=
name|NULL
block|,
comment|/* Use inline code in bus.h */
comment|/* read multiple stream */
operator|.
name|bs_rm_1_s
operator|=
name|generic_bs_rm_1
block|,
operator|.
name|bs_rm_2_s
operator|=
name|generic_armv4_bs_rm_2
block|,
operator|.
name|bs_rm_4_s
operator|=
name|generic_bs_rm_4
block|,
operator|.
name|bs_rm_8_s
operator|=
name|BS_UNIMPLEMENTED
block|,
comment|/* read region stream */
operator|.
name|bs_rr_1_s
operator|=
name|generic_bs_rr_1
block|,
operator|.
name|bs_rr_2_s
operator|=
name|generic_bs_rr_2
block|,
operator|.
name|bs_rr_4_s
operator|=
name|generic_bs_rr_4
block|,
operator|.
name|bs_rr_8_s
operator|=
name|BS_UNIMPLEMENTED
block|,
comment|/* write stream (single) */
operator|.
name|bs_w_1_s
operator|=
name|NULL
block|,
comment|/* Use inline code in bus.h */
operator|.
name|bs_w_2_s
operator|=
name|NULL
block|,
comment|/* Use inline code in bus.h */
operator|.
name|bs_w_4_s
operator|=
name|NULL
block|,
comment|/* Use inline code in bus.h */
operator|.
name|bs_w_8_s
operator|=
name|NULL
block|,
comment|/* Use inline code in bus.h */
comment|/* write multiple stream */
operator|.
name|bs_wm_1_s
operator|=
name|generic_bs_wm_1
block|,
operator|.
name|bs_wm_2_s
operator|=
name|generic_armv4_bs_wm_2
block|,
operator|.
name|bs_wm_4_s
operator|=
name|generic_bs_wm_4
block|,
operator|.
name|bs_wm_8_s
operator|=
name|BS_UNIMPLEMENTED
block|,
comment|/* write region stream */
operator|.
name|bs_wr_1_s
operator|=
name|generic_bs_wr_1
block|,
operator|.
name|bs_wr_2_s
operator|=
name|generic_bs_wr_4
block|,
operator|.
name|bs_wr_4_s
operator|=
name|generic_bs_wr_8
block|,
operator|.
name|bs_wr_8_s
operator|=
name|BS_UNIMPLEMENTED
block|, }
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

