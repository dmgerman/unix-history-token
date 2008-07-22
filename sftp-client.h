begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: sftp-client.h,v 1.14 2005/04/26 12:59:02 jmc Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001-2004 Damien Miller<djm@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* Client side of SSH2 filexfer protocol */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SFTP_CLIENT_H
end_ifndef

begin_define
define|#
directive|define
name|_SFTP_CLIENT_H
end_define

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
comment|/*  * Initialise a SSH filexfer connection. Returns NULL on error or  * a pointer to a initialized sftp_conn struct on success.  */
end_comment

begin_function_decl
name|struct
name|sftp_conn
modifier|*
name|do_init
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|sftp_proto_version
parameter_list|(
name|struct
name|sftp_conn
modifier|*
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
name|struct
name|sftp_conn
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|u_int
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
name|struct
name|sftp_conn
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|SFTP_DIRENT
modifier|*
modifier|*
modifier|*
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
name|struct
name|sftp_conn
modifier|*
parameter_list|,
name|char
modifier|*
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
name|struct
name|sftp_conn
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|Attrib
modifier|*
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
name|struct
name|sftp_conn
modifier|*
parameter_list|,
name|char
modifier|*
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
name|struct
name|sftp_conn
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
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
name|struct
name|sftp_conn
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
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
name|struct
name|sftp_conn
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|int
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
name|struct
name|sftp_conn
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|Attrib
modifier|*
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
name|struct
name|sftp_conn
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|Attrib
modifier|*
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
name|struct
name|sftp_conn
modifier|*
parameter_list|,
name|char
modifier|*
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
name|struct
name|sftp_conn
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
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
name|struct
name|sftp_conn
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
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
name|struct
name|sftp_conn
modifier|*
parameter_list|,
name|char
modifier|*
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
name|struct
name|sftp_conn
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
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
name|struct
name|sftp_conn
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

