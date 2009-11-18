begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm %s -o - 2>&1 | not grep warning
end_comment

begin_comment
comment|// RUN: clang-cc -emit-llvm %s -o - | grep @b | count 1
end_comment

begin_decl_stmt
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|c1
init|=
literal|1
operator|<
literal|2
condition|?
operator|&
name|a
else|:
operator|&
name|b
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|c2
init|=
literal|3
operator|!=
literal|3LL
condition|?
operator|&
name|b
else|:
operator|&
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|c3
init|=
operator|!
operator|(
literal|3
operator|<=
literal|4.0
operator|)
condition|?
operator|&
name|b
else|:
operator|&
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|c4
init|=
operator|&
name|a
operator|-
operator|(
literal|6
operator|*
literal|5
operator|>
literal|30
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|c5
init|=
operator|&
name|a
operator|+
operator|(
literal|6
operator|*
literal|5
operator|>=
literal|30
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|c6
init|=
literal|44
operator|<
literal|33
decl_stmt|;
end_decl_stmt

end_unit

