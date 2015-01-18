begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir %t
end_comment

begin_comment
comment|// RUN: not env TMPDIR=%t TEMP=%t TMP=%t RC_DEBUG_OPTIONS=1 %clang -fsyntax-only %s \
end_comment

begin_comment
comment|// RUN:  -F/tmp/ -I /tmp/ -idirafter /tmp/ -iquote /tmp/ -isystem /tmp/ \
end_comment

begin_comment
comment|// RUN:  -iprefix /the/prefix -iwithprefix /tmp -iwithprefixbefore /tmp/ \
end_comment

begin_comment
comment|// RUN:  -Xclang -internal-isystem -Xclang /tmp/                         \
end_comment

begin_comment
comment|// RUN:  -Xclang -internal-externc-isystem -Xclang /tmp/                 \
end_comment

begin_comment
comment|// RUN:  -DFOO=BAR 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: cat %t/crash-report-*.c | FileCheck --check-prefix=CHECKSRC %s
end_comment

begin_comment
comment|// RUN: cat %t/crash-report-*.sh | FileCheck --check-prefix=CHECKSH %s
end_comment

begin_comment
comment|// REQUIRES: crash-recovery
end_comment

begin_comment
comment|// because of the glob (*.c, *.sh)
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
comment|// CHECK-NEXT: note: diagnostic msg: {{.*}}crash-report-{{.*}}.c
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
comment|// CHECKSH: "-main-file-name" "crash-report.c"
end_comment

begin_comment
comment|// CHECKSH: "-D" "FOO=BAR"
end_comment

begin_comment
comment|// CHECKSH-NOT: "-F/tmp/"
end_comment

begin_comment
comment|// CHECKSH-NOT: "-I" "/tmp/"
end_comment

begin_comment
comment|// CHECKSH-NOT: "-idirafter" "/tmp/"
end_comment

begin_comment
comment|// CHECKSH-NOT: "-iquote" "/tmp/"
end_comment

begin_comment
comment|// CHECKSH-NOT: "-isystem" "/tmp/"
end_comment

begin_comment
comment|// CHECKSH-NOT: "-iprefix" "/the/prefix"
end_comment

begin_comment
comment|// CHECKSH-NOT: "-iwithprefix" "/tmp/"
end_comment

begin_comment
comment|// CHECKSH-NOT: "-iwithprefixbefore" "/tmp/"
end_comment

begin_comment
comment|// CHECKSH-NOT: "-internal-isystem" "/tmp/"
end_comment

begin_comment
comment|// CHECKSH-NOT: "-internal-externc-isystem" "/tmp/"
end_comment

begin_comment
comment|// CHECKSH-NOT: "-dwarf-debug-flags"
end_comment

begin_comment
comment|// CHECKSH: "crash-report-{{[^ ]*}}.c"
end_comment

end_unit

