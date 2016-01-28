begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides macros for Atmel Flexcom DT bindings.  *  * Copyright (C) 2015 Cyrille Pitchen<cyrille.pitchen@atmel.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License along with  * this program.  If not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_ATMEL_FLEXCOM_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_ATMEL_FLEXCOM_H__
end_define

begin_define
define|#
directive|define
name|ATMEL_FLEXCOM_MODE_USART
value|1
end_define

begin_define
define|#
directive|define
name|ATMEL_FLEXCOM_MODE_SPI
value|2
end_define

begin_define
define|#
directive|define
name|ATMEL_FLEXCOM_MODE_TWI
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_ATMEL_FLEXCOM_H__ */
end_comment

end_unit

