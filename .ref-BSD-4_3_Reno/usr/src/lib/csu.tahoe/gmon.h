begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)gmon.h	2.0 (Tahoe) 3/20/85 */
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
comment|/*      *	Fraction of text space to allocate for from hash buckets.      *	The value of HASHFRACTION is based on the minimum number of bytes      *	of separation between two subroutine call points in the object code.      *	Given MIN_SUBR_SEPARATION bytes of separation the value of      *	HASHFRACTION is calculated as:      *      *		HASHFRACTION = MIN_SUBR_SEPARATION / (2 * sizeof(short) - 1);      *      *	For the Tahoe, the shortest two call sequence is:      *      *		calls	$0,(r0)      *		calls	$0,(r0)      *      *	which is separated by only three bytes, thus HASHFRACTION is       *	calculated as:      *      *		HASHFRACTION = 3 / (2 * 2 - 1) = 1      *      *	Note that the division above rounds down, thus if MIN_SUBR_FRACTION      *	is less than three, this algorithm will not work!      */
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

