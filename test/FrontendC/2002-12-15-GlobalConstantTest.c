begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|W
init|=
literal|"foo"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|X
init|=
literal|7
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Y
init|=
literal|8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|Z
init|=
literal|"bar"
decl_stmt|;
end_decl_stmt

end_unit

