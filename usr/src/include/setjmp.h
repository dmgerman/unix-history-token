begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)setjmp.h	5.3 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SETJMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_SETJMP_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|hp300
end_ifdef

begin_define
define|#
directive|define
name|_JBLEN
value|17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|i386
end_ifdef

begin_define
define|#
directive|define
name|_JBLEN
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_define
define|#
directive|define
name|_JBLEN
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|_JBLEN
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * sigsetjmp/siglongjmp use the first int to decide if the  * signal mask was saved or not.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|sigjmp_buf
index|[
name|_JBLEN
operator|+
literal|1
index|]
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_typedef
typedef|typedef
name|int
name|jmp_buf
index|[
name|_JBLEN
index|]
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|sigsetjmp
name|__P
argument_list|(
operator|(
name|sigjmp_buf
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|siglongjmp
name|__P
argument_list|(
operator|(
name|sigjmp_buf
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_decl_stmt
name|int
name|setjmp
name|__P
argument_list|(
operator|(
name|jmp_buf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_setjmp
name|__P
argument_list|(
operator|(
name|jmp_buf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|longjmp
name|__P
argument_list|(
operator|(
name|jmp_buf
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_longjmp
name|__P
argument_list|(
operator|(
name|jmp_buf
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SETJMP_H_ */
end_comment

end_unit

