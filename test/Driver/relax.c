begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -c -integrated-as -Wa,--mrelax-relocations=yes %s 2>&1 | FileCheck  %s
end_comment

begin_comment
comment|// CHECK: "-cc1"
end_comment

begin_comment
comment|// CHECK: "--mrelax-relocations"
end_comment

end_unit

