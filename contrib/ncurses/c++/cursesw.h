begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// * This makes emacs happy -*-Mode: C++;-*-
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CURSESW_H
end_ifndef

begin_define
define|#
directive|define
name|_CURSESW_H
end_define

begin_comment
comment|// $Id: cursesw.h,v 1.18 1999/10/23 15:16:53 tom Exp $
end_comment

begin_include
include|#
directive|include
file|<etip.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__MWERKS__
end_ifdef

begin_comment
comment|/* This is a bogus check, stringstream is actually ANSI C++ standard,  * but old compilers like GCC don't have it, and new compilers like Metrowerks  * don't have strstream  */
end_comment

begin_include
include|#
directive|include
file|<sstream>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strstream.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern
literal|"C"
block|{
include|#
directive|include
file|<curses.h>
block|}
end_extern

begin_comment
comment|/* SCO 3.2v4 curses.h includes term.h, which defines lines as a macro.    Undefine it here, because NCursesWindow uses lines as a method.  */
end_comment

begin_undef
undef|#
directive|undef
name|lines
end_undef

begin_comment
comment|/* "Convert" macros to inlines. We'll define it as another symbol to avoid  * conflict with library symbols.  */
end_comment

begin_undef
undef|#
directive|undef
name|UNDEF
end_undef

