begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2013-2014, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I40E_PF_H_
end_ifndef

begin_define
define|#
directive|define
name|_I40E_PF_H_
end_define

begin_comment
comment|/* Physical controller structure */
end_comment

begin_struct
struct|struct
name|i40e_pf
block|{
name|struct
name|i40e_hw
name|hw
decl_stmt|;
name|struct
name|i40e_osdep
name|osdep
decl_stmt|;
name|struct
name|device
modifier|*
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|pci_mem
decl_stmt|;
name|struct
name|resource
modifier|*
name|msix_mem
decl_stmt|;
comment|/* 	 * Interrupt resources: this set is 	 * either used for legacy, or for Link 	 * when doing MSIX 	 */
name|void
modifier|*
name|tag
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|struct
name|callout
name|timer
decl_stmt|;
name|int
name|msix
decl_stmt|;
name|int
name|if_flags
decl_stmt|;
name|struct
name|mtx
name|pf_mtx
decl_stmt|;
name|u32
name|qbase
decl_stmt|;
name|u32
name|admvec
decl_stmt|;
name|struct
name|task
name|adminq
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|tq
decl_stmt|;
comment|/* 	** VSI - Stations:  	**   These are the traffic class holders, and 	**   will have a stack interface and queues  	**   associated with them. 	** NOTE: for now using just one, so embed it. 	*/
name|struct
name|i40e_vsi
name|vsi
decl_stmt|;
comment|/* Misc stats maintained by the driver */
name|u64
name|watchdog_events
decl_stmt|;
name|u64
name|admin_irq
decl_stmt|;
comment|/* Statistics from hw */
name|struct
name|i40e_hw_port_stats
name|stats
decl_stmt|;
name|struct
name|i40e_hw_port_stats
name|stats_offsets
decl_stmt|;
name|bool
name|stat_offsets_loaded
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I40E_PF_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_sc)->pf_mtx, _name, "I40E PF Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|I40E_PF_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->pf_mtx)
end_define

begin_define
define|#
directive|define
name|I40E_PF_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->pf_mtx)
end_define

begin_define
define|#
directive|define
name|I40E_PF_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->pf_mtx)
end_define

begin_define
define|#
directive|define
name|I40E_PF_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->pf_mtx, MA_OWNED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I40E_PF_H_ */
end_comment

end_unit

