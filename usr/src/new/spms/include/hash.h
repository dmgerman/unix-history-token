begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Hash table definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Hash table block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_hblk
block|{
name|char
modifier|*
name|h_key
decl_stmt|;
comment|/* points to key */
name|char
modifier|*
name|h_def
decl_stmt|;
comment|/* points to definition string */
name|int
name|h_val
decl_stmt|;
comment|/* integer value */
name|struct
name|_hblk
modifier|*
name|h_next
decl_stmt|;
comment|/* ptr to next block */
block|}
name|HASHBLK
typedef|;
end_typedef

begin_comment
comment|/*  * Hash pointer table struct  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_hash
block|{
name|HASHBLK
modifier|*
modifier|*
name|hashtab
decl_stmt|;
comment|/* hash pointer table */
name|int
name|hashsiz
decl_stmt|;
comment|/* hash table size */
block|}
name|HASH
typedef|;
end_typedef

begin_comment
comment|/*  * Functions defined for hash tables  */
end_comment

begin_function_decl
specifier|extern
name|HASHBLK
modifier|*
name|htbrm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove hash table block */
end_comment

begin_function_decl
specifier|extern
name|int
name|hthash
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* compute hash value */
end_comment

begin_function_decl
specifier|extern
name|HASH
modifier|*
name|htinit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* initialize hash table */
end_comment

begin_function_decl
specifier|extern
name|HASHBLK
modifier|*
name|htinstall
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* install hash table entry */
end_comment

begin_function_decl
specifier|extern
name|HASHBLK
modifier|*
name|htlookup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find hash table entry */
end_comment

begin_function_decl
specifier|extern
name|void
name|htrm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove hash table entry */
end_comment

end_unit

