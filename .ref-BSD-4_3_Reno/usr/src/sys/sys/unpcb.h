begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)unpcb.h	7.6 (Berkeley) 6/28/90  */
end_comment

begin_comment
comment|/*  * Protocol control block for an active  * instance of a UNIX internal protocol.  *  * A socket may be associated with an vnode in the  * file system.  If so, the unp_vnode pointer holds  * a reference count to this vnode, which should be irele'd  * when the socket goes away.  *  * A socket may be connected to another socket, in which  * case the control block of the socket to which it is connected  * is given by unp_conn.  *  * A socket may be referenced by a number of sockets (e.g. several  * sockets may be connected to a datagram socket.)  These sockets  * are in a linked list starting with unp_refs, linked through  * unp_nextref and null-terminated.  Note that a socket may be referenced  * by a number of other sockets and may also reference a socket (not  * necessarily one which is referencing it).  This generates  * the need for unp_refs and unp_nextref to be separate fields.  *  * Stream sockets keep copies of receive sockbuf sb_cc and sb_mbcnt  * so that changes in the sockbuf may be computed to modify  * back pressure on the sender accordingly.  */
end_comment

begin_struct
struct|struct
name|unpcb
block|{
name|struct
name|socket
modifier|*
name|unp_socket
decl_stmt|;
comment|/* pointer back to socket */
name|struct
name|vnode
modifier|*
name|unp_vnode
decl_stmt|;
comment|/* if associated with file */
name|ino_t
name|unp_ino
decl_stmt|;
comment|/* fake inode number */
name|struct
name|unpcb
modifier|*
name|unp_conn
decl_stmt|;
comment|/* control block of connected socket */
name|struct
name|unpcb
modifier|*
name|unp_refs
decl_stmt|;
comment|/* referencing socket linked list */
name|struct
name|unpcb
modifier|*
name|unp_nextref
decl_stmt|;
comment|/* link in unp_refs list */
name|struct
name|mbuf
modifier|*
name|unp_addr
decl_stmt|;
comment|/* bound address of socket */
name|int
name|unp_cc
decl_stmt|;
comment|/* copy of rcv.sb_cc */
name|int
name|unp_mbcnt
decl_stmt|;
comment|/* copy of rcv.sb_mbcnt */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sotounpcb
parameter_list|(
name|so
parameter_list|)
value|((struct unpcb *)((so)->so_pcb))
end_define

end_unit

