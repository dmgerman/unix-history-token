begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check ld invocations on Mentor Graphics MIPS toolchain.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// = Big-endian, hard float
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips-linux-gnu \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/mips_cs_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-BE-HF-32 %s
end_comment

begin_comment
comment|// CHECK-BE-HF-32: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-BE-HF-32: "--sysroot=[[TC:[^"]+]]/../../../../mips-linux-gnu/libc"
end_comment

begin_comment
comment|// CHECK-BE-HF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/usr/lib/../lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/usr/lib/../lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-32: "-L[[TC]]"
end_comment

begin_comment
comment|// CHECK-BE-HF-32: "-L[[TC]]/../../../../mips-linux-gnu/lib/../lib"
end_comment

begin_comment
comment|// CHECK-BE-HF-32: "-L[[TC]]/../../../../mips-linux-gnu/libc/lib"
end_comment

begin_comment
comment|// CHECK-BE-HF-32: "-L[[TC]]/../../../../mips-linux-gnu/libc/usr/lib"
end_comment

begin_comment
comment|// CHECK-BE-HF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/usr/lib/../lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// = Big-endian, hard float, mips16
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips-linux-gnu -mips16 \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/mips_cs_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-BE-HF-16 %s
end_comment

begin_comment
comment|// CHECK-BE-HF-16: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-BE-HF-16: "--sysroot=[[TC:[^"]+]]/../../../../mips-linux-gnu/libc/mips16"
end_comment

begin_comment
comment|// CHECK-BE-HF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/mips16/usr/lib/../lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/mips16/usr/lib/../lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/mips16{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-16: "-L[[TC]]/mips16"
end_comment

begin_comment
comment|// CHECK-BE-HF-16: "-L[[TC]]/../../../../mips-linux-gnu/lib/../lib/mips16"
end_comment

begin_comment
comment|// CHECK-BE-HF-16-NOT: "-L[[TC]]"
end_comment

begin_comment
comment|// CHECK-BE-HF-16: "-L[[TC]]/../../../../mips-linux-gnu/libc/mips16/lib/../lib"
end_comment

begin_comment
comment|// CHECK-BE-HF-16: "-L[[TC]]/../../../../mips-linux-gnu/libc/mips16/usr/lib/../lib"
end_comment

begin_comment
comment|// CHECK-BE-HF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/mips16{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/mips16/usr/lib/../lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// = Big-endian, hard float, mmicromips
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips-linux-gnu -mmicromips \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/mips_cs_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-BE-HF-MICRO %s
end_comment

begin_comment
comment|// CHECK-BE-HF-MICRO: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-BE-HF-MICRO: "--sysroot=[[TC:[^"]+]]/../../../../mips-linux-gnu/libc/micromips"
end_comment

begin_comment
comment|// CHECK-BE-HF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/micromips/usr/lib/../lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/micromips/usr/lib/../lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/micromips{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-MICRO: "-L[[TC]]/micromips"
end_comment

begin_comment
comment|// CHECK-BE-HF-MICRO: "-L[[TC]]/../../../../mips-linux-gnu/lib/../lib/micromips"
end_comment

begin_comment
comment|// CHECK-BE-HF-MICRO-NOT: "-L[[TC]]"
end_comment

begin_comment
comment|// CHECK-BE-HF-MICRO: "-L[[TC]]/../../../../mips-linux-gnu/libc/micromips/lib/../lib"
end_comment

begin_comment
comment|// CHECK-BE-HF-MICRO: "-L[[TC]]/../../../../mips-linux-gnu/libc/micromips/usr/lib/../lib"
end_comment

begin_comment
comment|// CHECK-BE-HF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/micromips{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/micromips/usr/lib/../lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// = Big-endian, soft float
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips-linux-gnu -msoft-float \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/mips_cs_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-BE-SF-32 %s
end_comment

begin_comment
comment|// CHECK-BE-SF-32: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-BE-SF-32: "--sysroot=[[TC:[^"]+]]/../../../../mips-linux-gnu/libc/soft-float"
end_comment

begin_comment
comment|// CHECK-BE-SF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/soft-float/usr/lib/../lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-BE-SF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/soft-float/usr/lib/../lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-BE-SF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/soft-float{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-BE-SF-32: "-L[[TC]]/soft-float"
end_comment

