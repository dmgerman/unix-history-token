begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)edit.h	1.1 */
end_comment

begin_comment
comment|/*  *  edit.h -  common data structure for vi and emacs edit options  *  *   David Korn  *   AT&T Bell Laboratories  *   Room 5D-112  *   Murray Hill, N. J. 07974  *   Tel. x7975  *  */
end_comment

begin_define
define|#
directive|define
name|LOOKAHEAD
value|80
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VENIX
end_ifdef

begin_define
define|#
directive|define
name|READAHEAD
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|READAHEAD
value|LOOKAHEAD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VENIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MULTIBYTE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ESS_MAXCHAR
end_ifndef

begin_include
include|#
directive|include
file|"national.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ESS_MAXCHAR */
end_comment

begin_if
if|#
directive|if
name|ESS_MAXCHAR
operator|<=
literal|2
end_if

begin_typedef
typedef|typedef
name|unsigned
name|short
name|genchar
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|long
name|genchar
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CHARSIZE
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
name|genchar
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CHARSIZE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MULTIBYTE */
end_comment

begin_struct
struct|struct
name|edit
block|{
name|int
name|e_kill
decl_stmt|;
name|int
name|e_erase
decl_stmt|;
name|int
name|e_eof
decl_stmt|;
name|int
name|e_fchar
decl_stmt|;
name|char
name|e_plen
decl_stmt|;
comment|/* length of prompt string */
name|char
name|e_crlf
decl_stmt|;
comment|/* zero if cannot return to beginning of line */
name|jmp_buf
name|e_env
decl_stmt|;
name|int
name|e_llimit
decl_stmt|;
comment|/* line length limit */
name|int
name|e_hline
decl_stmt|;
comment|/* current history line number */
name|int
name|e_hloff
decl_stmt|;
comment|/* line number offset for command */
name|int
name|e_hismin
decl_stmt|;
comment|/* minimum history line number */
name|int
name|e_hismax
decl_stmt|;
comment|/* maximum history line number */
name|int
name|e_raw
decl_stmt|;
comment|/* set when in raw mode or alt mode */
name|int
name|e_cur
decl_stmt|;
comment|/* current line position */
name|int
name|e_eol
decl_stmt|;
comment|/* end-of-line position */
name|int
name|e_pcur
decl_stmt|;
comment|/* current physical line position */
name|int
name|e_peol
decl_stmt|;
comment|/* end of physical line position */
name|int
name|e_mode
decl_stmt|;
comment|/* edit mode */
name|int
name|e_index
decl_stmt|;
comment|/* index in look-ahead buffer */
name|int
name|e_repeat
decl_stmt|;
name|int
name|e_saved
decl_stmt|;
name|int
name|e_fcol
decl_stmt|;
comment|/* first column */
name|int
name|e_ucol
decl_stmt|;
comment|/* column for undo */
name|int
name|e_addnl
decl_stmt|;
comment|/* set if new-line must be added */
name|int
name|e_wsize
decl_stmt|;
comment|/* width of display window */
name|unsigned
name|char
modifier|*
name|e_outptr
decl_stmt|;
comment|/* pointer with output buffer */
name|genchar
modifier|*
name|e_inbuf
decl_stmt|;
comment|/* pointer to input buffer */
name|char
modifier|*
name|e_prompt
decl_stmt|;
comment|/* pointer to buffer containing the prompt */
name|genchar
modifier|*
name|e_ubuf
decl_stmt|;
comment|/* pointer to the undo buffer */
name|genchar
modifier|*
name|e_tmp
decl_stmt|;
comment|/* temporary workspace buffer */
name|char
modifier|*
name|e_search
decl_stmt|;
comment|/* temporary workspace buffer */
name|genchar
modifier|*
name|e_Ubuf
decl_stmt|;
comment|/* temporary workspace buffer */
name|genchar
modifier|*
name|e_physbuf
decl_stmt|;
comment|/* temporary workspace buffer */
name|int
name|e_lbuf
index|[
name|LOOKAHEAD
index|]
decl_stmt|;
comment|/* pointer to look-ahead buffer */
name|int
name|e_fd
decl_stmt|;
comment|/* file descriptor */
name|int
name|e_ttyspeed
decl_stmt|;
comment|/* line speed, also indicates tty parms are valid */
name|int
modifier|*
name|e_globals
decl_stmt|;
comment|/* global variables */
name|genchar
modifier|*
name|e_window
decl_stmt|;
comment|/* display window  image */
name|char
name|e_inmacro
decl_stmt|;
comment|/* processing macro expansion */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FEMAX
value|50
end_define

begin_comment
comment|/* maximum number of file matches for q_expand */
end_comment

begin_define
define|#
directive|define
name|MAXWINDOW
value|160
end_define

begin_comment
comment|/* maximum width window */
end_comment

begin_define
define|#
directive|define
name|MINWINDOW
value|20
end_define

begin_comment
comment|/* minimum width window */
end_comment

begin_define
define|#
directive|define
name|DFLTWINDOW
value|80
end_define

begin_comment
comment|/* default window width */
end_comment

begin_define
define|#
directive|define
name|MAXPAT
value|100
end_define

begin_comment
comment|/* maximum length for pattern word */
end_comment

begin_define
define|#
directive|define
name|YES
value|1
end_define

begin_define
define|#
directive|define
name|NO
value|0
end_define

begin_define
define|#
directive|define
name|FAST
value|2
end_define

begin_define
define|#
directive|define
name|SLOW
value|1
end_define

begin_define
define|#
directive|define
name|RAWMODE
value|1
end_define

begin_define
define|#
directive|define
name|ALTMODE
value|2
end_define

begin_define
define|#
directive|define
name|DELETE
value|'\177'
end_define

begin_define
define|#
directive|define
name|BELL
value|'\7'
end_define

begin_define
define|#
directive|define
name|ESC
value|033
end_define

begin_define
define|#
directive|define
name|UEOF
value|-2
end_define

begin_comment
comment|/* user eof char synonym */
end_comment

begin_define
define|#
directive|define
name|UERASE
value|-3
end_define

begin_comment
comment|/* user erase char synonym */
end_comment

begin_define
define|#
directive|define
name|UINTR
value|-4
end_define

begin_comment
comment|/* user intr char synonym */
end_comment

begin_define
define|#
directive|define
name|UKILL
value|-5
end_define

begin_comment
comment|/* user kill char synonym */
end_comment

begin_define
define|#
directive|define
name|UQUIT
value|-6
end_define

begin_comment
comment|/* user quit char synonym */
end_comment

begin_define
define|#
directive|define
name|cntl
parameter_list|(
name|x
parameter_list|)
value|('x'&037)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KSHELL
end_ifndef

begin_define
define|#
directive|define
name|STRIP
value|0377
end_define

begin_define
define|#
directive|define
name|TO_PRINT
value|0100
end_define

begin_define
define|#
directive|define
name|GMACS
value|1
end_define

begin_define
define|#
directive|define
name|EMACS
value|2
end_define

begin_define
define|#
directive|define
name|VIRAW
value|4
end_define

begin_define
define|#
directive|define
name|EDITVI
value|8
end_define

begin_define
define|#
directive|define
name|NOHIST
value|16
end_define

begin_define
define|#
directive|define
name|EDITMASK
value|15
end_define

begin_define
define|#
directive|define
name|is_option
parameter_list|(
name|m
parameter_list|)
value|(opt_flag&(m))
end_define

begin_decl_stmt
specifier|extern
name|char
name|opt_flag
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|read
parameter_list|(
name|fd
parameter_list|,
name|buff
parameter_list|,
name|n
parameter_list|)
value|syscall(3,fd,buff,n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KSHELL */
end_comment

begin_function_decl
specifier|extern
name|void
name|setcooked
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|edit
name|editb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|big_vi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|version
decl_stmt|;
end_decl_stmt

end_unit

