begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t.dir
end_comment

begin_comment
comment|// RUN: mkdir -p %t.dir/a.out
end_comment

begin_comment
comment|// RUN: cd %t.dir&& not %clang %s
end_comment

begin_comment
comment|// RUN: test -d %t.dir/a.out
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

