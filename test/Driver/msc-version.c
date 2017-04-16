begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//
end_comment

begin_comment
comment|// Verify -fms-compatibility-version parsing
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target i686-windows -fms-compatibility -fms-compatibility-version=14 -dM -E -</dev/null -o - | FileCheck %s -check-prefix CHECK-MSC-VERSION-MAJOR
end_comment

begin_comment
comment|// CHECK-MSC-VERSION-MAJOR: _MSC_BUILD 1
end_comment

begin_comment
comment|// CHECK-MSC-VERSION-MAJOR: _MSC_FULL_VER 140000000
end_comment

begin_comment
comment|// CHECK-MSC-VERSION-MAJOR: _MSC_VER 1400
end_comment

begin_comment
comment|// RUN: %clang -target i686-windows -fms-compatibility -fms-compatibility-version=15.00 -dM -E -</dev/null -o - | FileCheck %s -check-prefix CHECK-MSC-VERSION-MAJOR-MINOR
end_comment

begin_comment
comment|// CHECK-MSC-VERSION-MAJOR-MINOR: _MSC_BUILD 1
end_comment

begin_comment
comment|// CHECK-MSC-VERSION-MAJOR-MINOR: _MSC_FULL_VER 150000000
end_comment

begin_comment
comment|// CHECK-MSC-VERSION-MAJOR-MINOR: _MSC_VER 1500
end_comment

begin_comment
comment|// RUN: %clang -target i686-windows -fms-compatibility -fms-compatibility-version=15.00.20706 -dM -E -</dev/null -o - | FileCheck %s -check-prefix CHECK-MSC-VERSION-MAJOR-MINOR-BUILD
end_comment

begin_comment
comment|// CHECK-MSC-VERSION-MAJOR-MINOR-BUILD: _MSC_BUILD 1
end_comment

begin_comment
comment|// CHECK-MSC-VERSION-MAJOR-MINOR-BUILD: _MSC_FULL_VER 150020706
end_comment

begin_comment
comment|// CHECK-MSC-VERSION-MAJOR-MINOR-BUILD: _MSC_VER 1500
end_comment

begin_comment
comment|// RUN: %clang -target i686-windows -fms-compatibility -fms-compatibility-version=15.00.20706.01 -dM -E -</dev/null -o - | FileCheck %s -check-prefix CHECK-MSC-VERSION-MAJOR-MINOR-BUILD-PATCH
end_comment

begin_comment
comment|// CHECK-MSC-VERSION-MAJOR-MINOR-BUILD-PATCH: _MSC_BUILD 1
end_comment

begin_comment
comment|// CHECK-MSC-VERSION-MAJOR-MINOR-BUILD-PATCH: _MSC_FULL_VER 150020706
end_comment

begin_comment
comment|// CHECK-MSC-VERSION-MAJOR-MINOR-BUILD-PATCH: _MSC_VER 1500
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Verify -fmsc-version and -fms-compatibility-version diagnostic
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not %clang -target i686-windows -fms-compatibility -fmsc-version=1700 -fms-compatibility-version=17.00.50727.1 -E -</dev/null 2>&1 | FileCheck %s -check-prefix CHECK-BASIC-EXTENDED-DIAGNOSTIC
end_comment

begin_comment
comment|// CHECK-BASIC-EXTENDED-DIAGNOSTIC: invalid argument '-fmsc-version={{.*}}' not allowed with '-fms-compatibility-version={{.*}}'
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Verify -fmsc-version to -fms-compatibility-version conversion
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-windows -fms-compatibility -fmsc-version=17 -E -</dev/null -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-MSC-17
end_comment

begin_comment
comment|// CHECK-MSC-17-NOT: "-fmsc-version=1700"
end_comment

begin_comment
comment|// CHECK-MSC-17: "-fms-compatibility-version=17"
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-windows -fms-compatibility -fmsc-version=1600 -E -</dev/null -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-MSC-16
end_comment

begin_comment
comment|// CHECK-MSC-16-NOT: "-fmsc-version=1600"
end_comment

begin_comment
comment|// CHECK-MSC-16: "-fms-compatibility-version=16.0"
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-windows -fms-compatibility -fmsc-version=150020706 -E -</dev/null -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-MSC-15
end_comment

begin_comment
comment|// CHECK-MSC-15-NOT: "-fmsc-version=150020706"
end_comment

begin_comment
comment|// CHECK-MSC-15: "-fms-compatibility-version=15.0.20706"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Verify default version with -fms-extensions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target i686-windows -fms-extensions -dM -E -</dev/null -o - | FileCheck %s -check-prefix CHECK-MS-EXTENSIONS
end_comment

begin_comment
comment|// CHECK-MS-EXTENSIONS: _MSC_BUILD 1
end_comment

begin_comment
comment|// CHECK-MS-EXTENSIONS: _MSC_FULL_VER {{.+}}
end_comment

begin_comment
comment|// CHECK-MS-EXTENSIONS: _MSC_VER {{....}}
end_comment

end_unit

