begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Helper for external-defs.c test
end_comment

begin_comment
comment|// Tentative definitions
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|x2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Should not show up
end_comment

begin_decl_stmt
specifier|static
name|int
name|z
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|incomplete_array
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|incomplete_array2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|S
name|s
decl_stmt|;
end_decl_stmt

end_unit

