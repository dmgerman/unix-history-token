begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)defs.h	3.4 83/09/01	  */
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

begin_define
define|#
directive|define
name|NWINDOW
value|9
end_define

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

begin_comment
comment|/* things for handling input */
end_comment

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
name|window
index|[
name|NWINDOW
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the windows */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|selwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the selected window */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|cmdwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the command window */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|framewin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the window for framing */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|boxwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the window for the box */
end_comment

begin_decl_stmt
name|char
modifier|*
name|shell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the shell program */
end_comment

begin_decl_stmt
name|char
modifier|*
name|shellname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the shell program name (for argv[0]) */
end_comment

begin_decl_stmt
name|int
name|nbufline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of lines in the buffer */
end_comment

begin_comment
comment|/* flags */
end_comment

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
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|incmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in command mode */
end_comment

begin_decl_stmt
name|char
name|escapec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* escape character */
end_comment

begin_function_decl
name|struct
name|ww
modifier|*
name|getwin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ww
modifier|*
name|openwin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ww
modifier|*
name|idtowin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ww
modifier|*
name|openiwin
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* stuff for long commands */
end_comment

begin_decl_stmt
name|int
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|argv
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number in the source file */
end_comment

begin_decl_stmt
name|char
name|insource
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* we're in a source */
end_comment

end_unit

