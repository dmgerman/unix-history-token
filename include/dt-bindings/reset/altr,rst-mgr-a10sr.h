begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright Intel Corporation (C) 2017. All Rights Reserved  *  * This program is free software; you can redistribute it and/or modify it  * under the terms and conditions of the GNU General Public License,  * version 2, as published by the Free Software Foundation.  *  * This program is distributed in the hope it will be useful, but WITHOUT  * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or  * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for  * more details.  *  * You should have received a copy of the GNU General Public License along with  * this program.  If not, see<http://www.gnu.org/licenses/>.  *  * Reset binding definitions for Altera Arria10 MAX5 System Resource Chip  *  * Adapted from altr,rst-mgr-a10.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_RESET_ALTR_RST_MGR_A10SR_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_RESET_ALTR_RST_MGR_A10SR_H
end_define

begin_comment
comment|/* Peripheral PHY resets */
end_comment

begin_define
define|#
directive|define
name|A10SR_RESET_ENET_HPS
value|0
end_define

begin_define
define|#
directive|define
name|A10SR_RESET_PCIE
value|1
end_define

begin_define
define|#
directive|define
name|A10SR_RESET_FILE
value|2
end_define

begin_define
define|#
directive|define
name|A10SR_RESET_BQSPI
value|3
end_define

begin_define
define|#
directive|define
name|A10SR_RESET_USB
value|4
end_define

begin_define
define|#
directive|define
name|A10SR_RESET_NUM
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

