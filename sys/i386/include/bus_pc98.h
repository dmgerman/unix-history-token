begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NecBSD: busio.h,v 3.25.4.2.2.1 2000/06/12 03:53:08 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD: bus.h,v 1.12 1997/10/01 08:25:15 fvdl Exp $	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1997, 1998  *	NetBSD/pc98 porting staff. All rights reserved.  *  * [Ported for FreeBSD]  *  Copyright (c) 2001  *	TAKAHASHI Yoshihiro. All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997, 1998  *	Naofumi HONDA.  All rights reserved.  *  * This module support generic bus address relocation mechanism.  * To reduce a function call overhead, we employ pascal call methods.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_BUS_PC98_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_BUS_PC98_H_
end_define

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_comment
comment|/*  * Bus address and size types  */
end_comment

begin_typedef
typedef|typedef
name|u_int
name|bus_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int
name|bus_size_t
typedef|;
end_typedef

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
value|(64 * 1024)
end_define

begin_comment
comment|/* Maximum supported size */
end_comment

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

begin_define
define|#
directive|define
name|BUS_SPACE_IAT_MAXSIZE
value|32
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
comment|/*  * bus space tag  */
end_comment

begin_define
define|#
directive|define
name|_PASCAL_CALL
value|__P((void))
end_define

begin_define
define|#
directive|define
name|_BUS_SPACE_CALL_FUNCS_TAB
parameter_list|(
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|BWN
parameter_list|)
define|\
value|NAME##_space_read_##BWN##, 				\ 	NAME##_space_read_multi_##BWN##, 			\ 	NAME##_space_read_region_##BWN##,			\ 	NAME##_space_write_##BWN##, 				\ 	NAME##_space_write_multi_##BWN##, 			\ 	NAME##_space_write_region_##BWN##,			\ 	NAME##_space_set_multi_##BWN##,				\ 	NAME##_space_set_region_##BWN##,			\ 	NAME##_space_copy_region_##BWN
end_define

begin_define
define|#
directive|define
name|_BUS_SPACE_CALL_FUNCS_PROTO
parameter_list|(
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|BWN
parameter_list|)
define|\
value|TYPE NAME##_space_read_##BWN _PASCAL_CALL;		\ 	void NAME##_space_read_multi_##BWN _PASCAL_CALL;	\ 	void NAME##_space_read_region_##BWN _PASCAL_CALL;	\ 	void NAME##_space_write_##BWN _PASCAL_CALL;		\ 	void NAME##_space_write_multi_##BWN _PASCAL_CALL;	\ 	void NAME##_space_write_region_##BWN _PASCAL_CALL;	\ 	void NAME##_space_set_multi_##BWN _PASCAL_CALL;		\ 	void NAME##_space_set_region_##BWN _PASCAL_CALL;	\ 	void NAME##_space_copy_region_##BWN _PASCAL_CALL;
end_define

