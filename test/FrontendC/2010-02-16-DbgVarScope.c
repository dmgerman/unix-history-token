begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
comment|// RUN: %link %t.o -o %t.exe
end_comment

begin_comment
comment|// RUN: echo {break 24\nrun\np loc\n}> %t.in
end_comment

begin_comment
comment|// RN: gdb -q -batch -n -x %t.in %t.exe | tee %t.out | \
end_comment

begin_comment
comment|// RN:   grep {$1 = 1}
end_comment

begin_decl_stmt
name|int
name|g1
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|g2
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|always_inline
operator|)
argument_list|)
name|bar
argument_list|()
block|{
return|return
name|g2
operator|-
name|g1
return|;
block|}
end_decl_stmt

begin_function
name|void
name|foobar
parameter_list|()
block|{}
end_function

begin_function
name|void
name|foo
parameter_list|(
name|int
name|s
parameter_list|)
block|{
name|unsigned
name|loc
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|s
condition|)
block|{
name|loc
operator|=
literal|1
expr_stmt|;
name|foobar
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|loc
operator|=
name|bar
argument_list|()
expr_stmt|;
name|foobar
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|foo
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

