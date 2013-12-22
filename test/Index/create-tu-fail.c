begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -f %t.c
end_comment

begin_comment
comment|// RUN: touch %t.c
end_comment

begin_comment
comment|// RUN: c-index-test -write-pch %t.pch %t.c
end_comment

begin_comment
comment|// RUN: cp %s %t.c
end_comment

begin_comment
comment|// RUN: not c-index-test -test-load-tu %t.pch local 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// rdar://11558355
end_comment

begin_comment
comment|// Unfortunately this would crash reliably only via valgrind.
end_comment

begin_comment
comment|// CHECK: Unable to load translation unit
end_comment

end_unit

