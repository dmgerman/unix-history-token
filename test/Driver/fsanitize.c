begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fcatch-undefined-behavior %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-TRAP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=undefined-trap -fsanitize-undefined-trap-on-error %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-TRAP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-undefined-trap-on-error -fsanitize=undefined-trap %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-TRAP
end_comment

begin_comment
comment|// CHECK-UNDEFINED-TRAP: "-fsanitize={{((signed-integer-overflow|integer-divide-by-zero|float-divide-by-zero|shift|unreachable|return|vla-bound|alignment|null|object-size|float-cast-overflow|array-bounds|enum|bool),?){14}"}}
end_comment

begin_comment
comment|// CHECK-UNDEFINED-TRAP: "-fsanitize-undefined-trap-on-error"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=undefined %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED
end_comment

begin_comment
comment|// CHECK-UNDEFINED: "-fsanitize={{((signed-integer-overflow|integer-divide-by-zero|float-divide-by-zero|function|shift|unreachable|return|vla-bound|alignment|null|vptr|object-size|float-cast-overflow|array-bounds|enum|bool),?){16}"}}
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -fsanitize=undefined %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-DARWIN
end_comment

begin_comment
comment|// CHECK-UNDEFINED-DARWIN: "-fsanitize={{((signed-integer-overflow|integer-divide-by-zero|float-divide-by-zero|shift|unreachable|return|vla-bound|alignment|null|vptr|object-size|float-cast-overflow|array-bounds|enum|bool),?){15}"}}
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=integer %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-INTEGER
end_comment

begin_comment
comment|// CHECK-INTEGER: "-fsanitize={{((signed-integer-overflow|unsigned-integer-overflow|integer-divide-by-zero|shift),?){4}"}}
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=thread,undefined -fno-thread-sanitizer -fno-sanitize=float-cast-overflow,vptr,bool,enum %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-PARTIAL-UNDEFINED
end_comment

begin_comment
comment|// CHECK-PARTIAL-UNDEFINED: "-fsanitize={{((signed-integer-overflow|integer-divide-by-zero|float-divide-by-zero|function|shift|unreachable|return|vla-bound|alignment|null|object-size|array-bounds),?){12}"}}
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address-full %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ASAN-FULL
end_comment

begin_comment
comment|// CHECK-ASAN-FULL: "-fsanitize={{((address|init-order|use-after-return|use-after-scope),?){4}"}}
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fno-sanitize=init-order,use-after-return -fsanitize=address %s -### 2>&1 |  FileCheck %s --check-prefix=CHECK-ASAN-IMPLIED-INIT-ORDER-UAR
end_comment

begin_comment
comment|// CHECK-ASAN-IMPLIED-INIT-ORDER-UAR: "-fsanitize={{((address|init-order|use-after-return),?){3}"}}
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fno-sanitize=init-order %s -### 2>&1 |  FileCheck %s --check-prefix=CHECK-ASAN-NO-IMPLIED-INIT-ORDER
end_comment

begin_comment
comment|// CHECK-ASAN-NO-IMPLIED-INIT-ORDER-NOT: init-order
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fno-sanitize=use-after-return %s -### 2>&1 |  FileCheck %s --check-prefix=CHECK-ASAN-NO-IMPLIED-UAR
end_comment

begin_comment
comment|// CHECK-ASAN-NO-IMPLIED-UAR-NOT: use-after-return
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fcatch-undefined-behavior -fno-sanitize-undefined-trap-on-error %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-UNDEFINED-NO-TRAP-ERROR
end_comment

begin_comment
comment|// CHECK-UNDEFINED-NO-TRAP-ERROR: '-fcatch-undefined-behavior' not allowed with '-fno-sanitize-undefined-trap-on-error'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=vptr -fcatch-undefined-behavior %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-VPTR-UNDEF-ERROR
end_comment

begin_comment
comment|// CHECK-VPTR-UNDEF-ERROR: '-fsanitize=vptr' not allowed with '-fcatch-undefined-behavior'
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
comment|// RUN: %clang -target x86_64-linux-gnu -faddress-sanitizer -fthread-sanitizer -fno-rtti %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ASAN-TSAN
end_comment

begin_comment
comment|// CHECK-ASAN-TSAN: '-faddress-sanitizer' not allowed with '-fthread-sanitizer'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=init-order %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ONLY-EXTRA-ASAN
end_comment

begin_comment
comment|// CHECK-ONLY-EXTRA-ASAN: '-fsanitize=init-order' is ignored in absence of '-fsanitize=address'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -Wno-unused-sanitize-argument -fsanitize=init-order %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-WNO-UNUSED-SANITIZE-ARGUMENT
end_comment

begin_comment
comment|// CHECK-WNO-UNUSED-SANITIZE-ARGUMENT-NOT: '-fsanitize=init-order' is ignored in absence of '-fsanitize=address'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address,init-order -fno-sanitize=address %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NOWARN-ONLY-EXTRA-ASAN
end_comment

