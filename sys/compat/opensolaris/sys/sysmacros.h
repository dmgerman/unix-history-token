begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_comment
comment|/*  * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_SYSMACROS_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_SYSMACROS_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
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
comment|/*  * Macro for checking power of 2 address alignment.  */
define|#
directive|define
name|IS_P2ALIGNED
parameter_list|(
name|v
parameter_list|,
name|a
parameter_list|)
value|((((uintptr_t)(v))& ((uintptr_t)(a) - 1)) == 0)
comment|/*  * Macro to determine if value is a power of 2  */
define|#
directive|define
name|ISP2
parameter_list|(
name|x
parameter_list|)
value|(((x)& ((x) - 1)) == 0)
comment|/*  * Macros for various sorts of alignment and rounding when the alignment  * is known to be a power of 2.  */
define|#
directive|define
name|P2ALIGN
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|)
value|((x)& -(align))
define|#
directive|define
name|P2PHASE
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|)
value|((x)& ((align) - 1))
define|#
directive|define
name|P2NPHASE
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|)
value|(-(x)& ((align) - 1))
define|#
directive|define
name|P2ROUNDUP
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|)
value|(-(-(x)& -(align)))
define|#
directive|define
name|P2END
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|)
value|(-(~(x)& -(align)))
define|#
directive|define
name|P2PHASEUP
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|,
name|phase
parameter_list|)
value|((phase) - (((phase) - (x))& -(align)))
define|#
directive|define
name|P2CROSS
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|align
parameter_list|)
value|(((x) ^ (y))> (align) - 1)
comment|/*  * Determine whether two numbers have the same high-order bit.  */
define|#
directive|define
name|P2SAMEHIGHBIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x) ^ (y))< ((x)& (y)))
comment|/*  * Typed version of the P2* macros.  These macros should be used to ensure  * that the result is correctly calculated based on the data type of (x),  * which is passed in as the last argument, regardless of the data  * type of the alignment.  For example, if (x) is of type uint64_t,  * and we want to round it up to a page boundary using "PAGESIZE" as  * the alignment, we can do either  *	P2ROUNDUP(x, (uint64_t)PAGESIZE)  * or  *	P2ROUNDUP_TYPED(x, PAGESIZE, uint64_t)  */
define|#
directive|define
name|P2ALIGN_TYPED
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|,
name|type
parameter_list|)
define|\
value|((type)(x)& -(type)(align))
define|#
directive|define
name|P2PHASE_TYPED
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|,
name|type
parameter_list|)
define|\
value|((type)(x)& ((type)(align) - 1))
define|#
directive|define
name|P2NPHASE_TYPED
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|,
name|type
parameter_list|)
define|\
value|(-(type)(x)& ((type)(align) - 1))
define|#
directive|define
name|P2ROUNDUP_TYPED
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|,
name|type
parameter_list|)
define|\
value|(-(-(type)(x)& -(type)(align)))
define|#
directive|define
name|P2END_TYPED
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|,
name|type
parameter_list|)
define|\
value|(-(~(type)(x)& -(type)(align)))
define|#
directive|define
name|P2PHASEUP_TYPED
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|,
name|phase
parameter_list|,
name|type
parameter_list|)
define|\
value|((type)(phase) - (((type)(phase) - (type)(x))& -(type)(align)))
define|#
directive|define
name|P2CROSS_TYPED
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|align
parameter_list|,
name|type
parameter_list|)
define|\
value|(((type)(x) ^ (type)(y))> (type)(align) - 1)
define|#
directive|define
name|P2SAMEHIGHBIT_TYPED
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|type
parameter_list|)
define|\
value|(((type)(x) ^ (type)(y))< ((type)(x)& (type)(y)))
ifdef|#
directive|ifdef
name|_KERNEL
define|#
directive|define
name|memmove
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|size
parameter_list|)
value|bcopy((src), (dst), (size))
endif|#
directive|endif
comment|/*  * Find highest one bit set.  *      Returns bit number + 1 of highest bit that is set, otherwise returns 0.  * High order bit is 31 (or 63 in _LP64 kernel).  */
specifier|static
name|__inline
name|int
name|highbit
parameter_list|(
name|ulong_t
name|i
parameter_list|)
block|{
specifier|register
name|int
name|h
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
ifdef|#
directive|ifdef
name|_LP64
if|if
condition|(
name|i
operator|&
literal|0xffffffff00000000ul
condition|)
block|{
name|h
operator|+=
literal|32
expr_stmt|;
name|i
operator|>>=
literal|32
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|i
operator|&
literal|0xffff0000
condition|)
block|{
name|h
operator|+=
literal|16
expr_stmt|;
name|i
operator|>>=
literal|16
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|&
literal|0xff00
condition|)
block|{
name|h
operator|+=
literal|8
expr_stmt|;
name|i
operator|>>=
literal|8
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|&
literal|0xf0
condition|)
block|{
name|h
operator|+=
literal|4
expr_stmt|;
name|i
operator|>>=
literal|4
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|&
literal|0xc
condition|)
block|{
name|h
operator|+=
literal|2
expr_stmt|;
name|i
operator|>>=
literal|2
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|&
literal|0x2
condition|)
block|{
name|h
operator|+=
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|h
operator|)
return|;
block|}
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
comment|/* _OPENSOLARIS_SYS_SYSMACROS_H_ */
end_comment

end_unit

