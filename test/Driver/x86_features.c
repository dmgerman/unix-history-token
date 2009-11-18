begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -### -S %s -msse -msse4 -mno-sse -mno-mmx -msse 2> %t
end_comment

begin_comment
comment|// RUN: grep '"-target-feature" "+sse" "-target-feature" "+sse4" "-target-feature" "-sse" "-target-feature" "-mmx" "-target-feature" "+sse"' %t
end_comment

end_unit

