begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)defs.h	1.6 83/07/28		*/
end_comment

begin_include
include|#
directive|include
file|"ww.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_decl_stmt
name|int
name|nread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nreade
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nreadz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nreadc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timeval
name|starttime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timezone
name|timezone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ibuf
index|[
literal|512
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ibufp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ibufc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|bgetc
parameter_list|()
value|(ibufc ? ibufc--, *ibufp++&0x7f : -1)
end_define

begin_define
define|#
directive|define
name|bpeekc
parameter_list|()
value|(ibufc ? *ibufp&0x7f : -1)
end_define

begin_define
define|#
directive|define
name|bungetc
parameter_list|(
name|c
parameter_list|)
value|(ibufp> ibuf ? ibufc++, *--ibufp = (c) : -1)
end_define

begin_decl_stmt
name|struct
name|ww
modifier|*
name|selwin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ww
modifier|*
name|cmdwin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|quit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|terse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|escapec
decl_stmt|;
end_decl_stmt

end_unit

