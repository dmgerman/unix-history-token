begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)bsearch.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* size_t */
end_comment

begin_comment
comment|/*  * Perform a binary search.  *  * The code below is a bit sneaky.  After a comparison fails, we  * divide the work in half by moving either left or right. If lim  * is odd, moving left simply involves halving lim: e.g., when lim  * is 5 we look at item 2, so we change lim to 2 so that we will  * look at items 0& 1.  If lim is even, the same applies.  If lim  * is odd, moving right again involes halving lim, this time moving  * the base up one item past p: e.g., when lim is 5 we change base  * to item 3 and make lim 2 so that we will look at items 3 and 4.  * If lim is even, however, we have to shrink it by one before  * halving: e.g., when lim is 4, we still looked at item 2, so we  * have to make lim 3, then halve, obtaining 1, so that we will only  * look at item 3.  */
end_comment

begin_decl_stmt
name|void
modifier|*
name|bsearch
argument_list|(
name|key
argument_list|,
name|base0
argument_list|,
name|nmemb
argument_list|,
name|size
argument_list|,
name|compar
argument_list|)
decl|register
name|void
modifier|*
name|key
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|base0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|nmemb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|size_t
name|size
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|register
name|int
function_decl|(
modifier|*
name|compar
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_block
block|{
specifier|register
name|char
modifier|*
name|base
init|=
name|base0
decl_stmt|;
specifier|register
name|int
name|lim
decl_stmt|,
name|cmp
decl_stmt|;
specifier|register
name|void
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|lim
operator|=
name|nmemb
init|;
name|lim
operator|!=
literal|0
condition|;
name|lim
operator|>>=
literal|1
control|)
block|{
name|p
operator|=
name|base
operator|+
operator|(
name|lim
operator|>>
literal|1
operator|)
operator|*
name|size
expr_stmt|;
name|cmp
operator|=
call|(
modifier|*
name|compar
call|)
argument_list|(
name|key
argument_list|,
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|cmp
operator|==
literal|0
condition|)
return|return
operator|(
name|p
operator|)
return|;
if|if
condition|(
name|cmp
operator|>
literal|0
condition|)
block|{
comment|/* key> p: move right */
name|base
operator|=
operator|(
name|char
operator|*
operator|)
name|p
operator|+
name|size
expr_stmt|;
name|lim
operator|--
expr_stmt|;
block|}
comment|/* else move left */
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_block

end_unit

