begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Provide relocatable packages.    Copyright (C) 2003 Free Software Foundation, Inc.    Written by Bruno Haible<bruno@clisp.org>, 2003.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU Library General Public License as published    by the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301,    USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RELOCATABLE_H
end_ifndef

begin_define
define|#
directive|define
name|_RELOCATABLE_H
end_define

begin_comment
comment|/* This can be enabled through the configure --enable-relocatable option.  */
end_comment

begin_if
if|#
directive|if
name|ENABLE_RELOCATABLE
end_if

begin_comment
comment|/* When building a DLL, we must export some functions.  Note that because    this is a private .h file, we don't need to use __declspec(dllimport)    in any case.  */
end_comment

begin_if
if|#
directive|if
name|defined
name|_MSC_VER
operator|&&
name|BUILDING_DLL
end_if

begin_define
define|#
directive|define
name|RELOCATABLE_DLL_EXPORTED
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RELOCATABLE_DLL_EXPORTED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sets the original and the current installation prefix of the package.    Relocation simply replaces a pathname starting with the original prefix    by the corresponding pathname with the current prefix instead.  Both    prefixes should be directory names without trailing slash (i.e. use ""    instead of "/").  */
end_comment

begin_function_decl
specifier|extern
name|RELOCATABLE_DLL_EXPORTED
name|void
name|set_relocation_prefix
parameter_list|(
specifier|const
name|char
modifier|*
name|orig_prefix
parameter_list|,
specifier|const
name|char
modifier|*
name|curr_prefix
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the pathname, relocated according to the current installation    directory.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|relocate
parameter_list|(
specifier|const
name|char
modifier|*
name|pathname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Memory management: relocate() leaks memory, because it has to construct    a fresh pathname.  If this is a problem because your program calls    relocate() frequently, think about caching the result.  */
end_comment

begin_comment
comment|/* Convenience function:    Computes the current installation prefix, based on the original    installation prefix, the original installation directory of a particular    file, and the current pathname of this file.  Returns NULL upon failure.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|compute_curr_prefix
parameter_list|(
specifier|const
name|char
modifier|*
name|orig_installprefix
parameter_list|,
specifier|const
name|char
modifier|*
name|orig_installdir
parameter_list|,
specifier|const
name|char
modifier|*
name|curr_pathname
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* By default, we use the hardwired pathnames.  */
end_comment

begin_define
define|#
directive|define
name|relocate
parameter_list|(
name|pathname
parameter_list|)
value|(pathname)
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
comment|/* _RELOCATABLE_H */
end_comment

end_unit

