begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996, 1997, 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Charles M. Hannum.  All rights reserved.  * Copyright (c) 1996 Christopher G. Demetriou.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: bus.h,v 1.9.4.1 2000/06/30 16:27:30 simonb Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACPPC_BUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACPPC_BUS_H_
end_define

begin_include
include|#
directive|include
file|<machine/pio.h>
end_include

begin_define
define|#
directive|define
name|BUS_SPACE_MAXSIZE_24BIT
value|0xFFFFFF
end_define

begin_define
define|#
directive|define
name|BUS_SPACE_MAXSIZE_32BIT
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|BUS_SPACE_MAXSIZE
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|BUS_SPACE_MAXADDR_24BIT
value|0xFFFFFF
end_define

begin_define
define|#
directive|define
name|BUS_SPACE_MAXADDR_32BIT
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|BUS_SPACE_MAXADDR
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|BUS_SPACE_UNRESTRICTED
value|(~0)
end_define

begin_comment
comment|/*  * Values for the macppc bus space tag, not to be used directly by MI code.  */
end_comment

begin_define
define|#
directive|define
name|__BUS_SPACE_HAS_STREAM_METHODS
value|1
end_define

begin_comment
comment|/*  * Bus address and size types  */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|bus_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|bus_size_t
typedef|;
end_typedef

begin_comment
comment|/*  * Define the PPC tag values  */
end_comment

begin_define
define|#
directive|define
name|PPC_BUS_SPACE_MEM
value|1
end_define

begin_comment
comment|/* space is mem space */
end_comment

begin_define
define|#
directive|define
name|PPC_BUS_SPACE_IO
value|2
end_define

begin_comment
comment|/* space is io space */
end_comment

