begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *      All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  */
end_comment

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_macro
name|SM_RCSID
argument_list|(
literal|"@(#)$Id: syslogio.c,v 1.29 2001/09/11 04:04:49 gshapiro Exp $"
argument_list|)
end_macro

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SM_RPOOL
end_ifdef

begin_include
include|#
directive|include
file|<sm/rpool.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_RPOOL */
end_comment

begin_include
include|#
directive|include
file|<sm/io.h>
end_include

begin_include
include|#
directive|include
file|"local.h"
end_include

begin_comment
comment|/* **  Overall: **  This is a output file type that copies its output to the syslog daemon. **  Each line of output is written as a separate syslog message. **  The client is responsible for calling openlog() before writing to **  any syslog file, and calling closelog() after all syslog output is complete. **  The only state associated with a syslog file is 'int priority', **  which we store in fp->f_ival. */
end_comment

begin_comment
comment|/* **  SM_SYSLOGOPEN -- open a file pointer to syslog ** **	Parameters: **		fp -- file pointer assigned for the open **		info -- priority level of the syslog messages **		flags -- not used **		rpool -- ignored ** **	Returns: **		0 (zero) success always (see Overall) */
end_comment

begin_function
name|int
name|sm_syslogopen
parameter_list|(
name|fp
parameter_list|,
name|info
parameter_list|,
name|flags
parameter_list|,
name|rpool
parameter_list|)
name|SM_FILE_T
modifier|*
name|fp
decl_stmt|;
specifier|const
name|void
modifier|*
name|info
decl_stmt|;
name|int
name|flags
decl_stmt|;
specifier|const
name|void
modifier|*
name|rpool
decl_stmt|;
block|{
name|int
modifier|*
name|priority
init|=
operator|(
name|int
operator|*
operator|)
name|info
decl_stmt|;
name|fp
operator|->
name|f_ival
operator|=
operator|*
name|priority
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* **  SM_SYSLOGREAD -- read function for syslog ** **  This is a "stub" function (placeholder) that always returns an error. **  It is an error to read syslog. ** **	Parameters: **		fp -- the file pointer **		buf -- buffer to place the data read **		n -- number of bytes to read ** **	Returns: **		-1 (error) always and sets errno */
end_comment

begin_function
name|ssize_t
name|sm_syslogread
parameter_list|(
name|fp
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
name|SM_FILE_T
modifier|*
name|fp
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|size_t
name|n
decl_stmt|;
block|{
comment|/* an error to read */
name|errno
operator|=
name|ENODEV
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* **  SM_SYSLOGWRITE -- write function for syslog ** **  Send output to syslog. ** **	Parameters: **		fp -- the file pointer **		buf -- buffer that the write data comes from **		n -- number of bytes to write ** **	Returns: **		0 (zero) for success always */
end_comment

begin_comment
comment|/* **  XXX TODO: more work needs to be done to ensure that each line of output **  XXX written to a syslog file is mapped to exactly one syslog message. */
end_comment

begin_function
name|ssize_t
name|sm_syslogwrite
parameter_list|(
name|fp
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
name|SM_FILE_T
modifier|*
name|fp
decl_stmt|;
name|char
specifier|const
modifier|*
name|buf
decl_stmt|;
name|size_t
name|n
decl_stmt|;
block|{
name|syslog
argument_list|(
name|fp
operator|->
name|f_ival
argument_list|,
literal|"%s"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* **  SM_SYSLOGSEEK -- position the syslog file offset ** **  This is a "stub" function (placeholder) that always returns an error. **  It is an error to seek syslog. ** **	Parameters: **		fp -- the file pointer **		offset -- the new offset position relative to 'whence' **		whence -- flag indicating start of 'offset' ** **	Returns: **		-1 (error) always. */
end_comment

begin_function
name|off_t
name|sm_syslogseek
parameter_list|(
name|fp
parameter_list|,
name|offset
parameter_list|,
name|whence
parameter_list|)
name|SM_FILE_T
modifier|*
name|fp
decl_stmt|;
name|off_t
name|offset
decl_stmt|;
name|int
name|whence
decl_stmt|;
block|{
name|errno
operator|=
name|ENODEV
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* **  SM_SYSLOGCLOSE -- close the syslog file pointer ** **	Parameters: **		fp -- the file pointer ** **	Returns: **		0 (zero) success always (see Overall) ** */
end_comment

begin_function
name|int
name|sm_syslogclose
parameter_list|(
name|fp
parameter_list|)
name|SM_FILE_T
modifier|*
name|fp
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* **  SM_SYSLOGSETINFO -- set information for the file pointer ** **	Parameters: **		fp -- the file pointer being set **		what -- what information is being set **		valp -- information content being set to ** **	Returns: **		-1 on failure **		0 (zero) on success ** **	Side Effects: **		Sets internal file pointer data */
end_comment

begin_function
name|int
name|sm_syslogsetinfo
parameter_list|(
name|fp
parameter_list|,
name|what
parameter_list|,
name|valp
parameter_list|)
name|SM_FILE_T
modifier|*
name|fp
decl_stmt|;
name|int
name|what
decl_stmt|;
name|void
modifier|*
name|valp
decl_stmt|;
block|{
switch|switch
condition|(
name|what
condition|)
block|{
case|case
name|SM_IO_SL_PRIO
case|:
name|fp
operator|->
name|f_ival
operator|=
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
operator|(
name|valp
operator|)
operator|)
expr_stmt|;
return|return
literal|0
return|;
default|default:
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
end_function

begin_comment
comment|/* **  SM_SYSLOGGETINFO -- get information relating to the file pointer ** **	Parameters: **		fp -- the file pointer being queried **		what -- the information type being queried **		valp -- location to placed queried information ** **	Returns: **		0 (zero) on success **		-1 on failure ** **	Side Effects: **		Fills in 'valp' with data. */
end_comment

begin_function
name|int
name|sm_sysloggetinfo
parameter_list|(
name|fp
parameter_list|,
name|what
parameter_list|,
name|valp
parameter_list|)
name|SM_FILE_T
modifier|*
name|fp
decl_stmt|;
name|int
name|what
decl_stmt|;
name|void
modifier|*
name|valp
decl_stmt|;
block|{
switch|switch
condition|(
name|what
condition|)
block|{
case|case
name|SM_IO_SL_PRIO
case|:
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
operator|(
name|valp
operator|)
operator|)
operator|=
name|fp
operator|->
name|f_ival
expr_stmt|;
return|return
literal|0
return|;
default|default:
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
end_function

end_unit

