begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* general.c - general utilities for emulation of 4.2BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: /f/osi/compat/RCS/general.c,v 7.3 91/02/22 09:15:10 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/compat/RCS/general.c,v 7.3 91/02/22 09:15:10 mrose Interim $  *  *  * $Log:	general.c,v $  * Revision 7.3  91/02/22  09:15:10  mrose  * Interim 6.8  *   * Revision 7.2  91/02/12  18:30:43  mrose  * update  *   * Revision 7.1  91/01/14  13:33:48  mrose  * loader  *   * Revision 7.0  89/11/23  21:23:00  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"general.h"
end_include

begin_include
include|#
directive|include
file|"manifest.h"
end_include

begin_comment
comment|/*
comment|Berkeley UNIX: 4.2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD42
end_ifdef

begin_comment
comment|/* Simply including "general.h" is sufficient. */
end_comment

begin_function
name|int
name|_general_stub
parameter_list|()
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_undef
undef|#
directive|undef
name|BSDLIBC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|non-Berkeley UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSDLIBC
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_struct
struct|struct
name|qelem
block|{
name|struct
name|qelem
modifier|*
name|q_forw
decl_stmt|;
name|struct
name|qelem
modifier|*
name|q_back
decl_stmt|;
name|char
name|q_data
index|[
literal|1
index|]
decl_stmt|;
comment|/* extensible */
block|}
struct|;
end_struct

begin_macro
name|insque
argument_list|(
argument|elem
argument_list|,
argument|pred
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|qelem
modifier|*
name|elem
decl_stmt|,
modifier|*
name|pred
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|pred
operator|->
name|q_forw
operator|->
name|q_back
operator|=
name|elem
expr_stmt|;
name|elem
operator|->
name|q_forw
operator|=
name|pred
operator|->
name|q_forw
expr_stmt|;
name|elem
operator|->
name|q_back
operator|=
name|pred
expr_stmt|;
name|pred
operator|->
name|q_forw
operator|=
name|elem
expr_stmt|;
block|}
end_block

begin_macro
name|remque
argument_list|(
argument|elem
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|qelem
modifier|*
name|elem
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|elem
operator|->
name|q_forw
operator|->
name|q_back
operator|=
name|elem
operator|->
name|q_back
expr_stmt|;
name|elem
operator|->
name|q_back
operator|->
name|q_forw
operator|=
name|elem
operator|->
name|q_forw
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|DUP2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD42
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SYS5
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|dup2
parameter_list|(
name|d1
parameter_list|,
name|d2
parameter_list|)
specifier|register
name|int
name|d1
decl_stmt|,
name|d2
decl_stmt|;
block|{
name|int
name|d
decl_stmt|;
if|if
condition|(
name|d1
operator|==
name|d2
condition|)
return|return
name|OK
return|;
operator|(
name|void
operator|)
name|close
argument_list|(
name|d2
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|F_DUPFD
if|if
condition|(
operator|(
name|d
operator|=
name|fcntl
argument_list|(
name|d1
argument_list|,
name|F_DUPFD
argument_list|,
name|d2
argument_list|)
operator|)
operator|==
name|NOTOK
condition|)
return|return
name|NOTOK
return|;
else|#
directive|else
if|if
condition|(
operator|(
name|d
operator|=
name|dup2_aux
argument_list|(
name|d1
argument_list|,
name|d2
argument_list|)
operator|)
operator|==
name|NOTOK
condition|)
return|return
name|NOTOK
return|;
endif|#
directive|endif
if|if
condition|(
name|d
operator|==
name|d2
condition|)
return|return
name|OK
return|;
name|errno
operator|=
literal|0
expr_stmt|;
return|return
name|NOTOK
return|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|F_DUPFD
end_ifndef

begin_macro
name|dup2_aux
argument_list|(
argument|d1
argument_list|,
argument|d2
argument_list|)
end_macro

begin_decl_stmt
name|int
name|d1
decl_stmt|,
name|d2
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|fd
decl_stmt|,
name|result
decl_stmt|;
if|if
condition|(
operator|(
name|fd
operator|=
name|dup
argument_list|(
name|d1
argument_list|)
operator|)
operator|==
name|NOTOK
operator|||
name|fd
operator|==
name|d2
condition|)
return|return
name|fd
return|;
name|result
operator|=
name|dup2_aux
argument_list|(
name|d1
argument_list|,
name|d2
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|BYTEORDER */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SWABLIB
end_ifndef

begin_comment
comment|/* ROS and HP-UX don't seem to have these in libc.a */
end_comment

begin_undef
undef|#
directive|undef
name|ntohs
end_undef

begin_function
name|u_short
name|ntohs
parameter_list|(
name|netshort
parameter_list|)
name|u_short
name|netshort
decl_stmt|;
block|{
return|return
name|netshort
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|htons
end_undef

begin_function
name|u_short
name|htons
parameter_list|(
name|hostshort
parameter_list|)
name|u_short
name|hostshort
decl_stmt|;
block|{
return|return
name|hostshort
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|ntohl
end_undef

begin_function
name|u_long
name|ntohl
parameter_list|(
name|netlong
parameter_list|)
name|u_long
name|netlong
decl_stmt|;
block|{
return|return
name|netlong
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|htonl
end_undef

begin_function
name|u_long
name|htonl
parameter_list|(
name|hostlong
parameter_list|)
name|u_long
name|hostlong
decl_stmt|;
block|{
return|return
name|hostlong
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

