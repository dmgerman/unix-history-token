begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i386-apple-darwin10 -### -x assembler -c %s \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -static -dynamic 2>%t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=STATIC_AND_DYNAMIC-32 --input-file %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-STATIC_AND_DYNAMIC-32: as{{(.exe)?}}" "-arch" "i386" "-force_cpusubtype_ALL" "-static" "-o"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### -x assembler -c %s \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -static 2>%t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=STATIC-64 --input-file %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-STATIC-64: as{{(.exe)?}}" "-arch" "x86_64" "-force_cpusubtype_ALL" "-o"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### \
end_comment

begin_comment
comment|// RUN:   -arch armv6 -no-integrated-as -x assembler -c %s 2>%t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=ARMV6 --input-file %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ARMV6: as{{(.exe)?}}" "-arch" "armv6" "-o"
end_comment

end_unit

