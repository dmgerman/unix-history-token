begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Xilinx Video IP Core  *  * Copyright (C) 2013-2015 Ideas on Board  * Copyright (C) 2013-2015 Xilinx, Inc.  *  * Contacts: Hyun Kwon<hyun.kwon@xilinx.com>  *           Laurent Pinchart<laurent.pinchart@ideasonboard.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_MEDIA_XILINX_VIP_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_MEDIA_XILINX_VIP_H__
end_define

begin_comment
comment|/*  * Video format codes as defined in "AXI4-Stream Video IP and System Design  * Guide".  */
end_comment

begin_define
define|#
directive|define
name|XVIP_VF_YUV_422
value|0
end_define

begin_define
define|#
directive|define
name|XVIP_VF_YUV_444
value|1
end_define

begin_define
define|#
directive|define
name|XVIP_VF_RBG
value|2
end_define

begin_define
define|#
directive|define
name|XVIP_VF_YUV_420
value|3
end_define

begin_define
define|#
directive|define
name|XVIP_VF_YUVA_422
value|4
end_define

begin_define
define|#
directive|define
name|XVIP_VF_YUVA_444
value|5
end_define

begin_define
define|#
directive|define
name|XVIP_VF_RGBA
value|6
end_define

begin_define
define|#
directive|define
name|XVIP_VF_YUVA_420
value|7
end_define

begin_define
define|#
directive|define
name|XVIP_VF_YUVD_422
value|8
end_define

begin_define
define|#
directive|define
name|XVIP_VF_YUVD_444
value|9
end_define

begin_define
define|#
directive|define
name|XVIP_VF_RGBD
value|10
end_define

begin_define
define|#
directive|define
name|XVIP_VF_YUVD_420
value|11
end_define

begin_define
define|#
directive|define
name|XVIP_VF_MONO_SENSOR
value|12
end_define

begin_define
define|#
directive|define
name|XVIP_VF_CUSTOM2
value|13
end_define

begin_define
define|#
directive|define
name|XVIP_VF_CUSTOM3
value|14
end_define

begin_define
define|#
directive|define
name|XVIP_VF_CUSTOM4
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_MEDIA_XILINX_VIP_H__ */
end_comment

end_unit

