begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software developed by the Computer Systems  * Engineering group at Lawrence Berkeley Laboratory under DARPA contract  * BG 91-66 and contributed to Berkeley.  *  * %sccs.include.redist.c%  *  *	@(#)kvm_private.h	8.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|__kvm
block|{
comment|/* 	 * a string to be prepended to error messages 	 * provided for compatibility with sun's interface 	 * if this value is null, errors are saved in errbuf[] 	 */
specifier|const
name|char
modifier|*
name|program
decl_stmt|;
name|char
modifier|*
name|errp
decl_stmt|;
comment|/* XXX this can probably go away */
name|char
name|errbuf
index|[
name|_POSIX2_LINE_MAX
index|]
decl_stmt|;
name|DB
modifier|*
name|db
decl_stmt|;
define|#
directive|define
name|ISALIVE
parameter_list|(
name|kd
parameter_list|)
value|((kd)->vmfd>= 0)
name|int
name|pmfd
decl_stmt|;
comment|/* physical memory file (or crashdump) */
name|int
name|vmfd
decl_stmt|;
comment|/* virtual memory file (-1 if crashdump) */
name|int
name|swfd
decl_stmt|;
comment|/* swap file (e.g., /dev/drum) */
name|int
name|nlfd
decl_stmt|;
comment|/* namelist file (e.g., /vmunix) */
name|struct
name|kinfo_proc
modifier|*
name|procbase
decl_stmt|;
name|char
modifier|*
name|argspc
decl_stmt|;
comment|/* (dynamic) storage for argv strings */
name|int
name|arglen
decl_stmt|;
comment|/* length of the above */
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
comment|/* (dynamic) storage for argv pointers */
name|int
name|argc
decl_stmt|;
comment|/* length of above (not actual # present) */
comment|/* 	 * Kernel virtual address translation state.  This only gets filled 	 * in for dead kernels; otherwise, the running kernel (i.e. kmem) 	 * will do the translations for us.  It could be big, so we 	 * only allocate it if necessary. 	 */
name|struct
name|vmstate
modifier|*
name|vmst
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Functions used internally by kvm, but across kvm modules.  */
end_comment

begin_decl_stmt
name|void
name|_kvm_err
name|__P
argument_list|(
operator|(
name|kvm_t
operator|*
name|kd
operator|,
specifier|const
name|char
operator|*
name|program
operator|,
specifier|const
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_kvm_freeprocs
name|__P
argument_list|(
operator|(
name|kvm_t
operator|*
name|kd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_kvm_freevtop
name|__P
argument_list|(
operator|(
name|kvm_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_kvm_initvtop
name|__P
argument_list|(
operator|(
name|kvm_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_kvm_kvatop
name|__P
argument_list|(
operator|(
name|kvm_t
operator|*
operator|,
name|u_long
operator|,
name|u_long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|_kvm_malloc
name|__P
argument_list|(
operator|(
name|kvm_t
operator|*
name|kd
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|_kvm_realloc
name|__P
argument_list|(
operator|(
name|kvm_t
operator|*
name|kd
operator|,
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_kvm_syserr
name|__P
argument_list|(
operator|(
name|kvm_t
operator|*
name|kd
operator|,
specifier|const
name|char
operator|*
name|program
operator|,
specifier|const
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_kvm_uvatop
name|__P
argument_list|(
operator|(
name|kvm_t
operator|*
operator|,
specifier|const
expr|struct
name|proc
operator|*
operator|,
name|u_long
operator|,
name|u_long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

