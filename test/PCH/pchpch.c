begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-pch -o %t1 %S/pchpch1.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-pch -o %t2 %S/pchpch2.h -include-pch %t1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -fsyntax-only %s -include-pch %t2
end_comment

begin_comment
comment|// The purpose of this test is to make sure that a PCH created while including
end_comment

begin_comment
comment|// an existing PCH can be loaded.
end_comment

end_unit

