begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)gmon.h	5.3 (Berkeley) 5/6/91  */
end_comment

begin_struct
struct|struct
name|phdr
block|{
name|char
modifier|*
name|lpc
decl_stmt|;
name|char
modifier|*
name|hpc
decl_stmt|;
name|int
name|ncnt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*      *	histogram counters are unsigned shorts (according to the kernel).      */
end_comment

begin_define
define|#
directive|define
name|HISTCOUNTER
value|unsigned short
end_define

begin_comment
comment|/*      *	fraction of text space to allocate for histogram counters      *	here, 1/2      */
end_comment

begin_define
define|#
directive|define
name|HISTFRACTION
value|2
end_define

begin_comment
comment|/*      *	Fraction of text space to allocate for from hash buckets.      *	The value of HASHFRACTION is based on the minimum number of bytes      *	of separation between two subroutine call points in the object code.      *	Given MIN_SUBR_SEPARATION bytes of separation the value of      *	HASHFRACTION is calculated as:      *      *		HASHFRACTION = MIN_SUBR_SEPARATION / (2 * sizeof(short) - 1);      *      *	For the VAX, the shortest two call sequence is:      *      *		calls	$0,(r0)      *		calls	$0,(r0)      *      *	which is separated by only three bytes, thus HASHFRACTION is       *	calculated as:      *      *		HASHFRACTION = 3 / (2 * 2 - 1) = 1      *      *	Note that the division above rounds down, thus if MIN_SUBR_FRACTION      *	is less than three, this algorithm will not work!      */
end_comment

begin_define
define|#
directive|define
name|HASHFRACTION
value|1
end_define

begin_comment
comment|/*      *	percent of text space to allocate for tostructs      *	with a minimum.      */
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

begin_struct
struct|struct
name|tostruct
block|{
name|char
modifier|*
name|selfpc
decl_stmt|;
name|long
name|count
decl_stmt|;
name|unsigned
name|short
name|link
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*      *	a raw arc,      *	    with pointers to the calling site and the called site      *	    and a count.      */
end_comment

begin_struct
struct|struct
name|rawarc
block|{
name|unsigned
name|long
name|raw_frompc
decl_stmt|;
name|unsigned
name|long
name|raw_selfpc
decl_stmt|;
name|long
name|raw_count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*      *	general rounding functions.      */
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

end_unit

