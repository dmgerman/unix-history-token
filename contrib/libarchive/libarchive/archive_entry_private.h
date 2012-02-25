begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|ARCHIVE_ENTRY_PRIVATE_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_ENTRY_PRIVATE_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|"archive_acl_private.h"
end_include

begin_include
include|#
directive|include
file|"archive_string.h"
end_include

begin_struct
struct|struct
name|ae_xattr
block|{
name|struct
name|ae_xattr
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|void
modifier|*
name|value
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ae_sparse
block|{
name|struct
name|ae_sparse
modifier|*
name|next
decl_stmt|;
name|int64_t
name|offset
decl_stmt|;
name|int64_t
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Description of an archive entry.  *  * Basically, this is a "struct stat" with a few text fields added in.  *  * TODO: Add "comment", "charset", and possibly other entries  * that are supported by "pax interchange" format.  However, GNU, ustar,  * cpio, and other variants don't support these features, so they're not an  * excruciatingly high priority right now.  *  * TODO: "pax interchange" format allows essentially arbitrary  * key/value attributes to be attached to any entry.  Supporting  * such extensions may make this library useful for special  * applications (e.g., a package manager could attach special  * package-management attributes to each entry).  There are tricky  * API issues involved, so this is not going to happen until  * there's a real demand for it.  *  * TODO: Design a good API for handling sparse files.  */
end_comment

begin_struct
struct|struct
name|archive_entry
block|{
name|struct
name|archive
modifier|*
name|archive
decl_stmt|;
comment|/* 	 * Note that ae_stat.st_mode& AE_IFMT  can be  0! 	 * 	 * This occurs when the actual file type of the object is not 	 * in the archive.  For example, 'tar' archives store 	 * hardlinks without marking the type of the underlying 	 * object. 	 */
comment|/* 	 * We have a "struct aest" for holding file metadata rather than just 	 * a "struct stat" because on some platforms the "struct stat" has 	 * fields which are too narrow to hold the range of possible values; 	 * we don't want to lose information if we read an archive and write 	 * out another (e.g., in "tar -cf new.tar @old.tar"). 	 * 	 * The "stat" pointer points to some form of platform-specific struct 	 * stat; it is declared as a void * rather than a struct stat * as 	 * some platforms have multiple varieties of stat structures. 	 */
name|void
modifier|*
name|stat
decl_stmt|;
name|int
name|stat_valid
decl_stmt|;
comment|/* Set to 0 whenever a field in aest changes. */
struct|struct
name|aest
block|{
name|int64_t
name|aest_atime
decl_stmt|;
name|uint32_t
name|aest_atime_nsec
decl_stmt|;
name|int64_t
name|aest_ctime
decl_stmt|;
name|uint32_t
name|aest_ctime_nsec
decl_stmt|;
name|int64_t
name|aest_mtime
decl_stmt|;
name|uint32_t
name|aest_mtime_nsec
decl_stmt|;
name|int64_t
name|aest_birthtime
decl_stmt|;
name|uint32_t
name|aest_birthtime_nsec
decl_stmt|;
name|int64_t
name|aest_gid
decl_stmt|;
name|int64_t
name|aest_ino
decl_stmt|;
name|uint32_t
name|aest_nlink
decl_stmt|;
name|uint64_t
name|aest_size
decl_stmt|;
name|int64_t
name|aest_uid
decl_stmt|;
comment|/* 		 * Because converting between device codes and 		 * major/minor values is platform-specific and 		 * inherently a bit risky, we only do that conversion 		 * lazily.  That way, we will do a better job of 		 * preserving information in those cases where no 		 * conversion is actually required. 		 */
name|int
name|aest_dev_is_broken_down
decl_stmt|;
name|dev_t
name|aest_dev
decl_stmt|;
name|dev_t
name|aest_devmajor
decl_stmt|;
name|dev_t
name|aest_devminor
decl_stmt|;
name|int
name|aest_rdev_is_broken_down
decl_stmt|;
name|dev_t
name|aest_rdev
decl_stmt|;
name|dev_t
name|aest_rdevmajor
decl_stmt|;
name|dev_t
name|aest_rdevminor
decl_stmt|;
block|}
name|ae_stat
struct|;
name|int
name|ae_set
decl_stmt|;
comment|/* bitmap of fields that are currently set */
define|#
directive|define
name|AE_SET_HARDLINK
value|1
define|#
directive|define
name|AE_SET_SYMLINK
value|2
define|#
directive|define
name|AE_SET_ATIME
value|4
define|#
directive|define
name|AE_SET_CTIME
value|8
define|#
directive|define
name|AE_SET_MTIME
value|16
define|#
directive|define
name|AE_SET_BIRTHTIME
value|32
define|#
directive|define
name|AE_SET_SIZE
value|64
define|#
directive|define
name|AE_SET_INO
value|128
define|#
directive|define
name|AE_SET_DEV
value|256
comment|/* 	 * Use aes here so that we get transparent mbs<->wcs conversions. 	 */
name|struct
name|archive_mstring
name|ae_fflags_text
decl_stmt|;
comment|/* Text fflags per fflagstostr(3) */
name|unsigned
name|long
name|ae_fflags_set
decl_stmt|;
comment|/* Bitmap fflags */
name|unsigned
name|long
name|ae_fflags_clear
decl_stmt|;
name|struct
name|archive_mstring
name|ae_gname
decl_stmt|;
comment|/* Name of owning group */
name|struct
name|archive_mstring
name|ae_hardlink
decl_stmt|;
comment|/* Name of target for hardlink */
name|struct
name|archive_mstring
name|ae_pathname
decl_stmt|;
comment|/* Name of entry */
name|struct
name|archive_mstring
name|ae_symlink
decl_stmt|;
comment|/* symlink contents */
name|struct
name|archive_mstring
name|ae_uname
decl_stmt|;
comment|/* Name of owner */
comment|/* Not used within libarchive; useful for some clients. */
name|struct
name|archive_mstring
name|ae_sourcepath
decl_stmt|;
comment|/* Path this entry is sourced from. */
name|void
modifier|*
name|mac_metadata
decl_stmt|;
name|size_t
name|mac_metadata_size
decl_stmt|;
comment|/* ACL support. */
name|struct
name|archive_acl
name|acl
decl_stmt|;
comment|/* extattr support. */
name|struct
name|ae_xattr
modifier|*
name|xattr_head
decl_stmt|;
name|struct
name|ae_xattr
modifier|*
name|xattr_p
decl_stmt|;
comment|/* sparse support. */
name|struct
name|ae_sparse
modifier|*
name|sparse_head
decl_stmt|;
name|struct
name|ae_sparse
modifier|*
name|sparse_tail
decl_stmt|;
name|struct
name|ae_sparse
modifier|*
name|sparse_p
decl_stmt|;
comment|/* Miscellaneous. */
name|char
name|strmode
index|[
literal|12
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
comment|/* ARCHIVE_ENTRY_PRIVATE_H_INCLUDED */
end_comment

end_unit

