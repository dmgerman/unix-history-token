begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -mno-red-zone %s -S -emit-llvm -o %t.log&&
end_comment

begin_comment
comment|// RUN: grep 'noredzone' %t.log&&
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -mred-zone %s -S -emit-llvm -o %t.log&&
end_comment

begin_comment
comment|// RUN: grep -v 'noredzone' %t.log
end_comment

begin_function
name|int
name|foo
parameter_list|()
block|{
return|return
literal|42
return|;
block|}
end_function

end_unit

