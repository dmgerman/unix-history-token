begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for I2C bindings  *  * Copyright (C) 2015 by Sang Engineering  * Copyright (C) 2015 by Renesas Electronics Corporation  *  * Wolfram Sang<wsa@sang-engineering.com>  *  * GPLv2 only  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_I2C_I2C_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_I2C_I2C_H
end_define

begin_define
define|#
directive|define
name|I2C_TEN_BIT_ADDRESS
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|I2C_OWN_SLAVE_ADDRESS
value|(1<< 30)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

