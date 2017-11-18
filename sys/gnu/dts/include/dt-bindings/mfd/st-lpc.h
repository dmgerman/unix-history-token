begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_comment
comment|/*  * This header provides shared DT/Driver defines for ST's LPC device  *  * Copyright (C) 2014 STMicroelectronics -- All Rights Reserved  *  * Author: Lee Jones<lee.jones@linaro.org> for STMicroelectronics  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_ST_LPC_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_ST_LPC_H__
end_define

begin_define
define|#
directive|define
name|ST_LPC_MODE_RTC
value|0
end_define

begin_define
define|#
directive|define
name|ST_LPC_MODE_WDT
value|1
end_define

begin_define
define|#
directive|define
name|ST_LPC_MODE_CLKSRC
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_ST_LPC_H__ */
end_comment

end_unit

