begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rodney Ruddock of the University of Guelph.  *  * %sccs.include.redist.c%  *  *	@(#)ed.h	8.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|FILENAME_LEN
value|PATH_MAX
end_define

begin_define
define|#
directive|define
name|JMP_SET
value|(int)0
end_define

begin_define
define|#
directive|define
name|INTERUPT
value|(int)1
end_define

begin_define
define|#
directive|define
name|HANGUP
value|(int)2
end_define

begin_define
define|#
directive|define
name|SIGINT_ACTION
value|longjmp(ctrl_position, INTERUPT)
end_define

begin_define
define|#
directive|define
name|SIGINT_ALACTION
value|longjmp(ctrl_position2, INTERUPT)
end_define

begin_define
define|#
directive|define
name|SIGINT_ILACTION
value|longjmp(ctrl_position3, INTERUPT)
end_define

begin_define
define|#
directive|define
name|SIGHUP_ACTION
value|longjmp(ctrl_position, HANGUP)
end_define

begin_define
define|#
directive|define
name|NN_MAX_START
value|510
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|STDIN_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDOUT_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|A
block|{
name|struct
name|A
modifier|*
name|above
decl_stmt|,
modifier|*
name|below
decl_stmt|;
ifdef|#
directive|ifdef
name|STDIO
name|long
name|handle
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DBI
name|recno_t
name|handle
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MEMORY
name|char
modifier|*
name|handle
decl_stmt|;
endif|#
directive|endif
name|size_t
name|len
decl_stmt|;
block|}
name|LINE
typedef|;
end_typedef

begin_struct
struct|struct
name|MARK
block|{
name|LINE
modifier|*
name|address
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|u_layer
block|{
name|LINE
modifier|*
name|val
decl_stmt|,
modifier|*
modifier|*
name|cell
decl_stmt|;
name|struct
name|u_layer
modifier|*
name|below
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|d_layer
block|{
name|LINE
modifier|*
name|begin
decl_stmt|,
modifier|*
name|end
decl_stmt|;
name|struct
name|d_layer
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|nn_max
decl_stmt|,
name|nn_max_flag
decl_stmt|,
name|Start_default
decl_stmt|,
name|End_default
decl_stmt|,
name|address_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LINE
modifier|*
name|nn_max_start
decl_stmt|,
modifier|*
name|nn_max_end
decl_stmt|,
modifier|*
name|Start
decl_stmt|,
modifier|*
name|End
decl_stmt|,
modifier|*
name|current
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|text
decl_stmt|,
modifier|*
name|prompt_string
decl_stmt|,
name|help_msg
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LINE
modifier|*
modifier|*
name|gut
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|MARK
name|mark_matrix
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|filename_current
decl_stmt|,
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|zsnum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* z sticky number */
end_comment

begin_decl_stmt
specifier|extern
name|LINE
modifier|*
name|top
decl_stmt|,
modifier|*
name|bottom
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ...of the buffer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ss
decl_stmt|,
name|explain_flag
decl_stmt|,
name|name_set
decl_stmt|,
name|exit_code
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|filename_flag
decl_stmt|,
name|add_flag
decl_stmt|,
name|join_flag
decl_stmt|,
name|gut_num
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|change_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pat_err
decl_stmt|,
name|flag
decl_stmt|,
name|g_flag
decl_stmt|,
name|GV_flag
decl_stmt|,
name|printsfx
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|STDIO
end_ifdef

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|fhtmp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|file_seek
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|template
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DBI
end_ifdef

begin_decl_stmt
specifier|extern
name|DB
modifier|*
name|dbhtmp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|template
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|u_layer
modifier|*
name|u_stk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LINE
modifier|*
name|u_current
decl_stmt|,
modifier|*
name|u_top
decl_stmt|,
modifier|*
name|u_bottom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|u_set
decl_stmt|,
name|line_length
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|d_layer
modifier|*
name|d_stk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sigint_flag
decl_stmt|,
name|sighup_flag
decl_stmt|,
name|sigspecial
decl_stmt|,
name|sigspecial2
decl_stmt|,
name|sigspecial3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|jmp_buf
name|ctrl_position
decl_stmt|,
name|ctrl_position2
decl_stmt|,
name|ctrl_position3
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|RE_SEC
value|10
end_define

begin_decl_stmt
specifier|extern
name|regex_t
name|RE_comp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|regmatch_t
name|RE_match
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|RE_sol
decl_stmt|,
name|RE_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|RE_patt
decl_stmt|;
end_decl_stmt

end_unit

