begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S -O2 -g %s -o - | llc -O2 -mtriple=i386-apple-darwin | FileCheck %s
end_comment

begin_comment
comment|// Use DW_FORM_addr for DW_AT_entry_pc.
end_comment

begin_comment
comment|// Radar 8094785
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// XTARGET: x86,i386,i686
end_comment

begin_comment
comment|// CHECK:	.byte	17                      ## DW_TAG_compile_unit
end_comment

begin_comment
comment|// CHECK-NEXT:	.byte	1                       ## DW_CHILDREN_yes
end_comment

begin_comment
comment|// CHECK-NEXT:	.byte	37                      ## DW_AT_producer
end_comment

begin_comment
comment|// CHECK-NEXT:	.byte	8                       ## DW_FORM_string
end_comment

begin_comment
comment|// CHECK-NEXT:	.byte	19                      ## DW_AT_language
end_comment

begin_comment
comment|// CHECK-NEXT:	.byte	11                      ## DW_FORM_data1
end_comment

begin_comment
comment|// CHECK-NEXT:	.byte	3                       ## DW_AT_name
end_comment

begin_comment
comment|// CHECK-NEXT:	.byte	8                       ## DW_FORM_string
end_comment

begin_comment
comment|// CHECK-NEXT:	.byte	82                      ## DW_AT_entry_pc
end_comment

begin_comment
comment|// CHECK-NEXT:	.byte	1                       ## DW_FORM_addr
end_comment

begin_comment
comment|// CHECK-NEXT:	.byte	16                      ## DW_AT_stmt_list
end_comment

begin_comment
comment|// CHECK-NEXT:	.byte	6                       ## DW_FORM_data4
end_comment

begin_comment
comment|// CHECK-NEXT:	.byte	27                      ## DW_AT_comp_dir
end_comment

begin_comment
comment|// CHECK-NEXT:	.byte	8                       ## DW_FORM_string
end_comment

begin_comment
comment|// CHECK-NEXT:	.byte	225                     ## DW_AT_APPLE_optimized
end_comment

begin_struct
struct|struct
name|a
block|{
name|int
name|c
decl_stmt|;
name|struct
name|a
modifier|*
name|d
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|ret
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|foo
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noinline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
modifier|*
name|bar
parameter_list|(
name|struct
name|a
modifier|*
name|b
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noinline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|foo
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|ret
operator|=
name|x
expr_stmt|;
block|}
end_function

begin_function
name|void
modifier|*
name|bar
parameter_list|(
name|struct
name|a
modifier|*
name|b
parameter_list|)
block|{
name|foo
argument_list|(
name|b
operator|->
name|c
argument_list|)
expr_stmt|;
return|return
name|b
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|struct
name|a
name|e
decl_stmt|;
name|e
operator|.
name|c
operator|=
literal|4
expr_stmt|;
name|e
operator|.
name|d
operator|=
operator|&
name|e
expr_stmt|;
operator|(
name|void
operator|)
name|bar
argument_list|(
operator|&
name|e
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

end_unit

