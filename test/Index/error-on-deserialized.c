begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"targeted-top.h"
end_include

begin_comment
comment|// This tests that we will correctly error out on the deserialized decl.
end_comment

begin_comment
comment|// RUN: c-index-test -write-pch %t.h.pch %S/targeted-top.h
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 not c-index-test -cursor-at=%S/targeted-nested1.h:2:16 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=NestedVar1
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_FAILONERROR=1 not c-index-test -cursor-at=%S/targeted-nested1.h:2:16 %s -include %t.h \
end_comment

begin_comment
comment|// RUN:    -Xclang -error-on-deserialized-decl=NestedVar1 2>&1 \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s
end_comment

begin_comment
comment|// CHECK: error: NestedVar1 was deserialized
end_comment

end_unit

