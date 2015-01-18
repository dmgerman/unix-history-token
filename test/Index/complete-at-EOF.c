begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_CACHING=1 c-index-test \
end_comment

begin_comment
comment|// RUN:	    -code-completion-at=%S/Inputs/complete-at-EOF.c:4:1 %S/Inputs/complete-at-EOF.c | FileCheck -check-prefix=CHECK-EOF %s
end_comment

begin_comment
comment|// CHECK-EOF: macro definition:{TypedText CAKE}
end_comment

begin_comment
comment|// CHECK-EOF: TypedefDecl:{TypedText foo}
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_CACHING=1 c-index-test \
end_comment

begin_comment
comment|// RUN:     -code-completion-at=%S/Inputs/complete-at-EOF.c:2:1 %S/Inputs/complete-at-EOF.c | FileCheck -check-prefix=CHECK-AFTER-PREAMBLE %s
end_comment

begin_comment
comment|// CHECK-AFTER-PREAMBLE: macro definition:{TypedText CAKE}
end_comment

end_unit

