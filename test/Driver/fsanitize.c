begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=undefined -fsanitize-trap=undefined %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-TRAP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=undefined -fsanitize-trap=undefined -fno-sanitize-trap=signed-integer-overflow %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-TRAP2
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=undefined -fsanitize-undefined-trap-on-error %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-TRAP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=undefined-trap -fsanitize-undefined-trap-on-error %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-TRAP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-undefined-trap-on-error -fsanitize=undefined-trap %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-TRAP
end_comment

begin_comment
comment|// CHECK-UNDEFINED-TRAP: "-fsanitize={{((signed-integer-overflow|integer-divide-by-zero|float-divide-by-zero|shift-base|shift-exponent|unreachable|return|vla-bound|alignment|null|object-size|float-cast-overflow|array-bounds|enum|bool|returns-nonnull-attribute|nonnull-attribute|function),?){18}"}}
end_comment

begin_comment
comment|// CHECK-UNDEFINED-TRAP: "-fsanitize-trap=alignment,array-bounds,bool,enum,float-cast-overflow,float-divide-by-zero,function,integer-divide-by-zero,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift-base,shift-exponent,signed-integer-overflow,unreachable,vla-bound"
end_comment

begin_comment
comment|// CHECK-UNDEFINED-TRAP2: "-fsanitize-trap=alignment,array-bounds,bool,enum,float-cast-overflow,float-divide-by-zero,function,integer-divide-by-zero,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift-base,shift-exponent,unreachable,vla-bound"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=undefined %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED
end_comment

begin_comment
comment|// CHECK-UNDEFINED: "-fsanitize={{((signed-integer-overflow|integer-divide-by-zero|float-divide-by-zero|function|shift-base|shift-exponent|unreachable|return|vla-bound|alignment|null|vptr|object-size|float-cast-overflow|array-bounds|enum|bool|returns-nonnull-attribute|nonnull-attribute),?){19}"}}
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -fsanitize=undefined %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-DARWIN
end_comment

begin_comment
comment|// CHECK-UNDEFINED-DARWIN: "-fsanitize={{((signed-integer-overflow|integer-divide-by-zero|float-divide-by-zero|shift-base|shift-exponent|unreachable|return|vla-bound|alignment|null|object-size|float-cast-overflow|array-bounds|enum|bool|returns-nonnull-attribute|nonnull-attribute),?){17}"}}
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-openbsd -fsanitize=undefined %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-OPENBSD
end_comment

begin_comment
comment|// CHECK-UNDEFINED-OPENBSD: "-fsanitize={{((signed-integer-overflow|integer-divide-by-zero|float-divide-by-zero|shift-base|shift-exponent|unreachable|return|vla-bound|alignment|null|object-size|float-cast-overflow|array-bounds|enum|bool|returns-nonnull-attribute|nonnull-attribute),?){17}"}}
end_comment

begin_comment
comment|// RUN: %clang -target i386-pc-win32 -fsanitize=undefined %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-WIN --check-prefix=CHECK-UNDEFINED-WIN32
end_comment

begin_comment
comment|// RUN: %clang -target i386-pc-win32 -fsanitize=undefined -x c++ %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-WIN --check-prefix=CHECK-UNDEFINED-WIN32 --check-prefix=CHECK-UNDEFINED-WIN-CXX
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-win32 -fsanitize=undefined %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-WIN --check-prefix=CHECK-UNDEFINED-WIN64
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-win32 -fsanitize=undefined -x c++ %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-WIN --check-prefix=CHECK-UNDEFINED-WIN64 --check-prefix=CHECK-UNDEFINED-WIN-CXX
end_comment

begin_comment
comment|// CHECK-UNDEFINED-WIN: "-fsanitize={{((signed-integer-overflow|integer-divide-by-zero|float-divide-by-zero|shift-base|shift-exponent|unreachable|return|vla-bound|alignment|null|object-size|float-cast-overflow|array-bounds|enum|bool|returns-nonnull-attribute|nonnull-attribute),?){17}"}}
end_comment

