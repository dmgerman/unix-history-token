begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///
end_comment

begin_comment
comment|/// Perform several driver tests for OpenMP offloading
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|// REQUIRES: clang-driver
end_comment

begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// REQUIRES: nvptx-registered-target
end_comment

begin_comment
comment|/// ###########################################################################
end_comment

begin_comment
comment|/// Check whether an invalid OpenMP target is specified:
end_comment

begin_comment
comment|// RUN:   %clang -### -fopenmp=libomp -fopenmp-targets=aaa-bbb-ccc-ddd %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-INVALID-TARGET %s
end_comment

begin_comment
comment|// CHK-INVALID-TARGET: error: OpenMP target is invalid: 'aaa-bbb-ccc-ddd'
end_comment

begin_comment
comment|/// ###########################################################################
end_comment

begin_comment
comment|/// Check warning for empty -fopenmp-targets
end_comment

begin_comment
comment|// RUN:   %clang -### -fopenmp=libomp -fopenmp-targets=  %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-EMPTY-OMPTARGETS %s
end_comment

begin_comment
comment|// CHK-EMPTY-OMPTARGETS: warning: joined argument expects additional value: '-fopenmp-targets='
end_comment

begin_comment
comment|/// ###########################################################################
end_comment

begin_comment
comment|/// Check error for no -fopenmp option
end_comment

begin_comment
comment|// RUN:   %clang -### -fopenmp-targets=powerpc64le-ibm-linux-gnu  %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-NO-FOPENMP %s
end_comment

begin_comment
comment|// RUN:   %clang -### -fopenmp=libgomp -fopenmp-targets=powerpc64le-ibm-linux-gnu  %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-NO-FOPENMP %s
end_comment

begin_comment
comment|// CHK-NO-FOPENMP: error: The option -fopenmp-targets must be used in conjunction with a -fopenmp option compatible with offloading, please use -fopenmp=libomp or -fopenmp=libiomp5.
end_comment

begin_comment
comment|/// ###########################################################################
end_comment

begin_comment
comment|/// Check warning for duplicate offloading targets.
end_comment

begin_comment
comment|// RUN:   %clang -### -ccc-print-phases -fopenmp=libomp -fopenmp-targets=powerpc64le-ibm-linux-gnu,powerpc64le-ibm-linux-gnu  %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-DUPLICATES %s
end_comment

begin_comment
comment|// CHK-DUPLICATES: warning: The OpenMP offloading target 'powerpc64le-ibm-linux-gnu' is similar to target 'powerpc64le-ibm-linux-gnu' already specified - will be ignored.
end_comment

begin_comment
comment|/// ###########################################################################
end_comment

begin_comment
comment|/// Check the phases graph when using a single target, different from the host.
end_comment

begin_comment
comment|/// We should have an offload action joining the host compile and device
end_comment

begin_comment
comment|/// preprocessor and another one joining the device linking outputs to the host
end_comment

begin_comment
comment|/// action.
end_comment

begin_comment
comment|// RUN:   %clang -ccc-print-phases -fopenmp=libomp -target powerpc64le-ibm-linux-gnu -fopenmp-targets=x86_64-pc-linux-gnu %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-PHASES %s
end_comment

begin_comment
comment|// CHK-PHASES: 0: input, "[[INPUT:.+\.c]]", c, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES: 1: preprocessor, {0}, cpp-output, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES: 2: compiler, {1}, ir, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES: 3: backend, {2}, assembler, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES: 4: assembler, {3}, object, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES: 5: linker, {4}, image, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES: 6: input, "[[INPUT]]", c, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES: 7: preprocessor, {6}, cpp-output, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES: 8: compiler, {7}, ir, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES: 9: offload, "host-openmp (powerpc64le-ibm-linux-gnu)" {2}, "device-openmp (x86_64-pc-linux-gnu)" {8}, ir
end_comment

begin_comment
comment|// CHK-PHASES: 10: backend, {9}, assembler, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES: 11: assembler, {10}, object, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES: 12: linker, {11}, image, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES: 13: offload, "host-openmp (powerpc64le-ibm-linux-gnu)" {5}, "device-openmp (x86_64-pc-linux-gnu)" {12}, image
end_comment

begin_comment
comment|/// ###########################################################################
end_comment

begin_comment
comment|/// Check the phases when using multiple targets. Here we also add a library to
end_comment

begin_comment
comment|/// make sure it is treated as input by the device.
end_comment

begin_comment
comment|// RUN:   %clang -ccc-print-phases -lsomelib -fopenmp=libomp -target powerpc64-ibm-linux-gnu -fopenmp-targets=x86_64-pc-linux-gnu,powerpc64-ibm-linux-gnu %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-PHASES-LIB %s
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 0: input, "somelib", object, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 1: input, "[[INPUT:.+\.c]]", c, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 2: preprocessor, {1}, cpp-output, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 3: compiler, {2}, ir, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 4: backend, {3}, assembler, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 5: assembler, {4}, object, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 6: linker, {0, 5}, image, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 7: input, "somelib", object, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 8: input, "[[INPUT]]", c, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 9: preprocessor, {8}, cpp-output, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 10: compiler, {9}, ir, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 11: offload, "host-openmp (powerpc64-ibm-linux-gnu)" {3}, "device-openmp (x86_64-pc-linux-gnu)" {10}, ir
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 12: backend, {11}, assembler, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 13: assembler, {12}, object, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 14: linker, {7, 13}, image, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 15: input, "somelib", object, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 16: input, "[[INPUT]]", c, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 17: preprocessor, {16}, cpp-output, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 18: compiler, {17}, ir, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 19: offload, "host-openmp (powerpc64-ibm-linux-gnu)" {3}, "device-openmp (powerpc64-ibm-linux-gnu)" {18}, ir
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 20: backend, {19}, assembler, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 21: assembler, {20}, object, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 22: linker, {15, 21}, image, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-LIB: 23: offload, "host-openmp (powerpc64-ibm-linux-gnu)" {6}, "device-openmp (x86_64-pc-linux-gnu)" {14}, "device-openmp (powerpc64-ibm-linux-gnu)" {22}, image
end_comment

begin_comment
comment|/// ###########################################################################
end_comment

begin_comment
comment|/// Check the phases when using multiple targets and multiple source files
end_comment

begin_comment
comment|// RUN:   echo " "> %t.c
end_comment

