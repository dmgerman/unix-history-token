begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 \
end_comment

begin_comment
comment|// RUN:   not c-index-test -code-completion-at=%s:20:1 \
end_comment

begin_comment
comment|// RUN:   "-remap-file=%s;%S/Inputs/crash-recovery-code-complete-remap.c" \
end_comment

begin_comment
comment|// RUN:   %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck< %t.err -check-prefix=CHECK-CODE-COMPLETE-CRASH %s
end_comment

begin_comment
comment|// CHECK-CODE-COMPLETE-CRASH: Unable to perform code completion!
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// REQUIRES: crash-recovery
end_comment

begin_warning
warning|#
directive|warning
warning|parsing original file
end_warning

end_unit

