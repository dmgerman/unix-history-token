begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ps.h	5.3 (Berkeley) 6/3/91  */
end_comment

begin_define
define|#
directive|define
name|UNLIMITED
value|0
end_define

begin_comment
comment|/* unlimited terminal width */
end_comment

begin_enum
enum|enum
name|type
block|{
name|CHAR
block|,
name|UCHAR
block|,
name|SHORT
block|,
name|USHORT
block|,
name|LONG
block|,
name|ULONG
block|,
name|KPTR
block|}
enum|;
end_enum

begin_struct
struct|struct
name|usave
block|{
name|struct
name|proc
modifier|*
name|u_procp
decl_stmt|;
name|struct
name|timeval
name|u_start
decl_stmt|;
name|struct
name|rusage
name|u_ru
decl_stmt|;
name|struct
name|rusage
name|u_cru
decl_stmt|;
name|char
name|u_acflag
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|_kinfo
block|{
name|struct
name|proc
modifier|*
name|ki_p
decl_stmt|;
comment|/* proc structure */
name|struct
name|eproc
modifier|*
name|ki_e
decl_stmt|;
comment|/* extra stuff */
name|struct
name|usave
modifier|*
name|ki_u
decl_stmt|;
comment|/* interesting parts of user */
name|char
modifier|*
name|ki_args
decl_stmt|;
comment|/* exec args (should be char **) */
name|char
modifier|*
name|ki_env
decl_stmt|;
comment|/* environment (should be char **) */
block|}
name|KINFO
typedef|;
end_typedef

begin_comment
comment|/* Variables. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_var
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name(s) of variable */
name|char
modifier|*
name|header
decl_stmt|;
comment|/* default header */
name|char
modifier|*
name|alias
decl_stmt|;
comment|/* aliases */
define|#
directive|define
name|COMM
value|0x01
comment|/* needs exec arguments and environment (XXX) */
define|#
directive|define
name|LJUST
value|0x02
comment|/* left adjust on output (trailing blanks) */
define|#
directive|define
name|USER
value|0x04
comment|/* needs user structure */
name|u_int
name|flag
decl_stmt|;
name|int
function_decl|(
modifier|*
name|oproc
function_decl|)
parameter_list|()
function_decl|;
comment|/* output routine */
name|short
name|width
decl_stmt|;
comment|/* printing width */
comment|/* 	 * The following (optional) elements are hooks for passing information 	 * to the generic output routines: pvar, evar, uvar (those which print 	 * simple elements from well known structures: proc, eproc, usave) 	 */
name|int
name|off
decl_stmt|;
comment|/* offset in structure */
name|enum
name|type
name|type
decl_stmt|;
comment|/* type of element */
name|char
modifier|*
name|fmt
decl_stmt|;
comment|/* printf format */
name|char
modifier|*
name|time
decl_stmt|;
comment|/* time format */
comment|/* 	 * glue to link selected fields together 	 */
block|}
name|VAR
typedef|;
end_typedef

begin_struct
struct|struct
name|varent
block|{
name|VAR
modifier|*
name|var
decl_stmt|;
name|struct
name|varent
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|"extern.h"
end_include

end_unit

