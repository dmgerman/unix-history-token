begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|COM_IF_INTERNAL
value|0x00
end_define

begin_define
define|#
directive|define
name|COM_IF_PC9861K_1
value|0x01
end_define

begin_define
define|#
directive|define
name|COM_IF_PC9861K_2
value|0x02
end_define

begin_define
define|#
directive|define
name|COM_IF_IND_SS_1
value|0x03
end_define

begin_define
define|#
directive|define
name|COM_IF_IND_SS_2
value|0x04
end_define

begin_define
define|#
directive|define
name|COM_IF_PIO9032B_1
value|0x05
end_define

begin_define
define|#
directive|define
name|COM_IF_PIO9032B_2
value|0x06
end_define

begin_define
define|#
directive|define
name|COM_IF_B98_01_1
value|0x07
end_define

begin_define
define|#
directive|define
name|COM_IF_B98_01_2
value|0x08
end_define

begin_define
define|#
directive|define
name|COM_IF_END1
value|COM_IF_B98_01_2
end_define

begin_define
define|#
directive|define
name|COM_IF_RSA98
value|0x10
end_define

begin_comment
comment|/* same as COM_IF_NS16550 */
end_comment

begin_define
define|#
directive|define
name|COM_IF_NS16550
value|0x11
end_define

begin_define
define|#
directive|define
name|COM_IF_SECOND_CCU
value|0x12
end_define

begin_comment
comment|/* same as COM_IF_NS16550 */
end_comment

begin_define
define|#
directive|define
name|COM_IF_MC16550II
value|0x13
end_define

begin_define
define|#
directive|define
name|COM_IF_MCRS98
value|0x14
end_define

begin_comment
comment|/* same as COM_IF_MC16550II */
end_comment

begin_define
define|#
directive|define
name|COM_IF_RSB3000
value|0x15
end_define

begin_define
define|#
directive|define
name|COM_IF_RSB384
value|0x16
end_define

begin_define
define|#
directive|define
name|COM_IF_MODEM_CARD
value|0x17
end_define

begin_define
define|#
directive|define
name|COM_IF_RSA98III
value|0x18
end_define

begin_define
define|#
directive|define
name|COM_IF_ESP98
value|0x19
end_define

begin_define
define|#
directive|define
name|COM_IF_END2
value|COM_IF_ESP98
end_define

begin_define
define|#
directive|define
name|GET_IFTYPE
parameter_list|(
name|type
parameter_list|)
value|(((type)>> 24)& 0x1f)
end_define

begin_define
define|#
directive|define
name|SET_IFTYPE
parameter_list|(
name|type
parameter_list|)
value|((type)<< 24)
end_define

begin_define
define|#
directive|define
name|SET_FLAG
parameter_list|(
name|dev
parameter_list|,
name|bit
parameter_list|)
value|device_set_flags(dev, device_get_flags(dev) | (bit))
end_define

begin_define
define|#
directive|define
name|CLR_FLAG
parameter_list|(
name|dev
parameter_list|,
name|bit
parameter_list|)
value|device_set_flags(dev, device_get_flags(dev)& ~(bit))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PC98 */
end_comment

begin_function_decl
name|int
name|sioattach
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|xrid
parameter_list|,
name|u_long
name|rclk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|siodetach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sioprobe
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|xrid
parameter_list|,
name|u_long
name|rclk
parameter_list|,
name|int
name|noprobe
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|sio_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|sio_driver_name
index|[]
decl_stmt|;
end_decl_stmt

end_unit

