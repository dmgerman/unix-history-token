begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ibcs2_dirent.h,v 1.2 1994/10/26 02:52:51 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994 Scott Bartram  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Scott Bartram.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IBCS2_DIRENT_H
end_ifndef

begin_define
define|#
directive|define
name|_IBCS2_DIRENT_H
value|1
end_define

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_types.h>
end_include

begin_define
define|#
directive|define
name|IBCS2_MAXNAMLEN
value|512
end_define

begin_define
define|#
directive|define
name|IBCS2_DIRBUF
value|1048
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|dd_fd
decl_stmt|;
name|int
name|dd_loc
decl_stmt|;
name|int
name|dd_size
decl_stmt|;
name|char
modifier|*
name|dd_buf
decl_stmt|;
block|}
name|IBCS2_DIR
typedef|;
end_typedef

begin_struct
struct|struct
name|ibcs2_dirent
block|{
name|ibcs2_ino_t
name|d_ino
decl_stmt|;
name|short
name|d_pad
decl_stmt|;
name|ibcs2_off_t
name|d_off
decl_stmt|;
name|u_short
name|d_reclen
decl_stmt|;
name|char
name|d_name
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IBCS2_DIRENT_H */
end_comment

end_unit

