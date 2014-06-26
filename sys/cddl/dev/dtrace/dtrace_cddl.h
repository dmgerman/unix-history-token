begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DTRACE_CDDL_H_
end_ifndef

begin_define
define|#
directive|define
name|_DTRACE_CDDL_H_
end_define

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_define
define|#
directive|define
name|LOCK_LEVEL
value|10
end_define

begin_comment
comment|/*  * Kernel DTrace extension to 'struct proc' for FreeBSD.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|kdtrace_proc
block|{
name|int
name|p_dtrace_probes
decl_stmt|;
comment|/* Are there probes for this proc? */
name|u_int64_t
name|p_dtrace_count
decl_stmt|;
comment|/* Number of DTrace tracepoints */
name|void
modifier|*
name|p_dtrace_helpers
decl_stmt|;
comment|/* DTrace helpers, if any */
name|int
name|p_dtrace_model
decl_stmt|;
block|}
name|kdtrace_proc_t
typedef|;
end_typedef

begin_comment
comment|/*  * Kernel DTrace extension to 'struct thread' for FreeBSD.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|kdtrace_thread
block|{
name|u_int8_t
name|td_dtrace_stop
decl_stmt|;
comment|/* Indicates a DTrace-desired stop */
name|u_int8_t
name|td_dtrace_sig
decl_stmt|;
comment|/* Signal sent via DTrace's raise() */
name|u_int
name|td_predcache
decl_stmt|;
comment|/* DTrace predicate cache */
name|u_int64_t
name|td_dtrace_vtime
decl_stmt|;
comment|/* DTrace virtual time */
name|u_int64_t
name|td_dtrace_start
decl_stmt|;
comment|/* DTrace slice start time */
union|union
name|__tdu
block|{
struct|struct
name|__tds
block|{
name|u_int8_t
name|_td_dtrace_on
decl_stmt|;
comment|/* Hit a fasttrap tracepoint. */
name|u_int8_t
name|_td_dtrace_step
decl_stmt|;
comment|/* About to return to kernel. */
name|u_int8_t
name|_td_dtrace_ret
decl_stmt|;
comment|/* Handling a return probe. */
name|u_int8_t
name|_td_dtrace_ast
decl_stmt|;
comment|/* Saved ast flag. */
ifdef|#
directive|ifdef
name|__amd64__
name|u_int8_t
name|_td_dtrace_reg
decl_stmt|;
endif|#
directive|endif
block|}
name|_tds
struct|;
name|u_long
name|_td_dtrace_ft
decl_stmt|;
comment|/* Bitwise or of these flags. */
block|}
name|_tdu
union|;
define|#
directive|define
name|td_dtrace_ft
value|_tdu._td_dtrace_ft
define|#
directive|define
name|td_dtrace_on
value|_tdu._tds._td_dtrace_on
define|#
directive|define
name|td_dtrace_step
value|_tdu._tds._td_dtrace_step
define|#
directive|define
name|td_dtrace_ret
value|_tdu._tds._td_dtrace_ret
define|#
directive|define
name|td_dtrace_ast
value|_tdu._tds._td_dtrace_ast
define|#
directive|define
name|td_dtrace_reg
value|_tdu._tds._td_dtrace_reg
name|uintptr_t
name|td_dtrace_pc
decl_stmt|;
comment|/* DTrace saved pc from fasttrap. */
name|uintptr_t
name|td_dtrace_npc
decl_stmt|;
comment|/* DTrace next pc from fasttrap. */
name|uintptr_t
name|td_dtrace_scrpc
decl_stmt|;
comment|/* DTrace per-thread scratch location. */
name|uintptr_t
name|td_dtrace_astpc
decl_stmt|;
comment|/* DTrace return sequence location. */
ifdef|#
directive|ifdef
name|__amd64__
name|uintptr_t
name|td_dtrace_regv
decl_stmt|;
endif|#
directive|endif
name|u_int64_t
name|td_hrtime
decl_stmt|;
comment|/* Last time on cpu. */
name|int
name|td_errno
decl_stmt|;
comment|/* Syscall return value. */
name|void
modifier|*
name|td_dtrace_sscr
decl_stmt|;
comment|/* Saved scratch space location. */
block|}
name|kdtrace_thread_t
typedef|;
end_typedef

begin_comment
comment|/*  * Definitions to reference fields in the FreeBSD DTrace structures defined  * above using the names of fields in similar structures in Solaris. Note   * that the separation on FreeBSD is a licensing constraint designed to  * keep the GENERIC kernel BSD licensed.  */
end_comment

begin_define
define|#
directive|define
name|t_dtrace_vtime
value|td_dtrace->td_dtrace_vtime
end_define

begin_define
define|#
directive|define
name|t_dtrace_start
value|td_dtrace->td_dtrace_start
end_define

