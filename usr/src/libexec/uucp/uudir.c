begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* uudir.c    Create a directory owned by uucp.  This is Unix specific.     Copyright (C) 1992 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     The author of the program may be contacted at ian@airs.com or    c/o AIRS, P.O. Box 520, Waltham, MA 02254.     $Log: uudir.c,v $    Revision 1.1  1992/02/09  05:11:42  ian    Initial revision     */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_if
if|#
directive|if
name|USE_RCS_ID
end_if

begin_decl_stmt
name|char
name|uudir_rcsid
index|[]
init|=
literal|"$Id: uudir.c,v 1.1 1992/02/09 05:11:42 ian Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_if
if|#
directive|if
name|USE_STDIO
operator|&&
name|HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_comment
comment|/* External functions.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|setuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwnam
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* This is a simple program which sets its real uid to uucp and then    invokes /bin/mkdir.  It is only used if the system does not support    the mkdir system call.  It must be installed suid to root.     This program is needed because the UUCP programs will be run suid    to uucp.  On a system without the mkdir system call, /bin/mkdir is    a suid root program.  This means that /bin/mkdir always creates    directories using the real uid, rather than the effective uid.    This is wrong, since the UUCP programs always want to create    directories that are owned by uucp.  Therefore, this simple suid    root program is used to force /bin/mkdir into making a directory    owned by uucp.     If we made the program publically executable, this would mean that    anybody could create a directory owned by uucp.  This is probably    not a good thing, but since the program must be owned by root we    can't simply make it executable only by uucp.  Therefore, the    Makefile hides the program away in /usr/lib/uucp/util, and makes    that directory searchable only by uucp.  This should prevent    anybody else from getting to the program.     This is not a perfect solution, since any suid root program is by    definition a potential security hole.  I really can't see any way    to avoid this, though.  */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|struct
name|passwd
modifier|*
name|q
decl_stmt|;
specifier|const
name|char
modifier|*
name|zprog
decl_stmt|,
modifier|*
name|zname
decl_stmt|;
comment|/* We don't print any error messages, since this program should      never be run directly by a user.  */
if|if
condition|(
name|argc
operator|!=
literal|2
condition|)
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
comment|/* OWNER is passed in from the Makefile.  It will normally be      "uucp".  */
name|q
operator|=
name|getpwnam
argument_list|(
name|OWNER
argument_list|)
expr_stmt|;
if|if
condition|(
name|q
operator|==
name|NULL
condition|)
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
if|if
condition|(
name|setuid
argument_list|(
name|q
operator|->
name|pw_uid
argument_list|)
operator|<
literal|0
condition|)
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
name|zprog
operator|=
name|MKDIR_PROGRAM
expr_stmt|;
name|zname
operator|=
name|strrchr
argument_list|(
name|zprog
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
if|if
condition|(
name|zname
operator|==
name|NULL
condition|)
name|zname
operator|=
name|zprog
expr_stmt|;
else|else
operator|++
name|zname
expr_stmt|;
operator|(
name|void
operator|)
name|execl
argument_list|(
name|zprog
argument_list|,
name|zname
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

