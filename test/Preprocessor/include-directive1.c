begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s -fno-caret-diagnostics 2>&1>/dev/null | grep 'file successfully included' | count 3
end_comment

begin_comment
comment|// XX expands to nothing.
end_comment

begin_define
define|#
directive|define
name|XX
end_define

begin_comment
comment|// expand macros to get to file to include
end_comment

begin_define
define|#
directive|define
name|FILE
value|"file_to_include.h"
end_define

begin_include
include|#
directive|include
include|XX FILE
end_include

begin_include
include|#
directive|include
include|FILE
end_include

begin_comment
comment|// normal include
end_comment

begin_include
include|#
directive|include
file|"file_to_include.h"
end_include

end_unit

