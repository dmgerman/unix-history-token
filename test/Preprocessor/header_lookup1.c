begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fno-ms-extensions %s -E | grep 'stddef.h.*3.*4'
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

end_unit

