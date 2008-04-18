begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  $FreeBSD$   */
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
file|<machine/bus.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DEFINED
end_ifdef

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

begin_include
include|#
directive|include
file|<ulp/toecore/cxgb_toedev.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<dev/cxgb/cxgb_osdep.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/common/cxgb_common.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/cxgb_ioctl.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/cxgb_offload.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/common/cxgb_regs.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/common/cxgb_t3_cpl.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/common/cxgb_ctl_defs.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/common/cxgb_sge_defs.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/common/cxgb_firmware_exports.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/common/jhash.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/ulp/toecore/cxgb_toedev.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

