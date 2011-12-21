begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2009 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBARCHIVE_BUILD
end_ifndef

begin_error
error|#
directive|error
error|This header is only to be used internally to libarchive.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_READ_DISK_PRIVATE_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_READ_DISK_PRIVATE_H_INCLUDED
end_define

begin_struct
struct|struct
name|archive_read_disk
block|{
name|struct
name|archive
name|archive
decl_stmt|;
comment|/* 	 * Symlink mode is one of 'L'ogical, 'P'hysical, or 'H'ybrid, 	 * following an old BSD convention.  'L' follows all symlinks, 	 * 'P' follows none, 'H' follows symlinks only for the first 	 * item. 	 */
name|char
name|symlink_mode
decl_stmt|;
comment|/* 	 * Since symlink interaction changes, we need to track whether 	 * we're following symlinks for the current item.  'L' mode above 	 * sets this true, 'P' sets it false, 'H' changes it as we traverse. 	 */
name|char
name|follow_symlinks
decl_stmt|;
comment|/* Either 'L' or 'P'. */
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|lookup_gname
function_decl|)
parameter_list|(
name|void
modifier|*
name|private
parameter_list|,
name|gid_t
name|gid
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cleanup_gname
function_decl|)
parameter_list|(
name|void
modifier|*
name|private
parameter_list|)
function_decl|;
name|void
modifier|*
name|lookup_gname_data
decl_stmt|;
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|lookup_uname
function_decl|)
parameter_list|(
name|void
modifier|*
name|private
parameter_list|,
name|gid_t
name|gid
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cleanup_uname
function_decl|)
parameter_list|(
name|void
modifier|*
name|private
parameter_list|)
function_decl|;
name|void
modifier|*
name|lookup_uname_data
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

