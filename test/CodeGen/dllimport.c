begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows-msvc   -emit-llvm -std=c11 -O0 -o - %s | FileCheck --check-prefix=CHECK --check-prefix=MS %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows-msvc -emit-llvm -std=c11 -O0 -o - %s | FileCheck --check-prefix=CHECK --check-prefix=MS %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows-gnu    -emit-llvm -std=c11 -O0 -o - %s | FileCheck --check-prefix=CHECK --check-prefix=GNU %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows-gnu  -emit-llvm -std=c11 -O0 -o - %s | FileCheck --check-prefix=CHECK --check-prefix=GNU %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows-msvc   -emit-llvm -std=c11 -O1 -o - %s | FileCheck --check-prefix=O1 --check-prefix=MO1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows-gnu    -emit-llvm -std=c11 -O1 -o - %s | FileCheck --check-prefix=O1 --check-prefix=GO1 %s
end_comment

begin_define
define|#
directive|define
name|JOIN2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x##y
end_define

begin_define
define|#
directive|define
name|JOIN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|JOIN2(x, y)
end_define

begin_define
define|#
directive|define
name|USEVAR
parameter_list|(
name|var
parameter_list|)
value|int JOIN(use, __LINE__)() { return var; }
end_define

begin_define
define|#
directive|define
name|USE
parameter_list|(
name|func
parameter_list|)
value|void JOIN(use, __LINE__)() { func(); }
end_define

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Globals
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Import declaration.
end_comment

begin_comment
comment|// CHECK: @ExternGlobalDecl = external dllimport global i32
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|ExternGlobalDecl
decl_stmt|;
end_decl_stmt

begin_macro
name|USEVAR
argument_list|(
argument|ExternGlobalDecl
argument_list|)
end_macro

begin_comment
comment|// dllimport implies a declaration.
end_comment

begin_comment
comment|// CHECK: @GlobalDecl = external dllimport global i32
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|GlobalDecl
decl_stmt|;
end_decl_stmt

begin_macro
name|USEVAR
argument_list|(
argument|GlobalDecl
argument_list|)
end_macro

begin_comment
comment|// Redeclarations
end_comment

begin_comment
comment|// CHECK: @GlobalRedecl1 = external dllimport global i32
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|GlobalRedecl1
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|GlobalRedecl1
decl_stmt|;
end_decl_stmt

begin_macro
name|USEVAR
argument_list|(
argument|GlobalRedecl1
argument_list|)
end_macro

begin_comment
comment|// CHECK: @GlobalRedecl2 = external dllimport global i32
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|GlobalRedecl2
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|GlobalRedecl2
decl_stmt|;
end_decl_stmt

begin_macro
name|USEVAR
argument_list|(
argument|GlobalRedecl2
argument_list|)
end_macro

begin_comment
comment|// NB: MSVC issues a warning and makes GlobalRedecl3 dllexport. We follow GCC
end_comment

begin_comment
comment|// and drop the dllimport with a warning.
end_comment

begin_comment
comment|// CHECK: @GlobalRedecl3 = external global i32
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|GlobalRedecl3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|GlobalRedecl3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// dllimport ignored
end_comment

begin_macro
name|USEVAR
argument_list|(
argument|GlobalRedecl3
argument_list|)
end_macro

begin_comment
comment|// Make sure this works even if the decl has been used before it's defined (PR20792).
end_comment

begin_comment
comment|// CHECK: @GlobalRedecl4 = common global i32
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|GlobalRedecl4
decl_stmt|;
end_decl_stmt

begin_macro
name|USEVAR
argument_list|(
argument|GlobalRedecl4
argument_list|)
end_macro

begin_decl_stmt
name|int
name|GlobalRedecl4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// dllimport ignored
end_comment

begin_comment
comment|// FIXME: dllimport is dropped in the AST; this should be reflected in codegen (PR02803).
end_comment

begin_comment
comment|// CHECK: @GlobalRedecl5 = external dllimport global i32
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|GlobalRedecl5
decl_stmt|;
end_decl_stmt

