begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Paul Kranenburg.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: mk48txxreg.h,v 1.4 2000/11/11 11:59:42 pk Exp $  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Mostek MK48Txx clocks.  *  * The MK48T02 has 2KB of non-volatile memory. The time-of-day clock  * registers start at offset 0x7f8.  *  * The MK48T08 has 8KB of non-volatile memory  *  * The MK48T59 also has 8KB of non-volatile memory but in addition it  * has a battery low detection bit and a power supply wakeup alarm for  * power management.  It's at offset 0x1ff0 in the NVRAM.  */
end_comment

begin_comment
comment|/*  * Mostek MK48TXX register definitions  */
end_comment

begin_comment
comment|/*  * The first bank of eight registers at offset (nvramsz - 16) is  * available only on recenter (which?) MK48Txx models.  */
end_comment

begin_define
define|#
directive|define
name|MK48TXX_X0
value|0
end_define

begin_comment
comment|/* find out later */
end_comment

begin_comment
comment|/* ... */
end_comment

begin_define
define|#
directive|define
name|MK48TXX_X7
value|7
end_define

begin_comment
comment|/* find out later */
end_comment

begin_define
define|#
directive|define
name|MK48TXX_ICSR
value|8
end_define

begin_comment
comment|/* control register */
end_comment

begin_define
define|#
directive|define
name|MK48TXX_ISEC
value|9
end_define

begin_comment
comment|/* seconds (0..59; BCD) */
end_comment

begin_define
define|#
directive|define
name|MK48TXX_IMIN
value|10
end_define

begin_comment
comment|/* minutes (0..59; BCD) */
end_comment

begin_define
define|#
directive|define
name|MK48TXX_IHOUR
value|11
end_define

begin_comment
comment|/* hour (0..23; BCD) */
end_comment

begin_define
define|#
directive|define
name|MK48TXX_IWDAY
value|12
end_define

begin_comment
comment|/* weekday (1..7) */
end_comment

begin_define
define|#
directive|define
name|MK48TXX_IDAY
value|13
end_define

begin_comment
comment|/* day in month (1..31; BCD) */
end_comment

begin_define
define|#
directive|define
name|MK48TXX_IMON
value|14
end_define

begin_comment
comment|/* month (1..12; BCD) */
end_comment

begin_define
define|#
directive|define
name|MK48TXX_IYEAR
value|15
end_define

begin_comment
comment|/* year (0..99; BCD) */
end_comment

begin_comment
comment|/* Bits in the control register */
end_comment

begin_define
define|#
directive|define
name|MK48TXX_CSR_WRITE
value|0x80
end_define

begin_comment
comment|/* want to write */
end_comment

begin_define
define|#
directive|define
name|MK48TXX_CSR_READ
value|0x40
end_define

begin_comment
comment|/* want to read (freeze clock) */
end_comment

begin_define
define|#
directive|define
name|MK48T02_CLKSZ
value|2048
end_define

begin_define
define|#
directive|define
name|MK48T02_CLKOFF
value|0x7f0
end_define

begin_define
define|#
directive|define
name|MK48T08_CLKSZ
value|8192
end_define

begin_define
define|#
directive|define
name|MK48T08_CLKOFF
value|0x1ff0
end_define

begin_define
define|#
directive|define
name|MK48T59_CLKSZ
value|8192
end_define

begin_define
define|#
directive|define
name|MK48T59_CLKOFF
value|0x1ff0
end_define

begin_comment
comment|/* Chip attach function */
end_comment

begin_function_decl
name|int
name|mk48txx_attach
parameter_list|(
name|device_t
parameter_list|,
name|bus_space_tag_t
parameter_list|,
name|bus_space_handle_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Retrieve size of the on-chip NVRAM area */
end_comment

begin_function_decl
name|int
name|mk48txx_get_nvram_size
parameter_list|(
name|device_t
parameter_list|,
name|bus_size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Methods for the clock interface. */
end_comment

begin_function_decl
name|int
name|mk48txx_gettime
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mk48txx_settime
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

