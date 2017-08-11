begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------------------------- __libunwind_config.h -----------------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|____LIBUNWIND_CONFIG_H__
end_ifndef

begin_define
define|#
directive|define
name|____LIBUNWIND_CONFIG_H__
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__USING_SJLJ_EXCEPTIONS__
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__ARM_DWARF_EH__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_LIBUNWIND_ARM_EHABI
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_LIBUNWIND_ARM_EHABI
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LIBUNWIND_IS_NATIVE_ONLY
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_LIBUNWIND_TARGET_I386
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_CONTEXT_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_CURSOR_SIZE
value|19
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_MAX_REGISTER
value|9
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_LIBUNWIND_TARGET_X86_64
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_CONTEXT_SIZE
value|21
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_CURSOR_SIZE
value|33
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_MAX_REGISTER
value|17
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ppc__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_LIBUNWIND_TARGET_PPC
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_CONTEXT_SIZE
value|117
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_CURSOR_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_MAX_REGISTER
value|113
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_LIBUNWIND_TARGET_AARCH64
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_CONTEXT_SIZE
value|66
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_CURSOR_SIZE
value|78
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_MAX_REGISTER
value|96
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_LIBUNWIND_TARGET_ARM
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_CONTEXT_SIZE
value|60
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_CURSOR_SIZE
value|67
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_MAX_REGISTER
value|96
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__or1k__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_LIBUNWIND_TARGET_OR1K
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_CONTEXT_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_CURSOR_SIZE
value|28
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_MAX_REGISTER
value|32
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__riscv
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_LIBUNWIND_TARGET_RISCV
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_CONTEXT_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_CURSOR_SIZE
value|76
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_MAX_REGISTER
value|96
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Unsupported architecture."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|// !_LIBUNWIND_IS_NATIVE_ONLY
end_comment

begin_define
define|#
directive|define
name|_LIBUNWIND_TARGET_I386
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_TARGET_X86_64
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_TARGET_PPC
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_TARGET_AARCH64
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_TARGET_ARM
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_TARGET_OR1K
value|1
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_CONTEXT_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_CURSOR_SIZE
value|140
end_define

begin_define
define|#
directive|define
name|_LIBUNWIND_MAX_REGISTER
value|120
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBUNWIND_IS_NATIVE_ONLY
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ____LIBUNWIND_CONFIG_H__
end_comment

end_unit

