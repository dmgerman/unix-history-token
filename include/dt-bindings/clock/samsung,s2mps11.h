begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2015 Markus Reichl  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Device Tree binding constants clocks for the Samsung S2MPS11 PMIC.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_SAMSUNG_S2MPS11_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_SAMSUNG_S2MPS11_CLOCK_H
end_define

begin_comment
comment|/* Fixed rate clocks. */
end_comment

begin_define
define|#
directive|define
name|S2MPS11_CLK_AP
value|0
end_define

begin_define
define|#
directive|define
name|S2MPS11_CLK_CP
value|1
end_define

begin_define
define|#
directive|define
name|S2MPS11_CLK_BT
value|2
end_define

begin_comment
comment|/* Total number of clocks. */
end_comment

begin_define
define|#
directive|define
name|S2MPS11_CLKS_NUM
value|(S2MPS11_CLK_BT + 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_SAMSUNG_S2MPS11_CLOCK_H */
end_comment

end_unit

