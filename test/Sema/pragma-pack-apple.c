begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fapple-pragma-pack %s 2>&1 | FileCheck -check-prefix=CHECK-APPLE %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|2
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_comment
comment|// CHECK: pack(show) == 8
end_comment

begin_comment
comment|// CHECK-APPLE: pack(show) == 1
end_comment

end_unit

