begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  * All rights reserved.  *  * This code is derived from software donated to Berkeley by  * Jan-Simon Pendry.  *  * %sccs.include.redist.c%  *  *	@(#)fdesc.h	8.4 (Berkeley) %G%  *  * $Id: fdesc.h,v 1.8 1993/04/06 15:28:33 jsp Exp $  */
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

begin_define
define|#
directive|define
name|FD_ROOT
value|2
end_define

begin_define
define|#
directive|define
name|FD_DEVFD
value|3
end_define

begin_define
define|#
directive|define
name|FD_STDIN
value|4
end_define

begin_define
define|#
directive|define
name|FD_STDOUT
value|5
end_define

begin_define
define|#
directive|define
name|FD_STDERR
value|6
end_define

begin_define
define|#
directive|define
name|FD_CTTY
value|7
end_define

begin_define
define|#
directive|define
name|FD_DESC
value|8
end_define

begin_define
define|#
directive|define
name|FD_MAX
value|12
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|Froot
block|,
name|Fdevfd
block|,
name|Fdesc
block|,
name|Flink
block|,
name|Fctty
block|}
name|fdntype
typedef|;
end_typedef

begin_struct
struct|struct
name|fdescnode
block|{
name|struct
name|fdescnode
modifier|*
name|fd_forw
decl_stmt|;
comment|/* Hash chain */
name|struct
name|fdescnode
modifier|*
name|fd_back
decl_stmt|;
name|struct
name|vnode
modifier|*
name|fd_vnode
decl_stmt|;
comment|/* Back ptr to vnode */
name|fdntype
name|fd_type
decl_stmt|;
comment|/* Type of this node */
name|unsigned
name|fd_fd
decl_stmt|;
comment|/* Fd to be dup'ed */
name|char
modifier|*
name|fd_link
decl_stmt|;
comment|/* Link to fd/n */
name|int
name|fd_ix
decl_stmt|;
comment|/* filesystem index */
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

begin_decl_stmt
specifier|extern
name|dev_t
name|devctty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fdesc_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fdesc_root
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
expr|struct
name|vnode
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fdesc_allocvp
name|__P
argument_list|(
operator|(
name|fdntype
operator|,
name|int
operator|,
expr|struct
name|mount
operator|*
operator|,
expr|struct
name|vnode
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

