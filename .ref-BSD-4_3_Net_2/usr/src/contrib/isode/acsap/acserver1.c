begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* acserver1.c - generic server dispatch */
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
literal|"$Header: /f/osi/acsap/RCS/acserver1.c,v 7.4 91/02/22 09:14:23 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/acsap/RCS/acserver1.c,v 7.4 91/02/22 09:14:23 mrose Interim $  *  *  * $Log:	acserver1.c,v $  * Revision 7.4  91/02/22  09:14:23  mrose  * Interim 6.8  *   * Revision 7.3  90/10/29  18:37:49  mrose  * updates  *   * Revision 7.2  90/07/09  14:30:45  mrose  * sync  *   * Revision 7.1  90/02/19  13:07:05  mrose  * update  *   * Revision 7.0  89/11/23  21:22:02  mrose  * Release 6.0  *   */
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
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"psap.h"
end_include

begin_include
include|#
directive|include
file|"tsap.h"
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BSD42
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_include
include|#
directive|include
file|"tailor.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|int
name|isodeserver
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|,
name|aei
parameter_list|,
name|initfnx
parameter_list|,
name|workfnx
parameter_list|,
name|losefnx
parameter_list|,
name|td
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
name|AEI
name|aei
decl_stmt|;
name|IFP
name|initfnx
decl_stmt|,
name|workfnx
decl_stmt|,
name|losefnx
decl_stmt|;
name|struct
name|TSAPdisconnect
modifier|*
name|td
decl_stmt|;
block|{
if|if
condition|(
name|iserver_init
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|aei
argument_list|,
name|initfnx
argument_list|,
name|td
argument_list|)
operator|==
name|NOTOK
condition|)
return|return
name|NOTOK
return|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|int
name|result
decl_stmt|;
if|if
condition|(
operator|(
name|result
operator|=
name|iserver_wait
argument_list|(
name|initfnx
argument_list|,
name|workfnx
argument_list|,
name|losefnx
argument_list|,
literal|0
argument_list|,
name|NULLFD
argument_list|,
name|NULLFD
argument_list|,
name|NULLFD
argument_list|,
name|NOTOK
argument_list|,
name|td
argument_list|)
operator|)
operator|!=
name|OK
condition|)
return|return
operator|(
name|result
operator|==
name|DONE
condition|?
name|OK
else|:
name|result
operator|)
return|;
block|}
block|}
end_function

end_unit

