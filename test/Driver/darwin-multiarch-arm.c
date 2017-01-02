begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that we compile correctly with multiple ARM -arch options.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target arm7-apple-darwin10 -### \
end_comment

begin_comment
comment|// RUN:   -arch armv7 -arch armv7s %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-cc1" "-triple" "thumbv7-apple-ios5.0.0"
end_comment

begin_comment
comment|// CHECK-SAME: "-o" "[[CC_OUT1:[^"]*]]"
end_comment

begin_comment
comment|// CHECK:ld{{(\.exe)?}}" {{.*}} "-o" "[[LD_OUT1:[^"]*]]" {{.*}} "[[CC_OUT1]]"
end_comment

begin_comment
comment|// CHECK:"-cc1" "-triple" "thumbv7s-apple-ios5.0.0"
end_comment

begin_comment
comment|// CHECK-SAME: "-o" "[[CC_OUT2:[^"]*]]"
end_comment

begin_comment
comment|// CHECK:ld{{(\.exe)?}}" {{.*}} "-o" "[[LD_OUT2:[^"]*]]" {{.*}} "[[CC_OUT2]]"
end_comment

begin_comment
comment|// CHECK:lipo{{(\.exe)?}}"
end_comment

begin_comment
comment|// CHECK-DAG: "[[LD_OUT1]]"
end_comment

begin_comment
comment|// CHECK-DAG: "[[LD_OUT2]]"
end_comment

end_unit

