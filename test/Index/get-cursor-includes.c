begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"get-cursor-includes-2.h"
end_include

begin_include
include|#
directive|include
file|"get-cursor-includes-2.h"
end_include

begin_comment
comment|// RUN: c-index-test -write-pch %t.h.pch -I%S/Inputs -Xclang -detailed-preprocessing-record %S/Inputs/get-cursor-includes-2.h
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%S/Inputs/get-cursor-includes-2.h:1:5 -I%S/Inputs -include %t.h %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: inclusion directive=get-cursor-includes-1.h
end_comment

end_unit

