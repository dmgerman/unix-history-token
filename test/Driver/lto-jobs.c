begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Confirm that -flto-jobs=N is passed to linker
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux -### %s -flto=thin -flto-jobs=5 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-LINK-THIN-JOBS-ACTION< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LINK-THIN-JOBS-ACTION: "-plugin-opt=jobs=5"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin13.3.0 -### %s -flto=thin -flto-jobs=5 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-LINK-THIN-JOBS2-ACTION< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LINK-THIN-JOBS2-ACTION: "-mllvm" "-threads=5"
end_comment

end_unit

