begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* cu.h    Header file for cu.     Copyright (C) 1992 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
end_comment

begin_comment
comment|/* The user settable variables supported by cu.  */
end_comment

begin_comment
comment|/* The escape character used to introduce a special command.  The    escape character is the first character of this string.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zCuvar_escape
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether to delay for a second before printing the host name after    seeing an escape character.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fCuvar_delay
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The input characters which finish a line.  The escape character is    only recognized following one of these characters.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zCuvar_eol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether to transfer binary data (nonprintable characters other than    newline and tab) when sending a file.  If this is FALSE, then    newline is changed to carriage return.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fCuvar_binary
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A prefix string to use before sending a binary character from a    file; this is only used if fCuvar_binary is TRUE.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zCuvar_binary_prefix
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether to check for echoes of characters sent when sending a file.    This is ignored if fCuvar_binary is TRUE.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fCuvar_echocheck
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A character to look for after each newline is sent when sending a    file.  The character is the first character in this string, except    that a '\0' means that no echo check is done.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zCuvar_echonl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The timeout to use when looking for an character.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cCuvar_timeout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The character to use to kill a line if an echo check fails.  The    first character in this string is sent.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zCuvar_kill
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of times to try resending a line if the echo check keeps    failing.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cCuvar_resend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The string to send at the end of a file sent with ~>.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zCuvar_eofwrite
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The string to look for to finish a file received with ~<.  For tip    this is a collection of single characters, but I don't want to do    that because it means that there are characters which cannot be    received.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zCuvar_eofread
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether to provide verbose information when sending or receiving a    file.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fCuvar_verbose
decl_stmt|;
end_decl_stmt

end_unit

