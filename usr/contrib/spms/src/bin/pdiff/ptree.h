begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * project comparison tree definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_pnode
block|{
name|char
modifier|*
name|alias
decl_stmt|;
comment|/* project directory alias */
name|char
modifier|*
name|pd1
decl_stmt|;
comment|/* project directory pathname */
name|char
modifier|*
name|pd2
decl_stmt|;
comment|/* project directory pathname */
name|struct
name|_pnode
modifier|*
name|left
decl_stmt|;
comment|/* left child */
name|struct
name|_pnode
modifier|*
name|right
decl_stmt|;
comment|/* right child */
block|}
name|PTREE
typedef|;
end_typedef

end_unit

