begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* util.h - various useful utility definitions */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/util.h,v 7.2 91/02/22 09:26:10 mrose Interim $  *  *  * $Log:	util.h,v $  * Revision 7.2  91/02/22  09:26:10  mrose  * Interim 6.8  *   * Revision 7.1  90/07/09  14:38:41  mrose  * sync  *   * Revision 7.0  89/11/23  21:56:45  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DIDUTIL_
end_ifndef

begin_define
define|#
directive|define
name|_DIDUTIL_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_H_UTIL
end_ifndef

begin_comment
comment|/* PP interwork */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* minus the ctype stuff */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|"manifest.h"
end_include

begin_include
include|#
directive|include
file|"logger.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_GENERAL_
end_ifndef

begin_include
include|#
directive|include
file|"general.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"quipu/config.h"
end_include

begin_comment
comment|/* declarations that should have been in the system files */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_H_UTIL
end_ifndef

begin_comment
comment|/* PP interwork */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strncpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strdup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|multcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|multcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|gets
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* some common logical values */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|YES
end_ifndef

begin_define
define|#
directive|define
name|YES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO
end_ifndef

begin_define
define|#
directive|define
name|NO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OK
end_ifndef

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DONE
end_ifndef

begin_define
define|#
directive|define
name|DONE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NOTOK
end_ifndef

begin_define
define|#
directive|define
name|NOTOK
value|-1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAYBE
end_ifndef

begin_define
define|#
directive|define
name|MAYBE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* stdio extensions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lowtoup
end_ifndef

begin_define
define|#
directive|define
name|lowtoup
parameter_list|(
name|chr
parameter_list|)
value|(islower(chr)?toupper(chr):chr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|uptolow
end_ifndef

begin_define
define|#
directive|define
name|uptolow
parameter_list|(
name|chr
parameter_list|)
value|(isupper(chr)?tolower(chr):chr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(( (b)< (a) ) ? (b) : (a) )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(( (b)> (a) ) ? (b) : (a) )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXINT
end_ifndef

begin_define
define|#
directive|define
name|MAXINT
value|(~(1<< ((sizeof(int) * 8) - 1)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|isstr
parameter_list|(
name|ptr
parameter_list|)
value|((ptr) != 0&& *(ptr) != '\0')
end_define

begin_define
define|#
directive|define
name|isnull
parameter_list|(
name|chr
parameter_list|)
value|((chr) == '\0')
end_define

begin_define
define|#
directive|define
name|isnumber
parameter_list|(
name|c
parameter_list|)
value|((c)>= '0'&& (c)<= '9')
end_define

begin_comment
comment|/*  * provide a timeout facility  */
end_comment

begin_decl_stmt
specifier|extern
name|jmp_buf
name|_timeobuf
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|timeout
parameter_list|(
name|val
parameter_list|)
value|(setjmp(_timeobuf) ? 1 : (_timeout(val), 0))
end_define

begin_comment
comment|/*  * some common extensions  */
end_comment

begin_define
define|#
directive|define
name|LINESIZE
value|1024
end_define

begin_comment
comment|/* what we are prepared to consider a line length */
end_comment

begin_define
define|#
directive|define
name|FILNSIZE
value|256
end_define

begin_comment
comment|/* max filename length */
end_comment

begin_define
define|#
directive|define
name|LOTS
value|1024
end_define

begin_comment
comment|/* a max sort of thing */
end_comment

begin_define
define|#
directive|define
name|MAXFILENAMELEN
value|15
end_define

begin_comment
comment|/* size of largest fine name allowed */
end_comment

begin_define
define|#
directive|define
name|MAXFORK
value|10
end_define

begin_comment
comment|/* no. of times to try a fork() */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULLCP
end_ifndef

begin_define
define|#
directive|define
name|NULLCP
value|((char *)0)
end_define

begin_define
define|#
directive|define
name|NULLVP
value|((char **) 0)
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|smalloc
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_H_UTIL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

