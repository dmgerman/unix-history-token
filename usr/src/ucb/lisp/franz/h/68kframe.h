begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sccs id  %W%  %G%  */
end_comment

begin_struct
struct|struct
name|frame
block|{
name|struct
name|frame
modifier|*
name|fp
decl_stmt|;
name|lispval
function_decl|(
modifier|*
name|pc
function_decl|)
parameter_list|()
function_decl|;
name|lispval
name|ap
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

