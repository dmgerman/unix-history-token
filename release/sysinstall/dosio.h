begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996 Robert Nordier  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOSIO_H
end_ifndef

begin_define
define|#
directive|define
name|DOSIO_H
end_define

begin_comment
comment|/*   * DOS file attributes  */
end_comment

begin_define
define|#
directive|define
name|FA_RDONLY
value|0x01
end_define

begin_comment
comment|/* read-only */
end_comment

begin_define
define|#
directive|define
name|FA_HIDDEN
value|0x02
end_define

begin_comment
comment|/* hidden file */
end_comment

begin_define
define|#
directive|define
name|FA_SYSTEM
value|0x04
end_define

begin_comment
comment|/* system file */
end_comment

begin_define
define|#
directive|define
name|FA_LABEL
value|0x08
end_define

begin_comment
comment|/* volume label */
end_comment

begin_define
define|#
directive|define
name|FA_DIR
value|0x10
end_define

begin_comment
comment|/* directory */
end_comment

begin_define
define|#
directive|define
name|FA_ARCH
value|0x20
end_define

begin_comment
comment|/* archive (file modified) */
end_comment

begin_comment
comment|/*   * Error number to overload if filesystem errors are detected during  * routine processing  */
end_comment

begin_define
define|#
directive|define
name|EBADFS
value|EINVAL
end_define

begin_comment
comment|/*  * Macros to convert DOS-format 16-bit and 32-bit quantities  */
end_comment

begin_define
define|#
directive|define
name|cv2
parameter_list|(
name|p
parameter_list|)
value|((u_short)(p)[0] |         \                ((u_short)(p)[1]<< 010))
end_define

begin_define
define|#
directive|define
name|cv4
parameter_list|(
name|p
parameter_list|)
value|((u_long)(p)[0] |          \                ((u_long)(p)[1]<< 010) |  \                ((u_long)(p)[2]<< 020) |  \                ((u_long)(p)[3]<< 030))
end_define

begin_comment
comment|/*  * DOS directory structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|name
index|[
literal|8
index|]
decl_stmt|;
comment|/* name */
name|u_char
name|ext
index|[
literal|3
index|]
decl_stmt|;
comment|/* extension */
name|u_char
name|attr
decl_stmt|;
comment|/* attributes */
name|u_char
name|reserved
index|[
literal|10
index|]
decl_stmt|;
comment|/* reserved */
name|u_char
name|time
index|[
literal|2
index|]
decl_stmt|;
comment|/* time */
name|u_char
name|date
index|[
literal|2
index|]
decl_stmt|;
comment|/* date */
name|u_char
name|clus
index|[
literal|2
index|]
decl_stmt|;
comment|/* starting cluster */
name|u_char
name|size
index|[
literal|4
index|]
decl_stmt|;
comment|/* file size */
block|}
name|DOS_DE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
modifier|*
name|fat
decl_stmt|;
comment|/* FAT */
name|u_long
name|volid
decl_stmt|;
comment|/* volume id */
name|u_long
name|lsnfat
decl_stmt|;
comment|/* logical sector number: fat */
name|u_long
name|lsndir
decl_stmt|;
comment|/* logical sector number: dir */
name|u_long
name|lsndta
decl_stmt|;
comment|/* logical sector number: data area */
name|short
name|fd
decl_stmt|;
comment|/* file descriptor */
name|short
name|fat12
decl_stmt|;
comment|/* 12-bit FAT entries */
name|u_short
name|spf
decl_stmt|;
comment|/* sectors per fat */
name|u_short
name|dirents
decl_stmt|;
comment|/* root directory entries */
name|u_short
name|spc
decl_stmt|;
comment|/* sectors per cluster */
name|u_short
name|xclus
decl_stmt|;
comment|/* maximum cluster number */
name|u_short
name|bsize
decl_stmt|;
comment|/* cluster size in bytes */
name|u_short
name|bshift
decl_stmt|;
comment|/* cluster conversion shift */
name|u_short
name|links
decl_stmt|;
comment|/* active links to structure */
block|}
name|DOS_FS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|DOS_FS
modifier|*
name|fs
decl_stmt|;
comment|/* associated filesystem */
name|DOS_DE
name|de
decl_stmt|;
comment|/* directory entry */
name|u_long
name|offset
decl_stmt|;
comment|/* current offset */
name|u_short
name|c
decl_stmt|;
comment|/* last cluster read */
block|}
name|DOS_FILE
typedef|;
end_typedef

begin_comment
comment|/*  * The following variable can be set to the address of an error-handling  * routine which will be invoked when a read() returns EIO.  The handler  * should return 1 to retry the read, otherwise 0.  */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|dos_ioerr
function_decl|)
parameter_list|(
name|int
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dos_mount
parameter_list|(
name|DOS_FS
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|devname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dos_unmount
parameter_list|(
name|DOS_FS
modifier|*
name|fs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|dos_free
parameter_list|(
name|DOS_FS
modifier|*
name|fs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|dos_open
parameter_list|(
name|DOS_FS
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dos_close
parameter_list|(
name|void
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|fpos_t
name|dos_seek
parameter_list|(
name|void
modifier|*
name|v
parameter_list|,
name|fpos_t
name|offset
parameter_list|,
name|int
name|whence
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dos_read
parameter_list|(
name|void
modifier|*
name|v
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dos_stat
parameter_list|(
name|DOS_FS
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|struct
name|stat
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dos_fstat
parameter_list|(
name|DOS_FILE
modifier|*
name|f
parameter_list|,
name|struct
name|stat
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dos_cvtime
parameter_list|(
name|time_t
modifier|*
name|timer
parameter_list|,
name|u_short
name|ddate
parameter_list|,
name|u_short
name|dtime
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !DOSIO_H */
end_comment

end_unit

