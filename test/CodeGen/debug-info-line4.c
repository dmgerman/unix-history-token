begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -g -gcolumn-info -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Checks that clang emits column information when -gcolumn-info is passed.
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
name|int
name|c
init|=
name|a
operator|+
name|b
decl_stmt|;
return|return
name|c
return|;
block|}
end_function

begin_comment
comment|// Without column information we wouldn't change locations for b.
end_comment

begin_comment
comment|// CHECK:  !MDLocation(line: 4, column: 20,
end_comment

end_unit

