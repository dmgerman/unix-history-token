begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-pch -o %t %S/preprocess.h&&
end_comment

begin_comment
comment|// RUN: clang-cc -include-pch %t -E -o - %s | grep -c "a_typedef" | count 1
end_comment

begin_include
include|#
directive|include
file|"preprocess.h"
end_include

begin_decl_stmt
name|int
name|a_value
decl_stmt|;
end_decl_stmt

end_unit

