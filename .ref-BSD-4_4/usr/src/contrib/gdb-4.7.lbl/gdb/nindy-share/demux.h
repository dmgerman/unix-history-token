begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  Copyright 1990, 1992 Free Software Foundation, Inc.  *  *  This code was donated by Intel Corp.  *  * This include file supports demultiplexing of input from two sources:  * stdin and one external source (normally the NINDY monitor).  *  * Its purpose is to promote portability of applications between different  * flavors (BSD and USG/SysV) of Unix.  As of this writing, it is used by the  * gdb960 remote communications module (remote.c) and the comm960 utility.  *   * It is assumed that 'USG' is defined on the compiler invocation line if the  * code should compile and run on a USG/SysV system.  Otherwise, BSD is assumed.  *  * The application code must use all three of these macros:  *  *	DEMUX_DECL	Declares data structures needed by the other macros.  *  *	DEMUX_WAIT(fd)	Waits until input is available on either stdin or  *			file descriptor 'fd'.  *  *	DEMUX_READ(fd,bufp,bufsz)  *			Reads up to 'bufsz' bytes from file descriptor 'fd'  *			into buffer pointed at by character pointer 'bufp'.  *			Returns the number of bytes read, which will be 0  *			if there was no input pending on 'fd'. 'fd' should be  *			either 0 (stdin) or the same descriptor that was used  *			in the invocation of 'DEMUX_WAIT'.  *  * The following macro is also included:  *  *	TIME_INPUT(fd,timeout,retp)  *			Waits up to 'timeout' seconds for input on file  *			descriptor 'fd'.  Sets (*retp) to:  *				 1 if input is ready  *				 0 if timeout occurred  *				-1 if wait was interrupted by a signal  *  * WARNINGS ABOUT USG (System V) UNIX!!  *  *	The TIME_INPUT macro isn't implemented: it's a no-op.  *  *	The damned 'poll' call can't be used on normal tty's, so DEMUX_WAIT is  *	also a no-op: DEMUX_READ uses the FIONREAD ioctl if it's available;  *	otherwise the file descriptor is temporarily set for non-blocking input  *	and a read it done.  *  ******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_define
define|#
directive|define
name|DEMUX_DECL
value|int _saveflags_; int _n_
end_define

begin_define
define|#
directive|define
name|DEMUX_WAIT
parameter_list|(
name|fd
parameter_list|)
end_define

begin_comment
comment|/* Use non-blocking I/O */
end_comment

begin_define
define|#
directive|define
name|DEMUX_READ
parameter_list|(
name|fd
parameter_list|,
name|bufp
parameter_list|,
name|bufsz
parameter_list|)
value|(			\ 			_saveflags_ = fcntl( fd, F_GETFL, 0 ),		\ 			fcntl( fd, F_SETFL, _saveflags_ | O_NDELAY ),	\ 			_n_ = read( fd, bufp, bufsz ),			\ 			fcntl( fd, F_SETFL, _saveflags_ ),		\ 			_n_ )
end_define

begin_define
define|#
directive|define
name|TIME_INPUT
parameter_list|(
name|fd
parameter_list|,
name|timeout
parameter_list|,
name|retp
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BSD */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_define
define|#
directive|define
name|DEMUX_DECL
value|fd_set _mux_
end_define

begin_define
define|#
directive|define
name|DEMUX_WAIT
parameter_list|(
name|fd
parameter_list|)
value|{					\ 			FD_ZERO(&_mux_ );				\ 			FD_SET( 0,&_mux_ );				\ 			FD_SET( fd,&_mux_ );				\ 			if (select(fd+1,&_mux_,0,0,0)<= 0){		\ 				FD_ZERO(&_mux_);			\ 			}						\ 	}
end_define

begin_comment
comment|/* Check return value of select in case of 			 * premature termination due to signal:  clear 			 * file descriptors in this case so DEMUX_READ 			 * doesn't mistakenly say there's input on them. 			 */
end_comment

begin_define
define|#
directive|define
name|DEMUX_READ
parameter_list|(
name|fd
parameter_list|,
name|bufp
parameter_list|,
name|bufsz
parameter_list|)
define|\
value|( FD_ISSET(fd,&_mux_) ?	read(fd,bufp,bufsz) : 0 )
end_define

begin_define
define|#
directive|define
name|TIME_INPUT
parameter_list|(
name|fd
parameter_list|,
name|timeout
parameter_list|,
name|retp
parameter_list|)
value|{			\ 			fd_set _fds_;					\ 			struct timeval _timeout_;			\ 			FD_ZERO(&_fds_ );				\ 			FD_SET( fd,&_fds_ );				\ 			_timeout_.tv_sec  = timeout;			\ 			_timeout_.tv_usec = 0;				\ 			*(retp) = select(fd+1,&_fds_,0,0,&_timeout_);	\ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

