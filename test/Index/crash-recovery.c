begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not c-index-test -test-load-source all %s 2> %t.err
end_comment

begin_comment
comment|// RUN: FileCheck< %t.err -check-prefix=CHECK-LOAD-SOURCE-CRASH %s
end_comment

begin_comment
comment|// CHECK-LOAD-SOURCE-CRASH: Unable to load translation unit
end_comment

begin_comment
comment|// RUN: env LIBCLANG_DISABLE_CRASH_RECOVERY=1 not --crash c-index-test -test-load-source all %s
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

begin_pragma
pragma|#
directive|pragma
name|clang
name|__debug
name|crash
end_pragma

end_unit

