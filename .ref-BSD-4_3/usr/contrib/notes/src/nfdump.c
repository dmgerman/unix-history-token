begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|MAINLINE
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|RCSIDENT
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Header: nfdump.c,v 1.7.0.1 85/10/09 18:07:40 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

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
name|int
name|i
decl_stmt|;
if|if
condition|(
name|argc
operator|!=
literal|2
condition|)
block|{
name|printf
argument_list|(
literal|"Usage: %s notesfile\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|startup
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
comment|/*       * the "-" is vestigal from the days when this routine       * accepted a file. we force it out stdout now.      * it would be nice to have /dev/stdout type names      * or to merely change the arg to be a file descriptor      */
name|i
operator|=
name|dumpnf
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"-"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"dumpnf returned %d\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

