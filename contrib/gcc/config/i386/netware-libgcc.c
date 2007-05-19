begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Startup code for libgcc_s.nlm, necessary because we can't allow    libgcc_s to use libc's malloc& Co., which associate allocations    with the NLM owning the current (application) thread.    Contributed by Jan Beulich (jbeulich@novell.com)    Copyright (C) 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|<netware.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_decl_stmt
specifier|static
name|rtag_t
name|allocRTag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BOOL
name|DllMain
argument_list|(
name|HINSTANCE
name|libraryId
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
argument_list|,
name|DWORD
name|reason
argument_list|,
name|void
operator|*
name|hModule
argument_list|)
block|{
switch|switch
condition|(
name|reason
condition|)
block|{
case|case
name|DLL_NLM_STARTUP
case|:
name|allocRTag
operator|=
name|AllocateResourceTag
argument_list|(
name|hModule
argument_list|,
literal|"libgcc memory"
argument_list|,
name|AllocSignature
argument_list|)
expr_stmt|;
return|return
name|allocRTag
operator|!=
name|NULL
return|;
case|case
name|DLL_NLM_SHUTDOWN
case|:
comment|/* This does not recover resources associated with the tag...          ReturnResourceTag (allocRTag, 0); */
break|break;
block|}
return|return
literal|1
return|;
block|}
end_decl_stmt

begin_function
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
return|return
name|AllocSleepOK
argument_list|(
name|size
argument_list|,
name|allocRTag
argument_list|,
name|NULL
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|free
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|Free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

