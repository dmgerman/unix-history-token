begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: sftp-client.h,v 1.5 2001/04/05 10:42:52 markus Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Damien Miller.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* Client side of SSH2 filexfer protocol */
end_comment

begin_typedef
typedef|typedef
name|struct
name|SFTP_DIRENT
name|SFTP_DIRENT
typedef|;
end_typedef

begin_struct
struct|struct
name|SFTP_DIRENT
block|{
name|char
modifier|*
name|filename
decl_stmt|;
name|char
modifier|*
name|longname
decl_stmt|;
name|Attrib
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Initialiase a SSH filexfer connection. Returns -1 on error or  * protocol version on success.  */
end_comment

begin_function_decl
name|int
name|do_init
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Close file referred to by 'handle' */
end_comment

begin_function_decl
name|int
name|do_close
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|handle
parameter_list|,
name|u_int
name|handle_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* List contents of directory 'path' to stdout */
end_comment

begin_function_decl
name|int
name|do_ls
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read contents of 'path' to NULL-terminated array 'dir' */
end_comment

begin_function_decl
name|int
name|do_readdir
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|SFTP_DIRENT
modifier|*
modifier|*
modifier|*
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Frees a NULL-terminated array of SFTP_DIRENTs (eg. from do_readdir) */
end_comment

begin_function_decl
name|void
name|free_sftp_dirents
parameter_list|(
name|SFTP_DIRENT
modifier|*
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Delete file 'path' */
end_comment

begin_function_decl
name|int
name|do_rm
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create directory 'path' */
end_comment

begin_function_decl
name|int
name|do_mkdir
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|Attrib
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Remove directory 'path' */
end_comment

begin_function_decl
name|int
name|do_rmdir
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get file attributes of 'path' (follows symlinks) */
end_comment

begin_function_decl
name|Attrib
modifier|*
name|do_stat
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|int
name|quiet
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get file attributes of 'path' (does not follow symlinks) */
end_comment

begin_function_decl
name|Attrib
modifier|*
name|do_lstat
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|int
name|quiet
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get file attributes of open file 'handle' */
end_comment

begin_function_decl
name|Attrib
modifier|*
name|do_fstat
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|handle
parameter_list|,
name|u_int
name|handle_len
parameter_list|,
name|int
name|quiet
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set file attributes of 'path' */
end_comment

begin_function_decl
name|int
name|do_setstat
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|Attrib
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set file attributes of open file 'handle' */
end_comment

begin_function_decl
name|int
name|do_fsetstat
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|handle
parameter_list|,
name|u_int
name|handle_len
parameter_list|,
name|Attrib
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Canonicalise 'path' - caller must free result */
end_comment

begin_function_decl
name|char
modifier|*
name|do_realpath
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Rename 'oldpath' to 'newpath' */
end_comment

begin_function_decl
name|int
name|do_rename
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|oldpath
parameter_list|,
name|char
modifier|*
name|newpath
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Rename 'oldpath' to 'newpath' */
end_comment

begin_function_decl
name|int
name|do_symlink
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|oldpath
parameter_list|,
name|char
modifier|*
name|newpath
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return target of symlink 'path' - caller must free result */
end_comment

begin_function_decl
name|char
modifier|*
name|do_readlink
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX: add callbacks to do_download/do_upload so we can do progress meter */
end_comment

begin_comment
comment|/*  * Download 'remote_path' to 'local_path'. Preserve permissions and times  * if 'pflag' is set  */
end_comment

begin_function_decl
name|int
name|do_download
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|remote_path
parameter_list|,
name|char
modifier|*
name|local_path
parameter_list|,
name|int
name|pflag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Upload 'local_path' to 'remote_path'. Preserve permissions and times  * if 'pflag' is set  */
end_comment

begin_function_decl
name|int
name|do_upload
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|,
name|char
modifier|*
name|local_path
parameter_list|,
name|char
modifier|*
name|remote_path
parameter_list|,
name|int
name|pflag
parameter_list|)
function_decl|;
end_function_decl

end_unit

