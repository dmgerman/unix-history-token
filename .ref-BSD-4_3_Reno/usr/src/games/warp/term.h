begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: term.h,v 7.0.1.2 86/12/12 17:05:15 lwall Exp $ */
end_comment

begin_comment
comment|/* $Log:	term.h,v $  * Revision 7.0.1.2  86/12/12  17:05:15  lwall  * Baseline for net release.  *   * Revision 7.0.1.1  86/10/16  10:53:33  lwall  * Added Damage.  Fixed random bugs.  *   * Revision 7.0  86/10/08  15:14:07  lwall  * Split into separate files.  Added amoebas and pirates.  *   */
end_comment

begin_comment
comment|/* warp will still work without the following, but may get ahead at low speed */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCOUTQ
end_ifdef

begin_comment
comment|/* chars left in output queue */
end_comment

begin_define
define|#
directive|define
name|output_pending
parameter_list|()
value|(ioctl(1, TIOCOUTQ,&iocount),iocount)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If some of the following look something like curses calls, it is because  * warp used to use curses but doesn't now.  Warp was neither as efficient nor  * as portable with curses, and since the program had to cheat on curses all  * over the place anyway, we ripped it out.  */
end_comment

begin_define
define|#
directive|define
name|setimage
parameter_list|(
name|of
parameter_list|,
name|to
parameter_list|)
value|(mvaddch(of->posy+1,of->posx*2,of->image=(to)))
end_define

begin_define
define|#
directive|define
name|mvaddch
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|,
name|ch
parameter_list|)
value|move((y),(x),(ch))
end_define

begin_comment
comment|/* #define addch(ch) (tmpchr=(ch), write(1,&tmpchr,1), real_x++) */
end_comment

begin_define
define|#
directive|define
name|mvaddc
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|,
name|ch
parameter_list|)
value|move((y),(x),(ch))
end_define

begin_define
define|#
directive|define
name|addc
parameter_list|(
name|ch
parameter_list|)
value|(write(1,&(ch),1), real_x++)
end_define

begin_define
define|#
directive|define
name|addspace
parameter_list|()
value|(write(1," ",1), real_x++)
end_define

begin_define
define|#
directive|define
name|mvaddstr
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|)
value|(move((y),(x),0), tmpstr = (s), \      tmplen = strlen(tmpstr), write(1, tmpstr, tmplen), real_x += tmplen)
end_define

begin_decl_stmt
name|EXT
name|int
name|tmplen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|tmpstr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EXT char tmpchr; */
end_comment

begin_comment
comment|/* The following macros are like the pseudo-curses macros above, but do  * certain amount of controlled output buffering.  *  * NOTE: a beg_qwrite()..end_qwrite() sequence must NOT contain a cursor  * movement (move), because the move() routine uses beg_qwrite()..end_qwrite()  * itself.  */
end_comment

begin_define
define|#
directive|define
name|beg_qwrite
parameter_list|()
value|(maxcmstring = cmbuffer)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|qwrite
parameter_list|()
value|asm("movc3 _gfillen,_filler,*_maxcmstring"); maxcmstring += gfillen
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|qwrite
parameter_list|()
value|(movc3(gfillen,filler,maxcmstring), maxcmstring += gfillen)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|qaddc
parameter_list|(
name|ch
parameter_list|)
value|(*maxcmstring++ = (ch), real_x++)
end_define

begin_define
define|#
directive|define
name|qaddch
parameter_list|(
name|ch
parameter_list|)
value|(*maxcmstring++ = (ch), real_x++)
end_define

begin_define
define|#
directive|define
name|qaddspace
parameter_list|()
value|(*maxcmstring++ = ' ', real_x++)
end_define

begin_define
define|#
directive|define
name|end_qwrite
parameter_list|()
value|(write(1,cmbuffer,maxcmstring-cmbuffer))
end_define

begin_comment
comment|/* setting a ??size to infinity forces cursor addressing in that direction */
end_comment