begin_define
define|#
directive|define
name|_BUS_SPACE_CALL_FUNCS
parameter_list|(
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|BWN
parameter_list|)
define|\
value|TYPE (*##NAME##_read_##BWN) _PASCAL_CALL;		\ 	void (*##NAME##_read_multi_##BWN) _PASCAL_CALL;		\ 	void (*##NAME##_read_region_##BWN) _PASCAL_CALL;	\ 	void (*##NAME##_write_##BWN) _PASCAL_CALL;		\ 	void (*##NAME##_write_multi_##BWN) _PASCAL_CALL;	\ 	void (*##NAME##_write_region_##BWN) _PASCAL_CALL;	\ 	void (*##NAME##_set_multi_##BWN) _PASCAL_CALL;		\ 	void (*##NAME##_set_region_##BWN) _PASCAL_CALL;		\ 	void (*##NAME##_copy_region_##BWN) _PASCAL_CALL;
end_define

begin_struct
struct|struct
name|bus_space_access_methods
block|{
comment|/* 8 bits access methods */
name|_BUS_SPACE_CALL_FUNCS
argument_list|(
argument|bs
argument_list|,
argument|u_int8_t
argument_list|,
literal|1
argument_list|)
comment|/* 16 bits access methods */
name|_BUS_SPACE_CALL_FUNCS
argument_list|(
argument|bs
argument_list|,
argument|u_int16_t
argument_list|,
literal|2
argument_list|)
comment|/* 32 bits access methods */
name|_BUS_SPACE_CALL_FUNCS
argument_list|(
argument|bs
argument_list|,
argument|u_int32_t
argument_list|,
literal|4
argument_list|)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bus_space_tag
block|{
define|#
directive|define
name|BUS_SPACE_IO
value|0
define|#
directive|define
name|BUS_SPACE_MEM
value|1
name|u_int
name|bs_tag
decl_stmt|;
comment|/* bus space flags */
name|struct
name|bus_space_access_methods
name|bs_da
decl_stmt|;
comment|/* direct access */
name|struct
name|bus_space_access_methods
name|bs_ra
decl_stmt|;
comment|/* relocate access */
if|#
directive|if
literal|0
block|struct bus_space_access_methods bs_ida;
comment|/* indexed direct access */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bus_space_tag
modifier|*
name|bus_space_tag_t
typedef|;
end_typedef

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
comment|/*  * bus space handle  */
end_comment

begin_struct
struct|struct
name|bus_space_handle
block|{
name|bus_addr_t
name|bsh_base
decl_stmt|;
name|size_t
name|bsh_sz
decl_stmt|;
name|bus_addr_t
name|bsh_iat
index|[
name|BUS_SPACE_IAT_MAXSIZE
index|]
decl_stmt|;
name|size_t
name|bsh_maxiatsz
decl_stmt|;
name|size_t
name|bsh_iatsz
decl_stmt|;
name|struct
name|resource
modifier|*
modifier|*
name|bsh_res
decl_stmt|;
name|size_t
name|bsh_ressz
decl_stmt|;
name|struct
name|bus_space_access_methods
name|bsh_bam
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bus_space_handle
modifier|*
name|bus_space_handle_t
typedef|;
end_typedef

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
value|static __inline TYPE bus_space_read_##BWN 			\ 	__P((bus_space_tag_t, bus_space_handle_t, bus_size_t offset));	\ 	static __inline void bus_space_read_multi_##BWN			\ 	__P((bus_space_tag_t, bus_space_handle_t,			\ 	     bus_size_t, TYPE *, size_t));				\ 	static __inline void bus_space_read_region_##BWN		\ 	__P((bus_space_tag_t, bus_space_handle_t,			\ 	     bus_size_t, TYPE *, size_t));				\ 	static __inline void bus_space_write_##BWN			\ 	__P((bus_space_tag_t, bus_space_handle_t, bus_size_t, TYPE));	\ 	static __inline void bus_space_write_multi_##BWN		\ 	__P((bus_space_tag_t, bus_space_handle_t,			\ 	     bus_size_t, const TYPE *, size_t));			\ 	static __inline void bus_space_write_region_##BWN		\ 	__P((bus_space_tag_t, bus_space_handle_t,			\ 	     bus_size_t, const TYPE *, size_t));			\ 	static __inline void bus_space_set_multi_##BWN			\ 	__P((bus_space_tag_t, bus_space_handle_t, bus_size_t, TYPE, size_t));\ 	static __inline void bus_space_set_region_##BWN			\ 	__P((bus_space_tag_t, bus_space_handle_t, bus_size_t, TYPE, size_t));\ 	static __inline void bus_space_copy_region_##BWN		\ 	__P((bus_space_tag_t, bus_space_handle_t, bus_size_t,		\ 	     bus_space_handle_t, bus_size_t, size_t));
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
value|static __inline TYPE						\ bus_space_read_##BWN##(tag, bsh, offset)			\ 	bus_space_tag_t tag;					\ 	bus_space_handle_t bsh;					\ 	bus_size_t offset;					\ {								\ 	register TYPE result;					\ 								\ 	__asm __volatile("call *%2"  				\ 			:"=a" (result),				\ 			 "=d" (offset)				\ 			:"o" (bsh->bsh_bam.bs_read_##BWN),	\ 			 "b" (bsh),				\ 			 "1" (offset)				\ 			);					\ 								\ 	return result;						\ }
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
value|static __inline void						\ bus_space_write_##BWN##(tag, bsh, offset, val)			\ 	bus_space_tag_t tag;					\ 	bus_space_handle_t bsh;					\ 	bus_size_t offset;					\ 	TYPE val;						\ {								\ 								\ 	__asm __volatile("call *%1"				\ 			:"=d" (offset)				\ 			:"o" (bsh->bsh_bam.bs_write_##BWN),	\ 			 "a" (val),				\ 			 "b" (bsh),				\ 			 "0" (offset)				\ 			);					\ }
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
value|static __inline void							\ bus_space_read_multi_##BWN##(tag, bsh, offset, buf, cnt) 		\ 	bus_space_tag_t tag;						\ 	bus_space_handle_t bsh;						\ 	bus_size_t offset;						\ 	TYPE *buf;							\ 	size_t cnt;							\ {									\ 									\ 	__asm __volatile("call *%3"					\ 			:"=c" (cnt),					\ 			 "=d" (offset),					\ 			 "=D" (buf)					\ 			:"o" (bsh->bsh_bam.bs_read_multi_##BWN),	\ 			 "b" (bsh),					\ 			 "0" (cnt),					\ 			 "1" (offset),					\ 			 "2" (buf)					\ 			:"memory");					\ }
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
value|static __inline void							\ bus_space_write_multi_##BWN##(tag, bsh, offset, buf, cnt) 		\ 	bus_space_tag_t tag;						\ 	bus_space_handle_t bsh;						\ 	bus_size_t offset;						\ 	const TYPE *buf;						\ 	size_t cnt;							\ {									\ 									\ 	__asm __volatile("call *%3"					\ 			:"=c" (cnt),					\ 			 "=d" (offset),					\ 			 "=S" (buf)					\ 			:"o" (bsh->bsh_bam.bs_write_multi_##BWN),	\ 			 "b" (bsh),					\ 			 "0" (cnt),					\ 			 "1" (offset),					\ 			 "2" (buf)					\ 			);						\ }
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
value|static __inline void							\ bus_space_read_region_##BWN##(tag, bsh, offset, buf, cnt) 		\ 	bus_space_tag_t tag;						\ 	bus_space_handle_t bsh;						\ 	bus_size_t offset;						\ 	TYPE *buf;						\ 	size_t cnt;							\ {									\ 									\ 	__asm __volatile("call *%3"					\ 			:"=c" (cnt),					\ 			 "=d" (offset),					\ 			 "=D" (buf)					\ 			:"o" (bsh->bsh_bam.bs_read_region_##BWN),	\ 			 "b" (bsh),					\ 			 "0" (cnt),					\ 			 "1" (offset),					\ 			 "2" (buf)					\ 			:"memory");					\ }
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
value|static __inline void							\ bus_space_write_region_##BWN##(tag, bsh, offset, buf, cnt) 		\ 	bus_space_tag_t tag;						\ 	bus_space_handle_t bsh;						\ 	bus_size_t offset;						\ 	const TYPE *buf;						\ 	size_t cnt;							\ {									\ 									\ 	__asm __volatile("call *%3"					\ 			:"=c" (cnt),					\ 			 "=d" (offset),					\ 			 "=S" (buf)					\ 			:"o" (bsh->bsh_bam.bs_write_region_##BWN),	\ 			 "b" (bsh),					\ 			 "0" (cnt),					\ 			 "1" (offset),					\ 			 "2" (buf)					\ 			);						\ }
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
value|static __inline void							\ bus_space_set_multi_##BWN##(tag, bsh, offset, val, cnt) 		\ 	bus_space_tag_t tag;						\ 	bus_space_handle_t bsh;						\ 	bus_size_t offset;						\ 	TYPE val;							\ 	size_t cnt;							\ {									\ 									\ 	__asm __volatile("call *%2"					\ 			:"=c" (cnt),					\ 			 "=d" (offset)					\ 			:"o" (bsh->bsh_bam.bs_set_multi_##BWN),		\ 			 "a" (val),					\ 			 "b" (bsh),					\ 			 "0" (cnt),					\ 			 "1" (offset)					\ 			);						\ }
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
value|static __inline void							\ bus_space_set_region_##BWN##(tag, bsh, offset, val, cnt) 		\ 	bus_space_tag_t tag;						\ 	bus_space_handle_t bsh;						\ 	bus_size_t offset;						\ 	TYPE val;							\ 	size_t cnt;							\ {									\ 									\ 	__asm __volatile("call *%2"					\ 			:"=c" (cnt),					\ 			 "=d" (offset)					\ 			:"o" (bsh->bsh_bam.bs_set_region_##BWN),	\ 			 "a" (val),					\ 			 "b" (bsh),					\ 			 "0" (cnt),					\ 			 "1" (offset)					\ 			);						\ }
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
value|static __inline void							\ bus_space_copy_region_##BWN##(tag, sbsh, src, dbsh, dst, cnt)		\ 	bus_space_tag_t tag;						\ 	bus_space_handle_t sbsh;					\ 	bus_size_t src;							\ 	bus_space_handle_t dbsh;					\ 	bus_size_t dst;							\ 	size_t cnt;							\ {									\ 									\ 	if (dbsh->bsh_bam.bs_copy_region_1 != sbsh->bsh_bam.bs_copy_region_1) \ 		panic("bus_space_copy_region: funcs mismatch (ENOSUPPORT)");\ 									\ 	__asm __volatile("call *%3"					\ 			:"=c" (cnt),					\ 			 "=S" (src),					\ 			 "=D" (dst)					\ 			:"o" (dbsh->bsh_bam.bs_copy_region_##BWN),	\ 			 "a" (sbsh),					\ 			 "b" (dbsh),					\ 			 "0" (cnt),					\ 			 "1" (src),					\ 			 "2" (dst)					\ 			);						\ }
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_BUS_PC98_H_ */
end_comment

end_unit

