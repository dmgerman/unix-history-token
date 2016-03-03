begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************   © 1995-2003, 2004, 2005-2011 Freescale Semiconductor, Inc.  All rights reserved.   This is proprietary source code of Freescale Semiconductor Inc.,  and its use is subject to the NetComm Device Drivers EULA.  The copyright notice above does not evidence any actual or intended  publication of such source code.   ALTERNATIVELY, redistribution and use in source and binary forms, with  or without modification, are permitted provided that the following  conditions are met:      * Redistributions of source code must retain the above copyright        notice, this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.      * Neither the name of Freescale Semiconductor nor the        names of its contributors may be used to endorse or promote products        derived from this software without specific prior written permission.   THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   **************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  @File          fsl_bman.h   @Description   BM header */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FSL_BMAN_H
end_ifndef

begin_define
define|#
directive|define
name|__FSL_BMAN_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_comment
comment|/*************************************************/
end_comment

begin_comment
comment|/*   BMan s/w corenet portal, low-level i/face   */
end_comment

begin_comment
comment|/*************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|e_BmPortalPCI
init|=
literal|0
block|,
comment|/* PI index, cache-inhibited */
name|e_BmPortalPCE
block|,
comment|/* PI index, cache-enabled */
name|e_BmPortalPVB
comment|/* valid-bit */
block|}
name|e_BmPortalProduceMode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|e_BmPortalRcrCCI
init|=
literal|0
block|,
comment|/* CI index, cache-inhibited */
name|e_BmPortalRcrCCE
comment|/* CI index, cache-enabled */
block|}
name|e_BmPortalRcrConsumeMode
typedef|;
end_typedef

begin_comment
comment|/* Portal constants */
end_comment

begin_define
define|#
directive|define
name|BM_RCR_SIZE
value|8
end_define

begin_comment
comment|/* Hardware constants */
end_comment

