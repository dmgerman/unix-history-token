begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux -fsanitize=cfi-icall -fsanitize-trap=cfi-icall -emit-llvm -o - %s | FileCheck --check-prefix=CHECK --check-prefix=ITANIUM %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-windows-msvc -fsanitize=cfi-icall -fsanitize-trap=cfi-icall -emit-llvm -o - %s | FileCheck --check-prefix=CHECK --check-prefix=MS %s
end_comment

begin_comment
comment|// Tests that we assign appropriate identifiers to unprototyped functions.
end_comment

begin_comment
comment|// CHECK: define void @f({{.*}} !type [[TVOID:![0-9]+]]
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{ }
end_function

begin_function_decl
name|void
name|xf
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: define void @g({{.*}} !type [[TINT:![0-9]+]]
end_comment

begin_function
name|void
name|g
parameter_list|(
name|int
name|b
parameter_list|)
block|{
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|()
init|=
name|b
condition|?
name|f
operator|:
name|xf
function_decl|;
comment|// ITANIUM: call i1 @llvm.type.test(i8* {{.*}}, metadata !"_ZTSFvE")
name|fp
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare !type [[TVOID:![0-9]+]] void @xf({{.*}}
end_comment

begin_comment
comment|// ITANIUM-DAG: [[TVOID]] = !{i64 0, !"_ZTSFvE"}
end_comment

begin_comment
comment|// ITANIUM-DAG: [[TINT]] = !{i64 0, !"_ZTSFviE"}
end_comment

begin_comment
comment|// MS-DAG: [[TVOID]] = !{i64 0, !"?6AX@Z"}
end_comment

begin_comment
comment|// MS-DAG: [[TINT]] = !{i64 0, !"?6AXH@Z"}
end_comment

end_unit

