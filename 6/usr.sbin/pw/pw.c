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
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|"pw.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_PATH_YP
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_YP
value|"/var/yp/"
end_define

begin_endif
endif|#
directive|endif
end_endif

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
literal|0
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
name|pwdb
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
block|,
name|grdb
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pwf
name|VPWF
init|=
block|{
literal|1
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
name|vpwdb
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
block|,
name|vgrdb
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|cargs
name|arglist
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
name|ch
decl_stmt|;
name|int
name|mode
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|which
init|=
operator|-
literal|1
decl_stmt|;
name|char
modifier|*
name|config
init|=
name|NULL
decl_stmt|;
name|struct
name|userconf
modifier|*
name|cnf
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|opts
index|[
name|W_NUM
index|]
index|[
name|M_NUM
index|]
init|=
block|{
block|{
comment|/* user */
literal|"V:C:qn:u:c:d:e:p:g:G:mM:k:s:oL:i:w:h:H:Db:NPy:Y"
block|,
literal|"V:C:qn:u:rY"
block|,
literal|"V:C:qn:u:c:d:e:p:g:G:mM:l:k:s:w:L:h:H:FNPY"
block|,
literal|"V:C:qn:u:FPa7"
block|,
literal|"V:C:q"
block|,
literal|"V:C:q"
block|,
literal|"V:C:q"
block|}
block|,
block|{
comment|/* grp  */
literal|"V:C:qn:g:h:H:M:opNPY"
block|,
literal|"V:C:qn:g:Y"
block|,
literal|"V:C:qn:g:l:h:H:FM:m:NPY"
block|,
literal|"V:C:qn:g:FPa"
block|,
literal|"V:C:q"
block|}
block|}
decl_stmt|;
specifier|static
name|int
function_decl|(
modifier|*
name|funcs
index|[
name|W_NUM
index|]
function_decl|)
parameter_list|(
name|struct
name|userconf
modifier|*
name|_cnf
parameter_list|,
name|int
name|_mode
parameter_list|,
name|struct
name|cargs
modifier|*
name|_args
parameter_list|)
init|=
block|{
comment|/* Request handlers */
name|pw_user
operator|,
function_decl|pw_group
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|LIST_INIT
argument_list|(
operator|&
name|arglist
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|(
name|void
operator|)
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 * Break off the first couple of words to determine what exactly 	 * we're being asked to do 	 */
end_comment

begin_while
while|while
condition|(
name|argc
operator|>
literal|1
condition|)
block|{
name|int
name|tmp
decl_stmt|;
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
if|if
condition|(
name|argv
index|[
literal|1
index|]
index|[
literal|1
index|]
operator|==
literal|'V'
condition|)
block|{
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
name|addarg
argument_list|(
operator|&
name|arglist
argument_list|,
literal|'V'
argument_list|,
name|optarg
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
name|addarg
argument_list|(
operator|&
name|arglist
argument_list|,
literal|'n'
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
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
end_while

begin_comment
comment|/* 	 * Bail out unless the user is specific! 	 */
end_comment

begin_if
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
end_if

begin_comment
comment|/* 	 * We know which mode we're in and what we're about to do, so now 	 * let's dispatch the remaining command line args in a genric way. 	 */
end_comment

begin_expr_stmt
name|optarg
operator|=
name|NULL
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
operator|(
name|ch
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|opts
index|[
name|which
index|]
index|[
name|mode
index|]
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|ch
operator|==
literal|'?'
condition|)
name|errx
argument_list|(
name|EX_USAGE
argument_list|,
literal|"unknown switch"
argument_list|)
expr_stmt|;
else|else
name|addarg
argument_list|(
operator|&
name|arglist
argument_list|,
name|ch
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
name|optarg
operator|=
name|NULL
expr_stmt|;
block|}
end_while

begin_comment
comment|/* 	 * Must be root to attempt an update 	 */
end_comment

begin_if
if|if
condition|(
name|geteuid
argument_list|()
operator|!=
literal|0
operator|&&
name|mode
operator|!=
name|M_PRINT
operator|&&
name|mode
operator|!=
name|M_NEXT
operator|&&
name|getarg
argument_list|(
operator|&
name|arglist
argument_list|,
literal|'N'
argument_list|)
operator|==
name|NULL
condition|)
name|errx
argument_list|(
name|EX_NOPERM
argument_list|,
literal|"you must be root to run this program"
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* 	 * We should immediately look for the -q 'quiet' switch so that we 	 * don't bother with extraneous errors 	 */
end_comment

begin_if
if|if
condition|(
name|getarg
argument_list|(
operator|&
name|arglist
argument_list|,
literal|'q'
argument_list|)
operator|!=
name|NULL
condition|)
name|freopen
argument_list|(
name|_PATH_DEVNULL
argument_list|,
literal|"w"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* 	 * Set our base working path if not overridden 	 */
end_comment

begin_expr_stmt
name|config
operator|=
name|getarg
argument_list|(
operator|&
name|arglist
argument_list|,
literal|'C'
argument_list|)
condition|?
name|getarg
argument_list|(
operator|&
name|arglist
argument_list|,
literal|'C'
argument_list|)
operator|->
name|val
else|:
name|NULL
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|getarg
argument_list|(
operator|&
name|arglist
argument_list|,
literal|'V'
argument_list|)
operator|!=
name|NULL
condition|)
block|{
name|char
modifier|*
name|etcpath
init|=
name|getarg
argument_list|(
operator|&
name|arglist
argument_list|,
literal|'V'
argument_list|)
operator|->
name|val
decl_stmt|;
if|if
condition|(
operator|*
name|etcpath
condition|)
block|{
if|if
condition|(
name|config
operator|==
name|NULL
condition|)
block|{
comment|/* Only override config location if -C not specified */
name|config
operator|=
name|malloc
argument_list|(
name|MAXPATHLEN
argument_list|)
expr_stmt|;
name|snprintf
argument_list|(
name|config
argument_list|,
name|MAXPATHLEN
argument_list|,
literal|"%s/pw.conf"
argument_list|,
name|etcpath
argument_list|)
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
name|setpwdir
argument_list|(
name|etcpath
argument_list|)
expr_stmt|;
name|setgrdir
argument_list|(
name|etcpath
argument_list|)
expr_stmt|;
block|}
block|}
end_if

begin_comment
comment|/* 	 * Now, let's do the common initialisation 	 */
end_comment

begin_expr_stmt
name|cnf
operator|=
name|read_userconfig
argument_list|(
name|config
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ch
operator|=
name|funcs
index|[
name|which
index|]
operator|(
name|cnf
operator|,
name|mode
operator|,
operator|&
name|arglist
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 * If everything went ok, and we've been asked to update 	 * the NIS maps, then do it now 	 */
end_comment

begin_if
if|if
condition|(
name|ch
operator|==
name|EXIT_SUCCESS
operator|&&
name|getarg
argument_list|(
operator|&
name|arglist
argument_list|,
literal|'Y'
argument_list|)
operator|!=
name|NULL
condition|)
block|{
name|pid_t
name|pid
decl_stmt|;
name|fflush
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|chdir
argument_list|(
name|_PATH_YP
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|warn
argument_list|(
literal|"chdir("
name|_PATH_YP
literal|")"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|pid
operator|=
name|fork
argument_list|()
operator|)
operator|==
operator|-
literal|1
condition|)
name|warn
argument_list|(
literal|"fork()"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|pid
operator|==
literal|0
condition|)
block|{
comment|/* Is make anywhere else? */
name|execlp
argument_list|(
literal|"/usr/bin/make"
argument_list|,
literal|"make"
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
name|_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|int
name|i
decl_stmt|;
name|waitpid
argument_list|(
name|pid
argument_list|,
operator|&
name|i
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|i
operator|=
name|WEXITSTATUS
argument_list|(
name|i
argument_list|)
operator|)
operator|!=
literal|0
condition|)
name|errx
argument_list|(
name|ch
argument_list|,
literal|"make exited with status %d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
else|else
name|pw_log
argument_list|(
name|cnf
argument_list|,
name|mode
argument_list|,
name|which
argument_list|,
literal|"NIS maps updated"
argument_list|)
expr_stmt|;
block|}
block|}
end_if

begin_return
return|return
name|ch
return|;
end_return

begin_function
unit|}   static
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
name|i
return|;
name|i
operator|++
expr_stmt|;
block|}
return|return
operator|-
literal|1
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
literal|"\t-n name        login name\n"
literal|"\t-u uid         user id\n"
literal|"\t-Y             update NIS maps\n"
literal|"\t-r             remove home& contents\n"
block|,
literal|"usage: pw usermod [uid|name] [switches]\n"
literal|"\t-V etcdir      alternate /etc location\n"
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
literal|"\t-N             no update\n"
block|,
literal|"usage: pw usershow [uid|name] [switches]\n"
literal|"\t-V etcdir      alternate /etc location\n"
literal|"\t-n name        login name\n"
literal|"\t-u uid         user id\n"
literal|"\t-F             force print\n"
literal|"\t-P             prettier format\n"
literal|"\t-a             print all users\n"
literal|"\t-7             print in v7 format\n"
block|,
literal|"usage: pw usernext [switches]\n"
literal|"\t-V etcdir      alternate /etc location\n"
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
literal|"\t-n name        group name\n"
literal|"\t-g gid         group id\n"
literal|"\t-Y             update NIS maps\n"
block|,
literal|"usage: pw groupmod [group|gid] [switches]\n"
literal|"\t-V etcdir      alternate /etc location\n"
literal|"\t-C config      configuration file\n"
literal|"\t-q             quiet operation\n"
literal|"\t-F             force add if not exists\n"
literal|"\t-n name        group name\n"
literal|"\t-g gid         group id\n"
literal|"\t-M usr1,usr2   replaces users as group members\n"
literal|"\t-m usr1,usr2   add users as group members\n"
literal|"\t-l name        new group name\n"
literal|"\t-Y             update NIS maps\n"
literal|"\t-N             no update\n"
block|,
literal|"usage: pw groupshow [group|gid] [switches]\n"
literal|"\t-V etcdir      alternate /etc location\n"
literal|"\t-n name        group name\n"
literal|"\t-g gid         group id\n"
literal|"\t-F             force print\n"
literal|"\t-P             prettier format\n"
literal|"\t-a             print all accounting groups\n"
block|,
literal|"usage: pw groupnext [switches]\n"
literal|"\t-V etcdir      alternate /etc location\n"
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

begin_function
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
block|{
name|struct
name|carg
modifier|*
name|c
init|=
name|LIST_FIRST
argument_list|(
name|_args
argument_list|)
decl_stmt|;
while|while
condition|(
name|c
operator|!=
name|NULL
operator|&&
name|c
operator|->
name|ch
operator|!=
name|ch
condition|)
name|c
operator|=
name|LIST_NEXT
argument_list|(
name|c
argument_list|,
name|list
argument_list|)
expr_stmt|;
return|return
name|c
return|;
block|}
end_function

begin_function
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
block|{
name|struct
name|carg
modifier|*
name|ca
init|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|carg
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|ca
operator|==
name|NULL
condition|)
name|errx
argument_list|(
name|EX_OSERR
argument_list|,
literal|"out of memory"
argument_list|)
expr_stmt|;
name|ca
operator|->
name|ch
operator|=
name|ch
expr_stmt|;
name|ca
operator|->
name|val
operator|=
name|argstr
expr_stmt|;
name|LIST_INSERT_HEAD
argument_list|(
name|_args
argument_list|,
name|ca
argument_list|,
name|list
argument_list|)
expr_stmt|;
return|return
name|ca
return|;
block|}
end_function

end_unit

