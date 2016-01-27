begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  *  * userspace compatibility code for dummynet schedulers  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DN_TEST_H
end_ifndef

begin_define
define|#
directive|define
name|_DN_TEST_H
end_define

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
include|#
directive|include
file|<inttypes.h>
include|#
directive|include
file|<stdio.h>
include|#
directive|include
file|<stdlib.h>
include|#
directive|include
file|<strings.h>
comment|/* bzero, ffs, ... */
include|#
directive|include
file|<string.h>
comment|/* strcmp */
include|#
directive|include
file|<errno.h>
include|#
directive|include
file|<sys/queue.h>
include|#
directive|include
file|<sys/time.h>
specifier|extern
name|int
name|debug
decl_stmt|;
define|#
directive|define
name|ND
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {} while (0)
define|#
directive|define
name|D1
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {} while (0)
define|#
directive|define
name|D
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|fprintf(stderr, "%-10s %4d %-8s " fmt "\n",      \         __FILE__, __LINE__, __FUNCTION__, ## args)
define|#
directive|define
name|DX
parameter_list|(
name|lev
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {              \         if (debug> lev) D(fmt, ## args); } while (0)
ifndef|#
directive|ifndef
name|offsetof
define|#
directive|define
name|offsetof
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|)
value|(int)(intptr_t)((&((t *)0L)->m))
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
comment|// XXX osx
typedef|typedef
name|unsigned
name|int
name|u_int
typedef|;
endif|#
directive|endif
comment|/* osx */
include|#
directive|include
file|<mylist.h>
comment|/* prevent include of other system headers */
define|#
directive|define
name|_NETINET_IP_VAR_H_
comment|/* ip_fw_args */
define|#
directive|define
name|_IPFW2_H
define|#
directive|define
name|_SYS_MBUF_H_
enum|enum
block|{
name|DN_QUEUE
block|, }
enum|;
enum|enum
block|{
name|DN_SCHED_FIFO
block|,
name|DN_SCHED_WF2QP
block|, }
enum|;
comment|/* from ip_dummynet.h, fields used in ip_dn_private.h */
struct|struct
name|dn_id
block|{
name|uint16_t
name|len
decl_stmt|;
comment|/* total len inc. this header */
name|uint8_t
name|type
decl_stmt|;
name|uint8_t
name|subtype
decl_stmt|;
comment|//	uint32_t	id;	/* generic id */
block|}
struct|;
comment|/* (from ip_dummynet.h)  * A flowset, which is a template for flows. Contains parameters  * from the command line: id, target scheduler, queue sizes, plr,  * flow masks, buckets for the flow hash, and possibly scheduler-  * specific parameters (weight, quantum and so on).  */
struct|struct
name|dn_fs
block|{
comment|/* generic scheduler parameters. Leave them at -1 if unset.          * Now we use 0: weight, 1: lmax, 2: priority          */
name|int
name|par
index|[
literal|4
index|]
decl_stmt|;
comment|/* flowset parameters */
comment|/* simulation entries. 	 * 'index' is not strictly necessary 	 * y is used for the inverse mapping , 	 */
name|int
name|index
decl_stmt|;
name|int
name|y
decl_stmt|;
comment|/* inverse mapping */
name|int
name|base_y
decl_stmt|;
comment|/* inverse mapping */
name|int
name|next_y
decl_stmt|;
comment|/* inverse mapping */
name|int
name|n_flows
decl_stmt|;
name|int
name|first_flow
decl_stmt|;
name|int
name|next_flow
decl_stmt|;
comment|/* first_flow + n_flows */
comment|/* 	 * when generating, let 'cur' go from 0 to n_flows-1, 	 * then point to flow first_flow + cur 	 */
name|int
name|cur
decl_stmt|;
block|}
struct|;
comment|/* (ip_dummynet.h)  * scheduler template, indicating nam, number, mask and buckets  */
struct|struct
name|dn_sch
block|{ }
struct|;
comment|/* (from ip_dummynet.h)  * dn_flow collects flow_id and stats for queues and scheduler  * instances, and is used to pass these info to userland.  * oid.type/oid.subtype describe the object, oid.id is number  * of the parent object.  */
struct|struct
name|dn_flow
block|{
name|struct
name|dn_id
name|oid
decl_stmt|;
name|uint64_t
name|tot_pkts
decl_stmt|;
name|uint64_t
name|tot_bytes
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
comment|/* Queue length, in packets */
name|uint32_t
name|len_bytes
decl_stmt|;
comment|/* Queue length, in bytes */
name|uint32_t
name|drops
decl_stmt|;
comment|//uint32_t flow_id;
comment|/* the following fields are used by the traffic generator. 	 */
name|struct
name|list_head
name|h
decl_stmt|;
comment|/* used by the generator */
comment|/* bytes served by the flow since the last backlog time */
name|uint64_t
name|bytes
decl_stmt|;
comment|/* bytes served by the system at the last backlog time  */
name|uint64_t
name|sch_bytes
decl_stmt|;
block|}
struct|;
comment|/* the link */
struct|struct
name|dn_link
block|{ }
struct|;
struct|struct
name|ip_fw_args
block|{ }
struct|;
struct|struct
name|mbuf
block|{
struct|struct
block|{
name|int
name|len
decl_stmt|;
block|}
name|m_pkthdr
struct|;
name|struct
name|mbuf
modifier|*
name|m_nextpkt
decl_stmt|;
name|uint32_t
name|flow_id
decl_stmt|;
comment|/* for testing, index of a flow */
comment|//int flowset_id;	/* for testing, index of a flowset */
comment|//void *cfg;	/* config args */
block|}
struct|;
define|#
directive|define
name|MALLOC_DECLARE
parameter_list|(
name|x
parameter_list|)
value|extern volatile int __dummy__ ## x
define|#
directive|define
name|KASSERT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|do { if (!(x)) printf y ; exit(0); } while (0)
struct|struct
name|ipfw_flow_id
block|{ }
struct|;
typedef|typedef
name|void
modifier|*
name|module_t
typedef|;
struct|struct
name|_md_t
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|module_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|p
decl_stmt|;
block|}
struct|;
typedef|typedef
name|struct
name|_md_t
name|moduledata_t
typedef|;
define|#
directive|define
name|DECLARE_MODULE
parameter_list|(
name|name
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
define|\
value|moduledata_t *_g_##name =& b
define|#
directive|define
name|MODULE_DEPEND
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
include|#
directive|include
file|<dn_heap.h>
include|#
directive|include
file|<ip_dn_private.h>
include|#
directive|include
file|<dn_sched.h>
ifndef|#
directive|ifndef
name|__FreeBSD__
name|int
name|fls
parameter_list|(
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
specifier|static
specifier|inline
name|void
name|mq_append
parameter_list|(
name|struct
name|mq
modifier|*
name|q
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
if|if
condition|(
name|q
operator|->
name|head
operator|==
name|NULL
condition|)
name|q
operator|->
name|head
operator|=
name|m
expr_stmt|;
else|else
name|q
operator|->
name|tail
operator|->
name|m_nextpkt
operator|=
name|m
expr_stmt|;
name|q
operator|->
name|tail
operator|=
name|m
expr_stmt|;
name|m
operator|->
name|m_nextpkt
operator|=
name|NULL
expr_stmt|;
block|}
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
comment|/* _DN_TEST_H */
end_comment

end_unit

