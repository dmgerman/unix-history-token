begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)string.c	1.1 (Berkeley) 3/2/81"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_empty
empty|#
end_empty

begin_comment
comment|/*  * pxp - Pascal execution profiler  *  * Bill Joy UCB  * Version 1.2 January 1979  */
end_comment

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_comment
comment|/*  * STRING SPACE DECLARATIONS  *  * Strng is the base of the current  * string space and strngp the  * base of the free area therein.  * No array of descriptors is needed  * as string space is never freed.  */
end_comment

begin_decl_stmt
name|STATIC
name|char
name|strings
index|[
name|STRINC
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STATIC
name|char
modifier|*
name|strng
name|strings
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STATIC
name|char
modifier|*
name|strngp
name|strings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initstring() {  }  */
end_comment

begin_comment
comment|/*  * Copy a string into the string area.  */
end_comment

begin_expr_stmt
name|savestr
argument_list|(
name|cp
argument_list|)
specifier|register
name|char
operator|*
name|cp
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|i
operator|=
name|strlen
argument_list|(
name|cp
argument_list|)
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|strngp
operator|+
name|i
operator|>=
name|strng
operator|+
name|STRINC
condition|)
block|{
name|strngp
operator|=
name|alloc
argument_list|(
name|STRINC
argument_list|)
expr_stmt|;
if|if
condition|(
name|strngp
operator|==
operator|-
literal|1
condition|)
block|{
name|yerror
argument_list|(
literal|"Ran out of memory (string)"
argument_list|)
expr_stmt|;
name|pexit
argument_list|(
name|DIED
argument_list|)
expr_stmt|;
block|}
name|strng
operator|=
name|strngp
expr_stmt|;
block|}
name|strcpy
argument_list|(
name|strngp
argument_list|,
name|cp
argument_list|)
expr_stmt|;
name|cp
operator|=
name|strngp
expr_stmt|;
name|strngp
operator|=
name|cp
operator|+
name|i
expr_stmt|;
return|return
operator|(
name|cp
operator|)
return|;
block|}
end_block

begin_macro
name|esavestr
argument_list|(
argument|cp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|strngp
operator|=
call|(
name|int
call|)
argument_list|(
name|strngp
operator|+
operator|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|-
literal|1
operator|)
argument_list|)
operator|&
operator|~
operator|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|-
literal|1
operator|)
expr_stmt|;
return|return
operator|(
name|savestr
argument_list|(
name|cp
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

