begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 Herb Peyerl (hpeyerl@novatel.ca) All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met: 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer. 2. The name  * of the author may not be used to endorse or promote products derived from  * this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO  * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  October 2, 1994   Modified by: Andres Vega Garcia   INRIA - Sophia Antipolis, France  e-mail: avega@sophia.inria.fr  finger: avega@pax.inria.fr   */
end_comment

begin_comment
comment|/*  * Ethernet software status per interface.  */
end_comment

begin_struct
struct|struct
name|vx_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* Ethernet common part		*/
name|int
name|unit
decl_stmt|;
comment|/* unit number */
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|void
modifier|*
name|vx_intrhand
decl_stmt|;
name|struct
name|resource
modifier|*
name|vx_irq
decl_stmt|;
name|struct
name|resource
modifier|*
name|vx_res
decl_stmt|;
define|#
directive|define
name|MAX_MBS
value|8
comment|/* # of mbufs we keep around	*/
name|struct
name|mbuf
modifier|*
name|mb
index|[
name|MAX_MBS
index|]
decl_stmt|;
comment|/* spare mbuf storage.		*/
name|int
name|next_mb
decl_stmt|;
comment|/* Which mbuf to use next. 	*/
name|int
name|last_mb
decl_stmt|;
comment|/* Last mbuf.			*/
name|char
name|vx_connectors
decl_stmt|;
comment|/* Connectors on this card.	*/
name|char
name|vx_connector
decl_stmt|;
comment|/* Connector to use.		*/
name|short
name|tx_start_thresh
decl_stmt|;
comment|/* Current TX_start_thresh.	*/
name|int
name|tx_succ_ok
decl_stmt|;
comment|/* # packets sent in sequence	*/
comment|/* w/o underrun			*/
name|struct
name|callout_handle
name|ch
decl_stmt|;
comment|/* Callout handle for timeouts  */
name|int
name|buffill_pending
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4(sc->bst, sc->bsh, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2(sc->bst, sc->bsh, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1(sc->bst, sc->bsh, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4(sc->bst, sc->bsh, reg)
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_2(sc->bst, sc->bsh, reg)
end_define

begin_define
define|#
directive|define
name|CSR_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_1(sc->bst, sc->bsh, reg)
end_define

begin_function_decl
specifier|extern
name|void
name|vxfree
parameter_list|(
name|struct
name|vx_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vxattach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vxstop
parameter_list|(
name|struct
name|vx_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vxintr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vxbusyeeprom
parameter_list|(
name|struct
name|vx_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

