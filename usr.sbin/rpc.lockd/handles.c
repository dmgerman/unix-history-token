begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995  *	A.R. Gordon (andrew.gordon@net-tel.co.uk).  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the FreeBSD project  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY ANDREW GORDON AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id: handles.c,v 1.3 1997/10/13 11:10:49 charnier Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"nlm_prot.h"
end_include

begin_comment
comment|/* ------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*   * need to find all fds in use by a host and free them when host crashes   (need not be efficient)  * need to find fd corresponding to<inode, device>  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|fdinfo
block|{
name|int
name|fd
decl_stmt|;
comment|/* The file descriptor itself			*/
name|int
name|ref_count
decl_stmt|;
comment|/* Count of hosts using the fd - fd is 	*/
comment|/* closed when this reaches zero	*/
name|ino_t
name|inode_no
decl_stmt|;
comment|/* The inode number of this file.	*/
name|dev_t
name|device
decl_stmt|;
comment|/* device on which the file lives.	*/
name|struct
name|fdinfo
modifier|*
name|next
decl_stmt|;
comment|/* Chain of FdInfo structures		*/
name|struct
name|fdinfo
modifier|*
name|prev
decl_stmt|;
block|}
name|FdInfo
typedef|;
end_typedef

end_unit

