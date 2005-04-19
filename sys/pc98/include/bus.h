begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) KATO Takenori, 1999.  *  * All rights reserved.  Unpublished rights reserved under the copyright  * laws of Japan.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*	$NecBSD: busio.h,v 3.25.4.2.2.1 2000/06/12 03:53:08 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD: bus.h,v 1.12 1997/10/01 08:25:15 fvdl Exp $	*/
end_comment

begin_comment
comment|/*-  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1997, 1998  *	NetBSD/pc98 porting staff. All rights reserved.  *  * [Ported for FreeBSD]  *  Copyright (c) 2001  *	TAKAHASHI Yoshihiro. All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997, 1998  *	Naofumi HONDA.  All rights reserved.  *  * This module support generic bus address relocation mechanism.  * To reduce a function call overhead, we employ pascal call methods.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PC98_BUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_PC98_BUS_H_
end_define

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/_bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
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
comment|/*  * Access methods for bus resources and address space.  */
end_comment

begin_struct_decl
struct_decl|struct
name|resource
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Values for the i386 bus space tag, not to be used directly by MI code.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|bus_space_tag
name|SBUS_io_space_tag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|bus_space_tag
name|SBUS_mem_space_tag
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|I386_BUS_SPACE_IO
value|(&SBUS_io_space_tag)
end_define

begin_define
define|#
directive|define
name|I386_BUS_SPACE_MEM
value|(&SBUS_mem_space_tag)
end_define

begin_comment
comment|/*  * Allocate/Free bus_space_handle  */
end_comment

begin_function_decl
name|int
name|i386_bus_space_handle_alloc
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_addr_t
name|bpa
parameter_list|,
name|bus_size_t
name|size
parameter_list|,
name|bus_space_handle_t
modifier|*
name|bshp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i386_bus_space_handle_free
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *      int bus_space_map (bus_space_tag_t t, bus_addr_t addr,  *          bus_size_t size, int flag, bus_space_handle_t *bshp);  *  * Map a region of bus space.  */
end_comment

begin_function_decl
name|int
name|i386_memio_map
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
name|flag
parameter_list|,
name|bus_space_handle_t
modifier|*
name|bshp
parameter_list|)
function_decl|;
end_function_decl

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
name|f
parameter_list|,
name|hp
parameter_list|)
define|\
value|i386_memio_map((t), (a), (s), (f), (hp))
end_define

begin_comment
comment|/*  *      int bus_space_unmap (bus_space_tag_t t,  *          bus_space_handle_t bsh, bus_size_t size);  *  * Unmap a region of bus space.  */
end_comment

begin_function_decl
name|void
name|i386_memio_unmap
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

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
value|i386_memio_unmap((t), (h), (s))
end_define

begin_comment
comment|/*  *      int bus_space_subregion (bus_space_tag_t t,  *          bus_space_handle_t bsh, bus_size_t offset, bus_size_t size,  *          bus_space_handle_t *nbshp);  *  * Get a new handle for a subregion of an already-mapped area of bus space.  */
end_comment

begin_function_decl
name|int
name|i386_memio_subregion
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|bus_size_t
name|size
parameter_list|,
name|bus_space_handle_t
modifier|*
name|nbshp
parameter_list|)
function_decl|;
end_function_decl

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
name|nhp
parameter_list|)
define|\
value|i386_memio_subregion((t), (h), (o), (s), (nhp))
end_define

begin_comment
comment|/*  *      int bus_space_free (bus_space_tag_t t,  *          bus_space_handle_t bsh, bus_size_t size);  *  * Free a region of bus space.  */
end_comment

begin_function_decl
name|void
name|i386_memio_free
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

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
value|i386_memio_free((t), (h), (s))
end_define

begin_comment
comment|/*  * Access methods for bus resources and address space.  */
end_comment

