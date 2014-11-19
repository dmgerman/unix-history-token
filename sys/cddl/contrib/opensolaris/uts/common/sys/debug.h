begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2014 Garrett D'Amore<garrett@damore.org>  *  * Copyright 2010 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2012 by Delphix. All rights reserved.  */
end_comment

begin_comment
comment|/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DEBUG_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/note.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  * ASSERT(ex) causes a panic or debugger entry if expression ex is not  * true.  ASSERT() is included only for debugging, and is a no-op in  * production kernels.  VERIFY(ex), on the other hand, behaves like  * ASSERT and is evaluated on both debug and non-debug kernels.  */
specifier|extern
name|int
name|assfail
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
define|#
directive|define
name|VERIFY
parameter_list|(
name|EX
parameter_list|)
value|((void)((EX) || assfail(#EX, __FILE__, __LINE__)))
ifdef|#
directive|ifdef
name|DEBUG
define|#
directive|define
name|ASSERT
parameter_list|(
name|EX
parameter_list|)
value|((void)((EX) || assfail(#EX, __FILE__, __LINE__)))
else|#
directive|else
define|#
directive|define
name|ASSERT
parameter_list|(
name|x
parameter_list|)
value|((void)0)
endif|#
directive|endif
comment|/*  * Assertion variants sensitive to the compilation data model  */
if|#
directive|if
name|defined
argument_list|(
name|_LP64
argument_list|)
define|#
directive|define
name|ASSERT64
parameter_list|(
name|x
parameter_list|)
value|ASSERT(x)
define|#
directive|define
name|ASSERT32
parameter_list|(
name|x
parameter_list|)
else|#
directive|else
define|#
directive|define
name|ASSERT64
parameter_list|(
name|x
parameter_list|)
define|#
directive|define
name|ASSERT32
parameter_list|(
name|x
parameter_list|)
value|ASSERT(x)
endif|#
directive|endif
comment|/*  * IMPLY and EQUIV are assertions of the form:  *  *	if (a) then (b)  * and  *	if (a) then (b) *AND* if (b) then (a)  */
ifdef|#
directive|ifdef
name|DEBUG
define|#
directive|define
name|IMPLY
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|((void)(((!(A)) || (B)) || \ 	    assfail("(" #A ") implies (" #B ")", __FILE__, __LINE__)))
define|#
directive|define
name|EQUIV
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|((void)((!!(A) == !!(B)) || \ 	    assfail("(" #A ") is equivalent to (" #B ")", __FILE__, __LINE__)))
else|#
directive|else
define|#
directive|define
name|IMPLY
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|((void)0)
define|#
directive|define
name|EQUIV
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|((void)0)
endif|#
directive|endif
comment|/*  * ASSERT3() behaves like ASSERT() except that it is an explicit conditional,  * and prints out the values of the left and right hand expressions as part of  * the panic message to ease debugging.  The three variants imply the type  * of their arguments.  ASSERT3S() is for signed data types, ASSERT3U() is  * for unsigned, and ASSERT3P() is for pointers.  The VERIFY3*() macros  * have the same relationship as above.  */
specifier|extern
name|void
name|assfail3
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uintmax_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|uintmax_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
define|#
directive|define
name|VERIFY3_IMPL
parameter_list|(
name|LEFT
parameter_list|,
name|OP
parameter_list|,
name|RIGHT
parameter_list|,
name|TYPE
parameter_list|)
value|do { \ 	const TYPE __left = (TYPE)(LEFT); \ 	const TYPE __right = (TYPE)(RIGHT); \ 	if (!(__left OP __right)) \ 		assfail3(#LEFT " " #OP " " #RIGHT, \ 			(uintmax_t)__left, #OP, (uintmax_t)__right, \ 			__FILE__, __LINE__); \ _NOTE(CONSTCOND) } while (0)
define|#
directive|define
name|VERIFY3S
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|VERIFY3_IMPL(x, y, z, int64_t)
define|#
directive|define
name|VERIFY3U
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|VERIFY3_IMPL(x, y, z, uint64_t)
define|#
directive|define
name|VERIFY3P
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|VERIFY3_IMPL(x, y, z, uintptr_t)
define|#
directive|define
name|VERIFY0
parameter_list|(
name|x
parameter_list|)
value|VERIFY3_IMPL(x, ==, 0, uintmax_t)
ifdef|#
directive|ifdef
name|DEBUG
define|#
directive|define
name|ASSERT3S
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|VERIFY3_IMPL(x, y, z, int64_t)
define|#
directive|define
name|ASSERT3U
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|VERIFY3_IMPL(x, y, z, uint64_t)
define|#
directive|define
name|ASSERT3P
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|VERIFY3_IMPL(x, y, z, uintptr_t)
define|#
directive|define
name|ASSERT0
parameter_list|(
name|x
parameter_list|)
value|VERIFY3_IMPL(x, ==, 0, uintmax_t)
else|#
directive|else
define|#
directive|define
name|ASSERT3S
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((void)0)
define|#
directive|define
name|ASSERT3U
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((void)0)
define|#
directive|define
name|ASSERT3P
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((void)0)
define|#
directive|define
name|ASSERT0
parameter_list|(
name|x
parameter_list|)
value|((void)0)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_KERNEL
specifier|extern
name|void
name|abort_sequence_enter
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|debug_enter
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* _KERNEL */
if|#
directive|if
name|defined
argument_list|(
name|DEBUG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__sun
argument_list|)
comment|/* CSTYLED */
define|#
directive|define
name|STATIC
else|#
directive|else
comment|/* CSTYLED */
define|#
directive|define
name|STATIC
value|static
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_DEBUG_H */
end_comment

end_unit

