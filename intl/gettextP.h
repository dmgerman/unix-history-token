begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header describing internals of libintl library.    Copyright (C) 1995-1999, 2000-2003 Free Software Foundation, Inc.    Written by Ulrich Drepper<drepper@cygnus.com>, 1995.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU Library General Public License as published    by the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301,    USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GETTEXTP_H
end_ifndef

begin_define
define|#
directive|define
name|_GETTEXTP_H
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* Get size_t.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_include
include|#
directive|include
file|"../iconv/gconv_int.h"
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_ICONV
end_if

begin_include
include|#
directive|include
file|<iconv.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"loadinfo.h"
end_include

begin_include
include|#
directive|include
file|"gmo.h"
end_include

begin_comment
comment|/* Get nls_uint32.  */
end_comment

begin_comment
comment|/* @@ end of prolog @@ */
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

begin_ifndef
ifndef|#
directive|ifndef
name|attribute_hidden
end_ifndef

begin_define
define|#
directive|define
name|attribute_hidden
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

begin_ifndef
ifndef|#
directive|ifndef
name|W
end_ifndef

begin_define
define|#
directive|define
name|W
parameter_list|(
name|flag
parameter_list|,
name|data
parameter_list|)
value|((flag) ? SWAP (data) : (data))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_include
include|#
directive|include
file|<byteswap.h>
end_include

