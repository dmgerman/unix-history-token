begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header$"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * pexec - execute command over project hierarchy  *  * Author: Peter J. Nicklin  */
end_comment

begin_include
include|#
directive|include
file|"bin.h"
end_include

begin_include
include|#
directive|include
file|"macro.h"
end_include

begin_include
include|#
directive|include
file|"getarg.h"
end_include

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_include
include|#
directive|include
file|"path.h"
end_include

begin_include
include|#
directive|include
file|"pdtyp.h"
end_include

begin_include
include|#
directive|include
file|"slist.h"
end_include

begin_include
include|#
directive|include
file|"spms.h"
end_include

begin_include
include|#
directive|include
file|"yesno.h"
end_include

begin_decl_stmt
name|char
modifier|*
name|COMMAND
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command string to be executed */
end_comment

begin_decl_stmt
name|char
modifier|*
name|PGN
init|=
literal|"pexec"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SHELLNAME
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of command shell */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SHELLPATH
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pathname of command shell */
end_comment

begin_decl_stmt
name|int
name|CSHELL
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use csh or sh? */
end_comment

begin_decl_stmt
name|int
name|CSHRC
init|=
name|NO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* execute .cshrc if csh shell */
end_comment

begin_decl_stmt
name|int
name|DEBUG
init|=
name|NO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print pexec debugging info */
end_comment

begin_decl_stmt
name|int
name|ERRSTATUS
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pexec error status */
end_comment

begin_decl_stmt
name|int
name|EXECUTE
init|=
name|YES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* execute command? */
end_comment

begin_decl_stmt
name|int
name|IGNORE_BAD_EXIT
init|=
name|NO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* exit if command doesn't return 0 */
end_comment

begin_decl_stmt
name|int
name|NOQUERY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* query user about quitting? */
end_comment

begin_decl_stmt
name|int
name|PRINT_HEADING
init|=
name|YES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print headings for project dirs */
end_comment

begin_decl_stmt
name|int
name|PVINDEX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* environ index for PROJECT variable */
end_comment

begin_decl_stmt
name|PDTYP
name|PDIRTYP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* project directory type labels list */
end_comment

