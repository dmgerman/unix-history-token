begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $FreeBSD$ (LBL)  */
end_comment

begin_define
define|#
directive|define
name|TCPDUMP_ALIGN
end_define

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_comment
comment|/* 32-bit data types */
end_comment

begin_comment
comment|/* N.B.: this doesn't address printf()'s %d vs. %ld formats */
end_comment

begin_typedef
typedef|typedef
name|long
name|int32
typedef|;
end_typedef

begin_comment
comment|/* signed 32-bit integer */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTH_UNIX
end_ifndef

begin_typedef
typedef|typedef
name|u_long
name|u_int32
typedef|;
end_typedef

begin_comment
comment|/* unsigned 32-bit integer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

