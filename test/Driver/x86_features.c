begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -### -S %s -msse -msse4 -mno-sse -mno-mmx -msse  2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "pentium4" "-target-feature" "+sse4" "-target-feature" "-mmx" "-target-feature" "+sse"
end_comment

begin_comment
comment|// Note that we filter out all but the last -m(no)sse.
end_comment

begin_comment
comment|// Test that we don't produce an error with -mieee-fp.
end_comment

begin_comment
comment|// RUN: %clang -### %s -mieee-fp -S 2>&1 | FileCheck --check-prefix=IEEE %s
end_comment

begin_comment
comment|// IEEE-NOT: error: unknown argument
end_comment

end_unit

