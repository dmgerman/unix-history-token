begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Proofpoint, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: time.h,v 1.2 2013-11-22 20:51:32 ca Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_TIME_H
end_ifndef

begin_define
define|#
directive|define
name|SM_TIME_H
value|1
end_define

begin_include
include|#
directive|include
file|<sm/config.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* should be defined in sys/time.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|timersub
end_ifndef

begin_define
define|#
directive|define
name|timersub
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|vvp
parameter_list|)
define|\
value|do								\ 	{								\ 		(vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;		\ 		(vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;	\ 		if ((vvp)->tv_usec< 0)					\ 		{							\ 			(vvp)->tv_sec--;				\ 			(vvp)->tv_usec += 1000000;			\ 		}							\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !timersub */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|timeradd
end_ifndef

begin_define
define|#
directive|define
name|timeradd
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|vvp
parameter_list|)
define|\
value|do								\ 	{								\ 		(vvp)->tv_sec = (tvp)->tv_sec + (uvp)->tv_sec;		\ 		(vvp)->tv_usec = (tvp)->tv_usec + (uvp)->tv_usec;	\ 		if ((vvp)->tv_usec>= 1000000)				\ 		{							\ 			(vvp)->tv_sec++;				\ 			(vvp)->tv_usec -= 1000000;			\ 		}							\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !timeradd */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|timercmp
end_ifndef

begin_define
define|#
directive|define
name|timercmp
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|cmp
parameter_list|)
define|\
value|(((tvp)->tv_sec == (uvp)->tv_sec) ?				\ 	    ((tvp)->tv_usec cmp (uvp)->tv_usec) :			\ 	    ((tvp)->tv_sec cmp (uvp)->tv_sec))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !timercmp */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_TIME_H */
end_comment

end_unit

