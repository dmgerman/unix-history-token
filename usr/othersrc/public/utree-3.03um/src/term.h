begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *      TERM.H  *      UTREE terminal and screen definitions.  *      3.01-um klin, Wed May  1 14:34:34 1991  *              klin, Sat Oct 26 15:27:00 1991, Some additions  *      3.02-um klin, Fri Nov  1 10:44:45 1991, Screen layout changed  *              klin, Sun Nov 24 15:12:48 1991, Video attributes changed  *      3.03-um klin, Tue Feb 11 19:39:09 1992, Video attributes changed  *            e klin, Sat Apr 11 11:05:54 1992, Use colors for video attributes  *  *      Copyright (c) 1991/92 by Peter Klingebiel& UNIX Magazin Muenchen.  *      For copying and distribution information see the file COPYRIGHT.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MAIN_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid_term
index|[]
init|=
literal|"@(#) utree 3.03e-um (klin) Apr 1992 term.h"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MAIN_&& !lint */
end_comment

begin_define
define|#
directive|define
name|MINCOLS
value|80
end_define

begin_comment
comment|/* Min number of screen columns needed  */
end_comment

begin_define
define|#
directive|define
name|MINLINS
value|24
end_define

begin_comment
comment|/* Min number of screen lines needed    */
end_comment

begin_comment
comment|/* Return values from getline()                                         */
end_comment

begin_define
define|#
directive|define
name|EMPTY
value|0
end_define

begin_comment
comment|/* Input is empty                       */
end_comment

begin_define
define|#
directive|define
name|DONE
value|1
end_define

begin_comment
comment|/* Input not empty and ok               */
end_comment

begin_comment
comment|/* Video attribute flags                                                */
end_comment

begin_define
define|#
directive|define
name|VA_NORMAL
value|0x00
end_define

begin_comment
comment|/* Reset all video attributes           */
end_comment

begin_define
define|#
directive|define
name|VA_REVERSE
value|0x01
end_define

begin_comment
comment|/* Video reverse   attribute            */
end_comment

begin_define
define|#
directive|define
name|VA_BLINK
value|0x02
end_define

begin_comment
comment|/* Video blink     attribute            */
end_comment

begin_define
define|#
directive|define
name|VA_HALF
value|0x04
end_define

begin_comment
comment|/* Half bright     attribute            */
end_comment

begin_define
define|#
directive|define
name|VA_BOLD
value|0x08
end_define

begin_comment
comment|/* Video bold      attribute            */
end_comment

begin_define
define|#
directive|define
name|VA_UNDERLINE
value|0x10
end_define

begin_comment
comment|/* Video underline attribute            */
end_comment

begin_comment
comment|/* Cursor functions                                                     */
end_comment

begin_define
define|#
directive|define
name|CF_VISIBLE
value|0x01
end_define

begin_comment
comment|/* Cursor visible                       */
end_comment

begin_define
define|#
directive|define
name|CF_INVISIBLE
value|0x02
end_define

begin_comment
comment|/* Cursor invisible                     */
end_comment

begin_define
define|#
directive|define
name|CF_SAVE
value|0x04
end_define

begin_comment
comment|/* Save cursor position                 */
end_comment

begin_define
define|#
directive|define
name|CF_RESTORE
value|0x08
end_define

begin_comment
comment|/* Restore cursor position              */
end_comment

begin_comment
comment|/* Keypad functions                                                     */
end_comment

begin_define
define|#
directive|define
name|KP_NORMAL
value|0x00
end_define

begin_comment
comment|/* Switch keypad to normal mode         */
end_comment

begin_define
define|#
directive|define
name|KP_XMIT
value|0x01
end_define

begin_comment
comment|/* Switch keypad to transmit mode       */
end_comment

begin_comment
comment|/* Graphical charset functions                                          */
end_comment

begin_define
define|#
directive|define
name|GC_OFF
value|0x00
end_define

begin_comment
comment|/* Turn off graph charset               */
end_comment

begin_define
define|#
directive|define
name|GC_ON
value|0x01
end_define

begin_comment
comment|/* Turn on graph charset                */
end_comment

begin_comment
comment|/* The graph charset is accessed and hidden by the following macros     */
end_comment

begin_define
define|#
directive|define
name|GC_HB
value|_graphset[0]
end_define

