begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Source: /u1/X/xterm/RCS/error.h,v $  *	$Header: error.h,v 10.100 86/12/01 14:39:28 jg Rel $  */
end_comment

begin_comment
comment|/* @(#)error.h       X10/6.6B 12/26/86 */
end_comment

begin_comment
comment|/* main.c */
end_comment

begin_define
define|#
directive|define
name|ERROR_KMALLOC
value|10
end_define

begin_comment
comment|/* main: malloc() failed for keyboardtype */
end_comment

begin_define
define|#
directive|define
name|ERROR_FIONBIO
value|11
end_define

begin_comment
comment|/* main: ioctl() failed on FIONBIO */
end_comment

begin_define
define|#
directive|define
name|ERROR_TSLOT
value|12
end_define

begin_comment
comment|/* spawn: tslot() failed and getty */
end_comment

begin_define
define|#
directive|define
name|ERROR_TSLOT2
value|13
end_define

begin_comment
comment|/* spawn: tslot() failed and am_slave */
end_comment

begin_define
define|#
directive|define
name|ERROR_OPDEVTTY
value|14
end_define

begin_comment
comment|/* spawn: open() failed on /dev/tty */
end_comment

begin_define
define|#
directive|define
name|ERROR_TIOCGETP
value|15
end_define

begin_comment
comment|/* spawn: ioctl() failed on TIOCGETP */
end_comment

begin_define
define|#
directive|define
name|ERROR_TIOCGETC
value|16
end_define

begin_comment
comment|/* spawn: ioctl() failed on TIOCGETC */
end_comment

begin_define
define|#
directive|define
name|ERROR_TIOCGETD
value|17
end_define

begin_comment
comment|/* spawn: ioctl() failed on TIOCGETD */
end_comment

begin_define
define|#
directive|define
name|ERROR_TIOCGLTC
value|18
end_define

begin_comment
comment|/* spawn: ioctl() failed on TIOCGLTC */
end_comment

begin_define
define|#
directive|define
name|ERROR_TIOCLGET
value|19
end_define

begin_comment
comment|/* spawn: ioctl() failed on TIOCLGET */
end_comment

begin_define
define|#
directive|define
name|ERROR_TIOCCONS
value|20
end_define

begin_comment
comment|/* spawn: ioctl() failed on TIOCCONS */
end_comment

begin_define
define|#
directive|define
name|ERROR_OPDEVTTY2
value|21
end_define

begin_comment
comment|/* spawn: second open() failed on /dev/tty */
end_comment

begin_define
define|#
directive|define
name|ERROR_NOTTY
value|22
end_define

begin_comment
comment|/* spawn: ioctl() failed on TIOCNOTTY */
end_comment

begin_define
define|#
directive|define
name|ERROR_TIOCSETP
value|23
end_define

begin_comment
comment|/* spawn: ioctl() failed on TIOCSETP */
end_comment

begin_define
define|#
directive|define
name|ERROR_TIOCSETC
value|24
end_define

begin_comment
comment|/* spawn: ioctl() failed on TIOCSETC */
end_comment

begin_define
define|#
directive|define
name|ERROR_TIOCSETD
value|25
end_define

begin_comment
comment|/* spawn: ioctl() failed on TIOCSETD */
end_comment

begin_define
define|#
directive|define
name|ERROR_TIOCSLTC
value|26
end_define

begin_comment
comment|/* spawn: ioctl() failed on TIOCSLTC */
end_comment

begin_define
define|#
directive|define
name|ERROR_TIOCLSET
value|27
end_define

begin_comment
comment|/* spawn: ioctl() failed on TIOCLSET */
end_comment

begin_define
define|#
directive|define
name|ERROR_TSLOT3
value|28
end_define

begin_comment
comment|/* spawn: tslot() failed  */
end_comment

begin_define
define|#
directive|define
name|ERROR_FORK
value|29
end_define

begin_comment
comment|/* spawn: fork() failed */
end_comment

begin_define
define|#
directive|define
name|ERROR_EXEC
value|30
end_define

begin_comment
comment|/* spawn: exec() failed */
end_comment

begin_define
define|#
directive|define
name|ERROR_OPDEVTTY3
value|31
end_define