begin_enum
enum|enum
name|bm_isr_reg
block|{
name|bm_isr_status
init|=
literal|0
block|,
name|bm_isr_enable
init|=
literal|1
block|,
name|bm_isr_disable
init|=
literal|2
block|,
name|bm_isr_inhibit
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/* Represents s/w corenet portal mapped data structures */
end_comment

begin_struct_decl
struct_decl|struct
name|bm_rcr_entry
struct_decl|;
end_struct_decl

begin_comment
comment|/* RCR (Release Command Ring) entries */
end_comment

begin_struct_decl
struct_decl|struct
name|bm_mc_command
struct_decl|;
end_struct_decl

begin_comment
comment|/* MC (Management Command) command */
end_comment

begin_struct_decl
struct_decl|struct
name|bm_mc_result
struct_decl|;
end_struct_decl

begin_comment
comment|/* MC result */
end_comment

begin_comment
comment|/* This type represents a s/w corenet portal space, and is used for creating the  * portal objects within it (RCR, etc) */
end_comment

begin_struct_decl
struct_decl|struct
name|bm_portal
struct_decl|;
end_struct_decl

begin_comment
comment|/* This wrapper represents a bit-array for the depletion state of the 64 Bman  * buffer pools. */
end_comment

begin_struct
struct|struct
name|bman_depletion
block|{
name|uint32_t
name|__state
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|__bmdep_word
parameter_list|(
name|x
parameter_list|)
value|((x)>> 5)
end_define

begin_define
define|#
directive|define
name|__bmdep_shift
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1f)
end_define

begin_define
define|#
directive|define
name|__bmdep_bit
parameter_list|(
name|x
parameter_list|)
value|(0x80000000>> __bmdep_shift(x))
end_define

begin_function
specifier|static
name|__inline__
name|void
name|bman_depletion_init
parameter_list|(
name|struct
name|bman_depletion
modifier|*
name|c
parameter_list|)
block|{
name|c
operator|->
name|__state
index|[
literal|0
index|]
operator|=
name|c
operator|->
name|__state
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|bman_depletion_fill
parameter_list|(
name|struct
name|bman_depletion
modifier|*
name|c
parameter_list|)
block|{
name|c
operator|->
name|__state
index|[
literal|0
index|]
operator|=
name|c
operator|->
name|__state
index|[
literal|1
index|]
operator|=
operator|(
name|uint32_t
operator|)
operator|~
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|bman_depletion_get
parameter_list|(
specifier|const
name|struct
name|bman_depletion
modifier|*
name|c
parameter_list|,
name|uint8_t
name|bpid
parameter_list|)
block|{
return|return
call|(
name|int
call|)
argument_list|(
name|c
operator|->
name|__state
index|[
name|__bmdep_word
argument_list|(
name|bpid
argument_list|)
index|]
operator|&
name|__bmdep_bit
argument_list|(
name|bpid
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|bman_depletion_set
parameter_list|(
name|struct
name|bman_depletion
modifier|*
name|c
parameter_list|,
name|uint8_t
name|bpid
parameter_list|)
block|{
name|c
operator|->
name|__state
index|[
name|__bmdep_word
argument_list|(
name|bpid
argument_list|)
index|]
operator||=
name|__bmdep_bit
argument_list|(
name|bpid
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|bman_depletion_unset
parameter_list|(
name|struct
name|bman_depletion
modifier|*
name|c
parameter_list|,
name|uint8_t
name|bpid
parameter_list|)
block|{
name|c
operator|->
name|__state
index|[
name|__bmdep_word
argument_list|(
name|bpid
argument_list|)
index|]
operator|&=
operator|~
name|__bmdep_bit
argument_list|(
name|bpid
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------------------------------ */
end_comment

begin_comment
comment|/* --- Portal enumeration API --- */
end_comment

begin_comment
comment|/* ------------------------------ */
end_comment

begin_comment
comment|/* --- Buffer pool allocation --- */
end_comment

begin_define
define|#
directive|define
name|BM_POOL_THRESH_SW_ENTER
value|0
end_define

begin_define
define|#
directive|define
name|BM_POOL_THRESH_SW_EXIT
value|1
end_define

begin_define
define|#
directive|define
name|BM_POOL_THRESH_HW_ENTER
value|2
end_define

begin_define
define|#
directive|define
name|BM_POOL_THRESH_HW_EXIT
value|3
end_define

begin_comment
comment|/* --------------- */
end_comment

begin_comment
comment|/* --- RCR API --- */
end_comment

begin_comment
comment|/* Create/destroy */
end_comment

begin_function_decl
name|t_Error
name|bm_rcr_init
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|,
name|e_BmPortalProduceMode
name|pmode
parameter_list|,
name|e_BmPortalRcrConsumeMode
name|cmode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bm_rcr_finish
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Start/abort RCR entry */
end_comment

begin_function_decl
name|struct
name|bm_rcr_entry
modifier|*
name|bm_rcr_start
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bm_rcr_abort
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For PI modes only. This presumes a started but uncommitted RCR entry. If  * there's no more room in the RCR, this function returns NULL. Otherwise it  * returns the next RCR entry and increments an internal PI counter without  * flushing it to h/w. */
end_comment

begin_function_decl
name|struct
name|bm_rcr_entry
modifier|*
name|bm_rcr_pend_and_next
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|,
name|uint8_t
name|myverb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Commit RCR entries, including pending ones (aka "write PI") */
end_comment

begin_function_decl
name|void
name|bm_rcr_pci_commit
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|,
name|uint8_t
name|myverb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bm_rcr_pce_prefetch
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bm_rcr_pce_commit
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|,
name|uint8_t
name|myverb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bm_rcr_pvb_commit
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|,
name|uint8_t
name|myverb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Track h/w consumption. Returns non-zero if h/w had consumed previously  * unconsumed RCR entries. */
end_comment

begin_function_decl
name|uint8_t
name|bm_rcr_cci_update
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bm_rcr_cce_prefetch
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|bm_rcr_cce_update
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the number of available RCR entries */
end_comment

begin_function_decl
name|uint8_t
name|bm_rcr_get_avail
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the number of unconsumed RCR entries */
end_comment

begin_function_decl
name|uint8_t
name|bm_rcr_get_fill
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read/write the RCR interrupt threshold */
end_comment

begin_function_decl
name|uint8_t
name|bm_rcr_get_ithresh
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bm_rcr_set_ithresh
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|,
name|uint8_t
name|ithresh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ------------------------------ */
end_comment

begin_comment
comment|/* --- Management command API --- */
end_comment

begin_comment
comment|/* Create/destroy */
end_comment

begin_function_decl
name|t_Error
name|bm_mc_init
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bm_mc_finish
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Start/abort mgmt command */
end_comment

begin_function_decl
name|struct
name|bm_mc_command
modifier|*
name|bm_mc_start
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bm_mc_abort
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Writes 'verb' with appropriate 'vbit'. Invalidates and pre-fetches the  * response. */
end_comment

begin_function_decl
name|void
name|bm_mc_commit
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|,
name|uint8_t
name|myverb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Poll for result. If NULL, invalidates and prefetches for the next call. */
end_comment

begin_function_decl
name|struct
name|bm_mc_result
modifier|*
name|bm_mc_result
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ------------------------------------- */
end_comment

begin_comment
comment|/* --- Portal interrupt register API --- */
end_comment

begin_comment
comment|/* For a quick explanation of the Bman interrupt model, see the comments in the  * equivalent section of the qman_portal.h header.  */
end_comment

begin_comment
comment|/* Create/destroy */
end_comment

begin_function_decl
name|t_Error
name|bm_isr_init
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bm_isr_finish
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* BSCN masking is a per-portal configuration */
end_comment

begin_function_decl
name|void
name|bm_isr_bscn_mask
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|,
name|uint8_t
name|bpid
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Used by all portal interrupt registers except 'inhibit' */
end_comment

begin_define
define|#
directive|define
name|BM_PIRQ_RCRI
value|0x00000002
end_define

begin_comment
comment|/* RCR Ring (below threshold) */
end_comment

begin_define
define|#
directive|define
name|BM_PIRQ_BSCN
value|0x00000001
end_define

begin_comment
comment|/* Buffer depletion State Change */
end_comment

begin_comment
comment|/* These are bm_<reg>_<verb>(). So for example, bm_disable_write() means "write  * the disable register" rather than "disable the ability to write". */
end_comment

begin_define
define|#
directive|define
name|bm_isr_status_read
parameter_list|(
name|bm
parameter_list|)
value|__bm_isr_read(bm, bm_isr_status)
end_define

begin_define
define|#
directive|define
name|bm_isr_status_clear
parameter_list|(
name|bm
parameter_list|,
name|m
parameter_list|)
value|__bm_isr_write(bm, bm_isr_status, m)
end_define

begin_define
define|#
directive|define
name|bm_isr_enable_read
parameter_list|(
name|bm
parameter_list|)
value|__bm_isr_read(bm, bm_isr_enable)
end_define

begin_define
define|#
directive|define
name|bm_isr_enable_write
parameter_list|(
name|bm
parameter_list|,
name|v
parameter_list|)
value|__bm_isr_write(bm, bm_isr_enable, v)
end_define

begin_define
define|#
directive|define
name|bm_isr_disable_read
parameter_list|(
name|bm
parameter_list|)
value|__bm_isr_read(bm, bm_isr_disable)
end_define

begin_define
define|#
directive|define
name|bm_isr_disable_write
parameter_list|(
name|bm
parameter_list|,
name|v
parameter_list|)
value|__bm_isr_write(bm, bm_isr_disable, v)
end_define

begin_define
define|#
directive|define
name|bm_isr_inhibit
parameter_list|(
name|bm
parameter_list|)
value|__bm_isr_write(bm, bm_isr_inhibit, 1)
end_define

begin_define
define|#
directive|define
name|bm_isr_uninhibit
parameter_list|(
name|bm
parameter_list|)
value|__bm_isr_write(bm, bm_isr_inhibit, 0)
end_define

begin_comment
comment|/* Don't use these, use the wrappers above*/
end_comment

begin_function_decl
name|uint32_t
name|__bm_isr_read
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|,
name|enum
name|bm_isr_reg
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__bm_isr_write
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|portal
parameter_list|,
name|enum
name|bm_isr_reg
name|n
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ------------------------------------------------------- */
end_comment

begin_comment
comment|/* --- Bman data structures (and associated constants) --- */
end_comment

begin_comment
comment|/* Code-reduction, define a wrapper for 48-bit buffers. In cases where a buffer  * pool id specific to this buffer is needed (BM_RCR_VERB_CMD_BPID_MULTI,  * BM_MCC_VERB_ACQUIRE), the 'bpid' field is used. */
end_comment

begin_define
define|#
directive|define
name|BM_RCR_VERB_VBIT
value|0x80
end_define

begin_define
define|#
directive|define
name|BM_RCR_VERB_CMD_MASK
value|0x70
end_define

begin_comment
comment|/* one of two values; */
end_comment

begin_define
define|#
directive|define
name|BM_RCR_VERB_CMD_BPID_SINGLE
value|0x20
end_define

begin_define
define|#
directive|define
name|BM_RCR_VERB_CMD_BPID_MULTI
value|0x30
end_define

begin_define
define|#
directive|define
name|BM_RCR_VERB_BUFCOUNT_MASK
value|0x0f
end_define

begin_comment
comment|/* values 1..8 */
end_comment

begin_define
define|#
directive|define
name|BM_MCC_VERB_VBIT
value|0x80
end_define

begin_define
define|#
directive|define
name|BM_MCC_VERB_CMD_MASK
value|0x70
end_define

begin_comment
comment|/* where the verb contains; */
end_comment

begin_define
define|#
directive|define
name|BM_MCC_VERB_CMD_ACQUIRE
value|0x10
end_define

begin_define
define|#
directive|define
name|BM_MCC_VERB_CMD_QUERY
value|0x40
end_define

begin_define
define|#
directive|define
name|BM_MCC_VERB_ACQUIRE_BUFCOUNT
value|0x0f
end_define

begin_comment
comment|/* values 1..8 go here */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__MWERKS__)&& ... */
end_comment

begin_define
define|#
directive|define
name|MEM_MAP_START
end_define

begin_macro
name|_Packed
end_macro

begin_struct
struct|struct
name|bm_buffer
block|{
specifier|volatile
name|uint8_t
name|reserved1
decl_stmt|;
specifier|volatile
name|uint8_t
name|bpid
decl_stmt|;
specifier|volatile
name|uint16_t
name|hi
decl_stmt|;
comment|/* High 16-bits of 48-bit address */
specifier|volatile
name|uint32_t
name|lo
decl_stmt|;
comment|/* Low 32-bits of 48-bit address */
block|}
name|_PackedType
struct|;
end_struct

begin_comment
comment|/* See 1.5.3.5.4: "Release Command" */
end_comment

begin_macro
name|_Packed
end_macro

begin_struct
struct|struct
name|bm_rcr_entry
block|{
name|_Packed
union|union
block|{
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint8_t
name|__dont_write_directly__verb
decl_stmt|;
specifier|volatile
name|uint8_t
name|bpid
decl_stmt|;
comment|/* used with BM_RCR_VERB_CMD_BPID_SINGLE */
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|62
index|]
decl_stmt|;
block|}
name|_PackedType
struct|;
specifier|volatile
name|struct
name|bm_buffer
name|bufs
index|[
literal|8
index|]
decl_stmt|;
block|}
name|_PackedType
union|;
block|}
name|_PackedType
struct|;
end_struct

begin_comment
comment|/* See 1.5.3.1: "Acquire Command" */
end_comment

begin_comment
comment|/* See 1.5.3.2: "Query Command" */
end_comment

begin_macro
name|_Packed
end_macro

begin_struct
struct|struct
name|bm_mc_command
block|{
specifier|volatile
name|uint8_t
name|__dont_write_directly__verb
decl_stmt|;
name|_Packed
union|union
block|{
name|_Packed
struct|struct
name|bm_mcc_acquire
block|{
specifier|volatile
name|uint8_t
name|bpid
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|62
index|]
decl_stmt|;
block|}
name|_PackedType
name|acquire
struct|;
name|_Packed
struct|struct
name|bm_mcc_query
block|{
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|63
index|]
decl_stmt|;
block|}
name|_PackedType
name|query
struct|;
block|}
name|_PackedType
union|;
block|}
name|_PackedType
struct|;
end_struct

begin_comment
comment|/* See 1.5.3.3: "Acquire Reponse" */
end_comment

begin_comment
comment|/* See 1.5.3.4: "Query Reponse" */
end_comment

begin_macro
name|_Packed
end_macro

begin_struct
struct|struct
name|bm_mc_result
block|{
name|_Packed
union|union
block|{
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint8_t
name|verb
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|63
index|]
decl_stmt|;
block|}
name|_PackedType
struct|;
name|_Packed
union|union
block|{
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint8_t
name|reserved1
decl_stmt|;
specifier|volatile
name|uint8_t
name|bpid
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved2
index|[
literal|62
index|]
decl_stmt|;
block|}
name|_PackedType
struct|;
specifier|volatile
name|struct
name|bm_buffer
name|bufs
index|[
literal|8
index|]
decl_stmt|;
block|}
name|_PackedType
name|acquire
union|;
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|32
index|]
decl_stmt|;
comment|/* "availability state" and "depletion state" */
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|8
index|]
decl_stmt|;
comment|/* Access using bman_depletion_***() */
specifier|volatile
name|struct
name|bman_depletion
name|state
decl_stmt|;
block|}
name|_PackedType
name|as
struct|,
name|ds
struct|;
block|}
name|_PackedType
name|query
struct|;
block|}
name|_PackedType
union|;
block|}
name|_PackedType
struct|;
end_struct

