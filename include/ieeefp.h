begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ieeefp.h,v 1.4 1998/01/09 08:03:43 perry Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*   * Written by J.T. Conklin, Apr 6, 1995  * Public domain.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IEEEFP_H_
end_ifndef

begin_define
define|#
directive|define
name|_IEEEFP_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<machine/ieeefp.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_include
include|#
directive|include
file|<machine/floatingpoint.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__i386__ */
end_comment

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|fp_rnd_t
name|fpgetround
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fp_rnd_t
name|fpsetround
parameter_list|(
name|fp_rnd_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fp_except_t
name|fpgetmask
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fp_except_t
name|fpsetmask
parameter_list|(
name|fp_except_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fp_except_t
name|fpgetsticky
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fp_except_t
name|fpsetsticky
parameter_list|(
name|fp_except_t
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __i386__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IEEEFP_H_ */
end_comment

end_unit

