begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2014 Ulrich Hecht  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_R8A7778_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_R8A7778_H__
end_define

begin_comment
comment|/* CPG */
end_comment

begin_define
define|#
directive|define
name|R8A7778_CLK_PLLA
value|0
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_PLLB
value|1
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_B
value|2
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_OUT
value|3
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_P
value|4
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_S
value|5
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_S1
value|6
end_define

begin_comment
comment|/* MSTP0 */
end_comment

begin_define
define|#
directive|define
name|R8A7778_CLK_I2C0
value|30
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_I2C1
value|29
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_I2C2
value|28
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_I2C3
value|27
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SCIF0
value|26
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SCIF1
value|25
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SCIF2
value|24
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SCIF3
value|23
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SCIF4
value|22
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SCIF5
value|21
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_TMU0
value|16
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_TMU1
value|15
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_TMU2
value|14
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SSI0
value|12
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SSI1
value|11
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SSI2
value|10
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SSI3
value|9
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SRU
value|8
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_HSPI
value|7
end_define

begin_comment
comment|/* MSTP1 */
end_comment

begin_define
define|#
directive|define
name|R8A7778_CLK_ETHER
value|14
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_VIN0
value|10
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_VIN1
value|9
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_USB
value|0
end_define

begin_comment
comment|/* MSTP3 */
end_comment

begin_define
define|#
directive|define
name|R8A7778_CLK_MMC
value|31
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SDHI0
value|23
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SDHI1
value|22
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SDHI2
value|21
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SSI4
value|11
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SSI5
value|10
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SSI6
value|9
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SSI7
value|8
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SSI8
value|7
end_define

begin_comment
comment|/* MSTP5 */
end_comment

begin_define
define|#
directive|define
name|R8A7778_CLK_SRU_SRC0
value|31
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SRU_SRC1
value|30
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SRU_SRC2
value|29
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SRU_SRC3
value|28
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SRU_SRC4
value|27
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SRU_SRC5
value|26
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SRU_SRC6
value|25
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SRU_SRC7
value|24
end_define

begin_define
define|#
directive|define
name|R8A7778_CLK_SRU_SRC8
value|23
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_CLOCK_R8A7778_H__ */
end_comment

end_unit

