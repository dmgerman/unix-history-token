begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)gmon.h	7.7 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_GMON_H_
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
name|spare
index|[
literal|3
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
comment|/*  * histogram counters are unsigned shorts (according to the kernel).  */
end_comment

begin_define
define|#
directive|define
name|HISTCOUNTER
value|unsigned short
end_define

begin_comment
comment|/*  * fraction of text space to allocate for histogram counters here, 1/2  */
end_comment

begin_define
define|#
directive|define
name|HISTFRACTION
value|2
end_define

begin_comment
comment|/*  * Fraction of text space to allocate for from hash buckets.  * The value of HASHFRACTION is based on the minimum number of bytes  * of separation between two subroutine call points in the object code.  * Given MIN_SUBR_SEPARATION bytes of separation the value of  * HASHFRACTION is calculated as:  *  *	HASHFRACTION = MIN_SUBR_SEPARATION / (2 * sizeof(short) - 1);  *  * For example, on the VAX, the shortest two call sequence is:  *  *	calls	$0,(r0)  *	calls	$0,(r0)  *  * which is separated by only three bytes, thus HASHFRACTION is   * calculated as:  *  *	HASHFRACTION = 3 / (2 * 2 - 1) = 1  *  * Note that the division above rounds down, thus if MIN_SUBR_FRACTION  * is less than three, this algorithm will not work!  *  * In practice, however, call instructions are rarely at a minimal   * distance.  Hence, we will define HASHFRACTION to be 2 across all  * architectures.  This saves a reasonable amount of space for   * profiling data structures without (in practice) sacrificing  * any granularity.  */
end_comment

begin_define
define|#
directive|define
name|HASHFRACTION
value|2
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

begin_define
define|#
directive|define
name|MAXARCS
value|((1<< (8 * sizeof(HISTCOUNTER))) - 2)
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
comment|/*  * a raw arc, with pointers to the calling site and   * the called site and a count.  */
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
value|(((x)/(y))*(y))
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
value|((((x)+(y)-1)/(y))*(y))
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
name|u_short
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
name|u_long
name|lowpc
decl_stmt|;
name|u_long
name|highpc
decl_stmt|;
name|u_long
name|textsize
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
comment|/* profiling enabling variable */
end_comment

begin_define
define|#
directive|define
name|GPROF_COUNT
value|1
end_define

begin_comment
comment|/* profile tick count buffer */
end_comment

begin_define
define|#
directive|define
name|GPROF_FROMS
value|2
end_define

begin_comment
comment|/* from location hash bucket */
end_comment

begin_define
define|#
directive|define
name|GPROF_TOS
value|3
end_define

begin_comment
comment|/* destination/count structure */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

