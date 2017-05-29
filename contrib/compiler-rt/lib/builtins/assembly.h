begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- assembly.h - compiler-rt assembler support macros -----------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file defines macros for use in compiler-rt assembler source.  * This file is not part of the interface of this library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMPILERRT_ASSEMBLY_H
end_ifndef

begin_define
define|#
directive|define
name|COMPILERRT_ASSEMBLY_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__POWERPC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ppc__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SEPARATOR
value|@
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SEPARATOR
value|;
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
name|__APPLE__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HIDDEN
parameter_list|(
name|name
parameter_list|)
value|.private_extern name
end_define

begin_define
define|#
directive|define
name|LOCAL_LABEL
parameter_list|(
name|name
parameter_list|)
value|L_##name
end_define

begin_comment
comment|// tell linker it can break up file at label boundaries
end_comment

begin_define
define|#
directive|define
name|FILE_LEVEL_DIRECTIVE
value|.subsections_via_symbols
end_define

begin_define
define|#
directive|define
name|SYMBOL_IS_FUNC
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CONST_SECTION
value|.const
end_define

begin_define
define|#
directive|define
name|NO_EXEC_STACK_DIRECTIVE
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ELF__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|HIDDEN
parameter_list|(
name|name
parameter_list|)
value|.hidden name
end_define

begin_define
define|#
directive|define
name|LOCAL_LABEL
parameter_list|(
name|name
parameter_list|)
value|.L_##name
end_define

begin_define
define|#
directive|define
name|FILE_LEVEL_DIRECTIVE
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYMBOL_IS_FUNC
parameter_list|(
name|name
parameter_list|)
value|.type name,%function
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYMBOL_IS_FUNC
parameter_list|(
name|name
parameter_list|)
value|.type name,@function
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CONST_SECTION
value|.section .rodata
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNU__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__Fuchsia__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_define
define|#
directive|define
name|NO_EXEC_STACK_DIRECTIVE
value|.section .note.GNU-stack,"",%progbits
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NO_EXEC_STACK_DIRECTIVE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|// !__APPLE__&& !__ELF__
end_comment

begin_define
define|#
directive|define
name|HIDDEN
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LOCAL_LABEL
parameter_list|(
name|name
parameter_list|)
value|.L ## name
end_define

begin_define
define|#
directive|define
name|FILE_LEVEL_DIRECTIVE
end_define

begin_define
define|#
directive|define
name|SYMBOL_IS_FUNC
parameter_list|(
name|name
parameter_list|)
define|\
value|.def name SEPARATOR                                                          \     .scl 2 SEPARATOR                                                           \     .type 32 SEPARATOR                                                         \   .endef
end_define

begin_define
define|#
directive|define
name|CONST_SECTION
value|.section .rdata,"rd"
end_define

begin_define
define|#
directive|define
name|NO_EXEC_STACK_DIRECTIVE
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
name|__arm__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_4T__
argument_list|)
operator|||
name|__ARM_ARCH
operator|>=
literal|5
end_if

