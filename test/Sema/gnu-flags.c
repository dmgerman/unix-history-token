begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DNONE -Wno-gnu
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DALL -Wgnu
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DALL -Wno-gnu \
end_comment

begin_comment
comment|// RUN:   -Wgnu-alignof-expression -Wgnu-case-range -Wgnu-complex-integer -Wgnu-conditional-omitted-operand \
end_comment

begin_comment
comment|// RUN:   -Wgnu-empty-initializer -Wgnu-label-as-value -Wgnu-statement-expression \
end_comment

begin_comment
comment|// RUN:   -Wgnu-compound-literal-initializer -Wgnu-flexible-array-initializer \
end_comment

begin_comment
comment|// RUN:   -Wgnu-redeclared-enum  -Wgnu-folding-constant -Wgnu-empty-struct \
end_comment

begin_comment
comment|// RUN:   -Wgnu-union-cast -Wgnu-variable-sized-type-not-at-end
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DNONE -Wgnu \
end_comment

begin_comment
comment|// RUN:   -Wno-gnu-alignof-expression -Wno-gnu-case-range -Wno-gnu-complex-integer -Wno-gnu-conditional-omitted-operand \
end_comment

begin_comment
comment|// RUN:   -Wno-gnu-empty-initializer -Wno-gnu-label-as-value -Wno-gnu-statement-expression \
end_comment

begin_comment
comment|// RUN:   -Wno-gnu-compound-literal-initializer -Wno-gnu-flexible-array-initializer \
end_comment

begin_comment
comment|// RUN:   -Wno-gnu-redeclared-enum -Wno-gnu-folding-constant -Wno-gnu-empty-struct \
end_comment

begin_comment
comment|// RUN:   -Wno-gnu-union-cast -Wno-gnu-variable-sized-type-not-at-end
end_comment

begin_comment
comment|// Additional disabled tests:
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DALIGNOF -Wno-gnu -Wgnu-alignof-expression
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DCASERANGE -Wno-gnu -Wgnu-case-range
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DCOMPLEXINT -Wno-gnu -Wgnu-complex-integer
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DOMITTEDOPERAND -Wno-gnu -Wgnu-conditional-omitted-operand
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DEMPTYINIT -Wno-gnu -Wgnu-empty-initializer
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DLABELVALUE -Wno-gnu -Wgnu-label-as-value
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DSTATEMENTEXP -Wno-gnu -Wgnu-statement-expression
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DCOMPOUNDLITERALINITIALIZER -Wno-gnu -Wgnu-compound-literal-initializer
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DFLEXIBLEARRAYINITIALIZER -Wno-gnu -Wgnu-flexible-array-initializer
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DREDECLAREDENUM -Wno-gnu -Wgnu-redeclared-enum
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DUNIONCAST -Wno-gnu -Wgnu-union-cast
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DVARIABLESIZEDTYPENOTATEND -Wno-gnu -Wgnu-variable-sized-type-not-at-end
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DFOLDINGCONSTANT -Wno-gnu -Wgnu-folding-constant
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DEMPTYSTRUCT -Wno-gnu -Wgnu-empty-struct
end_comment

begin_if
if|#
directive|if
name|NONE
end_if

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ALL
operator|||
name|ALIGNOF
end_if

begin_comment
comment|// expected-warning@+4 {{'_Alignof' applied to an expression is a GNU extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
name|align
decl_stmt|;
end_decl_stmt

begin_assert
assert|_Static_assert
argument_list|(
alignof|_Alignof
argument_list|(
name|align
argument_list|)
operator|>
literal|0
argument_list|,
literal|"align's alignment is wrong"
argument_list|)
assert|;
end_assert

begin_if
if|#
directive|if
name|ALL
operator|||
name|CASERANGE
end_if

begin_comment
comment|// expected-warning@+5 {{use of GNU case range extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|caserange
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|42
operator|...
literal|44
case|:
empty_stmt|;
block|}
block|}
end_function

begin_if
if|#
directive|if
name|ALL
operator|||
name|COMPLEXINT
end_if

begin_comment
comment|// expected-warning@+3 {{complex integer types are a GNU extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|_Complex
name|short
name|int
name|complexint
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|ALL
operator|||
name|OMITTEDOPERAND
end_if

begin_comment
comment|// expected-warning@+3 {{use of GNU ?: conditional expression extension, omitting middle operand}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|omittedoperand
init|=
operator|(
specifier|const
name|char
operator|*
operator|)
literal|0
condition|?
else|:
literal|"Null"
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|ALL
operator|||
name|EMPTYINIT
end_if

