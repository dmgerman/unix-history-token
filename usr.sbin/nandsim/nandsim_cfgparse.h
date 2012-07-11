begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2009-2012 Semihalf  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NANDSIM_CONFPARSER_H_
end_ifndef

begin_define
define|#
directive|define
name|_NANDSIM_CONFPARSER_H_
end_define

begin_define
define|#
directive|define
name|VALUE_UINT
value|0x08
end_define

begin_define
define|#
directive|define
name|VALUE_INT
value|0x10
end_define

begin_define
define|#
directive|define
name|VALUE_UINTARRAY
value|0x18
end_define

begin_define
define|#
directive|define
name|VALUE_INTARRAY
value|0x20
end_define

begin_define
define|#
directive|define
name|VALUE_STRING
value|0x28
end_define

begin_define
define|#
directive|define
name|VALUE_CHAR
value|0x40
end_define

begin_define
define|#
directive|define
name|VALUE_BOOL
value|0x48
end_define

begin_define
define|#
directive|define
name|SIZE_8
value|0x01
end_define

begin_define
define|#
directive|define
name|SIZE_16
value|0x02
end_define

begin_define
define|#
directive|define
name|SIZE_32
value|0x04
end_define

begin_include
include|#
directive|include
file|"nandsim_rcfile.h"
end_include

begin_comment
comment|/*  * keyname	= name of a key,  * mandatory	= is key mandatory in section belonging to, 0=false 1=true  * valuetype	= what kind of value is assigned to that key, e.g.  *		  VALUE_UINT | SIZE_8 -- unsigned uint size 8 bits;  *		  VALUE_UINTARRAY | SIZE_8 -- array of uints 8-bit long;  *		  VALUE_BOOL -- 'on', 'off','true','false','yes' or 'no'  *		  literals;  *		  VALUE_STRING -- strings  * field	= ptr to the field that should hold value for parsed value  * maxlength	= contains maximum length of an array (used only with either  *		  VALUE_STRING or VALUE_(U)INTARRAY value types.  */
end_comment

begin_struct
struct|struct
name|nandsim_key
block|{
specifier|const
name|char
modifier|*
name|keyname
decl_stmt|;
name|uint8_t
name|mandatory
decl_stmt|;
name|uint8_t
name|valuetype
decl_stmt|;
name|void
modifier|*
name|field
decl_stmt|;
name|uint32_t
name|maxlength
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nandsim_section
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|nandsim_key
modifier|*
name|keys
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nandsim_config
block|{
name|struct
name|sim_param
modifier|*
modifier|*
name|simparams
decl_stmt|;
name|struct
name|sim_chip
modifier|*
modifier|*
name|simchips
decl_stmt|;
name|struct
name|sim_ctrl
modifier|*
modifier|*
name|simctrls
decl_stmt|;
name|int
name|chipcnt
decl_stmt|;
name|int
name|ctrlcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|parse_intarray
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_config
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_section
parameter_list|(
name|struct
name|rcfile
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|compare_configs
parameter_list|(
name|struct
name|nandsim_config
modifier|*
parameter_list|,
name|struct
name|nandsim_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|convert_argint
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|convert_arguint
parameter_list|(
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NANDSIM_CONFPARSER_H_ */
end_comment

end_unit

