begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)raw_cb.h	7.6 (Berkeley) 6/28/90  */
end_comment

begin_comment
comment|/*  * Raw protocol interface control block.  Used  * to tie a socket to the generic raw interface.  */
end_comment

begin_struct
struct|struct
name|rawcb
block|{
name|struct
name|rawcb
modifier|*
name|rcb_next
decl_stmt|;
comment|/* doubly linked list */
name|struct
name|rawcb
modifier|*
name|rcb_prev
decl_stmt|;
name|struct
name|socket
modifier|*
name|rcb_socket
decl_stmt|;
comment|/* back pointer to socket */
name|struct
name|sockaddr
modifier|*
name|rcb_faddr
decl_stmt|;
comment|/* destination address */
name|struct
name|sockaddr
modifier|*
name|rcb_laddr
decl_stmt|;
comment|/* socket's address */
name|struct
name|sockproto
name|rcb_proto
decl_stmt|;
comment|/* protocol family, protocol */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sotorawcb
parameter_list|(
name|so
parameter_list|)
value|((struct rawcb *)(so)->so_pcb)
end_define

begin_comment
comment|/*  * Nominal space allocated to a raw socket.  */
end_comment

begin_define
define|#
directive|define
name|RAWSNDQ
value|8192
end_define

begin_define
define|#
directive|define
name|RAWRCVQ
value|8192
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|rawcb
name|rawcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of list */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

