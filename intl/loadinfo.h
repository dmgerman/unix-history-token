begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1996-1999, 2000-2002 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Contributed by Ulrich Drepper<drepper@cygnus.com>, 1996.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU Library General Public License as published    by the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301,    USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOADINFO_H
end_ifndef

begin_define
define|#
directive|define
name|_LOADINFO_H
value|1
end_define

begin_comment
comment|/* Declarations of locale dependent catalog lookup functions.    Implemented in       localealias.c    Possibly replace a locale name by another.      explodename.c    Split a locale name into its various fields.      l10nflist.c      Generate a list of filenames of possible message catalogs.      finddomain.c     Find and open the relevant message catalogs.     The main function _nl_find_domain() in finddomain.c is declared    in gettextP.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|defined
name|__GNUC__
operator|||
name|defined
name|__SUNPRO_C
operator|||
name|defined
name|__cplusplus
operator|||
name|__PROTOTYPES
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|internal_function
end_ifndef

begin_define
define|#
directive|define
name|internal_function
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tell the compiler when a conditional or integer expression is    almost always true or almost always false.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_BUILTIN_EXPECT
end_ifndef

begin_define
define|#
directive|define
name|__builtin_expect
parameter_list|(
name|expr
parameter_list|,
name|val
parameter_list|)
value|(expr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Separator in PATH like lists of pathnames.  */
end_comment

begin_if
if|#
directive|if
name|defined
name|_WIN32
operator|||
name|defined
name|__WIN32__
operator|||
name|defined
name|__EMX__
operator|||
name|defined
name|__DJGPP__
end_if

begin_comment
comment|/* Win32, OS/2, DOS */
end_comment

begin_define
define|#
directive|define
name|PATH_SEPARATOR
value|';'
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Unix */
end_comment

begin_define
define|#
directive|define
name|PATH_SEPARATOR
value|':'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Encoding of locale name parts.  */
end_comment

begin_define
define|#
directive|define
name|CEN_REVISION
value|1
end_define

begin_define
define|#
directive|define
name|CEN_SPONSOR
value|2
end_define

begin_define
define|#
directive|define
name|CEN_SPECIAL
value|4
end_define

begin_define
define|#
directive|define
name|XPG_NORM_CODESET
value|8
end_define

begin_define
define|#
directive|define
name|XPG_CODESET
value|16
end_define

begin_define
define|#
directive|define
name|TERRITORY
value|32
end_define

begin_define
define|#
directive|define
name|CEN_AUDIENCE
value|64
end_define

begin_define
define|#
directive|define
name|XPG_MODIFIER
value|128
end_define

begin_define
define|#
directive|define
name|CEN_SPECIFIC
value|(CEN_REVISION|CEN_SPONSOR|CEN_SPECIAL|CEN_AUDIENCE)
end_define

begin_define
define|#
directive|define
name|XPG_SPECIFIC
value|(XPG_CODESET|XPG_NORM_CODESET|XPG_MODIFIER)
end_define

begin_struct
struct|struct
name|loaded_l10nfile
block|{
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
name|int
name|decided
decl_stmt|;
specifier|const
name|void
modifier|*
name|data
decl_stmt|;
name|struct
name|loaded_l10nfile
modifier|*
name|next
decl_stmt|;
name|struct
name|loaded_l10nfile
modifier|*
name|successor
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Normalize codeset name.  There is no standard for the codeset    names.  Normalization allows the user to use any of the common    names.  The return value is dynamically allocated and has to be    freed by the caller.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|_nl_normalize_codeset
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|codeset
operator|,
name|size_t
name|name_len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lookup a locale dependent file.    *L10NFILE_LIST denotes a pool of lookup results of locale dependent    files of the same kind, sorted in decreasing order of ->filename.    DIRLIST and DIRLIST_LEN are an argz list of directories in which to    look, containing at least one directory (i.e. DIRLIST_LEN> 0).    MASK, LANGUAGE, TERRITORY, CODESET, NORMALIZED_CODESET, MODIFIER,    SPECIAL, SPONSOR, REVISION are the pieces of the locale name, as    produced by _nl_explode_name().  FILENAME is the filename suffix.    The return value is the lookup result, either found in *L10NFILE_LIST,    or - if DO_ALLOCATE is nonzero - freshly allocated, or possibly NULL.    If the return value is non-NULL, it is added to *L10NFILE_LIST, and    its ->next field denotes the chaining inside *L10NFILE_LIST, and    furthermore its ->successor[] field contains a list of other lookup    results from which this lookup result inherits.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|loaded_l10nfile
modifier|*
name|_nl_make_l10nflist
name|PARAMS
argument_list|(
operator|(
expr|struct
name|loaded_l10nfile
operator|*
operator|*
name|l10nfile_list
operator|,
specifier|const
name|char
operator|*
name|dirlist
operator|,
name|size_t
name|dirlist_len
operator|,
name|int
name|mask
operator|,
specifier|const
name|char
operator|*
name|language
operator|,
specifier|const
name|char
operator|*
name|territory
operator|,
specifier|const
name|char
operator|*
name|codeset
operator|,
specifier|const
name|char
operator|*
name|normalized_codeset
operator|,
specifier|const
name|char
operator|*
name|modifier
operator|,
specifier|const
name|char
operator|*
name|special
operator|,
specifier|const
name|char
operator|*
name|sponsor
operator|,
specifier|const
name|char
operator|*
name|revision
operator|,
specifier|const
name|char
operator|*
name|filename
operator|,
name|int
name|do_allocate
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lookup the real locale name for a locale alias NAME, or NULL if    NAME is not a locale alias (but possibly a real locale name).    The return value is statically allocated and must not be freed.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|_nl_expand_alias
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Split a locale name NAME into its pieces: language, modifier,    territory, codeset, special, sponsor, revision.    NAME gets destructively modified: NUL bytes are inserted here and    there.  *LANGUAGE gets assigned NAME.  Each of *MODIFIER, *TERRITORY,    *CODESET, *SPECIAL, *SPONSOR, *REVISION gets assigned either a    pointer into the old NAME string, or NULL.  *NORMALIZED_CODESET    gets assigned the expanded *CODESET, if it is different from *CODESET;    this one is dynamically allocated and has to be freed by the caller.    The return value is a bitmask, where each bit corresponds to one    filled-in value:      XPG_MODIFIER, CEN_AUDIENCE  for *MODIFIER,      TERRITORY                   for *TERRITORY,      XPG_CODESET                 for *CODESET,      XPG_NORM_CODESET            for *NORMALIZED_CODESET,      CEN_SPECIAL                 for *SPECIAL,      CEN_SPONSOR                 for *SPONSOR,      CEN_REVISION                for *REVISION.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_nl_explode_name
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
specifier|const
name|char
operator|*
operator|*
name|language
operator|,
specifier|const
name|char
operator|*
operator|*
name|modifier
operator|,
specifier|const
name|char
operator|*
operator|*
name|territory
operator|,
specifier|const
name|char
operator|*
operator|*
name|codeset
operator|,
specifier|const
name|char
operator|*
operator|*
name|normalized_codeset
operator|,
specifier|const
name|char
operator|*
operator|*
name|special
operator|,
specifier|const
name|char
operator|*
operator|*
name|sponsor
operator|,
specifier|const
name|char
operator|*
operator|*
name|revision
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Split a locale name NAME into a leading language part and all the    rest.  Return a pointer to the first character after the language,    i.e. to the first byte of the rest.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_nl_find_language
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* loadinfo.h */
end_comment

end_unit

