begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Linaro Ltd.  * Copyright (c) 2014 Hisilicon Limited.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms and conditions of the GNU General Public License,  * version 2, as published by the Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_HIX5HD2_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_HIX5HD2_CLOCK_H
end_define

begin_comment
comment|/* fixed rate */
end_comment

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_1200M
value|1
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_400M
value|2
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_48M
value|3
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_24M
value|4
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_600M
value|5
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_300M
value|6
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_75M
value|7
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_200M
value|8
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_100M
value|9
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_40M
value|10
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_150M
value|11
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_1728M
value|12
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_28P8M
value|13
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_432M
value|14
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_345P6M
value|15
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_288M
value|16
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_60M
value|17
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_750M
value|18
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_500M
value|19
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_54M
value|20
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_27M
value|21
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_1500M
value|22
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_375M
value|23
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_187M
value|24
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_250M
value|25
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_125M
value|26
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_2P02M
value|27
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_50M
value|28
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_25M
value|29
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FIXED_83M
value|30
end_define

begin_comment
comment|/* mux clocks */
end_comment

begin_define
define|#
directive|define
name|HIX5HD2_SFC_MUX
value|64
end_define

begin_define
define|#
directive|define
name|HIX5HD2_MMC_MUX
value|65
end_define

begin_define
define|#
directive|define
name|HIX5HD2_FEPHY_MUX
value|66
end_define

begin_comment
comment|/* gate clocks */
end_comment

begin_define
define|#
directive|define
name|HIX5HD2_SFC_RST
value|128
end_define

begin_define
define|#
directive|define
name|HIX5HD2_SFC_CLK
value|129
end_define

begin_define
define|#
directive|define
name|HIX5HD2_MMC_CIU_CLK
value|130
end_define

begin_define
define|#
directive|define
name|HIX5HD2_MMC_BIU_CLK
value|131
end_define

begin_define
define|#
directive|define
name|HIX5HD2_MMC_CIU_RST
value|132
end_define

begin_define
define|#
directive|define
name|HIX5HD2_NR_CLKS
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DTS_HIX5HD2_CLOCK_H */
end_comment

end_unit

