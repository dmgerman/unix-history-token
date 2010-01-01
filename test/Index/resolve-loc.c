begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Run lines are sensitive to line numbers and come below the code.
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

begin_struct
struct|struct
name|S
block|{
name|int
name|field_var
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// RUN: %clang_cc1 -emit-pch %s -o %t.ast
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:3:8 | grep top_var
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:5:15 | grep top_func_decl
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:5:25 | grep param1
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:7:17 | grep top_func_def
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:7:23 | grep param2
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:8:10 | grep local_var1
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:9:15 | grep for_var
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:9:43> %t
end_comment

begin_comment
comment|// RUN: grep '++for_var' %t
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:10:9 | grep local_var2
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:10:30> %t
end_comment

begin_comment
comment|// RUN: grep 'for_var + 1' %t
end_comment

begin_comment
comment|// fields test.
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:15:10 | grep field_var
end_comment

end_unit

