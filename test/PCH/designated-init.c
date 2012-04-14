begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -include %s.h -emit-llvm -o %t.withoutpch.ll
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s.h -emit-pch -o %t.pch
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -include-pch %t.pch -emit-llvm -o %t.withpch.ll
end_comment

begin_comment
comment|// RUN: diff %t.withoutpch.ll %t.withpch.ll
end_comment

end_unit

