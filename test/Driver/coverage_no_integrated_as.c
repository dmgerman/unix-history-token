begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: clang-driver
end_comment

begin_comment
comment|// XFAIL: win32,win64
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-arcs %s 2>&1 | FileCheck -check-prefix=CHECK-GCNO-DEFAULT-LOCATION %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-arcs -no-integrated-as %s 2>&1 | FileCheck -check-prefix=CHECK-GCNO-DEFAULT-LOCATION %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -fprofile-arcs %s 2>&1 | FileCheck -check-prefix=CHECK-GCNO-DEFAULT-LOCATION %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -fprofile-arcs -no-integrated-as %s 2>&1 | FileCheck -check-prefix=CHECK-GCNO-DEFAULT-LOCATION %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-arcs %s -o /foo/bar.o 2>&1 | FileCheck -check-prefix=CHECK-GCNO-LOCATION %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-arcs -no-integrated-as %s -o /foo/bar.o 2>&1 | FileCheck -check-prefix=CHECK-GCNO-LOCATION %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -fprofile-arcs %s -o /foo/bar.o 2>&1 | FileCheck -check-prefix=CHECK-GCNO-LOCATION %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -fprofile-arcs -no-integrated-as %s -o /foo/bar.o 2>&1 | FileCheck -check-prefix=CHECK-GCNO-LOCATION %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-arcs %s -o foo/bar.o 2>&1 | FileCheck -check-prefix=CHECK-GCNO-LOCATION-REL-PATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -fprofile-arcs -no-integrated-as %s -o foo/bar.o 2>&1 | FileCheck -check-prefix=CHECK-GCNO-LOCATION-REL-PATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -fprofile-arcs %s -o foo/bar.o 2>&1 | FileCheck -check-prefix=CHECK-GCNO-LOCATION-REL-PATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -fprofile-arcs -no-integrated-as %s -o foo/bar.o 2>&1 | FileCheck -check-prefix=CHECK-GCNO-LOCATION-REL-PATH %s
end_comment

begin_comment
comment|// CHECK-GCNO-DEFAULT-LOCATION: "-coverage-file" "{{.*}}/coverage_no_integrated_as.c"
end_comment

begin_comment
comment|// CHECK-GCNO-DEFAULT-LOCATION-NOT: "-coverage-file" "/tmp/{{.*}}/coverage_no_integrated_as.c"
end_comment

begin_comment
comment|// CHECK-GCNO-LOCATION: "-coverage-file" "/foo/bar.o"
end_comment

begin_comment
comment|// CHECK-GCNO-LOCATION-REL-PATH: "-coverage-file" "{{.*}}/foo/bar.o"
end_comment

end_unit