begin_comment
comment|// CHECK-UNDEFINED-WIN32-SAME: "--dependent-lib={{[^"]*}}ubsan_standalone-i386.lib"
end_comment

begin_comment
comment|// CHECK-UNDEFINED-WIN64-SAME: "--dependent-lib={{[^"]*}}ubsan_standalone-x86_64.lib"
end_comment

begin_comment
comment|// CHECK-UNDEFINED-WIN-CXX-SAME: "--dependent-lib={{[^"]*}}ubsan_standalone_cxx{{[^"]*}}.lib"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=integer %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-INTEGER
end_comment

begin_comment
comment|// CHECK-INTEGER: "-fsanitize={{((signed-integer-overflow|unsigned-integer-overflow|integer-divide-by-zero|shift-base|shift-exponent),?){5}"}}
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=bounds -### -fsyntax-only %s 2>&1 | FileCheck %s --check-prefix=CHECK-BOUNDS
end_comment

begin_comment
comment|// CHECK-BOUNDS: "-fsanitize={{((array-bounds|local-bounds),?){2}"}}
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=all %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-FSANITIZE-ALL
end_comment

begin_comment
comment|// CHECK-FSANITIZE-ALL: error: unsupported argument 'all' to option 'fsanitize='
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address,undefined -fno-sanitize=all -fsanitize=thread %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-FNO-SANITIZE-ALL
end_comment

begin_comment
comment|// CHECK-FNO-SANITIZE-ALL: "-fsanitize=thread"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=thread,undefined -fno-sanitize=thread -fno-sanitize=float-cast-overflow,vptr,bool,enum %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-PARTIAL-UNDEFINED
end_comment

begin_comment
comment|// CHECK-PARTIAL-UNDEFINED: "-fsanitize={{((signed-integer-overflow|integer-divide-by-zero|float-divide-by-zero|function|shift-base|shift-exponent|unreachable|return|vla-bound|alignment|null|object-size|array-bounds|returns-nonnull-attribute|nonnull-attribute),?){15}"}}
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=shift -fno-sanitize=shift-base %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-FSANITIZE-SHIFT-PARTIAL
end_comment

begin_comment
comment|// CHECK-FSANITIZE-SHIFT-PARTIAL: "-fsanitize=shift-exponent"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=vptr -fsanitize-trap=undefined %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-VPTR-TRAP-UNDEF
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=vptr -fsanitize-undefined-trap-on-error %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-VPTR-TRAP-UNDEF
end_comment

begin_comment
comment|// CHECK-VPTR-TRAP-UNDEF: error: invalid argument '-fsanitize=vptr' not allowed with '-fsanitize-trap=undefined'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=vptr -fno-rtti %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-VPTR-NO-RTTI
end_comment

begin_comment
comment|// CHECK-VPTR-NO-RTTI: '-fsanitize=vptr' not allowed with '-fno-rtti'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=undefined -fno-rtti %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-NO-RTTI
end_comment

begin_comment
comment|// CHECK-UNDEFINED-NO-RTTI-NOT: vptr
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address,thread -fno-rtti %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANA-SANT
end_comment

begin_comment
comment|// CHECK-SANA-SANT: '-fsanitize=address' not allowed with '-fsanitize=thread'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address,memory -pie -fno-rtti %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANA-SANM
end_comment

begin_comment
comment|// CHECK-SANA-SANM: '-fsanitize=address' not allowed with '-fsanitize=memory'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=thread,memory -pie -fno-rtti %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANT-SANM
end_comment

begin_comment
comment|// CHECK-SANT-SANM: '-fsanitize=thread' not allowed with '-fsanitize=memory'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory,thread -pie -fno-rtti %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANM-SANT
end_comment

begin_comment
comment|// CHECK-SANM-SANT: '-fsanitize=thread' not allowed with '-fsanitize=memory'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=leak,thread -pie -fno-rtti %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANL-SANT
end_comment

begin_comment
comment|// CHECK-SANL-SANT: '-fsanitize=leak' not allowed with '-fsanitize=thread'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=leak,memory -pie -fno-rtti %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANL-SANM
end_comment

