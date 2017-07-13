begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check handling MIPS specific features options.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mabicalls
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s -mno-abicalls -mabicalls 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MABICALLS %s
end_comment

begin_comment
comment|// CHECK-MABICALLS: "-target-feature" "-noabicalls"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mno-abicalls
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s -mabicalls -mno-abicalls 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MNOABICALLS %s
end_comment

begin_comment
comment|// CHECK-MNOABICALLS: "-target-feature" "+noabicalls"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mips16
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mno-mips16 -mips16 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPS16 %s
end_comment

begin_comment
comment|// CHECK-MIPS16: "-target-feature" "+mips16"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mno-mips16
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mips16 -mno-mips16 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOMIPS16 %s
end_comment

begin_comment
comment|// CHECK-NOMIPS16: "-target-feature" "-mips16"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mmicromips
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mno-micromips -mmicromips 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MICROMIPS %s
end_comment

begin_comment
comment|// CHECK-MICROMIPS: "-target-feature" "+micromips"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mno-micromips
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mmicromips -mno-micromips 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOMICROMIPS %s
end_comment

begin_comment
comment|// CHECK-NOMICROMIPS: "-target-feature" "-micromips"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mdsp
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mno-dsp -mdsp 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MDSP %s
end_comment

begin_comment
comment|// CHECK-MDSP: "-target-feature" "+dsp"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mno-dsp
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mdsp -mno-dsp 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOMDSP %s
end_comment

begin_comment
comment|// CHECK-NOMDSP: "-target-feature" "-dsp"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mdspr2
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mno-dspr2 -mdspr2 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MDSPR2 %s
end_comment

begin_comment
comment|// CHECK-MDSPR2: "-target-feature" "+dspr2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mno-dspr2
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mdspr2 -mno-dspr2 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOMDSPR2 %s
end_comment

begin_comment
comment|// CHECK-NOMDSPR2: "-target-feature" "-dspr2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mmsa
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mno-msa -mmsa 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MMSA %s
end_comment

begin_comment
comment|// CHECK-MMSA: "-target-feature" "+msa"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mno-msa
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mmsa -mno-msa 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOMMSA %s
end_comment

begin_comment
comment|// CHECK-NOMMSA: "-target-feature" "-msa"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mmt
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mno-mt -mmt 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MMT %s
end_comment

begin_comment
comment|// CHECK-MMT: "-target-feature" "+mt"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mno-mt
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mmt -mno-mt 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOMMT %s
end_comment

begin_comment
comment|// CHECK-NOMMT: "-target-feature" "-mt"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -modd-spreg
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s -mno-odd-spreg -modd-spreg 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MODDSPREG %s
end_comment

begin_comment
comment|// CHECK-MODDSPREG: "-target-feature" "-nooddspreg"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mno-odd-spreg
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s -modd-spreg -mno-odd-spreg 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOMODDSPREG %s
end_comment

begin_comment
comment|// CHECK-NOMODDSPREG: "-target-feature" "+nooddspreg"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mfpxx
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s -mfpxx 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MFPXX %s
end_comment

begin_comment
comment|// CHECK-MFPXX: "-target-feature" "+fpxx"
end_comment

begin_comment
comment|// CHECK-MFPXX: "-target-feature" "+nooddspreg"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mfpxx -modd-spreg
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s -mfpxx -modd-spreg 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MFPXX-ODDSPREG %s
end_comment

begin_comment
comment|// CHECK-MFPXX-ODDSPREG: "-target-feature" "+fpxx"
end_comment

begin_comment
comment|// CHECK-MFPXX-ODDSPREG: "-target-feature" "-nooddspreg"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mfp64
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mfp32 -mfp64 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MFP64 %s
end_comment

begin_comment
comment|// CHECK-MFP64: "-target-feature" "+fp64"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mfp32
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mfp64 -mfp32 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOMFP64 %s
end_comment

begin_comment
comment|// CHECK-NOMFP64: "-target-feature" "-fp64"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mnan=2008
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -march=mips32r3 -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mnan=legacy -mnan=2008 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NAN2008 %s
end_comment

