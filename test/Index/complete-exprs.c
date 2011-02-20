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
function_decl|__attribute__
parameter_list|(
function_decl|(unavailable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

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
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
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

begin_function_decl
name|void
name|f3
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(sentinel
parameter_list|(
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|NULL
value|__null
end_define

begin_function
name|void
name|f4
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
name|f3
argument_list|(
name|str
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|int
name|type
typedef|;
end_typedef

begin_function
name|void
name|f5
parameter_list|(
name|float
name|f
parameter_list|)
block|{
operator|(
name|type
operator|)
name|f
expr_stmt|;
block|}
end_function

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:7:9 -Xclang -code-completion-patterns %s | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_CACHING=1 c-index-test -code-completion-at=%s:7:9 -Xclang -code-completion-patterns %s | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

begin_comment
comment|// CHECK-CC1: NotImplemented:{TypedText __PRETTY_FUNCTION__} (65)
end_comment

begin_comment
comment|// CHECK-CC1: macro definition:{TypedText __VERSION__} (70)
end_comment

begin_comment
comment|// CHECK-CC1: FunctionDecl:{ResultType int}{TypedText f}{LeftParen (}{Placeholder int}{RightParen )} (12) (unavailable)
end_comment

begin_comment
comment|// CHECK-CC1-NOT: NotImplemented:{TypedText float} (65)
end_comment

begin_comment
comment|// CHECK-CC1: ParmDecl:{ResultType int}{TypedText j} (8)
end_comment

begin_comment
comment|// CHECK-CC1: NotImplemented:{TypedText sizeof}{LeftParen (}{Placeholder expression-or-type}{RightParen )} (40)
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_CACHING=1 c-index-test -code-completion-at=%s:7:9 -Xclang -code-completion-patterns %s | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:7:14 -Xclang -code-completion-patterns %s | FileCheck -check-prefix=CHECK-CC3 %s
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_CACHING=1 c-index-test -code-completion-at=%s:7:14 -Xclang -code-completion-patterns %s | FileCheck -check-prefix=CHECK-CC3 %s
end_comment

begin_comment
comment|// CHECK-CC3: macro definition:{TypedText __VERSION__} (70)
end_comment

begin_comment
comment|// CHECK-CC3: FunctionDecl:{ResultType int}{TypedText f}{LeftParen (}{Placeholder int}{RightParen )} (50)
end_comment

begin_comment
comment|// CHECK-CC3-NOT: NotImplemented:{TypedText float}
end_comment

begin_comment
comment|// CHECK-CC3: ParmDecl:{ResultType int}{TypedText j} (34)
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
comment|// CHECK-CC2: NotImplemented:{TypedText float} (50)
end_comment

begin_comment
comment|// CHECK-CC2: ParmDecl:{ResultType int}{TypedText j} (34)
end_comment

begin_comment
comment|// CHECK-CC2: NotImplemented:{TypedText sizeof}{LeftParen (}{Placeholder expression-or-type}{RightParen )} (40)
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:11:16 -Xclang -code-completion-patterns %s | FileCheck -check-prefix=CHECK-CC4 %s
end_comment

begin_comment
comment|// CHECK-CC4: FunctionDecl:{ResultType int}{TypedText f}{LeftParen (}{Placeholder int}{RightParen )} (50)
end_comment

begin_comment
comment|// CHECK-CC4: VarDecl:{ResultType struct X}{TypedText f1} (50) (deprecated)
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:19:3 -Xclang -code-completion-patterns %s | FileCheck -check-prefix=CHECK-CC6 %s
end_comment

begin_comment
comment|// CHECK-CC6: FunctionDecl:{ResultType void}{TypedText f3}{LeftParen (}{Placeholder const char *, ...}{Text , NULL}{RightParen )} (50)
end_comment

begin_comment
comment|// CHECK-CC6: NotImplemented:{TypedText void} (50)
end_comment

begin_comment
comment|// CHECK-CC6: NotImplemented:{TypedText volatile} (50)
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:24:4 -Xclang -code-completion-patterns %s | FileCheck -check-prefix=CHECK-CC7 %s
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_CACHING=1 c-index-test -code-completion-at=%s:24:4 -Xclang -code-completion-patterns %s | FileCheck -check-prefix=CHECK-CC7 %s
end_comment

begin_comment
comment|// CHECK-CC7: ParmDecl:{ResultType float}{TypedText f} (34)
end_comment

begin_comment
comment|// CHECK-CC7: VarDecl:{ResultType struct X}{TypedText f1} (50) (deprecated)
end_comment

begin_comment
comment|// CHECK-CC7: FunctionDecl:{ResultType void}{TypedText f2}{LeftParen (}{RightParen )} (50)
end_comment

begin_comment
comment|// CHECK-CC7: FunctionDecl:{ResultType void}{TypedText f3}{LeftParen (}{Placeholder const char *, ...}{Text , NULL}{RightParen )} (50)
end_comment

begin_comment
comment|// CHECK-CC7: FunctionDecl:{ResultType void}{TypedText f4}{LeftParen (}{Placeholder const char *str}{RightParen )} (50)
end_comment

begin_comment
comment|// CHECK-CC7: FunctionDecl:{ResultType void}{TypedText f5}{LeftParen (}{Placeholder float f}{RightParen )} (50)
end_comment

begin_comment
comment|// CHECK-CC7: TypedefDecl:{TypedText type}
end_comment

end_unit

