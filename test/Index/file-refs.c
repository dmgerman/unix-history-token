begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_enum
enum|enum
block|{
name|VALUE
init|=
literal|3
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|int
name|glob_x
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
operator|+
name|glob_x
operator|+
name|VALUE
return|;
block|}
end_function

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
name|Vector
typedef|;
end_typedef

begin_function
name|int
name|vector_get_x
parameter_list|(
name|Vector
name|v
parameter_list|)
block|{
name|int
name|x
init|=
name|v
operator|.
name|x
decl_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_function_decl
name|int
name|f
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|f
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// RUN: c-index-test \
end_comment

begin_comment
comment|// RUN:  -file-refs-at=%s:2:5 \
end_comment

begin_comment
comment|// CHECK:      EnumConstantDecl=VALUE:2:3 (Definition)
end_comment

begin_comment
comment|// CHECK-NEXT: EnumConstantDecl=VALUE:2:3 (Definition) =[2:3 - 2:8]
end_comment

begin_comment
comment|// CHECK-NEXT: DeclRefExpr=VALUE:2:3 =[8:19 - 8:24]
end_comment

begin_comment
comment|// RUN:  -file-refs-at=%s:8:15 \
end_comment

begin_comment
comment|// CHECK-NEXT: DeclRefExpr=glob_x:5:12
end_comment

begin_comment
comment|// CHECK-NEXT: VarDecl=glob_x:5:12 =[5:12 - 5:18]
end_comment

begin_comment
comment|// CHECK-NEXT: DeclRefExpr=glob_x:5:12 =[8:12 - 8:18]
end_comment

begin_comment
comment|// RUN:  -file-refs-at=%s:8:10 \
end_comment

begin_comment
comment|// CHECK-NEXT: DeclRefExpr=x:7:11
end_comment

begin_comment
comment|// CHECK-NEXT: ParmDecl=x:7:11 (Definition) =[7:11 - 7:12]
end_comment

begin_comment
comment|// CHECK-NEXT: DeclRefExpr=x:7:11 =[8:10 - 8:11]
end_comment

begin_comment
comment|// RUN:  -file-refs-at=%s:12:7 \
end_comment

begin_comment
comment|// CHECK-NEXT: FieldDecl=x:12:7 (Definition)
end_comment

begin_comment
comment|// CHECK-NEXT: FieldDecl=x:12:7 (Definition) =[12:7 - 12:8]
end_comment

begin_comment
comment|// CHECK-NEXT: MemberRefExpr=x:12:7 {{.*}} =[17:13 - 17:14]
end_comment

begin_comment
comment|// RUN:  -file-refs-at=%s:16:21 \
end_comment

begin_comment
comment|// CHECK-NEXT: TypeRef=Vector:14:3
end_comment

begin_comment
comment|// CHECK-NEXT: TypedefDecl=Vector:14:3 (Definition) =[14:3 - 14:9]
end_comment

begin_comment
comment|// CHECK-NEXT: TypeRef=Vector:14:3 =[16:18 - 16:24]
end_comment

begin_comment
comment|// RUN:  -file-refs-at=%s:21:5 \
end_comment

begin_comment
comment|// CHECK-NEXT: FunctionDecl=f:21:5
end_comment

begin_comment
comment|// CHECK-NEXT: FunctionDecl=f:7:5 (Definition) =[7:5 - 7:6]
end_comment

begin_comment
comment|// CHECK-NEXT: FunctionDecl=f:21:5 =[21:5 - 21:6]
end_comment

begin_comment
comment|// CHECK-NEXT: FunctionDecl=f:22:5 =[22:5 - 22:6]
end_comment

begin_comment
comment|// RUN:   %s | FileCheck %s
end_comment

end_unit

