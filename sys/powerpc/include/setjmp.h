begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *	$NetBSD: setjmp.h,v 1.3 1998/09/16 23:51:27 thorpej Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SETJMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SETJMP_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|_JBLEN
value|100
end_define

begin_comment
comment|/*  * jmp_buf and sigjmp_buf are encapsulated in different structs to force  * compile-time diagnostics for mismatches.  The structs are the same  * internally to avoid some run-time errors for mismatches.  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
operator|||
name|__POSIX_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

begin_typedef
typedef|typedef
struct|struct
name|_sigjmp_buf
block|{
name|long
name|_sjb
index|[
name|_JBLEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|sigjmp_buf
index|[
literal|1
index|]
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_jmp_buf
block|{
name|long
name|_jb
index|[
name|_JBLEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|jmp_buf
index|[
literal|1
index|]
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SETJMP_H_ */
end_comment

end_unit

