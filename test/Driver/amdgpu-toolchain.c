begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -target amdgcn--amdhsa -x assembler -mcpu=kaveri %s 2>&1 | FileCheck -check-prefix=AS_LINK %s
end_comment

begin_comment
comment|// AS_LINK: clang{{.*}} "-cc1as"
end_comment

begin_comment
comment|// AS_LINK: ld.lld{{.*}} "-shared"
end_comment

begin_comment
comment|// RUN: %clang -### -g -target amdgcn--amdhsa -mcpu=kaveri %s 2>&1 | FileCheck -check-prefix=DWARF_VER %s
end_comment

begin_comment
comment|// DWARF_VER: "-dwarf-version=2"
end_comment

end_unit