begin_define
define|#
directive|define
name|SWAP
parameter_list|(
name|i
parameter_list|)
value|bswap_32 (i)
end_define

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
specifier|inline
name|nls_uint32
name|SWAP
parameter_list|(
name|i
parameter_list|)
name|nls_uint32
name|i
decl_stmt|;
block|{
return|return
operator|(
name|i
operator|<<
literal|24
operator|)
operator||
operator|(
operator|(
name|i
operator|&
literal|0xff00
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|i
operator|>>
literal|8
operator|)
operator|&
literal|0xff00
operator|)
operator||
operator|(
name|i
operator|>>
literal|24
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In-memory representation of system dependent string.  */
end_comment

begin_struct
struct|struct
name|sysdep_string_desc
block|{
comment|/* Length of addressed string, including the trailing NUL.  */
name|size_t
name|length
decl_stmt|;
comment|/* Pointer to addressed string.  */
specifier|const
name|char
modifier|*
name|pointer
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The representation of an opened message catalog.  */
end_comment

begin_struct
struct|struct
name|loaded_domain
block|{
comment|/* Pointer to memory containing the .mo file.  */
specifier|const
name|char
modifier|*
name|data
decl_stmt|;
comment|/* 1 if the memory is mmap()ed, 0 if the memory is malloc()ed.  */
name|int
name|use_mmap
decl_stmt|;
comment|/* Size of mmap()ed memory.  */
name|size_t
name|mmap_size
decl_stmt|;
comment|/* 1 if the .mo file uses a different endianness than this machine.  */
name|int
name|must_swap
decl_stmt|;
comment|/* Pointer to additional malloc()ed memory.  */
name|void
modifier|*
name|malloced
decl_stmt|;
comment|/* Number of static strings pairs.  */
name|nls_uint32
name|nstrings
decl_stmt|;
comment|/* Pointer to descriptors of original strings in the file.  */
specifier|const
name|struct
name|string_desc
modifier|*
name|orig_tab
decl_stmt|;
comment|/* Pointer to descriptors of translated strings in the file.  */
specifier|const
name|struct
name|string_desc
modifier|*
name|trans_tab
decl_stmt|;
comment|/* Number of system dependent strings pairs.  */
name|nls_uint32
name|n_sysdep_strings
decl_stmt|;
comment|/* Pointer to descriptors of original sysdep strings.  */
specifier|const
name|struct
name|sysdep_string_desc
modifier|*
name|orig_sysdep_tab
decl_stmt|;
comment|/* Pointer to descriptors of translated sysdep strings.  */
specifier|const
name|struct
name|sysdep_string_desc
modifier|*
name|trans_sysdep_tab
decl_stmt|;
comment|/* Size of hash table.  */
name|nls_uint32
name|hash_size
decl_stmt|;
comment|/* Pointer to hash table.  */
specifier|const
name|nls_uint32
modifier|*
name|hash_tab
decl_stmt|;
comment|/* 1 if the hash table uses a different endianness than this machine.  */
name|int
name|must_swap_hash_tab
decl_stmt|;
name|int
name|codeset_cntr
decl_stmt|;
ifdef|#
directive|ifdef
name|_LIBC
name|__gconv_t
name|conv
decl_stmt|;
else|#
directive|else
if|#
directive|if
name|HAVE_ICONV
name|iconv_t
name|conv
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|char
modifier|*
modifier|*
name|conv_tab
decl_stmt|;
name|struct
name|expression
modifier|*
name|plural
decl_stmt|;
name|unsigned
name|long
name|int
name|nplurals
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* We want to allocate a string at the end of the struct.  But ISO C    doesn't allow zero sized arrays.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|ZERO
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ZERO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A set of settings bound to a message domain.  Used to store settings    from bindtextdomain() and bind_textdomain_codeset().  */
end_comment

begin_struct
struct|struct
name|binding
block|{
name|struct
name|binding
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|dirname
decl_stmt|;
name|int
name|codeset_cntr
decl_stmt|;
comment|/* Incremented each time codeset changes.  */
name|char
modifier|*
name|codeset
decl_stmt|;
name|char
name|domainname
index|[
name|ZERO
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A counter which is incremented each time some previous translations    become invalid.    This variable is part of the external ABI of the GNU libintl.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_nl_msg_cat_cntr
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC
end_ifndef

begin_decl_stmt
specifier|const
name|char
modifier|*
name|_nl_locale_name
name|PARAMS
argument_list|(
operator|(
name|int
name|category
operator|,
specifier|const
name|char
operator|*
name|categoryname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|loaded_l10nfile
modifier|*
name|_nl_find_domain
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|__dirname
operator|,
name|char
operator|*
name|__locale
operator|,
specifier|const
name|char
operator|*
name|__domainname
operator|,
expr|struct
name|binding
operator|*
name|__domainbinding
operator|)
argument_list|)
name|internal_function
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_nl_load_domain
name|PARAMS
argument_list|(
operator|(
expr|struct
name|loaded_l10nfile
operator|*
name|__domain
operator|,
expr|struct
name|binding
operator|*
name|__domainbinding
operator|)
argument_list|)
name|internal_function
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_nl_unload_domain
name|PARAMS
argument_list|(
operator|(
expr|struct
name|loaded_domain
operator|*
name|__domain
operator|)
argument_list|)
name|internal_function
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|_nl_init_domain_conv
name|PARAMS
argument_list|(
operator|(
expr|struct
name|loaded_l10nfile
operator|*
name|__domain_file
operator|,
expr|struct
name|loaded_domain
operator|*
name|__domain
operator|,
expr|struct
name|binding
operator|*
name|__domainbinding
operator|)
argument_list|)
name|internal_function
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_nl_free_domain_conv
name|PARAMS
argument_list|(
operator|(
expr|struct
name|loaded_domain
operator|*
name|__domain
operator|)
argument_list|)
name|internal_function
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|_nl_find_msg
name|PARAMS
argument_list|(
operator|(
expr|struct
name|loaded_l10nfile
operator|*
name|domain_file
operator|,
expr|struct
name|binding
operator|*
name|domainbinding
operator|,
specifier|const
name|char
operator|*
name|msgid
operator|,
name|size_t
operator|*
name|lengthp
operator|)
argument_list|)
name|internal_function
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__gettext
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|__msgid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__dgettext
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|__domainname
operator|,
specifier|const
name|char
operator|*
name|__msgid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__dcgettext
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|__domainname
operator|,
specifier|const
name|char
operator|*
name|__msgid
operator|,
name|int
name|__category
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__ngettext
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|__msgid1
operator|,
specifier|const
name|char
operator|*
name|__msgid2
operator|,
name|unsigned
name|long
name|int
name|__n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__dngettext
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|__domainname
operator|,
specifier|const
name|char
operator|*
name|__msgid1
operator|,
specifier|const
name|char
operator|*
name|__msgid2
operator|,
name|unsigned
name|long
name|int
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__dcngettext
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|__domainname
operator|,
specifier|const
name|char
operator|*
name|__msgid1
operator|,
specifier|const
name|char
operator|*
name|__msgid2
operator|,
name|unsigned
name|long
name|int
name|__n
operator|,
name|int
name|__category
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__dcigettext
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|__domainname
operator|,
specifier|const
name|char
operator|*
name|__msgid1
operator|,
specifier|const
name|char
operator|*
name|__msgid2
operator|,
name|int
name|__plural
operator|,
name|unsigned
name|long
name|int
name|__n
operator|,
name|int
name|__category
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__textdomain
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|__domainname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__bindtextdomain
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|__domainname
operator|,
specifier|const
name|char
operator|*
name|__dirname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__bind_textdomain_codeset
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|__domainname
operator|,
specifier|const
name|char
operator|*
name|__codeset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Declare the exported libintl_* functions, in a way that allows us to    call them under their real name.  */
end_comment

begin_define
define|#
directive|define
name|_INTL_REDIRECT_MACROS
end_define

begin_include
include|#
directive|include
file|"libintl.h"
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|libintl_dcigettext
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|__domainname
operator|,
specifier|const
name|char
operator|*
name|__msgid1
operator|,
specifier|const
name|char
operator|*
name|__msgid2
operator|,
name|int
name|__plural
operator|,
name|unsigned
name|long
name|int
name|__n
operator|,
name|int
name|__category
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* @@ begin of epilog @@ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gettextP.h  */
end_comment

end_unit

