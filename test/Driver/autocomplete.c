begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang --autocomplete=-fsyn | FileCheck %s -check-prefix=FSYN
end_comment

begin_comment
comment|// FSYN: -fsyntax-only
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-s | FileCheck %s -check-prefix=STD
end_comment

begin_comment
comment|// STD: -std={{.*}}-stdlib=
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=foo | FileCheck %s -check-prefix=FOO
end_comment

begin_comment
comment|// FOO-NOT: foo
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-stdlib=,l | FileCheck %s -check-prefix=STDLIB
end_comment

begin_comment
comment|// STDLIB: libc++ libstdc++
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-stdlib=, | FileCheck %s -check-prefix=STDLIBALL
end_comment

begin_comment
comment|// STDLIBALL: libc++ libstdc++ platform
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-meabi,d | FileCheck %s -check-prefix=MEABI
end_comment

begin_comment
comment|// MEABI: default
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-meabi, | FileCheck %s -check-prefix=MEABIALL
end_comment

begin_comment
comment|// MEABIALL: 4 5 default gnu
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-cl-std=,CL2 | FileCheck %s -check-prefix=CLSTD
end_comment

begin_comment
comment|// CLSTD: CL2.0
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-cl-std=, | FileCheck %s -check-prefix=CLSTDALL
end_comment

begin_comment
comment|// CLSTDALL: cl CL cl1.1 CL1.1 cl1.2 CL1.2 cl2.0 CL2.0
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-fno-sanitize-coverage=,f | FileCheck %s -check-prefix=FNOSANICOVER
end_comment

begin_comment
comment|// FNOSANICOVER: func
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-fno-sanitize-coverage=, | FileCheck %s -check-prefix=FNOSANICOVERALL
end_comment

begin_comment
comment|// FNOSANICOVERALL: 8bit-counters bb edge func indirect-calls inline-8bit-counters no-prune trace-bb trace-cmp trace-div trace-gep trace-pc trace-pc-guard
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-ffp-contract=, | FileCheck %s -check-prefix=FFPALL
end_comment

begin_comment
comment|// FFPALL: fast off on
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-flto=, | FileCheck %s -check-prefix=FLTOALL
end_comment

begin_comment
comment|// FLTOALL: full thin
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-fveclib=, | FileCheck %s -check-prefix=FVECLIBALL
end_comment

begin_comment
comment|// FVECLIBALL: Accelerate none SVML
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-fshow-overloads=, | FileCheck %s -check-prefix=FSOVERALL
end_comment

begin_comment
comment|// FSOVERALL: all best
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-fvisibility=, | FileCheck %s -check-prefix=FVISIBILITYALL
end_comment

begin_comment
comment|// FVISIBILITYALL: default hidden
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-mfloat-abi=, | FileCheck %s -check-prefix=MFLOATABIALL
end_comment

begin_comment
comment|// MFLOATABIALL: hard soft softfp
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-mthread-model, | FileCheck %s -check-prefix=MTHREADMODELALL
end_comment

begin_comment
comment|// MTHREADMODELALL: posix single
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-mrelocation-model, | FileCheck %s -check-prefix=MRELOCMODELALL
end_comment

begin_comment
comment|// MRELOCMODELALL: dynamic-no-pic pic ropi ropi-rwpi rwpi static
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-mrelocation-mode | FileCheck %s -check-prefix=MRELOCMODEL_CLANG
end_comment

begin_comment
comment|// MRELOCMODEL_CLANG-NOT: -mrelocation-model
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=#-mrelocation-mode | FileCheck %s -check-prefix=MRELOCMODEL_CC1
end_comment

begin_comment
comment|// MRELOCMODEL_CC1: -mrelocation-model
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-Wma | FileCheck %s -check-prefix=WARNING
end_comment

begin_comment
comment|// WARNING: -Wmacro-redefined -Wmain -Wmain-return-type -Wmalformed-warning-check -Wmany-braces-around-scalar-init -Wmax-unsigned-zero
end_comment

begin_comment
comment|// RUN: %clang --autocomplete=-Wnoinvalid-pp- | FileCheck %s -check-prefix=NOWARNING
end_comment

begin_comment
comment|// NOWARNING: -Wnoinvalid-pp-token
end_comment

end_unit

