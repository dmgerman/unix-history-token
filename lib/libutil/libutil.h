begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Peter Wemm<peter@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, is permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. This work was done expressly for inclusion into FreeBSD.  Other use  *    is permitted provided this notation is included.  * 4. Absolutely no warranty of function or purpose is made by the author  *    Peter Wemm.  * 5. Modifications may be freely made to this file providing the above  *    conditions are met.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBUTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBUTIL_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* Avoid pulling in all the include files for no need */
end_comment

begin_struct_decl
struct_decl|struct
name|termios
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|winsize
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|utmp
struct_decl|;
end_struct_decl

begin_decl_stmt
name|__BEGIN_DECLS
name|void
name|setproctitle
name|__P
argument_list|(
operator|(
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
name|login
name|__P
argument_list|(
operator|(
expr|struct
name|utmp
operator|*
name|ut
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|login_tty
name|__P
argument_list|(
operator|(
name|int
name|fd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|logout
name|__P
argument_list|(
operator|(
name|char
operator|*
name|line
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|logwtmp
name|__P
argument_list|(
operator|(
name|char
operator|*
name|line
operator|,
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|host
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|openpty
name|__P
argument_list|(
operator|(
name|int
operator|*
name|amaster
operator|,
name|int
operator|*
name|aslave
operator|,
name|char
operator|*
name|name
operator|,
expr|struct
name|termios
operator|*
name|termp
operator|,
expr|struct
name|winsize
operator|*
name|winp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBUTIL_H_ */
end_comment

end_unit

