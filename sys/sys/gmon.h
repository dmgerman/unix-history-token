begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)gmon.h	8.2 (Berkeley) 1/4/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_GMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_GMON_H_
end_define

begin_include
include|#
directive|include
file|<machine/profile.h>
end_include

begin_comment
comment|/*  * Structure prepended to gmon.out profiling data file.  */
end_comment

begin_struct
struct|struct
name|gmonhdr
block|{
name|u_long
name|lpc
decl_stmt|;
comment|/* base pc address of sample buffer */
name|u_long
name|hpc
decl_stmt|;
comment|/* max pc address of sampled buffer */
name|int
name|ncnt
decl_stmt|;
comment|/* size of sample buffer (plus this header) */
name|int
name|version
decl_stmt|;
comment|/* version number */
name|int
name|profrate
decl_stmt|;
comment|/* profiling clock rate */
name|int
name|histcounter_type
decl_stmt|;
comment|/* size (in bits) and sign of HISTCOUNTER */
name|int
name|spare
index|[
literal|2
index|]
decl_stmt|;
comment|/* reserved */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GMONVERSION
value|0x00051879
end_define

begin_comment
comment|/*  * Type of histogram counters used in the kernel.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GPROF4
end_ifdef

begin_define
define|#
directive|define
name|HISTCOUNTER
value|int64_t
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HISTCOUNTER
value|unsigned short
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Fraction of text space to allocate for histogram counters.  * We allocate counters at the same or higher density as function  * addresses, so that each counter belongs to a unique function.  * A lower density of counters would give less resolution but a  * higher density would be wasted.  */
end_comment

begin_define
define|#
directive|define
name|HISTFRACTION
value|(FUNCTION_ALIGNMENT / sizeof(HISTCOUNTER) == 0 \ 			 ? 1 : FUNCTION_ALIGNMENT / sizeof(HISTCOUNTER))
end_define

begin_comment
comment|/*  * Fraction of text space to allocate for from hash buckets.  * The value of HASHFRACTION is based on the minimum number of bytes  * of separation between two subroutine call points in the object code.  * Given MIN_SUBR_SEPARATION bytes of separation the value of  * HASHFRACTION is calculated as:  *  *	HASHFRACTION = MIN_SUBR_SEPARATION / (2 * sizeof(short) - 1);  *  * For example, on the VAX, the shortest two call sequence is:  *  *	calls	$0,(r0)  *	calls	$0,(r0)  *  * which is separated by only three bytes, thus HASHFRACTION is  * calculated as:  *  *	HASHFRACTION = 3 / (2 * 2 - 1) = 1  *  * Note that the division above rounds down, thus if MIN_SUBR_FRACTION  * is less than three, this algorithm will not work!  *  * In practice, however, call instructions are rarely at a minimal  * distance.  Hence, we will define HASHFRACTION to be 2 across all  * architectures.  This saves a reasonable amount of space for  * profiling data structures without (in practice) sacrificing  * any granularity.  */
end_comment

begin_comment
comment|/*  * XXX I think the above analysis completely misses the point.  I think  * the point is that addresses in different functions must hash to  * different values.  Since the hash is essentially division by  * sizeof(unsigned short), the correct formula is:  *  * 	HASHFRACTION = MIN_FUNCTION_ALIGNMENT / sizeof(unsigned short)  *  * Note that he unsigned short here has nothing to do with the one for  * HISTFRACTION.  *  * Hash collisions from a two call sequence don't matter.  They get  * handled like collisions for calls to different addresses from the  * same address through a function pointer.  */
end_comment

begin_define
define|#
directive|define
name|HASHFRACTION
value|(FUNCTION_ALIGNMENT / sizeof(unsigned short) == 0 \ 			 ? 1 : FUNCTION_ALIGNMENT / sizeof(unsigned short))
end_define

begin_comment
comment|/*  * percent of text space to allocate for tostructs with a minimum.  */
end_comment

begin_define
define|#
directive|define
name|ARCDENSITY
value|2
end_define

begin_define
define|#
directive|define
name|MINARCS
value|50
end_define

begin_comment
comment|/*  * Limit on the number of arcs to so that arc numbers can be stored in  * `*froms' and stored and incremented without overflow in links.  */
end_comment

begin_define
define|#
directive|define
name|MAXARCS
value|(((u_long)1<< (8 * sizeof(u_short))) - 2)
end_define

begin_struct
struct|struct
name|tostruct
block|{
name|u_long
name|selfpc
decl_stmt|;
name|long
name|count
decl_stmt|;
name|u_short
name|link
decl_stmt|;
name|u_short
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * a raw arc, with pointers to the calling site and  * the called site and a count.  */
end_comment

begin_struct
struct|struct
name|rawarc
block|{
name|u_long
name|raw_frompc
decl_stmt|;
name|u_long
name|raw_selfpc
decl_stmt|;
name|long
name|raw_count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * general rounding functions.  */
end_comment

begin_define
define|#
directive|define
name|ROUNDDOWN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|rounddown(x,y)
end_define

begin_define
define|#
directive|define
name|ROUNDUP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|roundup(x,y)
end_define

begin_comment
comment|/*  * The profiling data structures are housed in this structure.  */
end_comment

begin_struct
struct|struct
name|gmonparam
block|{
name|int
name|state
decl_stmt|;
name|HISTCOUNTER
modifier|*
name|kcount
decl_stmt|;
name|u_long
name|kcountsize
decl_stmt|;
name|u_short
modifier|*
name|froms
decl_stmt|;
name|u_long
name|fromssize
decl_stmt|;
name|struct
name|tostruct
modifier|*
name|tos
decl_stmt|;
name|u_long
name|tossize
decl_stmt|;
name|long
name|tolimit
decl_stmt|;
name|uintfptr_t
name|lowpc
decl_stmt|;
name|uintfptr_t
name|highpc
decl_stmt|;
name|u_long
name|textsize
decl_stmt|;
name|u_long
name|hashfraction
decl_stmt|;
name|int
name|profrate
decl_stmt|;
comment|/* XXX wrong type to match gmonhdr */
name|HISTCOUNTER
modifier|*
name|cputime_count
decl_stmt|;
name|int
name|cputime_overhead
decl_stmt|;
name|HISTCOUNTER
modifier|*
name|mcount_count
decl_stmt|;
name|int
name|mcount_overhead
decl_stmt|;
name|int
name|mcount_post_overhead
decl_stmt|;
name|int
name|mcount_pre_overhead
decl_stmt|;
name|HISTCOUNTER
modifier|*
name|mexitcount_count
decl_stmt|;
name|int
name|mexitcount_overhead
decl_stmt|;
name|int
name|mexitcount_post_overhead
decl_stmt|;
name|int
name|mexitcount_pre_overhead
decl_stmt|;
name|int
name|histcounter_type
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|gmonparam
name|_gmonparam
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Possible states of profiling.  */
end_comment

begin_define
define|#
directive|define
name|GMON_PROF_ON
value|0
end_define

begin_define
define|#
directive|define
name|GMON_PROF_BUSY
value|1
end_define

begin_define
define|#
directive|define
name|GMON_PROF_ERROR
value|2
end_define

begin_define
define|#
directive|define
name|GMON_PROF_OFF
value|3
end_define

begin_define
define|#
directive|define
name|GMON_PROF_HIRES
value|4
end_define

begin_comment
comment|/*  * Sysctl definitions for extracting profiling information from the kernel.  */
end_comment

begin_define
define|#
directive|define
name|GPROF_STATE
value|0
end_define

begin_comment
comment|/* int: profiling enabling variable */
end_comment

begin_define
define|#
directive|define
name|GPROF_COUNT
value|1
end_define

begin_comment
comment|/* struct: profile tick count buffer */
end_comment

begin_define
define|#
directive|define
name|GPROF_FROMS
value|2
end_define

begin_comment
comment|/* struct: from location hash bucket */
end_comment

begin_define
define|#
directive|define
name|GPROF_TOS
value|3
end_define

begin_comment
comment|/* struct: destination/count structure */
end_comment

begin_define
define|#
directive|define
name|GPROF_GMONPARAM
value|4
end_define

begin_comment
comment|/* struct: profiling parameters (see above) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_GMON_H_ */
end_comment

end_unit

