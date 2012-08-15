begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fms-extensions -Wno-invalid-token-paste %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -fms-extensions -Wno-invalid-token-paste %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -fms-extensions -Wno-invalid-token-paste -x assembler-with-cpp %s | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|foo
value|a ## b ## = 0
end_define

begin_decl_stmt
name|int
name|foo
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: int ab = 0;
end_comment

end_unit

