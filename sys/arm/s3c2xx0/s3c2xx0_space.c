begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: s3c2xx0_space.c,v 1.7 2005/11/24 13:08:32 yamt Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2002 Fujitsu Component Limited  * Copyright (c) 2002 Genetec Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The Fujitsu Component Limited nor the name of  *    Genetec corporation may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY FUJITSU COMPONENT LIMITED AND GENETEC  * CORPORATION ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL FUJITSU COMPONENT LIMITED OR GENETEC  * CORPORATION BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* derived from sa11x0_io.c */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997 Mark Brinicombe.  * Copyright (c) 1997 Causality Limited.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Ichiro FUKUHARA.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Mark Brinicombe.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * bus_space functions for Samsung S3C2800/2400/2410.  */
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
name|s3c2xx0_bs_tag
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
comment|/* not implemented */
name|generic_bs_free
block|,
comment|/* not implemented */
comment|/* barrier */
name|generic_bs_barrier
block|,
comment|/* read (single) */
name|generic_bs_r_1
block|,
name|generic_armv4_bs_r_2
block|,
name|generic_bs_r_4
block|,
name|NULL
block|,
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
name|generic_bs_w_1
block|,
name|generic_armv4_bs_w_2
block|,
name|generic_bs_w_4
block|,
name|NULL
block|,
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
name|NULL
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
block|, }
decl_stmt|;
end_decl_stmt

end_unit

