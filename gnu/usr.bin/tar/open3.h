begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Defines for Sys V style 3-argument open call.    Copyright (C) 1988 Free Software Foundation  This file is part of GNU Tar.  GNU Tar is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Tar is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Tar; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * open3.h -- #defines for the various flags for the Sys V style 3-argument  * open() call.  On BSD or System 5, the system already has this in an  * include file.  This file is needed for V7 and MINIX systems for the  * benefit of open3() in port.c, a routine that emulates the 3-argument  * call using system calls available on V7/MINIX.  *  * This file is needed by PD tar even if we aren't using the  * emulator, since the #defines for O_WRONLY, etc. are used in  * a couple of places besides the open() calls, (e.g. in the assignment  * to openflag in extract.c).  We just #include this rather than  * #ifdef them out.  *  * Written 6/10/87 by rmtodd@uokmax (Richard Todd).  *  * The names have been changed by John Gilmore, 31 July 1987, since  * Richard called it "bsdopen", and really this change was introduced in  * AT&T Unix systems before BSD picked it up.  */
end_comment

begin_comment
comment|/* Only one of the next three should be specified */
end_comment

begin_define
define|#
directive|define
name|O_RDONLY
value|0
end_define

begin_comment
comment|/* only allow read */
end_comment

begin_define
define|#
directive|define
name|O_WRONLY
value|1
end_define

begin_comment
comment|/* only allow write */
end_comment

begin_define
define|#
directive|define
name|O_RDWR
value|2
end_define

begin_comment
comment|/* both are allowed */
end_comment

begin_comment
comment|/* The rest of these can be OR-ed in to the above. */
end_comment

begin_comment
comment|/*  * O_NDELAY isn't implemented by the emulator.  It's only useful (to tar) on  * systems that have named pipes anyway; it prevents tar's hanging by  * opening a named pipe.  We #ifndef it because some systems already have  * it defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|O_NDELAY
end_ifndef

begin_define
define|#
directive|define
name|O_NDELAY
value|4
end_define

begin_comment
comment|/* don't block on opening devices that would 			    * block on open -- ignored by emulator. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|O_CREAT
value|8
end_define

begin_comment
comment|/* create file if needed */
end_comment

begin_define
define|#
directive|define
name|O_EXCL
value|16
end_define

begin_comment
comment|/* file cannot already exist */
end_comment

begin_define
define|#
directive|define
name|O_TRUNC
value|32
end_define

begin_comment
comment|/* truncate file on open */
end_comment

begin_define
define|#
directive|define
name|O_APPEND
value|64
end_define

begin_comment
comment|/* always write at end of file -- ignored by emul */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EMUL_OPEN3
end_ifdef

begin_comment
comment|/*  * make emulation transparent to rest of file -- redirect all open() calls  * to our routine  */
end_comment

begin_define
define|#
directive|define
name|open
value|open3
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

