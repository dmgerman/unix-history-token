begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Dean Huxley (dean@fsa.ca)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Dean Huxley.  * 4. The name of Dean Huxley may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Register offsets from base.  */
end_comment

begin_define
define|#
directive|define
name|EG_COMMAND
value|0x00
end_define

begin_define
define|#
directive|define
name|EG_STATUS
value|0x02
end_define

begin_define
define|#
directive|define
name|EG_DATA
value|0x04
end_define

begin_define
define|#
directive|define
name|EG_CONTROL
value|0x06
end_define

begin_comment
comment|/*  * Host Control Register bits  * EG_CTL_ATTN - does a soft reset  * EG_CTL_FLSH - flushes the data register  * EG_CTL_RESET - does a hard reset  * EG_CTL_DMAE - Used with DIR bit, enables DMA transfers to/from data reg.  * EG_CTL_DIR  - if clear then host -> adapter, if set then adapter -> host  * EG_CTL_TCEN - terminal count enable. enables host interrupt after DMA.  * EG_CTL_CMDE - command reg interrupt enable. (when it is written)  * EG_CTL_HSF1 - Host status flag 1  * EG_CTL_HSF2 - Host status flag 2  */
end_comment

begin_define
define|#
directive|define
name|EG_CTL_ATTN
value|0x80
end_define

begin_define
define|#
directive|define
name|EG_CTL_FLSH
value|0x40
end_define

begin_define
define|#
directive|define
name|EG_CTL_RESET
value|(EG_CTL_ATTN|EG_CTL_FLSH)
end_define

begin_define
define|#
directive|define
name|EG_CTL_DMAE
value|0x20
end_define

begin_define
define|#
directive|define
name|EG_CTL_DIR
value|0x10
end_define

begin_define
define|#
directive|define
name|EG_CTL_TCEN
value|0x08
end_define

begin_define
define|#
directive|define
name|EG_CTL_CMDE
value|0x04
end_define

begin_define
define|#
directive|define
name|EG_CTL_HSF2
value|0x02
end_define

begin_define
define|#
directive|define
name|EG_CTL_HSF1
value|0x01
end_define

begin_comment
comment|/*  * Host Status Register bits  * EG_STAT_HRDY - Data Register ready  * EG_STAT_HCRE - Host Command Register empty  * EG_STAT_ACRF - Adapter Command register full  * EG_STAT_DIR  - Direction flag, 0 = host -> adapter, 1 = adapter -> host  * EG_STAT_DONE - DMA done  * EG_STAT_ASF1 - Adapter status flag 1  * EG_STAT_ASF2 - Adapter status flag 2  * EG_STAT_ASF3 - Adapter status flag 3  */
end_comment

begin_define
define|#
directive|define
name|EG_STAT_HRDY
value|0x80
end_define

begin_define
define|#
directive|define
name|EG_STAT_HCRE
value|0x40
end_define

begin_define
define|#
directive|define
name|EG_STAT_ACRF
value|0x20
end_define

begin_define
define|#
directive|define
name|EG_STAT_DIR
value|0x10
end_define

begin_define
define|#
directive|define
name|EG_STAT_DONE
value|0x08
end_define

begin_define
define|#
directive|define
name|EG_STAT_ASF3
value|0x04
end_define

begin_define
define|#
directive|define
name|EG_STAT_ASF2
value|0x02
end_define

begin_define
define|#
directive|define
name|EG_STAT_ASF1
value|0x01
end_define

begin_define
define|#
directive|define
name|EG_PCB_ACCEPT
value|1
end_define

begin_define
define|#
directive|define
name|EG_PCB_REJECT
value|2
end_define

begin_define
define|#
directive|define
name|EG_PCB_DONE
value|3
end_define

begin_define
define|#
directive|define
name|EG_PCB_STAT
parameter_list|(
name|x
parameter_list|)
value|((x)&3)
end_define

begin_define
define|#
directive|define
name|EG_PCB_MASK
parameter_list|(
name|x
parameter_list|)
value|((x)&~3)
end_define

begin_define
define|#
directive|define
name|EG_CMD_CONFIG82586
value|0x02
end_define

begin_define
define|#
directive|define
name|EG_CMD_GETEADDR
value|0x03
end_define

begin_define
define|#
directive|define
name|EG_CMD_RECVPACKET
value|0x08
end_define

begin_define
define|#
directive|define
name|EG_CMD_SENDPACKET
value|0x09
end_define

begin_define
define|#
directive|define
name|EG_CMD_GETSTATS
value|0x0a
end_define

begin_define
define|#
directive|define
name|EG_CMD_SETEADDR
value|0x10
end_define

begin_define
define|#
directive|define
name|EG_CMD_GETINFO
value|0x11
end_define

begin_define
define|#
directive|define
name|EG_RSP_CONFIG82586
value|0x32
end_define

begin_define
define|#
directive|define
name|EG_RSP_GETEADDR
value|0x33
end_define

begin_define
define|#
directive|define
name|EG_RSP_RECVPACKET
value|0x38
end_define

begin_define
define|#
directive|define
name|EG_RSP_SENDPACKET
value|0x39
end_define

begin_define
define|#
directive|define
name|EG_RSP_GETSTATS
value|0x3a
end_define

begin_define
define|#
directive|define
name|EG_RSP_SETEADDR
value|0x40
end_define

begin_define
define|#
directive|define
name|EG_RSP_GETINFO
value|0x41
end_define

end_unit

