begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   Copyright (c) 1998 Martin Husemann. All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the distribution.  *   3. Neither the name of the author nor the names of any co-contributors  *      may be used to endorse or promote products derived from this software  *      without specific prior written permission.  *   4. Altered versions must be plainly marked as such, and must not be  *      misrepresented as being the original software and/or documentation.  *     *   THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  *   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *   ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  *   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *   OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *   OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *   SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	ELSA MicroLink MC/all card specific routines  *	--------------------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Sun Feb 14 10:26:29 1999]  *  *	-mh	started support for ELSA MC/all  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|"isic.h"
end_include

begin_include
include|#
directive|include
file|"opt_i4b.h"
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NISIC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NISIC
operator|>
literal|0
operator|&&
name|defined
argument_list|(
name|ELSA_MCALL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD__
operator|>=
literal|3
end_if

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/device.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<machine/i4b_debug.h>
end_include

begin_include
include|#
directive|include
file|<machine/i4b_ioctl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<i4b/i4b_debug.h>
end_include

begin_include
include|#
directive|include
file|<i4b/i4b_ioctl.h>
end_include

begin_include
include|#
directive|include
file|<dev/pcmcia/pcmciareg.h>
end_include

begin_include
include|#
directive|include
file|<dev/pcmcia/pcmciavar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<i4b/layer1/i4b_l1.h>
end_include

begin_include
include|#
directive|include
file|<i4b/layer1/i4b_isac.h>
end_include

begin_include
include|#
directive|include
file|<i4b/layer1/i4b_hscx.h>
end_include

begin_include
include|#
directive|include
file|<i4b/layer1/i4b_ipac.h>
end_include

begin_include
include|#
directive|include
file|<i4b/layer1/pcmcia_isic.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_comment
comment|/* PCMCIA support routines */
end_comment

begin_decl_stmt
specifier|static
name|u_int8_t
name|elsa_mcall_read_reg
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|,
name|int
name|what
operator|,
name|bus_size_t
name|offs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|elsa_mcall_write_reg
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|,
name|int
name|what
operator|,
name|bus_size_t
name|offs
operator|,
name|u_int8_t
name|data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|elsa_mcall_read_fifo
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|,
name|int
name|what
operator|,
name|void
operator|*
name|buf
operator|,
name|size_t
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|elsa_mcall_write_fifo
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|,
name|int
name|what
operator|,
specifier|const
name|void
operator|*
name|data
operator|,
name|size_t
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------------------------------------------------------------------*  *	read fifo routines  *---------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|PCMCIA_IO_BASE
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ap: XXX hack */
end_comment

begin_function
specifier|static
name|void
name|elsa_mcall_read_fifo
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
specifier|const
name|void
modifier|*
name|base
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{ }
end_function

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|void
name|elsa_mcall_read_fifo
parameter_list|(
name|struct
name|isic_softc
modifier|*
name|sc
parameter_list|,
name|int
name|what
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
comment|/* 	bus_space_tag_t t = sc->sc_maps[0].t; 	bus_space_handle_t h = sc->sc_maps[0].h; 	*/
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------------------------------------------------------------------*  *	write fifo routines  *---------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function
specifier|static
name|void
name|elsa_mcall_write_fifo
parameter_list|(
name|void
modifier|*
name|base
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{ }
end_function

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|void
name|elsa_mcall_write_fifo
parameter_list|(
name|struct
name|isic_softc
modifier|*
name|sc
parameter_list|,
name|int
name|what
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
comment|/* 	bus_space_tag_t t = sc->sc_maps[0].t; 	bus_space_handle_t h = sc->sc_maps[0].h; 	*/
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------------------------------------------------------------------*  *	write register routines  *---------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function
specifier|static
name|void
name|elsa_mcall_write_reg
parameter_list|(
name|u_char
modifier|*
name|base
parameter_list|,
name|u_int
name|offset
parameter_list|,
name|u_int
name|v
parameter_list|)
block|{ }
end_function

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|void
name|elsa_mcall_write_reg
parameter_list|(
name|struct
name|isic_softc
modifier|*
name|sc
parameter_list|,
name|int
name|what
parameter_list|,
name|bus_size_t
name|offs
parameter_list|,
name|u_int8_t
name|data
parameter_list|)
block|{
comment|/* 	bus_space_tag_t t = sc->sc_maps[0].t; 	bus_space_handle_t h = sc->sc_maps[0].h; 	*/
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------------------------------------------------------------------*  *	read register routines  *---------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function
specifier|static
name|u_char
name|elsa_mcall_read_reg
parameter_list|(
name|u_char
modifier|*
name|base
parameter_list|,
name|u_int
name|offset
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|u_int8_t
name|elsa_mcall_read_reg
parameter_list|(
name|struct
name|isic_softc
modifier|*
name|sc
parameter_list|,
name|int
name|what
parameter_list|,
name|bus_size_t
name|offs
parameter_list|)
block|{
comment|/* 	bus_space_tag_t t = sc->sc_maps[0].t; 	bus_space_handle_t h = sc->sc_maps[0].h; 	*/
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * XXX - one time only! Some of this has to go into an enable  * function, with apropriate counterpart in disable, so a card  * could be removed an inserted again. But never mind for now,  * this won't work anyway for several reasons (both in NetBSD  * and in I4B).  */
end_comment

begin_function
name|int
name|isic_attach_elsamcall
parameter_list|(
name|struct
name|pcmcia_isic_softc
modifier|*
name|psc
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
block|{
name|struct
name|isic_softc
modifier|*
name|sc
init|=
operator|&
name|psc
operator|->
name|sc_isic
decl_stmt|;
name|bus_space_tag_t
name|t
decl_stmt|;
name|bus_space_handle_t
name|h
decl_stmt|;
comment|/* Validate config info */
if|if
condition|(
name|cfe
operator|->
name|num_memspace
operator|!=
literal|0
condition|)
name|printf
argument_list|(
literal|": unexpected number of memory spaces %d should be 0\n"
argument_list|,
name|cfe
operator|->
name|num_memspace
argument_list|)
expr_stmt|;
if|if
condition|(
name|cfe
operator|->
name|num_iospace
operator|!=
literal|1
condition|)
name|printf
argument_list|(
literal|": unexpected number of memory spaces %d should be 1\n"
argument_list|,
name|cfe
operator|->
name|num_iospace
argument_list|)
expr_stmt|;
comment|/* Allocate pcmcia space */
if|if
condition|(
name|pcmcia_io_alloc
argument_list|(
name|pa
operator|->
name|pf
argument_list|,
literal|0
argument_list|,
name|cfe
operator|->
name|iospace
index|[
literal|0
index|]
operator|.
name|length
argument_list|,
name|cfe
operator|->
name|iospace
index|[
literal|0
index|]
operator|.
name|length
argument_list|,
operator|&
name|psc
operator|->
name|sc_pcioh
argument_list|)
condition|)
name|printf
argument_list|(
literal|": can't allocate i/o space\n"
argument_list|)
expr_stmt|;
comment|/* map them */
if|if
condition|(
name|pcmcia_io_map
argument_list|(
name|pa
operator|->
name|pf
argument_list|,
operator|(
operator|(
name|cfe
operator|->
name|flags
operator|&
name|PCMCIA_CFE_IO16
operator|)
condition|?
name|PCMCIA_WIDTH_IO16
else|:
name|PCMCIA_WIDTH_IO8
operator|)
argument_list|,
literal|0
argument_list|,
name|cfe
operator|->
name|iospace
index|[
literal|0
index|]
operator|.
name|length
argument_list|,
operator|&
name|psc
operator|->
name|sc_pcioh
argument_list|,
operator|&
name|psc
operator|->
name|sc_io_window
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|": can't map i/o space\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/* setup card type */
name|sc
operator|->
name|sc_cardtyp
operator|=
name|CARD_TYPEP_ELSAMLMCALL
expr_stmt|;
comment|/* Setup bus space maps */
name|sc
operator|->
name|sc_num_mappings
operator|=
literal|1
expr_stmt|;
name|MALLOC_MAPS
argument_list|(
name|sc
argument_list|)
expr_stmt|;
comment|/* Copy our handles/tags to the MI maps */
name|sc
operator|->
name|sc_maps
index|[
literal|0
index|]
operator|.
name|t
operator|=
name|psc
operator|->
name|sc_pcioh
operator|.
name|iot
expr_stmt|;
name|sc
operator|->
name|sc_maps
index|[
literal|0
index|]
operator|.
name|h
operator|=
name|psc
operator|->
name|sc_pcioh
operator|.
name|ioh
expr_stmt|;
name|sc
operator|->
name|sc_maps
index|[
literal|0
index|]
operator|.
name|offset
operator|=
literal|0
expr_stmt|;
name|sc
operator|->
name|sc_maps
index|[
literal|0
index|]
operator|.
name|size
operator|=
literal|0
expr_stmt|;
comment|/* not our mapping */
name|t
operator|=
name|sc
operator|->
name|sc_maps
index|[
literal|0
index|]
operator|.
name|t
expr_stmt|;
name|h
operator|=
name|sc
operator|->
name|sc_maps
index|[
literal|0
index|]
operator|.
name|h
expr_stmt|;
name|sc
operator|->
name|clearirq
operator|=
name|NULL
expr_stmt|;
name|sc
operator|->
name|readreg
operator|=
name|elsa_mcall_read_reg
expr_stmt|;
name|sc
operator|->
name|writereg
operator|=
name|elsa_mcall_write_reg
expr_stmt|;
name|sc
operator|->
name|readfifo
operator|=
name|elsa_mcall_read_fifo
expr_stmt|;
name|sc
operator|->
name|writefifo
operator|=
name|elsa_mcall_write_fifo
expr_stmt|;
comment|/* setup IOM bus type */
name|sc
operator|->
name|sc_bustyp
operator|=
name|BUS_TYPE_IOM2
expr_stmt|;
name|sc
operator|->
name|sc_ipac
operator|=
literal|1
expr_stmt|;
name|sc
operator|->
name|sc_bfifolen
operator|=
name|IPAC_BFIFO_LEN
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NISIC> 0 */
end_comment

end_unit