begin_comment
comment|// expected-warning@+3 {{use of GNU empty initializer extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
block|{
name|int
name|x
decl_stmt|;
block|}
name|emptyinit
init|=
block|{}
struct|;
end_struct

begin_if
if|#
directive|if
name|ALL
operator|||
name|LABELVALUE
end_if

begin_comment
comment|// expected-warning@+6 {{use of GNU address-of-label extension}}
end_comment

begin_comment
comment|// expected-warning@+7 {{use of GNU indirect-goto extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|labelvalue
parameter_list|()
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
name|ptr
operator|=
operator|&&
name|foo
expr_stmt|;
name|foo
label|:
goto|goto *
name|ptr
goto|;
block|}
end_function

begin_if
if|#
directive|if
name|ALL
operator|||
name|STATEMENTEXP
end_if

begin_comment
comment|// expected-warning@+5 {{use of GNU statement expression extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|statementexp
parameter_list|()
block|{
name|int
name|a
init|=
operator|(
block|{
literal|1
block|; }
operator|)
decl_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|ALL
operator|||
name|COMPOUNDLITERALINITIALIZER
end_if

begin_comment
comment|// expected-warning@+4 {{initialization of an array of type 'int [5]' from a compound literal of type 'int [5]' is a GNU extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|int5
index|[
literal|5
index|]
typedef|;
end_typedef

begin_decl_stmt
name|int
name|cli
index|[
literal|5
index|]
init|=
operator|(
name|int
index|[]
operator|)
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|ALL
operator|||
name|FLEXIBLEARRAYINITIALIZER
end_if

begin_comment
comment|// expected-note@+6 {{initialized flexible array member 'y' is here}}
end_comment

begin_comment
comment|// expected-warning@+6 {{flexible array initialization is a GNU extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|fai
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
index|[]
decl_stmt|;
block|}
name|fai
init|=
block|{
literal|1
block|,
block|{
literal|2
block|,
literal|3
block|,
literal|4
block|}
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|ALL
operator|||
name|FOLDINGCONSTANT
end_if

begin_comment
comment|// expected-warning@+5 {{expression is not an integer constant expression; folding it to a constant is a GNU extension}}
end_comment

begin_comment
comment|// expected-warning@+7 {{variable length array folded to constant array as an extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
block|{
name|fic
init|=
operator|(
name|int
operator|)
operator|(
literal|0.75
operator|*
literal|1000
operator|*
literal|1000
operator|)
block|}
enum|;
end_enum

begin_decl_stmt
specifier|static
specifier|const
name|int
name|size
init|=
literal|100
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|data
index|[
name|size
index|]
decl_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|ALL
operator|||
name|REDECLAREDENUM
end_if

begin_comment
comment|// expected-note@+4 {{previous definition is here}}
end_comment

begin_comment
comment|// expected-warning@+8 {{redeclaration of already-defined enum 'RE' is a GNU extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|RE
block|{
name|Val1
block|,
name|Val2
block|}
enum|;
end_enum

begin_enum_decl
enum_decl|enum
name|RE
enum_decl|;
end_enum_decl

begin_if
if|#
directive|if
name|ALL
operator|||
name|UNIONCAST
end_if

begin_comment
comment|// expected-warning@+4 {{cast to union type is a GNU extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_union
union|union
name|uc
block|{
name|int
name|i
decl_stmt|;
name|unsigned
label|:
literal|3
expr_stmt|;
block|}
union|;
end_union

begin_decl_stmt
name|union
name|uc
name|w
init|=
operator|(
expr|union
name|uc
operator|)
literal|2
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|ALL
operator|||
name|VARIABLESIZEDTYPENOTATEND
end_if

begin_comment
comment|// expected-warning@+8 {{field 'hdr' with variable sized type 'struct vst' not at the end of a struct or class is a GNU extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|vst
block|{
name|short
name|tag_type
decl_stmt|;
name|char
name|tag_data
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vstnae
block|{
name|struct
name|vst
name|hdr
decl_stmt|;
name|char
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|ALL
operator|||
name|EMPTYSTRUCT
end_if

begin_comment
comment|// expected-warning@+4 {{empty struct is a GNU extension}}
end_comment

begin_comment
comment|// expected-warning@+4 {{struct without named members is a GNU extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct
specifier|const
struct|struct
block|{}
name|es
struct|;
end_struct

begin_struct
struct|struct
block|{
name|int
label|:
literal|5
expr_stmt|;
block|}
name|swnm
struct|;
end_struct

end_unit

