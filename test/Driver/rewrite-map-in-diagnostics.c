begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf "%t"
end_comment

begin_comment
comment|// RUN: mkdir -p "%t"
end_comment

begin_comment
comment|// RUN: not env TMPDIR="%t" TEMP="%t" TMP="%t" RC_DEBUG_OPTION=1 \
end_comment

begin_comment
comment|// RUN:     %clang -fsyntax-only -frewrite-map-file %p/Inputs/rewrite.map %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|__debug
name|parser_crash
end_pragma

begin_comment
comment|// CHECK: note: diagnostic msg: {{.*}}rewrite.map
end_comment

begin_comment
comment|// FIXME: This doesn't fail on "env clang". Investigating.
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

end_unit

