begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple hexagon-unknown-elf -O2 -emit-llvm -o - | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|union
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|4
argument_list|)
operator|)
argument_list|)
block|{
name|unsigned
name|short
name|uh
index|[
literal|2
index|]
block|;
name|unsigned
name|uw
block|; }
end_typedef

begin_expr_stmt
name|vect32
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|bar
parameter_list|(
name|vect32
name|p
index|[]
index|[
literal|2
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: define void @fred
end_comment

begin_function
name|void
name|fred
parameter_list|(
name|unsigned
name|Num
parameter_list|,
name|int
name|Vec
index|[
literal|2
index|]
parameter_list|,
name|int
modifier|*
name|Index
parameter_list|,
name|int
name|Arr
index|[
literal|4
index|]
index|[
literal|2
index|]
parameter_list|)
block|{
name|vect32
name|Tmp
index|[
literal|4
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|// Generate tbaa for the load of Index:
comment|// CHECK: load i32, i32* %Index{{.*}}tbaa
comment|// But no tbaa for the two stores:
comment|// CHECK: %uw[[UW1:[0-9]*]] = getelementptr
comment|// CHECK: store{{.*}}%uw[[UW1]]
comment|// CHECK: tbaa ![[OCPATH:[0-9]+]]
comment|// There will be a load after the store, and it will use tbaa. Make sure
comment|// the check-not above doesn't find it:
comment|// CHECK: load
name|Tmp
index|[
operator|*
name|Index
index|]
index|[
literal|0
index|]
operator|.
name|uw
operator|=
name|Arr
index|[
operator|*
name|Index
index|]
index|[
literal|0
index|]
operator|*
name|Num
expr_stmt|;
comment|// CHECK: %uw[[UW2:[0-9]*]] = getelementptr
comment|// CHECK: store{{.*}}%uw[[UW2]]
comment|// CHECK: tbaa ![[OCPATH]]
name|Tmp
index|[
operator|*
name|Index
index|]
index|[
literal|1
index|]
operator|.
name|uw
operator|=
name|Arr
index|[
operator|*
name|Index
index|]
index|[
literal|1
index|]
operator|*
name|Num
expr_stmt|;
comment|// Same here, don't generate tbaa for the loads:
comment|// CHECK: %uh[[UH1:[0-9]*]] = bitcast %union.vect32
comment|// CHECK: %arrayidx[[AX1:[0-9]*]] = getelementptr{{.*}}%uh[[UH1]]
comment|// CHECK: load i16, i16* %arrayidx[[AX1]]
comment|// CHECK: tbaa ![[OCPATH]]
comment|// CHECK: store
name|Vec
index|[
literal|0
index|]
operator|=
name|Tmp
index|[
operator|*
name|Index
index|]
index|[
literal|0
index|]
operator|.
name|uh
index|[
literal|1
index|]
expr_stmt|;
comment|// CHECK: %uh[[UH2:[0-9]*]] = bitcast %union.vect32
comment|// CHECK: %arrayidx[[AX2:[0-9]*]] = getelementptr{{.*}}%uh[[UH2]]
comment|// CHECK: load i16, i16* %arrayidx[[AX2]]
comment|// CHECK: tbaa ![[OCPATH]]
comment|// CHECK: store
name|Vec
index|[
literal|1
index|]
operator|=
name|Tmp
index|[
operator|*
name|Index
index|]
index|[
literal|1
index|]
operator|.
name|uh
index|[
literal|1
index|]
expr_stmt|;
name|bar
argument_list|(
name|Tmp
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-DAG: ![[CHAR:[0-9]+]] = !{!"omnipotent char"
end_comment

begin_comment
comment|// CHECK-DAG: ![[OCPATH]] = !{![[CHAR]], ![[CHAR]], i64 0}
end_comment

end_unit

