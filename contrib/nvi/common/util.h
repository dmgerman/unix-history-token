begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)util.h	10.5 (Berkeley) 3/16/96  */
end_comment

begin_comment
comment|/* Macros to init/set/clear/test flags. */
end_comment

begin_define
define|#
directive|define
name|FL_INIT
parameter_list|(
name|l
parameter_list|,
name|f
parameter_list|)
value|(l) = (f)
end_define

begin_comment
comment|/* Specific flags location. */
end_comment

begin_define
define|#
directive|define
name|FL_SET
parameter_list|(
name|l
parameter_list|,
name|f
parameter_list|)
value|((l) |= (f))
end_define

begin_define
define|#
directive|define
name|FL_CLR
parameter_list|(
name|l
parameter_list|,
name|f
parameter_list|)
value|((l)&= ~(f))
end_define

begin_define
define|#
directive|define
name|FL_ISSET
parameter_list|(
name|l
parameter_list|,
name|f
parameter_list|)
value|((l)& (f))
end_define

begin_define
define|#
directive|define
name|LF_INIT
parameter_list|(
name|f
parameter_list|)
value|FL_INIT(flags, f)
end_define

begin_comment
comment|/* Local variable flags. */
end_comment

begin_define
define|#
directive|define
name|LF_SET
parameter_list|(
name|f
parameter_list|)
value|FL_SET(flags, f)
end_define

begin_define
define|#
directive|define
name|LF_CLR
parameter_list|(
name|f
parameter_list|)
value|FL_CLR(flags, f)
end_define

begin_define
define|#
directive|define
name|LF_ISSET
parameter_list|(
name|f
parameter_list|)
value|FL_ISSET(flags, f)
end_define

begin_define
define|#
directive|define
name|F_INIT
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|)
value|FL_INIT((p)->flags, f)
end_define

begin_comment
comment|/* Structure element flags. */
end_comment

begin_define
define|#
directive|define
name|F_SET
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|)
value|FL_SET((p)->flags, f)
end_define

begin_define
define|#
directive|define
name|F_CLR
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|)
value|FL_CLR((p)->flags, f)
end_define

begin_define
define|#
directive|define
name|F_ISSET
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|)
value|FL_ISSET((p)->flags, f)
end_define

begin_comment
comment|/* Offset to next column of stop size, e.g. tab offsets. */
end_comment

begin_define
define|#
directive|define
name|COL_OFF
parameter_list|(
name|c
parameter_list|,
name|stop
parameter_list|)
value|((stop) - ((c) % (stop)))
end_define

begin_comment
comment|/* Busy message types. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|B_NONE
block|,
name|B_OFF
block|,
name|B_READ
block|,
name|B_RECOVER
block|,
name|B_SEARCH
block|,
name|B_WRITE
block|}
name|bmsg_t
typedef|;
end_typedef

begin_comment
comment|/*  * Number handling defines and protoypes.  *  * NNFITS:	test for addition of two negative numbers under a limit  * NPFITS:	test for addition of two positive numbers under a limit  * NADD_SLONG:	test for addition of two signed longs  * NADD_USLONG:	test for addition of two unsigned longs  */
end_comment

begin_enum
enum|enum
name|nresult
block|{
name|NUM_ERR
block|,
name|NUM_OK
block|,
name|NUM_OVER
block|,
name|NUM_UNDER
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|NNFITS
parameter_list|(
name|min
parameter_list|,
name|cur
parameter_list|,
name|add
parameter_list|)
define|\
value|(((long)(min)) - (cur)<= (add))
end_define

begin_define
define|#
directive|define
name|NPFITS
parameter_list|(
name|max
parameter_list|,
name|cur
parameter_list|,
name|add
parameter_list|)
define|\
value|(((unsigned long)(max)) - (cur)>= (add))
end_define

begin_define
define|#
directive|define
name|NADD_SLONG
parameter_list|(
name|sp
parameter_list|,
name|v1
parameter_list|,
name|v2
parameter_list|)
define|\
value|((v1)< 0 ?							\ 	    ((v2)< 0&&						\ 	    NNFITS(LONG_MIN, (v1), (v2))) ? NUM_UNDER : NUM_OK :	\ 	 (v1)> 0 ?							\ 	    (v2)> 0&&							\ 	    NPFITS(LONG_MAX, (v1), (v2)) ? NUM_OK : NUM_OVER :		\ 	 NUM_OK)
end_define

begin_define
define|#
directive|define
name|NADD_USLONG
parameter_list|(
name|sp
parameter_list|,
name|v1
parameter_list|,
name|v2
parameter_list|)
define|\
value|(NPFITS(ULONG_MAX, (v1), (v2)) ? NUM_OK : NUM_OVER)
end_define

end_unit

