begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2016 Renesas Electronics Corp.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_R8A7796_CPG_MSSR_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_R8A7796_CPG_MSSR_H__
end_define

begin_include
include|#
directive|include
file|<dt-bindings/clock/renesas-cpg-mssr.h>
end_include

begin_comment
comment|/* r8a7796 CPG Core Clocks */
end_comment

begin_define
define|#
directive|define
name|R8A7796_CLK_Z
value|0
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_Z2
value|1
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_ZR
value|2
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_ZG
value|3
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_ZTR
value|4
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_ZTRD2
value|5
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_ZT
value|6
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_ZX
value|7
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_S0D1
value|8
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_S0D2
value|9
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_S0D3
value|10
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_S0D4
value|11
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_S0D6
value|12
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_S0D8
value|13
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_S0D12
value|14
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_S1D1
value|15
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_S1D2
value|16
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_S1D4
value|17
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_S2D1
value|18
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_S2D2
value|19
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_S2D4
value|20
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_S3D1
value|21
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_S3D2
value|22
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_S3D4
value|23
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_LB
value|24
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_CL
value|25
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_ZB3
value|26
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_ZB3D2
value|27
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_ZB3D4
value|28
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_CR
value|29
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_CRD2
value|30
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_SD0H
value|31
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_SD0
value|32
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_SD1H
value|33
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_SD1
value|34
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_SD2H
value|35
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_SD2
value|36
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_SD3H
value|37
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_SD3
value|38
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_SSP2
value|39
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_SSP1
value|40
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_SSPRS
value|41
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_RPC
value|42
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_RPCD2
value|43
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_MSO
value|44
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_CANFD
value|45
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_HDMI
value|46
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_CSI0
value|47
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_CSIREF
value|48
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_CP
value|49
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_CPEX
value|50
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_R
value|51
end_define

begin_define
define|#
directive|define
name|R8A7796_CLK_OSC
value|52
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_CLOCK_R8A7796_CPG_MSSR_H__ */
end_comment

end_unit

