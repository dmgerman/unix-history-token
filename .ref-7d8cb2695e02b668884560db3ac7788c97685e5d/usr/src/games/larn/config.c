begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	config.c	--	This defines the installation dependent variables.  *                  Some strings are modified later.  ANSI C would  *                  allow compile time string concatenation, we must  *                  do runtime concatenation, in main.  *  *		Larn is copyrighted 1986 by Noah Morgan.  */
end_comment

begin_include
include|#
directive|include
file|"header.h"
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_comment
comment|/*  *	All these strings will be appended to in main() to be complete filenames  */
end_comment

begin_comment
comment|/* the game save filename */
end_comment

begin_decl_stmt
name|char
name|savefilename
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the logging file */
end_comment

begin_decl_stmt
name|char
name|logfile
index|[]
init|=
name|_PATH_LOG
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the help text file */
end_comment

begin_decl_stmt
name|char
name|helpfile
index|[]
init|=
name|_PATH_HELP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the score file */
end_comment

begin_decl_stmt
name|char
name|scorefile
index|[]
init|=
name|_PATH_SCORE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the maze data file */
end_comment

begin_decl_stmt
name|char
name|larnlevels
index|[]
init|=
name|_PATH_LEVELS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the fortune data file */
end_comment

begin_decl_stmt
name|char
name|fortfile
index|[]
init|=
name|_PATH_FORTS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the .larnopts filename */
end_comment

begin_decl_stmt
name|char
name|optsfile
index|[
literal|1024
index|]
init|=
literal|"/.larnopts"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the player id datafile name */
end_comment

begin_decl_stmt
name|char
name|playerids
index|[]
init|=
name|_PATH_PLAYERIDS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|diagfile
index|[]
init|=
literal|"Diagfile"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the diagnostic filename */
end_comment

begin_decl_stmt
name|char
name|ckpfile
index|[]
init|=
literal|"Larn12.0.ckp"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the checkpoint filename */
end_comment

begin_decl_stmt
name|char
modifier|*
name|password
init|=
literal|"pvnert(x)"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the wizards password<=32 */
end_comment

begin_decl_stmt
name|char
name|psname
index|[
name|PSNAMESIZE
index|]
init|=
literal|"larn"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the process name */
end_comment

begin_define
define|#
directive|define
name|WIZID
value|1
end_define

begin_decl_stmt
name|int
name|wisid
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the user id of the only person who can be wizard */
end_comment

end_unit

