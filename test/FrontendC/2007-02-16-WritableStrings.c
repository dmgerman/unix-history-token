begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test the -fwritable-strings option.
end_comment

begin_comment
comment|// RUN: %llvmgcc -O3 -S -o - -emit-llvm -fwritable-strings %s | \
end_comment

begin_comment
comment|// RUN:    grep {private global}
end_comment

begin_comment
comment|// RUN: %llvmgcc -O3 -S -o - -emit-llvm %s | grep {private constant}
end_comment

begin_decl_stmt
name|char
modifier|*
name|X
init|=
literal|"foo"
decl_stmt|;
end_decl_stmt

end_unit