begin_define
define|#
directive|define
name|_BUS_ACCESS_METHODS_PROTO
parameter_list|(
name|TYPE
parameter_list|,
name|BWN
parameter_list|)
define|\
value|static __inline TYPE bus_space_read_##BWN 			\ 	(bus_space_tag_t, bus_space_handle_t, bus_size_t offset);	\ 	static __inline void bus_space_read_multi_##BWN			\ 	(bus_space_tag_t, bus_space_handle_t,				\ 	     bus_size_t, TYPE *, size_t);				\ 	static __inline void bus_space_read_region_##BWN		\ 	(bus_space_tag_t, bus_space_handle_t,				\ 	     bus_size_t, TYPE *, size_t);				\ 	static __inline void bus_space_write_##BWN			\ 	(bus_space_tag_t, bus_space_handle_t, bus_size_t, TYPE);	\ 	static __inline void bus_space_write_multi_##BWN		\ 	(bus_space_tag_t, bus_space_handle_t,				\ 	     bus_size_t, const TYPE *, size_t);				\ 	static __inline void bus_space_write_region_##BWN		\ 	(bus_space_tag_t, bus_space_handle_t,				\ 	     bus_size_t, const TYPE *, size_t);				\ 	static __inline void bus_space_set_multi_##BWN			\ 	(bus_space_tag_t, bus_space_handle_t, bus_size_t, TYPE, size_t);\ 	static __inline void bus_space_set_region_##BWN			\ 	(bus_space_tag_t, bus_space_handle_t, bus_size_t, TYPE, size_t);\ 	static __inline void bus_space_copy_region_##BWN		\ 	(bus_space_tag_t, bus_space_handle_t, bus_size_t,		\ 	     bus_space_handle_t, bus_size_t, size_t);
end_define

