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
name|HIDDEN_DIRECTIVE
value|.private_extern
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

begin_define
define|#
directive|define
name|FILE_LEVEL_DIRECTIVE
value|.subsections_via_symbols
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
value|HIDDEN_DIRECTIVE SYMBOL_NAME(name) SEPARATOR
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
value|FILE_LEVEL_DIRECTIVE     SEPARATOR                       \   .globl SYMBOL_NAME(name) SEPARATOR                       \   DECLARE_SYMBOL_VISIBILITY(name)                          \   SYMBOL_NAME(name):
end_define

begin_define
define|#
directive|define
name|DEFINE_COMPILERRT_PRIVATE_FUNCTION
parameter_list|(
name|name
parameter_list|)
define|\
value|.globl SYMBOL_NAME(name) SEPARATOR                       \   HIDDEN_DIRECTIVE SYMBOL_NAME(name) SEPARATOR             \   SYMBOL_NAME(name):
end_define

begin_define
define|#
directive|define
name|DEFINE_COMPILERRT_PRIVATE_FUNCTION_UNMANGLED
parameter_list|(
name|name
parameter_list|)
define|\
value|.globl name SEPARATOR                                    \   HIDDEN_DIRECTIVE name SEPARATOR                          \   name:
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
value|.globl SYMBOL_NAME(name) SEPARATOR                       \   .set SYMBOL_NAME(name), SYMBOL_NAME(target) SEPARATOR
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMPILERRT_ASSEMBLY_H */
end_comment

end_unit

