begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. LAR PURPOSE.  *  *	@(#)defines.h	1.10 (Berkeley) 6/28/90  */
end_comment

begin_define
define|#
directive|define
name|settimer
parameter_list|(
name|x
parameter_list|)
value|clocks.x = clocks.system++
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TN3270
argument_list|)
end_if

begin_define
define|#
directive|define
name|SetIn3270
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(TN3270) */
end_comment

begin_define
define|#
directive|define
name|NETADD
parameter_list|(
name|c
parameter_list|)
value|{ *netoring.supply = c; ring_supplied(&netoring, 1); }
end_define

begin_define
define|#
directive|define
name|NET2ADD
parameter_list|(
name|c1
parameter_list|,
name|c2
parameter_list|)
value|{ NETADD(c1); NETADD(c2); }
end_define

begin_define
define|#
directive|define
name|NETBYTES
parameter_list|()
value|(ring_full_count(&netoring))
end_define

begin_define
define|#
directive|define
name|NETROOM
parameter_list|()
value|(ring_empty_count(&netoring))
end_define

begin_define
define|#
directive|define
name|TTYADD
parameter_list|(
name|c
parameter_list|)
value|if (!(SYNCHing||flushout)) { \ 				*ttyoring.supply = c; \ 				ring_supplied(&ttyoring, 1); \ 			}
end_define

begin_define
define|#
directive|define
name|TTYBYTES
parameter_list|()
value|(ring_full_count(&ttyoring))
end_define

begin_define
define|#
directive|define
name|TTYROOM
parameter_list|()
value|(ring_empty_count(&ttyoring))
end_define

begin_comment
comment|/*	Various modes */
end_comment

begin_define
define|#
directive|define
name|MODE_LOCAL_CHARS
parameter_list|(
name|m
parameter_list|)
value|((m)&(MODE_EDIT|MODE_TRAPSIG))
end_define

begin_define
define|#
directive|define
name|MODE_LOCAL_ECHO
parameter_list|(
name|m
parameter_list|)
value|((m)&MODE_ECHO)
end_define

begin_define
define|#
directive|define
name|MODE_COMMAND_LINE
parameter_list|(
name|m
parameter_list|)
value|((m)==-1)
end_define

begin_define
define|#
directive|define
name|CONTROL
parameter_list|(
name|x
parameter_list|)
value|((x)&0x1f)
end_define

begin_comment
comment|/* CTRL(x) is not portable */
end_comment

end_unit

