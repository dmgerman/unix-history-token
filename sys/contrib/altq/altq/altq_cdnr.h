begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$KAME: altq_cdnr.h,v 1.9 2003/07/10 12:07:48 kjc Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1999-2002  *	Sony Computer Science Laboratories Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY SONY CSL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL SONY CSL OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALTQ_ALTQ_CDNR_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALTQ_ALTQ_CDNR_H_
end_define

begin_include
include|#
directive|include
file|<altq/altq.h>
end_include

begin_comment
comment|/*  * traffic conditioner element types  */
end_comment

begin_define
define|#
directive|define
name|TCETYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|TCETYPE_TOP
value|1
end_define

begin_comment
comment|/* top level conditioner */
end_comment

begin_define
define|#
directive|define
name|TCETYPE_ELEMENT
value|2
end_define

begin_comment
comment|/* a simple tc element */
end_comment

begin_define
define|#
directive|define
name|TCETYPE_TBMETER
value|3
end_define

begin_comment
comment|/* token bucket meter */
end_comment

begin_define
define|#
directive|define
name|TCETYPE_TRTCM
value|4
end_define

begin_comment
comment|/* (two-rate) three color marker */
end_comment

begin_define
define|#
directive|define
name|TCETYPE_TSWTCM
value|5
end_define

begin_comment
comment|/* time sliding window 3-color maker */
end_comment

begin_comment
comment|/*  * traffic conditioner action  */
end_comment

