begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rtf.h - definitions for RT-file transfer utility */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/others/rtf/RCS/rtf.h,v 7.1 91/02/22 09:34:17 mrose Interim $  *  *  * $Log:	rtf.h,v $  * Revision 7.1  91/02/22  09:34:17  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:10:47  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"rtsap.h"
end_include

begin_include
include|#
directive|include
file|"logger.h"
end_include

begin_include
include|#
directive|include
file|"RTF-types.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NULL
end_ifdef

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SYS5
end_ifndef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|AIX
end_ifndef

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<fcntl.h>
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
file|<sys/stat.h>
end_include

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|pgm_log
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_function_decl
name|char
modifier|*
name|SReportString
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|rts_adios
argument_list|()
decl_stmt|,
name|rts_advise
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|adios
argument_list|()
decl_stmt|,
name|advise
argument_list|()
decl_stmt|,
name|ryr_advise
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

