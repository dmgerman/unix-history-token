begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -g -emit-llvm< %s | FileCheck %s
end_comment

begin_comment
comment|// Check that, just because we emitted a function from a different file doesn't
end_comment

begin_comment
comment|// mean we insert a file-change inside the next function.
end_comment

begin_comment
comment|// CHECK: ret void, !dbg [[F1_LINE:![0-9]*]]
end_comment

begin_comment
comment|// CHECK: ret void, !dbg [[F2_LINE:![0-9]*]]
end_comment

begin_comment
comment|// CHECK: [[F1:![0-9]*]] = {{.*}} ; [ DW_TAG_subprogram ] {{.*}} [def] [f1]
end_comment

begin_comment
comment|// CHECK: [[F2:![0-9]*]] = {{.*}} ; [ DW_TAG_subprogram ] {{.*}} [def] [f2]
end_comment

begin_comment
comment|// CHECK: [[F1_LINE]] = !MDLocation({{.*}}, scope: [[F1]])
end_comment

begin_comment
comment|// CHECK: [[F2_LINE]] = !MDLocation({{.*}}, scope: [[F2]])
end_comment

begin_function
name|void
name|f1
parameter_list|()
block|{ }
end_function

begin_empty
empty|# 2 "foo.c"
end_empty

begin_function
name|void
name|f2
parameter_list|()
block|{ }
end_function

end_unit

