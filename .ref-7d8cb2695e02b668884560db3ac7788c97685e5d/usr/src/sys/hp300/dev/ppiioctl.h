begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ppiioctl.h	7.3 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOCTL_
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ppiparam
block|{
name|int
name|burst
decl_stmt|;
comment|/* chars to send/recv in one call */
name|int
name|timo
decl_stmt|;
comment|/* timeout: -1 blocking, 0 non-blocking,>0 msec */
name|int
name|delay
decl_stmt|;
comment|/* delay between polls (msec) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PPI_BLOCK
value|-1
end_define

begin_define
define|#
directive|define
name|PPI_NOBLOCK
value|0
end_define

begin_comment
comment|/* default values */
end_comment

begin_define
define|#
directive|define
name|PPI_BURST
value|1024
end_define

begin_define
define|#
directive|define
name|PPI_TIMO
value|PPI_BLOCK
end_define

begin_define
define|#
directive|define
name|PPI_DELAY
value|10
end_define

begin_comment
comment|/* limits */
end_comment

begin_define
define|#
directive|define
name|PPI_BURST_MIN
value|1
end_define

begin_define
define|#
directive|define
name|PPI_BURST_MAX
value|1024
end_define

begin_define
define|#
directive|define
name|PPI_DELAY_MIN
value|0
end_define

begin_define
define|#
directive|define
name|PPI_DELAY_MAX
value|30000
end_define

begin_define
define|#
directive|define
name|PPIIOCSPARAM
value|_IOW('P', 0x1, struct ppiparam)
end_define

begin_define
define|#
directive|define
name|PPIIOCGPARAM
value|_IOR('P', 0x2, struct ppiparam)
end_define

begin_define
define|#
directive|define
name|PPIIOCSSEC
value|_IOW('P', 0x3, int)
end_define

end_unit