begin_comment
comment|/*  * Access methods for bus resources and address space.  */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|bus_space_tag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|bus_space_handle_t
typedef|;
end_typedef

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|__ppc_ba
parameter_list|(
name|bus_space_tag_t
name|tag
name|__unused
parameter_list|,
name|bus_space_handle_t
name|handle
parameter_list|,
name|bus_size_t
name|offset
parameter_list|)
block|{
return|return
operator|(
operator|(
name|void
operator|*
operator|)
operator|(
name|handle
operator|+
name|offset
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *	int bus_space_map(bus_space_tag_t t, bus_addr_t addr,  *	    bus_size_t size, int flags, bus_space_handle_t *bshp));  *  * Map a region of bus space.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|bus_space_map(t, addr, size, flags, bshp) ! not implemented !
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	int bus_space_unmap(bus_space_tag_t t,  *	    bus_space_handle_t bsh, bus_size_t size));  *  * Unmap a region of bus space.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|bus_space_unmap
parameter_list|(
name|bus_space_tag_t
name|t
name|__unused
parameter_list|,
name|bus_space_handle_t
name|bsh
name|__unused
parameter_list|,
name|bus_size_t
name|size
name|__unused
parameter_list|)
block|{ }
end_function

begin_comment
comment|/*  *	int bus_space_subregion(bus_space_tag_t t,  *	    bus_space_handle_t bsh, bus_size_t offset, bus_size_t size,  *	    bus_space_handle_t *nbshp));  *  * Get a new handle for a subregion of an already-mapped area of bus space.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|bus_space_subregion
parameter_list|(
name|bus_space_tag_t
name|t
name|__unused
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|bus_size_t
name|size
name|__unused
parameter_list|,
name|bus_space_handle_t
modifier|*
name|nbshp
parameter_list|)
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

begin_comment
comment|/*  *	int bus_space_alloc(bus_space_tag_t t, bus_addr_t rstart,  *	    bus_addr_t rend, bus_size_t size, bus_size_t align,  *	    bus_size_t boundary, int flags, bus_addr_t *addrp,  *	    bus_space_handle_t *bshp));  *  * Allocate a region of bus space.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

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
name|f
parameter_list|,
name|ap
parameter_list|,
name|hp
parameter_list|)
value|!!! unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	int bus_space_free(bus_space_tag_t t,  *	    bus_space_handle_t bsh, bus_size_t size));  *  * Free a region of bus space.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

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
value|!!! unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	u_intN_t bus_space_read_N(bus_space_tag_t tag,  *	    bus_space_handle_t bsh, bus_size_t offset));  *  * Read a 1, 2, 4, or 8 byte quantity from bus space  * described by tag/handle/offset.  */
end_comment

begin_function
specifier|static
name|__inline
name|u_int8_t
name|bus_space_read_1
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|)
block|{
return|return
operator|(
name|in8
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int16_t
name|bus_space_read_2
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|)
block|{
return|return
operator|(
name|in16rb
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int32_t
name|bus_space_read_4
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|)
block|{
return|return
operator|(
name|in32rb
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Cause a link error for bus_space_read_8 */
end_comment

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
value|!!! unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|u_int8_t
name|bus_space_read_stream_1
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|)
block|{
return|return
operator|(
name|in8
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int16_t
name|bus_space_read_stream_2
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|)
block|{
return|return
operator|(
name|in16
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int32_t
name|bus_space_read_stream_4
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|)
block|{
return|return
operator|(
name|in32
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Cause a link error for bus_space_read_stream_8 */
end_comment

begin_define
define|#
directive|define
name|bus_space_read_stream_8
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|)
value|!!! unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	void bus_space_read_multi_N(bus_space_tag_t tag,  *	    bus_space_handle_t bsh, bus_size_t offset,  *	    u_intN_t *addr, size_t count));  *  * Read `count' 1, 2, 4, or 8 byte quantities from bus space  * described by tag/handle/offset and copy into buffer provided.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|bus_space_read_multi_1
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
name|u_int8_t
modifier|*
name|a
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
name|ins8
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_read_multi_2
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
name|u_int16_t
modifier|*
name|a
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
name|ins16rb
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_read_multi_4
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
name|u_int32_t
modifier|*
name|a
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
name|ins32rb
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Cause a link error for bus_space_read_multi_8 */
end_comment

begin_define
define|#
directive|define
name|bus_space_read_multi_8
value|!!! unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|void
name|bus_space_read_multi_stream_1
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
name|u_int8_t
modifier|*
name|a
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
name|ins8
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_read_multi_stream_2
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
name|u_int16_t
modifier|*
name|a
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
name|ins16
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_read_multi_stream_4
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
name|u_int32_t
modifier|*
name|a
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
name|ins32
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Cause a link error for bus_space_read_multi_stream_8 */
end_comment

begin_define
define|#
directive|define
name|bus_space_read_multi_stream_8
value|!!! unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	void bus_space_read_region_N(bus_space_tag_t tag,  *	    bus_space_handle_t bsh, bus_size_t offset,  *	    u_intN_t *addr, size_t count));  *  * Read `count' 1, 2, 4, or 8 byte quantities from bus space  * described by tag/handle and starting at `offset' and copy into  * buffer provided.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|bus_space_read_region_1
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|u_int8_t
modifier|*
name|addr
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int8_t
modifier|*
name|s
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
operator|*
name|addr
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
asm|__asm __volatile("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_read_region_2
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|u_int16_t
modifier|*
name|addr
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int16_t
modifier|*
name|s
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
asm|__asm __volatile("lhbrx %0, 0, %1" :
literal|"=r"
operator|(
operator|*
name|addr
operator|++
operator|)
operator|:
literal|"r"
operator|(
name|s
operator|++
operator|)
block|)
function|;
end_function

begin_asm
asm|__asm __volatile("eieio; sync");
end_asm

begin_function
unit|}  static
name|__inline
name|void
name|bus_space_read_region_4
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|u_int32_t
modifier|*
name|addr
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int32_t
modifier|*
name|s
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
asm|__asm __volatile("lwbrx %0, 0, %1" :
literal|"=r"
operator|(
operator|*
name|addr
operator|++
operator|)
operator|:
literal|"r"
operator|(
name|s
operator|++
operator|)
block|)
function|;
end_function

begin_asm
asm|__asm __volatile("eieio; sync");
end_asm

begin_if
unit|}
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Cause a link error for bus_space_read_region_8 */
end_comment

begin_define
define|#
directive|define
name|bus_space_read_region_8
value|!!! unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
unit|static
name|__inline
name|void
name|bus_space_read_region_stream_2
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|u_int16_t
modifier|*
name|addr
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int16_t
modifier|*
name|s
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
operator|*
name|addr
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
asm|__asm __volatile("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_read_region_stream_4
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|u_int32_t
modifier|*
name|addr
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int32_t
modifier|*
name|s
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
operator|*
name|addr
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
asm|__asm __volatile("eieio; sync");
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Cause a link error */
end_comment

begin_define
define|#
directive|define
name|bus_space_read_region_stream_8
value|!!! unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	void bus_space_write_N(bus_space_tag_t tag,  *	    bus_space_handle_t bsh, bus_size_t offset,  *	    u_intN_t value));  *  * Write the 1, 2, 4, or 8 byte value `value' to bus space  * described by tag/handle/offset.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|bus_space_write_1
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
name|uint8_t
name|v
parameter_list|)
block|{
name|out8
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_write_2
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
name|uint16_t
name|v
parameter_list|)
block|{
name|out16rb
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_write_4
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
name|uint32_t
name|v
parameter_list|)
block|{
name|out32rb
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Cause a link error for bus_space_write_8 */
end_comment

begin_define
define|#
directive|define
name|bus_space_write_8
value|!!! unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|void
name|bus_space_write_stream_1
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
name|uint8_t
name|v
parameter_list|)
block|{
name|out8
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_write_stream_2
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
name|uint16_t
name|v
parameter_list|)
block|{
name|out16
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_write_stream_4
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
name|uint32_t
name|v
parameter_list|)
block|{
name|out32
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Cause a link error for bus_space_write_stream_8 */
end_comment

begin_define
define|#
directive|define
name|bus_space_write_stream_8
value|!!! unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	void bus_space_write_multi_N(bus_space_tag_t tag,  *	    bus_space_handle_t bsh, bus_size_t offset,  *	    const u_intN_t *addr, size_t count));  *  * Write `count' 1, 2, 4, or 8 byte quantities from the buffer  * provided to bus space described by tag/handle/offset.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|bus_space_write_multi_1
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
name|uint8_t
modifier|*
name|a
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
name|outsb
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_write_multi_2
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
name|uint16_t
modifier|*
name|a
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
name|outsw
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_write_multi_4
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
name|uint32_t
modifier|*
name|a
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
name|outsl
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|bus_space_write_multi_8
value|!!! unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|void
name|bus_space_write_multi_stream_1
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|a
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
name|outsb
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_write_multi_stream_2
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
specifier|const
name|u_int16_t
modifier|*
name|a
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
name|outsw
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_write_multi_stream_4
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|o
parameter_list|,
specifier|const
name|u_int32_t
modifier|*
name|a
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
name|outsl
argument_list|(
name|__ppc_ba
argument_list|(
name|t
argument_list|,
name|h
argument_list|,
name|o
argument_list|)
argument_list|,
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|bus_space_write_multi_stream_8
value|!!! unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	void bus_space_write_region_N(bus_space_tag_t tag,  *	    bus_space_handle_t bsh, bus_size_t offset,  *	    const u_intN_t *addr, size_t count));  *  * Write `count' 1, 2, 4, or 8 byte quantities from the buffer provided  * to bus space described by tag/handle starting at `offset'.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|bus_space_write_region_1
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|addr
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int8_t
modifier|*
name|d
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
operator|*
name|d
operator|++
operator|=
operator|*
name|addr
operator|++
expr_stmt|;
asm|__asm __volatile("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_write_region_2
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
specifier|const
name|u_int16_t
modifier|*
name|addr
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int16_t
modifier|*
name|d
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
asm|__asm __volatile("sthbrx %0, 0, %1" ::
literal|"r"
operator|(
operator|*
name|addr
operator|++
operator|)
operator|,
literal|"r"
operator|(
name|d
operator|++
operator|)
block|)
function|;
end_function

begin_asm
asm|__asm __volatile("eieio; sync");
end_asm

begin_function
unit|}  static
name|__inline
name|void
name|bus_space_write_region_4
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
specifier|const
name|u_int32_t
modifier|*
name|addr
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int32_t
modifier|*
name|d
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
asm|__asm __volatile("stwbrx %0, 0, %1" ::
literal|"r"
operator|(
operator|*
name|addr
operator|++
operator|)
operator|,
literal|"r"
operator|(
name|d
operator|++
operator|)
block|)
function|;
end_function

begin_asm
asm|__asm __volatile("eieio; sync");
end_asm

begin_if
unit|}
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|bus_space_write_region_8
value|!!! bus_space_write_region_8 unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
unit|static
name|__inline
name|void
name|bus_space_write_region_stream_2
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
specifier|const
name|u_int16_t
modifier|*
name|addr
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int16_t
modifier|*
name|d
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
operator|*
name|d
operator|++
operator|=
operator|*
name|addr
operator|++
expr_stmt|;
asm|__asm __volatile("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_write_region_stream_4
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
specifier|const
name|u_int32_t
modifier|*
name|addr
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int32_t
modifier|*
name|d
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
operator|*
name|d
operator|++
operator|=
operator|*
name|addr
operator|++
expr_stmt|;
asm|__asm __volatile("eieio; sync");
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|bus_space_write_region_stream_8
value|!!! unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	void bus_space_set_multi_N(bus_space_tag_t tag,  *	    bus_space_handle_t bsh, bus_size_t offset, u_intN_t val,  *	    size_t count));  *  * Write the 1, 2, 4, or 8 byte value `val' to bus space described  * by tag/handle/offset `count' times.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|bus_space_set_multi_1
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|u_int8_t
name|val
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int8_t
modifier|*
name|d
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
operator|*
name|d
operator|=
name|val
expr_stmt|;
asm|__asm __volatile("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_set_multi_2
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|u_int16_t
name|val
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int16_t
modifier|*
name|d
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
asm|__asm __volatile("sthbrx %0, 0, %1" ::
literal|"r"
operator|(
name|val
operator|)
operator|,
literal|"r"
operator|(
name|d
operator|)
block|)
function|;
end_function

begin_asm
asm|__asm __volatile("eieio; sync");
end_asm

begin_function
unit|}  static
name|__inline
name|void
name|bus_space_set_multi_4
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|u_int32_t
name|val
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int32_t
modifier|*
name|d
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
asm|__asm __volatile("stwbrx %0, 0, %1" ::
literal|"r"
operator|(
name|val
operator|)
operator|,
literal|"r"
operator|(
name|d
operator|)
block|)
function|;
end_function

begin_asm
asm|__asm __volatile("eieio; sync");
end_asm

begin_if
unit|}
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|bus_space_set_multi_8
value|!!! bus_space_set_multi_8 unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
unit|static
name|__inline
name|void
name|bus_space_set_multi_stream_2
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|u_int16_t
name|val
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int16_t
modifier|*
name|d
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
operator|*
name|d
operator|=
name|val
expr_stmt|;
asm|__asm __volatile("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_set_multi_stream_4
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|u_int32_t
name|val
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int32_t
modifier|*
name|d
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
operator|*
name|d
operator|=
name|val
expr_stmt|;
asm|__asm __volatile("eieio; sync");
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|bus_space_set_multi_stream_8
value|!!! unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	void bus_space_set_region_N(bus_space_tag_t tag,  *	    bus_space_handle_t bsh, bus_size_t offset, u_intN_t val,  *	    size_t count));  *  * Write `count' 1, 2, 4, or 8 byte value `val' to bus space described  * by tag/handle starting at `offset'.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|bus_space_set_region_1
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|u_int8_t
name|val
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int8_t
modifier|*
name|d
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
operator|*
name|d
operator|++
operator|=
name|val
expr_stmt|;
asm|__asm __volatile("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_set_region_2
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|u_int16_t
name|val
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int16_t
modifier|*
name|d
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
asm|__asm __volatile("sthbrx %0, 0, %1" ::
literal|"r"
operator|(
name|val
operator|)
operator|,
literal|"r"
operator|(
name|d
operator|++
operator|)
block|)
function|;
end_function

begin_asm
asm|__asm __volatile("eieio; sync");
end_asm

begin_function
unit|}  static
name|__inline
name|void
name|bus_space_set_region_4
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|u_int32_t
name|val
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int32_t
modifier|*
name|d
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
asm|__asm __volatile("stwbrx %0, 0, %1" ::
literal|"r"
operator|(
name|val
operator|)
operator|,
literal|"r"
operator|(
name|d
operator|++
operator|)
block|)
function|;
end_function

begin_asm
asm|__asm __volatile("eieio; sync");
end_asm

begin_if
unit|}
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|bus_space_set_region_8
value|!!! bus_space_set_region_8 unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
unit|static
name|__inline
name|void
name|bus_space_set_region_stream_2
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|u_int16_t
name|val
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int16_t
modifier|*
name|d
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
operator|*
name|d
operator|++
operator|=
name|val
expr_stmt|;
asm|__asm __volatile("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|bus_space_set_region_stream_4
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|u_int32_t
name|val
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
specifier|volatile
name|u_int32_t
modifier|*
name|d
init|=
name|__ppc_ba
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|)
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
operator|*
name|d
operator|++
operator|=
name|val
expr_stmt|;
asm|__asm __volatile("eieio; sync");
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|bus_space_set_region_stream_8
value|!!! unimplemented !!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	void bus_space_copy_region_N(bus_space_tag_t tag,  *	    bus_space_handle_t bsh1, bus_size_t off1,  *	    bus_space_handle_t bsh2, bus_size_t off2,  *	    size_t count));  *  * Copy `count' 1, 2, 4, or 8 byte values from bus space starting  * at tag/bsh1/off1 to bus space starting at tag/bsh2/off2.  */
end_comment

begin_comment
comment|/* XXX IMPLEMENT bus_space_copy_N() XXX */
end_comment

begin_comment
comment|/*  * Bus read/write barrier methods.  *  *	void bus_space_barrier(bus_space_tag_t tag,  *	    bus_space_handle_t bsh, bus_size_t offset,  *	    bus_size_t len, int flags));  *  * Note: the macppc does not currently require barriers, but we must  * provide the flags to MI code.  */
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
value|((void)((void)(t), (void)(h), (void)(o), (void)(l), (void)(f)))
end_define

begin_define
define|#
directive|define
name|BUS_SPACE_BARRIER_READ
value|0x01
end_define

begin_comment
comment|/* force read barrier */
end_comment

begin_define
define|#
directive|define
name|BUS_SPACE_BARRIER_WRITE
value|0x02
end_define

begin_comment
comment|/* force write barrier */
end_comment

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
comment|/*  * Bus DMA methods.  */
end_comment

begin_comment
comment|/*  * Flags used in various bus DMA methods.  */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_WAITOK
value|0x00
end_define

begin_comment
comment|/* safe to sleep (pseudo-flag) */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_NOWAIT
value|0x01
end_define

begin_comment
comment|/* not safe to sleep */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_ALLOCNOW
value|0x02
end_define

begin_comment
comment|/* perform resource allocation now */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_COHERENT
value|0x04
end_define

begin_comment
comment|/* hint: map memory DMA coherent */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_ZERO
value|0x08
end_define

begin_comment
comment|/* allocate zero'ed memory */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_BUS1
value|0x10
end_define

begin_comment
comment|/* placeholders for bus functions... */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_BUS2
value|0x20
end_define

begin_define
define|#
directive|define
name|BUS_DMA_BUS3
value|0x40
end_define

begin_define
define|#
directive|define
name|BUS_DMA_BUS4
value|0x80
end_define

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
comment|/*  *      Operations performed by bus_dmamap_sync().  */
end_comment

begin_typedef
typedef|typedef
name|int
name|bus_dmasync_op_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BUS_DMASYNC_PREREAD
value|1
end_define

begin_define
define|#
directive|define
name|BUS_DMASYNC_POSTREAD
value|2
end_define

begin_define
define|#
directive|define
name|BUS_DMASYNC_PREWRITE
value|4
end_define

begin_define
define|#
directive|define
name|BUS_DMASYNC_POSTWRITE
value|8
end_define

begin_comment
comment|/*  *      bus_dma_tag_t  *  *      A machine-dependent opaque type describing the characteristics  *      of how to perform DMA mappings.  This structure encapsultes  *      information concerning address and alignment restrictions, number  *      of S/G  segments, amount of data per S/G segment, etc.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|bus_dma_tag
modifier|*
name|bus_dma_tag_t
typedef|;
end_typedef

begin_comment
comment|/*  *      bus_dmamap_t  *  *      DMA mapping instance information.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|bus_dmamap
modifier|*
name|bus_dmamap_t
typedef|;
end_typedef

begin_comment
comment|/*  *	bus_dma_segment_t  *  *	Describes a single contiguous DMA transaction.  Values  *	are suitable for programming into DMA registers.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bus_dma_segment
block|{
name|bus_addr_t
name|ds_addr
decl_stmt|;
comment|/* DMA address */
name|bus_size_t
name|ds_len
decl_stmt|;
comment|/* length of transfer */
block|}
name|bus_dma_segment_t
typedef|;
end_typedef

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

begin_comment
comment|/*  * Allocate a handle for mapping from kva/uva/physical  * address space into bus device space.  */
end_comment

begin_function_decl
name|int
name|bus_dmamap_create
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|int
name|flags
parameter_list|,
name|bus_dmamap_t
modifier|*
name|mapp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy  a handle for mapping from kva/uva/physical  * address space into bus device space.  */
end_comment

begin_function_decl
name|int
name|bus_dmamap_destroy
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate a piece of memory that can be efficiently mapped into  * bus device space based on the constraints lited in the dma tag.  * A dmamap to for use with dmamap_load is also allocated.  */
end_comment

begin_function_decl
name|int
name|bus_dmamem_alloc
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|void
modifier|*
modifier|*
name|vaddr
parameter_list|,
name|int
name|flags
parameter_list|,
name|bus_dmamap_t
modifier|*
name|mapp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Free a piece of memory and it's allociated dmamap, that was allocated  * via bus_dmamem_alloc.  */
end_comment

begin_function_decl
name|void
name|bus_dmamem_free
parameter_list|(
name|bus_dma_tag_t
name|dmat
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
comment|/*  * A function that processes a successfully loaded dma map or an error  * from a delayed load map.  */
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

begin_comment
comment|/*  * Map the buffer buf into bus space using the dmamap map.  */
end_comment

begin_function_decl
name|int
name|bus_dmamap_load
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|bus_size_t
name|buflen
parameter_list|,
name|bus_dmamap_callback_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Like bus_dmamap_callback but includes map size in bytes.  This is  * defined as a separate interface to maintain compatiiblity for users  * of bus_dmamap_callback_t--at some point these interfaces should be merged.  */
end_comment

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

begin_comment
comment|/*  * Like bus_dmamap_load but for mbufs.  Note the use of the  * bus_dmamap_callback2_t interface.  */
end_comment

begin_function_decl
name|int
name|bus_dmamap_load_mbuf
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|,
name|struct
name|mbuf
modifier|*
name|mbuf
parameter_list|,
name|bus_dmamap_callback2_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Like bus_dmamap_load but for uios.  Note the use of the  * bus_dmamap_callback2_t interface.  */
end_comment

begin_function_decl
name|int
name|bus_dmamap_load_uio
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|,
name|struct
name|uio
modifier|*
name|ui
parameter_list|,
name|bus_dmamap_callback2_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Perform a syncronization operation on the given map.  */
end_comment

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

begin_comment
comment|/*  * Release the mapping held by map.  */
end_comment

begin_function_decl
name|void
name|bus_dmamap_unload
parameter_list|(
name|bus_dma_tag_t
name|dmat
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
comment|/* _MACPPC_BUS_H_ */
end_comment

end_unit

