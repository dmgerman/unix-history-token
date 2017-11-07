begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ptrace.h,v 1.2 2001/02/23 21:23:52 reinoud Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PTRACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PTRACE_H_
end_define

begin_define
define|#
directive|define
name|__HAVE_PTRACE_MACHDEP
end_define

begin_comment
comment|/*  * Must match mcontext_vfp_t.  Note that mcontext_vfp_t does not  * include explicit padding.  */
end_comment

begin_struct
struct|struct
name|vfpreg
block|{
name|__uint64_t
name|vfp_reg
index|[
literal|32
index|]
decl_stmt|;
name|__uint32_t
name|vfp_scr
decl_stmt|;
name|__uint32_t
name|vfp_pad0
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PT_GETVFPREGS
value|(PT_FIRSTMACH + 0)
end_define

begin_define
define|#
directive|define
name|PT_SETVFPREGS
value|(PT_FIRSTMACH + 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PTRACE_H */
end_comment

end_unit

