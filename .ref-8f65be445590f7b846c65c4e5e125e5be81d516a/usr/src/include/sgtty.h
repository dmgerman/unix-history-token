begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)sgtty.h	5.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOCTL_H_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|USE_OLD_TTY
end_ifndef

begin_define
define|#
directive|define
name|USE_OLD_TTY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IOCTL_H_ */
end_comment

end_unit

