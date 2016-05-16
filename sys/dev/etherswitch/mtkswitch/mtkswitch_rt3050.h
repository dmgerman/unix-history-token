begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Stanislav Galabov.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MTKSWITCH_RT3050_H__
end_ifndef

begin_define
define|#
directive|define
name|__MTKSWITCH_RT3050_H__
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_PVID
parameter_list|(
name|p
parameter_list|)
value|((((p)>> 1) * 4) + 0x40)
end_define

begin_define
define|#
directive|define
name|PVID_OFF
parameter_list|(
name|p
parameter_list|)
value|(((p)& 1) ? 12 : 0)
end_define

begin_define
define|#
directive|define
name|PVID_MASK
value|0xfff
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_VLANI
parameter_list|(
name|v
parameter_list|)
value|((((v)>> 1) * 4) + 0x50)
end_define

begin_define
define|#
directive|define
name|VLANI_OFF
parameter_list|(
name|v
parameter_list|)
value|(((v)& 1) ? 12 : 0)
end_define

begin_define
define|#
directive|define
name|VLANI_MASK
value|0xfff
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_VMSC
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 2) * 4) + 0x70)
end_define

begin_define
define|#
directive|define
name|VMSC_OFF
parameter_list|(
name|x
parameter_list|)
value|((x& 3) * 8)
end_define

begin_define
define|#
directive|define
name|VMSC_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_POA
value|0x0080
end_define

begin_define
define|#
directive|define
name|POA_PRT_DPX
parameter_list|(
name|x
parameter_list|)
value|((1<<9)<<(x))
end_define

begin_define
define|#
directive|define
name|POA_FE_SPEED
parameter_list|(
name|x
parameter_list|)
value|((1<<0)<<(x))
end_define

begin_define
define|#
directive|define
name|POA_GE_SPEED
parameter_list|(
name|v
parameter_list|,
name|x
parameter_list|)
value|((((v)>>5)>>(((x)-5)*2))& 0x3)
end_define

begin_define
define|#
directive|define
name|POA_FE_XFC
parameter_list|(
name|x
parameter_list|)
value|((1<<16)<<(x))
end_define

begin_define
define|#
directive|define
name|POA_GE_XFC
parameter_list|(
name|v
parameter_list|,
name|x
parameter_list|)
value|((((v)>>21)>>(((x)-5)*2))& 0x3)
end_define

begin_define
define|#
directive|define
name|POA_PRT_LINK
parameter_list|(
name|x
parameter_list|)
value|((1<<25)<<(x))
end_define

begin_define
define|#
directive|define
name|POA_GE_XFC_TX_MSK
value|0x2
end_define

begin_define
define|#
directive|define
name|POA_GE_XFC_RX_MSK
value|0x1
end_define

begin_define
define|#
directive|define
name|POA_GE_SPEED_10
value|0x0
end_define

begin_define
define|#
directive|define
name|POA_GE_SPEED_100
value|0x1
end_define

begin_define
define|#
directive|define
name|POA_GE_SPEED_1000
value|0x2
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_FPA
value|0x0084
end_define

begin_define
define|#
directive|define
name|FPA_ALL_AUTO
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_POC2
value|0x0098
end_define

begin_define
define|#
directive|define
name|POC2_UNTAG_PORT
parameter_list|(
name|x
parameter_list|)
value|(1<< (x))
end_define

begin_define
define|#
directive|define
name|POC2_UNTAG_VLAN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_STRT
value|0x00a0
end_define

begin_define
define|#
directive|define
name|STRT_RESET
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_PCR0
value|0x00c0
end_define

begin_define
define|#
directive|define
name|PCR0_WRITE
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|PCR0_READ
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|PCR0_ACTIVE
value|(PCR0_WRITE | PCR0_READ)
end_define

begin_define
define|#
directive|define
name|PCR0_REG
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1f)<< 8)
end_define

begin_define
define|#
directive|define
name|PCR0_PHY
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1f)
end_define

begin_define
define|#
directive|define
name|PCR0_DATA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffff)<< 16)
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_PCR1
value|0x00c4
end_define

begin_define
define|#
directive|define
name|PCR1_DATA_OFF
value|16
end_define

begin_define
define|#
directive|define
name|PCR1_DATA_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_SGC2
value|0x00e4
end_define

begin_define
define|#
directive|define
name|SGC2_DOUBLE_TAG_PORT
parameter_list|(
name|x
parameter_list|)
value|(1<< (x))
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_VUB
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 2) * 4) + 0x100)
end_define

begin_define
define|#
directive|define
name|VUB_OFF
parameter_list|(
name|x
parameter_list|)
value|((x& 3) * 7)
end_define

begin_define
define|#
directive|define
name|VUB_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|MTKSWITCH_PORT_IS_100M
parameter_list|(
name|x
parameter_list|)
value|((x)< 5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MTKSWITCH_RT3050_H__ */
end_comment

end_unit

