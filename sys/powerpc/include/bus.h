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

begin_comment
comment|/*  * Values for the macppc bus space tag, not to be used directly by MI code.  */
end_comment

begin_define
define|#
directive|define
name|__BUS_SPACE_HAS_STREAM_METHODS
end_define

begin_define
define|#
directive|define
name|MACPPC_BUS_ADDR_MASK
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|MACPPC_BUS_STRIDE_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|macppc_make_bus_space_tag
parameter_list|(
name|addr
parameter_list|,
name|stride
parameter_list|)
define|\
value|(((addr)& MACPPC_BUS_ADDR_MASK) | (stride))
end_define

begin_define
define|#
directive|define
name|__BA
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|)
value|((void *)((h) + ((o)<< ((t)& MACPPC_BUS_STRIDE_MASK))))
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

begin_comment
comment|/*  *	int bus_space_map(bus_space_tag_t t, bus_addr_t addr,  *	    bus_size_t size, int flags, bus_space_handle_t *bshp));  *  * Map a region of bus space.  */
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

begin_function_decl
specifier|extern
name|void
modifier|*
name|mapiodev
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|int
name|bus_space_map
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_addr_t
name|addr
parameter_list|,
name|bus_size_t
name|size
parameter_list|,
name|int
name|flags
parameter_list|,
name|bus_space_handle_t
modifier|*
name|bshp
parameter_list|)
block|{
name|vm_offset_t
name|base
init|=
name|t
operator|&
name|MACPPC_BUS_ADDR_MASK
decl_stmt|;
name|int
name|stride
init|=
name|t
operator|&
name|MACPPC_BUS_STRIDE_MASK
decl_stmt|;
operator|*
name|bshp
operator|=
operator|(
name|bus_space_handle_t
operator|)
name|mapiodev
argument_list|(
name|base
operator|+
operator|(
name|addr
operator|<<
name|stride
operator|)
argument_list|,
name|size
operator|<<
name|stride
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  *	int bus_space_unmap(bus_space_tag_t t,  *	    bus_space_handle_t bsh, bus_size_t size));  *  * Unmap a region of bus space.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_unmap
parameter_list|(
name|t
parameter_list|,
name|bsh
parameter_list|,
name|size
parameter_list|)
end_define

begin_comment
comment|/*  *	int bus_space_subregion(bus_space_tag_t t,  *	    bus_space_handle_t bsh, bus_size_t offset, bus_size_t size,  *	    bus_space_handle_t *nbshp));  *  * Get a new handle for a subregion of an already-mapped area of bus space.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_subregion
parameter_list|(
name|t
parameter_list|,
name|bsh
parameter_list|,
name|offset
parameter_list|,
name|size
parameter_list|,
name|bshp
parameter_list|)
define|\
value|((*(bshp) = (bus_space_handle_t)__BA(t, bsh, offset)), 0)
end_define

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
value|(in8(__BA(t, h, o)))
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
value|(in16rb(__BA(t, h, o)))
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
value|(in32rb(__BA(t, h, o)))
end_define

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

begin_define
define|#
directive|define
name|bus_space_read_stream_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|)
value|(in8(__BA(t, h, o)))
end_define

begin_define
define|#
directive|define
name|bus_space_read_stream_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|)
value|(in16(__BA(t, h, o)))
end_define

begin_define
define|#
directive|define
name|bus_space_read_stream_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|)
value|(in32(__BA(t, h, o)))
end_define

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

begin_comment
comment|/*  *	void bus_space_read_multi_N(bus_space_tag_t tag,  *	    bus_space_handle_t bsh, bus_size_t offset,  *	    u_intN_t *addr, size_t count));  *  * Read `count' 1, 2, 4, or 8 byte quantities from bus space  * described by tag/handle/offset and copy into buffer provided.  */
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
value|do {			\ 		ins8(__BA(t, h, o), (a), (c));				\ 	} while (0)
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
value|do {			\ 		ins16rb(__BA(t, h, o), (a), (c));			\ 	} while (0)
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
value|do {			\ 		ins32rb(__BA(t, h, o), (a), (c));			\ 	} while (0)
end_define

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

begin_define
define|#
directive|define
name|bus_space_read_multi_stream_1
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
value|do {		\ 		ins8(__BA(t, h, o), (a), (c));				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|bus_space_read_multi_stream_2
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
value|do {		\ 		ins16(__BA(t, h, o), (a), (c));				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|bus_space_read_multi_stream_4
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
value|do {		\ 		ins32(__BA(t, h, o), (a), (c));				\ 	} while (0)
end_define

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
name|__BA
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
name|__BA
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
name|__BA
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
name|__BA
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
name|__BA
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
value|out8(__BA(t, h, o), (v))
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
value|out16rb(__BA(t, h, o), (v))
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
value|out32rb(__BA(t, h, o), (v))
end_define

begin_define
define|#
directive|define
name|bus_space_write_stream_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
value|out8(__BA(t, h, o), (v))
end_define

begin_define
define|#
directive|define
name|bus_space_write_stream_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
value|out16(__BA(t, h, o), (v))
end_define

begin_define
define|#
directive|define
name|bus_space_write_stream_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
value|out32(__BA(t, h, o), (v))
end_define

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

begin_comment
comment|/*  *	void bus_space_write_multi_N(bus_space_tag_t tag,  *	    bus_space_handle_t bsh, bus_size_t offset,  *	    const u_intN_t *addr, size_t count));  *  * Write `count' 1, 2, 4, or 8 byte quantities from the buffer  * provided to bus space described by tag/handle/offset.  */
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
value|do {			\ 		outsb(__BA(t, h, o), (a), (c));				\ 	} while (0)
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
value|do {			\ 		outsw(__BA(t, h, o), (a), (c));				\ 	} while (0)
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
value|do {			\ 		outsl(__BA(t, h, o), (a), (c));				\ 	} while (0)
end_define

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

begin_define
define|#
directive|define
name|bus_space_write_multi_stream_2
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
value|do {		\ 		outsw(__BA(t, h, o), (a), (c));				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|bus_space_write_multi_stream_4
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
value|do {		\ 		outsl(__BA(t, h, o), (a), (c));				\ 	} while (0)
end_define

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
name|__BA
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
name|__BA
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
name|__BA
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
name|__BA
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
name|__BA
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
name|__BA
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
name|__BA
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
name|__BA
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
name|__BA
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
name|__BA
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
name|__BA
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
name|__BA
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
name|__BA
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
name|__BA
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
name|__BA
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
name|macppc_bus_dma_tag
modifier|*
name|bus_dma_tag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|macppc_bus_dmamap
modifier|*
name|bus_dmamap_t
typedef|;
end_typedef

begin_comment
comment|/*  *	bus_dma_segment_t  *  *	Describes a single contiguous DMA transaction.  Values  *	are suitable for programming into DMA registers.  */
end_comment

begin_struct
struct|struct
name|macppc_bus_dma_segment
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
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|macppc_bus_dma_segment
name|bus_dma_segment_t
typedef|;
end_typedef

begin_comment
comment|/*  *	bus_dma_tag_t  *  *	A machine-dependent opaque type describing the implementation of  *	DMA for a given bus.  */
end_comment

begin_struct
struct|struct
name|macppc_bus_dma_tag
block|{
comment|/* 	 * The `bounce threshold' is checked while we are loading 	 * the DMA map.  If the physical address of the segment 	 * exceeds the threshold, an error will be returned.  The 	 * caller can then take whatever action is necessary to 	 * bounce the transfer.  If this value is 0, it will be 	 * ignored. 	 */
name|bus_addr_t
name|_bounce_thresh
decl_stmt|;
comment|/* 	 * DMA mapping methods. 	 */
name|int
function_decl|(
modifier|*
name|_dmamap_create
function_decl|)
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|int
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|int
parameter_list|,
name|bus_dmamap_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|_dmamap_destroy
function_decl|)
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|_dmamap_load
function_decl|)
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
name|struct
name|proc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|_dmamap_load_mbuf
function_decl|)
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|_dmamap_load_uio
function_decl|)
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|_dmamap_load_raw
function_decl|)
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
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
name|void
function_decl|(
modifier|*
name|_dmamap_unload
function_decl|)
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|_dmamap_sync
function_decl|)
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
parameter_list|,
name|bus_addr_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* 	 * DMA memory utility functions. 	 */
name|int
function_decl|(
modifier|*
name|_dmamem_alloc
function_decl|)
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_dma_segment_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|_dmamem_free
function_decl|)
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dma_segment_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|_dmamem_map
function_decl|)
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dma_segment_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|size_t
parameter_list|,
name|caddr_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|_dmamem_unmap
function_decl|)
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|caddr_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|vm_offset_t
function_decl|(
modifier|*
name|_dmamem_mmap
function_decl|)
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dma_segment_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|bus_dmamap_create
parameter_list|(
name|t
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|,
name|m
parameter_list|,
name|b
parameter_list|,
name|f
parameter_list|,
name|p
parameter_list|)
define|\
value|(*(t)->_dmamap_create)((t), (s), (n), (m), (b), (f), (p))
end_define