begin_comment
comment|// CHECK-NAN2008: "-target-feature" "+nan2008"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mnan=legacy
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -march=mips32r3 -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mnan=2008 -mnan=legacy 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NANLEGACY %s
end_comment

begin_comment
comment|// CHECK-NANLEGACY: "-target-feature" "-nan2008"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mcompact-branches=never
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -march=mips32r6 -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mcompact-branches=never 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CBNEVER %s
end_comment

begin_comment
comment|// CHECK-CBNEVER: "-mllvm" "-mips-compact-branches=never"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mcompact-branches=optimal
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -march=mips32r6 -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mcompact-branches=optimal 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CBOPTIMAL %s
end_comment

begin_comment
comment|// CHECK-CBOPTIMAL: "-mllvm" "-mips-compact-branches=optimal"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mcompact-branches=always
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -march=mips32r6 -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mcompact-branches=always 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CBALWAYS %s
end_comment

begin_comment
comment|// CHECK-CBALWAYS: "-mllvm" "-mips-compact-branches=always"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mxgot
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mno-xgot -mxgot 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-XGOT %s
end_comment

begin_comment
comment|// CHECK-XGOT: "-mllvm" "-mxgot"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mno-xgot
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mxgot -mno-xgot 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOXGOT %s
end_comment

begin_comment
comment|// CHECK-NOXGOT-NOT: "-mllvm" "-mxgot"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mldc1-sdc1
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mno-ldc1-sdc1 -mldc1-sdc1 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LDC1SDC1 %s
end_comment

begin_comment
comment|// CHECK-LDC1SDC1-NOT: "-mllvm" "-mno-ldc1-sdc1"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mno-ldc1-sdc1
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mldc1-sdc1 -mno-ldc1-sdc1 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOLDC1SDC1 %s
end_comment

begin_comment
comment|// CHECK-NOLDC1SDC1: "-mllvm" "-mno-ldc1-sdc1"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mcheck-zero-division
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mno-check-zero-division -mcheck-zero-division 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ZERODIV %s
end_comment

begin_comment
comment|// CHECK-ZERODIV-NOT: "-mllvm" "-mno-check-zero-division"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mno-check-zero-division
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -mcheck-zero-division -mno-check-zero-division 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOZERODIV %s
end_comment

begin_comment
comment|// CHECK-NOZERODIV: "-mllvm" "-mno-check-zero-division"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -G
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:     -G 16 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MIPS-G %s
end_comment

begin_comment
comment|// CHECK-MIPS-G: "-mllvm" "-mips-ssection-threshold=16"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -msoft-float (unknown vendor)
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s -msoft-float 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SOFTFLOAT %s
end_comment

begin_comment
comment|// CHECK-SOFTFLOAT: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|// CHECK-SOFTFLOAT-NOT: "-target-feature" "+fpxx"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -msoft-float -mfpxx (unknown vendor)
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s -msoft-float -mfpxx 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SOFTFLOAT-FPXX %s
end_comment

begin_comment
comment|// CHECK-SOFTFLOAT-FPXX: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|// CHECK-SOFTFLOAT-FPXX: "-target-feature" "+fpxx"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -msoft-float (MTI)
end_comment

begin_comment
comment|// RUN: %clang -target mips-mti-linux-gnu -### -c %s -msoft-float 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MTI-SOFTFLOAT %s
end_comment

begin_comment
comment|// CHECK-MTI-SOFTFLOAT: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|// CHECK-MTI-SOFTFLOAT-NOT: "-target-feature" "+fpxx"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -msoft-float -mfpxx (MTI)
end_comment

begin_comment
comment|// RUN: %clang -target mips-mti-linux-gnu -### -c %s -msoft-float -mfpxx 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MTI-SOFTFLOAT-FPXX %s
end_comment

begin_comment
comment|// CHECK-MTI-SOFTFLOAT-FPXX: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|// CHECK-MTI-SOFTFLOAT-FPXX: "-target-feature" "+fpxx"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -msoft-float (IMG)
end_comment

begin_comment
comment|// RUN: %clang -target mips-img-linux-gnu -### -c %s -msoft-float 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-IMG-SOFTFLOAT %s
end_comment

