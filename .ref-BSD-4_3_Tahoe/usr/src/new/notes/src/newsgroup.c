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

begin_include
include|#
directive|include
file|"newsgate.h"
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
literal|"$Header: newsgroup.c,v 1.7 85/01/18 15:21:09 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	newsgroup(lookfor, mapped,direct)  *  *	This routine looks in the file specified by NEWSALIAS  *	for a correspondence between the notesfile name supplied   *	and a news(1) newsgroup.  *	The resultant match is placed where the second parameter points.  *	In the event of no match, the same name is passed back.  *  *	direct gives us the direction of mapping:   *	NFNEWS says that lookfor is a notesfile and we find a newsgroup  *	NEWSNF says that lookfor is a newsgroup and we find a nf  *	in both cases lookfor is the input and mapped is the output  *  *	Original Coding:	Ray Essick	April 7, 1982  */
end_comment

begin_macro
name|newsgroup
argument_list|(
argument|lookfor
argument_list|,
argument|mapped
argument_list|,
argument|direct
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|lookfor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mapped
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|FILE
modifier|*
name|groups
decl_stmt|;
name|char
name|linebuf
index|[
name|CMDLEN
index|]
decl_stmt|;
comment|/* lines in file */
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|,
modifier|*
name|r
decl_stmt|;
name|int
name|c
decl_stmt|;
name|strcpy
argument_list|(
name|mapped
argument_list|,
name|lookfor
argument_list|)
expr_stmt|;
comment|/* ready to fail */
name|sprintf
argument_list|(
name|linebuf
argument_list|,
literal|"%s/%s/%s"
argument_list|,
name|Mstdir
argument_list|,
name|UTILITY
argument_list|,
name|NEWSALIAS
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|groups
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
name|groups
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
name|groups
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
comment|/* comment or empty */
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
comment|/* formatted ok? */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Bad line in newsgroup file: %s\n"
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
comment|/* break into parts */
comment|/*  *	Grab the `response' group if there is one.  */
name|r
operator|=
name|q
expr_stmt|;
comment|/* start here */
while|while
condition|(
operator|*
name|r
operator|!=
literal|':'
operator|&&
operator|*
name|r
condition|)
name|r
operator|++
expr_stmt|;
comment|/* not this one */
if|if
condition|(
operator|*
name|r
operator|==
literal|':'
condition|)
comment|/* we have a response group */
block|{
operator|*
name|r
operator|++
operator|=
literal|'\0'
expr_stmt|;
comment|/* null terminate base group */
if|if
condition|(
operator|!
operator|*
name|r
condition|)
comment|/* see if empty field */
name|r
operator|=
name|q
expr_stmt|;
comment|/* give it base group */
block|}
else|else
block|{
name|r
operator|=
name|q
expr_stmt|;
comment|/* base group */
block|}
comment|/*  *	Now decide which to match and which to fill  */
switch|switch
condition|(
name|direct
condition|)
comment|/* which direction */
block|{
case|case
name|NFBASENEWS
case|:
comment|/* notesfile base note */
if|if
condition|(
name|strcmp
argument_list|(
name|linebuf
argument_list|,
name|lookfor
argument_list|)
operator|==
literal|0
condition|)
comment|/* match ? */
block|{
name|strcpy
argument_list|(
name|mapped
argument_list|,
name|q
argument_list|)
expr_stmt|;
comment|/* copy it to caller */
name|fclose
argument_list|(
name|groups
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
comment|/* success */
block|}
break|break;
comment|/* out of switch */
case|case
name|NEWSNF
case|:
comment|/* newsgroup to notesfile */
if|if
condition|(
name|strcmp
argument_list|(
name|q
argument_list|,
name|lookfor
argument_list|)
operator|==
literal|0
condition|)
block|{
name|strcpy
argument_list|(
name|mapped
argument_list|,
name|linebuf
argument_list|)
expr_stmt|;
comment|/* move find */
name|fclose
argument_list|(
name|groups
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
comment|/* success */
block|}
break|break;
comment|/* from switch */
case|case
name|NFRESPNEWS
case|:
comment|/* nf response to news */
if|if
condition|(
name|strcmp
argument_list|(
name|linebuf
argument_list|,
name|lookfor
argument_list|)
operator|==
literal|0
condition|)
comment|/* match ? */
block|{
name|strcpy
argument_list|(
name|mapped
argument_list|,
name|r
argument_list|)
expr_stmt|;
comment|/* copy to caller */
name|fclose
argument_list|(
name|groups
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
comment|/* success */
block|}
break|break;
comment|/* out of switch */
default|default:
name|fclose
argument_list|(
name|groups
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* what the heck */
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

