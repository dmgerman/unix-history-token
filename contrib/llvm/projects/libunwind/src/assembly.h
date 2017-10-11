begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- assembly.h - libUnwind assembler support macros -------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file defines macros for use in libUnwind assembler source.  * This file is not part of the interface of this library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNWIND_ASSEMBLY_H
end_ifndef

begin_define
define|#
directive|define
name|UNWIND_ASSEMBLY_H
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

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SEPARATOR
value|%%
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
name|HIDDEN_DIRECTIVE
value|.private_extern
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HIDDEN_DIRECTIVE
value|.hidden
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GLUE2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a ## b
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
name|SYMBOL_IS_FUNC
parameter_list|(
name|name
parameter_list|)
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
name|__ANDROID__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
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
name|NO_EXEC_STACK_DIRECTIVE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEFINE_LIBUNWIND_FUNCTION
parameter_list|(
name|name
parameter_list|)
define|\
value|.globl SYMBOL_NAME(name) SEPARATOR                      \   SYMBOL_IS_FUNC(SYMBOL_NAME(name)) SEPARATOR             \   SYMBOL_NAME(name):
end_define

begin_define
define|#
directive|define
name|DEFINE_LIBUNWIND_PRIVATE_FUNCTION
parameter_list|(
name|name
parameter_list|)
define|\
value|.globl SYMBOL_NAME(name) SEPARATOR                      \   HIDDEN_DIRECTIVE SYMBOL_NAME(name) SEPARATOR            \   SYMBOL_IS_FUNC(SYMBOL_NAME(name)) SEPARATOR             \   SYMBOL_NAME(name):
end_define

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
operator|!
name|defined
argument_list|(
name|__ARM_ARCH
argument_list|)
end_if

begin_define
define|#
directive|define
name|__ARM_ARCH
value|4
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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __arm__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNWIND_ASSEMBLY_H */
end_comment

end_unit

