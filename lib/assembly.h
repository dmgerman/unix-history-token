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

begin_comment
comment|/* We can't use __USER_LABEL_PREFIX__ here, it isn't possible to concatenate the    *values* of two macros. This is quite brittle, though. */
end_comment

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
name|SYMBOL_NAME
parameter_list|(
name|name
parameter_list|)
value|_##name
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYMBOL_NAME
parameter_list|(
name|name
parameter_list|)
value|name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VISIBILITY_HIDDEN
end_ifdef

begin_define
define|#
directive|define
name|DEFINE_COMPILERRT_FUNCTION
parameter_list|(
name|name
parameter_list|)
define|\
value|.globl SYMBOL_NAME(name) SEPARATOR     \   .private_extern SYMBOL_NAME(name) SEPARATOR    \   SYMBOL_NAME(name):
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEFINE_COMPILERRT_FUNCTION
parameter_list|(
name|name
parameter_list|)
define|\
value|.globl SYMBOL_NAME(name) SEPARATOR     \   SYMBOL_NAME(name):
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEFINE_COMPILERRT_PRIVATE_FUNCTION
parameter_list|(
name|name
parameter_list|)
define|\
value|.globl SYMBOL_NAME(name) SEPARATOR             \   .private_extern SYMBOL_NAME(name) SEPARATOR    \   SYMBOL_NAME(name):
end_define

begin_define
define|#
directive|define
name|DEFINE_COMPILERRT_PRIVATE_FUNCTION_UNMANGLED
parameter_list|(
name|name
parameter_list|)
define|\
value|.globl name SEPARATOR             \   .private_extern name SEPARATOR    \   name:
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMPILERRT_ASSEMBLY_H */
end_comment

end_unit

