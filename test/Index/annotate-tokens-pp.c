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

begin_comment
comment|// RUN: c-index-test -test-annotate-tokens=%s:2:1:9:1 -I%S/Inputs %s | FileCheck %s
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
comment|// CHECK: Identifier: "NOTHING" [2:23 - 2:30] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [2:30 - 2:31] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "honk" [2:31 - 2:35] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Punctuation: "," [2:35 - 2:36] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "warble" [2:36 - 2:42] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [2:42 - 2:43] preprocessing directive=
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
comment|// CHECK: Identifier: "baz" [3:13 - 3:16] preprocessing directive=
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
comment|// CHECK: Punctuation: "(" [4:15 - 4:16] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "X" [4:16 - 4:17] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Punctuation: "," [4:17 - 4:18] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "Y" [4:19 - 4:20] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [4:20 - 4:21] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "X" [4:22 - 4:23] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Punctuation: "##" [4:23 - 4:25] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "Y" [4:25 - 4:26] preprocessing directive=
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
comment|// CHECK: Punctuation: "#" [7:1 - 7:2] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Identifier: "include" [7:2 - 7:9] preprocessing directive=
end_comment

begin_comment
comment|// CHECK: Literal: ""foo.h"" [7:10 - 7:17] preprocessing directive=
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

end_unit

