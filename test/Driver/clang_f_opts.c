begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -### -S -fblocks -fbuiltin -fmath-errno -fcommon -fpascal-strings -fno-blocks -fno-builtin -fno-math-errno -fno-common -fno-pascal-strings -fblocks -fbuiltin -fmath-errno -fcommon -fpascal-strings %s 2>&1 | FileCheck -check-prefix=CHECK-OPTIONS1 %s
end_comment

begin_comment
comment|// RUN: clang -### -S -fblocks -fbuiltin -fmath-errno -fcommon -fpascal-strings -fno-blocks -fno-builtin -fno-math-errno -fno-common -fno-pascal-strings -fno-show-source-location -fshort-wchar %s 2>&1 | FileCheck -check-prefix=CHECK-OPTIONS2 %s
end_comment

begin_comment
comment|// RUN: clang -### -fshort-enums %s 2>&1 | FileCheck -check-prefix=CHECK-SHORT-ENUMS %s
end_comment

begin_comment
comment|// CHECK-OPTIONS1: -fblocks
end_comment

begin_comment
comment|// CHECK-OPTIONS1: -fpascal-strings
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fno-math-errno
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fno-builtin
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
comment|// CHECK-SHORT-ENUMS: compiler does not support '-fshort-enums'
end_comment

end_unit

