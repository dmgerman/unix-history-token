begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Chelsio Communications, Inc.  * All rights reserved.  * Written by: Navdeep Parhar<np@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CXGBE_OSDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|__CXGBE_OSDEP_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_define
define|#
directive|define
name|CH_ERR
parameter_list|(
name|adap
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|log(LOG_ERR, fmt, ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|CH_WARN
parameter_list|(
name|adap
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|log(LOG_WARNING, fmt, ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|CH_ALERT
parameter_list|(
name|adap
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|log(LOG_ALERT, fmt, ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|CH_WARN_RATELIMIT
parameter_list|(
name|adap
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|log(LOG_WARNING, fmt, ##__VA_ARGS__)
end_define

begin_typedef
typedef|typedef
name|int8_t
name|s8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int16_t
name|s16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|s32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|s64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|u64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|__u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|__u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|__u64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|__be8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|__be16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__be32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|__be64
typedef|;
end_typedef

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|__BIG_ENDIAN_BITFIELD
end_define

begin_define
define|#
directive|define
name|htobe32_const
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_elif
elif|#
directive|elif
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_elif

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN_BITFIELD
end_define

begin_define
define|#
directive|define
name|htobe32_const
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24) | (((x)>> 8)& 0xff00) |	\     ((((x)& 0xffffff)<< 8)& 0xff0000) | ((((x)& 0xff)<< 24)& 0xff000000))
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Must set BYTE_ORDER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__bool_true_false_are_defined
end_ifndef

begin_typedef
typedef|typedef
name|boolean_t
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|false
value|FALSE
end_define

begin_define
define|#
directive|define
name|true
value|TRUE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|mdelay
parameter_list|(
name|x
parameter_list|)
value|DELAY((x) * 1000)
end_define

begin_define
define|#
directive|define
name|udelay
parameter_list|(
name|x
parameter_list|)
value|DELAY(x)
end_define

begin_define
define|#
directive|define
name|__devinit
end_define

begin_define
define|#
directive|define
name|simple_strtoul
value|strtoul
end_define

begin_define
define|#
directive|define
name|DIV_ROUND_UP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|howmany(x, y)
end_define

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|x
parameter_list|)
value|nitems(x)
end_define

begin_define
define|#
directive|define
name|container_of
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
value|((s *)(((uint8_t *)(p)) - offsetof(s, f)))
end_define

begin_define
define|#
directive|define
name|swab16
parameter_list|(
name|x
parameter_list|)
value|bswap16(x)
end_define

begin_define
define|#
directive|define
name|swab32
parameter_list|(
name|x
parameter_list|)
value|bswap32(x)
end_define

begin_define
define|#
directive|define
name|swab64
parameter_list|(
name|x
parameter_list|)
value|bswap64(x)
end_define

begin_define
define|#
directive|define
name|le16_to_cpu
parameter_list|(
name|x
parameter_list|)
value|le16toh(x)
end_define

begin_define
define|#
directive|define
name|le32_to_cpu
parameter_list|(
name|x
parameter_list|)
value|le32toh(x)
end_define

begin_define
define|#
directive|define
name|le64_to_cpu
parameter_list|(
name|x
parameter_list|)
value|le64toh(x)
end_define

begin_define
define|#
directive|define
name|cpu_to_le16
parameter_list|(
name|x
parameter_list|)
value|htole16(x)
end_define

begin_define
define|#
directive|define
name|cpu_to_le32
parameter_list|(
name|x
parameter_list|)
value|htole32(x)
end_define

begin_define
define|#
directive|define
name|cpu_to_le64
parameter_list|(
name|x
parameter_list|)
value|htole64(x)
end_define

begin_define
define|#
directive|define
name|be16_to_cpu
parameter_list|(
name|x
parameter_list|)
value|be16toh(x)
end_define

begin_define
define|#
directive|define
name|be32_to_cpu
parameter_list|(
name|x
parameter_list|)
value|be32toh(x)
end_define

begin_define
define|#
directive|define
name|be64_to_cpu
parameter_list|(
name|x
parameter_list|)
value|be64toh(x)
end_define

begin_define
define|#
directive|define
name|cpu_to_be16
parameter_list|(
name|x
parameter_list|)
value|htobe16(x)
end_define

begin_define
define|#
directive|define
name|cpu_to_be32
parameter_list|(
name|x
parameter_list|)
value|htobe32(x)
end_define

begin_define
define|#
directive|define
name|cpu_to_be64
parameter_list|(
name|x
parameter_list|)
value|htobe64(x)
end_define

begin_define
define|#
directive|define
name|SPEED_10
value|10
end_define

begin_define
define|#
directive|define
name|SPEED_100
value|100
end_define

begin_define
define|#
directive|define
name|SPEED_1000
value|1000
end_define

begin_define
define|#
directive|define
name|SPEED_10000
value|10000
end_define

begin_define
define|#
directive|define
name|SPEED_40000
value|40000
end_define

begin_define
define|#
directive|define
name|DUPLEX_HALF
value|0
end_define

begin_define
define|#
directive|define
name|DUPLEX_FULL
value|1
end_define

begin_define
define|#
directive|define
name|AUTONEG_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|AUTONEG_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID
value|PCIR_DEVICE
end_define

begin_define
define|#
directive|define
name|PCI_CAP_ID_VPD
value|PCIY_VPD
end_define

begin_define
define|#
directive|define
name|PCI_VPD_ADDR
value|PCIR_VPD_ADDR
end_define

begin_define
define|#
directive|define
name|PCI_VPD_ADDR_F
value|0x8000
end_define

begin_define
define|#
directive|define
name|PCI_VPD_DATA
value|PCIR_VPD_DATA
end_define

begin_define
define|#
directive|define
name|PCI_CAP_ID_EXP
value|PCIY_EXPRESS
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL
value|PCIER_DEVICE_CTL
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_PAYLOAD
value|PCIEM_CTL_MAX_PAYLOAD
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_READRQ
value|PCIEM_CTL_MAX_READ_REQUEST
end_define

begin_define
define|#
directive|define
name|PCI_EXP_LNKCTL
value|PCIER_LINK_CTL
end_define

begin_define
define|#
directive|define
name|PCI_EXP_LNKSTA
value|PCIER_LINK_STA
end_define

begin_define
define|#
directive|define
name|PCI_EXP_LNKSTA_CLS
value|PCIEM_LINK_STA_SPEED
end_define

begin_define
define|#
directive|define
name|PCI_EXP_LNKSTA_NLW
value|PCIEM_LINK_STA_WIDTH
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL2
value|PCIER_DEVICE_CTL2
end_define

begin_function
specifier|static
specifier|inline
name|int
name|ilog2
parameter_list|(
name|long
name|x
parameter_list|)
block|{
name|KASSERT
argument_list|(
name|x
operator|>
literal|0
operator|&&
name|powerof2
argument_list|(
name|x
argument_list|)
argument_list|,
operator|(
literal|"%s: invalid arg %ld"
operator|,
name|__func__
operator|,
name|x
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|flsl
argument_list|(
name|x
argument_list|)
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|char
modifier|*
name|strstrip
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
block|{
name|char
name|c
decl_stmt|,
modifier|*
name|r
decl_stmt|,
modifier|*
name|trim_at
decl_stmt|;
while|while
condition|(
name|isspace
argument_list|(
operator|*
name|s
argument_list|)
condition|)
name|s
operator|++
expr_stmt|;
name|r
operator|=
name|trim_at
operator|=
name|s
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|s
operator|++
operator|)
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
operator|!
name|isspace
argument_list|(
name|c
argument_list|)
condition|)
name|trim_at
operator|=
name|s
expr_stmt|;
block|}
operator|*
name|trim_at
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|r
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

