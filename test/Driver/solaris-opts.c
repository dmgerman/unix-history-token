begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s --target=sparc-sun-solaris2.11 -### -o %t.o 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-fno-use-cxa-atexit"
end_comment

end_unit

