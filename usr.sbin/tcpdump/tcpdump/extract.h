begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $FreeBSD$ (LBL)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TCPDUMP_ALIGN
end_ifdef

begin_if
if|#
directive|if
name|BYTEORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|EXTRACT_SHORT
parameter_list|(
name|p
parameter_list|)
define|\
value|((u_short)\ 		((u_short)*((u_char *)p+1)<<8|\ 		 (u_short)*((u_char *)p+0)<<0))
end_define

begin_define
define|#
directive|define
name|EXTRACT_LONG
parameter_list|(
name|p
parameter_list|)
define|\
value|((u_int32)*((u_char *)p+3)<<24|\ 		 (u_int32)*((u_char *)p+2)<<16|\ 		 (u_int32)*((u_char *)p+1)<<8|\ 		 (u_int32)*((u_char *)p+0)<<0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTRACT_SHORT
parameter_list|(
name|p
parameter_list|)
define|\
value|((u_short)\ 		((u_short)*((u_char *)p+0)<<8|\ 		 (u_short)*((u_char *)p+1)<<0))
end_define

begin_define
define|#
directive|define
name|EXTRACT_LONG
parameter_list|(
name|p
parameter_list|)
define|\
value|((u_int32)*((u_char *)p+0)<<24|\ 		 (u_int32)*((u_char *)p+1)<<16|\ 		 (u_int32)*((u_char *)p+2)<<8|\ 		 (u_int32)*((u_char *)p+3)<<0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTRACT_SHORT
parameter_list|(
name|p
parameter_list|)
value|((u_short)ntohs(*(u_short *)p))
end_define

begin_define
define|#
directive|define
name|EXTRACT_LONG
parameter_list|(
name|p
parameter_list|)
value|(ntohl(*(u_int32 *)p))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