begin_comment
comment|// CHECK-SANL-SANM: '-fsanitize=leak' not allowed with '-fsanitize=memory'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=kernel-address,thread -fno-rtti %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANKA-SANT
end_comment

begin_comment
comment|// CHECK-SANKA-SANT: '-fsanitize=kernel-address' not allowed with '-fsanitize=thread'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=kernel-address,memory -pie -fno-rtti %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANKA-SANM
end_comment

begin_comment
comment|// CHECK-SANKA-SANM: '-fsanitize=kernel-address' not allowed with '-fsanitize=memory'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=kernel-address,address -fno-rtti %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANKA-SANA
end_comment

begin_comment
comment|// CHECK-SANKA-SANA: '-fsanitize=kernel-address' not allowed with '-fsanitize=address'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=kernel-address,leak -pie -fno-rtti %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANKA-SANL
end_comment

begin_comment
comment|// CHECK-SANKA-SANL: '-fsanitize=kernel-address' not allowed with '-fsanitize=leak'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-memory-track-origins -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ONLY-TRACK-ORIGINS
end_comment

begin_comment
comment|// CHECK-ONLY-TRACK-ORIGINS: warning: argument unused during compilation: '-fsanitize-memory-track-origins'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fno-sanitize=memory -fsanitize-memory-track-origins -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACK-ORIGINS-DISABLED-MSAN
end_comment

begin_comment
comment|// CHECK-TRACK-ORIGINS-DISABLED-MSAN-NOT: warning: argument unused
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-EXTRA-TRACK-ORIGINS
end_comment

begin_comment
comment|// CHECK-NO-EXTRA-TRACK-ORIGINS-NOT: "-fsanitize-memory-track-origins"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize=alignment -fsanitize=vptr -fno-sanitize=vptr %s -### 2>&1
end_comment

begin_comment
comment|// OK
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -pie %s -### 2>&1
end_comment

begin_comment
comment|// OK
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACK-ORIGINS-2
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins=1 -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACK-ORIGINS-1
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins=1 -fsanitize-memory-track-origins -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACK-ORIGINS-2
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins=2 -fsanitize-memory-track-origins -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACK-ORIGINS-2
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fno-sanitize-memory-track-origins -fsanitize-memory-track-origins -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACK-ORIGINS-2
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins=0 -fsanitize-memory-track-origins=1 -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACK-ORIGINS-1
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins=0 -fsanitize-memory-track-origins -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACK-ORIGINS-2
end_comment

begin_comment
comment|// CHECK-TRACK-ORIGINS-1: -fsanitize-memory-track-origins=1
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fno-sanitize-memory-track-origins -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-TRACK-ORIGINS
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins=0 -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-TRACK-ORIGINS
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins -fno-sanitize-memory-track-origins -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-TRACK-ORIGINS
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins -fsanitize-memory-track-origins=0 -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-TRACK-ORIGINS
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins=2 -fno-sanitize-memory-track-origins -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-TRACK-ORIGINS
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins=2 -fsanitize-memory-track-origins=0 -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-TRACK-ORIGINS
end_comment

begin_comment
comment|// CHECK-NO-TRACK-ORIGINS-NOT: sanitize-memory-track-origins
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins=2 -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACK-ORIGINS-2
end_comment

begin_comment
comment|// CHECK-TRACK-ORIGINS-2: -fsanitize-memory-track-origins=2
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins=3 -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACK-ORIGINS-3
end_comment

begin_comment
comment|// CHECK-TRACK-ORIGINS-3: error: invalid value '3' in '-fsanitize-memory-track-origins=3'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-use-after-dtor -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-MSAN-USE-AFTER-DTOR
end_comment

begin_comment
comment|// CHECK-MSAN-USE-AFTER-DTOR: -cc1{{.*}}-fsanitize-memory-use-after-dtor
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-address-field-padding=0 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ASAN-FIELD-PADDING-0
end_comment

