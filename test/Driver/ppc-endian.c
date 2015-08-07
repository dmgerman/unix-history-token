begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target powerpc64le -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-LE %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64le -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-LE %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-LE %s
end_comment

begin_comment
comment|// CHECK-LE: "-cc1"{{.*}} "-triple" "powerpc64le{{.*}}"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64le -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE %s
end_comment

begin_comment
comment|// CHECK-BE: "-cc1"{{.*}} "-triple" "powerpc64{{.*}}"
end_comment

end_unit