begin_define
define|#
directive|define
name|MEM_MAP_END
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__MWERKS__)&& ... */
end_comment

begin_define
define|#
directive|define
name|BM_MCR_VERB_VBIT
value|0x80
end_define

begin_define
define|#
directive|define
name|BM_MCR_VERB_CMD_MASK
value|BM_MCC_VERB_CMD_MASK
end_define

begin_define
define|#
directive|define
name|BM_MCR_VERB_CMD_ACQUIRE
value|BM_MCC_VERB_CMD_ACQUIRE
end_define

begin_define
define|#
directive|define
name|BM_MCR_VERB_CMD_QUERY
value|BM_MCC_VERB_CMD_QUERY
end_define

begin_define
define|#
directive|define
name|BM_MCR_VERB_CMD_ERR_INVALID
value|0x60
end_define

begin_define
define|#
directive|define
name|BM_MCR_VERB_CMD_ERR_ECC
value|0x70
end_define

begin_define
define|#
directive|define
name|BM_MCR_VERB_ACQUIRE_BUFCOUNT
value|BM_MCC_VERB_ACQUIRE_BUFCOUNT
end_define

begin_comment
comment|/* 0..8 */
end_comment

begin_comment
comment|/* Determine the "availability state" of pool 'p' from a query result 'r' */
end_comment

