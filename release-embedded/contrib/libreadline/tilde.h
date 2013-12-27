begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tilde.h: Externally available variables and function in libtilde.a. */
end_comment

begin_comment
comment|/* Copyright (C) 1992 Free Software Foundation, Inc.     This file contains the Readline Library (the Library), a set of    routines for providing Emacs style line input to programs that ask    for it.     The Library is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     The Library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_TILDE_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_TILDE_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* A function can be defined using prototypes and compile on both ANSI C    and traditional C compilers with something like this: 	extern char *func PARAMS((char *, char *, int)); */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PARAMS
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
define|#
directive|define
name|PARAMS
parameter_list|(
name|protos
parameter_list|)
value|protos
else|#
directive|else
define|#
directive|define
name|PARAMS
parameter_list|(
name|protos
parameter_list|)
value|()
endif|#
directive|endif
endif|#
directive|endif
typedef|typedef
name|char
modifier|*
name|tilde_hook_func_t
name|PARAMS
typedef|((
name|char
modifier|*
typedef|));
comment|/* If non-null, this contains the address of a function that the application    wants called before trying the standard tilde expansions.  The function    is called with the text sans tilde, and returns a malloc()'ed string    which is the expansion, or a NULL pointer if the expansion fails. */
specifier|extern
name|tilde_hook_func_t
modifier|*
name|tilde_expansion_preexpansion_hook
decl_stmt|;
comment|/* If non-null, this contains the address of a function to call if the    standard meaning for expanding a tilde fails.  The function is called    with the text (sans tilde, as in "foo"), and returns a malloc()'ed string    which is the expansion, or a NULL pointer if there is no expansion. */
specifier|extern
name|tilde_hook_func_t
modifier|*
name|tilde_expansion_failure_hook
decl_stmt|;
comment|/* When non-null, this is a NULL terminated array of strings which    are duplicates for a tilde prefix.  Bash uses this to expand    `=~' and `:~'. */
specifier|extern
name|char
modifier|*
modifier|*
name|tilde_additional_prefixes
decl_stmt|;
comment|/* When non-null, this is a NULL terminated array of strings which match    the end of a username, instead of just "/".  Bash sets this to    `:' and `=~'. */
specifier|extern
name|char
modifier|*
modifier|*
name|tilde_additional_suffixes
decl_stmt|;
comment|/* Return a new string which is the result of tilde expanding STRING. */
specifier|extern
name|char
modifier|*
name|tilde_expand
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Do the work of tilde expansion on FILENAME.  FILENAME starts with a    tilde.  If there is no expansion, call tilde_expansion_failure_hook. */
specifier|extern
name|char
modifier|*
name|tilde_expand_word
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Find the portion of the string beginning with ~ that should be expanded. */
specifier|extern
name|char
modifier|*
name|tilde_find_word
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TILDE_H_ */
end_comment

end_unit

