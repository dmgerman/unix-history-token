begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fdeclspec -DCF_BUILDING_CF -DDECL -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-CF-IN-CF-DECL
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fdeclspec -DCF_BUILDING_CF -DDEFN -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-CF-IN-CF-DEFN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fdeclspec -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-CF
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fdeclspec -DEXTERN -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-CF-EXTERN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fdeclspec -DEXTERN_DLLIMPORT -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-CF-EXTERN-DLLIMPORT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fdeclspec -DDLLIMPORT -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-CF-DLLIMPORT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Os -triple thumbv7-windows -fdeclspec -DCF_BUILDING_CF -DDECL -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-CF-IN-CF-DECL
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Os -triple thumbv7-windows -fdeclspec -DCF_BUILDING_CF -DDEFN -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-CF-IN-CF-DEFN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Os -triple thumbv7-windows -fdeclspec -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-CF
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Os -triple thumbv7-windows -fdeclspec -DEXTERN -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-CF-EXTERN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Os -triple thumbv7-windows -fdeclspec -DEXTERN_DLLIMPORT -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-CF-EXTERN-DLLIMPORT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Os -triple thumbv7-windows -fdeclspec -DDLLIMPORT -S -emit-llvm %s -o - | FileCheck %s -check-prefix CHECK-CF-DLLIMPORT
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CF_BUILDING_CF
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DECL
argument_list|)
end_if

begin_extern
extern|extern __declspec(dllexport
end_extern

begin_decl_stmt
unit|)
name|long
name|__CFConstantStringClassReference
index|[]
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|DEFN
argument_list|)
end_elif

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
name|long
name|__CFConstantStringClassReference
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EXTERN
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|long
name|__CFConstantStringClassReference
index|[]
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|EXTERN_DLLIMPORT
argument_list|)
end_elif

begin_extern
extern|extern __declspec(dllimport
end_extern

begin_decl_stmt
unit|)
name|long
name|__CFConstantStringClassReference
index|[]
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|DLLIMPORT
argument_list|)
end_elif

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|long
name|__CFConstantStringClassReference
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|__CFString
modifier|*
name|CFStringRef
typedef|;
end_typedef

begin_decl_stmt
specifier|const
name|CFStringRef
name|string
init|=
operator|(
name|CFStringRef
operator|)
name|__builtin___CFStringMakeConstantString
argument_list|(
literal|"string"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-CF-IN-CF-DECL: @__CFConstantStringClassReference = external dllexport global [0 x i32]
end_comment

begin_comment
comment|// CHECK-CF-IN-CF-DEFN: @__CFConstantStringClassReference = common dllexport global [32 x i32]
end_comment

begin_comment
comment|// CHECK-CF: @__CFConstantStringClassReference = external dllimport global [0 x i32]
end_comment

begin_comment
comment|// CHECK-CF-EXTERN: @__CFConstantStringClassReference = external dllimport global [0 x i32]
end_comment

begin_comment
comment|// CHECK-CF-EXTERN-DLLIMPORT: @__CFConstantStringClassReference = external dllimport global [0 x i32]
end_comment

begin_comment
comment|// CHECK-CF-DLLIMPORT: @__CFConstantStringClassReference = external dllimport global [0 x i32]
end_comment

end_unit

