begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	unpcb.h	6.1	83/07/29	*/
end_comment

begin_comment
comment|/*  * Protocol control block for an active  * instance of a UNIX internal protocol.  *  * A socket may be associated with an inode in the  * file system.  If so, the unp_inode pointer holds  * a reference count to this inode, which should be irele'd  * when the socket goes away.  *  * A socket may be connected to another socket, in which  * case the control block of the socket to which it is connected  * is given by unp_conn.  *  * A socket may be referenced by a number of sockets (e.g. several  * sockets may be connected to a datagram socket.)  These sockets  * are in a linked list starting with unp_refs, linked through  * unp_nextref and null-terminated.  Note that a socket may be referenced  * by a number of other sockets and may also reference a socket (not  * necessarily one which is referencing it).  This generates  * the need for unp_refs and unp_nextref to be separate fields.  */
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
name|inode
modifier|*
name|unp_inode
decl_stmt|;
comment|/* if associated with file */
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
name|unp_remaddr
decl_stmt|;
comment|/* address of connected socket */
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

