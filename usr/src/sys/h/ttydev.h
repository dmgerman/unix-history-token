begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ttydev.h	7.2 (Berkeley) 10/13/86  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

