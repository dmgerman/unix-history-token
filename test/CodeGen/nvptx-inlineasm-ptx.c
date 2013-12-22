begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple nvptx-unknown-unknown -O3 -S -o - %s -emit-llvm | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple nvptx64-unknown-unknown -O3 -S -o - %s -emit-llvm | FileCheck %s
end_comment

begin_function
name|void
name|constraints
parameter_list|()
block|{
name|char
name|c
decl_stmt|;
name|unsigned
name|char
name|uc
decl_stmt|;
name|short
name|s
decl_stmt|;
name|unsigned
name|short
name|us
decl_stmt|;
name|int
name|i
decl_stmt|;
name|unsigned
name|int
name|ui
decl_stmt|;
name|long
name|l
decl_stmt|;
name|unsigned
name|long
name|ul
decl_stmt|;
name|float
name|f
decl_stmt|;
name|double
name|d
decl_stmt|;
comment|// CHECK: i8 asm sideeffect "mov.b8 $0, $1;", "=c,c"
asm|asm
specifier|volatile
asm|("mov.b8 %0, %1;" : "=c"(c) : "c"(c));
comment|// CHECK: i8 asm sideeffect "mov.b8 $0, $1;", "=c,c"
asm|asm
specifier|volatile
asm|("mov.b8 %0, %1;" : "=c"(uc) : "c"(uc));
comment|// CHECK: i16 asm sideeffect "mov.b16 $0, $1;", "=h,h"
asm|asm
specifier|volatile
asm|("mov.b16 %0, %1;" : "=h"(s) : "h"(s));
comment|// CHECK: i16 asm sideeffect "mov.b16 $0, $1;", "=h,h"
asm|asm
specifier|volatile
asm|("mov.b16 %0, %1;" : "=h"(us) : "h"(us));
comment|// CHECK: i32 asm sideeffect "mov.b32 $0, $1;", "=r,r"
asm|asm
specifier|volatile
asm|("mov.b32 %0, %1;" : "=r"(i) : "r"(i));
comment|// CHECK: i32 asm sideeffect "mov.b32 $0, $1;", "=r,r"
asm|asm
specifier|volatile
asm|("mov.b32 %0, %1;" : "=r"(ui) : "r"(ui));
comment|// CHECK: i64 asm sideeffect "mov.b64 $0, $1;", "=l,l"
asm|asm
specifier|volatile
asm|("mov.b64 %0, %1;" : "=l"(l) : "l"(l));
comment|// CHECK: i64 asm sideeffect "mov.b64 $0, $1;", "=l,l"
asm|asm
specifier|volatile
asm|("mov.b64 %0, %1;" : "=l"(ul) : "l"(ul));
comment|// CHECK: float asm sideeffect "mov.b32 $0, $1;", "=f,f"
asm|asm
specifier|volatile
asm|("mov.b32 %0, %1;" : "=f"(f) : "f"(f));
comment|// CHECK: double asm sideeffect "mov.b64 $0, $1;", "=d,d"
asm|asm
specifier|volatile
asm|("mov.b64 %0, %1;" : "=d"(d) : "d"(d));
block|}
end_function

end_unit

