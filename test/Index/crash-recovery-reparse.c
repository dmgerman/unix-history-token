begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 CINDEXTEST_PREAMBLE_FILE=%t-preamble.pch \
end_comment

begin_comment
comment|// RUN:   not c-index-test -test-load-source-reparse 1 local \
end_comment

begin_comment
comment|// RUN:   -remap-file="%s,%S/Inputs/crash-recovery-reparse-remap.c" \
end_comment

begin_comment
comment|// RUN:   %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck< %t.err -check-prefix=CHECK-REPARSE-SOURCE-CRASH %s
end_comment

begin_comment
comment|// RUN: test ! -e $t-preamble.pch
end_comment

begin_comment
comment|// CHECK-REPARSE-SOURCE-CRASH: Unable to reparse translation unit
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// REQUIRES: crash-recovery
end_comment

begin_comment
comment|// UNSUPPORTED: libstdcxx-safe-mode
end_comment

begin_warning
warning|#
directive|warning
warning|parsing original file
end_warning

end_unit

