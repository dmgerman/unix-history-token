begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)cur_hash.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * __hash() is "hashpjw" from the Dragon Book, Aho, Sethi& Ullman, p.436.  */
end_comment

begin_function
name|u_int
name|__hash
parameter_list|(
name|s
parameter_list|,
name|len
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
specifier|register
name|u_int
name|h
decl_stmt|,
name|g
decl_stmt|,
name|i
decl_stmt|;
name|h
operator|=
literal|0
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|i
operator|<
name|len
condition|)
block|{
name|h
operator|=
operator|(
name|h
operator|<<
literal|4
operator|)
operator|+
name|s
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|g
operator|=
name|h
operator|&
literal|0xf0000000
condition|)
block|{
name|h
operator|=
name|h
operator|^
operator|(
name|g
operator|>>
literal|24
operator|)
expr_stmt|;
name|h
operator|=
name|h
operator|^
name|g
expr_stmt|;
block|}
name|i
operator|++
expr_stmt|;
block|}
return|return
name|h
return|;
block|}
end_function

end_unit

