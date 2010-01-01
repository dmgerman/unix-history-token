begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1< %s -emit-llvm
end_comment

begin_decl_stmt
name|int
name|A
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|long
name|B
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|C
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|P
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test1
parameter_list|()
block|{
name|C
operator|=
operator|(
name|A
operator|/=
name|B
operator|)
expr_stmt|;
name|P
operator|-=
literal|4
expr_stmt|;
name|C
operator|=
name|P
operator|-
operator|(
name|P
operator|+
literal|10
operator|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|short
name|x
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test2
parameter_list|(
name|char
name|c
parameter_list|)
block|{
name|x
operator|+=
name|c
expr_stmt|;
block|}
end_function

begin_function
name|void
name|foo
parameter_list|(
name|char
modifier|*
name|strbuf
parameter_list|)
block|{
name|int
name|stufflen
init|=
literal|4
decl_stmt|;
name|strbuf
operator|+=
name|stufflen
expr_stmt|;
block|}
end_function

begin_comment
comment|// Aggregate cast to void
end_comment

begin_union
union|union
name|uu
block|{
name|int
name|a
decl_stmt|;
block|}
union|;
end_union

begin_function
name|void
name|f
parameter_list|(
name|union
name|uu
name|p
parameter_list|)
block|{
operator|(
name|void
operator|)
name|p
expr_stmt|;
block|}
end_function

end_unit

