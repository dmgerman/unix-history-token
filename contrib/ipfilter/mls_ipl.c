begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * (C)opyright 1993,1994,1995 by Darren Reed.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and due credit is given  * to the original author and the contributors.  */
end_comment

begin_comment
comment|/*  * 29/12/94 Added code from Marc Huber<huber@fzi.de> to allow it to allocate  * its own major char number! Way cool patch!  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sundev/mbvar.h>
end_include

begin_include
include|#
directive|include
file|<sun/autoconf.h>
end_include

begin_include
include|#
directive|include
file|<sun/vddrv.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun4c
argument_list|)
operator|||
name|defined
argument_list|(
name|sun4m
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sun/openprom.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ipl.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)mls_ipl.c	2.6 10/15/95 (C) 1993-1995 Darren Reed"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Id: mls_ipl.c,v 2.0.1.1 1997/01/09 15:14:44 darrenr Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPL_NAME
end_ifndef

begin_define
define|#
directive|define
name|IPL_NAME
value|"/dev/ipl"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|iplattach
argument_list|()
decl_stmt|,
name|iplopen
argument_list|()
decl_stmt|,
name|iplclose
argument_list|()
decl_stmt|,
name|iplioctl
argument_list|()
decl_stmt|,
name|ipldetach
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|IPFILTER_LOG
end_ifdef

begin_function_decl
specifier|extern
name|int
name|iplread
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|iplread
value|nulldev
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|nulldev
argument_list|()
decl_stmt|,
name|iplidentify
argument_list|()
decl_stmt|,
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|unload
argument_list|()
decl_stmt|,
name|ipl_attach
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cdevsw
name|ipldevsw
init|=
block|{
name|iplopen
block|,
name|iplclose
block|,
name|iplread
block|,
name|nulldev
block|,
name|iplioctl
block|,
name|nulldev
block|,
name|nulldev
block|,
name|nulldev
block|,
literal|0
block|,
name|nulldev
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|dev_ops
name|ipl_ops
init|=
block|{
literal|1
block|,
name|iplidentify
block|,
name|iplattach
block|,
name|iplopen
block|,
name|iplclose
block|,
name|iplread
block|,
name|NULL
block|,
comment|/* write */
name|NULL
block|,
comment|/* strategy */
name|NULL
block|,
comment|/* dump */
literal|0
block|,
comment|/* psize */
name|iplioctl
block|,
name|NULL
block|,
comment|/* reset */
name|NULL
comment|/* mmap */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipl_major
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|sun4m
end_ifdef

begin_decl_stmt
name|struct
name|vdldrv
name|vd
init|=
block|{
name|VDMAGIC_PSEUDO
block|,
name|IPL_VERSION
block|,
operator|&
name|ipl_ops
block|,
name|NULL
block|,
operator|&
name|ipldevsw
block|,
literal|0
block|,
literal|0
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
literal|0
block|,
literal|1
block|, }
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* sun4m */
end_comment

begin_decl_stmt
name|struct
name|vdldrv
name|vd
init|=
block|{
name|VDMAGIC_PSEUDO
block|,
comment|/* magic */
name|IPL_VERSION
block|,
ifdef|#
directive|ifdef
name|sun4c
operator|&
name|ipl_ops
block|,
comment|/* dev_ops */
else|#
directive|else
name|NULL
block|,
comment|/* struct mb_ctlr *mb_ctlr */
name|NULL
block|,
comment|/* struct mb_driver *mb_driver */
name|NULL
block|,
comment|/* struct mb_device *mb_device */
literal|0
block|,
comment|/* num ctlrs */
literal|1
block|,
comment|/* numdevs */
endif|#
directive|endif
comment|/* sun4c */
name|NULL
block|,
comment|/* bdevsw */
operator|&
name|ipldevsw
block|,
comment|/* cdevsw */
literal|0
block|,
comment|/* block major */
literal|0
block|,
comment|/* char major */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun4m */
end_comment

begin_function_decl
specifier|extern
name|int
name|vd_unuseddev
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|cdevsw
name|cdevsw
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nchrdev
decl_stmt|;
end_decl_stmt

begin_macro
name|xxxinit
argument_list|(
argument|fc
argument_list|,
argument|vdp
argument_list|,
argument|vdi
argument_list|,
argument|vds
argument_list|)
end_macro

begin_decl_stmt
name|u_int
name|fc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vddrv
modifier|*
name|vdp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|vdi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vdstat
modifier|*
name|vds
decl_stmt|;
end_decl_stmt

begin_block
block|{
switch|switch
condition|(
name|fc
condition|)
block|{
case|case
name|VDLOAD
case|:
while|while
condition|(
name|ipl_major
operator|<
name|nchrdev
operator|&&
name|cdevsw
index|[
name|ipl_major
index|]
operator|.
name|d_open
operator|!=
name|vd_unuseddev
condition|)
name|ipl_major
operator|++
expr_stmt|;
if|if
condition|(
name|ipl_major
operator|==
name|nchrdev
condition|)
return|return
name|ENODEV
return|;
name|vd
operator|.
name|Drv_charmajor
operator|=
name|ipl_major
expr_stmt|;
name|vdp
operator|->
name|vdd_vdtab
operator|=
operator|(
expr|struct
name|vdlinkage
operator|*
operator|)
operator|&
name|vd
expr_stmt|;
return|return
name|ipl_attach
argument_list|()
return|;
case|case
name|VDUNLOAD
case|:
return|return
name|unload
argument_list|()
return|;
case|case
name|VDSTAT
case|:
return|return
literal|0
return|;
default|default:
return|return
name|EIO
return|;
block|}
block|}
end_block

begin_function
specifier|static
name|int
name|unload
parameter_list|()
block|{
name|int
name|err
decl_stmt|;
name|err
operator|=
name|ipldetach
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|err
condition|)
operator|(
name|void
operator|)
name|vn_remove
argument_list|(
name|IPL_NAME
argument_list|,
name|UIO_SYSSPACE
argument_list|,
name|FILE
argument_list|)
expr_stmt|;
return|return
name|err
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ipl_attach
parameter_list|()
block|{
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
name|struct
name|vattr
name|vattr
decl_stmt|;
name|int
name|error
init|=
literal|0
decl_stmt|,
name|fmode
init|=
name|S_IFCHR
operator||
literal|0600
decl_stmt|;
name|error
operator|=
name|iplattach
argument_list|()
expr_stmt|;
if|if
condition|(
name|error
condition|)
return|return
name|error
return|;
operator|(
name|void
operator|)
name|vn_remove
argument_list|(
name|IPL_NAME
argument_list|,
name|UIO_SYSSPACE
argument_list|,
name|FILE
argument_list|)
expr_stmt|;
name|vattr_null
argument_list|(
operator|&
name|vattr
argument_list|)
expr_stmt|;
name|vattr
operator|.
name|va_type
operator|=
name|MFTOVT
argument_list|(
name|fmode
argument_list|)
expr_stmt|;
name|vattr
operator|.
name|va_mode
operator|=
operator|(
name|fmode
operator|&
literal|07777
operator|)
expr_stmt|;
name|vattr
operator|.
name|va_rdev
operator|=
name|ipl_major
operator|<<
literal|8
expr_stmt|;
name|error
operator|=
name|vn_create
argument_list|(
name|IPL_NAME
argument_list|,
name|UIO_SYSSPACE
argument_list|,
operator|&
name|vattr
argument_list|,
name|EXCL
argument_list|,
literal|0
argument_list|,
operator|&
name|vp
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
literal|0
condition|)
name|VN_RELE
argument_list|(
name|vp
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_function

end_unit