begin_comment
comment|// CHECK-IMG-SOFTFLOAT: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|// CHECK-IMG-SOFTFLOAT-NOT: "-target-feature" "+fpxx"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -msoft-float -mfpxx (IMG)
end_comment

begin_comment
comment|// RUN: %clang -target mips-img-linux-gnu -### -c %s -msoft-float -mfpxx 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-IMG-SOFTFLOAT-FPXX %s
end_comment

begin_comment
comment|// CHECK-IMG-SOFTFLOAT-FPXX: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|// CHECK-IMG-SOFTFLOAT-FPXX: "-target-feature" "+fpxx"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -msingle-float (unknown vendor)
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s -msingle-float 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SINGLEFLOAT %s
end_comment

begin_comment
comment|// CHECK-SINGLEFLOAT: "-target-feature" "+single-float"
end_comment

begin_comment
comment|// CHECK-SINGLEFLOAT-NOT: "-target-feature" "+fpxx"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -msingle-float -mfpxx (unknown vendor)
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s -msingle-float -mfpxx 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SINGLEFLOAT-FPXX %s
end_comment

begin_comment
comment|// CHECK-SINGLEFLOAT-FPXX: "-target-feature" "+single-float"
end_comment

begin_comment
comment|// CHECK-SINGLEFLOAT-FPXX: "-target-feature" "+fpxx"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -msingle-float (MTI)
end_comment

begin_comment
comment|// RUN: %clang -target mips-mti-linux-gnu -### -c %s -msingle-float 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MTI-SINGLEFLOAT %s
end_comment

begin_comment
comment|// CHECK-MTI-SINGLEFLOAT: "-target-feature" "+single-float"
end_comment

begin_comment
comment|// CHECK-MTI-SINGLEFLOAT-NOT: "-target-feature" "+fpxx"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -msingle-float -mfpxx (MTI)
end_comment

begin_comment
comment|// RUN: %clang -target mips-mti-linux-gnu -### -c %s -msingle-float -mfpxx 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MTI-SINGLEFLOAT-FPXX %s
end_comment

begin_comment
comment|// CHECK-MTI-SINGLEFLOAT-FPXX: "-target-feature" "+single-float"
end_comment

begin_comment
comment|// CHECK-MTI-SINGLEFLOAT-FPXX: "-target-feature" "+fpxx"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -msingle-float (IMG)
end_comment

begin_comment
comment|// RUN: %clang -target mips-img-linux-gnu -### -c %s -msingle-float 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-IMG-SINGLEFLOAT %s
end_comment

begin_comment
comment|// CHECK-IMG-SINGLEFLOAT: "-target-feature" "+single-float"
end_comment

begin_comment
comment|// CHECK-IMG-SINGLEFLOAT-NOT: "-target-feature" "+fpxx"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -msingle-float -mfpxx (IMG)
end_comment

begin_comment
comment|// RUN: %clang -target mips-img-linux-gnu -### -c %s -msingle-float -mfpxx 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-IMG-SINGLEFLOAT-FPXX %s
end_comment

begin_comment
comment|// CHECK-IMG-SINGLEFLOAT-FPXX: "-target-feature" "+single-float"
end_comment

begin_comment
comment|// CHECK-IMG-SINGLEFLOAT-FPXX: "-target-feature" "+fpxx"
end_comment

begin_comment
comment|// -mlong-call
end_comment

begin_comment
comment|// RUN: %clang -target mips-img-linux-gnu -### -c %s -mlong-calls 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=LONG-CALLS-ON %s
end_comment

begin_comment
comment|// RUN: %clang -target mips-img-linux-gnu -### -c %s -mno-long-calls 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=LONG-CALLS-OFF %s
end_comment

begin_comment
comment|// RUN: %clang -target mips-img-linux-gnu -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=LONG-CALLS-DEF %s
end_comment

begin_comment
comment|// LONG-CALLS-ON: "-target-feature" "+long-calls"
end_comment

begin_comment
comment|// LONG-CALLS-OFF: "-target-feature" "-long-calls"
end_comment

begin_comment
comment|// LONG-CALLS-DEF-NOT: "long-calls"
end_comment

end_unit

