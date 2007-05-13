begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Cameron Grant<cg@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|AC97_MUTE
value|0x8080
end_define

begin_define
define|#
directive|define
name|AC97_REG_RESET
value|0x00
end_define

begin_define
define|#
directive|define
name|AC97_CAP_MICCHANNEL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AC97_CAP_TONE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AC97_CAP_SIMSTEREO
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AC97_CAP_HEADPHONE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AC97_CAP_LOUDNESS
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AC97_CAP_DAC_18
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AC97_CAP_DAC_20
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AC97_CAP_ADC_18
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AC97_CAP_ADC_20
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AC97_MIX_MASTER
value|0x02
end_define

begin_define
define|#
directive|define
name|AC97_MIX_AUXOUT
value|0x04
end_define

begin_define
define|#
directive|define
name|AC97_MIX_MONO
value|0x06
end_define

begin_define
define|#
directive|define
name|AC97_MIX_TONE
value|0x08
end_define

begin_define
define|#
directive|define
name|AC97_MIX_BEEP
value|0x0a
end_define

begin_define
define|#
directive|define
name|AC97_MIX_PHONE
value|0x0c
end_define

begin_define
define|#
directive|define
name|AC97_MIX_MIC
value|0x0e
end_define

begin_define
define|#
directive|define
name|AC97_MIX_LINE
value|0x10
end_define

begin_define
define|#
directive|define
name|AC97_MIX_CD
value|0x12
end_define

begin_define
define|#
directive|define
name|AC97_MIX_VIDEO
value|0x14
end_define

begin_define
define|#
directive|define
name|AC97_MIX_AUX
value|0x16
end_define

begin_define
define|#
directive|define
name|AC97_MIX_PCM
value|0x18
end_define

begin_define
define|#
directive|define
name|AC97_REG_RECSEL
value|0x1a
end_define

begin_define
define|#
directive|define
name|AC97_MIX_RGAIN
value|0x1c
end_define

begin_define
define|#
directive|define
name|AC97_MIX_MGAIN
value|0x1e
end_define

begin_define
define|#
directive|define
name|AC97_REG_GEN
value|0x20
end_define

begin_define
define|#
directive|define
name|AC97_REG_3D
value|0x22
end_define

begin_define
define|#
directive|define
name|AC97_REG_POWER
value|0x26
end_define

begin_define
define|#
directive|define
name|AC97_POWER_ADC
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AC97_POWER_DAC
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AC97_POWER_ANL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AC97_POWER_REF
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AC97_POWER_STATUS
value|(AC97_POWER_ADC | AC97_POWER_DAC | \ 					 AC97_POWER_REF | AC97_POWER_ANL )
end_define

begin_define
define|#
directive|define
name|AC97_REGEXT_ID
value|0x28
end_define

begin_define
define|#
directive|define
name|AC97_EXTCAP_VRA
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AC97_EXTCAP_DRA
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AC97_EXTCAP_VRM
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AC97_EXTCAPS
value|(AC97_EXTCAP_VRA | AC97_EXTCAP_DRA | AC97_EXTCAP_VRM)
end_define

begin_define
define|#
directive|define
name|AC97_EXTCAP_SDAC
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AC97_REGEXT_STAT
value|0x2a
end_define

begin_define
define|#
directive|define
name|AC97_REGEXT_FDACRATE
value|0x2c
end_define

begin_define
define|#
directive|define
name|AC97_REGEXT_SDACRATE
value|0x2e
end_define

begin_define
define|#
directive|define
name|AC97_REGEXT_LDACRATE
value|0x30
end_define

begin_define
define|#
directive|define
name|AC97_REGEXT_LADCRATE
value|0x32
end_define

begin_define
define|#
directive|define
name|AC97_REGEXT_MADCRATE
value|0x34
end_define

begin_define
define|#
directive|define
name|AC97_MIXEXT_CLFE
value|0x36
end_define

begin_define
define|#
directive|define
name|AC97_MIXEXT_SURROUND
value|0x38
end_define

begin_define
define|#
directive|define
name|AC97_REG_ID1
value|0x7c
end_define

begin_define
define|#
directive|define
name|AC97_REG_ID2
value|0x7e
end_define

begin_define
define|#
directive|define
name|AC97_F_EAPD_INV
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AC97_F_RDCD_BUG
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AC97_DECLARE
parameter_list|(
name|name
parameter_list|)
value|static DEFINE_CLASS(name, name ## _methods, sizeof(struct kobj))
end_define

begin_define
define|#
directive|define
name|AC97_CREATE
parameter_list|(
name|dev
parameter_list|,
name|devinfo
parameter_list|,
name|cls
parameter_list|)
value|ac97_create(dev, devinfo,&cls ## _class)
end_define

begin_struct_decl
struct_decl|struct
name|ac97_info
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|"ac97_if.h"
end_include

begin_function_decl
specifier|extern
name|kobj_class_t
name|ac97_getmixerclass
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ac97_info
modifier|*
name|ac97_create
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|devinfo
parameter_list|,
name|kobj_class_t
name|cls
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ac97_destroy
parameter_list|(
name|struct
name|ac97_info
modifier|*
name|codec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ac97_setflags
parameter_list|(
name|struct
name|ac97_info
modifier|*
name|codec
parameter_list|,
name|u_int32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|ac97_getflags
parameter_list|(
name|struct
name|ac97_info
modifier|*
name|codec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ac97_setrate
parameter_list|(
name|struct
name|ac97_info
modifier|*
name|codec
parameter_list|,
name|int
name|which
parameter_list|,
name|int
name|rate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ac97_setextmode
parameter_list|(
name|struct
name|ac97_info
modifier|*
name|codec
parameter_list|,
name|u_int16_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|ac97_getextmode
parameter_list|(
name|struct
name|ac97_info
modifier|*
name|codec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|ac97_getextcaps
parameter_list|(
name|struct
name|ac97_info
modifier|*
name|codec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|ac97_getcaps
parameter_list|(
name|struct
name|ac97_info
modifier|*
name|codec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|ac97_getsubvendor
parameter_list|(
name|struct
name|ac97_info
modifier|*
name|codec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|ac97_rdcd
parameter_list|(
name|struct
name|ac97_info
modifier|*
name|codec
parameter_list|,
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ac97_wrcd
parameter_list|(
name|struct
name|ac97_info
modifier|*
name|codec
parameter_list|,
name|int
name|reg
parameter_list|,
name|u_int16_t
name|val
parameter_list|)
function_decl|;
end_function_decl

end_unit

