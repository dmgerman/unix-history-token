begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: obio_space.c,v 1.6 2003/07/15 00:25:05 lukem Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001, 2002, 2003 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * bus_space functions for PXA devices  */
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

begin_include
include|#
directive|include
file|<arm/xscale/pxa/pxareg.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/pxa/pxavar.h>
end_include

begin_expr_stmt
specifier|static
name|MALLOC_DEFINE
argument_list|(
name|M_PXATAG
argument_list|,
literal|"PXA bus_space tags"
argument_list|,
literal|"Bus_space tags for PXA"
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|pxa
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * The obio bus space tag.  This is constant for all instances, so  * we never have to explicitly "create" it.  */
end_comment

begin_decl_stmt
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
name|pxa_bs_r_1
block|,
name|pxa_bs_r_2
block|,
name|pxa_bs_r_4
block|,
name|NULL
block|,
comment|/* read multiple */
name|pxa_bs_rm_1
block|,
name|pxa_bs_rm_2
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* read region */
name|pxa_bs_rr_1
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
comment|/* write (single) */
name|pxa_bs_w_1
block|,
name|pxa_bs_w_2
block|,
name|pxa_bs_w_4
block|,
name|NULL
block|,
comment|/* write multiple */
name|pxa_bs_wm_1
block|,
name|pxa_bs_wm_2
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

begin_decl_stmt
specifier|static
name|struct
name|bus_space
name|_obio_tag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_space_tag_t
name|base_tag
init|=
operator|&
name|_base_tag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_space_tag_t
name|obio_tag
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|pxa_obio_tag_init
parameter_list|()
block|{
name|bcopy
argument_list|(
operator|&
name|_base_tag
argument_list|,
operator|&
name|_obio_tag
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|bus_space
argument_list|)
argument_list|)
expr_stmt|;
name|_obio_tag
operator|.
name|bs_privdata
operator|=
operator|(
name|void
operator|*
operator|)
name|PXA2X0_PERIPH_OFFSET
expr_stmt|;
name|obio_tag
operator|=
operator|&
name|_obio_tag
expr_stmt|;
block|}
end_function

