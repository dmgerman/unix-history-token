begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2004 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_ENTRY_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_ENTRY_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_comment
comment|/*  * Description of an archive entry.  *  * Basically, a "struct stat" with a few text fields added in.  *  * TODO: Add "comment", "charset", and possibly other entries that are  * supported by "pax interchange" format.  However, GNU, ustar, cpio,  * and other variants don't support these features, so they're not an  * excruciatingly high priority right now.  *  * TODO: "pax interchange" format allows essentially arbitrary  * key/value attributes to be attached to any entry.  Supporting  * such extensions may make this library useful for special  * applications (e.g., a package manager could attach special  * package-management attributes to each entry).  *  * TODO: Design a good API for handling sparse files.  */
end_comment

begin_struct_decl
struct_decl|struct
name|archive_entry
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Basic object manipulation  */
end_comment

begin_function_decl
name|struct
name|archive_entry
modifier|*
name|archive_entry_clear
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The 'clone' function does a deep copy; all of the strings are copied too. */
end_comment

begin_function_decl
name|struct
name|archive_entry
modifier|*
name|archive_entry_clone
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_free
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|archive_entry
modifier|*
name|archive_entry_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Retrieve fields from an archive_entry.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|archive_entry_acl
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|archive_entry_acl_default
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dev_t
name|archive_entry_devmajor
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dev_t
name|archive_entry_devminor
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|archive_entry_fflags
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|archive_entry_gname
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|archive_entry_hardlink
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mode_t
name|archive_entry_mode
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|archive_entry_pathname
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|wchar_t
modifier|*
name|archive_entry_pathname_w
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int64_t
name|archive_entry_size
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|stat
modifier|*
name|archive_entry_stat
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|archive_entry_symlink
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_entry_tartype
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|archive_entry_uname
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set fields in an archive_entry.  *  * Note that string 'set' functions do not copy the string, only the pointer.  * In contrast, 'copy_stat' does copy the full structure.  */
end_comment

begin_function_decl
name|void
name|archive_entry_copy_stat
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_set_acl
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_copy_acl_w
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_set_acl_default
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_copy_acl_default_w
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_set_fflags
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_copy_fflags_w
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_set_devmajor
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
name|dev_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_set_devminor
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
name|dev_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_set_gid
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_set_gname
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_copy_gname_w
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_set_hardlink
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_copy_hardlink_w
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_set_mode
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_set_pathname
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_copy_pathname_w
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_set_size
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
name|int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_set_symlink
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_copy_symlink_w
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_set_tartype
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_set_uid
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_set_uname
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_entry_copy_uname_w
parameter_list|(
name|struct
name|archive_entry
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ARCHIVE_ENTRY_H_INCLUDED */
end_comment

end_unit

