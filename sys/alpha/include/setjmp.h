begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: setjmp.h,v 1.1 1998/01/10 23:00:06 jb Exp $ */
end_comment

begin_comment
comment|/* From: NetBSD: setjmp.h,v 1.2 1997/04/06 08:47:41 cgd Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * machine/setjmp.h: machine dependent setjmp-related information.  */
end_comment

begin_define
define|#
directive|define
name|_JBLEN
value|81
end_define

begin_comment
comment|/* size, in longs, of a jmp_buf */
end_comment

begin_comment
comment|/*  * jmp_buf and sigjmp_buf are encapsulated in different structs to force  * compile-time diagnostics for mismatches.  The structs are the same  * internally to avoid some run-time errors for mismatches.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_SOURCE
end_ifndef

begin_typedef
typedef|typedef
struct|struct
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

begin_comment
comment|/* not ANSI */
end_comment

begin_typedef
typedef|typedef
struct|struct
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

end_unit

