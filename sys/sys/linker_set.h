begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 John D. Polstra  * Copyright (c) 1999,2001 Peter Wemm<peter@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_LINKER_SET_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_LINKER_SET_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CDEFS_H_
end_ifndef

begin_error
error|#
directive|error
error|this file needs sys/cdefs.h as a prerequisite
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following macros are used to declare global sets of objects, which  * are collected by the linker into a `linker_set' as defined below.  * For ELF, this is done by constructing a separate segment for each set.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
end_if

begin_comment
comment|/*  * Move the symbol pointer from ".text" to ".data" segment, to make  * the GCC compiler happy:  */
end_comment

begin_define
define|#
directive|define
name|__MAKE_SET_CONST
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__MAKE_SET_CONST
value|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Private macros, not to be used outside this header file.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUCLIKE___SECTION
end_ifdef

begin_define
define|#
directive|define
name|__MAKE_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
define|\
value|__GLOBL(__CONCAT(__start_set_,set));		\ 	__GLOBL(__CONCAT(__stop_set_,set));		\ 	static void const * __MAKE_SET_CONST		\ 	__set_##set##_sym_##sym __section("set_" #set)	\ 	__used =&(sym)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__GNUCLIKE___SECTION */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_error
error|#
directive|error
error|this file needs to be ported to your compiler
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_define
define|#
directive|define
name|__MAKE_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|extern void const * const (__set_##set##_sym_##sym)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUCLIKE___SECTION */
end_comment

begin_comment
comment|/*  * Public macros.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|__MAKE_SET(set, sym)
end_define

begin_define
define|#
directive|define
name|DATA_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|__MAKE_SET(set, sym)
end_define

begin_define
define|#
directive|define
name|BSS_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|__MAKE_SET(set, sym)
end_define

begin_define
define|#
directive|define
name|ABS_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|__MAKE_SET(set, sym)
end_define

begin_define
define|#
directive|define
name|SET_ENTRY
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|)
value|__MAKE_SET(set, sym)
end_define

begin_comment
comment|/*  * Initialize before referring to a given linker set.  */
end_comment

begin_define
define|#
directive|define
name|SET_DECLARE
parameter_list|(
name|set
parameter_list|,
name|ptype
parameter_list|)
define|\
value|extern ptype __weak *__CONCAT(__start_set_,set);	\ 	extern ptype __weak *__CONCAT(__stop_set_,set)
end_define

begin_define
define|#
directive|define
name|SET_BEGIN
parameter_list|(
name|set
parameter_list|)
define|\
value|(&__CONCAT(__start_set_,set))
end_define

begin_define
define|#
directive|define
name|SET_LIMIT
parameter_list|(
name|set
parameter_list|)
define|\
value|(&__CONCAT(__stop_set_,set))
end_define

begin_comment
comment|/*  * Iterate over all the elements of a set.  *  * Sets always contain addresses of things, and "pvar" points to words  * containing those addresses.  Thus is must be declared as "type **pvar",  * and the address of each set item is obtained inside the loop by "*pvar".  */
end_comment

begin_define
define|#
directive|define
name|SET_FOREACH
parameter_list|(
name|pvar
parameter_list|,
name|set
parameter_list|)
define|\
value|for (pvar = SET_BEGIN(set); pvar< SET_LIMIT(set); pvar++)
end_define

begin_define
define|#
directive|define
name|SET_ITEM
parameter_list|(
name|set
parameter_list|,
name|i
parameter_list|)
define|\
value|((SET_BEGIN(set))[i])
end_define

begin_comment
comment|/*  * Provide a count of the items in a set.  */
end_comment

begin_define
define|#
directive|define
name|SET_COUNT
parameter_list|(
name|set
parameter_list|)
define|\
value|(SET_LIMIT(set) - SET_BEGIN(set))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_LINKER_SET_H_ */
end_comment

end_unit

