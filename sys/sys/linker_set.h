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

begin_comment
comment|/*  * The following macros are used to declare global sets of objects, which  * are collected by the linker into a `linker_set' as defined below.  * For ELF, this is done by constructing a separate segment for each set.  * For a.out, it is done automatically by the linker.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ELF__
argument_list|)
end_if

begin_comment
comment|/*  * Private macros, not to be used outside this header file.  */
end_comment

begin_comment
comment|/* this bit of h0h0magic brought to you by cpp */
end_comment

begin_define
define|#
directive|define
name|__GLOBL
parameter_list|(
name|sym
parameter_list|)
value|__GLOBL2(sym)
end_define

begin_define
define|#
directive|define
name|__GLOBL2
parameter_list|(
name|sym
parameter_list|)
value|__asm(".globl " #sym)
end_define

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
value|__GLOBL(__CONCAT(__start_set_,set));				\ 	__GLOBL(__CONCAT(__stop_set_,set));				\ 	static void const * const __set_##set##_sym_##sym 		\ 	__attribute__((__section__("set_" #set),__unused__)) =&sym
end_define

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
comment|/*  * Initialize before referring to a give linker set  */
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
value|extern ptype *__CONCAT(__start_set_,set);			\ 	extern ptype *__CONCAT(__stop_set_,set)
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __ELF__ */
end_comment

begin_comment
comment|/*  * The old way.  This depends on GNU ld extensions that are not widely  * available outside of the a.out format.  *  * NB: the constants defined below must match those defined in  * ld/ld.h.  Since their calculation requires arithmetic, we  * can't name them symbolically (e.g., 23 is N_SETT | N_EXT).  *  * In the __MAKE_SET macro below, the line:  *   static void const * const __set_##set##_sym_##sym =&sym;  * is present only to prevent the compiler from producing bogus  * warnings about unused symbols.  */
end_comment

begin_comment
comment|/* Private macros */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__UNDERSCORES__
end_ifdef

begin_define
define|#
directive|define
name|__MAKE_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|,
name|type
parameter_list|)
define|\
value|static void const * const __set_##set##_sym_##sym =&sym;	\ 	__asm(".stabs \"_" #set "\", " #type ", 0, 0, _" #sym)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__MAKE_SET
parameter_list|(
name|set
parameter_list|,
name|sym
parameter_list|,
name|type
parameter_list|)
define|\
value|static void const * const __set_##set##_sym_##sym =&sym;	\ 	__asm(".stabs \"" #set "\", " #type ", 0, 0, " #sym)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Public Macros */
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
value|__MAKE_SET(set, sym, 23)
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
value|__MAKE_SET(set, sym, 25)
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
value|__MAKE_SET(set, sym, 27)
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
value|__MAKE_SET(set, sym, 21)
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
value|error error must provide text/data type
end_define

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
value|extern struct  {						\ 		int		ls_length;				\ 		ptype		*ls_items[1];				\ 	} set
end_define

begin_define
define|#
directive|define
name|SET_BEGIN
parameter_list|(
name|set
parameter_list|)
define|\
value|(&((set).ls_items[0]))
end_define

begin_define
define|#
directive|define
name|SET_LIMIT
parameter_list|(
name|set
parameter_list|)
define|\
value|(&((set).ls_items[(set).ls_length]))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ELF__ */
end_comment

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

