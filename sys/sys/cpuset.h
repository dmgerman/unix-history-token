begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008,	Jeffrey Roberson<jeff@freebsd.org>  * All rights reserved.  *  * Copyright (c) 2008 Nokia Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CPUSET_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CPUSET_H_
end_define

begin_include
include|#
directive|include
file|<sys/_cpuset.h>
end_include

begin_define
define|#
directive|define
name|CPUSETBUFSIZ
value|((2 + sizeof(long) * 2) * _NCPUWORDS)
end_define

begin_comment
comment|/*  * Macros addressing word and bit within it, tuned to make compiler  * optimize cases when CPU_SETSIZE fits into single machine word.  */
end_comment

begin_define
define|#
directive|define
name|__cpuset_mask
parameter_list|(
name|n
parameter_list|)
define|\
value|((long)1<< ((_NCPUWORDS == 1) ? (__size_t)(n) : ((n) % _NCPUBITS)))
end_define

begin_define
define|#
directive|define
name|__cpuset_word
parameter_list|(
name|n
parameter_list|)
value|((_NCPUWORDS == 1) ? 0 : ((n) / _NCPUBITS))
end_define

begin_define
define|#
directive|define
name|CPU_CLR
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->__bits[__cpuset_word(n)]&= ~__cpuset_mask(n))
end_define

begin_define
define|#
directive|define
name|CPU_COPY
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|(void)(*(t) = *(f))
end_define

begin_define
define|#
directive|define
name|CPU_ISSET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|(((p)->__bits[__cpuset_word(n)]& __cpuset_mask(n)) != 0)
end_define

begin_define
define|#
directive|define
name|CPU_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->__bits[__cpuset_word(n)] |= __cpuset_mask(n))
end_define

