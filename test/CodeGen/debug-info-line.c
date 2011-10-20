begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -emit-llvm -S -g %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Radar 8396182
end_comment

begin_comment
comment|// There is only one lexical block, but we need a DILexicalBlock and two
end_comment

begin_comment
comment|// DILexicalBlockFile to correctly represent file info. This means we have
end_comment

begin_comment
comment|// two lexical blocks shown as the latter is also tagged as a lexical block.
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

begin_comment
comment|// CHECK: DW_TAG_lexical_block
end_comment

begin_comment
comment|// CHECK: DW_TAG_lexical_block
end_comment

begin_comment
comment|// CHECK: !"m.h"
end_comment

begin_comment
comment|// CHECK: DW_TAG_lexical_block
end_comment

begin_comment
comment|// CHECK: !"m.c"
end_comment

begin_comment
comment|// CHECK-NOT: DW_TAG_lexical_block
end_comment

end_unit

