begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nlist.h	8.2 (Berkeley) 1/21/94  *  *	$Id: nlist.h,v 1.5 1997/02/23 09:17:14 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NLIST_H_
end_ifndef

begin_define
define|#
directive|define
name|_NLIST_H_
end_define

begin_comment
comment|/*  * Symbol table entries in a.out files.  */
end_comment

begin_comment
comment|/*  * Layout of each symbol.  The "#ifdef _AOUT_INCLUDE_" is so that  * programs including nlist.h can initialize nlist structures  * statically.  */
end_comment

begin_struct
struct|struct
name|nlist
block|{
ifdef|#
directive|ifdef
name|_AOUT_INCLUDE_
union|union
block|{
name|char
modifier|*
name|n_name
decl_stmt|;
comment|/* symbol name (in memory) */
name|long
name|n_strx
decl_stmt|;
comment|/* file string table offset (on disk) */
block|}
name|n_un
union|;
else|#
directive|else
name|char
modifier|*
name|n_name
decl_stmt|;
comment|/* symbol name (in memory) */
endif|#
directive|endif
name|unsigned
name|char
name|n_type
decl_stmt|;
comment|/* type defines */
name|char
name|n_other
decl_stmt|;
comment|/* ".type" and binding information */
name|short
name|n_desc
decl_stmt|;
comment|/* used by stab entries */
name|unsigned
name|long
name|n_value
decl_stmt|;
comment|/* address/value of the symbol */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|n_hash
value|n_desc
end_define

begin_comment
comment|/* used internally by ld(1); XXX */
end_comment

begin_comment
comment|/*  * Defines for n_type.  */
end_comment

begin_define
define|#
directive|define
name|N_UNDF
value|0x00
end_define

begin_comment
comment|/* undefined */
end_comment

begin_define
define|#
directive|define
name|N_ABS
value|0x02
end_define

begin_comment
comment|/* absolute address */
end_comment

begin_define
define|#
directive|define
name|N_TEXT
value|0x04
end_define

begin_comment
comment|/* text segment */
end_comment

begin_define
define|#
directive|define
name|N_DATA
value|0x06
end_define

begin_comment
comment|/* data segment */
end_comment

begin_define
define|#
directive|define
name|N_BSS
value|0x08
end_define

begin_comment
comment|/* bss segment */
end_comment

begin_define
define|#
directive|define
name|N_INDR
value|0x0a
end_define

begin_comment
comment|/* alias definition */
end_comment

begin_define
define|#
directive|define
name|N_SIZE
value|0x0c
end_define

begin_comment
comment|/* pseudo type, defines a symbol's size */
end_comment

begin_define
define|#
directive|define
name|N_COMM
value|0x12
end_define

begin_comment
comment|/* common reference */
end_comment

begin_comment
comment|/* GNU extensions */
end_comment

begin_define
define|#
directive|define
name|N_SETA
value|0x14
end_define

begin_comment
comment|/* Absolute set element symbol */
end_comment

begin_define
define|#
directive|define
name|N_SETT
value|0x16
end_define

begin_comment
comment|/* Text set element symbol */
end_comment

begin_define
define|#
directive|define
name|N_SETD
value|0x18
end_define

begin_comment
comment|/* Data set element symbol */
end_comment

begin_define
define|#
directive|define
name|N_SETB
value|0x1a
end_define

begin_comment
comment|/* Bss set element symbol */
end_comment

begin_define
define|#
directive|define
name|N_SETV
value|0x1c
end_define

begin_comment
comment|/* Pointer to set vector in data area. */
end_comment

begin_comment
comment|/* end GNU extensions */
end_comment

begin_define
define|#
directive|define
name|N_FN
value|0x1e
end_define

begin_comment
comment|/* file name (N_EXT on) */
end_comment

begin_define
define|#
directive|define
name|N_WARN
value|0x1e
end_define

begin_comment
comment|/* warning message (N_EXT off) */
end_comment

begin_define
define|#
directive|define
name|N_EXT
value|0x01
end_define

begin_comment
comment|/* external (global) bit, OR'ed in */
end_comment

begin_define
define|#
directive|define
name|N_TYPE
value|0x1e
end_define

begin_comment
comment|/* mask for all the type bits */
end_comment

begin_define
define|#
directive|define
name|N_STAB
value|0xe0
end_define

begin_comment
comment|/* mask for debugger symbols -- stab(5) */
end_comment

begin_comment
comment|/*  * Defines for n_other.  It contains the ".type" (AUX) field in the least  * significant 4 bits, and the binding (for weak symbols) in the most  * significant 4 bits.  */
end_comment

begin_define
define|#
directive|define
name|N_AUX
parameter_list|(
name|p
parameter_list|)
value|((p)->n_other& 0xf)
end_define

begin_define
define|#
directive|define
name|N_BIND
parameter_list|(
name|p
parameter_list|)
value|(((unsigned int)(p)->n_other>> 4)& 0xf)
end_define

begin_define
define|#
directive|define
name|N_OTHER
parameter_list|(
name|r
parameter_list|,
name|v
parameter_list|)
value|(((unsigned int)(r)<< 4) | ((v)& 0xf))
end_define

begin_define
define|#
directive|define
name|AUX_OBJECT
value|1
end_define

begin_comment
comment|/* data object */
end_comment

begin_define
define|#
directive|define
name|AUX_FUNC
value|2
end_define

begin_comment
comment|/* function */
end_comment

begin_comment
comment|/*#define BIND_LOCAL	0	not used */
end_comment

begin_comment
comment|/*#define BIND_GLOBAL	1	not used */
end_comment

begin_define
define|#
directive|define
name|BIND_WEAK
value|2
end_define

begin_comment
comment|/* weak binding */
end_comment

begin_define
define|#
directive|define
name|N_FORMAT
value|"%08x"
end_define

begin_comment
comment|/* namelist value format; XXX */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|nlist
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
expr|struct
name|nlist
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NLIST_H_ */
end_comment

end_unit

