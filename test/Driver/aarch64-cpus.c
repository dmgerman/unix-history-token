begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check target CPUs are correctly passed.
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC %s
end_comment

begin_comment
comment|// GENERIC: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53 %s
end_comment

begin_comment
comment|// CA53: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a53"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57 %s
end_comment

begin_comment
comment|// CA57: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a57"
end_comment

end_unit

