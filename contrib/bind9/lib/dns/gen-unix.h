begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: gen-unix.h,v 1.12.12.5 2005/06/09 23:54:29 marka Exp $ */
end_comment

begin_comment
comment|/*  * This file is responsible for defining two operations that are not  * directly portable between Unix-like systems and Windows NT, option  * parsing and directory scanning.  It is here because it was decided  * that the "gen" build utility was not to depend on libisc.a, so  * the functions delcared in isc/commandline.h and isc/dir.h could not  * be used.  *  * The commandline stuff is really just a wrapper around getopt().  * The dir stuff was shrunk to fit the needs of gen.c.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_GEN_UNIX_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_GEN_UNIX_H
value|1
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Required on some systems for dirent.h. */
end_comment

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/* XXXDCL Required for ?. */
end_comment

begin_include
include|#
directive|include
file|<isc/boolean.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_OPTARG
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|isc_commandline_parse
value|getopt
end_define

begin_define
define|#
directive|define
name|isc_commandline_argument
value|optarg
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|DIR
modifier|*
name|handle
decl_stmt|;
name|char
modifier|*
name|filename
decl_stmt|;
block|}
name|isc_dir_t
typedef|;
end_typedef

begin_function
name|ISC_LANG_BEGINDECLS
specifier|static
name|isc_boolean_t
name|start_directory
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|isc_dir_t
modifier|*
name|dir
parameter_list|)
block|{
name|dir
operator|->
name|handle
operator|=
name|opendir
argument_list|(
name|path
argument_list|)
expr_stmt|;
if|if
condition|(
name|dir
operator|->
name|handle
operator|!=
name|NULL
condition|)
return|return
operator|(
name|ISC_TRUE
operator|)
return|;
else|else
return|return
operator|(
name|ISC_FALSE
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|isc_boolean_t
name|next_file
parameter_list|(
name|isc_dir_t
modifier|*
name|dir
parameter_list|)
block|{
name|struct
name|dirent
modifier|*
name|dirent
decl_stmt|;
name|dir
operator|->
name|filename
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|dir
operator|->
name|handle
operator|!=
name|NULL
condition|)
block|{
name|dirent
operator|=
name|readdir
argument_list|(
name|dir
operator|->
name|handle
argument_list|)
expr_stmt|;
if|if
condition|(
name|dirent
operator|!=
name|NULL
condition|)
name|dir
operator|->
name|filename
operator|=
name|dirent
operator|->
name|d_name
expr_stmt|;
block|}
if|if
condition|(
name|dir
operator|->
name|filename
operator|!=
name|NULL
condition|)
return|return
operator|(
name|ISC_TRUE
operator|)
return|;
else|else
return|return
operator|(
name|ISC_FALSE
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|end_directory
parameter_list|(
name|isc_dir_t
modifier|*
name|dir
parameter_list|)
block|{
if|if
condition|(
name|dir
operator|->
name|handle
operator|!=
name|NULL
condition|)
operator|(
name|void
operator|)
name|closedir
argument_list|(
name|dir
operator|->
name|handle
argument_list|)
expr_stmt|;
name|dir
operator|->
name|handle
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_GEN_UNIX_H */
end_comment

end_unit

