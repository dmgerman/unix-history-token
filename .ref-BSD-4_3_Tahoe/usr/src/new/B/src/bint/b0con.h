begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b0con.h,v 1.4 85/08/26 10:42:23 timo Exp $ */
end_comment

begin_comment
comment|/* Configuration file: some easy changes to the system                      */
end_comment

begin_comment
comment|/* As much as possible, this is done automatically these days               */
end_comment

begin_comment
comment|/* You only need to change this file under rare circumstances               */
end_comment

begin_comment
comment|/* At the end, this file #includes another file, config.h, which is       */
end_comment

begin_comment
comment|/* generated automatically (by running mkconfig).  Most machine-dependent   */
end_comment

begin_comment
comment|/* changes are put there.                                                   */
end_comment

begin_comment
comment|/* VOID is used to keep lint quiet(er)                                      */
end_comment

begin_comment
comment|/* (This could be moved to "b.h", as it is never necessary to change it)    */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|VOID
value|(void)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VOID
end_define

begin_comment
comment|/*empty*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* some un*xes demand that you reset stdin in some way if you get eof, and  */
end_comment

begin_comment
comment|/* want to read from it still. If yours doesn't, delete "clearerr(stdin)"   */
end_comment

begin_comment
comment|/* Actually, it never harms, so why should you want to delete it?           */
end_comment

begin_define
define|#
directive|define
name|CLEAR_EOF
value|clearerr(stdin)
end_define

begin_comment
comment|/* Miscellaneous definitions*/
end_comment

begin_typedef
typedef|typedef
name|int
name|expint
typedef|;
end_typedef

begin_comment
comment|/*The 2nd argument of frexp points to this */
end_comment

begin_comment
comment|/*(see manual page frexp(3)).              */
end_comment

begin_comment
comment|/*On some 68K systems must be short (foo!) */
end_comment

begin_define
define|#
directive|define
name|Maxtrig
value|1e16
end_define

begin_comment
comment|/*Max x for sin(x), cos(x), tan(x)         */
end_comment

begin_comment
comment|/*(Can anybody find a way to compute this  */
end_comment

begin_comment
comment|/*automatically?)                          */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IBMPC
end_ifdef

begin_define
define|#
directive|define
name|Maxrefcnt
value|255
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Maxrefcnt
value|Maxintlet
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MaxSmallInt
value|(BASE-1)
end_define

begin_comment
comment|/* This must be so! */
end_comment

begin_define
define|#
directive|define
name|MinSmallInt
value|(-BASE)
end_define

begin_comment
comment|/* This must be so!!! */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INTEGRATION
end_ifndef

begin_define
define|#
directive|define
name|CMBUFSIZE
value|1000
end_define

begin_comment
comment|/*Buffer used for commands*/
end_comment

begin_define
define|#
directive|define
name|RDBUFSIZE
value|1000
end_define

begin_comment
comment|/*Buffer used for reading*/
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CMBUFSIZE
value|200
end_define

begin_comment
comment|/*Buffer used for commands*/
end_comment

begin_define
define|#
directive|define
name|RDBUFSIZE
value|100
end_define

begin_comment
comment|/*Buffer used for reading*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|unix
end_ifdef

begin_define
define|#
directive|define
name|SEED
value|getpid()
end_define

begin_comment
comment|/*Any suitable random int (eg date or time) */
end_comment

begin_comment
comment|/*to start the random number generator with */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SEED
value|getseed()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_comment
comment|/* Chain to real machine dependencies       */
end_comment

end_unit

