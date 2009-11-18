begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-pth %s -o %t
end_comment

begin_comment
comment|// RUN: clang-cc -include-pth %t %s -E | grep 'file_to_include' | count 2
end_comment

begin_include
include|#
directive|include
file|"file_to_include.h"
end_include

end_unit