begin_comment
comment|/* spawn: third open() failed on /dev/tty */
end_comment

begin_define
define|#
directive|define
name|ERROR_PTYS
value|32
end_define

begin_comment
comment|/* get_pty: not enough ptys */
end_comment

begin_define
define|#
directive|define
name|ERROR_NOX
value|33
end_define

begin_comment
comment|/* get_terminal: can't connect to server */
end_comment

begin_define
define|#
directive|define
name|ERROR_NOX2
value|34
end_define

begin_comment
comment|/* get_terminal: can't connect and getty */
end_comment

begin_define
define|#
directive|define
name|ERROR_TITLEFONT
value|35
end_define

begin_comment
comment|/* get_terminal: can't open title font */
end_comment

begin_define
define|#
directive|define
name|ERROR_INIT
value|36
end_define

begin_comment
comment|/* spawn: can't initialize window */
end_comment

begin_define
define|#
directive|define
name|ERROR_NOCO
value|37
end_define

begin_comment
comment|/* resize: no `co' in termcap */
end_comment

begin_define
define|#
directive|define
name|ERROR_NOLI
value|38
end_define

begin_comment
comment|/* resize: no `li' in termcap */
end_comment

begin_define
define|#
directive|define
name|ERROR_BORDER
value|39
end_define

begin_comment
comment|/* get_terminal: can't make border tile */
end_comment

begin_define
define|#
directive|define
name|ERROR_BACK
value|40
end_define

begin_comment
comment|/* get_terminal: can't make background tile */
end_comment

begin_comment
comment|/* charproc.c */
end_comment

begin_define
define|#
directive|define
name|ERROR_SELECT
value|50
end_define

begin_comment
comment|/* in_put: select() failed */
end_comment

begin_define
define|#
directive|define
name|ERROR_CRTITLE
value|51
end_define

begin_comment
comment|/* VTTitleInit: XCreateWindow() failed */
end_comment

begin_define
define|#
directive|define
name|ERROR_HILITE
value|52
end_define

begin_comment
comment|/* VTTitleInit: make_hilite() failed */
end_comment

begin_define
define|#
directive|define
name|ERROR_CRLFRG
value|53
end_define

begin_comment
comment|/* VTTitleInit: XCreateWindows() failed */
end_comment

begin_define
define|#
directive|define
name|ERROR_VINIT
value|54
end_define

begin_comment
comment|/* VTInit: can't initialize window */
end_comment

begin_define
define|#
directive|define
name|ERROR_RTMALLOC1
value|55
end_define

begin_comment
comment|/* VTRetitle: malloc failed */
end_comment

begin_define
define|#
directive|define
name|ERROR_RTMALLOC2
value|56
end_define

begin_comment
comment|/* VTRetitle: malloc failed */
end_comment

begin_comment
comment|/* Tekproc.c */
end_comment

begin_define
define|#
directive|define
name|ERROR_TSELECT
value|60
end_define

begin_comment
comment|/* Tinput: select() failed */
end_comment

begin_define
define|#
directive|define
name|ERROR_TCRTITLE
value|61
end_define

begin_comment
comment|/* TekTitleInit: XCreateWindow() failed */
end_comment

begin_define
define|#
directive|define
name|ERROR_THILITE
value|62
end_define

begin_comment
comment|/* TekTitleInit: make_hilite() failed */
end_comment

begin_define
define|#
directive|define
name|ERROR_TCRLFRG
value|63
end_define

begin_comment
comment|/* TekTitleInit: XCreateWindows() failed */
end_comment

begin_define
define|#
directive|define
name|ERROR_TINIT
value|64
end_define

begin_comment
comment|/* TekInit: can't initialize window */
end_comment

begin_define
define|#
directive|define
name|ERROR_TBACK
value|65
end_define

begin_comment
comment|/* TekBackground: can't make background */
end_comment

begin_define
define|#
directive|define
name|ERROR_TWINNAME
value|66
end_define

begin_comment
comment|/* TekInit: malloc failed */
end_comment

begin_comment
comment|/* button.c */
end_comment

begin_define
define|#
directive|define
name|ERROR_BMALLOC
value|70
end_define