begin_define
define|#
directive|define
name|CPU_ZERO
parameter_list|(
name|p
parameter_list|)
value|do {				\ 	__size_t __i;					\ 	for (__i = 0; __i< _NCPUWORDS; __i++)		\ 		(p)->__bits[__i] = 0;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|CPU_FILL
parameter_list|(
name|p
parameter_list|)
value|do {				\ 	__size_t __i;					\ 	for (__i = 0; __i< _NCPUWORDS; __i++)		\ 		(p)->__bits[__i] = -1;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|CPU_SETOF
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|do {					\ 	CPU_ZERO(p);						\ 	((p)->__bits[__cpuset_word(n)] = __cpuset_mask(n));	\ } while (0)
end_define

begin_comment
comment|/* Is p empty. */
end_comment

begin_define
define|#
directive|define
name|CPU_EMPTY
parameter_list|(
name|p
parameter_list|)
value|__extension__ ({			\ 	__size_t __i;					\ 	for (__i = 0; __i< _NCPUWORDS; __i++)		\ 		if ((p)->__bits[__i])			\ 			break;				\ 	__i == _NCPUWORDS;				\ })
end_define

begin_comment
comment|/* Is p full set. */
end_comment

begin_define
define|#
directive|define
name|CPU_ISFULLSET
parameter_list|(
name|p
parameter_list|)
value|__extension__ ({		\ 	__size_t __i;					\ 	for (__i = 0; __i< _NCPUWORDS; __i++)		\ 		if ((p)->__bits[__i] != (long)-1)	\ 			break;				\ 	__i == _NCPUWORDS;				\ })
end_define

begin_comment
comment|/* Is c a subset of p. */
end_comment

begin_define
define|#
directive|define
name|CPU_SUBSET
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|__extension__ ({		\ 	__size_t __i;					\ 	for (__i = 0; __i< _NCPUWORDS; __i++)		\ 		if (((c)->__bits[__i]&			\ 		    (p)->__bits[__i]) !=		\ 		    (c)->__bits[__i])			\ 			break;				\ 	__i == _NCPUWORDS;				\ })
end_define

begin_comment
comment|/* Are there any common bits between b& c? */
end_comment

begin_define
define|#
directive|define
name|CPU_OVERLAP
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|__extension__ ({		\ 	__size_t __i;					\ 	for (__i = 0; __i< _NCPUWORDS; __i++)		\ 		if (((c)->__bits[__i]&			\ 		    (p)->__bits[__i]) != 0)		\ 			break;				\ 	__i != _NCPUWORDS;				\ })
end_define

begin_comment
comment|/* Compare two sets, returns 0 if equal 1 otherwise. */
end_comment

begin_define
define|#
directive|define
name|CPU_CMP
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|__extension__ ({			\ 	__size_t __i;					\ 	for (__i = 0; __i< _NCPUWORDS; __i++)		\ 		if (((c)->__bits[__i] !=		\ 		    (p)->__bits[__i]))			\ 			break;				\ 	__i != _NCPUWORDS;				\ })
end_define

begin_define
define|#
directive|define
name|CPU_OR
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|do {				\ 	__size_t __i;					\ 	for (__i = 0; __i< _NCPUWORDS; __i++)		\ 		(d)->__bits[__i] |= (s)->__bits[__i];	\ } while (0)
end_define

begin_define
define|#
directive|define
name|CPU_AND
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|do {				\ 	__size_t __i;					\ 	for (__i = 0; __i< _NCPUWORDS; __i++)		\ 		(d)->__bits[__i]&= (s)->__bits[__i];	\ } while (0)
end_define

begin_define
define|#
directive|define
name|CPU_NAND
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|do {				\ 	__size_t __i;					\ 	for (__i = 0; __i< _NCPUWORDS; __i++)		\ 		(d)->__bits[__i]&= ~(s)->__bits[__i];	\ } while (0)
end_define

begin_define
define|#
directive|define
name|CPU_CLR_ATOMIC
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|atomic_clear_long(&(p)->__bits[__cpuset_word(n)], __cpuset_mask(n))
end_define

begin_define
define|#
directive|define
name|CPU_SET_ATOMIC
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|atomic_set_long(&(p)->__bits[__cpuset_word(n)], __cpuset_mask(n))
end_define

begin_comment
comment|/* Convenience functions catering special cases. */
end_comment

begin_define
define|#
directive|define
name|CPU_OR_ATOMIC
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|do {			\ 	__size_t __i;					\ 	for (__i = 0; __i< _NCPUWORDS; __i++)		\ 		atomic_set_long(&(d)->__bits[__i],	\ 		    (s)->__bits[__i]);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|CPU_COPY_STORE_REL
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|do {				\ 	__size_t __i;						\ 	for (__i = 0; __i< _NCPUWORDS; __i++)			\ 		atomic_store_rel_long(&(t)->__bits[__i],	\ 		    (f)->__bits[__i]);				\ } while (0)
end_define

begin_comment
comment|/*  * Valid cpulevel_t values.  */
end_comment

begin_define
define|#
directive|define
name|CPU_LEVEL_ROOT
value|1
end_define

begin_comment
comment|/* All system cpus. */
end_comment

begin_define
define|#
directive|define
name|CPU_LEVEL_CPUSET
value|2
end_define

begin_comment
comment|/* Available cpus for which. */
end_comment

begin_define
define|#
directive|define
name|CPU_LEVEL_WHICH
value|3
end_define

begin_comment
comment|/* Actual mask/id for which. */
end_comment

begin_comment
comment|/*  * Valid cpuwhich_t values.  */
end_comment

begin_define
define|#
directive|define
name|CPU_WHICH_TID
value|1
end_define

begin_comment
comment|/* Specifies a thread id. */
end_comment

begin_define
define|#
directive|define
name|CPU_WHICH_PID
value|2
end_define

begin_comment
comment|/* Specifies a process id. */
end_comment

begin_define
define|#
directive|define
name|CPU_WHICH_CPUSET
value|3
end_define

begin_comment
comment|/* Specifies a set id. */
end_comment

begin_define
define|#
directive|define
name|CPU_WHICH_IRQ
value|4
end_define

begin_comment
comment|/* Specifies an irq #. */
end_comment

begin_define
define|#
directive|define
name|CPU_WHICH_JAIL
value|5
end_define

begin_comment
comment|/* Specifies a jail id. */
end_comment

begin_comment
comment|/*  * Reserved cpuset identifiers.  */
end_comment

begin_define
define|#
directive|define
name|CPUSET_INVALID
value|-1
end_define

begin_define
define|#
directive|define
name|CPUSET_DEFAULT
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|setlist
argument_list|,
name|cpuset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * cpusets encapsulate cpu binding information for one or more threads.  *  * 	a - Accessed with atomics.  *	s - Set at creation, never modified.  Only a ref required to read.  *	c - Locked internally by a cpuset lock.  *  * The bitmask is only modified while holding the cpuset lock.  It may be  * read while only a reference is held but the consumer must be prepared  * to deal with inconsistent results.  */
end_comment

begin_struct
struct|struct
name|cpuset
block|{
name|cpuset_t
name|cs_mask
decl_stmt|;
comment|/* bitmask of valid cpus. */
specifier|volatile
name|u_int
name|cs_ref
decl_stmt|;
comment|/* (a) Reference count. */
name|int
name|cs_flags
decl_stmt|;
comment|/* (s) Flags from below. */
name|cpusetid_t
name|cs_id
decl_stmt|;
comment|/* (s) Id or INVALID. */
name|struct
name|cpuset
modifier|*
name|cs_parent
decl_stmt|;
comment|/* (s) Pointer to our parent. */
name|LIST_ENTRY
argument_list|(
argument|cpuset
argument_list|)
name|cs_link
expr_stmt|;
comment|/* (c) All identified sets. */
name|LIST_ENTRY
argument_list|(
argument|cpuset
argument_list|)
name|cs_siblings
expr_stmt|;
comment|/* (c) Sibling set link. */
name|struct
name|setlist
name|cs_children
decl_stmt|;
comment|/* (c) List of children. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CPU_SET_ROOT
value|0x0001
end_define

begin_comment
comment|/* Set is a root set. */
end_comment

begin_define
define|#
directive|define
name|CPU_SET_RDONLY
value|0x0002
end_define

begin_comment
comment|/* No modification allowed. */
end_comment

begin_decl_stmt
specifier|extern
name|cpuset_t
modifier|*
name|cpuset_root
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|prison
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|cpuset
modifier|*
name|cpuset_thread0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cpuset
modifier|*
name|cpuset_ref
parameter_list|(
name|struct
name|cpuset
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpuset_rel
parameter_list|(
name|struct
name|cpuset
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpuset_setthread
parameter_list|(
name|lwpid_t
name|id
parameter_list|,
name|cpuset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpuset_create_root
parameter_list|(
name|struct
name|prison
modifier|*
parameter_list|,
name|struct
name|cpuset
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpuset_setproc_update_set
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|cpuset
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpusetobj_ffs
parameter_list|(
specifier|const
name|cpuset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cpusetobj_strprint
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|cpuset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpusetobj_strscan
parameter_list|(
name|cpuset_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_function_decl
name|void
name|ddb_display_cpuset
parameter_list|(
specifier|const
name|cpuset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_function_decl
name|__BEGIN_DECLS
name|int
name|cpuset
parameter_list|(
name|cpusetid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpuset_setid
parameter_list|(
name|cpuwhich_t
parameter_list|,
name|id_t
parameter_list|,
name|cpusetid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpuset_getid
parameter_list|(
name|cpulevel_t
parameter_list|,
name|cpuwhich_t
parameter_list|,
name|id_t
parameter_list|,
name|cpusetid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpuset_getaffinity
parameter_list|(
name|cpulevel_t
parameter_list|,
name|cpuwhich_t
parameter_list|,
name|id_t
parameter_list|,
name|size_t
parameter_list|,
name|cpuset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpuset_setaffinity
parameter_list|(
name|cpulevel_t
parameter_list|,
name|cpuwhich_t
parameter_list|,
name|id_t
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|cpuset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_CPUSET_H_ */
end_comment

end_unit

