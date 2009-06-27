begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-pch %s -o %t.ast&&
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:15:8 | grep top_var&&
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:17:15 | grep top_func_decl&&
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:17:25 | grep param1&&
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:19:17 | grep top_func_def&&
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:19:23 | grep param2&&
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:20:10 | grep local_var1&&
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:21:15 | grep for_var&&
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:21:43 | grep top_func_def&&
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:21:43 | grep '++for_var'&&
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:22:9 | grep local_var2&&
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:22:30 | grep local_var2&&
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:22:30 | grep 'for_var + 1'
end_comment

begin_decl_stmt
name|int
name|top_var
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|top_func_decl
parameter_list|(
name|int
name|param1
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|top_func_def
parameter_list|(
name|int
name|param2
parameter_list|)
block|{
name|int
name|local_var1
decl_stmt|;
for|for
control|(
name|int
name|for_var
init|=
literal|100
init|;
name|for_var
operator|<
literal|500
condition|;
operator|++
name|for_var
control|)
block|{
name|int
name|local_var2
init|=
name|for_var
operator|+
literal|1
decl_stmt|;
block|}
block|}
end_function

end_unit