begin_comment
comment|// CHECK-ASAN-FIELD-PADDING-0-NOT: -fsanitize-address-field-padding
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-address-field-padding=1 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ASAN-FIELD-PADDING-1
end_comment

begin_comment
comment|// CHECK-ASAN-FIELD-PADDING-1: -fsanitize-address-field-padding=1
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-address-field-padding=2 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ASAN-FIELD-PADDING-2
end_comment

begin_comment
comment|// CHECK-ASAN-FIELD-PADDING-2: -fsanitize-address-field-padding=2
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-address-field-padding=3 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ASAN-FIELD-PADDING-3
end_comment

begin_comment
comment|// CHECK-ASAN-FIELD-PADDING-3: error: invalid value '3' in '-fsanitize-address-field-padding=3'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-address-field-padding=2 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ASAN-FIELD-PADDING-NO-ASAN
end_comment

begin_comment
comment|// CHECK-ASAN-FIELD-PADDING-NO-ASAN: warning: argument unused during compilation: '-fsanitize-address-field-padding=2'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-address-field-padding=2 -fsanitize=address -fno-sanitize=address %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ASAN-FIELD-PADDING-DISABLED-ASAN
end_comment

begin_comment
comment|// CHECK-ASAN-FIELD-PADDING-DISABLED-ASAN-NOT: warning: argument unused
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=vptr -fno-sanitize=vptr -fsanitize=undefined,address %s -### 2>&1
end_comment

begin_comment
comment|// OK
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=thread %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TSAN-NO-PIE
end_comment

begin_comment
comment|// CHECK-TSAN-NO-PIE: "-mrelocation-model" "static"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-MSAN-NO-PIE
end_comment

begin_comment
comment|// CHECK-MSAN-NO-PIE: "-mrelocation-model" "pic" "-pic-level" "2" "-pie-level" "2"
end_comment

begin_comment
comment|// CHECK-MSAN-NO-PIE: "-pie"
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-androideabi -fsanitize=address %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ANDROID-ASAN-NO-PIE
end_comment

begin_comment
comment|// CHECK-ANDROID-ASAN-NO-PIE: "-mrelocation-model" "pic" "-pic-level" "2" "-pie-level" "2"
end_comment

begin_comment
comment|// CHECK-ANDROID-ASAN-NO-PIE: "-pie"
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-androideabi %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ANDROID-NO-ASAN
end_comment

begin_comment
comment|// CHECK-ANDROID-NO-ASAN: "-mrelocation-model" "pic"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize=undefined -### 2>&1 | FileCheck %s --check-prefix=CHECK-RECOVER
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize=undefined -fsanitize-recover -### 2>&1 | FileCheck %s --check-prefix=CHECK-RECOVER
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize=undefined -fsanitize-recover=all -### 2>&1 | FileCheck %s --check-prefix=CHECK-RECOVER
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize=undefined -fno-sanitize-recover=undefined -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-RECOVER
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize=undefined -fno-sanitize-recover=all -fsanitize-recover=thread -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-RECOVER
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize=undefined -fno-sanitize-recover -fsanitize-recover=undefined -### 2>&1 | FileCheck %s --check-prefix=CHECK-RECOVER
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize=undefined -fsanitize-recover=all -fno-sanitize-recover=undefined -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-RECOVER
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize=undefined -fno-sanitize-recover=all -fsanitize-recover=object-size,shift-base -### 2>&1 | FileCheck %s --check-prefix=CHECK-PARTIAL-RECOVER
end_comment

begin_comment
comment|// CHECK-RECOVER: "-fsanitize-recover={{((signed-integer-overflow|integer-divide-by-zero|float-divide-by-zero|function|shift-base|shift-exponent|vla-bound|alignment|null|vptr|object-size|float-cast-overflow|array-bounds|enum|bool|returns-nonnull-attribute|nonnull-attribute),?){17}"}}
end_comment

begin_comment
comment|// CHECK-NO-RECOVER-NOT: sanitize-recover
end_comment

