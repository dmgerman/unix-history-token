begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
name|int
name|T
typedef|;
end_typedef

begin_struct
struct|struct
name|X
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|T
modifier|*
name|t_ptr
init|=
operator|(
name|T
operator|*
operator|)
name|ptr
decl_stmt|;
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|T
argument_list|)
expr_stmt|;
comment|/* A comment */
name|struct
name|X
name|x
init|=
operator|(
expr|struct
name|X
operator|)
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
name|void
modifier|*
name|xx
init|=
name|ptr
condition|?
else|:
operator|&
name|x
decl_stmt|;
specifier|const
name|char
modifier|*
name|hello
init|=
literal|"Hello"
decl_stmt|;
block|}
end_function

begin_enum
enum|enum
name|Color
block|{
name|Red
block|,
name|Green
block|,
name|Blue
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|int
name|Int
typedef|;
end_typedef

begin_function
name|enum
name|Color
name|g
parameter_list|(
name|int
name|i
parameter_list|,
modifier|...
parameter_list|)
block|{
name|__builtin_va_list
name|va
decl_stmt|;
operator|(
name|void
operator|)
name|__builtin_va_arg
argument_list|(
name|va
argument_list|,
name|Int
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__builtin_types_compatible_p
argument_list|(
name|Int
argument_list|,
name|Int
argument_list|)
expr_stmt|;
name|struct
name|X
name|x
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
do|do
block|{
name|x
operator|.
name|a
operator|++
expr_stmt|;
block|}
do|while
condition|(
name|x
operator|.
name|a
operator|<
literal|10
condition|)
do|;
name|enum
name|Color
name|c
decl_stmt|;
switch|switch
condition|(
name|c
condition|)
block|{
case|case
name|Red
case|:
return|return
name|Green
return|;
case|case
name|Green
case|:
return|return
name|Blue
return|;
case|case
name|Blue
case|:
return|return
name|Red
return|;
block|}
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(unavailable)
argument_list|)
end_macro

begin_decl_stmt
name|Int
name|__attribute__
argument_list|(
operator|(
name|unavailable
operator|)
argument_list|)
name|test
argument_list|()
name|__attribute__
argument_list|(
operator|(
name|unavailable
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HEADER
parameter_list|()
define|\
value|int x; \     int y; \     int z
end_define

begin_define
define|#
directive|define
name|TYPE_INST
parameter_list|(
name|name
parameter_list|,
modifier|...
parameter_list|)
define|\
value|static const struct { \         HEADER(); \     } name = { \         __VA_ARGS__ \     }
end_define

begin_function_decl
name|void
name|func1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|TYPE_INST
argument_list|(
name|Foo
argument_list|,
operator|.
name|x
operator|=
literal|0
argument_list|,
operator|.
name|y
operator|=
literal|1
argument_list|,
operator|.
name|z
operator|=
literal|2
argument_list|, )
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|func2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|int
name|field
range|:
literal|16
decl_stmt|;
block|}
struct|;
block|}
name|r_t
typedef|;
end_typedef

begin_function
name|void
name|test
parameter_list|()
block|{
name|r_t
name|reg
decl_stmt|;
name|reg
operator|.
name|field
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|// RUN: c-index-test -test-annotate-tokens=%s:4:1:37:1 %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: Identifier: "T" [4:3 - 4:4] TypeRef=T:1:13
end_comment

begin_comment
comment|// CHECK: Punctuation: "*" [4:4 - 4:5] VarDecl=t_ptr:4:6 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "t_ptr" [4:6 - 4:11] VarDecl=t_ptr:4:6 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "=" [4:12 - 4:13] VarDecl=t_ptr:4:6 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [4:14 - 4:15] CStyleCastExpr=
end_comment

begin_comment
comment|// CHECK: Identifier: "T" [4:15 - 4:16] TypeRef=T:1:13
end_comment

begin_comment
comment|// CHECK: Identifier: "ptr" [4:19 - 4:22] DeclRefExpr=ptr:3:14
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [4:22 - 4:23] DeclStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [5:3 - 5:4] CStyleCastExpr=
end_comment

begin_comment
comment|// CHECK: Keyword: "void" [5:4 - 5:8] CStyleCastExpr=
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [5:8 - 5:9] CStyleCastExpr=
end_comment

begin_comment
comment|// CHECK: Keyword: "sizeof" [5:9 - 5:15] UnaryExpr=
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [5:15 - 5:16] UnaryExpr=
end_comment

begin_comment
comment|// CHECK: Identifier: "T" [5:16 - 5:17] TypeRef=T:1:13
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [5:17 - 5:18] UnaryExpr=
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [5:18 - 5:19] CompoundStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "struct" [7:3 - 7:9] VarDecl=x:7:12 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "X" [7:10 - 7:11] TypeRef=struct X:2:8
end_comment

begin_comment
comment|// CHECK: Identifier: "x" [7:12 - 7:13] VarDecl=x:7:12 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "=" [7:14 - 7:15] VarDecl=x:7:12 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [7:16 - 7:17] CompoundLiteralExpr=
end_comment

begin_comment
comment|// CHECK: Keyword: "struct" [7:17 - 7:23] CompoundLiteralExpr=
end_comment

begin_comment
comment|// CHECK: Identifier: "X" [7:24 - 7:25] TypeRef=struct X:2:8
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [7:25 - 7:26] CompoundLiteralExpr=
end_comment

begin_comment
comment|// CHECK: Punctuation: "{" [7:26 - 7:27] InitListExpr=
end_comment

begin_comment
comment|// CHECK: Literal: "1" [7:27 - 7:28] IntegerLiteral=
end_comment

begin_comment
comment|// CHECK: Punctuation: "," [7:28 - 7:29] InitListExpr=
end_comment

begin_comment
comment|// CHECK: Literal: "2" [7:30 - 7:31] IntegerLiteral=
end_comment

begin_comment
comment|// CHECK: Punctuation: "}" [7:31 - 7:32] InitListExpr=
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [7:32 - 7:33] DeclStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "void" [8:3 - 8:7] VarDecl=xx:8:9 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "*" [8:8 - 8:9] VarDecl=xx:8:9 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "xx" [8:9 - 8:11] VarDecl=xx:8:9 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "=" [8:12 - 8:13] VarDecl=xx:8:9 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "ptr" [8:14 - 8:17] DeclRefExpr=ptr:3:14
end_comment

begin_comment
comment|// CHECK: Punctuation: "?" [8:18 - 8:19] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK: Punctuation: ":" [8:20 - 8:21] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK: Punctuation: "&" [8:22 - 8:23] UnaryOperator=
end_comment

begin_comment
comment|// CHECK: Identifier: "x" [8:23 - 8:24] DeclRefExpr=x:7:12
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [8:24 - 8:25] DeclStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "const" [9:3 - 9:8] VarDecl=hello:9:16 (Definition)
end_comment

begin_comment
comment|// CHECK: Keyword: "char" [9:9 - 9:13] VarDecl=hello:9:16 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "*" [9:14 - 9:15] VarDecl=hello:9:16 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "hello" [9:16 - 9:21] VarDecl=hello:9:16 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "=" [9:22 - 9:23] VarDecl=hello:9:16 (Definition)
end_comment

begin_comment
comment|// CHECK: Literal: ""Hello"" [9:24 - 9:31] StringLiteral=
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [9:31 - 9:32] DeclStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: "}" [10:1 - 10:2] CompoundStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "__builtin_va_arg" [15:9 - 15:25] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK: Identifier: "Int" [15:30 - 15:33] TypeRef=Int:12:13
end_comment

begin_comment
comment|// CHECK: Keyword: "__builtin_types_compatible_p" [16:9 - 16:37] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK: Identifier: "Int" [16:38 - 16:41] TypeRef=Int:12:13
end_comment

begin_comment
comment|// CHECK: Punctuation: "," [16:41 - 16:42] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK: Identifier: "Int" [16:43 - 16:46] TypeRef=Int:12:13
end_comment

begin_comment
comment|// CHECK: Keyword: "struct" [18:3 - 18:9] VarDecl=x:18:12 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "X" [18:10 - 18:11] TypeRef=struct X:2:8
end_comment

begin_comment
comment|// CHECK: Identifier: "x" [18:12 - 18:13] VarDecl=x:18:12 (Definition)
end_comment

begin_comment
comment|// CHECK: Keyword: "do" [19:3 - 19:5] DoStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "x" [20:5 - 20:6] DeclRefExpr=x:18:12
end_comment

begin_comment
comment|// CHECK: Punctuation: "." [20:6 - 20:7] MemberRefExpr=a:2:16
end_comment

begin_comment
comment|// CHECK: Identifier: "a" [20:7 - 20:8] MemberRefExpr=a:2:16
end_comment

begin_comment
comment|// CHECK: Punctuation: "++" [20:8 - 20:10] UnaryOperator=
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [20:10 - 20:11] CompoundStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: "}" [21:3 - 21:4] CompoundStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "while" [21:5 - 21:10] DoStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [21:11 - 21:12] DoStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "x" [21:12 - 21:13] DeclRefExpr=x:18:12
end_comment

begin_comment
comment|// CHECK: Punctuation: "." [21:13 - 21:14] MemberRefExpr=a:2:16
end_comment

begin_comment
comment|// CHECK: Identifier: "a" [21:14 - 21:15] MemberRefExpr=a:2:16
end_comment

begin_comment
comment|// CHECK: Keyword: "enum" [23:3 - 23:7] VarDecl=c:23:14 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "Color" [23:8 - 23:13] TypeRef=enum Color:11:6
end_comment

begin_comment
comment|// CHECK: Identifier: "c" [23:14 - 23:15] VarDecl=c:23:14 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [23:15 - 23:16] DeclStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "switch" [24:3 - 24:9] SwitchStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [24:10 - 24:11] SwitchStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "c" [24:11 - 24:12] DeclRefExpr=c:23:14
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [24:12 - 24:13] SwitchStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: "{" [24:14 - 24:15] CompoundStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "case" [25:3 - 25:7] CaseStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "Red" [25:8 - 25:11] DeclRefExpr=Red:11:14
end_comment

begin_comment
comment|// CHECK: Punctuation: ":" [25:11 - 25:12] CaseStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "return" [26:5 - 26:11] ReturnStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "Green" [26:12 - 26:17] DeclRefExpr=Green:11:19
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [26:17 - 26:18] CompoundStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "case" [28:3 - 28:7] CaseStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "Green" [28:8 - 28:13] DeclRefExpr=Green:11:19
end_comment

begin_comment
comment|// CHECK: Punctuation: ":" [28:13 - 28:14] CaseStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "return" [29:5 - 29:11] ReturnStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "Blue" [29:12 - 29:16] DeclRefExpr=Blue:11:26
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [29:16 - 29:17] CompoundStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "case" [31:3 - 31:7] CaseStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "Blue" [31:8 - 31:12] DeclRefExpr=Blue:11:26
end_comment

begin_comment
comment|// CHECK: Punctuation: ":" [31:12 - 31:13] CaseStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "return" [32:5 - 32:11] ReturnStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "Red" [32:12 - 32:15] DeclRefExpr=Red:11:14
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [32:15 - 32:16] CompoundStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "__attribute__" [36:1 - 36:14] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [36:14 - 36:15] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [36:15 - 36:16] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Identifier: "unavailable" [36:16 - 36:27] UnexposedAttr=
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [36:27 - 36:28] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [36:28 - 36:29] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Identifier: "Int" [36:30 - 36:33] TypeRef=Int:12:13
end_comment

begin_comment
comment|// CHECK: Keyword: "__attribute__" [36:34 - 36:47] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [36:47 - 36:48] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [36:48 - 36:49] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Identifier: "unavailable" [36:49 - 36:60] UnexposedAttr=
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [36:60 - 36:61] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [36:61 - 36:62] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Identifier: "test" [36:63 - 36:67] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [36:67 - 36:68] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [36:68 - 36:69] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Keyword: "__attribute__" [36:70 - 36:83] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [36:83 - 36:84] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [36:84 - 36:85] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Identifier: "unavailable" [36:85 - 36:96] UnexposedAttr=
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [36:96 - 36:97] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [36:97 - 36:98] FunctionDecl=test:36:63 (unavailable)  (always unavailable: "")
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [36:98 - 36:99]
end_comment

begin_comment
comment|// RUN: c-index-test -test-annotate-tokens=%s:4:1:165:32 %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: c-index-test -test-annotate-tokens=%s:4:1:165:38 %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: c-index-test -test-annotate-tokens=%s:50:1:55:1 %s | FileCheck %s -check-prefix=CHECK-RANGE1
end_comment

begin_comment
comment|// CHECK-RANGE1: Keyword: "void" [50:1 - 50:5] FunctionDecl=func1:50:6
end_comment

begin_comment
comment|// CHECK-RANGE1: Identifier: "func1" [50:6 - 50:11] FunctionDecl=func1:50:6
end_comment

begin_comment
comment|// CHECK-RANGE1: Punctuation: "(" [50:11 - 50:12] FunctionDecl=func1:50:6
end_comment

begin_comment
comment|// CHECK-RANGE1: Keyword: "void" [50:12 - 50:16] FunctionDecl=func1:50:6
end_comment

begin_comment
comment|// CHECK-RANGE1: Punctuation: ")" [50:16 - 50:17] FunctionDecl=func1:50:6
end_comment

begin_comment
comment|// CHECK-RANGE1: Punctuation: ";" [50:17 - 50:18]
end_comment

begin_comment
comment|// CHECK-RANGE1: Identifier: "TYPE_INST" [52:1 - 52:10] macro expansion=TYPE_INST:43:9
end_comment

begin_comment
comment|// CHECK-RANGE1: Punctuation: "(" [52:10 - 52:11]
end_comment

begin_comment
comment|// CHECK-RANGE1: Identifier: "Foo" [52:11 - 52:14] VarDecl=Foo:52:11 (Definition)
end_comment

begin_comment
comment|// CHECK-RANGE1: Punctuation: "," [52:14 - 52:15]
end_comment

begin_comment
comment|// CHECK-RANGE1: Punctuation: "." [53:5 - 53:6] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK-RANGE1: Identifier: "x" [53:6 - 53:7] MemberRef=x:52:1
end_comment

begin_comment
comment|// CHECK-RANGE1: Punctuation: "=" [53:8 - 53:9] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK-RANGE1: Literal: "0" [53:10 - 53:11] IntegerLiteral=
end_comment

begin_comment
comment|// CHECK-RANGE1: Punctuation: "," [53:11 - 53:12] InitListExpr=
end_comment

begin_comment
comment|// CHECK-RANGE1: Punctuation: "." [54:5 - 54:6] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK-RANGE1: Identifier: "y" [54:6 - 54:7] MemberRef=y:52:1
end_comment

begin_comment
comment|// CHECK-RANGE1: Punctuation: "=" [54:8 - 54:9] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK-RANGE1: Literal: "1" [54:10 - 54:11] IntegerLiteral=
end_comment

begin_comment
comment|// CHECK-RANGE1: Punctuation: "," [54:11 - 54:12] InitListExpr=
end_comment

begin_comment
comment|// RUN: c-index-test -test-annotate-tokens=%s:54:1:70:1 %s | FileCheck %s -check-prefix=CHECK-RANGE2
end_comment

begin_comment
comment|// CHECK-RANGE2: Punctuation: "." [54:5 - 54:6] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK-RANGE2: Identifier: "y" [54:6 - 54:7] MemberRef=y:52:1
end_comment

begin_comment
comment|// CHECK-RANGE2: Punctuation: "=" [54:8 - 54:9] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK-RANGE2: Literal: "1" [54:10 - 54:11] IntegerLiteral=
end_comment

begin_comment
comment|// CHECK-RANGE2: Punctuation: "," [54:11 - 54:12] InitListExpr=
end_comment

begin_comment
comment|// CHECK-RANGE2: Punctuation: "." [55:5 - 55:6] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK-RANGE2: Identifier: "z" [55:6 - 55:7] MemberRef=z:52:1
end_comment

begin_comment
comment|// CHECK-RANGE2: Punctuation: "=" [55:8 - 55:9] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK-RANGE2: Literal: "2" [55:10 - 55:11] IntegerLiteral=
end_comment

begin_comment
comment|// CHECK-RANGE2: Punctuation: "," [55:11 - 55:12] InitListExpr=
end_comment

begin_comment
comment|// CHECK-RANGE2: Punctuation: ")" [56:1 - 56:2]
end_comment

begin_comment
comment|// CHECK-RANGE2: Punctuation: ";" [56:2 - 56:3]
end_comment

begin_comment
comment|// CHECK-RANGE2: Keyword: "void" [58:1 - 58:5] FunctionDecl=func2:58:6
end_comment

begin_comment
comment|// CHECK-RANGE2: Identifier: "func2" [58:6 - 58:11] FunctionDecl=func2:58:6
end_comment

begin_comment
comment|// CHECK-RANGE2: Punctuation: "(" [58:11 - 58:12] FunctionDecl=func2:58:6
end_comment

begin_comment
comment|// CHECK-RANGE2: Keyword: "void" [58:12 - 58:16] FunctionDecl=func2:58:6
end_comment

begin_comment
comment|// CHECK-RANGE2: Punctuation: ")" [58:16 - 58:17] FunctionDecl=func2:58:6
end_comment

begin_comment
comment|// CHECK-RANGE2: Punctuation: ";" [58:17 - 58:18]
end_comment

begin_comment
comment|// CHECK-RANGE2: Identifier: "reg" [68:3 - 68:6] DeclRefExpr=reg:67:7
end_comment

begin_comment
comment|// CHECK-RANGE2: Punctuation: "." [68:6 - 68:7] MemberRefExpr=field:62:9
end_comment

begin_comment
comment|// CHECK-RANGE2: Identifier: "field" [68:7 - 68:12] MemberRefExpr=field:62:9
end_comment

begin_comment
comment|// RUN: c-index-test -test-annotate-tokens=%s:68:15:68:16 %s | FileCheck %s -check-prefix=CHECK-RANGE3
end_comment

begin_comment
comment|// CHECK-RANGE3: Literal: "1" [68:15 - 68:16] IntegerLiteral=
end_comment

begin_comment
comment|// CHECK-RANGE3-NOT: Punctuation: ";"
end_comment

end_unit

