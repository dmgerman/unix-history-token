begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_dag.h,v 1.3 1999/02/05 00:06:07 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: William V. Courtright II, Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/****************************************************************************  *                                                                          *  * dag.h -- header file for DAG-related data structures                     *  *                                                                          *  ****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_DAG_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_DAG_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_threadstuff.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_alloclist.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_stripelocks.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_layout.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_dagflags.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_acctrace.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_memchunk.h>
end_include

begin_define
define|#
directive|define
name|RF_THREAD_CONTEXT
value|0
end_define

begin_comment
comment|/* we were invoked from thread context */
end_comment

begin_define
define|#
directive|define
name|RF_INTR_CONTEXT
value|1
end_define

begin_comment
comment|/* we were invoked from interrupt context */
end_comment

begin_define
define|#
directive|define
name|RF_MAX_ANTECEDENTS
value|20
end_define

begin_comment
comment|/* max num of antecedents a node may posses */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD_version
operator|>
literal|500005
end_if

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_struct
struct|struct
name|RF_PropHeader_s
block|{
comment|/* structure for propagation of results */
name|int
name|resultNum
decl_stmt|;
comment|/* bind result # resultNum */
name|int
name|paramNum
decl_stmt|;
comment|/* to parameter # paramNum */
name|RF_PropHeader_t
modifier|*
name|next
decl_stmt|;
comment|/* linked list for multiple results/params */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
name|RF_NodeStatus_e
block|{
name|rf_bwd1
block|,
comment|/* node is ready for undo logging (backward 				 * error recovery only) */
name|rf_bwd2
block|,
comment|/* node has completed undo logging (backward 				 * error recovery only) */
name|rf_wait
block|,
comment|/* node is waiting to be executed */
name|rf_fired
block|,
comment|/* node is currently executing its do function */
name|rf_good
block|,
comment|/* node successfully completed execution of 				 * its do function */
name|rf_bad
block|,
comment|/* node failed to successfully execute its do 				 * function */
name|rf_skipped
block|,
comment|/* not used anymore, used to imply a node was 				 * not executed */
name|rf_recover
block|,
comment|/* node is currently executing its undo 				 * function */
name|rf_panic
block|,
comment|/* node failed to successfully execute its 				 * undo function */
name|rf_undone
comment|/* node successfully executed its undo 				 * function */
block|}
name|RF_NodeStatus_t
typedef|;
end_typedef

begin_comment
comment|/*  * These were used to control skipping a node.  * Now, these are only used as comments.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|RF_AntecedentType_e
block|{
name|rf_trueData
block|,
name|rf_antiData
block|,
name|rf_outputData
block|,
name|rf_control
block|}
name|RF_AntecedentType_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RF_DAG_PTRCACHESIZE
value|40
end_define

begin_define
define|#
directive|define
name|RF_DAG_PARAMCACHESIZE
value|12
end_define

begin_typedef
typedef|typedef
name|RF_uint8
name|RF_DagNodeFlags_t
typedef|;
end_typedef

begin_struct
struct|struct
name|RF_DagNode_s
block|{
name|RF_NodeStatus_t
name|status
decl_stmt|;
comment|/* current status of this node */
name|int
function_decl|(
modifier|*
name|doFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
parameter_list|)
function_decl|;
comment|/* normal function */
name|int
function_decl|(
modifier|*
name|undoFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
parameter_list|)
function_decl|;
comment|/* func to remove effect of 						 * doFunc */
name|int
function_decl|(
modifier|*
name|wakeFunc
function_decl|)
parameter_list|(
name|RF_DagNode_t
modifier|*
parameter_list|,
name|int
name|status
parameter_list|)
function_decl|;
comment|/* func called when the 								 * node completes an I/O */
name|int
name|numParams
decl_stmt|;
comment|/* number of parameters required by *funcPtr */
name|int
name|numResults
decl_stmt|;
comment|/* number of results produced by *funcPtr */
name|int
name|numAntecedents
decl_stmt|;
comment|/* number of antecedents */
name|int
name|numAntDone
decl_stmt|;
comment|/* number of antecedents which have finished */
name|int
name|numSuccedents
decl_stmt|;
comment|/* number of succedents */
name|int
name|numSuccFired
decl_stmt|;
comment|/* incremented when a succedent is fired 				 * during forward execution */
name|int
name|numSuccDone
decl_stmt|;
comment|/* incremented when a succedent finishes 				 * during rollBackward */
name|int
name|commitNode
decl_stmt|;
comment|/* boolean flag - if true, this is a commit 				 * node */
name|RF_DagNode_t
modifier|*
modifier|*
name|succedents
decl_stmt|;
comment|/* succedents, array size 					 * numSuccedents */
name|RF_DagNode_t
modifier|*
modifier|*
name|antecedents
decl_stmt|;
comment|/* antecedents, array size 					 * numAntecedents */
name|RF_AntecedentType_t
name|antType
index|[
name|RF_MAX_ANTECEDENTS
index|]
decl_stmt|;
comment|/* type of each 								 * antecedent */
name|void
modifier|*
modifier|*
name|results
decl_stmt|;
comment|/* array of results produced by *funcPtr */
name|RF_DagParam_t
modifier|*
name|params
decl_stmt|;
comment|/* array of parameters required by *funcPtr */
name|RF_PropHeader_t
modifier|*
modifier|*
name|propList
decl_stmt|;
comment|/* propagation list, size 					 * numSuccedents */
name|RF_DagHeader_t
modifier|*
name|dagHdr
decl_stmt|;
comment|/* ptr to head of dag containing this node */
name|void
modifier|*
name|dagFuncData
decl_stmt|;
comment|/* dag execution func uses this for whatever 				 * it wants */
name|RF_DagNode_t
modifier|*
name|next
decl_stmt|;
name|int
name|nodeNum
decl_stmt|;
comment|/* used by PrintDAG for debug only */
name|int
name|visited
decl_stmt|;
comment|/* used to avoid re-visiting nodes on DAG 				 * walks */
comment|/* ANY CODE THAT USES THIS FIELD MUST MAINTAIN THE PROPERTY THAT AFTER 	 * IT FINISHES, ALL VISITED FLAGS IN THE DAG ARE IDENTICAL */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* debug only */
name|RF_DagNodeFlags_t
name|flags
decl_stmt|;
comment|/* see below */
name|RF_DagNode_t
modifier|*
name|dag_ptrs
index|[
name|RF_DAG_PTRCACHESIZE
index|]
decl_stmt|;
comment|/* cache for performance */
name|RF_DagParam_t
name|dag_params
index|[
name|RF_DAG_PARAMCACHESIZE
index|]
decl_stmt|;
comment|/* cache for performance */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bit values for flags field of RF_DagNode_t  */
end_comment

begin_define
define|#
directive|define
name|RF_DAGNODE_FLAG_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|RF_DAGNODE_FLAG_YIELD
value|0x01
end_define

begin_comment
comment|/* in the kernel, yield the processor 					 * before firing this node */
end_comment

begin_comment
comment|/* enable - DAG ready for normal execution, no errors encountered  * rollForward - DAG encountered an error after commit point, rolling forward  * rollBackward - DAG encountered an error prior to commit point, rolling backward  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|RF_DagStatus_e
block|{
name|rf_enable
block|,
name|rf_rollForward
block|,
name|rf_rollBackward
block|}
name|RF_DagStatus_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RF_MAX_HDR_SUCC
value|1
end_define

begin_define
define|#
directive|define
name|RF_MAXCHUNKS
value|10
end_define

begin_struct
struct|struct
name|RF_DagHeader_s
block|{
name|RF_DagStatus_t
name|status
decl_stmt|;
comment|/* status of this DAG */
name|int
name|numSuccedents
decl_stmt|;
comment|/* DAG may be a tree, i.e. may have> 1 root */
name|int
name|numCommitNodes
decl_stmt|;
comment|/* number of commit nodes in graph */
name|int
name|numCommits
decl_stmt|;
comment|/* number of commit nodes which have been 				 * fired  */
name|RF_DagNode_t
modifier|*
name|succedents
index|[
name|RF_MAX_HDR_SUCC
index|]
decl_stmt|;
comment|/* array of succedents, 							 * size numSuccedents */
name|RF_DagHeader_t
modifier|*
name|next
decl_stmt|;
comment|/* ptr to allow a list of dags */
name|RF_AllocListElem_t
modifier|*
name|allocList
decl_stmt|;
comment|/* ptr to list of ptrs to be freed 					 * prior to freeing DAG */
name|RF_AccessStripeMapHeader_t
modifier|*
name|asmList
decl_stmt|;
comment|/* list of access stripe maps 						 * to be freed */
name|int
name|nodeNum
decl_stmt|;
comment|/* used by PrintDAG for debug only */
name|int
name|numNodesCompleted
decl_stmt|;
name|RF_AccTraceEntry_t
modifier|*
name|tracerec
decl_stmt|;
comment|/* perf mon only */
name|void
function_decl|(
modifier|*
name|cbFunc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* function to call when the dag 					 * completes */
name|void
modifier|*
name|cbArg
decl_stmt|;
comment|/* argument for cbFunc */
name|char
modifier|*
name|creator
decl_stmt|;
comment|/* name of function used to create this dag */
name|RF_Raid_t
modifier|*
name|raidPtr
decl_stmt|;
comment|/* the descriptor for the RAID device this DAG 				 * is for */
name|void
modifier|*
name|bp
decl_stmt|;
comment|/* the bp for this I/O passed down from the 				 * file system. ignored outside kernel */
name|RF_ChunkDesc_t
modifier|*
name|memChunk
index|[
name|RF_MAXCHUNKS
index|]
decl_stmt|;
comment|/* experimental- Chunks of 						 * memory to be retained upon 						 * DAG free for re-use */
name|int
name|chunkIndex
decl_stmt|;
comment|/* the idea is to avoid calls to alloc and 				 * free */
name|RF_ChunkDesc_t
modifier|*
modifier|*
name|xtraMemChunk
decl_stmt|;
comment|/* escape hatch which allows 					 * SelectAlgorithm to merge memChunks 					 * from several dags */
name|int
name|xtraChunkIndex
decl_stmt|;
comment|/* number of ptrs to valid chunks */
name|int
name|xtraChunkCnt
decl_stmt|;
comment|/* number of ptrs to chunks allocated */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RF_DagList_s
block|{
comment|/* common info for a list of dags which will be fired sequentially */
name|int
name|numDags
decl_stmt|;
comment|/* number of dags in the list */
name|int
name|numDagsFired
decl_stmt|;
comment|/* number of dags in list which have initiated 				 * execution */
name|int
name|numDagsDone
decl_stmt|;
comment|/* number of dags in list which have completed 				 * execution */
name|RF_DagHeader_t
modifier|*
name|dags
decl_stmt|;
comment|/* list of dags */
name|RF_RaidAccessDesc_t
modifier|*
name|desc
decl_stmt|;
comment|/* ptr to descriptor for this access */
name|RF_AccTraceEntry_t
name|tracerec
decl_stmt|;
comment|/* perf mon info for dags (not user 					 * info) */
block|}
struct|;
end_struct

begin_comment
comment|/* resets a node so that it can be fired again */
end_comment

begin_define
define|#
directive|define
name|RF_ResetNode
parameter_list|(
name|_n_
parameter_list|)
value|{ \   (_n_)->status = rf_wait;   \   (_n_)->numAntDone = 0;     \   (_n_)->numSuccFired = 0;   \   (_n_)->numSuccDone = 0;    \   (_n_)->next = NULL;        \ }
end_define

begin_define
define|#
directive|define
name|RF_ResetDagHeader
parameter_list|(
name|_h_
parameter_list|)
value|{ \   (_h_)->numNodesCompleted = 0;  \   (_h_)->numCommits = 0;         \   (_h_)->status = rf_enable;     \ }
end_define

begin_comment
comment|/* convience macro for declaring a create dag function */
end_comment

begin_define
define|#
directive|define
name|RF_CREATE_DAG_FUNC_DECL
parameter_list|(
name|_name_
parameter_list|)
define|\
value|void _name_ ( \ 	RF_Raid_t             *raidPtr, \ 	RF_AccessStripeMap_t  *asmap, \ 	RF_DagHeader_t        *dag_h, \ 	void                  *bp, \ 	RF_RaidAccessFlags_t   flags, \ 	RF_AllocListElem_t    *allocList)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_DAG_H_ */
end_comment

end_unit

