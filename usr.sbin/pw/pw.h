begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1996  *	David L. Nugent.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY DAVID L. NUGENT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL DAVID L. NUGENT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: pw.h,v 1.1.1.2 1996/12/09 23:55:23 joerg Exp $  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
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
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_include
include|#
directive|include
file|"psdate.h"
end_include

begin_enum
enum|enum
name|_mode
block|{
name|M_ADD
block|,
name|M_DELETE
block|,
name|M_UPDATE
block|,
name|M_PRINT
block|,
name|M_NEXT
block|,
name|M_NUM
block|}
enum|;
end_enum

begin_enum
enum|enum
name|_which
block|{
name|W_USER
block|,
name|W_GROUP
block|,
name|W_NUM
block|}
enum|;
end_enum

begin_struct
struct|struct
name|carg
block|{
name|int
name|ch
decl_stmt|;
name|char
modifier|*
name|val
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|carg
argument_list|)
name|list
expr_stmt|;
block|}
struct|;
end_struct

begin_extern
extern|extern LIST_HEAD(cargs
operator|,
extern|carg
end_extern

begin_expr_stmt
unit|)
name|arglist
expr_stmt|;
end_expr_stmt

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
name|char
modifier|*
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
name|int
name|expire_days
decl_stmt|;
comment|/* Days to expiry */
name|int
name|password_days
decl_stmt|;
comment|/* Days to password expiry */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_PATH_PW_CONF
value|"/etc/pw.conf"
end_define

begin_define
define|#
directive|define
name|_UC_MAXLINE
value|1024
end_define

begin_define
define|#
directive|define
name|_UC_MAXSHELLS
value|32
end_define

begin_define
define|#
directive|define
name|_UC_MAXGROUPS
value|200
end_define

begin_function_decl
name|struct
name|userconf
modifier|*
name|read_userconfig
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
name|write_userconfig
parameter_list|(
name|char
specifier|const
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|carg
modifier|*
name|addarg
parameter_list|(
name|struct
name|cargs
modifier|*
name|_args
parameter_list|,
name|int
name|ch
parameter_list|,
name|char
modifier|*
name|argstr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|carg
modifier|*
name|getarg
parameter_list|(
name|struct
name|cargs
modifier|*
name|_args
parameter_list|,
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cmderr
parameter_list|(
name|int
name|ec
parameter_list|,
name|char
specifier|const
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pw_user
parameter_list|(
name|struct
name|userconf
modifier|*
name|cnf
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|cargs
modifier|*
name|_args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pw_group
parameter_list|(
name|struct
name|userconf
modifier|*
name|cnf
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|cargs
modifier|*
name|_args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|int
name|fmtpwent
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|struct
name|passwd
modifier|*
name|pwd
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
name|login
parameter_list|,
name|struct
name|group
modifier|*
name|grp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fmtgrent
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|struct
name|group
modifier|*
name|grp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|boolean_val
parameter_list|(
name|char
specifier|const
modifier|*
name|str
parameter_list|,
name|int
name|dflt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
specifier|const
modifier|*
name|boolean_str
parameter_list|(
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|newstr
parameter_list|(
name|char
specifier|const
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pw_log
parameter_list|(
name|struct
name|userconf
modifier|*
name|cnf
parameter_list|,
name|int
name|mode
parameter_list|,
name|int
name|which
parameter_list|,
name|char
specifier|const
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|pw_pwcrypt
parameter_list|(
name|char
modifier|*
name|password
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|Modes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|Which
index|[]
decl_stmt|;
end_decl_stmt

end_unit