begin_comment
comment|/* Horizontal bar                       */
end_comment

begin_define
define|#
directive|define
name|GC_VB
value|_graphset[1]
end_define

begin_comment
comment|/* Vertical bar                         */
end_comment

begin_define
define|#
directive|define
name|GC_LT
value|_graphset[2]
end_define

begin_comment
comment|/* Left tee                             */
end_comment

begin_define
define|#
directive|define
name|GC_RT
value|_graphset[3]
end_define

begin_comment
comment|/* Right tree                           */
end_comment

begin_define
define|#
directive|define
name|GC_TT
value|_graphset[4]
end_define

begin_comment
comment|/* Top tee                              */
end_comment

begin_define
define|#
directive|define
name|GC_BT
value|_graphset[5]
end_define

begin_comment
comment|/* Bottom tee                           */
end_comment

begin_define
define|#
directive|define
name|GC_UL
value|_graphset[6]
end_define

begin_comment
comment|/* Upper left corner                    */
end_comment

begin_define
define|#
directive|define
name|GC_LL
value|_graphset[7]
end_define

begin_comment
comment|/* Lower left corner                    */
end_comment

begin_define
define|#
directive|define
name|GC_UR
value|_graphset[8]
end_define

begin_comment
comment|/* Upper right corner                   */
end_comment

begin_define
define|#
directive|define
name|GC_LR
value|_graphset[9]
end_define

begin_comment
comment|/* Lower right corner                   */
end_comment

begin_define
define|#
directive|define
name|GC_TG
value|_graphset[10]
end_define

begin_comment
comment|/* Tag sign (diamond or plus)           */
end_comment

begin_define
define|#
directive|define
name|NGRAPH
value|11
end_define

begin_comment
comment|/* Max number of graphic characters     */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USEANSICOLORS
end_ifdef

begin_define
define|#
directive|define
name|CS_BLACK
value|0
end_define

begin_comment
comment|/* Ansi compatible color codes          */
end_comment

begin_define
define|#
directive|define
name|CS_RED
value|1
end_define

begin_define
define|#
directive|define
name|CS_GREEN
value|2
end_define

begin_define
define|#
directive|define
name|CS_BROWN
value|3
end_define

begin_define
define|#
directive|define
name|CS_BLUE
value|4
end_define

begin_define
define|#
directive|define
name|CS_MAGENTA
value|5
end_define

begin_define
define|#
directive|define
name|CS_CYAN
value|6
end_define

begin_define
define|#
directive|define
name|CS_WHITE
value|7
end_define

begin_define
define|#
directive|define
name|CS_INIT
value|-1
end_define

begin_define
define|#
directive|define
name|CS_RESET
value|-2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USEANSICOLORS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MAIN_
end_ifdef

begin_decl_stmt
name|int
name|columns
decl_stmt|,
name|lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of screen columns and lines   */
end_comment

begin_decl_stmt
name|int
name|glitchcap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Standout mode/underline glitch flag  */
end_comment

begin_decl_stmt
name|int
name|scrollcap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Window/scrolling capabilities flag   */
end_comment

begin_decl_stmt
name|int
name|cursorcap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cursor capabilities                  */
end_comment

begin_decl_stmt
name|int
name|videocap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Video capabilities flag              */
end_comment

begin_decl_stmt
name|int
name|graphcap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Graphic character set flag           */
end_comment

begin_decl_stmt
name|char
name|_graphset
index|[
name|NGRAPH
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Graphic character set                */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USEANSICOLORS
end_ifdef

begin_decl_stmt
name|int
name|colorcap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Can colors                           */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USEANSICOLORS */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_MAIN_ */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|columns
decl_stmt|,
name|lines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|glitchcap
decl_stmt|,
name|scrollcap
decl_stmt|,
name|cursorcap
decl_stmt|,
name|videocap
decl_stmt|,
name|graphcap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|_graphset
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USEANSICOLORS
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|colorcap
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USEANSICOLORS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MAIN_ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|putchar
end_ifdef

begin_comment
comment|/* Don't use stdio.h's putchar macro    */
end_comment

begin_undef
undef|#
directive|undef
name|putchar
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|getchar
end_ifdef

begin_comment
comment|/* Don't use stdio.h's getchar macro    */
end_comment

begin_undef
undef|#
directive|undef
name|getchar
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

