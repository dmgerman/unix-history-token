begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -no-canonical-prefixes -target wasm32-unknown-unknown -x assembler %s 2>&1 | FileCheck -check-prefix=AS_LINK %s
end_comment

begin_comment
comment|// AS_LINK: clang{{.*}}" "-cc1as" {{.*}} "-o" "[[temp:[^"]*]]"
end_comment

begin_comment
comment|// AS_LINK: lld{{.*}}" "-flavor" "ld" "[[temp]]" "-o" "a.out"
end_comment

end_unit

