begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) UNIX System Laboratories, Inc.  All or some portions  * of this file are derived from material licensed to the  * University of California by American Telephone and Telegraph Co.  * or UNIX System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  *	$Id$  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nlist.h	5.6 (Berkeley) 4/4/91  */
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
comment|/*  * Symbol table entry format.  The #ifdef's are so that programs including  * nlist.h can initialize nlist structures statically.  */
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
define|#
directive|define
name|N_UNDF
value|0x00
comment|/* undefined */
define|#
directive|define
name|N_ABS
value|0x02
comment|/* absolute address */
define|#
directive|define
name|N_TEXT
value|0x04
comment|/* text segment */
define|#
directive|define
name|N_DATA
value|0x06
comment|/* data segment */
define|#
directive|define
name|N_BSS
value|0x08
comment|/* bss segment */
define|#
directive|define
name|N_INDR
value|0x0a
comment|/* indirect reference */
define|#
directive|define
name|N_COMM
value|0x12
comment|/* common reference */
define|#
directive|define
name|N_SETA
value|0x14
comment|/* absolute set element symbol */
define|#
directive|define
name|N_SETT
value|0x16
comment|/* text set element symbol */
define|#
directive|define
name|N_SETD
value|0x18
comment|/* data set element symbol */
define|#
directive|define
name|N_SETB
value|0x1a
comment|/* bss set element symbol */
define|#
directive|define
name|N_SETV
value|0x1c
comment|/* pointer to set vector in data area */
define|#
directive|define
name|N_FN
value|0x1e
comment|/* file name */
define|#
directive|define
name|N_EXT
value|0x01
comment|/* external (global) bit, OR'ed in */
define|#
directive|define
name|N_TYPE
value|0x1e
comment|/* mask for all the type bits */
name|unsigned
name|char
name|n_type
decl_stmt|;
comment|/* type defines */
name|char
name|n_other
decl_stmt|;
comment|/* spare */
define|#
directive|define
name|n_hash
value|n_desc
comment|/* used internally by ld(1); XXX */
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
name|N_FORMAT
value|"%08x"
end_define

begin_comment
comment|/* namelist value format; XXX */
end_comment

begin_define
define|#
directive|define
name|N_STAB
value|0x0e0
end_define

begin_comment
comment|/* mask for debugger symbols -- stab(5) */
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