begin_comment
comment|// CHECK-PARTIAL-RECOVER: "-fsanitize-recover={{((object-size|shift-base),?){2}"}}
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize=undefined -fsanitize-recover=address,foobar,object-size,unreachable -### 2>&1 | FileCheck %s --check-prefix=CHECK-DIAG-RECOVER
end_comment

begin_comment
comment|// CHECK-DIAG-RECOVER: unsupported argument 'foobar' to option 'fsanitize-recover='
end_comment

begin_comment
comment|// CHECK-DIAG-RECOVER: unsupported argument 'address,unreachable' to option 'fsanitize-recover='
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize=undefined -fsanitize-recover -fno-sanitize-recover -### 2>&1 | FileCheck %s --check-prefix=CHECK-DEPRECATED-RECOVER
end_comment

begin_comment
comment|// CHECK-DEPRECATED-RECOVER: argument '-fsanitize-recover' is deprecated, use '-fsanitize-recover=undefined,integer' instead
end_comment

begin_comment
comment|// CHECK-DEPRECATED-RECOVER: argument '-fno-sanitize-recover' is deprecated, use '-fno-sanitize-recover=undefined,integer' instead
end_comment

begin_comment
comment|// CHECK-DEPRECATED-RECOVER-NOT: is deprecated
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=leak %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANL
end_comment

begin_comment
comment|// CHECK-SANL: "-fsanitize=leak"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address,leak -fno-sanitize=address %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANA-SANL-NO-SANA
end_comment

begin_comment
comment|// CHECK-SANA-SANL-NO-SANA: "-fsanitize=leak"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-MSAN
end_comment

begin_comment
comment|// CHECK-MSAN: "-fno-assume-sane-operator-new"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ASAN
end_comment

begin_comment
comment|// CHECK-ASAN: "-fno-assume-sane-operator-new"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=zzz %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-DIAG1
end_comment

begin_comment
comment|// CHECK-DIAG1: unsupported argument 'zzz' to option 'fsanitize='
end_comment

begin_comment
comment|// CHECK-DIAG1-NOT: unsupported argument 'zzz' to option 'fsanitize='
end_comment

begin_comment
comment|// RUN: %clang -target i686-linux-gnu -fsanitize=memory %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-MSAN-X86
end_comment

begin_comment
comment|// CHECK-MSAN-X86: error: unsupported option '-fsanitize=memory' for target 'i686--linux-gnu'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -fsanitize=memory %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-MSAN-DARWIN
end_comment

begin_comment
comment|// CHECK-MSAN-DARWIN: unsupported option '-fsanitize=memory' for target 'x86_64-apple-darwin10'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -fsanitize=memory -fno-sanitize=memory %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-MSAN-NOMSAN-DARWIN
end_comment

begin_comment
comment|// CHECK-MSAN-NOMSAN-DARWIN-NOT: unsupported option
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -fsanitize=memory -fsanitize=thread,memory %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-MSAN-TSAN-MSAN-DARWIN
end_comment

begin_comment
comment|// CHECK-MSAN-TSAN-MSAN-DARWIN: unsupported option '-fsanitize=thread,memory' for target 'x86_64-apple-darwin10'
end_comment

begin_comment
comment|// CHECK-MSAN-TSAN-MSAN-DARWIN-NOT: unsupported option
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -fsanitize=thread,memory -fsanitize=memory %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TSAN-MSAN-MSAN-DARWIN
end_comment

begin_comment
comment|// CHECK-TSAN-MSAN-MSAN-DARWIN: unsupported option '-fsanitize=memory' for target 'x86_64-apple-darwin10'
end_comment

begin_comment
comment|// CHECK-TSAN-MSAN-MSAN-DARWIN: unsupported option '-fsanitize=thread' for target 'x86_64-apple-darwin10'
end_comment

begin_comment
comment|// CHECK-TSAN-MSAN-MSAN-DARWIN-NOT: unsupported option
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -fsanitize=function %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-FSAN-DARWIN
end_comment

begin_comment
comment|// CHECK-FSAN-DARWIN: unsupported option '-fsanitize=function' for target 'x86_64-apple-darwin10'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -fsanitize=function -fsanitize=undefined %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-FSAN-UBSAN-DARWIN
end_comment

