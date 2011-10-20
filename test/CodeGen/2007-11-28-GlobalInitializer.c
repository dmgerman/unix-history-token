begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o -
end_comment

begin_comment
comment|// PR1744
end_comment

begin_typedef
typedef|typedef
struct|struct
name|foo
block|{
name|int
name|x
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
block|}
name|FOO
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|FOO
name|yy
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|y
init|=
operator|&
operator|(
operator|(
name|yy
operator|+
literal|1
operator|)
operator|->
name|x
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|z
init|=
operator|&
operator|(
operator|(
name|yy
operator|+
literal|1
operator|)
operator|->
name|x
operator|)
decl_stmt|;
end_decl_stmt

end_unit

