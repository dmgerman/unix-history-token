begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)ioctl.h	8.6 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_IOCTL_H_
end_define

begin_include
include|#
directive|include
file|<sys/ttycom.h>
end_include

begin_comment
comment|/*  * Pun for SunOS prior to 3.2.  SunOS 3.2 and later support TIOCGWINSZ  * and TIOCSWINSZ (yes, even 3.2-3.5, the fact that it wasn't documented  * nonwithstanding).  */
end_comment

begin_struct
struct|struct
name|ttysize
block|{
name|unsigned
name|short
name|ts_lines
decl_stmt|;
name|unsigned
name|short
name|ts_cols
decl_stmt|;
name|unsigned
name|short
name|ts_xxx
decl_stmt|;
name|unsigned
name|short
name|ts_yyy
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TIOCGSIZE
value|TIOCGWINSZ
end_define

begin_define
define|#
directive|define
name|TIOCSSIZE
value|TIOCSWINSZ
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|IOC_DIRMASK
value|(IOC_IN|IOC_OUT|IOC_VOID)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|ioctl
name|__P
argument_list|(
operator|(
name|int
operator|,
name|unsigned
name|long
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_IOCTL_H_ */
end_comment

begin_comment
comment|/*  * Keep outside _SYS_IOCTL_H_  * Compatability with old terminal driver  *  * Source level -> #define USE_OLD_TTY  * Kernel level -> options COMPAT_43 or COMPAT_SUNOS  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_OLD_TTY
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_43
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_SUNOS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ioctl_compat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

