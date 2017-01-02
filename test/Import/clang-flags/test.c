begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-import-test -import %S/Inputs/S.c -expression %s -Xcc -DSTRUCT=struct
end_comment

begin_function
name|void
name|expr
parameter_list|()
block|{
name|STRUCT
name|S
name|MyS
decl_stmt|;
name|void
modifier|*
name|MyPtr
init|=
operator|&
name|MyS
decl_stmt|;
block|}
end_function

end_unit

