begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004-2005 Sam Leffler, Errno Consulting  * Copyright (c) 2004 Video54 Technologies, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,     without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_RATECTRL_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_RATECTRL_H_
end_define

begin_comment
comment|/*  * Interface definitions for transmit rate control modules for the  * Atheros driver.  *  * A rate control module is responsible for choosing the transmit rate  * for each data frame.  Management+control frames are always sent at  * a fixed rate.  *  * Only one module may be present at a time; the driver references  * rate control interfaces by symbol name.  If multiple modules are  * to be supported we'll need to switch to a registration-based scheme  * as is currently done, for example, for authentication modules.  *  * An instance of the rate control module is attached to each device  * at attach time and detached when the device is destroyed.  The module  * may associate data with each device and each node (station).  Both  * sets of storage are opaque except for the size of the per-node storage  * which must be provided when the module is attached.  *  * The rate control module is notified for each state transition and  * station association/reassociation.  Otherwise it is queried for a  * rate for each outgoing frame and provided status from each transmitted  * frame.  Any ancillary processing is the responsibility of the module  * (e.g. if periodic processing is required then the module should setup  * it's own timer).  *  * In addition to the transmit rate for each frame the module must also  * indicate the number of attempts to make at the specified rate.  If this  * number is != ATH_TXMAXTRY then an additional callback is made to setup  * additional transmit state.  The rate control code is assumed to write  * this additional data directly to the transmit descriptor.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ath_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ath_node
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ath_desc
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ath_ratectrl
block|{
name|size_t
name|arc_space
decl_stmt|;
comment|/* space required for per-node state */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Attach/detach a rate control module.  */
end_comment

begin_function_decl
name|struct
name|ath_ratectrl
modifier|*
name|ath_rate_attach
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ath_rate_detach
parameter_list|(
name|struct
name|ath_ratectrl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * State storage handling.  */
end_comment

begin_comment
comment|/*  * Initialize per-node state already allocated for the specified  * node; this space can be assumed initialized to zero.  */
end_comment

begin_function_decl
name|void
name|ath_rate_node_init
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|,
name|struct
name|ath_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Cleanup any per-node state prior to the node being reclaimed.  */
end_comment

begin_function_decl
name|void
name|ath_rate_node_cleanup
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|,
name|struct
name|ath_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Update rate control state on station associate/reassociate   * (when operating as an ap or for nodes discovered when operating  * in ibss mode).  */
end_comment

begin_function_decl
name|void
name|ath_rate_newassoc
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|,
name|struct
name|ath_node
modifier|*
parameter_list|,
name|int
name|isNewAssociation
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Update/reset rate control state for 802.11 state transitions.  * Important mostly as the analog to ath_rate_newassoc when operating  * in station mode.  */
end_comment

begin_function_decl
name|void
name|ath_rate_newstate
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|,
name|enum
name|ieee80211_state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Transmit handling.  */
end_comment

begin_comment
comment|/*  * Return the transmit info for a data packet.  If multi-rate state  * is to be setup then try0 should contain a value other than ATH_TXMATRY  * and ath_rate_setupxtxdesc will be called after deciding if the frame  * can be transmitted with multi-rate retry.  */
end_comment

begin_function_decl
name|void
name|ath_rate_findrate
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|,
name|struct
name|ath_node
modifier|*
parameter_list|,
name|int
name|shortPreamble
parameter_list|,
name|size_t
name|frameLen
parameter_list|,
name|u_int8_t
modifier|*
name|rix
parameter_list|,
name|int
modifier|*
name|try0
parameter_list|,
name|u_int8_t
modifier|*
name|txrate
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Setup any extended (multi-rate) descriptor state for a data packet.  * The rate index returned by ath_rate_findrate is passed back in.  */
end_comment

begin_function_decl
name|void
name|ath_rate_setupxtxdesc
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|,
name|struct
name|ath_node
modifier|*
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|int
name|shortPreamble
parameter_list|,
name|u_int8_t
name|rix
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Update rate control state for a packet associated with the  * supplied transmit descriptor.  The routine is invoked both  * for packets that were successfully sent and for those that  * failed (consult the descriptor for details).  */
end_comment

begin_struct_decl
struct_decl|struct
name|ath_buf
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ath_rate_tx_complete
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|,
name|struct
name|ath_node
modifier|*
parameter_list|,
specifier|const
name|struct
name|ath_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_RATECTRL_H_ */
end_comment

end_unit

