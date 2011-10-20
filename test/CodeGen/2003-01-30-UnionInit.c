begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o /dev/null
end_comment

begin_union
union|union
name|foo
block|{
struct|struct
block|{
name|char
name|A
decl_stmt|,
name|B
decl_stmt|;
block|}
name|X
struct|;
name|int
name|C
decl_stmt|;
block|}
union|;
end_union

begin_decl_stmt
name|union
name|foo
name|V
init|=
block|{
block|{
literal|1
block|,
literal|2
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