begin_decl_stmt
name|EXT
name|int
name|CMsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|BCsize
name|INIT
argument_list|(
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|DOsize
name|INIT
argument_list|(
literal|1000
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|UPsize
name|INIT
argument_list|(
literal|1000
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|NDsize
name|INIT
argument_list|(
literal|1000
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|charsperhalfsec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|real_y
name|INIT
argument_list|(
operator|-
literal|100
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|real_x
name|INIT
argument_list|(
operator|-
literal|100
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_decl_stmt
name|char
name|filler
index|[]
init|=
block|{
literal|0
block|,
literal|'\b'
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXT
name|char
name|filler
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|char
modifier|*
name|bsptr
name|INIT
argument_list|(
name|filler
operator|+
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
name|term
index|[
literal|12
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
name|gfillen
name|INIT
argument_list|(
literal|25
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|maxcmstring
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
name|cmbuffer
index|[
literal|512
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BREAKCH
value|'\0'
end_define

begin_decl_stmt
name|EXT
name|char
name|INTRCH
name|INIT
argument_list|(
literal|'\03'
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PUSHBACK
end_ifdef

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
value|(nextin!=nextout || \ (ioctl(0, FIONREAD,&iocount),(int)iocount))
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

begin_function_decl
name|int
name|circfill
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|RDCHK
end_ifdef

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
value|rdchk(0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* lint */
end_comment

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
comment|/* RDCHK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|O_NDELAY
end_ifndef

begin_comment
comment|/* assert O_NDELAY */
end_comment

begin_expr_stmt
operator|???
name|PENDING
name|isn
literal|'t defined correctly in warp.h #		endif 		EXT int devtty INIT(0); #		ifndef lint #		    define input_pending() (nextin!=nextout || circfill()) #		else #		    define input_pending() bizarre #		endif /* lint */ #	    endif /* RDCHK */ #	endif /* FIONREAD */ #   else /* PENDING */ 	??? warp won'
name|t
name|work
name|without
name|PENDING
ifndef|#
directive|ifndef
name|lint
define|#
directive|define
name|input_pending
parameter_list|()
value|(nextin!=nextout)
else|#
directive|else
define|#
directive|define
name|input_pending
parameter_list|()
value|bizarre
endif|#
directive|endif
comment|/* lint */
endif|#
directive|endif
comment|/* PENDING */
else|#
directive|else
comment|/* PUSHBACK */
ifdef|#
directive|ifdef
name|PENDING
ifdef|#
directive|ifdef
name|FIONREAD
comment|/* must have FIONREAD or O_NDELAY for input_pending() */
define|#
directive|define
name|read_tty
parameter_list|(
name|addr
parameter_list|,
name|size
parameter_list|)
value|read(0,addr,size)
ifndef|#
directive|ifndef
name|lint
define|#
directive|define
name|input_pending
parameter_list|()
value|(ioctl(0, FIONREAD,&iocount), \ (int)iocount)
else|#
directive|else
define|#
directive|define
name|input_pending
parameter_list|()
value|bizarre
endif|#
directive|endif
comment|/* lint */
name|EXT
name|long
name|iocount
name|INIT
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|RDCHK
end_ifdef

begin_comment
comment|/* actually, they can have rdchk() too */
end_comment

begin_define
define|#
directive|define
name|read_tty
parameter_list|(
name|addr
parameter_list|,
name|size
parameter_list|)
value|read(0,addr,size)
end_define

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
value|rdchk(0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* lint */
end_comment

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
comment|/* RDCHK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|O_NDELAY
end_ifndef

begin_comment
comment|/* assert O_NDELAY */
end_comment

begin_expr_stmt
operator|???
name|PENDING
name|isn
literal|'t defined correctly in warp.h #		endif 		EXT int devtty INIT(0); 		EXT bool is_input INIT(FALSE); 		EXT char pending_ch INIT(0); #		ifndef lint #		    define input_pending() (is_input || \ (is_input=read(devtty,&pending_ch,1))) #		else #		    define input_pending() bizarre #		endif /* lint */ #	    endif /* RDCHK */ #	endif /* FIONREAD */ #   else /* PENDING */ 	??? warp won'
name|t
name|work
name|without
name|PENDING
define|#
directive|define
name|read_tty
parameter_list|(
name|addr
parameter_list|,
name|size
parameter_list|)
value|read(0,addr,size)
define|#
directive|define
name|input_pending
parameter_list|()
value|(FALSE)
endif|#
directive|endif
comment|/* PENDING */
endif|#
directive|endif
comment|/* PUSHBACK */
comment|/* stuff wanted by terminal mode diddling routines */
ifdef|#
directive|ifdef
name|TERMIO
name|EXT
expr|struct
name|termio
name|_tty
operator|,
name|_oldtty
expr_stmt|;
end_expr_stmt

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
name|TERMIO
end_ifdef

begin_define
define|#
directive|define
name|raw
parameter_list|()
value|((bizarre=1),_tty.c_lflag&=~ISIG,_tty.c_cc[VMIN] = 1,ioctl(_tty_ch,TCSETAF,&_tty))
end_define

begin_define
define|#
directive|define
name|noraw
parameter_list|()
value|((bizarre=1),_tty.c_lflag |= ISIG,_tty.c_cc[VEOF] = CEOF,ioctl(_tty_ch,TCSETAF,&_tty))
end_define

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
value|((bizarre=1),_tty.c_lflag |= ICANON,_tty.c_cc[VEOF] = CEOF,ioctl(_tty_ch,TCSETAF,&_tty))
end_define

begin_define
define|#
directive|define
name|echo
parameter_list|()
value|((bizarre=1),_tty.c_lflag |= ECHO, ioctl(_tty_ch, TCSETAW,&_tty))
end_define

begin_define
define|#
directive|define
name|noecho
parameter_list|()
value|((bizarre=1),_tty.c_lflag&=~ECHO, ioctl(_tty_ch, TCSETAW,&_tty))
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TERMIO */
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
comment|/*  * NOTE: if you don't have termlib you'll have to define these strings,  *    the tputs routine, and the tgoto routine.  * The tgoto routine simply produces a cursor addressing string for a given  * x and y.  The 1st argument is a generic string to be interpreted.  * If you are hardwiring it you might just ignore the 1st argument.  * The tputs routine interprets any leading number as a padding factor, possibly  * scaled by the number of lines (2nd argument), puts out the string (1st arg)  * and the padding using the routine specified as the 3rd argument.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVETERMLIB
end_ifdef

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

begin_decl_stmt
name|EXT
name|char
modifier|*
name|myUP
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|char
modifier|*
name|ND
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* non-destructive cursor right */
end_comment

begin_decl_stmt
name|EXT
name|char
modifier|*
name|myND
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|char
modifier|*
name|DO
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* move cursor down one line */
end_comment

begin_decl_stmt
name|EXT
name|char
modifier|*
name|myDO
decl_stmt|;
end_decl_stmt

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
name|CM
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cursor motion -- PWP */
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
comment|/* home cursor -- PWP */
end_comment

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
comment|/* clear to end of display -- PWP */
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
comment|/* underline a character, if that's how it's done */
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
comment|/* does terminal have automatic margins? */
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
comment|/* does it eat 1st newline after automatic wrap? */
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

begin_decl_stmt
name|EXT
name|short
name|ospeed
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* terminal output speed, for use by tputs() */
end_comment

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

begin_decl_stmt
name|EXT
name|char
name|ERASECH
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rubout character */
end_comment

begin_decl_stmt
name|EXT
name|char
name|KILLCH
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line delete character */
end_comment

begin_comment
comment|/* define a few handy macros */
end_comment

begin_define
define|#
directive|define
name|clear
parameter_list|()
value|(do_tc(CL,LINES),real_y=real_x=0)
end_define

begin_define
define|#
directive|define
name|erase_eol
parameter_list|()
value|do_tc(CE,1)
end_define

begin_define
define|#
directive|define
name|backspace
parameter_list|()
value|(do_tc(BC,0),real_x--)
end_define

begin_define
define|#
directive|define
name|clear_rest
parameter_list|()
value|do_tc(CD,LINES)
end_define

begin_define
define|#
directive|define
name|underline
parameter_list|()
value|do_tc(US,1)
end_define

begin_define
define|#
directive|define
name|un_underline
parameter_list|()
value|do_tc(UE,1)
end_define

begin_define
define|#
directive|define
name|underchar
parameter_list|()
value|do_tc(UC,0)
end_define

begin_define
define|#
directive|define
name|standout
parameter_list|()
value|do_tc(SO,1)
end_define

begin_define
define|#
directive|define
name|un_standout
parameter_list|()
value|do_tc(SE,1)
end_define

begin_define
define|#
directive|define
name|up_line
parameter_list|()
value|do_tc(UP,1)
end_define

begin_define
define|#
directive|define
name|carriage_return
parameter_list|()
value|do_tc(CR,1)
end_define

begin_define
define|#
directive|define
name|dingaling
parameter_list|()
value|do_tc(VB,1)
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
name|void
name|term_init
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|term_set
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PUSHBACK
end_ifdef

begin_function_decl
name|void
name|pushchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_line
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|eat_typeahead
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|settle_down
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|read_tty
end_ifndef

begin_function_decl
name|int
name|read_tty
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|getcmd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_nd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|page
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|move
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_tc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|comp_tc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|helper
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rewrite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|cmstore
parameter_list|()
function_decl|;
end_function_decl

end_unit

