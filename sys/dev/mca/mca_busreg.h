begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Matthew N. Dodd<winter@jurai.net>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Standardized MCA configuration information  */
end_comment

begin_define
define|#
directive|define
name|MCA_MAX_SLOTS
value|8
end_define

begin_comment
comment|/* max number of slots per bus */
end_comment

begin_define
define|#
directive|define
name|MCA_MB_SCSI_SLOT
value|8
end_define

begin_define
define|#
directive|define
name|MCA_MB_VIDEO_SLOT
value|9
end_define

begin_define
define|#
directive|define
name|MCA_MAX_ADAPTERS
value|9
end_define

begin_comment
comment|/*  * When an ADF file talks about a POS register  * its not talking about the same index we are  * so provide this to convert ADF pos register  * offsets to our register offsets. (Since   * to us, POS0 and POS1 are just 2 more registers  */
end_comment

begin_define
define|#
directive|define
name|MCA_ADP_POS
parameter_list|(
name|pos
parameter_list|)
value|(pos + 2)
end_define

begin_define
define|#
directive|define
name|MCA_POS0
value|0
end_define

begin_comment
comment|/* low byte of board ID		*/
end_comment

begin_define
define|#
directive|define
name|MCA_POS1
value|1
end_define

begin_comment
comment|/* high byte of board ID	*/
end_comment

begin_define
define|#
directive|define
name|MCA_POS2
value|2
end_define

begin_define
define|#
directive|define
name|MCA_POS2_ENABLE
value|0x01
end_define

begin_comment
comment|/* POS2, hi => adapter enabled */
end_comment

begin_define
define|#
directive|define
name|MCA_POS3
value|3
end_define

begin_define
define|#
directive|define
name|MCA_POS4
value|4
end_define

begin_define
define|#
directive|define
name|MCA_POS5
value|5
end_define

begin_define
define|#
directive|define
name|MCA_POS5_CHCK_STAT
value|0x40
end_define

begin_comment
comment|/* lo => CHCK status available */
end_comment

begin_define
define|#
directive|define
name|MCA_POS5_CHCK
value|0x80
end_define

begin_comment
comment|/* lo => adapter CHCK signal */
end_comment

begin_define
define|#
directive|define
name|MCA_POS6
value|6
end_define

begin_comment
comment|/* low byte of CHCK status */
end_comment

begin_define
define|#
directive|define
name|MCA_POS7
value|7
end_define

begin_comment
comment|/* high byte of CHCK status */
end_comment

begin_comment
comment|/*  * MCA register addresses for IBM PS/2  */
end_comment

begin_define
define|#
directive|define
name|MCA_SYS_CTL_A_REG
value|0x92
end_define

begin_comment
comment|/* PS/2 System Control Port A */
end_comment

begin_define
define|#
directive|define
name|MCA_SYS_CTL_B_REG
value|0x60
end_define

begin_comment
comment|/* PS/2 System Control Port B */
end_comment

begin_define
define|#
directive|define
name|MCA_ARB_REG
value|0x90
end_define

begin_comment
comment|/* MCA Arbitration port */
end_comment

begin_define
define|#
directive|define
name|MCA_CSF_REG
value|0x91
end_define

begin_comment
comment|/* MCA Card Select Feedback */
end_comment

begin_comment
comment|/*  *	0x96, 0x97	POS Registers  *	0x100 - 0x107	POS Registers  */
end_comment

begin_define
define|#
directive|define
name|MCA_MB_SETUP_REG
value|0x94
end_define

begin_comment
comment|/* Motherboard setup register */
end_comment

begin_define
define|#
directive|define
name|MCA_MB_SETUP_DIS
value|0xff
end_define

begin_comment
comment|/* Disable motherboard setup */
end_comment

begin_define
define|#
directive|define
name|MCA_MB_SETUP_VIDEO
value|0xdf
end_define

begin_define
define|#
directive|define
name|MCA_MB_SETUP_SCSI
value|0xf7
end_define

begin_comment
comment|/* Pri. SCSI setup reg */
end_comment

begin_define
define|#
directive|define
name|MCA_MB_SETUP_SCSI_ALT
value|0xfd
end_define

begin_comment
comment|/* Alt. SCSI setup reg */
end_comment

begin_define
define|#
directive|define
name|MCA_ADAP_SETUP_REG
value|0x96
end_define

begin_comment
comment|/* Adapter setup register */
end_comment

begin_define
define|#
directive|define
name|MCA_ADAP_SETUP_DIS
value|0x0
end_define

begin_comment
comment|/* Disable adapter setup */
end_comment

begin_define
define|#
directive|define
name|MCA_ADAP_SET
value|0x08
end_define

begin_comment
comment|/* Adapter setup mode */
end_comment

begin_define
define|#
directive|define
name|MCA_ADAP_CHR
value|0x80
end_define

begin_comment
comment|/* Adapter channel reset */
end_comment

begin_define
define|#
directive|define
name|MCA_POS_REG
parameter_list|(
name|n
parameter_list|)
value|(0x100+(n))
end_define

begin_comment
comment|/* POS registers 0-7 */
end_comment

end_unit

