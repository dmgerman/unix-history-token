begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994, 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  *	from: NetBSD: profile.h,v 1.9 1997/04/06 08:47:37 cgd Exp  *	from: FreeBSD: src/sys/alpha/include/profile.h,v 1.4 1999/12/29  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PROFILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PROFILE_H_
end_define

begin_define
define|#
directive|define
name|_MCOUNT_DECL
value|void mcount
end_define

begin_define
define|#
directive|define
name|FUNCTION_ALIGNMENT
value|32
end_define

begin_typedef
typedef|typedef
name|u_long
name|fptrdiff_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|uintfptr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MCOUNT
define|\
value|void \ _mcount() \ { \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|MCOUNT_ENTER
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MCOUNT_DECL
parameter_list|(
name|s
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GUPROF
end_ifdef

begin_struct_decl
struct_decl|struct
name|gmonparam
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|nullfunc_loop_profiled
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nullfunc_profiled
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|startguprof
name|__P
argument_list|(
operator|(
expr|struct
name|gmonparam
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|stopguprof
name|__P
argument_list|(
operator|(
expr|struct
name|gmonparam
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|startguprof
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|stopguprof
parameter_list|(
name|p
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GUPROF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PROFILE_H_ */
end_comment

end_unit

