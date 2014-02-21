begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright Red Hat Inc 2010.  * Author : Dave Airlie<airlied@redhat.com>  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<drm/drmP.h>
end_include

begin_include
include|#
directive|include
file|<drm/radeon_drm.h>
end_include

begin_include
include|#
directive|include
file|"radeon.h"
end_include

begin_define
define|#
directive|define
name|CREATE_TRACE_POINTS
end_define

begin_include
include|#
directive|include
file|"radeon_trace.h"
end_include

end_unit