begin_comment
comment|/* GetRestOfLine: malloc() failed */
end_comment

begin_define
define|#
directive|define
name|ERROR_BMALLOC2
value|71
end_define

begin_comment
comment|/* SaltTextAway: malloc() failed */
end_comment

begin_comment
comment|/* misc.c */
end_comment

begin_define
define|#
directive|define
name|ERROR_LOGEXEC
value|80
end_define

begin_comment
comment|/* StartLog: exec() failed */
end_comment

begin_define
define|#
directive|define
name|ERROR_OPENBITMAP
value|81
end_define

begin_comment
comment|/* IconInit: XReadBitmapFile returns zero */
end_comment

begin_define
define|#
directive|define
name|ERROR_SYNTAXBITMAP
value|82
end_define

begin_comment
comment|/* IconInit: XReadBitmapFile returns negative */
end_comment

begin_define
define|#
directive|define
name|ERROR_XERROR
value|83
end_define

begin_comment
comment|/* xerror: XError event */
end_comment

begin_define
define|#
directive|define
name|ERROR_XIOERROR
value|84
end_define

begin_comment
comment|/* xioerror: X I/O error */
end_comment

begin_define
define|#
directive|define
name|ERROR_WINNAME
value|85
end_define

begin_comment
comment|/* IconInit: malloc failed */
end_comment

begin_comment
comment|/* screen.c */
end_comment

begin_define
define|#
directive|define
name|ERROR_SCALLOC
value|90
end_define

begin_comment
comment|/* Alloc: calloc() failed on base */
end_comment

begin_define
define|#
directive|define
name|ERROR_SCALLOC2
value|91
end_define

begin_comment
comment|/* Alloc: calloc() failed on rows */
end_comment

begin_define
define|#
directive|define
name|ERROR_SREALLOC
value|92
end_define

begin_comment
comment|/* ScreenResize: realloc() failed on alt base */
end_comment

begin_define
define|#
directive|define
name|ERROR_SREALLOC2
value|93
end_define

begin_comment
comment|/* ScreenResize: realloc() failed on alt rows */
end_comment

begin_define
define|#
directive|define
name|ERROR_SREALLOC3
value|94
end_define

begin_comment
comment|/* ScreenResize: realloc() failed on rows */
end_comment

begin_define
define|#
directive|define
name|ERROR_SREALLOC4
value|95
end_define

begin_comment
comment|/* ScreenResize: realloc() failed on rows */
end_comment

begin_define
define|#
directive|define
name|ERROR_RESIZE
value|96
end_define

begin_comment
comment|/* ScreenResize: malloc() or realloc() failed */
end_comment

begin_define
define|#
directive|define
name|ERROR_RESIZE2
value|97
end_define

begin_comment
comment|/* ScreenResize: malloc() or realloc() failed */
end_comment

begin_define
define|#
directive|define
name|ERROR_RESIZROW
value|98
end_define

begin_comment
comment|/* ScreenResize: realloc() failed on alt char */
end_comment

begin_define
define|#
directive|define
name|ERROR_RESIZROW2
value|99
end_define

begin_comment
comment|/* ScreenResize: realloc() failed on alt attr */
end_comment

begin_define
define|#
directive|define
name|ERROR_RESIZROW3
value|100
end_define

begin_comment
comment|/* ScreenResize: realloc() failed on attr */
end_comment

begin_define
define|#
directive|define
name|ERROR_RESIZROW4
value|101
end_define

begin_comment
comment|/* ScreenResize: realloc() failed on attr */
end_comment

begin_comment
comment|/* scrollbar.c */
end_comment

begin_define
define|#
directive|define
name|ERROR_SBRALLOC
value|110
end_define

begin_comment
comment|/* ScrollBarOn: realloc() failed on base */
end_comment

begin_define
define|#
directive|define
name|ERROR_SBRALLOC2
value|111
end_define

begin_comment
comment|/* ScrollBarOn: realloc() failed on rows */
end_comment

begin_comment
comment|/* util.c */
end_comment

begin_define
define|#
directive|define
name|ERROR_UBACK
value|120
end_define

begin_comment
comment|/* ReverseVideo: can't make background */
end_comment

end_unit

