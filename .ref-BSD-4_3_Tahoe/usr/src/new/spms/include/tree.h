begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Binary tree definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * The basic node for a binary tree.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tnode
block|{
name|char
modifier|*
name|key
decl_stmt|;
comment|/* points to a key */
name|int
name|count
decl_stmt|;
comment|/* number of occurrences */
name|struct
name|tnode
modifier|*
name|left
decl_stmt|;
comment|/* left child */
name|struct
name|tnode
modifier|*
name|right
decl_stmt|;
comment|/* right child */
block|}
name|TREE
typedef|;
end_typedef

begin_comment
comment|/*  * Functions defined for binary trees  */
end_comment

begin_function_decl
specifier|extern
name|int
name|treesearch
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* tree search */
end_comment

begin_function_decl
specifier|extern
name|TREE
modifier|*
name|tree
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* tree search and insert */
end_comment

begin_function_decl
specifier|extern
name|TREE
modifier|*
name|treerm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* tree deletion */
end_comment

end_unit

