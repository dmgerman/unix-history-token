begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)fdset.h	1.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The following is defined just in case someone should want to run  * this telnet on a 4.2 system.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FD_SETSIZE
end_ifndef

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[0] |= (1<<(n)))
end_define

begin_define
define|#
directive|define
name|FD_CLR
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[0]&= ~(1<<(n)))
end_define

begin_define
define|#
directive|define
name|FD_ISSET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[0]& (1<<(n)))
end_define

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|p
parameter_list|)
value|((p)->fds_bits[0] = 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

