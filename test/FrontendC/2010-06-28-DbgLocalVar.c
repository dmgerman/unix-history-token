begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S -O2 -g %s -o - | llc -O2 -o %t.s
end_comment

begin_comment
comment|// RUN: grep DW_TAG_structure_type %t.s | count 2
end_comment

begin_comment
comment|// Radar 8122864
end_comment

begin_comment
comment|// Code is not generated for function foo, but preserve type information of
end_comment

begin_comment
comment|// local variable xyz.
end_comment

begin_expr_stmt
specifier|static
name|foo
argument_list|()
block|{   struct
name|X
block|{
name|int
name|a
block|;
name|int
name|b
block|; }
name|xyz
block|; }
name|int
name|bar
argument_list|()
block|{
name|foo
argument_list|()
block|;
return|return
literal|1
return|;
block|}
end_expr_stmt

end_unit

