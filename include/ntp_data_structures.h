begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ntp_data_structures.h  *  * This file contains the structures and function prototypes for the data   * structures used by the ntp configuration code and the discrete event   * simulator.  *  * Written By: Sachin Kamboj  *             University of Delaware  *             Newark, DE 19711  * Copyright (c) 2006  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NTP_DATA_STRUCTURES_H__
end_ifndef

begin_define
define|#
directive|define
name|__NTP_DATA_STRUCTURES_H__
end_define

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
struct|struct
name|Queue
block|{
name|int
function_decl|(
modifier|*
name|get_order
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
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

begin_function_decl
name|queue
modifier|*
name|create_priority_queue
parameter_list|(
name|int
function_decl|(
modifier|*
name|get_order
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

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
modifier|*
name|get_node
parameter_list|(
name|size_t
name|size
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
name|int
name|get_fifo_order
parameter_list|(
name|void
modifier|*
name|el1
parameter_list|,
name|void
modifier|*
name|el2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|queue
modifier|*
name|create_queue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

