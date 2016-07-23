begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fblocks -fdeclspec -DBLOCKS_IN_BLOCKS_DECL -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-IN-BLOCKS-DECL
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fblocks -fdeclspec -DBLOCKS_IN_BLOCKS_DEFN -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-IN-BLOCKS-DEFN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fblocks -fdeclspec -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fblocks -fdeclspec -DBLOCKS_NOT_IN_BLOCKS_EXTERN -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-EXTERN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fblocks -fdeclspec -DBLCOKS_NOT_IN_BLOCKS_EXTERN_DLLIMPORT -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-EXTERN-DLLIMPORT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fblocks -fdeclspec -DBLCOKS_NOT_IN_BLOCKS_DLLIMPORT -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-DLLIMPORT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fblocks -fdeclspec -DBLOCKS_IN_BLOCKS_DECL -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-IN-BLOCKS-DECL
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fblocks -fdeclspec -DBLOCKS_IN_BLOCKS_DEFN -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-IN-BLOCKS-DEFN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fblocks -fdeclspec -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fblocks -fdeclspec -DBLOCKS_NOT_IN_BLOCKS_EXTERN -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-EXTERN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fblocks -fdeclspec -DBLCOKS_NOT_IN_BLOCKS_EXTERN_DLLIMPORT -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-EXTERN-DLLIMPORT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fblocks -fdeclspec -DBLCOKS_NOT_IN_BLOCKS_DLLIMPORT -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-DLLIMPORT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows -fblocks -fdeclspec -DBLOCKS_IN_BLOCKS_DECL -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-IN-BLOCKS-DECL
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows -fblocks -fdeclspec -DBLOCKS_IN_BLOCKS_DEFN -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-IN-BLOCKS-DEFN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows -fblocks -fdeclspec -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows -fblocks -fdeclspec -DBLOCKS_NOT_IN_BLOCKS_EXTERN -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-EXTERN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows -fblocks -fdeclspec -DBLCOKS_NOT_IN_BLOCKS_EXTERN_DLLIMPORT -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-EXTERN-DLLIMPORT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows -fblocks -fdeclspec -DBLCOKS_NOT_IN_BLOCKS_DLLIMPORT -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-DLLIMPORT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows -fblocks -fdeclspec -DBLOCKS_IN_BLOCKS_DECL -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-IN-BLOCKS-DECL
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows -fblocks -fdeclspec -DBLOCKS_IN_BLOCKS_DEFN -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-IN-BLOCKS-DEFN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows -fblocks -fdeclspec -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows -fblocks -fdeclspec -DBLOCKS_NOT_IN_BLOCKS_EXTERN -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-EXTERN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows -fblocks -fdeclspec -DBLCOKS_NOT_IN_BLOCKS_EXTERN_DLLIMPORT -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-EXTERN-DLLIMPORT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows -fblocks -fdeclspec -DBLCOKS_NOT_IN_BLOCKS_DLLIMPORT -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-DLLIMPORT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -fblocks -fdeclspec -DBLOCKS_IN_BLOCKS_DECL -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-IN-BLOCKS-DECL
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -fblocks -fdeclspec -DBLOCKS_IN_BLOCKS_DEFN -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-IN-BLOCKS-DEFN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -fblocks -fdeclspec -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -fblocks -fdeclspec -DBLOCKS_NOT_IN_BLOCKS_EXTERN -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-EXTERN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -fblocks -fdeclspec -DBLCOKS_NOT_IN_BLOCKS_EXTERN_DLLIMPORT -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-EXTERN-DLLIMPORT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -fblocks -fdeclspec -DBLCOKS_NOT_IN_BLOCKS_DLLIMPORT -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-DLLIMPORT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -fblocks -fdeclspec -DBLOCKS_IN_BLOCKS_DECL -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-IN-BLOCKS-DECL
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -fblocks -fdeclspec -DBLOCKS_IN_BLOCKS_DEFN -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-IN-BLOCKS-DEFN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -fblocks -fdeclspec -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -fblocks -fdeclspec -DBLOCKS_NOT_IN_BLOCKS_EXTERN -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-EXTERN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -fblocks -fdeclspec -DBLCOKS_NOT_IN_BLOCKS_EXTERN_DLLIMPORT -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-EXTERN-DLLIMPORT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows -fblocks -fdeclspec -DBLCOKS_NOT_IN_BLOCKS_DLLIMPORT -Os -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-BLOCKS-NOT-IN-BLOCKS-DLLIMPORT
end_comment

begin_function_decl
name|void
modifier|*
name|_Block_copy
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BLOCKS_IN_BLOCKS_DECL
argument_list|)
end_if

begin_extern
extern|extern __declspec(dllexport
end_extern

begin_decl_stmt
unit|)
name|long
name|_NSConcreteStackBlock
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BLOCKS_IN_BLOCKS_DEFN
argument_list|)
end_if

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
name|long
name|_NSConcreteStackBlock
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BLOCKS_NOT_IN_BLOCKS_EXTERN
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|long
name|_NSConcreteStackBlock
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BLOCKS_NOT_IN_BLOCKS_EXTERN_DLLIMPORT
argument_list|)
end_if

begin_extern
extern|extern __declspec(dllimport
end_extern

begin_decl_stmt
unit|)
name|long
name|_NSConcreteStackBlock
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BLOCKS_NOT_IN_BLOCKS_DLLIMPORT
argument_list|)
end_if

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|long
name|_NSConcreteStackBlock
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|int
argument_list|(
argument|*g(void)
argument_list|)
end_macro

begin_expr_stmt
operator|(
name|void
operator|)
block|{
specifier|__block
name|int
name|i
block|;
return|return
name|_Block_copy
argument_list|(
lambda|^
block|{
operator|++
name|i
expr_stmt|;
return|return
name|i
return|;
block|}
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// CHECK-BLOCKS-IN-BLOCKS-DECL: @_NSConcreteStackBlock = external dllexport global i8*
end_comment

begin_comment
comment|// CHECK-BLOCKS-IN-BLOCKS-DEFN: @_NSConcreteStackBlock = common dllexport global [5 x i32]
end_comment

begin_comment
comment|// CHECK-BLOCKS-NOT-IN-BLOCKS: @_NSConcreteStackBlock = external dllimport global i8*
end_comment

begin_comment
comment|// CHECK-BLOCKS-NOT-IN-BLOCKS-EXTERN: @_NSConcreteStackBlock = external dllimport global i8*
end_comment

begin_comment
comment|// CHECK-BLOCKS-NOT-IN-BLOCKS-EXTERN-DLLIMPORT: @_NSConcreteStackBlock = external dllimport global i8*
end_comment

begin_comment
comment|// CHECK-BLOCKS-NOT-IN-BLOCKS-DLLIMPORT: @_NSConcreteStackBlock = external dllimport global i8*
end_comment

end_unit

