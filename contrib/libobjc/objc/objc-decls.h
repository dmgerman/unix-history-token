begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU Objective-C Extern helpers for Win32.    Copyright (C) 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files compiled    with GCC to produce an executable, this does not cause the resulting    executable to be covered by the GNU General Public License.  This    exception does not however invalidate any other reasons why the    executable file might be covered by the GNU General Public License. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__objc_decls_INCLUDE_GNU
end_ifndef

begin_define
define|#
directive|define
name|__objc_decls_INCLUDE_GNU
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__WIN32__
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|DLL_EXPORT
end_ifdef

begin_comment
comment|/* defined by libtool (if required) */
end_comment

begin_define
define|#
directive|define
name|objc_EXPORT
value|__declspec(dllexport)
end_define

begin_define
define|#
directive|define
name|objc_DECLARE
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|objc_EXPORT
value|extern __declspec(dllimport)
end_define

begin_define
define|#
directive|define
name|objc_DECLARE
value|extern __declspec(dllimport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|objc_EXPORT
value|extern
end_define

begin_define
define|#
directive|define
name|objc_DECLARE
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
comment|/* __objc_decls_INCLUDE_GNU */
end_comment

end_unit

