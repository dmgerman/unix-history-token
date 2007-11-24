begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2002, 2004-2006 Sendmail, Inc. and its suppliers.  *      All rights reserved.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: local.h,v 1.58 2006/12/19 19:44:23 ca Exp $  */
end_comment

begin_comment
comment|/* **  Information local to this implementation of stdio, **  in particular, macros and private variables. */
end_comment

begin_include
include|#
directive|include
file|<sm/time.h>
end_include

begin_if
if|#
directive|if
operator|!
name|SM_CONF_MEMCHR
end_if

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SM_CONF_MEMCHR */
end_comment

begin_include
include|#
directive|include
file|<sm/heap.h>
end_include

begin_decl_stmt
name|int
name|sm_flush
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SM_FILE_T
modifier|*
name|smfp
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_refill
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sm_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sm_cleanup
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sm_makebuf
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_whatbuf
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|size_t
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_fwalk
name|__P
argument_list|(
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|SM_FILE_T
operator|*
argument_list|,
name|int
operator|*
argument_list|)
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_wsetup
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_flags
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SM_FILE_T
modifier|*
name|sm_fp
name|__P
argument_list|(
operator|(
specifier|const
name|SM_FILE_T
operator|*
operator|,
specifier|const
name|int
operator|,
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_vprintf
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
specifier|const
operator|*
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* std io functions */
end_comment

begin_decl_stmt
name|ssize_t
name|sm_stdread
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|sm_stdwrite
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|off_t
name|sm_stdseek
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|off_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_stdclose
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_stdopen
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
specifier|const
name|void
operator|*
operator|,
name|int
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_stdfdopen
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
specifier|const
name|void
operator|*
operator|,
name|int
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_stdsetinfo
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_stdgetinfo
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stdio io functions */
end_comment

begin_decl_stmt
name|ssize_t
name|sm_stdioread
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|sm_stdiowrite
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|off_t
name|sm_stdioseek
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|off_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_stdioclose
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_stdioopen
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
specifier|const
name|void
operator|*
operator|,
name|int
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_stdiosetinfo
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_stdiogetinfo
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string io functions */
end_comment

begin_decl_stmt
name|ssize_t
name|sm_strread
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|sm_strwrite
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|off_t
name|sm_strseek
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|off_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_strclose
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_stropen
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
specifier|const
name|void
operator|*
operator|,
name|int
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_strsetinfo
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_strgetinfo
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* syslog io functions */
end_comment

begin_decl_stmt
name|ssize_t
name|sm_syslogread
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|sm_syslogwrite
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|off_t
name|sm_syslogseek
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|off_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_syslogclose
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_syslogopen
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
specifier|const
name|void
operator|*
operator|,
name|int
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_syslogsetinfo
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_sysloggetinfo
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|Sm_IO_DidInit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return true iff the given SM_FILE_T cannot be written now. */
end_comment

begin_define
define|#
directive|define
name|cantwrite
parameter_list|(
name|fp
parameter_list|)
define|\
value|((((fp)->f_flags& SMWR) == 0 || (fp)->f_bf.smb_base == NULL)&& \ 	 sm_wsetup(fp))
end_define

begin_comment
comment|/* **  Test whether the given stdio file has an active ungetc buffer; **   release such a buffer, without restoring ordinary unread data. */
end_comment

begin_define
define|#
directive|define
name|HASUB
parameter_list|(
name|fp
parameter_list|)
value|((fp)->f_ub.smb_base != NULL)
end_define

begin_define
define|#
directive|define
name|FREEUB
parameter_list|(
name|fp
parameter_list|)
define|\
value|{							\ 	if ((fp)->f_ub.smb_base != (fp)->f_ubuf)	\ 		sm_free((char *)(fp)->f_ub.smb_base);	\ 	(fp)->f_ub.smb_base = NULL;			\ }
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|SmFileMagic
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SM_ALIGN
parameter_list|(
name|p
parameter_list|)
value|(((unsigned long)(p) + SM_ALIGN_BITS)& ~SM_ALIGN_BITS)
end_define

begin_define
define|#
directive|define
name|sm_io_flockfile
parameter_list|(
name|fp
parameter_list|)
value|((void) 0)
end_define

begin_define
define|#
directive|define
name|sm_io_funlockfile
parameter_list|(
name|fp
parameter_list|)
value|((void) 0)
end_define

begin_decl_stmt
name|int
name|sm_flags
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|FDSET_CAST
end_ifndef

begin_define
define|#
directive|define
name|FDSET_CAST
end_define

begin_comment
comment|/* empty cast for fd_set arg to select */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  SM_CONVERT_TIME -- convert the API timeout flag for select() usage. ** **	This takes a 'fp' (a file type pointer) and obtains the "raw" **	file descriptor (fd) if possible. The 'fd' is needed to possibly **	switch the mode of the file (blocking/non-blocking) to match **	the type of timeout. If timeout is SM_TIME_FOREVER then the **	timeout using select won't be needed and the file is best placed **	in blocking mode. If there is to be a finite timeout then the file **	is best placed in non-blocking mode. Then, if not enough can be **	written, select() can be used to test when something can be written **	yet still timeout if the wait is too long. **	If the mode is already in the correct state we don't change it. **	Iff (yes "iff") the 'fd' is "-1" in value then the mode change **	will not happen. This situation arises when a late-binding-to-disk **	file type is in use. An example of this is the sendmail buffered **	file type (in sendmail/bf.c). ** **	Parameters **		fp -- the file pointer the timeout is for **		fd -- to become the file descriptor value from 'fp' **		val -- the timeout value to be converted **		time -- a struct timeval holding the converted value ** **	Returns **		nothing, this is flow-through code ** **	Side Effects: **		May or may not change the mode of a currently open file. **		The file mode may be changed to O_NONBLOCK or ~O_NONBLOCK **		(meaning block). This is done to best match the type of **		timeout and for (possible) use with select(). */
end_comment

begin_define
define|#
directive|define
name|SM_CONVERT_TIME
parameter_list|(
name|fp
parameter_list|,
name|fd
parameter_list|,
name|val
parameter_list|,
name|time
parameter_list|)
value|{ \ 	if (((fd) = sm_io_getinfo(fp, SM_IO_WHAT_FD, NULL)) == -1) \ 	{ \
comment|/* can't get an fd, likely internal 'fake' fp */
value|\ 		errno = 0; \ 	} \ 	if ((val) == SM_TIME_DEFAULT) \ 		(val) = (fp)->f_timeout; \ 	if ((val) == SM_TIME_IMMEDIATE || (val) == SM_TIME_FOREVER) \ 	{ \ 		(time)->tv_sec = 0; \ 		(time)->tv_usec = 0; \ 	} \ 	else \ 	{ \ 		(time)->tv_sec = (val) / 1000; \ 		(time)->tv_usec = ((val) - ((time)->tv_sec * 1000)) * 1000; \ 	} \ 	if ((val) == SM_TIME_FOREVER) \ 	{ \ 		if ((fp)->f_timeoutstate == SM_TIME_NONBLOCK&& (fd) != -1) \ 		{ \ 			int ret; \ 			ret = fcntl((fd), F_GETFL, 0); \ 			if (ret == -1 || fcntl((fd), F_SETFL, \ 					       ret& ~O_NONBLOCK) == -1) \ 			{ \
comment|/* errno should be set */
value|\ 				return SM_IO_EOF; \ 			} \ 			(fp)->f_timeoutstate = SM_TIME_BLOCK; \ 			if ((fp)->f_modefp != NULL) \ 				(fp)->f_modefp->f_timeoutstate = SM_TIME_BLOCK; \ 		} \ 	} \ 	else { \ 		if ((fp)->f_timeoutstate == SM_TIME_BLOCK&& (fd) != -1) \ 		{ \ 			int ret; \ 			ret = fcntl((fd), F_GETFL, 0); \ 			if (ret == -1 || fcntl((fd), F_SETFL, \ 					       ret | O_NONBLOCK) == -1) \ 			{ \
comment|/* errno should be set */
value|\ 				return SM_IO_EOF; \ 			} \ 			(fp)->f_timeoutstate = SM_TIME_NONBLOCK; \ 			if ((fp)->f_modefp != NULL) \ 				(fp)->f_modefp->f_timeoutstate = SM_TIME_NONBLOCK; \ 		} \ 	} \ }
end_define

begin_comment
comment|/* **  SM_IO_WR_TIMEOUT -- setup the timeout for the write ** **  This #define uses a select() to wait for the 'fd' to become writable. **  The select() can be active for up to 'to' time. The select may not **  use all of the the 'to' time. Hence, the amount of "wall-clock" time is **  measured to decide how much to subtract from 'to' to update it. On some **  BSD-based/like systems the timeout for a select is updated for the **  amount of time used. On many/most systems this does not happen. Therefore **  the updating of 'to' must be done ourselves; a copy of 'to' is passed **  since a BSD-like system will have updated it and we don't want to **  double the time used! **  Note: if a valid 'fd' doesn't exist yet, don't use this (e.g. the **  sendmail buffered file type in sendmail/bf.c; see fvwrite.c). ** **	Parameters **		fd -- a file descriptor for doing select() with **		timeout -- the original user set value. ** **	Returns **		nothing, this is flow through code ** **	Side Effects: **		adjusts 'timeout' for time used */
end_comment

begin_define
define|#
directive|define
name|SM_IO_WR_TIMEOUT
parameter_list|(
name|fp
parameter_list|,
name|fd
parameter_list|,
name|to
parameter_list|)
value|{ \ 	struct timeval sm_io_to_before, sm_io_to_after, sm_io_to_diff; \ 	struct timeval sm_io_to; \ 	int sm_io_to_sel; \ 	fd_set sm_io_to_mask, sm_io_x_mask; \ 	errno = 0; \ 	if ((to) == SM_TIME_DEFAULT) \ 		(to) = (fp)->f_timeout; \ 	if ((to) == SM_TIME_IMMEDIATE) \ 	{ \ 		errno = EAGAIN; \ 		return SM_IO_EOF; \ 	} \ 	else if ((to) == SM_TIME_FOREVER) \ 	{ \ 		errno = EINVAL; \ 		return SM_IO_EOF; \ 	} \ 	else \ 	{ \ 		sm_io_to.tv_sec = (to) / 1000; \ 		sm_io_to.tv_usec = ((to) - (sm_io_to.tv_sec * 1000)) * 1000; \ 	} \ 	if (FD_SETSIZE> 0&& (fd)>= FD_SETSIZE) \ 	{ \ 		errno = EINVAL; \ 		return SM_IO_EOF; \ 	} \ 	FD_ZERO(&sm_io_to_mask); \ 	FD_SET((fd),&sm_io_to_mask); \ 	FD_ZERO(&sm_io_x_mask); \ 	FD_SET((fd),&sm_io_x_mask); \ 	if (gettimeofday(&sm_io_to_before, NULL)< 0) \ 		return SM_IO_EOF; \ 	do \ 	{	\ 		sm_io_to_sel = select((fd) + 1, NULL,&sm_io_to_mask, \&sm_io_x_mask,&sm_io_to); \ 	} while (sm_io_to_sel< 0&& errno == EINTR); \ 	if (sm_io_to_sel< 0) \ 	{ \
comment|/* something went wrong, errno set */
value|\ 		return SM_IO_EOF; \ 	} \ 	else if (sm_io_to_sel == 0) \ 	{ \
comment|/* timeout */
value|\ 		errno = EAGAIN; \ 		return SM_IO_EOF; \ 	} \
comment|/* else loop again */
value|\ 	if (gettimeofday(&sm_io_to_after, NULL)< 0) \ 		return SM_IO_EOF; \ 	timersub(&sm_io_to_after,&sm_io_to_before,&sm_io_to_diff); \ 	(to) -= (sm_io_to_diff.tv_sec * 1000); \ 	(to) -= (sm_io_to_diff.tv_usec / 1000); \ 	if ((to)< 0) \ 		(to) = 0; \ }
end_define

begin_comment
comment|/* **  If there is no 'fd' just error (we can't timeout). If the timeout **  is SM_TIME_FOREVER then there is no need to do a timeout with **  select since this will be a real error.  If the error is not **  EAGAIN/EWOULDBLOCK (from a nonblocking) then it's a real error. **  Specify the condition here as macro so it can be used in several places. */
end_comment

begin_define
define|#
directive|define
name|IS_IO_ERROR
parameter_list|(
name|fd
parameter_list|,
name|ret
parameter_list|,
name|to
parameter_list|)
define|\
value|((fd)< 0 ||	\ 	 ((ret)< 0&& errno != EAGAIN&& errno != EWOULDBLOCK) ||	\ 	 (to) == SM_TIME_FOREVER)
end_define

end_unit

