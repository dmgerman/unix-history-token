begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Header: 68kframe.h,v 1.3 84/02/29 12:43:22 sklower Exp $  * $Locker:  $  * machine stack frame  */
end_comment

begin_struct
struct|struct
name|machframe
block|{
name|struct
name|machframe
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

