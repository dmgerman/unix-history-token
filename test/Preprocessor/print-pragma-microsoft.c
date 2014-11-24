begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -fms-extensions -E -o - | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|BAR
value|"2"
end_define

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|linker
name|,
literal|"bar="
name|BAR
name|)
end_pragma

begin_comment
comment|// CHECK: #pragma comment(linker, "bar=" "2")
end_comment

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|user
name|,
literal|"Compiled on "
name|__DATE__
literal|" at "
name|__TIME__
name|)
end_pragma

begin_comment
comment|// CHECK: #pragma comment(user, "Compiled on " "{{[^"]*}}" " at " "{{[^"]*}}")
end_comment

begin_define
define|#
directive|define
name|KEY1
value|"KEY1"
end_define

begin_define
define|#
directive|define
name|KEY2
value|"KEY2"
end_define

begin_define
define|#
directive|define
name|VAL1
value|"VAL1\""
end_define

begin_define
define|#
directive|define
name|VAL2
value|"VAL2"
end_define

begin_pragma
pragma|#
directive|pragma
name|detect_mismatch
name|(
name|KEY1
name|KEY2
name|,
name|VAL1
name|VAL2
name|)
end_pragma

begin_comment
comment|// CHECK: #pragma detect_mismatch("KEY1" "KEY2", "VAL1\"" "VAL2")
end_comment

begin_define
define|#
directive|define
name|_CRT_PACKING
value|8
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|_CRT_PACKING
name|)
end_pragma

begin_comment
comment|// CHECK: #pragma pack(push, 8)
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

end_unit

