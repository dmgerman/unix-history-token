begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Source: /u1/X/xterm/RCS/main.h,v $  *	$Header: main.h,v 10.100 86/12/01 14:39:34 jg Rel $  */
end_comment

begin_comment
comment|/* @(#)main.h	1.8 (Berkeley/CSRG) 10/29/87 */
end_comment

begin_comment
comment|/* @(#)main.h       X10/6.6B 12/28/86 */
end_comment

begin_define
define|#
directive|define
name|DEF_ACTIVEICON
value|0
end_define

begin_define
define|#
directive|define
name|DEF_ALLOWICONINPUT
value|(DEF_ACTIVEICON+1)
end_define

begin_define
define|#
directive|define
name|DEF_AUTORAISE
value|(DEF_ALLOWICONINPUT+1)
end_define

begin_define
define|#
directive|define
name|DEF_BACKGROUND
value|(DEF_AUTORAISE+1)
end_define

begin_define
define|#
directive|define
name|DEF_BODYFONT
value|(DEF_BACKGROUND+1)
end_define

begin_define
define|#
directive|define
name|DEF_BOLDFONT
value|(DEF_BODYFONT+1)
end_define

begin_define
define|#
directive|define
name|DEF_BORDER
value|(DEF_BOLDFONT+1)
end_define

begin_define
define|#
directive|define
name|DEF_BORDERWIDTH
value|(DEF_BORDER+1)
end_define

begin_define
define|#
directive|define
name|DEF_C132
value|(DEF_BORDERWIDTH+1)
end_define

begin_define
define|#
directive|define
name|DEF_CURSES
value|(DEF_C132+1)
end_define

begin_define
define|#
directive|define
name|DEF_CURSOR
value|(DEF_CURSES+1)
end_define

begin_define
define|#
directive|define
name|DEF_CURSORSHAPE
value|(DEF_CURSOR+1)
end_define

begin_define
define|#
directive|define
name|DEF_DEICONWARP
value|(DEF_CURSORSHAPE+1)
end_define

begin_define
define|#
directive|define
name|DEF_FOREGROUND
value|(DEF_DEICONWARP+1)
end_define

begin_define
define|#
directive|define
name|DEF_GRAYBORDER
value|(DEF_FOREGROUND+1)
end_define

begin_define
define|#
directive|define
name|DEF_ICONBITMAP
value|(DEF_GRAYBORDER+1)
end_define

begin_define
define|#
directive|define
name|DEF_ICONFONT
value|(DEF_ICONBITMAP+1)
end_define

begin_define
define|#
directive|define
name|DEF_ICONSTARTUP
value|(DEF_ICONFONT+1)
end_define

begin_define
define|#
directive|define
name|DEF_INTERNALBORDER
value|(DEF_ICONSTARTUP+1)
end_define

