begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// A test for the propagation of the -mmcu option to -cc1 and -cc1as
end_comment

begin_comment
comment|// RUN: %clang -### -target avr -no-canonical-prefixes -mmcu=atmega328p -save-temps %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: clang{{.*}} "-cc1" {{.*}} "-target-cpu" "atmega328p"
end_comment

begin_comment
comment|// CHECK: clang{{.*}} "-cc1as" {{.*}} "-target-cpu" "atmega328p"
end_comment

end_unit

