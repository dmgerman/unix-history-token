begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: unix.h,v 2.4 85/08/22 16:09:55 timo Exp $ */
end_comment

begin_comment
comment|/*  * B editor -- inventory of available UNIX features.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_define
define|#
directive|define
name|VFORK
end_define

begin_comment
comment|/* 4.x BSD vfork() system call available */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_2
end_ifdef

begin_define
define|#
directive|define
name|SELECT
end_define

begin_comment
comment|/* 4.2 BSD select() system call available */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGNAL
end_define

begin_comment
comment|/* can #include<signal.h> (v7 or any BSD compatible) */
end_comment

begin_define
define|#
directive|define
name|SETJMP
end_define

begin_comment
comment|/* can #include<setjmp.h> */
end_comment

begin_define
define|#
directive|define
name|SGTTY_H
end_define

begin_comment
comment|/* can #include<sgtty.h> (at least v7 compatible) */
end_comment

begin_define
define|#
directive|define
name|PERROR
end_define

begin_comment
comment|/* can use perror(), sys_errlist and sys_nerr */
end_comment

begin_comment
comment|/* #define PWB */
end_comment

begin_comment
comment|/* Turn on for PWB/UNIX systems without getenv etc. */
end_comment

end_unit

