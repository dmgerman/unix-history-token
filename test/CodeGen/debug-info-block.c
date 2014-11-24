begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fblocks -g -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Verify that the desired debugging type is generated for a structure
end_comment

begin_comment
comment|//  member that is a pointer to a block.
end_comment

begin_comment
comment|// CHECK: __block_literal_generic{{.*}}DW_TAG_structure_type
end_comment

begin_comment
comment|// CHECK: __block_descriptor{{.*}}DW_TAG_structure_type
end_comment

begin_struct
struct|struct
name|inStruct
block|{
name|void
function_decl|(
modifier|^
name|genericBlockPtr
function_decl|)
parameter_list|()
function_decl|;
block|}
name|is
struct|;
end_struct

end_unit

