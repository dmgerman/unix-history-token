begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSMV_TXN_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSMV_TXN_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qmap.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_madw.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_event_wheel.h>
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor_mlx_rmpp_ctx.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__cplusplus */
end_comment

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_macro
name|BEGIN_C_DECLS
end_macro

begin_typedef
typedef|typedef
enum|enum
name|_osmv_txn_rmpp_state
block|{
name|OSMV_TXN_RMPP_NONE
init|=
literal|0
block|,
comment|/* Not part of RMPP transaction */
name|OSMV_TXN_RMPP_SENDER
block|,
name|OSMV_TXN_RMPP_RECEIVER
block|}
name|osmv_txn_rmpp_state_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_osmv_rmpp_txfr
block|{
name|osmv_txn_rmpp_state_t
name|rmpp_state
decl_stmt|;
name|boolean_t
name|is_rmpp_init_by_peer
decl_stmt|;
name|osmv_rmpp_send_ctx_t
modifier|*
name|p_rmpp_send_ctx
decl_stmt|;
name|osmv_rmpp_recv_ctx_t
modifier|*
name|p_rmpp_recv_ctx
decl_stmt|;
block|}
name|osmv_rmpp_txfr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_osmv_txn_ctx
block|{
comment|/* The original Transaction ID */
name|uint64_t
name|tid
decl_stmt|;
comment|/* The key by which the Transaction is stored */
name|uint64_t
name|key
decl_stmt|;
comment|/* RMPP Send/Receive contexts, if applicable */
name|osmv_rmpp_txfr_t
name|rmpp_txfr
decl_stmt|;
comment|/* A MAD that was sent during the transaction (request or response) */
name|osm_madw_t
modifier|*
name|p_madw
decl_stmt|;
comment|/* Reference to a log to enable tracing */
name|osm_log_t
modifier|*
name|p_log
decl_stmt|;
block|}
name|osmv_txn_ctx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_osmv_txn_mgr
block|{
comment|/* Container of all the transactions */
name|cl_qmap_t
modifier|*
name|p_txn_map
decl_stmt|;
comment|/* The timeouts DB */
name|cl_event_wheel_t
modifier|*
name|p_event_wheel
decl_stmt|;
comment|/* Reference to a log to enable tracing */
name|osm_log_t
modifier|*
name|p_log
decl_stmt|;
block|}
name|osmv_txn_mgr_t
typedef|;
end_typedef

begin_comment
comment|/* *    *   *   *   *   *   osmv_txn_ctx_t functions  *    *   *   *   *   *   *   *   */
end_comment

begin_comment
comment|/*  * NAME  *   osmv_txn_init  *  * DESCRIPTION  *   allocs& inits the osmv_txn_ctx obj and insert it into the db  * SEE ALSO  *  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_txn_init
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
name|uint64_t
name|tid
parameter_list|,
name|IN
name|uint64_t
name|key
parameter_list|,
name|OUT
name|osmv_txn_ctx_t
modifier|*
modifier|*
name|pp_txn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *   osmv_rmpp_txfr_init_sender  *  * DESCRIPTION  *   init the rmpp send ctx in the transaction  *  * SEE ALSO  *  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_txn_init_rmpp_sender
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
name|osmv_txn_ctx_t
modifier|*
name|p_txn
parameter_list|,
name|IN
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *   osmv_rmpp_txfr_init_receiver  *  * DESCRIPTION  *   init the rmpp recv ctx in the transaction  *  * SEE ALSO  *  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_txn_init_rmpp_receiver
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
name|osmv_txn_ctx_t
modifier|*
name|p_txn
parameter_list|,
name|IN
name|boolean_t
name|is_init_by_peer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *   osmv_txn_done  *  * DESCRIPTION  *   destroys txn object and removes it from the db  *  * SEE ALSO  *  */
end_comment

begin_function_decl
name|void
name|osmv_txn_done
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
name|uint64_t
name|key
parameter_list|,
name|IN
name|boolean_t
name|is_in_cb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *   osmv_txn_get_tid  *  * DESCRIPTION  *   returns tid of the transaction  * SEE ALSO  *  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint64_t
name|osmv_txn_get_tid
parameter_list|(
name|IN
name|osmv_txn_ctx_t
modifier|*
name|p_txn
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|NULL
operator|!=
name|p_txn
argument_list|)
expr_stmt|;
return|return
name|p_txn
operator|->
name|tid
return|;
block|}
end_function

begin_comment
comment|/*  * NAME  *   osmv_txn_get_key  *  * DESCRIPTION  *   returns key of the transaction  * SEE ALSO  *  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint64_t
name|osmv_txn_get_key
parameter_list|(
name|IN
name|osmv_txn_ctx_t
modifier|*
name|p_txn
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|NULL
operator|!=
name|p_txn
argument_list|)
expr_stmt|;
return|return
name|p_txn
operator|->
name|key
return|;
block|}
end_function

begin_comment
comment|/*  * NAME  *   osmv_txn_is_rmpp_init_by_peer  *  * DESCRIPTION  *   returns whether the rmpp txfr was init by the peer  *  * SEE ALSO  *  */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|osmv_txn_is_rmpp_init_by_peer
parameter_list|(
name|IN
name|osmv_txn_ctx_t
modifier|*
name|p_txn
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|NULL
operator|!=
name|p_txn
argument_list|)
expr_stmt|;
return|return
name|p_txn
operator|->
name|rmpp_txfr
operator|.
name|is_rmpp_init_by_peer
return|;
block|}
end_function

begin_comment
comment|/*  * NAME  *   osmv_txn_get_rmpp_send_ctx  *  * DESCRIPTION  *   returns osmv_rmpp_send_ctx obj  * SEE ALSO  *  */
end_comment

