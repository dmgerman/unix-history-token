begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   Copyright (c) 1998 Martin Husemann. All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the distribution.  *   3. Neither the name of the author nor the names of any co-contributors  *      may be used to endorse or promote products derived from this software  *      without specific prior written permission.  *   4. Altered versions must be plainly marked as such, and must not be  *      misrepresented as being the original software and/or documentation.  *     *   THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  *   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *   ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  *   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *   OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *   OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *   SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	pcmcia_isic.h - common definitions for pcmcia isic cards  *	--------------------------------------------------------  *  * $FreeBSD$   *  *      last edit-date: [Sun Feb 14 10:29:33 1999]  *  *	-mh	original implementation  *  *---------------------------------------------------------------------------*/
end_comment

begin_struct
struct|struct
name|pcmcia_isic_softc
block|{
name|struct
name|isic_softc
name|sc_isic
decl_stmt|;
comment|/* parent class */
comment|/* PCMCIA-specific goo */
name|struct
name|pcmcia_io_handle
name|sc_pcioh
decl_stmt|;
comment|/* PCMCIA i/o space info */
name|int
name|sc_io_window
decl_stmt|;
comment|/* our i/o window */
name|struct
name|pcmcia_function
modifier|*
name|sc_pf
decl_stmt|;
comment|/* our PCMCIA function */
name|void
modifier|*
name|sc_ih
decl_stmt|;
comment|/* interrupt handler */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|isic_pcmcia_attach_func
function_decl|)
parameter_list|(
name|struct
name|pcmcia_isic_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|pcmcia_config_entry
modifier|*
name|cfe
parameter_list|,
name|struct
name|pcmcia_attach_args
modifier|*
name|pa
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|isic_attach_fritzpcmcia
parameter_list|(
name|struct
name|pcmcia_isic_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|pcmcia_config_entry
modifier|*
name|cfe
parameter_list|,
name|struct
name|pcmcia_attach_args
modifier|*
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_elsaisdnmc
parameter_list|(
name|struct
name|pcmcia_isic_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|pcmcia_config_entry
modifier|*
name|cfe
parameter_list|,
name|struct
name|pcmcia_attach_args
modifier|*
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_elsamcall
parameter_list|(
name|struct
name|pcmcia_isic_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|pcmcia_config_entry
modifier|*
name|cfe
parameter_list|,
name|struct
name|pcmcia_attach_args
modifier|*
name|pa
parameter_list|)
function_decl|;
end_function_decl

end_unit

