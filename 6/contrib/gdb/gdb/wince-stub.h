begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* wince-stub.h -- Definitions for commnicating with the WinCE stub.     Copyright 1999, 2000 Free Software Foundation, Inc.    Contributed by Cygnus Solutions, A Red Hat Company.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without eve nthe implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* by Christopher Faylor (cgf@cygnus.com) */
end_comment

begin_enum
enum|enum
name|win_func
block|{
name|GDB_CREATEPROCESS
init|=
literal|42
block|,
name|GDB_TERMINATEPROCESS
block|,
name|GDB_WAITFORDEBUGEVENT
block|,
name|GDB_GETTHREADCONTEXT
block|,
name|GDB_SETTHREADCONTEXT
block|,
name|GDB_READPROCESSMEMORY
block|,
name|GDB_WRITEPROCESSMEMORY
block|,
name|GDB_THREADALIVE
block|,
name|GDB_SUSPENDTHREAD
block|,
name|GDB_RESUMETHREAD
block|,
name|GDB_CONTINUEDEBUGEVENT
block|,
name|GDB_CLOSEHANDLE
block|,
name|GDB_STOPSTUB
block|,
name|GDB_SINGLESTEP
block|,
name|GDB_SETBREAK
block|,
name|GDB_INVALID
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|unsigned
name|char
name|gdb_wince_id
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|gdb_wince_len
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|gdb_wince_result
typedef|;
end_typedef

end_unit

