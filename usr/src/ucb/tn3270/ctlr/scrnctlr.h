begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)scrnctlr.h	3.2 (Berkeley) 3/28/88  */
end_comment

begin_comment
comment|/*  * definitions that have to do with the interface between the  * controller and the screen.  */
end_comment

begin_define
define|#
directive|define
name|DISP_AMPERSAND
value|0x30
end_define

begin_define
define|#
directive|define
name|DISP_BLANK
value|0x10
end_define

begin_define
define|#
directive|define
name|DISP_CENTSIGN
value|0x1b
end_define

begin_define
define|#
directive|define
name|DISP_DUP
value|0x9f
end_define

begin_define
define|#
directive|define
name|DISP_FM
value|0x9e
end_define

begin_define
define|#
directive|define
name|DISP_GREATER_THAN
value|0x08
end_define

begin_define
define|#
directive|define
name|DISP_NULL
value|0x00
end_define

begin_define
define|#
directive|define
name|DISP_QUESTION
value|0x18
end_define

end_unit

