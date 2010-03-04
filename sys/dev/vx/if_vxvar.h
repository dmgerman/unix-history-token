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
name|ifnet
modifier|*
name|vx_ifp
decl_stmt|;
name|bus_space_tag_t
name|vx_bst
decl_stmt|;
name|bus_space_handle_t
name|vx_bsh
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
comment|/* # of mbufs we keep around	 */
name|struct
name|mbuf
modifier|*
name|vx_mb
index|[
name|MAX_MBS
index|]
decl_stmt|;
comment|/* spare mbuf storage.		 */
name|int
name|vx_next_mb
decl_stmt|;
comment|/* Which mbuf to use next. 	 */
name|int
name|vx_last_mb
decl_stmt|;
comment|/* Last mbuf.			 */
name|char
name|vx_connectors
decl_stmt|;
comment|/* Connectors on this card.	 */
name|char
name|vx_connector
decl_stmt|;
comment|/* Connector to use.		 */
name|short
name|vx_tx_start_thresh
decl_stmt|;
comment|/* Current TX_start_thresh.	 */
name|int
name|vx_tx_succ_ok
decl_stmt|;
comment|/* # packets sent in sequence	 */
comment|/* w/o underrun			 */
name|struct
name|callout
name|vx_callout
decl_stmt|;
comment|/* Callout for timeouts		 */
name|struct
name|callout
name|vx_watchdog
decl_stmt|;
name|struct
name|mtx
name|vx_mtx
decl_stmt|;
name|int
name|vx_buffill_pending
decl_stmt|;
name|int
name|vx_timer
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
value|bus_space_write_4(sc->vx_bst, sc->vx_bsh, reg, val)
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
value|bus_space_write_2(sc->vx_bst, sc->vx_bsh, reg, val)
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
value|bus_space_write_1(sc->vx_bst, sc->vx_bsh, reg, val)
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
value|bus_space_read_4(sc->vx_bst, sc->vx_bsh, reg)
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
value|bus_space_read_2(sc->vx_bst, sc->vx_bsh, reg)
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
value|bus_space_read_1(sc->vx_bst, sc->vx_bsh, reg)
end_define

begin_define
define|#
directive|define
name|VX_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->vx_mtx)
end_define

begin_define
define|#
directive|define
name|VX_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->vx_mtx)
end_define

begin_define
define|#
directive|define
name|VX_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->vx_mtx, MA_OWNED)
end_define

begin_function_decl
name|int
name|vx_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vx_stop
parameter_list|(
name|struct
name|vx_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vx_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vx_busy_eeprom
parameter_list|(
name|struct
name|vx_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

