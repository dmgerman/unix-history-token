begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Source: /u1/X/hacks/bitrot/RCS/twiddle.h,v $  *	$Author: tony $  *	$Locker:  $  *	$Header: twiddle.h,v 10.1 86/02/01 15:43:23 tony Rel $  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* WARNING!  ASSUMES 8-BIT CHARACTERS! */
end_comment

begin_comment
comment|/* Each of these operates on the xth bit from map */
end_comment

begin_comment
comment|/* Map must be a pointer, not necessarily a u_char pointer */
end_comment

begin_define
define|#
directive|define
name|fetch
parameter_list|(
name|map
parameter_list|,
name|x
parameter_list|)
value|(1& (((u_char *) map)[x>> 3]>> (x& 7)))
end_define

begin_define
define|#
directive|define
name|set
parameter_list|(
name|map
parameter_list|,
name|x
parameter_list|)
value|((((u_char *) map)[x>>3] |= 1<< (x& 7)))
end_define

begin_define
define|#
directive|define
name|reset
parameter_list|(
name|map
parameter_list|,
name|x
parameter_list|)
value|((((u_char *) map)[x>>3]&= ~(1<< (x& 7))))
end_define

begin_define
define|#
directive|define
name|flip
parameter_list|(
name|map
parameter_list|,
name|x
parameter_list|)
value|((((u_char *) map)[x>>3] ^=  1<< (x& 7)))
end_define

begin_define
define|#
directive|define
name|place
parameter_list|(
name|map
parameter_list|,
name|x
parameter_list|,
name|bit
parameter_list|)
value|((bit ? set(map,x),0 : reset(map,x), 0))
end_define

end_unit

