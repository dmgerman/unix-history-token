begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)PACK.c	1.4 (Berkeley) %G%"
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
comment|/*  * pack(a,i,z)  *  * with:	a: array[m..n] of t  *	z: packed array[u..v] of t  *  * semantics:	for j := u to v do  *			z[j] := a[j-u+i];  *  * need to check:  *	1. i>= m  *	2. i+(v-u)<= n		(i.e. i-m<= (n-m)-(v-u))  *  * on stack:	lv(z), lv(a), rv(i) (len 4)  *  * move w(t)*(v-u+1) bytes from lv(a)+w(t)*(i-m) to lv(z)  */
end_comment

begin_macro
name|PACK
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
literal|"i = %D: Bad i to pack(a,i,z)\n"
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
name|zp
operator|++
operator|=
operator|*
name|cp
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

