begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ichsmb_reg.h  *  * Copyright (c) 2000 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@freebsd.org>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ICHSMB_ICHSMB_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ICHSMB_ICHSMB_REG_H_
end_define

begin_comment
comment|/*  * Definitions for the SMBus controller logical device which is part of the  * Intel 81801AA (ICH) and 81801AB (ICH0) I/O controller hub chips.  */
end_comment

begin_comment
comment|/*  * PCI configuration registers  */
end_comment

begin_define
define|#
directive|define
name|ICH_SMB_BASE
value|0x20
end_define

begin_comment
comment|/* base address register */
end_comment

begin_define
define|#
directive|define
name|ICH_HOSTC
value|0x40
end_define

begin_comment
comment|/* host config register */
end_comment

begin_define
define|#
directive|define
name|ICH_HOSTC_I2C_EN
value|0x04
end_define

begin_comment
comment|/*   enable i2c mode */
end_comment

begin_define
define|#
directive|define
name|ICH_HOSTC_SMB_SMI_EN
value|0x02
end_define

begin_comment
comment|/*   SMI# instead of irq */
end_comment

begin_define
define|#
directive|define
name|ICH_HOSTC_HST_EN
value|0x01
end_define

begin_comment
comment|/*   enable host cntrlr */
end_comment

begin_comment
comment|/*  * I/O registers  */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_STA
value|0x00
end_define

begin_comment
comment|/* host status */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_STA_BYTE_DONE_STS
value|0x80
end_define

begin_comment
comment|/*   byte send/rec'd */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_STA_INUSE_STS
value|0x40
end_define

begin_comment
comment|/*   device access mutex */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_STA_SMBALERT_STS
value|0x20
end_define

begin_comment
comment|/*   SMBALERT# signal */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_STA_FAILED
value|0x10
end_define

begin_comment
comment|/*   failed bus transaction */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_STA_BUS_ERR
value|0x08
end_define

begin_comment
comment|/*   transaction collision */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_STA_DEV_ERR
value|0x04
end_define

begin_comment
comment|/*   misc. smb device error */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_STA_INTR
value|0x02
end_define

begin_comment
comment|/*   command completed ok */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_STA_HOST_BUSY
value|0x01
end_define

begin_comment
comment|/*   command is running */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_CNT
value|0x02
end_define

begin_comment
comment|/* host control */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_CNT_START
value|0x40
end_define

begin_comment
comment|/*   start command */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_CNT_LAST_BYTE
value|0x20
end_define

begin_comment
comment|/*   indicate last byte */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_CNT_SMB_CMD_QUICK
value|0x00
end_define

begin_comment
comment|/*   command: quick */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_CNT_SMB_CMD_BYTE
value|0x04
end_define

begin_comment
comment|/*   command: byte */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_CNT_SMB_CMD_BYTE_DATA
value|0x08
end_define

begin_comment
comment|/*   command: byte data */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_CNT_SMB_CMD_WORD_DATA
value|0x0c
end_define

begin_comment
comment|/*   command: word data */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_CNT_SMB_CMD_PROC_CALL
value|0x10
end_define

begin_comment
comment|/*   command: process call */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_CNT_SMB_CMD_BLOCK
value|0x14
end_define

begin_comment
comment|/*   command: block */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_CNT_SMB_CMD_I2C_READ
value|0x18
end_define

begin_comment
comment|/*   command: i2c read */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_CNT_KILL
value|0x02
end_define

begin_comment
comment|/*   kill current transaction */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_CNT_INTREN
value|0x01
end_define

begin_comment
comment|/*   enable interrupt */
end_comment

begin_define
define|#
directive|define
name|ICH_HST_CMD
value|0x03
end_define

begin_comment
comment|/* host command */
end_comment

begin_define
define|#
directive|define
name|ICH_XMIT_SLVA
value|0x04
end_define

begin_comment
comment|/* transmit slave address */
end_comment

begin_define
define|#
directive|define
name|ICH_XMIT_SLVA_READ
value|0x01
end_define

begin_comment
comment|/*   direction: read */
end_comment

begin_define
define|#
directive|define
name|ICH_XMIT_SLVA_WRITE
value|0x00
end_define

begin_comment
comment|/*   direction: write */
end_comment

begin_define
define|#
directive|define
name|ICH_D0
value|0x05
end_define

begin_comment
comment|/* host data 0 */
end_comment

begin_define
define|#
directive|define
name|ICH_D1
value|0x06
end_define

begin_comment
comment|/* host data 1 */
end_comment

begin_define
define|#
directive|define
name|ICH_BLOCK_DB
value|0x07
end_define

begin_comment
comment|/* block data byte */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ICHSMB_ICHSMB_REG_H_ */
end_comment

end_unit

