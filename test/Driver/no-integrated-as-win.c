begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-pc-win32 -### -no-integrated-as %s -c 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: there is no external assembler we can use on windows
end_comment

end_unit

