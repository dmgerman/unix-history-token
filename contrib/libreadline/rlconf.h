begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rlconf.h -- readline configuration definitions */
end_comment

begin_comment
comment|/* Copyright (C) 1994 Free Software Foundation, Inc.     This file contains the Readline Library (the Library), a set of    routines for providing Emacs style line input to programs that ask    for it.     The Library is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.     The Library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_RLCONF_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_RLCONF_H_
end_define

begin_comment
comment|/* Define this if you want the vi-mode editing available. */
end_comment

begin_define
define|#
directive|define
name|VI_MODE
end_define

begin_comment
comment|/* Define this to get an indication of file type when listing completions. */
end_comment

begin_define
define|#
directive|define
name|VISIBLE_STATS
end_define

begin_comment
comment|/* If defined, readline shows opening parens and braces when closing    paren or brace entered. */
end_comment

begin_define
define|#
directive|define
name|PAREN_MATCHING
end_define

begin_comment
comment|/* This definition is needed by readline.c, rltty.c, and signals.c. */
end_comment

begin_comment
comment|/* If on, then readline handles signals in a way that doesn't screw. */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SIGNALS
end_define

begin_comment
comment|/* Ugly but working hack for binding prefix meta. */
end_comment

begin_define
define|#
directive|define
name|PREFIX_META_HACK
end_define

begin_comment
comment|/* The final, last-ditch effort file name for an init file. */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_INPUTRC
value|"~/.inputrc"
end_define

begin_comment
comment|/* If defined, expand tabs to spaces. */
end_comment

begin_define
define|#
directive|define
name|DISPLAY_TABS
end_define

begin_comment
comment|/* If defined, use the terminal escape sequence to move the cursor forward    over a character when updating the line rather than rewriting it. */
end_comment

begin_comment
comment|/* #define HACK_TERMCAP_MOTION */
end_comment

begin_comment
comment|/* The string inserted by the `insert comment' command. */
end_comment

begin_define
define|#
directive|define
name|RL_COMMENT_BEGIN_DEFAULT
value|"#"
end_define

begin_comment
comment|/* Define this if you want code that allows readline to be used in an    X `callback' style. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SHELL
argument_list|)
end_if

begin_define
define|#
directive|define
name|READLINE_CALLBACKS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RLCONF_H_ */
end_comment

end_unit

