begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)ufsmount.h	7.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Mount structure.  * One allocated on every mount.  * Used to find the super block.  */
end_comment

begin_struct
struct|struct
name|ufsmount
block|{
name|struct
name|mount
modifier|*
name|um_mountp
decl_stmt|;
comment|/* vfs structure for this filesystem */
name|dev_t
name|um_dev
decl_stmt|;
comment|/* device mounted */
name|struct
name|vnode
modifier|*
name|um_devvp
decl_stmt|;
comment|/* vnode for block device mounted */
name|struct
name|fs
modifier|*
name|um_fs
decl_stmt|;
comment|/* pointer to superblock */
name|struct
name|inode
modifier|*
name|um_qinod
decl_stmt|;
comment|/* QUOTA: pointer to quota file */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Convert mount ptr to ufsmount ptr.  */
end_comment

begin_define
define|#
directive|define
name|VFSTOUFS
parameter_list|(
name|mp
parameter_list|)
value|((struct ufsmount *)((mp)->m_data))
end_define

begin_comment
comment|/*  * mount table  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ufsmount
name|mounttab
index|[
name|NMOUNT
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

