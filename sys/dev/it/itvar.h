begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: itvar.h,v 1.4 2007/03/22 16:55:31 deraadt Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2003 Julien Bordet<zejames@greyhats.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ISA_ITVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ISA_ITVAR_H
end_define

begin_define
define|#
directive|define
name|IT_NUM_SENSORS
value|15
end_define

begin_comment
comment|/* chip ids */
end_comment

begin_define
define|#
directive|define
name|IT_ID_IT87
value|0x90
end_define

begin_comment
comment|/* ctl registers */
end_comment

begin_define
define|#
directive|define
name|ITC_ADDR
value|0x05
end_define

begin_define
define|#
directive|define
name|ITC_DATA
value|0x06
end_define

begin_comment
comment|/* data registers */
end_comment

begin_define
define|#
directive|define
name|ITD_CONFIG
value|0x00
end_define

begin_define
define|#
directive|define
name|ITD_ISR1
value|0x01
end_define

begin_define
define|#
directive|define
name|ITD_ISR2
value|0x02
end_define

begin_define
define|#
directive|define
name|ITD_ISR3
value|0x03
end_define

begin_define
define|#
directive|define
name|ITD_SMI1
value|0x04
end_define

begin_define
define|#
directive|define
name|ITD_SMI2
value|0x05
end_define

begin_define
define|#
directive|define
name|ITD_SMI3
value|0x06
end_define

begin_define
define|#
directive|define
name|ITD_IMR1
value|0x07
end_define

begin_define
define|#
directive|define
name|ITD_IMR2
value|0x08
end_define

begin_define
define|#
directive|define
name|ITD_IMR3
value|0x09
end_define

begin_define
define|#
directive|define
name|ITD_VID
value|0x0a
end_define

begin_define
define|#
directive|define
name|ITD_FAN
value|0x0b
end_define

begin_define
define|#
directive|define
name|ITD_FANMINBASE
value|0x10
end_define

begin_define
define|#
directive|define
name|ITD_FANENABLE
value|0x13
end_define

begin_define
define|#
directive|define
name|ITD_SENSORFANBASE
value|0x0d
end_define

begin_comment
comment|/* Fan from 0x0d to 0x0f */
end_comment

begin_define
define|#
directive|define
name|ITD_SENSORVOLTBASE
value|0x20
end_define

begin_comment
comment|/* Fan from 0x20 to 0x28 */
end_comment

begin_define
define|#
directive|define
name|ITD_SENSORTEMPBASE
value|0x29
end_define

begin_comment
comment|/* Fan from 0x29 to 0x2b */
end_comment

begin_define
define|#
directive|define
name|ITD_VOLTMAXBASE
value|0x30
end_define

begin_define
define|#
directive|define
name|ITD_VOLTMINBASE
value|0x31
end_define

begin_define
define|#
directive|define
name|ITD_TEMPMAXBASE
value|0x40
end_define

begin_define
define|#
directive|define
name|ITD_TEMPMINBASE
value|0x41
end_define

begin_define
define|#
directive|define
name|ITD_SBUSADDR
value|0x48
end_define

begin_define
define|#
directive|define
name|ITD_VOLTENABLE
value|0x50
end_define

begin_define
define|#
directive|define
name|ITD_TEMPENABLE
value|0x51
end_define

begin_define
define|#
directive|define
name|ITD_CHIPID
value|0x58
end_define

begin_define
define|#
directive|define
name|IT_VREF
value|(4096)
end_define

begin_comment
comment|/* Vref = 4.096 V */
end_comment

begin_struct
struct|struct
name|it_softc
block|{
name|struct
name|device
modifier|*
name|sc_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_iores
decl_stmt|;
name|int
name|sc_iorid
decl_stmt|;
name|bus_space_tag_t
name|sc_iot
decl_stmt|;
name|bus_space_handle_t
name|sc_ioh
decl_stmt|;
name|struct
name|ksensor
name|sensors
index|[
name|IT_NUM_SENSORS
index|]
decl_stmt|;
name|struct
name|ksensordev
name|sensordev
decl_stmt|;
name|u_int
name|numsensors
decl_stmt|;
name|void
function_decl|(
modifier|*
name|refresh_sensor_data
function_decl|)
parameter_list|(
name|struct
name|it_softc
modifier|*
parameter_list|)
function_decl|;
name|u_int8_t
function_decl|(
modifier|*
name|it_readreg
function_decl|)
parameter_list|(
name|struct
name|it_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|it_writereg
function_decl|)
parameter_list|(
name|struct
name|it_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

