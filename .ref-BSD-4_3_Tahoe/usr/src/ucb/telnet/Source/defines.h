begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)defines.h	1.5 (Berkeley) 3/8/88  */
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
name|ExitString
parameter_list|(
name|s
parameter_list|,
name|r
parameter_list|)
value|{ fprintf(stderr, s); exit(r); }
end_define

begin_define
define|#
directive|define
name|Exit
parameter_list|(
name|x
parameter_list|)
value|exit(x)
end_define

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
name|MODE_LINE
parameter_list|(
name|m
parameter_list|)
value|(modelist[m].modetype& LINE)
end_define

begin_define
define|#
directive|define
name|MODE_LOCAL_CHARS
parameter_list|(
name|m
parameter_list|)
value|(modelist[m].modetype&  LOCAL_CHARS)
end_define

begin_define
define|#
directive|define
name|MODE_LOCAL_ECHO
parameter_list|(
name|m
parameter_list|)
value|(modelist[m].modetype& LOCAL_ECHO)
end_define

begin_define
define|#
directive|define
name|MODE_COMMAND_LINE
parameter_list|(
name|m
parameter_list|)
value|(modelist[m].modetype& COMMAND_LINE)
end_define

begin_define
define|#
directive|define
name|LOCAL_CHARS
value|0x01
end_define

begin_comment
comment|/* Characters processed locally */
end_comment

begin_define
define|#
directive|define
name|LINE
value|0x02
end_define

begin_comment
comment|/* Line-by-line mode of operation */
end_comment

begin_define
define|#
directive|define
name|LOCAL_ECHO
value|0x04
end_define

begin_comment
comment|/* Echoing locally */
end_comment

begin_define
define|#
directive|define
name|COMMAND_LINE
value|0x08
end_define

begin_comment
comment|/* Command line mode */
end_comment

end_unit

