begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm -o - %s | not grep "common"
end_comment

begin_comment
comment|// This checks that the global won't be marked as common.
end_comment

begin_comment
comment|// (It shouldn't because it's being initialized).
end_comment

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|a
init|=
literal|242
decl_stmt|;
end_decl_stmt

end_unit

