begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -triple=i686-pc-linux-gnu -emit-llvm -o -> %t1
end_comment

begin_comment
comment|// RUN: grep "ax" %t1&&
end_comment

begin_comment
comment|// RUN: grep "bx" %t1&&
end_comment

begin_comment
comment|// RUN: grep "cx" %t1&&
end_comment

begin_comment
comment|// RUN: grep "dx" %t1&&
end_comment

begin_comment
comment|// RUN: grep "di" %t1&&
end_comment

begin_comment
comment|// RUN: grep "si" %t1&&
end_comment

begin_comment
comment|// RUN: grep "st" %t1&&
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

begin_comment
comment|// rdar://6803924
end_comment

begin_typedef
typedef|typedef
name|double
name|T
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_function
name|T
name|test2
parameter_list|(
name|T
name|va
parameter_list|)
block|{
return|return
name|__builtin_ia32_shufpd
argument_list|(
name|va
argument_list|,
name|va
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

end_unit

