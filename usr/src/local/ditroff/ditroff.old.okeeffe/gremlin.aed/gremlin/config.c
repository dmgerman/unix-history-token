begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)config.c	1.3	%G%  *  * This file contains a few strings that define file locations for  * the current gremlin configuration.  */
end_comment

begin_comment
comment|/* The following string must contain the rooted name of gremlin's  * library directory.  */
end_comment

begin_decl_stmt
name|char
name|GLibrary
index|[]
init|=
literal|"/usr/local/gremlib/"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The following string contains the full rooted name of the file  * giving the terminal-to-display mappings.  */
end_comment

begin_decl_stmt
name|char
name|GDisplays
index|[]
init|=
literal|"/usr/local/displays"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The following string gives the shell command used to send mail  * to the gremlin maintainer.  */
end_comment

begin_decl_stmt
name|char
name|GMailCommand
index|[]
init|=
literal|"/usr/ucb/Mail slatteng@ucbernie"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The following string should indicate the rooted name of gremlin's   * color map  */
end_comment

begin_decl_stmt
name|char
name|GMapFile
index|[]
init|=
literal|"/usr/local/gremlin.cmap"
decl_stmt|;
end_decl_stmt

end_unit

