begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ttyent.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TTYENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_TTYENT_H_
end_define

begin_define
define|#
directive|define
name|_PATH_TTYS
value|"/etc/ttys"
end_define

begin_define
define|#
directive|define
name|_TTYS_OFF
value|"off"
end_define

begin_define
define|#
directive|define
name|_TTYS_ON
value|"on"
end_define

begin_define
define|#
directive|define
name|_TTYS_SECURE
value|"secure"
end_define

begin_define
define|#
directive|define
name|_TTYS_WINDOW
value|"window"
end_define

begin_struct
struct|struct
name|ttyent
block|{
name|char
modifier|*
name|ty_name
decl_stmt|;
comment|/* terminal device name */
name|char
modifier|*
name|ty_getty
decl_stmt|;
comment|/* command to execute, usually getty */
name|char
modifier|*
name|ty_type
decl_stmt|;
comment|/* terminal type for termcap */
define|#
directive|define
name|TTY_ON
value|0x01
comment|/* enable logins (start ty_getty program) */
define|#
directive|define
name|TTY_SECURE
value|0x02
comment|/* allow uid of 0 to login */
name|int
name|ty_status
decl_stmt|;
comment|/* status flags */
name|char
modifier|*
name|ty_window
decl_stmt|;
comment|/* command to start up window manager */
name|char
modifier|*
name|ty_comment
decl_stmt|;
comment|/* comment field */
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|struct
name|ttyent
modifier|*
name|getttyent
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ttyent
modifier|*
name|getttynam
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setttyent
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|endttyent
name|__P
argument_list|(
operator|(
name|void
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
comment|/* !_TTYENT_H_ */
end_comment

end_unit

