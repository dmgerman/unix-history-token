begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * htinit() returns a pointer to a new hash table, or a null pointer if  * out of memory.  */
end_comment

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_include
include|#
directive|include
file|"hash.h"
end_include

begin_function
name|HASH
modifier|*
name|htinit
parameter_list|(
name|hashsiz
parameter_list|)
name|unsigned
name|int
name|hashsiz
decl_stmt|;
comment|/* hash table size */
block|{
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
comment|/* memory allocator + zero init */
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
comment|/* memory allocator */
name|HASH
modifier|*
name|ht
decl_stmt|;
comment|/* pointer to hash table struct */
name|HASHBLK
modifier|*
modifier|*
name|pt
decl_stmt|;
comment|/* pointer to hash pointer table */
if|if
condition|(
operator|(
name|ht
operator|=
operator|(
name|HASH
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|HASH
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
operator|||
operator|(
name|pt
operator|=
operator|(
name|HASHBLK
operator|*
operator|*
operator|)
name|calloc
argument_list|(
name|hashsiz
argument_list|,
sizeof|sizeof
argument_list|(
name|HASHBLK
operator|*
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|warn
argument_list|(
literal|"out of memory"
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|ht
operator|->
name|hashtab
operator|=
name|pt
expr_stmt|;
name|ht
operator|->
name|hashsiz
operator|=
name|hashsiz
expr_stmt|;
return|return
operator|(
name|ht
operator|)
return|;
block|}
end_function

end_unit