begin_comment
comment|// RUN:   %clang -ccc-print-phases -lsomelib -fopenmp=libomp -target powerpc64-ibm-linux-gnu -fopenmp-targets=x86_64-pc-linux-gnu,powerpc64-ibm-linux-gnu %s %t.c 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-PHASES-FILES %s
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 0: input, "somelib", object, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 1: input, "[[INPUT1:.+\.c]]", c, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 2: preprocessor, {1}, cpp-output, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 3: compiler, {2}, ir, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 4: backend, {3}, assembler, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 5: assembler, {4}, object, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 6: input, "[[INPUT2:.+\.c]]", c, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 7: preprocessor, {6}, cpp-output, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 8: compiler, {7}, ir, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 9: backend, {8}, assembler, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 10: assembler, {9}, object, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 11: linker, {0, 5, 10}, image, (host-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 12: input, "somelib", object, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 13: input, "[[INPUT1]]", c, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 14: preprocessor, {13}, cpp-output, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 15: compiler, {14}, ir, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 16: offload, "host-openmp (powerpc64-ibm-linux-gnu)" {3}, "device-openmp (x86_64-pc-linux-gnu)" {15}, ir
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 17: backend, {16}, assembler, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 18: assembler, {17}, object, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 19: input, "[[INPUT2]]", c, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 20: preprocessor, {19}, cpp-output, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 21: compiler, {20}, ir, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 22: offload, "host-openmp (powerpc64-ibm-linux-gnu)" {8}, "device-openmp (x86_64-pc-linux-gnu)" {21}, ir
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 23: backend, {22}, assembler, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 24: assembler, {23}, object, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 25: linker, {12, 18, 24}, image, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 26: input, "somelib", object, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 27: input, "[[INPUT1]]", c, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 28: preprocessor, {27}, cpp-output, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 29: compiler, {28}, ir, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 30: offload, "host-openmp (powerpc64-ibm-linux-gnu)" {3}, "device-openmp (powerpc64-ibm-linux-gnu)" {29}, ir
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 31: backend, {30}, assembler, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 32: assembler, {31}, object, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 33: input, "[[INPUT2]]", c, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 34: preprocessor, {33}, cpp-output, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 35: compiler, {34}, ir, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 36: offload, "host-openmp (powerpc64-ibm-linux-gnu)" {8}, "device-openmp (powerpc64-ibm-linux-gnu)" {35}, ir
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 37: backend, {36}, assembler, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 38: assembler, {37}, object, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 39: linker, {26, 32, 38}, image, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-FILES: 40: offload, "host-openmp (powerpc64-ibm-linux-gnu)" {11}, "device-openmp (x86_64-pc-linux-gnu)" {25}, "device-openmp (powerpc64-ibm-linux-gnu)" {39}, image
end_comment

begin_comment
comment|/// ###########################################################################
end_comment

begin_comment
comment|/// Check the phases graph when using a single GPU target, and check the OpenMP
end_comment

begin_comment
comment|/// and CUDA phases are articulated correctly.
end_comment

begin_comment
comment|// RUN:   %clang -ccc-print-phases -fopenmp=libomp -target powerpc64le-ibm-linux-gnu -fopenmp-targets=nvptx64-nvidia-cuda -x cuda %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-PHASES-WITH-CUDA %s
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 0: input, "[[INPUT:.+\.c]]", cuda, (host-cuda-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 1: preprocessor, {0}, cuda-cpp-output, (host-cuda-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 2: compiler, {1}, ir, (host-cuda-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 3: input, "[[INPUT]]", cuda, (device-cuda, sm_20)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 4: preprocessor, {3}, cuda-cpp-output, (device-cuda, sm_20)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 5: compiler, {4}, ir, (device-cuda, sm_20)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 6: backend, {5}, assembler, (device-cuda, sm_20)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 7: assembler, {6}, object, (device-cuda, sm_20)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 8: offload, "device-cuda (nvptx64-nvidia-cuda:sm_20)" {7}, object
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 9: offload, "device-cuda (nvptx64-nvidia-cuda:sm_20)" {6}, assembler
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 10: linker, {8, 9}, cuda-fatbin, (device-cuda)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 11: offload, "host-cuda-openmp (powerpc64le-ibm-linux-gnu)" {2}, "device-cuda (nvptx64-nvidia-cuda)" {10}, ir
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 12: backend, {11}, assembler, (host-cuda-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 13: assembler, {12}, object, (host-cuda-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 14: linker, {13}, image, (host-cuda-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 15: input, "[[INPUT]]", cuda, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 16: preprocessor, {15}, cuda-cpp-output, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 17: compiler, {16}, ir, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 18: offload, "host-cuda-openmp (powerpc64le-ibm-linux-gnu)" {2}, "device-openmp (nvptx64-nvidia-cuda)" {17}, ir
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 19: backend, {18}, assembler, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 20: assembler, {19}, object, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 21: linker, {20}, image, (device-openmp)
end_comment

begin_comment
comment|// CHK-PHASES-WITH-CUDA: 22: offload, "host-cuda-openmp (powerpc64le-ibm-linux-gnu)" {14}, "device-openmp (nvptx64-nvidia-cuda)" {21}, image
end_comment

begin_comment
comment|/// ###########################################################################
end_comment

begin_comment
comment|/// Check of the commands passed to each tool when using valid OpenMP targets.
end_comment

begin_comment
comment|/// Here we also check that offloading does not break the use of integrated
end_comment

begin_comment
comment|/// assembler. It does however preclude the merge of the host compile and
end_comment

begin_comment
comment|/// backend phases. There are also two offloading specific options:
end_comment

begin_comment
comment|/// -fopenmp-is-device: will tell the frontend that it will generate code for a
end_comment

begin_comment
comment|/// target.
end_comment

begin_comment
comment|/// -fopenmp-host-ir-file-path: specifies the host IR file that can be loaded by
end_comment

begin_comment
comment|/// the target code generation to gather information about which declaration
end_comment

begin_comment
comment|/// really need to be emitted.
end_comment

begin_comment
comment|/// We use -fopenmp-dump-offload-linker-script to dump the linker script and
end_comment

begin_comment
comment|/// check its contents.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|// RUN:   %clang -### -fopenmp=libomp -o %t.out -target powerpc64le-linux -fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu %s -fopenmp-dump-offload-linker-script -no-canonical-prefixes 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-COMMANDS -check-prefix=CHK-LKS -check-prefix=CHK-LKS-REG %s
end_comment

begin_comment
comment|// RUN:   %clang -### -fopenmp=libomp -o %t.out -target powerpc64le-linux -fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu %s -save-temps -fopenmp-dump-offload-linker-script -no-canonical-prefixes 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-COMMANDS-ST -check-prefix=CHK-LKS -check-prefix=CHK-LKS-ST %s
end_comment

begin_comment
comment|// Make sure we are not dumping the script unless the user requested it.
end_comment

begin_comment
comment|// RUN:   %clang -### -fopenmp=libomp -o %t.out -target powerpc64le-linux -fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu %s -no-canonical-prefixes 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-LKS-NODUMP %s
end_comment

begin_comment
comment|// RUN:   %clang -### -fopenmp=libomp -o %t.out -target powerpc64le-linux -fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu %s -save-temps -no-canonical-prefixes 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-LKS-NODUMP %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check the linker script contains what we expect.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHK-LKS: /*
end_comment

begin_comment
comment|// CHK-LKS:                   OpenMP Offload Linker Script
end_comment

begin_comment
comment|// CHK-LKS:             *** Automatically generated by Clang ***
end_comment

begin_comment
comment|// CHK-LKS-NODUMP-NOT:  OpenMP Offload Linker Script.
end_comment

begin_comment
comment|// CHK-LKS: */
end_comment

begin_comment
comment|// CHK-LKS: TARGET(binary)
end_comment

begin_comment
comment|// CHK-LKS-REG: INPUT([[T1BIN:.+\.out]])
end_comment

begin_comment
comment|// CHK-LKS-REG: INPUT([[T2BIN:.+\.out]])
end_comment

begin_comment
comment|// CHK-LKS-ST: INPUT([[T1BIN:.+\.out-openmp-powerpc64le-ibm-linux-gnu]])
end_comment

begin_comment
comment|// CHK-LKS-ST: INPUT([[T2BIN:.+\.out-openmp-x86_64-pc-linux-gnu]])
end_comment

begin_comment
comment|// CHK-LKS: SECTIONS
end_comment

begin_comment
comment|// CHK-LKS: {
end_comment

begin_comment
comment|// CHK-LKS:   .omp_offloading.powerpc64le-ibm-linux-gnu :
end_comment

begin_comment
comment|// CHK-LKS:   ALIGN(0x10)
end_comment

begin_comment
comment|// CHK-LKS:   {
end_comment

begin_comment
comment|// CHK-LKS:     PROVIDE_HIDDEN(.omp_offloading.img_start.powerpc64le-ibm-linux-gnu = .);
end_comment

begin_comment
comment|// CHK-LKS:     [[T1BIN]]
end_comment

begin_comment
comment|// CHK-LKS:     PROVIDE_HIDDEN(.omp_offloading.img_end.powerpc64le-ibm-linux-gnu = .);
end_comment

begin_comment
comment|// CHK-LKS:   }
end_comment

begin_comment
comment|// CHK-LKS:   .omp_offloading.x86_64-pc-linux-gnu :
end_comment

begin_comment
comment|// CHK-LKS:   ALIGN(0x10)
end_comment

begin_comment
comment|// CHK-LKS:   {
end_comment

begin_comment
comment|// CHK-LKS:     PROVIDE_HIDDEN(.omp_offloading.img_start.x86_64-pc-linux-gnu = .);
end_comment

begin_comment
comment|// CHK-LKS:     [[T2BIN]]
end_comment

begin_comment
comment|// CHK-LKS:     PROVIDE_HIDDEN(.omp_offloading.img_end.x86_64-pc-linux-gnu = .);
end_comment

begin_comment
comment|// CHK-LKS:   }
end_comment

begin_comment
comment|// CHK-LKS:   .omp_offloading.entries :
end_comment

begin_comment
comment|// CHK-LKS:   ALIGN(0x10)
end_comment

begin_comment
comment|// CHK-LKS:   SUBALIGN(0x01)
end_comment

begin_comment
comment|// CHK-LKS:   {
end_comment

begin_comment
comment|// CHK-LKS:     PROVIDE_HIDDEN(.omp_offloading.entries_begin = .);
end_comment

begin_comment
comment|// CHK-LKS:     *(.omp_offloading.entries)
end_comment

begin_comment
comment|// CHK-LKS:     PROVIDE_HIDDEN(.omp_offloading.entries_end = .);
end_comment

begin_comment
comment|// CHK-LKS:   }
end_comment

begin_comment
comment|// CHK-LKS: }
end_comment

begin_comment
comment|// CHK-LKS: INSERT BEFORE .data
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Generate host BC file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHK-COMMANDS: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-emit-llvm-bc" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-SAME: [[HOSTBC:[^\\/]+\.bc]]" "-x" "c" "
end_comment

begin_comment
comment|// CHK-COMMANDS-SAME: [[INPUT:[^\\/]+\.c]]" "-fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu"
end_comment

begin_comment
comment|// CHK-COMMANDS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-E" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[HOSTPP:[^\\/]+\.i]]" "-x" "c" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[INPUT:[^\\/]+\.c]]"
end_comment

begin_comment
comment|// CHK-COMMANDS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-emit-llvm-bc" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[HOSTBC:[^\\/]+\.bc]]" "-x" "cpp-output" "{{.*}}[[HOSTPP]]" "-fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Compile for the powerpc device.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHK-COMMANDS: clang{{.*}}" "-cc1" "-triple" "powerpc64le-ibm-linux-gnu" "-emit-obj" {{.*}}"-pic-level" "2" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-SAME: [[T1OBJ:[^\\/]+\.o]]" "-x" "c" "{{.*}}[[INPUT]]" "-fopenmp-is-device" "-fopenmp-host-ir-file-path" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-COMMANDS: ld{{(\.exe)?}}" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-SAME: [[T1BIN:[^\\/]+\.out]]" {{.*}}"{{.*}}[[T1OBJ]]"
end_comment

begin_comment
comment|// CHK-COMMANDS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le-ibm-linux-gnu" "-E" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[T1PP:[^\\/]+\.i]]" "-x" "c" "{{.*}}[[INPUT]]"
end_comment

begin_comment
comment|// CHK-COMMANDS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le-ibm-linux-gnu" "-emit-llvm-bc" {{.*}}"-pic-level" "2" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[T1BC:[^\\/]+\.bc]]" "-x" "cpp-output" "{{.*}}[[T1PP]]" "-fopenmp-is-device" "-fopenmp-host-ir-file-path" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-COMMANDS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le-ibm-linux-gnu" "-S" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[T1ASM:[^\\/]+\.s]]" "-x" "ir" "{{.*}}[[T1BC]]"
end_comment

begin_comment
comment|// CHK-COMMANDS-ST: clang{{.*}}" "-cc1as" "-triple" "powerpc64le-ibm-linux-gnu" "-filetype" "obj" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[T1OBJ:[^\\/]+\.o]]" "{{.*}}[[T1ASM]]"
end_comment

begin_comment
comment|// CHK-COMMANDS-ST: ld{{(\.exe)?}}" {{.*}}"-shared" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[T1BIN:[^\\/]+\.out-openmp-powerpc64le-ibm-linux-gnu]]" {{.*}}"{{.*}}[[T1OBJ]]"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Compile for the x86 device.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHK-COMMANDS: clang{{.*}}" "-cc1" "-triple" "x86_64-pc-linux-gnu" "-emit-obj" {{.*}}"-pic-level" "2" {{.*}}"-fopenmp"  {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-SAME: [[T2OBJ:[^\\/]+\.o]]" "-x" "c" "{{.*}}[[INPUT]]" "-fopenmp-is-device" "-fopenmp-host-ir-file-path" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-COMMANDS: ld{{(\.exe)?}}" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-SAME: [[T2BIN:[^\\/]+\.out]]" {{.*}}"{{.*}}[[T2OBJ]]"
end_comment

begin_comment
comment|// CHK-COMMANDS-ST: clang{{.*}}" "-cc1" "-triple" "x86_64-pc-linux-gnu" "-E" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[T2PP:[^\\/]+\.i]]" "-x" "c" "{{.*}}[[INPUT]]"
end_comment

begin_comment
comment|// CHK-COMMANDS-ST: clang{{.*}}" "-cc1" "-triple" "x86_64-pc-linux-gnu" "-emit-llvm-bc" {{.*}}"-pic-level" "2" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[T2BC:[^\\/]+\.bc]]" "-x" "cpp-output" "{{.*}}[[T2PP]]" "-fopenmp-is-device" "-fopenmp-host-ir-file-path" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-COMMANDS-ST: clang{{.*}}" "-cc1" "-triple" "x86_64-pc-linux-gnu" "-S" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[T2ASM:[^\\/]+\.s]]" "-x" "ir" "{{.*}}[[T2BC]]"
end_comment

begin_comment
comment|// CHK-COMMANDS-ST: clang{{.*}}" "-cc1as" "-triple" "x86_64-pc-linux-gnu" "-filetype" "obj" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[T2OBJ:[^\\/]+\.o]]" "{{.*}}[[T2ASM]]"
end_comment

begin_comment
comment|// CHK-COMMANDS-ST: ld{{(\.exe)?}}" {{.*}}"-shared" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[T2BIN:[^\\/]+\.out-openmp-x86_64-pc-linux-gnu]]" {{.*}}"{{.*}}[[T2OBJ]]"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Generate host object from the BC file and link using the linker script.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHK-COMMANDS: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-emit-obj" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-SAME: [[HOSTOBJ:[^\\/]+\.o]]" "-x" "ir" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-COMMANDS: ld{{(\.exe)?}}" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-SAME: [[HOSTBIN:[^\\/]+\.out]]"  {{.*}}"-lomptarget" {{.*}}"-T" "
end_comment

begin_comment
comment|// CHK-COMMANDS-SAME: [[HOSTLK:[^\\/]+\.lk]]"
end_comment

begin_comment
comment|// CHK-COMMANDS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-S" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[HOSTASM:[^\\/]+\.s]]" "-x" "ir" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-COMMANDS-ST: clang{{.*}}" "-cc1as" "-triple" "powerpc64le--linux" "-filetype" "obj" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[HOSTOBJ:[^\\/]+\.o]]" "{{.*}}[[HOSTASM]]"
end_comment

begin_comment
comment|// CHK-COMMANDS-ST: ld{{(\.exe)?}}" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[HOSTBIN:[^\\/]+\.out]]"  {{.*}}"-lomptarget" {{.*}}"-T" "
end_comment

begin_comment
comment|// CHK-COMMANDS-ST-SAME: [[HOSTLK:[^\\/]+\.lk]]"
end_comment

begin_comment
comment|/// ###########################################################################
end_comment

begin_comment
comment|/// Check separate compilation with offloading - bundling actions
end_comment

begin_comment
comment|// RUN:   %clang -### -ccc-print-phases -fopenmp=libomp -c -o %t.o -lsomelib -target powerpc64le-linux -fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu %s -no-canonical-prefixes 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-BUACTIONS %s
end_comment

begin_comment
comment|// CHK-BUACTIONS: 0: input, "[[INPUT:.+\.c]]", c, (host-openmp)
end_comment

begin_comment
comment|// CHK-BUACTIONS: 1: preprocessor, {0}, cpp-output, (host-openmp)
end_comment

begin_comment
comment|// CHK-BUACTIONS: 2: compiler, {1}, ir, (host-openmp)
end_comment

begin_comment
comment|// CHK-BUACTIONS: 3: input, "[[INPUT]]", c, (device-openmp)
end_comment

begin_comment
comment|// CHK-BUACTIONS: 4: preprocessor, {3}, cpp-output, (device-openmp)
end_comment

begin_comment
comment|// CHK-BUACTIONS: 5: compiler, {4}, ir, (device-openmp)
end_comment

begin_comment
comment|// CHK-BUACTIONS: 6: offload, "host-openmp (powerpc64le--linux)" {2}, "device-openmp (powerpc64le-ibm-linux-gnu)" {5}, ir
end_comment

begin_comment
comment|// CHK-BUACTIONS: 7: backend, {6}, assembler, (device-openmp)
end_comment

begin_comment
comment|// CHK-BUACTIONS: 8: assembler, {7}, object, (device-openmp)
end_comment

begin_comment
comment|// CHK-BUACTIONS: 9: offload, "device-openmp (powerpc64le-ibm-linux-gnu)" {8}, object
end_comment

begin_comment
comment|// CHK-BUACTIONS: 10: input, "[[INPUT]]", c, (device-openmp)
end_comment

begin_comment
comment|// CHK-BUACTIONS: 11: preprocessor, {10}, cpp-output, (device-openmp)
end_comment

begin_comment
comment|// CHK-BUACTIONS: 12: compiler, {11}, ir, (device-openmp)
end_comment

begin_comment
comment|// CHK-BUACTIONS: 13: offload, "host-openmp (powerpc64le--linux)" {2}, "device-openmp (x86_64-pc-linux-gnu)" {12}, ir
end_comment

begin_comment
comment|// CHK-BUACTIONS: 14: backend, {13}, assembler, (device-openmp)
end_comment

begin_comment
comment|// CHK-BUACTIONS: 15: assembler, {14}, object, (device-openmp)
end_comment

begin_comment
comment|// CHK-BUACTIONS: 16: offload, "device-openmp (x86_64-pc-linux-gnu)" {15}, object
end_comment

begin_comment
comment|// CHK-BUACTIONS: 17: backend, {2}, assembler, (host-openmp)
end_comment

begin_comment
comment|// CHK-BUACTIONS: 18: assembler, {17}, object, (host-openmp)
end_comment

begin_comment
comment|// CHK-BUACTIONS: 19: clang-offload-bundler, {9, 16, 18}, object, (host-openmp)
end_comment

begin_comment
comment|/// ###########################################################################
end_comment

begin_comment
comment|/// Check separate compilation with offloading - unbundling actions
end_comment

begin_comment
comment|// RUN:   touch %t.i
end_comment

begin_comment
comment|// RUN:   %clang -### -ccc-print-phases -fopenmp=libomp -o %t.out -lsomelib -target powerpc64le-linux -fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu %t.i -no-canonical-prefixes 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-UBACTIONS %s
end_comment

begin_comment
comment|// CHK-UBACTIONS: 0: input, "somelib", object, (host-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 1: input, "[[INPUT:.+\.i]]", cpp-output, (host-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 2: clang-offload-unbundler, {1}, cpp-output, (host-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 3: compiler, {2}, ir, (host-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 4: backend, {3}, assembler, (host-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 5: assembler, {4}, object, (host-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 6: linker, {0, 5}, image, (host-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 7: input, "somelib", object, (device-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 8: compiler, {2}, ir, (device-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 9: offload, "host-openmp (powerpc64le--linux)" {3}, "device-openmp (powerpc64le-ibm-linux-gnu)" {8}, ir
end_comment

begin_comment
comment|// CHK-UBACTIONS: 10: backend, {9}, assembler, (device-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 11: assembler, {10}, object, (device-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 12: linker, {7, 11}, image, (device-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 13: input, "somelib", object, (device-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 14: compiler, {2}, ir, (device-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 15: offload, "host-openmp (powerpc64le--linux)" {3}, "device-openmp (x86_64-pc-linux-gnu)" {14}, ir
end_comment

begin_comment
comment|// CHK-UBACTIONS: 16: backend, {15}, assembler, (device-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 17: assembler, {16}, object, (device-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 18: linker, {13, 17}, image, (device-openmp)
end_comment

begin_comment
comment|// CHK-UBACTIONS: 19: offload, "host-openmp (powerpc64le--linux)" {6}, "device-openmp (powerpc64le-ibm-linux-gnu)" {12}, "device-openmp (x86_64-pc-linux-gnu)" {18}, image
end_comment

begin_comment
comment|/// ###########################################################################
end_comment

begin_comment
comment|/// Check separate compilation with offloading - unbundling/bundling actions
end_comment

begin_comment
comment|// RUN:   touch %t.i
end_comment

begin_comment
comment|// RUN:   %clang -### -ccc-print-phases -fopenmp=libomp -c -o %t.o -lsomelib -target powerpc64le-linux -fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu %t.i -no-canonical-prefixes 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-UBUACTIONS %s
end_comment

begin_comment
comment|// CHK-UBUACTIONS: 0: input, "[[INPUT:.+\.i]]", cpp-output, (host-openmp)
end_comment

begin_comment
comment|// CHK-UBUACTIONS: 1: clang-offload-unbundler, {0}, cpp-output, (host-openmp)
end_comment

begin_comment
comment|// CHK-UBUACTIONS: 2: compiler, {1}, ir, (host-openmp)
end_comment

begin_comment
comment|// CHK-UBUACTIONS: 3: compiler, {1}, ir, (device-openmp)
end_comment

begin_comment
comment|// CHK-UBUACTIONS: 4: offload, "host-openmp (powerpc64le--linux)" {2}, "device-openmp (powerpc64le-ibm-linux-gnu)" {3}, ir
end_comment

begin_comment
comment|// CHK-UBUACTIONS: 5: backend, {4}, assembler, (device-openmp)
end_comment

begin_comment
comment|// CHK-UBUACTIONS: 6: assembler, {5}, object, (device-openmp)
end_comment

begin_comment
comment|// CHK-UBUACTIONS: 7: offload, "device-openmp (powerpc64le-ibm-linux-gnu)" {6}, object
end_comment

begin_comment
comment|// CHK-UBUACTIONS: 8: compiler, {1}, ir, (device-openmp)
end_comment

begin_comment
comment|// CHK-UBUACTIONS: 9: offload, "host-openmp (powerpc64le--linux)" {2}, "device-openmp (x86_64-pc-linux-gnu)" {8}, ir
end_comment

begin_comment
comment|// CHK-UBUACTIONS: 10: backend, {9}, assembler, (device-openmp)
end_comment

begin_comment
comment|// CHK-UBUACTIONS: 11: assembler, {10}, object, (device-openmp)
end_comment

begin_comment
comment|// CHK-UBUACTIONS: 12: offload, "device-openmp (x86_64-pc-linux-gnu)" {11}, object
end_comment

begin_comment
comment|// CHK-UBUACTIONS: 13: backend, {2}, assembler, (host-openmp)
end_comment

begin_comment
comment|// CHK-UBUACTIONS: 14: assembler, {13}, object, (host-openmp)
end_comment

begin_comment
comment|// CHK-UBUACTIONS: 15: clang-offload-bundler, {7, 12, 14}, object, (host-openmp)
end_comment

begin_comment
comment|/// ###########################################################################
end_comment

begin_comment
comment|/// Check separate compilation with offloading - bundling jobs construct
end_comment

begin_comment
comment|// RUN:   %clang -### -fopenmp=libomp -c -o %t.o -lsomelib -target powerpc64le-linux -fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu %s -no-canonical-prefixes 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-BUJOBS %s
end_comment

begin_comment
comment|// RUN:   %clang -### -fopenmp=libomp -c -o %t.o -lsomelib -target powerpc64le-linux -fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu %s -save-temps -no-canonical-prefixes 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-BUJOBS-ST %s
end_comment

begin_comment
comment|// Create host BC.
end_comment

begin_comment
comment|// CHK-BUJOBS: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-emit-llvm-bc"  {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-BUJOBS-SAME: [[HOSTBC:[^\\/]+\.bc]]" "-x" "c" "
end_comment

begin_comment
comment|// CHK-BUJOBS-SAME: [[INPUT:[^\\/]+\.c]]" "-fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu"
end_comment

begin_comment
comment|// CHK-BUJOBS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-E"  {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-BUJOBS-ST-SAME: [[HOSTPP:[^\\/]+\.i]]" "-x" "c" "
end_comment

begin_comment
comment|// CHK-BUJOBS-ST-SAME: [[INPUT:[^\\/]+\.c]]"
end_comment

begin_comment
comment|// CHK-BUJOBS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-emit-llvm-bc"  {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-BUJOBS-ST-SAME: [[HOSTBC:[^\\/]+\.bc]]" "-x" "cpp-output" "{{.*}}[[HOSTPP]]" "-fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu"
end_comment

begin_comment
comment|// Create target 1 object.
end_comment

begin_comment
comment|// CHK-BUJOBS: clang{{.*}}" "-cc1" "-triple" "powerpc64le-ibm-linux-gnu" "-emit-obj" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-BUJOBS-SAME: [[T1OBJ:[^\\/]+\.o]]" "-x" "c" "{{.*}}[[INPUT]]" "-fopenmp-is-device" "-fopenmp-host-ir-file-path" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-BUJOBS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le-ibm-linux-gnu" "-E" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-BUJOBS-ST-SAME: [[T1PP:[^\\/]+\.i]]" "-x" "c" "{{.*}}[[INPUT]]"
end_comment

begin_comment
comment|// CHK-BUJOBS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le-ibm-linux-gnu" "-emit-llvm-bc" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-BUJOBS-ST-SAME: [[T1BC:[^\\/]+\.bc]]" "-x" "cpp-output" "{{.*}}[[T1PP]]" "-fopenmp-is-device" "-fopenmp-host-ir-file-path" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-BUJOBS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le-ibm-linux-gnu" "-S" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-BUJOBS-ST-SAME: [[T1ASM:[^\\/]+\.s]]" "-x" "ir" "{{.*}}[[T1BC]]"
end_comment

begin_comment
comment|// CHK-BUJOBS-ST: clang{{.*}}" "-cc1as" "-triple" "powerpc64le-ibm-linux-gnu" "-filetype" "obj" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-BUJOBS-ST-SAME: [[T1OBJ:[^\\/]+\.o]]" "{{.*}}[[T1ASM]]"
end_comment

begin_comment
comment|// Create target 2 object.
end_comment

begin_comment
comment|// CHK-BUJOBS: clang{{.*}}" "-cc1" "-triple" "x86_64-pc-linux-gnu" "-emit-obj" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-BUJOBS-SAME: [[T2OBJ:[^\\/]+\.o]]" "-x" "c" "{{.*}}[[INPUT]]" "-fopenmp-is-device" "-fopenmp-host-ir-file-path" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-BUJOBS-ST: clang{{.*}}" "-cc1" "-triple" "x86_64-pc-linux-gnu" "-E" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-BUJOBS-ST-SAME: [[T2PP:[^\\/]+\.i]]" "-x" "c" "{{.*}}[[INPUT]]"
end_comment

begin_comment
comment|// CHK-BUJOBS-ST: clang{{.*}}" "-cc1" "-triple" "x86_64-pc-linux-gnu" "-emit-llvm-bc" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-BUJOBS-ST-SAME: [[T2BC:[^\\/]+\.bc]]" "-x" "cpp-output" "{{.*}}[[T2PP]]" "-fopenmp-is-device" "-fopenmp-host-ir-file-path" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-BUJOBS-ST: clang{{.*}}" "-cc1" "-triple" "x86_64-pc-linux-gnu" "-S" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-BUJOBS-ST-SAME: [[T2ASM:[^\\/]+\.s]]" "-x" "ir" "{{.*}}[[T2BC]]"
end_comment

begin_comment
comment|// CHK-BUJOBS-ST: clang{{.*}}" "-cc1as" "-triple" "x86_64-pc-linux-gnu" "-filetype" "obj" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-BUJOBS-ST-SAME: [[T2OBJ:[^\\/]+\.o]]" "{{.*}}[[T2ASM]]"
end_comment

begin_comment
comment|// Create host object and bundle.
end_comment

begin_comment
comment|// CHK-BUJOBS: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-emit-obj" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-BUJOBS-SAME: [[HOSTOBJ:[^\\/]+\.o]]" "-x" "ir" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-BUJOBS: clang-offload-bundler{{.*}}" "-type=o" "-targets=openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu,host-powerpc64le--linux" "-outputs=
end_comment

begin_comment
comment|// CHK-BUJOBS-SAME: [[RES:[^\\/]+\.o]]" "-inputs={{.*}}[[T1OBJ]],{{.*}}[[T2OBJ]],{{.*}}[[HOSTOBJ]]"
end_comment

begin_comment
comment|// CHK-BUJOBS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-S" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-BUJOBS-ST-SAME: [[HOSTASM:[^\\/]+\.s]]" "-x" "ir" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-BUJOBS-ST: clang{{.*}}" "-cc1as" "-triple" "powerpc64le--linux" "-filetype" "obj" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-BUJOBS-ST-SAME: [[HOSTOBJ:[^\\/]+\.o]]" "{{.*}}[[HOSTASM]]"
end_comment

begin_comment
comment|// CHK-BUJOBS-ST: clang-offload-bundler{{.*}}" "-type=o" "-targets=openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu,host-powerpc64le--linux" "-outputs=
end_comment

begin_comment
comment|// CHK-BUJOBS-ST-SAME: [[RES:[^\\/]+\.o]]" "-inputs={{.*}}[[T1OBJ]],{{.*}}[[T2OBJ]],{{.*}}[[HOSTOBJ]]"
end_comment

begin_comment
comment|/// ###########################################################################
end_comment

begin_comment
comment|/// Check separate compilation with offloading - unbundling jobs construct
end_comment

begin_comment
comment|// RUN:   touch %t.i
end_comment

begin_comment
comment|// RUN:   %clang -###  -fopenmp=libomp -o %t.out -lsomelib -target powerpc64le-linux -fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu %t.i -no-canonical-prefixes 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-UBJOBS %s
end_comment

begin_comment
comment|// RUN:   %clang -### -fopenmp=libomp -o %t.out -lsomelib -target powerpc64le-linux -fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu %t.i -save-temps -no-canonical-prefixes 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-UBJOBS-ST %s
end_comment

begin_comment
comment|// RUN:   touch %t.o
end_comment

begin_comment
comment|// RUN:   %clang -###  -fopenmp=libomp -o %t.out -lsomelib -target powerpc64le-linux -fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu %t.o -no-canonical-prefixes 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-UBJOBS2 %s
end_comment

begin_comment
comment|// RUN:   %clang -### -fopenmp=libomp -o %t.out -lsomelib -target powerpc64le-linux -fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu %t.o -save-temps -no-canonical-prefixes 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-UBJOBS2-ST %s
end_comment

begin_comment
comment|// Unbundle and create host BC.
end_comment

begin_comment
comment|// CHK-UBJOBS: clang-offload-bundler{{.*}}" "-type=i" "-targets=host-powerpc64le--linux,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu" "-inputs=
end_comment

begin_comment
comment|// CHK-UBJOBS-SAME: [[INPUT:[^\\/]+\.i]]" "-outputs=
end_comment

begin_comment
comment|// CHK-UBJOBS-SAME: [[HOSTPP:[^\\/]+\.i]],
end_comment

begin_comment
comment|// CHK-UBJOBS-SAME: [[T1PP:[^\\/]+\.i]],
end_comment

begin_comment
comment|// CHK-UBJOBS-SAME: [[T2PP:[^\\/]+\.i]]" "-unbundle"
end_comment

begin_comment
comment|// CHK-UBJOBS: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-emit-llvm-bc"  {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-SAME: [[HOSTBC:[^\\/]+\.bc]]" "-x" "cpp-output" "{{.*}}[[HOSTPP]]" "-fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu"
end_comment

begin_comment
comment|// CHK-UBJOBS-ST: clang-offload-bundler{{.*}}" "-type=i" "-targets=host-powerpc64le--linux,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu" "-inputs=
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[INPUT:[^\\/]+\.i]]" "-outputs=
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[HOSTPP:[^\\/,]+\.i]],
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[T1PP:[^\\/,]+\.i]],
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[T2PP:[^\\/,]+\.i]]" "-unbundle"
end_comment

begin_comment
comment|// CHK-UBJOBS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-emit-llvm-bc"  {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[HOSTBC:[^\\/]+\.bc]]" "-x" "cpp-output" "{{.*}}[[HOSTPP]]" "-fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu"
end_comment

begin_comment
comment|// Create target 1 object.
end_comment

begin_comment
comment|// CHK-UBJOBS: clang{{.*}}" "-cc1" "-triple" "powerpc64le-ibm-linux-gnu" "-emit-obj" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-SAME: [[T1OBJ:[^\\/]+\.o]]" "-x" "cpp-output" "{{.*}}[[T1PP]]" "-fopenmp-is-device" "-fopenmp-host-ir-file-path" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-UBJOBS: ld{{(\.exe)?}}" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-SAME: [[T1BIN:[^\\/]+\.out]]" {{.*}}"{{.*}}[[T1OBJ]]"
end_comment

begin_comment
comment|// CHK-UBJOBS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le-ibm-linux-gnu" "-emit-llvm-bc" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[T1BC:[^\\/]+\.bc]]" "-x" "cpp-output" "{{.*}}[[T1PP]]" "-fopenmp-is-device" "-fopenmp-host-ir-file-path" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-UBJOBS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le-ibm-linux-gnu" "-S" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[T1ASM:[^\\/]+\.s]]" "-x" "ir" "{{.*}}[[T1BC]]"
end_comment

begin_comment
comment|// CHK-UBJOBS-ST: clang{{.*}}" "-cc1as" "-triple" "powerpc64le-ibm-linux-gnu" "-filetype" "obj" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[T1OBJ:[^\\/]+\.o]]" "{{.*}}[[T1ASM]]"
end_comment

begin_comment
comment|// CHK-UBJOBS-ST: ld{{(\.exe)?}}" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[T1BIN:[^\\/]+\.out-openmp-powerpc64le-ibm-linux-gnu]]" {{.*}}"{{.*}}[[T1OBJ]]"
end_comment

begin_comment
comment|// Create target 2 object.
end_comment

begin_comment
comment|// CHK-UBJOBS: clang{{.*}}" "-cc1" "-triple" "x86_64-pc-linux-gnu" "-emit-obj" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-SAME: [[T2OBJ:[^\\/]+\.o]]" "-x" "cpp-output" "{{.*}}[[T2PP]]" "-fopenmp-is-device" "-fopenmp-host-ir-file-path" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-UBJOBS: ld{{(\.exe)?}}" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-SAME: [[T2BIN:[^\\/]+\.out]]" {{.*}}"{{.*}}[[T2OBJ]]"
end_comment

begin_comment
comment|// CHK-UBJOBS-ST: clang{{.*}}" "-cc1" "-triple" "x86_64-pc-linux-gnu" "-emit-llvm-bc" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[T2BC:[^\\/]+\.bc]]" "-x" "cpp-output" "{{.*}}[[T2PP]]" "-fopenmp-is-device" "-fopenmp-host-ir-file-path" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-UBJOBS-ST: clang{{.*}}" "-cc1" "-triple" "x86_64-pc-linux-gnu" "-S" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[T2ASM:[^\\/]+\.s]]" "-x" "ir" "{{.*}}[[T2BC]]"
end_comment

begin_comment
comment|// CHK-UBJOBS-ST: clang{{.*}}" "-cc1as" "-triple" "x86_64-pc-linux-gnu" "-filetype" "obj" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[T2OBJ:[^\\/]+\.o]]" "{{.*}}[[T2ASM]]"
end_comment

begin_comment
comment|// CHK-UBJOBS-ST: ld{{(\.exe)?}}" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[T2BIN:[^\\/]+\.out-openmp-x86_64-pc-linux-gnu]]" {{.*}}"{{.*}}[[T2OBJ]]"
end_comment

begin_comment
comment|// Create binary.
end_comment

begin_comment
comment|// CHK-UBJOBS: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-emit-obj" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-SAME: [[HOSTOBJ:[^\\/]+\.o]]" "-x" "ir" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-UBJOBS: ld{{(\.exe)?}}" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-SAME: [[HOSTBIN:[^\\/]+\.out]]" {{.*}}"{{.*}}[[HOSTOBJ]]" {{.*}}"-T" "
end_comment

begin_comment
comment|// CHK-UBJOBS-SAME: [[LKS:[^\\/]+\.lk]]"
end_comment

begin_comment
comment|// CHK-UBJOBS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-S" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[HOSTASM:[^\\/]+\.s]]" "-x" "ir" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-UBJOBS-ST: clang{{.*}}" "-cc1as" "-triple" "powerpc64le--linux" "-filetype" "obj" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[HOSTOBJ:[^\\/]+\.o]]" "{{.*}}[[HOSTASM]]"
end_comment

begin_comment
comment|// CHK-UBJOBS-ST: ld{{(\.exe)?}}" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[HOSTBIN:[^\\/]+\.out]]" {{.*}}"{{.*}}[[HOSTOBJ]]" {{.*}}"-T" "
end_comment

begin_comment
comment|// CHK-UBJOBS-ST-SAME: [[LKS:[^\\/]+\.lk]]"
end_comment

begin_comment
comment|// Unbundle object file.
end_comment

begin_comment
comment|// CHK-UBJOBS2: clang-offload-bundler{{.*}}" "-type=o" "-targets=host-powerpc64le--linux,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu" "-inputs=
end_comment

begin_comment
comment|// CHK-UBJOBS2-SAME: [[INPUT:[^\\/]+\.o]]" "-outputs=
end_comment

begin_comment
comment|// CHK-UBJOBS2-SAME: [[HOSTOBJ:[^\\/]+\.o]],
end_comment

begin_comment
comment|// CHK-UBJOBS2-SAME: [[T1OBJ:[^\\/]+\.o]],
end_comment

begin_comment
comment|// CHK-UBJOBS2-SAME: [[T2OBJ:[^\\/]+\.o]]" "-unbundle"
end_comment

begin_comment
comment|// CHK-UBJOBS2: ld{{(\.exe)?}}" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS2-SAME: [[T1BIN:[^\\/]+\.out]]" {{.*}}"{{.*}}[[T1OBJ]]"
end_comment

begin_comment
comment|// CHK-UBJOBS2: ld{{(\.exe)?}}" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS2-SAME: [[T2BIN:[^\\/]+\.out]]" {{.*}}"{{.*}}[[T2OBJ]]"
end_comment

begin_comment
comment|// CHK-UBJOBS2: ld{{(\.exe)?}}" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS2-SAME: [[HOSTBIN:[^\\/]+\.out]]" {{.*}}"{{.*}}[[HOSTOBJ]]" {{.*}}"-T" "
end_comment

begin_comment
comment|// CHK-UBJOBS2-SAME: [[LKS:[^\\/]+\.lk]]"
end_comment

begin_comment
comment|// CHK-UBJOBS2-ST: clang-offload-bundler{{.*}}" "-type=o" "-targets=host-powerpc64le--linux,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu" "-inputs=
end_comment

begin_comment
comment|// CHK-UBJOBS2-ST-SAME: [[INPUT:[^\\/]+\.o]]" "-outputs=
end_comment

begin_comment
comment|// CHK-UBJOBS2-ST-SAME: [[HOSTOBJ:[^\\/,]+\.o]],
end_comment

begin_comment
comment|// CHK-UBJOBS2-ST-SAME: [[T1OBJ:[^\\/,]+\.o]],
end_comment

begin_comment
comment|// CHK-UBJOBS2-ST-SAME: [[T2OBJ:[^\\/,]+\.o]]" "-unbundle"
end_comment

begin_comment
comment|// CHK-UBJOBS2-ST: ld{{(\.exe)?}}" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS2-ST-SAME: [[T1BIN:[^\\/]+\.out-openmp-powerpc64le-ibm-linux-gnu]]" {{.*}}"{{.*}}[[T1OBJ]]"
end_comment

begin_comment
comment|// CHK-UBJOBS2-ST: ld{{(\.exe)?}}" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS2-ST-SAME: [[T2BIN:[^\\/]+\.out-openmp-x86_64-pc-linux-gnu]]" {{.*}}"{{.*}}[[T2OBJ]]"
end_comment

begin_comment
comment|// CHK-UBJOBS2-ST: ld{{(\.exe)?}}" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBJOBS2-ST-SAME: [[HOSTBIN:[^\\/]+\.out]]" {{.*}}"{{.*}}[[HOSTOBJ]]" {{.*}}"-T" "
end_comment

begin_comment
comment|// CHK-UBJOBS2-ST-SAME: [[LKS:[^\\/]+\.lk]]"
end_comment

begin_comment
comment|/// ###########################################################################
end_comment

begin_comment
comment|/// Check separate compilation with offloading - unbundling/bundling jobs
end_comment

begin_comment
comment|/// construct
end_comment

begin_comment
comment|// RUN:   touch %t.i
end_comment

begin_comment
comment|// RUN:   %clang -### -fopenmp=libomp -c %t.o -lsomelib -target powerpc64le-linux -fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu %t.i -no-canonical-prefixes 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-UBUJOBS %s
end_comment

begin_comment
comment|// RUN:   %clang -### -fopenmp=libomp -c %t.o -lsomelib -target powerpc64le-linux -fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu %t.i -save-temps -no-canonical-prefixes 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHK-UBUJOBS-ST %s
end_comment

begin_comment
comment|// Unbundle and create host BC.
end_comment

begin_comment
comment|// CHK-UBUJOBS: clang-offload-bundler{{.*}}" "-type=i" "-targets=host-powerpc64le--linux,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu" "-inputs=
end_comment

begin_comment
comment|// CHK-UBUJOBS-SAME: [[INPUT:[^\\/]+\.i]]" "-outputs=
end_comment

begin_comment
comment|// CHK-UBUJOBS-SAME: [[HOSTPP:[^\\/]+\.i]],
end_comment

begin_comment
comment|// CHK-UBUJOBS-SAME: [[T1PP:[^\\/]+\.i]],
end_comment

begin_comment
comment|// CHK-UBUJOBS-SAME: [[T2PP:[^\\/]+\.i]]" "-unbundle"
end_comment

begin_comment
comment|// CHK-UBUJOBS: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-emit-llvm-bc"  {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBUJOBS-SAME: [[HOSTBC:[^\\/]+\.bc]]" "-x" "cpp-output" "{{.*}}[[HOSTPP]]" "-fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu"
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST: clang-offload-bundler{{.*}}" "-type=i" "-targets=host-powerpc64le--linux,openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu" "-inputs=
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST-SAME: [[INPUT:[^\\/]+\.i]]" "-outputs=
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST-SAME: [[HOSTPP:[^\\/,]+\.i]],
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST-SAME: [[T1PP:[^\\/,]+\.i]],
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST-SAME: [[T2PP:[^\\/,]+\.i]]" "-unbundle"
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-emit-llvm-bc"  {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST-SAME: [[HOSTBC:[^\\/]+\.bc]]" "-x" "cpp-output" "{{.*}}[[HOSTPP]]" "-fopenmp-targets=powerpc64le-ibm-linux-gnu,x86_64-pc-linux-gnu"
end_comment

begin_comment
comment|// Create target 1 object.
end_comment

begin_comment
comment|// CHK-UBUJOBS: clang{{.*}}" "-cc1" "-triple" "powerpc64le-ibm-linux-gnu" "-emit-obj" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBUJOBS-SAME: [[T1OBJ:[^\\/]+\.o]]" "-x" "cpp-output" "{{.*}}[[T1PP]]" "-fopenmp-is-device" "-fopenmp-host-ir-file-path" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le-ibm-linux-gnu" "-emit-llvm-bc" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST-SAME: [[T1BC:[^\\/]+\.bc]]" "-x" "cpp-output" "{{.*}}[[T1PP]]" "-fopenmp-is-device" "-fopenmp-host-ir-file-path" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le-ibm-linux-gnu" "-S" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST-SAME: [[T1ASM:[^\\/]+\.s]]" "-x" "ir" "{{.*}}[[T1BC]]"
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST: clang{{.*}}" "-cc1as" "-triple" "powerpc64le-ibm-linux-gnu" "-filetype" "obj" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST-SAME: [[T1OBJ:[^\\/]+\.o]]" "{{.*}}[[T1ASM]]"
end_comment

begin_comment
comment|// Create target 2 object.
end_comment

begin_comment
comment|// CHK-UBUJOBS: clang{{.*}}" "-cc1" "-triple" "x86_64-pc-linux-gnu" "-emit-obj" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBUJOBS-SAME: [[T2OBJ:[^\\/]+\.o]]" "-x" "cpp-output" "{{.*}}[[T2PP]]" "-fopenmp-is-device" "-fopenmp-host-ir-file-path" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST: clang{{.*}}" "-cc1" "-triple" "x86_64-pc-linux-gnu" "-emit-llvm-bc" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST-SAME: [[T2BC:[^\\/]+\.bc]]" "-x" "cpp-output" "{{.*}}[[T2PP]]" "-fopenmp-is-device" "-fopenmp-host-ir-file-path" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST: clang{{.*}}" "-cc1" "-triple" "x86_64-pc-linux-gnu" "-S" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST-SAME: [[T2ASM:[^\\/]+\.s]]" "-x" "ir" "{{.*}}[[T2BC]]"
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST: clang{{.*}}" "-cc1as" "-triple" "x86_64-pc-linux-gnu" "-filetype" "obj" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST-SAME: [[T2OBJ:[^\\/]+\.o]]" "{{.*}}[[T2ASM]]"
end_comment

begin_comment
comment|// Create binary.
end_comment

begin_comment
comment|// CHK-UBUJOBS: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-emit-obj" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBUJOBS-SAME: [[HOSTOBJ:[^\\/]+\.o]]" "-x" "ir" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-UBUJOBS: clang-offload-bundler{{.*}}" "-type=o" "-targets=openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu,host-powerpc64le--linux" "-outputs=
end_comment

begin_comment
comment|// CHK-UBUJOBS-SAME: [[RES:[^\\/]+\.o]]" "-inputs={{.*}}[[T1OBJ]],{{.*}}[[T2OBJ]],{{.*}}[[HOSTOBJ]]"
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux" "-S" {{.*}}"-fopenmp" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST-SAME: [[HOSTASM:[^\\/]+\.s]]" "-x" "ir" "{{.*}}[[HOSTBC]]"
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST: clang{{.*}}" "-cc1as" "-triple" "powerpc64le--linux" "-filetype" "obj" {{.*}}"-o" "
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST-SAME: [[HOSTOBJ:[^\\/]+\.o]]" "{{.*}}[[HOSTASM]]"
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST: clang-offload-bundler{{.*}}" "-type=o" "-targets=openmp-powerpc64le-ibm-linux-gnu,openmp-x86_64-pc-linux-gnu,host-powerpc64le--linux" "-outputs=
end_comment

begin_comment
comment|// CHK-UBUJOBS-ST-SAME: [[RES:[^\\/]+\.o]]" "-inputs={{.*}}[[T1OBJ]],{{.*}}[[T2OBJ]],{{.*}}[[HOSTOBJ]]"
end_comment

end_unit

