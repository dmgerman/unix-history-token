begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Werror -triple i386-unknown-unknown -emit-llvm -O1 -disable-llvm-optzns -o %t %s
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
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
comment|// CHECK: store i32 0, i32* %{{.*}}, !tbaa !1
operator|*
name|ai
operator|=
literal|0
expr_stmt|;
comment|// CHECK: store i32 1, i32* %{{.*}}, !tbaa !3
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
comment|// CHECK: store i32 2, i32* {{%.*}}, !tbaa !1
name|p1
operator|->
name|x
operator|=
literal|2
expr_stmt|;
comment|// CHECK: store i32 3, i32* {{%.*}}, !tbaa !3
name|p2
operator|->
name|x
operator|=
literal|3
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: !0 = metadata !{metadata !"any pointer", metadata !1}
end_comment

begin_comment
comment|// CHECK: !1 = metadata !{metadata !"omnipotent char", metadata !2}
end_comment

begin_comment
comment|// CHECK: !2 = metadata !{metadata !"Simple C/C++ TBAA", null}
end_comment

begin_comment
comment|// CHECK: !3 = metadata !{metadata !"int", metadata !1}
end_comment

end_unit