begin_define
define|#
directive|define
name|UNDEF
parameter_list|(
name|name
parameter_list|)
value|CUR_ ##name
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|addch
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|addch
function|)
parameter_list|(
name|chtype
name|ch
parameter_list|)
block|{
return|return
name|addch
argument_list|(
name|ch
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|addch
end_undef

begin_define
define|#
directive|define
name|addch
value|UNDEF(addch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|echochar
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|echochar
function|)
parameter_list|(
name|chtype
name|ch
parameter_list|)
block|{
return|return
name|echochar
argument_list|(
name|ch
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|echochar
end_undef

begin_define
define|#
directive|define
name|echochar
value|UNDEF(echochar)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|insdelln
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|insdelln
function|)
parameter_list|(
name|int
name|n
parameter_list|)
block|{
return|return
name|insdelln
argument_list|(
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|insdelln
end_undef

begin_define
define|#
directive|define
name|insdelln
value|UNDEF(insdelln)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|addstr
end_ifdef

begin_comment
comment|/* The (char*) cast is to hack around missing const's */
end_comment

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|addstr
function|)
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
return|return
name|addstr
argument_list|(
operator|(
name|char
operator|*
operator|)
name|str
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|addstr
end_undef

begin_define
define|#
directive|define
name|addstr
value|UNDEF(addstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|attron
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|attron
function|)
parameter_list|(
name|chtype
name|at
parameter_list|)
block|{
return|return
name|attron
argument_list|(
name|at
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|attron
end_undef

begin_define
define|#
directive|define
name|attron
value|UNDEF(attron)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|attroff
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|attroff
function|)
parameter_list|(
name|chtype
name|at
parameter_list|)
block|{
return|return
name|attroff
argument_list|(
name|at
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|attroff
end_undef

begin_define
define|#
directive|define
name|attroff
value|UNDEF(attroff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|attrset
end_ifdef

begin_function
specifier|inline
name|chtype
name|UNDEF
function|(
name|attrset
function|)
parameter_list|(
name|chtype
name|at
parameter_list|)
block|{
return|return
name|attrset
argument_list|(
name|at
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|attrset
end_undef

begin_define
define|#
directive|define
name|attrset
value|UNDEF(attrset)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|color_set
end_ifdef

begin_function
specifier|inline
name|chtype
name|UNDEF
function|(
name|color_set
function|)
parameter_list|(
name|short
name|p
parameter_list|,
name|void
modifier|*
name|opts
parameter_list|)
block|{
return|return
name|color_set
argument_list|(
name|p
argument_list|,
name|opts
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|color_set
end_undef

begin_define
define|#
directive|define
name|color_set
value|UNDEF(color_set)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|border
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|border
function|)
parameter_list|(
name|chtype
name|ls
parameter_list|,
name|chtype
name|rs
parameter_list|,
name|chtype
name|ts
parameter_list|,
name|chtype
name|bs
parameter_list|,
name|chtype
name|tl
parameter_list|,
name|chtype
name|tr
parameter_list|,
name|chtype
name|bl
parameter_list|,
name|chtype
name|br
parameter_list|)
block|{
return|return
name|border
argument_list|(
name|ls
argument_list|,
name|rs
argument_list|,
name|ts
argument_list|,
name|bs
argument_list|,
name|tl
argument_list|,
name|tr
argument_list|,
name|bl
argument_list|,
name|br
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|border
end_undef

begin_define
define|#
directive|define
name|border
value|UNDEF(border)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|box
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|box
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|v
parameter_list|,
name|int
name|h
parameter_list|)
block|{
return|return
name|box
argument_list|(
name|win
argument_list|,
name|v
argument_list|,
name|h
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|box
end_undef

begin_define
define|#
directive|define
name|box
value|UNDEF(box)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwhline
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvwhline
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|chtype
name|c
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|mvwhline
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|c
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwhline
end_undef

begin_define
define|#
directive|define
name|mvwhline
value|UNDEF(mvwhline)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwvline
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvwvline
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|chtype
name|c
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|mvwvline
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|c
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwvline
end_undef

begin_define
define|#
directive|define
name|mvwvline
value|UNDEF(mvwvline)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|clear
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|clear
function|)
parameter_list|()
block|{
return|return
name|clear
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|clear
end_undef

begin_define
define|#
directive|define
name|clear
value|UNDEF(clear)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|clearok
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|clearok
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|bool
name|bf
parameter_list|)
block|{
return|return
name|clearok
argument_list|(
name|win
argument_list|,
name|bf
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|clearok
end_undef

begin_define
define|#
directive|define
name|clearok
value|UNDEF(clearok)
end_define

begin_else
else|#
directive|else
end_else

begin_extern
extern|extern
literal|"C"
name|int
name|clearok
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|clrtobot
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|clrtobot
function|)
parameter_list|()
block|{
return|return
name|clrtobot
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|clrtobot
end_undef

begin_define
define|#
directive|define
name|clrtobot
value|UNDEF(clrtobot)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|clrtoeol
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|clrtoeol
function|)
parameter_list|()
block|{
return|return
name|clrtoeol
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|clrtoeol
end_undef

begin_define
define|#
directive|define
name|clrtoeol
value|UNDEF(clrtoeol)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|delch
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|delch
function|)
parameter_list|()
block|{
return|return
name|delch
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|delch
end_undef

begin_define
define|#
directive|define
name|delch
value|UNDEF(delch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|deleteln
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|deleteln
function|)
parameter_list|()
block|{
return|return
name|deleteln
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|deleteln
end_undef

begin_define
define|#
directive|define
name|deleteln
value|UNDEF(deleteln)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|erase
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|erase
function|)
parameter_list|()
block|{
return|return
name|erase
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|erase
end_undef

begin_define
define|#
directive|define
name|erase
value|UNDEF(erase)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|flushok
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|flushok
function|)
parameter_list|(
name|WINDOW
modifier|*
name|_win
parameter_list|,
name|bool
name|_bf
parameter_list|)
block|{
return|return
name|flushok
argument_list|(
name|_win
argument_list|,
name|_bf
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|flushok
end_undef

begin_define
define|#
directive|define
name|flushok
value|UNDEF(flushok)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_no_flushok
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|getch
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|getch
function|)
parameter_list|()
block|{
return|return
name|getch
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|getch
end_undef

begin_define
define|#
directive|define
name|getch
value|UNDEF(getch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|getstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|getstr
function|)
parameter_list|(
name|char
modifier|*
name|_str
parameter_list|)
block|{
return|return
name|getstr
argument_list|(
name|_str
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|getstr
end_undef

begin_define
define|#
directive|define
name|getstr
value|UNDEF(getstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|instr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|instr
function|)
parameter_list|(
name|char
modifier|*
name|_str
parameter_list|)
block|{
return|return
name|instr
argument_list|(
name|_str
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|instr
end_undef

begin_define
define|#
directive|define
name|instr
value|UNDEF(instr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|innstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|innstr
function|)
parameter_list|(
name|char
modifier|*
name|_str
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|innstr
argument_list|(
name|_str
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|innstr
end_undef

begin_define
define|#
directive|define
name|innstr
value|UNDEF(innstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwinnstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvwinnstr
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|char
modifier|*
name|_str
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|mvwinnstr
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|_str
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwinnstr
end_undef

begin_define
define|#
directive|define
name|mvwinnstr
value|UNDEF(mvwinnstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvinnstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvinnstr
function|)
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|char
modifier|*
name|_str
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|mvinnstr
argument_list|(
name|y
argument_list|,
name|x
argument_list|,
name|_str
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvinnstr
end_undef

begin_define
define|#
directive|define
name|mvinnstr
value|UNDEF(mvinnstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|winsstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|winsstr
function|)
parameter_list|(
name|WINDOW
modifier|*
name|w
parameter_list|,
specifier|const
name|char
modifier|*
name|_str
parameter_list|)
block|{
return|return
name|winsstr
argument_list|(
name|w
argument_list|,
name|_str
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|winsstr
end_undef

begin_define
define|#
directive|define
name|winsstr
value|UNDEF(winsstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwinsstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvwinsstr
function|)
parameter_list|(
name|WINDOW
modifier|*
name|w
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
specifier|const
name|char
modifier|*
name|_str
parameter_list|)
block|{
return|return
name|mvwinsstr
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|_str
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwinsstr
end_undef

begin_define
define|#
directive|define
name|mvwinsstr
value|UNDEF(mvwinsstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|insstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|insstr
function|)
parameter_list|(
specifier|const
name|char
modifier|*
name|_str
parameter_list|)
block|{
return|return
name|insstr
argument_list|(
name|_str
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|insstr
end_undef

begin_define
define|#
directive|define
name|insstr
value|UNDEF(insstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvinsstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvinsstr
function|)
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
specifier|const
name|char
modifier|*
name|_str
parameter_list|)
block|{
return|return
name|mvinsstr
argument_list|(
name|y
argument_list|,
name|x
argument_list|,
name|_str
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvinsstr
end_undef

begin_define
define|#
directive|define
name|mvinsstr
value|UNDEF(mvinsstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|insnstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|insnstr
function|)
parameter_list|(
specifier|const
name|char
modifier|*
name|_str
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|insnstr
argument_list|(
name|_str
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|insnstr
end_undef

begin_define
define|#
directive|define
name|insnstr
value|UNDEF(insnstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwinsnstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvwinsnstr
function|)
parameter_list|(
name|WINDOW
modifier|*
name|w
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
specifier|const
name|char
modifier|*
name|_str
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|mvwinsnstr
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|_str
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwinsnstr
end_undef

begin_define
define|#
directive|define
name|mvwinsnstr
value|UNDEF(mvwinsnstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvinsnstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvinsnstr
function|)
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
specifier|const
name|char
modifier|*
name|_str
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|mvinsnstr
argument_list|(
name|y
argument_list|,
name|x
argument_list|,
name|_str
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvinsnstr
end_undef

begin_define
define|#
directive|define
name|mvinsnstr
value|UNDEF(mvinsnstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|getnstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|getnstr
function|)
parameter_list|(
name|char
modifier|*
name|_str
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|getnstr
argument_list|(
name|_str
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|getnstr
end_undef

begin_define
define|#
directive|define
name|getnstr
value|UNDEF(getnstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|getyx
end_ifdef

begin_function
specifier|inline
name|void
name|UNDEF
function|(
name|getyx
function|)
parameter_list|(
specifier|const
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
modifier|&
name|y
parameter_list|,
name|int
modifier|&
name|x
parameter_list|)
block|{
name|getyx
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|getyx
end_undef

begin_define
define|#
directive|define
name|getyx
value|UNDEF(getyx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|getbegyx
end_ifdef

begin_function
specifier|inline
name|void
name|UNDEF
function|(
name|getbegyx
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
modifier|&
name|y
parameter_list|,
name|int
modifier|&
name|x
parameter_list|)
block|{
name|getbegyx
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|getbegyx
end_undef

begin_define
define|#
directive|define
name|getbegyx
value|UNDEF(getbegyx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|getmaxyx
end_ifdef

begin_function
specifier|inline
name|void
name|UNDEF
function|(
name|getmaxyx
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
modifier|&
name|y
parameter_list|,
name|int
modifier|&
name|x
parameter_list|)
block|{
name|getmaxyx
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|getmaxyx
end_undef

begin_define
define|#
directive|define
name|getmaxyx
value|UNDEF(getmaxyx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|hline
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|hline
function|)
parameter_list|(
name|chtype
name|ch
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|hline
argument_list|(
name|ch
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|hline
end_undef

begin_define
define|#
directive|define
name|hline
value|UNDEF(hline)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|inch
end_ifdef

begin_function
specifier|inline
name|chtype
name|UNDEF
function|(
name|inch
function|)
parameter_list|()
block|{
return|return
name|inch
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|inch
end_undef

begin_define
define|#
directive|define
name|inch
value|UNDEF(inch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|insch
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|insch
function|)
parameter_list|(
name|char
name|c
parameter_list|)
block|{
return|return
name|insch
argument_list|(
name|c
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|insch
end_undef

begin_define
define|#
directive|define
name|insch
value|UNDEF(insch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|insertln
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|insertln
function|)
parameter_list|()
block|{
return|return
name|insertln
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|insertln
end_undef

begin_define
define|#
directive|define
name|insertln
value|UNDEF(insertln)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|leaveok
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|leaveok
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|bool
name|bf
parameter_list|)
block|{
return|return
name|leaveok
argument_list|(
name|win
argument_list|,
name|bf
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|leaveok
end_undef

begin_define
define|#
directive|define
name|leaveok
value|UNDEF(leaveok)
end_define

begin_else
else|#
directive|else
end_else

begin_extern
extern|extern
literal|"C"
name|int
name|leaveok
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|bool
name|bf
parameter_list|)
function_decl|;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|move
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|move
function|)
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
return|return
name|move
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|move
end_undef

begin_define
define|#
directive|define
name|move
value|UNDEF(move)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|refresh
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|refresh
function|)
parameter_list|()
block|{
return|return
name|refresh
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|refresh
end_undef

begin_define
define|#
directive|define
name|refresh
value|UNDEF(refresh)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|redrawwin
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|redrawwin
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|)
block|{
return|return
name|redrawwin
argument_list|(
name|win
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|redrawwin
end_undef

begin_define
define|#
directive|define
name|redrawwin
value|UNDEF(redrawwin)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|scrl
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|scrl
function|)
parameter_list|(
name|int
name|l
parameter_list|)
block|{
return|return
name|scrl
argument_list|(
name|l
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|scrl
end_undef

begin_define
define|#
directive|define
name|scrl
value|UNDEF(scrl)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|scroll
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|scroll
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|)
block|{
return|return
name|scroll
argument_list|(
name|win
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|scroll
end_undef

begin_define
define|#
directive|define
name|scroll
value|UNDEF(scroll)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|scrollok
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|scrollok
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|bool
name|bf
parameter_list|)
block|{
return|return
name|scrollok
argument_list|(
name|win
argument_list|,
name|bf
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|scrollok
end_undef

begin_define
define|#
directive|define
name|scrollok
value|UNDEF(scrollok)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NCURSES_H
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
name|int
name|scrollok
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_extern

begin_else
else|#
directive|else
end_else

begin_extern
extern|extern
literal|"C"
name|int
name|scrollok
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|char
parameter_list|)
function_decl|;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|setscrreg
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|setscrreg
function|)
parameter_list|(
name|int
name|t
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|setscrreg
argument_list|(
name|t
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|setscrreg
end_undef

begin_define
define|#
directive|define
name|setscrreg
value|UNDEF(setscrreg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|standend
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|standend
function|)
parameter_list|()
block|{
return|return
name|standend
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|standend
end_undef

begin_define
define|#
directive|define
name|standend
value|UNDEF(standend)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|standout
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|standout
function|)
parameter_list|()
block|{
return|return
name|standout
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|standout
end_undef

begin_define
define|#
directive|define
name|standout
value|UNDEF(standout)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|subpad
end_ifdef

begin_function
specifier|inline
name|WINDOW
modifier|*
name|UNDEF
function|(
name|subpad
function|)
parameter_list|(
name|WINDOW
modifier|*
name|p
parameter_list|,
name|int
name|l
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
block|{
return|return
name|derwin
argument_list|(
name|p
argument_list|,
name|l
argument_list|,
name|c
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|subpad
end_undef

begin_define
define|#
directive|define
name|subpad
value|UNDEF(subpad)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|timeout
end_ifdef

begin_function
specifier|inline
name|void
name|UNDEF
function|(
name|timeout
function|)
parameter_list|(
name|int
name|delay
parameter_list|)
block|{
name|timeout
argument_list|(
name|delay
argument_list|)
expr_stmt|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|timeout
end_undef

begin_define
define|#
directive|define
name|timeout
value|UNDEF(timeout)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|touchline
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|touchline
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|s
parameter_list|,
name|int
name|c
parameter_list|)
block|{
return|return
name|touchline
argument_list|(
name|win
argument_list|,
name|s
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|touchline
end_undef

begin_define
define|#
directive|define
name|touchline
value|UNDEF(touchline)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|touchwin
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|touchwin
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|)
block|{
return|return
name|touchwin
argument_list|(
name|win
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|touchwin
end_undef

begin_define
define|#
directive|define
name|touchwin
value|UNDEF(touchwin)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|untouchwin
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|untouchwin
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|)
block|{
return|return
name|untouchwin
argument_list|(
name|win
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|untouchwin
end_undef

begin_define
define|#
directive|define
name|untouchwin
value|UNDEF(untouchwin)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|vline
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|vline
function|)
parameter_list|(
name|chtype
name|ch
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|vline
argument_list|(
name|ch
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|vline
end_undef

begin_define
define|#
directive|define
name|vline
value|UNDEF(vline)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|waddstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|waddstr
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|char
modifier|*
name|str
parameter_list|)
block|{
return|return
name|waddstr
argument_list|(
name|win
argument_list|,
name|str
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|waddstr
end_undef

begin_define
define|#
directive|define
name|waddstr
value|UNDEF(waddstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|waddchstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|waddchstr
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|chtype
modifier|*
name|at
parameter_list|)
block|{
return|return
name|waddchstr
argument_list|(
name|win
argument_list|,
name|at
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|waddchstr
end_undef

begin_define
define|#
directive|define
name|waddchstr
value|UNDEF(waddchstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|wstandend
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|wstandend
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|)
block|{
return|return
name|wstandend
argument_list|(
name|win
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|wstandend
end_undef

begin_define
define|#
directive|define
name|wstandend
value|UNDEF(wstandend)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|wstandout
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|wstandout
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|)
block|{
return|return
name|wstandout
argument_list|(
name|win
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|wstandout
end_undef

begin_define
define|#
directive|define
name|wstandout
value|UNDEF(wstandout)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|wattroff
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|wattroff
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|att
parameter_list|)
block|{
return|return
name|wattroff
argument_list|(
name|win
argument_list|,
name|att
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|wattroff
end_undef

begin_define
define|#
directive|define
name|wattroff
value|UNDEF(wattroff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|chgat
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|chgat
function|)
parameter_list|(
name|int
name|n
parameter_list|,
name|attr_t
name|attr
parameter_list|,
name|short
name|color
parameter_list|,
specifier|const
name|void
modifier|*
name|opts
parameter_list|)
block|{
return|return
name|chgat
argument_list|(
name|n
argument_list|,
name|attr
argument_list|,
name|color
argument_list|,
name|opts
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|chgat
end_undef

begin_define
define|#
directive|define
name|chgat
value|UNDEF(chgat)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvchgat
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvchgat
function|)
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|n
parameter_list|,
name|attr_t
name|attr
parameter_list|,
name|short
name|color
parameter_list|,
specifier|const
name|void
modifier|*
name|opts
parameter_list|)
block|{
return|return
name|mvchgat
argument_list|(
name|y
argument_list|,
name|x
argument_list|,
name|n
argument_list|,
name|attr
argument_list|,
name|color
argument_list|,
name|opts
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvchgat
end_undef

begin_define
define|#
directive|define
name|mvchgat
value|UNDEF(mvchgat)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwchgat
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvwchgat
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|n
parameter_list|,
name|attr_t
name|attr
parameter_list|,
name|short
name|color
parameter_list|,
specifier|const
name|void
modifier|*
name|opts
parameter_list|)
block|{
return|return
name|mvwchgat
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|n
argument_list|,
name|attr
argument_list|,
name|color
argument_list|,
name|opts
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwchgat
end_undef

begin_define
define|#
directive|define
name|mvwchgat
value|UNDEF(mvwchgat)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|wattrset
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|wattrset
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|att
parameter_list|)
block|{
return|return
name|wattrset
argument_list|(
name|win
argument_list|,
name|att
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|wattrset
end_undef

begin_define
define|#
directive|define
name|wattrset
value|UNDEF(wattrset)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|winch
end_ifdef

begin_function
specifier|inline
name|chtype
name|UNDEF
function|(
name|winch
function|)
parameter_list|(
specifier|const
name|WINDOW
modifier|*
name|win
parameter_list|)
block|{
return|return
name|winch
argument_list|(
name|win
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|winch
end_undef

begin_define
define|#
directive|define
name|winch
value|UNDEF(winch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwaddch
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvwaddch
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
specifier|const
name|chtype
name|ch
parameter_list|)
block|{
return|return
name|mvwaddch
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|ch
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwaddch
end_undef

begin_define
define|#
directive|define
name|mvwaddch
value|UNDEF(mvwaddch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwaddchnstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvwaddchnstr
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|chtype
modifier|*
name|str
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|mvwaddchnstr
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|str
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwaddchnstr
end_undef

begin_define
define|#
directive|define
name|mvwaddchnstr
value|UNDEF(mvwaddchnstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwaddchstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvwaddchstr
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|chtype
modifier|*
name|str
parameter_list|)
block|{
return|return
name|mvwaddchstr
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|str
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwaddchstr
end_undef

begin_define
define|#
directive|define
name|mvwaddchstr
value|UNDEF(mvwaddchstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|addnstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|addnstr
function|)
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|addnstr
argument_list|(
operator|(
name|char
operator|*
operator|)
name|str
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|addnstr
end_undef

begin_define
define|#
directive|define
name|addnstr
value|UNDEF(addnstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwaddnstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvwaddnstr
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|mvwaddnstr
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
operator|(
name|char
operator|*
operator|)
name|str
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwaddnstr
end_undef

begin_define
define|#
directive|define
name|mvwaddnstr
value|UNDEF(mvwaddnstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwaddstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvwaddstr
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
return|return
name|mvwaddstr
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
operator|(
name|char
operator|*
operator|)
name|str
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwaddstr
end_undef

begin_define
define|#
directive|define
name|mvwaddstr
value|UNDEF(mvwaddstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwdelch
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvwdelch
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
block|{
return|return
name|mvwdelch
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwdelch
end_undef

begin_define
define|#
directive|define
name|mvwdelch
value|UNDEF(mvwdelch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwgetch
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvwgetch
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
block|{
return|return
name|mvwgetch
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwgetch
end_undef

begin_define
define|#
directive|define
name|mvwgetch
value|UNDEF(mvwgetch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwgetstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvwgetstr
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|char
modifier|*
name|str
parameter_list|)
block|{
return|return
name|mvwgetstr
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|str
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwgetstr
end_undef

begin_define
define|#
directive|define
name|mvwgetstr
value|UNDEF(mvwgetstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwgetnstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvwgetnstr
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|mvwgetnstr
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|str
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwgetnstr
end_undef

begin_define
define|#
directive|define
name|mvwgetnstr
value|UNDEF(mvwgetnstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwinch
end_ifdef

begin_function
specifier|inline
name|chtype
name|UNDEF
function|(
name|mvwinch
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
block|{
return|return
name|mvwinch
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwinch
end_undef

begin_define
define|#
directive|define
name|mvwinch
value|UNDEF(mvwinch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvwinsch
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvwinsch
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|char
name|c
parameter_list|)
block|{
return|return
name|mvwinsch
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvwinsch
end_undef

begin_define
define|#
directive|define
name|mvwinsch
value|UNDEF(mvwinsch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvaddch
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvaddch
function|)
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|chtype
name|ch
parameter_list|)
block|{
return|return
name|mvaddch
argument_list|(
name|y
argument_list|,
name|x
argument_list|,
name|ch
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvaddch
end_undef

begin_define
define|#
directive|define
name|mvaddch
value|UNDEF(mvaddch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvaddnstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvaddnstr
function|)
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|mvaddnstr
argument_list|(
name|y
argument_list|,
name|x
argument_list|,
operator|(
name|char
operator|*
operator|)
name|str
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvaddnstr
end_undef

begin_define
define|#
directive|define
name|mvaddnstr
value|UNDEF(mvaddnstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvaddstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvaddstr
function|)
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
return|return
name|mvaddstr
argument_list|(
name|y
argument_list|,
name|x
argument_list|,
operator|(
name|char
operator|*
operator|)
name|str
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvaddstr
end_undef

begin_define
define|#
directive|define
name|mvaddstr
value|UNDEF(mvaddstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvdelch
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvdelch
function|)
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
block|{
return|return
name|mvdelch
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvdelch
end_undef

begin_define
define|#
directive|define
name|mvdelch
value|UNDEF(mvdelch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvgetch
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvgetch
function|)
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
block|{
return|return
name|mvgetch
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvgetch
end_undef

begin_define
define|#
directive|define
name|mvgetch
value|UNDEF(mvgetch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvgetstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvgetstr
function|)
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|char
modifier|*
name|str
parameter_list|)
block|{
return|return
name|mvgetstr
argument_list|(
name|y
argument_list|,
name|x
argument_list|,
name|str
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvgetstr
end_undef

begin_define
define|#
directive|define
name|mvgetstr
value|UNDEF(mvgetstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvgetnstr
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvgetnstr
function|)
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|mvgetnstr
argument_list|(
name|y
argument_list|,
name|x
argument_list|,
name|str
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvgetnstr
end_undef

begin_define
define|#
directive|define
name|mvgetnstr
value|UNDEF(mvgetnstr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvinch
end_ifdef

begin_function
specifier|inline
name|chtype
name|UNDEF
function|(
name|mvinch
function|)
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
block|{
return|return
name|mvinch
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvinch
end_undef

begin_define
define|#
directive|define
name|mvinch
value|UNDEF(mvinch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mvinsch
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|mvinsch
function|)
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|char
name|c
parameter_list|)
block|{
return|return
name|mvinsch
argument_list|(
name|y
argument_list|,
name|x
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|mvinsch
end_undef

begin_define
define|#
directive|define
name|mvinsch
value|UNDEF(mvinsch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|napms
end_ifdef

begin_function
specifier|inline
name|void
name|UNDEF
function|(
name|napms
function|)
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|)
block|{
name|napms
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|napms
end_undef

begin_define
define|#
directive|define
name|napms
value|UNDEF(napms)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|fixterm
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|fixterm
function|)
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|fixterm
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|fixterm
end_undef

begin_define
define|#
directive|define
name|fixterm
value|UNDEF(fixterm)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|resetterm
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|resetterm
function|)
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|resetterm
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|resetterm
end_undef

begin_define
define|#
directive|define
name|resetterm
value|UNDEF(resetterm)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|saveterm
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|saveterm
function|)
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|saveterm
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|saveterm
end_undef

begin_define
define|#
directive|define
name|saveterm
value|UNDEF(saveterm)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|crmode
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|crmode
function|)
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|crmode
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|crmode
end_undef

begin_define
define|#
directive|define
name|crmode
value|UNDEF(crmode)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|nocrmode
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|nocrmode
function|)
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|nocrmode
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|nocrmode
end_undef

begin_define
define|#
directive|define
name|nocrmode
value|UNDEF(nocrmode)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|getbkgd
end_ifdef

begin_function
specifier|inline
name|chtype
name|UNDEF
function|(
name|getbkgd
function|)
parameter_list|(
specifier|const
name|WINDOW
modifier|*
name|win
parameter_list|)
block|{
return|return
name|getbkgd
argument_list|(
name|win
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|getbkgd
end_undef

begin_define
define|#
directive|define
name|getbkgd
value|UNDEF(getbkgd)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|bkgd
end_ifdef

begin_function
specifier|inline
name|int
name|UNDEF
function|(
name|bkgd
function|)
parameter_list|(
name|chtype
name|ch
parameter_list|)
block|{
return|return
name|bkgd
argument_list|(
name|ch
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|bkgd
end_undef

begin_define
define|#
directive|define
name|bkgd
value|UNDEF(bkgd)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|bkgdset
end_ifdef

begin_function
specifier|inline
name|void
name|UNDEF
function|(
name|bkgdset
function|)
parameter_list|(
name|chtype
name|ch
parameter_list|)
block|{
name|bkgdset
argument_list|(
name|ch
argument_list|)
expr_stmt|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|bkgdset
end_undef

begin_define
define|#
directive|define
name|bkgdset
value|UNDEF(bkgdset)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  * C++ class for windows.  *  *  */
end_comment

begin_decl_stmt
name|class
name|NCursesWindow
block|{
name|friend
name|class
name|NCursesMenu
decl_stmt|;
name|friend
name|class
name|NCursesForm
decl_stmt|;
name|private
label|:
specifier|static
name|bool
name|b_initialized
decl_stmt|;
specifier|static
name|void
name|initialize
parameter_list|()
function_decl|;
specifier|static
name|int
name|ripoff_init
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
name|short
name|getcolor
parameter_list|(
name|int
name|getback
parameter_list|)
function_decl|const;
specifier|static
name|int
name|setpalette
parameter_list|(
name|short
name|fore
parameter_list|,
name|short
name|back
parameter_list|,
name|short
name|pair
parameter_list|)
function_decl|;
specifier|static
name|int
name|colorInitialized
decl_stmt|;
comment|// This private constructor is only used during the initialization
comment|// of windows generated by ripoffline() calls.
name|NCursesWindow
argument_list|(
argument|WINDOW* win
argument_list|,
argument|int cols
argument_list|)
empty_stmt|;
name|protected
label|:
name|void
name|err_handler
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
decl|const
name|THROWS
argument_list|(
name|NCursesException
argument_list|)
decl_stmt|;
comment|// Signal an error with the given message text.
specifier|static
name|long
name|count
decl_stmt|;
comment|// count of all active windows:
comment|//   We rely on the c++ promise that
comment|//   all otherwise uninitialized
comment|//   static class vars are set to 0
name|WINDOW
modifier|*
name|w
decl_stmt|;
comment|// the curses WINDOW
name|bool
name|alloced
decl_stmt|;
comment|// TRUE if we own the WINDOW
name|NCursesWindow
modifier|*
name|par
decl_stmt|;
comment|// parent, if subwindow
name|NCursesWindow
modifier|*
name|subwins
decl_stmt|;
comment|// head of subwindows list
name|NCursesWindow
modifier|*
name|sib
decl_stmt|;
comment|// next subwindow of parent
name|void
name|kill_subwindows
parameter_list|()
function_decl|;
comment|// disable all subwindows
comment|// Destroy all subwindows.
comment|/* Only for use by derived classes. They are then in charge to      fill the member variables correctly. */
name|NCursesWindow
argument_list|()
expr_stmt|;
name|public
label|:
name|NCursesWindow
argument_list|(
name|WINDOW
operator|*
operator|&
name|window
argument_list|)
expr_stmt|;
comment|// useful only for stdscr
name|NCursesWindow
argument_list|(
argument|int lines
argument_list|,
comment|// number of lines
argument|int cols
argument_list|,
comment|// number of columns
argument|int begin_y
argument_list|,
comment|// line origin
argument|int begin_x
argument_list|)
empty_stmt|;
comment|// col origin
name|NCursesWindow
argument_list|(
argument|NCursesWindow& par
argument_list|,
comment|// parent window
argument|int lines
argument_list|,
comment|// number of lines
argument|int cols
argument_list|,
comment|// number of columns
argument|int begin_y
argument_list|,
comment|// absolute or relative
argument|int begin_x
argument_list|,
comment|//   origins:
argument|char absrel =
literal|'a'
argument_list|)
empty_stmt|;
comment|// if `a', by& bx are
comment|// absolute screen pos, else if `r', they are relative to par origin
name|NCursesWindow
argument_list|(
argument|NCursesWindow& par
argument_list|,
comment|// parent window
argument|bool do_box = TRUE
argument_list|)
empty_stmt|;
comment|// this is the very common case that we want to create the subwindow that
comment|// is two lines and two columns smaller and begins at (1,1).
comment|// We may automatically request the box around it.
name|virtual
operator|~
name|NCursesWindow
argument_list|()
expr_stmt|;
name|NCursesWindow
name|Clone
parameter_list|()
function_decl|;
comment|// Make an exact copy of the window.
comment|// Initialization.
specifier|static
name|void
name|useColors
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Call this routine very early if you want to have colors.
specifier|static
name|int
name|ripoffline
parameter_list|(
name|int
name|ripoff_lines
parameter_list|,
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|NCursesWindow
modifier|&
name|win
parameter_list|)
parameter_list|)
function_decl|;
comment|// This function is used to generate a window of ripped-of lines.
comment|// If the argument is positive, lines are removed from the top, if it
comment|// is negative lines are removed from the bottom. This enhances the
comment|// lowlevel ripoffline() function because it uses the internal
comment|// implementation that allows to remove more than just a single line.
comment|// This function must be called before any other ncurses function. The
comment|// creation of the window is defered until ncurses gets initialized.
comment|// The initialization function is then called.
comment|// -------------------------------------------------------------------------
comment|// terminal status
comment|// -------------------------------------------------------------------------
name|int
name|lines
argument_list|()
specifier|const
block|{
return|return
name|LINES
return|;
block|}
comment|// Number of lines on terminal, *not* window
name|int
name|cols
argument_list|()
specifier|const
block|{
return|return
name|COLS
return|;
block|}
comment|// Number of cols  on terminal, *not* window
name|int
name|tabsize
argument_list|()
specifier|const
block|{
return|return
name|TABSIZE
return|;
block|}
comment|// Size of a tab on terminal, *not* window
specifier|static
name|int
name|NumberOfColors
parameter_list|()
function_decl|;
comment|// Number of available colors
name|int
name|colors
argument_list|()
specifier|const
block|{
return|return
name|NumberOfColors
argument_list|()
return|;
block|}
comment|// Number of available colors
comment|// -------------------------------------------------------------------------
comment|// window status
comment|// -------------------------------------------------------------------------
name|int
name|height
argument_list|()
specifier|const
block|{
return|return
name|maxy
argument_list|()
operator|+
literal|1
return|;
block|}
comment|// Number of lines in this window
name|int
name|width
argument_list|()
specifier|const
block|{
return|return
name|maxx
argument_list|()
operator|+
literal|1
return|;
block|}
comment|// Number of columns in this window
name|int
name|begx
argument_list|()
specifier|const
block|{
return|return
name|w
operator|->
name|_begx
return|;
block|}
comment|// Column of top left corner relative to stdscr
name|int
name|begy
argument_list|()
specifier|const
block|{
return|return
name|w
operator|->
name|_begy
return|;
block|}
comment|// Line of top left corner relative to stdscr
name|int
name|maxx
argument_list|()
specifier|const
block|{
return|return
name|w
operator|->
name|_maxx
return|;
block|}
comment|// Largest x coord in window
name|int
name|maxy
argument_list|()
specifier|const
block|{
return|return
name|w
operator|->
name|_maxy
return|;
block|}
comment|// Largest y coord in window
name|short
name|getcolor
argument_list|()
specifier|const
expr_stmt|;
comment|// Actual color pair
name|short
name|foreground
argument_list|()
specifier|const
block|{
return|return
name|getcolor
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|// Actual foreground color
name|short
name|background
argument_list|()
specifier|const
block|{
return|return
name|getcolor
argument_list|(
literal|1
argument_list|)
return|;
block|}
comment|// Actual background color
name|int
name|setpalette
parameter_list|(
name|short
name|fore
parameter_list|,
name|short
name|back
parameter_list|)
function_decl|;
comment|// Set color palette entry
name|int
name|setcolor
parameter_list|(
name|short
name|pair
parameter_list|)
function_decl|;
comment|// Set actually used palette entry
comment|// -------------------------------------------------------------------------
comment|// window positioning
comment|// -------------------------------------------------------------------------
name|virtual
name|int
name|mvwin
parameter_list|(
name|int
name|begin_y
parameter_list|,
name|int
name|begin_x
parameter_list|)
block|{
return|return
operator|::
name|mvwin
argument_list|(
name|w
argument_list|,
name|begin_y
argument_list|,
name|begin_x
argument_list|)
return|;
block|}
comment|// Move window to new position with the new position as top left corner.
comment|// This is virtual because it is redefined in NCursesPanel.
comment|// -------------------------------------------------------------------------
comment|// coordinate positioning
comment|// -------------------------------------------------------------------------
name|int
name|move
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
block|{
return|return
operator|::
name|wmove
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
return|;
block|}
comment|// Move cursor the this position
name|void
name|getyx
argument_list|(
name|int
operator|&
name|y
argument_list|,
name|int
operator|&
name|x
argument_list|)
decl|const
block|{
operator|::
name|getyx
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
comment|// Get current position of the cursor
name|int
name|mvcur
argument_list|(
name|int
name|oldrow
argument_list|,
name|int
name|oldcol
argument_list|,
name|int
name|newrow
argument_list|,
name|int
name|newcol
argument_list|)
decl|const
block|{
return|return
operator|::
name|mvcur
argument_list|(
name|oldrow
argument_list|,
name|oldcol
argument_list|,
name|newrow
argument_list|,
name|newcol
argument_list|)
return|;
block|}
comment|// Perform lowlevel cursor motion that takes effect immediately.
comment|// -------------------------------------------------------------------------
comment|// input
comment|// -------------------------------------------------------------------------
name|int
name|getch
parameter_list|()
block|{
return|return
operator|::
name|wgetch
argument_list|(
name|w
argument_list|)
return|;
block|}
comment|// Get a keystroke from the window.
name|int
name|getch
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
block|{
return|return
operator|::
name|mvwgetch
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
return|;
block|}
comment|// Move cursor to position and get a keystroke from the window
name|int
name|getstr
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|int
name|n
init|=
operator|-
literal|1
parameter_list|)
block|{
return|return
operator|::
name|wgetnstr
argument_list|(
name|w
argument_list|,
name|str
argument_list|,
name|n
argument_list|)
return|;
block|}
comment|// Read a series of characters into str until a newline or carriage return
comment|// is received. Read at most n characters. If n is negative, the limit is
comment|// ignored.
name|int
name|getstr
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|int
name|n
init|=
operator|-
literal|1
parameter_list|)
block|{
return|return
operator|::
name|mvwgetnstr
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|str
argument_list|,
name|n
argument_list|)
return|;
block|}
comment|// Move the cursor to the requested position and then perform the getstr()
comment|// as described above.
name|int
name|instr
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|int
name|n
init|=
operator|-
literal|1
parameter_list|)
block|{
return|return
operator|::
name|winnstr
argument_list|(
name|w
argument_list|,
name|s
argument_list|,
name|n
argument_list|)
return|;
block|}
comment|// Get a string of characters from the window into the buffer s. Retrieve
comment|// at most n characters, if n is negative retrieve all characters up to the
comment|// end of the current line. Attributes are stripped from the characters.
name|int
name|instr
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|char
modifier|*
name|s
parameter_list|,
name|int
name|n
init|=
operator|-
literal|1
parameter_list|)
block|{
return|return
operator|::
name|mvwinnstr
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|s
argument_list|,
name|n
argument_list|)
return|;
block|}
comment|// Move the cursor to the requested position and then perform the instr()
comment|// as described above.
name|int
name|scanw
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
comment|// Perform a scanw function from the window. This only works if you're
comment|// using the GNU C++ compiler.
if|#
directive|if
name|__GNUG__
operator|>=
literal|2
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|scanf
parameter_list|,
function_decl|2
operator|,
function_decl|3
block|)
decl_stmt|)
end_decl_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|scanw
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
comment|// Move the cursor to the requested position and then perform a scanw
comment|// from the window. This nly works if you're using the GNU C++ compiler.
if|#
directive|if
name|__GNUG__
operator|>=
literal|2
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|scanf
parameter_list|,
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// output
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_function
name|int
name|addch
parameter_list|(
specifier|const
name|chtype
name|ch
parameter_list|)
block|{
return|return
operator|::
name|waddch
argument_list|(
name|w
argument_list|,
name|ch
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Put attributed character to the window.
end_comment

begin_function
name|int
name|addch
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
specifier|const
name|chtype
name|ch
parameter_list|)
block|{
return|return
operator|::
name|mvwaddch
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|ch
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Move cursor to the requested position and then put attributed character
end_comment

begin_comment
comment|// to the window.
end_comment

begin_function
name|int
name|echochar
parameter_list|(
specifier|const
name|chtype
name|ch
parameter_list|)
block|{
return|return
operator|::
name|wechochar
argument_list|(
name|w
argument_list|,
name|ch
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Put attributed character to the window and refresh it immediately.
end_comment

begin_function
name|int
name|addstr
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|n
init|=
operator|-
literal|1
parameter_list|)
block|{
return|return
operator|::
name|waddnstr
argument_list|(
name|w
argument_list|,
operator|(
name|char
operator|*
operator|)
name|str
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Write the string str to the window, stop writing if the terminating
end_comment

begin_comment
comment|// NUL or the limit n is reached. If n is negative, it is ignored.
end_comment

begin_function
name|int
name|addstr
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|n
init|=
operator|-
literal|1
parameter_list|)
block|{
return|return
operator|::
name|mvwaddnstr
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
operator|(
name|char
operator|*
operator|)
name|str
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Move the cursor to the requested position and then perform the addstr
end_comment

begin_comment
comment|// as described above.
end_comment

begin_function_decl
name|int
name|printw
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
comment|// Do a formatted print to the window.
if|#
directive|if
name|__GNUG__
operator|>=
literal|2
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|printw
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
comment|// Move the cursor and then do a formatted print to the window.
if|#
directive|if
name|__GNUG__
operator|>=
literal|2
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|chtype
name|inch
argument_list|()
specifier|const
block|{
return|return
operator|::
name|winch
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Retrieve attributed character under the current cursor position.
end_comment

begin_function
name|chtype
name|inch
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
block|{
return|return
operator|::
name|mvwinch
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Move cursor to requested position and then retrieve attributed character
end_comment

begin_comment
comment|// at this position.
end_comment

begin_function
name|int
name|insch
parameter_list|(
name|chtype
name|ch
parameter_list|)
block|{
return|return
operator|::
name|winsch
argument_list|(
name|w
argument_list|,
name|ch
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Insert attributed character into the window before current cursor
end_comment

begin_comment
comment|// position.
end_comment

begin_function
name|int
name|insch
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|chtype
name|ch
parameter_list|)
block|{
return|return
operator|::
name|mvwinsch
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
operator|(
name|char
operator|)
name|ch
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Move cursor to requested position and then insert the attributed
end_comment

begin_comment
comment|// character before that position.
end_comment

begin_function
name|int
name|insertln
parameter_list|()
block|{
return|return
operator|::
name|winsdelln
argument_list|(
name|w
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Insert an empty line above the current line.
end_comment

begin_function
name|int
name|insdelln
parameter_list|(
name|int
name|n
init|=
literal|1
parameter_list|)
block|{
return|return
operator|::
name|winsdelln
argument_list|(
name|w
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// If n>0 insert that many lines above the current line. If n<0 delete
end_comment

begin_comment
comment|// that many lines beginning with the current line.
end_comment

begin_function
name|int
name|insstr
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|n
init|=
operator|-
literal|1
parameter_list|)
block|{
return|return
operator|::
name|winsnstr
argument_list|(
name|w
argument_list|,
name|s
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Insert the string into the window before the current cursor position.
end_comment

begin_comment
comment|// Insert stops at end of string or when the limit n is reached. If n is
end_comment

begin_comment
comment|// negative, it is ignored.
end_comment

begin_function
name|int
name|insstr
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|n
init|=
operator|-
literal|1
parameter_list|)
block|{
return|return
operator|::
name|mvwinsnstr
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|s
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Move the cursor to the requested position and then perform the insstr()
end_comment

begin_comment
comment|// as described above.
end_comment

begin_function
name|int
name|attron
parameter_list|(
name|chtype
name|at
parameter_list|)
block|{
return|return
operator|::
name|wattron
argument_list|(
name|w
argument_list|,
name|at
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Switch on the window attributes;
end_comment

begin_function
name|int
name|attroff
parameter_list|(
name|chtype
name|at
parameter_list|)
block|{
return|return
operator|::
name|wattroff
argument_list|(
name|w
argument_list|,
operator|(
name|int
operator|)
name|at
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Switch off the window attributes;
end_comment

begin_function
name|int
name|attrset
parameter_list|(
name|chtype
name|at
parameter_list|)
block|{
return|return
operator|::
name|wattrset
argument_list|(
name|w
argument_list|,
operator|(
name|int
operator|)
name|at
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Set the window attributes;
end_comment

begin_function
name|int
name|color_set
parameter_list|(
name|short
name|color_pair_number
parameter_list|,
name|void
modifier|*
name|opts
init|=
name|NULL
parameter_list|)
block|{
return|return
operator|::
name|wcolor_set
argument_list|(
name|w
argument_list|,
name|color_pair_number
argument_list|,
name|opts
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Set the window color attribute;
end_comment

begin_function
name|int
name|chgat
parameter_list|(
name|int
name|n
parameter_list|,
name|attr_t
name|attr
parameter_list|,
name|short
name|color
parameter_list|,
specifier|const
name|void
modifier|*
name|opts
init|=
name|NULL
parameter_list|)
block|{
return|return
operator|::
name|wchgat
argument_list|(
name|w
argument_list|,
name|n
argument_list|,
name|attr
argument_list|,
name|color
argument_list|,
name|opts
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Change the attributes of the next n characters in the current line. If
end_comment

begin_comment
comment|// n is negative or greater than the number of remaining characters in the
end_comment

begin_comment
comment|// line, the attributes will be changed up to the end of the line.
end_comment

begin_function
name|int
name|chgat
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|n
parameter_list|,
name|attr_t
name|attr
parameter_list|,
name|short
name|color
parameter_list|,
specifier|const
name|void
modifier|*
name|opts
init|=
name|NULL
parameter_list|)
block|{
return|return
operator|::
name|mvwchgat
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|n
argument_list|,
name|attr
argument_list|,
name|color
argument_list|,
name|opts
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Move the cursor to the requested position and then perform chgat() as
end_comment

begin_comment
comment|// described above.
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// background
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_expr_stmt
name|chtype
name|getbkgd
argument_list|()
specifier|const
block|{
return|return
operator|::
name|getbkgd
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Get current background setting.
end_comment

begin_function
name|int
name|bkgd
parameter_list|(
specifier|const
name|chtype
name|ch
parameter_list|)
block|{
return|return
operator|::
name|wbkgd
argument_list|(
name|w
argument_list|,
name|ch
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Set the background property and apply it to the window.
end_comment

begin_function
name|void
name|bkgdset
parameter_list|(
name|chtype
name|ch
parameter_list|)
block|{
operator|::
name|wbkgdset
argument_list|(
name|w
argument_list|,
name|ch
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Set the background property.
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// borders
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_function
name|int
name|box
parameter_list|(
name|chtype
name|vert
init|=
literal|0
parameter_list|,
name|chtype
name|hor
init|=
literal|0
parameter_list|)
block|{
return|return
operator|::
name|wborder
argument_list|(
name|w
argument_list|,
name|vert
argument_list|,
name|vert
argument_list|,
name|hor
argument_list|,
name|hor
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Draw a box around the window with the given vertical and horizontal
end_comment

begin_comment
comment|// drawing characters. If you specifiy a zero as character, curses will try
end_comment

begin_comment
comment|// to find a "nice" character.
end_comment

begin_function
name|int
name|border
parameter_list|(
name|chtype
name|left
init|=
literal|0
parameter_list|,
name|chtype
name|right
init|=
literal|0
parameter_list|,
name|chtype
name|top
init|=
literal|0
parameter_list|,
name|chtype
name|bottom
init|=
literal|0
parameter_list|,
name|chtype
name|top_left
init|=
literal|0
parameter_list|,
name|chtype
name|top_right
init|=
literal|0
parameter_list|,
name|chtype
name|bottom_left
init|=
literal|0
parameter_list|,
name|chtype
name|bottom_right
init|=
literal|0
parameter_list|)
block|{
return|return
operator|::
name|wborder
argument_list|(
name|w
argument_list|,
name|left
argument_list|,
name|right
argument_list|,
name|top
argument_list|,
name|bottom
argument_list|,
name|top_left
argument_list|,
name|top_right
argument_list|,
name|bottom_left
argument_list|,
name|bottom_right
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Draw a border around the window with the given characters for the
end_comment

begin_comment
comment|// various parts of the border. If you pass zero for a character, curses
end_comment

begin_comment
comment|// will try to find "nice" characters.
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// lines and boxes
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_function
name|int
name|hline
parameter_list|(
name|int
name|len
parameter_list|,
name|chtype
name|ch
init|=
literal|0
parameter_list|)
block|{
return|return
operator|::
name|whline
argument_list|(
name|w
argument_list|,
name|ch
argument_list|,
name|len
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Draw a horizontal line of len characters with the given character. If
end_comment

begin_comment
comment|// you pass zero for the character, curses will try to find a "nice" one.
end_comment

begin_function
name|int
name|hline
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|len
parameter_list|,
name|chtype
name|ch
init|=
literal|0
parameter_list|)
block|{
return|return
operator|::
name|mvwhline
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|ch
argument_list|,
name|len
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Move the cursor to the requested position and then draw a horizontal line.
end_comment

begin_function
name|int
name|vline
parameter_list|(
name|int
name|len
parameter_list|,
name|chtype
name|ch
init|=
literal|0
parameter_list|)
block|{
return|return
operator|::
name|wvline
argument_list|(
name|w
argument_list|,
name|ch
argument_list|,
name|len
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Draw a vertical line of len characters with the given character. If
end_comment

begin_comment
comment|// you pass zero for the character, curses will try to find a "nice" one.
end_comment

begin_function
name|int
name|vline
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|len
parameter_list|,
name|chtype
name|ch
init|=
literal|0
parameter_list|)
block|{
return|return
operator|::
name|mvwvline
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|ch
argument_list|,
name|len
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Move the cursor to the requested position and then draw a vertical line.
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// erasure
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_function
name|int
name|erase
parameter_list|()
block|{
return|return
operator|::
name|werase
argument_list|(
name|w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Erase the window.
end_comment

begin_function
name|int
name|clear
parameter_list|()
block|{
return|return
operator|::
name|wclear
argument_list|(
name|w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Clear the window.
end_comment

begin_function
name|int
name|clearok
parameter_list|(
name|bool
name|bf
parameter_list|)
block|{
return|return
operator|::
name|clearok
argument_list|(
name|w
argument_list|,
name|bf
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Set/Reset the clear flag. If set, the next refresh() will clear the
end_comment

begin_comment
comment|// screen.
end_comment

begin_function
name|int
name|clrtobot
parameter_list|()
block|{
return|return
operator|::
name|wclrtobot
argument_list|(
name|w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Clear to the end of the window.
end_comment

begin_function
name|int
name|clrtoeol
parameter_list|()
block|{
return|return
operator|::
name|wclrtoeol
argument_list|(
name|w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Clear to the end of the line.
end_comment

begin_function
name|int
name|delch
parameter_list|()
block|{
return|return
operator|::
name|wdelch
argument_list|(
name|w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Delete character under the cursor.
end_comment

begin_function
name|int
name|delch
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
block|{
return|return
operator|::
name|mvwdelch
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Move cursor to requested position and delete the character under the
end_comment

begin_comment
comment|// cursor.
end_comment

begin_function
name|int
name|deleteln
parameter_list|()
block|{
return|return
operator|::
name|winsdelln
argument_list|(
name|w
argument_list|,
operator|-
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Delete the current line.
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// screen control
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_function
name|int
name|scroll
parameter_list|(
name|int
name|amount
init|=
literal|1
parameter_list|)
block|{
return|return
operator|::
name|wscrl
argument_list|(
name|w
argument_list|,
name|amount
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Scroll amount lines. If amount is positive, scroll up, otherwise
end_comment

begin_comment
comment|// scroll down.
end_comment

begin_function
name|int
name|scrollok
parameter_list|(
name|bool
name|bf
parameter_list|)
block|{
return|return
operator|::
name|scrollok
argument_list|(
name|w
argument_list|,
name|bf
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// If bf is TRUE, window scrolls if cursor is moved off the bottom
end_comment

begin_comment
comment|// edge of the window or a scrolling region, otherwise the cursor is left
end_comment

begin_comment
comment|// at the bottom line.
end_comment

begin_function
name|int
name|setscrreg
parameter_list|(
name|int
name|from
parameter_list|,
name|int
name|to
parameter_list|)
block|{
return|return
operator|::
name|wsetscrreg
argument_list|(
name|w
argument_list|,
name|from
argument_list|,
name|to
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Define a soft scrolling region.
end_comment

begin_function
name|int
name|idlok
parameter_list|(
name|bool
name|bf
parameter_list|)
block|{
return|return
operator|::
name|idlok
argument_list|(
name|w
argument_list|,
name|bf
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// If bf is TRUE, use insert/delete line hardware support if possible.
end_comment

begin_comment
comment|// Otherwise do it in software.
end_comment

begin_function
name|void
name|idcok
parameter_list|(
name|bool
name|bf
parameter_list|)
block|{
operator|::
name|idcok
argument_list|(
name|w
argument_list|,
name|bf
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// If bf is TRUE, use insert/delete character hardware support if possible.
end_comment

begin_comment
comment|// Otherwise do it in software.
end_comment

begin_function
name|int
name|touchwin
parameter_list|()
block|{
return|return
operator|::
name|wtouchln
argument_list|(
name|w
argument_list|,
literal|0
argument_list|,
name|height
argument_list|()
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Mark the whole window as modified.
end_comment

begin_function
name|int
name|untouchwin
parameter_list|()
block|{
return|return
operator|::
name|wtouchln
argument_list|(
name|w
argument_list|,
literal|0
argument_list|,
name|height
argument_list|()
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Mark the whole window as unmodified.
end_comment

begin_function
name|int
name|touchln
parameter_list|(
name|int
name|s
parameter_list|,
name|int
name|cnt
parameter_list|,
name|bool
name|changed
init|=
name|TRUE
parameter_list|)
block|{
return|return
operator|::
name|wtouchln
argument_list|(
name|w
argument_list|,
name|s
argument_list|,
name|cnt
argument_list|,
call|(
name|int
call|)
argument_list|(
name|changed
condition|?
literal|1
else|:
literal|0
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Mark cnt lines beginning from line s as changed or unchanged, depending
end_comment

begin_comment
comment|// on the value of the changed flag.
end_comment

begin_decl_stmt
name|bool
name|is_linetouched
argument_list|(
name|int
name|line
argument_list|)
decl|const
block|{
return|return
operator|(
operator|::
name|is_linetouched
argument_list|(
name|w
argument_list|,
name|line
argument_list|)
condition|?
name|TRUE
else|:
name|FALSE
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Return TRUE if line is marked as changed, FALSE otherwise
end_comment

begin_expr_stmt
name|bool
name|is_wintouched
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|::
name|is_wintouched
argument_list|(
name|w
argument_list|)
operator|?
name|TRUE
operator|:
name|FALSE
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Return TRUE if window is marked as changed, FALSE otherwise
end_comment

begin_function
name|int
name|leaveok
parameter_list|(
name|bool
name|bf
parameter_list|)
block|{
return|return
operator|::
name|leaveok
argument_list|(
name|w
argument_list|,
name|bf
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// If bf is TRUE, curses will leave the cursor after an update whereever
end_comment

begin_comment
comment|// it is after the update.
end_comment

begin_function
name|int
name|redrawln
parameter_list|(
name|int
name|from
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
operator|::
name|wredrawln
argument_list|(
name|w
argument_list|,
name|from
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Redraw n lines starting from the requested line
end_comment

begin_function
name|int
name|redrawwin
parameter_list|()
block|{
return|return
operator|::
name|wredrawln
argument_list|(
name|w
argument_list|,
literal|0
argument_list|,
name|height
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Redraw the whole window
end_comment

begin_function
name|int
name|doupdate
parameter_list|()
block|{
return|return
operator|::
name|doupdate
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// Do all outputs to make the physical screen looking like the virtual one
end_comment

begin_function
name|void
name|syncdown
parameter_list|()
block|{
operator|::
name|wsyncdown
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Propagate the changes down to all descendant windows
end_comment

begin_function
name|void
name|syncup
parameter_list|()
block|{
operator|::
name|wsyncup
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Propagate the changes up in the hierarchy
end_comment

begin_function
name|void
name|cursyncup
parameter_list|()
block|{
operator|::
name|wcursyncup
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Position the cursor in all ancestor windows corresponding to our setting
end_comment

begin_function
name|int
name|syncok
parameter_list|(
name|bool
name|bf
parameter_list|)
block|{
return|return
operator|::
name|syncok
argument_list|(
name|w
argument_list|,
name|bf
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// If called with bf=TRUE, syncup() is called whenever the window is changed
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_no_flushok
end_ifndef

begin_function
name|int
name|flushok
parameter_list|(
name|bool
name|bf
parameter_list|)
block|{
return|return
operator|::
name|flushok
argument_list|(
name|w
argument_list|,
name|bf
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|immedok
parameter_list|(
name|bool
name|bf
parameter_list|)
block|{
operator|::
name|immedok
argument_list|(
name|w
argument_list|,
name|bf
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// If called with bf=TRUE, any change in the window will cause an
end_comment

begin_comment
comment|// automatic immediate refresh()
end_comment

begin_function
name|int
name|keypad
parameter_list|(
name|bool
name|bf
parameter_list|)
block|{
return|return
operator|::
name|keypad
argument_list|(
name|w
argument_list|,
name|bf
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// If called with bf=TRUE, the application will interpret function keys.
end_comment

begin_function
name|int
name|meta
parameter_list|(
name|bool
name|bf
parameter_list|)
block|{
return|return
operator|::
name|meta
argument_list|(
name|w
argument_list|,
name|bf
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// If called with bf=TRUE, keys may generate 8-Bit characters. Otherwise
end_comment

begin_comment
comment|// 7-Bit characters are generated.
end_comment

begin_function
name|int
name|standout
parameter_list|()
block|{
return|return
operator|::
name|wstandout
argument_list|(
name|w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Enable "standout" attributes
end_comment

begin_function
name|int
name|standend
parameter_list|()
block|{
return|return
operator|::
name|wstandend
argument_list|(
name|w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Disable "standout" attributes
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// The next two are virtual, because we redefine them in the
end_comment

begin_comment
comment|// NCursesPanel class.
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_function
name|virtual
name|int
name|refresh
parameter_list|()
block|{
return|return
operator|::
name|wrefresh
argument_list|(
name|w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Propagate the changes in this window to the virtual screen and call
end_comment

begin_comment
comment|// doupdate(). This is redefined in NCursesPanel.
end_comment

begin_function
name|virtual
name|int
name|noutrefresh
parameter_list|()
block|{
return|return
operator|::
name|wnoutrefresh
argument_list|(
name|w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Propagate the changes in this window to the virtual screen. This is
end_comment

begin_comment
comment|// redefined in NCursesPanel.
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// multiple window control
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_function
name|int
name|overlay
parameter_list|(
name|NCursesWindow
modifier|&
name|win
parameter_list|)
block|{
return|return
operator|::
name|overlay
argument_list|(
name|w
argument_list|,
name|win
operator|.
name|w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Overlay this window over win.
end_comment

begin_function
name|int
name|overwrite
parameter_list|(
name|NCursesWindow
modifier|&
name|win
parameter_list|)
block|{
return|return
operator|::
name|overwrite
argument_list|(
name|w
argument_list|,
name|win
operator|.
name|w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Overwrite win with this window.
end_comment

begin_function
name|int
name|copywin
parameter_list|(
name|NCursesWindow
modifier|&
name|win
parameter_list|,
name|int
name|sminrow
parameter_list|,
name|int
name|smincol
parameter_list|,
name|int
name|dminrow
parameter_list|,
name|int
name|dmincol
parameter_list|,
name|int
name|dmaxrow
parameter_list|,
name|int
name|dmaxcol
parameter_list|,
name|bool
name|overlay
init|=
name|TRUE
parameter_list|)
block|{
return|return
operator|::
name|copywin
argument_list|(
name|w
argument_list|,
name|win
operator|.
name|w
argument_list|,
name|sminrow
argument_list|,
name|smincol
argument_list|,
name|dminrow
argument_list|,
name|dmincol
argument_list|,
name|dmaxrow
argument_list|,
name|dmaxcol
argument_list|,
call|(
name|int
call|)
argument_list|(
name|overlay
condition|?
literal|1
else|:
literal|0
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Overlay or overwrite the rectangle in win given by dminrow,dmincol,
end_comment

begin_comment
comment|// dmaxrow,dmaxcol with the rectangle in this window beginning at
end_comment

begin_comment
comment|// sminrow,smincol.
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// Mouse related
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_expr_stmt
name|bool
name|has_mouse
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Return TRUE if terminal supports a mouse, FALSE otherwise
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// traversal support
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_function
name|NCursesWindow
modifier|*
name|child
parameter_list|()
block|{
return|return
name|subwins
return|;
block|}
end_function

begin_comment
comment|// Get the first child window.
end_comment

begin_function
name|NCursesWindow
modifier|*
name|sibling
parameter_list|()
block|{
return|return
name|sib
return|;
block|}
end_function

begin_comment
comment|// Get the next child of my parent.
end_comment

begin_function
name|NCursesWindow
modifier|*
name|parent
parameter_list|()
block|{
return|return
name|par
return|;
block|}
end_function

begin_comment
comment|// Get my parent.
end_comment

begin_function_decl
name|bool
name|isDescendant
parameter_list|(
name|NCursesWindow
modifier|&
name|win
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Return TRUE if win is a descendant of this.
end_comment

begin_comment
unit|};
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// We leave this here for compatibility reasons.
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|NCursesColorWindow
range|:
name|public
name|NCursesWindow
block|{
name|public
operator|:
name|NCursesColorWindow
argument_list|(
name|WINDOW
operator|*
operator|&
name|window
argument_list|)
comment|// useful only for stdscr
operator|:
name|NCursesWindow
argument_list|(
argument|window
argument_list|)
block|{
name|useColors
argument_list|()
block|; }
name|NCursesColorWindow
argument_list|(
argument|int lines
argument_list|,
comment|// number of lines
argument|int cols
argument_list|,
comment|// number of columns
argument|int begin_y
argument_list|,
comment|// line origin
argument|int begin_x
argument_list|)
comment|// col origin
operator|:
name|NCursesWindow
argument_list|(
argument|lines
argument_list|,
argument|cols
argument_list|,
argument|begin_y
argument_list|,
argument|begin_x
argument_list|)
block|{
name|useColors
argument_list|()
block|; }
name|NCursesColorWindow
argument_list|(
argument|NCursesWindow& par
argument_list|,
comment|// parent window
argument|int lines
argument_list|,
comment|// number of lines
argument|int cols
argument_list|,
comment|// number of columns
argument|int begin_y
argument_list|,
comment|// absolute or relative
argument|int begin_x
argument_list|,
comment|//   origins:
argument|char absrel =
literal|'a'
argument_list|)
comment|// if `a', by& bx are
operator|:
name|NCursesWindow
argument_list|(
argument|par
argument_list|,
argument|lines
argument_list|,
argument|cols
argument_list|,
comment|// absolute screen pos,
argument|begin_y
argument_list|,
argument|begin_x
argument_list|,
comment|// else if `r', they are
argument|absrel
argument_list|)
block|{
comment|// relative to par origin
name|useColors
argument_list|()
block|; }
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// These enum definitions really belong inside the NCursesPad class, but only
end_comment

begin_comment
comment|// recent compilers support that feature.
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|REQ_PAD_REFRESH
init|=
name|KEY_MAX
operator|+
literal|1
block|,
name|REQ_PAD_UP
block|,
name|REQ_PAD_DOWN
block|,
name|REQ_PAD_LEFT
block|,
name|REQ_PAD_RIGHT
block|,
name|REQ_PAD_EXIT
block|}
name|Pad_Request
typedef|;
end_typedef

begin_decl_stmt
specifier|const
name|Pad_Request
name|PAD_LOW
init|=
name|REQ_PAD_REFRESH
decl_stmt|;
end_decl_stmt

begin_comment
comment|// lowest  op-code
end_comment

begin_decl_stmt
specifier|const
name|Pad_Request
name|PAD_HIGH
init|=
name|REQ_PAD_EXIT
decl_stmt|;
end_decl_stmt

begin_comment
comment|// highest op-code
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// Pad Support. We allow an association of a pad with a "real" window
end_comment

begin_comment
comment|// through which the pad may be viewed.
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|NCursesPad
range|:
name|public
name|NCursesWindow
block|{
name|private
operator|:
name|NCursesWindow
operator|*
name|viewWin
block|;
comment|// the "viewport" window
name|NCursesWindow
operator|*
name|viewSub
block|;
comment|// the "viewport" subwindow
name|int
name|h_gridsize
block|,
name|v_gridsize
block|;
name|protected
operator|:
name|int
name|min_row
block|,
name|min_col
block|;
comment|// top left row/col of the pads display area
name|NCursesWindow
operator|*
name|Win
argument_list|(
argument|void
argument_list|)
specifier|const
block|{
comment|// Get the window into which the pad should be copied (if any)
return|return
operator|(
name|viewSub
operator|?
name|viewSub
operator|:
operator|(
name|viewWin
operator|?
name|viewWin
operator|:
literal|0
operator|)
operator|)
return|;
block|}
name|NCursesWindow
operator|*
name|getWindow
argument_list|(
argument|void
argument_list|)
specifier|const
block|{
return|return
name|viewWin
return|;
block|}
name|NCursesWindow
operator|*
name|getSubWindow
argument_list|(
argument|void
argument_list|)
specifier|const
block|{
return|return
name|viewSub
return|;
block|}
name|virtual
name|int
name|driver
argument_list|(
argument|int key
argument_list|)
block|;
comment|// Virtualize keystroke key
comment|// The driver translates the keystroke c into an Pad_Request
name|virtual
name|void
name|OnUnknownOperation
argument_list|(
argument|int pad_req
argument_list|)
block|{
operator|::
name|beep
argument_list|()
block|;   }
comment|// This is called if the driver returns an unknown op-code
name|virtual
name|void
name|OnNavigationError
argument_list|(
argument|int pad_req
argument_list|)
block|{
operator|::
name|beep
argument_list|()
block|;   }
comment|// This is called if a navigation request couldn't be satisfied
name|virtual
name|void
name|OnOperation
argument_list|(
argument|int pad_req
argument_list|)
block|{   }
block|;
comment|// OnOperation is called if a Pad_Operation was executed and just before
comment|// the refresh() operation is done.
name|public
operator|:
name|NCursesPad
argument_list|(
argument|int lines
argument_list|,
argument|int cols
argument_list|)
block|;
comment|// create a pad with the given size
name|virtual
operator|~
name|NCursesPad
argument_list|()
block|{}
name|int
name|echochar
argument_list|(
argument|const chtype ch
argument_list|)
block|{
return|return
operator|::
name|pechochar
argument_list|(
name|w
argument_list|,
name|ch
argument_list|)
return|;
block|}
comment|// Put the attributed character onto the pad and immediately do a
comment|// prefresh().
name|int
name|refresh
argument_list|()
block|;
comment|// If a viewport is defined the pad is displayed in this window, otherwise
comment|// this is a noop.
name|int
name|refresh
argument_list|(
argument|int pminrow
argument_list|,
argument|int pmincol
argument_list|,
argument|int sminrow
argument_list|,
argument|int smincol
argument_list|,
argument|int smaxrow
argument_list|,
argument|int smaxcol
argument_list|)
block|{
return|return
operator|::
name|prefresh
argument_list|(
name|w
argument_list|,
name|pminrow
argument_list|,
name|pmincol
argument_list|,
name|sminrow
argument_list|,
name|smincol
argument_list|,
name|smaxrow
argument_list|,
name|smaxcol
argument_list|)
return|;
block|}
comment|// The coordinates sminrow,smincol,smaxrow,smaxcol describe a rectangle
comment|// on the screen.<b>refresh</b> copies a rectangle of this size beginning
comment|// with top left corner pminrow,pmincol onto the screen and calls doupdate().
name|int
name|noutrefresh
argument_list|()
block|;
comment|// If a viewport is defined the pad is displayed in this window, otherwise
comment|// this is a noop.
name|int
name|noutrefresh
argument_list|(
argument|int pminrow
argument_list|,
argument|int pmincol
argument_list|,
argument|int sminrow
argument_list|,
argument|int smincol
argument_list|,
argument|int smaxrow
argument_list|,
argument|int smaxcol
argument_list|)
block|{
return|return
operator|::
name|pnoutrefresh
argument_list|(
name|w
argument_list|,
name|pminrow
argument_list|,
name|pmincol
argument_list|,
name|sminrow
argument_list|,
name|smincol
argument_list|,
name|smaxrow
argument_list|,
name|smaxcol
argument_list|)
return|;
block|}
comment|// Does the same like refresh() but without calling doupdate().
name|virtual
name|void
name|setWindow
argument_list|(
argument|NCursesWindow& view
argument_list|,
argument|int v_grid =
literal|1
argument_list|,
argument|int h_grid =
literal|1
argument_list|)
block|;
comment|// Add the window "view" as viewing window to the pad.
name|virtual
name|void
name|setSubWindow
argument_list|(
name|NCursesWindow
operator|&
name|sub
argument_list|)
block|;
comment|// Use the subwindow "sub" of the viewport window for the actual viewing.
comment|// The full viewport window is usually used to provide some decorations
comment|// like frames, titles etc.
name|virtual
name|void
name|operator
argument_list|()
argument_list|(
name|void
argument_list|)
block|;
comment|// Perform Pad's operation
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// A FramedPad is constructed always with a viewport window. This viewport
end_comment

begin_comment
comment|// will be framed (by a box() command) and the interior of the box is the
end_comment

begin_comment
comment|// viewport subwindow. On the frame we display scrollbar sliders.
end_comment

begin_decl_stmt
name|class
name|NCursesFramedPad
range|:
name|public
name|NCursesPad
block|{
name|protected
operator|:
name|virtual
name|void
name|OnOperation
argument_list|(
argument|int pad_req
argument_list|)
block|;
name|public
operator|:
name|NCursesFramedPad
argument_list|(
argument|NCursesWindow& win
argument_list|,
argument|int lines
argument_list|,
argument|int cols
argument_list|,
argument|int v_grid =
literal|1
argument_list|,
argument|int h_grid =
literal|1
argument_list|)
operator|:
name|NCursesPad
argument_list|(
argument|lines
argument_list|,
argument|cols
argument_list|)
block|{
name|NCursesPad
operator|::
name|setWindow
argument_list|(
name|win
argument_list|,
name|v_grid
argument_list|,
name|h_grid
argument_list|)
block|;
name|NCursesPad
operator|::
name|setSubWindow
argument_list|(
operator|*
operator|(
name|new
name|NCursesWindow
argument_list|(
name|win
argument_list|)
operator|)
argument_list|)
block|;   }
comment|// Construct the FramedPad with the given Window win as viewport.
name|virtual
operator|~
name|NCursesFramedPad
argument_list|()
block|{
name|delete
name|getSubWindow
argument_list|()
block|;   }
name|void
name|setWindow
argument_list|(
argument|NCursesWindow& view
argument_list|,
argument|int v_grid =
literal|1
argument_list|,
argument|int h_grid =
literal|1
argument_list|)
block|{
name|err_handler
argument_list|(
literal|"Operation not allowed"
argument_list|)
block|;   }
comment|// Disable this call; the viewport is already defined
name|void
name|setSubWindow
argument_list|(
argument|NCursesWindow& sub
argument_list|)
block|{
name|err_handler
argument_list|(
literal|"Operation not allowed"
argument_list|)
block|;   }
comment|// Disable this call; the viewport subwindow is already defined
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _CURSESW_H
end_comment

end_unit