begin_function
name|bus_space_tag_t
name|pxa_bus_tag_alloc
parameter_list|(
name|bus_addr_t
name|offset
parameter_list|)
block|{
name|struct
name|bus_space
modifier|*
name|tag
decl_stmt|;
name|tag
operator|=
operator|(
expr|struct
name|bus_space
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|bus_space
argument_list|)
argument_list|,
name|M_PXATAG
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
if|if
condition|(
name|tag
operator|==
name|NULL
condition|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|bcopy
argument_list|(
operator|&
name|_base_tag
argument_list|,
name|tag
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|bus_space
argument_list|)
argument_list|)
expr_stmt|;
name|tag
operator|->
name|bs_privdata
operator|=
operator|(
name|void
operator|*
operator|)
name|offset
expr_stmt|;
return|return
operator|(
operator|(
name|bus_space_tag_t
operator|)
name|tag
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|READ_SINGLE
parameter_list|(
name|type
parameter_list|,
name|proto
parameter_list|,
name|base
parameter_list|)
define|\
value|type								\ 	proto(bus_space_tag_t tag, bus_space_handle_t bsh, bus_size_t offset)	\ 	{								\ 		bus_addr_t	tag_offset;				\ 		type		value;					\ 		tag_offset = (bus_addr_t)tag->bs_privdata;		\ 		value = base(NULL, bsh + tag_offset, offset);		\ 		return (value);						\ 	}
end_define

begin_macro
name|READ_SINGLE
argument_list|(
argument|u_int8_t
argument_list|,
argument|pxa_bs_r_1
argument_list|,
argument|generic_bs_r_1
argument_list|)
end_macro

begin_macro
name|READ_SINGLE
argument_list|(
argument|u_int16_t
argument_list|,
argument|pxa_bs_r_2
argument_list|,
argument|generic_bs_r_2
argument_list|)
end_macro

begin_macro
name|READ_SINGLE
argument_list|(
argument|u_int32_t
argument_list|,
argument|pxa_bs_r_4
argument_list|,
argument|generic_bs_r_4
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|READ_SINGLE
end_undef

begin_define
define|#
directive|define
name|WRITE_SINGLE
parameter_list|(
name|type
parameter_list|,
name|proto
parameter_list|,
name|base
parameter_list|)
define|\
value|void								\ 	proto(bus_space_tag_t tag, bus_space_handle_t bsh, bus_size_t offset,	\ 	    type value)							\ 	{								\ 		bus_addr_t	tag_offset;				\ 		tag_offset = (bus_addr_t)tag->bs_privdata;		\ 		base(NULL, bsh + tag_offset, offset, value);		\ 	}
end_define

begin_macro
name|WRITE_SINGLE
argument_list|(
argument|u_int8_t
argument_list|,
argument|pxa_bs_w_1
argument_list|,
argument|generic_bs_w_1
argument_list|)
end_macro

begin_macro
name|WRITE_SINGLE
argument_list|(
argument|u_int16_t
argument_list|,
argument|pxa_bs_w_2
argument_list|,
argument|generic_bs_w_2
argument_list|)
end_macro

begin_macro
name|WRITE_SINGLE
argument_list|(
argument|u_int32_t
argument_list|,
argument|pxa_bs_w_4
argument_list|,
argument|generic_bs_w_4
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|WRITE_SINGLE
end_undef

begin_define
define|#
directive|define
name|READ_MULTI
parameter_list|(
name|type
parameter_list|,
name|proto
parameter_list|,
name|base
parameter_list|)
define|\
value|void								\ 	proto(bus_space_tag_t tag, bus_space_handle_t bsh, bus_size_t offset,	\ 	    type *dest, bus_size_t count)				\ 	{								\ 		bus_addr_t	tag_offset;				\ 		tag_offset = (bus_addr_t)tag->bs_privdata;		\ 		base(NULL, bsh + tag_offset, offset, dest, count);	\ 	}
end_define

begin_macro
name|READ_MULTI
argument_list|(
argument|u_int8_t
argument_list|,
argument|pxa_bs_rm_1
argument_list|,
argument|generic_bs_rm_1
argument_list|)
end_macro

begin_macro
name|READ_MULTI
argument_list|(
argument|u_int16_t
argument_list|,
argument|pxa_bs_rm_2
argument_list|,
argument|generic_bs_rm_2
argument_list|)
end_macro

begin_macro
name|READ_MULTI
argument_list|(
argument|u_int8_t
argument_list|,
argument|pxa_bs_rr_1
argument_list|,
argument|generic_bs_rr_1
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|READ_MULTI
end_undef

begin_define
define|#
directive|define
name|WRITE_MULTI
parameter_list|(
name|type
parameter_list|,
name|proto
parameter_list|,
name|base
parameter_list|)
define|\
value|void								\ 	proto(bus_space_tag_t tag, bus_space_handle_t bsh, bus_size_t offset,	\ 	    const type *src, bus_size_t count)				\ 	{								\ 		bus_addr_t	tag_offset;				\ 		tag_offset = (bus_addr_t)tag->bs_privdata;		\ 		base(NULL, bsh + tag_offset, offset, src, count);	\ 	}
end_define

begin_macro
name|WRITE_MULTI
argument_list|(
argument|u_int8_t
argument_list|,
argument|pxa_bs_wm_1
argument_list|,
argument|generic_bs_wm_1
argument_list|)
end_macro

begin_macro
name|WRITE_MULTI
argument_list|(
argument|u_int16_t
argument_list|,
argument|pxa_bs_wm_2
argument_list|,
argument|generic_bs_wm_2
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|WRITE_MULTI
end_undef

end_unit