begin_comment
comment|// CHECK-BE-SF-32: "-L[[TC]]/../../../../mips-linux-gnu/lib/../lib/soft-float"
end_comment

begin_comment
comment|// CHECK-BE-SF-32-NOT: "-L[[TC]]"
end_comment

begin_comment
comment|// CHECK-BE-SF-32: "-L[[TC]]/../../../../mips-linux-gnu/libc/soft-float/lib/../lib"
end_comment

begin_comment
comment|// CHECK-BE-SF-32: "-L[[TC]]/../../../../mips-linux-gnu/libc/soft-float/usr/lib/../lib"
end_comment

begin_comment
comment|// CHECK-BE-SF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/soft-float{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-BE-SF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/soft-float/usr/lib/../lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// = Big-endian, soft float, mips16
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips-linux-gnu -msoft-float -mips16 \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/mips_cs_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-BE-SF-16 %s
end_comment

begin_comment
comment|// CHECK-BE-SF-16: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-BE-SF-16: "--sysroot=[[TC:[^"]+]]/../../../../mips-linux-gnu/libc/mips16/soft-float"
end_comment

begin_comment
comment|// CHECK-BE-SF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/mips16/soft-float/usr/lib/../lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-BE-SF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/mips16/soft-float/usr/lib/../lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-BE-SF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/mips16/soft-float{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-BE-SF-16: "-L[[TC]]/mips16/soft-float"
end_comment

begin_comment
comment|// CHECK-BE-SF-16: "-L[[TC]]/../../../../mips-linux-gnu/lib/../lib/mips16/soft-float"
end_comment

begin_comment
comment|// CHECK-BE-SF-16-NOT: "-L[[TC]]"
end_comment

begin_comment
comment|// CHECK-BE-SF-16: "-L[[TC]]/../../../../mips-linux-gnu/libc/mips16/soft-float/lib/../lib"
end_comment

begin_comment
comment|// CHECK-BE-SF-16: "-L[[TC]]/../../../../mips-linux-gnu/libc/mips16/soft-float/usr/lib/../lib"
end_comment

begin_comment
comment|// CHECK-BE-SF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/mips16/soft-float{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-BE-SF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/mips16/soft-float/usr/lib/../lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// = Big-endian, soft float, micromips
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips-linux-gnu -msoft-float -mmicromips \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/mips_cs_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-BE-SF-MICRO %s
end_comment

begin_comment
comment|// CHECK-BE-SF-MICRO: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-BE-SF-MICRO: "--sysroot=[[TC:[^"]+]]/../../../../mips-linux-gnu/libc/micromips/soft-float"
end_comment

begin_comment
comment|// CHECK-BE-SF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/micromips/soft-float/usr/lib/../lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-BE-SF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/micromips/soft-float/usr/lib/../lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-BE-SF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/micromips/soft-float{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-BE-SF-MICRO: "-L[[TC]]/micromips/soft-float"
end_comment

begin_comment
comment|// CHECK-BE-SF-MICRO: "-L[[TC]]/../../../../mips-linux-gnu/lib/../lib/micromips/soft-float"
end_comment

begin_comment
comment|// CHECK-BE-SF-MICRO-NOT: "-L[[TC]]"
end_comment

begin_comment
comment|// CHECK-BE-SF-MICRO: "-L[[TC]]/../../../../mips-linux-gnu/libc/micromips/soft-float/lib/../lib"
end_comment

begin_comment
comment|// CHECK-BE-SF-MICRO: "-L[[TC]]/../../../../mips-linux-gnu/libc/micromips/soft-float/usr/lib/../lib"
end_comment

begin_comment
comment|// CHECK-BE-SF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/micromips/soft-float{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-BE-SF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/micromips/soft-float/usr/lib/../lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// = Big-endian, hard float, 64-bit
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips64-linux-gnu \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/mips_cs_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-BE-HF-64 %s
end_comment

begin_comment
comment|// CHECK-BE-HF-64: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-BE-HF-64: "--sysroot=[[TC:[^"]+]]/../../../../mips-linux-gnu/libc"
end_comment

begin_comment
comment|// CHECK-BE-HF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/usr/lib/../lib64{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/usr/lib/../lib64{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/64{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-64: "-L[[TC]]/64"
end_comment

