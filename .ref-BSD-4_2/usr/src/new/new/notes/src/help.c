begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)help.c	1.2 2/1/83"
decl_stmt|;
end_decl_stmt

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
file|"parms.h"
end_include

begin_include
include|#
directive|include
file|"structs.h"
end_include

begin_comment
comment|/*  *	help(file) char *file;  *	prints the specified help file using more and then  *	does a pause with 'hit any key to continue.  *	  *	Original idea:	Rob Kolstad January 1982  */
end_comment

begin_macro
name|help
argument_list|(
argument|file
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|file
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|cmdline
index|[
name|CMDLEN
index|]
decl_stmt|;
comment|/* line buffer */
specifier|extern
name|char
modifier|*
name|mypager
decl_stmt|;
name|sprintf
argument_list|(
name|cmdline
argument_list|,
literal|"%s/%s/%s"
argument_list|,
name|MSTDIR
argument_list|,
name|UTILITY
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|dounix
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
name|mypager
argument_list|,
name|cmdline
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|wfchar
argument_list|()
expr_stmt|;
return|return;
block|}
end_block

end_unit

