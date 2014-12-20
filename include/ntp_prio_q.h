begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ntp_prio_q.h  *  * This file contains the structures and function prototypes for the  * priority queue implementation used by the discrete event simulator.  *  * Written By:	Sachin Kamboj  *		University of Delaware  *		Newark, DE 19711  * Copyright (c) 2006  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_PRIO_Q_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_PRIO_Q_H
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* size_t */
end_comment

begin_comment
comment|/* Structures for storing a priority queue   * ---------------------------------------  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|node
block|{
union|union
block|{
name|struct
name|node
modifier|*
name|next
decl_stmt|;
name|double
name|d
decl_stmt|;
block|}
name|nodeu
union|;
block|}
name|node
typedef|;
end_typedef

begin_define
define|#
directive|define
name|node_next
value|nodeu.next
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|q_order_func
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Queue
block|{
name|q_order_func
name|get_order
decl_stmt|;
name|node
modifier|*
name|front
decl_stmt|;
name|int
name|no_of_elements
decl_stmt|;
block|}
name|queue
typedef|;
end_typedef

begin_comment
comment|/* FUNCTION PROTOTYPES  * -------------------  */
end_comment

begin_comment
comment|/* Define a function to create a FIFO queue */
end_comment

begin_define
define|#
directive|define
name|create_queue
parameter_list|()
value|create_priority_queue(&get_fifo_order)
end_define

begin_function_decl
name|void
name|destroy_queue
parameter_list|(
name|queue
modifier|*
name|my_queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_node
parameter_list|(
name|void
modifier|*
name|my_node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|next_node
parameter_list|(
name|void
modifier|*
name|my_node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|empty
parameter_list|(
name|queue
modifier|*
name|my_queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|queue_head
parameter_list|(
name|queue
modifier|*
name|my_queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|queue
modifier|*
name|enqueue
parameter_list|(
name|queue
modifier|*
name|my_queue
parameter_list|,
name|void
modifier|*
name|my_node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|append_queue
parameter_list|(
name|queue
modifier|*
name|q1
parameter_list|,
name|queue
modifier|*
name|q2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|dequeue
parameter_list|(
name|queue
modifier|*
name|my_queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_no_of_elements
parameter_list|(
name|queue
modifier|*
name|my_queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_fifo_order
parameter_list|(
specifier|const
name|void
modifier|*
name|el1
parameter_list|,
specifier|const
name|void
modifier|*
name|el2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Preserve original callsite __FILE__ and __LINE__ for these   * malloc-like funcs when using MS C runtime debug heap.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_CRTDBG_MAP_ALLOC
end_ifdef

begin_define
define|#
directive|define
name|create_priority_queue
parameter_list|(
name|order
parameter_list|)
value|debug_create_priority_queue(order, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|get_node
parameter_list|(
name|size
parameter_list|)
value|debug_get_node(size, __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|create_priority_queue
parameter_list|(
name|order
parameter_list|)
value|debug_create_priority_queue(order)
end_define

begin_define
define|#
directive|define
name|get_node
parameter_list|(
name|size
parameter_list|)
value|debug_get_node(size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|queue
modifier|*
name|debug_create_priority_queue
parameter_list|(
name|q_order_func
name|get_order
ifdef|#
directive|ifdef
name|_CRTDBG_MAP_ALLOC
parameter_list|,
specifier|const
name|char
modifier|*
name|sourcefile
parameter_list|,
name|int
name|line_num
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|debug_get_node
parameter_list|(
name|size_t
name|size
ifdef|#
directive|ifdef
name|_CRTDBG_MAP_ALLOC
parameter_list|,
specifier|const
name|char
modifier|*
name|sourcefile
parameter_list|,
name|int
name|line_num
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_PRIO_Q_H */
end_comment

end_unit

