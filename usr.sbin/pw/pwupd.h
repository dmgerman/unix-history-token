begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1996  *	David L. Nugent.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY DAVID L. NUGENT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL DAVID L. NUGENT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PWUPD_H_
end_ifndef

begin_define
define|#
directive|define
name|_PWUPD_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stringlist.h>
end_include

begin_struct
struct|struct
name|pwf
block|{
name|int
name|_altdir
decl_stmt|;
name|void
function_decl|(
modifier|*
name|_setpwent
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|_endpwent
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|struct
name|passwd
modifier|*
function_decl|(
modifier|*
name|_getpwent
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|struct
name|passwd
modifier|*
function_decl|(
modifier|*
name|_getpwuid
function_decl|)
parameter_list|(
name|uid_t
name|uid
parameter_list|)
function_decl|;
name|struct
name|passwd
modifier|*
function_decl|(
modifier|*
name|_getpwnam
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|nam
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|_setgrent
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|_endgrent
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|struct
name|group
modifier|*
function_decl|(
modifier|*
name|_getgrent
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|struct
name|group
modifier|*
function_decl|(
modifier|*
name|_getgrgid
function_decl|)
parameter_list|(
name|gid_t
name|gid
parameter_list|)
function_decl|;
name|struct
name|group
modifier|*
function_decl|(
modifier|*
name|_getgrnam
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|nam
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|userconf
block|{
name|int
name|default_password
decl_stmt|;
comment|/* Default password for new users? */
name|int
name|reuse_uids
decl_stmt|;
comment|/* Reuse uids? */
name|int
name|reuse_gids
decl_stmt|;
comment|/* Reuse gids? */
name|char
modifier|*
name|nispasswd
decl_stmt|;
comment|/* Path to NIS version of the passwd file */
name|char
modifier|*
name|dotdir
decl_stmt|;
comment|/* Where to obtain skeleton files */
name|char
modifier|*
name|newmail
decl_stmt|;
comment|/* Mail to send to new accounts */
name|char
modifier|*
name|logfile
decl_stmt|;
comment|/* Where to log changes */
name|char
modifier|*
name|home
decl_stmt|;
comment|/* Where to create home directory */
name|mode_t
name|homemode
decl_stmt|;
comment|/* Home directory permissions */
name|char
modifier|*
name|shelldir
decl_stmt|;
comment|/* Where shells are located */
name|char
modifier|*
modifier|*
name|shells
decl_stmt|;
comment|/* List of shells */
name|char
modifier|*
name|shell_default
decl_stmt|;
comment|/* Default shell */
name|char
modifier|*
name|default_group
decl_stmt|;
comment|/* Default group number */
name|StringList
modifier|*
name|groups
decl_stmt|;
comment|/* Default (additional) groups */
name|char
modifier|*
name|default_class
decl_stmt|;
comment|/* Default user class */
name|uid_t
name|min_uid
decl_stmt|,
name|max_uid
decl_stmt|;
comment|/* Allowed range of uids */
name|gid_t
name|min_gid
decl_stmt|,
name|max_gid
decl_stmt|;
comment|/* Allowed range of gids */
name|time_t
name|expire_days
decl_stmt|;
comment|/* Days to expiry */
name|time_t
name|password_days
decl_stmt|;
comment|/* Days to password expiry */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pwconf
block|{
name|char
name|rootdir
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
name|etcpath
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|int
name|rootfd
decl_stmt|;
name|bool
name|checkduplicate
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|pwf
name|PWF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pwf
name|VPWF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pwconf
name|conf
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SETPWENT
parameter_list|()
value|PWF._setpwent()
end_define

begin_define
define|#
directive|define
name|ENDPWENT
parameter_list|()
value|PWF._endpwent()
end_define

begin_define
define|#
directive|define
name|GETPWENT
parameter_list|()
value|PWF._getpwent()
end_define

begin_define
define|#
directive|define
name|GETPWUID
parameter_list|(
name|uid
parameter_list|)
value|PWF._getpwuid(uid)
end_define

begin_define
define|#
directive|define
name|GETPWNAM
parameter_list|(
name|nam
parameter_list|)
value|PWF._getpwnam(nam)
end_define

begin_define
define|#
directive|define
name|SETGRENT
parameter_list|()
value|PWF._setgrent()
end_define

begin_define
define|#
directive|define
name|ENDGRENT
parameter_list|()
value|PWF._endgrent()
end_define

begin_define
define|#
directive|define
name|GETGRENT
parameter_list|()
value|PWF._getgrent()
end_define

begin_define
define|#
directive|define
name|GETGRGID
parameter_list|(
name|gid
parameter_list|)
value|PWF._getgrgid(gid)
end_define

begin_define
define|#
directive|define
name|GETGRNAM
parameter_list|(
name|nam
parameter_list|)
value|PWF._getgrnam(nam)
end_define

begin_define
define|#
directive|define
name|PWF_REGULAR
value|0
end_define

begin_define
define|#
directive|define
name|PWF_ALT
value|1
end_define

begin_define
define|#
directive|define
name|PWF_ROOTDIR
value|2
end_define

begin_define
define|#
directive|define
name|PWALTDIR
parameter_list|()
value|PWF._altdir
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_PWD
end_ifndef

begin_define
define|#
directive|define
name|_PATH_PWD
value|"/etc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_GROUP
end_ifndef

begin_define
define|#
directive|define
name|_GROUP
value|"group"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MASTERPASSWD
end_ifndef

begin_define
define|#
directive|define
name|_MASTERPASSWD
value|"master.passwd"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__BEGIN_DECLS
name|int
name|addpwent
parameter_list|(
name|struct
name|passwd
modifier|*
name|pwd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|delpwent
parameter_list|(
name|struct
name|passwd
modifier|*
name|pwd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chgpwent
parameter_list|(
name|char
specifier|const
modifier|*
name|login
parameter_list|,
name|struct
name|passwd
modifier|*
name|pwd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getpwpath
parameter_list|(
name|char
specifier|const
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|addgrent
parameter_list|(
name|struct
name|group
modifier|*
name|grp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|delgrent
parameter_list|(
name|struct
name|group
modifier|*
name|grp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chggrent
parameter_list|(
name|char
specifier|const
modifier|*
name|name
parameter_list|,
name|struct
name|group
modifier|*
name|grp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getgrpath
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vsetpwent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vendpwent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|vgetpwent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|vgetpwuid
parameter_list|(
name|uid_t
name|uid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|vgetpwnam
parameter_list|(
specifier|const
name|char
modifier|*
name|nam
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|group
modifier|*
name|vgetgrent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|group
modifier|*
name|vgetgrgid
parameter_list|(
name|gid_t
name|gid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|group
modifier|*
name|vgetgrnam
parameter_list|(
specifier|const
name|char
modifier|*
name|nam
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vsetgrent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vendgrent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copymkdir
parameter_list|(
name|int
name|rootfd
parameter_list|,
name|char
specifier|const
modifier|*
name|dir
parameter_list|,
name|int
name|skelfd
parameter_list|,
name|mode_t
name|mode
parameter_list|,
name|uid_t
name|uid
parameter_list|,
name|gid_t
name|gid
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rm_r
parameter_list|(
name|int
name|rootfd
parameter_list|,
name|char
specifier|const
modifier|*
name|dir
parameter_list|,
name|uid_t
name|uid
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PWUPD_H */
end_comment

end_unit

