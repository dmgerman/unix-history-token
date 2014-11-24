begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -test-load-source-reparse 5 local "-remap-file=%S/Inputs/preamble-reparse-1.c,%S/Inputs/preamble-reparse-2.c" %S/Inputs/preamble-reparse-1.c | FileCheck %s
end_comment

begin_comment
comment|// CHECK: preamble-reparse-1.c:1:5: VarDecl=x:1:5 Extent=[1:1 - 1:6]
end_comment

end_unit

