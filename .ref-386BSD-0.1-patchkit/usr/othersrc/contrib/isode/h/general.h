begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* general.h - general compatibility */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/general.h,v 7.5 91/02/22 09:24:42 mrose Interim $  *  *  * $Log:	general.h,v $  * Revision 7.5  91/02/22  09:24:42  mrose  * Interim 6.8  *   * Revision 7.4  90/12/23  18:41:46  mrose  * update  *   * Revision 7.3  90/10/17  14:39:15  mrose  * update  *   * Revision 7.2  90/07/09  14:37:45  mrose  * sync  *   * Revision 7.1  90/03/06  14:10:28  mrose  * jch  *   * Revision 7.0  89/11/23  21:55:44  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GENERAL_
end_ifndef

begin_define
define|#
directive|define
name|_GENERAL_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_CONFIG_
end_ifndef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_comment
comment|/* system-specific configuration */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* target-dependent defines:  	BSDFORK -	target has BSD vfork 	BSDLIBC -	target has real BSD libc 	BSDSTRS -	target has BSD strings 	SWABLIB -	target has byteorder(3n) routines  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SOCKETS
end_ifdef

begin_define
define|#
directive|define
name|SWABLIB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WINTLI
end_ifdef

begin_define
define|#
directive|define
name|SWABLIB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EXOS
end_ifdef

begin_define
define|#
directive|define
name|SWABLIB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD42
end_ifdef

begin_define
define|#
directive|define
name|BSDFORK
end_define

begin_define
define|#
directive|define
name|BSDLIBC
end_define

begin_define
define|#
directive|define
name|BSDSTRS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ROS
end_ifdef

begin_undef
undef|#
directive|undef
name|BSDFORK
end_undef

begin_undef
undef|#
directive|undef
name|BSDLIBC
end_undef

begin_define
define|#
directive|define
name|BSDSTRS
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BSD42
end_ifndef

begin_define
define|#
directive|define
name|BSD42
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|SWABLIB
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYS5
end_ifdef

begin_undef
undef|#
directive|undef
name|BSDFORK
end_undef

begin_undef
undef|#
directive|undef
name|BSDLIBC
end_undef

begin_undef
undef|#
directive|undef
name|BSDSTRS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sgi
end_ifdef

begin_undef
undef|#
directive|undef
name|BSDFORK
end_undef

begin_undef
undef|#
directive|undef
name|BSDLIBC
end_undef

begin_undef
undef|#
directive|undef
name|BSDSTRS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX
end_ifdef

begin_define
define|#
directive|define
name|BSDFORK
end_define

begin_undef
undef|#
directive|undef
name|BSDLIBC
end_undef

begin_undef
undef|#
directive|undef
name|BSDSTRS
end_undef

begin_undef
undef|#
directive|undef
name|SWABLIB
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|pyr
end_ifdef

begin_undef
undef|#
directive|undef
name|SWABLIB
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|XOS
end_ifdef

begin_undef
undef|#
directive|undef
name|SWABLIB
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|XOS_2
end_ifdef

begin_undef
undef|#
directive|undef
name|SWABLIB
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|apollo
end_ifdef

begin_undef
undef|#
directive|undef
name|SWABLIB
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUX
end_ifdef

begin_undef
undef|#
directive|undef
name|BSDFORK
end_undef

begin_define
define|#
directive|define
name|BSDSTRS
end_define

begin_undef
undef|#
directive|undef
name|SWABLIB
end_undef

begin_define
define|#
directive|define
name|BSDLIBC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BSDFORK
end_ifndef

begin_define
define|#
directive|define
name|vfork
value|fork
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|STRINGS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSDSTRS
end_ifndef

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mktemp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSDSTRS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSD44
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|BSD43
argument_list|)
operator|||
name|defined
argument_list|(
name|SUNOS4
argument_list|)
operator|||
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|RT
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|mips
argument_list|)
operator|&&
name|defined
argument_list|(
name|ultrix
argument_list|)
operator|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|XOS_2
argument_list|)
end_if

begin_function_decl
name|char
modifier|*
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strcmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strlen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strncat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strncmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strncpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|calloc
argument_list|()
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|realloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS5
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|AIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|XOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|XOS_2
argument_list|)
end_if

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|length
parameter_list|)
value|(void) memcpy ((b2), (b1), (length))
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|length
parameter_list|)
value|memcmp ((b1), (b2), (length))
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|b
parameter_list|,
name|length
parameter_list|)
value|(void) memset ((b), 0, (length))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|HEXIFY */
end_comment

begin_decl_stmt
name|int
name|explode
argument_list|()
decl_stmt|,
name|implode
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|SPRINTB */
end_comment

begin_function_decl
name|char
modifier|*
name|sprintb
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|STR2VEC */
end_comment

begin_define
define|#
directive|define
name|NVEC
value|100
end_define

begin_define
define|#
directive|define
name|NSLACK
value|10
end_define

begin_define
define|#
directive|define
name|str2vec
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|str2vecX ((s), (v), 0, NULLIP, NULL, 1)
end_define

begin_function_decl
name|int
name|str2vecX
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|STR2ELEM */
end_comment

begin_define
define|#
directive|define
name|NELEM
value|20
end_define

begin_function_decl
name|int
name|str2elem
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|STR2SEL */
end_comment

begin_function_decl
name|int
name|str2sel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|sel2str
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|GETPASS */
end_comment

begin_function_decl
name|char
modifier|*
name|getpassword
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|BADUSER */
end_comment

begin_function_decl
name|int
name|baduser
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|UTILITIES */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|chrcnv
index|[]
decl_stmt|,
name|nochrcnv
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lexequ
argument_list|()
decl_stmt|,
name|lexnequ
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|log_tai
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sstr2arg
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|smalloc
argument_list|()
decl_stmt|,
modifier|*
name|strdup
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|MISC */
end_comment

begin_function_decl
name|char
modifier|*
name|sys_errname
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|insque
parameter_list|(
name|e
parameter_list|,
name|p
parameter_list|)
value|INSQUE ((char *) (e), (char *) (p))
end_define

begin_define
define|#
directive|define
name|remque
parameter_list|(
name|e
parameter_list|)
value|REMQUE ((char *) (e))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|asprintf
argument_list|()
decl_stmt|,
name|_asprintf
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|isodetailor
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* also in tailor.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ntohs
end_ifndef

begin_function_decl
name|unsigned
name|short
name|ntohs
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|htons
end_ifndef

begin_function_decl
name|unsigned
name|short
name|htons
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ntohl
end_ifndef

begin_function_decl
name|unsigned
name|long
name|ntohl
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|htonl
end_ifndef

begin_function_decl
name|unsigned
name|long
name|htonl
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