begin_comment
comment|// CHECK-BE-HF-64: "-L[[TC]]/../../../../mips-linux-gnu/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-BE-HF-64: "-L[[TC]]/../../../../mips-linux-gnu/libc/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-BE-HF-64: "-L[[TC]]/../../../../mips-linux-gnu/libc/usr/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-BE-HF-64-NOT: "-L[[TC]]"
end_comment

begin_comment
comment|// CHECK-BE-HF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/64{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/usr/lib/../lib64{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// = Big-endian, soft float, 64-bit
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips64-linux-gnu -msoft-float \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/mips_cs_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-BE-SF-64 %s
end_comment

begin_comment
comment|// CHECK-BE-SF-64: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-BE-SF-64: "--sysroot=[[TC:[^"]+]]/../../../../mips-linux-gnu/libc/soft-float"
end_comment

begin_comment
comment|// CHECK-BE-SF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/soft-float/usr/lib/../lib64{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-BE-SF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/soft-float/usr/lib/../lib64{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-BE-SF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/soft-float/64{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-BE-SF-64: "-L[[TC]]/soft-float/64"
end_comment

begin_comment
comment|// CHECK-BE-SF-64: "-L[[TC]]/../../../../mips-linux-gnu/lib/../lib64/soft-float"
end_comment

begin_comment
comment|// CHECK-BE-SF-64: "-L[[TC]]/../../../../mips-linux-gnu/libc/soft-float/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-BE-SF-64: "-L[[TC]]/../../../../mips-linux-gnu/libc/soft-float/usr/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-BE-SF-64-NOT: "-L[[TC]]"
end_comment

begin_comment
comment|// CHECK-BE-SF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/soft-float/64{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-BE-SF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/soft-float/usr/lib/../lib64{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// = Little-endian, hard float
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mipsel-linux-gnu -mhard-float \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/mips_cs_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-EL-HF-32 %s
end_comment

begin_comment
comment|// CHECK-EL-HF-32: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-EL-HF-32: "--sysroot=[[TC:[^"]+]]/../../../../mips-linux-gnu/libc/el"
end_comment

begin_comment
comment|// CHECK-EL-HF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/el/usr/lib/../lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-EL-HF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/el/usr/lib/../lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-EL-HF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/el{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-EL-HF-32: "-L[[TC]]/el"
end_comment

begin_comment
comment|// CHECK-EL-HF-32: "-L[[TC]]/../../../../mips-linux-gnu/lib/../lib/el"
end_comment

begin_comment
comment|// CHECK-EL-HF-32-NOT: "-L[[TC]]"
end_comment

begin_comment
comment|// CHECK-EL-HF-32: "-L[[TC]]/../../../../mips-linux-gnu/libc/el/lib/../lib"
end_comment

begin_comment
comment|// CHECK-EL-HF-32: "-L[[TC]]/../../../../mips-linux-gnu/libc/el/usr/lib/../lib"
end_comment

begin_comment
comment|// CHECK-EL-HF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/el{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-EL-HF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/el/usr/lib/../lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// = Little-endian, hard float, mips16
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mipsel-linux-gnu -mips16 \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/mips_cs_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-EL-HF-16 %s
end_comment

begin_comment
comment|// CHECK-EL-HF-16: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-EL-HF-16: "--sysroot=[[TC:[^"]+]]/../../../../mips-linux-gnu/libc/mips16/el"
end_comment

begin_comment
comment|// CHECK-EL-HF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/mips16/el/usr/lib/../lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-EL-HF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/mips16/el/usr/lib/../lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-EL-HF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/mips16/el{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-EL-HF-16: "-L[[TC]]/mips16/el"
end_comment

begin_comment
comment|// CHECK-EL-HF-16: "-L[[TC]]/../../../../mips-linux-gnu/lib/../lib/mips16/el"
end_comment

begin_comment
comment|// CHECK-EL-HF-16-NOT: "-L[[TC]]"
end_comment

begin_comment
comment|// CHECK-EL-HF-16: "-L[[TC]]/../../../../mips-linux-gnu/libc/mips16/el/lib/../lib"
end_comment

begin_comment
comment|// CHECK-EL-HF-16: "-L[[TC]]/../../../../mips-linux-gnu/libc/mips16/el/usr/lib/../lib"
end_comment

begin_comment
comment|// CHECK-EL-HF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/mips16/el{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-EL-HF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/mips16/el/usr/lib/../lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// = Little-endian, hard float, micromips
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mipsel-linux-gnu -mmicromips \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/mips_cs_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-EL-HF-MICRO %s
end_comment

