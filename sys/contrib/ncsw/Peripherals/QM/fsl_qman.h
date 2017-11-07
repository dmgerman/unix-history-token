begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************   © 1995-2003, 2004, 2005-2011 Freescale Semiconductor, Inc.  All rights reserved.   This is proprietary source code of Freescale Semiconductor Inc.,  and its use is subject to the NetComm Device Drivers EULA.  The copyright notice above does not evidence any actual or intended  publication of such source code.   ALTERNATIVELY, redistribution and use in source and binary forms, with  or without modification, are permitted provided that the following  conditions are met:      * Redistributions of source code must retain the above copyright        notice, this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.      * Neither the name of Freescale Semiconductor nor the        names of its contributors may be used to endorse or promote products        derived from this software without specific prior written permission.   THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   **************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  @File          fsl_qman.h   @Description   QM header */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FSL_QMAN_H
end_ifndef

begin_define
define|#
directive|define
name|__FSL_QMAN_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"string_ext.h"
end_include

begin_include
include|#
directive|include
file|"qm_ext.h"
end_include

begin_comment
comment|/*************************************************/
end_comment

begin_comment
comment|/*   QMan s/w corenet portal, low-level i/face   */
end_comment

begin_comment
comment|/*************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|e_QmPortalPCI
init|=
literal|0
block|,
comment|/* PI index, cache-inhibited */
name|e_QmPortalPCE
block|,
comment|/* PI index, cache-enabled */
name|e_QmPortalPVB
comment|/* valid-bit */
block|}
name|e_QmPortalProduceMode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|e_QmPortalEqcrCCI
init|=
literal|0
block|,
comment|/* CI index, cache-inhibited */
name|e_QmPortalEqcrCCE
comment|/* CI index, cache-enabled */
block|}
name|e_QmPortalEqcrConsumeMode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|e_QmPortalDqrrCCI
init|=
literal|0
block|,
comment|/* CI index, cache-inhibited */
name|e_QmPortalDqrrCCE
block|,
comment|/* CI index, cache-enabled */
name|e_QmPortalDqrrDCA
comment|/* Discrete Consumption Acknowledgment */
block|}
name|e_QmPortalDqrrConsumeMode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|e_QmPortalMrCCI
init|=
literal|0
block|,
comment|/* CI index, cache-inhibited */
name|e_QmPortalMrCCE
comment|/* CI index, cache-enabled */
block|}
name|e_QmPortalMrConsumeMode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|e_QmPortalDequeuePushMode
init|=
literal|0
block|,
comment|/* SDQCR  + VDQCR */
name|e_QmPortalDequeuePullMode
comment|/* PDQCR */
block|}
name|e_QmPortalDequeueMode
typedef|;
end_typedef

begin_comment
comment|/* Portal constants */
end_comment

begin_define
define|#
directive|define
name|QM_EQCR_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|QM_DQRR_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|QM_MR_SIZE
value|8
end_define

begin_comment
comment|/* Hardware constants */
end_comment

begin_enum
enum|enum
name|qm_isr_reg
block|{
name|qm_isr_status
init|=
literal|0
block|,
name|qm_isr_enable
init|=
literal|1
block|,
name|qm_isr_disable
init|=
literal|2
block|,
name|qm_isr_inhibit
init|=
literal|3
block|}
enum|;
end_enum

