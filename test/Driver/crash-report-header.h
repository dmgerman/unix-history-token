begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir %t
end_comment

begin_comment
comment|// RUN: not env TMPDIR="%t" TEMP="%t" TMP="%t" RC_DEBUG_OPTIONS=1 %clang -fsyntax-only %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: cat %t/crash-report-header-*.h | FileCheck --check-prefix=CHECKSRC "%s"
end_comment

begin_comment
comment|// RUN: cat %t/crash-report-header-*.sh | FileCheck --check-prefix=CHECKSH "%s"
end_comment

begin_comment
comment|// REQUIRES: crash-recovery
end_comment

begin_comment
comment|// because of the glob (*.h, *.sh)
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|__debug
name|parser_crash
end_pragma

begin_comment
comment|// CHECK: Preprocessed source(s) and associated run script(s) are located at:
end_comment

begin_comment
comment|// CHECK-NEXT: note: diagnostic msg: {{.*}}.h
end_comment

begin_macro
name|FOO
end_macro

begin_comment
comment|// CHECKSRC: FOO
end_comment

begin_comment
comment|// CHECKSH: "-cc1"
end_comment

begin_comment
comment|// CHECKSH: "-main-file-name" "crash-report-header.h"
end_comment

begin_comment
comment|// CHECKSH: "crash-report-header-{{[^ ]*}}.h"
end_comment

end_unit

