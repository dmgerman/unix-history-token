begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Small helper utilities.  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_HELPER_UTIL_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_HELPER_UTIL_H__
end_define

begin_include
include|#
directive|include
file|"cvmx.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-mio-defs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_ENABLE_HELPER_FUNCTIONS
end_ifdef

begin_typedef
typedef|typedef
name|char
name|cvmx_pknd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|cvmx_bpid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CVMX_INVALID_PKND
value|((cvmx_pknd_t) -1)
end_define

begin_define
define|#
directive|define
name|CVMX_INVALID_BPID
value|((cvmx_bpid_t) -1)
end_define

begin_define
define|#
directive|define
name|CVMX_MAX_PKND
value|((cvmx_pknd_t) 64)
end_define

begin_define
define|#
directive|define
name|CVMX_MAX_BPID
value|((cvmx_bpid_t) 64)
end_define

begin_define
define|#
directive|define
name|CVMX_HELPER_MAX_IFACE
value|9
end_define

begin_comment
comment|/**  * Convert a interface mode into a human readable string  *  * @param mode   Mode to convert  *  * @return String  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|cvmx_helper_interface_mode_to_string
parameter_list|(
name|cvmx_helper_interface_mode_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Debug routine to dump the packet structure to the console  *  * @param work   Work queue entry containing the packet to dump  * @return  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_helper_dump_packet
parameter_list|(
name|cvmx_wqe_t
modifier|*
name|work
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Setup Random Early Drop on a specific input queue  *  * @param queue  Input queue to setup RED on (0-7)  * @param pass_thresh  *               Packets will begin slowly dropping when there are less than  *               this many packet buffers free in FPA 0.  * @param drop_thresh  *               All incomming packets will be dropped when there are less  *               than this many free packet buffers in FPA 0.  * @return Zero on success. Negative on failure  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_helper_setup_red_queue
parameter_list|(
name|int
name|queue
parameter_list|,
name|int
name|pass_thresh
parameter_list|,
name|int
name|drop_thresh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Setup Random Early Drop to automatically begin dropping packets.  *  * @param pass_thresh  *               Packets will begin slowly dropping when there are less than  *               this many packet buffers free in FPA 0.  * @param drop_thresh  *               All incomming packets will be dropped when there are less  *               than this many free packet buffers in FPA 0.  * @return Zero on success. Negative on failure  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_helper_setup_red
parameter_list|(
name|int
name|pass_thresh
parameter_list|,
name|int
name|drop_thresh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get the version of the CVMX libraries.  *  * @return Version string. Note this buffer is allocated statically  *         and will be shared by all callers.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|cvmx_helper_get_version
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @INTERNAL  * Setup the common GMX settings that determine the number of  * ports. These setting apply to almost all configurations of all  * chips.  *  * @param interface Interface to configure  * @param num_ports Number of ports on the interface  *  * @return Zero on success, negative on failure  */
end_comment

