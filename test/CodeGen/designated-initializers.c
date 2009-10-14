begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown %s -emit-llvm -o %t&&
end_comment

begin_comment
comment|// RUN: grep "{ i8\* null, i32 1024 }" %t&&
end_comment

begin_comment
comment|// RUN: grep "i32 0, i32 22" %t
end_comment

begin_struct
struct|struct
name|foo
block|{
name|void
modifier|*
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
block|{
name|int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
name|u
init|=
block|{ }
union|;
end_union

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
union|union
block|{
name|int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
name|u2
init|=
block|{ }
union|;
specifier|static
name|struct
name|foo
name|foo
init|=
block|{
operator|.
name|b
operator|=
literal|1024
block|,     }
decl_stmt|;
block|}
end_function

begin_decl_stmt
name|int
name|b
index|[
literal|2
index|]
init|=
block|{
index|[
literal|1
index|]
literal|22
block|}
decl_stmt|;
end_decl_stmt

end_unit

