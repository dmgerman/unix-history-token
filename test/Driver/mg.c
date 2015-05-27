begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -M -MG -include nonexistent-preinclude.h %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: nonexistent-preinclude.h
end_comment

begin_comment
comment|// CHECK: nonexistent-ppinclude.h
end_comment

begin_include
include|#
directive|include
file|"nonexistent-ppinclude.h"
end_include

end_unit

