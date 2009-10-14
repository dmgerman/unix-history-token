begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_decl_stmt
specifier|extern
name|char
name|algbrfile
index|[
literal|9
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|algbrfile
index|[
literal|9
index|]
init|=
literal|"abcdefgh"
decl_stmt|;
end_decl_stmt

end_unit

