begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux -O1 \
end_comment

begin_comment
comment|// RUN:   -fsanitize=cfi-icall -fsanitize-cfi-cross-dso \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -o - %s | FileCheck \
end_comment

begin_comment
comment|// RUN:       --check-prefix=CHECK --check-prefix=CHECK-DIAG \
end_comment

begin_comment
comment|// RUN:       --check-prefix=ITANIUM --check-prefix=ITANIUM-DIAG \
end_comment

begin_comment
comment|// RUN:       %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux -O1 \
end_comment

begin_comment
comment|// RUN:   -fsanitize=cfi-icall -fsanitize-cfi-cross-dso -fsanitize-trap=cfi-icall \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -o - %s | FileCheck \
end_comment

begin_comment
comment|// RUN:       --check-prefix=CHECK \
end_comment

begin_comment
comment|// RUN:       --check-prefix=ITANIUM --check-prefix=ITANIUM-TRAP \
end_comment

begin_comment
comment|// RUN:       %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-windows-msvc -O1 \
end_comment

begin_comment
comment|// RUN:   -fsanitize=cfi-icall -fsanitize-cfi-cross-dso \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -o - %s | FileCheck \
end_comment

begin_comment
comment|// RUN:       --check-prefix=CHECK --check-prefix=CHECK-DIAG \
end_comment

begin_comment
comment|// RUN:       --check-prefix=MS --check-prefix=MS-DIAG \
end_comment

begin_comment
comment|// RUN:       %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-windows-msvc -O1 \
end_comment

begin_comment
comment|// RUN:   -fsanitize=cfi-icall -fsanitize-cfi-cross-dso -fsanitize-trap=cfi-icall \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -o - %s | FileCheck \
end_comment

begin_comment
comment|// RUN:       --check-prefix=CHECK \
end_comment

begin_comment
comment|// RUN:       --check-prefix=MS --check-prefix=MS-TRAP \
end_comment

begin_comment
comment|// RUN:       %s
end_comment

begin_comment
comment|// CHECK-DIAG: @[[SRC:.*]] = private unnamed_addr constant {{.*}}cfi-icall-cross-dso.c\00
end_comment

begin_comment
comment|// CHECK-DIAG: @[[TYPE:.*]] = private unnamed_addr constant { i16, i16, [{{.*}} x i8] } { i16 -1, i16 0, [{{.*}} x i8] c"'void ()'\00"
end_comment

begin_comment
comment|// CHECK-DIAG: @[[DATA:.*]] = private unnamed_addr global {{.*}}@[[SRC]]{{.*}}@[[TYPE]]
end_comment

begin_comment
comment|// ITANIUM: call i1 @llvm.type.test(i8* %{{.*}}, metadata !"_ZTSFvE"), !nosanitize
end_comment

begin_comment
comment|// ITANIUM-DIAG: call void @__cfi_slowpath_diag(i64 6588678392271548388, i8* %{{.*}}, {{.*}}@[[DATA]]{{.*}}) {{.*}}, !nosanitize
end_comment

begin_comment
comment|// ITANIUM-TRAP: call void @__cfi_slowpath(i64 6588678392271548388, i8* %{{.*}}) {{.*}}, !nosanitize
end_comment

begin_comment
comment|// MS: call i1 @llvm.type.test(i8* %{{.*}}, metadata !"?6AX@Z"), !nosanitize
end_comment

begin_comment
comment|// MS-DIAG: call void @__cfi_slowpath_diag(i64 4195979634929632483, i8* %{{.*}}, {{.*}}@[[DATA]]{{.*}}) {{.*}}, !nosanitize
end_comment

begin_comment
comment|// MS-TRAP: call void @__cfi_slowpath(i64 4195979634929632483, i8* %{{.*}}) {{.*}}, !nosanitize
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

begin_comment
comment|// Check that we emit both string and hash based type entries for static void g(),
end_comment

begin_comment
comment|// and don't emit them for the declaration of h().
end_comment

begin_comment
comment|// CHECK: define internal void @g({{.*}} !type [[TVOID:![0-9]+]] !type [[TVOID_ID:![0-9]+]]
end_comment

begin_function
specifier|static
name|void
name|g
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: declare void @h({{[^!]*$}}
end_comment

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

begin_comment
comment|// CHECK: define void @bar({{.*}} !type [[TNOPROTO:![0-9]+]] !type [[TNOPROTO_ID:![0-9]+]]
end_comment

begin_comment
comment|// ITANIUM: define available_externally void @foo({{[^!]*$}}
end_comment

begin_comment
comment|// MS: define linkonce_odr void @foo({{.*}} !type [[TNOPROTO]] !type [[TNOPROTO_ID]]
end_comment

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
comment|// CHECK: !{i32 4, !"Cross-DSO CFI", i32 1}
end_comment

begin_comment
comment|// Check that the type entries are correct.
end_comment

begin_comment
comment|// ITANIUM: [[TVOID]] = !{i64 0, !"_ZTSFvvE"}
end_comment

begin_comment
comment|// ITANIUM: [[TVOID_ID]] = !{i64 0, i64 9080559750644022485}
end_comment

begin_comment
comment|// ITANIUM: [[TNOPROTO]] = !{i64 0, !"_ZTSFvE"}
end_comment

begin_comment
comment|// ITANIUM: [[TNOPROTO_ID]] = !{i64 0, i64 6588678392271548388}
end_comment

begin_comment
comment|// MS: [[TVOID]] = !{i64 0, !"?6AXXZ"}
end_comment

begin_comment
comment|// MS: [[TVOID_ID]] = !{i64 0, i64 5113650790573562461}
end_comment

begin_comment
comment|// MS: [[TNOPROTO]] = !{i64 0, !"?6AX@Z"}
end_comment

begin_comment
comment|// MS: [[TNOPROTO_ID]] = !{i64 0, i64 4195979634929632483}
end_comment

end_unit