begin_define
define|#
directive|define
name|BM_MCR_QUERY_AVAILABILITY
parameter_list|(
name|r
parameter_list|,
name|p
parameter_list|)
value|bman_depletion_get(&r->query.as.state,p)
end_define

begin_comment
comment|/* Determine the "depletion state" of pool 'p' from a query result 'r' */
end_comment

begin_define
define|#
directive|define
name|BM_MCR_QUERY_DEPLETION
parameter_list|(
name|r
parameter_list|,
name|p
parameter_list|)
value|bman_depletion_get(&r->query.ds.state,p)
end_define

begin_comment
comment|/* Portal and Buffer Pools */
end_comment

begin_comment
comment|/* ----------------------- */
end_comment

begin_comment
comment|/* Flags to bman_create_portal() */
end_comment

begin_define
define|#
directive|define
name|BMAN_PORTAL_FLAG_IRQ
value|0x00000001
end_define

begin_comment
comment|/* use interrupt handler */
end_comment

begin_define
define|#
directive|define
name|BMAN_PORTAL_FLAG_IRQ_FAST
value|0x00000002
end_define

begin_comment
comment|/* ... for fast-path too! */
end_comment

begin_define
define|#
directive|define
name|BMAN_PORTAL_FLAG_COMPACT
value|0x00000004
end_define

