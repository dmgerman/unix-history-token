begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: /tcpdump/master/tcpdump/gmt2local.h,v 1.2.1.1 1999/10/07 23:47:10 mcr Exp $ (LBL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|gmt2local_h
end_ifndef

begin_define
define|#
directive|define
name|gmt2local_h
end_define

begin_function_decl
name|int32_t
name|gmt2local
parameter_list|(
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

