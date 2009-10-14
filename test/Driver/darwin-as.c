begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -ccc-host-triple i386-apple-darwin10 -### -x assembler -c %s -static -dynamic 2>%t&&
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=STATIC_AND_DYNAMIC-32 --input-file %t %s&&
end_comment

begin_comment
comment|// CHECK-STATIC_AND_DYNAMIC-32: as{{(.exe)?}}" "-arch" "i386" "-force_cpusubtype_ALL" "-static" "-o"
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple x86_64-apple-darwin10 -### -x assembler -c %s -static 2>%t&&
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=STATIC-64 --input-file %t %s
end_comment

begin_comment
comment|// CHECK-STATIC-64: as{{(.exe)?}}" "-arch" "x86_64" "-force_cpusubtype_ALL" "-o"
end_comment

end_unit