begin_enum
enum|enum
name|qm_dc_portal
block|{
name|qm_dc_portal_fman0
init|=
literal|0
block|,
name|qm_dc_portal_fman1
init|=
literal|1
block|,
name|qm_dc_portal_caam
init|=
literal|2
block|,
name|qm_dc_portal_pme
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
name|qm_eqcr_entry
struct_decl|;
end_struct_decl

begin_comment
comment|/* EQCR (EnQueue Command Ring) entries */
end_comment

begin_struct_decl
struct_decl|struct
name|qm_dqrr_entry
struct_decl|;
end_struct_decl

begin_comment
comment|/* DQRR (DeQueue Response Ring) entries */
end_comment

begin_struct_decl
struct_decl|struct
name|qm_mr_entry
struct_decl|;
end_struct_decl

begin_comment
comment|/* MR (Message Ring) entries */
end_comment

begin_struct_decl
struct_decl|struct
name|qm_mc_command
struct_decl|;
end_struct_decl

begin_comment
comment|/* MC (Management Command) command */
end_comment

begin_struct_decl
struct_decl|struct
name|qm_mc_result
struct_decl|;
end_struct_decl

begin_comment
comment|/* MC result */
end_comment

begin_comment
comment|/* This type represents a s/w corenet portal space, and is used for creating the  * portal objects within it (EQCR, DQRR, etc) */
end_comment

begin_struct_decl
struct_decl|struct
name|qm_portal
struct_decl|;
end_struct_decl

begin_comment
comment|/* When iterating the available portals, this is the exposed config structure */
end_comment

begin_struct
struct|struct
name|qm_portal_config
block|{
comment|/* If the caller enables DQRR stashing (and thus wishes to operate the      * portal from only one cpu), this is the logical CPU that the portal      * will stash to. Whether stashing is enabled or not, this setting is      * also used for any "core-affine" portals, ie. default portals      * associated to the corresponding cpu. -1 implies that there is no core      * affinity configured. */
name|int
name|cpu
decl_stmt|;
comment|/* portal interrupt line */
name|uintptr_t
name|irq
decl_stmt|;
comment|/* The portal's dedicated channel id, use this value for initializing      * frame queues to target this portal when scheduled. */
name|e_QmFQChannel
name|channel
decl_stmt|;
comment|/* A mask of which pool channels this portal has dequeue access to      * (using QM_SDQCR_CHANNELS_POOL(n) for the bitmask) */
name|uint32_t
name|pools
decl_stmt|;
comment|/* which portal sub-interfaces are already bound (ie. "in use") */
name|uint8_t
name|bound
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* qm_portal_config::bound uses these bit masks */
end_comment

begin_define
define|#
directive|define
name|QM_BIND_EQCR
value|0x01
end_define

begin_define
define|#
directive|define
name|QM_BIND_DQRR
value|0x02
end_define

begin_define
define|#
directive|define
name|QM_BIND_MR
value|0x04
end_define

begin_define
define|#
directive|define
name|QM_BIND_MC
value|0x08
end_define

begin_define
define|#
directive|define
name|QM_BIND_ISR
value|0x10
end_define

begin_comment
comment|/* This struct represents a pool channel */
end_comment

begin_struct
struct|struct
name|qm_pool_channel
block|{
comment|/* The QM_SDQCR_CHANNELS_POOL(n) bit that corresponds to this channel */
name|uint32_t
name|pool
decl_stmt|;
comment|/* The channel id, used for initialising frame queues to target this      * channel. */
name|e_QmFQChannel
name|channel
decl_stmt|;
comment|/* Bitmask of portal (logical-, not cell-)indices that have dequeue      * access to this channel;      * 0x001 -> qm_portal_get(0)      * 0x002 -> qm_portal_get(1)      * 0x004 -> qm_portal_get(2)      * ...      * 0x200 -> qm_portal_get(9)      */
name|uint32_t
name|portals
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ------------------------------ */
end_comment

begin_comment
comment|/* --- Portal enumeration API --- */
end_comment

begin_comment
comment|/* Obtain the number of portals available */
end_comment

begin_function_decl
name|uint8_t
name|qm_portal_num
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Obtain a portal handle and configuration information about it */
end_comment

begin_function_decl
name|struct
name|qm_portal
modifier|*
name|qm_portal_get
parameter_list|(
name|uint8_t
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ------------------------------------ */
end_comment

begin_comment
comment|/* --- Pool channel enumeration API --- */
end_comment

begin_comment
comment|/* Obtain a mask of the available pool channels, expressed using  * QM_SDQCR_CHANNELS_POOL(n). */
end_comment

begin_function_decl
name|uint32_t
name|qm_pools
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Retrieve a pool channel configuration, given a QM_SDQCR_CHANNEL_POOL(n)  * bit-mask (the least significant bit of 'mask' is used if more than one bit is  * set). */
end_comment

begin_function_decl
specifier|const
name|struct
name|qm_pool_channel
modifier|*
name|qm_pool_channel
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Flags to qm_fq_free_flags() */
end_comment

begin_define
define|#
directive|define
name|QM_FQ_FREE_WAIT
value|0x00000001
end_define

begin_comment
comment|/* wait if RCR is full */
end_comment

begin_define
define|#
directive|define
name|QM_FQ_FREE_WAIT_INT
value|0x00000002
end_define

begin_comment
comment|/* if wait, interruptible? */
end_comment

begin_define
define|#
directive|define
name|QM_FQ_FREE_WAIT_SYNC
value|0x00000004
end_define

begin_comment
comment|/* if wait, until consumed? */
end_comment

begin_define
define|#
directive|define
name|QM_SDQCR_SOURCE_CHANNELS
value|0x0
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_SOURCE_SPECIFICWQ
value|0x40000000
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_COUNT_EXACT1
value|0x0
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_COUNT_UPTO3
value|0x20000000
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_DEDICATED_PRECEDENCE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_TYPE_MASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_TYPE_NULL
value|0x0
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_TYPE_PRIO_QOS
value|0x01000000
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_TYPE_ACTIVE_QOS
value|0x02000000
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_TYPE_ACTIVE
value|0x03000000
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_TYPE_SET
parameter_list|(
name|v
parameter_list|)
value|(((v)& 0x03)<< (31-7))
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_TOKEN_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_TOKEN_SET
parameter_list|(
name|v
parameter_list|)
value|(((v)& 0xff)<< 16)
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_TOKEN_GET
parameter_list|(
name|v
parameter_list|)
value|(((v)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_CHANNELS_DEDICATED
value|0x00008000
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_CHANNELS_POOL_MASK
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_CHANNELS_POOL
parameter_list|(
name|n
parameter_list|)
value|(0x00008000>> (n))
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_SPECIFICWQ_MASK
value|0x000000f7
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_SPECIFICWQ_DEDICATED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_SPECIFICWQ_POOL
parameter_list|(
name|n
parameter_list|)
value|((n)<< 4)
end_define

begin_define
define|#
directive|define
name|QM_SDQCR_SPECIFICWQ_WQ
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_comment
comment|/* For qm_dqrr_vdqcr_set(); Choose one PRECEDENCE. EXACT is optional. Use  * NUMFRAMES(n) (6-bit) or NUMFRAMES_TILLEMPTY to fill in the frame-count. Use  * FQID(n) to fill in the frame queue ID. */
end_comment

begin_define
define|#
directive|define
name|QM_VDQCR_PRECEDENCE_VDQCR
value|0x0
end_define

begin_define
define|#
directive|define
name|QM_VDQCR_PRECEDENCE_SDQCR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|QM_VDQCR_EXACT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|QM_VDQCR_NUMFRAMES_MASK
value|0x3f000000
end_define

begin_define
define|#
directive|define
name|QM_VDQCR_NUMFRAMES_SET
parameter_list|(
name|n
parameter_list|)
value|(((n)& 0x3f)<< 24)
end_define

begin_define
define|#
directive|define
name|QM_VDQCR_NUMFRAMES_GET
parameter_list|(
name|n
parameter_list|)
value|(((n)>> 24)& 0x3f)
end_define

begin_define
define|#
directive|define
name|QM_VDQCR_NUMFRAMES_TILLEMPTY
value|QM_VDQCR_NUMFRAMES_SET(0)
end_define

begin_define
define|#
directive|define
name|QM_VDQCR_FQID_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|QM_VDQCR_FQID
parameter_list|(
name|n
parameter_list|)
value|((n)& QM_VDQCR_FQID_MASK)
end_define

begin_comment
comment|/* For qm_dqrr_pdqcr_set(); Choose one MODE. Choose one COUNT.  * If MODE==SCHEDULED  *   Choose SCHEDULED_CHANNELS or SCHEDULED_SPECIFICWQ. Choose one dequeue TYPE.  *   If CHANNELS,  *     Choose CHANNELS_DEDICATED and/or CHANNELS_POOL() channels.  *     You can choose DEDICATED_PRECEDENCE if the portal channel should have  *     priority.  *   If SPECIFICWQ,  *     Either select the work-queue ID with SPECIFICWQ_WQ(), or select the  *     channel (SPECIFICWQ_DEDICATED or SPECIFICWQ_POOL()) and specify the  *     work-queue priority (0-7) with SPECIFICWQ_WQ() - either way, you get the  *     same value.  * If MODE==UNSCHEDULED  *     Choose FQID().  */
end_comment

begin_define
define|#
directive|define
name|QM_PDQCR_MODE_SCHEDULED
value|0x0
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_MODE_UNSCHEDULED
value|0x80000000
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_SCHEDULED_CHANNELS
value|0x0
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_SCHEDULED_SPECIFICWQ
value|0x40000000
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_COUNT_EXACT1
value|0x0
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_COUNT_UPTO3
value|0x20000000
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_DEDICATED_PRECEDENCE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_TYPE_MASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_TYPE_NULL
value|0x0
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_TYPE_PRIO_QOS
value|0x01000000
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_TYPE_ACTIVE_QOS
value|0x02000000
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_TYPE_ACTIVE
value|0x03000000
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_CHANNELS_DEDICATED
value|0x00008000
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_CHANNELS_POOL
parameter_list|(
name|n
parameter_list|)
value|(0x00008000>> (n))
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_SPECIFICWQ_MASK
value|0x000000f7
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_SPECIFICWQ_DEDICATED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_SPECIFICWQ_POOL
parameter_list|(
name|n
parameter_list|)
value|((n)<< 4)
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_SPECIFICWQ_WQ
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|QM_PDQCR_FQID
parameter_list|(
name|n
parameter_list|)
value|((n)& 0xffffff)
end_define

begin_comment
comment|/* ------------------------------------- */
end_comment

begin_comment
comment|/* --- Portal interrupt register API --- */
end_comment

begin_comment
comment|/* Quick explanation of the Qman interrupt model. Each bit has a source  * condition, that source is asserted iff the condition is true. Eg. Each  * DQAVAIL source bit tracks whether the corresponding channel's work queues  * contain any truly scheduled frame queues. That source exists "asserted" if  * and while there are truly-scheduled FQs available, it is deasserted as/when  * there are no longer any truly-scheduled FQs available. The same is true for  * the various other interrupt source conditions (QM_PIRQ_***). The following  * steps indicate what those source bits affect;  *    1. if the corresponding bit is set in the disable register, the source  *       bit is masked off, we never see any effect from it.  *    2. otherwise, the corresponding bit is set in the status register. Once  *       asserted in the status register, it must be write-1-to-clear'd - the  *       status register bit will stay set even if the source condition  *       deasserts.  *    3. if a bit is set in the status register but *not* set in the enable  *       register, it will not cause the interrupt to assert. Other bits may  *       still cause the interrupt to assert of course, and a read of the  *       status register can still reveal un-enabled bits - this is why the  *       enable and disable registers aren't strictly speaking "opposites".  *       "Un-enabled" means it won't, on its own, trigger an interrupt.  *       "Disabled" means it won't even show up in the status register.  *    4. if a bit is set in the status register *and* the enable register, the  *       interrupt line will assert if and only if the inhibit register is  *       zero. The inhibit register is the only interrupt-related register that  *       does not share the bit definitions - it is a boolean on/off register.  */
end_comment

begin_comment
comment|/* Create/destroy */
end_comment

begin_comment
comment|/* Used by all portal interrupt registers except 'inhibit' */
end_comment

begin_define
define|#
directive|define
name|QM_PIRQ_CSCI
value|0x00100000
end_define

begin_comment
comment|/* Congestion State Change */
end_comment

begin_define
define|#
directive|define
name|QM_PIRQ_EQCI
value|0x00080000
end_define

begin_comment
comment|/* Enqueue Command Committed */
end_comment

begin_define
define|#
directive|define
name|QM_PIRQ_EQRI
value|0x00040000
end_define

begin_comment
comment|/* EQCR Ring (below threshold) */
end_comment

begin_define
define|#
directive|define
name|QM_PIRQ_DQRI
value|0x00020000
end_define

begin_comment
comment|/* DQRR Ring (non-empty) */
end_comment

begin_define
define|#
directive|define
name|QM_PIRQ_MRI
value|0x00010000
end_define

begin_comment
comment|/* MR Ring (non-empty) */
end_comment

begin_comment
comment|/* The DQAVAIL interrupt fields break down into these bits; */
end_comment

begin_define
define|#
directive|define
name|QM_PIRQ_DQAVAIL
value|0x0000ffff
end_define

begin_comment
comment|/* Channels with frame availability */
end_comment

begin_define
define|#
directive|define
name|QM_DQAVAIL_PORTAL
value|0x8000
end_define

begin_comment
comment|/* Portal channel */
end_comment

begin_define
define|#
directive|define
name|QM_DQAVAIL_POOL
parameter_list|(
name|n
parameter_list|)
value|(0x8000>> (n))
end_define

begin_comment
comment|/* Pool channel, n==[1..15] */
end_comment

begin_comment
comment|/* These are qm_<reg>_<verb>(). So for example, qm_disable_write() means "write  * the disable register" rather than "disable the ability to write". */
end_comment

begin_define
define|#
directive|define
name|qm_isr_status_read
parameter_list|(
name|qm
parameter_list|)
value|__qm_isr_read(qm, qm_isr_status)
end_define

begin_define
define|#
directive|define
name|qm_isr_status_clear
parameter_list|(
name|qm
parameter_list|,
name|m
parameter_list|)
value|__qm_isr_write(qm, qm_isr_status, m)
end_define

begin_define
define|#
directive|define
name|qm_isr_enable_read
parameter_list|(
name|qm
parameter_list|)
value|__qm_isr_read(qm, qm_isr_enable)
end_define

begin_define
define|#
directive|define
name|qm_isr_enable_write
parameter_list|(
name|qm
parameter_list|,
name|v
parameter_list|)
value|__qm_isr_write(qm, qm_isr_enable, v)
end_define

begin_define
define|#
directive|define
name|qm_isr_disable_read
parameter_list|(
name|qm
parameter_list|)
value|__qm_isr_read(qm, qm_isr_disable)
end_define

begin_define
define|#
directive|define
name|qm_isr_disable_write
parameter_list|(
name|qm
parameter_list|,
name|v
parameter_list|)
value|__qm_isr_write(qm, qm_isr_disable, v)
end_define

begin_define
define|#
directive|define
name|qm_isr_inhibit
parameter_list|(
name|qm
parameter_list|)
value|__qm_isr_write(qm, qm_isr_inhibit, 1)
end_define

begin_define
define|#
directive|define
name|qm_isr_uninhibit
parameter_list|(
name|qm
parameter_list|)
value|__qm_isr_write(qm, qm_isr_inhibit, 0)
end_define

begin_comment
comment|/* ------------------------------------------------------- */
end_comment

begin_comment
comment|/* --- Qman data structures (and associated constants) --- */
end_comment

begin_comment
comment|/* See David Lapp's "Frame formats" document, "dpateam", Jan 07, 2008 */
end_comment

begin_define
define|#
directive|define
name|QM_FD_FORMAT_SG
value|0x4
end_define

begin_define
define|#
directive|define
name|QM_FD_FORMAT_LONG
value|0x2
end_define

begin_define
define|#
directive|define
name|QM_FD_FORMAT_COMPOUND
value|0x1
end_define

begin_enum
enum|enum
name|qm_fd_format
block|{
comment|/* 'contig' implies a contiguous buffer, whereas 'sg' implies a      * scatter-gather table. 'big' implies a 29-bit length with no offset      * field, otherwise length is 20-bit and offset is 9-bit. 'compound'      * implies a s/g-like table, where each entry itself represents a frame      * (contiguous or scatter-gather) and the 29-bit "length" is      * interpreted purely for congestion calculations, ie. a "congestion      * weight". */
name|qm_fd_contig
init|=
literal|0
block|,
name|qm_fd_contig_big
init|=
name|QM_FD_FORMAT_LONG
block|,
name|qm_fd_sg
init|=
name|QM_FD_FORMAT_SG
block|,
name|qm_fd_sg_big
init|=
name|QM_FD_FORMAT_SG
operator||
name|QM_FD_FORMAT_LONG
block|,
name|qm_fd_compound
init|=
name|QM_FD_FORMAT_COMPOUND
block|}
enum|;
end_enum

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
name|qm_fqd_stashing
block|{
comment|/* See QM_STASHING_EXCL_<...> */
specifier|volatile
name|uint8_t
name|exclusive
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved1
range|:
literal|2
decl_stmt|;
comment|/* Numbers of cachelines */
specifier|volatile
name|uint8_t
name|annotation_cl
range|:
literal|2
decl_stmt|;
specifier|volatile
name|uint8_t
name|data_cl
range|:
literal|2
decl_stmt|;
specifier|volatile
name|uint8_t
name|context_cl
range|:
literal|2
decl_stmt|;
block|}
name|_PackedType
struct|;
end_struct

begin_typedef
typedef|typedef
name|_Packed
union|union
block|{
comment|/* Treat it as 64-bit opaque */
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|hi
decl_stmt|;
specifier|volatile
name|uint32_t
name|lo
decl_stmt|;
block|}
name|_PackedType
struct|;
comment|/* Treat it as s/w portal stashing config */
comment|/* See 1.5.6.7.1: "FQD Context_A field used for [...] */
name|_Packed
struct|struct
block|{
name|struct
name|qm_fqd_stashing
name|stashing
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved1
decl_stmt|;
comment|/* 40-bit address of FQ context to          * stash, must be cacheline-aligned */
specifier|volatile
name|uint8_t
name|context_hi
decl_stmt|;
specifier|volatile
name|uint32_t
name|context_lo
decl_stmt|;
block|}
name|_PackedType
struct|;
block|}
name|_PackedType
name|u_QmFqdContextA
typedef|;
end_typedef

begin_comment
comment|/* See 1.5.1.1: "Frame Descriptor (FD)" */
end_comment

begin_macro
name|_Packed
end_macro

begin_struct
struct|struct
name|qm_fd
block|{
specifier|volatile
name|uint8_t
name|dd
range|:
literal|2
decl_stmt|;
comment|/* dynamic debug */
specifier|volatile
name|uint8_t
name|liodn_offset
range|:
literal|6
decl_stmt|;
comment|/* aka. "Partition ID" in rev1.0 */
specifier|volatile
name|uint8_t
name|bpid
decl_stmt|;
comment|/* Buffer Pool ID */
specifier|volatile
name|uint8_t
name|eliodn_offset
range|:
literal|4
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved
range|:
literal|4
decl_stmt|;
specifier|volatile
name|uint8_t
name|addr_hi
decl_stmt|;
comment|/* high 8-bits of 40-bit address */
specifier|volatile
name|uint32_t
name|addr_lo
decl_stmt|;
comment|/* low 32-bits of 40-bit address */
comment|/* The 'format' field indicates the interpretation of the remaining 29      * bits of the 32-bit word. For packing reasons, it is duplicated in the      * other union elements. */
name|_Packed
union|union
block|{
comment|/* If 'format' is _contig or _sg, 20b length and 9b offset */
name|_Packed
struct|struct
block|{
specifier|volatile
name|enum
name|qm_fd_format
name|format
range|:
literal|3
decl_stmt|;
specifier|volatile
name|uint16_t
name|offset
range|:
literal|9
decl_stmt|;
specifier|volatile
name|uint32_t
name|length20
range|:
literal|20
decl_stmt|;
block|}
name|_PackedType
struct|;
comment|/* If 'format' is _contig_big or _sg_big, 29b length */
name|_Packed
struct|struct
block|{
specifier|volatile
name|enum
name|qm_fd_format
name|_format1
range|:
literal|3
decl_stmt|;
specifier|volatile
name|uint32_t
name|length29
range|:
literal|29
decl_stmt|;
block|}
name|_PackedType
struct|;
comment|/* If 'format' is _compound, 29b "congestion weight" */
name|_Packed
struct|struct
block|{
specifier|volatile
name|enum
name|qm_fd_format
name|_format2
range|:
literal|3
decl_stmt|;
specifier|volatile
name|uint32_t
name|cong_weight
range|:
literal|29
decl_stmt|;
block|}
name|_PackedType
struct|;
comment|/* For easier/faster copying of this part of the fd (eg. from a          * DQRR entry to an EQCR entry) copy 'opaque' */
specifier|volatile
name|uint32_t
name|opaque
decl_stmt|;
block|}
name|_PackedType
union|;
name|_Packed
union|union
block|{
specifier|volatile
name|uint32_t
name|cmd
decl_stmt|;
specifier|volatile
name|uint32_t
name|status
decl_stmt|;
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
name|QM_FD_DD_NULL
value|0x00
end_define

begin_define
define|#
directive|define
name|QM_FD_PID_MASK
value|0x3f
end_define

begin_comment
comment|/* See 1.5.8.1: "Enqueue Command" */
end_comment

begin_macro
name|_Packed
end_macro

begin_struct
struct|struct
name|qm_eqcr_entry
block|{
specifier|volatile
name|uint8_t
name|__dont_write_directly__verb
decl_stmt|;
specifier|volatile
name|uint8_t
name|dca
decl_stmt|;
specifier|volatile
name|uint16_t
name|seqnum
decl_stmt|;
specifier|volatile
name|uint32_t
name|orp
decl_stmt|;
comment|/* 24-bit */
specifier|volatile
name|uint32_t
name|fqid
decl_stmt|;
comment|/* 24-bit */
specifier|volatile
name|uint32_t
name|tag
decl_stmt|;
specifier|volatile
name|struct
name|qm_fd
name|fd
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved3
index|[
literal|32
index|]
decl_stmt|;
block|}
name|_PackedType
struct|;
end_struct

begin_define
define|#
directive|define
name|QM_EQCR_VERB_VBIT
value|0x80
end_define

begin_define
define|#
directive|define
name|QM_EQCR_VERB_CMD_MASK
value|0x61
end_define

begin_comment
comment|/* but only one value; */
end_comment

begin_define
define|#
directive|define
name|QM_EQCR_VERB_CMD_ENQUEUE
value|0x01
end_define

begin_define
define|#
directive|define
name|QM_EQCR_VERB_COLOUR_MASK
value|0x18
end_define

begin_comment
comment|/* 4 possible values; */
end_comment

begin_define
define|#
directive|define
name|QM_EQCR_VERB_COLOUR_GREEN
value|0x00
end_define

begin_define
define|#
directive|define
name|QM_EQCR_VERB_COLOUR_YELLOW
value|0x08
end_define

begin_define
define|#
directive|define
name|QM_EQCR_VERB_COLOUR_RED
value|0x10
end_define

begin_define
define|#
directive|define
name|QM_EQCR_VERB_COLOUR_OVERRIDE
value|0x18
end_define

begin_define
define|#
directive|define
name|QM_EQCR_VERB_INTERRUPT
value|0x04
end_define

begin_comment
comment|/* on command consumption */
end_comment

begin_define
define|#
directive|define
name|QM_EQCR_VERB_ORP
value|0x02
end_define

begin_comment
comment|/* enable order restoration */
end_comment

begin_define
define|#
directive|define
name|QM_EQCR_DCA_ENABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|QM_EQCR_DCA_PARK
value|0x40
end_define

begin_define
define|#
directive|define
name|QM_EQCR_DCA_IDXMASK
value|0x0f
end_define

begin_comment
comment|/* "DQRR::idx" goes here */
end_comment

begin_define
define|#
directive|define
name|QM_EQCR_SEQNUM_NESN
value|0x8000
end_define

begin_comment
comment|/* Advance NESN */
end_comment

begin_define
define|#
directive|define
name|QM_EQCR_SEQNUM_NLIS
value|0x4000
end_define

begin_comment
comment|/* More fragments to come */
end_comment

begin_define
define|#
directive|define
name|QM_EQCR_SEQNUM_SEQMASK
value|0x3fff
end_define

begin_comment
comment|/* sequence number goes here */
end_comment

begin_define
define|#
directive|define
name|QM_EQCR_FQID_NULL
value|0
end_define

begin_comment
comment|/* eg. for an ORP seqnum hole */
end_comment

begin_comment
comment|/* See 1.5.8.2: "Frame Dequeue Response" */
end_comment

begin_macro
name|_Packed
end_macro

begin_struct
struct|struct
name|qm_dqrr_entry
block|{
specifier|volatile
name|uint8_t
name|verb
decl_stmt|;
specifier|volatile
name|uint8_t
name|stat
decl_stmt|;
specifier|volatile
name|uint16_t
name|seqnum
decl_stmt|;
comment|/* 15-bit */
specifier|volatile
name|uint8_t
name|tok
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|fqid
decl_stmt|;
comment|/* 24-bit */
specifier|volatile
name|uint32_t
name|contextB
decl_stmt|;
specifier|volatile
name|struct
name|qm_fd
name|fd
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved4
index|[
literal|32
index|]
decl_stmt|;
block|}
name|_PackedType
struct|;
end_struct

begin_define
define|#
directive|define
name|QM_DQRR_VERB_VBIT
value|0x80
end_define

begin_define
define|#
directive|define
name|QM_DQRR_VERB_MASK
value|0x7f
end_define

begin_comment
comment|/* where the verb contains; */
end_comment

begin_define
define|#
directive|define
name|QM_DQRR_VERB_FRAME_DEQUEUE
value|0x60
end_define

begin_comment
comment|/* "this format" */
end_comment

begin_define
define|#
directive|define
name|QM_DQRR_STAT_FQ_EMPTY
value|0x80
end_define

begin_comment
comment|/* FQ empty */
end_comment

begin_define
define|#
directive|define
name|QM_DQRR_STAT_FQ_HELDACTIVE
value|0x40
end_define

begin_comment
comment|/* FQ held active */
end_comment

begin_define
define|#
directive|define
name|QM_DQRR_STAT_FQ_FORCEELIGIBLE
value|0x20
end_define

begin_comment
comment|/* FQ was force-eligible'd */
end_comment

begin_define
define|#
directive|define
name|QM_DQRR_STAT_FD_VALID
value|0x10
end_define

begin_comment
comment|/* has a non-NULL FD */
end_comment

begin_define
define|#
directive|define
name|QM_DQRR_STAT_UNSCHEDULED
value|0x02
end_define

begin_comment
comment|/* Unscheduled dequeue */
end_comment

begin_define
define|#
directive|define
name|QM_DQRR_STAT_DQCR_EXPIRED
value|0x01
end_define

begin_comment
comment|/* VDQCR or PDQCR expired*/
end_comment

begin_define
define|#
directive|define
name|VDQCR_DONE
value|(QM_DQRR_STAT_UNSCHEDULED | QM_DQRR_STAT_DQCR_EXPIRED)
end_define

begin_comment
comment|/* See 1.5.8.3: "ERN Message Response" */
end_comment

begin_comment
comment|/* See 1.5.8.4: "FQ State Change Notification" */
end_comment

begin_macro
name|_Packed
end_macro

begin_struct
struct|struct
name|qm_mr_entry
block|{
specifier|volatile
name|uint8_t
name|verb
decl_stmt|;
name|_Packed
union|union
block|{
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint8_t
name|dca
decl_stmt|;
specifier|volatile
name|uint16_t
name|seqnum
decl_stmt|;
specifier|volatile
name|uint8_t
name|rc
decl_stmt|;
comment|/* Rejection Code */
specifier|volatile
name|uint32_t
name|orp
range|:
literal|24
decl_stmt|;
specifier|volatile
name|uint32_t
name|fqid
decl_stmt|;
comment|/* 24-bit */
specifier|volatile
name|uint32_t
name|tag
decl_stmt|;
specifier|volatile
name|struct
name|qm_fd
name|fd
decl_stmt|;
block|}
name|_PackedType
name|ern
struct|;
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint8_t
name|colour
range|:
literal|2
decl_stmt|;
comment|/* See QM_MR_DCERN_COLOUR_* */
specifier|volatile
name|uint8_t
name|reserved1
range|:
literal|3
decl_stmt|;
specifier|volatile
name|enum
name|qm_dc_portal
name|portal
range|:
literal|3
decl_stmt|;
specifier|volatile
name|uint16_t
name|reserved2
decl_stmt|;
specifier|volatile
name|uint8_t
name|rc
decl_stmt|;
comment|/* Rejection Code */
specifier|volatile
name|uint32_t
name|reserved3
range|:
literal|24
decl_stmt|;
specifier|volatile
name|uint32_t
name|fqid
decl_stmt|;
comment|/* 24-bit */
specifier|volatile
name|uint32_t
name|tag
decl_stmt|;
specifier|volatile
name|struct
name|qm_fd
name|fd
decl_stmt|;
block|}
name|_PackedType
name|dcern
struct|;
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint8_t
name|fqs
decl_stmt|;
comment|/* Frame Queue Status */
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|6
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|fqid
decl_stmt|;
comment|/* 24-bit */
specifier|volatile
name|uint32_t
name|contextB
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved2
index|[
literal|16
index|]
decl_stmt|;
block|}
name|_PackedType
name|fq
struct|;
comment|/* FQRN/FQRNI/FQRL/FQPN */
block|}
name|_PackedType
union|;
specifier|volatile
name|uint8_t
name|reserved2
index|[
literal|32
index|]
decl_stmt|;
block|}
name|_PackedType
struct|;
end_struct

begin_define
define|#
directive|define
name|QM_MR_VERB_VBIT
value|0x80
end_define

begin_comment
comment|/* The "ern" VERB bits match QM_EQCR_VERB_*** so aren't reproduced here. ERNs  * originating from direct-connect portals ("dcern") use 0x20 as a verb which  * would be invalid as a s/w enqueue verb. A s/w ERN can be distinguished from  * the other MR types by noting if the 0x20 bit is unset. */
end_comment

begin_define
define|#
directive|define
name|QM_MR_VERB_TYPE_MASK
value|0x23
end_define

begin_define
define|#
directive|define
name|QM_MR_VERB_DC_ERN
value|0x20
end_define

begin_define
define|#
directive|define
name|QM_MR_VERB_FQRN
value|0x21
end_define

begin_define
define|#
directive|define
name|QM_MR_VERB_FQRNI
value|0x22
end_define

begin_define
define|#
directive|define
name|QM_MR_VERB_FQRL
value|0x23
end_define

begin_define
define|#
directive|define
name|QM_MR_VERB_FQPN
value|0x24
end_define

begin_define
define|#
directive|define
name|QM_MR_RC_MASK
value|0xf0
end_define

begin_comment
comment|/* contains one of; */
end_comment

begin_define
define|#
directive|define
name|QM_MR_RC_CGR_TAILDROP
value|0x00
end_define

begin_define
define|#
directive|define
name|QM_MR_RC_WRED
value|0x10
end_define

begin_define
define|#
directive|define
name|QM_MR_RC_ERROR
value|0x20
end_define

begin_define
define|#
directive|define
name|QM_MR_RC_ORPWINDOW_EARLY
value|0x30
end_define

begin_define
define|#
directive|define
name|QM_MR_RC_ORPWINDOW_LATE
value|0x40
end_define

begin_define
define|#
directive|define
name|QM_MR_RC_FQ_TAILDROP
value|0x50
end_define

begin_define
define|#
directive|define
name|QM_MR_RC_ORP_RETIRED
value|0x60
end_define

begin_define
define|#
directive|define
name|QM_MR_RC_ORP_DISABLE
value|0x70
end_define

begin_define
define|#
directive|define
name|QM_MR_FQS_ORLPRESENT
value|0x02
end_define

begin_comment
comment|/* ORL fragments to come */
end_comment

begin_define
define|#
directive|define
name|QM_MR_FQS_NOTEMPTY
value|0x01
end_define

begin_comment
comment|/* FQ has enqueued frames */
end_comment

begin_define
define|#
directive|define
name|QM_MR_DCERN_COLOUR_GREEN
value|0x00
end_define

begin_define
define|#
directive|define
name|QM_MR_DCERN_COLOUR_YELLOW
value|0x01
end_define

begin_define
define|#
directive|define
name|QM_MR_DCERN_COLOUR_RED
value|0x02
end_define

begin_define
define|#
directive|define
name|QM_MR_DCERN_COLOUR_OVERRIDE
value|0x03
end_define

begin_comment
comment|/* This identical structure of FQD fields is present in the "Init FQ" command  * and the "Query FQ" result. It's suctioned out here into its own struct. It's  * also used as the qman_query_fq() result structure in the high-level API. */
end_comment

begin_comment
comment|/* TODO What about OAC for intra-class? */
end_comment

begin_define
define|#
directive|define
name|QM_FQD_TD_THRESH_OAC_EN
value|0x4000
end_define

begin_macro
name|_Packed
end_macro

begin_struct
struct|struct
name|qm_fqd
block|{
name|_Packed
union|union
block|{
specifier|volatile
name|uint8_t
name|orpc
decl_stmt|;
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint8_t
name|reserved1
range|:
literal|2
decl_stmt|;
specifier|volatile
name|uint8_t
name|orprws
range|:
literal|3
decl_stmt|;
specifier|volatile
name|uint8_t
name|oa
range|:
literal|1
decl_stmt|;
specifier|volatile
name|uint8_t
name|olws
range|:
literal|2
decl_stmt|;
block|}
name|_PackedType
struct|;
block|}
name|_PackedType
union|;
specifier|volatile
name|uint8_t
name|cgid
decl_stmt|;
specifier|volatile
name|uint16_t
name|fq_ctrl
decl_stmt|;
comment|/* See QM_FQCTRL_<...> */
name|_Packed
union|union
block|{
specifier|volatile
name|uint16_t
name|dest_wq
decl_stmt|;
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint16_t
name|channel
range|:
literal|13
decl_stmt|;
comment|/* enum qm_channel */
specifier|volatile
name|uint16_t
name|wq
range|:
literal|3
decl_stmt|;
block|}
name|_PackedType
name|dest
struct|;
block|}
name|_PackedType
union|;
specifier|volatile
name|uint16_t
name|reserved2
range|:
literal|1
decl_stmt|;
specifier|volatile
name|uint16_t
name|ics_cred
range|:
literal|15
decl_stmt|;
name|_Packed
union|union
block|{
specifier|volatile
name|uint16_t
name|td_thresh
decl_stmt|;
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint16_t
name|reserved1
range|:
literal|3
decl_stmt|;
specifier|volatile
name|uint16_t
name|mant
range|:
literal|8
decl_stmt|;
specifier|volatile
name|uint16_t
name|exp
range|:
literal|5
decl_stmt|;
block|}
name|_PackedType
name|td
struct|;
block|}
name|_PackedType
union|;
specifier|volatile
name|uint32_t
name|context_b
decl_stmt|;
specifier|volatile
name|u_QmFqdContextA
name|context_a
decl_stmt|;
block|}
name|_PackedType
struct|;
end_struct

begin_comment
comment|/* See 1.5.2.2: "Frame Queue Descriptor (FQD)" */
end_comment

begin_comment
comment|/* Frame Queue Descriptor (FQD) field 'fq_ctrl' uses these constants */
end_comment

begin_define
define|#
directive|define
name|QM_FQCTRL_MASK
value|0x07ff
end_define

begin_comment
comment|/* 'fq_ctrl' flags; */
end_comment

begin_define
define|#
directive|define
name|QM_FQCTRL_CGE
value|0x0400
end_define

begin_comment
comment|/* Congestion Group Enable */
end_comment

begin_define
define|#
directive|define
name|QM_FQCTRL_TDE
value|0x0200
end_define

begin_comment
comment|/* Tail-Drop Enable */
end_comment

begin_define
define|#
directive|define
name|QM_FQCTRL_ORP
value|0x0100
end_define

begin_comment
comment|/* ORP Enable */
end_comment

begin_define
define|#
directive|define
name|QM_FQCTRL_CTXASTASHING
value|0x0080
end_define

begin_comment
comment|/* Context-A stashing */
end_comment

begin_define
define|#
directive|define
name|QM_FQCTRL_CPCSTASH
value|0x0040
end_define

begin_comment
comment|/* CPC Stash Enable */
end_comment

begin_define
define|#
directive|define
name|QM_FQCTRL_FORCESFDR
value|0x0008
end_define

begin_comment
comment|/* High-priority SFDRs */
end_comment

begin_define
define|#
directive|define
name|QM_FQCTRL_AVOIDBLOCK
value|0x0004
end_define

begin_comment
comment|/* Don't block active */
end_comment

begin_define
define|#
directive|define
name|QM_FQCTRL_HOLDACTIVE
value|0x0002
end_define

begin_comment
comment|/* Hold active in portal */
end_comment

begin_define
define|#
directive|define
name|QM_FQCTRL_LOCKINCACHE
value|0x0001
end_define

begin_comment
comment|/* Aggressively cache FQD */
end_comment

begin_comment
comment|/* See 1.5.6.7.1: "FQD Context_A field used for [...] */
end_comment

begin_comment
comment|/* Frame Queue Descriptor (FQD) field 'CONTEXT_A' uses these constants */
end_comment

begin_define
define|#
directive|define
name|QM_STASHING_EXCL_ANNOTATION
value|0x04
end_define

begin_define
define|#
directive|define
name|QM_STASHING_EXCL_DATA
value|0x02
end_define

begin_define
define|#
directive|define
name|QM_STASHING_EXCL_CONTEXT
value|0x01
end_define

begin_comment
comment|/* See 1.5.8.4: "FQ State Change Notification" */
end_comment

begin_comment
comment|/* This struct represents the 32-bit "WR_PARM_[GYR]" parameters in CGR fields  * and associated commands/responses. The WRED parameters are calculated from  * these fields as follows;  *   MaxTH = MA * (2 ^ Mn)  *   Slope = SA / (2 ^ Sn)  *    MaxP = 4 * (Pn + 1)  */
end_comment

begin_macro
name|_Packed
end_macro

begin_struct
struct|struct
name|qm_cgr_wr_parm
block|{
name|_Packed
union|union
block|{
specifier|volatile
name|uint32_t
name|word
decl_stmt|;
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|MA
range|:
literal|8
decl_stmt|;
specifier|volatile
name|uint32_t
name|Mn
range|:
literal|5
decl_stmt|;
specifier|volatile
name|uint32_t
name|SA
range|:
literal|7
decl_stmt|;
comment|/* must be between 64-127 */
specifier|volatile
name|uint32_t
name|Sn
range|:
literal|6
decl_stmt|;
specifier|volatile
name|uint32_t
name|Pn
range|:
literal|6
decl_stmt|;
block|}
name|_PackedType
struct|;
block|}
name|_PackedType
union|;
block|}
name|_PackedType
struct|;
end_struct

