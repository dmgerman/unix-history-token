begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  *	Copyright (C) 1994, Paul S. LaFollette, Jr. This software may be used,  *	modified, copied, distributed, and sold, in both source and binary form  *	provided that the above copyright and these terms are retained. Under  *	no circumstances is the author responsible for the proper functioning  *	of this software, nor does the author assume any responsibility  *	for damages incurred with its use  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *	ioctl constants for Cortex-I frame grabber  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IOCTL_CTX_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IOCTL_CTX_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_typedef
typedef|typedef
name|char
name|_CTX_LUTBUF
index|[
literal|256
index|]
typedef|;
end_typedef

begin_comment
comment|/* look up table buffer */
end_comment

begin_define
define|#
directive|define
name|CTX_LIVE
value|_IO('x', 1)
end_define

begin_comment
comment|/* live video */
end_comment

begin_define
define|#
directive|define
name|CTX_GRAB
value|_IO('x', 2)
end_define

begin_comment
comment|/* frame grab */
end_comment

begin_define
define|#
directive|define
name|CTX_H_ORGANIZE
value|_IO('x', 3)
end_define

begin_comment
comment|/* file goes across screen (horiz. read) */
end_comment

begin_define
define|#
directive|define
name|CTX_V_ORGANIZE
value|_IO('x', 4)
end_define

begin_comment
comment|/* file goes down screen (vert. read)    */
end_comment

begin_define
define|#
directive|define
name|CTX_SET_LUT
value|_IOW('x', 5, _CTX_LUTBUF)
end_define

begin_comment
comment|/* set lookup table */
end_comment

begin_define
define|#
directive|define
name|CTX_GET_LUT
value|_IOR('x', 6, _CTX_LUTBUF)
end_define

begin_comment
comment|/* get lookup table */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_IOCTL_CTX_H_ */
end_comment

end_unit

