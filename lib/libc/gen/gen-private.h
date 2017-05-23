begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GEN_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_GEN_PRIVATE_H_
end_define

begin_struct_decl
struct_decl|struct
name|_telldir
struct_decl|;
end_struct_decl

begin_comment
comment|/* see telldir.h */
end_comment

begin_struct_decl
struct_decl|struct
name|pthread_mutex
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Structure describing an open directory.  *  * NOTE. Change structure layout with care, at least dd_fd field has to  * remain unchanged to guarantee backward compatibility.  */
end_comment

begin_struct
struct|struct
name|_dirdesc
block|{
name|int
name|dd_fd
decl_stmt|;
comment|/* file descriptor associated with directory */
name|long
name|dd_loc
decl_stmt|;
comment|/* offset in current buffer */
name|long
name|dd_size
decl_stmt|;
comment|/* amount of data returned by getdirentries */
name|char
modifier|*
name|dd_buf
decl_stmt|;
comment|/* data buffer */
name|int
name|dd_len
decl_stmt|;
comment|/* size of data buffer */
name|off_t
name|dd_seek
decl_stmt|;
comment|/* magic cookie returned by getdirentries */
name|int
name|dd_flags
decl_stmt|;
comment|/* flags for readdir */
name|struct
name|pthread_mutex
modifier|*
name|dd_lock
decl_stmt|;
comment|/* lock */
name|struct
name|_telldir
modifier|*
name|dd_td
decl_stmt|;
comment|/* telldir position recording */
name|void
modifier|*
name|dd_compat_de
decl_stmt|;
comment|/* compat dirent */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_dirfd
parameter_list|(
name|dirp
parameter_list|)
value|((dirp)->dd_fd)
end_define

begin_struct_decl
struct_decl|struct
name|dirent
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|__readdir_r
parameter_list|(
name|DIR
modifier|*
name|dirp
parameter_list|,
name|struct
name|dirent
modifier|*
name|entry
parameter_list|,
name|struct
name|dirent
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_GEN_PRIVATE_H_ */
end_comment

end_unit

