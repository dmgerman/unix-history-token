begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)strcmpn.c	4.3 (Berkeley) 3/9/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_comment
comment|/*  * Compare strings (at most n bytes):  s1>s2:>0  s1==s2: 0  s1<s2:<0  */
end_comment

begin_expr_stmt
name|strcmpn
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|,
name|n
argument_list|)
specifier|register
name|char
operator|*
name|s1
operator|,
operator|*
name|s2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|register
name|n
expr_stmt|;
end_expr_stmt

begin_block
block|{
while|while
condition|(
operator|--
name|n
operator|>=
literal|0
operator|&&
operator|*
name|s1
operator|==
operator|*
name|s2
operator|++
condition|)
if|if
condition|(
operator|*
name|s1
operator|++
operator|==
literal|'\0'
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
name|n
operator|<
literal|0
condition|?
literal|0
else|:
operator|*
name|s1
operator|-
operator|*
operator|--
name|s2
operator|)
return|;
block|}
end_block

end_unit

