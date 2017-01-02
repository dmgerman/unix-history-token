begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: clang-driver
end_comment

begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// REQUIRES: nvptx-registered-target
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Verify that CUDA device commands do not get OpenMP flags.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -x cuda -target powerpc64le-linux-gnu -std=c++11 --cuda-gpu-arch=sm_35 -fopenmp=libomp %s 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck %s --check-prefix NO-OPENMP-FLAGS-FOR-CUDA-DEVICE
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NO-OPENMP-FLAGS-FOR-CUDA-DEVICE:      clang{{.*}}" "-cc1" "-triple" "nvptx64-nvidia-cuda"
end_comment

begin_comment
comment|// NO-OPENMP-FLAGS-FOR-CUDA-DEVICE-NOT:  -fopenmp
end_comment

begin_comment
comment|// NO-OPENMP-FLAGS-FOR-CUDA-DEVICE-NEXT: ptxas" "-m64"
end_comment

begin_comment
comment|// NO-OPENMP-FLAGS-FOR-CUDA-DEVICE-NEXT: fatbinary" "--cuda" "-64"
end_comment

begin_comment
comment|// NO-OPENMP-FLAGS-FOR-CUDA-DEVICE-NEXT: clang{{.*}}" "-cc1" "-triple" "powerpc64le--linux-gnu"
end_comment

begin_comment
comment|// NO-OPENMP-FLAGS-FOR-CUDA-DEVICE:      -fopenmp
end_comment

begin_comment
comment|// NO-OPENMP-FLAGS-FOR-CUDA-DEVICE-NEXT: {{ld(.exe)?"}} {{.*}}"-m" "elf64lppc"
end_comment

end_unit