begin_comment
comment|// CHECK-FSAN-UBSAN-DARWIN: unsupported option '-fsanitize=function' for target 'x86_64-apple-darwin10'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -mmacosx-version-min=10.8 -fsanitize=vptr %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-VPTR-DARWIN-OLD
end_comment

begin_comment
comment|// CHECK-VPTR-DARWIN-OLD: unsupported option '-fsanitize=vptr' for target 'x86_64-apple-darwin10'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -mmacosx-version-min=10.9 -fsanitize=alignment,vptr %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-VPTR-DARWIN-NEW
end_comment

begin_comment
comment|// CHECK-VPTR-DARWIN-NEW: -fsanitize=alignment,vptr
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-ios7 -miphoneos-version-min=7.0 -fsanitize=address %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ASAN-IOS
end_comment

begin_comment
comment|// CHECK-ASAN-IOS: unsupported option '-fsanitize=address' for target 'arm-apple-ios7'
end_comment

begin_comment
comment|// RUN: %clang -target i386-pc-openbsd -fsanitize=address %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ASAN-OPENBSD
end_comment

begin_comment
comment|// CHECK-ASAN-OPENBSD: unsupported option '-fsanitize=address' for target 'i386-pc-openbsd'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=cfi -flto -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CFI
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=cfi-derived-cast -flto -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CFI-DCAST
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=cfi-unrelated-cast -flto -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CFI-UCAST
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -flto -fsanitize=cfi-nvcall -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CFI-NVCALL
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -flto -fsanitize=cfi-vcall -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CFI-VCALL
end_comment

begin_comment
comment|// CHECK-CFI: -emit-llvm-bc{{.*}}-fsanitize=cfi-derived-cast,cfi-unrelated-cast,cfi-nvcall,cfi-vcall
end_comment

begin_comment
comment|// CHECK-CFI-DCAST: -emit-llvm-bc{{.*}}-fsanitize=cfi-derived-cast
end_comment

begin_comment
comment|// CHECK-CFI-UCAST: -emit-llvm-bc{{.*}}-fsanitize=cfi-unrelated-cast
end_comment

begin_comment
comment|// CHECK-CFI-NVCALL: -emit-llvm-bc{{.*}}-fsanitize=cfi-nvcall
end_comment

begin_comment
comment|// CHECK-CFI-VCALL: -emit-llvm-bc{{.*}}-fsanitize=cfi-vcall
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -flto -fsanitize=cfi-derived-cast -fno-lto -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CFI-NOLTO
end_comment

begin_comment
comment|// CHECK-CFI-NOLTO: '-fsanitize=cfi-derived-cast' only allowed with '-flto'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-trap=address -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ASAN-TRAP
end_comment

begin_comment
comment|// CHECK-ASAN-TRAP: error: unsupported argument 'address' to option '-fsanitize-trap'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -mmacosx-version-min=10.7 -flto -fsanitize=cfi-vcall -fno-sanitize-trap=cfi -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CFI-NOTRAP-OLD-MACOS
end_comment

begin_comment
comment|// CHECK-CFI-NOTRAP-OLD-MACOS: error: unsupported option '-fno-sanitize-trap=cfi-vcall' for target 'x86_64-apple-darwin10'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-win32 -flto -fsanitize=cfi-vcall -fno-sanitize-trap=cfi -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CFI-NOTRAP-WIN
end_comment

begin_comment
comment|// CHECK-CFI-NOTRAP-WIN: -emit-llvm-bc
end_comment

begin_comment
comment|// CHECK-CFI-NOTRAP-WIN-NOT: -fsanitize-trap=cfi
end_comment

begin_comment
comment|// RUN: %clang_cl -fsanitize=address -c -MDd -### -- %s 2>&1 | FileCheck %s -check-prefix=CHECK-ASAN-DEBUGRTL
end_comment

begin_comment
comment|// RUN: %clang_cl -fsanitize=address -c -MTd -### -- %s 2>&1 | FileCheck %s -check-prefix=CHECK-ASAN-DEBUGRTL
end_comment

