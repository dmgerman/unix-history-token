begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux -O1 -fsanitize=cfi-icall -fsanitize-cfi-cross-dso -emit-llvm -o - %s | FileCheck --check-prefix=CHECK --check-prefix=ITANIUM %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-windows-msvc -O1 -fsanitize=cfi-icall  -fsanitize-cfi-cross-dso -emit-llvm -o - %s | FileCheck --check-prefix=CHECK --check-prefix=MS %s
end_comment

begin_function
name|void
name|caller
parameter_list|(
name|void
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|()
parameter_list|)
block|{
name|f
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|g
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function_decl
name|void
name|h
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|Fn
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function
name|Fn
name|g1
parameter_list|()
block|{
return|return
operator|&
name|g
return|;
block|}
end_function

begin_function
name|Fn
name|h1
parameter_list|()
block|{
return|return
operator|&
name|h
return|;
block|}
end_function

begin_function
specifier|inline
name|void
name|foo
parameter_list|()
block|{}
end_function

begin_function
name|void
name|bar
parameter_list|()
block|{
name|foo
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// ITANIUM: call i1 @llvm.bitset.test(i8* %{{.*}}, metadata !"_ZTSFvE"), !nosanitize
end_comment

begin_comment
comment|// ITANIUM: call void @__cfi_slowpath(i64 6588678392271548388, i8* %{{.*}}) {{.*}}, !nosanitize
end_comment

begin_comment
comment|// MS: call i1 @llvm.bitset.test(i8* %{{.*}}, metadata !"?6AX@Z"), !nosanitize
end_comment

begin_comment
comment|// MS: call void @__cfi_slowpath(i64 4195979634929632483, i8* %{{.*}}) {{.*}}, !nosanitize
end_comment

begin_comment
comment|// ITANIUM: define available_externally void @foo()
end_comment

begin_comment
comment|// MS: define linkonce_odr void @foo()
end_comment

begin_comment
comment|// Check that we emit both string and hash based bit set entries for static void g(),
end_comment

begin_comment
comment|// and don't emit them for the declaration of h().
end_comment

begin_comment
comment|// CHECK-NOT: !{!"{{.*}}", void ()* @h, i64 0}
end_comment

begin_comment
comment|// CHECK: !{!"{{.*}}", void ()* @g, i64 0}
end_comment

begin_comment
comment|// CHECK-NOT: !{!"{{.*}}", void ()* @h, i64 0}
end_comment

begin_comment
comment|// CHECK: !{i64 {{.*}}, void ()* @g, i64 0}
end_comment

begin_comment
comment|// CHECK-NOT: !{!"{{.*}}", void ()* @h, i64 0}
end_comment

begin_comment
comment|// ITANIUM-NOT: !{!{{.*}}, void ()* @foo,
end_comment

begin_comment
comment|// ITANIUM: !{!"_ZTSFvE", void ()* @bar, i64 0}
end_comment

begin_comment
comment|// ITANIUM-NOT: !{!{{.*}}, void ()* @foo,
end_comment

begin_comment
comment|// ITANIUM: !{i64 6588678392271548388, void ()* @bar, i64 0}
end_comment

begin_comment
comment|// ITANIUM-NOT: !{!{{.*}}, void ()* @foo,
end_comment

begin_comment
comment|// MS: !{!"?6AX@Z", void ()* @foo, i64 0}
end_comment

begin_comment
comment|// MS: !{i64 4195979634929632483, void ()* @foo, i64 0}
end_comment

begin_comment
comment|// CHECK: !{i32 4, !"Cross-DSO CFI", i32 1}
end_comment

end_unit

