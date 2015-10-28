begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1996  *	David L. Nugent.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY DAVID L. NUGENT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL DAVID L. NUGENT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"$FreeBSD$"
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
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"pw.h"
end_include

begin_decl_stmt
specifier|const
name|char
modifier|*
name|Modes
index|[]
init|=
block|{
literal|"add"
block|,
literal|"del"
block|,
literal|"mod"
block|,
literal|"show"
block|,
literal|"next"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|Which
index|[]
init|=
block|{
literal|"user"
block|,
literal|"group"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|Combo1
index|[]
init|=
block|{
literal|"useradd"
block|,
literal|"userdel"
block|,
literal|"usermod"
block|,
literal|"usershow"
block|,
literal|"usernext"
block|,
literal|"lock"
block|,
literal|"unlock"
block|,
literal|"groupadd"
block|,
literal|"groupdel"
block|,
literal|"groupmod"
block|,
literal|"groupshow"
block|,
literal|"groupnext"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|Combo2
index|[]
init|=
block|{
literal|"adduser"
block|,
literal|"deluser"
block|,
literal|"moduser"
block|,
literal|"showuser"
block|,
literal|"nextuser"
block|,
literal|"lock"
block|,
literal|"unlock"
block|,
literal|"addgroup"
block|,
literal|"delgroup"
block|,
literal|"modgroup"
block|,
literal|"showgroup"
block|,
literal|"nextgroup"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pwf
name|PWF
init|=
block|{
name|PWF_REGULAR
block|,
name|setpwent
block|,
name|endpwent
block|,
name|getpwent
block|,
name|getpwuid
block|,
name|getpwnam
block|,
name|setgrent
block|,
name|endgrent
block|,
name|getgrent
block|,
name|getgrgid
block|,
name|getgrnam
block|,  }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pwf
name|VPWF
init|=
block|{
name|PWF_ALT
block|,
name|vsetpwent
block|,
name|vendpwent
block|,
name|vgetpwent
block|,
name|vgetpwuid
block|,
name|vgetpwnam
block|,
name|vsetgrent
block|,
name|vendgrent
block|,
name|vgetgrent
block|,
name|vgetgrgid
block|,
name|vgetgrnam
block|, }
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
function_decl|(
modifier|*
name|cmdfunc
index|[
name|W_NUM
index|]
index|[
name|M_NUM
index|]
function_decl|)
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|char
modifier|*
name|_name
parameter_list|)
init|=
block|{
block|{
comment|/* user */
name|pw_user_add
operator|,
function_decl|pw_user_del
operator|,
function_decl|pw_user_mod
operator|,
function_decl|pw_user_show
operator|,
function_decl|pw_user_next
operator|,
function_decl|pw_user_lock
operator|,
function_decl|pw_user_unlock
operator|,
end_function_decl

begin_block
unit|},
block|{
comment|/* group */
name|pw_group_add
operator|,
name|pw_group_del
operator|,
name|pw_group_mod
operator|,
name|pw_group_show
operator|,
name|pw_group_next
operator|,
block|}
end_block

begin_decl_stmt
unit|};
name|struct
name|pwconf
name|conf
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|getindex
parameter_list|(
specifier|const
name|char
modifier|*
name|words
index|[]
parameter_list|,
specifier|const
name|char
modifier|*
name|word
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|cmdhelp
parameter_list|(
name|int
name|mode
parameter_list|,
name|int
name|which
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
name|mode
init|=
operator|-
literal|1
decl_stmt|,
name|which
init|=
operator|-
literal|1
decl_stmt|,
name|tmp
decl_stmt|;
name|struct
name|stat
name|st
decl_stmt|;
name|char
name|arg
decl_stmt|,
modifier|*
name|arg1
decl_stmt|;
name|bool
name|relocated
decl_stmt|,
name|nis
decl_stmt|;
name|arg1
operator|=
name|NULL
expr_stmt|;
name|relocated
operator|=
name|nis
operator|=
name|false
expr_stmt|;
name|memset
argument_list|(
operator|&
name|conf
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|conf
argument_list|)
argument_list|)
expr_stmt|;
name|strlcpy
argument_list|(
name|conf
operator|.
name|rootdir
argument_list|,
literal|"/"
argument_list|,
sizeof|sizeof
argument_list|(
name|conf
operator|.
name|rootdir
argument_list|)
argument_list|)
expr_stmt|;
name|strlcpy
argument_list|(
name|conf
operator|.
name|etcpath
argument_list|,
name|_PATH_PWD
argument_list|,
sizeof|sizeof
argument_list|(
name|conf
operator|.
name|etcpath
argument_list|)
argument_list|)
expr_stmt|;
name|conf
operator|.
name|fd
operator|=
operator|-
literal|1
expr_stmt|;
name|conf
operator|.
name|checkduplicate
operator|=
name|true
expr_stmt|;
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
literal|""
argument_list|)
expr_stmt|;
comment|/* 	 * Break off the first couple of words to determine what exactly 	 * we're being asked to do 	 */
while|while
condition|(
name|argc
operator|>
literal|1
condition|)
block|{
if|if
condition|(
operator|*
name|argv
index|[
literal|1
index|]
operator|==
literal|'-'
condition|)
block|{
comment|/* 			 * Special case, allow pw -V<dir><operation> [args] for scripts etc. 			 */
name|arg
operator|=
name|argv
index|[
literal|1
index|]
index|[
literal|1
index|]
expr_stmt|;
if|if
condition|(
name|arg
operator|==
literal|'V'
operator|||
name|arg
operator|==
literal|'R'
condition|)
block|{
if|if
condition|(
name|relocated
condition|)
name|errx
argument_list|(
name|EXIT_FAILURE
argument_list|,
literal|"Both '-R' and '-V' "
literal|"specified, only one accepted"
argument_list|)
expr_stmt|;
name|relocated
operator|=
name|true
expr_stmt|;
name|optarg
operator|=
operator|&
name|argv
index|[
literal|1
index|]
index|[
literal|2
index|]
expr_stmt|;
if|if
condition|(
operator|*
name|optarg
operator|==
literal|'\0'
condition|)
block|{
if|if
condition|(
name|stat
argument_list|(
name|argv
index|[
literal|2
index|]
argument_list|,
operator|&
name|st
argument_list|)
operator|!=
literal|0
condition|)
name|errx
argument_list|(
name|EX_OSFILE
argument_list|, \
literal|"no such directory `%s'"
argument_list|,
name|argv
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|S_ISDIR
argument_list|(
name|st
operator|.
name|st_mode
argument_list|)
condition|)
name|errx
argument_list|(
name|EX_OSFILE
argument_list|,
literal|"`%s' not a "
literal|"directory"
argument_list|,
name|argv
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|optarg
operator|=
name|argv
index|[
literal|2
index|]
expr_stmt|;
operator|++
name|argv
expr_stmt|;
operator|--
name|argc
expr_stmt|;
block|}
name|memcpy
argument_list|(
operator|&
name|PWF
argument_list|,
operator|&
name|VPWF
argument_list|,
sizeof|sizeof
name|PWF
argument_list|)
expr_stmt|;
if|if
condition|(
name|arg
operator|==
literal|'R'
condition|)
block|{
name|strlcpy
argument_list|(
name|conf
operator|.
name|rootdir
argument_list|,
name|optarg
argument_list|,
sizeof|sizeof
argument_list|(
name|conf
operator|.
name|rootdir
argument_list|)
argument_list|)
expr_stmt|;
name|PWF
operator|.
name|_altdir
operator|=
name|PWF_ROOTDIR
expr_stmt|;
block|}
name|snprintf
argument_list|(
name|conf
operator|.
name|etcpath
argument_list|,
sizeof|sizeof
argument_list|(
name|conf
operator|.
name|etcpath
argument_list|)
argument_list|,
literal|"%s%s"
argument_list|,
name|optarg
argument_list|,
name|arg
operator|==
literal|'R'
condition|?
literal|"/etc"
else|:
literal|""
argument_list|)
expr_stmt|;
block|}
else|else
break|break;
block|}
elseif|else
if|if
condition|(
name|mode
operator|==
operator|-
literal|1
operator|&&
operator|(
name|tmp
operator|=
name|getindex
argument_list|(
name|Modes
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
name|mode
operator|=
name|tmp
expr_stmt|;
elseif|else
if|if
condition|(
name|which
operator|==
operator|-
literal|1
operator|&&
operator|(
name|tmp
operator|=
name|getindex
argument_list|(
name|Which
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
name|which
operator|=
name|tmp
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|mode
operator|==
operator|-
literal|1
operator|&&
name|which
operator|==
operator|-
literal|1
operator|)
operator|&&
operator|(
operator|(
name|tmp
operator|=
name|getindex
argument_list|(
name|Combo1
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
operator|)
operator|!=
operator|-
literal|1
operator|||
operator|(
name|tmp
operator|=
name|getindex
argument_list|(
name|Combo2
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
operator|)
operator|!=
operator|-
literal|1
operator|)
condition|)
block|{
name|which
operator|=
name|tmp
operator|/
name|M_NUM
expr_stmt|;
name|mode
operator|=
name|tmp
operator|%
name|M_NUM
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"help"
argument_list|)
operator|==
literal|0
operator|&&
name|argv
index|[
literal|2
index|]
operator|==
name|NULL
condition|)
name|cmdhelp
argument_list|(
name|mode
argument_list|,
name|which
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|which
operator|!=
operator|-
literal|1
operator|&&
name|mode
operator|!=
operator|-
literal|1
condition|)
name|arg1
operator|=
name|argv
index|[
literal|1
index|]
expr_stmt|;
else|else
name|errx
argument_list|(
name|EX_USAGE
argument_list|,
literal|"unknown keyword `%s'"
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
operator|++
name|argv
expr_stmt|;
operator|--
name|argc
expr_stmt|;
block|}
comment|/* 	 * Bail out unless the user is specific! 	 */
if|if
condition|(
name|mode
operator|==
operator|-
literal|1
operator|||
name|which
operator|==
operator|-
literal|1
condition|)
name|cmdhelp
argument_list|(
name|mode
argument_list|,
name|which
argument_list|)
expr_stmt|;
name|conf
operator|.
name|rootfd
operator|=
name|open
argument_list|(
name|conf
operator|.
name|rootdir
argument_list|,
name|O_DIRECTORY
operator||
name|O_CLOEXEC
argument_list|)
expr_stmt|;
if|if
condition|(
name|conf
operator|.
name|rootfd
operator|==
operator|-
literal|1
condition|)
name|errx
argument_list|(
name|EXIT_FAILURE
argument_list|,
literal|"Unable to open '%s'"
argument_list|,
name|conf
operator|.
name|rootdir
argument_list|)
expr_stmt|;
return|return
operator|(
name|cmdfunc
index|[
name|which
index|]
index|[
name|mode
index|]
operator|(
name|argc
operator|,
name|argv
operator|,
name|arg1
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|getindex
parameter_list|(
specifier|const
name|char
modifier|*
name|words
index|[]
parameter_list|,
specifier|const
name|char
modifier|*
name|word
parameter_list|)
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|words
index|[
name|i
index|]
condition|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|words
index|[
name|i
index|]
argument_list|,
name|word
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|i
operator|)
return|;
name|i
operator|++
expr_stmt|;
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * This is probably an overkill for a cmdline help system, but it reflects  * the complexity of the command line.  */
end_comment

begin_function
specifier|static
name|void
name|cmdhelp
parameter_list|(
name|int
name|mode
parameter_list|,
name|int
name|which
parameter_list|)
block|{
if|if
condition|(
name|which
operator|==
operator|-
literal|1
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage:\n  pw [user|group|lock|unlock] [add|del|mod|show|next] [help|switches/values]\n"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|mode
operator|==
operator|-
literal|1
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage:\n  pw %s [add|del|mod|show|next] [help|switches/values]\n"
argument_list|,
name|Which
index|[
name|which
index|]
argument_list|)
expr_stmt|;
else|else
block|{
comment|/* 		 * We need to give mode specific help 		 */
specifier|static
specifier|const
name|char
modifier|*
name|help
index|[
name|W_NUM
index|]
index|[
name|M_NUM
index|]
init|=
block|{
block|{
literal|"usage: pw useradd [name] [switches]\n"
literal|"\t-V etcdir      alternate /etc location\n"
literal|"\t-R rootdir     alternate root directory\n"
literal|"\t-C config      configuration file\n"
literal|"\t-q             quiet operation\n"
literal|"  Adding users:\n"
literal|"\t-n name        login name\n"
literal|"\t-u uid         user id\n"
literal|"\t-c comment     user name/comment\n"
literal|"\t-d directory   home directory\n"
literal|"\t-e date        account expiry date\n"
literal|"\t-p date        password expiry date\n"
literal|"\t-g grp         initial group\n"
literal|"\t-G grp1,grp2   additional groups\n"
literal|"\t-m [ -k dir ]  create and set up home\n"
literal|"\t-M mode        home directory permissions\n"
literal|"\t-s shell       name of login shell\n"
literal|"\t-o             duplicate uid ok\n"
literal|"\t-L class       user class\n"
literal|"\t-h fd          read password on fd\n"
literal|"\t-H fd          read encrypted password on fd\n"
literal|"\t-Y             update NIS maps\n"
literal|"\t-N             no update\n"
literal|"  Setting defaults:\n"
literal|"\t-V etcdir      alternate /etc location\n"
literal|"\t-R rootdir     alternate root directory\n"
literal|"\t-D             set user defaults\n"
literal|"\t-b dir         default home root dir\n"
literal|"\t-e period      default expiry period\n"
literal|"\t-p period      default password change period\n"
literal|"\t-g group       default group\n"
literal|"\t-G grp1,grp2   additional groups\n"
literal|"\t-L class       default user class\n"
literal|"\t-k dir         default home skeleton\n"
literal|"\t-M mode        home directory permissions\n"
literal|"\t-u min,max     set min,max uids\n"
literal|"\t-i min,max     set min,max gids\n"
literal|"\t-w method      set default password method\n"
literal|"\t-s shell       default shell\n"
literal|"\t-y path        set NIS passwd file path\n"
block|,
literal|"usage: pw userdel [uid|name] [switches]\n"
literal|"\t-V etcdir      alternate /etc location\n"
literal|"\t-R rootdir     alternate root directory\n"
literal|"\t-n name        login name\n"
literal|"\t-u uid         user id\n"
literal|"\t-Y             update NIS maps\n"
literal|"\t-y path        set NIS passwd file path\n"
literal|"\t-r             remove home& contents\n"
block|,
literal|"usage: pw usermod [uid|name] [switches]\n"
literal|"\t-V etcdir      alternate /etc location\n"
literal|"\t-R rootdir     alternate root directory\n"
literal|"\t-C config      configuration file\n"
literal|"\t-q             quiet operation\n"
literal|"\t-F             force add if no user\n"
literal|"\t-n name        login name\n"
literal|"\t-u uid         user id\n"
literal|"\t-c comment     user name/comment\n"
literal|"\t-d directory   home directory\n"
literal|"\t-e date        account expiry date\n"
literal|"\t-p date        password expiry date\n"
literal|"\t-g grp         initial group\n"
literal|"\t-G grp1,grp2   additional groups\n"
literal|"\t-l name        new login name\n"
literal|"\t-L class       user class\n"
literal|"\t-m [ -k dir ]  create and set up home\n"
literal|"\t-M mode        home directory permissions\n"
literal|"\t-s shell       name of login shell\n"
literal|"\t-w method      set new password using method\n"
literal|"\t-h fd          read password on fd\n"
literal|"\t-H fd          read encrypted password on fd\n"
literal|"\t-Y             update NIS maps\n"
literal|"\t-y path        set NIS passwd file path\n"
literal|"\t-N             no update\n"
block|,
literal|"usage: pw usershow [uid|name] [switches]\n"
literal|"\t-V etcdir      alternate /etc location\n"
literal|"\t-R rootdir     alternate root directory\n"
literal|"\t-n name        login name\n"
literal|"\t-u uid         user id\n"
literal|"\t-F             force print\n"
literal|"\t-P             prettier format\n"
literal|"\t-a             print all users\n"
literal|"\t-7             print in v7 format\n"
block|,
literal|"usage: pw usernext [switches]\n"
literal|"\t-V etcdir      alternate /etc location\n"
literal|"\t-R rootdir     alternate root directory\n"
literal|"\t-C config      configuration file\n"
literal|"\t-q             quiet operation\n"
block|,
literal|"usage pw: lock [switches]\n"
literal|"\t-V etcdir      alternate /etc locations\n"
literal|"\t-C config      configuration file\n"
literal|"\t-q             quiet operation\n"
block|,
literal|"usage pw: unlock [switches]\n"
literal|"\t-V etcdir      alternate /etc locations\n"
literal|"\t-C config      configuration file\n"
literal|"\t-q             quiet operation\n"
block|}
block|,
block|{
literal|"usage: pw groupadd [group|gid] [switches]\n"
literal|"\t-V etcdir      alternate /etc location\n"
literal|"\t-R rootdir     alternate root directory\n"
literal|"\t-C config      configuration file\n"
literal|"\t-q             quiet operation\n"
literal|"\t-n group       group name\n"
literal|"\t-g gid         group id\n"
literal|"\t-M usr1,usr2   add users as group members\n"
literal|"\t-o             duplicate gid ok\n"
literal|"\t-Y             update NIS maps\n"
literal|"\t-N             no update\n"
block|,
literal|"usage: pw groupdel [group|gid] [switches]\n"
literal|"\t-V etcdir      alternate /etc location\n"
literal|"\t-R rootdir     alternate root directory\n"
literal|"\t-n name        group name\n"
literal|"\t-g gid         group id\n"
literal|"\t-Y             update NIS maps\n"
block|,
literal|"usage: pw groupmod [group|gid] [switches]\n"
literal|"\t-V etcdir      alternate /etc location\n"
literal|"\t-R rootdir     alternate root directory\n"
literal|"\t-C config      configuration file\n"
literal|"\t-q             quiet operation\n"
literal|"\t-F             force add if not exists\n"
literal|"\t-n name        group name\n"
literal|"\t-g gid         group id\n"
literal|"\t-M usr1,usr2   replaces users as group members\n"
literal|"\t-m usr1,usr2   add users as group members\n"
literal|"\t-d usr1,usr2   delete users as group members\n"
literal|"\t-l name        new group name\n"
literal|"\t-Y             update NIS maps\n"
literal|"\t-N             no update\n"
block|,
literal|"usage: pw groupshow [group|gid] [switches]\n"
literal|"\t-V etcdir      alternate /etc location\n"
literal|"\t-R rootdir     alternate root directory\n"
literal|"\t-n name        group name\n"
literal|"\t-g gid         group id\n"
literal|"\t-F             force print\n"
literal|"\t-P             prettier format\n"
literal|"\t-a             print all accounting groups\n"
block|,
literal|"usage: pw groupnext [switches]\n"
literal|"\t-V etcdir      alternate /etc location\n"
literal|"\t-R rootdir     alternate root directory\n"
literal|"\t-C config      configuration file\n"
literal|"\t-q             quiet operation\n"
block|}
block|}
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s"
argument_list|,
name|help
index|[
name|which
index|]
index|[
name|mode
index|]
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

