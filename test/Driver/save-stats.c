begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -save-stats %s -### 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -save-stats=cwd %s -### 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-stats-file=save-stats.stats"
end_comment

begin_comment
comment|// CHECK: "{{.*}}save-stats.c"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -S %s -### 2>&1 | FileCheck %s -check-prefix=NO-STATS
end_comment

begin_comment
comment|// NO-STATS-NO: -stats-file
end_comment

begin_comment
comment|// NO-STATS: "{{.*}}save-stats.c"
end_comment

begin_comment
comment|// NO-STATS-NO: -stats-file
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -save-stats=obj -c -o obj/dir/save-stats.o %s -### 2>&1 | FileCheck %s -check-prefix=CHECK-OBJ
end_comment

begin_comment
comment|// CHECK-OBJ: "-stats-file=obj/dir{{/|\\\\}}save-stats.stats"
end_comment

begin_comment
comment|// CHECK-OBJ: "-o" "obj/dir{{/|\\\\}}save-stats.o"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -save-stats=obj -c %s -### 2>&1 | FileCheck %s -check-prefix=CHECK-OBJ-NOO
end_comment

begin_comment
comment|// CHECK-OBJ-NOO: "-stats-file=save-stats.stats"
end_comment

begin_comment
comment|// CHECK-OBJ-NOO: "-o" "save-stats.o"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -save-stats=bla -c %s -### 2>&1 | FileCheck %s -check-prefix=CHECK-INVALID
end_comment

begin_comment
comment|// CHECK-INVALID: invalid value 'bla' in '-save-stats=bla'
end_comment

end_unit

