begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -S -msoft-float %s 2>&1 | FileCheck -check-prefix=TEST1 %s
end_comment

begin_comment
comment|// TEST1: "-no-implicit-float"
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -S -msoft-float -mno-soft-float %s 2>&1 | FileCheck -check-prefix=TEST2 %s
end_comment

begin_comment
comment|// TEST2-NOT: "-no-implicit-float"
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -S -mno-soft-float %s -msoft-float 2>&1 | FileCheck -check-prefix=TEST3 %s
end_comment

begin_comment
comment|// TEST3: "-no-implicit-float"
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -S -mno-implicit-float %s 2>&1 | FileCheck -check-prefix=TEST4 %s
end_comment

begin_comment
comment|// TEST4: "-no-implicit-float"
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -S -mno-implicit-float -mimplicit-float %s 2>&1 | FileCheck -check-prefix=TEST4A %s
end_comment

begin_comment
comment|// TEST4A-NOT: "-no-implicit-float"
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -S -mkernel %s 2>&1 | FileCheck -check-prefix=TEST5 %s
end_comment

begin_comment
comment|// TEST5: "-no-implicit-float"
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -S -mkernel -mno-soft-float %s 2>&1 | FileCheck -check-prefix=TEST6 %s
end_comment

begin_comment
comment|// TEST6-NOT: "-no-implicit-float"
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-darwin10 -### -S -mno-implicit-float %s 2>&1 | FileCheck -check-prefix=TEST7 %s
end_comment

begin_comment
comment|// TEST7: "-no-implicit-float"
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-darwin10 -### -S -mno-implicit-float -mimplicit-float %s 2>&1 | FileCheck -check-prefix=TEST8 %s
end_comment

begin_comment
comment|// TEST8-NOT: "-no-implicit-float"
end_comment

end_unit

