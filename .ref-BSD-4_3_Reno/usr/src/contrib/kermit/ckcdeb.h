begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  C K C D E B . H  */
end_comment

begin_comment
comment|/*  This file is included by all C-Kermit modules, including the modules  that aren't specific to Kermit (like the command parser and the ck?tio and  ck?fio modules.  It specifies format codes for debug(), tlog(), and similar  functions, and includes any necessary typedefs to be used by all C-Kermit  modules, and also includes some feature selection compile-time switches. */
end_comment

begin_comment
comment|/*  Copyright (C) 1985, Trustees of Columbia University in the City of New York.  Permission is granted to any individual or institution to use, copy, or  redistribute this software so long as it is not sold for profit, provided this  copyright notice is retained. */
end_comment

begin_comment
comment|/*  DEBUG and TLOG should be defined in the Makefile if you want debugging  and transaction logs.  Don't define them if you want to save the space  and overhead. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|{}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TLOG
end_ifndef

begin_define
define|#
directive|define
name|tlog
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|{}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Formats for debug(), tlog(), etc */
end_comment

begin_define
define|#
directive|define
name|F000
value|0
end_define

begin_define
define|#
directive|define
name|F001
value|1
end_define

begin_define
define|#
directive|define
name|F010
value|2
end_define

begin_define
define|#
directive|define
name|F011
value|3
end_define

begin_define
define|#
directive|define
name|F100
value|4
end_define

begin_define
define|#
directive|define
name|F101
value|5
end_define

begin_define
define|#
directive|define
name|F110
value|6
end_define

begin_define
define|#
directive|define
name|F111
value|7
end_define

begin_comment
comment|/* Compiler dependencies */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROVX1
end_ifdef

begin_typedef
typedef|typedef
name|char
name|CHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|LONG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|void
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_typedef
typedef|typedef
name|char
name|CHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|LONG
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|C70
end_ifdef

begin_typedef
typedef|typedef
name|char
name|CHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|LONG
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|char
name|CHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|LONG
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TOWER1
end_ifdef

begin_typedef
typedef|typedef
name|int
name|void
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Line delimiter for text files */
end_comment

begin_comment
comment|/*  If the system uses a single character for text file line delimitation,  define NLCHAR to the value of that character.  For text files, that  character will be converted to CRLF upon output, and CRLF will be converted  to that character on input. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_comment
comment|/* Macintosh */
end_comment

begin_define
define|#
directive|define
name|NLCHAR
value|015
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* All Unix-like systems */
end_comment

begin_define
define|#
directive|define
name|NLCHAR
value|012
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  At this point, if there's a system that uses ordinary CRLF line  delimitation AND the C compiler actually returns both the CR and  the LF when doing input from a file, then #undef NLCHAR. */
end_comment

begin_comment
comment|/* The device name of a job's controlling terminal */
end_comment

begin_comment
comment|/* Special for VMS, same for all Unixes (?), not used by Macintosh */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax11c
end_ifdef

begin_define
define|#
directive|define
name|CTTNAM
value|"TT:"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CTTNAM
value|"/dev/tty"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some special includes for VAX/VMS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax11c
end_ifdef

begin_include
include|#
directive|include
include|ssdef
end_include

begin_include
include|#
directive|include
include|stsdef
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Program return codes for VMS, DECUS C, and Unix */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax11c
end_ifdef

begin_define
define|#
directive|define
name|GOOD_EXIT
value|(SS$_NORMAL | STS$M_INHIB_MSG)
end_define

begin_define
define|#
directive|define
name|BAD_EXIT
value|SS$_ABORT
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|decus
end_ifdef

begin_define
define|#
directive|define
name|GOOD_EXIT
value|IO_NORMAL
end_define

begin_define
define|#
directive|define
name|BAD_EXIT
value|IO_ERROR
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GOOD_EXIT
value|0
end_define

begin_define
define|#
directive|define
name|BAD_EXIT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

