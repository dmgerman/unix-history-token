begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)assert.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Unlike other ANSI header files,<assert.h> may usefully be included  * multiple times, with and without NDEBUG defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|assert
end_undef

begin_undef
undef|#
directive|undef
name|_assert
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|NDEBUG
end_ifdef

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|e
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|_assert
parameter_list|(
name|e
parameter_list|)
value|((void)0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_assert
parameter_list|(
name|e
parameter_list|)
value|assert(e)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|e
parameter_list|)
value|((e) ? (void)0 : __assert(__FILE__, __LINE__, #e))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PCC */
end_comment

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|e
parameter_list|)
value|((e) ? (void)0 : __assert(__FILE__, __LINE__, "e"))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|void
name|__assert
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

end_unit

