begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)filio.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_FILIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FILIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/* Generic file-descriptor ioctl's. */
end_comment

begin_define
define|#
directive|define
name|FIOCLEX
value|_IO('f', 1)
end_define

begin_comment
comment|/* set close on exec on fd */
end_comment

begin_define
define|#
directive|define
name|FIONCLEX
value|_IO('f', 2)
end_define

begin_comment
comment|/* remove close on exec */
end_comment

begin_define
define|#
directive|define
name|FIONREAD
value|_IOR('f', 127, int)
end_define

begin_comment
comment|/* get # bytes to read */
end_comment

begin_define
define|#
directive|define
name|FIONBIO
value|_IOW('f', 126, int)
end_define

begin_comment
comment|/* set/clear non-blocking i/o */
end_comment

begin_define
define|#
directive|define
name|FIOASYNC
value|_IOW('f', 125, int)
end_define

begin_comment
comment|/* set/clear async i/o */
end_comment

begin_define
define|#
directive|define
name|FIOSETOWN
value|_IOW('f', 124, int)
end_define

begin_comment
comment|/* set owner */
end_comment

begin_define
define|#
directive|define
name|FIOGETOWN
value|_IOR('f', 123, int)
end_define

begin_comment
comment|/* get owner */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_FILIO_H_ */
end_comment

end_unit

