begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: sort.h,v 1.11 2001/01/19 10:14:31 jdolecek Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Peter McIlroy.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)sort.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|NBINS
value|256
end_define

begin_define
define|#
directive|define
name|MAXMERGE
value|16
end_define

begin_comment
comment|/* values for masks, weights, and other flags. */
end_comment

begin_define
define|#
directive|define
name|I
value|1
end_define

begin_comment
comment|/* mask out non-printable characters */
end_comment

begin_define
define|#
directive|define
name|D
value|2
end_define

begin_comment
comment|/* sort alphanumeric characters only */
end_comment

begin_define
define|#
directive|define
name|N
value|4
end_define

begin_comment
comment|/* Field is a number */
end_comment

begin_define
define|#
directive|define
name|F
value|8
end_define

begin_comment
comment|/* weight lower and upper case the same */
end_comment

begin_define
define|#
directive|define
name|R
value|16
end_define

begin_comment
comment|/* Field is reversed with respect to the global weight */
end_comment

begin_define
define|#
directive|define
name|BI
value|32
end_define

begin_comment
comment|/* ignore blanks in icol */
end_comment

begin_define
define|#
directive|define
name|BT
value|64
end_define

begin_comment
comment|/* ignore blanks in tcol */
end_comment

begin_comment
comment|/* masks for delimiters: blanks, fields, and termination. */
end_comment

begin_define
define|#
directive|define
name|BLANK
value|1
end_define

begin_comment
comment|/* ' ', '\t'; '\n' if -T is invoked */
end_comment

begin_define
define|#
directive|define
name|FLD_D
value|2
end_define

begin_comment
comment|/* ' ', '\t' default; from -t otherwise */
end_comment

begin_define
define|#
directive|define
name|REC_D_F
value|4
end_define

begin_comment
comment|/* '\n' default; from -T otherwise */
end_comment

begin_define
define|#
directive|define
name|ND
value|10
end_define

begin_comment
comment|/* limit on number of -k options. */
end_comment

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|FCLOSE
parameter_list|(
name|file
parameter_list|)
value|{							\ 	if (EOF == fclose(file))					\ 		err(2, "%p", file);					\ }
end_define

begin_define
define|#
directive|define
name|EWRITE
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|,
name|n
parameter_list|,
name|f
parameter_list|)
value|{					\ 	if (!fwrite(ptr, size, n, f))					\ 		 err(2, NULL);						\ }
end_define

begin_comment
comment|/* length of record is currently limited to maximum string length (size_t) */
end_comment

begin_typedef
typedef|typedef
name|size_t
name|length_t
typedef|;
end_typedef

begin_comment
comment|/* a record is a key/line pair starting at rec.data. It has a total length  * and an offset to the start of the line half of the pair.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|recheader
block|{
name|length_t
name|length
decl_stmt|;
name|length_t
name|offset
decl_stmt|;
name|u_char
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|RECHEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|trecheader
block|{
name|length_t
name|length
decl_stmt|;
name|length_t
name|offset
decl_stmt|;
block|}
name|TRECHEADER
typedef|;
end_typedef

begin_comment
comment|/* This is the column as seen by struct field.  It is used by enterfield.  * They are matched with corresponding coldescs during initialization.  */
end_comment

begin_struct
struct|struct
name|column
block|{
name|struct
name|coldesc
modifier|*
name|p
decl_stmt|;
name|int
name|num
decl_stmt|;
name|int
name|indent
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* a coldesc has a number and pointers to the beginning and end of the  * corresponding column in the current line.  This is determined in enterkey.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|coldesc
block|{
name|u_char
modifier|*
name|start
decl_stmt|;
name|u_char
modifier|*
name|end
decl_stmt|;
name|int
name|num
decl_stmt|;
block|}
name|COLDESC
typedef|;
end_typedef

begin_comment
comment|/* A field has an initial and final column; an omitted final column  * implies the end of the line.  Flags regulate omission of blanks and  * numerical sorts; mask determines which characters are ignored (from -i, -d);  * weights determines the sort weights of a character (from -f, -r).  */
end_comment

begin_struct
struct|struct
name|field
block|{
name|struct
name|column
name|icol
decl_stmt|;
name|struct
name|column
name|tcol
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
name|u_char
modifier|*
name|mask
decl_stmt|;
name|u_char
modifier|*
name|weights
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|filelist
block|{
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|names
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|get_func_t
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|filelist
modifier|*
parameter_list|,
name|int
parameter_list|,
name|RECHEADER
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|struct
name|field
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|put_func_t
function_decl|)
parameter_list|(
specifier|const
name|struct
name|recheader
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|PANIC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum depth of fsort before fmerge is called */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|ascii
index|[
name|NBINS
index|]
decl_stmt|,
name|Rascii
index|[
name|NBINS
index|]
decl_stmt|,
name|Ftable
index|[
name|NBINS
index|]
decl_stmt|,
name|RFtable
index|[
name|NBINS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|d_mask
index|[
name|NBINS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SINGL_FLD
decl_stmt|,
name|SEP_FLAG
decl_stmt|,
name|UNIQUE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|REC_D
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|tmpdir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|stable_sort
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|gweights
index|[
name|NBINS
index|]
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"extern.h"
end_include

end_unit

