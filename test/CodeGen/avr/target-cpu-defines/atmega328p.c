begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: avr-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -triple avr-unknown-unknown -target-cpu atmega328p /dev/null | FileCheck -match-full-lines %s
end_comment

begin_comment
comment|// CHECK: #define AVR 1
end_comment

begin_comment
comment|// CHECK: #define __AVR 1
end_comment

begin_comment
comment|// CHECK: #define __AVR_ATmega328P__ 1
end_comment

begin_comment
comment|// CHECK: #define __AVR__ 1
end_comment

end_unit

