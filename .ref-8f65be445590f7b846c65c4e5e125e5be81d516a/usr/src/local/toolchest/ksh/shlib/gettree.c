begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)gettree.c	1.1 */
end_comment

begin_comment
comment|/*  *   GETTREE.C  *  *   Programmer:  D. A. Lambeth  *  *        Owner:  D. A. Lambeth  *  *         Date:  April 17, 1980  *  *  *  *   GETTREE (MSIZE)  *  *        Create a shell associative memory with MSIZE buckets,  *        and return a pointer to the root of the memory.  *        MSIZE must be a power of 2.  *  *  *  *   See Also:  linknod(III), findnod(III), libname.h  */
end_comment

begin_include
include|#
directive|include
file|"name.h"
end_include

begin_include
include|#
directive|include
file|"flags.h"
end_include

begin_comment
comment|/*  *   GETTREE (MSIZE)  *  *      int MSIZE;  *  *   Create an associative memory containing MSIZE headnodes or  *   buckets, and return a pointer to the root of the memory.  *  *   Algorithm:  Memory consists of a hash table of MSIZE buckets,  *               each of which holds a pointer to a linked list  *               of Namnods.  Nodes are hashed into a bucket by  *               namid.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|struct
name|Amemory
modifier|*
name|gettree
parameter_list|(
name|msize
parameter_list|)
specifier|register
name|int
name|msize
decl_stmt|;
block|{
specifier|register
name|struct
name|Amemory
modifier|*
name|root
decl_stmt|;
name|root
operator|=
operator|(
expr|struct
name|Amemory
operator|*
operator|)
name|malloc
argument_list|(
call|(
name|unsigned
call|)
argument_list|(
operator|(
name|msize
operator|-
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|Namnod
operator|*
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|Amemory
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|root
operator|->
name|memsize
operator|=
name|msize
expr_stmt|;
name|root
operator|->
name|nexttree
operator|=
name|NULL
expr_stmt|;
while|while
condition|(
name|msize
condition|)
name|root
operator|->
name|memhead
index|[
operator|--
name|msize
index|]
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|root
operator|)
return|;
block|}
end_function

end_unit

