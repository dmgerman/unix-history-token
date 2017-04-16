begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: asserts
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -analyzer-stats %s 2>&1 | FileCheck %s
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: ... Statistics Collected ...
end_comment

begin_comment
comment|// CHECK:100 AnalysisConsumer - The % of reachable basic blocks.
end_comment

begin_comment
comment|// CHECK:The # of times RemoveDeadBindings is called
end_comment

end_unit

