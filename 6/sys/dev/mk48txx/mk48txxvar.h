begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Paul Kranenburg.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	from: NetBSD: mk48txxvar.h,v 1.1 2003/11/01 22:41:42 tsutsui Exp  *  * $FreeBSD$  */
end_comment

begin_typedef
typedef|typedef
name|uint8_t
function_decl|(
modifier|*
name|mk48txx_nvrd_t
function_decl|)
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|mk48txx_nvwr_t
function_decl|)
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|mk48txx_softc
block|{
name|bus_space_tag_t
name|sc_bst
decl_stmt|;
comment|/* bus space tag */
name|bus_space_handle_t
name|sc_bsh
decl_stmt|;
comment|/* bus space handle */
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* hardware mutex */
name|eventhandler_tag
name|sc_wet
decl_stmt|;
comment|/* watchdog event handler tag */
specifier|const
name|char
modifier|*
name|sc_model
decl_stmt|;
comment|/* chip model name */
name|bus_size_t
name|sc_nvramsz
decl_stmt|;
comment|/* Size of NVRAM on the chip */
name|bus_size_t
name|sc_clkoffset
decl_stmt|;
comment|/* Offset in NVRAM to clock bits */
name|u_int
name|sc_year0
decl_stmt|;
comment|/* year counter offset */
name|u_int
name|sc_flag
decl_stmt|;
comment|/* MD flags */
define|#
directive|define
name|MK48TXX_NO_CENT_ADJUST
value|0x0001
comment|/* don't manually adjust century */
define|#
directive|define
name|MK48TXX_WDOG_REGISTER
value|0x0002
comment|/* register watchdog */
define|#
directive|define
name|MK48TXX_WDOG_ENABLE_WDS
value|0x0004
comment|/* enable watchdog steering bit */
name|mk48txx_nvrd_t
name|sc_nvrd
decl_stmt|;
comment|/* NVRAM/RTC read function */
name|mk48txx_nvwr_t
name|sc_nvwr
decl_stmt|;
comment|/* NVRAM/RTC write function */
block|}
struct|;
end_struct

begin_comment
comment|/* Chip attach function */
end_comment

begin_function_decl
name|int
name|mk48txx_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Methods for the clock interface */
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

