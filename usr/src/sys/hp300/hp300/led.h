begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 University of Utah.  * Copyright (c) 1982, 1986, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: led.h 1.2 92/08/27$  *  *	@(#)led.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|LED_ADDR
value|0x1FFFF
end_define

begin_comment
comment|/* a ROM address--strange but true */
end_comment

begin_define
define|#
directive|define
name|LED_LANXMT
value|0x80
end_define

begin_comment
comment|/* for LAN transmit activity */
end_comment

begin_define
define|#
directive|define
name|LED_LANRCV
value|0x40
end_define

begin_comment
comment|/* for LAN receive activity */
end_comment

begin_define
define|#
directive|define
name|LED_DISK
value|0x20
end_define

begin_comment
comment|/* for disk activity */
end_comment

begin_define
define|#
directive|define
name|LED_PULSE
value|0x10
end_define

begin_comment
comment|/* heartbeat */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ledaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inledcontrol
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

