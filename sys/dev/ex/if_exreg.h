begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, Javier Martín Rueda (jmrueda@diatel.upm.es)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Intel EtherExpress Pro/10 Ethernet driver  */
end_comment

begin_comment
comment|/*  * Several constants.  */
end_comment

begin_comment
comment|/* Length of an ethernet address. */
end_comment

begin_define
define|#
directive|define
name|ETHER_ADDR_LEN
value|6
end_define

begin_comment
comment|/* Default RAM size in board. */
end_comment

begin_define
define|#
directive|define
name|CARD_RAM_SIZE
value|0x8000
end_define

begin_comment
comment|/* Number of I/O ports used. */
end_comment

begin_define
define|#
directive|define
name|EX_IOSIZE
value|16
end_define

begin_comment
comment|/*  * Intel EtherExpress Pro (i82595 based) registers  */
end_comment

begin_comment
comment|/* Common registers to all banks. */
end_comment

begin_define
define|#
directive|define
name|CMD_REG
value|0
end_define

begin_define
define|#
directive|define
name|REG1
value|1
end_define

begin_define
define|#
directive|define
name|REG2
value|2
end_define

begin_define
define|#
directive|define
name|REG3
value|3
end_define

begin_define
define|#
directive|define
name|REG4
value|4
end_define

begin_define
define|#
directive|define
name|REG5
value|5
end_define

begin_define
define|#
directive|define
name|REG6
value|6
end_define

begin_define
define|#
directive|define
name|REG7
value|7
end_define

begin_define
define|#
directive|define
name|REG8
value|8
end_define

begin_define
define|#
directive|define
name|REG9
value|9
end_define

begin_define
define|#
directive|define
name|REG10
value|10
end_define

begin_define
define|#
directive|define
name|REG11
value|11
end_define

begin_define
define|#
directive|define
name|REG12
value|12
end_define

begin_define
define|#
directive|define
name|REG13
value|13
end_define

begin_define
define|#
directive|define
name|REG14
value|14
end_define

begin_define
define|#
directive|define
name|REG15
value|15
end_define

begin_comment
comment|/* Definitions for command register (CMD_REG). */
end_comment

begin_define
define|#
directive|define
name|Switch_Bank_CMD
value|0
end_define

begin_define
define|#
directive|define
name|MC_Setup_CMD
value|3
end_define

begin_define
define|#
directive|define
name|Transmit_CMD
value|4
end_define

begin_define
define|#
directive|define
name|Diagnose_CMD
value|7
end_define

begin_define
define|#
directive|define
name|Rcv_Enable_CMD
value|8
end_define

begin_define
define|#
directive|define
name|Rcv_Stop
value|11
end_define

begin_define
define|#
directive|define
name|Reset_CMD
value|14
end_define

begin_define
define|#
directive|define
name|Resume_XMT_List_CMD
value|28
end_define

begin_define
define|#
directive|define
name|Sel_Reset_CMD
value|30
end_define

begin_define
define|#
directive|define
name|Abort
value|0x20
end_define

begin_define
define|#
directive|define
name|Bank0_Sel
value|0x00
end_define

begin_define
define|#
directive|define
name|Bank1_Sel
value|0x40
end_define

begin_define
define|#
directive|define
name|Bank2_Sel
value|0x80
end_define

begin_comment
comment|/* Bank 0 specific registers. */
end_comment

begin_define
define|#
directive|define
name|STATUS_REG
value|1
end_define

begin_define
define|#
directive|define
name|ID_REG
value|2
end_define

begin_define
define|#
directive|define
name|Id_Mask
value|0x2c
end_define

begin_define
define|#
directive|define
name|Id_Sig
value|0x24
end_define

begin_define
define|#
directive|define
name|Counter_bits
value|0xc0
end_define

begin_define
define|#
directive|define
name|MASK_REG
value|3
end_define

begin_define
define|#
directive|define
name|Exec_Int
value|0x08
end_define

begin_define
define|#
directive|define
name|Tx_Int
value|0x04
end_define

begin_define
define|#
directive|define
name|Rx_Int
value|0x02
end_define

begin_define
define|#
directive|define
name|Rx_Stp_Int
value|0x01
end_define

begin_define
define|#
directive|define
name|All_Int
value|0x0f
end_define

begin_define
define|#
directive|define
name|RCV_BAR
value|4
end_define