begin_define
define|#
directive|define
name|DEF_JUMPSCROLL
value|(DEF_INTERNALBORDER+1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KEYBD
end_ifdef

begin_define
define|#
directive|define
name|DEF_KEYBOARD
value|(DEF_JUMPSCROLL+1)
end_define

begin_define
define|#
directive|define
name|DEF_LOGFILE
value|(DEF_KEYBOARD+1)
end_define

begin_else
else|#
directive|else
else|KEYBD
end_else

begin_define
define|#
directive|define
name|DEF_LOGFILE
value|(DEF_JUMPSCROLL+1)
end_define

begin_endif
endif|#
directive|endif
endif|KEYBD
end_endif

begin_define
define|#
directive|define
name|DEF_LOGGING
value|(DEF_LOGFILE+1)
end_define

begin_define
define|#
directive|define
name|DEF_LOGINHIBIT
value|(DEF_LOGGING+1)
end_define

begin_define
define|#
directive|define
name|DEF_LOGINSHELL
value|(DEF_LOGINHIBIT+1)
end_define

begin_define
define|#
directive|define
name|DEF_MARGINBELL
value|(DEF_LOGINSHELL+1)
end_define

begin_define
define|#
directive|define
name|DEF_MOUSE
value|(DEF_MARGINBELL+1)
end_define

begin_define
define|#
directive|define
name|DEF_NMARGINBELL
value|(DEF_MOUSE+1)
end_define

begin_define
define|#
directive|define
name|DEF_PAGEOVERLAP
value|(DEF_NMARGINBELL+1)
end_define

begin_define
define|#
directive|define
name|DEF_PAGESCROLL
value|(DEF_PAGEOVERLAP+1)
end_define

begin_define
define|#
directive|define
name|DEF_REVERSEVIDEO
value|(DEF_PAGESCROLL+1)
end_define

begin_define
define|#
directive|define
name|DEF_REVERSEWRAP
value|(DEF_REVERSEVIDEO+1)
end_define

begin_define
define|#
directive|define
name|DEF_SAVELINES
value|(DEF_REVERSEWRAP+1)
end_define

begin_define
define|#
directive|define
name|DEF_SCROLLBAR
value|(DEF_SAVELINES+1)
end_define

begin_define
define|#
directive|define
name|DEF_SCROLLINPUT
value|(DEF_SCROLLBAR+1)
end_define

begin_define
define|#
directive|define
name|DEF_SCROLLKEY
value|(DEF_SCROLLINPUT+1)
end_define

begin_define
define|#
directive|define
name|DEF_SIGNALINHIBIT
value|(DEF_SCROLLKEY+1)
end_define

begin_define
define|#
directive|define
name|DEF_STATUSLINE
value|(DEF_SIGNALINHIBIT+1)
end_define

begin_define
define|#
directive|define
name|DEF_STATUSNORMAL
value|(DEF_STATUSLINE+1)
end_define

begin_define
define|#
directive|define
name|DEF_TEKICONBITMAP
value|(DEF_STATUSNORMAL+1)
end_define

begin_define
define|#
directive|define
name|DEF_TEKINHIBIT
value|(DEF_TEKICONBITMAP+1)
end_define

begin_define
define|#
directive|define
name|DEF_TEXTUNDERICON
value|(DEF_TEKINHIBIT+1)
end_define

begin_define
define|#
directive|define
name|DEF_TITLEBAR
value|(DEF_TEXTUNDERICON+1)
end_define

begin_define
define|#
directive|define
name|DEF_TITLEFONT
value|(DEF_TITLEBAR+1)
end_define

begin_define
define|#
directive|define
name|DEF_VISUALBELL
value|(DEF_TITLEFONT+1)
end_define

begin_define
define|#
directive|define
name|DEF_VISBELLDELAY
value|(DEF_VISUALBELL+1)
end_define

begin_define
define|#
directive|define
name|DEF_AUDIBLEBELL
value|(DEF_VISBELLDELAY+1)
end_define

begin_define
define|#
directive|define
name|DEF_DROPMENU
value|(DEF_AUDIBLEBELL+1)
end_define

begin_define
define|#
directive|define
name|DEF_UNIQUESUFFIX
value|(DEF_DROPMENU+1)
end_define

begin_define
define|#
directive|define
name|DEF_UNSHIFTEDSELECTION
value|(DEF_UNIQUESUFFIX+1)
end_define

begin_define
define|#
directive|define
name|ARG_132
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCCONS
end_ifdef

begin_define
define|#
directive|define
name|ARG__C
value|(ARG_132+1)
end_define

begin_endif
endif|#
directive|endif
endif|TIOCCONS
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ARG__C
end_ifdef

begin_define
define|#
directive|define
name|ARG__L
value|(ARG__C+1)
end_define

begin_else
else|#
directive|else
else|ARG__C
end_else

begin_define
define|#
directive|define
name|ARG__L
value|(ARG_132+1)
end_define

begin_endif
endif|#
directive|endif
endif|ARG__C
end_endif

begin_define
define|#
directive|define
name|ARG__S
value|(ARG__L+1)
end_define

begin_define
define|#
directive|define
name|ARG_AI
value|(ARG__S+1)
end_define

begin_define
define|#
directive|define
name|ARG_AR
value|(ARG_AI+1)
end_define

begin_define
define|#
directive|define
name|ARG_B
value|(ARG_AR+1)
end_define

begin_define
define|#
directive|define
name|ARG_BD
value|(ARG_B+1)
end_define

begin_define
define|#
directive|define
name|ARG_BG
value|(ARG_BD+1)
end_define

begin_define
define|#
directive|define
name|ARG_BW
value|(ARG_BG+1)
end_define

begin_define
define|#
directive|define
name|ARG_CR
value|(ARG_BW+1)
end_define

begin_define
define|#
directive|define
name|ARG_CU
value|(ARG_CR+1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ARG_D
value|(ARG_CU+1)
end_define

begin_define
define|#
directive|define
name|ARG_DW
value|(ARG_D+1)
end_define

begin_else
else|#
directive|else
else|DEBUG
end_else

begin_define
define|#
directive|define
name|ARG_DW
value|(ARG_CU+1)
end_define

begin_endif
endif|#
directive|endif
endif|DEBUG
end_endif

begin_define
define|#
directive|define
name|ARG_E
value|(ARG_DW+1)
end_define

begin_define
define|#
directive|define
name|ARG_FB
value|(ARG_E+1)
end_define

begin_define
define|#
directive|define
name|ARG_FG
value|(ARG_FB+1)
end_define

begin_define
define|#
directive|define
name|ARG_FI
value|(ARG_FG+1)
end_define

begin_define
define|#
directive|define
name|ARG_FN
value|(ARG_FI+1)
end_define

begin_define
define|#
directive|define
name|ARG_FT
value|(ARG_FN+1)
end_define

begin_define
define|#
directive|define
name|ARG_I
value|(ARG_FT+1)
end_define

begin_define
define|#
directive|define
name|ARG_IB
value|(ARG_I+1)
end_define

begin_define
define|#
directive|define
name|ARG_IT
value|(ARG_IB+1)
end_define

begin_define
define|#
directive|define
name|ARG_J
value|(ARG_IT+1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KEYBD
end_ifdef

begin_define
define|#
directive|define
name|ARG_K
value|(ARG_J+1)
end_define

begin_define
define|#
directive|define
name|ARG_L
value|(ARG_K+1)
end_define

begin_else
else|#
directive|else
else|KEYBD
end_else

begin_define
define|#
directive|define
name|ARG_L
value|(ARG_J+1)
end_define

begin_endif
endif|#
directive|endif
endif|KEYBD
end_endif

begin_define
define|#
directive|define
name|ARG_LF
value|(ARG_L+1)
end_define

begin_define
define|#
directive|define
name|ARG_LS
value|(ARG_LF+1)
end_define

begin_define
define|#
directive|define
name|ARG_MB
value|(ARG_LS+1)
end_define

begin_define
define|#
directive|define
name|ARG_MS
value|(ARG_MB+1)
end_define

begin_define
define|#
directive|define
name|ARG_N
value|(ARG_MS+1)
end_define

begin_define
define|#
directive|define
name|ARG_NB
value|(ARG_N+1)
end_define

begin_define
define|#
directive|define
name|ARG_PO
value|(ARG_NB+1)
end_define

begin_define
define|#
directive|define
name|ARG_PS
value|(ARG_PO+1)
end_define

begin_define
define|#
directive|define
name|ARG_RV
value|(ARG_PS+1)
end_define

begin_define
define|#
directive|define
name|ARG_RW
value|(ARG_RV+1)
end_define

begin_define
define|#
directive|define
name|ARG_S
value|(ARG_RW+1)
end_define

begin_define
define|#
directive|define
name|ARG_SB
value|(ARG_S+1)
end_define

begin_define
define|#
directive|define
name|ARG_SI
value|(ARG_SB+1)
end_define

begin_define
define|#
directive|define
name|ARG_SK
value|(ARG_SI+1)
end_define

begin_define
define|#
directive|define
name|ARG_SL
value|(ARG_SK+1)
end_define

begin_define
define|#
directive|define
name|ARG_SN
value|(ARG_SL+1)
end_define

begin_define
define|#
directive|define
name|ARG_ST
value|(ARG_SN+1)
end_define

begin_define
define|#
directive|define
name|ARG_T
value|(ARG_ST+1)
end_define

begin_define
define|#
directive|define
name|ARG_TB
value|(ARG_T+1)
end_define

begin_define
define|#
directive|define
name|ARG_TI
value|(ARG_TB+1)
end_define

begin_define
define|#
directive|define
name|ARG_VB
value|(ARG_TI+1)
end_define

begin_define
define|#
directive|define
name|ARG_VD
value|(ARG_VB+1)
end_define

begin_define
define|#
directive|define
name|ARG_AB
value|(ARG_VD+1)
end_define

begin_define
define|#
directive|define
name|DEFBOLDFONT
value|"vtbold"
end_define

begin_define
define|#
directive|define
name|DEFBORDER
value|1
end_define

begin_define
define|#
directive|define
name|DEFBORDERWIDTH
value|2
end_define

begin_define
define|#
directive|define
name|DEFFONT
value|"vtsingle"
end_define

begin_define
define|#
directive|define
name|DEFICONFONT
value|"nil2"
end_define

begin_define
define|#
directive|define
name|DEFTITLEFONT
value|"vtsingle"
end_define

begin_define
define|#
directive|define
name|VISBELLDELAY
value|100
end_define

begin_comment
comment|/* milliseconds */
end_comment

end_unit

