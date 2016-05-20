begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Michael Zhilin<mizhka@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_SOC_BHND_SOC_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_SOC_BHND_SOC_H_
end_define

begin_define
define|#
directive|define
name|BHND_SOC_MAXNUM_CORES
value|0x20
end_define

begin_define
define|#
directive|define
name|BHND_SOC_RAM_OFFSET
value|0x0
end_define

begin_define
define|#
directive|define
name|BHND_SOC_RAM_SIZE
value|0x20000000
end_define

begin_struct
struct|struct
name|bhnd_soc_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|device_t
name|bridge
decl_stmt|;
name|device_t
name|bus
decl_stmt|;
name|struct
name|bhnd_chipid
name|chipid
decl_stmt|;
comment|/* chip identification */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bhnd_soc_devinfo
block|{
name|struct
name|resource_list
name|resources
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_SOC_BHND_SOC_H_ */
end_comment

end_unit

