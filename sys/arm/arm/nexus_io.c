begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: mainbus_io.c,v 1.13 2003/07/15 00:24:47 lukem Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997 Mark Brinicombe.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Mark Brinicombe.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * bus_space I/O functions for mainbus  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
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
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/pmap.h>
end_include

begin_comment
comment|/* Proto types for all the bus_space structure functions */
end_comment

begin_decl_stmt
name|vm_offset_t
name|lala
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bs_protos
argument_list|(
name|nexus
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Declare the mainbus bus space tag */
end_comment

begin_decl_stmt
name|struct
name|bus_space
name|mainbus_bs_tag
init|=
block|{
comment|/* cookie */
name|NULL
block|,
comment|/* mapping/unmapping */
name|nexus_bs_map
block|,
name|nexus_bs_unmap
block|,
name|nexus_bs_subregion
block|,
comment|/* allocation/deallocation */
name|nexus_bs_alloc
block|,
name|nexus_bs_free
block|,
comment|/* barrier */
name|nexus_bs_barrier
block|,
comment|/* read (single) */
name|nexus_bs_r_1
block|,
name|nexus_bs_r_2
block|,
name|nexus_bs_r_4
block|,
name|NULL
block|,
comment|/* read multiple */
name|NULL
block|,
name|nexus_bs_rm_2
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* read region */
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* write (single) */
name|nexus_bs_w_1
block|,
name|nexus_bs_w_2
block|,
name|nexus_bs_w_4
block|,
name|NULL
block|,
comment|/* write multiple */
name|nexus_bs_wm_1
block|,
name|nexus_bs_wm_2
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* write region */
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
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
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* copy */
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bus space functions */
end_comment

begin_function
name|int
name|nexus_bs_map
parameter_list|(
name|void
modifier|*
name|t
parameter_list|,
name|bus_addr_t
name|bpa
parameter_list|,
name|bus_size_t
name|size
parameter_list|,
name|int
name|cacheable
parameter_list|,
name|bus_space_handle_t
modifier|*
name|bshp
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|nexus_bs_alloc
parameter_list|(
name|t
parameter_list|,
name|rstart
parameter_list|,
name|rend
parameter_list|,
name|size
parameter_list|,
name|alignment
parameter_list|,
name|boundary
parameter_list|,
name|cacheable
parameter_list|,
name|bpap
parameter_list|,
name|bshp
parameter_list|)
name|void
modifier|*
name|t
decl_stmt|;
name|bus_addr_t
name|rstart
decl_stmt|,
name|rend
decl_stmt|;
name|bus_size_t
name|size
decl_stmt|,
name|alignment
decl_stmt|,
name|boundary
decl_stmt|;
name|int
name|cacheable
decl_stmt|;
name|bus_addr_t
modifier|*
name|bpap
decl_stmt|;
name|bus_space_handle_t
modifier|*
name|bshp
decl_stmt|;
block|{
name|panic
argument_list|(
literal|"mainbus_bs_alloc(): Help!"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|nexus_bs_unmap
parameter_list|(
name|void
modifier|*
name|t
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|size
parameter_list|)
block|{
comment|/* 	 * Temporary implementation 	 */
block|}
end_function

begin_function
name|void
name|nexus_bs_free
parameter_list|(
name|t
parameter_list|,
name|bsh
parameter_list|,
name|size
parameter_list|)
name|void
modifier|*
name|t
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|bus_size_t
name|size
decl_stmt|;
block|{
name|panic
argument_list|(
literal|"mainbus_bs_free(): Help!"
argument_list|)
expr_stmt|;
comment|/* mainbus_bs_unmap() does all that we need to do. */
comment|/*	mainbus_bs_unmap(t, bsh, size);*/
block|}
end_function

begin_function
name|int
name|nexus_bs_subregion
parameter_list|(
name|t
parameter_list|,
name|bsh
parameter_list|,
name|offset
parameter_list|,
name|size
parameter_list|,
name|nbshp
parameter_list|)
name|void
modifier|*
name|t
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|bus_size_t
name|offset
decl_stmt|,
name|size
decl_stmt|;
name|bus_space_handle_t
modifier|*
name|nbshp
decl_stmt|;
block|{
operator|*
name|nbshp
operator|=
name|bsh
operator|+
name|offset
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|nexus_bs_mmap
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|,
name|vm_offset_t
name|off
parameter_list|,
name|vm_paddr_t
modifier|*
name|addr
parameter_list|,
name|int
name|prot
parameter_list|)
block|{
operator|*
name|addr
operator|=
name|off
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|nexus_bs_barrier
parameter_list|(
name|t
parameter_list|,
name|bsh
parameter_list|,
name|offset
parameter_list|,
name|len
parameter_list|,
name|flags
parameter_list|)
name|void
modifier|*
name|t
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|bus_size_t
name|offset
decl_stmt|,
name|len
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|{ }
end_function

begin_comment
comment|/* End of mainbus_io.c */
end_comment

end_unit

