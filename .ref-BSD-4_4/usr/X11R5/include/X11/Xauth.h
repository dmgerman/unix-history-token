begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Xau - X Authorization Database Library  *  * $XConsortium: Xauth.h,v 1.12 91/07/15 18:12:39 gildea Exp $  *  * Copyright 1988 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * Author:  Keith Packard, MIT X Consortium  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_Xauth_h
end_ifndef

begin_define
define|#
directive|define
name|_Xauth_h
end_define

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|FamilyLocal
value|(256)
end_define

begin_comment
comment|/* not part of X standard (i.e. X.h) */
end_comment

begin_define
define|#
directive|define
name|FamilyWild
value|(65535)
end_define

begin_define
define|#
directive|define
name|FamilyNetname
value|(254)
end_define

begin_comment
comment|/* not part of X standard */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xauth
block|{
name|unsigned
name|short
name|family
decl_stmt|;
name|unsigned
name|short
name|address_length
decl_stmt|;
name|char
modifier|*
name|address
decl_stmt|;
name|unsigned
name|short
name|number_length
decl_stmt|;
name|char
modifier|*
name|number
decl_stmt|;
name|unsigned
name|short
name|name_length
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|short
name|data_length
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|Xauth
typedef|;
end_typedef

begin_function_decl
name|_XFUNCPROTOBEGIN
name|char
modifier|*
name|XauFileName
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Xauth
modifier|*
name|XauReadAuth
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|FILE
modifier|*
comment|/* auth_file */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XauLockAuth
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* file_name */
parameter_list|,
name|int
comment|/* retries */
parameter_list|,
name|int
comment|/* timeout */
parameter_list|,
name|long
comment|/* dead */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XauUnlockAuth
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* file_name */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|XauWriteAuth
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|FILE
modifier|*
comment|/* auth_file */
parameter_list|,
name|Xauth
modifier|*
comment|/* auth */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Xauth
modifier|*
name|XauGetAuthByName
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* display_name */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Xauth
modifier|*
name|XauGetAuthByAddr
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
if|#
directive|if
name|NeedWidePrototypes
name|unsigned
name|int
comment|/* family */
parameter_list|,
name|unsigned
name|int
comment|/* address_length */
parameter_list|,
else|#
directive|else
name|unsigned
name|short
comment|/* family */
parameter_list|,
name|unsigned
name|short
comment|/* address_length */
parameter_list|,
endif|#
directive|endif
name|_Xconst
name|char
modifier|*
comment|/* address */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
name|unsigned
name|int
comment|/* number_length */
parameter_list|,
else|#
directive|else
name|unsigned
name|short
comment|/* number_length */
parameter_list|,
endif|#
directive|endif
name|_Xconst
name|char
modifier|*
comment|/* number */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
name|unsigned
name|int
comment|/* name_length */
parameter_list|,
else|#
directive|else
name|unsigned
name|short
comment|/* name_length */
parameter_list|,
endif|#
directive|endif
name|_Xconst
name|char
modifier|*
comment|/* name */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Xauth
modifier|*
name|XauGetBestAuthByAddr
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
if|#
directive|if
name|NeedWidePrototypes
name|unsigned
name|int
comment|/* family */
parameter_list|,
name|unsigned
name|int
comment|/* address_length */
parameter_list|,
else|#
directive|else
name|unsigned
name|short
comment|/* family */
parameter_list|,
name|unsigned
name|short
comment|/* address_length */
parameter_list|,
endif|#
directive|endif
name|_Xconst
name|char
modifier|*
comment|/* address */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
name|unsigned
name|int
comment|/* number_length */
parameter_list|,
else|#
directive|else
name|unsigned
name|short
comment|/* number_length */
parameter_list|,
endif|#
directive|endif
name|_Xconst
name|char
modifier|*
comment|/* number */
parameter_list|,
name|int
comment|/* types_length */
parameter_list|,
name|char
modifier|*
modifier|*
comment|/* type_names */
parameter_list|,
name|_Xconst
name|int
modifier|*
comment|/* type_lengths */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|XauDisposeAuth
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Xauth
modifier|*
comment|/* auth */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_comment
comment|/* Return values from XauLockAuth */
end_comment

begin_define
define|#
directive|define
name|LOCK_SUCCESS
value|0
end_define

begin_comment
comment|/* lock succeeded */
end_comment

begin_define
define|#
directive|define
name|LOCK_ERROR
value|1
end_define

begin_comment
comment|/* lock unexpectely failed, check errno */
end_comment

begin_define
define|#
directive|define
name|LOCK_TIMEOUT
value|2
end_define

begin_comment
comment|/* lock failed, timeouts expired */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _Xauth_h */
end_comment

end_unit

