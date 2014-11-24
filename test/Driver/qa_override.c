begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env CCC_OVERRIDE_OPTIONS="#+-Os +-Oz +-O +-O3 +-Oignore +a +b +c xb Xa Omagic ^-###  " %clang -target x86_64-apple-darwin %s -O2 b -O3 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: env CCC_OVERRIDE_OPTIONS="x-Werror +-msse" %clang -target x86_64-apple-darwin -Werror %s -c -### 2>&1 | FileCheck %s -check-prefix=RM-WERROR
end_comment

begin_comment
comment|// CHECK: "-cc1"
end_comment

begin_comment
comment|// CHECK-NOT: "-Oignore"
end_comment

begin_comment
comment|// CHECK: "-Omagic"
end_comment

begin_comment
comment|// CHECK-NOT: "-Oignore"
end_comment

begin_comment
comment|// RM-WERROR: ### CCC_OVERRIDE_OPTIONS: x-Werror +-msse
end_comment

begin_comment
comment|// RM-WERROR-NEXT: ### Deleting argument -Werror
end_comment

begin_comment
comment|// RM-WERROR-NEXT: ### Adding argument -msse at end
end_comment

begin_comment
comment|// RM-WERROR-NOT: "-Werror"
end_comment

end_unit

