begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU Emacs password definition file.    Copyright (C) 1986 Free Software Foundation.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_comment
comment|/* On VMS, we read the UAF file and emulate some of the necessary    fields for Emacs. */
end_comment

begin_include
include|#
directive|include
file|"uaf.h"
end_include

begin_struct
struct|struct
name|passwd
block|{
name|char
name|pw_name
index|[
name|UAF$S_USERNAME
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|pw_passwd
index|[
name|UAF$S_PWD
index|]
decl_stmt|;
name|short
name|pw_uid
decl_stmt|;
name|short
name|pw_gid
decl_stmt|;
name|char
name|pw_gecos
index|[
name|UAF$S_OWNER
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|pw_dir
index|[
name|UAF$S_DEFDEV
operator|+
name|UAF$S_DEFDIR
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|pw_shell
index|[
name|UAF$S_DEFCLI
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

end_unit

