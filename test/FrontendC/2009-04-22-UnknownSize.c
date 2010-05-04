begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %llvmgcc -O1 %s -S -o /dev/null |& grep {error: storage size}
end_comment

begin_comment
comment|// PR2958
end_comment

begin_decl_stmt
specifier|static
name|struct
name|foo
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|foo
modifier|*
name|p
init|=
operator|&
name|s
decl_stmt|;
end_decl_stmt

end_unit