begin_comment
comment|/* This struct represents the 13-bit "CS_THRES" CGR field. In the corresponding  * management commands, this is padded to a 16-bit structure field, so that's  * how we represent it here. The congestion state threshold is calculated from  * these fields as follows;  *   CS threshold = TA * (2 ^ Tn)  */
end_comment

begin_macro
name|_Packed
end_macro

begin_struct
struct|struct
name|qm_cgr_cs_thres
block|{
specifier|volatile
name|uint16_t
name|reserved
range|:
literal|3
decl_stmt|;
specifier|volatile
name|uint16_t
name|TA
range|:
literal|8
decl_stmt|;
specifier|volatile
name|uint16_t
name|Tn
range|:
literal|5
decl_stmt|;
block|}
name|_PackedType
struct|;
end_struct

begin_comment
comment|/* This identical structure of CGR fields is present in the "Init/Modify CGR"  * commands and the "Query CGR" result. It's suctioned out here into its own  * struct. */
end_comment

begin_macro
name|_Packed
end_macro

begin_struct
struct|struct
name|__qm_mc_cgr
block|{
specifier|volatile
name|struct
name|qm_cgr_wr_parm
name|wr_parm_g
decl_stmt|;
specifier|volatile
name|struct
name|qm_cgr_wr_parm
name|wr_parm_y
decl_stmt|;
specifier|volatile
name|struct
name|qm_cgr_wr_parm
name|wr_parm_r
decl_stmt|;
specifier|volatile
name|uint8_t
name|wr_en_g
decl_stmt|;
comment|/* boolean, use QM_CGR_EN */
specifier|volatile
name|uint8_t
name|wr_en_y
decl_stmt|;
comment|/* boolean, use QM_CGR_EN */
specifier|volatile
name|uint8_t
name|wr_en_r
decl_stmt|;
comment|/* boolean, use QM_CGR_EN */
specifier|volatile
name|uint8_t
name|cscn_en
decl_stmt|;
comment|/* boolean, use QM_CGR_EN */
specifier|volatile
name|uint32_t
name|cscn_targ
decl_stmt|;
comment|/* use QM_CGR_TARG_* */
specifier|volatile
name|uint8_t
name|cstd_en
decl_stmt|;
comment|/* boolean, use QM_CGR_EN */
specifier|volatile
name|uint8_t
name|cs
decl_stmt|;
comment|/* boolean, only used in query response */
specifier|volatile
name|struct
name|qm_cgr_cs_thres
name|cs_thres
decl_stmt|;
specifier|volatile
name|uint8_t
name|frame_mode
decl_stmt|;
comment|/* boolean, use QM_CGR_EN */
block|}
name|_PackedType
struct|;
end_struct

