begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// A basic clang -cc1 command-line.
end_comment

begin_comment
comment|// RUN: %clang %s -### -no-canonical-prefixes -target avr 2>&1 | FileCheck -check-prefix=CC1 %s
end_comment

begin_comment
comment|// CC1: clang{{.*}} "-cc1" "-triple" "avr"
end_comment

end_unit

