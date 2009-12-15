begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -o - | opt -std-compile-opts | llc | \
end_comment

begin_comment
comment|// RUN:    not grep _foo2
end_comment

begin_expr_stmt
name|void
name|foo
argument_list|()
end_expr_stmt

begin_asm
asm|__asm__("foo2");
end_asm

begin_function
name|void
name|bar
parameter_list|()
block|{
name|foo
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

