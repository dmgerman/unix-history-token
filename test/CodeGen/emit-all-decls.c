begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: not grep "@foo" %t
end_comment

begin_comment
comment|// RUN: clang-cc -femit-all-decls -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep "@foo" %t
end_comment

begin_function
specifier|static
name|void
name|foo
parameter_list|()
block|{    }
end_function

end_unit