begin_function
specifier|static
specifier|inline
name|osmv_rmpp_send_ctx_t
modifier|*
name|osmv_txn_get_rmpp_send_ctx
parameter_list|(
name|IN
name|osmv_txn_ctx_t
modifier|*
name|p_txn
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|NULL
operator|!=
name|p_txn
argument_list|)
expr_stmt|;
return|return
name|p_txn
operator|->
name|rmpp_txfr
operator|.
name|p_rmpp_send_ctx
return|;
block|}
end_function

begin_comment
comment|/*  * NAME  *   osmv_txn_get_rmpp_recv_ctx  *  * DESCRIPTION  *   returns osmv_rmpp_recv_ctx obj  * SEE ALSO  *  */
end_comment

begin_function
specifier|static
specifier|inline
name|osmv_rmpp_recv_ctx_t
modifier|*
name|osmv_txn_get_rmpp_recv_ctx
parameter_list|(
name|IN
name|osmv_txn_ctx_t
modifier|*
name|p_txn
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|NULL
operator|!=
name|p_txn
argument_list|)
expr_stmt|;
return|return
name|p_txn
operator|->
name|rmpp_txfr
operator|.
name|p_rmpp_recv_ctx
return|;
block|}
end_function

begin_comment
comment|/*  * NAME  *   osmv_txn_get_rmpp_state  *  * DESCRIPTION  *   returns the rmpp role of the transactino ( send/ recv)  * SEE ALSO  *  */
end_comment

begin_function
specifier|static
specifier|inline
name|osmv_txn_rmpp_state_t
name|osmv_txn_get_rmpp_state
parameter_list|(
name|IN
name|osmv_txn_ctx_t
modifier|*
name|p_txn
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|NULL
operator|!=
name|p_txn
argument_list|)
expr_stmt|;
return|return
name|p_txn
operator|->
name|rmpp_txfr
operator|.
name|rmpp_state
return|;
block|}
end_function

begin_comment
comment|/*  * NAME  *   osmv_txn_set_rmpp_state  *  * DESCRIPTION  *   sets the rmpp role of the transaction (send/ recv)  * SEE ALSO  *  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osmv_txn_set_rmpp_state
parameter_list|(
name|IN
name|osmv_txn_ctx_t
modifier|*
name|p_txn
parameter_list|,
name|IN
name|osmv_txn_rmpp_state_t
name|state
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|NULL
operator|!=
name|p_txn
argument_list|)
expr_stmt|;
name|p_txn
operator|->
name|rmpp_txfr
operator|.
name|rmpp_state
operator|=
name|state
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * NAME  *   osmv_txn_get_madw  *  * DESCRIPTION  *   returns the requester madw  * SEE ALSO  *  */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_madw_t
modifier|*
name|osmv_txn_get_madw
parameter_list|(
name|IN
name|osmv_txn_ctx_t
modifier|*
name|p_txn
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|NULL
operator|!=
name|p_txn
argument_list|)
expr_stmt|;
return|return
name|p_txn
operator|->
name|p_madw
return|;
block|}
end_function

begin_comment
comment|/*  * NAME  *   osmv_txn_set_madw  *  * DESCRIPTION  *   sets the requester madw  * SEE ALSO  *  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osmv_txn_set_madw
parameter_list|(
name|IN
name|osmv_txn_ctx_t
modifier|*
name|p_txn
parameter_list|,
name|IN
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|NULL
operator|!=
name|p_txn
argument_list|)
expr_stmt|;
name|p_txn
operator|->
name|p_madw
operator|=
name|p_madw
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * NAME  *  osmv_txn_set_timeout_ev  *  * DESCRIPTION  *  * SEE ALSO  *  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_txn_set_timeout_ev
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
name|uint64_t
name|key
parameter_list|,
name|IN
name|uint64_t
name|msec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *  osmv_txn_remove_timeout_ev  *  * DESCRIPTION   * SEE ALSO  *  */
end_comment

begin_function_decl
name|void
name|osmv_txn_remove_timeout_ev
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
name|uint64_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *  osmv_txn_lookup  *  * DESCRIPTION  *   get a transaction by its key  *  * SEE ALSO  *  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_txn_lookup
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
name|uint64_t
name|key
parameter_list|,
name|OUT
name|osmv_txn_ctx_t
modifier|*
modifier|*
name|pp_txn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osmv_txn_abort_rmpp_txns
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*      *       *       *       *       *       *       *       *       *       *       *       */
end_comment

begin_comment
comment|/*  * NAME  *  osmv_txnmgr_init  *  * DESCRIPTION  *  c'tor for txn mgr obj  * SEE ALSO  *  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_txnmgr_init
parameter_list|(
name|IN
name|osmv_txn_mgr_t
modifier|*
name|p_tx_mgr
parameter_list|,
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|cl_spinlock_t
modifier|*
name|p_lock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NAME  *  osmv_txnmgr_done  *  * DESCRIPTION  *  c'tor for txn mgr obj  * SEE ALSO  *  */
end_comment

begin_function_decl
name|void
name|osmv_txnmgr_done
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osmv_txn_lock
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osmv_txn_unlock
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|inline
specifier|static
name|uint64_t
name|osmv_txn_uniq_key
parameter_list|(
name|IN
name|uint64_t
name|tid
parameter_list|)
block|{
name|uint64_t
name|pid
init|=
name|getpid
argument_list|()
decl_stmt|;
return|return
operator|(
operator|(
name|pid
operator|<<
literal|32
operator|)
operator||
operator|(
name|tid
operator|&
literal|0xFFFFFFFF
operator|)
operator|)
return|;
block|}
end_function

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSMV_TXN_H_ */
end_comment

end_unit

