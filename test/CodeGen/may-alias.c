begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Werror -triple i386-unknown-unknown -emit-llvm -O1 -no-struct-path-tbaa -disable-llvm-optzns -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Werror -triple i386-unknown-unknown -emit-llvm -O1 -disable-llvm-optzns -o - %s | FileCheck %s -check-prefix=PATH
end_comment

begin_comment
comment|// Types with the may_alias attribute should be considered equivalent
end_comment

begin_comment
comment|// to char for aliasing.
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|may_alias
operator|)
argument_list|)
name|aliasing_int
typedef|;
end_typedef

begin_function
name|void
name|test0
parameter_list|(
name|aliasing_int
modifier|*
name|ai
parameter_list|,
name|int
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: store i32 0, i32* %{{.*}}, !tbaa [[TAG_CHAR:!.*]]
comment|// PATH: store i32 0, i32* %{{.*}}, !tbaa [[TAG_CHAR:!.*]]
operator|*
name|ai
operator|=
literal|0
expr_stmt|;
comment|// CHECK: store i32 1, i32* %{{.*}}, !tbaa [[TAG_INT:!.*]]
comment|// PATH: store i32 1, i32* %{{.*}}, !tbaa [[TAG_INT:!.*]]
operator|*
name|i
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|// PR9307
end_comment

begin_struct
struct|struct
name|Test1
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Test1MA
block|{
name|int
name|x
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|may_alias
operator|)
argument_list|)
struct|;
end_struct

begin_function
name|void
name|test1
parameter_list|(
name|struct
name|Test1MA
modifier|*
name|p1
parameter_list|,
name|struct
name|Test1
modifier|*
name|p2
parameter_list|)
block|{
comment|// CHECK: store i32 2, i32* {{%.*}}, !tbaa [[TAG_CHAR]]
comment|// PATH: store i32 2, i32* {{%.*}}, !tbaa [[TAG_CHAR]]
name|p1
operator|->
name|x
operator|=
literal|2
expr_stmt|;
comment|// CHECK: store i32 3, i32* {{%.*}}, !tbaa [[TAG_INT]]
comment|// PATH: store i32 3, i32* {{%.*}}, !tbaa [[TAG_test1_x:!.*]]
name|p2
operator|->
name|x
operator|=
literal|3
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK:  !"any pointer", [[TYPE_CHAR:!.*]],
end_comment

begin_comment
comment|// CHECK: [[TYPE_CHAR]] = !{!"omnipotent char", [[TAG_CXX_TBAA:!.*]],
end_comment

begin_comment
comment|// CHECK: [[TAG_CXX_TBAA]] = !{!"Simple C/C++ TBAA"}
end_comment

begin_comment
comment|// CHECK: [[TAG_CHAR]] = !{[[TYPE_CHAR]], [[TYPE_CHAR]], i64 0}
end_comment

begin_comment
comment|// CHECK: [[TAG_INT]] = !{[[TYPE_INT:!.*]], [[TYPE_INT]], i64 0}
end_comment

begin_comment
comment|// CHECK: [[TYPE_INT]] = !{!"int", [[TYPE_CHAR]]
end_comment

begin_comment
comment|// PATH: [[TYPE_CHAR:!.*]] = !{!"omnipotent char", !{{.*}}
end_comment

begin_comment
comment|// PATH: [[TAG_CHAR]] = !{[[TYPE_CHAR]], [[TYPE_CHAR]], i64 0}
end_comment

begin_comment
comment|// PATH: [[TAG_INT]] = !{[[TYPE_INT:!.*]], [[TYPE_INT]], i64 0}
end_comment

begin_comment
comment|// PATH: [[TYPE_INT]] = !{!"int", [[TYPE_CHAR]]
end_comment

begin_comment
comment|// PATH: [[TAG_test1_x]] = !{[[TYPE_test1:!.*]], [[TYPE_INT]], i64 0}
end_comment

begin_comment
comment|// PATH: [[TYPE_test1]] = !{!"Test1", [[TYPE_INT]], i64 0}
end_comment

end_unit

