begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/fptr_wlist.h - function pointer whitelists.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions that check function pointers.  * The functions contain a whitelist of known good callback values.  * Any other values lead to an error.   *   * This prevent heap overflow based exploits, where the callback pointer  * is overwritten by a buffer overflow (apart from this defense, buffer   * overflows should be fixed of course).  *  * Function pointers are used in  * 	o network code callbacks.  * 	o rbtree, lruhash, region data manipulation  *		in lruhash, the assertions are before the critical regions.  *		in other places, assertions are before the callback.  * 	o module operations.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_FPTR_WLIST_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_FPTR_WLIST_H
end_define

begin_include
include|#
directive|include
file|"util/netevent.h"
end_include

begin_include
include|#
directive|include
file|"util/storage/lruhash.h"
end_include

begin_include
include|#
directive|include
file|"util/module.h"
end_include

begin_include
include|#
directive|include
file|"util/tube.h"
end_include

begin_include
include|#
directive|include
file|"services/mesh.h"
end_include

begin_comment
comment|/**  * Macro to perform an assertion check for fptr wlist checks.  * Does not get disabled in optimize mode. Check adds security by layers.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EXPORT_ALL_SYMBOLS
argument_list|)
end_if

begin_define
define|#
directive|define
name|fptr_ok
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* nothing, dll-exe memory layout on win disables it */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|fptr_ok
parameter_list|(
name|x
parameter_list|)
define|\
value|do { if(!(x)) \ 		fatal_exit("%s:%d: %s: pointer whitelist %s failed", \ 		__FILE__, __LINE__, __func__, #x); \ 	} while(0);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * Check function pointer whitelist for comm_point callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_comm_point
parameter_list|(
name|comm_point_callback_t
modifier|*
name|fptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for raw comm_point callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_comm_point_raw
parameter_list|(
name|comm_point_callback_t
modifier|*
name|fptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for comm_timer callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_comm_timer
parameter_list|(
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for comm_signal callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_comm_signal
parameter_list|(
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for start_accept callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_start_accept
parameter_list|(
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for stop_accept callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_stop_accept
parameter_list|(
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for event structure callback values.  * This is not called by libevent itself, but checked by netevent.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_event
parameter_list|(
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|short
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for pending udp callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_pending_udp
parameter_list|(
name|comm_point_callback_t
modifier|*
name|fptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for pending tcp callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_pending_tcp
parameter_list|(
name|comm_point_callback_t
modifier|*
name|fptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for serviced query callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_serviced_query
parameter_list|(
name|comm_point_callback_t
modifier|*
name|fptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for rbtree cmp callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_rbtree_cmp
parameter_list|(
name|int
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for lruhash sizefunc callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_hash_sizefunc
parameter_list|(
name|lruhash_sizefunc_t
name|fptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for lruhash compfunc callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_hash_compfunc
parameter_list|(
name|lruhash_compfunc_t
name|fptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for lruhash delkeyfunc callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_hash_delkeyfunc
parameter_list|(
name|lruhash_delkeyfunc_t
name|fptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for lruhash deldata callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_hash_deldatafunc
parameter_list|(
name|lruhash_deldatafunc_t
name|fptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for lruhash markdel callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_hash_markdelfunc
parameter_list|(
name|lruhash_markdelfunc_t
name|fptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for module_env send_query callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_decl_stmt
name|int
name|fptr_whitelist_modenv_send_query
argument_list|(
expr|struct
name|outbound_entry
operator|*
operator|(
operator|*
name|fptr
operator|)
operator|(
name|uint8_t
operator|*
name|qname
operator|,
name|size_t
name|qnamelen
operator|,
name|uint16_t
name|qtype
operator|,
name|uint16_t
name|qclass
operator|,
name|uint16_t
name|flags
operator|,
name|int
name|dnssec
operator|,
name|int
name|want_dnssec
operator|,
expr|struct
name|sockaddr_storage
operator|*
name|addr
operator|,
name|socklen_t
name|addrlen
operator|,
name|uint8_t
operator|*
name|zone
operator|,
name|size_t
name|zonelen
operator|,
expr|struct
name|module_qstate
operator|*
name|q
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * Check function pointer whitelist for module_env detach_subs callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_modenv_detach_subs
parameter_list|(
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for module_env attach_sub callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_modenv_attach_sub
parameter_list|(
name|int
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|uint16_t
name|qflags
parameter_list|,
name|int
name|prime
parameter_list|,
name|struct
name|module_qstate
modifier|*
modifier|*
name|newq
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for module_env kill_sub callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_modenv_kill_sub
parameter_list|(
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|newq
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for module_env detect_cycle callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_modenv_detect_cycle
parameter_list|(
name|int
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|uint16_t
name|flags
parameter_list|,
name|int
name|prime
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for module init call values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_mod_init
parameter_list|(
name|int
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|int
name|id
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for module deinit call values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_mod_deinit
parameter_list|(
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|int
name|id
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for module operate call values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_mod_operate
parameter_list|(
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|enum
name|module_ev
name|event
parameter_list|,
name|int
name|id
parameter_list|,
name|struct
name|outbound_entry
modifier|*
name|outbound
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for module inform_super call values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_mod_inform_super
parameter_list|(
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|int
name|id
parameter_list|,
name|struct
name|module_qstate
modifier|*
name|super
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for module clear call values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_mod_clear
parameter_list|(
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|int
name|id
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for module get_mem call values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_mod_get_mem
parameter_list|(
name|size_t
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|int
name|id
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for alloc clear on id overflow call values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_alloc_cleanup
parameter_list|(
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for tube listen handler values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_tube_listen
parameter_list|(
name|tube_callback_t
modifier|*
name|fptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for mesh state callback values.  *  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_mesh_cb
parameter_list|(
name|mesh_cb_func_t
name|fptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check function pointer whitelist for config_get_option func values.  * @param fptr: function pointer to check.  * @return false if not in whitelist.  */
end_comment

begin_function_decl
name|int
name|fptr_whitelist_print_func
parameter_list|(
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Due to module breakage by fptr wlist, these test app declarations  * are presented here */
end_comment

begin_comment
comment|/**   * compare two order_ids from lock-verify test app   * @param e1: first order_id  * @param e2: second order_id  * @return compare code -1, 0, +1 (like memcmp).  */
end_comment

begin_function_decl
name|int
name|order_lock_cmp
parameter_list|(
specifier|const
name|void
modifier|*
name|e1
parameter_list|,
specifier|const
name|void
modifier|*
name|e2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * compare two codeline structs for rbtree from memstats test app   * @param a: codeline  * @param b: codeline  * @return compare code -1, 0, +1 (like memcmp).  */
end_comment

begin_function_decl
name|int
name|codeline_cmp
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
specifier|const
name|void
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** compare two replay_vars */
end_comment

begin_function_decl
name|int
name|replay_var_compare
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
specifier|const
name|void
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_FPTR_WLIST_H */
end_comment

end_unit