begin_define
define|#
directive|define
name|QM_CGR_EN
value|0x01
end_define

begin_comment
comment|/* For wr_en_*, cscn_en, cstd_en, frame_mode */
end_comment

begin_comment
comment|/* See 1.5.8.5.1: "Initialize FQ" */
end_comment

begin_comment
comment|/* See 1.5.8.5.2: "Query FQ" */
end_comment

begin_comment
comment|/* See 1.5.8.5.3: "Query FQ Non-Programmable Fields" */
end_comment

begin_comment
comment|/* See 1.5.8.5.4: "Alter FQ State Commands " */
end_comment

begin_comment
comment|/* See 1.5.8.6.1: "Initialize/Modify CGR" */
end_comment

begin_comment
comment|/* See 1.5.8.6.2: "Query CGR" */
end_comment

begin_comment
comment|/* See 1.5.8.6.3: "Query Congestion Group State" */
end_comment

begin_macro
name|_Packed
end_macro

begin_struct
struct|struct
name|qm_mc_command
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
name|qm_mcc_initfq
block|{
specifier|volatile
name|uint8_t
name|reserved1
decl_stmt|;
specifier|volatile
name|uint16_t
name|we_mask
decl_stmt|;
comment|/* Write Enable Mask */
specifier|volatile
name|uint32_t
name|fqid
decl_stmt|;
comment|/* 24-bit */
specifier|volatile
name|uint16_t
name|count
decl_stmt|;
comment|/* Initialises 'count+1' FQDs */
specifier|volatile
name|struct
name|qm_fqd
name|fqd
decl_stmt|;
comment|/* the FQD fields go here */
specifier|volatile
name|uint8_t
name|reserved3
index|[
literal|32
index|]
decl_stmt|;
block|}
name|_PackedType
name|initfq
struct|;
name|_Packed
struct|struct
name|qm_mcc_queryfq
block|{
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|3
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|fqid
decl_stmt|;
comment|/* 24-bit */
specifier|volatile
name|uint8_t
name|reserved2
index|[
literal|56
index|]
decl_stmt|;
block|}
name|_PackedType
name|queryfq
struct|;
name|_Packed
struct|struct
name|qm_mcc_queryfq_np
block|{
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|3
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|fqid
decl_stmt|;
comment|/* 24-bit */
specifier|volatile
name|uint8_t
name|reserved2
index|[
literal|56
index|]
decl_stmt|;
block|}
name|_PackedType
name|queryfq_np
struct|;
name|_Packed
struct|struct
name|qm_mcc_alterfq
block|{
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|3
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|fqid
decl_stmt|;
comment|/* 24-bit */
specifier|volatile
name|uint8_t
name|reserved2
index|[
literal|12
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|context_b
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved3
index|[
literal|40
index|]
decl_stmt|;
block|}
name|_PackedType
name|alterfq
struct|;
name|_Packed
struct|struct
name|qm_mcc_initcgr
block|{
specifier|volatile
name|uint8_t
name|reserved1
decl_stmt|;
specifier|volatile
name|uint16_t
name|we_mask
decl_stmt|;
comment|/* Write Enable Mask */
specifier|volatile
name|struct
name|__qm_mc_cgr
name|cgr
decl_stmt|;
comment|/* CGR fields */
specifier|volatile
name|uint8_t
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
specifier|volatile
name|uint8_t
name|cgid
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved4
index|[
literal|32
index|]
decl_stmt|;
block|}
name|_PackedType
name|initcgr
struct|;
name|_Packed
struct|struct
name|qm_mcc_querycgr
block|{
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|30
index|]
decl_stmt|;
specifier|volatile
name|uint8_t
name|cgid
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved2
index|[
literal|32
index|]
decl_stmt|;
block|}
name|_PackedType
name|querycgr
struct|;
name|_Packed
struct|struct
name|qm_mcc_querycongestion
block|{
specifier|volatile
name|uint8_t
name|reserved
index|[
literal|63
index|]
decl_stmt|;
block|}
name|_PackedType
name|querycongestion
struct|;
name|_Packed
struct|struct
name|qm_mcc_querywq
block|{
specifier|volatile
name|uint8_t
name|reserved
decl_stmt|;
comment|/* select channel if verb != QUERYWQ_DEDICATED */
name|_Packed
union|union
block|{
specifier|volatile
name|uint16_t
name|channel_wq
decl_stmt|;
comment|/* ignores wq (3 lsbits) */
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint16_t
name|id
range|:
literal|13
decl_stmt|;
comment|/* enum qm_channel */
specifier|volatile
name|uint16_t
name|reserved1
range|:
literal|3
decl_stmt|;
block|}
name|_PackedType
name|channel
struct|;
block|}
name|_PackedType
union|;
specifier|volatile
name|uint8_t
name|reserved2
index|[
literal|60
index|]
decl_stmt|;
block|}
name|_PackedType
name|querywq
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
name|QM_MCC_VERB_VBIT
value|0x80
end_define

