begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Gary Jennejohn. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------  *  *      i4b_ifpi2 - Fritz!Card PCI Version 2 for split layers  *      ------------------------------------------  *  *	$Id$  *  * $FreeBSD$  *  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_IFPI2_EXT_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_IFPI2_EXT_H_
end_define

begin_include
include|#
directive|include
file|<i4b/include/i4b_l3l4.h>
end_include

begin_function_decl
name|void
name|ifpi2_set_linktab
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|drvr_link_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isdn_link_t
modifier|*
name|ifpi2_ret_linktab
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifpi2_ph_data_req
parameter_list|(
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifpi2_ph_activate_req
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifpi2_mph_command_req
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifpi2_isacsx_irq
parameter_list|(
name|struct
name|l1_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifpi2_isacsx_l1_cmd
parameter_list|(
name|struct
name|l1_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifpi2_isacsx_init
parameter_list|(
name|struct
name|l1_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifpi2_recover
parameter_list|(
name|struct
name|l1_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ifpi2_printstate
parameter_list|(
name|struct
name|l1_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifpi2_next_state
parameter_list|(
name|struct
name|l1_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IFPI2_MAXUNIT
value|4
end_define

begin_decl_stmt
specifier|extern
name|struct
name|l1_softc
modifier|*
name|ifpi2_scp
index|[
name|IFPI2_MAXUNIT
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the ISACSX has 2 mask registers of interest - cannot use ISAC_IMASK */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|isacsx_imaskd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|isacsx_imask
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_IFPI2_EXT_H_ */
end_comment

end_unit

