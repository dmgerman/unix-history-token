begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1< %s -emit-llvm | grep internal | count 1
end_comment

begin_comment
comment|// The two decls for 'a' should merge into one llvm GlobalVariable.
end_comment

begin_struct
struct|struct
name|s
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|s
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|s
modifier|*
name|ap1
init|=
operator|&
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|s
name|a
init|=
block|{
literal|10
block|}
decl_stmt|;
end_decl_stmt

end_unit

