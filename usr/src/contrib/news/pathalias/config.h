begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pathalias -- by steve bellovin, as told to peter honeyman */
end_comment

begin_comment
comment|/**************************************************************************  * +--------------------------------------------------------------------+ *  * |                    begin configuration section                     | *  * +--------------------------------------------------------------------+ *  **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|STRCHR
end_define

begin_comment
comment|/* have strchr -- system v and many others */
end_comment

begin_undef
undef|#
directive|undef
name|UNAME
end_undef

begin_comment
comment|/* have uname() -- probably system v or 8th ed. */
end_comment

begin_define
define|#
directive|define
name|MEMSET
end_define

begin_comment
comment|/* have memset() -- probably system v or 8th ed. */
end_comment

begin_define
define|#
directive|define
name|GETHOSTNAME
end_define

begin_comment
comment|/* have gethostname() -- probably bsd */
end_comment

begin_define
define|#
directive|define
name|BZERO
end_define

begin_comment
comment|/* have bzero() -- probably bsd */
end_comment

begin_define
define|#
directive|define
name|RESOLVER
end_define

begin_comment
comment|/* have internet domain name resolver */
end_comment

begin_comment
comment|/* default place for dbm output of makedb (or use -o at run-time) */
end_comment

begin_define
define|#
directive|define
name|ALIASDB
value|"/usr/local/lib/palias"
end_define

begin_comment
comment|/**************************************************************************  * +--------------------------------------------------------------------+ *  * |                    end of configuration section                    | *  * +--------------------------------------------------------------------+ *  **************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAIN
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|c_sccsid
init|=
literal|"@(#)config.h	9.5 91/06/11"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*lint*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*MAIN*/
end_comment

begin_comment
comment|/* the usual case: unix */
end_comment

begin_define
define|#
directive|define
name|NULL_DEVICE
value|"/dev/null"
end_define

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_define
define|#
directive|define
name|ERROR
value|1
end_define

begin_define
define|#
directive|define
name|SEVERE_ERROR
value|(-1)
end_define

begin_define
define|#
directive|define
name|STDIO_H
value|<stdio.h>
end_define

begin_define
define|#
directive|define
name|CTYPE_H
value|<ctype.h>
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_include
include|#
directive|include
include|ssdef
end_include

begin_include
include|#
directive|include
include|stsdef
end_include

begin_undef
undef|#
directive|undef
name|NULL_DEVICE
end_undef

begin_define
define|#
directive|define
name|NULL_DEVICE
value|"NL:"
end_define

begin_undef
undef|#
directive|undef
name|OK
end_undef

begin_define
define|#
directive|define
name|OK
value|SS$_NORMAL
end_define

begin_undef
undef|#
directive|undef
name|ERROR
end_undef

begin_define
define|#
directive|define
name|ERROR
value|(STS$K_ERROR|STS$M_INHIB_MSG)
end_define

begin_undef
undef|#
directive|undef
name|SEVERE_ERROR
end_undef

begin_define
define|#
directive|define
name|SEVERE_ERROR
value|(STS$K_SEVERE|STS$M_INHIB_MSG)
end_define

begin_undef
undef|#
directive|undef
name|STDIO_H
end_undef

begin_define
define|#
directive|define
name|STDIO_H
value|stdio
end_define

begin_undef
undef|#
directive|undef
name|CTYPE_H
end_undef

begin_define
define|#
directive|define
name|CTYPE_H
value|ctype
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * malloc/free fine tuned for pathalias.  *  * MYMALLOC should work everwhere, so it's not a configuration  * option (anymore).  nonetheless, if you're getting strange  * core dumps (or panics!), comment out the following manifest,  * and use the inferior C library malloc/free.  */
end_comment

begin_define
define|#
directive|define
name|MYMALLOC
end_define

begin_comment
comment|/**/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MYMALLOC
end_ifdef

begin_define
define|#
directive|define
name|malloc
value|mymalloc
end_define

begin_define
define|#
directive|define
name|calloc
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|malloc ((n)*(s))
end_define

begin_define
define|#
directive|define
name|free
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cfree
parameter_list|(
name|s
parameter_list|)
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|memget
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !MYMALLOC */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MYMALLOC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STRCHR
end_ifdef

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BZERO
end_ifdef

begin_define
define|#
directive|define
name|strclear
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|((void) bzero((s), (n)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*!BZERO*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MEMSET
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|memset
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|strclear
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|((void) memset((s), 0, (n)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*!MEMSET*/
end_comment

begin_function_decl
specifier|extern
name|void
name|strclear
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*MEMSET*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*BZERO*/
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|index
argument_list|()
decl_stmt|,
modifier|*
name|rindex
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|STATIC
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|STATIC
value|extern
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*DEBUG*/
end_comment

begin_define
define|#
directive|define
name|STATIC
value|static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*DEBUG*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*STATIC*/
end_comment

end_unit

