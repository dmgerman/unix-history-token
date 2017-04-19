begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INIT_FW_FUNCS_H
end_ifndef

begin_define
define|#
directive|define
name|_INIT_FW_FUNCS_H
end_define

begin_comment
comment|/* Forward declarations */
end_comment

begin_struct_decl
struct_decl|struct
name|init_qm_pq_params
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * @brief ecore_qm_pf_mem_size - Prepare QM ILT sizes  *  * Returns the required host memory size in 4KB units.  * Must be called before all QM init HSI functions.  *  * @param pf_id -	physical function ID  * @param num_pf_cids - number of connections used by this PF  * @param num_vf_cids -	number of connections used by VFs of this PF  * @param num_tids -	number of tasks used by this PF  * @param num_pf_pqs -	number of PQs used by this PF  * @param num_vf_pqs -	number of PQs used by VFs of this PF  *  * @return The required host memory size in 4KB units.  */
end_comment

begin_function_decl
name|u32
name|ecore_qm_pf_mem_size
parameter_list|(
name|u8
name|pf_id
parameter_list|,
name|u32
name|num_pf_cids
parameter_list|,
name|u32
name|num_vf_cids
parameter_list|,
name|u32
name|num_tids
parameter_list|,
name|u16
name|num_pf_pqs
parameter_list|,
name|u16
name|num_vf_pqs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_qm_common_rt_init - Prepare QM runtime init values for the  * engine phase.  *  * @param p_hwfn -			  HW device data  * @param max_ports_per_engine -  max number of ports per engine in HW  * @param max_phys_tcs_per_port	- max number of physical TCs per port in HW  * @param pf_rl_en -		  enable per-PF rate limiters  * @param pf_wfq_en -		  enable per-PF WFQ  * @param vport_rl_en -		  enable per-VPORT rate limiters  * @param vport_wfq_en -	  enable per-VPORT WFQ  * @param port_params -		  array of size MAX_NUM_PORTS with parameters  *				  for each port  *  * @return 0 on success, -1 on error.  */
end_comment

begin_function_decl
name|int
name|ecore_qm_common_rt_init
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|max_ports_per_engine
parameter_list|,
name|u8
name|max_phys_tcs_per_port
parameter_list|,
name|bool
name|pf_rl_en
parameter_list|,
name|bool
name|pf_wfq_en
parameter_list|,
name|bool
name|vport_rl_en
parameter_list|,
name|bool
name|vport_wfq_en
parameter_list|,
name|struct
name|init_qm_port_params
name|port_params
index|[
name|MAX_NUM_PORTS
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_qm_pf_rt_init - Prepare QM runtime init values for the PF phase  *  * @param p_hwfn -			  HW device data  * @param p_ptt -			  ptt window used for writing the registers  * @param port_id -		  port ID  * @param pf_id -		  PF ID  * @param max_phys_tcs_per_port	- max number of physical TCs per port in HW  * @param is_first_pf -		  1 = first PF in engine, 0 = othwerwise  * @param num_pf_cids -		  number of connections used by this PF  * @param num_vf_cids -		  number of connections used by VFs of this PF  * @param num_tids -		  number of tasks used by this PF  * @param start_pq -		  first Tx PQ ID associated with this PF  * @param num_pf_pqs -		  number of Tx PQs associated with this PF  *				  (non-VF)  * @param num_vf_pqs -		  number of Tx PQs associated with a VF  * @param start_vport -		  first VPORT ID associated with this PF  * @param num_vports -		  number of VPORTs associated with this PF  * @param pf_wfq -		  WFQ weight. if PF WFQ is globally disabled,  *				  the weight must be 0. otherwise, the weight  *				  must be non-zero.  * @param pf_rl -		  rate limit in Mb/sec units. a value of 0  *				  means don't configure. ignored if PF RL is  *				  globally disabled.  * @param pq_params -		  array of size (num_pf_pqs + num_vf_pqs) with  *				  parameters for each Tx PQ associated with the  *				  specified PF.  * @param vport_params -	  array of size num_vports with parameters for  *				  each associated VPORT.  *  * @return 0 on success, -1 on error.  */
end_comment

begin_function_decl
name|int
name|ecore_qm_pf_rt_init
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u8
name|port_id
parameter_list|,
name|u8
name|pf_id
parameter_list|,
name|u8
name|max_phys_tcs_per_port
parameter_list|,
name|bool
name|is_first_pf
parameter_list|,
name|u32
name|num_pf_cids
parameter_list|,
name|u32
name|num_vf_cids
parameter_list|,
name|u32
name|num_tids
parameter_list|,
name|u16
name|start_pq
parameter_list|,
name|u16
name|num_pf_pqs
parameter_list|,
name|u16
name|num_vf_pqs
parameter_list|,
name|u8
name|start_vport
parameter_list|,
name|u8
name|num_vports
parameter_list|,
name|u16
name|pf_wfq
parameter_list|,
name|u32
name|pf_rl
parameter_list|,
name|struct
name|init_qm_pq_params
modifier|*
name|pq_params
parameter_list|,
name|struct
name|init_qm_vport_params
modifier|*
name|vport_params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_init_pf_wfq - Initializes the WFQ weight of the specified PF  *  * @param p_hwfn -	   HW device data  * @param p_ptt -	   ptt window used for writing the registers  * @param pf_id	-  PF ID  * @param pf_wfq - WFQ weight. Must be non-zero.  *  * @return 0 on success, -1 on error.  */
end_comment

begin_function_decl
name|int
name|ecore_init_pf_wfq
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u8
name|pf_id
parameter_list|,
name|u16
name|pf_wfq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_init_pf_rl - Initializes the rate limit of the specified PF  *  * @param p_hwfn  * @param p_ptt -   ptt window used for writing the registers  * @param pf_id	- PF ID  * @param pf_rl	- rate limit in Mb/sec units  *  * @return 0 on success, -1 on error.  */
end_comment

begin_function_decl
name|int
name|ecore_init_pf_rl
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u8
name|pf_id
parameter_list|,
name|u32
name|pf_rl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_init_vport_wfq - Initializes the WFQ weight of the specified VPORT  *  * @param p_hwfn -		   HW device data  * @param p_ptt -		   ptt window used for writing the registers  * @param first_tx_pq_id - An array containing the first Tx PQ ID associated  *                         with the VPORT for each TC. This array is filled by  *                         ecore_qm_pf_rt_init  * @param vport_wfq -	   WFQ weight. Must be non-zero.  *  * @return 0 on success, -1 on error.  */
end_comment

begin_function_decl
name|int
name|ecore_init_vport_wfq
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u16
name|first_tx_pq_id
index|[
name|NUM_OF_TCS
index|]
parameter_list|,
name|u16
name|vport_wfq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_init_vport_rl - Initializes the rate limit of the specified  * VPORT.  *  * @param p_hwfn -	     HW device data  * @param p_ptt -	     ptt window used for writing the registers  * @param vport_id - VPORT ID  * @param vport_rl - rate limit in Mb/sec units  *  * @return 0 on success, -1 on error.  */
end_comment

begin_function_decl
name|int
name|ecore_init_vport_rl
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u8
name|vport_id
parameter_list|,
name|u32
name|vport_rl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_send_qm_stop_cmd - Sends a stop command to the QM  *  * @param p_hwfn -		   HW device data  * @param p_ptt -		   ptt window used for writing the registers  * @param is_release_cmd - true for release, false for stop.  * @param is_tx_pq -	   true for Tx PQs, false for Other PQs.  * @param start_pq -	   first PQ ID to stop  * @param num_pqs -	   Number of PQs to stop, starting from start_pq.  *  * @return bool, true if successful, false if timeout occured while waiting for  * QM command done.  */
end_comment

begin_function_decl
name|bool
name|ecore_send_qm_stop_cmd
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|bool
name|is_release_cmd
parameter_list|,
name|bool
name|is_tx_pq
parameter_list|,
name|u16
name|start_pq
parameter_list|,
name|u16
name|num_pqs
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|UNUSED_HSI_FUNC
end_ifndef

begin_comment
comment|/**  * @brief ecore_init_nig_ets - Initializes the NIG ETS arbiter  *  * Based on weight/priority requirements per-TC.  *  * @param p_hwfn -   HW device data  * @param p_ptt -   ptt window used for writing the registers.  * @param req -   the NIG ETS initialization requirements.  * @param is_lb	- if set, the loopback port arbiter is initialized, otherwise  *		  the physical port arbiter is initialized. The pure-LB TC  *		  requirements are ignored when is_lb is cleared.  */
end_comment

begin_function_decl
name|void
name|ecore_init_nig_ets
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|struct
name|init_ets_req
modifier|*
name|req
parameter_list|,
name|bool
name|is_lb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_init_nig_lb_rl - Initializes the NIG LB RLs  *  * Based on global and per-TC rate requirements  *  * @param p_hwfn -	HW device data  * @param p_ptt - ptt window used for writing the registers.  * @param req -	the NIG LB RLs initialization requirements.  */
end_comment

begin_function_decl
name|void
name|ecore_init_nig_lb_rl
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|struct
name|init_nig_lb_rl_req
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNUSED_HSI_FUNC */
end_comment

begin_comment
comment|/**  * @brief ecore_init_nig_pri_tc_map - Initializes the NIG priority to TC map.  *  * Assumes valid arguments.  *  * @param p_hwfn -	HW device data  * @param p_ptt - ptt window used for writing the registers.  * @param req - required mapping from prioirties to TCs.  */
end_comment

begin_function_decl
name|void
name|ecore_init_nig_pri_tc_map
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|struct
name|init_nig_pri_tc_map_req
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|UNUSED_HSI_FUNC
end_ifndef

begin_comment
comment|/**  * @brief ecore_init_prs_ets - Initializes the PRS Rx ETS arbiter  *  * Based on weight/priority requirements per-TC.  *  * @param p_hwfn -	HW device data  * @param p_ptt - ptt window used for writing the registers.  * @param req -	the PRS ETS initialization requirements.  */
end_comment

begin_function_decl
name|void
name|ecore_init_prs_ets
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|struct
name|init_ets_req
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNUSED_HSI_FUNC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNUSED_HSI_FUNC
end_ifndef

begin_comment
comment|/**  * @brief ecore_init_brb_ram - Initializes BRB RAM sizes per TC.  *  * Based on weight/priority requirements per-TC.  *  * @param p_hwfn -   HW device data  * @param p_ptt	- ptt window used for writing the registers.  * @param req -   the BRB RAM initialization requirements.  */
end_comment

begin_function_decl
name|void
name|ecore_init_brb_ram
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|struct
name|init_brb_ram_req
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNUSED_HSI_FUNC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNUSED_HSI_FUNC
end_ifndef

begin_comment
comment|/**  * @brief ecore_set_engine_mf_ovlan_eth_type - Initializes Nig,Prs,Pbf and llh  * ethType Regs to  input ethType. Should Be called once per engine if engine  * is in BD mode.  *  * @param p_hwfn -	    HW device data  * @param p_ptt -     ptt window used for writing the registers.  * @param ethType - etherType to configure  */
end_comment

begin_function_decl
name|void
name|ecore_set_engine_mf_ovlan_eth_type
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u32
name|ethType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_set_port_mf_ovlan_eth_type - initializes DORQ ethType Regs to  * input ethType. should Be called once per port.  *  * @param p_hwfn -     HW device data  * @param p_ptt -     ptt window used for writing the registers.  * @param ethType - etherType to configure  */
end_comment

begin_function_decl
name|void
name|ecore_set_port_mf_ovlan_eth_type
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u32
name|ethType
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNUSED_HSI_FUNC */
end_comment

begin_comment
comment|/**  * @brief ecore_set_vxlan_dest_port - Initializes vxlan tunnel destination udp  * port.  *  * @param p_hwfn -	      HW device data  * @param p_ptt -       ptt window used for writing the registers.  * @param dest_port - vxlan destination udp port.  */
end_comment

begin_function_decl
name|void
name|ecore_set_vxlan_dest_port
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u16
name|dest_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_set_vxlan_enable - Enable or disable VXLAN tunnel in HW  *  * @param p_hwfn -		 HW device data  * @param p_ptt -		 ptt window used for writing the registers.  * @param vxlan_enable - vxlan enable flag.  */
end_comment

begin_function_decl
name|void
name|ecore_set_vxlan_enable
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|bool
name|vxlan_enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_set_gre_enable - Enable or disable GRE tunnel in HW  *  * @param p_hwfn -		   HW device data  * @param p_ptt -		   ptt window used for writing the registers.  * @param eth_gre_enable - eth GRE enable enable flag.  * @param ip_gre_enable -  IP GRE enable enable flag.  */
end_comment

begin_function_decl
name|void
name|ecore_set_gre_enable
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|bool
name|eth_gre_enable
parameter_list|,
name|bool
name|ip_gre_enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_set_geneve_dest_port - Initializes geneve tunnel destination  * udp port.  *  * @param p_hwfn -	      HW device data  * @param p_ptt -       ptt window used for writing the registers.  * @param dest_port - geneve destination udp port.  */
end_comment

begin_function_decl
name|void
name|ecore_set_geneve_dest_port
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u16
name|dest_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_set_geneve_enable - Enable or disable GRE tunnel in HW  *  * @param p_hwfn -			HW device data  * @param p_ptt -			ptt window used for writing the registers.  * @param eth_geneve_enable -	eth GENEVE enable enable flag.  * @param ip_geneve_enable -	IP GENEVE enable enable flag.   */
end_comment

begin_function_decl
name|void
name|ecore_set_geneve_enable
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|bool
name|eth_geneve_enable
parameter_list|,
name|bool
name|ip_geneve_enable
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|UNUSED_HSI_FUNC
end_ifndef

begin_comment
comment|/**  * @brief ecore_set_gft_event_id_cm_hdr - Configure GFT event id and cm header  *  * @param p_hwfn - HW device data  * @param p_ptt - ptt window used for writing the registers.  */
end_comment

begin_function_decl
name|void
name|ecore_set_gft_event_id_cm_hdr
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_set_rfs_mode_disable - Disable and configure HW for RFS  *  * @param p_hwfn -   HW device data  * @param p_ptt -   ptt window used for writing the registers.  * @param pf_id - pf on which to disable RFS.  */
end_comment

begin_function_decl
name|void
name|ecore_set_rfs_mode_disable
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u16
name|pf_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_set_rfs_mode_enable - Enable and configure HW for RFS  *                             * @param p_hwfn -	  HW device data  * @param p_ptt -   ptt window used for writing the registers.  * @param pf_id - pf on which to enable RFS.  * @param tcp -   set profile tcp packets.  * @param udp -   set profile udp  packet.  * @param ipv4 -  set profile ipv4 packet.  * @param ipv6 -  set profile ipv6 packet.  */
end_comment

begin_function_decl
name|void
name|ecore_set_rfs_mode_enable
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u16
name|pf_id
parameter_list|,
name|bool
name|tcp
parameter_list|,
name|bool
name|udp
parameter_list|,
name|bool
name|ipv4
parameter_list|,
name|bool
name|ipv6
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNUSED_HSI_FUNC */
end_comment

begin_comment
comment|/**  * @brief ecore_config_vf_zone_size_mode - Configure VF zone size mode. Must be  * used before first ETH queue started.  *  * @param p_hwfn -		 HW device data  * @param p_ptt -		 ptt window used for writing the registers. Don't care  *			 if runtime_init used.  * @param mode -	 VF zone size mode. Use enum vf_zone_size_mode.  * @param runtime_init - Set 1 to init runtime registers in engine phase.  *			 Set 0 if VF zone size mode configured after engine  *			 phase.  */
end_comment

begin_function_decl
name|void
name|ecore_config_vf_zone_size_mode
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u16
name|mode
parameter_list|,
name|bool
name|runtime_init
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_get_mstorm_queue_stat_offset - Get mstorm statistics offset by  * VF zone size mode.  *  * @param p_hwfn -			HW device data  * @param stat_cnt_id -		statistic counter id  * @param vf_zone_size_mode -	VF zone size mode. Use enum vf_zone_size_mode.  */
end_comment

begin_function_decl
name|u32
name|ecore_get_mstorm_queue_stat_offset
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u16
name|stat_cnt_id
parameter_list|,
name|u16
name|vf_zone_size_mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_get_mstorm_eth_vf_prods_offset - VF producer offset by VF zone  * size mode.  *  * @param p_hwfn -		      HW device data  * @param vf_id -	      vf id.  * @param vf_queue_id -	      per VF rx queue id.  * @param vf_zone_size_mode - vf zone size mode. Use enum vf_zone_size_mode.  */
end_comment

begin_function_decl
name|u32
name|ecore_get_mstorm_eth_vf_prods_offset
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|vf_id
parameter_list|,
name|u8
name|vf_queue_id
parameter_list|,
name|u16
name|vf_zone_size_mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_enable_context_validation - Enable and configure context  * validation.  *  * @param p_hwfn -   HW device data  * @param p_ptt - ptt window used for writing the registers.  */
end_comment

begin_function_decl
name|void
name|ecore_enable_context_validation
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** * @brief ecore_calc_session_ctx_validation - Calcualte validation byte for * session context. * * @param p_ctx_mem -	pointer to context memory. * @param ctx_size -	context size. * @param ctx_type -	context type. * @param cid -		context cid. */
end_comment

begin_function_decl
name|void
name|ecore_calc_session_ctx_validation
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|void
modifier|*
name|p_ctx_mem
parameter_list|,
name|u16
name|ctx_size
parameter_list|,
name|u8
name|ctx_type
parameter_list|,
name|u32
name|cid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** * @brief ecore_calc_task_ctx_validation - Calcualte validation byte for task * context. * * @param p_hwfn -		    HW device data * @param p_ctx_mem -	pointer to context memory. * @param ctx_size -	context size. * @param ctx_type -	context type. * @param tid -		    context tid. */
end_comment

begin_function_decl
name|void
name|ecore_calc_task_ctx_validation
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|void
modifier|*
name|p_ctx_mem
parameter_list|,
name|u16
name|ctx_size
parameter_list|,
name|u8
name|ctx_type
parameter_list|,
name|u32
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** * @brief ecore_memset_session_ctx - Memset session context to 0 while * preserving validation bytes. * * @param p_hwfn -		  HW device data * @param p_ctx_mem - pointer to context memory. * @param ctx_size -  size to initialzie. * @param ctx_type -  context type. */
end_comment

begin_function_decl
name|void
name|ecore_memset_session_ctx
parameter_list|(
name|void
modifier|*
name|p_ctx_mem
parameter_list|,
name|u32
name|ctx_size
parameter_list|,
name|u8
name|ctx_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** * @brief ecore_memset_task_ctx - Memset task context to 0 while preserving * validation bytes. * * @param p_ctx_mem - pointer to context memory. * @param ctx_size -  size to initialzie. * @param ctx_type -  context type. */
end_comment

begin_function_decl
name|void
name|ecore_memset_task_ctx
parameter_list|(
name|void
modifier|*
name|p_ctx_mem
parameter_list|,
name|u32
name|ctx_size
parameter_list|,
name|u8
name|ctx_type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