begin_define
define|#
directive|define
name|QM_MCC_VERB_MASK
value|0x7f
end_define

begin_comment
comment|/* where the verb contains; */
end_comment

begin_define
define|#
directive|define
name|QM_MCC_VERB_INITFQ_PARKED
value|0x40
end_define

begin_define
define|#
directive|define
name|QM_MCC_VERB_INITFQ_SCHED
value|0x41
end_define

begin_define
define|#
directive|define
name|QM_MCC_VERB_QUERYFQ
value|0x44
end_define

begin_define
define|#
directive|define
name|QM_MCC_VERB_QUERYFQ_NP
value|0x45
end_define

begin_comment
comment|/* "non-programmable" fields */
end_comment

begin_define
define|#
directive|define
name|QM_MCC_VERB_QUERYWQ
value|0x46
end_define

begin_define
define|#
directive|define
name|QM_MCC_VERB_QUERYWQ_DEDICATED
value|0x47
end_define

begin_define
define|#
directive|define
name|QM_MCC_VERB_ALTER_SCHED
value|0x48
end_define

begin_comment
comment|/* Schedule FQ */
end_comment

begin_define
define|#
directive|define
name|QM_MCC_VERB_ALTER_FE
value|0x49
end_define

begin_comment
comment|/* Force Eligible FQ */
end_comment

begin_define
define|#
directive|define
name|QM_MCC_VERB_ALTER_RETIRE
value|0x4a
end_define

begin_comment
comment|/* Retire FQ */
end_comment

begin_define
define|#
directive|define
name|QM_MCC_VERB_ALTER_OOS
value|0x4b
end_define

begin_comment
comment|/* Take FQ out of service */
end_comment

begin_define
define|#
directive|define
name|QM_MCC_VERB_ALTER_RETIRE_CTXB
value|0x4c
end_define

begin_comment
comment|/* Retire FQ with contextB*/
end_comment

begin_define
define|#
directive|define
name|QM_MCC_VERB_INITCGR
value|0x50
end_define

begin_define
define|#
directive|define
name|QM_MCC_VERB_MODIFYCGR
value|0x51
end_define

begin_define
define|#
directive|define
name|QM_MCC_VERB_QUERYCGR
value|0x58
end_define

begin_define
define|#
directive|define
name|QM_MCC_VERB_QUERYCONGESTION
value|0x59
end_define

begin_comment
comment|/* INITFQ-specific flags */
end_comment

begin_define
define|#
directive|define
name|QM_INITFQ_WE_MASK
value|0x01ff
end_define

begin_comment
comment|/* 'Write Enable' flags; */
end_comment

begin_define
define|#
directive|define
name|QM_INITFQ_WE_OAC
value|0x0100
end_define

begin_define
define|#
directive|define
name|QM_INITFQ_WE_ORPC
value|0x0080
end_define

begin_define
define|#
directive|define
name|QM_INITFQ_WE_CGID
value|0x0040
end_define

begin_define
define|#
directive|define
name|QM_INITFQ_WE_FQCTRL
value|0x0020
end_define

begin_define
define|#
directive|define
name|QM_INITFQ_WE_DESTWQ
value|0x0010
end_define

begin_define
define|#
directive|define
name|QM_INITFQ_WE_ICSCRED
value|0x0008
end_define

begin_define
define|#
directive|define
name|QM_INITFQ_WE_TDTHRESH
value|0x0004
end_define

begin_define
define|#
directive|define
name|QM_INITFQ_WE_CONTEXTB
value|0x0002
end_define

begin_define
define|#
directive|define
name|QM_INITFQ_WE_CONTEXTA
value|0x0001
end_define

begin_comment
comment|/* INITCGR/MODIFYCGR-specific flags */
end_comment

begin_define
define|#
directive|define
name|QM_CGR_WE_MASK
value|0x07ff
end_define

begin_comment
comment|/* 'Write Enable Mask'; */
end_comment

begin_define
define|#
directive|define
name|QM_CGR_WE_WR_PARM_G
value|0x0400
end_define

begin_define
define|#
directive|define
name|QM_CGR_WE_WR_PARM_Y
value|0x0200
end_define

begin_define
define|#
directive|define
name|QM_CGR_WE_WR_PARM_R
value|0x0100
end_define

begin_define
define|#
directive|define
name|QM_CGR_WE_WR_EN_G
value|0x0080
end_define

begin_define
define|#
directive|define
name|QM_CGR_WE_WR_EN_Y
value|0x0040
end_define