begin_comment
comment|/* use compaction algorithm */
end_comment

begin_define
define|#
directive|define
name|BMAN_PORTAL_FLAG_RECOVER
value|0x00000008
end_define

begin_comment
comment|/* recovery mode */
end_comment

begin_define
define|#
directive|define
name|BMAN_PORTAL_FLAG_WAIT
value|0x00000010
end_define

begin_comment
comment|/* wait if RCR is full */
end_comment

begin_define
define|#
directive|define
name|BMAN_PORTAL_FLAG_WAIT_INT
value|0x00000020
end_define

begin_comment
comment|/* if wait, interruptible? */
end_comment

begin_define
define|#
directive|define
name|BMAN_PORTAL_FLAG_CACHE
value|0x00000400
end_define

begin_comment
comment|/* use cache-able area for rings */
end_comment

begin_comment
comment|/* Flags to bman_new_pool() */
end_comment

begin_define
define|#
directive|define
name|BMAN_POOL_FLAG_NO_RELEASE
value|0x00000001
end_define

begin_comment
comment|/* can't release to pool */
end_comment

begin_define
define|#
directive|define
name|BMAN_POOL_FLAG_ONLY_RELEASE
value|0x00000002
end_define

begin_comment
comment|/* can only release to pool */
end_comment

begin_define
define|#
directive|define
name|BMAN_POOL_FLAG_DEPLETION
value|0x00000004
end_define

