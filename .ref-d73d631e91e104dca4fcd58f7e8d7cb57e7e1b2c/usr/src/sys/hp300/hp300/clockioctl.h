begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: clockioctl.h 1.1 90/07/09$  *  *	@(#)clockioctl.h	7.2 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|CLOCKMAP
value|_IOWR('C', 1, int)
end_define

begin_define
define|#
directive|define
name|CLOCKUNMAP
value|_IOW('C', 2, int)
end_define

begin_define
define|#
directive|define
name|CLOCKGETRES
value|_IOR('C', 3, int)
end_define

end_unit

