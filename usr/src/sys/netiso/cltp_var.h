begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)cltp_var.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|UD_TPDU_type
value|0x40
end_define

begin_comment
comment|/* packet type */
end_comment

begin_define
define|#
directive|define
name|CLTPOVAL_SRC
value|0xc1
end_define

begin_comment
comment|/* Source TSAP -- required */
end_comment

begin_define
define|#
directive|define
name|CLTPOVAL_DST
value|0xc2
end_define

begin_comment
comment|/* Destination TSAP -- required */
end_comment

begin_define
define|#
directive|define
name|CLTPOVAL_CSM
value|0xc3
end_define

begin_comment
comment|/* Checksum parameter -- optional */
end_comment

begin_struct
struct|struct
name|cltpstat
block|{
name|int
name|cltps_hdrops
decl_stmt|;
name|int
name|cltps_badsum
decl_stmt|;
name|int
name|cltps_badlen
decl_stmt|;
name|int
name|cltps_noport
decl_stmt|;
name|int
name|cltps_ipackets
decl_stmt|;
name|int
name|cltps_opackets
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|isopcb
name|cltb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cltpstat
name|cltpstat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

