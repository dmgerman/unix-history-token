begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -M -MG -include nonexistent-preinclude.h %s> %t
end_comment

begin_comment
comment|// RUN: fgrep nonexistent-preinclude.h %t
end_comment

begin_comment
comment|// RUN: fgrep nonexistent-ppinclude.h %t
end_comment

begin_include
include|#
directive|include
file|"nonexistent-ppinclude.h"
end_include

end_unit