begin_comment
comment|/* track depletion entry/exit */
end_comment

begin_define
define|#
directive|define
name|BMAN_POOL_FLAG_DYNAMIC_BPID
value|0x00000008
end_define

begin_comment
comment|/* (de)allocate bpid */
end_comment

begin_define
define|#
directive|define
name|BMAN_POOL_FLAG_THRESH
value|0x00000010
end_define

begin_comment
comment|/* set depletion thresholds */
end_comment

begin_define
define|#
directive|define
name|BMAN_POOL_FLAG_STOCKPILE
value|0x00000020
end_define

begin_comment
comment|/* stockpile to reduce hw ops */
end_comment

begin_comment
comment|/* Flags to bman_release() */
end_comment

begin_define
define|#
directive|define
name|BMAN_RELEASE_FLAG_WAIT
value|0x00000001
end_define

begin_comment
comment|/* wait if RCR is full */
end_comment

begin_define
define|#
directive|define
name|BMAN_RELEASE_FLAG_WAIT_INT
value|0x00000002
end_define

begin_comment
comment|/* if we wait, interruptible? */
end_comment

begin_define
define|#
directive|define
name|BMAN_RELEASE_FLAG_WAIT_SYNC
value|0x00000004
end_define

begin_comment
comment|/* if wait, until consumed? */
end_comment

begin_define
define|#
directive|define
name|BMAN_RELEASE_FLAG_NOW
value|0x00000008
end_define

begin_comment
comment|/* issue immediate release */
end_comment

begin_comment
comment|/* Flags to bman_acquire() */
end_comment

begin_define
define|#
directive|define
name|BMAN_ACQUIRE_FLAG_STOCKPILE
value|0x00000001
end_define

begin_comment
comment|/* no hw op, stockpile only */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FSL_BMAN_H */
end_comment

end_unit

