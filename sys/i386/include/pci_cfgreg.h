begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, Stefan Esser<se@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_define
define|#
directive|define
name|CONF1_ADDR_PORT
value|0x0cf8
end_define

begin_define
define|#
directive|define
name|CONF1_DATA_PORT
value|0x0cfc
end_define

begin_define
define|#
directive|define
name|CONF1_ENABLE
value|0x80000000ul
end_define

begin_define
define|#
directive|define
name|CONF1_ENABLE_CHK
value|0x80000000ul
end_define

begin_define
define|#
directive|define
name|CONF1_ENABLE_MSK
value|0x7ff00000ul
end_define

begin_define
define|#
directive|define
name|CONF1_ENABLE_CHK1
value|0xff000001ul
end_define

begin_define
define|#
directive|define
name|CONF1_ENABLE_MSK1
value|0x80000001ul
end_define

begin_define
define|#
directive|define
name|CONF1_ENABLE_RES1
value|0x80000000ul
end_define

begin_define
define|#
directive|define
name|CONF2_ENABLE_PORT
value|0x0cf8
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|CONF2_FORWARD_PORT
value|0x0cf9
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CONF2_FORWARD_PORT
value|0x0cfa
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CONF2_ENABLE_CHK
value|0x0e
end_define

begin_define
define|#
directive|define
name|CONF2_ENABLE_RES
value|0x0e
end_define

begin_function_decl
specifier|extern
name|int
name|pci_cfgregopen
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32_t
name|pci_cfgregread
parameter_list|(
name|int
name|bus
parameter_list|,
name|int
name|slot
parameter_list|,
name|int
name|func
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pci_cfgregwrite
parameter_list|(
name|int
name|bus
parameter_list|,
name|int
name|slot
parameter_list|,
name|int
name|func
parameter_list|,
name|int
name|reg
parameter_list|,
name|u_int32_t
name|data
parameter_list|,
name|int
name|bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pci_cfgintr
parameter_list|(
name|int
name|bus
parameter_list|,
name|int
name|device
parameter_list|,
name|int
name|pin
parameter_list|)
function_decl|;
end_function_decl

end_unit