begin_comment
comment|// RUN: %clang_cl -fsanitize=address -c -LDd -### -- %s 2>&1 | FileCheck %s -check-prefix=CHECK-ASAN-DEBUGRTL
end_comment

begin_comment
comment|// RUN: %clang_cl -fsanitize=address -c -MD -MDd -### -- %s 2>&1 | FileCheck %s -check-prefix=CHECK-ASAN-DEBUGRTL
end_comment

begin_comment
comment|// RUN: %clang_cl -fsanitize=address -c -MT -MTd -### -- %s 2>&1 | FileCheck %s -check-prefix=CHECK-ASAN-DEBUGRTL
end_comment

begin_comment
comment|// RUN: %clang_cl -fsanitize=address -c -LD -LDd -### -- %s 2>&1 | FileCheck %s -check-prefix=CHECK-ASAN-DEBUGRTL
end_comment

begin_comment
comment|// CHECK-ASAN-DEBUGRTL: error: invalid argument
end_comment

begin_comment
comment|// CHECK-ASAN-DEBUGRTL: not allowed with '-fsanitize=address'
end_comment

begin_comment
comment|// CHECK-ASAN-DEBUGRTL: note: AddressSanitizer doesn't support linking with debug runtime libraries yet
end_comment

begin_comment
comment|// RUN: %clang_cl -fsanitize=address -c -MT -### -- %s 2>&1 | FileCheck %s -check-prefix=CHECK-ASAN-RELEASERTL
end_comment

begin_comment
comment|// RUN: %clang_cl -fsanitize=address -c -MD -### -- %s 2>&1 | FileCheck %s -check-prefix=CHECK-ASAN-RELEASERTL
end_comment

begin_comment
comment|// RUN: %clang_cl -fsanitize=address -c -LD -### -- %s 2>&1 | FileCheck %s -check-prefix=CHECK-ASAN-RELEASERTL
end_comment

begin_comment
comment|// RUN: %clang_cl -fsanitize=address -c -MTd -MT -### -- %s 2>&1 | FileCheck %s -check-prefix=CHECK-ASAN-RELEASERTL
end_comment

begin_comment
comment|// RUN: %clang_cl -fsanitize=address -c -MDd -MD -### -- %s 2>&1 | FileCheck %s -check-prefix=CHECK-ASAN-RELEASERTL
end_comment

begin_comment
comment|// RUN: %clang_cl -fsanitize=address -c -LDd -LD -### -- %s 2>&1 | FileCheck %s -check-prefix=CHECK-ASAN-RELEASERTL
end_comment

begin_comment
comment|// CHECK-ASAN-RELEASERTL-NOT: error: invalid argument
end_comment

begin_comment
comment|// RUN: %clang -fno-sanitize=safe-stack -### %s 2>&1 | FileCheck %s -check-prefix=NOSP
end_comment

begin_comment
comment|// NOSP-NOT: "-fsanitize=safe-stack"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=safe-stack -### %s 2>&1 | FileCheck %s -check-prefix=SP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address,safe-stack -### %s 2>&1 | FileCheck %s -check-prefix=SP-ASAN
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fstack-protector -fsanitize=safe-stack -### %s 2>&1 | FileCheck %s -check-prefix=SP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=safe-stack -fstack-protector-all -### %s 2>&1 | FileCheck %s -check-prefix=SP
end_comment

begin_comment
comment|// SP-NOT: stack-protector
end_comment

begin_comment
comment|// SP: "-fsanitize=safe-stack"
end_comment

begin_comment
comment|// SP-ASAN-NOT: stack-protector
end_comment

begin_comment
comment|// SP-ASAN: "-fsanitize=address,safe-stack"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu -fsanitize=memory %s -### 2>&1 | FileCheck %s -check-prefix=CHECK-SANM
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64le-unknown-linux-gnu -fsanitize=memory %s -### 2>&1 | FileCheck %s -check-prefix=CHECK-SANM
end_comment

begin_comment
comment|// CHECK-SANM: "-fsanitize=memory"
end_comment

end_unit

