begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown %s -emit-llvm -o - | FileCheck %s
end_comment

begin_struct
struct|struct
name|foo
block|{
name|void
modifier|*
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: @u = global %union.anon zeroinitializer
end_comment

begin_union
union|union
block|{
name|int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
name|u
init|=
block|{ }
union|;
end_union

begin_comment
comment|// CHECK: @u2 = global %0 { i32 0, [4 x i8] undef }
end_comment

begin_union
union|union
block|{
name|int
name|i
decl_stmt|;
name|double
name|f
decl_stmt|;
block|}
name|u2
init|=
block|{ }
union|;
end_union

begin_comment
comment|// CHECK: @u3 = global %1 zeroinitializer
end_comment

begin_union
union|union
block|{
name|double
name|f
decl_stmt|;
name|int
name|i
decl_stmt|;
block|}
name|u3
init|=
block|{ }
union|;
end_union

begin_comment
comment|// CHECK: @b = global [2 x i32] [i32 0, i32 22]
end_comment

begin_decl_stmt
name|int
name|b
index|[
literal|2
index|]
init|=
block|{
index|[
literal|1
index|]
operator|=
literal|22
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
comment|// CHECK: internal global %struct.foo { i8* null, i32 1024 }
specifier|static
name|struct
name|foo
name|foo
init|=
block|{
operator|.
name|b
operator|=
literal|1024
block|,   }
decl_stmt|;
comment|// CHECK: bitcast %union.anon* %u2
comment|// CHECK: call void @llvm.memset
union|union
block|{
name|int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
name|u2
init|=
block|{ }
union|;
comment|// CHECK-NOT: call void @llvm.memset
union|union
block|{
name|int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
name|u3
union|;
comment|// CHECK: ret i32
block|}
end_function

end_unit

