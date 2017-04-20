begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// Verify that the suggested attribute subject match rules don't include the
end_comment

begin_comment
comment|// rules that are not applicable in the current language mode.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|abi_tag
name|(
literal|"a"
name|)
name|)
name|)
name|)
end_pragma

begin_comment
comment|// CHECK: fix-it:{{.*}}:{[[@LINE-1]]:60-[[@LINE-1]]:60}:", apply_to = any(record(unless(is_union)), variable, function)"
end_comment

end_unit

