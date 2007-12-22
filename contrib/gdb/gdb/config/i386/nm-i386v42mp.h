begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native support for i386 running SVR4.    Copyright 1986, 1987, 1989, 1992, 1996, 1997, 1998    Free Software Foundation, Inc.    Changes for 80386 by Pace Willisson (pace@prep.ai.mit.edu), July 1988.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_I386V42MP_H
end_ifndef

begin_define
define|#
directive|define
name|NM_I386V42MP_H
end_define

begin_include
include|#
directive|include
file|"config/nm-sysv4.h"
end_include

begin_comment
comment|/* define to select for other sysv4.2mp weirdness (see procfs.c) */
end_comment

begin_define
define|#
directive|define
name|UNIXWARE
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* The following macros extract process and lwp/thread ids from a    composite id.     For consistency with UnixWare core files, allocate bits 0-15 for    process ids and bits 16 and up for lwp ids.  Reserve bit 31 for    negative return values to indicate exceptions, and use bit 30 as a    flag to indicate a user-mode thread, leaving 14 bits for lwp    ids. */
end_comment

begin_comment
comment|/* Number of bits in composite id allocated to process number. */
end_comment

begin_define
define|#
directive|define
name|PIDBITS
value|16
end_define

begin_comment
comment|/* Return the process id stored in composite PID. */
end_comment

begin_define
define|#
directive|define
name|PIDGET
parameter_list|(
name|PID
parameter_list|)
value|(((PID)& ((1<< PIDBITS) - 1)))
end_define

begin_comment
comment|/* Return the thread or lwp id stored in composite PID. */
end_comment

begin_define
define|#
directive|define
name|TIDGET
parameter_list|(
name|PID
parameter_list|)
value|(((PID)& 0x3fffffff)>> PIDBITS)
end_define

begin_define
define|#
directive|define
name|LIDGET
parameter_list|(
name|PID
parameter_list|)
value|TIDGET(PID)
end_define

begin_comment
comment|/* Construct a composite id from lwp LID and the process portion of    composite PID. */
end_comment

begin_define
define|#
directive|define
name|MERGEPID
parameter_list|(
name|PID
parameter_list|,
name|LID
parameter_list|)
value|(PIDGET(PID) | ((LID)<< PIDBITS))
end_define

begin_define
define|#
directive|define
name|MKLID
parameter_list|(
name|PID
parameter_list|,
name|LID
parameter_list|)
value|MERGEPID(PID, LID)
end_define

begin_comment
comment|/* Construct a composite id from thread TID and the process portion of    composite PID. */
end_comment

begin_define
define|#
directive|define
name|MKTID
parameter_list|(
name|PID
parameter_list|,
name|TID
parameter_list|)
value|(MERGEPID(PID, TID) | 0x40000000)
end_define

begin_comment
comment|/* Return whether PID contains a user-space thread id. */
end_comment

begin_define
define|#
directive|define
name|ISTID
parameter_list|(
name|PID
parameter_list|)
value|((PID)& 0x40000000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* New definitions of the ptid stuff.  Due to the way the    code is structured in uw-thread.c, I'm overloading the thread id    and lwp id onto the lwp field.  The tid field is used to indicate    whether the lwp is a tid or not.          FIXME: Check that core file support is not broken.  (See original    #if 0'd comments above.)    FIXME: Restructure uw-thread.c so that the struct ptid fields    can be used as intended. */
end_comment

begin_comment
comment|/* Return the process id stored in composite PID. */
end_comment

begin_define
define|#
directive|define
name|PIDGET
parameter_list|(
name|PID
parameter_list|)
value|(ptid_get_pid (PID))
end_define

begin_comment
comment|/* Return the thread or lwp id stored in composite PID. */
end_comment

begin_define
define|#
directive|define
name|TIDGET
parameter_list|(
name|PID
parameter_list|)
value|(ptid_get_lwp (PID))
end_define

begin_define
define|#
directive|define
name|LIDGET
parameter_list|(
name|PID
parameter_list|)
value|TIDGET(PID)
end_define

begin_define
define|#
directive|define
name|MERGEPID
parameter_list|(
name|PID
parameter_list|,
name|LID
parameter_list|)
value|(ptid_build ((PID), (LID), 0))
end_define

begin_define
define|#
directive|define
name|MKLID
parameter_list|(
name|PID
parameter_list|,
name|LID
parameter_list|)
value|(ptid_build ((PID), (LID), 0))
end_define

begin_comment
comment|/* Construct a composite id from thread TID and the process portion of    composite PID. */
end_comment

begin_define
define|#
directive|define
name|MKTID
parameter_list|(
name|PID
parameter_list|,
name|TID
parameter_list|)
value|(ptid_build ((PID), (TID), 1))
end_define

begin_comment
comment|/* Return whether PID contains a user-space thread id. */
end_comment

begin_define
define|#
directive|define
name|ISTID
parameter_list|(
name|PID
parameter_list|)
value|(ptid_get_tid (PID))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NM_I386V42MP_H */
end_comment

end_unit

