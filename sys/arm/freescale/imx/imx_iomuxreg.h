begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Oleksandr Tymoshenko<gonzo@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IMX_IOMUXREG_H
end_ifndef

begin_define
define|#
directive|define
name|IMX_IOMUXREG_H
end_define

begin_define
define|#
directive|define
name|IMX_IOMUXREG_LOWEST_SET_BIT
parameter_list|(
name|__mask
parameter_list|)
value|((((__mask) - 1)& (__mask)) ^ (__mask))
end_define

begin_define
define|#
directive|define
name|IMX_IOMUXREG_SHIFTIN
parameter_list|(
name|__x
parameter_list|,
name|__mask
parameter_list|)
value|((__x) * IMX_IOMUXREG_LOWEST_SET_BIT(__mask))
end_define

begin_define
define|#
directive|define
name|IMX_IOMUXREG_BIT
parameter_list|(
name|n
parameter_list|)
value|(1<< (n))
end_define

begin_define
define|#
directive|define
name|IMX_IOMUXREG_BITS
parameter_list|(
name|__m
parameter_list|,
name|__n
parameter_list|)
define|\
value|((IMX_IOMUXREG_BIT(MAX((__m), (__n)) + 1) - 1) ^ (IMX_IOMUXREG_BIT(MIN((__m), (__n))) - 1))
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPR0
value|0x00
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPR1
value|0x04
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPR2
value|0x08
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPR3
value|0x0C
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPR3_HDMI_MASK
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPR3_HDMI_IPU1_DI0
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPR3_HDMI_IPU1_DI1
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPR3_HDMI_IPU2_DI0
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPR3_HDMI_IPU2_DI1
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|IOMUX_GPR13
value|0x34
end_define

begin_define
define|#
directive|define
name|IOMUX_GPR13_SATA_PHY_8
parameter_list|(
name|n
parameter_list|)
value|IMX_IOMUXREG_SHIFTIN(n, IMX_IOMUXREG_BITS(26, 24))
end_define

begin_define
define|#
directive|define
name|IOMUX_GPR13_SATA_PHY_7
parameter_list|(
name|n
parameter_list|)
value|IMX_IOMUXREG_SHIFTIN(n, IMX_IOMUXREG_BITS(23, 19))
end_define

begin_define
define|#
directive|define
name|IOMUX_GPR13_SATA_PHY_6
parameter_list|(
name|n
parameter_list|)
value|IMX_IOMUXREG_SHIFTIN(n, IMX_IOMUXREG_BITS(18, 16))
end_define

begin_define
define|#
directive|define
name|IOMUX_GPR13_SATA_SPEED
parameter_list|(
name|n
parameter_list|)
value|IMX_IOMUXREG_SHIFTIN(n, (1<< 15))
end_define

begin_define
define|#
directive|define
name|IOMUX_GPR13_SATA_PHY_5
parameter_list|(
name|n
parameter_list|)
value|IMX_IOMUXREG_SHIFTIN(n, (1<< 14))
end_define

begin_define
define|#
directive|define
name|IOMUX_GPR13_SATA_PHY_4
parameter_list|(
name|n
parameter_list|)
value|IMX_IOMUXREG_SHIFTIN(n, IMX_IOMUXREG_BITS(13, 11))
end_define

begin_define
define|#
directive|define
name|IOMUX_GPR13_SATA_PHY_3
parameter_list|(
name|n
parameter_list|)
value|IMX_IOMUXREG_SHIFTIN(n, IMX_IOMUXREG_BITS(10, 7))
end_define

begin_define
define|#
directive|define
name|IOMUX_GPR13_SATA_PHY_2
parameter_list|(
name|n
parameter_list|)
value|IMX_IOMUXREG_SHIFTIN(n, IMX_IOMUXREG_BITS(6, 2))
end_define

begin_define
define|#
directive|define
name|IOMUX_GPR13_SATA_PHY_1
parameter_list|(
name|n
parameter_list|)
value|IMX_IOMUXREG_SHIFTIN(n, (1<< 1))
end_define

begin_define
define|#
directive|define
name|IOMUX_GPR13_SATA_PHY_0
parameter_list|(
name|n
parameter_list|)
value|IMX_IOMUXREG_SHIFTIN(n, (1<< 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