begin_define
define|#
directive|define
name|bus_dmamap_destroy
parameter_list|(
name|t
parameter_list|,
name|p
parameter_list|)
define|\
value|(*(t)->_dmamap_destroy)((t), (p))
end_define

begin_define
define|#
directive|define
name|bus_dmamap_load
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|,
name|b
parameter_list|,
name|s
parameter_list|,
name|p
parameter_list|,
name|f
parameter_list|)
define|\
value|(*(t)->_dmamap_load)((t), (m), (b), (s), (p), (f))
end_define

begin_define
define|#
directive|define
name|bus_dmamap_load_mbuf
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|,
name|b
parameter_list|,
name|f
parameter_list|)
define|\
value|(*(t)->_dmamap_load_mbuf)((t), (m), (b), (f))
end_define

begin_define
define|#
directive|define
name|bus_dmamap_load_uio
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|,
name|u
parameter_list|,
name|f
parameter_list|)
define|\
value|(*(t)->_dmamap_load_uio)((t), (m), (u), (f))
end_define

begin_define
define|#
directive|define
name|bus_dmamap_load_raw
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|,
name|sg
parameter_list|,
name|n
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
define|\
value|(*(t)->_dmamap_load_raw)((t), (m), (sg), (n), (s), (f))
end_define

begin_define
define|#
directive|define
name|bus_dmamap_unload
parameter_list|(
name|t
parameter_list|,
name|p
parameter_list|)
define|\
value|(*(t)->_dmamap_unload)((t), (p))
end_define

