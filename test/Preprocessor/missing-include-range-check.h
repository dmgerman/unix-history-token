begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env CINDEXTEST_KEEP_GOING=1 c-index-test -test-load-source all %s> /dev/null 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck< %t.err -check-prefix=CHECK-RANGE %s
end_comment

begin_include
include|#
directive|include
file|<foobar.h>
end_include

begin_include
include|#
directive|include
file|"moozegnarf.h"
end_include

begin_comment
comment|// CHECK-RANGE: rewrite-includes-missing.c:4:10:{4:10-4:19}: fatal error: 'foobar.h' file not found
end_comment

begin_comment
comment|// CHECK-RANGE: rewrite-includes-missing.c:5:10:{5:10-5:24}: fatal error: 'moozegnarf.h' file not found
end_comment

end_unit

