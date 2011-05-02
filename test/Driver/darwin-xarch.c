begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-apple-darwin10 -### \
end_comment

begin_comment
comment|// RUN:   -arch i386 -Xarch_i386 -mmacosx-version-min=10.4 \
end_comment

begin_comment
comment|// RUN:   -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 \
end_comment

begin_comment
comment|// RUN:   -c %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-COMPILE< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-COMPILE: clang{{.*}}" "-cc1" "-triple" "i386-apple-macosx10.4.0"
end_comment

begin_comment
comment|// CHECK-COMPILE: clang{{.*}}" "-cc1" "-triple" "x86_64-apple-macosx10.5.0"
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-apple-darwin10 -### \
end_comment

begin_comment
comment|// RUN:   -arch i386 -Xarch_i386 -Wl,-some-linker-arg -filelist X 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-LINK< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LINK: ld{{.*}} "-arch" "i386"{{.*}} "-some-linker-arg"
end_comment

end_unit

