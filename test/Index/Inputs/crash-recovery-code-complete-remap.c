begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: echo env CINDEXTEST_EDITING=1 \
end_comment

begin_comment
comment|// RUN:   not c-index-test -test-load-source-reparse 1 local \
end_comment

begin_comment
comment|// RUN:   -remap-file="%s,%S/Inputs/crash-recovery-code-complete-remap.c" \
end_comment

begin_comment
comment|// RUN:   %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck< %t.err -check-prefix=CHECK-CODE-COMPLETE-CRASH %s
end_comment

begin_comment
comment|// CHECK-CODE-COMPLETE-CRASH: Unable to reparse translation unit
end_comment

begin_warning
warning|#
directive|warning
warning|parsing original file
end_warning

begin_pragma
pragma|#
directive|pragma
name|clang
name|__debug
name|crash
end_pragma

end_unit

