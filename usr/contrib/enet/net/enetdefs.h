begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      enetdefs.h	Stanford	25 April 1983 */
end_comment

begin_comment
comment|/* Notes:  *	- check maxwaiting, etc.  *	- Xdrops in enState may be meaningless  */
end_comment

begin_comment
comment|/*  *  Ethernet definitions NOT needed for user processes  *  **********************************************************************  * HISTORY  * 7 October 1985	Jeff Mogul	Stanford  *	Removed ENMAXOPENS limitation; available minors are now  *	dynamically allocated to interfaces.  *	Certain arrays in the enState structure are now indirected  *	via pointers.  * 17 October 1984	Jeff Mogul	Stanford  *	Added RecvCount filed to enOpenDescriptor struct to store count  *	of packets received on this filter.  *	Also, made some changes to encourage use of "high-priority"  *	devices:  *	- changed ENHIPRIDEV from 12 to 0; allows anyone to use  *		high priority  *	- changed ENHIPRI from 128 to 2; no point in having more than  *		one priority below ENHIPRI, since all would be equivalent.  *  * 2 October 1984	Jeff Mogul	Stanford  *	Added field to enOpenDescriptor struct to store pre-computed  *	address of short word AFTER last valid word in the filter;  *	this saves a few instructions in some very busy code.  *  * 10 November 1983	Jeffrey Mogul	Stanford  *	Minor changes to support EIOCDEVP ioctl,  *	removed references to enUnit[]  *  * 25-Apr-83	Jeffrey Mogul	Stanford  *	Began conversion to 4.2BSD.  This involves removing all  *	references to the actual hardware.  *	Most previous history comments removed.  *	Split off from definitions of interest to users.  *  * 10-Aug-82  Mike Accetta (mja) at Carnegie-Mellon University  *	Added EIOCMBIS and EIOCMBIC definitions, and new ENHOLDSIG mode  *	bit and ENPRIVMODES defintions (V3.05e). [Last change before  *	4.2BSD conversion starts.]  *  * 22-Feb-80  Rick Rashid (rfr) at Carnegie-Mellon University  *	Rewritten for multiple simultaneous opens with filters (V1.05).  *  * 18-Jan-80  Mike Accetta (mja) at Carnegie-Mellon University  *      Created (V1.00).  *  **********************************************************************  */
end_comment

begin_comment
comment|/* tunable constants */
end_comment

begin_define
define|#
directive|define
name|ENHIPRI
value|2
end_define

begin_comment
comment|/* high priority priority */
end_comment

begin_comment
comment|/* 			 * setting ENHIPRI to 2 makes sense because all 			 * priorities below ENHIPRI are equivalent; therefore, 			 * we only need one of them. 			 */
end_comment

begin_define
define|#
directive|define
name|ENMAXPRI
value|255
end_define

begin_comment
comment|/* maximum high priority priority */
end_comment

begin_define
define|#
directive|define
name|ENUNIT
parameter_list|(
name|dev
parameter_list|)
value|(enUnitMap[minor(dev)])
end_define

begin_comment
comment|/* macro */
end_comment

begin_comment
comment|/* to extract ethernet unit number */
end_comment

begin_comment
comment|/* from device number (used as the */
end_comment

begin_comment
comment|/* index into the enState[] table); */
end_comment

begin_define
define|#
directive|define
name|ENINDEX
parameter_list|(
name|dev
parameter_list|)
value|(minor(dev))
end_define

begin_comment
comment|/* macro to extract logical */
end_comment

begin_comment
comment|/* device index from device number */
end_comment

begin_comment
comment|/* (used as the index into the */
end_comment

begin_comment
comment|/* AllDescriptors table for the */
end_comment

begin_comment
comment|/* unit) */
end_comment

begin_define
define|#
directive|define
name|ENMAXWAITING
value|8
end_define

begin_comment
comment|/* maximum number of packets */
end_comment

begin_comment
comment|/* which can be queued at one time */
end_comment

begin_comment
comment|/* for an open enet file (max 256) */
end_comment

begin_define
define|#
directive|define
name|ENDEFWAITING
value|2
end_define

begin_comment
comment|/* default number of packets */
end_comment

begin_comment
comment|/* which can be queued at one */
end_comment

begin_comment
comment|/* time for an open enet file */
end_comment

begin_define
define|#
directive|define
name|ENPACKETS
value|50
end_define

begin_comment
comment|/* number of preallocated packets */
end_comment

