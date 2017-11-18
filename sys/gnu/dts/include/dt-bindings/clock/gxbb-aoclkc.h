begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright (c) 2016 BayLibre, SAS.  * Author: Neil Armstrong<narmstrong@baylibre.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, see<http://www.gnu.org/licenses/>.  * The full GNU General Public License is included in this distribution  * in the file called COPYING.  *  * BSD LICENSE  *  * Copyright (c) 2016 BayLibre, SAS.  * Author: Neil Armstrong<narmstrong@baylibre.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *   * Neither the name of Intel Corporation nor the names of its  *     contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DT_BINDINGS_CLOCK_AMLOGIC_MESON_GXBB_AOCLK
end_ifndef

begin_define
define|#
directive|define
name|DT_BINDINGS_CLOCK_AMLOGIC_MESON_GXBB_AOCLK
end_define

begin_define
define|#
directive|define
name|CLKID_AO_REMOTE
value|0
end_define

begin_define
define|#
directive|define
name|CLKID_AO_I2C_MASTER
value|1
end_define

begin_define
define|#
directive|define
name|CLKID_AO_I2C_SLAVE
value|2
end_define

begin_define
define|#
directive|define
name|CLKID_AO_UART1
value|3
end_define

begin_define
define|#
directive|define
name|CLKID_AO_UART2
value|4
end_define

begin_define
define|#
directive|define
name|CLKID_AO_IR_BLASTER
value|5
end_define

begin_define
define|#
directive|define
name|CLKID_AO_CEC_32K
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

