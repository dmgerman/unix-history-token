begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Peter Wemm<peter@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, is permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. This work was done expressly for inclusion into FreeBSD.  Other use  *    is permitted provided this notation is included.  * 4. Absolutely no warranty of function or purpose is made by the author  *    Peter Wemm.  * 5. Modifications may be freely made to this file providing the above  *    conditions are met.  *  * $Id$  */
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
name|_fmt
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
name|_ut
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
name|_fd
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
name|_line
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
specifier|const
name|char
operator|*
name|_line
operator|,
specifier|const
name|char
operator|*
name|_name
operator|,
specifier|const
name|char
operator|*
name|_host
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
name|_amaster
operator|,
name|int
operator|*
name|_aslave
operator|,
name|char
operator|*
name|_name
operator|,
expr|struct
name|termios
operator|*
name|_termp
operator|,
expr|struct
name|winsize
operator|*
name|_winp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|forkpty
name|__P
argument_list|(
operator|(
name|int
operator|*
name|_amaster
operator|,
name|char
operator|*
name|_name
operator|,
expr|struct
name|termios
operator|*
name|_termp
operator|,
expr|struct
name|winsize
operator|*
name|_winp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|uu_lockerr
name|__P
argument_list|(
operator|(
name|int
name|_uu_lockresult
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uu_lock
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|_ttyname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uu_unlock
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|_ttyname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_secure_path
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|_path
operator|,
name|uid_t
name|_uid
operator|,
name|gid_t
name|_gid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_define
define|#
directive|define
name|UU_LOCK_INUSE
value|(1)
end_define

begin_define
define|#
directive|define
name|UU_LOCK_OK
value|(0)
end_define

begin_define
define|#
directive|define
name|UU_LOCK_OPEN_ERR
value|(-1)
end_define

begin_define
define|#
directive|define
name|UU_LOCK_READ_ERR
value|(-2)
end_define

begin_define
define|#
directive|define
name|UU_LOCK_CREAT_ERR
value|(-3)
end_define

begin_define
define|#
directive|define
name|UU_LOCK_WRITE_ERR
value|(-4)
end_define

begin_define
define|#
directive|define
name|UU_LOCK_LINK_ERR
value|(-5)
end_define

begin_define
define|#
directive|define
name|UU_LOCK_TRY_ERR
value|(-6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBUTIL_H_ */
end_comment

end_unit

