begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: altq_hfsc.h,v 1.10 2003/07/10 12:07:48 kjc Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1997-1999 Carnegie Mellon University. All Rights Reserved.  *  * Permission to use, copy, modify, and distribute this software and  * its documentation is hereby granted (including for commercial or  * for-profit use), provided that both the copyright notice and this  * permission notice appear in all copies of the software, derivative  * works, or modified versions, and any portions thereof, and that  * both notices appear in supporting documentation, and that credit  * is given to Carnegie Mellon University in all publications reporting  * on direct or indirect use of this code or its derivatives.  *  * THIS SOFTWARE IS EXPERIMENTAL AND IS KNOWN TO HAVE BUGS, SOME OF  * WHICH MAY HAVE SERIOUS CONSEQUENCES.  CARNEGIE MELLON PROVIDES THIS  * SOFTWARE IN ITS ``AS IS'' CONDITION, AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL CARNEGIE MELLON UNIVERSITY BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * Carnegie Mellon encourages (but does not require) users of this  * software to return any improvements or extensions that they make,  * and to grant Carnegie Mellon the rights to redistribute these  * changes without encumbrance.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALTQ_ALTQ_HFSC_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALTQ_ALTQ_HFSC_H_
end_define

begin_include
include|#
directive|include
file|<altq/altq.h>
end_include

begin_include
include|#
directive|include
file|<altq/altq_classq.h>
end_include

begin_include
include|#
directive|include
file|<altq/altq_red.h>
end_include

