begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Marius Strobl<marius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_MCNTL_H
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_MCNTL_H
end_define

begin_comment
comment|/*  * Definitions for the SPARC64 V, VI, VII and VIIIfx Memory Control Register  */
end_comment

begin_define
define|#
directive|define
name|MCNTL_JPS1_TSBP
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|MCNTL_RMD_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MCNTL_RMD_BITS
value|2
end_define

begin_define
define|#
directive|define
name|MCNTL_RMD_MASK
define|\
value|(((1UL<< MCNTL_RMD_BITS) - 1)<< MCNTL_RMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|MCNTL_RMD_FULL
value|(0UL<< MCNTL_RMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|MCNTL_RMD_1024
value|(2UL<< MCNTL_RMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|MCNTL_RMD_512
value|(3UL<< MCNTL_RMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|MCNTL_FW_FDTLB
value|(1UL<< 14)
end_define

begin_define
define|#
directive|define
name|MCNTL_FW_FITLB
value|(1UL<< 15)
end_define

begin_define
define|#
directive|define
name|MCNTL_NC_CACHE
value|(1UL<< 16)
end_define

begin_comment
comment|/* The following bits are valid for the SPARC64 VI, VII and VIIIfx only. */
end_comment

begin_define
define|#
directive|define
name|MCNTL_MPG_SDTLB
value|(1UL<< 6)
end_define

begin_define
define|#
directive|define
name|MCNTL_MPG_SITLB
value|(1UL<< 7)
end_define

begin_comment
comment|/* The following bits are valid for the SPARC64 VIIIfx only. */
end_comment

begin_define
define|#
directive|define
name|MCNTL_HPF_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|MCNTL_HPF_BITS
value|2
end_define

begin_define
define|#
directive|define
name|MCNTL_HPF_MASK
define|\
value|(((1UL<< MCNTL_HPF_BITS) - 1)<< MCNTL_HPF_SHIFT)
end_define

begin_define
define|#
directive|define
name|MCNTL_HPF_STRONG
value|(0UL<< MCNTL_HPF_SHIFT)
end_define

begin_define
define|#
directive|define
name|MCNTL_HPF_NOT
value|(1UL<< MCNTL_HPF_SHIFT)
end_define

begin_define
define|#
directive|define
name|MCNTL_HPF_WEAK
value|(2UL<< MCNTL_HPF_SHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_MCNTL_H */
end_comment

end_unit

