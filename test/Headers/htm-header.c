begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64le-unknown-unknown -target-feature +htm -DHTM_HEADER -ffreestanding -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64le-unknown-unknown -target-feature +htm -DHTM_HEADER -ffreestanding -emit-llvm -x c++ -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64le-unknown-unknown -target-feature +htm -DHTMXL_HEADER -ffreestanding -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64le-unknown-unknown -target-feature +htm -DHTMXL_HEADER -ffreestanding -emit-llvm -x c++ -o - %s | FileCheck %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HTM_HEADER
end_ifdef

begin_include
include|#
directive|include
file|<htmintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HTMXL_HEADER
end_ifdef

begin_include
include|#
directive|include
file|<htmxlintrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Verify that simply including the headers does not generate any code
end_comment

begin_comment
comment|// (i.e. all inline routines in the header are marked "static")
end_comment

begin_comment
comment|// CHECK: target triple = "powerpc64
end_comment

begin_comment
comment|// CHECK-NEXT: {{^$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{llvm\..*}}
end_comment

end_unit

