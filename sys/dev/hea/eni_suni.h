begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Efficient ENI Adapter Support  * -----------------------------  *  * Defines for SUNI chip  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ENI_ENI_SUNI_H
end_ifndef

begin_define
define|#
directive|define
name|_ENI_ENI_SUNI_H
end_define

begin_comment
comment|/*  * Interrupt bits in SUNI Master Interrupt Status Reg  */
end_comment

begin_define
define|#
directive|define
name|SUNI_RSOPI
value|0x01
end_define

begin_define
define|#
directive|define
name|SUNI_RLOPI
value|0x02
end_define

begin_define
define|#
directive|define
name|SUNI_RPOPI
value|0x04
end_define

begin_define
define|#
directive|define
name|SUNI_RACPI
value|0x08
end_define

begin_define
define|#
directive|define
name|SUNI_TACPI
value|0x10
end_define

begin_define
define|#
directive|define
name|SUNI_RDOOLI
value|0x20
end_define

begin_define
define|#
directive|define
name|SUNI_LCDI
value|0x40
end_define

begin_define
define|#
directive|define
name|SUNI_TROOLI
value|0x80
end_define

begin_comment
comment|/*  * SUNI Register numbers  */
end_comment

begin_define
define|#
directive|define
name|SUNI_MASTER_REG
value|0x00
end_define

begin_comment
comment|/* Master reset and ID */
end_comment

begin_define
define|#
directive|define
name|SUNI_IS_REG
value|0x02
end_define

begin_comment
comment|/* Master Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|SUNI_CLOCK_REG
value|0x06
end_define

begin_comment
comment|/* Clock synth/control/status */
end_comment

begin_define
define|#
directive|define
name|SUNI_RSOP_REG
value|0x10
end_define

begin_comment
comment|/* RSOP control/Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|SUNI_SECT_BIP_REG
value|0x12
end_define

begin_define
define|#
directive|define
name|SUNI_RLOP_REG
value|0x18
end_define

begin_comment
comment|/* RLOP control/Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|SUNI_LINE_BIP_REG
value|0x1A
end_define

begin_define
define|#
directive|define
name|SUNI_LINE_FEBE_REG
value|0x1D
end_define

begin_define
define|#
directive|define
name|SUNI_RPOP_IS_REG
value|0x31
end_define

begin_comment
comment|/* RPOP Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|SUNI_PATH_BIP_REG
value|0x38
end_define

begin_define
define|#
directive|define
name|SUNI_PATH_FEBE_REG
value|0x3A
end_define

begin_define
define|#
directive|define
name|SUNI_RACP_REG
value|0x50
end_define

begin_comment
comment|/* RACP control/status */
end_comment

begin_define
define|#
directive|define
name|SUNI_HECS_REG
value|0x54
end_define

begin_define
define|#
directive|define
name|SUNI_UHECS_REG
value|0x55
end_define

begin_define
define|#
directive|define
name|SUNI_TACP_REG
value|0x60
end_define

begin_comment
comment|/* TACP control/status */
end_comment

begin_comment
comment|/*  * Delay timer to allow SUNI statistic registers to load  */
end_comment

begin_define
define|#
directive|define
name|SUNI_DELAY
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ENI_ENI_SUNI_H */
end_comment

end_unit

