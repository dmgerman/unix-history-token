begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|NOTHING
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
end_define

begin_define
define|#
directive|define
name|STILL_NOTHING
value|NOTHING(honk,warble)
end_define

begin_define
define|#
directive|define
name|BAR
value|baz
end_define

begin_define
define|#
directive|define
name|WIBBLE
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|X##Y
end_define

begin_macro
name|NOTHING
argument_list|(
argument|more
argument_list|,
argument|junk
argument_list|)
end_macro

begin_function_decl
name|float
name|WIBBLE
parameter_list|(
name|int
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|BAR
name|STILL_NOTHING
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"foo.h"
end_include

begin_undef
undef|#
directive|undef
name|BAR
end_undef

begin_define
define|#
directive|define
name|REVERSE_MACRO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|y + x
end_define

begin_define
define|#
directive|define
name|TWICE_MACRO
parameter_list|(
name|y
parameter_list|)
value|y + y
end_define

begin_function
name|void
name|test_macro_args
parameter_list|()
block|{
name|int
name|z
init|=
literal|1
decl_stmt|;
name|int
name|t
init|=
literal|2
decl_stmt|;
name|int
name|k
init|=
name|REVERSE_MACRO
argument_list|(
name|t
argument_list|,
name|z
argument_list|)
decl_stmt|;
name|int
name|j
init|=
name|TWICE_MACRO
argument_list|(
name|k
operator|+
name|k
argument_list|)
decl_stmt|;
name|int
name|w
init|=
name|j
operator|+
name|j
decl_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|fun_with_macro_bodies
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|do { if (x) y } while (0)
end_define

begin_function
name|void
name|test
parameter_list|()
block|{
name|int
name|x
init|=
literal|10
decl_stmt|;
name|fun_with_macro_bodies
argument_list|(
argument|x
argument_list|,
argument|{ int z = x; ++z; }
argument_list|)
empty_stmt|;
block|}
end_function

begin_comment
comment|// RUN: c-index-test -test-annotate-tokens=%s:2:1:26:1 -I%S/Inputs %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: Punctuation: "#" [2:1 - 2:2] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "define" [2:2 - 2:8] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "STILL_NOTHING" [2:9 - 2:22] macro definition=STILL_NOTHING
end_comment

begin_comment
comment|// CHECK: Identifier: "NOTHING" [2:23 - 2:30] macro definition=STILL_NOTHING
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [2:30 - 2:31] macro definition=STILL_NOTHING
end_comment

begin_comment
comment|// CHECK: Identifier: "honk" [2:31 - 2:35] macro definition=STILL_NOTHING
end_comment

begin_comment
comment|// CHECK: Punctuation: "," [2:35 - 2:36] macro definition=STILL_NOTHING
end_comment

begin_comment
comment|// CHECK: Identifier: "warble" [2:36 - 2:42] macro definition=STILL_NOTHING
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [2:42 - 2:43] macro definition=STILL_NOTHING
end_comment

begin_comment
comment|// CHECK: Punctuation: "#" [3:1 - 3:2] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "define" [3:2 - 3:8] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "BAR" [3:9 - 3:12] macro definition=BAR
end_comment

begin_comment
comment|// CHECK: Identifier: "baz" [3:13 - 3:16] macro definition=BAR
end_comment

begin_comment
comment|// CHECK: Punctuation: "#" [4:1 - 4:2] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "define" [4:2 - 4:8] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "WIBBLE" [4:9 - 4:15] macro definition=WIBBLE
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [4:15 - 4:16] macro definition=WIBBLE
end_comment

begin_comment
comment|// CHECK: Identifier: "X" [4:16 - 4:17] macro definition=WIBBLE
end_comment

begin_comment
comment|// CHECK: Punctuation: "," [4:17 - 4:18] macro definition=WIBBLE
end_comment

begin_comment
comment|// CHECK: Identifier: "Y" [4:19 - 4:20] macro definition=WIBBLE
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [4:20 - 4:21] macro definition=WIBBLE
end_comment

begin_comment
comment|// CHECK: Identifier: "X" [4:22 - 4:23] macro definition=WIBBLE
end_comment

begin_comment
comment|// CHECK: Punctuation: "##" [4:23 - 4:25] macro definition=WIBBLE
end_comment

begin_comment
comment|// CHECK: Identifier: "Y" [4:25 - 4:26] macro definition=WIBBLE
end_comment

begin_comment
comment|// CHECK: Identifier: "NOTHING" [5:1 - 5:8] macro instantiation=NOTHING:1:9
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [5:8 - 5:9]
end_comment

begin_comment
comment|// CHECK: Identifier: "more" [5:9 - 5:13]
end_comment

begin_comment
comment|// CHECK: Punctuation: "," [5:13 - 5:14]
end_comment

begin_comment
comment|// CHECK: Identifier: "junk" [5:14 - 5:18]
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [5:18 - 5:19]
end_comment

begin_comment
comment|// CHECK: Keyword: "float" [5:20 - 5:25]
end_comment

begin_comment
comment|// CHECK: Identifier: "WIBBLE" [5:26 - 5:32] macro instantiation=WIBBLE:4:9
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [5:32 - 5:33]
end_comment

begin_comment
comment|// CHECK: Keyword: "int" [5:33 - 5:36]
end_comment

begin_comment
comment|// CHECK: Punctuation: "," [5:36 - 5:37]
end_comment

begin_comment
comment|// CHECK: Keyword: "float" [5:38 - 5:43]
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [5:43 - 5:44]
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [5:44 - 5:45]
end_comment

begin_comment
comment|// CHECK: Keyword: "int" [6:1 - 6:4]
end_comment

begin_comment
comment|// CHECK: Identifier: "BAR" [6:5 - 6:8] macro instantiation=BAR:3:9
end_comment

begin_comment
comment|// CHECK: Identifier: "STILL_NOTHING" [6:9 - 6:22] macro instantiation=STILL_NOTHING:2:9
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [6:22 - 6:23]
end_comment

begin_comment
comment|// CHECK: Punctuation: "#" [7:1 - 7:2] inclusion directive=foo.h
end_comment

begin_comment
comment|// CHECK: Identifier: "include" [7:2 - 7:9] inclusion directive=foo.h
end_comment

begin_comment
comment|// CHECK: Literal: ""foo.h"" [7:10 - 7:17] inclusion directive=foo.h
end_comment

begin_comment
comment|// CHECK: Punctuation: "#" [8:1 - 8:2] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "undef" [8:2 - 8:7] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "BAR" [8:8 - 8:11] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Punctuation: "#" [10:1 - 10:2] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "define" [10:2 - 10:8] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "REVERSE_MACRO" [10:9 - 10:22] macro definition=REVERSE_MACRO
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [10:22 - 10:23] macro definition=REVERSE_MACRO
end_comment

begin_comment
comment|// CHECK: Identifier: "x" [10:23 - 10:24] macro definition=REVERSE_MACRO
end_comment

begin_comment
comment|// CHECK: Punctuation: "," [10:24 - 10:25] macro definition=REVERSE_MACRO
end_comment

begin_comment
comment|// CHECK: Identifier: "y" [10:25 - 10:26] macro definition=REVERSE_MACRO
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [10:26 - 10:27] macro definition=REVERSE_MACRO
end_comment

begin_comment
comment|// CHECK: Identifier: "y" [10:28 - 10:29] macro definition=REVERSE_MACRO
end_comment

begin_comment
comment|// CHECK: Punctuation: "+" [10:30 - 10:31] macro definition=REVERSE_MACRO
end_comment

begin_comment
comment|// CHECK: Identifier: "x" [10:32 - 10:33] macro definition=REVERSE_MACRO
end_comment

begin_comment
comment|// CHECK: Punctuation: "#" [11:1 - 11:2] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "define" [11:2 - 11:8] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "TWICE_MACRO" [11:9 - 11:20] macro definition=TWICE_MACRO
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [11:20 - 11:21] macro definition=TWICE_MACRO
end_comment

begin_comment
comment|// CHECK: Identifier: "y" [11:21 - 11:22] macro definition=TWICE_MACRO
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [11:22 - 11:23] macro definition=TWICE_MACRO
end_comment

begin_comment
comment|// CHECK: Identifier: "y" [11:24 - 11:25] macro definition=TWICE_MACRO
end_comment

begin_comment
comment|// CHECK: Punctuation: "+" [11:26 - 11:27] macro definition=TWICE_MACRO
end_comment

begin_comment
comment|// CHECK: Identifier: "y" [11:28 - 11:29] macro definition=TWICE_MACRO
end_comment

begin_comment
comment|// CHECK: Keyword: "void" [13:1 - 13:5] FunctionDecl=test_macro_args:13:6 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "test_macro_args" [13:6 - 13:21] FunctionDecl=test_macro_args:13:6 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [13:21 - 13:22] FunctionDecl=test_macro_args:13:6 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [13:22 - 13:23] FunctionDecl=test_macro_args:13:6 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "{" [13:24 - 13:25] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "int" [14:3 - 14:6] VarDecl=z:14:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "z" [14:7 - 14:8] VarDecl=z:14:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "=" [14:9 - 14:10] VarDecl=z:14:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Literal: "1" [14:11 - 14:12] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [14:12 - 14:13] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "int" [15:3 - 15:6] VarDecl=t:15:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "t" [15:7 - 15:8] VarDecl=t:15:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "=" [15:9 - 15:10] VarDecl=t:15:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Literal: "2" [15:11 - 15:12] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [15:12 - 15:13] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "int" [16:3 - 16:6] VarDecl=k:16:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "k" [16:7 - 16:8] VarDecl=k:16:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "=" [16:9 - 16:10] VarDecl=k:16:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "REVERSE_MACRO" [16:11 - 16:24] macro instantiation=REVERSE_MACRO:10:9
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [16:24 - 16:25] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "t" [16:25 - 16:26] DeclRefExpr=t:15:7
end_comment

begin_comment
comment|// CHECK: Punctuation: "," [16:26 - 16:27] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "z" [16:27 - 16:28] DeclRefExpr=z:14:7
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [16:28 - 16:29] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [16:29 - 16:30] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "int" [17:3 - 17:6] VarDecl=j:17:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "j" [17:7 - 17:8] VarDecl=j:17:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "=" [17:9 - 17:10] VarDecl=j:17:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "TWICE_MACRO" [17:11 - 17:22] macro instantiation=TWICE_MACRO:11:9
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [17:22 - 17:23] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "k" [17:23 - 17:24] DeclRefExpr=k:16:7
end_comment

begin_comment
comment|// CHECK: Punctuation: "+" [17:25 - 17:26] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "k" [17:27 - 17:28] DeclRefExpr=k:16:7
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [17:28 - 17:29] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [17:29 - 17:30] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "int" [18:3 - 18:6] VarDecl=w:18:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "w" [18:7 - 18:8] VarDecl=w:18:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "=" [18:9 - 18:10] VarDecl=w:18:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "j" [18:11 - 18:12] DeclRefExpr=j:17:7
end_comment

begin_comment
comment|// CHECK: Punctuation: "+" [18:13 - 18:14] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK: Identifier: "j" [18:15 - 18:16] DeclRefExpr=j:17:7
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [18:16 - 18:17] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: "}" [19:1 - 19:2] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: "#" [21:1 - 21:2] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "define" [21:2 - 21:8] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "fun_with_macro_bodies" [21:9 - 21:30] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [21:30 - 21:31] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Identifier: "x" [21:31 - 21:32] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Punctuation: "," [21:32 - 21:33] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Identifier: "y" [21:34 - 21:35] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [21:35 - 21:36] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Keyword: "do" [21:37 - 21:39] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Punctuation: "{" [21:40 - 21:41] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Keyword: "if" [21:42 - 21:44] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [21:45 - 21:46] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Identifier: "x" [21:46 - 21:47] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [21:47 - 21:48] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Identifier: "y" [21:49 - 21:50] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Punctuation: "}" [21:51 - 21:52] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Keyword: "while" [21:53 - 21:58] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [21:59 - 21:60] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Literal: "0" [21:60 - 21:61] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [21:61 - 21:62] macro definition=fun_with_macro_bodies
end_comment

begin_comment
comment|// CHECK: Keyword: "void" [23:1 - 23:5] FunctionDecl=test:23:6 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "test" [23:6 - 23:10] FunctionDecl=test:23:6 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [23:10 - 23:11] FunctionDecl=test:23:6 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [23:11 - 23:12] FunctionDecl=test:23:6 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "{" [23:13 - 23:14] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "int" [24:3 - 24:6] VarDecl=x:24:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Identifier: "x" [24:7 - 24:8] VarDecl=x:24:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "=" [24:9 - 24:10] VarDecl=x:24:7 (Definition)
end_comment

begin_comment
comment|// CHECK: Literal: "10" [24:11 - 24:13] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [24:13 - 24:14] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "fun_with_macro_bodies" [25:3 - 25:24] macro instantiation=fun_with_macro_bodies:21:9
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [25:24 - 25:25] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "x" [25:25 - 25:26] DeclRefExpr=x:24:7
end_comment

begin_comment
comment|// CHECK: Punctuation: "," [25:26 - 25:27] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: "{" [25:28 - 25:29] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Keyword: "int" [25:30 - 25:33] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "z" [25:34 - 25:35] VarDecl=z:25:34 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "=" [25:36 - 25:37] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Identifier: "x" [25:38 - 25:39] DeclRefExpr=x:24:7
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [25:39 - 25:40] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: "++" [25:41 - 25:43] UnexposedExpr=
end_comment

begin_comment
comment|// CHECK: Identifier: "z" [25:43 - 25:44] DeclRefExpr=z:25:3
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [25:44 - 25:45] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: "}" [25:46 - 25:47] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [25:47 - 25:48] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [25:48 - 25:49] UnexposedStmt=
end_comment

begin_comment
comment|// CHECK: Punctuation: "}" [26:1 - 26:2] UnexposedStmt=
end_comment

end_unit

