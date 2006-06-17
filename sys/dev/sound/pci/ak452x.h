begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Katsurajima Naoto<raven@katsurajima.seya.yokohama.jp>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHERIN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THEPOSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* supported CODECs */
end_comment

begin_define
define|#
directive|define
name|AK452X_TYPE_4524
value|0
end_define

begin_define
define|#
directive|define
name|AK452X_TYPE_4528
value|1
end_define

begin_comment
comment|/* AK4524/AK4528 control registers */
end_comment

begin_define
define|#
directive|define
name|AK4524_POWER
value|0x00
end_define

begin_define
define|#
directive|define
name|AK4528_POWER
value|0x00
end_define

begin_define
define|#
directive|define
name|AK452X_POWER_PWDA
value|0x01
end_define

begin_define
define|#
directive|define
name|AK452X_POWER_PWAD
value|0x02
end_define

begin_define
define|#
directive|define
name|AK452X_POWER_PWVR
value|0x04
end_define

begin_define
define|#
directive|define
name|AK4524_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|AK4528_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|AK452X_RESET_RSDA
value|0x01
end_define

begin_define
define|#
directive|define
name|AK452X_RESET_RSAD
value|0x02
end_define

begin_define
define|#
directive|define
name|AK4524_FORMAT
value|0x02
end_define

begin_define
define|#
directive|define
name|AK4528_FORMAT
value|0x02
end_define

begin_define
define|#
directive|define
name|AK452X_FORMAT_1X
value|0x00
end_define

begin_define
define|#
directive|define
name|AK452X_FORMAT_2X
value|0x01
end_define

begin_define
define|#
directive|define
name|AK452X_FORMAT_4X1
value|0x02
end_define

begin_define
define|#
directive|define
name|AK452X_FORMAT_4X2
value|0x03
end_define

begin_define
define|#
directive|define
name|AK452X_FORMAT_256FSN
value|0x00
end_define

begin_define
define|#
directive|define
name|AK452X_FORMAT_512FSN
value|0x04
end_define

begin_define
define|#
directive|define
name|AK452X_FORMAT_1024FSN
value|0x08
end_define

begin_define
define|#
directive|define
name|AK452X_FORMAT_384FSN
value|0x10
end_define

begin_define
define|#
directive|define
name|AK452X_FORMAT_768FSN
value|0x14
end_define

begin_define
define|#
directive|define
name|AK452X_FORMAT_OM24IL16
value|0x00
end_define

begin_define
define|#
directive|define
name|AK452X_FORMAT_OM24IL20
value|0x20
end_define

begin_define
define|#
directive|define
name|AK452X_FORMAT_OM24IM24
value|0x40
end_define

begin_define
define|#
directive|define
name|AK452X_FORMAT_I2S
value|0x60
end_define

begin_define
define|#
directive|define
name|AK452X_FORMAT_OM24IL24
value|0x80
end_define

begin_define
define|#
directive|define
name|AK4524_DVC
value|0x03
end_define

begin_define
define|#
directive|define
name|AK452X_DVC_DEM441
value|0x00
end_define

begin_define
define|#
directive|define
name|AK452X_DVC_DEMOFF
value|0x01
end_define

begin_define
define|#
directive|define
name|AK452X_DVC_DEM48
value|0x02
end_define

begin_define
define|#
directive|define
name|AK452X_DVC_DEM32
value|0x03
end_define

begin_define
define|#
directive|define
name|AK452X_DVC_ZTM256
value|0x00
end_define

begin_define
define|#
directive|define
name|AK452X_DVC_ZTM512
value|0x04
end_define

begin_define
define|#
directive|define
name|AK452X_DVC_ZTM1024
value|0x08
end_define

begin_define
define|#
directive|define
name|AK452X_DVC_ZTM2048
value|0x0c
end_define

begin_define
define|#
directive|define
name|AK452X_DVC_ZCE
value|0x10
end_define

begin_define
define|#
directive|define
name|AK452X_DVC_HPFL
value|0x04
end_define

begin_define
define|#
directive|define
name|AK452X_DVC_HPFR
value|0x08
end_define

begin_define
define|#
directive|define
name|AK452X_DVC_SMUTE
value|0x80
end_define

begin_define
define|#
directive|define
name|AK4524_LIPGA
value|0x04
end_define

begin_define
define|#
directive|define
name|AK4524_RIPGA
value|0x05
end_define

begin_define
define|#
directive|define
name|AK4524_LOATT
value|0x06
end_define

begin_define
define|#
directive|define
name|AK4524_ROATT
value|0x07
end_define

begin_define
define|#
directive|define
name|AK4528_LOATT
value|0x04
end_define

begin_define
define|#
directive|define
name|AK4528_ROATT
value|0x05
end_define

begin_struct_decl
struct_decl|struct
name|ak452x_info
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ak452x_ctrl
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|struct
name|ak452x_info
modifier|*
name|ak452x_create
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|devinfo
parameter_list|,
name|int
name|num
parameter_list|,
name|ak452x_ctrl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ak452x_destroy
parameter_list|(
name|struct
name|ak452x_info
modifier|*
name|codec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ak452x_settype
parameter_list|(
name|struct
name|ak452x_info
modifier|*
name|codec
parameter_list|,
name|unsigned
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ak452x_setcif
parameter_list|(
name|struct
name|ak452x_info
modifier|*
name|codec
parameter_list|,
name|unsigned
name|int
name|cif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ak452x_setformat
parameter_list|(
name|struct
name|ak452x_info
modifier|*
name|codec
parameter_list|,
name|unsigned
name|int
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ak452x_setdvc
parameter_list|(
name|struct
name|ak452x_info
modifier|*
name|codec
parameter_list|,
name|unsigned
name|int
name|dvc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ak452x_init
parameter_list|(
name|struct
name|ak452x_info
modifier|*
name|codec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ak452x_reinit
parameter_list|(
name|struct
name|ak452x_info
modifier|*
name|codec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ak452x_set
parameter_list|(
name|struct
name|ak452x_info
modifier|*
name|codec
parameter_list|,
name|int
name|dir
parameter_list|,
name|unsigned
name|int
name|left
parameter_list|,
name|unsigned
name|int
name|right
parameter_list|)
function_decl|;
end_function_decl

end_unit

