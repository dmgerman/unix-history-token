begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009 Advanced Micro Devices, Inc.  * Copyright 2009 Red Hat Inc.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Dave Airlie  *          Alex Deucher  *          Jerome Glisse  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AVIVOD_H
end_ifndef

begin_define
define|#
directive|define
name|AVIVOD_H
end_define

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

begin_define
define|#
directive|define
name|D1CRTC_CONTROL
value|0x6080
end_define

begin_define
define|#
directive|define
name|CRTC_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|D1CRTC_STATUS
value|0x609c
end_define

begin_define
define|#
directive|define
name|D1CRTC_UPDATE_LOCK
value|0x60E8
end_define

begin_define
define|#
directive|define
name|D1GRPH_PRIMARY_SURFACE_ADDRESS
value|0x6110
end_define

begin_define
define|#
directive|define
name|D1GRPH_SECONDARY_SURFACE_ADDRESS
value|0x6118
end_define

begin_define
define|#
directive|define
name|D2CRTC_CONTROL
value|0x6880
end_define

begin_define
define|#
directive|define
name|D2CRTC_STATUS
value|0x689c
end_define

begin_define
define|#
directive|define
name|D2CRTC_UPDATE_LOCK
value|0x68E8
end_define

begin_define
define|#
directive|define
name|D2GRPH_PRIMARY_SURFACE_ADDRESS
value|0x6910
end_define

begin_define
define|#
directive|define
name|D2GRPH_SECONDARY_SURFACE_ADDRESS
value|0x6918
end_define

begin_define
define|#
directive|define
name|D1VGA_CONTROL
value|0x0330
end_define

begin_define
define|#
directive|define
name|DVGA_CONTROL_MODE_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DVGA_CONTROL_TIMING_SELECT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|DVGA_CONTROL_SYNC_POLARITY_SELECT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|DVGA_CONTROL_OVERSCAN_TIMING_SELECT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|DVGA_CONTROL_OVERSCAN_COLOR_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|DVGA_CONTROL_ROTATE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|D2VGA_CONTROL
value|0x0338
end_define

begin_define
define|#
directive|define
name|VGA_HDP_CONTROL
value|0x328
end_define

begin_define
define|#
directive|define
name|VGA_MEM_PAGE_SELECT_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|VGA_MEMORY_DISABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|VGA_RBBM_LOCK_DISABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|VGA_SOFT_RESET
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|VGA_MEMORY_BASE_ADDRESS
value|0x0310
end_define

begin_define
define|#
directive|define
name|VGA_RENDER_CONTROL
value|0x0300
end_define

begin_define
define|#
directive|define
name|VGA_VSTATUS_CNTL_MASK
value|0x00030000
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

