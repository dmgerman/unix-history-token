begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: altqconf.h,v 1.1 2001/06/27 05:28:36 kjc Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD: altqconf.h,v 1.2 2001/05/30 11:57:16 mrg Exp $	*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL_OPT
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL_OPT
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_altq_enabled.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ
end_ifdef

begin_define
define|#
directive|define
name|NALTQ
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NALTQ
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|cdev_decl
argument_list|(
name|altq
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__OpenBSD__
end_ifdef

begin_define
define|#
directive|define
name|cdev_altq_init
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 	dev_init(c,n,open), dev_init(c,n,close), (dev_type_read((*))) enodev, \ 	(dev_type_write((*))) enodev, dev_init(c,n,ioctl), \ 	(dev_type_stop((*))) enodev, 0, (dev_type_select((*))) enodev, \ 	(dev_type_mmap((*))) enodev }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cdev_altq_init
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|cdev__oci_init(x,y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_KERNEL_OPT) || defined(__OpenBSD__) */
end_comment

end_unit

