begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California  * Copyright (c) 1990, 1992 Jan-Simon Pendry  * All rights reserved.  *  * This code is derived from software donated to Berkeley by  * Jan-Simon Pendry.  *  * %sccs.include.redist.c%  *  *	@(#)fdesc.h	1.1 (Berkeley) %G%  *  * $Id: fdesc.h,v 1.5 1992/05/30 10:05:34 jsp Exp jsp $  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct
struct|struct
name|fdescmount
block|{
name|struct
name|vnode
modifier|*
name|f_root
decl_stmt|;
comment|/* Root node */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fdescnode
block|{
name|unsigned
name|f_fd
decl_stmt|;
comment|/* Fd to be dup'ed */
comment|/*int		f_isroot;*/
comment|/* Is this the root */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VFSTOFDESC
parameter_list|(
name|mp
parameter_list|)
value|((struct fdescmount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|VTOFDESC
parameter_list|(
name|vp
parameter_list|)
value|((struct fdescnode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|MAXNAMLEN
value|255
end_define

begin_struct
struct|struct
name|readdir
block|{
name|u_long
name|d_ino
decl_stmt|;
comment|/* inode number of entry */
name|u_short
name|d_reclen
decl_stmt|;
comment|/* length of this record */
name|u_short
name|d_namlen
decl_stmt|;
comment|/* length of string in d_name */
name|char
name|d_name
index|[
name|MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name with length<= MAXNAMLEN */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
modifier|*
name|fdesc_vnodeop_p
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|fdesc_vfsops
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

