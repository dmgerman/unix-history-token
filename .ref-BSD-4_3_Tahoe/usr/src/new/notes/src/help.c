begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"$Header: help.c,v 1.7 85/01/18 15:13:16 notes Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

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
name|char
modifier|*
name|command
decl_stmt|;
if|if
condition|(
operator|(
name|command
operator|=
name|getenv
argument_list|(
literal|"PAGER"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
comment|/* see if overridden */
name|command
operator|=
name|PAGER
expr_stmt|;
comment|/* assign default */
ifndef|#
directive|ifndef
name|FASTFORK
name|sprintf
argument_list|(
name|cmdline
argument_list|,
literal|"%s< %s/%s/%s"
argument_list|,
name|command
argument_list|,
name|Mstdir
argument_list|,
name|UTILITY
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|dounix
argument_list|(
name|cmdline
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* set tty flags */
else|#
directive|else
name|sprintf
argument_list|(
name|cmdline
argument_list|,
literal|"%s/%s/%s"
argument_list|,
name|Mstdir
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
name|command
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
endif|#
directive|endif
comment|/* and to his uid */
name|printf
argument_list|(
literal|"  --Hit any key to continue--"
argument_list|)
expr_stmt|;
name|gchar
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

