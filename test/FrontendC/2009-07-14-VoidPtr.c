begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o -
end_comment

begin_comment
comment|// PR4556
end_comment

begin_decl_stmt
specifier|extern
name|void
name|foo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|bar
init|=
operator|&
name|foo
decl_stmt|;
end_decl_stmt

end_unit

