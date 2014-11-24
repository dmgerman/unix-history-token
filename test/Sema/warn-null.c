begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify
end_comment

begin_define
define|#
directive|define
name|SOME_ADDR
value|(unsigned long long)0
end_define

begin_comment
comment|// PR10837: Warn if a non-pointer-typed expression is folded to a null pointer
end_comment

begin_decl_stmt
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|q
init|=
literal|'\0'
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{expression which evaluates to zero treated as a null pointer constant}}
end_comment

begin_decl_stmt
name|int
modifier|*
name|r
init|=
operator|(
literal|1
operator|-
literal|1
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{expression which evaluates to zero treated as a null pointer constant}}
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|p
operator|=
literal|0
expr_stmt|;
name|q
operator|=
literal|'\0'
expr_stmt|;
comment|// expected-warning{{expression which evaluates to zero treated as a null pointer constant}}
name|r
operator|=
literal|1
operator|-
literal|1
expr_stmt|;
comment|// expected-warning{{expression which evaluates to zero treated as a null pointer constant}}
name|p
operator|=
name|SOME_ADDR
expr_stmt|;
comment|// expected-warning{{expression which evaluates to zero treated as a null pointer constant}}
block|}
end_function

end_unit

