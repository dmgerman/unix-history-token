begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * Copyright 1990, 1992 Free Software Foundation, Inc.  *  * This code was donated by Intel Corp.  *  * This include file provides BSD/USG-compatible tty control for a host utility  * that interacts with NINDY.  As of this writing, it is used by the gdb960  * remote communications module (remote.c) and the comm960 utility.  *   * It is assumed that 'USG' is defined on the compiler invocation line if the  * code should compile and run on a USG/SysV system.  Otherwise, BSD is assumed.  *  * The application code has access to these macros:  *  *	TTY_STRUCT	Data type used by tty functions (ioctls and the  *			following macros).  *  *	TTY_NINDYTERM(tty)  *			'tty' is assumed to be a TTY_STRUCT describing the  *			terminal.  It is modified as appropriate to allow  *			all user input to be passed through unmodified to NINDY  *			as soon as it is typed, and to allow all NINDY output  *			to be passed through unmodified to the display as soon  *			as it is received.  *  *	TTY_REMOTE(tty,baud)  *			'tty' is assumed to be a TTY_STRUCT describing the  *			serial connection between the host and NINDY.  It is  *			initialized as appropriate to allow communications  *			between the host and NINDY at the specified baud rate  *			(which must be one of the "B..." defined constants).  *  *	TTY_FLUSH(fd)	flush all pending input and output on the tty whose  *			file descriptor is 'fd'.  *  *	TTY_NBREAD(fd,n,bufptr)  *			Performs non-blocking read of 'n' characters on the  *			file descriptor 'fd'.  Sets the integer 'n' to the  *			number of characters actually read.  The characters  *			are read into the buffer pointed at by bufptr.  *  * In addition, the BSD ioctl commands TIOCGETP and TIOCSETP are defined to  * have the same meanings under USG: retrieve and set (respectively) the  * parameters of a tty.  ******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_define
define|#
directive|define
name|TTY_STRUCT
value|struct termio
end_define

begin_define
define|#
directive|define
name|TIOCGETP
value|TCGETA
end_define

begin_define
define|#
directive|define
name|TIOCSETP
value|TCSETAF
end_define

begin_comment
comment|/* NOTE!: 	 *	Remove CLOCAL from following macro if you will be accessing 	 *	the i960 system via a modem. 	 */
end_comment

begin_define
define|#
directive|define
name|TTY_REMOTE
parameter_list|(
name|tty
parameter_list|,
name|baud
parameter_list|)
value|{                   \                 tty.c_iflag = IXON | IXOFF;             \                 tty.c_oflag = 0;                        \                 tty.c_cflag = baud|CS8|CREAD|CLOCAL;    \                 tty.c_lflag = 0;                        \                 tty.c_cc[VEOF] = 1;                     \                 tty.c_cc[VEOL] = 0;                     \         }
end_define

begin_define
define|#
directive|define
name|TTY_NINDYTERM
parameter_list|(
name|tty
parameter_list|)
value|{		\ 		tty.c_iflag = 0;		\ 		tty.c_oflag = 0;		\ 		tty.c_lflag = ISIG;		\ 		tty.c_cc[VEOF] = 1;		\ 		tty.c_cc[VEOL] = 0;		\ 	}
end_define

begin_define
define|#
directive|define
name|TTY_FLUSH
parameter_list|(
name|fd
parameter_list|)
value|ioctl(fd,TCFLSH,2);
end_define

begin_define
define|#
directive|define
name|TTY_NBREAD
parameter_list|(
name|fd
parameter_list|,
name|n
parameter_list|,
name|bufptr
parameter_list|)
value|{			\ 		int _saveflags_;				\ 		_saveflags_ = fcntl( fd, F_GETFL, 0 );		\ 		fcntl( fd, F_SETFL, _saveflags_ | O_NDELAY );	\ 		n = read( fd, bufptr, n );			\ 		fcntl( fd, F_SETFL, _saveflags_ );		\ 	}
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
file|<sys/ioctl.h>
end_include

begin_define
define|#
directive|define
name|TTY_STRUCT
value|struct sgttyb
end_define

begin_define
define|#
directive|define
name|TTY_REMOTE
parameter_list|(
name|tty
parameter_list|,
name|baud
parameter_list|)
value|{            \                 tty.sg_flags = RAW | TANDEM;    \                 tty.sg_ispeed = baud;           \                 tty.sg_ospeed = baud;           \         }
end_define

begin_define
define|#
directive|define
name|TTY_NINDYTERM
parameter_list|(
name|tty
parameter_list|)
value|{	\ 		tty.sg_flags |= CBREAK;		\ 		tty.sg_flags&= ~(ECHO|CRMOD);	\ 	}
end_define

begin_define
define|#
directive|define
name|TTY_FLUSH
parameter_list|(
name|fd
parameter_list|)
value|{ int _i_ = 0; ioctl(fd,TIOCFLUSH,&_i_); }
end_define

begin_define
define|#
directive|define
name|TTY_NBREAD
parameter_list|(
name|fd
parameter_list|,
name|n
parameter_list|,
name|bufptr
parameter_list|)
value|{		\ 		int _n_;				\ 		ioctl(fd,FIONREAD,&_n_);		\ 		n = (_n_>0) ? read(fd,bufptr,n) : 0;	\ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|B19200
end_ifndef

begin_define
define|#
directive|define
name|B19200
value|EXTA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|B38400
end_ifndef

begin_define
define|#
directive|define
name|B38400
value|EXTB
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

