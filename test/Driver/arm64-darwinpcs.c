begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target arm64-apple-ios7.0 -### %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-target-abi" "darwinpcs"
end_comment

end_unit

