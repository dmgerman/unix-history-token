begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2013-2015, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXL_PF_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXL_PF_H_
end_define

begin_define
define|#
directive|define
name|VF_FLAG_ENABLED
value|0x01
end_define

begin_define
define|#
directive|define
name|VF_FLAG_SET_MAC_CAP
value|0x02
end_define

begin_define
define|#
directive|define
name|VF_FLAG_VLAN_CAP
value|0x04
end_define

begin_define
define|#
directive|define
name|VF_FLAG_PROMISC_CAP
value|0x08
end_define

begin_define
define|#
directive|define
name|VF_FLAG_MAC_ANTI_SPOOF
value|0x10
end_define

begin_define
define|#
directive|define
name|IXL_PF_STATE_EMPR_RESETTING
value|(1<< 0)
end_define

begin_struct
struct|struct
name|ixl_vf
block|{
name|struct
name|ixl_vsi
name|vsi
decl_stmt|;
name|uint32_t
name|vf_flags
decl_stmt|;
name|uint8_t
name|mac
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|vf_num
decl_stmt|;
name|uint32_t
name|version
decl_stmt|;
name|struct
name|sysctl_ctx_list
name|ctx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Physical controller structure */
end_comment

begin_struct
struct|struct
name|ixl_pf
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
name|int
name|state
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
name|bool
name|link_up
decl_stmt|;
name|u32
name|link_speed
decl_stmt|;
name|int
name|advertised_speed
decl_stmt|;
name|int
name|fc
decl_stmt|;
comment|/* local flow ctrl setting */
comment|/* 	** Network interfaces 	**   These are the traffic class holders, and 	**   will have a stack interface and queues  	**   associated with them. 	** NOTE: The PF has only a single interface, 	**   so it is embedded in the PF struct. 	*/
name|struct
name|ixl_vsi
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
name|struct
name|ixl_vf
modifier|*
name|vfs
decl_stmt|;
name|int
name|num_vfs
decl_stmt|;
name|uint16_t
name|veb_seid
decl_stmt|;
name|struct
name|task
name|vflr_task
decl_stmt|;
name|int
name|vc_debug_lvl
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Defines used for NVM update ioctls.  * This value is used in the Solaris tool, too.  */
end_comment

begin_define
define|#
directive|define
name|I40E_NVM_ACCESS
define|\
value|(((((((('E'<< 4) + '1')<< 4) + 'K')<< 4) + 'G')<< 4) | 5)
end_define

begin_define
define|#
directive|define
name|IXL_DEFAULT_PHY_INT_MASK
define|\
value|((~(I40E_AQ_EVENT_LINK_UPDOWN | I40E_AQ_EVENT_MODULE_QUAL_FAIL \       | I40E_AQ_EVENT_MEDIA_NA))& 0x3FF)
end_define

begin_comment
comment|/*** Sysctl help messages; displayed with "sysctl -d" ***/
end_comment

begin_define
define|#
directive|define
name|IXL_SYSCTL_HELP_SET_ADVERTISE
define|\
value|"\nControl advertised link speed.\n"	\ "Flags:\n"				\ "\t 0x1 - advertise 100M\n"		\ "\t 0x2 - advertise 1G\n"		\ "\t 0x4 - advertise 10G\n"		\ "\t 0x8 - advertise 20G\n"		\ "\t0x10 - advertise 40G\n\n"		\ "Set to 0 to disable link."
end_define

begin_define
define|#
directive|define
name|IXL_SYSCTL_HELP_FC
define|\
value|"\nSet flow control mode using the values below.\n" 	\ "\t0 - off\n" 						\ "\t1 - rx pause\n" 					\ "\t2 - tx pause\n"					\ "\t3 - tx and rx pause"
end_define

begin_define
define|#
directive|define
name|IXL_SYSCTL_HELP_LINK_STATUS
define|\
value|"\nExecutes a \"Get Link Status\" command on the Admin Queue, and displays" \ " the response."
end_define

begin_comment
unit|\
comment|/*** Functions / Macros ***/
end_comment

begin_comment
comment|/* ** Put the NVM, EEtrackID, and OEM version information into a string */
end_comment

begin_function
specifier|static
name|void
name|ixl_nvm_version_str
parameter_list|(
name|struct
name|i40e_hw
modifier|*
name|hw
parameter_list|,
name|struct
name|sbuf
modifier|*
name|buf
parameter_list|)
block|{
name|u8
name|oem_ver
init|=
call|(
name|u8
call|)
argument_list|(
name|hw
operator|->
name|nvm
operator|.
name|oem_ver
operator|>>
literal|24
argument_list|)
decl_stmt|;
name|u16
name|oem_build
init|=
call|(
name|u16
call|)
argument_list|(
operator|(
name|hw
operator|->
name|nvm
operator|.
name|oem_ver
operator|>>
literal|16
operator|)
operator|&
literal|0xFFFF
argument_list|)
decl_stmt|;
name|u8
name|oem_patch
init|=
call|(
name|u8
call|)
argument_list|(
name|hw
operator|->
name|nvm
operator|.
name|oem_ver
operator|&
literal|0xFF
argument_list|)
decl_stmt|;
name|sbuf_printf
argument_list|(
name|buf
argument_list|,
literal|"nvm %x.%02x etid %08x oem %d.%d.%d"
argument_list|,
operator|(
name|hw
operator|->
name|nvm
operator|.
name|version
operator|&
name|IXL_NVM_VERSION_HI_MASK
operator|)
operator|>>
name|IXL_NVM_VERSION_HI_SHIFT
argument_list|,
operator|(
name|hw
operator|->
name|nvm
operator|.
name|version
operator|&
name|IXL_NVM_VERSION_LO_MASK
operator|)
operator|>>
name|IXL_NVM_VERSION_LO_SHIFT
argument_list|,
name|hw
operator|->
name|nvm
operator|.
name|eetrack
argument_list|,
name|oem_ver
argument_list|,
name|oem_build
argument_list|,
name|oem_patch
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|ixl_print_nvm_version
parameter_list|(
name|struct
name|ixl_pf
modifier|*
name|pf
parameter_list|)
block|{
name|struct
name|i40e_hw
modifier|*
name|hw
init|=
operator|&
name|pf
operator|->
name|hw
decl_stmt|;
name|device_t
name|dev
init|=
name|pf
operator|->
name|dev
decl_stmt|;
name|struct
name|sbuf
modifier|*
name|sbuf
decl_stmt|;
name|sbuf
operator|=
name|sbuf_new_auto
argument_list|()
expr_stmt|;
name|ixl_nvm_version_str
argument_list|(
name|hw
argument_list|,
name|sbuf
argument_list|)
expr_stmt|;
name|sbuf_finish
argument_list|(
name|sbuf
argument_list|)
expr_stmt|;
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"%s\n"
argument_list|,
name|sbuf_data
argument_list|(
name|sbuf
argument_list|)
argument_list|)
expr_stmt|;
name|sbuf_delete
argument_list|(
name|sbuf
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|I40E_VC_DEBUG
parameter_list|(
name|pf
parameter_list|,
name|level
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do { \ 		if ((pf)->vc_debug_lvl>= (level)) \ 			device_printf((pf)->dev, __VA_ARGS__); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|i40e_send_vf_nack
parameter_list|(
name|pf
parameter_list|,
name|vf
parameter_list|,
name|op
parameter_list|,
name|st
parameter_list|)
define|\
value|ixl_send_vf_nack_msg((pf), (vf), (op), (st), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|IXL_PF_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_sc)->pf_mtx, _name, "IXL PF Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|IXL_PF_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->pf_mtx)
end_define

begin_define
define|#
directive|define
name|IXL_PF_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->pf_mtx)
end_define

begin_define
define|#
directive|define
name|IXL_PF_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->pf_mtx)
end_define

begin_define
define|#
directive|define
name|IXL_PF_LOCK_ASSERT
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
comment|/* _IXL_PF_H_ */
end_comment

end_unit