begin_comment
comment|/* available for receiving (these 					/* should be allocated dynamically */
end_comment

begin_comment
comment|/* once the system makes */
end_comment

begin_comment
comment|/* this more feasible) */
end_comment

begin_define
define|#
directive|define
name|ENMINSCAVENGE
value|4
end_define

begin_comment
comment|/* minimum number of packets */
end_comment

begin_comment
comment|/* guaranteed to be freed by */
end_comment

begin_comment
comment|/* scavenging */
end_comment

begin_comment
comment|/*  * Privileged mode bits  */
end_comment

begin_define
define|#
directive|define
name|ENKERNEL
value|(0x8000)
end_define

begin_comment
comment|/* flag bit to indicate kernel mode */
end_comment

begin_comment
comment|/*  requests */
end_comment

begin_comment
comment|/*  *  The following definitions are meant to clean up  *  C language syntax a bit.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|false
block|,
name|true
block|}
name|boolean
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TRUE
value|((int)true)
end_define

begin_define
define|#
directive|define
name|FALSE
value|((int)false)
end_define

begin_define
define|#
directive|define
name|endcase
value|break;
end_define

begin_comment
comment|/*  * General purpose structure to define circular queues.  *  Both the queue header and the queue elements have this  *  structure.  */
end_comment

begin_struct
struct|struct
name|Queue
block|{
name|struct
name|Queue
modifier|*
name|F
decl_stmt|;
name|struct
name|Queue
modifier|*
name|B
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_comment
comment|/* Temporary used by queue macros. */
end_comment

begin_decl_stmt
name|struct
name|Queue
modifier|*
name|q_tmp
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|enqueue
parameter_list|(
name|head
parameter_list|,
name|elt
parameter_list|)
define|\
value|{ (elt)->F = (head);(elt)->B = (head)->B;(head)->B = (elt);((elt)->B)->F = (elt); };
end_define

begin_define
define|#
directive|define
name|remqueue
parameter_list|(
name|head
parameter_list|,
name|elt
parameter_list|)
define|\
value|{ ((elt)->B)->F = (elt)->F; ((elt)->F)->B = (elt)->B; };
end_define

begin_define
define|#
directive|define
name|dequeue
parameter_list|(
name|head
parameter_list|)
define|\
value|(((q_tmp = (head)->F) == (head)) ? NULL : \      (((q_tmp->B)->F = q_tmp->F),         \       ((q_tmp->F)->B = q_tmp->B),	  \       (q_tmp)))
end_define

begin_define
define|#
directive|define
name|queueempty
parameter_list|(
name|head
parameter_list|)
define|\
value|((head)->F == (head))
end_define

begin_define
define|#
directive|define
name|initqueue
parameter_list|(
name|head
parameter_list|)
define|\
value|{ (head)->F = (head); (head)->B = (head); };
end_define

begin_endif
endif|#
directive|endif
endif|notdef
end_endif

begin_comment
comment|/*  *  The ethernet packet structure.  *  */
end_comment

begin_struct
struct|struct
name|enPacket
block|{
name|struct
name|Queue
name|enP_Link
decl_stmt|;
comment|/* queue pointers */
name|u_short
modifier|*
name|enP_Data
decl_stmt|;
comment|/* pointer to start of packet */
name|short
name|enP_ByteCount
decl_stmt|;
comment|/* # of bytes in Data */
name|u_short
name|enP_RefCount
decl_stmt|;
comment|/* # of outstanding references to */
comment|/* this packet */
name|struct
name|mbuf
modifier|*
name|enP_mbuf
decl_stmt|;
comment|/* first mbuf of packet */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|enP_F
value|enP_Link.F
end_define

begin_define
define|#
directive|define
name|enP_B
value|enP_Link.B
end_define

begin_comment
comment|/*  *  Ethernet queue header  */
end_comment

begin_struct
struct|struct
name|enQueue
block|{
name|struct
name|Queue
name|enQ_Head
decl_stmt|;
comment|/* queue header and trailer pointers */
name|short
name|enQ_NumQueued
decl_stmt|;
comment|/* number of elements in queue */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|enQ_F
value|enQ_Head.F
end_define

begin_define
define|#
directive|define
name|enQ_B
value|enQ_Head.B
end_define

begin_comment
comment|/*  *  Wait queue header  */
end_comment

begin_struct
struct|struct
name|enWaitQueue
block|{
name|struct
name|enPacket
modifier|*
name|enWQ_Packets
index|[
name|ENMAXWAITING
index|]
decl_stmt|;
comment|/* pointers to queued packets */
name|char
name|enWQ_Head
decl_stmt|;
comment|/* index into Packets (for dequeue) */
name|char
name|enWQ_Tail
decl_stmt|;
comment|/* index into Packets (for enqueue) */
name|u_char
name|enWQ_NumQueued
decl_stmt|;
comment|/* current queue size */
name|u_char
name|enWQ_MaxWaiting
decl_stmt|;
comment|/* threshold for additions */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|enNextWaitQueueIndex
parameter_list|(
name|idx
parameter_list|)
define|\
value|if (++(idx)>= ENMAXWAITING) (idx) = 0
end_define

begin_define
define|#
directive|define
name|enPrevWaitQueueIndex
parameter_list|(
name|idx
parameter_list|)
define|\
value|if (--(idx)< 0) (idx) = (ENMAXWAITING-1)
end_define

begin_comment
comment|/*  *  States of receive side of open enet file.  */
end_comment

begin_enum
enum|enum
name|enStates
block|{
name|ENRECVIDLE
block|,
name|ENRECVTIMING
block|,
name|ENRECVTIMEDOUT
block|}
enum|;
end_enum

begin_struct
struct|struct
name|enOpenDescriptor
block|{
name|struct
name|Queue
name|enOD_Link
decl_stmt|;
comment|/* Linked list of OpenDescriptors */
name|struct
name|enWaitQueue
name|enOD_Waiting
decl_stmt|;
comment|/* fixed Queue of waiting packets */
name|struct
name|proc
modifier|*
name|enOD_SigProc
decl_stmt|;
comment|/* Process to signal (user mode) */
name|short
name|enOD_SigPid
decl_stmt|;
comment|/* Process ID of process to signal */
name|short
name|enOD_SigNumb
decl_stmt|;
comment|/* Signal number for input packet */
comment|/* notification  */
name|long
name|enOD_Timeout
decl_stmt|;
comment|/* Length of time to wait for packet */
name|struct
name|enfilter
name|enOD_OpenFilter
decl_stmt|;
comment|/* Packet filter */
name|enum
name|enStates
name|enOD_RecvState
decl_stmt|;
comment|/* see enStates enumeration (above) */
name|short
name|enOD_Flag
decl_stmt|;
comment|/* option bits */
comment|/* following are for enetselect() */
name|short
name|enOD_SelColl
decl_stmt|;
comment|/* true if selects collide */
name|struct
name|proc
modifier|*
name|enOD_SelProc
decl_stmt|;
comment|/* process that last selected us */
name|unsigned
name|long
name|enOD_RecvCount
decl_stmt|;
comment|/* number of packets received */
comment|/* store precomputed address of end of filter */
name|unsigned
name|short
modifier|*
name|enOD_FiltEnd
decl_stmt|;
comment|/* addr of short AFTER end of filt */
block|}
struct|;
end_struct

begin_comment
comment|/*  *  State descriptor for each enet device  */
end_comment

begin_struct
struct|struct
name|enState
block|{
name|long
name|ens_Rcnt
decl_stmt|;
comment|/* input packets queued since */
comment|/* system startup */
name|long
name|ens_Xcnt
decl_stmt|;
comment|/* output packets sent since */
comment|/* system startup */
name|long
name|ens_Rdrops
decl_stmt|;
comment|/* input packets dropped since */
comment|/* system startup */
name|long
name|ens_Xdrops
decl_stmt|;
comment|/* output packets dropped since */
comment|/* system startup */
name|struct
name|enQueue
comment|/* queue of active open */
name|ens_Desq
decl_stmt|;
comment|/* file descriptors */
name|struct
name|endevp
name|ens_DevParams
decl_stmt|;
comment|/* device parameters, see enet.h */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|enRcnt
value|(enStatep->ens_Rcnt)
end_define

begin_define
define|#
directive|define
name|enXcnt
value|(enStatep->ens_Xcnt)
end_define

begin_define
define|#
directive|define
name|enRdrops
value|(enStatep->ens_Rdrops)
end_define

begin_define
define|#
directive|define
name|enXdrops
value|(enStatep->ens_Xdrops)
end_define

begin_define
define|#
directive|define
name|enDesq
value|(enStatep->ens_Desq)
end_define

begin_define
define|#
directive|define
name|enCurOpens
value|(enStatep->ens_Desq.enQ_NumQueued)
end_define

begin_define
define|#
directive|define
name|enDevParams
value|(enStatep->ens_DevParams)
end_define

end_unit

