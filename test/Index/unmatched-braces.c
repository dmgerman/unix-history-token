begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
if|if
condition|(
name|x
condition|)
block|{ }
end_function

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:2:7 %s> %t
end_comment

begin_comment
comment|// RUN: FileCheck %s -input-file %t
end_comment

begin_comment
comment|// CHECK: VarDecl=x:2:7
end_comment

end_unit