begin_comment
comment|// CHECK-NOWARN-ONLY-EXTRA-ASAN-NOT: is ignored in absence of '-fsanitize=address'
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
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-address-zero-base-shadow -pie %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ONLY-ASAN-ZERO-BASE-SHADOW
end_comment

begin_comment
comment|// CHECK-ONLY-ASAN-ZERO-BASE-SHADOW: warning: argument unused during compilation: '-fsanitize-address-zero-base-shadow'
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
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory -fsanitize-memory-track-origins -pie %s -### 2>&1
end_comment

begin_comment
comment|// OK
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=vptr -fno-sanitize=vptr -fsanitize=undefined,address %s -### 2>&1
end_comment

begin_comment
comment|// OK
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-address-zero-base-shadow -pie %s -### 2>&1
end_comment

begin_comment
comment|// OK
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fcatch-undefined-behavior -fthread-sanitizer -fno-thread-sanitizer -faddress-sanitizer -fno-address-sanitizer -fbounds-checking -### %s 2>&1 | FileCheck %s --check-prefix=CHECK-DEPRECATED
end_comment

begin_comment
comment|// CHECK-DEPRECATED: argument '-fbounds-checking' is deprecated, use '-fsanitize=local-bounds' instead
end_comment

begin_comment
comment|// CHECK-DEPRECATED: argument '-fno-address-sanitizer' is deprecated, use '-fno-sanitize=address' instead
end_comment

begin_comment
comment|// CHECK-DEPRECATED: argument '-faddress-sanitizer' is deprecated, use '-fsanitize=address' instead
end_comment

begin_comment
comment|// CHECK-DEPRECATED: argument '-fno-thread-sanitizer' is deprecated, use '-fno-sanitize=thread' instead
end_comment

begin_comment
comment|// CHECK-DEPRECATED: argument '-fthread-sanitizer' is deprecated, use '-fsanitize=thread' instead
end_comment

begin_comment
comment|// CHECK-DEPRECATED: argument '-fcatch-undefined-behavior' is deprecated, use '-fsanitize=undefined-trap -fsanitize-undefined-trap-on-error' instead
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=thread %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-TSAN-NO-PIE
end_comment

begin_comment
comment|// CHECK-TSAN-NO-PIE: "-mrelocation-model" "pic" "-pic-level" "2" "-pie-level" "2"
end_comment

begin_comment
comment|// CHECK-TSAN-NO-PIE: "-pie"
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
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-address-zero-base-shadow %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ASAN-ZERO-BASE-SHADOW-NO-PIE
end_comment

begin_comment
comment|// CHECK-ASAN-ZERO-BASE-SHADOW-NO-PIE: "-mrelocation-model" "pic" "-pic-level" "2" "-pie-level" "2"
end_comment

begin_comment
comment|// CHECK-ASAN-ZERO-BASE-SHADOW-NO-PIE: "-pie"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-address-zero-base-shadow -fno-sanitize-address-zero-base-shadow %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ASAN-ZERO-BASE-SHADOW-CANCEL
end_comment

begin_comment
comment|// CHECK-ASAN-ZERO-BASE-SHADOW-CANCEL-NOT: "-mrelocation-model" "pic" "-pic-level" "2" "-pie-level" "2"
end_comment

begin_comment
comment|// CHECK-ASAN-ZERO-BASE-SHADOW-CANCEL-NOT: "-pie"
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
comment|// CHECK-ANDROID-NO-ASAN: "-mrelocation-model" "static"
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-androideabi -fsanitize=address -fsanitize-address-zero-base-shadow %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ANDROID-ASAN-ZERO-BASE
end_comment

begin_comment
comment|// CHECK-ANDROID-ASAN-ZERO-BASE-NOT: argument unused during compilation
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-androideabi -fsanitize=address -fno-sanitize-address-zero-base-shadow %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ANDROID-ASAN-NO-ZERO-BASE
end_comment

begin_comment
comment|// CHECK-ANDROID-ASAN-NO-ZERO-BASE: '-fno-sanitize-address-zero-base-shadow' not allowed with '-fsanitize=address'
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-RECOVER
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize-recover -### 2>&1 | FileCheck %s --check-prefix=CHECK-RECOVER
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fno-sanitize-recover -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-RECOVER
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fno-sanitize-recover -fsanitize-recover -### 2>&1 | FileCheck %s --check-prefix=CHECK-RECOVER
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu %s -fsanitize-recover -fno-sanitize-recover -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-RECOVER
end_comment

begin_comment
comment|// CHECK-RECOVER-NOT: sanitize-recover
end_comment

begin_comment
comment|// CHECK-NO-RECOVER: "-fno-sanitize-recover"
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

end_unit

