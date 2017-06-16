begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple i686-pc-win32 -fms-extensions -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple thumbv7-windows -fms-extensions -emit-llvm -o - | FileCheck %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|detect_mismatch
name|(
literal|"test"
name|,
literal|"1"
name|)
end_pragma

begin_define
define|#
directive|define
name|BAR
value|"2"
end_define

begin_pragma
pragma|#
directive|pragma
name|detect_mismatch
name|(
literal|"test2"
name|,
name|BAR
name|)
end_pragma

begin_comment
comment|// CHECK: !llvm.linker.options = !{![[test:[0-9]+]], ![[test2:[0-9]+]]}
end_comment

begin_comment
comment|// CHECK: ![[test]] = !{!"/FAILIFMISMATCH:\22test=1\22"}
end_comment

begin_comment
comment|// CHECK: ![[test2]] = !{!"/FAILIFMISMATCH:\22test2=2\22"}
end_comment

end_unit

