begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Copyright (c) 1984, 1985, 1986 by the Regents of the  *	University of California and by Gregory Glenn Minshall.  *  *	Permission to use, copy, modify, and distribute these  *	programs and their documentation for any purpose and  *	without fee is hereby granted, provided that this  *	copyright and permission appear on all copies and  *	supporting documentation, the name of the Regents of  *	the University of California not be used in advertising  *	or publicity pertaining to distribution of the programs  *	without specific prior permission, and notice be given in  *	supporting documentation that copying and distribution is  *	by permission of the Regents of the University of California  *	and by Gregory Glenn Minshall.  Neither the Regents of the  *	University of California nor Gregory Glenn Minshall make  *	representations about the suitability of this software  *	for any purpose.  It is provided "as is" without  *	express or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)genbsubs.c	3.1  10/29/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef lint */
end_comment

begin_comment
comment|/* The output of bunequal is the offset of the byte which didn't match;  * if all the bytes match, then we return n.  * bunequal(s1, s2, n) */
end_comment

begin_decl_stmt
name|int
name|bunequal
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|,
name|n
argument_list|)
decl|register
name|char
modifier|*
name|s1
decl_stmt|,
modifier|*
name|s2
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|register
name|n
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|++
operator|<
name|n
condition|)
block|{
if|if
condition|(
operator|*
name|s1
operator|++
operator|!=
operator|*
name|s2
operator|++
condition|)
block|{
break|break;
block|}
block|}
return|return
operator|(
name|i
operator|-
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/* bskip(s1, n, b) : finds the first occurrence of any byte != 'b' in the 'n'  * bytes beginning at 's1'.  */
end_comment

begin_function
name|int
name|bskip
parameter_list|(
name|s1
parameter_list|,
name|n
parameter_list|,
name|b
parameter_list|)
specifier|register
name|char
modifier|*
name|s1
decl_stmt|;
specifier|register
name|int
name|n
decl_stmt|;
specifier|register
name|int
name|b
decl_stmt|;
block|{
specifier|register
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|++
operator|<
name|n
condition|)
block|{
if|if
condition|(
operator|*
name|s1
operator|++
operator|!=
name|b
condition|)
block|{
break|break;
block|}
block|}
return|return
operator|(
name|i
operator|-
literal|1
operator|)
return|;
block|}
end_function

end_unit

