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

begin_comment
comment|// RUN: c-index-test -test-annotate-tokens=%s:4:1:9:32 %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: Identifier: "T" [4:3 - 4:4] TypeRef=T:1:13
end_comment

begin_comment
comment|// CHECK: Punctuation: "*" [4:4 - 4:5]
end_comment

begin_comment
comment|// CHECK: Identifier: "t_ptr" [4:6 - 4:11] VarDecl=t_ptr:4:6 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "=" [4:12 - 4:13]
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [4:14 - 4:15]
end_comment

begin_comment
comment|// CHECK: Identifier: "T" [4:15 - 4:16] TypeRef=T:1:13
end_comment

begin_comment
comment|// CHECK: Punctuation: "*" [4:17 - 4:18]
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [4:18 - 4:19]
end_comment

begin_comment
comment|// CHECK: Identifier: "ptr" [4:19 - 4:22] DeclRefExpr=ptr:3:14
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [4:22 - 4:23]
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [5:3 - 5:4]
end_comment

begin_comment
comment|// CHECK: Keyword: "void" [5:4 - 5:8]
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [5:8 - 5:9]
end_comment

begin_comment
comment|// CHECK: Keyword: "sizeof" [5:9 - 5:15]
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [5:15 - 5:16]
end_comment

begin_comment
comment|// CHECK: Identifier: "T" [5:16 - 5:17] TypeRef=T:1:13
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [5:17 - 5:18]
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [5:18 - 5:19]
end_comment

begin_comment
comment|// CHECK: Comment: "/* A comment */" [6:3 - 6:18]
end_comment

begin_comment
comment|// CHECK: Keyword: "struct" [7:3 - 7:9]
end_comment

begin_comment
comment|// CHECK: Identifier: "X" [7:10 - 7:11] TypeRef=struct X:2:8
end_comment

begin_comment
comment|// CHECK: Identifier: "x" [7:12 - 7:13] VarDecl=x:7:12 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "=" [7:14 - 7:15]
end_comment

begin_comment
comment|// CHECK: Punctuation: "(" [7:16 - 7:17]
end_comment

begin_comment
comment|// CHECK: Keyword: "struct" [7:17 - 7:23]
end_comment

begin_comment
comment|// CHECK: Identifier: "X" [7:24 - 7:25] TypeRef=struct X:2:8
end_comment

begin_comment
comment|// CHECK: Punctuation: ")" [7:25 - 7:26]
end_comment

begin_comment
comment|// CHECK: Punctuation: "{" [7:26 - 7:27]
end_comment

begin_comment
comment|// CHECK: Literal: "1" [7:27 - 7:28]
end_comment

begin_comment
comment|// CHECK: Punctuation: "," [7:28 - 7:29]
end_comment

begin_comment
comment|// CHECK: Literal: "2" [7:30 - 7:31]
end_comment

begin_comment
comment|// CHECK: Punctuation: "}" [7:31 - 7:32]
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [7:32 - 7:33]
end_comment

begin_comment
comment|// CHECK: Keyword: "void" [8:3 - 8:7]
end_comment

begin_comment
comment|// CHECK: Punctuation: "*" [8:8 - 8:9]
end_comment

begin_comment
comment|// CHECK: Identifier: "xx" [8:9 - 8:11] VarDecl=xx:8:9 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "=" [8:12 - 8:13]
end_comment

begin_comment
comment|// CHECK: Identifier: "ptr" [8:14 - 8:17] DeclRefExpr=ptr:3:14
end_comment

begin_comment
comment|// CHECK: Punctuation: "?" [8:18 - 8:19]
end_comment

begin_comment
comment|// CHECK: Punctuation: ":" [8:20 - 8:21]
end_comment

begin_comment
comment|// CHECK: Punctuation: "&" [8:22 - 8:23]
end_comment

begin_comment
comment|// CHECK: Identifier: "x" [8:23 - 8:24] DeclRefExpr=x:7:12
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [8:24 - 8:25]
end_comment

begin_comment
comment|// CHECK: Keyword: "const" [9:3 - 9:8]
end_comment

begin_comment
comment|// CHECK: Keyword: "char" [9:9 - 9:13]
end_comment

begin_comment
comment|// CHECK: Punctuation: "*" [9:14 - 9:15]
end_comment

begin_comment
comment|// CHECK: Identifier: "hello" [9:16 - 9:21] VarDecl=hello:9:16 (Definition)
end_comment

begin_comment
comment|// CHECK: Punctuation: "=" [9:22 - 9:23]
end_comment

begin_comment
comment|// CHECK: Literal: ""Hello"" [9:24 - 9:31]
end_comment

begin_comment
comment|// CHECK: Punctuation: ";" [9:31 - 9:32]
end_comment

begin_comment
comment|// CHECK: Punctuation: "}" [10:1 - 10:2]
end_comment

end_unit

