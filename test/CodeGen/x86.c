begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -triple=i686-pc-linux-gnu -emit-llvm -o -> %t1
end_comment

begin_comment
comment|// RUN: grep "ax" %t1
end_comment

begin_comment
comment|// RUN: grep "bx" %t1
end_comment

begin_comment
comment|// RUN: grep "cx" %t1
end_comment

begin_comment
comment|// RUN: grep "dx" %t1
end_comment

begin_comment
comment|// RUN: grep "di" %t1
end_comment

begin_comment
comment|// RUN: grep "si" %t1
end_comment

begin_comment
comment|// RUN: grep "st" %t1
end_comment

begin_comment
comment|// RUN: grep "st(1)" %t1
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
name|int
name|d1
decl_stmt|,
name|d2
decl_stmt|;
asm|asm ("" : "=a" (d1), "=b" (d2) :        "c" (0), "d" (0), "S" (0), "D" (0), "t" (0), "u" (0));
block|}
end_function

end_unit

