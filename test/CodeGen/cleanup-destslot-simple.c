begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -triple x86_64-none-linux-gnu -emit-llvm -debug-info-kind=line-tables-only %s -o - | FileCheck %s --check-prefix=CHECK --check-prefix=LIFETIME
end_comment

begin_comment
comment|// We shouldn't have markers at -O0 or with msan.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O0 -triple x86_64-none-linux-gnu -emit-llvm -debug-info-kind=line-tables-only %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O1 -triple x86_64-none-linux-gnu -emit-llvm -debug-info-kind=line-tables-only %s -o - -fsanitize=memory | FileCheck %s
end_comment

begin_comment
comment|// There is no exception to handle here, lifetime.end is not a destructor,
end_comment

begin_comment
comment|// so there is no need have cleanup dest slot related code
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @test
end_comment

begin_function
name|int
name|test
parameter_list|()
block|{
name|int
name|x
init|=
literal|3
decl_stmt|;
name|int
modifier|*
specifier|volatile
name|p
init|=
operator|&
name|x
decl_stmt|;
return|return
operator|*
name|p
return|;
comment|// CHECK: [[X:%.*]] = alloca i32
comment|// CHECK: [[P:%.*]] = alloca i32*
comment|// LIFETIME: call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %{{.*}}){{( #[0-9]+)?}}, !dbg
comment|// LIFETIME: call void @llvm.lifetime.start.p0i8(i64 8, i8* nonnull %{{.*}}){{( #[0-9]+)?}}, !dbg
comment|// CHECK-NOT: store i32 %{{.*}}, i32* %cleanup.dest.slot
comment|// LIFETIME: call void @llvm.lifetime.end.p0i8(i64 8, {{.*}}){{( #[0-9]+)?}}, !dbg
comment|// LIFETIME: call void @llvm.lifetime.end.p0i8(i64 4, {{.*}}){{( #[0-9]+)?}}, !dbg
block|}
end_function

end_unit

