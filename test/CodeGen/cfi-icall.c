begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux -fsanitize=cfi-icall -fsanitize-trap=cfi-icall -emit-llvm -o - %s | FileCheck --check-prefix=ITANIUM %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-windows-msvc -fsanitize=cfi-icall -fsanitize-trap=cfi-icall -emit-llvm -o - %s | FileCheck --check-prefix=MS %s
end_comment

begin_comment
comment|// Tests that we assign appropriate identifiers to unprototyped functions.
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
comment|// ITANIUM: call i1 @llvm.bitset.test(i8* {{.*}}, metadata !"_ZTSFvE")
name|fp
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// ITANIUM-DAG: !{!"_ZTSFvE", void ()* @f, i64 0}
end_comment

begin_comment
comment|// ITANIUM-DAG: !{!"_ZTSFvE", void (...)* @xf, i64 0}
end_comment

begin_comment
comment|// MS-DAG: !{!"?6AX@Z", void ()* @f, i64 0}
end_comment

begin_comment
comment|// MS-DAG: !{!"?6AX@Z", void (...)* @xf, i64 0}
end_comment

end_unit