begin_define
define|#
directive|define
name|QM_CGR_WE_WR_EN_R
value|0x0020
end_define

begin_define
define|#
directive|define
name|QM_CGR_WE_CSCN_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|QM_CGR_WE_CSCN_TARG
value|0x0008
end_define

begin_define
define|#
directive|define
name|QM_CGR_WE_CSTD_EN
value|0x0004
end_define

begin_define
define|#
directive|define
name|QM_CGR_WE_CS_THRES
value|0x0002
end_define

begin_define
define|#
directive|define
name|QM_CGR_WE_MODE
value|0x0001
end_define

begin_comment
comment|/* See 1.5.8.5.1: "Initialize FQ" */
end_comment

begin_comment
comment|/* See 1.5.8.5.2: "Query FQ" */
end_comment

begin_comment
comment|/* See 1.5.8.5.3: "Query FQ Non-Programmable Fields" */
end_comment

begin_comment
comment|/* See 1.5.8.5.4: "Alter FQ State Commands " */
end_comment

begin_comment
comment|/* See 1.5.8.6.1: "Initialize/Modify CGR" */
end_comment

begin_comment
comment|/* See 1.5.8.6.2: "Query CGR" */
end_comment

begin_comment
comment|/* See 1.5.8.6.3: "Query Congestion Group State" */
end_comment

begin_macro
name|_Packed
end_macro

begin_struct
struct|struct
name|qm_mc_result
block|{
specifier|volatile
name|uint8_t
name|verb
decl_stmt|;
specifier|volatile
name|uint8_t
name|result
decl_stmt|;
name|_Packed
union|union
block|{
name|_Packed
struct|struct
name|qm_mcr_initfq
block|{
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|62
index|]
decl_stmt|;
block|}
name|_PackedType
name|initfq
struct|;
name|_Packed
struct|struct
name|qm_mcr_queryfq
block|{
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|8
index|]
decl_stmt|;
specifier|volatile
name|struct
name|qm_fqd
name|fqd
decl_stmt|;
comment|/* the FQD fields are here */
specifier|volatile
name|uint16_t
name|oac
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved2
index|[
literal|30
index|]
decl_stmt|;
block|}
name|_PackedType
name|queryfq
struct|;
name|_Packed
struct|struct
name|qm_mcr_queryfq_np
block|{
specifier|volatile
name|uint8_t
name|reserved1
decl_stmt|;
specifier|volatile
name|uint8_t
name|state
decl_stmt|;
comment|/* QM_MCR_NP_STATE_*** */
specifier|volatile
name|uint8_t
name|reserved2
decl_stmt|;
specifier|volatile
name|uint32_t
name|fqd_link
range|:
literal|24
decl_stmt|;
specifier|volatile
name|uint16_t
name|odp_seq
decl_stmt|;
specifier|volatile
name|uint16_t
name|orp_nesn
decl_stmt|;
specifier|volatile
name|uint16_t
name|orp_ea_hseq
decl_stmt|;
specifier|volatile
name|uint16_t
name|orp_ea_tseq
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved3
decl_stmt|;
specifier|volatile
name|uint32_t
name|orp_ea_hptr
range|:
literal|24
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved4
decl_stmt|;
specifier|volatile
name|uint32_t
name|orp_ea_tptr
range|:
literal|24
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved5
decl_stmt|;
specifier|volatile
name|uint32_t
name|pfdr_hptr
range|:
literal|24
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved6
decl_stmt|;
specifier|volatile
name|uint32_t
name|pfdr_tptr
range|:
literal|24
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved7
index|[
literal|5
index|]
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved8
range|:
literal|7
decl_stmt|;
specifier|volatile
name|uint8_t
name|is
range|:
literal|1
decl_stmt|;
specifier|volatile
name|uint16_t
name|ics_surp
decl_stmt|;
specifier|volatile
name|uint32_t
name|byte_cnt
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved9
decl_stmt|;
specifier|volatile
name|uint32_t
name|frm_cnt
range|:
literal|24
decl_stmt|;
specifier|volatile
name|uint32_t
name|reserved10
decl_stmt|;
specifier|volatile
name|uint16_t
name|ra1_sfdr
decl_stmt|;
comment|/* QM_MCR_NP_RA1_*** */
specifier|volatile
name|uint16_t
name|ra2_sfdr
decl_stmt|;
comment|/* QM_MCR_NP_RA2_*** */
specifier|volatile
name|uint16_t
name|reserved11
decl_stmt|;
specifier|volatile
name|uint16_t
name|od1_sfdr
decl_stmt|;
comment|/* QM_MCR_NP_OD1_*** */
specifier|volatile
name|uint16_t
name|od2_sfdr
decl_stmt|;
comment|/* QM_MCR_NP_OD2_*** */
specifier|volatile
name|uint16_t
name|od3_sfdr
decl_stmt|;
comment|/* QM_MCR_NP_OD3_*** */
block|}
name|_PackedType
name|queryfq_np
struct|;
name|_Packed
struct|struct
name|qm_mcr_alterfq
block|{
specifier|volatile
name|uint8_t
name|fqs
decl_stmt|;
comment|/* Frame Queue Status */
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|61
index|]
decl_stmt|;
block|}
name|_PackedType
name|alterfq
struct|;
name|_Packed
struct|struct
name|qm_mcr_initcgr
block|{
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|62
index|]
decl_stmt|;
block|}
name|_PackedType
name|initcgr
struct|;
name|_Packed
struct|struct
name|qm_mcr_querycgr
block|{
specifier|volatile
name|uint16_t
name|reserved1
decl_stmt|;
specifier|volatile
name|struct
name|__qm_mc_cgr
name|cgr
decl_stmt|;
comment|/* CGR fields */
specifier|volatile
name|uint8_t
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|reserved3
range|:
literal|24
decl_stmt|;
specifier|volatile
name|uint32_t
name|i_bcnt_hi
range|:
literal|8
decl_stmt|;
comment|/* high 8-bits of 40-bit "Instant" */
specifier|volatile
name|uint32_t
name|i_bcnt_lo
decl_stmt|;
comment|/* low 32-bits of 40-bit */
specifier|volatile
name|uint32_t
name|reserved4
range|:
literal|24
decl_stmt|;
specifier|volatile
name|uint32_t
name|a_bcnt_hi
range|:
literal|8
decl_stmt|;
comment|/* high 8-bits of 40-bit "Average" */
specifier|volatile
name|uint32_t
name|a_bcnt_lo
decl_stmt|;
comment|/* low 32-bits of 40-bit */
specifier|volatile
name|uint32_t
name|lgt
decl_stmt|;
comment|/* Last Group Tick */
specifier|volatile
name|uint8_t
name|reserved5
index|[
literal|12
index|]
decl_stmt|;
block|}
name|_PackedType
name|querycgr
struct|;
name|_Packed
struct|struct
name|qm_mcr_querycongestion
block|{
specifier|volatile
name|uint8_t
name|reserved
index|[
literal|30
index|]
decl_stmt|;
comment|/* Access this struct using QM_MCR_QUERYCONGESTION() */
name|_Packed
struct|struct
name|__qm_mcr_querycongestion
block|{
specifier|volatile
name|uint32_t
name|__state
index|[
literal|8
index|]
decl_stmt|;
block|}
name|_PackedType
name|state
struct|;
block|}
name|_PackedType
name|querycongestion
struct|;
name|_Packed
struct|struct
name|qm_mcr_querywq
block|{
name|_Packed
union|union
block|{
specifier|volatile
name|uint16_t
name|channel_wq
decl_stmt|;
comment|/* ignores wq (3 lsbits) */
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint16_t
name|id
range|:
literal|13
decl_stmt|;
comment|/* enum qm_channel */
specifier|volatile
name|uint16_t
name|reserved
range|:
literal|3
decl_stmt|;
block|}
name|_PackedType
name|channel
struct|;
block|}
name|_PackedType
union|;
specifier|volatile
name|uint8_t
name|reserved
index|[
literal|28
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|wq_len
index|[
literal|8
index|]
decl_stmt|;
block|}
name|_PackedType
name|querywq
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
name|QM_MCR_VERB_RRID
value|0x80
end_define

begin_define
define|#
directive|define
name|QM_MCR_VERB_MASK
value|QM_MCC_VERB_MASK
end_define

begin_define
define|#
directive|define
name|QM_MCR_VERB_INITFQ_PARKED
value|QM_MCC_VERB_INITFQ_PARKED
end_define

begin_define
define|#
directive|define
name|QM_MCR_VERB_INITFQ_SCHED
value|QM_MCC_VERB_INITFQ_SCHED
end_define

begin_define
define|#
directive|define
name|QM_MCR_VERB_QUERYFQ
value|QM_MCC_VERB_QUERYFQ
end_define

begin_define
define|#
directive|define
name|QM_MCR_VERB_QUERYFQ_NP
value|QM_MCC_VERB_QUERYFQ_NP
end_define

begin_define
define|#
directive|define
name|QM_MCR_VERB_QUERYWQ
value|QM_MCC_VERB_QUERYWQ
end_define

begin_define
define|#
directive|define
name|QM_MCR_VERB_QUERYWQ_DEDICATED
value|QM_MCC_VERB_QUERYWQ_DEDICATED
end_define

begin_define
define|#
directive|define
name|QM_MCR_VERB_ALTER_SCHED
value|QM_MCC_VERB_ALTER_SCHED
end_define

begin_define
define|#
directive|define
name|QM_MCR_VERB_ALTER_FE
value|QM_MCC_VERB_ALTER_FE
end_define

begin_define
define|#
directive|define
name|QM_MCR_VERB_ALTER_RETIRE
value|QM_MCC_VERB_ALTER_RETIRE
end_define

begin_define
define|#
directive|define
name|QM_MCR_VERB_ALTER_RETIRE_CTXB
value|QM_MCC_VERB_ALTER_RETIRE_CTXB
end_define

begin_define
define|#
directive|define
name|QM_MCR_VERB_ALTER_OOS
value|QM_MCC_VERB_ALTER_OOS
end_define

begin_define
define|#
directive|define
name|QM_MCR_RESULT_NULL
value|0x00
end_define

begin_define
define|#
directive|define
name|QM_MCR_RESULT_OK
value|0xf0
end_define

begin_define
define|#
directive|define
name|QM_MCR_RESULT_ERR_FQID
value|0xf1
end_define

begin_define
define|#
directive|define
name|QM_MCR_RESULT_ERR_FQSTATE
value|0xf2
end_define

begin_define
define|#
directive|define
name|QM_MCR_RESULT_ERR_NOTEMPTY
value|0xf3
end_define

begin_comment
comment|/* OOS fails if FQ is !empty */
end_comment

begin_define
define|#
directive|define
name|QM_MCR_RESULT_ERR_BADCHANNEL
value|0xf4
end_define

begin_define
define|#
directive|define
name|QM_MCR_RESULT_PENDING
value|0xf8
end_define

begin_define
define|#
directive|define
name|QM_MCR_RESULT_ERR_BADCOMMAND
value|0xff
end_define

