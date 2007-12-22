begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file drm_atomic.h  * Atomic operations used in the DRM which may or may not be provided by the OS.  *   * \author Eric Anholt<anholt@FreeBSD.org>  */
end_comment

begin_comment
comment|/*-  * Copyright 2004 Eric Anholt  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Many of these implementations are rather fake, but good enough. */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|atomic_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|atomic_set
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|(*(p) = (v))
end_define

begin_define
define|#
directive|define
name|atomic_read
parameter_list|(
name|p
parameter_list|)
value|(*(p))
end_define

begin_define
define|#
directive|define
name|atomic_inc
parameter_list|(
name|p
parameter_list|)
value|atomic_add_int(p, 1)
end_define

begin_define
define|#
directive|define
name|atomic_dec
parameter_list|(
name|p
parameter_list|)
value|atomic_subtract_int(p, 1)
end_define

begin_define
define|#
directive|define
name|atomic_add
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|atomic_add_int(p, n)
end_define

begin_define
define|#
directive|define
name|atomic_sub
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|atomic_subtract_int(p, n)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_comment
comment|/* FIXME */
end_comment

begin_define
define|#
directive|define
name|atomic_set
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|(*(p) = (v))
end_define

begin_define
define|#
directive|define
name|atomic_read
parameter_list|(
name|p
parameter_list|)
value|(*(p))
end_define

begin_define
define|#
directive|define
name|atomic_inc
parameter_list|(
name|p
parameter_list|)
value|(*(p) += 1)
end_define

begin_define
define|#
directive|define
name|atomic_dec
parameter_list|(
name|p
parameter_list|)
value|(*(p) -= 1)
end_define

begin_define
define|#
directive|define
name|atomic_add
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|(*(p) += (n))
end_define

begin_define
define|#
directive|define
name|atomic_sub
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|(*(p) -= (n))
end_define

begin_comment
comment|/* FIXME */
end_comment

begin_define
define|#
directive|define
name|atomic_add_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|*(p) += v
end_define

begin_define
define|#
directive|define
name|atomic_subtract_int
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|*(p) -= v
end_define

begin_define
define|#
directive|define
name|atomic_set_int
parameter_list|(
name|p
parameter_list|,
name|bits
parameter_list|)
value|*(p) |= (bits)
end_define

begin_define
define|#
directive|define
name|atomic_clear_int
parameter_list|(
name|p
parameter_list|,
name|bits
parameter_list|)
value|*(p)&= ~(bits)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__FreeBSD__ */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|||
operator|(
name|__FreeBSD_version
operator|<
literal|500000
operator|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_comment
comment|/* The extra atomic functions from 5.0 haven't been merged to 4.x */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|atomic_cmpset_int
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|dst
parameter_list|,
name|u_int
name|exp
parameter_list|,
name|u_int
name|src
parameter_list|)
block|{
name|int
name|res
init|=
name|exp
decl_stmt|;
asm|__asm __volatile (
literal|"	lock ;			"
literal|"	cmpxchgl %1,%2 ;	"
literal|"       setz	%%al ;		"
literal|"	movzbl	%%al,%0 ;	"
literal|"1:				"
literal|"# atomic_cmpset_int"
operator|:
literal|"+a"
operator|(
name|res
operator|)
comment|/* 0 (result) */
operator|:
literal|"r"
operator|(
name|src
operator|)
operator|,
comment|/* 1 */
literal|"m"
operator|(
operator|*
operator|(
name|dst
operator|)
operator|)
comment|/* 2 */
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|res
operator|)
return|;
end_return

begin_else
unit|}
else|#
directive|else
end_else

begin_comment
comment|/* __i386__ */
end_comment

begin_function
unit|static
name|__inline
name|int
name|atomic_cmpset_int
parameter_list|(
specifier|__volatile__
name|int
modifier|*
name|dst
parameter_list|,
name|int
name|old
parameter_list|,
name|int
name|new
parameter_list|)
block|{
name|int
name|s
init|=
name|splhigh
argument_list|()
decl_stmt|;
if|if
condition|(
operator|*
name|dst
operator|==
name|old
condition|)
block|{
operator|*
name|dst
operator|=
name|new
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__i386__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__FreeBSD_version || __FreeBSD_version< 500000 */
end_comment

begin_function
specifier|static
name|__inline
name|atomic_t
name|test_and_set_bit
parameter_list|(
name|int
name|b
parameter_list|,
specifier|volatile
name|void
modifier|*
name|p
parameter_list|)
block|{
name|int
name|s
init|=
name|splhigh
argument_list|()
decl_stmt|;
name|unsigned
name|int
name|m
init|=
literal|1
operator|<<
name|b
decl_stmt|;
name|unsigned
name|int
name|r
init|=
operator|*
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|p
operator|&
name|m
decl_stmt|;
operator|*
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|p
operator||=
name|m
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
name|r
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|clear_bit
parameter_list|(
name|int
name|b
parameter_list|,
specifier|volatile
name|void
modifier|*
name|p
parameter_list|)
block|{
name|atomic_clear_int
argument_list|(
operator|(
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|p
operator|)
operator|+
operator|(
name|b
operator|>>
literal|5
operator|)
argument_list|,
literal|1
operator|<<
operator|(
name|b
operator|&
literal|0x1f
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|set_bit
parameter_list|(
name|int
name|b
parameter_list|,
specifier|volatile
name|void
modifier|*
name|p
parameter_list|)
block|{
name|atomic_set_int
argument_list|(
operator|(
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|p
operator|)
operator|+
operator|(
name|b
operator|>>
literal|5
operator|)
argument_list|,
literal|1
operator|<<
operator|(
name|b
operator|&
literal|0x1f
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|test_bit
parameter_list|(
name|int
name|b
parameter_list|,
specifier|volatile
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|p
operator|)
index|[
name|b
operator|>>
literal|5
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|b
operator|&
literal|0x1f
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|find_first_zero_bit
parameter_list|(
specifier|volatile
name|void
modifier|*
name|p
parameter_list|,
name|int
name|max
parameter_list|)
block|{
name|int
name|b
decl_stmt|;
specifier|volatile
name|int
modifier|*
name|ptr
init|=
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|p
decl_stmt|;
for|for
control|(
name|b
operator|=
literal|0
init|;
name|b
operator|<
name|max
condition|;
name|b
operator|+=
literal|32
control|)
block|{
if|if
condition|(
name|ptr
index|[
name|b
operator|>>
literal|5
index|]
operator|!=
operator|~
literal|0
condition|)
block|{
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
operator|(
name|ptr
index|[
name|b
operator|>>
literal|5
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|b
operator|&
literal|0x1f
operator|)
operator|)
operator|)
operator|==
literal|0
condition|)
return|return
name|b
return|;
name|b
operator|++
expr_stmt|;
block|}
block|}
block|}
return|return
name|max
return|;
block|}
end_function

end_unit

