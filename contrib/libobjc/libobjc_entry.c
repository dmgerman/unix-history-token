begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU Objective C Runtime DLL Entry    Copyright (C) 1997 Free Software Foundation, Inc.    Contributed by Scott Christley<scottc@net-community.com>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files compiled with    GCC to produce an executable, this does not cause the resulting executable    to be covered by the GNU General Public License. This exception does not    however invalidate any other reasons why the executable file might be    covered by the GNU General Public License.  */
end_comment

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_comment
comment|/*   DLL entry function for Objective-C Runtime library   This function gets called everytime a process/thread attaches to DLL   */
end_comment

begin_function
name|WINBOOL
name|WINAPI
name|DllMain
parameter_list|(
name|HANDLE
name|hInst
parameter_list|,
name|ULONG
name|ul_reason_for_call
parameter_list|,
name|LPVOID
name|lpReserved
parameter_list|)
block|{
switch|switch
condition|(
name|ul_reason_for_call
condition|)
block|{
case|case
name|DLL_PROCESS_ATTACH
case|:
break|break;
case|case
name|DLL_PROCESS_DETACH
case|:
break|break;
case|case
name|DLL_THREAD_ATTACH
case|:
break|break;
case|case
name|DLL_THREAD_DETACH
case|:
break|break;
block|}
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/*   This section terminates the list of imports under GCC. If you do not   include this then you will have problems when linking with DLLs.   */
end_comment

begin_asm
asm|asm (".section .idata$3\n" ".long 0,0,0,0,0,0,0,0");
end_asm

end_unit

