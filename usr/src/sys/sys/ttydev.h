begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ttydev.h	7.5 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Terminal definitions related to underlying hardware.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TTYDEV_
end_ifndef

begin_define
define|#
directive|define
name|_TTYDEV_
end_define

begin_comment
comment|/*  * Speeds  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_OLD_TTY
end_ifdef

begin_comment
comment|/*  * Speeds  */
end_comment

begin_define
define|#
directive|define
name|B0
value|0
end_define

begin_define
define|#
directive|define
name|B50
value|1
end_define

begin_define
define|#
directive|define
name|B75
value|2
end_define

begin_define
define|#
directive|define
name|B110
value|3
end_define

begin_define
define|#
directive|define
name|B134
value|4
end_define

begin_define
define|#
directive|define
name|B150
value|5
end_define

begin_define
define|#
directive|define
name|B200
value|6
end_define

begin_define
define|#
directive|define
name|B300
value|7
end_define

begin_define
define|#
directive|define
name|B600
value|8
end_define

begin_define
define|#
directive|define
name|B1200
value|9
end_define

begin_define
define|#
directive|define
name|B1800
value|10
end_define

begin_define
define|#
directive|define
name|B2400
value|11
end_define

begin_define
define|#
directive|define
name|B4800
value|12
end_define

begin_define
define|#
directive|define
name|B9600
value|13
end_define

begin_define
define|#
directive|define
name|EXTA
value|14
end_define

begin_define
define|#
directive|define
name|EXTB
value|15
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|B0
value|0
end_define

begin_define
define|#
directive|define
name|B50
value|50
end_define

begin_define
define|#
directive|define
name|B75
value|75
end_define

begin_define
define|#
directive|define
name|B110
value|110
end_define

begin_define
define|#
directive|define
name|B134
value|134
end_define

begin_define
define|#
directive|define
name|B150
value|150
end_define

begin_define
define|#
directive|define
name|B200
value|200
end_define

begin_define
define|#
directive|define
name|B300
value|300
end_define

begin_define
define|#
directive|define
name|B600
value|600
end_define

begin_define
define|#
directive|define
name|B1200
value|1200
end_define

begin_define
define|#
directive|define
name|B1800
value|1800
end_define

begin_define
define|#
directive|define
name|B2400
value|2400
end_define

begin_define
define|#
directive|define
name|B4800
value|4800
end_define

begin_define
define|#
directive|define
name|B9600
value|9600
end_define

begin_define
define|#
directive|define
name|B19200
value|19200
end_define

begin_define
define|#
directive|define
name|B38400
value|38400
end_define

begin_define
define|#
directive|define
name|EXTA
value|14
end_define

begin_define
define|#
directive|define
name|EXTB
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct
struct|struct
name|speedtab
block|{
name|int
name|sp_speed
decl_stmt|;
name|int
name|sp_code
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Modem control commands.  */
end_comment

begin_define
define|#
directive|define
name|DMSET
value|0
end_define

begin_define
define|#
directive|define
name|DMBIS
value|1
end_define

begin_define
define|#
directive|define
name|DMBIC
value|2
end_define

begin_define
define|#
directive|define
name|DMGET
value|3
end_define

begin_comment
comment|/*  * Flags on character passed to ttyinput  */
end_comment

begin_define
define|#
directive|define
name|TTY_CHARMASK
value|0x000000ff
end_define

begin_comment
comment|/* Character mask */
end_comment

begin_define
define|#
directive|define
name|TTY_QUOTE
value|0x00000100
end_define

begin_comment
comment|/* Character quoted */
end_comment

begin_define
define|#
directive|define
name|TTY_ERRORMASK
value|0xff000000
end_define

begin_comment
comment|/* Error mask */
end_comment

begin_define
define|#
directive|define
name|TTY_FE
value|0x01000000
end_define

begin_comment
comment|/* Framing error or BREAK condition */
end_comment

begin_define
define|#
directive|define
name|TTY_PE
value|0x02000000
end_define

begin_comment
comment|/* Parity error */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TTYDEV_ */
end_comment

end_unit

