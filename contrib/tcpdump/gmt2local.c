begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/gmt2local.c,v 1.4 2000/07/11 00:49:02 assar Exp $ (LBL)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TIME_WITH_SYS_TIME
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OS_PROTO_H
end_ifdef

begin_include
include|#
directive|include
file|"os-proto.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"gmt2local.h"
end_include

begin_comment
comment|/*  * Returns the difference between gmt and local time in seconds.  * Use gmtime() and localtime() to keep things simple.  */
end_comment

begin_function
name|int32_t
name|gmt2local
parameter_list|(
name|time_t
name|t
parameter_list|)
block|{
specifier|register
name|int
name|dt
decl_stmt|,
name|dir
decl_stmt|;
specifier|register
name|struct
name|tm
modifier|*
name|gmt
decl_stmt|,
modifier|*
name|loc
decl_stmt|;
name|struct
name|tm
name|sgmt
decl_stmt|;
if|if
condition|(
name|t
operator|==
literal|0
condition|)
name|t
operator|=
name|time
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|gmt
operator|=
operator|&
name|sgmt
expr_stmt|;
operator|*
name|gmt
operator|=
operator|*
name|gmtime
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|loc
operator|=
name|localtime
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|dt
operator|=
operator|(
name|loc
operator|->
name|tm_hour
operator|-
name|gmt
operator|->
name|tm_hour
operator|)
operator|*
literal|60
operator|*
literal|60
operator|+
operator|(
name|loc
operator|->
name|tm_min
operator|-
name|gmt
operator|->
name|tm_min
operator|)
operator|*
literal|60
expr_stmt|;
comment|/* 	 * If the year or julian day is different, we span 00:00 GMT 	 * and must add or subtract a day. Check the year first to 	 * avoid problems when the julian day wraps. 	 */
name|dir
operator|=
name|loc
operator|->
name|tm_year
operator|-
name|gmt
operator|->
name|tm_year
expr_stmt|;
if|if
condition|(
name|dir
operator|==
literal|0
condition|)
name|dir
operator|=
name|loc
operator|->
name|tm_yday
operator|-
name|gmt
operator|->
name|tm_yday
expr_stmt|;
name|dt
operator|+=
name|dir
operator|*
literal|24
operator|*
literal|60
operator|*
literal|60
expr_stmt|;
return|return
operator|(
name|dt
operator|)
return|;
block|}
end_function

end_unit