begin_define
define|#
directive|define
name|QM_MCR_NP_STATE_FE
value|0x10
end_define

begin_define
define|#
directive|define
name|QM_MCR_NP_STATE_R
value|0x08
end_define

begin_define
define|#
directive|define
name|QM_MCR_NP_STATE_MASK
value|0x07
end_define

begin_comment
comment|/* Reads FQD::STATE; */
end_comment

begin_define
define|#
directive|define
name|QM_MCR_NP_STATE_OOS
value|0x00
end_define

begin_define
define|#
directive|define
name|QM_MCR_NP_STATE_RETIRED
value|0x01
end_define

begin_define
define|#
directive|define
name|QM_MCR_NP_STATE_TEN_SCHED
value|0x02
end_define

begin_define
define|#
directive|define
name|QM_MCR_NP_STATE_TRU_SCHED
value|0x03
end_define

begin_define
define|#
directive|define
name|QM_MCR_NP_STATE_PARKED
value|0x04
end_define

begin_define
define|#
directive|define
name|QM_MCR_NP_STATE_ACTIVE
value|0x05
end_define

begin_define
define|#
directive|define
name|QM_MCR_NP_PTR_MASK
value|0x07ff
end_define

begin_comment
comment|/* for RA[12]& OD[123] */
end_comment

begin_define
define|#
directive|define
name|QM_MCR_NP_RA1_NRA
parameter_list|(
name|v
parameter_list|)
value|(((v)>> 14)& 0x3)
end_define

begin_comment
comment|/* FQD::NRA */
end_comment

begin_define
define|#
directive|define
name|QM_MCR_NP_RA2_IT
parameter_list|(
name|v
parameter_list|)
value|(((v)>> 14)& 0x1)
end_define

begin_comment
comment|/* FQD::IT */
end_comment

begin_define
define|#
directive|define
name|QM_MCR_NP_OD1_NOD
parameter_list|(
name|v
parameter_list|)
value|(((v)>> 14)& 0x3)
end_define

begin_comment
comment|/* FQD::NOD */
end_comment

begin_define
define|#
directive|define
name|QM_MCR_NP_OD3_NPC
parameter_list|(
name|v
parameter_list|)
value|(((v)>> 14)& 0x3)
end_define

begin_comment
comment|/* FQD::NPC */
end_comment

begin_define
define|#
directive|define
name|QM_MCR_FQS_ORLPRESENT
value|0x02
end_define

begin_comment
comment|/* ORL fragments to come */
end_comment

begin_define
define|#
directive|define
name|QM_MCR_FQS_NOTEMPTY
value|0x01
end_define

begin_comment
comment|/* FQ has enqueued frames */
end_comment

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

begin_comment
comment|/* This extracts the state for congestion group 'n' from a query response.  * Eg.  *   uint8_t cgr = [...];  *   struct qm_mc_result *res = [...];  *   printf("congestion group %d congestion state: %d\n", cgr,  *       QM_MCR_QUERYCONGESTION(&res->querycongestion.state, cgr));  */
end_comment

begin_define
define|#
directive|define
name|__CGR_WORD
parameter_list|(
name|num
parameter_list|)
value|(num>> 5)
end_define

begin_define
define|#
directive|define
name|__CGR_SHIFT
parameter_list|(
name|num
parameter_list|)
value|(num& 0x1f)
end_define