begin_include
include|#
directive|include
file|<altq/altq_rio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
struct|struct
name|service_curve
block|{
name|u_int
name|m1
decl_stmt|;
comment|/* slope of the first segment in bits/sec */
name|u_int
name|d
decl_stmt|;
comment|/* the x-projection of the first segment in msec */
name|u_int
name|m2
decl_stmt|;
comment|/* slope of the second segment in bits/sec */
block|}
struct|;
comment|/* special class handles */
define|#
directive|define
name|HFSC_NULLCLASS_HANDLE
value|0
define|#
directive|define
name|HFSC_ROOTCLASS_HANDLE
value|1
define|#
directive|define
name|HFSC_MAX_CLASSES
value|64
comment|/* hfsc class flags */
define|#
directive|define
name|HFCF_RED
value|0x0001
comment|/* use RED */
define|#
directive|define
name|HFCF_ECN
value|0x0002
comment|/* use RED/ECN */
define|#
directive|define
name|HFCF_RIO
value|0x0004
comment|/* use RIO */
define|#
directive|define
name|HFCF_CLEARDSCP
value|0x0010
comment|/* clear diffserv codepoint */
define|#
directive|define
name|HFCF_DEFAULTCLASS
value|0x1000
comment|/* default class */
comment|/* service curve types */
define|#
directive|define
name|HFSC_REALTIMESC
value|1
define|#
directive|define
name|HFSC_LINKSHARINGSC
value|2
define|#
directive|define
name|HFSC_UPPERLIMITSC
value|4
define|#
directive|define
name|HFSC_DEFAULTSC
value|(HFSC_REALTIMESC|HFSC_LINKSHARINGSC)
struct|struct
name|hfsc_classstats
block|{
name|u_int
name|class_id
decl_stmt|;
name|u_int32_t
name|class_handle
decl_stmt|;
name|struct
name|service_curve
name|rsc
decl_stmt|;
name|struct
name|service_curve
name|fsc
decl_stmt|;
name|struct
name|service_curve
name|usc
decl_stmt|;
comment|/* upper limit service curve */
name|u_int64_t
name|total
decl_stmt|;
comment|/* total work in bytes */
name|u_int64_t
name|cumul
decl_stmt|;
comment|/* cumulative work in bytes 					   done by real-time criteria */
name|u_int64_t
name|d
decl_stmt|;
comment|/* deadline */
name|u_int64_t
name|e
decl_stmt|;
comment|/* eligible time */
name|u_int64_t
name|vt
decl_stmt|;
comment|/* virtual time */
name|u_int64_t
name|f
decl_stmt|;
comment|/* fit time for upper-limit */
comment|/* info helpful for debugging */
name|u_int64_t
name|initvt
decl_stmt|;
comment|/* init virtual time */
name|u_int64_t
name|vtoff
decl_stmt|;
comment|/* cl_vt_ipoff */
name|u_int64_t
name|cvtmax
decl_stmt|;
comment|/* cl_maxvt */
name|u_int64_t
name|myf
decl_stmt|;
comment|/* cl_myf */
name|u_int64_t
name|cfmin
decl_stmt|;
comment|/* cl_mincf */
name|u_int64_t
name|cvtmin
decl_stmt|;
comment|/* cl_mincvt */
name|u_int64_t
name|myfadj
decl_stmt|;
comment|/* cl_myfadj */
name|u_int64_t
name|vtadj
decl_stmt|;
comment|/* cl_vtadj */
name|u_int64_t
name|cur_time
decl_stmt|;
name|u_int32_t
name|machclk_freq
decl_stmt|;
name|u_int
name|qlength
decl_stmt|;
name|u_int
name|qlimit
decl_stmt|;
name|struct
name|pktcntr
name|xmit_cnt
decl_stmt|;
name|struct
name|pktcntr
name|drop_cnt
decl_stmt|;
name|u_int
name|period
decl_stmt|;
name|u_int
name|vtperiod
decl_stmt|;
comment|/* vt period sequence no */
name|u_int
name|parentperiod
decl_stmt|;
comment|/* parent's vt period seqno */
name|int
name|nactive
decl_stmt|;
comment|/* number of active children */
comment|/* red and rio related info */
name|int
name|qtype
decl_stmt|;
name|struct
name|redstats
name|red
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
struct|struct
name|hfsc_interface
block|{
name|char
name|hfsc_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* interface name (e.g., fxp0) */
block|}
struct|;
struct|struct
name|hfsc_attach
block|{
name|struct
name|hfsc_interface
name|iface
decl_stmt|;
name|u_int
name|bandwidth
decl_stmt|;
comment|/* link bandwidth in bits/sec */
block|}
struct|;
struct|struct
name|hfsc_add_class
block|{
name|struct
name|hfsc_interface
name|iface
decl_stmt|;
name|u_int32_t
name|parent_handle
decl_stmt|;
name|struct
name|service_curve
name|service_curve
decl_stmt|;
name|int
name|qlimit
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|u_int32_t
name|class_handle
decl_stmt|;
comment|/* return value */
block|}
struct|;
struct|struct
name|hfsc_delete_class
block|{
name|struct
name|hfsc_interface
name|iface
decl_stmt|;
name|u_int32_t
name|class_handle
decl_stmt|;
block|}
struct|;
struct|struct
name|hfsc_modify_class
block|{
name|struct
name|hfsc_interface
name|iface
decl_stmt|;
name|u_int32_t
name|class_handle
decl_stmt|;
name|struct
name|service_curve
name|service_curve
decl_stmt|;
name|int
name|sctype
decl_stmt|;
block|}
struct|;
struct|struct
name|hfsc_add_filter
block|{
name|struct
name|hfsc_interface
name|iface
decl_stmt|;
name|u_int32_t
name|class_handle
decl_stmt|;
name|struct
name|flow_filter
name|filter
decl_stmt|;
name|u_long
name|filter_handle
decl_stmt|;
comment|/* return value */
block|}
struct|;
struct|struct
name|hfsc_delete_filter
block|{
name|struct
name|hfsc_interface
name|iface
decl_stmt|;
name|u_long
name|filter_handle
decl_stmt|;
block|}
struct|;
struct|struct
name|hfsc_class_stats
block|{
name|struct
name|hfsc_interface
name|iface
decl_stmt|;
name|int
name|nskip
decl_stmt|;
comment|/* skip # of classes */
name|int
name|nclasses
decl_stmt|;
comment|/* # of class stats (WR) */
name|u_int64_t
name|cur_time
decl_stmt|;
comment|/* current time */
name|u_int32_t
name|machclk_freq
decl_stmt|;
comment|/* machine clock frequency */
name|u_int
name|hif_classes
decl_stmt|;
comment|/* # of classes in the tree */
name|u_int
name|hif_packets
decl_stmt|;
comment|/* # of packets in the tree */
name|struct
name|hfsc_classstats
modifier|*
name|stats
decl_stmt|;
comment|/* pointer to stats array */
block|}
struct|;
define|#
directive|define
name|HFSC_IF_ATTACH
value|_IOW('Q', 1, struct hfsc_attach)
define|#
directive|define
name|HFSC_IF_DETACH
value|_IOW('Q', 2, struct hfsc_interface)
define|#
directive|define
name|HFSC_ENABLE
value|_IOW('Q', 3, struct hfsc_interface)
define|#
directive|define
name|HFSC_DISABLE
value|_IOW('Q', 4, struct hfsc_interface)
define|#
directive|define
name|HFSC_CLEAR_HIERARCHY
value|_IOW('Q', 5, struct hfsc_interface)
define|#
directive|define
name|HFSC_ADD_CLASS
value|_IOWR('Q', 7, struct hfsc_add_class)
define|#
directive|define
name|HFSC_DEL_CLASS
value|_IOW('Q', 8, struct hfsc_delete_class)
define|#
directive|define
name|HFSC_MOD_CLASS
value|_IOW('Q', 9, struct hfsc_modify_class)
define|#
directive|define
name|HFSC_ADD_FILTER
value|_IOWR('Q', 10, struct hfsc_add_filter)
define|#
directive|define
name|HFSC_DEL_FILTER
value|_IOW('Q', 11, struct hfsc_delete_filter)
define|#
directive|define
name|HFSC_GETSTATS
value|_IOWR('Q', 12, struct hfsc_class_stats)
endif|#
directive|endif
comment|/* ALTQ3_COMPAT */
ifdef|#
directive|ifdef
name|_KERNEL
comment|/*  * kernel internal service curve representation  *	coordinates are given by 64 bit unsigned integers.  *	x-axis: unit is clock count.  for the intel x86 architecture,  *		the raw Pentium TSC (Timestamp Counter) value is used.  *		virtual time is also calculated in this time scale.  *	y-axis: unit is byte.  *  *	the service curve parameters are converted to the internal  *	representation.  *	the slope values are scaled to avoid overflow.  *	the inverse slope values as well as the y-projection of the 1st  *	segment are kept in order to to avoid 64-bit divide operations  *	that are expensive on 32-bit architectures.  *  *  note: Intel Pentium TSC never wraps around in several thousands of years.  *	x-axis doesn't wrap around for 1089 years with 1GHz clock.  *      y-axis doesn't wrap around for 4358 years with 1Gbps bandwidth.  */
comment|/* kernel internal representation of a service curve */
struct|struct
name|internal_sc
block|{
name|u_int64_t
name|sm1
decl_stmt|;
comment|/* scaled slope of the 1st segment */
name|u_int64_t
name|ism1
decl_stmt|;
comment|/* scaled inverse-slope of the 1st segment */
name|u_int64_t
name|dx
decl_stmt|;
comment|/* the x-projection of the 1st segment */
name|u_int64_t
name|dy
decl_stmt|;
comment|/* the y-projection of the 1st segment */
name|u_int64_t
name|sm2
decl_stmt|;
comment|/* scaled slope of the 2nd segment */
name|u_int64_t
name|ism2
decl_stmt|;
comment|/* scaled inverse-slope of the 2nd segment */
block|}
struct|;
comment|/* runtime service curve */
struct|struct
name|runtime_sc
block|{
name|u_int64_t
name|x
decl_stmt|;
comment|/* current starting position on x-axis */
name|u_int64_t
name|y
decl_stmt|;
comment|/* current starting position on x-axis */
name|u_int64_t
name|sm1
decl_stmt|;
comment|/* scaled slope of the 1st segment */
name|u_int64_t
name|ism1
decl_stmt|;
comment|/* scaled inverse-slope of the 1st segment */
name|u_int64_t
name|dx
decl_stmt|;
comment|/* the x-projection of the 1st segment */
name|u_int64_t
name|dy
decl_stmt|;
comment|/* the y-projection of the 1st segment */
name|u_int64_t
name|sm2
decl_stmt|;
comment|/* scaled slope of the 2nd segment */
name|u_int64_t
name|ism2
decl_stmt|;
comment|/* scaled inverse-slope of the 2nd segment */
block|}
struct|;
comment|/* for TAILQ based ellist and actlist implementation */
struct_decl|struct
name|hfsc_class
struct_decl|;
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument|_eligible
argument_list|,
argument|hfsc_class
argument_list|)
name|ellist_t
expr_stmt|;
typedef|typedef
name|TAILQ_ENTRY
argument_list|(
argument|hfsc_class
argument_list|)
name|elentry_t
expr_stmt|;
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument|_active
argument_list|,
argument|hfsc_class
argument_list|)
name|actlist_t
expr_stmt|;
typedef|typedef
name|TAILQ_ENTRY
argument_list|(
argument|hfsc_class
argument_list|)
name|actentry_t
expr_stmt|;
define|#
directive|define
name|ellist_first
parameter_list|(
name|s
parameter_list|)
value|TAILQ_FIRST(s)
define|#
directive|define
name|actlist_first
parameter_list|(
name|s
parameter_list|)
value|TAILQ_FIRST(s)
define|#
directive|define
name|actlist_last
parameter_list|(
name|s
parameter_list|)
value|TAILQ_LAST(s, _active)
struct|struct
name|hfsc_class
block|{
name|u_int
name|cl_id
decl_stmt|;
comment|/* class id (just for debug) */
name|u_int32_t
name|cl_handle
decl_stmt|;
comment|/* class handle */
name|struct
name|hfsc_if
modifier|*
name|cl_hif
decl_stmt|;
comment|/* back pointer to struct hfsc_if */
name|int
name|cl_flags
decl_stmt|;
comment|/* misc flags */
name|struct
name|hfsc_class
modifier|*
name|cl_parent
decl_stmt|;
comment|/* parent class */
name|struct
name|hfsc_class
modifier|*
name|cl_siblings
decl_stmt|;
comment|/* sibling classes */
name|struct
name|hfsc_class
modifier|*
name|cl_children
decl_stmt|;
comment|/* child classes */
name|class_queue_t
modifier|*
name|cl_q
decl_stmt|;
comment|/* class queue structure */
name|struct
name|red
modifier|*
name|cl_red
decl_stmt|;
comment|/* RED state */
name|struct
name|altq_pktattr
modifier|*
name|cl_pktattr
decl_stmt|;
comment|/* saved header used by ECN */
name|u_int64_t
name|cl_total
decl_stmt|;
comment|/* total work in bytes */
name|u_int64_t
name|cl_cumul
decl_stmt|;
comment|/* cumulative work in bytes 					   done by real-time criteria */
name|u_int64_t
name|cl_d
decl_stmt|;
comment|/* deadline */
name|u_int64_t
name|cl_e
decl_stmt|;
comment|/* eligible time */
name|u_int64_t
name|cl_vt
decl_stmt|;
comment|/* virtual time */
name|u_int64_t
name|cl_f
decl_stmt|;
comment|/* time when this class will fit for 					   link-sharing, max(myf, cfmin) */
name|u_int64_t
name|cl_myf
decl_stmt|;
comment|/* my fit-time (as calculated from this 					   class's own upperlimit curve) */
name|u_int64_t
name|cl_myfadj
decl_stmt|;
comment|/* my fit-time adjustment 					   (to cancel history dependence) */
name|u_int64_t
name|cl_cfmin
decl_stmt|;
comment|/* earliest children's fit-time (used 					   with cl_myf to obtain cl_f) */
name|u_int64_t
name|cl_cvtmin
decl_stmt|;
comment|/* minimal virtual time among the 					   children fit for link-sharing 					   (monotonic within a period) */
name|u_int64_t
name|cl_vtadj
decl_stmt|;
comment|/* intra-period cumulative vt 					   adjustment */
name|u_int64_t
name|cl_vtoff
decl_stmt|;
comment|/* inter-period cumulative vt offset */
name|u_int64_t
name|cl_cvtmax
decl_stmt|;
comment|/* max child's vt in the last period */
name|u_int64_t
name|cl_initvt
decl_stmt|;
comment|/* init virtual time (for debugging) */
name|struct
name|internal_sc
modifier|*
name|cl_rsc
decl_stmt|;
comment|/* internal real-time service curve */
name|struct
name|internal_sc
modifier|*
name|cl_fsc
decl_stmt|;
comment|/* internal fair service curve */
name|struct
name|internal_sc
modifier|*
name|cl_usc
decl_stmt|;
comment|/* internal upperlimit service curve */
name|struct
name|runtime_sc
name|cl_deadline
decl_stmt|;
comment|/* deadline curve */
name|struct
name|runtime_sc
name|cl_eligible
decl_stmt|;
comment|/* eligible curve */
name|struct
name|runtime_sc
name|cl_virtual
decl_stmt|;
comment|/* virtual curve */
name|struct
name|runtime_sc
name|cl_ulimit
decl_stmt|;
comment|/* upperlimit curve */
name|u_int
name|cl_vtperiod
decl_stmt|;
comment|/* vt period sequence no */
name|u_int
name|cl_parentperiod
decl_stmt|;
comment|/* parent's vt period seqno */
name|int
name|cl_nactive
decl_stmt|;
comment|/* number of active children */
name|actlist_t
modifier|*
name|cl_actc
decl_stmt|;
comment|/* active children list */
name|actentry_t
name|cl_actlist
decl_stmt|;
comment|/* active children list entry */
name|elentry_t
name|cl_ellist
decl_stmt|;
comment|/* eligible list entry */
struct|struct
block|{
name|struct
name|pktcntr
name|xmit_cnt
decl_stmt|;
name|struct
name|pktcntr
name|drop_cnt
decl_stmt|;
name|u_int
name|period
decl_stmt|;
block|}
name|cl_stats
struct|;
block|}
struct|;
comment|/*  * hfsc interface state  */
struct|struct
name|hfsc_if
block|{
name|struct
name|hfsc_if
modifier|*
name|hif_next
decl_stmt|;
comment|/* interface state list */
name|struct
name|ifaltq
modifier|*
name|hif_ifq
decl_stmt|;
comment|/* backpointer to ifaltq */
name|struct
name|hfsc_class
modifier|*
name|hif_rootclass
decl_stmt|;
comment|/* root class */
name|struct
name|hfsc_class
modifier|*
name|hif_defaultclass
decl_stmt|;
comment|/* default class */
name|struct
name|hfsc_class
modifier|*
name|hif_class_tbl
index|[
name|HFSC_MAX_CLASSES
index|]
decl_stmt|;
name|struct
name|hfsc_class
modifier|*
name|hif_pollcache
decl_stmt|;
comment|/* cache for poll operation */
name|u_int
name|hif_classes
decl_stmt|;
comment|/* # of classes in the tree */
name|u_int
name|hif_packets
decl_stmt|;
comment|/* # of packets in the tree */
name|u_int
name|hif_classid
decl_stmt|;
comment|/* class id sequence number */
name|ellist_t
modifier|*
name|hif_eligible
decl_stmt|;
comment|/* eligible list */
ifdef|#
directive|ifdef
name|ALTQ3_CLFIER_COMPAT
name|struct
name|acc_classifier
name|hif_classifier
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
endif|#
directive|endif
comment|/* _KERNEL */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALTQ_ALTQ_HFSC_H_ */
end_comment

end_unit

