begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Procfs.h ---------------------------------------------- -*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// source/Plugins/Process/Linux/Procfs.h defines the symbols we need from
end_comment

begin_comment
comment|// sys/procfs.h on Android/Linux for all supported architectures.
end_comment

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__ANDROID__
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|elf_greg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|elf_greg_t
name|elf_gregset_t
index|[
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|user_pt_regs
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|elf_greg_t
argument_list|)
operator|)
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|user_fpsimd_state
name|elf_fpregset_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|NT_FPREGSET
end_ifndef

begin_define
define|#
directive|define
name|NT_FPREGSET
value|NT_PRFPREG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// NT_FPREGSET
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips__
argument_list|)
end_elif

begin_ifndef
ifndef|#
directive|ifndef
name|NT_FPREGSET
end_ifndef

begin_define
define|#
directive|define
name|NT_FPREGSET
value|NT_PRFPREG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// NT_FPREGSET
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|// __ANDROID__
end_comment

begin_include
include|#
directive|include
file|<sys/procfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __ANDROID__
end_comment

end_unit

