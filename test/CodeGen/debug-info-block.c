begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fblocks -debug-info-kind=limited -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Verify that the desired debugging type is generated for a structure
end_comment

begin_comment
comment|// member that is a pointer to a block.
end_comment

begin_comment
comment|// CHECK: !DICompositeType(tag: DW_TAG_structure_type, scope
end_comment

begin_comment
comment|// CHECK-NOT:              line
end_comment

begin_comment
comment|// CHECK-SAME:             elements: ![[ELEMS1:.*]])
end_comment

begin_comment
comment|// CHECK: ![[ELEMS1]] = {{.*, .*, .*,}} ![[FPEL1:.*]], {{.*}}
end_comment

begin_comment
comment|// CHECK: ![[INT:.*]] = !DIBasicType(name: "int"
end_comment

begin_comment
comment|// CHECK: ![[FPEL1]] = {{.*}}"__FuncPtr", {{.*}}, baseType: ![[FPTY1:[0-9]+]]
end_comment

begin_comment
comment|// CHECK: ![[FPTY1]] = {{.*}}baseType: ![[FNTY1:[0-9]+]]
end_comment

begin_comment
comment|// CHECK: ![[FNTY1]] = !DISubroutineType(types: ![[VOIDVOID:[0-9]+]])
end_comment

begin_comment
comment|// CHECK: ![[VOIDVOID]] = !{null, null}
end_comment

begin_comment
comment|// CHECK: !DICompositeType(tag: DW_TAG_structure_type, name: "__block_descriptor"
end_comment

begin_comment
comment|// CHECK-NOT:              line
end_comment

begin_comment
comment|// CHECK-SAME:            )
end_comment

begin_comment
comment|// CHECK: !DICompositeType(tag: DW_TAG_structure_type, scope
end_comment

begin_comment
comment|// CHECK-NOT:              line
end_comment

begin_comment
comment|// CHECK-SAME:             elements: ![[ELEMS2:.*]])
end_comment

begin_comment
comment|// CHECK: ![[ELEMS2]] = {{.*,.*,.*}}, ![[FPEL2:.*]], {{.*}}
end_comment

begin_comment
comment|// CHECK: ![[FPEL2]] = {{.*}}"__FuncPtr", {{.*}}, baseType: ![[FPTY2:[0-9]+]]
end_comment

begin_comment
comment|// CHECK: ![[FPTY2]] = {{.*}}baseType: ![[FNTY2:[0-9]+]]
end_comment

begin_comment
comment|// CHECK: ![[FNTY2]] = !DISubroutineType(types: ![[INTINT:[0-9]+]])
end_comment

begin_comment
comment|// CHECK: ![[INTINT]] = !{![[INT]], ![[INT]]}
end_comment

begin_struct
struct|struct
name|inStruct
block|{
name|void
function_decl|(
modifier|^
name|voidBlockPtr
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|^
name|intBlockPtr
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
block|}
name|is
struct|;
end_struct

end_unit

