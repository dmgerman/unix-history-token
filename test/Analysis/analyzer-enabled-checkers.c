begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -triple x86_64-apple-darwin10 %s -o /dev/null -analyzer-checker=core -analyzer-list-enabled-checkers> %t 2>&1
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t %s
end_comment

begin_comment
comment|// CHECK: OVERVIEW: Clang Static Analyzer Enabled Checkers List
end_comment

begin_comment
comment|// CHECK: core.CallAndMessage
end_comment

begin_comment
comment|// CHECK: core.DivideZero
end_comment

begin_comment
comment|// CHECK: core.DynamicTypePropagation
end_comment

begin_comment
comment|// CHECK: core.NonNullParamChecker
end_comment

begin_comment
comment|// CHECK: core.NullDereference
end_comment

begin_comment
comment|// CHECK: core.StackAddressEscape
end_comment

begin_comment
comment|// CHECK: core.UndefinedBinaryOperatorResult
end_comment

begin_comment
comment|// CHECK: core.VLASize
end_comment

begin_comment
comment|// CHECK: core.builtin.BuiltinFunctions
end_comment

begin_comment
comment|// CHECK: core.builtin.NoReturnFunctions
end_comment

begin_comment
comment|// CHECK: core.uninitialized.ArraySubscript
end_comment

begin_comment
comment|// CHECK: core.uninitialized.Assign
end_comment

begin_comment
comment|// CHECK: core.uninitialized.Branch
end_comment

begin_comment
comment|// CHECK: core.uninitialized.CapturedBlockVariable
end_comment

begin_comment
comment|// CHECK: core.uninitialized.UndefReturn
end_comment

end_unit

