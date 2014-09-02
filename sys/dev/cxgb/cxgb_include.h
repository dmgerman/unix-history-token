begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<cxgb_osdep.h>
end_include

begin_include
include|#
directive|include
file|<common/cxgb_common.h>
end_include

begin_include
include|#
directive|include
file|<cxgb_ioctl.h>
end_include

begin_include
include|#
directive|include
file|<cxgb_offload.h>
end_include

begin_include
include|#
directive|include
file|<common/cxgb_regs.h>
end_include

begin_include
include|#
directive|include
file|<common/cxgb_t3_cpl.h>
end_include

begin_include
include|#
directive|include
file|<common/cxgb_ctl_defs.h>
end_include

begin_include
include|#
directive|include
file|<common/cxgb_sge_defs.h>
end_include

begin_include
include|#
directive|include
file|<common/cxgb_firmware_exports.h>
end_include

begin_include
include|#
directive|include
file|<common/jhash.h>
end_include

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_cxgb
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

