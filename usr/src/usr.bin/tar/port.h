begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Portability declarations.    Copyright (C) 1988 Free Software Foundation  This file is part of GNU Tar.  GNU Tar is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Tar is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Tar; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * Portability declarations for tar.  *  * @(#)port.h 1.3	87/11/11	by John Gilmore, 1986  */
end_comment

begin_comment
comment|/*  * Everybody does wait() differently.  There seem to be no definitions  * for this in V7 (e.g. you are supposed to shift and mask things out  * using constant shifts and masks.)  So fuck 'em all -- my own non  * standard but portable macros.  Don't change to a "union wait"  * based approach -- the ordering of the elements of the struct   * depends on the byte-sex of the machine.  Foo!  */
end_comment

begin_define
define|#
directive|define
name|TERM_SIGNAL
parameter_list|(
name|status
parameter_list|)
value|((status)& 0x7F)
end_define

begin_define
define|#
directive|define
name|TERM_COREDUMP
parameter_list|(
name|status
parameter_list|)
value|(((status)& 0x80) != 0)
end_define

begin_define
define|#
directive|define
name|TERM_VALUE
parameter_list|(
name|status
parameter_list|)
value|((status)>> 8)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_comment
comment|/* missing things from sys/stat.h */
end_comment

begin_define
define|#
directive|define
name|S_ISUID
value|0
end_define

begin_define
define|#
directive|define
name|S_ISGID
value|0
end_define

begin_define
define|#
directive|define
name|S_ISVTX
value|0
end_define

begin_comment
comment|/* device stuff */
end_comment

begin_define
define|#
directive|define
name|makedev
parameter_list|(
name|ma
parameter_list|,
name|mi
parameter_list|)
value|((ma<< 8) | mi)
end_define

begin_define
define|#
directive|define
name|major
parameter_list|(
name|dev
parameter_list|)
value|(dev)
end_define

begin_define
define|#
directive|define
name|minor
parameter_list|(
name|dev
parameter_list|)
value|(dev)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSDOS */
end_comment

end_unit

