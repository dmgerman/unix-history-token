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
literal|"$Header: nfcomment.c,v 1.7 85/01/18 15:25:46 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	nfcomment(nfname, text, title, dirflag, anonflag)  *	char *nfname, *text, *title;  *  *	Allows the user to insert notes into notesfiles from his programs.  *	The text is inserted into the notesfile 'nfname' with the   *	title specified. If dirflag or anonflag are non-null the  *	director or anonymous bits are enabled, provided the user has  *	permission.  *	If text is NULL, the text for the note will be taken from  *	standard input.  *  *	Original Coding:	Ray Essick	April 1982  */
end_comment

begin_function_decl
name|FILE
modifier|*
name|popen
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|nfcomment
argument_list|(
argument|nfname
argument_list|,
argument|text
argument_list|,
argument|title
argument_list|,
argument|dirflag
argument_list|,
argument|anonflag
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|nfname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|text
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|title
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|FILE
modifier|*
name|zpipe
decl_stmt|;
name|char
name|cmdline
index|[
name|CMDLEN
index|]
decl_stmt|;
if|if
condition|(
name|nfname
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"nfcomment: No notesfile specified\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|title
operator|==
name|NULL
condition|)
name|title
operator|=
literal|"From nfcomment"
expr_stmt|;
name|sprintf
argument_list|(
name|cmdline
argument_list|,
literal|"%s/nfpipe %s -t \"%s\" %s %s"
argument_list|,
name|BIN
argument_list|,
comment|/* where nfpipe lives */
name|nfname
argument_list|,
name|title
argument_list|,
name|dirflag
condition|?
literal|"-d"
else|:
literal|" "
argument_list|,
name|anonflag
condition|?
literal|"-a"
else|:
literal|" "
argument_list|)
expr_stmt|;
if|if
condition|(
name|text
operator|==
name|NULL
condition|)
block|{
name|system
argument_list|(
name|cmdline
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"EOT\n"
argument_list|)
expr_stmt|;
comment|/* let him know he hit EOT */
block|}
else|else
block|{
if|if
condition|(
operator|(
name|zpipe
operator|=
name|popen
argument_list|(
name|cmdline
argument_list|,
literal|"w"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
while|while
condition|(
operator|*
name|text
condition|)
name|putc
argument_list|(
operator|*
name|text
operator|++
argument_list|,
name|zpipe
argument_list|)
expr_stmt|;
name|pclose
argument_list|(
name|zpipe
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_block

end_unit