begin_define
define|#
directive|define
name|t_dtrace_stop
value|td_dtrace->td_dtrace_stop
end_define

begin_define
define|#
directive|define
name|t_dtrace_sig
value|td_dtrace->td_dtrace_sig
end_define

begin_define
define|#
directive|define
name|t_predcache
value|td_dtrace->td_predcache
end_define

begin_define
define|#
directive|define
name|t_dtrace_ft
value|td_dtrace->td_dtrace_ft
end_define

begin_define
define|#
directive|define
name|t_dtrace_on
value|td_dtrace->td_dtrace_on
end_define

begin_define
define|#
directive|define
name|t_dtrace_step
value|td_dtrace->td_dtrace_step
end_define

begin_define
define|#
directive|define
name|t_dtrace_ret
value|td_dtrace->td_dtrace_ret
end_define

begin_define
define|#
directive|define
name|t_dtrace_ast
value|td_dtrace->td_dtrace_ast
end_define

begin_define
define|#
directive|define
name|t_dtrace_reg
value|td_dtrace->td_dtrace_reg
end_define

begin_define
define|#
directive|define
name|t_dtrace_pc
value|td_dtrace->td_dtrace_pc
end_define

begin_define
define|#
directive|define
name|t_dtrace_npc
value|td_dtrace->td_dtrace_npc
end_define

begin_define
define|#
directive|define
name|t_dtrace_scrpc
value|td_dtrace->td_dtrace_scrpc
end_define

begin_define
define|#
directive|define
name|t_dtrace_astpc
value|td_dtrace->td_dtrace_astpc
end_define

begin_define
define|#
directive|define
name|t_dtrace_regv
value|td_dtrace->td_dtrace_regv
end_define

begin_define
define|#
directive|define
name|t_dtrace_sscr
value|td_dtrace->td_dtrace_sscr
end_define

begin_define
define|#
directive|define
name|p_dtrace_helpers
value|p_dtrace->p_dtrace_helpers
end_define

begin_define
define|#
directive|define
name|p_dtrace_count
value|p_dtrace->p_dtrace_count
end_define

begin_define
define|#
directive|define
name|p_dtrace_probes
value|p_dtrace->p_dtrace_probes
end_define

begin_define
define|#
directive|define
name|p_model
value|p_dtrace->p_dtrace_model
end_define

begin_define
define|#
directive|define
name|DATAMODEL_NATIVE
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_define
define|#
directive|define
name|DATAMODEL_LP64
value|0
end_define

begin_define
define|#
directive|define
name|DATAMODEL_ILP32
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DATAMODEL_LP64
value|1
end_define

begin_define
define|#
directive|define
name|DATAMODEL_ILP32
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Definitions for fields in struct proc which are named differently in FreeBSD.  */
end_comment

begin_define
define|#
directive|define
name|p_cred
value|p_ucred
end_define

begin_define
define|#
directive|define
name|p_parent
value|p_pptr
end_define

begin_comment
comment|/*  * Definitions for fields in struct thread which are named differently in FreeBSD.  */
end_comment

begin_define
define|#
directive|define
name|t_procp
value|td_proc
end_define

begin_define
define|#
directive|define
name|t_tid
value|td_tid
end_define

begin_define
define|#
directive|define
name|t_did
value|td_tid
end_define

begin_define
define|#
directive|define
name|t_cred
value|td_ucred
end_define

begin_function_decl
name|int
name|priv_policy
parameter_list|(
specifier|const
name|cred_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|boolean_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|priv_policy_only
parameter_list|(
specifier|const
name|cred_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|priv_policy_choice
parameter_list|(
specifier|const
name|cred_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Test privilege. Audit success or failure, allow privilege debugging.  * Returns 0 for success, err for failure.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_POLICY
parameter_list|(
name|cred
parameter_list|,
name|priv
parameter_list|,
name|all
parameter_list|,
name|err
parameter_list|,
name|reason
parameter_list|)
define|\
value|priv_policy((cred), (priv), (all), (err), (reason))
end_define

begin_comment
comment|/*  * Test privilege. Audit success only, no privilege debugging.  * Returns 1 for success, and 0 for failure.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_POLICY_CHOICE
parameter_list|(
name|cred
parameter_list|,
name|priv
parameter_list|,
name|all
parameter_list|)
define|\
value|priv_policy_choice((cred), (priv), (all))
end_define

begin_comment
comment|/*  * Test privilege. No priv_debugging, no auditing.  * Returns 1 for success, and 0 for failure.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_POLICY_ONLY
parameter_list|(
name|cred
parameter_list|,
name|priv
parameter_list|,
name|all
parameter_list|)
define|\
value|priv_policy_only((cred), (priv), (all))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DTRACE_CDDL_H_ */
end_comment

end_unit

