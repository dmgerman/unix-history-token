begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Michael Fischbein.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)ls.h	8.1 (Berkeley) 5/31/93  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|NO_PRINT
value|1
end_define

begin_decl_stmt
specifier|extern
name|long
name|blocksize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* block size units */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_accesstime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use time of last access */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show flags associated with a file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_humanval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show human-readable file sizes */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_inode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print inode */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_longform
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* long listing format */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_octal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print unprintables in octal */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_octal_escape
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* like f_octal but use C escapes if possible */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_nonprint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show unprintables as ? */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_sectime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print the real time for all files */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list size in short listing */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_statustime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use time of last mode change */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_notabs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't use tab-separated multi-col output */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* add type character for non-regular files */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COLORLS
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|f_color
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* add type in color for non-regular files */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|FTSENT
modifier|*
name|list
decl_stmt|;
name|u_long
name|btotal
decl_stmt|;
name|int
name|bcfile
decl_stmt|;
name|int
name|entries
decl_stmt|;
name|int
name|maxlen
decl_stmt|;
name|u_int
name|s_block
decl_stmt|;
name|u_int
name|s_flags
decl_stmt|;
name|u_int
name|s_group
decl_stmt|;
name|u_int
name|s_inode
decl_stmt|;
name|u_int
name|s_nlink
decl_stmt|;
name|u_int
name|s_size
decl_stmt|;
name|u_int
name|s_user
decl_stmt|;
block|}
name|DISPLAY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|user
decl_stmt|;
name|char
modifier|*
name|group
decl_stmt|;
name|char
modifier|*
name|flags
decl_stmt|;
name|char
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|NAMES
typedef|;
end_typedef

end_unit

