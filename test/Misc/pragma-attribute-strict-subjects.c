begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wno-pragma-clang-attribute -verify %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -ast-dump -ast-dump-filter test %s | FileCheck %s
end_comment

begin_comment
comment|// Check for contradictions in rules for attribute without a strict subject set:
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|annotate
name|(
literal|"subRuleContradictions"
name|)
name|)
name|)
name|,
name|apply_to
name|=
name|any
name|(
name|variable
name|,
name|variable
name|(
name|is_parameter
name|)
name|,
name|function
name|(
name|is_member
name|)
name|,
name|variable
name|(
name|is_global
name|)
name|)
name|)
end_pragma

begin_comment
comment|// expected-error@-1 {{redundant attribute subject matcher sub-rule 'variable(is_parameter)'; 'variable' already matches those declarations}}
end_comment

begin_comment
comment|// expected-error@-2 {{redundant attribute subject matcher sub-rule 'variable(is_global)'; 'variable' already matches those declarations}}
end_comment

begin_comment
comment|// Ensure that we've recovered from the error:
end_comment

begin_decl_stmt
name|int
name|testRecoverSubRuleContradiction
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: VarDecl{{.*}} testRecoverSubRuleContradiction
end_comment

begin_comment
comment|// CHECK-NEXT: IntegerLiteral
end_comment

begin_comment
comment|// CHECK-NEXT: AnnotateAttr{{.*}} "subRuleContradictions"
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|annotate
name|(
literal|"negatedSubRuleContradictions2"
name|)
name|)
name|)
name|,
name|apply_to
name|=
name|any
name|(
name|variable
name|(
name|unless
name|(
name|is_parameter
name|)
name|)
name|,
name|variable
name|(
name|is_thread_local
name|)
name|,
name|function
name|,
name|variable
name|(
name|is_global
name|)
name|)
name|)
end_pragma

begin_comment
comment|// expected-error@-1 {{negated attribute subject matcher sub-rule 'variable(unless(is_parameter))' contradicts sub-rule 'variable(is_global)'}}
end_comment

begin_comment
comment|// We have just one error, don't error on 'variable(is_global)'
end_comment

begin_comment
comment|// Ensure that we've recovered from the error:
end_comment

begin_decl_stmt
name|int
name|testRecoverNegatedContradiction
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: VarDecl{{.*}} testRecoverNegatedContradiction
end_comment

begin_comment
comment|// CHECK-NEXT: IntegerLiteral
end_comment

begin_comment
comment|// CHECK-NEXT: AnnotateAttr{{.*}} "negatedSubRuleContradictions2"
end_comment

begin_function_decl
name|void
name|testRecoverNegatedContradictionFunc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: FunctionDecl{{.*}} testRecoverNegatedContradictionFunc
end_comment

begin_comment
comment|// CHECK-NEXT: AnnotateAttr{{.*}} "negatedSubRuleContradictions2"
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_comment
comment|// Verify the strict subject set verification.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|abi_tag
name|(
literal|"a"
name|)
name|)
name|)
name|,
name|apply_to
name|=
name|any
name|(
name|function
name|)
name|)
end_pragma

begin_decl_stmt
name|int
name|testRecoverStrictnessVar
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: VarDecl{{.*}} testRecoverStrictnessVar
end_comment

begin_comment
comment|// CHECK-NEXT: IntegerLiteral
end_comment

begin_comment
comment|// CHECK-NOT: AbiTagAttr
end_comment

begin_function_decl
name|void
name|testRecoverStrictnessFunc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: FunctionDecl{{.*}} testRecoverStrictnessFunc
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_struct
struct|struct
name|testRecoverStrictnessStruct
block|{ }
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: RecordDecl{{.*}} testRecoverStrictnessStruct
end_comment

begin_comment
comment|// CHECK-NOT: AbiTagAttr
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|abi_tag
name|(
literal|"a"
name|)
name|)
name|)
name|,
name|apply_to
name|=
name|any
name|(
name|function
name|,
name|record
name|(
name|unless
name|(
name|is_union
name|)
name|)
name|,
name|variable
name|,
name|enum
name|)
name|)
end_pragma

