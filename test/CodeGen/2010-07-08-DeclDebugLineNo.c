begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -g %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Insure that dbg.declare lines for locals refer to correct line number records.
end_comment

begin_comment
comment|// Radar 8152866.
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|l
init|=
literal|0
decl_stmt|;
comment|// line #4: CHECK: {{call.*llvm.dbg.declare.*%l.*\!dbg }}[[variable_l:![0-9]+]]
name|int
name|p
init|=
literal|0
decl_stmt|;
comment|// line #5: CHECK: {{call.*llvm.dbg.declare.*%p.*\!dbg }}[[variable_p:![0-9]+]]
block|}
end_function

begin_comment
comment|// Now match the line number records:
end_comment

begin_comment
comment|// CHECK: {{^}}[[variable_l]] = !MDLocation(line: 5,
end_comment

begin_comment
comment|// CHECK: {{^}}[[variable_p]] = !MDLocation(line: 6,
end_comment

end_unit

