begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -g -emit-llvm< %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -gline-tables-only -emit-llvm< %s | FileCheck --check-prefix=GMLT %s
end_comment

begin_comment
comment|// Two variables with same name in separate scope.
end_comment

begin_comment
comment|// Radar 8330217.
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|j
init|=
literal|0
decl_stmt|;
name|int
name|k
init|=
literal|0
decl_stmt|;
comment|// CHECK: DW_TAG_auto_variable ] [i]
comment|// CHECK-NEXT: DW_TAG_lexical_block
comment|// FIXME: Looks like we don't actually need both these lexical blocks (disc 2
comment|// just refers to disc 1, nothing actually uses disc 2).
comment|// GMLT-NOT: DW_TAG_lexical_block
comment|// GMLT: "0xb\002", {{.*}}} ; [ DW_TAG_lexical_block ]
comment|// GMLT-NOT: DW_TAG_lexical_block
comment|// GMLT: "0xb\001", {{.*}}} ; [ DW_TAG_lexical_block ]
comment|// Make sure we don't have any more lexical blocks because we don't need them in
comment|// -gmlt.
comment|// GMLT-NOT: DW_TAG_lexical_block
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
name|j
operator|++
expr_stmt|;
comment|// CHECK: DW_TAG_auto_variable ] [i]
comment|// CHECK-NEXT: DW_TAG_lexical_block
comment|// GMLT-NOT: DW_TAG_lexical_block
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
name|k
operator|++
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

