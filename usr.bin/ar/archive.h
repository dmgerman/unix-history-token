begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Hugh Smith at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)archive.h	8.3 (Berkeley) 4/2/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Ar(1) options. */
end_comment

begin_define
define|#
directive|define
name|AR_A
value|0x0001
end_define

begin_define
define|#
directive|define
name|AR_B
value|0x0002
end_define

begin_define
define|#
directive|define
name|AR_C
value|0x0004
end_define

begin_define
define|#
directive|define
name|AR_D
value|0x0008
end_define

begin_define
define|#
directive|define
name|AR_M
value|0x0010
end_define

begin_define
define|#
directive|define
name|AR_O
value|0x0020
end_define

begin_define
define|#
directive|define
name|AR_P
value|0x0040
end_define

begin_define
define|#
directive|define
name|AR_Q
value|0x0080
end_define

begin_define
define|#
directive|define
name|AR_R
value|0x0100
end_define

begin_define
define|#
directive|define
name|AR_T
value|0x0200
end_define

begin_define
define|#
directive|define
name|AR_TR
value|0x0400
end_define

begin_define
define|#
directive|define
name|AR_U
value|0x0800
end_define

begin_define
define|#
directive|define
name|AR_V
value|0x1000
end_define

begin_define
define|#
directive|define
name|AR_X
value|0x2000
end_define

begin_decl_stmt
specifier|extern
name|u_int
name|options
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set up file copy. */
end_comment

begin_define
define|#
directive|define
name|SETCF
parameter_list|(
name|from
parameter_list|,
name|fromname
parameter_list|,
name|to
parameter_list|,
name|toname
parameter_list|,
name|pad
parameter_list|)
value|{ \ 	cf.rfd = from; \ 	cf.rname = fromname; \ 	cf.wfd = to; \ 	cf.wname = toname; \ 	cf.flags = pad; \ }
end_define

begin_comment
comment|/* File copy structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|rfd
decl_stmt|;
comment|/* read file descriptor */
specifier|const
name|char
modifier|*
name|rname
decl_stmt|;
comment|/* read name */
name|int
name|wfd
decl_stmt|;
comment|/* write file descriptor */
specifier|const
name|char
modifier|*
name|wname
decl_stmt|;
comment|/* write name */
define|#
directive|define
name|NOPAD
value|0x00
comment|/* don't pad */
define|#
directive|define
name|RPAD
value|0x01
comment|/* pad on reads */
define|#
directive|define
name|WPAD
value|0x02
comment|/* pad on writes */
name|u_int
name|flags
decl_stmt|;
comment|/* pad flags */
block|}
name|CF
typedef|;
end_typedef

begin_comment
comment|/* Header structure internal format. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|off_t
name|size
decl_stmt|;
comment|/* size of the object in bytes */
name|time_t
name|date
decl_stmt|;
comment|/* date */
name|int
name|lname
decl_stmt|;
comment|/* size of the long name in bytes */
name|int
name|gid
decl_stmt|;
comment|/* group */
name|int
name|uid
decl_stmt|;
comment|/* owner */
name|u_short
name|mode
decl_stmt|;
comment|/* permissions */
name|char
name|name
index|[
name|MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name */
block|}
name|CHDR
typedef|;
end_typedef

begin_comment
comment|/* Header format strings. */
end_comment

begin_define
define|#
directive|define
name|HDR1
value|"%s%-13d%-12ld%-6u%-6u%-8o%-10qd%2s"
end_define

begin_define
define|#
directive|define
name|HDR2
value|"%-16.16s%-12ld%-6u%-6u%-8o%-10qd%2s"
end_define

begin_define
define|#
directive|define
name|OLDARMAXNAME
value|15
end_define

begin_define
define|#
directive|define
name|HDR3
value|"%-16.15s%-12ld%-6u%-6u%-8o%-10qd%2s"
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|close_archive
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copy_ar
parameter_list|(
name|CF
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_arobj
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|open_archive
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|put_arobj
parameter_list|(
name|CF
modifier|*
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|skip_arobj
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

