begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// A basic clang -cc1 command-line. WebAssembly is somewhat special in
end_comment

begin_comment
comment|// enabling -ffunction-sections, -fdata-sections, and -fvisibility=hidden by
end_comment

begin_comment
comment|// default.
end_comment

begin_comment
comment|// RUN: %clang %s -### -no-canonical-prefixes -target wasm32-unknown-unknown 2>&1 | FileCheck -check-prefix=CC1 %s
end_comment

begin_comment
comment|// CC1: clang{{.*}} "-cc1" "-triple" "wasm32-unknown-unknown" {{.*}} "-fvisibility" "hidden" {{.*}} "-ffunction-sections" "-fdata-sections"
end_comment

begin_comment
comment|// Ditto, but ensure that a user -fno-function-sections disables the
end_comment

begin_comment
comment|// default -ffunction-sections.
end_comment

begin_comment
comment|// RUN: %clang %s -### -target wasm32-unknown-unknown -fno-function-sections 2>&1 | FileCheck -check-prefix=NO_FUNCTION_SECTIONS %s
end_comment

begin_comment
comment|// NO_FUNCTION_SECTIONS-NOT: function-sections
end_comment

begin_comment
comment|// Ditto, but ensure that a user -fno-data-sections disables the
end_comment

begin_comment
comment|// default -fdata-sections.
end_comment

begin_comment
comment|// RUN: %clang %s -### -target wasm32-unknown-unknown -fno-data-sections 2>&1 | FileCheck -check-prefix=NO_DATA_SECTIONS %s
end_comment

begin_comment
comment|// NO_DATA_SECTIONS-NOT: data-sections
end_comment

begin_comment
comment|// Ditto, but ensure that a user -fvisibility=default disables the default
end_comment

begin_comment
comment|// -fvisibility=hidden.
end_comment

begin_comment
comment|// RUN: %clang %s -### -target wasm32-unknown-unknown -fvisibility=default 2>&1 | FileCheck -check-prefix=FVISIBILITY_DEFAULT %s
end_comment

begin_comment
comment|// FVISIBILITY_DEFAULT-NOT: hidden
end_comment

begin_comment
comment|// A basic C link command-line.
end_comment

begin_comment
comment|// RUN: %clang -### -no-canonical-prefixes -target wasm32-unknown-unknown --sysroot=/foo %s 2>&1 | FileCheck -check-prefix=LINK %s
end_comment

begin_comment
comment|// LINK: clang{{.*}}" "-cc1" {{.*}} "-o" "[[temp:[^"]*]]"
end_comment

begin_comment
comment|// LINK: lld{{.*}}" "-flavor" "wasm" "-L/foo/lib32" "crt1.o" "crti.o" "[[temp]]" "-lc" "-lcompiler_rt" "crtn.o" "-o" "a.out"
end_comment

begin_comment
comment|// A basic C link command-line with optimization. WebAssembly is somewhat
end_comment

begin_comment
comment|// special in enabling --gc-sections by default.
end_comment

begin_comment
comment|// RUN: %clang -### -O2 -no-canonical-prefixes -target wasm32-unknown-unknown --sysroot=/foo %s 2>&1 | FileCheck -check-prefix=LINK_OPT %s
end_comment

begin_comment
comment|// LINK_OPT: clang{{.*}}" "-cc1" {{.*}} "-o" "[[temp:[^"]*]]"
end_comment

begin_comment
comment|// LINK_OPT: lld{{.*}}" "-flavor" "wasm" "--gc-sections" "-L/foo/lib32" "crt1.o" "crti.o" "[[temp]]" "-lc" "-lcompiler_rt" "crtn.o" "-o" "a.out"
end_comment

begin_comment
comment|// Ditto, but ensure that a user --no-gc-sections comes after the
end_comment

begin_comment
comment|// default --gc-sections.
end_comment

begin_comment
comment|// RUN: %clang -### -O2 -no-canonical-prefixes -target wasm32-unknown-unknown --sysroot=/foo -Wl,--no-gc-sections %s 2>&1 | FileCheck -check-prefix=NO_GC_SECTIONS %s
end_comment

begin_comment
comment|// NO_GC_SECTIONS: clang{{.*}}" "-cc1" {{.*}} "-o" "[[temp:[^"]*]]"
end_comment

begin_comment
comment|// NO_GC_SECTIONS: lld{{.*}}" "-flavor" "wasm" "--gc-sections" "-L/foo/lib32" "crt1.o" "crti.o" "--no-gc-sections" "[[temp]]" "-lc" "-lcompiler_rt" "crtn.o" "-o" "a.out"
end_comment

end_unit

