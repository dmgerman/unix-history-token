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
comment|/*  * phelp - on-line help for a project  *  * Author: Peter J. Nicklin  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"getarg.h"
end_include

begin_include
include|#
directive|include
file|"macro.h"
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
file|"phelp.h"
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
name|PGN
init|=
literal|"phelp"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program name */
end_comment

begin_decl_stmt
name|char
name|PHELP_CMD
index|[
name|PATHSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* help command file pathname */
end_comment

begin_decl_stmt
name|char
name|PHELP_HELP
index|[
name|PATHSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* help introduction file pathname */
end_comment

begin_decl_stmt
name|int
name|INTERACTIVE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* phelp interactive? */
end_comment

begin_decl_stmt
name|int
name|HELPLEVEL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* help hierarchy level */
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
name|getcwp
parameter_list|()
function_decl|;
comment|/* get current working project */
name|char
modifier|*
name|pathcat
parameter_list|()
function_decl|;
comment|/* pathname concatenation */
name|char
modifier|*
name|ppathname
init|=
name|CURPROJECT
decl_stmt|;
comment|/* project pathname */
name|int
name|isintract
parameter_list|()
function_decl|;
comment|/* find out if interactive */
name|int
name|printhelp
parameter_list|()
function_decl|;
comment|/* print a help file */
name|int
name|printtopic
parameter_list|()
function_decl|;
comment|/* print topic file and index */
name|int
name|processtopic
parameter_list|()
function_decl|;
comment|/* process help topic on stack */
name|int
name|status
init|=
literal|0
decl_stmt|;
comment|/* exit status */
name|void
name|gettopic
parameter_list|()
function_decl|;
comment|/* get next help topic from stdin */
name|void
name|printnotopics
parameter_list|()
function_decl|;
comment|/* print "no topics" error message */
name|void
name|prompt
parameter_list|()
function_decl|;
comment|/* prompt for a topic */
name|void
name|puttopic
parameter_list|()
function_decl|;
comment|/* add help topic to request queue */
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
literal|'D'
case|:
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
condition|)
name|fatal
argument_list|(
literal|"usage: phelp [-P projectname] [topic [subtopic ...]]"
argument_list|)
expr_stmt|;
if|if
condition|(
name|getcwp
argument_list|()
operator|==
name|NULL
condition|)
name|fatal
argument_list|(
literal|"There is no project environment"
argument_list|)
expr_stmt|;
if|if
condition|(
name|chghelp
argument_list|(
name|ppathname
argument_list|)
operator|==
name|NO
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|pathcat
argument_list|(
name|PHELP_CMD
argument_list|,
name|SPMSLIB
argument_list|,
name|PHELP_CMD_FILE
argument_list|)
expr_stmt|;
name|pathcat
argument_list|(
name|PHELP_HELP
argument_list|,
name|SPMSLIB
argument_list|,
name|PHELP_HELP_FILE
argument_list|)
expr_stmt|;
name|INTERACTIVE
operator|=
name|isintract
argument_list|()
expr_stmt|;
if|if
condition|(
name|argc
operator|==
literal|0
operator|||
operator|(
name|argc
operator|==
literal|1
operator|&&
name|PHELP
operator|)
condition|)
block|{
comment|/* general introduction */
if|if
condition|(
name|printtopic
argument_list|(
name|PHELP_HELP
argument_list|,
name|CURDIR
argument_list|)
operator|>
literal|1
condition|)
block|{
name|printnotopics
argument_list|(
name|ppathname
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* command line arguments */
while|while
condition|(
name|argc
operator|--
operator|>
literal|0
condition|)
name|puttopic
argument_list|(
operator|*
name|argv
operator|++
argument_list|)
expr_stmt|;
name|status
operator|=
name|processtopic
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|INTERACTIVE
operator|==
name|YES
condition|)
comment|/* further help topics */
while|while
condition|(
name|HELPLEVEL
operator|>=
literal|0
condition|)
block|{
name|prompt
argument_list|()
expr_stmt|;
name|gettopic
argument_list|()
expr_stmt|;
name|status
operator|=
name|processtopic
argument_list|()
expr_stmt|;
block|}
name|exit
argument_list|(
name|status
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * chghelp() changes to another help hierarchy. Returns YES if  * successful, otherwise NO.  */
end_comment

begin_macro
name|chghelp
argument_list|(
argument|ppathname
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|ppathname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* project pathname */
end_comment

begin_block
block|{
name|char
name|helpath
index|[
name|PATHSIZE
index|]
decl_stmt|;
comment|/* help directory pathname */
name|char
modifier|*
name|oldcwp
decl_stmt|;
comment|/* old current working project */
name|char
modifier|*
name|pathcat
parameter_list|()
function_decl|;
comment|/* pathname concatenation */
name|char
modifier|*
name|strsav
parameter_list|()
function_decl|;
comment|/* save a string somewhere */
name|int
name|chproject
parameter_list|()
function_decl|;
comment|/* change project */
name|void
name|printnotopics
parameter_list|()
function_decl|;
comment|/* print "no topics" error message */
name|oldcwp
operator|=
name|strsav
argument_list|(
name|getcwp
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|chproject
argument_list|(
name|ppathname
argument_list|)
operator|==
name|NO
condition|)
block|{
name|free
argument_list|(
name|oldcwp
argument_list|)
expr_stmt|;
return|return
operator|(
name|NO
operator|)
return|;
block|}
name|pathcat
argument_list|(
name|helpath
argument_list|,
name|getcwp
argument_list|()
argument_list|,
literal|"help"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|CHDIR
argument_list|(
name|helpath
argument_list|)
condition|)
block|{
name|printnotopics
argument_list|(
name|ppathname
argument_list|)
expr_stmt|;
return|return
operator|(
name|NO
operator|)
return|;
block|}
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * mkndir() makes a directory name by appending ".d" to a topic name.  */
end_comment

begin_function
name|char
modifier|*
name|mkndir
parameter_list|(
name|basename
parameter_list|)
name|char
modifier|*
name|basename
decl_stmt|;
comment|/* topic name */
block|{
specifier|static
name|char
name|dirnam
index|[
name|MAXNAMLEN
index|]
decl_stmt|;
comment|/* directory name buffer */
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
comment|/* string copy */
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
comment|/* string concatenation */
name|strcpy
argument_list|(
name|dirnam
argument_list|,
name|basename
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|dirnam
argument_list|,
literal|".d"
argument_list|)
expr_stmt|;
return|return
operator|(
name|dirnam
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * printhelp() prints a help file on output stream ofp. Returns YES if  * file can be opened and read, otherwise NO.  */
end_comment

begin_macro
name|printhelp
argument_list|(
argument|helpfile
argument_list|,
argument|ofp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|helpfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file containing help information */
end_comment

begin_decl_stmt
specifier|register
name|FILE
modifier|*
name|ofp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output stream */
end_comment

begin_block
block|{
specifier|register
name|FILE
modifier|*
name|ifp
decl_stmt|;
comment|/* input file stream */
specifier|register
name|int
name|c
decl_stmt|;
comment|/* current character */
name|FILE
modifier|*
name|fopen
parameter_list|()
function_decl|;
comment|/* open file */
if|if
condition|(
operator|(
name|ifp
operator|=
name|fopen
argument_list|(
name|helpfile
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NO
operator|)
return|;
if|if
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|ifp
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
block|{
name|putc
argument_list|(
name|c
argument_list|,
name|ofp
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|ifp
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
name|putc
argument_list|(
name|c
argument_list|,
name|ofp
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
return|return
operator|(
name|YES
operator|)
return|;
block|}
else|else
block|{
name|fclose
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
return|return
operator|(
name|NO
operator|)
return|;
block|}
block|}
end_block

begin_comment
comment|/* printtopic() prints a help topic plus a list of available subtopics. The  * output is piped through more(1) if phelp is interactive. Returns 0 if  * topic and subtopics printed; 1 if subtopics printed only; 2 if file printed  * only; 3 if nothing printed.  */
end_comment

begin_macro
name|printtopic
argument_list|(
argument|topic
argument_list|,
argument|subtopicdir
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|topic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of topic file to be printed */
end_comment

begin_decl_stmt
name|char
modifier|*
name|subtopicdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of subtopic directory */
end_comment

begin_block
block|{
name|FILE
modifier|*
name|popen
parameter_list|()
function_decl|;
comment|/* open pipe for writing */
name|FILE
modifier|*
name|ofp
decl_stmt|;
comment|/* output stream */
name|int
name|mkindex
parameter_list|()
function_decl|;
comment|/* make topic index */
name|int
name|printhelp
parameter_list|()
function_decl|;
comment|/* print help file */
name|int
name|status
init|=
literal|0
decl_stmt|;
comment|/* printhelp status */
name|void
name|printindex
parameter_list|()
function_decl|;
comment|/* print topic index */
if|if
condition|(
name|INTERACTIVE
operator|==
name|NO
operator|||
operator|(
name|ofp
operator|=
name|popen
argument_list|(
literal|"more -d"
argument_list|,
literal|"w"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|ofp
operator|=
name|stdout
expr_stmt|;
if|if
condition|(
name|printhelp
argument_list|(
name|topic
argument_list|,
name|ofp
argument_list|)
operator|==
name|NO
condition|)
name|status
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|mkindex
argument_list|(
name|subtopicdir
argument_list|)
operator|==
name|YES
condition|)
name|printindex
argument_list|(
name|ofp
argument_list|)
expr_stmt|;
else|else
name|status
operator|+=
literal|2
expr_stmt|;
if|if
condition|(
name|ofp
operator|!=
name|stdout
condition|)
name|pclose
argument_list|(
name|ofp
argument_list|)
expr_stmt|;
return|return
operator|(
name|status
operator|)
return|;
block|}
end_block

end_unit