begin_comment
comment|// expected-error@-1 {{attribute 'abi_tag' can't be applied to 'enum'}}
end_comment

begin_decl_stmt
name|int
name|testRecoverExtraVar
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: VarDecl{{.*}} testRecoverExtraVar
end_comment

begin_comment
comment|// CHECK-NEXT: IntegerLiteral
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_function_decl
name|void
name|testRecoverExtraFunc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: FunctionDecl{{.*}} testRecoverExtraFunc
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_struct
struct|struct
name|testRecoverExtraStruct
block|{ }
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: RecordDecl{{.*}} testRecoverExtraStruct
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_enum
enum|enum
name|testNoEnumAbiTag
block|{
name|CaseCase
block|}
enum|;
end_enum

begin_comment
comment|// CHECK-LABEL: EnumDecl{{.*}} testNoEnumAbiTag
end_comment

begin_comment
comment|// CHECK-NO: AbiTagAttr
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_comment
comment|// Verify the non-strict subject set verification.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|abi_tag
name|(
literal|"a"
name|)
name|)
name|)
name|,
name|apply_to
name|=
name|any
name|(
name|function
name|)
name|)
end_pragma

begin_decl_stmt
name|int
name|testSubset1Var
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: VarDecl{{.*}} testSubset1Var
end_comment

begin_comment
comment|// CHECK-NOT: AbiTagAttr
end_comment

begin_function_decl
name|void
name|testSubset1Func
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: FunctionDecl{{.*}} testSubset1Func
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_struct
struct|struct
name|testSubset1Struct
block|{ }
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: RecordDecl{{.*}} testSubset1Struct
end_comment

begin_comment
comment|// CHECK-NOT: AbiTagAttr
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|abi_tag
name|(
literal|"a"
name|)
name|)
name|)
name|,
name|apply_to
name|=
name|variable
name|)
end_pragma

begin_decl_stmt
name|int
name|testSubset2Var
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: VarDecl{{.*}} testSubset2Var
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_function_decl
name|void
name|testSubset2Func
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: FunctionDecl{{.*}} testSubset2Func
end_comment

begin_comment
comment|// CHECK-NOT: AbiTagAttr
end_comment

begin_struct
struct|struct
name|testSubset2Struct
block|{ }
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: RecordDecl{{.*}} testSubset2Struct
end_comment

begin_comment
comment|// CHECK-NOT: AbiTagAttr
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|abi_tag
name|(
literal|"a"
name|)
name|)
name|)
name|,
name|apply_to
name|=
name|any
name|(
name|record
name|(
name|unless
name|(
name|is_union
name|)
name|)
name|)
name|)
end_pragma

begin_decl_stmt
name|int
name|testSubset3Var
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: VarDecl{{.*}} testSubset3Var
end_comment

begin_comment
comment|// CHECK-NOT: AbiTagAttr
end_comment

begin_function_decl
name|void
name|testSubset3Func
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: FunctionDecl{{.*}} testSubset3Func
end_comment

begin_comment
comment|// CHECK-NOT: AbiTagAttr
end_comment

begin_struct
struct|struct
name|testSubset3Struct
block|{ }
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: RecordDecl{{.*}} testSubset3Struct
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|abi_tag
name|(
literal|"a"
name|)
name|)
name|)
name|,
name|apply_to
name|=
name|any
name|(
name|function
name|,
name|variable
name|)
name|)
end_pragma

begin_decl_stmt
name|int
name|testSubset4Var
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: VarDecl{{.*}} testSubset4Var
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_function_decl
name|void
name|testSubset4Func
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: FunctionDecl{{.*}} testSubset4Func
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_struct
struct|struct
name|testSubset4Struct
block|{ }
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: RecordDecl{{.*}} testSubset4Struct
end_comment