begin_comment
comment|// CHECK-EL-HF-MICRO: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-EL-HF-MICRO: "--sysroot=[[TC:[^"]+]]/../../../../mips-linux-gnu/libc/micromips/el"
end_comment

begin_comment
comment|// CHECK-EL-HF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/micromips/el/usr/lib/../lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-EL-HF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/micromips/el/usr/lib/../lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-EL-HF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/micromips/el{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-EL-HF-MICRO: "-L[[TC]]/micromips/el"
end_comment

begin_comment
comment|// CHECK-EL-HF-MICRO: "-L[[TC]]/../../../../mips-linux-gnu/lib/../lib/micromips/el"
end_comment

begin_comment
comment|// CHECK-EL-HF-MICRO-NOT: "-L[[TC]]"
end_comment

begin_comment
comment|// CHECK-EL-HF-MICRO: "-L[[TC]]/../../../../mips-linux-gnu/libc/micromips/el/lib/../lib"
end_comment

begin_comment
comment|// CHECK-EL-HF-MICRO: "-L[[TC]]/../../../../mips-linux-gnu/libc/micromips/el/usr/lib/../lib"
end_comment

begin_comment
comment|// CHECK-EL-HF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/micromips/el{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-EL-HF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/micromips/el/usr/lib/../lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// = Little-endian, soft float
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mipsel-linux-gnu -mfloat-abi=soft \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/mips_cs_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-EL-SF-32 %s
end_comment

begin_comment
comment|// CHECK-EL-SF-32: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-EL-SF-32: "--sysroot=[[TC:[^"]+]]/../../../../mips-linux-gnu/libc/soft-float/el"
end_comment

begin_comment
comment|// CHECK-EL-SF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/soft-float/el/usr/lib/../lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-EL-SF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/soft-float/el/usr/lib/../lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-EL-SF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/soft-float/el{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-EL-SF-32: "-L[[TC]]/soft-float/el"
end_comment

begin_comment
comment|// CHECK-EL-SF-32: "-L[[TC]]/../../../../mips-linux-gnu/lib/../lib/soft-float/el"
end_comment

begin_comment
comment|// CHECK-EL-SF-32-NOT: "-L[[TC]]"
end_comment

begin_comment
comment|// CHECK-EL-SF-32: "-L[[TC]]/../../../../mips-linux-gnu/libc/soft-float/el/lib/../lib"
end_comment

begin_comment
comment|// CHECK-EL-SF-32: "-L[[TC]]/../../../../mips-linux-gnu/libc/soft-float/el/usr/lib/../lib"
end_comment

begin_comment
comment|// CHECK-EL-SF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/soft-float/el{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-EL-SF-32: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/soft-float/el/usr/lib/../lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// = Little-endian, soft float, mips16
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mipsel-linux-gnu -mips16 -msoft-float \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/mips_cs_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-EL-SF-16 %s
end_comment

begin_comment
comment|// CHECK-EL-SF-16: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-EL-SF-16: "--sysroot=[[TC:[^"]+]]/../../../../mips-linux-gnu/libc/mips16/soft-float/el"
end_comment

begin_comment
comment|// CHECK-EL-SF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/mips16/soft-float/el/usr/lib/../lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-EL-SF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/mips16/soft-float/el/usr/lib/../lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-EL-SF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/mips16/soft-float/el{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-EL-SF-16: "-L[[TC]]/mips16/soft-float/el"
end_comment

begin_comment
comment|// CHECK-EL-SF-16: "-L[[TC]]/../../../../mips-linux-gnu/lib/../lib/mips16/soft-float/el"
end_comment

begin_comment
comment|// CHECK-EL-SF-16-NOT: "-L[[TC]]"
end_comment

begin_comment
comment|// CHECK-EL-SF-16: "-L[[TC]]/../../../../mips-linux-gnu/libc/mips16/soft-float/el/lib/../lib"
end_comment

begin_comment
comment|// CHECK-EL-SF-16: "-L[[TC]]/../../../../mips-linux-gnu/libc/mips16/soft-float/el/usr/lib/../lib"
end_comment

begin_comment
comment|// CHECK-EL-SF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/mips16/soft-float/el{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-EL-SF-16: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/mips16/soft-float/el/usr/lib/../lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// = Little-endian, soft float, micromips
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mipsel-linux-gnu -mmicromips -msoft-float \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/mips_cs_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-EL-SF-MICRO %s
end_comment

