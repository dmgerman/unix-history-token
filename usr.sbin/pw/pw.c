begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 by David L. Nugent<davidn@blaze.net.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by David L. Nugent.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE DAVID L. NUGENT ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL DAVID L. NUGENT BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: pw.c,v 1.1.1.2 1996/12/09 23:55:20 joerg Exp $  */
end_comment

begin_include
include|#
directive|include
file|"pw.h"
end_include

begin_decl_stmt
specifier|static
name|char
modifier|*
name|progname
init|=
literal|"pw"
decl_stmt|;
end_decl_stmt

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
literal|"C:qn:u:c:d:e:p:g:G:mk:s:oL:i:w:h:Db:NP"
block|,
literal|"C:qn:u:r"
block|,
literal|"C:qn:u:c:d:e:p:g:G:mk:s:w:L:h:FNP"
block|,
literal|"C:qn:u:FPa"
block|,
literal|"C:q"
block|}
block|,
block|{
comment|/* grp  */
literal|"C:qn:g:h:M:pNP"
block|,
literal|"C:qn:g:"
block|,
literal|"C:qn:g:l:h:FM:m:NP"
block|,
literal|"C:qn:g:FPa"
block|,
literal|"C:q"
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
name|umask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* We wish to handle this manually */
end_comment

begin_expr_stmt
name|progname
operator|=
name|strrchr
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|progname
operator|!=
name|NULL
condition|)
operator|++
name|progname
expr_stmt|;
else|else
name|progname
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
end_if

begin_expr_stmt
name|LIST_INIT
argument_list|(
operator|&
name|arglist
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
operator|&&
operator|*
name|argv
index|[
literal|1
index|]
operator|!=
literal|'-'
condition|)
block|{
name|int
name|tmp
decl_stmt|;
if|if
condition|(
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
operator|&&
name|arglist
operator|.
name|lh_first
operator|==
name|NULL
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
name|cmderr
argument_list|(
name|EX_USAGE
argument_list|,
literal|"Unknown keyword `%s'\n"
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
name|argv
index|[
literal|0
index|]
operator|=
name|progname
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Preserve this */
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
name|cmderr
argument_list|(
name|EX_USAGE
argument_list|,
name|NULL
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
name|getuid
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
name|cmderr
argument_list|(
name|EX_NOPERM
argument_list|,
literal|"you must be root to run this program\n"
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
literal|"/dev/null"
argument_list|,
literal|"w"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* 	 * Now, let's do the common initialisation 	 */
end_comment

begin_expr_stmt
name|cnf
operator|=
name|read_userconfig
argument_list|(
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
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
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
return|;
end_return

begin_function
unit|}  static
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
name|banner
parameter_list|(
name|void
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|progname
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
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
block|{
if|if
condition|(
name|fmt
operator|!=
name|NULL
condition|)
block|{
name|va_list
name|argp
decl_stmt|;
name|banner
argument_list|()
expr_stmt|;
name|va_start
argument_list|(
name|argp
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
name|argp
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|argp
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
name|ec
argument_list|)
expr_stmt|;
block|}
end_function

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
name|banner
argument_list|()
expr_stmt|;
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
literal|"usage: %s [user|group] [add|del|mod|show|next] [ help | switches/values ]\n"
argument_list|,
name|progname
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
literal|"usage: %s %s [add|del|mod|show|next] [ help | switches/values ]\n"
argument_list|,
name|progname
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
literal|"usage: %s useradd [name] [switches]\n"
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
literal|"\t-s shell       name of login shell\n"
literal|"\t-o             duplicate uid ok\n"
literal|"\t-L class       user class\n"
literal|"\t-h fd          read password on fd\n"
literal|"\t-N             no update\n"
literal|"  Setting defaults:\n"
literal|"\t-D             set user defaults\n"
literal|"\t-b dir         default home root dir\n"
literal|"\t-e period      default expiry period\n"
literal|"\t-p period      default password change period\n"
literal|"\t-g group       default group\n"
literal|"\t-G grp1,grp2   additional groups\n"
literal|"\t-L class       default user class\n"
literal|"\t-k dir         default home skeleton\n"
literal|"\t-u min,max     set min,max uids\n"
literal|"\t-i min,max     set min,max gids\n"
literal|"\t-w method      set default password method\n"
literal|"\t-s shell       default shell\n"
block|,
literal|"usage: %s userdel [uid|name] [switches]\n"
literal|"\t-n name        login name\n"
literal|"\t-u uid         user id\n"
literal|"\t-r             remove home& contents\n"
block|,
literal|"usage: %s usermod [uid|name] [switches]\n"
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
literal|"\t-s shell       name of login shell\n"
literal|"\t-w method      set new password using method\n"
literal|"\t-h fd          read password on fd\n"
literal|"\t-N             no update\n"
block|,
literal|"usage: %s usershow [uid|name] [switches]\n"
literal|"\t-n name        login name\n"
literal|"\t-u uid         user id\n"
literal|"\t-F             force print\n"
literal|"\t-P             prettier format\n"
literal|"\t-a             print all users\n"
block|,
literal|"usage: %s usernext [switches]\n"
literal|"\t-C config      configuration file\n"
block|}
block|,
block|{
literal|"usage: %s groupadd [group|gid] [switches]\n"
literal|"\t-C config      configuration file\n"
literal|"\t-q             quiet operation\n"
literal|"\t-n group       group name\n"
literal|"\t-g gid         group id\n"
literal|"\t-M usr1,usr2   add users as group members\n"
literal|"\t-o             duplicate gid ok\n"
literal|"\t-N             no update\n"
block|,
literal|"usage: %s groupdel [group|gid] [switches]\n"
literal|"\t-n name        group name\n"
literal|"\t-g gid         group id\n"
block|,
literal|"usage: %s groupmod [group|gid] [switches]\n"
literal|"\t-C config      configuration file\n"
literal|"\t-q             quiet operation\n"
literal|"\t-F             force add if not exists\n"
literal|"\t-n name        group name\n"
literal|"\t-g gid         group id\n"
literal|"\t-M usr1,usr2   replaces users as group members\n"
literal|"\t-m usr1,usr2   add users as group members\n"
literal|"\t-l name        new group name\n"
literal|"\t-N             no update\n"
block|,
literal|"usage: %s groupshow [group|gid] [switches]\n"
literal|"\t-n name        group name\n"
literal|"\t-g gid         group id\n"
literal|"\t-F             force print\n"
literal|"\t-P             prettier format\n"
literal|"\t-a             print all accounting groups\n"
block|,
literal|"usage: %s groupnext [switches]\n"
literal|"\t-C config      configuration file\n"
block|}
block|}
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|help
index|[
name|which
index|]
index|[
name|mode
index|]
argument_list|,
name|progname
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
name|_args
operator|->
name|lh_first
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
name|c
operator|->
name|list
operator|.
name|le_next
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
name|cmderr
argument_list|(
name|EX_OSERR
argument_list|,
literal|"Abort - out of memory\n"
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