begin_decl_stmt
name|SLIST
modifier|*
name|ENVLIST
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* project environment variable list */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
specifier|extern
name|int
name|PPDEBUG
decl_stmt|;
comment|/* project pathname debug flag */
name|char
modifier|*
name|argvtos
parameter_list|()
function_decl|;
comment|/* convert cmd args to string */
name|char
modifier|*
name|getcwp
parameter_list|()
function_decl|;
comment|/* get current working project */
name|char
modifier|*
name|getshell
parameter_list|()
function_decl|;
comment|/* get command shell pathname */
name|char
modifier|*
name|pathtail
parameter_list|()
function_decl|;
comment|/* remove pathname head */
name|char
modifier|*
name|ppathname
init|=
name|CURPROJECT
decl_stmt|;
comment|/* project pathname */
name|int
name|atoi
parameter_list|()
function_decl|;
comment|/* string to integer conversion */
name|int
name|build_pdset
parameter_list|()
function_decl|;
comment|/* create set of project dirs */
name|int
name|ch_dir
parameter_list|()
function_decl|;
comment|/* change current working directory */
name|int
name|check_pdset
parameter_list|()
function_decl|;
comment|/* check ordering of set of proj dirs */
name|int
name|exec_pdset
parameter_list|()
function_decl|;
comment|/* execute cmds in set of proj dirs */
name|int
name|execcmd
parameter_list|()
function_decl|;
comment|/* execute command in directory */
name|int
name|getpvindex
parameter_list|()
function_decl|;
comment|/* get PROJECT env. variable index */
name|int
name|pdtparse
parameter_list|()
function_decl|;
comment|/* parse boolean type label expr */
name|int
name|status
init|=
literal|0
decl_stmt|;
comment|/* exit status */
name|int
name|xppath
parameter_list|()
function_decl|;
comment|/* expand project pathname */
name|PATH
name|pathbuf
decl_stmt|;
comment|/* pathname struct buffer */
name|SLIST
modifier|*
name|slinit
parameter_list|()
function_decl|;
comment|/* initialize list */
name|void
name|debug_pdset
parameter_list|()
function_decl|;
comment|/* print dirs + types after sorting */
name|void
name|init_pdset
parameter_list|()
function_decl|;
comment|/* initialize set of project dirs */
name|void
name|print_title
parameter_list|()
function_decl|;
comment|/* print project directory title */
name|void
name|sort_pdset
parameter_list|()
function_decl|;
comment|/* sort set of project dirs */
block|{
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
comment|/* option pointer */
while|while
condition|(
operator|--
name|argc
operator|>
literal|0
operator|&&
operator|*
operator|*
operator|++
name|argv
operator|==
literal|'-'
condition|)
block|{
for|for
control|(
name|s
operator|=
name|argv
index|[
literal|0
index|]
operator|+
literal|1
init|;
operator|*
name|s
operator|!=
literal|'\0'
condition|;
name|s
operator|++
control|)
switch|switch
condition|(
operator|*
name|s
condition|)
block|{
case|case
literal|'?'
case|:
name|NOQUERY
operator|++
expr_stmt|;
break|break;
case|case
literal|'D'
case|:
name|DEBUG
operator|=
name|YES
expr_stmt|;
name|PPDEBUG
operator|=
name|YES
expr_stmt|;
break|break;
case|case
literal|'P'
case|:
name|ppathname
operator|=
name|GETARG
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|ppathname
operator|==
literal|'\0'
condition|)
block|{
name|warn
argument_list|(
literal|"missing project name"
argument_list|)
expr_stmt|;
name|status
operator|=
literal|1
expr_stmt|;
block|}
goto|goto
name|endfor
goto|;
case|case
literal|'T'
case|:
if|if
condition|(
name|pdtparse
argument_list|(
name|GETARG
argument_list|(
name|s
argument_list|)
argument_list|,
operator|&
name|PDIRTYP
argument_list|)
operator|==
name|NO
condition|)
name|status
operator|=
literal|1
expr_stmt|;
goto|goto
name|endfor
goto|;
case|case
literal|'X'
case|:
name|ERRSTATUS
operator|=
name|atoi
argument_list|(
name|GETARG
argument_list|(
name|s
argument_list|)
argument_list|)
expr_stmt|;
goto|goto
name|endfor
goto|;
case|case
literal|'c'
case|:
name|CSHRC
operator|=
name|YES
expr_stmt|;
break|break;
case|case
literal|'i'
case|:
name|IGNORE_BAD_EXIT
operator|=
name|YES
expr_stmt|;
break|break;
case|case
literal|'q'
case|:
name|PRINT_HEADING
operator|=
name|NO
expr_stmt|;
break|break;
case|case
literal|'x'
case|:
name|EXECUTE
operator|=
name|NO
expr_stmt|;
break|break;
default|default:
name|warn
argument_list|(
literal|"bad option -%c"
argument_list|,
operator|*
name|s
argument_list|)
expr_stmt|;
name|status
operator|=
literal|1
expr_stmt|;
goto|goto
name|endfor
goto|;
block|}
name|endfor
label|:
continue|continue;
block|}
block|}
if|if
condition|(
name|status
operator|==
literal|1
operator|||
name|argc
operator|<
literal|1
condition|)
block|{
name|warn
argument_list|(
literal|"usage: pexec [-?ciqx] [-P pdirname] [-T typexpr] command"
argument_list|)
expr_stmt|;
name|pxexit
argument_list|()
expr_stmt|;
block|}
comment|/* 	 * The PROJECT environment variable must exist because 	 * it has to be modified before each command execution. 	 */
if|if
condition|(
operator|(
name|PVINDEX
operator|=
name|getpvindex
argument_list|()
operator|)
operator|<
literal|0
condition|)
block|{
name|warn
argument_list|(
literal|"no project environment"
argument_list|)
expr_stmt|;
name|pxexit
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|COMMAND
operator|=
name|argvtos
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|pxexit
argument_list|()
expr_stmt|;
name|SHELLPATH
operator|=
name|getshell
argument_list|()
expr_stmt|;
name|SHELLNAME
operator|=
name|pathtail
argument_list|(
name|SHELLPATH
argument_list|)
expr_stmt|;
if|if
condition|(
name|EQUAL
argument_list|(
name|SHELLNAME
argument_list|,
name|pathtail
argument_list|(
name|CSH
argument_list|)
argument_list|)
condition|)
name|CSHELL
operator|++
expr_stmt|;
comment|/* convert project pathname to regular pathname */
if|if
condition|(
name|xppath
argument_list|(
name|ppathname
argument_list|,
operator|&
name|pathbuf
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|patherr
argument_list|(
name|ppathname
argument_list|)
expr_stmt|;
name|pxexit
argument_list|()
expr_stmt|;
block|}
else|else
switch|switch
condition|(
name|pathbuf
operator|.
name|p_mode
operator|&
name|P_IFMT
condition|)
block|{
case|case
name|P_IFNEW
case|:
case|case
name|P_IFREG
case|:
name|warn
argument_list|(
literal|"%s: no such project or project directory"
argument_list|,
name|ppathname
argument_list|)
expr_stmt|;
name|pxexit
argument_list|()
expr_stmt|;
case|case
name|P_IFPDIR
case|:
name|IGNORE_BAD_EXIT
operator|=
name|NO
expr_stmt|;
if|if
condition|(
name|PRINT_HEADING
operator|==
name|YES
condition|)
name|print_title
argument_list|(
name|ppathname
argument_list|)
expr_stmt|;
name|ch_dir
argument_list|(
name|pathbuf
operator|.
name|p_path
argument_list|)
expr_stmt|;
if|if
condition|(
name|EXECUTE
operator|==
name|YES
condition|)
name|status
operator||=
name|execcmd
argument_list|(
name|pathbuf
operator|.
name|p_project
argument_list|)
expr_stmt|;
break|break;
case|case
name|P_IFHOME
case|:
case|case
name|P_IFPROOT
case|:
if|if
condition|(
name|PDIRTYP
operator|.
name|pfxsize
operator|==
literal|0
condition|)
name|status
operator||=
name|execproject
argument_list|(
name|ppathname
argument_list|,
name|pathbuf
operator|.
name|p_path
argument_list|)
expr_stmt|;
else|else
block|{
name|ENVLIST
operator|=
name|slinit
argument_list|()
expr_stmt|;
name|init_pdset
argument_list|()
expr_stmt|;
if|if
condition|(
name|build_pdset
argument_list|(
name|ppathname
argument_list|,
name|pathbuf
operator|.
name|p_path
argument_list|)
operator|!=
literal|0
condition|)
name|pxexit
argument_list|()
expr_stmt|;
name|sort_pdset
argument_list|()
expr_stmt|;
if|if
condition|(
name|DEBUG
operator|==
name|YES
condition|)
name|debug_pdset
argument_list|()
expr_stmt|;
if|if
condition|(
name|check_pdset
argument_list|()
operator|!=
literal|0
condition|)
name|pxexit
argument_list|()
expr_stmt|;
name|status
operator||=
name|exec_pdset
argument_list|()
expr_stmt|;
block|}
break|break;
block|}
name|exit
argument_list|(
name|status
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

