begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1997-1998 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * @(#)linux.h	1.1 8/19/95  */
end_comment

begin_include
include|#
directive|include
file|<linux/config.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MODULE
end_ifdef

begin_include
include|#
directive|include
file|<linux/module.h>
end_include

begin_include
include|#
directive|include
file|<linux/version.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MODULE */
end_comment

begin_include
include|#
directive|include
file|"ip_compat.h"
end_include

end_unit