begin_define
define|#
directive|define
name|RCV_BAR_Lo
value|4
end_define

begin_define
define|#
directive|define
name|RCV_BAR_Hi
value|5
end_define

begin_define
define|#
directive|define
name|RCV_STOP_REG
value|6
end_define

begin_define
define|#
directive|define
name|XMT_BAR
value|10
end_define

begin_define
define|#
directive|define
name|HOST_ADDR_REG
value|12
end_define

begin_comment
comment|/* 16-bit register */
end_comment

begin_define
define|#
directive|define
name|IO_PORT_REG
value|14
end_define

begin_comment
comment|/* 16-bit register */
end_comment

begin_comment
comment|/* Bank 1 specific registers. */
end_comment

begin_define
define|#
directive|define
name|TriST_INT
value|0x80
end_define

begin_define
define|#
directive|define
name|INT_NO_REG
value|2
end_define

begin_define
define|#
directive|define
name|RCV_LOWER_LIMIT_REG
value|8
end_define

begin_define
define|#
directive|define
name|RCV_UPPER_LIMIT_REG
value|9
end_define

begin_define
define|#
directive|define
name|XMT_LOWER_LIMIT_REG
value|10
end_define

begin_define
define|#
directive|define
name|XMT_UPPER_LIMIT_REG
value|11
end_define

begin_comment
comment|/* Bank 2 specific registers. */
end_comment

begin_define
define|#
directive|define
name|Disc_Bad_Fr
value|0x80
end_define

begin_define
define|#
directive|define
name|Tx_Chn_ErStp
value|0x40
end_define

begin_define
define|#
directive|define
name|Tx_Chn_Int_Md
value|0x20
end_define

begin_define
define|#
directive|define
name|No_SA_Ins
value|0x10
end_define

begin_define
define|#
directive|define
name|RX_CRC_InMem
value|0x04
end_define

begin_define
define|#
directive|define
name|BNC_bit
value|0x20
end_define

begin_define
define|#
directive|define
name|TPE_bit
value|0x04
end_define

begin_define
define|#
directive|define
name|I_ADDR_REG0
value|4
end_define

begin_define
define|#
directive|define
name|EEPROM_REG
value|10
end_define

begin_define
define|#
directive|define
name|Trnoff_Enable
value|0x10
end_define

begin_comment
comment|/* EEPROM memory positions (16-bit wide). */
end_comment

begin_define
define|#
directive|define
name|EE_IRQ_No
value|1
end_define

begin_define
define|#
directive|define
name|IRQ_No_Mask
value|0x07
end_define

begin_define
define|#
directive|define
name|EE_Eth_Addr_Lo
value|2
end_define

begin_define
define|#
directive|define
name|EE_Eth_Addr_Mid
value|3
end_define

begin_define
define|#
directive|define
name|EE_Eth_Addr_Hi
value|4
end_define

begin_comment
comment|/* EEPROM serial interface. */
end_comment

begin_define
define|#
directive|define
name|EESK
value|0x01
end_define

begin_define
define|#
directive|define
name|EECS
value|0x02
end_define

begin_define
define|#
directive|define
name|EEDI
value|0x04
end_define

begin_define
define|#
directive|define
name|EEDO
value|0x08
end_define

begin_define
define|#
directive|define
name|EE_READ_CMD
value|(6<< 6)
end_define

begin_comment
comment|/* Frame chain constants. */
end_comment

begin_comment
comment|/* Transmit header length (in board's ring buffer). */
end_comment

begin_define
define|#
directive|define
name|XMT_HEADER_LEN
value|8
end_define

begin_define
define|#
directive|define
name|XMT_Chain_Point
value|4
end_define

begin_define
define|#
directive|define
name|XMT_Byte_Count
value|6
end_define

begin_define
define|#
directive|define
name|Done_bit
value|0x0080
end_define

begin_define
define|#
directive|define
name|Ch_bit
value|0x8000
end_define

begin_comment
comment|/* Transmit result bits. */
end_comment

begin_define
define|#
directive|define
name|No_Collisions_bits
value|0x000f
end_define

begin_define
define|#
directive|define
name|TX_OK_bit
value|0x2000
end_define

begin_comment
comment|/* Receive result bits. */
end_comment

begin_define
define|#
directive|define
name|RCV_Done
value|8
end_define

begin_define
define|#
directive|define
name|RCV_OK_bit
value|0x2000
end_define

end_unit

