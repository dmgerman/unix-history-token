begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)vpreg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_define
define|#
directive|define
name|VPPRI
value|(PZERO-1)
end_define

begin_struct
struct|struct
name|vpdevice
block|{
name|short
name|plbcr
decl_stmt|;
name|short
name|pbxaddr
decl_stmt|;
name|short
name|prbcr
decl_stmt|;
name|u_short
name|pbaddr
decl_stmt|;
name|short
name|plcsr
decl_stmt|;
name|short
name|plbuf
decl_stmt|;
name|short
name|prcsr
decl_stmt|;
name|u_short
name|prbuf
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VP_ERROR
value|0100000
end_define

begin_define
define|#
directive|define
name|VP_DTCINTR
value|0040000
end_define

begin_define
define|#
directive|define
name|VP_DMAACT
value|0020000
end_define

begin_define
define|#
directive|define
name|VP_READY
value|0000200
end_define

begin_define
define|#
directive|define
name|VP_IENABLE
value|0000100
end_define

begin_define
define|#
directive|define
name|VP_TERMCOM
value|0000040
end_define

begin_define
define|#
directive|define
name|VP_FFCOM
value|0000020
end_define

begin_define
define|#
directive|define
name|VP_EOTCOM
value|0000010
end_define

begin_define
define|#
directive|define
name|VP_CLRCOM
value|0000004
end_define

begin_define
define|#
directive|define
name|VP_RESET
value|0000002
end_define

begin_define
define|#
directive|define
name|VP_SPP
value|0000001
end_define

end_unit

