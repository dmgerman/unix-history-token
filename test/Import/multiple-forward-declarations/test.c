begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-import-test -import %S/Inputs/S1.c --import %S/Inputs/S2.c -expression %s
end_comment

begin_function
name|void
name|expr
parameter_list|()
block|{
name|struct
name|S
modifier|*
name|MySPtr
decl_stmt|;
block|}
end_function

end_unit

