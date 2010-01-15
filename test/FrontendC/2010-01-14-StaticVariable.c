begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This is a regression test on debug info to make sure that llvm emitted
end_comment

begin_comment
comment|// debug info does not crash gdb.
end_comment

begin_comment
comment|// RUN: %llvmgcc -S -O0 -g %s -o - | \
end_comment

begin_comment
comment|// RUN:    llc --disable-fp-elim -o %t.s -O0 -relocation-model=pic
end_comment

begin_comment
comment|// RUN: %compile_c %t.s -o %t.o
end_comment

begin_comment
comment|// RUN: echo {quit\n}> %t.in
end_comment

begin_comment
comment|// RUN: gdb -q -batch -n -x %t.in %t.o> /dev/null
end_comment

begin_function
name|int
name|foo
parameter_list|()
block|{
specifier|static
name|int
name|i
init|=
literal|42
decl_stmt|;
return|return
name|i
return|;
block|}
end_function

end_unit

