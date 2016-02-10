begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2013, The Linux Foundation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 and  * only version 2 as published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_QCOM_GSBI_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_QCOM_GSBI_H
end_define

begin_define
define|#
directive|define
name|GSBI_PROT_IDLE
value|0
end_define

begin_define
define|#
directive|define
name|GSBI_PROT_I2C_UIM
value|1
end_define

begin_define
define|#
directive|define
name|GSBI_PROT_I2C
value|2
end_define

begin_define
define|#
directive|define
name|GSBI_PROT_SPI
value|3
end_define

begin_define
define|#
directive|define
name|GSBI_PROT_UART_W_FC
value|4
end_define

begin_define
define|#
directive|define
name|GSBI_PROT_UIM
value|5
end_define

begin_define
define|#
directive|define
name|GSBI_PROT_I2C_UART
value|6
end_define

begin_define
define|#
directive|define
name|GSBI_CRCI_QUP
value|0
end_define

begin_define
define|#
directive|define
name|GSBI_CRCI_UART
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