begin_define
define|#
directive|define
name|bus_dmamap_sync
parameter_list|(
name|t
parameter_list|,
name|p
parameter_list|,
name|o
parameter_list|,
name|l
parameter_list|,
name|ops
parameter_list|)
define|\
value|(void)((t)->_dmamap_sync ?				\ 	    (*(t)->_dmamap_sync)((t), (p), (o), (l), (ops)) : (void)0)
end_define

begin_define
define|#
directive|define
name|bus_dmamem_alloc
parameter_list|(
name|t
parameter_list|,
name|s
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|sg
parameter_list|,
name|n
parameter_list|,
name|r
parameter_list|,
name|f
parameter_list|)
define|\
value|(*(t)->_dmamem_alloc)((t), (s), (a), (b), (sg), (n), (r), (f))
end_define

begin_define
define|#
directive|define
name|bus_dmamem_free
parameter_list|(
name|t
parameter_list|,
name|sg
parameter_list|,
name|n
parameter_list|)
define|\
value|(*(t)->_dmamem_free)((t), (sg), (n))
end_define

begin_define
define|#
directive|define
name|bus_dmamem_map
parameter_list|(
name|t
parameter_list|,
name|sg
parameter_list|,
name|n
parameter_list|,
name|s
parameter_list|,
name|k
parameter_list|,
name|f
parameter_list|)
define|\
value|(*(t)->_dmamem_map)((t), (sg), (n), (s), (k), (f))
end_define

begin_define
define|#
directive|define
name|bus_dmamem_unmap
parameter_list|(
name|t
parameter_list|,
name|k
parameter_list|,
name|s
parameter_list|)
define|\
value|(*(t)->_dmamem_unmap)((t), (k), (s))
end_define

begin_define
define|#
directive|define
name|bus_dmamem_mmap
parameter_list|(
name|t
parameter_list|,
name|sg
parameter_list|,
name|n
parameter_list|,
name|o
parameter_list|,
name|p
parameter_list|,
name|f
parameter_list|)
define|\
value|(*(t)->_dmamem_mmap)((t), (sg), (n), (o), (p), (f))
end_define

