begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: bus.h,v 1.11 2003/07/28 17:35:54 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996, 1997, 1998, 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Charles M. Hannum.  All rights reserved.  * Copyright (c) 1996 Christopher G. Demetriou.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_BUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_BUS_H_
end_define

begin_comment
comment|/*  * Addresses (in bus space).  */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|bus_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|bus_size_t
typedef|;
end_typedef

begin_comment
comment|/*  * Access methods for bus space.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|bus_space
modifier|*
name|bus_space_tag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|bus_space_handle_t
typedef|;
end_typedef

begin_comment
comment|/*  *	int bus_space_map  (bus_space_tag_t t, bus_addr_t addr,  *	    bus_size_t size, int flags, bus_space_handle_t *bshp);  *  * Map a region of bus space.  */
end_comment

begin_define
define|#
directive|define
name|BUS_SPACE_MAP_CACHEABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|BUS_SPACE_MAP_LINEAR
value|0x02
end_define

begin_define
define|#
directive|define
name|BUS_SPACE_MAP_PREFETCHABLE
value|0x04
end_define

begin_struct
struct|struct
name|bus_space
block|{
comment|/* cookie */
name|void
modifier|*
name|bs_cookie
decl_stmt|;
comment|/* mapping/unmapping */
name|int
function_decl|(
modifier|*
name|bs_map
function_decl|)
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
name|void
function_decl|(
modifier|*
name|bs_unmap
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|bs_subregion
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_space_handle_t
modifier|*
parameter_list|)
function_decl|;
comment|/* allocation/deallocation */
name|int
function_decl|(
modifier|*
name|bs_alloc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_addr_t
parameter_list|,
name|bus_addr_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|int
parameter_list|,
name|bus_addr_t
modifier|*
parameter_list|,
name|bus_space_handle_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_free
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
comment|/* get kernel virtual address */
name|void
modifier|*
function_decl|(
modifier|*
name|bs_vaddr
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|)
function_decl|;
comment|/* mmap bus space for user */
name|int
function_decl|(
modifier|*
name|bs_mmap
function_decl|)
parameter_list|(
name|struct
name|cdev
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_paddr_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* barrier */
name|void
function_decl|(
modifier|*
name|bs_barrier
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* read (single) */
name|u_int8_t
function_decl|(
modifier|*
name|bs_r_1
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|u_int16_t
function_decl|(
modifier|*
name|bs_r_2
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|u_int32_t
function_decl|(
modifier|*
name|bs_r_4
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|u_int64_t
function_decl|(
modifier|*
name|bs_r_8
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
comment|/* read multiple */
name|void
function_decl|(
modifier|*
name|bs_rm_1
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_rm_2
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_rm_4
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_rm_8
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int64_t
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
comment|/* read region */
name|void
function_decl|(
modifier|*
name|bs_rr_1
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_rr_2
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_rr_4
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_rr_8
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int64_t
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
comment|/* write (single) */
name|void
function_decl|(
modifier|*
name|bs_w_1
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_w_2
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_w_4
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_w_8
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
comment|/* write multiple */
name|void
function_decl|(
modifier|*
name|bs_wm_1
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_wm_2
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
specifier|const
name|u_int16_t
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_wm_4
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
specifier|const
name|u_int32_t
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_wm_8
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
specifier|const
name|u_int64_t
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
comment|/* write region */
name|void
function_decl|(
modifier|*
name|bs_wr_1
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_wr_2
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
specifier|const
name|u_int16_t
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_wr_4
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
specifier|const
name|u_int32_t
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_wr_8
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
specifier|const
name|u_int64_t
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
comment|/* set multiple */
name|void
function_decl|(
modifier|*
name|bs_sm_1
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_sm_2
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int16_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_sm_4
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_sm_8
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
comment|/* set region */
name|void
function_decl|(
modifier|*
name|bs_sr_1
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_sr_2
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int16_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_sr_4
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_sr_8
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
comment|/* copy */
name|void
function_decl|(
modifier|*
name|bs_c_1
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_c_2
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_c_4
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bs_c_8
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Utility macros; INTERNAL USE ONLY.  */
end_comment

begin_define
define|#
directive|define
name|__bs_c
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__CONCAT(a,b)
end_define

begin_define
define|#
directive|define
name|__bs_opname
parameter_list|(
name|op
parameter_list|,
name|size
parameter_list|)
value|__bs_c(__bs_c(__bs_c(bs_,op),_),size)
end_define

begin_define
define|#
directive|define
name|__bs_rs
parameter_list|(
name|sz
parameter_list|,
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|)
define|\
value|(*(t)->__bs_opname(r,sz))((t)->bs_cookie, h, o)
end_define

begin_define
define|#
directive|define
name|__bs_ws
parameter_list|(
name|sz
parameter_list|,
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|(*(t)->__bs_opname(w,sz))((t)->bs_cookie, h, o, v)
end_define

begin_define
define|#
directive|define
name|__bs_nonsingle
parameter_list|(
name|type
parameter_list|,
name|sz
parameter_list|,
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|(*(t)->__bs_opname(type,sz))((t)->bs_cookie, h, o, a, c)
end_define

begin_define
define|#
directive|define
name|__bs_set
parameter_list|(
name|type
parameter_list|,
name|sz
parameter_list|,
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|(*(t)->__bs_opname(type,sz))((t)->bs_cookie, h, o, v, c)
end_define

begin_define
define|#
directive|define
name|__bs_copy
parameter_list|(
name|sz
parameter_list|,
name|t
parameter_list|,
name|h1
parameter_list|,
name|o1
parameter_list|,
name|h2
parameter_list|,
name|o2
parameter_list|,
name|cnt
parameter_list|)
define|\
value|(*(t)->__bs_opname(c,sz))((t)->bs_cookie, h1, o1, h2, o2, cnt)
end_define

begin_comment
comment|/*  * Mapping and unmapping operations.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_map
parameter_list|(
name|t
parameter_list|,
name|a
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|,
name|hp
parameter_list|)
define|\
value|(*(t)->bs_map)((t)->bs_cookie, (a), (s), (c), (hp))
end_define

begin_define
define|#
directive|define
name|bus_space_unmap
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|s
parameter_list|)
define|\
value|(*(t)->bs_unmap)((t)->bs_cookie, (h), (s))
end_define

begin_define
define|#
directive|define
name|bus_space_subregion
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|s
parameter_list|,
name|hp
parameter_list|)
define|\
value|(*(t)->bs_subregion)((t)->bs_cookie, (h), (o), (s), (hp))
end_define

begin_comment
comment|/*  * Allocation and deallocation operations.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_alloc
parameter_list|(
name|t
parameter_list|,
name|rs
parameter_list|,
name|re
parameter_list|,
name|s
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|ap
parameter_list|,
name|hp
parameter_list|)
define|\
value|(*(t)->bs_alloc)((t)->bs_cookie, (rs), (re), (s), (a), (b),	\ 	    (c), (ap), (hp))
end_define

begin_define
define|#
directive|define
name|bus_space_free
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|s
parameter_list|)
define|\
value|(*(t)->bs_free)((t)->bs_cookie, (h), (s))
end_define

begin_comment
comment|/*  * Get kernel virtual address for ranges mapped BUS_SPACE_MAP_LINEAR.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_vaddr
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|)
define|\
value|(*(t)->bs_vaddr)((t)->bs_cookie, (h))
end_define

begin_comment
comment|/*  * MMap bus space for a user application.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_mmap
parameter_list|(
name|t
parameter_list|,
name|a
parameter_list|,
name|o
parameter_list|,
name|p
parameter_list|,
name|f
parameter_list|)
define|\
value|(*(t)->bs_mmap)((t)->bs_cookie, (a), (o), (p), (f))
end_define

begin_comment
comment|/*  * Bus barrier operations.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_barrier
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|)
define|\
value|(*(t)->bs_barrier)((t)->bs_cookie, (h), (o), (l), (f))
end_define

begin_define
define|#
directive|define
name|BUS_SPACE_BARRIER_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|BUS_SPACE_BARRIER_WRITE
value|0x02
end_define

begin_comment
comment|/*  * Bus read (single) operations.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_read_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|)
value|__bs_rs(1,(t),(h),(o))
end_define

begin_define
define|#
directive|define
name|bus_space_read_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|)
value|__bs_rs(2,(t),(h),(o))
end_define

begin_define
define|#
directive|define
name|bus_space_read_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|)
value|__bs_rs(4,(t),(h),(o))
end_define

begin_define
define|#
directive|define
name|bus_space_read_8
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|)
value|__bs_rs(8,(t),(h),(o))
end_define

begin_comment
comment|/*  * Bus read multiple operations.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_read_multi_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_nonsingle(rm,1,(t),(h),(o),(a),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_read_multi_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_nonsingle(rm,2,(t),(h),(o),(a),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_read_multi_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_nonsingle(rm,4,(t),(h),(o),(a),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_read_multi_8
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_nonsingle(rm,8,(t),(h),(o),(a),(c))
end_define

begin_comment
comment|/*  * Bus read region operations.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_read_region_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_nonsingle(rr,1,(t),(h),(o),(a),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_read_region_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_nonsingle(rr,2,(t),(h),(o),(a),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_read_region_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_nonsingle(rr,4,(t),(h),(o),(a),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_read_region_8
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_nonsingle(rr,8,(t),(h),(o),(a),(c))
end_define

begin_comment
comment|/*  * Bus write (single) operations.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_write_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
value|__bs_ws(1,(t),(h),(o),(v))
end_define

begin_define
define|#
directive|define
name|bus_space_write_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
value|__bs_ws(2,(t),(h),(o),(v))
end_define

begin_define
define|#
directive|define
name|bus_space_write_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
value|__bs_ws(4,(t),(h),(o),(v))
end_define

begin_define
define|#
directive|define
name|bus_space_write_8
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
value|__bs_ws(8,(t),(h),(o),(v))
end_define

begin_comment
comment|/*  * Bus write multiple operations.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_write_multi_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_nonsingle(wm,1,(t),(h),(o),(a),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_write_multi_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_nonsingle(wm,2,(t),(h),(o),(a),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_write_multi_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_nonsingle(wm,4,(t),(h),(o),(a),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_write_multi_8
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_nonsingle(wm,8,(t),(h),(o),(a),(c))
end_define

begin_comment
comment|/*  * Bus write region operations.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_write_region_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_nonsingle(wr,1,(t),(h),(o),(a),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_write_region_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_nonsingle(wr,2,(t),(h),(o),(a),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_write_region_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_nonsingle(wr,4,(t),(h),(o),(a),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_write_region_8
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_nonsingle(wr,8,(t),(h),(o),(a),(c))
end_define

begin_comment
comment|/*  * Set multiple operations.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_set_multi_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_set(sm,1,(t),(h),(o),(v),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_multi_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_set(sm,2,(t),(h),(o),(v),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_multi_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_set(sm,4,(t),(h),(o),(v),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_multi_8
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_set(sm,8,(t),(h),(o),(v),(c))
end_define

begin_comment
comment|/*  * Set region operations.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_set_region_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_set(sr,1,(t),(h),(o),(v),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_region_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_set(sr,2,(t),(h),(o),(v),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_region_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_set(sr,4,(t),(h),(o),(v),(c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_region_8
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_set(sr,8,(t),(h),(o),(v),(c))
end_define

begin_comment
comment|/*  * Copy operations.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_copy_region_1
parameter_list|(
name|t
parameter_list|,
name|h1
parameter_list|,
name|o1
parameter_list|,
name|h2
parameter_list|,
name|o2
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_copy(1, t, h1, o1, h2, o2, c)
end_define

begin_define
define|#
directive|define
name|bus_space_copy_region_2
parameter_list|(
name|t
parameter_list|,
name|h1
parameter_list|,
name|o1
parameter_list|,
name|h2
parameter_list|,
name|o2
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_copy(2, t, h1, o1, h2, o2, c)
end_define

begin_define
define|#
directive|define
name|bus_space_copy_region_4
parameter_list|(
name|t
parameter_list|,
name|h1
parameter_list|,
name|o1
parameter_list|,
name|h2
parameter_list|,
name|o2
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_copy(4, t, h1, o1, h2, o2, c)
end_define

begin_define
define|#
directive|define
name|bus_space_copy_region_8
parameter_list|(
name|t
parameter_list|,
name|h1
parameter_list|,
name|o1
parameter_list|,
name|h2
parameter_list|,
name|o2
parameter_list|,
name|c
parameter_list|)
define|\
value|__bs_copy(8, t, h1, o1, h2, o2, c)
end_define

begin_comment
comment|/*  * Macros to provide prototypes for all the functions used in the  * bus_space structure  */
end_comment

begin_define
define|#
directive|define
name|bs_map_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|int	__bs_c(f,_bs_map) (void *t, bus_addr_t addr,		\ 	    bus_size_t size, int cacheable, bus_space_handle_t *bshp);
end_define

begin_define
define|#
directive|define
name|bs_unmap_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_unmap) (void *t, bus_size_t size);
end_define

begin_define
define|#
directive|define
name|bs_subregion_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|int	__bs_c(f,_bs_subregion) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, bus_size_t size, 			\ 	    bus_space_handle_t *nbshp);
end_define

begin_define
define|#
directive|define
name|bs_alloc_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|int	__bs_c(f,_bs_alloc) (void *t, bus_addr_t rstart,		\ 	    bus_addr_t rend, bus_size_t size, bus_size_t align,		\ 	    bus_size_t boundary, int cacheable, bus_addr_t *addrp,	\ 	    bus_space_handle_t *bshp);
end_define

begin_define
define|#
directive|define
name|bs_free_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_free) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t size);
end_define

begin_define
define|#
directive|define
name|bs_vaddr_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void *	__bs_c(f,_bs_vaddr) (void *t, bus_space_handle_t bsh);
end_define

begin_define
define|#
directive|define
name|bs_mmap_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|int	__bs_c(f,_bs_mmap) (struct cdev *, vm_offset_t, vm_paddr_t *, int);
end_define

begin_define
define|#
directive|define
name|bs_barrier_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_barrier) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, bus_size_t len, int flags);
end_define

begin_define
define|#
directive|define
name|bs_r_1_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|u_int8_t	__bs_c(f,_bs_r_1) (void *t, bus_space_handle_t bsh,	\ 		    bus_size_t offset);
end_define

begin_define
define|#
directive|define
name|bs_r_2_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|u_int16_t	__bs_c(f,_bs_r_2) (void *t, bus_space_handle_t bsh,	\ 		    bus_size_t offset);
end_define

begin_define
define|#
directive|define
name|bs_r_4_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|u_int32_t	__bs_c(f,_bs_r_4) (void *t, bus_space_handle_t bsh,	\ 		    bus_size_t offset);
end_define

begin_define
define|#
directive|define
name|bs_r_8_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|u_int64_t	__bs_c(f,_bs_r_8) (void *t, bus_space_handle_t bsh,	\ 		    bus_size_t offset);
end_define

begin_define
define|#
directive|define
name|bs_w_1_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_w_1) (void *t, bus_space_handle_t bsh,		\ 	    bus_size_t offset, u_int8_t value);
end_define

begin_define
define|#
directive|define
name|bs_w_2_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_w_2) (void *t, bus_space_handle_t bsh,		\ 	    bus_size_t offset, u_int16_t value);
end_define

begin_define
define|#
directive|define
name|bs_w_4_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_w_4) (void *t, bus_space_handle_t bsh,		\ 	    bus_size_t offset, u_int32_t value);
end_define

begin_define
define|#
directive|define
name|bs_w_8_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_w_8) (void *t, bus_space_handle_t bsh,		\ 	    bus_size_t offset, u_int64_t value);
end_define

begin_define
define|#
directive|define
name|bs_rm_1_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_rm_1) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, u_int8_t *addr, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_rm_2_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_rm_2) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, u_int16_t *addr, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_rm_4_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_rm_4) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, u_int32_t *addr, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_rm_8_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_rm_8) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, u_int64_t *addr, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_wm_1_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_wm_1) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, const u_int8_t *addr, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_wm_2_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_wm_2) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, const u_int16_t *addr, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_wm_4_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_wm_4) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, const u_int32_t *addr, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_wm_8_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_wm_8) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, const u_int64_t *addr, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_rr_1_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f, _bs_rr_1) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, u_int8_t *addr, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_rr_2_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f, _bs_rr_2) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, u_int16_t *addr, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_rr_4_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f, _bs_rr_4) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, u_int32_t *addr, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_rr_8_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f, _bs_rr_8) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, u_int64_t *addr, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_wr_1_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f, _bs_wr_1) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, const u_int8_t *addr, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_wr_2_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f, _bs_wr_2) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, const u_int16_t *addr, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_wr_4_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f, _bs_wr_4) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, const u_int32_t *addr, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_wr_8_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f, _bs_wr_8) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, const u_int64_t *addr, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_sm_1_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_sm_1) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, u_int8_t value, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_sm_2_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_sm_2) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, u_int16_t value, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_sm_4_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_sm_4) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, u_int32_t value, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_sm_8_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_sm_8) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, u_int64_t value, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_sr_1_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_sr_1) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, u_int8_t value, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_sr_2_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_sr_2) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, u_int16_t value, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_sr_4_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_sr_4) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, u_int32_t value, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_sr_8_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_sr_8) (void *t, bus_space_handle_t bsh,	\ 	    bus_size_t offset, u_int64_t value, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_c_1_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_c_1) (void *t, bus_space_handle_t bsh1,	\ 	    bus_size_t offset1, bus_space_handle_t bsh2,		\ 	    bus_size_t offset2, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_c_2_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_c_2) (void *t, bus_space_handle_t bsh1,	\ 	    bus_size_t offset1, bus_space_handle_t bsh2,		\ 	    bus_size_t offset2, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_c_4_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_c_4) (void *t, bus_space_handle_t bsh1,	\ 	    bus_size_t offset1, bus_space_handle_t bsh2,		\ 	    bus_size_t offset2, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_c_8_proto
parameter_list|(
name|f
parameter_list|)
define|\
value|void	__bs_c(f,_bs_c_8) (void *t, bus_space_handle_t bsh1,	\ 	    bus_size_t offset1, bus_space_handle_t bsh2,		\ 	    bus_size_t offset2, bus_size_t count);
end_define

begin_define
define|#
directive|define
name|bs_protos
parameter_list|(
name|f
parameter_list|)
define|\
value|bs_map_proto(f);		\ bs_unmap_proto(f);		\ bs_subregion_proto(f);		\ bs_alloc_proto(f);		\ bs_free_proto(f);		\ bs_vaddr_proto(f);		\ bs_mmap_proto(f);		\ bs_barrier_proto(f);		\ bs_r_1_proto(f);		\ bs_r_2_proto(f);		\ bs_r_4_proto(f);		\ bs_r_8_proto(f);		\ bs_w_1_proto(f);		\ bs_w_2_proto(f);		\ bs_w_4_proto(f);		\ bs_w_8_proto(f);		\ bs_rm_1_proto(f);		\ bs_rm_2_proto(f);		\ bs_rm_4_proto(f);		\ bs_rm_8_proto(f);		\ bs_wm_1_proto(f);		\ bs_wm_2_proto(f);		\ bs_wm_4_proto(f);		\ bs_wm_8_proto(f);		\ bs_rr_1_proto(f);		\ bs_rr_2_proto(f);		\ bs_rr_4_proto(f);		\ bs_rr_8_proto(f);		\ bs_wr_1_proto(f);		\ bs_wr_2_proto(f);		\ bs_wr_4_proto(f);		\ bs_wr_8_proto(f);		\ bs_sm_1_proto(f);		\ bs_sm_2_proto(f);		\ bs_sm_4_proto(f);		\ bs_sm_8_proto(f);		\ bs_sr_1_proto(f);		\ bs_sr_2_proto(f);		\ bs_sr_4_proto(f);		\ bs_sr_8_proto(f);		\ bs_c_1_proto(f);		\ bs_c_2_proto(f);		\ bs_c_4_proto(f);		\ bs_c_8_proto(f);
end_define

begin_define
define|#
directive|define
name|BUS_SPACE_ALIGNED_POINTER
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|ALIGNED_POINTER(p, t)
end_define

begin_comment
comment|/* Bus Space DMA macros */
end_comment

begin_comment
comment|/*  * Flags used in various bus DMA methods.  */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_WAITOK
value|0x000
end_define

begin_comment
comment|/* safe to sleep (pseudo-flag) */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_NOWAIT
value|0x001
end_define

begin_comment
comment|/* not safe to sleep */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_ALLOCNOW
value|0x002
end_define

begin_comment
comment|/* perform resource allocation now */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_COHERENT
value|0x004
end_define

begin_comment
comment|/* hint: map memory DMA coherent */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_ZERO
value|0x008
end_define

begin_comment
comment|/* hint: sequential, unidirectional */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_BUS1
value|0x010
end_define

begin_comment
comment|/* placeholders for bus functions... */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_BUS2
value|0x020
end_define

begin_define
define|#
directive|define
name|BUS_DMA_BUS3
value|0x040
end_define

begin_define
define|#
directive|define
name|BUS_DMA_BUS4
value|0x080
end_define

begin_comment
comment|/*  * Private flags stored in the DMA map.  */
end_comment

begin_define
define|#
directive|define
name|ARM32_DMAMAP_COHERENT
value|0x10000
end_define

begin_comment
comment|/* no cache flush necessary on sync */
end_comment

begin_comment
comment|/* Forwards needed by prototypes below. */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Operations performed by bus_dmamap_sync().  */
end_comment

begin_define
define|#
directive|define
name|BUS_DMASYNC_PREREAD
value|0x01
end_define

begin_comment
comment|/* pre-read synchronization */
end_comment

begin_define
define|#
directive|define
name|BUS_DMASYNC_POSTREAD
value|0x02
end_define

begin_comment
comment|/* post-read synchronization */
end_comment

begin_define
define|#
directive|define
name|BUS_DMASYNC_PREWRITE
value|0x04
end_define

begin_comment
comment|/* pre-write synchronization */
end_comment

begin_define
define|#
directive|define
name|BUS_DMASYNC_POSTWRITE
value|0x08
end_define

begin_comment
comment|/* post-write synchronization */
end_comment

begin_typedef
typedef|typedef
name|struct
name|bus_dma_tag
modifier|*
name|bus_dma_tag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bus_dmamap
modifier|*
name|bus_dmamap_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BUS_DMA_TAG_VALID
parameter_list|(
name|t
parameter_list|)
value|((t) != (bus_dma_tag_t)0)
end_define

begin_comment
comment|/*  *	bus_dma_segment_t  *  *	Describes a single contiguous DMA transaction.  Values  *	are suitable for programming into DMA registers.  */
end_comment

begin_struct
struct|struct
name|bus_dma_segment
block|{
comment|/* 	 * PUBLIC MEMBERS: these are used by machine-independent code. 	 */
name|bus_addr_t
name|ds_addr
decl_stmt|;
comment|/* DMA address */
name|bus_size_t
name|ds_len
decl_stmt|;
comment|/* length of transfer */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bus_dma_segment
name|bus_dma_segment_t
typedef|;
end_typedef

begin_comment
comment|/*  *	arm32_dma_range  *  *	This structure describes a valid DMA range.  */
end_comment

begin_struct
struct|struct
name|arm32_dma_range
block|{
name|bus_addr_t
name|dr_sysbase
decl_stmt|;
comment|/* system base address */
name|bus_addr_t
name|dr_busbase
decl_stmt|;
comment|/* appears here on bus */
name|bus_size_t
name|dr_len
decl_stmt|;
comment|/* length of range */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	bus_dma_tag_t  *  *	A machine-dependent opaque type describing the implementation of  *	DMA for a given bus.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|bus_dmamap_callback_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_dma_segment_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|bus_dmasync_op_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|bus_dmamap_callback2_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_dma_segment_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|bus_size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_ARM32_BUS_DMA_PRIVATE
end_ifdef

begin_comment
comment|/* _dm_buftype */
end_comment

begin_define
define|#
directive|define
name|ARM32_BUFTYPE_INVALID
value|0
end_define

begin_define
define|#
directive|define
name|ARM32_BUFTYPE_LINEAR
value|1
end_define

begin_define
define|#
directive|define
name|ARM32_BUFTYPE_MBUF
value|2
end_define

begin_define
define|#
directive|define
name|ARM32_BUFTYPE_UIO
value|3
end_define

begin_define
define|#
directive|define
name|ARM32_BUFTYPE_RAW
value|4
end_define

begin_function_decl
name|struct
name|arm32_dma_range
modifier|*
name|bus_dma_get_range
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM32_BUS_DMA_PRIVATE */
end_comment

begin_comment
comment|/*  * A function that returns 1 if the address cannot be accessed by  * a device and 0 if it can be.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|bus_dma_filter_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_addr_t
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * A function that performs driver-specific syncronization on behalf of  * busdma.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BUS_DMA_LOCK
init|=
literal|0x01
block|,
name|BUS_DMA_UNLOCK
init|=
literal|0x02
block|, }
name|bus_dma_lock_op_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|bus_dma_lock_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_dma_lock_op_t
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Allocate a device specific dma_tag encapsulating the constraints of  * the parent tag in addition to other restrictions specified:  *  *      alignment:      alignment for segments.  *      boundary:       Boundary that segments cannot cross.  *      lowaddr:        Low restricted address that cannot appear in a mapping.  *      highaddr:       High restricted address that cannot appear in a mapping.  *      filtfunc:       An optional function to further test if an address  *                      within the range of lowaddr and highaddr cannot appear  *                      in a mapping.  *      filtfuncarg:    An argument that will be passed to filtfunc in addition  *                      to the address to test.  *      maxsize:        Maximum mapping size supported by this tag.  *      nsegments:      Number of discontinuities allowed in maps.  *      maxsegsz:       Maximum size of a segment in the map.  *      flags:          Bus DMA flags.  *      dmat:           A pointer to set to a valid dma tag should the return  *                      value of this function indicate success.  */
end_comment

begin_function_decl
name|int
name|bus_dma_tag_create
parameter_list|(
name|bus_dma_tag_t
name|parent
parameter_list|,
name|bus_size_t
name|alignment
parameter_list|,
name|bus_size_t
name|boundary
parameter_list|,
name|bus_addr_t
name|lowaddr
parameter_list|,
name|bus_addr_t
name|highaddr
parameter_list|,
name|bus_dma_filter_t
modifier|*
name|filtfunc
parameter_list|,
name|void
modifier|*
name|filtfuncarg
parameter_list|,
name|bus_size_t
name|maxsize
parameter_list|,
name|int
name|nsegments
parameter_list|,
name|bus_size_t
name|maxsegsz
parameter_list|,
name|int
name|flags
parameter_list|,
name|bus_dma_lock_t
modifier|*
name|lockfunc
parameter_list|,
name|void
modifier|*
name|lockfuncarg
parameter_list|,
name|bus_dma_tag_t
modifier|*
name|dmat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_dma_tag_destroy
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_dmamap_create
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|int
parameter_list|,
name|bus_dmamap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_dmamap_destroy
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_dmamap_load
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_dmamap_callback_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_dmamap_load_mbuf
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|bus_dmamap_callback2_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_dmamap_load_uio
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|bus_dmamap_callback2_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_dmamap_unload
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_dmamap_sync
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
parameter_list|,
name|bus_dmasync_op_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_dmamem_alloc
parameter_list|(
name|bus_dma_tag_t
name|tag
parameter_list|,
name|void
modifier|*
modifier|*
name|vaddr
parameter_list|,
name|int
name|flag
parameter_list|,
name|bus_dmamap_t
modifier|*
name|mapp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_dmamem_free
parameter_list|(
name|bus_dma_tag_t
name|tag
parameter_list|,
name|void
modifier|*
name|vaddr
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Generic helper function for manipulating mutexes.  */
end_comment

begin_function_decl
name|void
name|busdma_lock_mutex
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|bus_dma_lock_op_t
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_BUS_H_ */
end_comment

end_unit

