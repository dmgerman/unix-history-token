begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)UNPACK.c	1.4 (Berkeley) 4/9/90"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * unpack(z,a,i)  *  * with:	z and a as in pack  *  * semantics:	for j := u to v do  *			a[j-u+i] := z[j]  */
end_comment

begin_macro
name|UNPACK
argument_list|(
argument|i
argument_list|,
argument|a
argument_list|,
argument|z
argument_list|,
argument|size_a
argument_list|,
argument|lb_a
argument_list|,
argument|ub_a
argument_list|,
argument|size_z
argument_list|)
end_macro

begin_decl_stmt
name|long
name|i
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* subscript into a to begin packing */
end_comment

begin_decl_stmt
name|char
modifier|*
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to structure a */
end_comment

begin_decl_stmt
name|char
modifier|*
name|z
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to structure z */
end_comment

begin_decl_stmt
name|long
name|size_a
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sizeof(a_type) */
end_comment

begin_decl_stmt
name|long
name|lb_a
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lower bound of structure a */
end_comment

begin_decl_stmt
name|long
name|ub_a
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* (upper bound of a) - (lb_a + sizeof(z_type)) */
end_comment

begin_decl_stmt
name|long
name|size_z
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sizeof(z_type) */
end_comment

begin_block
block|{
name|int
name|subscr
decl_stmt|;
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
specifier|register
name|char
modifier|*
name|zp
init|=
name|z
decl_stmt|;
specifier|register
name|char
modifier|*
name|limit
decl_stmt|;
name|subscr
operator|=
name|i
operator|-
name|lb_a
expr_stmt|;
if|if
condition|(
name|subscr
operator|<
literal|0
operator|||
name|subscr
operator|>
name|ub_a
condition|)
block|{
name|ERROR
argument_list|(
literal|"i = %D: Bad i to unpack(z,a,i)\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
return|return;
block|}
name|cp
operator|=
operator|&
name|a
index|[
name|subscr
operator|*
name|size_a
index|]
expr_stmt|;
name|limit
operator|=
name|cp
operator|+
name|size_z
expr_stmt|;
do|do
block|{
operator|*
name|cp
operator|++
operator|=
operator|*
name|zp
operator|++
expr_stmt|;
block|}
do|while
condition|(
name|cp
operator|<
name|limit
condition|)
do|;
block|}
end_block

end_unit

