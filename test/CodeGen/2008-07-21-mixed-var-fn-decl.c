begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm -o - %s | grep -e "@g[0-9] " | count 2
end_comment

begin_decl_stmt
name|int
name|g0
decl_stmt|,
name|f0
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|f1
argument_list|()
decl_stmt|,
name|g1
decl_stmt|;
end_decl_stmt

end_unit

