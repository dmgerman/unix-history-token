begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * rparams.h - parameters for readnews, rfuncs, and readr.  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|Rparams
init|=
literal|"@(#)rparams.h	2.6	4/23/83"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"params.h"
end_include

begin_comment
comment|/* flags for readnews */
end_comment

begin_define
define|#
directive|define
name|pflag
value|options[0].flag
end_define

begin_define
define|#
directive|define
name|tflag
value|options[1].flag
end_define

begin_define
define|#
directive|define
name|aflag
value|options[2].flag
end_define

begin_define
define|#
directive|define
name|nflag
value|options[3].flag
end_define

begin_define
define|#
directive|define
name|cflag
value|options[4].flag
end_define

begin_define
define|#
directive|define
name|lflag
value|options[5].flag
end_define

begin_define
define|#
directive|define
name|rflag
value|options[6].flag
end_define

begin_define
define|#
directive|define
name|sflag
value|options[7].flag
end_define

begin_define
define|#
directive|define
name|xflag
value|options[8].flag
end_define

begin_define
define|#
directive|define
name|hflag
value|options[9].flag
end_define

begin_define
define|#
directive|define
name|Mflag
value|options[10].flag
end_define

begin_define
define|#
directive|define
name|fflag
value|options[11].flag
end_define

begin_define
define|#
directive|define
name|uflag
value|options[12].flag
end_define

begin_define
define|#
directive|define
name|eflag
value|options[13].flag
end_define

begin_define
define|#
directive|define
name|NEXT
value|0
end_define

begin_define
define|#
directive|define
name|SPEC
value|1
end_define

begin_define
define|#
directive|define
name|FORWARD
value|0
end_define

begin_define
define|#
directive|define
name|BACKWARD
value|1
end_define

begin_define
define|#
directive|define
name|UNKNOWN
value|0001
end_define

begin_comment
comment|/* possible modes for news program */
end_comment

begin_define
define|#
directive|define
name|MAIL
value|0004
end_define

begin_define
define|#
directive|define
name|ANY
value|0007
end_define

begin_struct
struct|struct
name|optable
block|{
comment|/* options table. */
name|char
name|optlet
decl_stmt|;
comment|/* option character. */
name|char
name|filchar
decl_stmt|;
comment|/* if to pickup string, fill character. */
name|int
name|flag
decl_stmt|;
comment|/* TRUE if have seen this opt. */
name|int
name|newstate
decl_stmt|;
comment|/* STRING if takes arg, else OPTION */
name|int
name|oldmode
decl_stmt|;
comment|/* OR of legal input modes. */
name|int
name|newmode
decl_stmt|;
comment|/* output mode. */
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* string buffer */
block|}
struct|;
end_struct

begin_comment
comment|/* external declarations specific to readnews */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|HELPFILE
index|[]
decl_stmt|,
modifier|*
name|infile
decl_stmt|,
modifier|*
name|outfile
decl_stmt|,
name|PAGER
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|bitmap
index|[]
decl_stmt|,
modifier|*
name|temprc
decl_stmt|,
modifier|*
name|MAILER
decl_stmt|,
name|USERS
index|[]
decl_stmt|,
name|CAESAR
index|[]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|ROOTID
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|ROOTID
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NOTIFY
end_ifdef

begin_decl_stmt
specifier|extern
name|char
name|TELLFILE
index|[]
decl_stmt|,
name|TELLME
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
name|filename
index|[]
decl_stmt|,
name|coptbuf
index|[]
decl_stmt|,
name|datebuf
index|[]
decl_stmt|,
name|titlebuf
index|[]
decl_stmt|,
name|afline
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|newsrc
index|[]
decl_stmt|,
name|groupdir
index|[]
decl_stmt|,
name|rcbuf
index|[]
decl_stmt|,
modifier|*
name|rcline
index|[]
decl_stmt|,
modifier|*
name|argvrc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bit
decl_stmt|,
name|obit
decl_stmt|,
name|mode
decl_stmt|,
name|ngrp
decl_stmt|,
name|last
decl_stmt|,
name|line
decl_stmt|,
name|newrc
argument_list|()
decl_stmt|,
name|readmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|rcfp
decl_stmt|,
modifier|*
name|actfp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|atime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stat
name|statbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|optable
modifier|*
name|optpt
decl_stmt|,
name|options
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|actdirect
decl_stmt|,
name|rcreadok
decl_stmt|,
name|zapng
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|ngsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* macros */
end_comment

begin_define
define|#
directive|define
name|get
parameter_list|(
name|i
parameter_list|)
value|(bitmap[(i-1)>> 3]& (1<< (i-1) % 8))
end_define

begin_define
define|#
directive|define
name|set
parameter_list|(
name|i
parameter_list|)
value|(bitmap[(i-1)>> 3] |= (1<< (i-1) % 8))
end_define

begin_define
define|#
directive|define
name|clear
parameter_list|(
name|i
parameter_list|)
value|(bitmap[(i-1)>> 3]&= ~(1<< (i-1) % 8))
end_define

end_unit