begin_struct_decl
struct_decl|struct
name|cdnr_block
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|tc_action
block|{
name|int
name|tca_code
decl_stmt|;
comment|/* e.g., TCACODE_PASS */
comment|/* tca_code dependent variable */
union|union
block|{
name|u_long
name|un_value
decl_stmt|;
comment|/* template */
name|u_int8_t
name|un_dscp
decl_stmt|;
comment|/* diffserv code point */
name|u_long
name|un_handle
decl_stmt|;
comment|/* tc action handle */
name|struct
name|cdnr_block
modifier|*
name|un_next
decl_stmt|;
comment|/* next tc element block */
block|}
name|tca_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tca_value
value|tca_un.un_value
end_define

begin_define
define|#
directive|define
name|tca_dscp
value|tca_un.un_dscp
end_define

begin_define
define|#
directive|define
name|tca_handle
value|tca_un.un_handle
end_define

begin_define
define|#
directive|define
name|tca_next
value|tca_un.un_next
end_define

begin_define
define|#
directive|define
name|TCACODE_NONE
value|0
end_define

begin_comment
comment|/* action is not set */
end_comment

begin_define
define|#
directive|define
name|TCACODE_PASS
value|1
end_define

begin_comment
comment|/* pass this packet */
end_comment

begin_define
define|#
directive|define
name|TCACODE_DROP
value|2
end_define

begin_comment
comment|/* discard this packet */
end_comment

begin_define
define|#
directive|define
name|TCACODE_RETURN
value|3
end_define

begin_comment
comment|/* do not process this packet */
end_comment

begin_define
define|#
directive|define
name|TCACODE_MARK
value|4
end_define

begin_comment
comment|/* mark dscp */
end_comment

begin_define
define|#
directive|define
name|TCACODE_HANDLE
value|5
end_define

begin_comment
comment|/* take action specified by handle */
end_comment

begin_define
define|#
directive|define
name|TCACODE_NEXT
value|6
end_define

begin_comment
comment|/* take action in the next tc element */
end_comment

begin_define
define|#
directive|define
name|TCACODE_MAX
value|6
end_define

begin_define
define|#
directive|define
name|CDNR_NULL_HANDLE
value|0
end_define

begin_struct
struct|struct
name|cdnr_interface
block|{
name|char
name|cdnr_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* interface name (e.g., fxp0) */
block|}
struct|;
end_struct

begin_comment
comment|/* simple element operations */
end_comment

begin_struct
struct|struct
name|cdnr_add_element
block|{
name|struct
name|cdnr_interface
name|iface
decl_stmt|;
name|struct
name|tc_action
name|action
decl_stmt|;
name|u_long
name|cdnr_handle
decl_stmt|;
comment|/* return value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cdnr_delete_element
block|{
name|struct
name|cdnr_interface
name|iface
decl_stmt|;
name|u_long
name|cdnr_handle
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* token-bucket meter operations */
end_comment

begin_struct
struct|struct
name|cdnr_add_tbmeter
block|{
name|struct
name|cdnr_interface
name|iface
decl_stmt|;
name|struct
name|tb_profile
name|profile
decl_stmt|;
name|struct
name|tc_action
name|in_action
decl_stmt|;
name|struct
name|tc_action
name|out_action
decl_stmt|;
name|u_long
name|cdnr_handle
decl_stmt|;
comment|/* return value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cdnr_modify_tbmeter
block|{
name|struct
name|cdnr_interface
name|iface
decl_stmt|;
name|u_long
name|cdnr_handle
decl_stmt|;
name|struct
name|tb_profile
name|profile
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cdnr_tbmeter_stats
block|{
name|struct
name|cdnr_interface
name|iface
decl_stmt|;
name|u_long
name|cdnr_handle
decl_stmt|;
name|struct
name|pktcntr
name|in_cnt
decl_stmt|;
name|struct
name|pktcntr
name|out_cnt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* two-rate three-color marker operations */
end_comment

begin_struct
struct|struct
name|cdnr_add_trtcm
block|{
name|struct
name|cdnr_interface
name|iface
decl_stmt|;
name|struct
name|tb_profile
name|cmtd_profile
decl_stmt|;
comment|/* profile for committed tb */
name|struct
name|tb_profile
name|peak_profile
decl_stmt|;
comment|/* profile for peak tb */
name|struct
name|tc_action
name|green_action
decl_stmt|;
comment|/* action for green packets */
name|struct
name|tc_action
name|yellow_action
decl_stmt|;
comment|/* action for yellow packets */
name|struct
name|tc_action
name|red_action
decl_stmt|;
comment|/* action for red packets */
name|int
name|coloraware
decl_stmt|;
comment|/* color-aware/color-blind */
name|u_long
name|cdnr_handle
decl_stmt|;
comment|/* return value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cdnr_modify_trtcm
block|{
name|struct
name|cdnr_interface
name|iface
decl_stmt|;
name|u_long
name|cdnr_handle
decl_stmt|;
name|struct
name|tb_profile
name|cmtd_profile
decl_stmt|;
comment|/* profile for committed tb */
name|struct
name|tb_profile
name|peak_profile
decl_stmt|;
comment|/* profile for peak tb */
name|int
name|coloraware
decl_stmt|;
comment|/* color-aware/color-blind */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cdnr_tcm_stats
block|{
name|struct
name|cdnr_interface
name|iface
decl_stmt|;
name|u_long
name|cdnr_handle
decl_stmt|;
name|struct
name|pktcntr
name|green_cnt
decl_stmt|;
name|struct
name|pktcntr
name|yellow_cnt
decl_stmt|;
name|struct
name|pktcntr
name|red_cnt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* time sliding window three-color marker operations */
end_comment

begin_struct
struct|struct
name|cdnr_add_tswtcm
block|{
name|struct
name|cdnr_interface
name|iface
decl_stmt|;
name|u_int32_t
name|cmtd_rate
decl_stmt|;
comment|/* committed rate (bits/sec) */
name|u_int32_t
name|peak_rate
decl_stmt|;
comment|/* peak rate (bits/sec) */
name|u_int32_t
name|avg_interval
decl_stmt|;
comment|/* averaging interval (msec) */
name|struct
name|tc_action
name|green_action
decl_stmt|;
comment|/* action for green packets */
name|struct
name|tc_action
name|yellow_action
decl_stmt|;
comment|/* action for yellow packets */
name|struct
name|tc_action
name|red_action
decl_stmt|;
comment|/* action for red packets */
name|u_long
name|cdnr_handle
decl_stmt|;
comment|/* return value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cdnr_modify_tswtcm
block|{
name|struct
name|cdnr_interface
name|iface
decl_stmt|;
name|u_long
name|cdnr_handle
decl_stmt|;
name|u_int32_t
name|cmtd_rate
decl_stmt|;
comment|/* committed rate (bits/sec) */
name|u_int32_t
name|peak_rate
decl_stmt|;
comment|/* peak rate (bits/sec) */
name|u_int32_t
name|avg_interval
decl_stmt|;
comment|/* averaging interval (msec) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cdnr_add_filter
block|{
name|struct
name|cdnr_interface
name|iface
decl_stmt|;
name|u_long
name|cdnr_handle
decl_stmt|;
ifdef|#
directive|ifdef
name|ALTQ3_CLFIER_COMPAT
name|struct
name|flow_filter
name|filter
decl_stmt|;
endif|#
directive|endif
name|u_long
name|filter_handle
decl_stmt|;
comment|/* return value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cdnr_delete_filter
block|{
name|struct
name|cdnr_interface
name|iface
decl_stmt|;
name|u_long
name|filter_handle
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tce_stats
block|{
name|u_long
name|tce_handle
decl_stmt|;
comment|/* tc element handle */
name|int
name|tce_type
decl_stmt|;
comment|/* e.g., TCETYPE_ELEMENT */
name|struct
name|pktcntr
name|tce_cnts
index|[
literal|3
index|]
decl_stmt|;
comment|/* tcm returns 3 counters */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cdnr_get_stats
block|{
name|struct
name|cdnr_interface
name|iface
decl_stmt|;
name|struct
name|pktcntr
name|cnts
index|[
name|TCACODE_MAX
operator|+
literal|1
index|]
decl_stmt|;
comment|/* element stats */
name|int
name|nskip
decl_stmt|;
comment|/* skip # of elements */
name|int
name|nelements
decl_stmt|;
comment|/* # of element stats (WR) */
name|struct
name|tce_stats
modifier|*
name|tce_stats
decl_stmt|;
comment|/* pointer to stats array */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CDNR_IF_ATTACH
value|_IOW('Q', 1, struct cdnr_interface)
end_define

begin_define
define|#
directive|define
name|CDNR_IF_DETACH
value|_IOW('Q', 2, struct cdnr_interface)
end_define

begin_define
define|#
directive|define
name|CDNR_ENABLE
value|_IOW('Q', 3, struct cdnr_interface)
end_define

begin_define
define|#
directive|define
name|CDNR_DISABLE
value|_IOW('Q', 4, struct cdnr_interface)
end_define

begin_define
define|#
directive|define
name|CDNR_ADD_FILTER
value|_IOWR('Q', 10, struct cdnr_add_filter)
end_define

begin_define
define|#
directive|define
name|CDNR_DEL_FILTER
value|_IOW('Q', 11, struct cdnr_delete_filter)
end_define

begin_define
define|#
directive|define
name|CDNR_GETSTATS
value|_IOWR('Q', 12, struct cdnr_get_stats)
end_define

begin_define
define|#
directive|define
name|CDNR_ADD_ELEM
value|_IOWR('Q', 30, struct cdnr_add_element)
end_define

begin_define
define|#
directive|define
name|CDNR_DEL_ELEM
value|_IOW('Q', 31, struct cdnr_delete_element)
end_define

begin_define
define|#
directive|define
name|CDNR_ADD_TBM
value|_IOWR('Q', 32, struct cdnr_add_tbmeter)
end_define

begin_define
define|#
directive|define
name|CDNR_MOD_TBM
value|_IOW('Q', 33, struct cdnr_modify_tbmeter)
end_define

begin_define
define|#
directive|define
name|CDNR_TBM_STATS
value|_IOWR('Q', 34, struct cdnr_tbmeter_stats)
end_define

begin_define
define|#
directive|define
name|CDNR_ADD_TCM
value|_IOWR('Q', 35, struct cdnr_add_trtcm)
end_define

begin_define
define|#
directive|define
name|CDNR_MOD_TCM
value|_IOWR('Q', 36, struct cdnr_modify_trtcm)
end_define

begin_define
define|#
directive|define
name|CDNR_TCM_STATS
value|_IOWR('Q', 37, struct cdnr_tcm_stats)
end_define

begin_define
define|#
directive|define
name|CDNR_ADD_TSW
value|_IOWR('Q', 38, struct cdnr_add_tswtcm)
end_define

begin_define
define|#
directive|define
name|CDNR_MOD_TSW
value|_IOWR('Q', 39, struct cdnr_modify_tswtcm)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DSCP_EF
end_ifndef

begin_comment
comment|/* diffserve code points */
end_comment

begin_define
define|#
directive|define
name|DSCP_MASK
value|0xfc
end_define

begin_define
define|#
directive|define
name|DSCP_CUMASK
value|0x03
end_define

begin_define
define|#
directive|define
name|DSCP_EF
value|0xb8
end_define

begin_define
define|#
directive|define
name|DSCP_AF11
value|0x28
end_define

begin_define
define|#
directive|define
name|DSCP_AF12
value|0x30
end_define

begin_define
define|#
directive|define
name|DSCP_AF13
value|0x38
end_define

begin_define
define|#
directive|define
name|DSCP_AF21
value|0x48
end_define

begin_define
define|#
directive|define
name|DSCP_AF22
value|0x50
end_define

begin_define
define|#
directive|define
name|DSCP_AF23
value|0x58
end_define

begin_define
define|#
directive|define
name|DSCP_AF31
value|0x68
end_define

begin_define
define|#
directive|define
name|DSCP_AF32
value|0x70
end_define

begin_define
define|#
directive|define
name|DSCP_AF33
value|0x78
end_define

begin_define
define|#
directive|define
name|DSCP_AF41
value|0x88
end_define

begin_define
define|#
directive|define
name|DSCP_AF42
value|0x90
end_define

begin_define
define|#
directive|define
name|DSCP_AF43
value|0x98
end_define

begin_define
define|#
directive|define
name|AF_CLASSMASK
value|0xe0
end_define

begin_define
define|#
directive|define
name|AF_DROPPRECMASK
value|0x18
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * packet information passed to the input function of tc elements  */
end_comment

begin_struct
struct|struct
name|cdnr_pktinfo
block|{
name|int
name|pkt_len
decl_stmt|;
comment|/* packet length */
name|u_int8_t
name|pkt_dscp
decl_stmt|;
comment|/* diffserv code point */
block|}
struct|;
end_struct

begin_comment
comment|/*  * traffic conditioner control block common to all types of tc elements  */
end_comment

begin_struct
struct|struct
name|cdnr_block
block|{
name|LIST_ENTRY
argument_list|(
argument|cdnr_block
argument_list|)
name|cb_next
expr_stmt|;
name|int
name|cb_len
decl_stmt|;
comment|/* size of this tc element */
name|int
name|cb_type
decl_stmt|;
comment|/* cdnr block type */
name|int
name|cb_ref
decl_stmt|;
comment|/* reference count of this element */
name|u_long
name|cb_handle
decl_stmt|;
comment|/* handle of this tc element */
name|struct
name|top_cdnr
modifier|*
name|cb_top
decl_stmt|;
comment|/* back pointer to top */
name|struct
name|tc_action
name|cb_action
decl_stmt|;
comment|/* top level action for this tcb */
name|struct
name|tc_action
modifier|*
function_decl|(
modifier|*
name|cb_input
function_decl|)
parameter_list|(
name|struct
name|cdnr_block
modifier|*
parameter_list|,
name|struct
name|cdnr_pktinfo
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * top level traffic conditioner structure for an interface  */
end_comment

begin_struct
struct|struct
name|top_cdnr
block|{
name|struct
name|cdnr_block
name|tc_block
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|top_cdnr
argument_list|)
name|tc_next
expr_stmt|;
name|struct
name|ifaltq
modifier|*
name|tc_ifq
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|cdnr_block
argument_list|)
name|tc_elements
expr_stmt|;
ifdef|#
directive|ifdef
name|ALTQ3_CLFIER_COMPAT
name|struct
name|acc_classifier
name|tc_classifier
decl_stmt|;
endif|#
directive|endif
name|struct
name|pktcntr
name|tc_cnts
index|[
name|TCACODE_MAX
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* token bucket element */
end_comment

begin_struct
struct|struct
name|tbe
block|{
name|u_int64_t
name|rate
decl_stmt|;
name|u_int64_t
name|depth
decl_stmt|;
name|u_int64_t
name|token
decl_stmt|;
name|u_int64_t
name|filluptime
decl_stmt|;
name|u_int64_t
name|last
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* token bucket meter structure */
end_comment

begin_struct
struct|struct
name|tbmeter
block|{
name|struct
name|cdnr_block
name|cdnrblk
decl_stmt|;
comment|/* conditioner block */
name|struct
name|tbe
name|tb
decl_stmt|;
comment|/* token bucket */
name|struct
name|tc_action
name|in_action
decl_stmt|;
comment|/* actions for IN/OUT */
name|struct
name|tc_action
name|out_action
decl_stmt|;
comment|/* actions for IN/OUT */
name|struct
name|pktcntr
name|in_cnt
decl_stmt|;
comment|/* statistics for IN/OUT */
name|struct
name|pktcntr
name|out_cnt
decl_stmt|;
comment|/* statistics for IN/OUT */
block|}
struct|;
end_struct

begin_comment
comment|/* two-rate three-color marker structure */
end_comment

begin_struct
struct|struct
name|trtcm
block|{
name|struct
name|cdnr_block
name|cdnrblk
decl_stmt|;
comment|/* conditioner block */
name|struct
name|tbe
name|cmtd_tb
decl_stmt|;
comment|/* committed tb profile */
name|struct
name|tbe
name|peak_tb
decl_stmt|;
comment|/* peak tb profile */
name|struct
name|tc_action
name|green_action
decl_stmt|;
name|struct
name|tc_action
name|yellow_action
decl_stmt|;
name|struct
name|tc_action
name|red_action
decl_stmt|;
name|int
name|coloraware
decl_stmt|;
name|u_int8_t
name|green_dscp
decl_stmt|;
name|u_int8_t
name|yellow_dscp
decl_stmt|;
name|u_int8_t
name|red_dscp
decl_stmt|;
name|struct
name|pktcntr
name|green_cnt
decl_stmt|;
name|struct
name|pktcntr
name|yellow_cnt
decl_stmt|;
name|struct
name|pktcntr
name|red_cnt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* time sliding window three-color marker structure */
end_comment

begin_struct
struct|struct
name|tswtcm
block|{
name|struct
name|cdnr_block
name|cdnrblk
decl_stmt|;
comment|/* conditioner block */
name|u_int32_t
name|avg_rate
decl_stmt|;
comment|/* average rate (bytes/sec) */
name|u_int64_t
name|t_front
decl_stmt|;
comment|/* timestamp of last update */
name|u_int64_t
name|timewin
decl_stmt|;
comment|/* average interval */
name|u_int32_t
name|cmtd_rate
decl_stmt|;
comment|/* committed target rate */
name|u_int32_t
name|peak_rate
decl_stmt|;
comment|/* peak target rate */
name|struct
name|tc_action
name|green_action
decl_stmt|;
name|struct
name|tc_action
name|yellow_action
decl_stmt|;
name|struct
name|tc_action
name|red_action
decl_stmt|;
name|u_int8_t
name|green_dscp
decl_stmt|;
name|u_int8_t
name|yellow_dscp
decl_stmt|;
name|u_int8_t
name|red_dscp
decl_stmt|;
name|struct
name|pktcntr
name|green_cnt
decl_stmt|;
name|struct
name|pktcntr
name|yellow_cnt
decl_stmt|;
name|struct
name|pktcntr
name|red_cnt
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALTQ_ALTQ_CDNR_H_ */
end_comment

end_unit

