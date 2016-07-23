begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu %s -emit-llvm -o - | FileCheck %s --check-prefix=X86_64_LINUX
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-linux-gnu %s -emit-llvm -o - | FileCheck %s --check-prefix=X86_LINUX
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-win32 %s -emit-llvm -o - | FileCheck %s --check-prefix=X86_64_WIN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-win32 %s -emit-llvm -o - | FileCheck %s --check-prefix=X86_WIN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnux32 %s -emit-llvm -o - | FileCheck %s --check-prefix=X86_64_LINUX
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_typedef
typedef|typedef
name|__UINT64_TYPE__
name|uword
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|__UINT32_TYPE__
name|uword
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt)
argument_list|)
end_macro

begin_function
name|void
name|foo7
parameter_list|(
name|int
modifier|*
name|a
parameter_list|,
name|uword
name|b
parameter_list|)
block|{}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt)
argument_list|)
end_macro

begin_function
name|void
name|foo8
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// X86_64_LINUX: @llvm.used = appending global [2 x i8*] [i8* bitcast (void (i32*, i64)* @foo7 to i8*), i8* bitcast (void (i32*)* @foo8 to i8*)], section "llvm.metadata"
end_comment

begin_comment
comment|// X86_64_LINUX: define x86_intrcc void @foo7(i32* %{{.+}}, i64 %{{.+}})
end_comment

begin_comment
comment|// X86_64_LINUX: define x86_intrcc void @foo8(i32* %{{.+}})
end_comment

begin_comment
comment|// X86_64_LINUX: "disable-tail-calls"="true"
end_comment

begin_comment
comment|// X86_64_LINUX-NOT: "disable-tail-calls"="false"
end_comment

begin_comment
comment|// X86_LINUX: @llvm.used = appending global [2 x i8*] [i8* bitcast (void (i32*, i32)* @foo7 to i8*), i8* bitcast (void (i32*)* @foo8 to i8*)], section "llvm.metadata"
end_comment

begin_comment
comment|// X86_LINUX: define x86_intrcc void @foo7(i32* %{{.+}}, i32 %{{.+}})
end_comment

begin_comment
comment|// X86_LINUX: define x86_intrcc void @foo8(i32* %{{.+}})
end_comment

begin_comment
comment|// X86_LINUX: "disable-tail-calls"="true"
end_comment

begin_comment
comment|// X86_LINUX-NOT: "disable-tail-calls"="false"
end_comment

begin_comment
comment|// X86_64_WIN: @llvm.used = appending global [2 x i8*] [i8* bitcast (void (i32*, i64)* @foo7 to i8*), i8* bitcast (void (i32*)* @foo8 to i8*)], section "llvm.metadata"
end_comment

begin_comment
comment|// X86_64_WIN: define x86_intrcc void @foo7(i32* %{{.+}}, i64 %{{.+}})
end_comment

begin_comment
comment|// X86_64_WIN: define x86_intrcc void @foo8(i32* %{{.+}})
end_comment

begin_comment
comment|// X86_64_Win: "disable-tail-calls"="true"
end_comment

begin_comment
comment|// X86_64_Win-NOT: "disable-tail-calls"="false"
end_comment

begin_comment
comment|// X86_WIN: @llvm.used = appending global [2 x i8*] [i8* bitcast (void (i32*, i32)* @foo7 to i8*), i8* bitcast (void (i32*)* @foo8 to i8*)], section "llvm.metadata"
end_comment

begin_comment
comment|// X86_WIN: define x86_intrcc void @foo7(i32* %{{.+}}, i32 %{{.+}})
end_comment

begin_comment
comment|// X86_WIN: define x86_intrcc void @foo8(i32* %{{.+}})
end_comment

begin_comment
comment|// X86_Win: "disable-tail-calls"="true"
end_comment

begin_comment
comment|// X86_Win-NOT: "disable-tail-calls"="false"
end_comment

end_unit

