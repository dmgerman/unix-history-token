begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|Point
block|{
name|float
name|x
decl_stmt|;
name|float
name|y
decl_stmt|;
name|float
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MACRO2
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|MACRO
parameter_list|(
name|x
parameter_list|)
value|MACRO2(x)
end_define

begin_function
name|void
name|test
parameter_list|(
name|struct
name|Point
modifier|*
name|p
parameter_list|)
block|{
name|p
operator|->
name|x
expr_stmt|;
name|MACRO
argument_list|(
name|p
operator|->
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|MACRO3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|x;y;z
end_define

begin_function
name|void
name|test2
parameter_list|(
name|struct
name|Point
modifier|*
name|p
parameter_list|)
block|{
name|MACRO3
argument_list|(
name|p
operator|->
name|x
argument_list|)
expr_stmt|;
name|MACRO3
argument_list|(
argument|p->x }
define|#
directive|define
name|FM
parameter_list|(
name|x
parameter_list|)
value|x
argument|void test3(struct Point *p) {   FM(p->x, a); }
define|#
directive|define
name|VGM
parameter_list|(
modifier|...
parameter_list|)
value|0
define|#
directive|define
name|VGM2
parameter_list|(
modifier|...
parameter_list|)
value|__VA_ARGS__
comment|// These need to be last, to test proper handling of EOF.
ifdef|#
directive|ifdef
name|EOF_TEST1
argument|void test3(struct Point *p) {   VGM(
literal|1
argument|,
literal|2
argument|, p->x
elif|#
directive|elif
name|EOF_TEST2
argument|void test3(struct Point *p) {   VGM2(VGM(
literal|1
argument|,
literal|2
argument|, p->x
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:11:12 %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:12:12 %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:18:13 %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:19:13 %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:24:9 %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK:      FieldDecl:{ResultType float}{TypedText x} (35)
end_comment

begin_comment
comment|// CHECK-NEXT: FieldDecl:{ResultType float}{TypedText y} (35)
end_comment

begin_comment
comment|// CHECK-NEXT: FieldDecl:{ResultType float}{TypedText z} (35)
end_comment

begin_comment
comment|// CHECK-NEXT: Completion contexts:
end_comment

begin_comment
comment|// CHECK-NEXT: Arrow member access
end_comment

begin_comment
comment|// CHECK-NEXT: Container Kind: StructDecl
end_comment

begin_comment
comment|// With these, code-completion is unknown because the macro argument (and the
end_comment

begin_comment
comment|// completion point) is not expanded by the macro definition.
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:33:15 %s -DEOF_TEST1 | FileCheck %s -check-prefix=CHECK-EOF
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:37:20 %s -DEOF_TEST2 | FileCheck %s -check-prefix=CHECK-EOF
end_comment

begin_comment
comment|// CHECK-EOF: Completion contexts:
end_comment

begin_comment
comment|// CHECK-EOF: Unknown
end_comment

end_unit

