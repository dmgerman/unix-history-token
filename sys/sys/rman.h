begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1998 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby  * granted, provided that both the above copyright notice and this  * permission notice appear in all copies, that both the above  * copyright notice and this permission notice appear in all  * supporting documentation, and that the name of M.I.T. not be used  * in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.  M.I.T. makes  * no representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied  * warranty.  *   * THIS SOFTWARE IS PROVIDED BY M.I.T. ``AS IS''.  M.I.T. DISCLAIMS  * ALL EXPRESS OR IMPLIED WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT  * SHALL M.I.T. BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/_bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
name|RF_SPARE1
value|0x0008
end_define

begin_define
define|#
directive|define
name|RF_SPARE2
value|0x0010
end_define

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
name|RF_PREFETCHABLE
value|0x0040
end_define

begin_comment
comment|/* resource is prefetchable */
end_comment

begin_define
define|#
directive|define
name|RF_OPTIONAL
value|0x0080
end_define

begin_comment
comment|/* for bus_alloc_resources() */
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
comment|/* resource address alignment size bit mask */
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

begin_comment
comment|/*  * String length exported to userspace for resource names, etc.  */
end_comment

begin_define
define|#
directive|define
name|RM_TEXTLEN
value|32
end_define

begin_comment
comment|/*  * Userspace-exported structures.  */
end_comment

begin_struct
struct|struct
name|u_resource
block|{
name|uintptr_t
name|r_handle
decl_stmt|;
comment|/* resource uniquifier */
name|uintptr_t
name|r_parent
decl_stmt|;
comment|/* parent rman */
name|uintptr_t
name|r_device
decl_stmt|;
comment|/* device owning this resource */
name|char
name|r_devname
index|[
name|RM_TEXTLEN
index|]
decl_stmt|;
comment|/* device name XXX obsolete */
name|u_long
name|r_start
decl_stmt|;
comment|/* offset in resource space */
name|u_long
name|r_size
decl_stmt|;
comment|/* size in resource space */
name|u_int
name|r_flags
decl_stmt|;
comment|/* RF_* flags */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|u_rman
block|{
name|uintptr_t
name|rm_handle
decl_stmt|;
comment|/* rman uniquifier */
name|char
name|rm_descr
index|[
name|RM_TEXTLEN
index|]
decl_stmt|;
comment|/* rman description */
name|u_long
name|rm_start
decl_stmt|;
comment|/* base of managed region */
name|u_long
name|rm_size
decl_stmt|;
comment|/* size of managed region */
name|enum
name|rman_type
name|rm_type
decl_stmt|;
comment|/* region type */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * The public (kernel) view of struct resource  *  * NB: Changing the offset/size/type of existing fields in struct resource  * NB: breaks the device driver ABI and is strongly FORBIDDEN.  * NB: Appending new fields is probably just misguided.  */
end_comment

begin_struct
struct|struct
name|resource
block|{
name|struct
name|resource_i
modifier|*
name|__r_i
decl_stmt|;
name|bus_space_tag_t
name|r_bustag
decl_stmt|;
comment|/* bus_space tag */
name|bus_space_handle_t
name|r_bushandle
decl_stmt|;
comment|/* bus_space handle */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|resource_i
struct_decl|;
end_struct_decl

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|resource_head
argument_list|,
name|resource_i
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|rman
block|{
name|struct
name|resource_head
name|rm_list
decl_stmt|;
name|struct
name|mtx
modifier|*
name|rm_mtx
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
name|rman_adjust_resource
parameter_list|(
name|struct
name|resource
modifier|*
name|r
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
name|rman_first_free_region
parameter_list|(
name|struct
name|rman
modifier|*
name|rm
parameter_list|,
name|u_long
modifier|*
name|start
parameter_list|,
name|u_long
modifier|*
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bus_space_handle_t
name|rman_get_bushandle
parameter_list|(
name|struct
name|resource
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bus_space_tag_t
name|rman_get_bustag
parameter_list|(
name|struct
name|resource
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|rman_get_end
parameter_list|(
name|struct
name|resource
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|device
modifier|*
name|rman_get_device
parameter_list|(
name|struct
name|resource
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rman_get_flags
parameter_list|(
name|struct
name|resource
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rman_get_rid
parameter_list|(
name|struct
name|resource
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|rman_get_size
parameter_list|(
name|struct
name|resource
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|rman_get_start
parameter_list|(
name|struct
name|resource
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|rman_get_virtual
parameter_list|(
name|struct
name|resource
modifier|*
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
name|rman_init_from_resource
parameter_list|(
name|struct
name|rman
modifier|*
name|rm
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rman_last_free_region
parameter_list|(
name|struct
name|rman
modifier|*
name|rm
parameter_list|,
name|u_long
modifier|*
name|start
parameter_list|,
name|u_long
modifier|*
name|end
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
name|rman_is_region_manager
parameter_list|(
name|struct
name|resource
modifier|*
name|r
parameter_list|,
name|struct
name|rman
modifier|*
name|rm
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
name|struct
name|resource
modifier|*
name|rman_reserve_resource_bound
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
name|u_long
name|bound
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
name|void
name|rman_set_bushandle
parameter_list|(
name|struct
name|resource
modifier|*
name|_r
parameter_list|,
name|bus_space_handle_t
name|_h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rman_set_bustag
parameter_list|(
name|struct
name|resource
modifier|*
name|_r
parameter_list|,
name|bus_space_tag_t
name|_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rman_set_device
parameter_list|(
name|struct
name|resource
modifier|*
name|_r
parameter_list|,
name|struct
name|device
modifier|*
name|_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rman_set_end
parameter_list|(
name|struct
name|resource
modifier|*
name|_r
parameter_list|,
name|u_long
name|_end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rman_set_rid
parameter_list|(
name|struct
name|resource
modifier|*
name|_r
parameter_list|,
name|int
name|_rid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rman_set_start
parameter_list|(
name|struct
name|resource
modifier|*
name|_r
parameter_list|,
name|u_long
name|_start
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rman_set_virtual
parameter_list|(
name|struct
name|resource
modifier|*
name|_r
parameter_list|,
name|void
modifier|*
name|_v
parameter_list|)
function_decl|;
end_function_decl

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