begin_function_decl
specifier|extern
name|int
name|__cvmx_helper_setup_gmx
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|num_ports
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @INTERNAL  * Get the number of ipd_ports on an interface.  *  * @param interface  *  * @return the number of ipd_ports on the interface and -1 for error.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|__cvmx_helper_get_num_ipd_ports
parameter_list|(
name|int
name|interface
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @INTERNAL  * Get the number of pko_ports on an interface.  *  * @param interface  *  * @return the number of pko_ports on the interface.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|__cvmx_helper_get_num_pko_ports
parameter_list|(
name|int
name|interface
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * @INTERNAL  *  * @param interface  * @param port  * @param link_info  *  * @return 0 for success and -1 for failure  */
end_comment

begin_function_decl
specifier|extern
name|int
name|__cvmx_helper_set_link_info
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|port
parameter_list|,
name|cvmx_helper_link_info_t
name|link_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @INTERNAL  *  * @param interface  * @param port  *  * @return valid link_info on success or -1 on failure  */
end_comment

begin_function_decl
specifier|extern
name|cvmx_helper_link_info_t
name|__cvmx_helper_get_link_info
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|cvmx_pko_padding
block|{
name|CVMX_PKO_PADDING_NONE
init|=
literal|0
block|,
name|CVMX_PKO_PADDING_60
init|=
literal|1
block|, }
enum|;
end_enum

begin_comment
comment|/**  * @INTERNAL  *  * @param interface  * @param num_ipd_ports is the number of ipd_ports on the interface  * @param has_fcs indicates if PKO does FCS for the ports on this  * @param pad The padding that PKO should apply.  * interface.  *  * @return 0 for success and -1 for failure  */
end_comment

begin_function_decl
specifier|extern
name|int
name|__cvmx_helper_init_interface
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|num_ipd_ports
parameter_list|,
name|int
name|has_fcs
parameter_list|,
name|enum
name|cvmx_pko_padding
name|pad
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @INTERNAL  *  * @param interface  *  * @return 0 if PKO does not do FCS and 1 otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|__cvmx_helper_get_has_fcs
parameter_list|(
name|int
name|interface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|cvmx_pko_padding
name|__cvmx_helper_get_pko_padding
parameter_list|(
name|int
name|interface
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Returns the IPD port number for a port on the given  * interface.  *  * @param interface Interface to use  * @param port      Port on the interface  *  * @return IPD port number  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_helper_get_ipd_port
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Returns the PKO port number for a port on the given interface,  * This is the base pko_port for o68 and ipd_port for older models.  *  * @param interface Interface to use  * @param port      Port on the interface  *  * @return PKO port number and -1 on error.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_helper_get_pko_port
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Returns the IPD/PKO port number for the first port on the given  * interface.  *  * @param interface Interface to use  *  * @return IPD/PKO port number  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|cvmx_helper_get_first_ipd_port
parameter_list|(
name|int
name|interface
parameter_list|)
block|{
return|return
operator|(
name|cvmx_helper_get_ipd_port
argument_list|(
name|interface
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Returns the IPD/PKO port number for the last port on the given  * interface.  *  * @param interface Interface to use  *  * @return IPD/PKO port number  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|cvmx_helper_get_last_ipd_port
parameter_list|(
name|int
name|interface
parameter_list|)
block|{
return|return
operator|(
name|cvmx_helper_get_first_ipd_port
argument_list|(
name|interface
argument_list|)
operator|+
name|cvmx_helper_ports_on_interface
argument_list|(
name|interface
argument_list|)
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Free the packet buffers contained in a work queue entry.  * The work queue entry is not freed.  *  * @param work   Work queue entry with packet to free  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|cvmx_helper_free_packet_data
parameter_list|(
name|cvmx_wqe_t
modifier|*
name|work
parameter_list|)
block|{
name|uint64_t
name|number_buffers
decl_stmt|;
name|cvmx_buf_ptr_t
name|buffer_ptr
decl_stmt|;
name|cvmx_buf_ptr_t
name|next_buffer_ptr
decl_stmt|;
name|uint64_t
name|start_of_buffer
decl_stmt|;
name|number_buffers
operator|=
name|work
operator|->
name|word2
operator|.
name|s
operator|.
name|bufs
expr_stmt|;
if|if
condition|(
name|number_buffers
operator|==
literal|0
condition|)
return|return;
name|buffer_ptr
operator|=
name|work
operator|->
name|packet_ptr
expr_stmt|;
comment|/* Since the number of buffers is not zero, we know this is not a dynamic         short packet. We need to check if it is a packet received with         IPD_CTL_STATUS[NO_WPTR]. If this is true, we need to free all buffers         except for the first one. The caller doesn't expect their WQE pointer         to be freed */
name|start_of_buffer
operator|=
operator|(
operator|(
name|buffer_ptr
operator|.
name|s
operator|.
name|addr
operator|>>
literal|7
operator|)
operator|-
name|buffer_ptr
operator|.
name|s
operator|.
name|back
operator|)
operator|<<
literal|7
expr_stmt|;
if|if
condition|(
name|cvmx_ptr_to_phys
argument_list|(
name|work
argument_list|)
operator|==
name|start_of_buffer
condition|)
block|{
name|next_buffer_ptr
operator|=
operator|*
operator|(
name|cvmx_buf_ptr_t
operator|*
operator|)
name|cvmx_phys_to_ptr
argument_list|(
name|buffer_ptr
operator|.
name|s
operator|.
name|addr
operator|-
literal|8
argument_list|)
expr_stmt|;
name|buffer_ptr
operator|=
name|next_buffer_ptr
expr_stmt|;
name|number_buffers
operator|--
expr_stmt|;
block|}
while|while
condition|(
name|number_buffers
operator|--
condition|)
block|{
comment|/* Remember the back pointer is in cache lines, not 64bit words */
name|start_of_buffer
operator|=
operator|(
operator|(
name|buffer_ptr
operator|.
name|s
operator|.
name|addr
operator|>>
literal|7
operator|)
operator|-
name|buffer_ptr
operator|.
name|s
operator|.
name|back
operator|)
operator|<<
literal|7
expr_stmt|;
comment|/* Read pointer to next buffer before we free the current buffer. */
name|next_buffer_ptr
operator|=
operator|*
operator|(
name|cvmx_buf_ptr_t
operator|*
operator|)
name|cvmx_phys_to_ptr
argument_list|(
name|buffer_ptr
operator|.
name|s
operator|.
name|addr
operator|-
literal|8
argument_list|)
expr_stmt|;
name|cvmx_fpa_free
argument_list|(
name|cvmx_phys_to_ptr
argument_list|(
name|start_of_buffer
argument_list|)
argument_list|,
name|buffer_ptr
operator|.
name|s
operator|.
name|pool
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|buffer_ptr
operator|=
name|next_buffer_ptr
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CVMX_ENABLE_HELPER_FUNCTIONS */
end_comment

begin_comment
comment|/**  * Returns the interface number for an IPD/PKO port number.  *  * @param ipd_port IPD/PKO port number  *  * @return Interface number  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_helper_get_interface_num
parameter_list|(
name|int
name|ipd_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Returns the interface index number for an IPD/PKO port  * number.  *  * @param ipd_port IPD/PKO port number  *  * @return Interface index number  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_helper_get_interface_index_num
parameter_list|(
name|int
name|ipd_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get port kind for a given port in an interface.  *  * @param interface  Interface  * @param port       index of the port in the interface  *  * @return port kind on sucicess  and -1 on failure  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_helper_get_pknd
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get bpid for a given port in an interface.  *  * @param interface  Interface  * @param port       index of the port in the interface  *  * @return port kind on sucicess  and -1 on failure  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_helper_get_bpid
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Internal functions.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|__cvmx_helper_post_init_interfaces
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__cvmx_helper_shutdown_interfaces
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cvmx_helper_show_stats
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_HELPER_H__ */
end_comment

end_unit

