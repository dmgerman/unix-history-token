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
literal|"$Header: nfalias.c,v 1.7 85/01/18 15:24:36 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_include
include|#
directive|include
file|"net.h"
end_include

begin_comment
comment|/*  *	nfalias(local, remote, remotesys)  *	char *local, *remote, *remotesys;  *  *	nfalias looks in the alias file for the remote system and  *	tries to find a match for the local notesfile.  *	If a match is found, it is copied to *remote, otherwise   *	the original name is copied over.  *  *	The routine returns -1 if there is no file.  *	A zero is returned if no match is found.  *	A 1 is returned if a match is found.  *  *	Original Coding:	Ray Essick	April 25, 1982  */
end_comment

begin_macro
name|nfalias
argument_list|(
argument|local
argument_list|,
argument|remote
argument_list|,
argument|remotesys
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|local
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|remote
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|remotesys
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|FILE
modifier|*
name|aliases
decl_stmt|;
name|char
name|linebuf
index|[
literal|100
index|]
decl_stmt|;
comment|/* hold lines from file */
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|;
name|int
name|c
decl_stmt|;
name|strcpy
argument_list|(
name|remote
argument_list|,
name|local
argument_list|)
expr_stmt|;
comment|/* pessimism - ready to fail */
name|sprintf
argument_list|(
name|linebuf
argument_list|,
literal|"%s/%s/%s/%s"
argument_list|,
name|Mstdir
argument_list|,
name|UTILITY
argument_list|,
name|ALIASES
argument_list|,
name|remotesys
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|aliases
operator|=
name|fopen
argument_list|(
name|linebuf
argument_list|,
literal|"r"
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
comment|/* no file, too bad */
while|while
condition|(
literal|1
condition|)
block|{
name|p
operator|=
name|linebuf
expr_stmt|;
comment|/* start line */
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|aliases
argument_list|)
operator|)
operator|!=
name|EOF
operator|&&
name|c
operator|!=
literal|'\n'
condition|)
operator|*
name|p
operator|++
operator|=
name|c
expr_stmt|;
if|if
condition|(
name|c
operator|==
name|EOF
condition|)
block|{
name|fclose
argument_list|(
name|aliases
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|/* no match */
block|}
operator|*
name|p
operator|=
literal|'\0'
expr_stmt|;
comment|/* terminate string */
if|if
condition|(
name|linebuf
index|[
literal|0
index|]
operator|==
literal|'#'
operator|||
name|linebuf
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
continue|continue;
comment|/* comment or empty line */
name|q
operator|=
name|linebuf
expr_stmt|;
comment|/* find colon */
while|while
condition|(
operator|*
name|q
operator|!=
literal|':'
operator|&&
operator|*
name|q
condition|)
name|q
operator|++
expr_stmt|;
comment|/* try next */
if|if
condition|(
operator|*
name|q
operator|!=
literal|':'
condition|)
comment|/* properly formatted? */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Bad line in alias file for system %s: %s\n"
argument_list|,
name|remotesys
argument_list|,
name|linebuf
argument_list|)
expr_stmt|;
continue|continue;
comment|/* skip the line */
block|}
operator|*
name|q
operator|++
operator|=
literal|'\0'
expr_stmt|;
comment|/* break into two parts */
if|if
condition|(
name|strcmp
argument_list|(
name|linebuf
argument_list|,
name|local
argument_list|)
operator|==
literal|0
condition|)
comment|/* match ? */
block|{
name|strcpy
argument_list|(
name|remote
argument_list|,
name|q
argument_list|)
expr_stmt|;
comment|/* copy the name over */
name|fclose
argument_list|(
name|aliases
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
comment|/* success */
block|}
block|}
comment|/*	yes, we know that this statement is unreachable! */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* to satisfy lint */
block|}
end_block

end_unit

