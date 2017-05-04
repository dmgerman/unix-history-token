begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * bluetooth.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001-2002 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_bluetooth.h,v 1.4 2003/04/26 22:32:34 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_BLUETOOTH_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_BLUETOOTH_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * Version of the stack  */
end_comment

begin_define
define|#
directive|define
name|NG_BLUETOOTH_VERSION
value|1
end_define

begin_comment
comment|/*  * Declare the base of the Bluetooth sysctl hierarchy,   * but only if this file cares about sysctl's  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_bluetooth
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_bluetooth_hci
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_bluetooth_l2cap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_bluetooth_rfcomm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_bluetooth_sco
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSCTL_DECL */
end_comment

begin_comment
comment|/*  * Mbuf qeueue and useful mbufq macros. We do not use ifqueue because we  * do not need mutex and other locking stuff  */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ng_bt_mbufq
block|{
name|struct
name|mbuf
modifier|*
name|head
decl_stmt|;
comment|/* first item in the queue */
name|struct
name|mbuf
modifier|*
name|tail
decl_stmt|;
comment|/* last item in the queue */
name|u_int32_t
name|len
decl_stmt|;
comment|/* number of items in the queue */
name|u_int32_t
name|maxlen
decl_stmt|;
comment|/* maximal number of items in the queue */
name|u_int32_t
name|drops
decl_stmt|;
comment|/* number if dropped items */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ng_bt_mbufq
name|ng_bt_mbufq_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ng_bt_mbufq
modifier|*
name|ng_bt_mbufq_p
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_BT_MBUFQ_INIT
parameter_list|(
name|q
parameter_list|,
name|_maxlen
parameter_list|)
define|\
value|do {						\ 		(q)->head = NULL;			\ 		(q)->tail = NULL;			\ 		(q)->len = 0;				\ 		(q)->maxlen = (_maxlen);		\ 		(q)->drops = 0;				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_BT_MBUFQ_DESTROY
parameter_list|(
name|q
parameter_list|)
define|\
value|do {						\ 		NG_BT_MBUFQ_DRAIN((q));			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_BT_MBUFQ_FIRST
parameter_list|(
name|q
parameter_list|)
value|(q)->head
end_define

begin_define
define|#
directive|define
name|NG_BT_MBUFQ_LEN
parameter_list|(
name|q
parameter_list|)
value|(q)->len
end_define

begin_define
define|#
directive|define
name|NG_BT_MBUFQ_FULL
parameter_list|(
name|q
parameter_list|)
value|((q)->len>= (q)->maxlen)
end_define

begin_define
define|#
directive|define
name|NG_BT_MBUFQ_DROP
parameter_list|(
name|q
parameter_list|)
value|(q)->drops ++
end_define

begin_define
define|#
directive|define
name|NG_BT_MBUFQ_ENQUEUE
parameter_list|(
name|q
parameter_list|,
name|i
parameter_list|)
define|\
value|do {						\ 		(i)->m_nextpkt = NULL;			\ 							\ 		if ((q)->tail == NULL)			\ 			(q)->head = (i);		\ 		else					\ 			(q)->tail->m_nextpkt = (i);	\ 							\ 		(q)->tail = (i);			\ 		(q)->len ++;				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_BT_MBUFQ_DEQUEUE
parameter_list|(
name|q
parameter_list|,
name|i
parameter_list|)
define|\
value|do {						\ 		(i) = (q)->head;			\ 		if ((i) != NULL) {			\ 			(q)->head = (q)->head->m_nextpkt; \ 			if ((q)->head == NULL)		\ 				(q)->tail = NULL;	\ 							\ 			(q)->len --;			\ 			(i)->m_nextpkt = NULL;		\ 		} 					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_BT_MBUFQ_PREPEND
parameter_list|(
name|q
parameter_list|,
name|i
parameter_list|)
define|\
value|do {						\ 		(i)->m_nextpkt = (q)->head;		\ 		if ((q)->tail == NULL)			\ 			(q)->tail = (i);		\ 							\ 		(q)->head = (i);			\ 		(q)->len ++;				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_BT_MBUFQ_DRAIN
parameter_list|(
name|q
parameter_list|)
define|\
value|do { 						\         	struct mbuf	*m = NULL;		\ 							\ 		for (;;) { 				\ 			NG_BT_MBUFQ_DEQUEUE((q), m);	\ 			if (m == NULL) 			\ 				break; 			\ 							\ 			NG_FREE_M(m);	 		\ 		} 					\ 	} while (0)
end_define

begin_comment
comment|/*   * Netgraph item queue and useful itemq macros  */
end_comment

begin_struct_decl
struct_decl|struct
name|ng_item
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ng_bt_itemq
block|{
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|ng_item
argument_list|)
name|queue
expr_stmt|;
comment|/* actually items queue */
name|u_int32_t
name|len
decl_stmt|;
comment|/* number of items in the queue */
name|u_int32_t
name|maxlen
decl_stmt|;
comment|/* maximal number of items in the queue */
name|u_int32_t
name|drops
decl_stmt|;
comment|/* number if dropped items */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ng_bt_itemq
name|ng_bt_itemq_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ng_bt_itemq
modifier|*
name|ng_bt_itemq_p
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NG_BT_ITEMQ_INIT
parameter_list|(
name|q
parameter_list|,
name|_maxlen
parameter_list|)
define|\
value|do {						\ 		STAILQ_INIT(&(q)->queue);		\ 		(q)->len = 0;				\ 		(q)->maxlen = (_maxlen);		\ 		(q)->drops = 0;				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_BT_ITEMQ_DESTROY
parameter_list|(
name|q
parameter_list|)
define|\
value|do {						\ 		NG_BT_ITEMQ_DRAIN((q));			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_BT_ITEMQ_FIRST
parameter_list|(
name|q
parameter_list|)
value|STAILQ_FIRST(&(q)->queue)
end_define

begin_define
define|#
directive|define
name|NG_BT_ITEMQ_LEN
parameter_list|(
name|q
parameter_list|)
value|NG_BT_MBUFQ_LEN((q))
end_define

begin_define
define|#
directive|define
name|NG_BT_ITEMQ_FULL
parameter_list|(
name|q
parameter_list|)
value|NG_BT_MBUFQ_FULL((q))
end_define

begin_define
define|#
directive|define
name|NG_BT_ITEMQ_DROP
parameter_list|(
name|q
parameter_list|)
value|NG_BT_MBUFQ_DROP((q))
end_define

begin_define
define|#
directive|define
name|NG_BT_ITEMQ_ENQUEUE
parameter_list|(
name|q
parameter_list|,
name|i
parameter_list|)
define|\
value|do {						\ 		STAILQ_INSERT_TAIL(&(q)->queue, (i), el_next);	\ 		(q)->len ++;				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_BT_ITEMQ_DEQUEUE
parameter_list|(
name|q
parameter_list|,
name|i
parameter_list|)
define|\
value|do {						\ 		(i) = STAILQ_FIRST(&(q)->queue);	\ 		if ((i) != NULL) {			\ 			STAILQ_REMOVE_HEAD(&(q)->queue, el_next);	\ 			(q)->len --;			\ 		} 					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_BT_ITEMQ_PREPEND
parameter_list|(
name|q
parameter_list|,
name|i
parameter_list|)
define|\
value|do {						\ 		STAILQ_INSERT_HEAD(&(q)->queue, (i), el_next);	\ 		(q)->len ++;				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_BT_ITEMQ_DRAIN
parameter_list|(
name|q
parameter_list|)
define|\
value|do { 						\         	struct ng_item	*i = NULL;		\ 							\ 		for (;;) { 				\ 			NG_BT_ITEMQ_DEQUEUE((q), i);	\ 			if (i == NULL) 			\ 				break; 			\ 							\ 			NG_FREE_ITEM(i); 		\ 		} 					\ 	} while (0)
end_define

begin_comment
comment|/*  * Get Bluetooth stack sysctl globals  */
end_comment

begin_function_decl
name|u_int32_t
name|bluetooth_hci_command_timeout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|bluetooth_hci_connect_timeout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|bluetooth_hci_max_neighbor_age
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|bluetooth_l2cap_rtx_timeout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|bluetooth_l2cap_ertx_timeout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|bluetooth_sco_rtx_timeout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BDADDR_BREDR
value|0
end_define

begin_define
define|#
directive|define
name|BDADDR_LE_PUBLIC
value|1
end_define

begin_define
define|#
directive|define
name|BDADDR_LE_RANDOM
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_BLUETOOTH_H_ */
end_comment

end_unit

