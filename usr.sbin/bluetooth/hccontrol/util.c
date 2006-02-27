begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util.c  *  * Copyright (c) 2001 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: util.c,v 1.2 2003/05/19 17:29:29 max Exp $  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<bluetooth.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|SIZE
parameter_list|(
name|x
parameter_list|)
value|(sizeof((x))/sizeof((x)[0]))
end_define

begin_function
name|char
specifier|const
modifier|*
specifier|const
name|hci_link2str
parameter_list|(
name|int
name|link_type
parameter_list|)
block|{
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|t
index|[]
init|=
block|{
comment|/* NG_HCI_LINK_SCO */
literal|"SCO"
block|,
comment|/* NG_HCI_LINK_ACL */
literal|"ACL"
block|}
decl_stmt|;
return|return
operator|(
name|link_type
operator|>=
name|SIZE
argument_list|(
name|t
argument_list|)
condition|?
literal|"?"
else|:
name|t
index|[
name|link_type
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* hci_link2str */
end_comment

begin_function
name|char
specifier|const
modifier|*
specifier|const
name|hci_pin2str
parameter_list|(
name|int
name|type
parameter_list|)
block|{
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|t
index|[]
init|=
block|{
comment|/* 0x00 */
literal|"Variable PIN"
block|,
comment|/* 0x01 */
literal|"Fixed PIN"
block|}
decl_stmt|;
return|return
operator|(
name|type
operator|>=
name|SIZE
argument_list|(
name|t
argument_list|)
condition|?
literal|"?"
else|:
name|t
index|[
name|type
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* hci_pin2str */
end_comment

begin_function
name|char
specifier|const
modifier|*
specifier|const
name|hci_scan2str
parameter_list|(
name|int
name|scan
parameter_list|)
block|{
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|t
index|[]
init|=
block|{
comment|/* 0x00 */
literal|"No Scan enabled"
block|,
comment|/* 0x01 */
literal|"Inquiry Scan enabled. Page Scan disabled"
block|,
comment|/* 0x02 */
literal|"Inquiry Scan disabled. Page Scan enabled"
block|,
comment|/* 0x03 */
literal|"Inquiry Scan enabled. Page Scan enabled"
block|}
decl_stmt|;
return|return
operator|(
name|scan
operator|>=
name|SIZE
argument_list|(
name|t
argument_list|)
condition|?
literal|"?"
else|:
name|t
index|[
name|scan
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* hci_scan2str */
end_comment

begin_function
name|char
specifier|const
modifier|*
specifier|const
name|hci_encrypt2str
parameter_list|(
name|int
name|encrypt
parameter_list|,
name|int
name|brief
parameter_list|)
block|{
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|t
index|[]
init|=
block|{
comment|/* 0x00 */
literal|"Disabled"
block|,
comment|/* 0x01 */
literal|"Only for point-to-point packets"
block|,
comment|/* 0x02 */
literal|"Both point-to-point and broadcast packets"
block|}
decl_stmt|;
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|t1
index|[]
init|=
block|{
comment|/* NG_HCI_ENCRYPTION_MODE_NONE */
literal|"NONE"
block|,
comment|/* NG_HCI_ENCRYPTION_MODE_P2P */
literal|"P2P"
block|,
comment|/* NG_HCI_ENCRYPTION_MODE_ALL */
literal|"ALL"
block|, 	}
decl_stmt|;
if|if
condition|(
name|brief
condition|)
return|return
operator|(
name|encrypt
operator|>=
name|SIZE
argument_list|(
name|t1
argument_list|)
condition|?
literal|"?"
else|:
name|t1
index|[
name|encrypt
index|]
operator|)
return|;
return|return
operator|(
name|encrypt
operator|>=
name|SIZE
argument_list|(
name|t
argument_list|)
condition|?
literal|"?"
else|:
name|t
index|[
name|encrypt
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* hci_encrypt2str */
end_comment

begin_function
name|char
specifier|const
modifier|*
specifier|const
name|hci_coding2str
parameter_list|(
name|int
name|coding
parameter_list|)
block|{
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|t
index|[]
init|=
block|{
comment|/* 0x00 */
literal|"Linear"
block|,
comment|/* 0x01 */
literal|"u-law"
block|,
comment|/* 0x02 */
literal|"A-law"
block|,
comment|/* 0x03 */
literal|"Reserved"
block|}
decl_stmt|;
return|return
operator|(
name|coding
operator|>=
name|SIZE
argument_list|(
name|t
argument_list|)
condition|?
literal|"?"
else|:
name|t
index|[
name|coding
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* hci_coding2str */
end_comment

begin_function
name|char
specifier|const
modifier|*
specifier|const
name|hci_vdata2str
parameter_list|(
name|int
name|data
parameter_list|)
block|{
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|t
index|[]
init|=
block|{
comment|/* 0x00 */
literal|"1's complement"
block|,
comment|/* 0x01 */
literal|"2's complement"
block|,
comment|/* 0x02 */
literal|"Sign-Magnitude"
block|,
comment|/* 0x03 */
literal|"Reserved"
block|}
decl_stmt|;
return|return
operator|(
name|data
operator|>=
name|SIZE
argument_list|(
name|t
argument_list|)
condition|?
literal|"?"
else|:
name|t
index|[
name|data
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* hci_vdata2str */
end_comment

begin_function
name|char
specifier|const
modifier|*
specifier|const
name|hci_hmode2str
parameter_list|(
name|int
name|mode
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|size
parameter_list|)
block|{
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|t
index|[]
init|=
block|{
comment|/* 0x01 */
literal|"Suspend Page Scan "
block|,
comment|/* 0x02 */
literal|"Suspend Inquiry Scan "
block|,
comment|/* 0x04 */
literal|"Suspend Periodic Inquiries "
block|}
decl_stmt|;
if|if
condition|(
name|buffer
operator|!=
name|NULL
operator|&&
name|size
operator|>
literal|0
condition|)
block|{
name|int
name|n
decl_stmt|;
name|memset
argument_list|(
name|buffer
argument_list|,
literal|0
argument_list|,
name|size
argument_list|)
expr_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|SIZE
argument_list|(
name|t
argument_list|)
condition|;
name|n
operator|++
control|)
block|{
name|int
name|len
init|=
name|strlen
argument_list|(
name|buffer
argument_list|)
decl_stmt|;
if|if
condition|(
name|len
operator|>=
name|size
condition|)
break|break;
if|if
condition|(
name|mode
operator|&
operator|(
literal|1
operator|<<
name|n
operator|)
condition|)
name|strncat
argument_list|(
name|buffer
argument_list|,
name|t
index|[
name|n
index|]
argument_list|,
name|size
operator|-
name|len
argument_list|)
expr_stmt|;
block|}
block|}
return|return
operator|(
name|buffer
operator|)
return|;
block|}
end_function

begin_comment
comment|/* hci_hmode2str */
end_comment

begin_function
name|char
specifier|const
modifier|*
specifier|const
name|hci_ver2str
parameter_list|(
name|int
name|ver
parameter_list|)
block|{
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|t
index|[]
init|=
block|{
comment|/* 0x00 */
literal|"Bluetooth HCI Specification 1.0B"
block|,
comment|/* 0x01 */
literal|"Bluetooth HCI Specification 1.1"
block|,
comment|/* 0x02 */
literal|"Bluetooth HCI Specification 1.2"
block|,
comment|/* 0x03 */
literal|"Bluetooth HCI Specification 2.0"
block|}
decl_stmt|;
return|return
operator|(
name|ver
operator|>=
name|SIZE
argument_list|(
name|t
argument_list|)
condition|?
literal|"?"
else|:
name|t
index|[
name|ver
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* hci_ver2str */
end_comment

begin_function
name|char
specifier|const
modifier|*
specifier|const
name|hci_lmpver2str
parameter_list|(
name|int
name|ver
parameter_list|)
block|{
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|t
index|[]
init|=
block|{
comment|/* 0x00 */
literal|"Bluetooth LMP 1.0"
block|,
comment|/* 0x01 */
literal|"Bluetooth LMP 1.1"
block|,
comment|/* 0x02 */
literal|"Bluetooth LMP 1.2"
block|,
comment|/* 0x03 */
literal|"Bluetooth LMP 2.0"
block|}
decl_stmt|;
return|return
operator|(
name|ver
operator|>=
name|SIZE
argument_list|(
name|t
argument_list|)
condition|?
literal|"?"
else|:
name|t
index|[
name|ver
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* hci_lmpver2str */
end_comment

begin_function
name|char
specifier|const
modifier|*
specifier|const
name|hci_manufacturer2str
parameter_list|(
name|int
name|m
parameter_list|)
block|{
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|t
index|[]
init|=
block|{
comment|/* 0000 */
literal|"Ericsson Technology Licensing"
block|,
comment|/* 0001 */
literal|"Nokia Mobile Phones"
block|,
comment|/* 0002 */
literal|"Intel Corp."
block|,
comment|/* 0003 */
literal|"IBM Corp."
block|,
comment|/* 0004 */
literal|"Toshiba Corp."
block|,
comment|/* 0005 */
literal|"3Com"
block|,
comment|/* 0006 */
literal|"Microsoft"
block|,
comment|/* 0007 */
literal|"Lucent"
block|,
comment|/* 0008 */
literal|"Motorola"
block|,
comment|/* 0009 */
literal|"Infineon Technologies AG"
block|,
comment|/* 0010 */
literal|"Cambridge Silicon Radio"
block|,
comment|/* 0011 */
literal|"Silicon Wave"
block|,
comment|/* 0012 */
literal|"Digianswer A/S"
block|,
comment|/* 0013 */
literal|"Texas Instruments Inc."
block|,
comment|/* 0014 */
literal|"Parthus Technologies Inc."
block|,
comment|/* 0015 */
literal|"Broadcom Corporation"
block|,
comment|/* 0016 */
literal|"Mitel Semiconductor"
block|,
comment|/* 0017 */
literal|"Widcomm, Inc."
block|,
comment|/* 0018 */
literal|"Zeevo, Inc."
block|,
comment|/* 0019 */
literal|"Atmel Corporation"
block|,
comment|/* 0020 */
literal|"Mitsubishi Electric Corporation"
block|,
comment|/* 0021 */
literal|"RTX Telecom A/S"
block|,
comment|/* 0022 */
literal|"KC Technology Inc."
block|,
comment|/* 0023 */
literal|"Newlogic"
block|,
comment|/* 0024 */
literal|"Transilica, Inc."
block|,
comment|/* 0025 */
literal|"Rohde& Schwartz GmbH& Co. KG"
block|,
comment|/* 0026 */
literal|"TTPCom Limited"
block|,
comment|/* 0027 */
literal|"Signia Technologies, Inc."
block|,
comment|/* 0028 */
literal|"Conexant Systems Inc."
block|,
comment|/* 0029 */
literal|"Qualcomm"
block|,
comment|/* 0030 */
literal|"Inventel"
block|,
comment|/* 0031 */
literal|"AVM Berlin"
block|,
comment|/* 0032 */
literal|"BandSpeed, Inc."
block|,
comment|/* 0033 */
literal|"Mansella Ltd"
block|,
comment|/* 0034 */
literal|"NEC Corporation"
block|,
comment|/* 0035 */
literal|"WavePlus Technology Co., Ltd."
block|,
comment|/* 0036 */
literal|"Alcatel"
block|,
comment|/* 0037 */
literal|"Philips Semiconductors"
block|,
comment|/* 0038 */
literal|"C Technologies"
block|,
comment|/* 0039 */
literal|"Open Interface"
block|,
comment|/* 0040 */
literal|"R F Micro Devices"
block|,
comment|/* 0041 */
literal|"Hitachi Ltd"
block|,
comment|/* 0042 */
literal|"Symbol Technologies, Inc."
block|,
comment|/* 0043 */
literal|"Tenovis"
block|,
comment|/* 0044 */
literal|"Macronix International Co. Ltd."
block|,
comment|/* 0045 */
literal|"GCT Semiconductor"
block|,
comment|/* 0046 */
literal|"Norwood Systems"
block|,
comment|/* 0047 */
literal|"MewTel Technology Inc."
block|,
comment|/* 0048 */
literal|"ST Microelectronics"
block|,
comment|/* 0049 */
literal|"Synopsys"
block|,
comment|/* 0050 */
literal|"Red-M (Communications) Ltd"
block|,
comment|/* 0051 */
literal|"Commil Ltd"
block|,
comment|/* 0052 */
literal|"Computer Access Technology Corporation (CATC)"
block|,
comment|/* 0053 */
literal|"Eclipse (HQ Espana) S.L."
block|,
comment|/* 0054 */
literal|"Renesas Technology Corp."
block|,
comment|/* 0055 */
literal|"Mobilian Corporation"
block|,
comment|/* 0056 */
literal|"Terax"
block|,
comment|/* 0057 */
literal|"Integrated System Solution Corp."
block|,
comment|/* 0058 */
literal|"Matsushita Electric Industrial Co., Ltd."
block|,
comment|/* 0059 */
literal|"Gennum Corporation"
block|,
comment|/* 0060 */
literal|"Research In Motion"
block|,
comment|/* 0061 */
literal|"IPextreme, Inc."
block|,
comment|/* 0062 */
literal|"Systems and Chips, Inc"
block|,
comment|/* 0063 */
literal|"Bluetooth SIG, Inc"
block|,
comment|/* 0064 */
literal|"Seiko Epson Corporation"
block|}
decl_stmt|;
return|return
operator|(
name|m
operator|>=
name|SIZE
argument_list|(
name|t
argument_list|)
condition|?
literal|"?"
else|:
name|t
index|[
name|m
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* hci_manufacturer2str */
end_comment

begin_function
name|char
specifier|const
modifier|*
specifier|const
name|hci_features2str
parameter_list|(
name|uint8_t
modifier|*
name|features
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|size
parameter_list|)
block|{
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|t
index|[]
index|[
literal|8
index|]
init|=
block|{
block|{
comment|/* byte 0 */
comment|/* 0 */
literal|"<3-Slot> "
block|,
comment|/* 1 */
literal|"<5-Slot> "
block|,
comment|/* 2 */
literal|"<Encryption> "
block|,
comment|/* 3 */
literal|"<Slot offset> "
block|,
comment|/* 4 */
literal|"<Timing accuracy> "
block|,
comment|/* 5 */
literal|"<Switch> "
block|,
comment|/* 6 */
literal|"<Hold mode> "
block|,
comment|/* 7 */
literal|"<Sniff mode> "
block|}
block|,
block|{
comment|/* byte 1 */
comment|/* 0 */
literal|"<Park mode> "
block|,
comment|/* 1 */
literal|"<RSSI> "
block|,
comment|/* 2 */
literal|"<Channel quality> "
block|,
comment|/* 3 */
literal|"<SCO link> "
block|,
comment|/* 4 */
literal|"<HV2 packets> "
block|,
comment|/* 5 */
literal|"<HV3 packets> "
block|,
comment|/* 6 */
literal|"<u-law log> "
block|,
comment|/* 7 */
literal|"<A-law log> "
block|}
block|,
block|{
comment|/* byte 2 */
comment|/* 0 */
literal|"<CVSD> "
block|,
comment|/* 1 */
literal|"<Paging scheme> "
block|,
comment|/* 2 */
literal|"<Power control> "
block|,
comment|/* 3 */
literal|"<Transparent SCO data> "
block|,
comment|/* 4 */
literal|"<Flow control lag (bit0)> "
block|,
comment|/* 5 */
literal|"<Flow control lag (bit1)> "
block|,
comment|/* 6 */
literal|"<Flow control lag (bit2)> "
block|,
comment|/* 7 */
literal|"<Unknown2.7> "
block|}
block|}
decl_stmt|;
if|if
condition|(
name|buffer
operator|!=
name|NULL
operator|&&
name|size
operator|>
literal|0
condition|)
block|{
name|int
name|n
decl_stmt|,
name|i
decl_stmt|,
name|len0
decl_stmt|,
name|len1
decl_stmt|;
name|memset
argument_list|(
name|buffer
argument_list|,
literal|0
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|len1
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|SIZE
argument_list|(
name|t
argument_list|)
condition|;
name|n
operator|++
control|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|SIZE
argument_list|(
name|t
index|[
name|n
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
block|{
name|len0
operator|=
name|strlen
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|len0
operator|>=
name|size
condition|)
goto|goto
name|done
goto|;
if|if
condition|(
name|features
index|[
name|n
index|]
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
condition|)
block|{
if|if
condition|(
name|len1
operator|+
name|strlen
argument_list|(
name|t
index|[
name|n
index|]
index|[
name|i
index|]
argument_list|)
operator|>
literal|60
condition|)
block|{
name|len1
operator|=
literal|0
expr_stmt|;
name|buffer
index|[
name|len0
operator|-
literal|1
index|]
operator|=
literal|'\n'
expr_stmt|;
block|}
name|len1
operator|+=
name|strlen
argument_list|(
name|t
index|[
name|n
index|]
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|strncat
argument_list|(
name|buffer
argument_list|,
name|t
index|[
name|n
index|]
index|[
name|i
index|]
argument_list|,
name|size
operator|-
name|len0
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
name|done
label|:
return|return
operator|(
name|buffer
operator|)
return|;
block|}
end_function

begin_comment
comment|/* hci_features2str */
end_comment

begin_function
name|char
specifier|const
modifier|*
specifier|const
name|hci_cc2str
parameter_list|(
name|int
name|cc
parameter_list|)
block|{
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|t
index|[]
init|=
block|{
comment|/* 0x00 */
literal|"North America, Europe, Japan"
block|,
comment|/* 0x01 */
literal|"France"
block|}
decl_stmt|;
return|return
operator|(
name|cc
operator|>=
name|SIZE
argument_list|(
name|t
argument_list|)
condition|?
literal|"?"
else|:
name|t
index|[
name|cc
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* hci_cc2str */
end_comment

begin_function
name|char
specifier|const
modifier|*
specifier|const
name|hci_con_state2str
parameter_list|(
name|int
name|state
parameter_list|)
block|{
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|t
index|[]
init|=
block|{
comment|/* NG_HCI_CON_CLOSED */
literal|"CLOSED"
block|,
comment|/* NG_HCI_CON_W4_LP_CON_RSP */
literal|"W4_LP_CON_RSP"
block|,
comment|/* NG_HCI_CON_W4_CONN_COMPLETE */
literal|"W4_CONN_COMPLETE"
block|,
comment|/* NG_HCI_CON_OPEN */
literal|"OPEN"
block|}
decl_stmt|;
return|return
operator|(
name|state
operator|>=
name|SIZE
argument_list|(
name|t
argument_list|)
condition|?
literal|"UNKNOWN"
else|:
name|t
index|[
name|state
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* hci_con_state2str */
end_comment

begin_function
name|char
specifier|const
modifier|*
specifier|const
name|hci_status2str
parameter_list|(
name|int
name|status
parameter_list|)
block|{
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|t
index|[]
init|=
block|{
comment|/* 0x00 */
literal|"No error"
block|,
comment|/* 0x01 */
literal|"Unknown HCI command"
block|,
comment|/* 0x02 */
literal|"No connection"
block|,
comment|/* 0x03 */
literal|"Hardware failure"
block|,
comment|/* 0x04 */
literal|"Page timeout"
block|,
comment|/* 0x05 */
literal|"Authentication failure"
block|,
comment|/* 0x06 */
literal|"Key missing"
block|,
comment|/* 0x07 */
literal|"Memory full"
block|,
comment|/* 0x08 */
literal|"Connection timeout"
block|,
comment|/* 0x09 */
literal|"Max number of connections"
block|,
comment|/* 0x0a */
literal|"Max number of SCO connections to a unit"
block|,
comment|/* 0x0b */
literal|"ACL connection already exists"
block|,
comment|/* 0x0c */
literal|"Command disallowed"
block|,
comment|/* 0x0d */
literal|"Host rejected due to limited resources"
block|,
comment|/* 0x0e */
literal|"Host rejected due to security reasons"
block|,
comment|/* 0x0f */
literal|"Host rejected due to remote unit is a personal unit"
block|,
comment|/* 0x10 */
literal|"Host timeout"
block|,
comment|/* 0x11 */
literal|"Unsupported feature or parameter value"
block|,
comment|/* 0x12 */
literal|"Invalid HCI command parameter"
block|,
comment|/* 0x13 */
literal|"Other end terminated connection: User ended connection"
block|,
comment|/* 0x14 */
literal|"Other end terminated connection: Low resources"
block|,
comment|/* 0x15 */
literal|"Other end terminated connection: About to power off"
block|,
comment|/* 0x16 */
literal|"Connection terminated by local host"
block|,
comment|/* 0x17 */
literal|"Repeated attempts"
block|,
comment|/* 0x18 */
literal|"Pairing not allowed"
block|,
comment|/* 0x19 */
literal|"Unknown LMP PDU"
block|,
comment|/* 0x1a */
literal|"Unsupported remote feature"
block|,
comment|/* 0x1b */
literal|"SCO offset rejected"
block|,
comment|/* 0x1c */
literal|"SCO interval rejected"
block|,
comment|/* 0x1d */
literal|"SCO air mode rejected"
block|,
comment|/* 0x1e */
literal|"Invalid LMP parameters"
block|,
comment|/* 0x1f */
literal|"Unspecified error"
block|,
comment|/* 0x20 */
literal|"Unsupported LMP parameter value"
block|,
comment|/* 0x21 */
literal|"Role change not allowed"
block|,
comment|/* 0x22 */
literal|"LMP response timeout"
block|,
comment|/* 0x23 */
literal|"LMP error transaction collision"
block|,
comment|/* 0x24 */
literal|"LMP PSU not allowed"
block|,
comment|/* 0x25 */
literal|"Encryption mode not acceptable"
block|,
comment|/* 0x26 */
literal|"Unit key used"
block|,
comment|/* 0x27 */
literal|"QoS is not supported"
block|,
comment|/* 0x28 */
literal|"Instant passed"
block|,
comment|/* 0x29 */
literal|"Pairing with unit key not supported"
block|}
decl_stmt|;
return|return
operator|(
name|status
operator|>=
name|SIZE
argument_list|(
name|t
argument_list|)
condition|?
literal|"Unknown error"
else|:
name|t
index|[
name|status
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* hci_status2str */
end_comment

begin_function
name|char
specifier|const
modifier|*
specifier|const
name|hci_bdaddr2str
parameter_list|(
name|bdaddr_t
specifier|const
modifier|*
name|ba
parameter_list|)
block|{
specifier|extern
name|int
name|numeric_bdaddr
decl_stmt|;
specifier|static
name|char
name|buffer
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
name|struct
name|hostent
modifier|*
name|he
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
name|ba
argument_list|,
name|NG_HCI_BDADDR_ANY
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|ba
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
block|{
name|buffer
index|[
literal|0
index|]
operator|=
literal|'*'
expr_stmt|;
name|buffer
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|buffer
operator|)
return|;
block|}
if|if
condition|(
operator|!
name|numeric_bdaddr
operator|&&
operator|(
name|he
operator|=
name|bt_gethostbyaddr
argument_list|(
operator|(
name|char
operator|*
operator|)
name|ba
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|ba
argument_list|)
argument_list|,
name|AF_BLUETOOTH
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|strlcpy
argument_list|(
name|buffer
argument_list|,
name|he
operator|->
name|h_name
argument_list|,
sizeof|sizeof
argument_list|(
name|buffer
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|buffer
operator|)
return|;
block|}
name|bt_ntoa
argument_list|(
name|ba
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
return|return
operator|(
name|buffer
operator|)
return|;
block|}
end_function

begin_comment
comment|/* hci_bdaddr2str */
end_comment

end_unit

