begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Note: the run lines follow their respective tests, since line/column
end_comment

begin_comment
comment|// matter in this test.
end_comment

begin_struct
struct|struct
name|StructA
block|{ }
struct|;
end_struct

begin_struct
struct|struct
name|StructB
block|{ }
struct|;
end_struct

begin_struct
struct|struct
name|StructC
block|{ }
struct|;
end_struct

begin_decl_stmt
name|int
name|ValueA
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ValueB
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f
parameter_list|()
block|{
name|int
name|ValueA
init|=
literal|0
decl_stmt|;
name|int
name|StructA
init|=
literal|0
decl_stmt|;
struct|struct
name|StructB
block|{ }
struct|;
name|struct
name|StructA
name|sa
init|=
block|{ }
decl_stmt|;
block|}
end_function

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:16:3 %s> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-CC1 -input-file=%t %s
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_CACHING=1 c-index-test -code-completion-at=%s:16:3 %s | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

begin_comment
comment|// CHECK-CC1: VarDecl:{ResultType int}{TypedText StructA} (34)
end_comment

begin_comment
comment|// CHECK-CC1: VarDecl:{ResultType int}{TypedText ValueA} (34)
end_comment

begin_comment
comment|// CHECK-CC1-NOT: VarDecl:{ResultType int}{TypedText ValueA} (50)
end_comment

begin_comment
comment|// CHECK-CC1: VarDecl:{ResultType int}{TypedText ValueB} (50)
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:16:10 %s> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-CC2 -input-file=%t %s
end_comment

begin_comment
comment|// CHECK-CC2: StructDecl:{TypedText StructA} (50)
end_comment

begin_comment
comment|// CHECK-CC2-NOT: StructDecl:{TypedText StructB} (50)
end_comment

begin_comment
comment|// CHECK-CC2: StructDecl:{TypedText StructC} (50)
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_CACHING=1 c-index-test -code-completion-at=%s:16:10 %s> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-CC2 -input-file=%t %s
end_comment

end_unit

