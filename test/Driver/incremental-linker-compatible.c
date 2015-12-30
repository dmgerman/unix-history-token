begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang '-###' %s -c -o tmp.o -target i686-pc-linux-gnu -integrated-as -mincremental-linker-compatible 2>&1 | FileCheck %s --check-prefix=TEST1
end_comment

begin_comment
comment|// TEST1: "-cc1" {{.*}} "-mincremental-linker-compatible"
end_comment

begin_comment
comment|// RUN: %clang '-###' %s -c -o tmp.o -target i686-pc-linux-gnu -integrated-as -mno-incremental-linker-compatible 2>&1 | FileCheck %s --check-prefix=TEST2
end_comment

begin_comment
comment|// TEST2-NOT: "-cc1" {{.*}} "-mincremental-linker-compatible"
end_comment

begin_comment
comment|// RUN: %clang '-###' %s -c -o tmp.o -target i686-pc-linux-gnu -integrated-as -mno-incremental-linker-compatible -mincremental-linker-compatible 2>&1 | FileCheck %s --check-prefix=TEST3
end_comment

begin_comment
comment|// TEST3: "-cc1" {{.*}} "-mincremental-linker-compatible"
end_comment

begin_comment
comment|// RUN: %clang '-###' %s -c -o tmp.o -target i686-pc-linux-gnu -integrated-as -mincremental-linker-compatible -mno-incremental-linker-compatible 2>&1 | FileCheck %s --check-prefix=TEST4
end_comment

begin_comment
comment|// TEST4-NOT: "-cc1" {{.*}} "-mincremental-linker-compatible"
end_comment

begin_comment
comment|// RUN: %clang '-###' %s -c -o tmp.o -target i686-pc-mingw32 -integrated-as 2>&1 | FileCheck %s --check-prefix=TEST5
end_comment

begin_comment
comment|// TEST5-NOT: "-cc1" {{.*}} "-mincremental-linker-compatible"
end_comment

begin_comment
comment|// RUN: %clang '-###' %s -c -o tmp.o -target i686-pc-win32 -integrated-as 2>&1 | FileCheck %s --check-prefix=TEST6
end_comment

begin_comment
comment|// TEST6: "-cc1" {{.*}} "-mincremental-linker-compatible"
end_comment

end_unit

