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
comment|/*  * chproject - change current project  *  * Author: Peter J. Nicklin  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
file|"path.h"
end_include

begin_include
include|#
directive|include
file|"pdb.h"
end_include

begin_include
include|#
directive|include
file|"pld.h"
end_include

begin_include
include|#
directive|include
file|"spms.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program name */
end_comment

begin_decl_stmt
name|int
name|CSHELL
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C shell command interpreter flag */
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
name|int
name|chproject
parameter_list|()
function_decl|;
comment|/* change project */
name|int
name|dflag
init|=
name|NO
decl_stmt|;
comment|/* project description flag */
name|int
name|fflag
init|=
name|YES
decl_stmt|;
comment|/* execute PROJECTRC file */
name|int
name|status
init|=
literal|0
decl_stmt|;
comment|/* exit status */
name|void
name|mustchdir
parameter_list|()
function_decl|;
comment|/* must change directory */
name|void
name|printPROJECT
parameter_list|()
function_decl|;
comment|/* print PROJECT value */
name|void
name|printcd
parameter_list|()
function_decl|;
comment|/* print "cd" command */
name|void
name|printdesc
parameter_list|()
function_decl|;
comment|/* print project description */
name|void
name|printrc
parameter_list|()
function_decl|;
comment|/* print PROJECTRC execution request */
name|PGN
operator|=
name|pathtail
argument_list|(
operator|*
name|argv
argument_list|)
expr_stmt|;
if|if
condition|(
name|EQUAL
argument_list|(
name|pathtail
argument_list|(
name|getshell
argument_list|()
argument_list|)
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
literal|'d'
case|:
name|dflag
operator|=
name|YES
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
name|fflag
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
operator|!=
literal|1
condition|)
name|fatal
argument_list|(
literal|"usage: chproject [-df] projectname"
argument_list|)
expr_stmt|;
if|if
condition|(
name|chproject
argument_list|(
operator|*
name|argv
argument_list|)
operator|==
name|NO
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|mustchdir
argument_list|(
name|getcwp
argument_list|()
argument_list|)
expr_stmt|;
name|printcd
argument_list|(
name|getcwp
argument_list|()
argument_list|)
expr_stmt|;
name|printPROJECT
argument_list|()
expr_stmt|;
if|if
condition|(
name|fflag
operator|==
name|YES
operator|&&
name|FILEXIST
argument_list|(
name|PROJECTRC
argument_list|)
condition|)
name|printrc
argument_list|()
expr_stmt|;
if|if
condition|(
name|dflag
operator|==
name|YES
condition|)
name|printdesc
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * mustchdir() must change current working directory or die.  */
end_comment

begin_function
name|void
name|mustchdir
parameter_list|(
name|pathname
parameter_list|)
name|char
modifier|*
name|pathname
decl_stmt|;
comment|/* destination directory */
block|{
if|if
condition|(
operator|!
name|CHDIR
argument_list|(
name|pathname
argument_list|)
condition|)
name|fatal
argument_list|(
literal|"permission denied"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * printPROJECT prints PROJECT environment variable value.  */
end_comment

begin_function
name|void
name|printPROJECT
parameter_list|()
block|{
name|char
modifier|*
name|getcwp
parameter_list|()
function_decl|;
comment|/* get current working project */
if|if
condition|(
name|CSHELL
condition|)
name|printf
argument_list|(
literal|"; setenv PROJECT "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"; export PROJECT; PROJECT="
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|getcwp
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * printcd() prints the "cd" change directory command.  */
end_comment

begin_function
name|void
name|printcd
parameter_list|(
name|pathname
parameter_list|)
name|char
modifier|*
name|pathname
decl_stmt|;
comment|/* pathname of destination directory */
block|{
name|printf
argument_list|(
literal|"cd %s"
argument_list|,
name|pathname
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * printrc() prints the PROJECTRC project initialization file execution  * request.  */
end_comment

begin_function
name|void
name|printrc
parameter_list|()
block|{
if|if
condition|(
name|CSHELL
condition|)
name|printf
argument_list|(
literal|"; source %s"
argument_list|,
name|PROJECTRC
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"; . %s"
argument_list|,
name|PROJECTRC
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * printdesc() prints project description.  */
end_comment

begin_function
name|void
name|printdesc
parameter_list|()
block|{
name|char
name|dirdesc
index|[
name|DIRDESCSIZE
index|]
decl_stmt|;
comment|/* project directory description */
name|char
modifier|*
name|pbgetstring
parameter_list|()
function_decl|;
comment|/* get specified string field */
name|int
name|errpdb
parameter_list|()
function_decl|;
comment|/* print database error message */
name|int
name|pfndent
parameter_list|()
function_decl|;
comment|/* find and load database entry */
name|PDB
modifier|*
name|openpdb
parameter_list|()
function_decl|;
comment|/* open database */
name|PDB
modifier|*
name|pldp
decl_stmt|;
comment|/* project link directory stream */
if|if
condition|(
operator|(
name|pldp
operator|=
name|openpdb
argument_list|(
name|PLDNAME
argument_list|,
name|CURDIR
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|exit
argument_list|(
name|errpdb
argument_list|(
operator|(
name|PDB
operator|*
operator|)
name|NULL
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|pfndent
argument_list|(
name|CURPROJECT
argument_list|,
name|pldp
argument_list|)
operator|==
name|NO
condition|)
name|fatal
argument_list|(
literal|"can't find %s alias in %s"
argument_list|,
name|CURPROJECT
argument_list|,
name|pldp
operator|->
name|path
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|pbgetstring
argument_list|(
name|PDIRDESC
argument_list|,
name|dirdesc
argument_list|)
operator|!=
literal|'\0'
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|dirdesc
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

