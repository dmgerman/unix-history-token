begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for PCH test delete.cpp
end_comment

begin_decl_stmt
name|namespace
name|pch_test
block|{
struct|struct
name|X
block|{
name|int
modifier|*
name|a
decl_stmt|;
name|X
argument_list|()
expr_stmt|;
name|X
argument_list|(
name|int
argument_list|)
expr_stmt|;
name|X
argument_list|(
name|bool
argument_list|)
operator|:
name|a
argument_list|(
argument|new int[
literal|1
argument|]
argument_list|)
block|{ }
comment|// expected-note{{allocated with 'new[]' here}}
operator|~
name|X
argument_list|()
block|{
name|delete
name|a
block|;
comment|// expected-warning{{'delete' applied to a pointer that was allocated with 'new[]'; did you mean 'delete[]'?}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:9-[[@LINE-1]]:9}:"[]"
block|}
block|}
struct|;
block|}
end_decl_stmt

end_unit

