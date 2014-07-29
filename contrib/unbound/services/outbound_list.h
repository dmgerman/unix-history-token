begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * services/outbound_list.h - keep list of outbound serviced queries.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions to help a module keep track of the  * queries it has outstanding to authoritative servers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SERVICES_OUTBOUND_LIST_H
end_ifndef

begin_define
define|#
directive|define
name|SERVICES_OUTBOUND_LIST_H
end_define

begin_struct_decl
struct_decl|struct
name|outbound_entry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|serviced_query
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_qstate
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * The outbound list. This structure is part of the module specific query  * state.  */
end_comment

begin_struct
struct|struct
name|outbound_list
block|{
comment|/** The linked list of outbound query entries. */
name|struct
name|outbound_entry
modifier|*
name|first
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Outbound list entry. A serviced query sent by a module processing the  * query from the qstate. Double linked list to aid removal.  */
end_comment

begin_struct
struct|struct
name|outbound_entry
block|{
comment|/** next in list */
name|struct
name|outbound_entry
modifier|*
name|next
decl_stmt|;
comment|/** prev in list */
name|struct
name|outbound_entry
modifier|*
name|prev
decl_stmt|;
comment|/** The query that was sent out */
name|struct
name|serviced_query
modifier|*
name|qsent
decl_stmt|;
comment|/** the module query state that sent it */
name|struct
name|module_qstate
modifier|*
name|qstate
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Init the user allocated outbound list structure  * @param list: the list structure.  */
end_comment

begin_function_decl
name|void
name|outbound_list_init
parameter_list|(
name|struct
name|outbound_list
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Clear the user owner outbound list structure.  * Deletes serviced queries.  * @param list: the list structure. It is cleared, but the list struct itself  * 	is callers responsability to delete.  */
end_comment

begin_function_decl
name|void
name|outbound_list_clear
parameter_list|(
name|struct
name|outbound_list
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Insert new entry into the list. Caller must allocate the entry with malloc.  * qstate and qsent are set by caller.  * @param list: the list to add to.  * @param e: entry to add, it is only half initialised at call start, fully  *	initialised at call end.  */
end_comment

begin_function_decl
name|void
name|outbound_list_insert
parameter_list|(
name|struct
name|outbound_list
modifier|*
name|list
parameter_list|,
name|struct
name|outbound_entry
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove an entry from the list, and deletes it.   * Deletes serviced query in the entry.  * @param list: the list to remove from.  * @param e: the entry to remove.  */
end_comment

begin_function_decl
name|void
name|outbound_list_remove
parameter_list|(
name|struct
name|outbound_list
modifier|*
name|list
parameter_list|,
name|struct
name|outbound_entry
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SERVICES_OUTBOUND_LIST_H */
end_comment

end_unit

