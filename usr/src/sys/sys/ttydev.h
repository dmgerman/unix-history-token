begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ttydev.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* COMPATABILITY HEADER FILE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TTYDEV_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TTYDEV_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_OLD_TTY
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_OLD_TTY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TTYDEV_H_ */
end_comment

end_unit

