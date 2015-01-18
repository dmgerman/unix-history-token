begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=undefined-trap -fsanitize-undefined-trap-on-error %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-TRAP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-undefined-trap-on-error -fsanitize=undefined-trap %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-TRAP
end_comment

begin_comment
comment|// CHECK-UNDEFINED-TRAP: "-fsanitize={{((signed-integer-overflow|integer-divide-by-zero|float-divide-by-zero|shift|unreachable|return|vla-bound|alignment|null|object-size|float-cast-overflow|array-bounds|enum|bool|returns-nonnull-attribute|nonnull-attribute),?){16}"}}
end_comment

begin_comment
comment|// CHECK-UNDEFINED-TRAP: "-fsanitize-undefined-trap-on-error"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=undefined %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED
end_comment

begin_comment
comment|// CHECK-UNDEFINED: "-fsanitize={{((signed-integer-overflow|integer-divide-by-zero|float-divide-by-zero|function|shift|unreachable|return|vla-bound|alignment|null|vptr|object-size|float-cast-overflow|array-bounds|enum|bool|returns-nonnull-attribute|nonnull-attribute),?){18}"}}
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -fsanitize=undefined %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-DARWIN
end_comment

begin_comment
comment|// CHECK-UNDEFINED-DARWIN: "-fsanitize={{((signed-integer-overflow|integer-divide-by-zero|float-divide-by-zero|shift|unreachable|return|vla-bound|alignment|null|vptr|object-size|float-cast-overflow|array-bounds|enum|bool|returns-nonnull-attribute|nonnull-attribute),?){17}"}}
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=integer %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-INTEGER
end_comment

begin_comment
comment|// CHECK-INTEGER: "-fsanitize={{((signed-integer-overflow|unsigned-integer-overflow|integer-divide-by-zero|shift),?){4}"}}
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
comment|// CHECK-PARTIAL-UNDEFINED: "-fsanitize={{((signed-integer-overflow|integer-divide-by-zero|float-divide-by-zero|function|shift|unreachable|return|vla-bound|alignment|null|object-size|array-bounds|returns-nonnull-attribute|nonnull-attribute),?){14}"}}
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=undefined -fsanitize-undefined-trap-on-error %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-TRAP-ON-ERROR-UNDEF
end_comment

begin_comment
comment|// CHECK-UNDEFINED-TRAP-ON-ERROR-UNDEF: '-fsanitize=undefined' not allowed with '-fsanitize-undefined-trap-on-error'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=vptr -fsanitize-undefined-trap-on-error %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-TRAP-ON-ERROR-VPTR
end_comment

begin_comment
comment|// CHECK-UNDEFINED-TRAP-ON-ERROR-VPTR: '-fsanitize=vptr' not allowed with '-fsanitize-undefined-trap-on-error'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=vptr -fno-rtti %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-VPTR-NO-RTTI
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=undefined -fno-rtti %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-VPTR-NO-RTTI
end_comment

begin_comment
comment|// CHECK-VPTR-NO-RTTI: '-fsanitize=vptr' not allowed with '-fno-rtti'
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
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-memory-track-origins -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ONLY-TRACK-ORIGINS
end_comment

begin_comment
comment|// CHECK-ONLY-TRACK-ORIGINS: warning: argument unused during compilation: '-fsanitize-memory-track-origins'
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
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACK-ORIGINS-1
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins=1 -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACK-ORIGINS-1
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins=2 -fsanitize-memory-track-origins -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACK-ORIGINS-1
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fno-sanitize-memory-track-origins -fsanitize-memory-track-origins -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACK-ORIGINS-1
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins=0 -fsanitize-memory-track-origins -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TRACK-ORIGINS-1
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
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=0 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-0
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address                       %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-0
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-0-NOT: fsanitize-coverage
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=1 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-1
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-coverage=1 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-1
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=leak -fsanitize-coverage=1 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-1
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=undefined -fsanitize-coverage=1 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-1
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=bool -fsanitize-coverage=1 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-1
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-1: fsanitize-coverage=1
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=4 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-4
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-4: fsanitize-coverage=4
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-coverage=5 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-5
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-5: error: invalid value '5' in '-fsanitize-coverage=5'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=thread   -fsanitize-coverage=1 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-UNUSED
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=dataflow -fsanitize-coverage=1 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-UNUSED
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu                     -fsanitize-coverage=1 %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SANITIZE-COVERAGE-UNUSED
end_comment

begin_comment
comment|// CHECK-SANITIZE-COVERAGE-UNUSED: argument unused during compilation: '-fsanitize-coverage=1'
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
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize=undefined -fno-sanitize-recover -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-RECOVER
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize=undefined -fno-sanitize-recover=all -fsanitize-recover=thread -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-RECOVER
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize=undefined -fno-sanitize-recover -fsanitize-recover=undefined -### 2>&1 | FileCheck %s --check-prefix=CHECK-RECOVER
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize=undefined -fsanitize-recover -fno-sanitize-recover -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-RECOVER
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize=undefined -fno-sanitize-recover=all -fsanitize-recover=object-size -### 2>&1 | FileCheck %s --check-prefix=CHECK-PARTIAL-RECOVER
end_comment

begin_comment
comment|// CHECK-RECOVER: "-fsanitize-recover={{((signed-integer-overflow|integer-divide-by-zero|float-divide-by-zero|function|shift|vla-bound|alignment|null|vptr|object-size|float-cast-overflow|array-bounds|enum|bool|returns-nonnull-attribute|nonnull-attribute),?){16}"}}
end_comment

begin_comment
comment|// CHECK-NO-RECOVER-NOT: sanitize-recover
end_comment

begin_comment
comment|// CHECK-PARTIAL-RECOVER: "-fsanitize-recover=object-size"
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

end_unit

