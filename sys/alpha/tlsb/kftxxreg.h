begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: kftxxreg.h,v 1.5 1998/07/08 00:45:08 mjacob Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997, 2000 by Matthew Jacob  * NASA AMES Research Center.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Registers and values specific to KFTIA or KFTHA nodes.  */
end_comment

begin_comment
comment|/*  * Taken from combinations of:  *  *	``DWLPA and DWLPB PCI Adapter Technical Manual,  *	  Order Number: EK-DWLPX-TM.A01''  *  *  and  *  *	``AlphaServer 8200/8400 System Technical Manual,  *	  Order Number EK-T8030-TM. A01''  */
end_comment

begin_define
define|#
directive|define
name|REGVAL
parameter_list|(
name|r
parameter_list|)
value|(*(volatile int32_t *)ALPHA_PHYS_TO_K0SEG(r))
end_define

begin_comment
comment|/*  * There are (potentially) 4 I/O hoses per I/O node.  *  * A CPU to Hose Address Mapping looks (roughly) like this:  *  *  39 38........36 35.34 33.................0  *  -------------------------------------------  *  |1|TLSB NodeID |Hose#|Hose Module Specific|  *  -------------------------------------------  *  */
end_comment

begin_define
define|#
directive|define
name|HOSE_SIZE
value|0x400000000L
end_define

begin_define
define|#
directive|define
name|MAXHOSE
value|4
end_define

begin_comment
comment|/*  * Hose Specific I/O registers (offsets from base of I/O Board)  */
end_comment

begin_define
define|#
directive|define
name|KFT_IDPNSEX
parameter_list|(
name|hose
parameter_list|)
value|((hose)? (0x2040 + (0x100 * (hose))) : 0x2A40)
end_define

begin_define
define|#
directive|define
name|KFT_ICCNSE
value|0x2040
end_define

begin_define
define|#
directive|define
name|KFT_ICCWTR
value|0x2100
end_define

begin_define
define|#
directive|define
name|KFT_IDPMSR
value|0x2B80
end_define

begin_define
define|#
directive|define
name|KFT_IDPNSE0
value|0x2A40
end_define

begin_define
define|#
directive|define
name|KFT_IDPNSE1
value|0x2140
end_define

begin_define
define|#
directive|define
name|KFT_IDPNSE2
value|0x2240
end_define

begin_define
define|#
directive|define
name|KFT_IDPNSE3
value|0x2340
end_define

end_unit