begin_define
define|#
directive|define
name|ARM_HAS_BX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__ARM_FEATURE_CLZ
argument_list|)
operator|&&
name|__ARM_ARCH_ISA_THUMB
operator|!=
literal|1
operator|&&
expr|\
operator|(
name|__ARM_ARCH
operator|>=
literal|6
operator|||
operator|(
name|__ARM_ARCH
operator|==
literal|5
operator|&&
operator|!
name|defined
argument_list|(
name|__ARM_ARCH_5__
argument_list|)
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|__ARM_FEATURE_CLZ
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ARM_HAS_BX
end_ifdef

begin_define
define|#
directive|define
name|JMP
parameter_list|(
name|r
parameter_list|)
value|bx r
end_define

begin_define
define|#
directive|define
name|JMPc
parameter_list|(
name|r
parameter_list|,
name|c
parameter_list|)
value|bx##c r
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|JMP
parameter_list|(
name|r
parameter_list|)
value|mov pc, r
end_define

begin_define
define|#
directive|define
name|JMPc
parameter_list|(
name|r
parameter_list|,
name|c
parameter_list|)
value|mov##c pc, r
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// pop {pc} can't switch Thumb mode on ARMv4T
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|5
end_if

begin_define
define|#
directive|define
name|POP_PC
parameter_list|()
value|pop {pc}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|POP_PC
parameter_list|()
define|\
value|pop {ip};                                                                    \   JMP(ip)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Determine actual [ARM][THUMB[1][2]] ISA using compiler predefined macros:  * - for '-mthumb -march=armv6' compiler defines '__thumb__'  * - for '-mthumb -march=armv7' compiler defines '__thumb__' and '__thumb2__'  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__thumb2__
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_THUMB_2
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__thumb__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|USE_THUMB_1
value|1
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
name|USE_THUMB_1
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_THUMB_2
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"USE_THUMB_1 and USE_THUMB_2 can't be defined together."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_THUMB_1
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_THUMB_1
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_THUMB_PROLOGUE
value|1
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
name|USE_THUMB_2
argument_list|)
end_if

begin_define
define|#
directive|define
name|IT
parameter_list|(
name|cond
parameter_list|)
value|it cond
end_define

begin_define
define|#
directive|define
name|ITT
parameter_list|(
name|cond
parameter_list|)
value|itt cond
end_define

begin_define
define|#
directive|define
name|ITE
parameter_list|(
name|cond
parameter_list|)
value|ite cond
end_define

begin_define
define|#
directive|define
name|WIDE
parameter_list|(
name|op
parameter_list|)
value|op.w
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IT
parameter_list|(
name|cond
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ITT
parameter_list|(
name|cond
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ITE
parameter_list|(
name|cond
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WIDE
parameter_list|(
name|op
parameter_list|)
value|op
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__arm__) */
end_comment

begin_define
define|#
directive|define
name|GLUE2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a##b
end_define

begin_define
define|#
directive|define
name|GLUE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|GLUE2(a, b)
end_define

begin_define
define|#
directive|define
name|SYMBOL_NAME
parameter_list|(
name|name
parameter_list|)
value|GLUE(__USER_LABEL_PREFIX__, name)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VISIBILITY_HIDDEN
end_ifdef

begin_define
define|#
directive|define
name|DECLARE_SYMBOL_VISIBILITY
parameter_list|(
name|name
parameter_list|)
define|\
value|HIDDEN(SYMBOL_NAME(name)) SEPARATOR
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DECLARE_SYMBOL_VISIBILITY
parameter_list|(
name|name
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEFINE_COMPILERRT_FUNCTION
parameter_list|(
name|name
parameter_list|)
define|\
value|FILE_LEVEL_DIRECTIVE SEPARATOR                                               \   .globl SYMBOL_NAME(name) SEPARATOR                                           \   SYMBOL_IS_FUNC(SYMBOL_NAME(name)) SEPARATOR                                  \   DECLARE_SYMBOL_VISIBILITY(name)                                              \   SYMBOL_NAME(name):
end_define

begin_define
define|#
directive|define
name|DEFINE_COMPILERRT_THUMB_FUNCTION
parameter_list|(
name|name
parameter_list|)
define|\
value|FILE_LEVEL_DIRECTIVE SEPARATOR                                               \   .globl SYMBOL_NAME(name) SEPARATOR                                           \   SYMBOL_IS_FUNC(SYMBOL_NAME(name)) SEPARATOR                                  \   DECLARE_SYMBOL_VISIBILITY(name) SEPARATOR                                    \   .thumb_func SEPARATOR                                                        \   SYMBOL_NAME(name):
end_define

begin_define
define|#
directive|define
name|DEFINE_COMPILERRT_PRIVATE_FUNCTION
parameter_list|(
name|name
parameter_list|)
define|\
value|FILE_LEVEL_DIRECTIVE SEPARATOR                                               \   .globl SYMBOL_NAME(name) SEPARATOR                                           \   SYMBOL_IS_FUNC(SYMBOL_NAME(name)) SEPARATOR                                  \   HIDDEN(SYMBOL_NAME(name)) SEPARATOR                                          \   SYMBOL_NAME(name):
end_define

begin_define
define|#
directive|define
name|DEFINE_COMPILERRT_PRIVATE_FUNCTION_UNMANGLED
parameter_list|(
name|name
parameter_list|)
define|\
value|.globl name SEPARATOR                                                        \   SYMBOL_IS_FUNC(name) SEPARATOR                                               \   HIDDEN(name) SEPARATOR                                                       \   name:
end_define

begin_define
define|#
directive|define
name|DEFINE_COMPILERRT_FUNCTION_ALIAS
parameter_list|(
name|name
parameter_list|,
name|target
parameter_list|)
define|\
value|.globl SYMBOL_NAME(name) SEPARATOR                                           \   SYMBOL_IS_FUNC(SYMBOL_NAME(name)) SEPARATOR                                  \   DECLARE_SYMBOL_VISIBILITY(SYMBOL_NAME(name)) SEPARATOR                       \   .set SYMBOL_NAME(name), SYMBOL_NAME(target) SEPARATOR
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_EABI__
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEFINE_AEABI_FUNCTION_ALIAS
parameter_list|(
name|aeabi_name
parameter_list|,
name|name
parameter_list|)
define|\
value|DEFINE_COMPILERRT_FUNCTION_ALIAS(aeabi_name, name)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEFINE_AEABI_FUNCTION_ALIAS
parameter_list|(
name|aeabi_name
parameter_list|,
name|name
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

begin_define
define|#
directive|define
name|END_COMPILERRT_FUNCTION
parameter_list|(
name|name
parameter_list|)
define|\
value|.size SYMBOL_NAME(name), . - SYMBOL_NAME(name)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|END_COMPILERRT_FUNCTION
parameter_list|(
name|name
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMPILERRT_ASSEMBLY_H */
end_comment

end_unit