begin_comment
comment|// CHECK-EL-SF-MICRO: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-EL-SF-MICRO: "--sysroot=[[TC:[^"]+]]/../../../../mips-linux-gnu/libc/micromips/soft-float/el"
end_comment

begin_comment
comment|// CHECK-EL-SF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/micromips/soft-float/el/usr/lib/../lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-EL-SF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/micromips/soft-float/el/usr/lib/../lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-EL-SF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/micromips/soft-float/el{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-EL-SF-MICRO: "-L[[TC]]/micromips/soft-float/el"
end_comment

begin_comment
comment|// CHECK-EL-SF-MICRO: "-L[[TC]]/../../../../mips-linux-gnu/lib/../lib/micromips/soft-float/el"
end_comment

begin_comment
comment|// CHECK-EL-SF-MICRO-NOT: "-L[[TC]]"
end_comment

begin_comment
comment|// CHECK-EL-SF-MICRO: "-L[[TC]]/../../../../mips-linux-gnu/libc/micromips/soft-float/el/lib/../lib"
end_comment

begin_comment
comment|// CHECK-EL-SF-MICRO: "-L[[TC]]/../../../../mips-linux-gnu/libc/micromips/soft-float/el/usr/lib/../lib"
end_comment

begin_comment
comment|// CHECK-EL-SF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/micromips/soft-float/el{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-EL-SF-MICRO: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/micromips/soft-float/el/usr/lib/../lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// = Little-endian, hard float, 64-bit
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips64el-linux-gnu \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/mips_cs_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-EL-HF-64 %s
end_comment

begin_comment
comment|// CHECK-EL-HF-64: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-EL-HF-64: "--sysroot=[[TC:[^"]+]]/../../../../mips-linux-gnu/libc/el"
end_comment

begin_comment
comment|// CHECK-EL-HF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/el/usr/lib/../lib64{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-EL-HF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/el/usr/lib/../lib64{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-EL-HF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/el/64{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-EL-HF-64: "-L[[TC]]/el/64"
end_comment

begin_comment
comment|// CHECK-EL-HF-64: "-L[[TC]]/../../../../mips-linux-gnu/lib/../lib64/el"
end_comment

begin_comment
comment|// CHECK-EL-HF-64: "-L[[TC]]/../../../../mips-linux-gnu/libc/el/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-EL-HF-64: "-L[[TC]]/../../../../mips-linux-gnu/libc/el/usr/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-EL-HF-64-NOT: "-L[[TC]]"
end_comment

begin_comment
comment|// CHECK-EL-HF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/el/64{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-EL-HF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/el/usr/lib/../lib64{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// = Little-endian, soft float, 64-bit
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips64el-linux-gnu -msoft-float \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain=%S/Inputs/mips_cs_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-EL-SF-64 %s
end_comment

begin_comment
comment|// CHECK-EL-SF-64: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-EL-SF-64: "--sysroot=[[TC:[^"]+]]/../../../../mips-linux-gnu/libc/soft-float/el"
end_comment

begin_comment
comment|// CHECK-EL-SF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/soft-float/el/usr/lib/../lib64{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-EL-SF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/soft-float/el/usr/lib/../lib64{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-EL-SF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/soft-float/el/64{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK-EL-SF-64: "-L[[TC]]/soft-float/el/64"
end_comment

begin_comment
comment|// CHECK-EL-SF-64: "-L[[TC]]/../../../../mips-linux-gnu/lib/../lib64/soft-float/el"
end_comment

begin_comment
comment|// CHECK-EL-SF-64: "-L[[TC]]/../../../../mips-linux-gnu/libc/soft-float/el/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-EL-SF-64: "-L[[TC]]/../../../../mips-linux-gnu/libc/soft-float/el/usr/lib/../lib64"
end_comment

begin_comment
comment|// CHECK-EL-SF-64-NOT: "-L[[TC]]"
end_comment

begin_comment
comment|// CHECK-EL-SF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/soft-float/el/64{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK-EL-SF-64: "{{.*}}/lib/gcc/mips-linux-gnu/4.6.3/../../../../mips-linux-gnu/libc/soft-float/el/usr/lib/../lib64{{/|\\\\}}crtn.o"
end_comment

end_unit

