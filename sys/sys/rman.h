begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1998 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby  * granted, provided that both the above copyright notice and this  * permission notice appear in all copies, that both the above  * copyright notice and this permission notice appear in all  * supporting documentation, and that the name of M.I.T. not be used  * in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.  M.I.T. makes  * no representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied  * warranty.  *   * THIS SOFTWARE IS PROVIDED BY M.I.T. ``AS IS''.  M.I.T. DISCLAIMS  * ALL EXPRESS OR IMPLIED WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT  * SHALL M.I.T. BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_RMAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_RMAN_H_
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * We use a linked list rather than a bitmap because we need to be able to  * represent potentially huge objects (like all of a processor's physical  * address space).  That is also why the indices are defined to have type  * `unsigned long' -- that being the largest integral type in Standard C.  */
end_comment

begin_expr_stmt
name|CIRCLEQ_HEAD
argument_list|(
name|resource_head
argument_list|,
name|resource
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|resource
block|{
name|CIRCLEQ_ENTRY
argument_list|(
argument|resource
argument_list|)
name|r_link
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|resource
argument_list|)
name|r_sharelink
expr_stmt|;
name|LIST_HEAD
argument_list|(,
name|resource
argument_list|)
operator|*
name|r_sharehead
expr_stmt|;
name|u_long
name|r_start
decl_stmt|;
comment|/* index of the first entry in this resource */
name|u_long
name|r_end
decl_stmt|;
comment|/* index of the last entry (inclusive) */
name|u_int
name|r_flags
decl_stmt|;
name|void
modifier|*
name|r_virtual
decl_stmt|;
comment|/* virtual address of this resource */
name|bus_space_tag_t
name|r_bustag
decl_stmt|;
comment|/* bus_space tag */
name|bus_space_handle_t
name|r_bushandle
decl_stmt|;
comment|/* bus_space handle */
name|struct
name|device
modifier|*
name|r_dev
decl_stmt|;
comment|/* device which has allocated this resource */
name|struct
name|rman
modifier|*
name|r_rm
decl_stmt|;
comment|/* resource manager from whence this came */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RF_ALLOCATED
value|0x0001
end_define

begin_comment
comment|/* resource has been reserved */
end_comment

begin_define
define|#
directive|define
name|RF_ACTIVE
value|0x0002
end_define

begin_comment
comment|/* resource allocation has been activated */
end_comment

begin_define
define|#
directive|define
name|RF_SHAREABLE
value|0x0004
end_define

begin_comment
comment|/* resource permits contemporaneous sharing */
end_comment

begin_define
define|#
directive|define
name|RF_TIMESHARE
value|0x0008
end_define

begin_comment
comment|/* resource permits time-division sharing */
end_comment

begin_define
define|#
directive|define
name|RF_WANTED
value|0x0010
end_define

begin_comment
comment|/* somebody is waiting for this resource */
end_comment

begin_define
define|#
directive|define
name|RF_FIRSTSHARE
value|0x0020
end_define

begin_comment
comment|/* first in sharing list */
end_comment

begin_define
define|#
directive|define
name|RF_ALIGNMENT_SHIFT
value|10
end_define

begin_comment
comment|/* alignment size bit starts bit 10 */
end_comment

begin_define
define|#
directive|define
name|RF_ALIGNMENT_MASK
value|(0x003F<< RF_ALIGNMENT_SHIFT)
end_define

begin_comment
comment|/* resource address alignemnt size bit mask */
end_comment

begin_define
define|#
directive|define
name|RF_ALIGNMENT_LOG2
parameter_list|(
name|x
parameter_list|)
value|((x)<< RF_ALIGNMENT_SHIFT)
end_define

begin_define
define|#
directive|define
name|RF_ALIGNMENT
parameter_list|(
name|x
parameter_list|)
value|(((x)& RF_ALIGNMENT_MASK)>> RF_ALIGNMENT_SHIFT)
end_define

begin_enum
enum|enum
name|rman_type
block|{
name|RMAN_UNINIT
init|=
literal|0
block|,
name|RMAN_GAUGE
block|,
name|RMAN_ARRAY
block|}
enum|;
end_enum

begin_struct
struct|struct
name|rman
block|{
name|struct
name|resource_head
name|rm_list
decl_stmt|;
name|struct
name|simplelock
modifier|*
name|rm_slock
decl_stmt|;
comment|/* mutex used to protect rm_list */
name|TAILQ_ENTRY
argument_list|(
argument|rman
argument_list|)
name|rm_link
expr_stmt|;
comment|/* link in list of all rmans */
name|u_long
name|rm_start
decl_stmt|;
comment|/* index of globally first entry */
name|u_long
name|rm_end
decl_stmt|;
comment|/* index of globally last entry */
name|enum
name|rman_type
name|rm_type
decl_stmt|;
comment|/* what type of resource this is */
specifier|const
name|char
modifier|*
name|rm_descr
decl_stmt|;
comment|/* text descripion of this resource */
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|rman_head
argument_list|,
name|rman
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|rman_activate_resource
parameter_list|(
name|struct
name|resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rman_await_resource
parameter_list|(
name|struct
name|resource
modifier|*
name|r
parameter_list|,
name|int
name|pri
parameter_list|,
name|int
name|timo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rman_deactivate_resource
parameter_list|(
name|struct
name|resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rman_fini
parameter_list|(
name|struct
name|rman
modifier|*
name|rm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rman_init
parameter_list|(
name|struct
name|rman
modifier|*
name|rm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rman_manage_region
parameter_list|(
name|struct
name|rman
modifier|*
name|rm
parameter_list|,
name|u_long
name|start
parameter_list|,
name|u_long
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rman_release_resource
parameter_list|(
name|struct
name|resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource
modifier|*
name|rman_reserve_resource
parameter_list|(
name|struct
name|rman
modifier|*
name|rm
parameter_list|,
name|u_long
name|start
parameter_list|,
name|u_long
name|end
parameter_list|,
name|u_long
name|count
parameter_list|,
name|u_int
name|flags
parameter_list|,
name|struct
name|device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|rman_make_alignment_flags
parameter_list|(
name|uint32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|rman_get_start
parameter_list|(
name|r
parameter_list|)
value|((r)->r_start)
end_define

begin_define
define|#
directive|define
name|rman_get_end
parameter_list|(
name|r
parameter_list|)
value|((r)->r_end)
end_define

begin_define
define|#
directive|define
name|rman_get_flags
parameter_list|(
name|r
parameter_list|)
value|((r)->r_flags)
end_define

begin_define
define|#
directive|define
name|rman_set_virtual
parameter_list|(
name|r
parameter_list|,
name|v
parameter_list|)
value|((r)->r_virtual = (v))
end_define

begin_define
define|#
directive|define
name|rman_get_virtual
parameter_list|(
name|r
parameter_list|)
value|((r)->r_virtual)
end_define

begin_define
define|#
directive|define
name|rman_set_bustag
parameter_list|(
name|r
parameter_list|,
name|t
parameter_list|)
value|((r)->r_bustag = (t))
end_define

begin_define
define|#
directive|define
name|rman_get_bustag
parameter_list|(
name|r
parameter_list|)
value|((r)->r_bustag)
end_define

begin_define
define|#
directive|define
name|rman_set_bushandle
parameter_list|(
name|r
parameter_list|,
name|h
parameter_list|)
value|((r)->r_bushandle = (h))
end_define

begin_define
define|#
directive|define
name|rman_get_bushandle
parameter_list|(
name|r
parameter_list|)
value|((r)->r_bushandle)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|rman_head
name|rman_head
decl_stmt|;
end_decl_stmt

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
comment|/* !_SYS_RMAN_H_ */
end_comment

end_unit

