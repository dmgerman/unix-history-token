begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * htinstall() installs a new entry in a hash table if it doesn't already  * exist. If it does, the old definition and value is superseded. Returns  * a pointer to the entry, or null if out of memory.  */
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
name|HASHBLK
modifier|*
name|htinstall
parameter_list|(
name|key
parameter_list|,
name|def
parameter_list|,
name|val
parameter_list|,
name|hash
parameter_list|)
name|char
modifier|*
name|key
decl_stmt|;
comment|/* key for hash table entry */
name|char
modifier|*
name|def
decl_stmt|;
comment|/* definition string */
name|int
name|val
decl_stmt|;
comment|/* integer value */
name|HASH
modifier|*
name|hash
decl_stmt|;
comment|/* hash table */
block|{
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
comment|/* memory allocator */
name|char
modifier|*
name|strsav
parameter_list|()
function_decl|;
comment|/* save string somewhere */
name|HASHBLK
modifier|*
name|htb
decl_stmt|;
comment|/* hash table entry block */
name|HASHBLK
modifier|*
name|htlookup
parameter_list|()
function_decl|;
comment|/* find hash table entry */
name|int
name|hashval
decl_stmt|;
comment|/* hash value for key */
name|int
name|hthash
parameter_list|()
function_decl|;
comment|/* calculate hash value */
if|if
condition|(
operator|(
name|htb
operator|=
name|htlookup
argument_list|(
name|key
argument_list|,
name|hash
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* not found */
if|if
condition|(
operator|(
name|htb
operator|=
operator|(
name|HASHBLK
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|HASHBLK
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
if|if
condition|(
operator|(
name|htb
operator|->
name|h_key
operator|=
name|strsav
argument_list|(
name|key
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|hashval
operator|=
name|hthash
argument_list|(
name|key
argument_list|,
name|hash
argument_list|)
expr_stmt|;
name|htb
operator|->
name|h_next
operator|=
operator|(
name|hash
operator|->
name|hashtab
operator|)
index|[
name|hashval
index|]
expr_stmt|;
operator|(
name|hash
operator|->
name|hashtab
operator|)
index|[
name|hashval
index|]
operator|=
name|htb
expr_stmt|;
block|}
else|else
block|{
comment|/* found */
name|free
argument_list|(
name|htb
operator|->
name|h_def
argument_list|)
expr_stmt|;
comment|/* free previous definition */
block|}
if|if
condition|(
operator|(
name|htb
operator|->
name|h_def
operator|=
name|strsav
argument_list|(
name|def
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|htb
operator|->
name|h_val
operator|=
name|val
expr_stmt|;
return|return
operator|(
name|htb
operator|)
return|;
block|}
end_function

end_unit

