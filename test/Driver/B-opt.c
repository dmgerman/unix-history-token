begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check -B driver option.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -B %S/Inputs/B_opt_tree/dir1 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-B-OPT-TRIPLE %s
end_comment

begin_comment
comment|// CHECK-B-OPT-TRIPLE: "{{.*}}/Inputs/B_opt_tree/dir1{{/|\\\\}}i386-unknown-linux-ld"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -B %S/Inputs/B_opt_tree/dir2 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-B-OPT-DIR %s
end_comment

begin_comment
comment|// CHECK-B-OPT-DIR: "{{.*}}/Inputs/B_opt_tree/dir2{{/|\\\\}}ld"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -B %S/Inputs/B_opt_tree/dir3/prefix- 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-B-OPT-PREFIX %s
end_comment

begin_comment
comment|// CHECK-B-OPT-PREFIX: "{{.*}}/Inputs/B_opt_tree/dir3{{/|\\\\}}prefix-ld"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -B %S/Inputs/B_opt_tree/dir3/prefix- \
end_comment

begin_comment
comment|// RUN:     -B %S/Inputs/B_opt_tree/dir2 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-B-OPT-MULT %s
end_comment

begin_comment
comment|// CHECK-B-OPT-MULT: "{{.*}}/Inputs/B_opt_tree/dir3{{/|\\\\}}prefix-ld"
end_comment

end_unit

