begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * htlookup() returns a pointer to a hash table entry if found, otherwise null.  */
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

begin_include
include|#
directive|include
file|"macro.h"
end_include

begin_function
name|HASHBLK
modifier|*
name|htlookup
parameter_list|(
name|key
parameter_list|,
name|hash
parameter_list|)
name|char
modifier|*
name|key
decl_stmt|;
comment|/* key for hash table entry */
name|HASH
modifier|*
name|hash
decl_stmt|;
comment|/* hash table */
block|{
name|HASHBLK
modifier|*
name|htb
decl_stmt|;
comment|/* hash table entry block */
name|int
name|hthash
parameter_list|()
function_decl|;
comment|/* calculate hash value */
for|for
control|(
name|htb
operator|=
operator|(
name|hash
operator|->
name|hashtab
operator|)
index|[
name|hthash
argument_list|(
name|key
argument_list|,
name|hash
argument_list|)
index|]
init|;
name|htb
operator|!=
name|NULL
condition|;
name|htb
operator|=
name|htb
operator|->
name|h_next
control|)
if|if
condition|(
name|EQUAL
argument_list|(
name|htb
operator|->
name|h_key
argument_list|,
name|key
argument_list|)
condition|)
return|return
operator|(
name|htb
operator|)
return|;
comment|/* found */
return|return
operator|(
name|NULL
operator|)
return|;
comment|/* not found */
block|}
end_function

end_unit

