begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -DTEST_XSAVE -O0 -triple=i686-unknown-unknown -target-feature +xsave -emit-llvm -o - -Werror | FileCheck %s --check-prefix=XSAVE
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -DTEST_XSAVE -O0 -triple=i686-unknown-unknown -target-feature +xsave -fno-signed-char -emit-llvm -o - -Werror | FileCheck %s --check-prefix=XSAVE
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -DTEST_XSAVEOPT -O0 -triple=i686-unknown-unknown -target-feature +xsave -target-feature +xsaveopt -emit-llvm -o - -Werror | FileCheck %s --check-prefix=XSAVEOPT
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -DTEST_XSAVEOPT -O0 -triple=i686-unknown-unknown -target-feature +xsave -target-feature +xsaveopt -fno-signed-char -emit-llvm -o - -Werror | FileCheck %s --check-prefix=XSAVEOPT
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -DTEST_XSAVEC -O0 -triple=i686-unknown-unknown -target-feature +xsave -target-feature +xsavec -emit-llvm -o - -Werror | FileCheck %s --check-prefix=XSAVEC
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -DTEST_XSAVEC -O0 -triple=i686-unknown-unknown -target-feature +xsave -target-feature +xsavec -fno-signed-char -emit-llvm -o - -Werror | FileCheck %s --check-prefix=XSAVEC
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -DTEST_XSAVES -O0 -triple=i686-unknown-unknown -target-feature +xsave -target-feature +xsaves -emit-llvm -o - -Werror | FileCheck %s --check-prefix=XSAVES
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -DTEST_XSAVES -O0 -triple=i686-unknown-unknown -target-feature +xsave -target-feature +xsaves -fno-signed-char -emit-llvm -o - -Werror | FileCheck %s --check-prefix=XSAVES
end_comment

begin_function
name|void
name|test
parameter_list|()
block|{
name|unsigned
name|long
name|long
name|tmp_ULLi
decl_stmt|;
name|void
modifier|*
name|tmp_vp
decl_stmt|;
ifdef|#
directive|ifdef
name|TEST_XSAVE
comment|// XSAVE: [[tmp_vp_1:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 4
comment|// XSAVE: [[tmp_ULLi_1:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
comment|// XSAVE: [[high64_1:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_1]], 32
comment|// XSAVE: [[high32_1:%[0-9a-zA-z]+]] = trunc i64 [[high64_1]] to i32
comment|// XSAVE: [[low32_1:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_1]] to i32
comment|// XSAVE: call void @llvm.x86.xsave(i8* [[tmp_vp_1]], i32 [[high32_1]], i32 [[low32_1]])
operator|(
name|void
operator|)
name|__builtin_ia32_xsave
argument_list|(
name|tmp_vp
argument_list|,
name|tmp_ULLi
argument_list|)
expr_stmt|;
comment|// XSAVE: [[tmp_vp_3:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 4
comment|// XSAVE: [[tmp_ULLi_3:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
comment|// XSAVE: [[high64_3:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_3]], 32
comment|// XSAVE: [[high32_3:%[0-9a-zA-z]+]] = trunc i64 [[high64_3]] to i32
comment|// XSAVE: [[low32_3:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_3]] to i32
comment|// XSAVE: call void @llvm.x86.xrstor(i8* [[tmp_vp_3]], i32 [[high32_3]], i32 [[low32_3]])
operator|(
name|void
operator|)
name|__builtin_ia32_xrstor
argument_list|(
name|tmp_vp
argument_list|,
name|tmp_ULLi
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TEST_XSAVEOPT
comment|// XSAVEOPT: [[tmp_vp_1:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 4
comment|// XSAVEOPT: [[tmp_ULLi_1:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
comment|// XSAVEOPT: [[high64_1:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_1]], 32
comment|// XSAVEOPT: [[high32_1:%[0-9a-zA-z]+]] = trunc i64 [[high64_1]] to i32
comment|// XSAVEOPT: [[low32_1:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_1]] to i32
comment|// XSAVEOPT: call void @llvm.x86.xsaveopt(i8* [[tmp_vp_1]], i32 [[high32_1]], i32 [[low32_1]])
operator|(
name|void
operator|)
name|__builtin_ia32_xsaveopt
argument_list|(
name|tmp_vp
argument_list|,
name|tmp_ULLi
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TEST_XSAVEC
comment|// XSAVEC: [[tmp_vp_1:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 4
comment|// XSAVEC: [[tmp_ULLi_1:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
comment|// XSAVEC: [[high64_1:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_1]], 32
comment|// XSAVEC: [[high32_1:%[0-9a-zA-z]+]] = trunc i64 [[high64_1]] to i32
comment|// XSAVEC: [[low32_1:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_1]] to i32
comment|// XSAVEC: call void @llvm.x86.xsavec(i8* [[tmp_vp_1]], i32 [[high32_1]], i32 [[low32_1]])
operator|(
name|void
operator|)
name|__builtin_ia32_xsavec
argument_list|(
name|tmp_vp
argument_list|,
name|tmp_ULLi
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TEST_XSAVES
comment|// XSAVES: [[tmp_vp_1:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 4
comment|// XSAVES: [[tmp_ULLi_1:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
comment|// XSAVES: [[high64_1:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_1]], 32
comment|// XSAVES: [[high32_1:%[0-9a-zA-z]+]] = trunc i64 [[high64_1]] to i32
comment|// XSAVES: [[low32_1:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_1]] to i32
comment|// XSAVES: call void @llvm.x86.xsaves(i8* [[tmp_vp_1]], i32 [[high32_1]], i32 [[low32_1]])
operator|(
name|void
operator|)
name|__builtin_ia32_xsaves
argument_list|(
name|tmp_vp
argument_list|,
name|tmp_ULLi
argument_list|)
expr_stmt|;
comment|// XSAVES: [[tmp_vp_3:%[0-9a-zA-z]+]] = load i8*, i8** %tmp_vp, align 4
comment|// XSAVES: [[tmp_ULLi_3:%[0-9a-zA-z]+]] = load i64, i64* %tmp_ULLi, align 8
comment|// XSAVES: [[high64_3:%[0-9a-zA-z]+]] = lshr i64 [[tmp_ULLi_3]], 32
comment|// XSAVES: [[high32_3:%[0-9a-zA-z]+]] = trunc i64 [[high64_3]] to i32
comment|// XSAVES: [[low32_3:%[0-9a-zA-z]+]] = trunc i64 [[tmp_ULLi_3]] to i32
comment|// XSAVES: call void @llvm.x86.xrstors(i8* [[tmp_vp_3]], i32 [[high32_3]], i32 [[low32_3]])
operator|(
name|void
operator|)
name|__builtin_ia32_xrstors
argument_list|(
name|tmp_vp
argument_list|,
name|tmp_ULLi
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

