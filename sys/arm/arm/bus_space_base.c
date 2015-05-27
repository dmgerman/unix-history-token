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

begin_include
include|#
directive|include
file|"opt_platform.h"
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

begin_comment
comment|/*  * The bus space tag.  This is constant for all instances, so  * we never have to explicitly "create" it.  */
end_comment

begin_function_decl
specifier|static
name|struct
name|bus_space
name|arm_base_bus_space
name|__aligned
parameter_list|(
name|CACHE_LINE_SIZE
parameter_list|)
init|=
block|{
comment|/* privdata is whatever the implementer wants; unused in base tag */
operator|.
name|bs_privdata
operator|=
name|NULL
operator|,
comment|/* mapping/unmapping */
function_decl|.bs_map
init|=
name|generic_bs_map
operator|,
function_decl|.bs_unmap
init|=
name|generic_bs_unmap
operator|,
function_decl|.bs_subregion
init|=
name|generic_bs_subregion
operator|,
comment|/* allocation/deallocation */
function_decl|.bs_alloc
init|=
name|generic_bs_alloc
operator|,
function_decl|.bs_free
init|=
name|generic_bs_free
operator|,
comment|/* barrier */
function_decl|.bs_barrier
init|=
name|generic_bs_barrier
operator|,
comment|/* read (single) */
function_decl|.bs_r_1
init|=
name|NULL
operator|,
comment|/* Use inline code in bus.h */
function_decl|.bs_r_2
init|=
name|NULL
operator|,
comment|/* Use inline code in bus.h */
function_decl|.bs_r_4
init|=
name|NULL
operator|,
comment|/* Use inline code in bus.h */
function_decl|.bs_r_8
init|=
name|NULL
operator|,
comment|/* Use inline code in bus.h */
comment|/* read multiple */
function_decl|.bs_rm_1
init|=
name|generic_bs_rm_1
operator|,
function_decl|.bs_rm_2
init|=
name|generic_bs_rm_2
operator|,
function_decl|.bs_rm_4
init|=
name|generic_bs_rm_4
operator|,
function_decl|.bs_rm_8
init|=
name|BS_UNIMPLEMENTED
operator|,
comment|/* read region */
function_decl|.bs_rr_1
init|=
name|generic_bs_rr_1
operator|,
function_decl|.bs_rr_2
init|=
name|generic_bs_rr_2
operator|,
function_decl|.bs_rr_4
init|=
name|generic_bs_rr_4
operator|,
function_decl|.bs_rr_8
init|=
name|BS_UNIMPLEMENTED
operator|,
comment|/* write (single) */
function_decl|.bs_w_1
init|=
name|NULL
operator|,
comment|/* Use inline code in bus.h */
function_decl|.bs_w_2
init|=
name|NULL
operator|,
comment|/* Use inline code in bus.h */
function_decl|.bs_w_4
init|=
name|NULL
operator|,
comment|/* Use inline code in bus.h */
function_decl|.bs_w_8
init|=
name|NULL
operator|,
comment|/* Use inline code in bus.h */
comment|/* write multiple */
function_decl|.bs_wm_1
init|=
name|generic_bs_wm_1
operator|,
function_decl|.bs_wm_2
init|=
name|generic_bs_wm_2
operator|,
function_decl|.bs_wm_4
init|=
name|generic_bs_wm_4
operator|,
function_decl|.bs_wm_8
init|=
name|BS_UNIMPLEMENTED
operator|,
comment|/* write region */
function_decl|.bs_wr_1
init|=
name|generic_bs_wr_1
operator|,
function_decl|.bs_wr_2
init|=
name|generic_bs_wr_2
operator|,
function_decl|.bs_wr_4
init|=
name|generic_bs_wr_4
operator|,
function_decl|.bs_wr_8
init|=
name|BS_UNIMPLEMENTED
operator|,
comment|/* set multiple */
function_decl|.bs_sm_1
init|=
name|BS_UNIMPLEMENTED
operator|,
function_decl|.bs_sm_2
init|=
name|BS_UNIMPLEMENTED
operator|,
function_decl|.bs_sm_4
init|=
name|BS_UNIMPLEMENTED
operator|,
function_decl|.bs_sm_8
init|=
name|BS_UNIMPLEMENTED
operator|,
comment|/* set region */
function_decl|.bs_sr_1
init|=
name|generic_bs_sr_1
operator|,
function_decl|.bs_sr_2
init|=
name|generic_bs_sr_2
operator|,
function_decl|.bs_sr_4
init|=
name|generic_bs_sr_4
operator|,
function_decl|.bs_sr_8
init|=
name|BS_UNIMPLEMENTED
operator|,
comment|/* copy */
function_decl|.bs_c_1
init|=
name|BS_UNIMPLEMENTED
operator|,
function_decl|.bs_c_2
init|=
name|generic_bs_c_2
operator|,
function_decl|.bs_c_4
init|=
name|BS_UNIMPLEMENTED
operator|,
function_decl|.bs_c_8
init|=
name|BS_UNIMPLEMENTED
operator|,
comment|/* read stream (single) */
function_decl|.bs_r_1_s
init|=
name|NULL
operator|,
comment|/* Use inline code in bus.h */
function_decl|.bs_r_2_s
init|=
name|NULL
operator|,
comment|/* Use inline code in bus.h */
function_decl|.bs_r_4_s
init|=
name|NULL
operator|,
comment|/* Use inline code in bus.h */
function_decl|.bs_r_8_s
init|=
name|NULL
operator|,
comment|/* Use inline code in bus.h */
comment|/* read multiple stream */
function_decl|.bs_rm_1_s
init|=
name|generic_bs_rm_1
operator|,
function_decl|.bs_rm_2_s
init|=
name|generic_bs_rm_2
operator|,
function_decl|.bs_rm_4_s
init|=
name|generic_bs_rm_4
operator|,
function_decl|.bs_rm_8_s
init|=
name|BS_UNIMPLEMENTED
operator|,
comment|/* read region stream */
function_decl|.bs_rr_1_s
init|=
name|generic_bs_rr_1
operator|,
function_decl|.bs_rr_2_s
init|=
name|generic_bs_rr_2
operator|,
function_decl|.bs_rr_4_s
init|=
name|generic_bs_rr_4
operator|,
function_decl|.bs_rr_8_s
init|=
name|BS_UNIMPLEMENTED
operator|,
comment|/* write stream (single) */
function_decl|.bs_w_1_s
init|=
name|NULL
operator|,
comment|/* Use inline code in bus.h */
function_decl|.bs_w_2_s
init|=
name|NULL
operator|,
comment|/* Use inline code in bus.h */
function_decl|.bs_w_4_s
init|=
name|NULL
operator|,
comment|/* Use inline code in bus.h */
function_decl|.bs_w_8_s
init|=
name|NULL
operator|,
comment|/* Use inline code in bus.h */
comment|/* write multiple stream */
function_decl|.bs_wm_1_s
init|=
name|generic_bs_wm_1
operator|,
function_decl|.bs_wm_2_s
init|=
name|generic_bs_wm_2
operator|,
function_decl|.bs_wm_4_s
init|=
name|generic_bs_wm_4
operator|,
function_decl|.bs_wm_8_s
init|=
name|BS_UNIMPLEMENTED
operator|,
comment|/* write region stream */
function_decl|.bs_wr_1_s
init|=
name|generic_bs_wr_1
operator|,
function_decl|.bs_wr_2_s
init|=
name|generic_bs_wr_2
operator|,
function_decl|.bs_wr_4_s
init|=
name|generic_bs_wr_4
operator|,
function_decl|.bs_wr_8_s
init|=
name|BS_UNIMPLEMENTED
operator|,
end_function_decl

begin_ifdef
unit|};
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_decl_stmt
name|bus_space_tag_t
name|fdtbus_bs_tag
init|=
operator|&
name|arm_base_bus_space
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|bus_space_tag_t
name|arm_base_bs_tag
init|=
operator|&
name|arm_base_bus_space
decl_stmt|;
end_decl_stmt

end_unit