begin_macro
name|USEVAR
argument_list|(
argument|GlobalRedecl5
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|GlobalRedecl5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// dllimport ignored
end_comment

begin_comment
comment|// Redeclaration in local context.
end_comment

begin_comment
comment|// CHECK: @GlobalRedecl6 = external dllimport global i32
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|GlobalRedecl6
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|functionScope
parameter_list|()
block|{
specifier|extern
name|int
name|GlobalRedecl6
decl_stmt|;
comment|// still dllimport
return|return
name|GlobalRedecl6
return|;
block|}
end_function

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Functions
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Import function declaration.
end_comment

begin_comment
comment|// CHECK-DAG: declare dllimport void @decl()
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|decl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Initialize use_decl with the address of the thunk.
end_comment

begin_comment
comment|// CHECK-DAG: @use_decl = global void ()* @decl
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|use_decl
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
operator|&
name|decl
function_decl|;
end_function_decl

begin_comment
comment|// Import inline function.
end_comment

begin_comment
comment|// MS-DAG: declare dllimport void @inlineFunc()
end_comment

begin_comment
comment|// MO1-DAG: define available_externally dllimport void @inlineFunc()
end_comment

begin_comment
comment|// GNU-DAG: declare void @inlineFunc()
end_comment

begin_comment
comment|// GO1-DAG: define available_externally void @inlineFunc()
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function
specifier|inline
name|void
name|inlineFunc
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_macro
name|USE
argument_list|(
argument|inlineFunc
argument_list|)
end_macro

begin_comment
comment|// inline attributes
end_comment

begin_comment
comment|// MS-DAG: declare dllimport void @noinline()
end_comment

begin_comment
comment|// MO1-DAG: define available_externally dllimport void @noinline()
end_comment

begin_comment
comment|// GNU-DAG: declare void @noinline()
end_comment

begin_comment
comment|// GO1-DAG: define available_externally void @noinline()
end_comment

begin_comment
comment|// CHECK-NOT: @alwaysInline()
end_comment

begin_comment
comment|// O1-NOT: @alwaysInline()
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
specifier|inline
name|void
name|noinline
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_macro
name|__attribute__
argument_list|(
argument|(always_inline)
argument_list|)
end_macro

begin_function
specifier|inline
name|void
name|alwaysInline
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_macro
name|USE
argument_list|(
argument|noinline
argument_list|)
end_macro

begin_macro
name|USE
argument_list|(
argument|alwaysInline
argument_list|)
end_macro

begin_comment
comment|// Redeclarations
end_comment

begin_comment
comment|// CHECK-DAG: declare dllimport void @redecl1()
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|USE
argument_list|(
argument|redecl1
argument_list|)
end_macro

begin_comment
comment|// NB: MSVC issues a warning and makes redecl2/redecl3 dllexport. We follow GCC
end_comment

begin_comment
comment|// and drop the dllimport with a warning.
end_comment

begin_comment
comment|// CHECK-DAG: declare void @redecl2()
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|redecl2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|USE
argument_list|(
argument|redecl2
argument_list|)
end_macro

begin_comment
comment|// CHECK-DAG: define void @redecl3()
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|redecl3
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// dllimport ignored
end_comment

begin_macro
name|USE
argument_list|(
argument|redecl3
argument_list|)
end_macro

begin_comment
comment|// Make sure this works even if the decl is used before it's defined (PR20792).
end_comment

begin_comment
comment|// CHECK-DAG: define void @redecl4()
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|USE
argument_list|(
argument|redecl4
argument_list|)
end_macro

begin_function
name|void
name|redecl4
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// dllimport ignored
end_comment

begin_comment
comment|// FIXME: dllimport is dropped in the AST; this should be reflected in codegen (PR20803).
end_comment

begin_comment
comment|// CHECK-DAG: declare dllimport
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl5
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|USE
argument_list|(
argument|redecl5
argument_list|)
end_macro

begin_function_decl
name|void
name|redecl5
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// dllimport ignored
end_comment

end_unit

