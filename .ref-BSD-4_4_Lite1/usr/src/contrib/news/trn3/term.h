begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: term.h,v 3.0 1992/02/01 03:09:32 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
end_comment

begin_decl_stmt
name|EXT
name|char
name|circlebuf
index|[
name|PUSHSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|nextin
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|nextout
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
name|lastchar
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PENDING
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|FIONREAD
end_ifdef

begin_decl_stmt
name|EXT
name|long
name|iocount
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|input_pending
parameter_list|()
value|(nextin!=nextout || (ioctl(0, FIONREAD,&iocount),(int)iocount))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|input_pending
parameter_list|()
value|bizarre
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FIONREAD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_RDCHK
end_ifdef

begin_define
define|#
directive|define
name|input_pending
parameter_list|()
value|(rdchk(0)> 0)
end_define

begin_comment
comment|/* boolean only */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  HAS_RDCHK */
end_comment

begin_function_decl
name|int
name|circfill
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|int
name|devtty
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|input_pending
parameter_list|()
value|(nextin!=nextout || circfill())
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|input_pending
parameter_list|()
value|bizarre
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_RDCHK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FIONREAD */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PENDING */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|input_pending
parameter_list|()
value|(nextin!=nextout)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|input_pending
parameter_list|()
value|bizarre
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PENDING */
end_comment

begin_comment
comment|/* stuff wanted by terminal mode diddling routines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_TERMIO
end_ifdef

begin_decl_stmt
name|EXT
name|struct
name|termio
name|_tty
decl_stmt|,
name|_oldtty
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|I_TERMIOS
end_ifdef

begin_decl_stmt
name|EXT
name|struct
name|termios
name|_tty
decl_stmt|,
name|_oldtty
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXT
name|struct
name|sgttyb
name|_tty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|_res_flg
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|int
name|_tty_ch
name|INIT
argument_list|(
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|bool
name|bizarre
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* do we need to restore terminal? */
end_comment

begin_comment
comment|/* terminal mode diddling routines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_TERMIO
end_ifdef

begin_define
define|#
directive|define
name|crmode
parameter_list|()
value|((bizarre=1),_tty.c_lflag&=~ICANON,_tty.c_cc[VMIN] = 1,ioctl(_tty_ch,TCSETAF,&_tty))
end_define

begin_define
define|#
directive|define
name|nocrmode
parameter_list|()
value|((bizarre=1),_tty.c_lflag |= ICANON,_tty.c_cc[VEOF] = CEOF,stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|echo
parameter_list|()
value|((bizarre=1),_tty.c_lflag |= ECHO, ioctl(_tty_ch, TCSETA,&_tty))
end_define

begin_define
define|#
directive|define
name|noecho
parameter_list|()
value|((bizarre=1),_tty.c_lflag&=~ECHO, ioctl(_tty_ch, TCSETA,&_tty))
end_define

begin_define
define|#
directive|define
name|nl
parameter_list|()
value|((bizarre=1),_tty.c_iflag |= ICRNL,_tty.c_oflag |= ONLCR,ioctl(_tty_ch, TCSETAW,&_tty))
end_define

begin_define
define|#
directive|define
name|nonl
parameter_list|()
value|((bizarre=1),_tty.c_iflag&=~ICRNL,_tty.c_oflag&=~ONLCR,ioctl(_tty_ch, TCSETAW,&_tty))
end_define

begin_define
define|#
directive|define
name|savetty
parameter_list|()
value|(ioctl(_tty_ch, TCGETA,&_oldtty),ioctl(_tty_ch, TCGETA,&_tty))
end_define

begin_define
define|#
directive|define
name|resetty
parameter_list|()
value|((bizarre=0),ioctl(_tty_ch, TCSETAF,&_oldtty))
end_define

begin_define
define|#
directive|define
name|unflush_output
parameter_list|()
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !I_TERMIO */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_TERMIOS
end_ifdef

begin_define
define|#
directive|define
name|crmode
parameter_list|()
value|((bizarre=1), _tty.c_lflag&= ~ICANON,_tty.c_cc[VMIN]=1,tcsetattr(_tty_ch, TCSAFLUSH,&_tty))
end_define

begin_define
define|#
directive|define
name|nocrmode
parameter_list|()
value|((bizarre=1),_tty.c_lflag |= ICANON,_tty.c_cc[VEOF] = CEOF,tcsetattr(_tty_ch, TCSAFLUSH,&_tty))
end_define

begin_define
define|#
directive|define
name|echo
parameter_list|()
value|((bizarre=1),_tty.c_lflag |= ECHO, tcsetattr(_tty_ch, TCSAFLUSH,&_tty))
end_define

begin_define
define|#
directive|define
name|noecho
parameter_list|()
value|((bizarre=1),_tty.c_lflag&=~ECHO, tcsetattr(_tty_ch, TCSAFLUSH,&_tty))
end_define

begin_define
define|#
directive|define
name|nl
parameter_list|()
value|((bizarre=1),_tty.c_iflag |= ICRNL,_tty.c_oflag |= ONLCR,tcsetattr(_tty_ch, TCSAFLUSH,&_tty))
end_define

begin_define
define|#
directive|define
name|nonl
parameter_list|()
value|((bizarre=1),_tty.c_iflag&=~ICRNL,_tty.c_oflag&=~ONLCR,tcsetattr(_tty_ch, TCSAFLUSH,&_tty))
end_define

begin_define
define|#
directive|define
name|savetty
parameter_list|()
value|(tcgetattr(_tty_ch,&_oldtty),tcgetattr(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|resetty
parameter_list|()
value|((bizarre=0),tcsetattr(_tty_ch, TCSAFLUSH,&_oldtty))
end_define

begin_define
define|#
directive|define
name|unflush_output
parameter_list|()
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !I_TERMIOS */
end_comment

begin_define
define|#
directive|define
name|raw
parameter_list|()
value|((bizarre=1),_tty.sg_flags|=RAW, stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|noraw
parameter_list|()
value|((bizarre=1),_tty.sg_flags&=~RAW,stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|crmode
parameter_list|()
value|((bizarre=1),_tty.sg_flags |= CBREAK, stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|nocrmode
parameter_list|()
value|((bizarre=1),_tty.sg_flags&= ~CBREAK,stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|echo
parameter_list|()
value|((bizarre=1),_tty.sg_flags |= ECHO, stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|noecho
parameter_list|()
value|((bizarre=1),_tty.sg_flags&= ~ECHO, stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|nl
parameter_list|()
value|((bizarre=1),_tty.sg_flags |= CRMOD,stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|nonl
parameter_list|()
value|((bizarre=1),_tty.sg_flags&= ~CRMOD, stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|savetty
parameter_list|()
value|(gtty(_tty_ch,&_tty), _res_flg = _tty.sg_flags)
end_define

begin_define
define|#
directive|define
name|resetty
parameter_list|()
value|((bizarre=0),_tty.sg_flags = _res_flg, stty(_tty_ch,&_tty))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LFLUSHO
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_function_decl
name|EXT
name|int
name|lflusho
name|INIT
parameter_list|(
name|LFLUSHO
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|EXT
name|long
name|lflusho
name|INIT
parameter_list|(
name|LFLUSHO
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_define
define|#
directive|define
name|unflush_output
parameter_list|()
value|(ioctl(_tty_ch,TIOCLBIC,&lflusho))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|unflush_output
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LFLUSHO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I_TERMIOS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I_TERMIO */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCSTI
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|forceme
parameter_list|(
name|c
parameter_list|)
value|ioctl(_tty_ch,TIOCSTI,Null(long*))
end_define

begin_comment
comment|/* ghad! */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|forceme
parameter_list|(
name|c
parameter_list|)
value|ioctl(_tty_ch,TIOCSTI,c)
end_define

begin_comment
comment|/* pass character in " " */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|forceme
parameter_list|(
name|c
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* termcap stuff */
end_comment

begin_comment
comment|/*  * NOTE: if you don't have termlib you'll either have to define these strings  *    and the tputs routine, or you'll have to redefine the macros below  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_TERMLIB
end_ifdef

begin_decl_stmt
name|EXT
name|int
name|GT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hardware tabs */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|BC
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* backspace character */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|UP
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* move cursor up one line */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|CR
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get to left margin, somehow */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|VB
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* visible bell */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|CL
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* home and clear screen */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|CE
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* clear to end of line */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|TI
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* initialize terminal */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|TE
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* reset terminal */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|CM
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cursor motion */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|HO
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* home cursor */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CLEAREOL
end_ifdef

begin_function_decl
name|EXT
name|char
modifier|*
name|CD
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* clear to end of display */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CLEAREOL */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|SO
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* begin standout mode */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|SE
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* end standout mode */
end_comment

begin_decl_stmt
name|EXT
name|int
name|SG
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* blanks left by SO and SE */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|US
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* start underline mode */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|UE
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* end underline mode */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|UC
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* underline a character, 						 if that's how it's done */
end_comment

begin_decl_stmt
name|EXT
name|int
name|UG
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* blanks left by US and UE */
end_comment

begin_function_decl
name|EXT
name|bool
name|AM
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* does terminal have automatic 								 margins? */
end_comment

begin_function_decl
name|EXT
name|bool
name|XN
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* does it eat 1st newline after 							 automatic wrap? */
end_comment

begin_decl_stmt
name|EXT
name|char
name|PC
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pad character for use by tputs() */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_SOURCE
end_ifdef

begin_decl_stmt
name|EXT
name|speed_t
name|outspeed
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* terminal output speed, */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXT
name|long
name|outspeed
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 	for use by tputs() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|int
name|LINES
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|,
name|COLS
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of screen */
end_comment

begin_decl_stmt
name|EXT
name|int
name|just_a_sec
name|INIT
argument_list|(
literal|960
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 sec at current baud rate */
end_comment

begin_comment
comment|/* (number of nulls) */
end_comment

begin_comment
comment|/* define a few handy macros */
end_comment

begin_define
define|#
directive|define
name|backspace
parameter_list|()
value|tputs(BC,0,putchr) FLUSH
end_define

begin_define
define|#
directive|define
name|clear
parameter_list|()
value|tputs(CL,LINES,putchr) FLUSH
end_define

begin_define
define|#
directive|define
name|erase_eol
parameter_list|()
value|tputs(CE,1,putchr) FLUSH
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CLEAREOL
end_ifdef

begin_define
define|#
directive|define
name|clear_rest
parameter_list|()
value|tputs(CD,LINES,putchr) FLUSH
end_define

begin_define
define|#
directive|define
name|maybe_eol
parameter_list|()
value|if(erase_screen&&can_home_clear)tputs(CE,1,putchr) FLUSH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CLEAREOL */
end_comment

begin_define
define|#
directive|define
name|underline
parameter_list|()
value|tputs(US,1,putchr) FLUSH
end_define

begin_define
define|#
directive|define
name|un_underline
parameter_list|()
value|tputs(UE,1,putchr) FLUSH
end_define

begin_define
define|#
directive|define
name|underchar
parameter_list|()
value|tputs(UC,0,putchr) FLUSH
end_define

begin_define
define|#
directive|define
name|standout
parameter_list|()
value|tputs(SO,1,putchr) FLUSH
end_define

begin_define
define|#
directive|define
name|un_standout
parameter_list|()
value|tputs(SE,1,putchr) FLUSH
end_define

begin_define
define|#
directive|define
name|up_line
parameter_list|()
value|tputs(UP,1,putchr) FLUSH
end_define

begin_define
define|#
directive|define
name|carriage_return
parameter_list|()
value|tputs(CR,1,putchr) FLUSH
end_define

begin_define
define|#
directive|define
name|dingaling
parameter_list|()
value|tputs(VB,1,putchr) FLUSH
end_define

begin_else
else|#
directive|else
end_else

begin_expr_stmt
operator|????????
comment|/* up to you */
endif|#
directive|endif
name|EXT
name|int
name|page_line
name|INIT
argument_list|(
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* line number for paging in 						 print_line (origin 1) */
end_comment

begin_decl_stmt
name|void
name|term_init
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|term_set
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pushchar
name|_
argument_list|(
operator|(
name|char_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pushstring
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mac_init
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mac_line
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|show_macros
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|putchr
name|_
argument_list|(
operator|(
name|char_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* routine for tputs to call */
end_comment

begin_decl_stmt
name|bool
name|finish_command
name|_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|finish_dblchar
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|eat_typeahead
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|save_typeahead
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|settle_down
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_TERMLIB
end_ifdef

begin_decl_stmt
name|void
name|termlib_init
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|termlib_reset
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|read_tty
end_ifndef

begin_decl_stmt
name|int
name|read_tty
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|underprint
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NOFIREWORKS
end_ifdef

begin_decl_stmt
name|void
name|no_sofire
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|no_ulfire
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|getcmd
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|get_anything
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pause_getcmd
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in_char
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in_answer
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|print_lines
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|page_init
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pad
name|_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|printcmd
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rubout
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|reprint
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|home_cursor
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|goto_line
name|_
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SIGWINCH
end_ifdef

begin_decl_stmt
name|Signal_t
name|winch_catcher
name|_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGWINCH */
end_comment

end_unit

