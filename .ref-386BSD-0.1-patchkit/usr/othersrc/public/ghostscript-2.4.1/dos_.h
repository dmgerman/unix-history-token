begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* dos.h */
end_comment

begin_comment
comment|/* Generic DOS interface for Ghostscript */
end_comment

begin_comment
comment|/* This file is needed because the Borland and Watcom compilers */
end_comment

begin_comment
comment|/* provide slightly different procedures for interfacing to DOS and */
end_comment

begin_comment
comment|/* the I/O hardware, and because the Watcom compiler is 32-bit. */
end_comment

begin_include
include|#
directive|include
file|<dos.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__WATCOMC__
end_ifdef

begin_comment
comment|/* ---------------- Watcom compiler, 32-bit flat model. */
end_comment

begin_comment
comment|/* ---------------- inp/outp prototypes are in conio.h, not dos.h. */
end_comment

begin_include
include|#
directive|include
file|<conio.h>
end_include

begin_define
define|#
directive|define
name|inportb
parameter_list|(
name|px
parameter_list|)
value|inp(px)
end_define

begin_define
define|#
directive|define
name|outportb
parameter_list|(
name|px
parameter_list|,
name|b
parameter_list|)
value|outp(px,b)
end_define

begin_define
define|#
directive|define
name|enable
parameter_list|()
value|_enable()
end_define

begin_define
define|#
directive|define
name|disable
parameter_list|()
value|_disable()
end_define

begin_define
define|#
directive|define
name|MK_PTR
parameter_list|(
name|seg
parameter_list|,
name|off
parameter_list|)
value|(((seg)<< 4) + (off))
end_define

begin_define
define|#
directive|define
name|PTR_OFF
parameter_list|(
name|ptr
parameter_list|)
value|((unsigned)(ptr)& 0xffff)
end_define

begin_define
define|#
directive|define
name|int86
value|int386
end_define

begin_define
define|#
directive|define
name|int86x
value|int386x
end_define

begin_comment
comment|/* Fetch and discard a byte.  Prevent the compiler from */
end_comment

begin_comment
comment|/* optimizing this away. */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|byte_discard_
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|byte_discard
parameter_list|(
name|expr
parameter_list|)
value|byte_discard_ = (expr)
end_define

begin_comment
comment|/* Define the regs union tag for short registers. */
end_comment

begin_define
define|#
directive|define
name|rshort
value|w
end_define

begin_comment
comment|/* Define the structure and procedures for file enumeration. */
end_comment

begin_define
define|#
directive|define
name|ff_struct_t
value|struct find_t
end_define

begin_define
define|#
directive|define
name|ff_name
value|name
end_define

begin_define
define|#
directive|define
name|dos_findfirst
parameter_list|(
name|n
parameter_list|,
name|b
parameter_list|)
value|_dos_findfirst(n, _A_NORMAL | _A_RDONLY, b)
end_define

begin_define
define|#
directive|define
name|dos_findnext
parameter_list|(
name|b
parameter_list|)
value|_dos_findnext(b)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ---------------- Borland compiler, 16:16 pseudo-segmented model. */
end_comment

begin_comment
comment|/* ---------------- ffblk is in dir.h, not dos.h. */
end_comment

begin_include
include|#
directive|include
file|<dir.h>
end_include

begin_define
define|#
directive|define
name|MK_PTR
parameter_list|(
name|seg
parameter_list|,
name|off
parameter_list|)
value|MK_FP(seg,off)
end_define

begin_define
define|#
directive|define
name|PTR_OFF
parameter_list|(
name|ptr
parameter_list|)
value|FP_OFF(ptr)
end_define

begin_define
define|#
directive|define
name|PTR_SEG
parameter_list|(
name|ptr
parameter_list|)
value|FP_SEG(ptr)
end_define

begin_comment
comment|/* Fetch and discard a byte.  No special cleverness required. */
end_comment

begin_define
define|#
directive|define
name|byte_discard
parameter_list|(
name|expr
parameter_list|)
value|byte discard = (expr)
end_define

begin_comment
comment|/* Define the regs union tag for short registers. */
end_comment

begin_define
define|#
directive|define
name|rshort
value|x
end_define

begin_comment
comment|/* Define the structure and procedures for file enumeration. */
end_comment

begin_define
define|#
directive|define
name|ff_struct_t
value|struct ffblk
end_define

begin_define
define|#
directive|define
name|dos_findfirst
parameter_list|(
name|n
parameter_list|,
name|b
parameter_list|)
value|findfirst(n, b, 0)
end_define

begin_define
define|#
directive|define
name|dos_findnext
parameter_list|(
name|b
parameter_list|)
value|findnext(b)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

