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
literal|"$Header: check.c,v 1.7 85/01/18 15:06:01 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	check.c - checks the arguement supplied. If there are any  *	.'s or /'s in the name a -1 is returned.   *	If the string is . and / free, then a zero is returned.  *  *	Ray Essick	23-nov-1981  */
end_comment

begin_macro
name|chkpath
argument_list|(
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|count
decl_stmt|;
if|if
condition|(
operator|*
name|p
operator|==
literal|'.'
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* hidden is bad */
name|count
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|*
name|p
operator|&&
operator|(
operator|*
name|p
operator|!=
literal|'/'
operator|)
operator|&&
operator|(
operator|*
name|p
operator|!=
literal|' '
operator|)
operator|&&
operator|(
operator|*
name|p
operator|!=
literal|':'
operator|)
condition|)
block|{
name|count
operator|++
expr_stmt|;
name|p
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|count
operator|>
name|NNLEN
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* name too long */
if|if
condition|(
operator|*
name|p
operator|==
literal|0
condition|)
return|return
literal|0
return|;
else|else
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  *	patcheck - look for a pattern character. These are the shell  *	meta-characters ?, [, and *  *	Return 0 if non exist in the string  */
end_comment

begin_macro
name|patcheck
argument_list|(
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|q
decl_stmt|;
name|q
operator|=
name|p
expr_stmt|;
while|while
condition|(
operator|*
name|q
operator|&&
operator|(
operator|*
name|q
operator|!=
literal|'?'
operator|)
operator|&&
operator|(
operator|*
name|q
operator|!=
literal|'['
operator|)
operator|&&
operator|(
operator|*
name|q
operator|!=
literal|'*'
operator|)
condition|)
name|q
operator|++
expr_stmt|;
return|return
operator|(
operator|*
name|q
operator|!=
literal|'\0'
operator|)
return|;
comment|/* return 0 if no pattern */
block|}
end_block

end_unit

