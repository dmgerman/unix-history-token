begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Stack of data placed on obstacks.  */
end_comment

begin_struct
struct|struct
name|stack_level
block|{
comment|/* Pointer back to previous such level.  */
name|struct
name|stack_level
modifier|*
name|prev
decl_stmt|;
comment|/* Point to obstack we should return to.  */
name|struct
name|obstack
modifier|*
name|obstack
decl_stmt|;
comment|/* First place we start putting data.  */
name|tree
modifier|*
name|first
decl_stmt|;
comment|/* Number of entries we can have from `first'.      Right now we are dumb: if we overflow, abort.  */
name|int
name|limit
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|stack_level
modifier|*
name|push_stack_level
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|stack_level
modifier|*
name|pop_stack_level
parameter_list|()
function_decl|;
end_function_decl

end_unit

