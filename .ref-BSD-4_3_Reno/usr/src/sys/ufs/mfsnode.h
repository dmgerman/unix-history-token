begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)mfsnode.h	7.2 (Berkeley) 6/28/90  */
end_comment

begin_comment
comment|/*  * This structure defines the control data for the memory  * based file system.  */
end_comment

begin_struct
struct|struct
name|mfsnode
block|{
name|struct
name|vnode
modifier|*
name|mfs_vnode
decl_stmt|;
comment|/* vnode associated with this mfsnode */
name|caddr_t
name|mfs_baseoff
decl_stmt|;
comment|/* base of file system in memory */
name|long
name|mfs_size
decl_stmt|;
comment|/* size of memory file system */
name|pid_t
name|mfs_pid
decl_stmt|;
comment|/* supporting process pid */
name|struct
name|buf
modifier|*
name|mfs_buflist
decl_stmt|;
comment|/* list of I/O requests */
name|long
name|mfs_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Convert between mfsnode pointers and vnode pointers  */
end_comment

begin_define
define|#
directive|define
name|VTOMFS
parameter_list|(
name|vp
parameter_list|)
value|((struct mfsnode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|MFSTOV
parameter_list|(
name|mfsp
parameter_list|)
value|((mfsp)->mfs_vnode)
end_define

end_unit