begin_comment
comment|/*  *	bus_dmamap_t  *  *	Describes a DMA mapping.  */
end_comment

begin_struct
struct|struct
name|macppc_bus_dmamap
block|{
comment|/* 	 * PRIVATE MEMBERS: not for use my machine-independent code. 	 */
name|bus_size_t
name|_dm_size
decl_stmt|;
comment|/* largest DMA transfer mappable */
name|int
name|_dm_segcnt
decl_stmt|;
comment|/* number of segs this map can map */
name|bus_size_t
name|_dm_maxsegsz
decl_stmt|;
comment|/* largest possible segment */
name|bus_size_t
name|_dm_boundary
decl_stmt|;
comment|/* don't cross this */
name|bus_addr_t
name|_dm_bounce_thresh
decl_stmt|;
comment|/* bounce threshold; see tag */
name|int
name|_dm_flags
decl_stmt|;
comment|/* misc. flags */
name|void
modifier|*
name|_dm_cookie
decl_stmt|;
comment|/* cookie for bus-specific functions */
comment|/* 	 * PUBLIC MEMBERS: these are used by machine-independent code. 	 */
name|bus_size_t
name|dm_mapsize
decl_stmt|;
comment|/* size of the mapping */
name|int
name|dm_nsegs
decl_stmt|;
comment|/* # valid segments in mapping */
name|bus_dma_segment_t
name|dm_segs
index|[
literal|1
index|]
decl_stmt|;
comment|/* segments; variable length */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_MACPPC_BUS_DMA_PRIVATE
end_ifdef

begin_function_decl
name|int
name|_bus_dmamap_create
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|int
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|int
parameter_list|,
name|bus_dmamap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_bus_dmamap_destroy
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_bus_dmamap_load
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
name|struct
name|proc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_bus_dmamap_load_mbuf
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_bus_dmamap_load_uio
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_bus_dmamap_load_raw
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
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
end_function_decl

begin_function_decl
name|void
name|_bus_dmamap_unload
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_bus_dmamap_sync
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|bus_dmamap_t
parameter_list|,
name|bus_addr_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_bus_dmamem_alloc
parameter_list|(
name|bus_dma_tag_t
name|tag
parameter_list|,
name|bus_size_t
name|size
parameter_list|,
name|bus_size_t
name|alignment
parameter_list|,
name|bus_size_t
name|boundary
parameter_list|,
name|bus_dma_segment_t
modifier|*
name|segs
parameter_list|,
name|int
name|nsegs
parameter_list|,
name|int
modifier|*
name|rsegs
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_bus_dmamem_free
parameter_list|(
name|bus_dma_tag_t
name|tag
parameter_list|,
name|bus_dma_segment_t
modifier|*
name|segs
parameter_list|,
name|int
name|nsegs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_bus_dmamem_map
parameter_list|(
name|bus_dma_tag_t
name|tag
parameter_list|,
name|bus_dma_segment_t
modifier|*
name|segs
parameter_list|,
name|int
name|nsegs
parameter_list|,
name|size_t
name|size
parameter_list|,
name|caddr_t
modifier|*
name|kvap
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_bus_dmamem_unmap
parameter_list|(
name|bus_dma_tag_t
name|tag
parameter_list|,
name|caddr_t
name|kva
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|_bus_dmamem_mmap
parameter_list|(
name|bus_dma_tag_t
name|tag
parameter_list|,
name|bus_dma_segment_t
modifier|*
name|segs
parameter_list|,
name|int
name|nsegs
parameter_list|,
name|off_t
name|off
parameter_list|,
name|int
name|prot
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_bus_dmamem_alloc_range
parameter_list|(
name|bus_dma_tag_t
name|tag
parameter_list|,
name|bus_size_t
name|size
parameter_list|,
name|bus_size_t
name|alignment
parameter_list|,
name|bus_size_t
name|boundary
parameter_list|,
name|bus_dma_segment_t
modifier|*
name|segs
parameter_list|,
name|int
name|nsegs
parameter_list|,
name|int
modifier|*
name|rsegs
parameter_list|,
name|int
name|flags
parameter_list|,
name|vm_offset_t
name|low
parameter_list|,
name|vm_offset_t
name|high
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACPPC_BUS_DMA_PRIVATE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACPPC_BUS_H_ */
end_comment

end_unit

