begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vcmd.h	6.1	83/07/29	*/
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

begin_define
define|#
directive|define
name|VPRINT
value|0100
end_define

begin_define
define|#
directive|define
name|VPLOT
value|0200
end_define

begin_define
define|#
directive|define
name|VPRINTPLOT
value|0400
end_define

begin_define
define|#
directive|define
name|VGETSTATE
value|_IOR(v, 0, int)
end_define

begin_define
define|#
directive|define
name|VSETSTATE
value|_IOW(v, 1, int)
end_define

end_unit

