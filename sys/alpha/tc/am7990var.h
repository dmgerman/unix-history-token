begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: am7990var.h,v 1.18 1998/01/12 09:23:16 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Charles M. Hannum.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Charles M. Hannum.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_define
define|#
directive|define
name|integrate
end_define

begin_define
define|#
directive|define
name|hide
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|integrate
value|static __inline
end_define

begin_define
define|#
directive|define
name|hide
value|static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Ethernet software status per device.  *  * Each interface is referenced by a network interface structure,  * ethercom.ec_if, which the routing code uses to locate the interface.   * This structure contains the output queue for the interface, its address, ...  *  * NOTE: this structure MUST be the first element in machine-dependent  * le_softc structures!  This is designed SPECIFICALLY to make it possible  * to simply cast a "void *" to "struct le_softc *" or to  * "struct am7990_softc *".  Among other things, this saves a lot of hair  * in the interrupt handlers.  */
end_comment

begin_struct
struct|struct
name|am7990_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* base device glue */
name|struct
name|arpcom
name|sc_ethercom
decl_stmt|;
comment|/* Ethernet common part */
name|struct
name|ifmedia
name|sc_media
decl_stmt|;
comment|/* our supported media */
comment|/* 	 * Memory functions: 	 * 	 *	copy to/from descriptor 	 *	copy to/from buffer 	 *	zero bytes in buffer 	 */
name|void
function_decl|(
modifier|*
name|sc_copytodesc
function_decl|)
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_copyfromdesc
function_decl|)
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_copytobuf
function_decl|)
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_copyfrombuf
function_decl|)
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_zerobuf
function_decl|)
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* 	 * Machine-dependent functions: 	 * 	 *	read/write CSR 	 *	hardware reset hook - may be NULL 	 *	hardware init hook - may be NULL 	 *	no carrier hook - may be NULL 	 *	media change hook - may be NULL 	 */
name|u_int16_t
function_decl|(
modifier|*
name|sc_rdcsr
function_decl|)
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_wrcsr
function_decl|)
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_hwreset
function_decl|)
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_hwinit
function_decl|)
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_nocarrier
function_decl|)
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sc_mediachange
function_decl|)
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_mediastatus
function_decl|)
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|,
name|struct
name|ifmediareq
modifier|*
parameter_list|)
function_decl|;
comment|/* 	 * Media-supported by this interface.  If this is NULL, 	 * the only supported media is assumed to be "manual". 	 */
name|int
modifier|*
name|sc_supmedia
decl_stmt|;
name|int
name|sc_nsupmedia
decl_stmt|;
name|int
name|sc_defaultmedia
decl_stmt|;
comment|/* PCnet bit to use software selection of a port */
name|int
name|sc_initmodemedia
decl_stmt|;
name|int
name|sc_havecarrier
decl_stmt|;
comment|/* carrier status */
name|void
modifier|*
name|sc_sh
decl_stmt|;
comment|/* shutdownhook cookie */
name|u_int16_t
name|sc_conf3
decl_stmt|;
comment|/* CSR3 value */
name|u_int16_t
name|sc_saved_csr0
decl_stmt|;
comment|/* Value of csr0 at time of interrupt */
name|void
modifier|*
name|sc_mem
decl_stmt|;
comment|/* base address of RAM -- CPU's view */
name|u_long
name|sc_addr
decl_stmt|;
comment|/* base address of RAM -- LANCE's view */
name|u_long
name|sc_memsize
decl_stmt|;
comment|/* size of RAM */
name|int
name|sc_nrbuf
decl_stmt|;
comment|/* number of receive buffers */
name|int
name|sc_ntbuf
decl_stmt|;
comment|/* number of transmit buffers */
name|int
name|sc_last_rd
decl_stmt|;
name|int
name|sc_first_td
decl_stmt|,
name|sc_last_td
decl_stmt|,
name|sc_no_td
decl_stmt|;
name|int
name|sc_initaddr
decl_stmt|;
name|int
name|sc_rmdaddr
decl_stmt|;
name|int
name|sc_tmdaddr
decl_stmt|;
name|int
modifier|*
name|sc_rbufaddr
decl_stmt|;
name|int
modifier|*
name|sc_tbufaddr
decl_stmt|;
ifdef|#
directive|ifdef
name|LEDEBUG
name|int
name|sc_debug
decl_stmt|;
endif|#
directive|endif
name|u_int8_t
name|sc_enaddr
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|sc_pad
index|[
literal|2
index|]
decl_stmt|;
name|int
name|unit
decl_stmt|;
if|#
directive|if
name|NRND
operator|>
literal|0
name|rndsource_element_t
name|rnd_source
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_function_decl
name|void
name|am7990_config
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|am7990_init
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|am7990_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|am7990_meminit
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|am7990_reset
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|am7990_setladrf
parameter_list|(
name|struct
name|arpcom
modifier|*
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|am7990_start
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|am7990_stop
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|am7990_watchdog
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|am7990_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The following functions are only useful on certain cpu/bus  * combinations.  They should be written in assembly language for  * maximum efficiency, but machine-independent versions are provided  * for drivers that have not yet been optimized.  */
end_comment

begin_function_decl
name|void
name|am7990_copytobuf_contig
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|am7990_copyfrombuf_contig
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|am7990_zerobuf_contig
parameter_list|(
name|struct
name|am7990_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Example only - see am7990.c */
end_comment

begin_endif
unit|void am7990_copytobuf_gap2(struct am7990_softc *, void *, int, int); void am7990_copyfrombuf_gap2(struct am7990_softc *, void *, int, int); void am7990_zerobuf_gap2(struct am7990_softc *, int, int);  void am7990_copytobuf_gap16(struct am7990_softc *, void *, int, int); void am7990_copyfrombuf_gap16(struct am7990_softc *, void *, int, int); void am7990_zerobuf_gap16(struct am7990_softc *, int, int);
endif|#
directive|endif
end_endif

begin_comment
comment|/* Example only */
end_comment

end_unit