begin_comment
comment|// CHECK-NOT: AbiTagAttr
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|abi_tag
name|(
literal|"a"
name|)
name|)
name|)
name|,
name|apply_to
name|=
name|any
name|(
name|variable
name|,
name|record
name|(
name|unless
name|(
name|is_union
name|)
name|)
name|)
name|)
end_pragma

begin_decl_stmt
name|int
name|testSubset5Var
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: VarDecl{{.*}} testSubset5Var
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_function_decl
name|void
name|testSubset5Func
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: FunctionDecl{{.*}} testSubset5Func
end_comment

begin_comment
comment|// CHECK-NOT: AbiTagAttr
end_comment

begin_struct
struct|struct
name|testSubset5Struct
block|{ }
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: RecordDecl{{.*}} testSubset5Struct
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|abi_tag
name|(
literal|"a"
name|)
name|)
name|)
name|,
name|apply_to
name|=
name|any
name|(
name|record
name|(
name|unless
name|(
name|is_union
name|)
name|)
name|,
name|function
name|)
name|)
end_pragma

begin_decl_stmt
name|int
name|testSubset6Var
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: VarDecl{{.*}} testSubset6Var
end_comment

begin_comment
comment|// CHECK-NOT: AbiTagAttr
end_comment

begin_function_decl
name|void
name|testSubset6Func
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: FunctionDecl{{.*}} testSubset6Func
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_struct
struct|struct
name|testSubset6Struct
block|{ }
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: RecordDecl{{.*}} testSubset6Struct
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|abi_tag
name|(
literal|"a"
name|)
name|)
name|)
name|,
name|apply_to
name|=
name|any
name|(
name|record
name|(
name|unless
name|(
name|is_union
name|)
name|)
name|,
name|function
name|,
name|variable
name|)
name|)
end_pragma

begin_decl_stmt
name|int
name|testSubset7Var
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: VarDecl{{.*}} testSubset7Var
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_function_decl
name|void
name|testSubset7Func
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: FunctionDecl{{.*}} testSubset7Func
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_struct
struct|struct
name|testSubset7Struct
block|{ }
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: RecordDecl{{.*}} testSubset7Struct
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|abi_tag
name|(
literal|"a"
name|)
name|)
name|)
name|,
name|apply_to
name|=
name|any
name|(
name|record
name|(
name|unless
name|(
name|is_union
name|)
name|)
name|,
name|function
name|,
name|variable
name|,
name|enum
name|,
name|enum_constant
name|)
name|)
end_pragma

begin_comment
comment|// expected-error@-1 {{attribute 'abi_tag' can't be applied to 'enum_constant', and 'enum'}}
end_comment

begin_decl_stmt
name|int
name|testSubsetRecoverVar
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: VarDecl{{.*}} testSubsetRecoverVar
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_function_decl
name|void
name|testSubsetRecoverFunc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: FunctionDecl{{.*}} testSubsetRecoverFunc
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_struct
struct|struct
name|testSubsetRecoverStruct
block|{ }
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: RecordDecl{{.*}} testSubsetRecoverStruct
end_comment

begin_comment
comment|// CHECK-NEXT: AbiTagAttr
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|abi_tag
name|(
literal|"a"
name|)
name|)
name|)
name|,
name|apply_to
name|=
name|enum
name|)
end_pragma

begin_comment
comment|// expected-error@-1 {{attribute 'abi_tag' can't be applied to 'enum'}}
end_comment

begin_decl_stmt
name|int
name|testSubsetNoVar
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: VarDecl{{.*}} testSubsetNoVar
end_comment

begin_comment
comment|// CHECK-NOT: AbiTagAttr
end_comment

begin_function_decl
name|void
name|testSubsetNoFunc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: FunctionDecl{{.*}} testSubsetNoFunc
end_comment

begin_comment
comment|// CHECK-NOT: AbiTagAttr
end_comment

begin_struct
struct|struct
name|testSubsetNoStruct
block|{ }
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: RecordDecl{{.*}} testSubsetNoStruct
end_comment

begin_comment
comment|// CHECK-NOT: AbiTagAttr
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

end_unit

