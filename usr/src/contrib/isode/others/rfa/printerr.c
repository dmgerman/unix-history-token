begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * RFA - Remote File Access  *  * Access and Management for a partial file system tree that exists  * at two sites either as master files or slave files  *  * printerr.c - print error message for protocol defined errors  *  * Contributed by Oliver Wenzel, GMD Berlin, 1990  *  * $Header: /f/osi/others/rfa/RCS/printerr.c,v 7.3 91/02/22 09:28:09 mrose Interim $  *  * $Log:	printerr.c,v $  * Revision 7.3  91/02/22  09:28:09  mrose  * Interim 6.8  *   * Revision 7.2  91/01/14  13:54:40  mrose  * update  *   * Revision 1.1  91/01/04  16:06:52  ow  * Initial revision  *   */
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
literal|"$Header: /f/osi/others/rfa/RCS/printerr.c,v 7.3 91/02/22 09:28:09 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *                              NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"RFA-ops.h"
end_include

begin_comment
comment|/* operation definitions */
end_comment

begin_include
include|#
directive|include
file|"RFA-types.h"
end_include

begin_comment
comment|/* type definitions */
end_comment

begin_include
include|#
directive|include
file|"rfa.h"
end_include

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|err
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|shortTime
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*--------------------------------------------------------------*/
end_comment

begin_comment
comment|/*  Print Error							*/
end_comment

begin_comment
comment|/*--------------------------------------------------------------*/
end_comment

begin_macro
name|printError
argument_list|(
argument|error
argument_list|,
argument|param
argument_list|,
argument|rc
argument_list|)
end_macro

begin_decl_stmt
name|int
name|error
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
modifier|*
name|param
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|rc
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|RyError
modifier|*
name|rye
decl_stmt|;
name|time_t
name|t
decl_stmt|;
name|struct
name|type_RFA_StatusErrorParm
modifier|*
name|se
init|=
operator|(
expr|struct
name|type_RFA_StatusErrorParm
operator|*
operator|)
name|param
decl_stmt|;
switch|switch
condition|(
name|error
condition|)
block|{
case|case
name|error_RFA_miscError
case|:
name|printf
argument_list|(
literal|"*** remote error : %s ***\n"
argument_list|,
name|qb2str
argument_list|(
name|param
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|rc
operator|=
literal|3
expr_stmt|;
break|break;
case|case
name|error_RFA_fileAccessError
case|:
name|printf
argument_list|(
literal|"*** remote file access error : %s ***\n"
argument_list|,
name|qb2str
argument_list|(
name|param
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|rc
operator|=
literal|4
expr_stmt|;
break|break;
case|case
name|error_RFA_statusError
case|:
switch|switch
condition|(
name|se
operator|->
name|reason
condition|)
block|{
case|case
name|int_RFA_reason_notMaster
case|:
name|fprintf
argument_list|(
name|err
argument_list|,
literal|"*** status error : remote site is not master ***\n"
argument_list|)
expr_stmt|;
operator|*
name|rc
operator|=
literal|10
expr_stmt|;
break|break;
case|case
name|int_RFA_reason_locked
case|:
name|t
operator|=
name|se
operator|->
name|since
expr_stmt|;
name|fprintf
argument_list|(
name|err
argument_list|,
literal|"*** status error : locked at remote site by %s since %s ***\n"
argument_list|,
name|qb2str
argument_list|(
name|se
operator|->
name|user
argument_list|)
argument_list|,
name|shortTime
argument_list|(
operator|&
name|t
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|rc
operator|=
literal|11
expr_stmt|;
break|break;
case|case
name|int_RFA_reason_notRegistered
case|:
name|fprintf
argument_list|(
name|err
argument_list|,
literal|"*** status error : file not registered at remote site ***\n"
argument_list|)
expr_stmt|;
operator|*
name|rc
operator|=
literal|12
expr_stmt|;
break|break;
case|case
name|int_RFA_reason_notWritable
case|:
name|fprintf
argument_list|(
name|err
argument_list|,
literal|"*** status error : file not writable at remote site ***\n"
argument_list|)
expr_stmt|;
operator|*
name|rc
operator|=
literal|13
expr_stmt|;
break|break;
case|case
name|int_RFA_reason_wrongVersion
case|:
name|fprintf
argument_list|(
name|err
argument_list|,
literal|"*** status error : wrong version ***\n"
argument_list|)
expr_stmt|;
operator|*
name|rc
operator|=
literal|14
expr_stmt|;
break|break;
case|case
name|int_RFA_reason_notRegularFile
case|:
name|fprintf
argument_list|(
name|err
argument_list|,
literal|"*** status error : not a regular file ***\n"
argument_list|)
expr_stmt|;
operator|*
name|rc
operator|=
literal|16
expr_stmt|;
break|break;
case|case
name|int_RFA_reason_slaveNewer
case|:
name|fprintf
argument_list|(
name|err
argument_list|,
literal|"*** status error : local slave version is newer than remote master ***\n"
argument_list|)
expr_stmt|;
operator|*
name|rc
operator|=
literal|17
expr_stmt|;
break|break;
default|default:
name|fprintf
argument_list|(
name|err
argument_list|,
literal|"*** status error : unknown error (%d) ***\n"
argument_list|,
name|se
operator|->
name|reason
argument_list|)
expr_stmt|;
operator|*
name|rc
operator|=
literal|19
expr_stmt|;
block|}
break|break;
default|default:
name|fprintf
argument_list|(
name|err
argument_list|,
literal|"*** unknown error (%d) ***\n"
argument_list|,
name|error
argument_list|)
expr_stmt|;
operator|*
name|rc
operator|=
literal|2
expr_stmt|;
block|}
block|}
end_block

end_unit

