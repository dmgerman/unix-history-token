begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 by the University of Southern California  * All rights reserved.  *  * Permission to use, copy, modify, and distribute this software and its  * documentation in source and binary forms for non-commercial purposes  * and without fee is hereby granted, provided that the above copyright  * notice appear in all copies and that both the copyright notice and  * this permission notice appear in supporting documentation. and that  * any documentation, advertising materials, and other materials related  * to such distribution and use acknowledge that the software was  * developed by the University of Southern California, Information  * Sciences Institute.  The name of the University may not be used to  * endorse or promote products derived from this software without  * specific prior written permission.  *  * THE UNIVERSITY OF SOUTHERN CALIFORNIA makes no representations about  * the suitability of this software for any purpose.  THIS SOFTWARE IS  * PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * Other copyrights might apply to parts of this software and are so  * noted when applicable.  */
end_comment

begin_comment
comment|/* RSRR things that are only needed by mrouted. */
end_comment

begin_comment
comment|/* Cache of Route Query messages, distinguished by source,  * destination, and client addresses.  Cache is flushed by RSRR client  * -- it sends notification when an unwanted Route Reply is received.  * Since this only happens during route changes, it is more likely  * that the cache will be flushed when the kernel table entry is  * deleted.  */
end_comment

begin_struct
struct|struct
name|rsrr_cache
block|{
name|struct
name|rsrr_rq
name|route_query
decl_stmt|;
comment|/* Cached Route Query */
name|struct
name|sockaddr_un
name|client_addr
decl_stmt|;
comment|/* Client address */
name|int
name|client_length
decl_stmt|;
comment|/* Length of client */
name|struct
name|rsrr_cache
modifier|*
name|next
decl_stmt|;
comment|/* next cache item */
block|}
struct|;
end_struct

end_unit

