begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)cdefs.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CDEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_CDEFS_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__BEGIN_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|__END_DECLS
value|};
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__BEGIN_DECLS
end_define

begin_define
define|#
directive|define
name|__END_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The __CONCAT macro is used to concatenate parts of symbol names, e.g.  * with "#define OLD(foo) __CONCAT(old,foo)", OLD(foo) produces oldfoo.  * The __CONCAT macro is a bit tricky -- make sure you don't put spaces  * in between its arguments.  __CONCAT can also concatenate double-quoted  * strings produced by the __STRING macro, but this only works with ANSI C.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|protos
end_define

begin_comment
comment|/* full-blown ANSI C */
end_comment

begin_define
define|#
directive|define
name|__CONCAT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x ## y
end_define

begin_define
define|#
directive|define
name|__STRING
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !(__STDC__ || __cplusplus) */
end_comment

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|()
end_define

begin_comment
comment|/* traditional C preprocessor */
end_comment

begin_define
define|#
directive|define
name|__CONCAT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x
comment|/**/
value|y
end_define

begin_define
define|#
directive|define
name|__STRING
parameter_list|(
name|x
parameter_list|)
value|"x"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|const
value|__const
end_define

begin_comment
comment|/* GCC: ANSI C with -traditional */
end_comment

begin_define
define|#
directive|define
name|inline
value|__inline
end_define

begin_define
define|#
directive|define
name|signed
value|__signed
end_define

begin_define
define|#
directive|define
name|volatile
value|__volatile
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__GNUC__ */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/* delete ANSI C keywords */
end_comment

begin_define
define|#
directive|define
name|inline
end_define

begin_define
define|#
directive|define
name|signed
end_define

begin_define
define|#
directive|define
name|volatile
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(__STDC__ || __cplusplus) */
end_comment

begin_comment
comment|/*  * GCC has extensions for declaring functions as `pure' (always returns  * the same value given the same inputs, i.e., has no external state and  * no side effects) and `dead' (nonreturning).  These mainly affect  * optimization and warnings.  Unfortunately, GCC complains if these are  * used under strict ANSI mode (`gcc -ansi -pedantic'), hence we need to  * define them only if compiling without this.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__dead
value|__volatile
end_define

begin_define
define|#
directive|define
name|__pure
value|__const
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__dead
end_define

begin_define
define|#
directive|define
name|__pure
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CDEFS_H_ */
end_comment

end_unit

