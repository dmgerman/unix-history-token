begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -emit-llvm -S -g %s -o %t
end_comment

begin_comment
comment|// RUN: grep DW_TAG_lexical_block %t | count 3
end_comment

begin_comment
comment|// Radar 8396182
end_comment

begin_comment
comment|// There are three lexical blocks in this test case.
end_comment

begin_function
name|int
name|foo
parameter_list|()
block|{
name|int
name|i
init|=
literal|1
decl_stmt|;
empty|# 4 "m.c"
empty|# 1 "m.h" 1
name|int
name|j
init|=
literal|2
decl_stmt|;
empty|# 2 "m.h"
empty|# 5 "m.c" 2
return|return
name|i
operator|+
name|j
return|;
block|}
end_function

end_unit

