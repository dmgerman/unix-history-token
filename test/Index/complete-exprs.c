begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Note: the run lines follow their respective tests, since line/column
end_comment

begin_comment
comment|// matter in this test.
end_comment

begin_function_decl
name|int
name|f
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|,
name|int
name|k
parameter_list|,
name|int
name|l
parameter_list|)
block|{
return|return
name|i
operator||
name|j
operator||
name|k
operator|&
name|l
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|X
name|f1
init|=
block|{
literal|17
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f2
parameter_list|()
block|{
name|f1
argument_list|(
literal|17
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|const
name|char
modifier|*
name|str
init|=
literal|"Hello, \nWorld"
decl_stmt|;
end_decl_stmt

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:7:9 -Xclang -code-completion-patterns %s | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

begin_comment
comment|// CHECK-CC1: macro definition:{TypedText __VERSION__} (70)
end_comment

begin_comment
comment|// CHECK-CC1: FunctionDecl:{ResultType int}{TypedText f}{LeftParen (}{Placeholder int}{RightParen )} (12)
end_comment

begin_comment
comment|// CHECK-CC1-NOT: NotImplemented:{TypedText float} (40)
end_comment

begin_comment
comment|// CHECK-CC1: ParmDecl:{ResultType int}{TypedText j} (2)
end_comment

begin_comment
comment|// CHECK-CC1: NotImplemented:{TypedText sizeof}{LeftParen (}{Placeholder expression-or-type}{RightParen )} (30)
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:7:14 -Xclang -code-completion-patterns %s | FileCheck -check-prefix=CHECK-CC3 %s
end_comment

begin_comment
comment|// CHECK-CC3: macro definition:{TypedText __VERSION__} (70)
end_comment

begin_comment
comment|// CHECK-CC3: FunctionDecl:{ResultType int}{TypedText f}{LeftParen (}{Placeholder int}{RightParen )} (50)
end_comment

begin_comment
comment|// CHECK-CC3-NOT: NotImplemented:{TypedText float} (40)
end_comment

begin_comment
comment|// CHECK-CC3: ParmDecl:{ResultType int}{TypedText j} (8)
end_comment

begin_comment
comment|// CHECK-CC3: NotImplemented:{TypedText sizeof}{LeftParen (}{Placeholder expressio
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:7:18 -Xclang -code-completion-patterns %s | FileCheck -check-prefix=CHECK-CC3 %s
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:7:22 -Xclang -code-completion-patterns %s | FileCheck -check-prefix=CHECK-CC3 %s
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:7:2 -Xclang -code-completion-patterns %s | FileCheck -check-prefix=CHECK-CC2 %s
end_comment

begin_comment
comment|// CHECK-CC2: macro definition:{TypedText __VERSION__} (70)
end_comment

begin_comment
comment|// CHECK-CC2: FunctionDecl:{ResultType int}{TypedText f}{LeftParen (}{Placeholder int}{RightParen )} (50)
end_comment

begin_comment
comment|// CHECK-CC2: NotImplemented:{TypedText float} (40)
end_comment

begin_comment
comment|// CHECK-CC2: ParmDecl:{ResultType int}{TypedText j} (8)
end_comment

begin_comment
comment|// CHECK-CC2: NotImplemented:{TypedText sizeof}{LeftParen (}{Placeholder expression-or-type}{RightParen )} (30)
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:11:16 -Xclang -code-completion-patterns %s | FileCheck -check-prefix=CHECK-CC4 %s
end_comment

begin_comment
comment|// CHECK-CC4: FunctionDecl:{ResultType int}{TypedText f}{LeftParen (}{Placeholder int}{RightParen )} (50)
end_comment

begin_comment
comment|// CHECK-CC4: VarDecl:{ResultType struct X}{TypedText f1} (50)
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:13:28 -Xclang -code-completion-patterns %s | FileCheck -check-prefix=CHECK-CC5 %s
end_comment

begin_comment
comment|// CHECK-CC5: NotImplemented:{TypedText void} (40)
end_comment

begin_comment
comment|// CHECK-CC5: NotImplemented:{TypedText volatile} (40)
end_comment

end_unit

