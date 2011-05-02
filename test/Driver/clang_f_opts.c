begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -S -fasm -fblocks -fbuiltin -fno-math-errno -fcommon -fpascal-strings -fno-blocks -fno-builtin -fmath-errno -fno-common -fno-pascal-strings -fblocks -fbuiltin -fmath-errno -fcommon -fpascal-strings %s 2>&1 | FileCheck -check-prefix=CHECK-OPTIONS1 %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fasm -fblocks -fbuiltin -fno-math-errno -fcommon -fpascal-strings -fno-asm -fno-blocks -fno-builtin -fmath-errno -fno-common -fno-pascal-strings -fno-show-source-location -fshort-enums -fshort-wchar %s 2>&1 | FileCheck -check-prefix=CHECK-OPTIONS2 %s
end_comment

begin_comment
comment|// CHECK-OPTIONS1: -fgnu-keywords
end_comment

begin_comment
comment|// CHECK-OPTIONS1: -fblocks
end_comment

begin_comment
comment|// CHECK-OPTIONS1: -fpascal-strings
end_comment

begin_comment
comment|// CHECK_OPTIONS2: -fno-gnu-keywords
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fmath-errno
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fno-builtin
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fshort-enums
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fshort-wchar
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fno-common
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fno-show-source-location
end_comment

begin_comment
comment|// RUN: %clang -### -S -Wwrite-strings %s 2>&1 | FileCheck -check-prefix=WRITE-STRINGS1 %s
end_comment

begin_comment
comment|// WRITE-STRINGS1: -fconst-strings
end_comment

begin_comment
comment|// RUN: %clang -### -S -Wwrite-strings -Wno-write-strings %s 2>&1 | FileCheck -check-prefix=WRITE-STRINGS2 %s
end_comment

begin_comment
comment|// WRITE-STRINGS2-NOT: -fconst-strings
end_comment

begin_comment
comment|// RUN: %clang -### -S -Wwrite-strings -w %s 2>&1 | FileCheck -check-prefix=WRITE-STRINGS3 %s
end_comment

begin_comment
comment|// WRITE-STRINGS3: -fconst-strings
end_comment

begin_comment
comment|// RUN: %clang -### -x c++ -c %s 2>&1 | FileCheck -check-prefix=DEPRECATED-ON-CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -### -x c++ -c -Wdeprecated %s 2>&1 | FileCheck -check-prefix=DEPRECATED-ON-CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -### -x c++ -c -Wno-deprecated %s 2>&1 | FileCheck -check-prefix=DEPRECATED-OFF-CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -### -x c++ -c -Wno-deprecated -Wdeprecated %s 2>&1 | FileCheck -check-prefix=DEPRECATED-ON-CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -### -x c++ -c -w %s 2>&1 | FileCheck -check-prefix=DEPRECATED-ON-CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -### -c %s 2>&1 | FileCheck -check-prefix=DEPRECATED-OFF-CHECK %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -Wdeprecated %s 2>&1 | FileCheck -check-prefix=DEPRECATED-OFF-CHECK %s
end_comment

begin_comment
comment|// DEPRECATED-ON-CHECK: -fdeprecated-macro
end_comment

begin_comment
comment|// DEPRECATED-OFF-CHECK-NOT: -fdeprecated-macro
end_comment

end_unit