begin_function
specifier|static
name|__inline__
name|int
name|QM_MCR_QUERYCONGESTION
parameter_list|(
name|struct
name|__qm_mcr_querycongestion
modifier|*
name|p
parameter_list|,
name|uint8_t
name|cgr
parameter_list|)
block|{
return|return
call|(
name|int
call|)
argument_list|(
name|p
operator|->
name|__state
index|[
name|__CGR_WORD
argument_list|(
name|cgr
argument_list|)
index|]
operator|&
operator|(
literal|0x80000000
operator|>>
name|__CGR_SHIFT
argument_list|(
name|cgr
argument_list|)
operator|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*********************/
end_comment

begin_comment
comment|/* Utility interface */
end_comment

begin_comment
comment|/*********************/
end_comment

begin_comment
comment|/* Represents an allocator over a range of FQIDs. NB, accesses are not locked,  * spinlock them yourself if needed. */
end_comment

begin_struct_decl
struct_decl|struct
name|qman_fqid_pool
struct_decl|;
end_struct_decl

begin_comment
comment|/* Create/destroy a FQID pool, num must be a multiple of 32. NB, _destroy()  * always succeeds, but returns non-zero if there were "leaked" FQID  * allocations. */
end_comment

begin_function_decl
name|struct
name|qman_fqid_pool
modifier|*
name|qman_fqid_pool_create
parameter_list|(
name|uint32_t
name|fqid_start
parameter_list|,
name|uint32_t
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|qman_fqid_pool_destroy
parameter_list|(
name|struct
name|qman_fqid_pool
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Alloc/free a FQID from the range. _alloc() returns zero for success. */
end_comment

begin_function_decl
name|int
name|qman_fqid_pool_alloc
parameter_list|(
name|struct
name|qman_fqid_pool
modifier|*
name|pool
parameter_list|,
name|uint32_t
modifier|*
name|fqid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|qman_fqid_pool_free
parameter_list|(
name|struct
name|qman_fqid_pool
modifier|*
name|pool
parameter_list|,
name|uint32_t
name|fqid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|qman_fqid_pool_used
parameter_list|(
name|struct
name|qman_fqid_pool
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*******************************************************************/
end_comment

begin_comment
comment|/* Managed (aka "shared" or "mux/demux") portal, high-level i/face */
end_comment

begin_comment
comment|/*******************************************************************/
end_comment

begin_comment
comment|/* Congestion Groups */
end_comment

begin_comment
comment|/* ----------------- */
end_comment

begin_comment
comment|/* This wrapper represents a bit-array for the state of the 256 Qman congestion  * groups. Is also used as a *mask* for congestion groups, eg. so we ignore  * those that don't concern us. We harness the structure and accessor details  * already used in the management command to query congestion groups. */
end_comment

begin_struct
struct|struct
name|qman_cgrs
block|{
name|struct
name|__qm_mcr_querycongestion
name|q
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|__inline__
name|void
name|QMAN_CGRS_INIT
parameter_list|(
name|struct
name|qman_cgrs
modifier|*
name|c
parameter_list|)
block|{
name|memset
argument_list|(
name|c
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|c
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|QMAN_CGRS_GET
parameter_list|(
name|struct
name|qman_cgrs
modifier|*
name|c
parameter_list|,
name|int
name|num
parameter_list|)
block|{
return|return
name|QM_MCR_QUERYCONGESTION
argument_list|(
operator|&
name|c
operator|->
name|q
argument_list|,
operator|(
name|uint8_t
operator|)
name|num
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|QMAN_CGRS_SET
parameter_list|(
name|struct
name|qman_cgrs
modifier|*
name|c
parameter_list|,
name|int
name|num
parameter_list|)
block|{
name|c
operator|->
name|q
operator|.
name|__state
index|[
name|__CGR_WORD
argument_list|(
name|num
argument_list|)
index|]
operator||=
operator|(
literal|0x80000000
operator|>>
name|__CGR_SHIFT
argument_list|(
name|num
argument_list|)
operator|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|QMAN_CGRS_UNSET
parameter_list|(
name|struct
name|qman_cgrs
modifier|*
name|c
parameter_list|,
name|int
name|num
parameter_list|)
block|{
name|c
operator|->
name|q
operator|.
name|__state
index|[
name|__CGR_WORD
argument_list|(
name|num
argument_list|)
index|]
operator|&=
operator|~
operator|(
literal|0x80000000
operator|>>
name|__CGR_SHIFT
argument_list|(
name|num
argument_list|)
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Portal and Frame Queues */
end_comment

begin_comment
comment|/* ----------------------- */
end_comment

begin_comment
comment|/* This object type represents Qman frame queue descriptors (FQD), and is  * stored within a cacheline passed to qman_new_fq(). */
end_comment

begin_struct_decl
struct_decl|struct
name|qman_fq
struct_decl|;
end_struct_decl

begin_comment
comment|/* This enum, and the callback type that returns it, are used when handling  * dequeued frames via DQRR. Note that for "null" callbacks registered with the  * portal object (for handling dequeues that do not demux because contextB is  * NULL), the return value *MUST* be qman_cb_dqrr_consume. */
end_comment

begin_enum
enum|enum
name|qman_cb_dqrr_result
block|{
comment|/* DQRR entry can be consumed */
name|qman_cb_dqrr_consume
block|,
comment|/* DQRR entry cannot be consumed now, pause until next poll request */
name|qman_cb_dqrr_pause
block|,
comment|/* Like _consume, but requests parking - FQ must be held-active */
name|qman_cb_dqrr_park
block|,
comment|/* Does not consume, for DCA mode only. This allows out-of-order      * consumes by explicit calls to qman_dca() and/or the use of implicit      * DCA via EQCR entries. */
name|qman_cb_dqrr_defer
block|}
enum|;
end_enum

begin_comment
comment|/*typedef enum qman_cb_dqrr_result (*qman_cb_dqrr)(t_Handle                   h_Arg,                                                  t_Handle                   h_QmPortal,                                                  struct qman_fq             *fq,                                                  const struct qm_dqrr_entry *dqrr);*/
end_comment

begin_typedef
typedef|typedef
name|t_QmReceivedFrameCallback
modifier|*
name|qman_cb_dqrr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|t_QmReceivedFrameCallback
modifier|*
name|qman_cb_fqs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|t_QmRejectedFrameCallback
modifier|*
name|qman_cb_ern
typedef|;
end_typedef

begin_comment
comment|/* This callback type is used when handling ERNs, FQRNs and FQRLs via MR. They  * are always consumed after the callback returns. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|qman_cb_mr
function_decl|)
parameter_list|(
name|t_Handle
name|h_Arg
parameter_list|,
name|t_Handle
name|h_QmPortal
parameter_list|,
name|struct
name|qman_fq
modifier|*
name|fq
parameter_list|,
specifier|const
name|struct
name|qm_mr_entry
modifier|*
name|msg
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|qman_fq_cb
block|{
name|qman_cb_dqrr
name|dqrr
decl_stmt|;
comment|/* for dequeued frames */
name|qman_cb_ern
name|ern
decl_stmt|;
comment|/* for s/w ERNs */
name|qman_cb_mr
name|dc_ern
decl_stmt|;
comment|/* for diverted h/w ERNs */
name|qman_cb_mr
name|fqs
decl_stmt|;
comment|/* frame-queue state changes*/
block|}
struct|;
end_struct

begin_enum
enum|enum
name|qman_fq_state
block|{
name|qman_fq_state_oos
block|,
name|qman_fq_state_waiting_parked
block|,
name|qman_fq_state_parked
block|,
name|qman_fq_state_sched
block|,
name|qman_fq_state_retired
block|}
enum|;
end_enum

begin_comment
comment|/* Flags to qman_create_portal() */
end_comment

begin_define
define|#
directive|define
name|QMAN_PORTAL_FLAG_IRQ
value|0x00000001
end_define

begin_comment
comment|/* use interrupt handler */
end_comment

begin_define
define|#
directive|define
name|QMAN_PORTAL_FLAG_IRQ_FAST
value|0x00000002
end_define

begin_comment
comment|/* ... for fast-path too! */
end_comment

begin_define
define|#
directive|define
name|QMAN_PORTAL_FLAG_IRQ_SLOW
value|0x00000003
end_define

begin_comment
comment|/* ... for slow-path too! */
end_comment

begin_define
define|#
directive|define
name|QMAN_PORTAL_FLAG_DCA
value|0x00000004
end_define

begin_comment
comment|/* use DCA */
end_comment

begin_define
define|#
directive|define
name|QMAN_PORTAL_FLAG_LOCKED
value|0x00000008
end_define

begin_comment
comment|/* multi-core locking */
end_comment

begin_define
define|#
directive|define
name|QMAN_PORTAL_FLAG_NOTAFFINE
value|0x00000010
end_define

begin_comment
comment|/* not cpu-default portal */
end_comment

begin_define
define|#
directive|define
name|QMAN_PORTAL_FLAG_RSTASH
value|0x00000020
end_define

begin_comment
comment|/* enable DQRR entry stashing */
end_comment

begin_define
define|#
directive|define
name|QMAN_PORTAL_FLAG_DSTASH
value|0x00000040
end_define

begin_comment
comment|/* enable data stashing */
end_comment

begin_define
define|#
directive|define
name|QMAN_PORTAL_FLAG_RECOVER
value|0x00000080
end_define

begin_comment
comment|/* recovery mode */
end_comment

begin_define
define|#
directive|define
name|QMAN_PORTAL_FLAG_WAIT
value|0x00000100
end_define

begin_comment
comment|/* for recovery; can wait */
end_comment

begin_define
define|#
directive|define
name|QMAN_PORTAL_FLAG_WAIT_INT
value|0x00000200
end_define

begin_comment
comment|/* for wait; interruptible */
end_comment

begin_define
define|#
directive|define
name|QMAN_PORTAL_FLAG_CACHE
value|0x00000400
end_define

begin_comment
comment|/* use cachable area for EQCR/DQRR */
end_comment

begin_comment
comment|/* Flags to qman_create_fq() */
end_comment

begin_define
define|#
directive|define
name|QMAN_FQ_FLAG_NO_ENQUEUE
value|0x00000001
end_define

begin_comment
comment|/* can't enqueue */
end_comment

begin_define
define|#
directive|define
name|QMAN_FQ_FLAG_NO_MODIFY
value|0x00000002
end_define

begin_comment
comment|/* can only enqueue */
end_comment

begin_define
define|#
directive|define
name|QMAN_FQ_FLAG_TO_DCPORTAL
value|0x00000004
end_define

begin_comment
comment|/* consumed by CAAM/PME/Fman */
end_comment

begin_define
define|#
directive|define
name|QMAN_FQ_FLAG_LOCKED
value|0x00000008
end_define

begin_comment
comment|/* multi-core locking */
end_comment

begin_define
define|#
directive|define
name|QMAN_FQ_FLAG_RECOVER
value|0x00000010
end_define

begin_comment
comment|/* recovery mode */
end_comment

begin_define
define|#
directive|define
name|QMAN_FQ_FLAG_DYNAMIC_FQID
value|0x00000020
end_define

begin_comment
comment|/* (de)allocate fqid */
end_comment

begin_comment
comment|/* Flags to qman_destroy_fq() */
end_comment

begin_define
define|#
directive|define
name|QMAN_FQ_DESTROY_PARKED
value|0x00000001
end_define

begin_comment
comment|/* FQ can be parked or OOS */
end_comment

begin_comment
comment|/* Flags from qman_fq_state() */
end_comment

begin_define
define|#
directive|define
name|QMAN_FQ_STATE_CHANGING
value|0x80000000
end_define

begin_comment
comment|/* 'state' is changing */
end_comment

begin_define
define|#
directive|define
name|QMAN_FQ_STATE_NE
value|0x40000000
end_define

begin_comment
comment|/* retired FQ isn't empty */
end_comment

begin_define
define|#
directive|define
name|QMAN_FQ_STATE_ORL
value|0x20000000
end_define

begin_comment
comment|/* retired FQ has ORL */
end_comment

begin_define
define|#
directive|define
name|QMAN_FQ_STATE_BLOCKOOS
value|0xe0000000
end_define

begin_comment
comment|/* if any are set, no OOS */
end_comment

begin_define
define|#
directive|define
name|QMAN_FQ_STATE_CGR_EN
value|0x10000000
end_define

begin_comment
comment|/* CGR enabled */
end_comment

begin_define
define|#
directive|define
name|QMAN_FQ_STATE_VDQCR
value|0x08000000
end_define

begin_comment
comment|/* being volatile dequeued */
end_comment

begin_comment
comment|/* Flags to qman_init_fq() */
end_comment

begin_define
define|#
directive|define
name|QMAN_INITFQ_FLAG_SCHED
value|0x00000001
end_define

begin_comment
comment|/* schedule rather than park */
end_comment

begin_define
define|#
directive|define
name|QMAN_INITFQ_FLAG_NULL
value|0x00000002
end_define

begin_comment
comment|/* zero 'contextB', no demux */
end_comment

begin_define
define|#
directive|define
name|QMAN_INITFQ_FLAG_LOCAL
value|0x00000004
end_define

begin_comment
comment|/* set dest portal */
end_comment

begin_comment
comment|/* Flags to qman_volatile_dequeue() */
end_comment

begin_define
define|#
directive|define
name|QMAN_VOLATILE_FLAG_WAIT_INT
value|0x00000001
end_define

begin_comment
comment|/* if we wait, interruptible? */
end_comment

begin_define
define|#
directive|define
name|QMAN_VOLATILE_FLAG_WAIT
value|0x00000002
end_define

begin_comment
comment|/* wait if VDQCR is in use */
end_comment

begin_define
define|#
directive|define
name|QMAN_VOLATILE_FLAG_FINISH
value|0x00000004
end_define

begin_comment
comment|/* wait till VDQCR completes */
end_comment

begin_comment
comment|/* Flags to qman_enqueue(). NB, the strange numbering is to align with  * hardware, bit-wise. */
end_comment

begin_define
define|#
directive|define
name|QMAN_ENQUEUE_FLAG_WAIT
value|0x00010000
end_define

begin_comment
comment|/* wait if EQCR is full */
end_comment

begin_define
define|#
directive|define
name|QMAN_ENQUEUE_FLAG_WAIT_INT
value|0x00020000
end_define

begin_comment
comment|/* if wait, interruptible? */
end_comment

begin_define
define|#
directive|define
name|QMAN_ENQUEUE_FLAG_WAIT_SYNC
value|0x00040000
end_define

begin_comment
comment|/* if wait, until consumed? */
end_comment

begin_define
define|#
directive|define
name|QMAN_ENQUEUE_FLAG_WATCH_CGR
value|0x00080000
end_define

begin_comment
comment|/* watch congestion state */
end_comment

begin_define
define|#
directive|define
name|QMAN_ENQUEUE_FLAG_INTERRUPT
value|0x00000004
end_define

begin_comment
comment|/* on command consumption */
end_comment

begin_define
define|#
directive|define
name|QMAN_ENQUEUE_FLAG_DCA
value|0x00008000
end_define

begin_comment
comment|/* perform enqueue-DCA */
end_comment

begin_define
define|#
directive|define
name|QMAN_ENQUEUE_FLAG_DCA_PARK
value|0x00004000
end_define

begin_comment
comment|/* If DCA, requests park */
end_comment

begin_define
define|#
directive|define
name|QMAN_ENQUEUE_FLAG_DCA_PTR
parameter_list|(
name|p
parameter_list|)
comment|/* If DCA, p is DQRR entry */
define|\
value|(((uint32_t)(p)<< 2)& 0x00000f00)
end_define

begin_define
define|#
directive|define
name|QMAN_ENQUEUE_FLAG_C_GREEN
value|0x00000000
end_define

begin_comment
comment|/* choose one C_*** flag */
end_comment

begin_define
define|#
directive|define
name|QMAN_ENQUEUE_FLAG_C_YELLOW
value|0x00000008
end_define

begin_define
define|#
directive|define
name|QMAN_ENQUEUE_FLAG_C_RED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|QMAN_ENQUEUE_FLAG_C_OVERRIDE
value|0x00000018
end_define

begin_comment
comment|/* For the ORP-specific qman_enqueue_orp() variant, this flag indicates "Not  * Last In Sequence", ie. a non-terminating fragment. */
end_comment

begin_define
define|#
directive|define
name|QMAN_ENQUEUE_FLAG_NLIS
value|0x01000000
end_define

begin_comment
comment|/* - this flag performs no enqueue but fills in an ORP sequence number that  *   would otherwise block it (eg. if a frame has been dropped). */
end_comment

begin_define
define|#
directive|define
name|QMAN_ENQUEUE_FLAG_HOLE
value|0x02000000
end_define

begin_comment
comment|/* - this flag performs no enqueue but advances NESN to the given sequence  *   number. */
end_comment

begin_define
define|#
directive|define
name|QMAN_ENQUEUE_FLAG_NESN
value|0x04000000
end_define

begin_comment
comment|/* FQ management */
end_comment

begin_comment
comment|/* ------------- */
end_comment

begin_comment
comment|/**  * qman_free_fq - Deallocates a FQ  * @fq: the frame queue object to release  * @flags: bit-mask of QMAN_FQ_FREE_*** options  *  * The memory for this frame queue object ('mem' provided in qman_new_fq()) is  * not deallocated but the caller regains ownership, to do with as desired. The  * FQ must be in the 'out-of-service' state unless the QMAN_FQ_FREE_PARKED flag  * is specified, in which case it may also be in the 'parked' state.  */
end_comment

begin_function_decl
name|void
name|qman_free_fq
parameter_list|(
name|struct
name|qman_fq
modifier|*
name|fq
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * qman_fq_fqid - Queries the frame queue ID of a FQ object  * @fq: the frame queue object to query  */
end_comment

begin_function_decl
name|uint32_t
name|qman_fq_fqid
parameter_list|(
name|struct
name|qman_fq
modifier|*
name|fq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * qman_fq_state - Queries the state of a FQ object  * @fq: the frame queue object to query  * @state: pointer to state enum to return the FQ scheduling state  * @flags: pointer to state flags to receive QMAN_FQ_STATE_*** bitmask  *  * Queries the state of the FQ object, without performing any h/w commands.  * This captures the state, as seen by the driver, at the time the function  * executes.  */
end_comment

begin_function_decl
name|void
name|qman_fq_state
parameter_list|(
name|struct
name|qman_fq
modifier|*
name|fq
parameter_list|,
name|enum
name|qman_fq_state
modifier|*
name|state
parameter_list|,
name|uint32_t
modifier|*
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FSL_QMAN_H */
end_comment

end_unit

