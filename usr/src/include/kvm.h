begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)kvm.h	5.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/kinfo.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * type byte prepending key  */
end_comment

begin_define
define|#
directive|define
name|KVMDB_NLIST
value|1
end_define

begin_define
define|#
directive|define
name|KVMDB_DEVS
value|2
end_define

begin_define
define|#
directive|define
name|KVMDBDIR
value|"/var/run"
end_define

begin_decl_stmt
name|__BEGIN_DECLS
name|struct
name|proc
modifier|*
name|kvm_nextproc
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|eproc
modifier|*
name|kvm_geteproc
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|user
modifier|*
name|kvm_getu
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kvm_getargs
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|proc
operator|*
operator|,
specifier|const
expr|struct
name|user
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kvm_geterr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

end_unit

