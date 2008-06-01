begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1989 Free Software Foundation     written by Eric Newton (newton@rocky.oswego.edu)  This file is part of the GNU C++ Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details. You should have received a copy of the GNU Library General Public License along with this library; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CursesWindow_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_CursesWindow_h
end_define

begin_include
include|#
directive|include
file|<_G_config.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_begx
value|begx
end_define

begin_define
define|#
directive|define
name|_begy
value|begy
end_define

begin_define
define|#
directive|define
name|_maxx
value|maxx
end_define

begin_define
define|#
directive|define
name|_maxy
value|maxy
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_G_HAVE_CURSES
end_if

begin_comment
comment|// Even many system which mostly have C++-ready header files,
end_comment

begin_comment
comment|// do not have C++-ready curses.h.
end_comment

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
comment|/* SCO 3.2v4 curses.h includes term.h, which defines lines as a macro.    Undefine it here, because CursesWindow uses lines as a method.  */
end_comment

begin_undef
undef|#
directive|undef
name|lines
end_undef

begin_comment
comment|// "Convert" macros to inlines, if needed.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|addch
end_ifdef

begin_function
specifier|inline
name|int
function|(
name|addch
function|)
parameter_list|(
name|char
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
function|(
name|clearok
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
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
name|int
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
function|(
name|flushok
function|)
parameter_list|(
name|WINDOW
modifier|*
name|_win
parameter_list|,
name|int
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
function|(
name|getyx
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
name|int
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
function|(
name|leaveok
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
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
name|int
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
function|(
name|rfresh
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
function|(
name|scrollok
function|)
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
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

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|hpux
end_ifndef

begin_extern
extern|extern
literal|"C"
name|int
name|scrollok
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
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
name|standend
end_ifdef

begin_function
specifier|inline
name|int
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
name|int
function|(
name|winch
function|)
parameter_list|(
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* deal with conflicting macros in ncurses.h  which is SYSV based*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|box
end_ifdef

begin_function
specifier|inline
name|int
name|_G_box
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|chtype
name|v
parameter_list|,
name|chtype
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

begin_function
specifier|inline
name|int
name|box
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|chtype
name|v
parameter_list|,
name|chtype
name|h
parameter_list|)
block|{
return|return
name|_G_box
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
name|char
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
name|int
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
name|char
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
name|int
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  * C++ class for windows.  *  *  */
end_comment

begin_decl_stmt
name|class
name|CursesWindow
block|{
name|protected
label|:
specifier|static
name|int
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
name|int
name|alloced
decl_stmt|;
comment|// true if we own the WINDOW
name|CursesWindow
modifier|*
name|par
decl_stmt|;
comment|// parent, if subwindow
name|CursesWindow
modifier|*
name|subwins
decl_stmt|;
comment|// head of subwindows list
name|CursesWindow
modifier|*
name|sib
decl_stmt|;
comment|// next subwindow of parent
name|void
name|kill_subwindows
parameter_list|()
function_decl|;
comment|// disable all subwindows
name|public
label|:
name|CursesWindow
argument_list|(
name|WINDOW
operator|*
operator|&
name|window
argument_list|)
expr_stmt|;
comment|// useful only for stdscr
name|CursesWindow
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
name|CursesWindow
argument_list|(
argument|CursesWindow& par
argument_list|,
comment|// parent window
argument|int lines
argument_list|,
comment|// number of lines
argument|int cols
argument_list|,
comment|// number of columns
argument|int by
argument_list|,
comment|// absolute or relative
argument|int bx
argument_list|,
comment|//   origins:
argument|char absrel =
literal|'a'
argument_list|)
empty_stmt|;
comment|// if `a', by& bx are
comment|// absolute screen pos,
comment|// else if `r', they are
comment|// relative to par origin
operator|~
name|CursesWindow
argument_list|()
expr_stmt|;
comment|// terminal status
name|int
name|lines
parameter_list|()
function_decl|;
comment|// number of lines on terminal, *not* window
name|int
name|cols
parameter_list|()
function_decl|;
comment|// number of cols  on terminal, *not* window
comment|// window status
name|int
name|height
parameter_list|()
function_decl|;
comment|// number of lines in this window
name|int
name|width
parameter_list|()
function_decl|;
comment|// number of cols in this window
name|int
name|begx
parameter_list|()
function_decl|;
comment|// smallest x coord in window
name|int
name|begy
parameter_list|()
function_decl|;
comment|// smallest y coord in window
name|int
name|maxx
parameter_list|()
function_decl|;
comment|// largest  x coord in window
name|int
name|maxy
parameter_list|()
function_decl|;
comment|// largest  x coord in window
comment|// window positioning
name|int
name|move
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
function_decl|;
comment|// coordinate positioning
name|void
name|getyx
parameter_list|(
name|int
modifier|&
name|y
parameter_list|,
name|int
modifier|&
name|x
parameter_list|)
function_decl|;
name|int
name|mvcur
parameter_list|(
name|int
name|sy
parameter_list|,
name|int
name|ey
parameter_list|,
name|int
name|sx
parameter_list|,
name|int
name|ex
parameter_list|)
function_decl|;
comment|// input
name|int
name|getch
parameter_list|()
function_decl|;
name|int
name|getstr
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
name|int
name|scanw
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
comment|// input + positioning
name|int
name|mvgetch
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
function_decl|;
name|int
name|mvgetstr
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
function_decl|;
name|int
name|mvscanw
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
comment|// output
name|int
name|addch
parameter_list|(
specifier|const
name|char
name|ch
parameter_list|)
function_decl|;
name|int
name|addstr
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
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
function_decl|;
name|int
name|inch
parameter_list|()
function_decl|;
name|int
name|insch
parameter_list|(
name|char
name|c
parameter_list|)
function_decl|;
name|int
name|insertln
parameter_list|()
function_decl|;
comment|// output + positioning
name|int
name|mvaddch
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|char
name|ch
parameter_list|)
function_decl|;
name|int
name|mvaddstr
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
function_decl|;
name|int
name|mvprintw
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
function_decl|;
name|int
name|mvinch
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
function_decl|;
name|int
name|mvinsch
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|char
name|ch
parameter_list|)
function_decl|;
comment|// borders
name|int
name|box
parameter_list|(
name|char
name|vert
parameter_list|,
name|char
name|hor
parameter_list|)
function_decl|;
comment|// erasure
name|int
name|erase
parameter_list|()
function_decl|;
name|int
name|clear
parameter_list|()
function_decl|;
name|int
name|clearok
parameter_list|(
name|int
name|bf
parameter_list|)
function_decl|;
name|int
name|clrtobot
parameter_list|()
function_decl|;
name|int
name|clrtoeol
parameter_list|()
function_decl|;
name|int
name|delch
parameter_list|()
function_decl|;
name|int
name|mvdelch
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
function_decl|;
name|int
name|deleteln
parameter_list|()
function_decl|;
comment|// screen control
name|int
name|scroll
parameter_list|()
function_decl|;
name|int
name|scrollok
parameter_list|(
name|int
name|bf
parameter_list|)
function_decl|;
name|int
name|touchwin
parameter_list|()
function_decl|;
name|int
name|refresh
parameter_list|()
function_decl|;
name|int
name|leaveok
parameter_list|(
name|int
name|bf
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|_no_flushok
name|int
name|flushok
parameter_list|(
name|int
name|bf
parameter_list|)
function_decl|;
endif|#
directive|endif
name|int
name|standout
parameter_list|()
function_decl|;
name|int
name|standend
parameter_list|()
function_decl|;
comment|// multiple window control
name|int
name|overlay
parameter_list|(
name|CursesWindow
modifier|&
name|win
parameter_list|)
function_decl|;
name|int
name|overwrite
parameter_list|(
name|CursesWindow
modifier|&
name|win
parameter_list|)
function_decl|;
comment|// traversal support
name|CursesWindow
modifier|*
name|child
parameter_list|()
function_decl|;
name|CursesWindow
modifier|*
name|sibling
parameter_list|()
function_decl|;
name|CursesWindow
modifier|*
name|parent
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|begx
argument_list|()
block|{
return|return
name|w
operator|->
name|_begx
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|begy
argument_list|()
block|{
return|return
name|w
operator|->
name|_begy
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|maxx
argument_list|()
block|{
return|return
name|w
operator|->
name|_maxx
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|maxy
argument_list|()
block|{
return|return
name|w
operator|->
name|_maxy
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|height
argument_list|()
block|{
return|return
name|maxy
argument_list|()
operator|-
name|begy
argument_list|()
operator|+
literal|1
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|width
argument_list|()
block|{
return|return
name|maxx
argument_list|()
operator|-
name|begx
argument_list|()
operator|+
literal|1
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|box
argument_list|(
argument|char vert
argument_list|,
argument|char  hor
argument_list|)
block|{
return|return
operator|::
name|box
argument_list|(
name|w
argument_list|,
name|vert
argument_list|,
name|hor
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|overlay
argument_list|(
argument|CursesWindow&win
argument_list|)
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
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|overwrite
argument_list|(
argument|CursesWindow&win
argument_list|)
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
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|scroll
argument_list|()
block|{
return|return
operator|::
name|scroll
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|touchwin
argument_list|()
block|{
return|return
operator|::
name|touchwin
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|addch
argument_list|(
argument|const char ch
argument_list|)
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
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|addstr
argument_list|(
argument|const char * str
argument_list|)
block|{
comment|// The (char*) cast is to hack around prototypes in curses.h that
comment|// have const missing in the parameter lists.  [E.g. SVR4]
return|return
operator|::
name|waddstr
argument_list|(
name|w
argument_list|,
operator|(
name|char
operator|*
operator|)
name|str
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|clear
argument_list|()
block|{
return|return
operator|::
name|wclear
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|clrtobot
argument_list|()
block|{
return|return
operator|::
name|wclrtobot
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|clrtoeol
argument_list|()
block|{
return|return
operator|::
name|wclrtoeol
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|delch
argument_list|()
block|{
return|return
operator|::
name|wdelch
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|deleteln
argument_list|()
block|{
return|return
operator|::
name|wdeleteln
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|erase
argument_list|()
block|{
return|return
operator|::
name|werase
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|getch
argument_list|()
block|{
return|return
operator|::
name|wgetch
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|getstr
argument_list|(
argument|char * str
argument_list|)
block|{
return|return
operator|::
name|wgetstr
argument_list|(
name|w
argument_list|,
name|str
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|inch
argument_list|()
block|{
return|return
name|winch
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|insch
argument_list|(
argument|char c
argument_list|)
block|{
return|return
operator|::
name|winsch
argument_list|(
name|w
argument_list|,
name|c
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|insertln
argument_list|()
block|{
return|return
operator|::
name|winsertln
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|move
argument_list|(
argument|int y
argument_list|,
argument|int x
argument_list|)
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
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|mvcur
argument_list|(
argument|int sy
argument_list|,
argument|int ey
argument_list|,
argument|int sx
argument_list|,
argument|int ex
argument_list|)
block|{
return|return
operator|::
name|mvcur
argument_list|(
name|sy
argument_list|,
name|ey
argument_list|,
name|sx
argument_list|,
name|ex
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|mvaddch
argument_list|(
argument|int y
argument_list|,
argument|int x
argument_list|,
argument|char ch
argument_list|)
block|{
return|return
operator|(
operator|::
name|wmove
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
operator|==
name|ERR
operator|)
operator|?
name|ERR
operator|:
operator|::
name|waddch
argument_list|(
name|w
argument_list|,
name|ch
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|mvgetch
argument_list|(
argument|int y
argument_list|,
argument|int x
argument_list|)
block|{
return|return
operator|(
operator|::
name|wmove
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
operator|==
name|ERR
operator|)
operator|?
name|ERR
operator|:
operator|::
name|wgetch
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|mvaddstr
argument_list|(
argument|int y
argument_list|,
argument|int x
argument_list|,
argument|const char * str
argument_list|)
block|{
return|return
operator|(
operator|::
name|wmove
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
operator|==
name|ERR
operator|)
operator|?
name|ERR
operator|:
operator|::
name|waddstr
argument_list|(
name|w
argument_list|,
operator|(
name|char
operator|*
operator|)
name|str
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|mvgetstr
argument_list|(
argument|int y
argument_list|,
argument|int x
argument_list|,
argument|char * str
argument_list|)
block|{
return|return
operator|(
operator|::
name|wmove
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
operator|==
name|ERR
operator|)
operator|?
name|ERR
operator|:
operator|::
name|wgetstr
argument_list|(
name|w
argument_list|,
name|str
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|mvinch
argument_list|(
argument|int y
argument_list|,
argument|int x
argument_list|)
block|{
return|return
operator|(
operator|::
name|wmove
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
operator|==
name|ERR
operator|)
operator|?
name|ERR
operator|:
operator|::
name|winch
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|mvdelch
argument_list|(
argument|int y
argument_list|,
argument|int x
argument_list|)
block|{
return|return
operator|(
operator|::
name|wmove
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
operator|==
name|ERR
operator|)
operator|?
name|ERR
operator|:
operator|::
name|wdelch
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|mvinsch
argument_list|(
argument|int y
argument_list|,
argument|int x
argument_list|,
argument|char ch
argument_list|)
block|{
return|return
operator|(
operator|::
name|wmove
argument_list|(
name|w
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
operator|==
name|ERR
operator|)
operator|?
name|ERR
operator|:
operator|::
name|winsch
argument_list|(
name|w
argument_list|,
name|ch
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|refresh
argument_list|()
block|{
return|return
operator|::
name|wrefresh
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|clearok
argument_list|(
argument|int bf
argument_list|)
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
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|leaveok
argument_list|(
argument|int bf
argument_list|)
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
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|scrollok
argument_list|(
argument|int bf
argument_list|)
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
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_no_flushok
end_ifndef

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|flushok
argument_list|(
argument|int bf
argument_list|)
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
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
specifier|inline
name|void
name|CursesWindow
operator|::
name|getyx
argument_list|(
argument|int& y
argument_list|,
argument|int& x
argument_list|)
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
block|;  }
specifier|inline
name|int
name|CursesWindow
operator|::
name|standout
argument_list|()
block|{
return|return
operator|::
name|wstandout
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|standend
argument_list|()
block|{
return|return
operator|::
name|wstandend
argument_list|(
name|w
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|lines
argument_list|()
block|{
return|return
name|LINES
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|CursesWindow
operator|::
name|cols
argument_list|()
block|{
return|return
name|COLS
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|CursesWindow
operator|*
name|CursesWindow
operator|::
name|child
argument_list|()
block|{
return|return
name|subwins
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|CursesWindow
operator|*
name|CursesWindow
operator|::
name|parent
argument_list|()
block|{
return|return
name|par
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|CursesWindow
operator|*
name|CursesWindow
operator|::
name|sibling
argument_list|()
block|{
return|return
name|sib
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _G_HAVE_CURSES */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

