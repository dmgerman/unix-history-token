begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ps.h	8.1 (Berkeley) 5/31/93  * $FreeBSD$  */
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
name|INT
block|,
name|UINT
block|,
name|LONG
block|,
name|ULONG
block|,
name|KPTR
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|kinfo
block|{
name|struct
name|kinfo_proc
modifier|*
name|ki_p
decl_stmt|;
comment|/* kinfo_proc structure */
name|char
modifier|*
name|ki_args
decl_stmt|;
comment|/* exec args */
name|char
modifier|*
name|ki_env
decl_stmt|;
comment|/* environment */
name|int
name|ki_valid
decl_stmt|;
comment|/* 1 => uarea stuff valid */
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
name|varent
block|{
name|struct
name|varent
modifier|*
name|next
decl_stmt|;
name|struct
name|var
modifier|*
name|var
decl_stmt|;
block|}
name|VARENT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|var
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
define|#
directive|define
name|DSIZ
value|0x08
comment|/* field size is dynamic*/
name|u_int
name|flag
decl_stmt|;
comment|/* output routine */
name|void
function_decl|(
modifier|*
name|oproc
function_decl|)
parameter_list|(
name|struct
name|kinfo
modifier|*
parameter_list|,
name|struct
name|varent
modifier|*
parameter_list|)
function_decl|;
comment|/* sizing routine*/
name|int
function_decl|(
modifier|*
name|sproc
function_decl|)
parameter_list|(
name|struct
name|kinfo
modifier|*
parameter_list|)
function_decl|;
name|short
name|width
decl_stmt|;
comment|/* printing width */
comment|/* 	 * The following (optional) elements are hooks for passing information 	 * to the generic output routine pvar (which prints simple elements 	 * from the well known kinfo_proc structure). 	 */
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
name|short
name|dwidth
decl_stmt|;
comment|/* dynamic printing width */
comment|/* 	 * glue to link selected fields together 	 */
block|}
name|VAR
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"extern.h"
end_include

end_unit