begin_macro
name|_BUS_ACCESS_METHODS_PROTO
argument_list|(
argument|u_int8_t
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|_BUS_ACCESS_METHODS_PROTO
argument_list|(
argument|u_int16_t
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|_BUS_ACCESS_METHODS_PROTO
argument_list|(
argument|u_int32_t
argument_list|,
literal|4
argument_list|)
end_macro

begin_comment
comment|/*  * read methods  */
end_comment

begin_define
define|#
directive|define
name|_BUS_SPACE_READ
parameter_list|(
name|TYPE
parameter_list|,
name|BWN
parameter_list|)
define|\
value|static __inline TYPE						\ bus_space_read_##BWN (tag, bsh, offset)				\ 	bus_space_tag_t tag;					\ 	bus_space_handle_t bsh;					\ 	bus_size_t offset;					\ {								\ 	register TYPE result;					\ 								\ 	__asm __volatile("call *%2"  				\ 			:"=a" (result),				\ 			 "=d" (offset)				\ 			:"o" (bsh->bsh_bam.bs_read_##BWN),	\ 			 "b" (bsh),				\ 			 "1" (offset)				\ 			);					\ 								\ 	return result;						\ }
end_define

begin_macro
name|_BUS_SPACE_READ
argument_list|(
argument|u_int8_t
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_READ
argument_list|(
argument|u_int16_t
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_READ
argument_list|(
argument|u_int32_t
argument_list|,
literal|4
argument_list|)
end_macro

begin_comment
comment|/*  * write methods  */
end_comment

begin_define
define|#
directive|define
name|_BUS_SPACE_WRITE
parameter_list|(
name|TYPE
parameter_list|,
name|BWN
parameter_list|)
define|\
value|static __inline void						\ bus_space_write_##BWN (tag, bsh, offset, val)			\ 	bus_space_tag_t tag;					\ 	bus_space_handle_t bsh;					\ 	bus_size_t offset;					\ 	TYPE val;						\ {								\ 								\ 	__asm __volatile("call *%1"				\ 			:"=d" (offset)				\ 			:"o" (bsh->bsh_bam.bs_write_##BWN),	\ 			 "a" (val),				\ 			 "b" (bsh),				\ 			 "0" (offset)				\ 			);					\ }
end_define

begin_macro
name|_BUS_SPACE_WRITE
argument_list|(
argument|u_int8_t
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_WRITE
argument_list|(
argument|u_int16_t
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_WRITE
argument_list|(
argument|u_int32_t
argument_list|,
literal|4
argument_list|)
end_macro

begin_comment
comment|/*  * multi read  */
end_comment

begin_define
define|#
directive|define
name|_BUS_SPACE_READ_MULTI
parameter_list|(
name|TYPE
parameter_list|,
name|BWN
parameter_list|)
define|\
value|static __inline void							\ bus_space_read_multi_##BWN (tag, bsh, offset, buf, cnt) 		\ 	bus_space_tag_t tag;						\ 	bus_space_handle_t bsh;						\ 	bus_size_t offset;						\ 	TYPE *buf;							\ 	size_t cnt;							\ {									\ 									\ 	__asm __volatile("call *%3"					\ 			:"=c" (cnt),					\ 			 "=d" (offset),					\ 			 "=D" (buf)					\ 			:"o" (bsh->bsh_bam.bs_read_multi_##BWN),	\ 			 "b" (bsh),					\ 			 "0" (cnt),					\ 			 "1" (offset),					\ 			 "2" (buf)					\ 			:"memory");					\ }
end_define

begin_macro
name|_BUS_SPACE_READ_MULTI
argument_list|(
argument|u_int8_t
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_READ_MULTI
argument_list|(
argument|u_int16_t
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_READ_MULTI
argument_list|(
argument|u_int32_t
argument_list|,
literal|4
argument_list|)
end_macro

begin_comment
comment|/*  * multi write  */
end_comment

begin_define
define|#
directive|define
name|_BUS_SPACE_WRITE_MULTI
parameter_list|(
name|TYPE
parameter_list|,
name|BWN
parameter_list|)
define|\
value|static __inline void							\ bus_space_write_multi_##BWN (tag, bsh, offset, buf, cnt) 		\ 	bus_space_tag_t tag;						\ 	bus_space_handle_t bsh;						\ 	bus_size_t offset;						\ 	const TYPE *buf;						\ 	size_t cnt;							\ {									\ 									\ 	__asm __volatile("call *%3"					\ 			:"=c" (cnt),					\ 			 "=d" (offset),					\ 			 "=S" (buf)					\ 			:"o" (bsh->bsh_bam.bs_write_multi_##BWN),	\ 			 "b" (bsh),					\ 			 "0" (cnt),					\ 			 "1" (offset),					\ 			 "2" (buf)					\ 			);						\ }
end_define

begin_macro
name|_BUS_SPACE_WRITE_MULTI
argument_list|(
argument|u_int8_t
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_WRITE_MULTI
argument_list|(
argument|u_int16_t
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_WRITE_MULTI
argument_list|(
argument|u_int32_t
argument_list|,
literal|4
argument_list|)
end_macro

begin_comment
comment|/*  * region read  */
end_comment

begin_define
define|#
directive|define
name|_BUS_SPACE_READ_REGION
parameter_list|(
name|TYPE
parameter_list|,
name|BWN
parameter_list|)
define|\
value|static __inline void							\ bus_space_read_region_##BWN (tag, bsh, offset, buf, cnt) 		\ 	bus_space_tag_t tag;						\ 	bus_space_handle_t bsh;						\ 	bus_size_t offset;						\ 	TYPE *buf;						\ 	size_t cnt;							\ {									\ 									\ 	__asm __volatile("call *%3"					\ 			:"=c" (cnt),					\ 			 "=d" (offset),					\ 			 "=D" (buf)					\ 			:"o" (bsh->bsh_bam.bs_read_region_##BWN),	\ 			 "b" (bsh),					\ 			 "0" (cnt),					\ 			 "1" (offset),					\ 			 "2" (buf)					\ 			:"memory");					\ }
end_define

begin_macro
name|_BUS_SPACE_READ_REGION
argument_list|(
argument|u_int8_t
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_READ_REGION
argument_list|(
argument|u_int16_t
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_READ_REGION
argument_list|(
argument|u_int32_t
argument_list|,
literal|4
argument_list|)
end_macro

begin_comment
comment|/*  * region write  */
end_comment

begin_define
define|#
directive|define
name|_BUS_SPACE_WRITE_REGION
parameter_list|(
name|TYPE
parameter_list|,
name|BWN
parameter_list|)
define|\
value|static __inline void							\ bus_space_write_region_##BWN (tag, bsh, offset, buf, cnt) 		\ 	bus_space_tag_t tag;						\ 	bus_space_handle_t bsh;						\ 	bus_size_t offset;						\ 	const TYPE *buf;						\ 	size_t cnt;							\ {									\ 									\ 	__asm __volatile("call *%3"					\ 			:"=c" (cnt),					\ 			 "=d" (offset),					\ 			 "=S" (buf)					\ 			:"o" (bsh->bsh_bam.bs_write_region_##BWN),	\ 			 "b" (bsh),					\ 			 "0" (cnt),					\ 			 "1" (offset),					\ 			 "2" (buf)					\ 			);						\ }
end_define

begin_macro
name|_BUS_SPACE_WRITE_REGION
argument_list|(
argument|u_int8_t
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_WRITE_REGION
argument_list|(
argument|u_int16_t
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_WRITE_REGION
argument_list|(
argument|u_int32_t
argument_list|,
literal|4
argument_list|)
end_macro

begin_comment
comment|/*  * multi set  */
end_comment

begin_define
define|#
directive|define
name|_BUS_SPACE_SET_MULTI
parameter_list|(
name|TYPE
parameter_list|,
name|BWN
parameter_list|)
define|\
value|static __inline void							\ bus_space_set_multi_##BWN (tag, bsh, offset, val, cnt)	 		\ 	bus_space_tag_t tag;						\ 	bus_space_handle_t bsh;						\ 	bus_size_t offset;						\ 	TYPE val;							\ 	size_t cnt;							\ {									\ 									\ 	__asm __volatile("call *%2"					\ 			:"=c" (cnt),					\ 			 "=d" (offset)					\ 			:"o" (bsh->bsh_bam.bs_set_multi_##BWN),		\ 			 "a" (val),					\ 			 "b" (bsh),					\ 			 "0" (cnt),					\ 			 "1" (offset)					\ 			);						\ }
end_define

begin_macro
name|_BUS_SPACE_SET_MULTI
argument_list|(
argument|u_int8_t
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_SET_MULTI
argument_list|(
argument|u_int16_t
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_SET_MULTI
argument_list|(
argument|u_int32_t
argument_list|,
literal|4
argument_list|)
end_macro

begin_comment
comment|/*  * region set  */
end_comment

begin_define
define|#
directive|define
name|_BUS_SPACE_SET_REGION
parameter_list|(
name|TYPE
parameter_list|,
name|BWN
parameter_list|)
define|\
value|static __inline void							\ bus_space_set_region_##BWN (tag, bsh, offset, val, cnt) 		\ 	bus_space_tag_t tag;						\ 	bus_space_handle_t bsh;						\ 	bus_size_t offset;						\ 	TYPE val;							\ 	size_t cnt;							\ {									\ 									\ 	__asm __volatile("call *%2"					\ 			:"=c" (cnt),					\ 			 "=d" (offset)					\ 			:"o" (bsh->bsh_bam.bs_set_region_##BWN),	\ 			 "a" (val),					\ 			 "b" (bsh),					\ 			 "0" (cnt),					\ 			 "1" (offset)					\ 			);						\ }
end_define

begin_macro
name|_BUS_SPACE_SET_REGION
argument_list|(
argument|u_int8_t
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_SET_REGION
argument_list|(
argument|u_int16_t
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_SET_REGION
argument_list|(
argument|u_int32_t
argument_list|,
literal|4
argument_list|)
end_macro

begin_comment
comment|/*  * copy  */
end_comment

begin_define
define|#
directive|define
name|_BUS_SPACE_COPY_REGION
parameter_list|(
name|BWN
parameter_list|)
define|\
value|static __inline void							\ bus_space_copy_region_##BWN (tag, sbsh, src, dbsh, dst, cnt)		\ 	bus_space_tag_t tag;						\ 	bus_space_handle_t sbsh;					\ 	bus_size_t src;							\ 	bus_space_handle_t dbsh;					\ 	bus_size_t dst;							\ 	size_t cnt;							\ {									\ 									\ 	if (dbsh->bsh_bam.bs_copy_region_1 != sbsh->bsh_bam.bs_copy_region_1) \ 		panic("bus_space_copy_region: funcs mismatch (ENOSUPPORT)");\ 									\ 	__asm __volatile("call *%3"					\ 			:"=c" (cnt),					\ 			 "=S" (src),					\ 			 "=D" (dst)					\ 			:"o" (dbsh->bsh_bam.bs_copy_region_##BWN),	\ 			 "a" (sbsh),					\ 			 "b" (dbsh),					\ 			 "0" (cnt),					\ 			 "1" (src),					\ 			 "2" (dst)					\ 			);						\ }
end_define

begin_macro
name|_BUS_SPACE_COPY_REGION
argument_list|(
literal|1
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_COPY_REGION
argument_list|(
literal|2
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_COPY_REGION
argument_list|(
literal|4
argument_list|)
end_macro

begin_comment
comment|/*  * Bus read/write barrier methods.  *  *	void bus_space_barrier(bus_space_tag_t tag, bus_space_handle_t bsh,  *			       bus_size_t offset, bus_size_t len, int flags);  *  *  * Note that BUS_SPACE_BARRIER_WRITE doesn't do anything other than  * prevent reordering by the compiler; all Intel x86 processors currently  * retire operations outside the CPU in program order.  */
end_comment

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

begin_function
specifier|static
name|__inline
name|void
name|bus_space_barrier
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
name|bus_size_t
name|len
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
if|if
condition|(
name|flags
operator|&
name|BUS_SPACE_BARRIER_READ
condition|)
asm|__asm __volatile("lock; addl $0,0(%%esp)" : : : "memory");
else|else
asm|__asm __volatile("" : : : "memory");
block|}
end_function

begin_if
if|#
directive|if
name|BUS_SPACE_NO_LEGACY
end_if

begin_undef
undef|#
directive|undef
name|inb
end_undef

begin_undef
undef|#
directive|undef
name|outb
end_undef

begin_define
define|#
directive|define
name|inb
parameter_list|(
name|a
parameter_list|)
value|compiler_error
end_define

begin_define
define|#
directive|define
name|inw
parameter_list|(
name|a
parameter_list|)
value|compiler_error
end_define

begin_define
define|#
directive|define
name|inl
parameter_list|(
name|a
parameter_list|)
value|compiler_error
end_define

begin_define
define|#
directive|define
name|outb
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|compiler_error
end_define

begin_define
define|#
directive|define
name|outw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|compiler_error
end_define

begin_define
define|#
directive|define
name|outl
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|compiler_error
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/bus_dma.h>
end_include

begin_comment
comment|/*  * Stream accesses are the same as normal accesses on i386/pc98; there are no  * supported bus systems with an endianess different from the host one.  */
end_comment

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
value|bus_space_read_1((t), (h), (o))
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
value|bus_space_read_2((t), (h), (o))
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
value|bus_space_read_4((t), (h), (o))
end_define

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
define|\
value|bus_space_read_multi_1((t), (h), (o), (a), (c))
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
define|\
value|bus_space_read_multi_2((t), (h), (o), (a), (c))
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
define|\
value|bus_space_read_multi_4((t), (h), (o), (a), (c))
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
define|\
value|bus_space_write_1((t), (h), (o), (v))
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
define|\
value|bus_space_write_2((t), (h), (o), (v))
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
define|\
value|bus_space_write_4((t), (h), (o), (v))
end_define

begin_define
define|#
directive|define
name|bus_space_write_multi_stream_1
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
value|bus_space_write_multi_1((t), (h), (o), (a), (c))
end_define

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
define|\
value|bus_space_write_multi_2((t), (h), (o), (a), (c))
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
define|\
value|bus_space_write_multi_4((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_multi_stream_1
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
value|bus_space_set_multi_1((t), (h), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_multi_stream_2
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
value|bus_space_set_multi_2((t), (h), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_multi_stream_4
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
value|bus_space_set_multi_4((t), (h), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_read_region_stream_1
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
value|bus_space_read_region_1((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_read_region_stream_2
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
value|bus_space_read_region_2((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_read_region_stream_4
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
value|bus_space_read_region_4((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_write_region_stream_1
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
value|bus_space_write_region_1((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_write_region_stream_2
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
value|bus_space_write_region_2((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_write_region_stream_4
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
value|bus_space_write_region_4((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_region_stream_1
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
value|bus_space_set_region_1((t), (h), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_region_stream_2
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
value|bus_space_set_region_2((t), (h), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_region_stream_4
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
value|bus_space_set_region_4((t), (h), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_copy_region_stream_1
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
value|bus_space_copy_region_1((t), (h1), (o1), (h2), (o2), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_copy_region_stream_2
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
value|bus_space_copy_region_2((t), (h1), (o1), (h2), (o2), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_copy_region_stream_4
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
value|bus_space_copy_region_4((t), (h1), (o1), (h2), (o2), (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PC98_BUS_H_ */
end_comment

end_unit

