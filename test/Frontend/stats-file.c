begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o /dev/null -stats-file=%t %s
end_comment

begin_comment
comment|// RUN: FileCheck -input-file=%t %s
end_comment

begin_comment
comment|// CHECK: {
end_comment

begin_comment
comment|//  ... here come some json values ...
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o %t -stats-file=%S/doesnotexist/bla %s 2>&1 | FileCheck -check-prefix=OUTPUTFAIL %s
end_comment

begin_comment
comment|// OUTPUTFAIL: warning: unable to open statistics output file '{{.*}}doesnotexist{{.}}bla': '{{[Nn]}}o such file or directory'
end_comment

end_unit

