begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows-msvc   -emit-llvm -std=c11 -O0 -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows-msvc -emit-llvm -std=c11 -O0 -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows-gnu    -emit-llvm -std=c11 -O0 -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-windows-gnu  -emit-llvm -std=c11 -O0 -o - %s | FileCheck %s
end_comment

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
comment|// Declarations are not exported.
end_comment

begin_comment
comment|// CHECK-NOT: @ExternGlobalDecl
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|ExternGlobalDecl
decl_stmt|;
end_decl_stmt

begin_comment
comment|// dllexport implies a definition.
end_comment

begin_comment
comment|// CHECK-DAG: @GlobalDef = common dllexport global i32 0, align 4
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|GlobalDef
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Export definition.
end_comment

begin_comment
comment|// CHECK-DAG: @GlobalInit = dllexport global i32 1, align 4
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|GlobalInit
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Declare, then export definition.
end_comment

begin_comment
comment|// CHECK-DAG: @GlobalDeclInit = dllexport global i32 1, align 4
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|GlobalDeclInit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|GlobalDeclInit
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Redeclarations
end_comment

begin_comment
comment|// CHECK-DAG: @GlobalRedecl1 = common dllexport global i32 0, align 4
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
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
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|GlobalRedecl1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DAG: @GlobalRedecl2 = common dllexport global i32 0, align 4
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|GlobalRedecl2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|GlobalRedecl2
decl_stmt|;
end_decl_stmt

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
comment|// Declarations are not exported.
end_comment

begin_comment
comment|// Export function definition.
end_comment

begin_comment
comment|// CHECK-DAG: define dllexport void @def()
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function
name|void
name|def
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// Export inline function.
end_comment

begin_comment
comment|// CHECK-DAG: define weak_odr dllexport void @inlineFunc()
end_comment

begin_comment
comment|// CHECK-DAG: define weak_odr dllexport void @externInlineFunc()
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
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
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function
specifier|inline
name|void
name|externInlineFunc
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function_decl
specifier|extern
name|void
name|externInlineFunc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Redeclarations
end_comment

begin_comment
comment|// CHECK-DAG: define dllexport void @redecl1()
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
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
argument|dllexport
argument_list|)
end_macro

begin_function
name|void
name|redecl1
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-DAG: define dllexport void @redecl2()
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
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

begin_function
name|void
name|redecl2
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Precedence
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// dllexport takes precedence over the dllimport if both are specified.
end_comment

begin_comment
comment|// CHECK-DAG: @PrecedenceGlobal1A = common dllexport global i32 0, align 4
end_comment

begin_comment
comment|// CHECK-DAG: @PrecedenceGlobal1B = common dllexport global i32 0, align 4
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(dllimport, dllexport)
argument_list|)
end_macro

begin_decl_stmt
name|int
name|PrecedenceGlobal1A
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|PrecedenceGlobal1B
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DAG: @PrecedenceGlobal2A = common dllexport global i32 0, align 4
end_comment

begin_comment
comment|// CHECK-DAG: @PrecedenceGlobal2B = common dllexport global i32 0, align 4
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(dllexport, dllimport)
argument_list|)
end_macro

begin_decl_stmt
name|int
name|PrecedenceGlobal2A
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_macro
name|__declspec
argument_list|(
argument|dllimport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|PrecedenceGlobal2B
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DAG: @PrecedenceGlobalRedecl1 = dllexport global i32 0, align 4
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|PrecedenceGlobalRedecl1
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
name|PrecedenceGlobalRedecl1
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DAG: @PrecedenceGlobalRedecl2 = common dllexport global i32 0, align 4
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
name|PrecedenceGlobalRedecl2
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|PrecedenceGlobalRedecl2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DAG: @PrecedenceGlobalMixed1 = dllexport global i32 1, align 4
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(dllexport)
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|PrecedenceGlobalMixed1
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
name|PrecedenceGlobalMixed1
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DAG: @PrecedenceGlobalMixed2 = common dllexport global i32 0, align 4
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(dllimport)
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|PrecedenceGlobalMixed2
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|PrecedenceGlobalMixed2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DAG: define dllexport void @precedence1A()
end_comment

begin_comment
comment|// CHECK-DAG: define dllexport void @precedence1B()
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|,
name|dllexport
operator|)
argument_list|)
name|precedence1A
argument_list|(
name|void
argument_list|)
block|{}
end_decl_stmt

begin_function
name|void
name|__declspec
parameter_list|(
name|dllimport
parameter_list|)
function|__declspec
parameter_list|(
name|dllexport
parameter_list|)
function|precedence1B
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-DAG: define dllexport void @precedence2A()
end_comment

begin_comment
comment|// CHECK-DAG: define dllexport void @precedence2B()
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllexport
operator|,
name|dllimport
operator|)
argument_list|)
name|precedence2A
argument_list|(
name|void
argument_list|)
block|{}
end_decl_stmt

begin_function
name|void
name|__declspec
parameter_list|(
name|dllexport
parameter_list|)
function|__declspec
parameter_list|(
name|dllimport
parameter_list|)
function|precedence2B
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-DAG: define dllexport void @precedenceRedecl1()
end_comment

begin_function_decl
name|void
name|__declspec
parameter_list|(
name|dllimport
parameter_list|)
function_decl|precedenceRedecl1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|__declspec
parameter_list|(
name|dllexport
parameter_list|)
function|precedenceRedecl1
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-DAG: define dllexport void @precedenceRedecl2()
end_comment

begin_function_decl
name|void
name|__declspec
parameter_list|(
name|dllexport
parameter_list|)
function_decl|precedenceRedecl2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|__declspec
parameter_list|(
name|dllimport
parameter_list|)
function|precedenceRedecl2
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

end_unit

