begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)hexdump.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_pr
block|{
name|struct
name|_pr
modifier|*
name|nextpr
decl_stmt|;
comment|/* next print unit */
define|#
directive|define
name|F_ADDRESS
value|0x001
comment|/* print offset */
define|#
directive|define
name|F_BPAD
value|0x002
comment|/* blank pad */
define|#
directive|define
name|F_C
value|0x004
comment|/* %_c */
define|#
directive|define
name|F_CHAR
value|0x008
comment|/* %c */
define|#
directive|define
name|F_DBL
value|0x010
comment|/* %[EefGf] */
define|#
directive|define
name|F_INT
value|0x020
comment|/* %[di] */
define|#
directive|define
name|F_P
value|0x040
comment|/* %_p */
define|#
directive|define
name|F_STR
value|0x080
comment|/* %s */
define|#
directive|define
name|F_U
value|0x100
comment|/* %_u */
define|#
directive|define
name|F_UINT
value|0x200
comment|/* %[ouXx] */
define|#
directive|define
name|F_TEXT
value|0x400
comment|/* no conversions */
name|u_int
name|flags
decl_stmt|;
comment|/* flag values */
name|int
name|bcnt
decl_stmt|;
comment|/* byte count */
name|char
modifier|*
name|cchar
decl_stmt|;
comment|/* conversion character */
name|char
modifier|*
name|fmt
decl_stmt|;
comment|/* printf format */
name|char
modifier|*
name|nospace
decl_stmt|;
comment|/* no whitespace version */
block|}
name|PR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_fu
block|{
name|struct
name|_fu
modifier|*
name|nextfu
decl_stmt|;
comment|/* next format unit */
name|struct
name|_pr
modifier|*
name|nextpr
decl_stmt|;
comment|/* next print unit */
define|#
directive|define
name|F_IGNORE
value|0x01
comment|/* %_A */
define|#
directive|define
name|F_SETREP
value|0x02
comment|/* rep count set, not default */
name|u_int
name|flags
decl_stmt|;
comment|/* flag values */
name|int
name|reps
decl_stmt|;
comment|/* repetition count */
name|int
name|bcnt
decl_stmt|;
comment|/* byte count */
name|char
modifier|*
name|fmt
decl_stmt|;
comment|/* format string */
block|}
name|FU
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_fs
block|{
comment|/* format strings */
name|struct
name|_fs
modifier|*
name|nextfs
decl_stmt|;
comment|/* linked list of format strings */
name|struct
name|_fu
modifier|*
name|nextfu
decl_stmt|;
comment|/* linked list of format units */
name|int
name|bcnt
decl_stmt|;
block|}
name|FS
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|FS
modifier|*
name|fshead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of format strings list */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|blocksize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* data block size */
end_comment

begin_enum
enum|enum
name|_vflag
block|{
name|ALL
block|,
name|DUP
block|,
name|FIRST
block|,
name|WAIT
block|}
enum|;
end_enum

begin_comment
comment|/* -v values */
end_comment

begin_function_decl
name|void
name|add
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addfile
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|badcnt
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|badconv
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|badfmt
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|badsfmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bpad
parameter_list|(
name|PR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|conv_c
parameter_list|(
name|PR
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|conv_u
parameter_list|(
name|PR
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|doskip
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|escape
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_char
modifier|*
name|get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|newsyntax
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|next
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nomem
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oldsyntax
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rewrite
parameter_list|(
name|FS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|size
parameter_list|(
name|FS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

