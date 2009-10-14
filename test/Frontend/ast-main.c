begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -emit-llvm -S -o %t1.ll -x c -< %s&&
end_comment

begin_comment
comment|// RUN: clang -emit-ast -o %t.ast %s&&
end_comment

begin_comment
comment|// RUN: clang -emit-llvm -S -o %t2.ll -x ast -< %t.ast&&
end_comment

begin_comment
comment|// RUN: diff %t1.ll %t2.ll
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

