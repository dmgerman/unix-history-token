begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)defs.h	8.1 (Berkeley) 6/4/93  */
end_comment

begin_comment
comment|/*  * Telnet server defines  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|BSD
value|43
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CRAY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LINEMODE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYSV_TERMIO
end_define

begin_define
define|#
directive|define
name|LINEMODE
end_define

begin_define
define|#
directive|define
name|KLUDGELINEMODE
end_define

begin_define
define|#
directive|define
name|DIAGNOSTICS
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UNICOS50
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|UNICOS5
argument_list|)
end_if

begin_define
define|#
directive|define
name|UNICOS5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|UNICOS5
argument_list|)
end_if

begin_define
define|#
directive|define
name|BFTPDAEMON
end_define

begin_define
define|#
directive|define
name|HAS_IP_TOS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRAY */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UNICOS5
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_SETSID
argument_list|)
end_if

begin_define
define|#
directive|define
name|NO_SETSID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PRINTOPTIONS
argument_list|)
operator|&&
name|defined
argument_list|(
name|DIAGNOSTICS
argument_list|)
end_if

begin_define
define|#
directive|define
name|TELOPTS
end_define

begin_define
define|#
directive|define
name|TELCMDS
end_define

begin_define
define|#
directive|define
name|SLC_NAMES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSV_TERMIO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_TERMIO
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_TERMIO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|CRAY
end_ifndef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRAY */
end_comment

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|FILIO_H
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/telnet.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_DAEMON
end_ifndef

begin_define
define|#
directive|define
name|LOG_DAEMON
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_ODELAY
end_ifndef

begin_define
define|#
directive|define
name|LOG_ODELAY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NO_STRING_H
end_ifndef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_TERMIO
end_ifndef

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV_TERMIO
end_ifdef

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|USE_TERMIO
argument_list|)
operator|||
name|defined
argument_list|(
name|NO_CC_T
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|char
name|cc_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_VDISABLE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|VDISABLE
end_ifdef

begin_define
define|#
directive|define
name|_POSIX_VDISABLE
value|VDISABLE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_POSIX_VDISABLE
value|((unsigned char)'\377')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY1
end_ifdef

begin_include
include|#
directive|include
file|<sys/pty.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|FD_ZERO
end_ifndef

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FD_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRAY1 */
end_comment

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
comment|/* CRAY */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_include
include|#
directive|include
file|<sys/ptyio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TIOCSCTTY
argument_list|)
operator|&&
name|defined
argument_list|(
name|TCSETCTTY
argument_list|)
end_if

begin_define
define|#
directive|define
name|TIOCSCTTY
value|TCSETCTTY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FD_SET
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_fd_set
end_ifndef

begin_typedef
typedef|typedef
struct|struct
name|fd_set
block|{
name|int
name|fds_bits
index|[
literal|1
index|]
decl_stmt|;
block|}
name|fd_set
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[0] |= (1<<(n)))
end_define

begin_define
define|#
directive|define
name|FD_CLR
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[0]&= ~(1<<(n)))
end_define

begin_define
define|#
directive|define
name|FD_ISSET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[0]& (1<<(n)))
end_define

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|p
parameter_list|)
value|((p)->fds_bits[0] = 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FD_SET */
end_comment

begin_comment
comment|/*  * I/O data buffers defines  */
end_comment

begin_define
define|#
directive|define
name|NETSLOP
value|64
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY
end_ifdef

begin_undef
undef|#
directive|undef
name|BUFSIZ
end_undef

begin_define
define|#
directive|define
name|BUFSIZ
value|2048
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NIACCUM
parameter_list|(
name|c
parameter_list|)
value|{   *netip++ = c; \ 			    ncc++; \ 			}
end_define

begin_comment
comment|/* clock manipulations */
end_comment

begin_define
define|#
directive|define
name|settimer
parameter_list|(
name|x
parameter_list|)
value|(clocks.x = ++clocks.system)
end_define

begin_define
define|#
directive|define
name|sequenceIs
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(clocks.x< clocks.y)
end_define

begin_comment
comment|/*  * Linemode support states, in decreasing order of importance  */
end_comment

begin_define
define|#
directive|define
name|REAL_LINEMODE
value|0x04
end_define

begin_define
define|#
directive|define
name|KLUDGE_OK
value|0x03
end_define

begin_define
define|#
directive|define
name|NO_AUTOKLUDGE
value|0x02
end_define

begin_define
define|#
directive|define
name|KLUDGE_LINEMODE
value|0x01
end_define

begin_define
define|#
directive|define
name|NO_LINEMODE
value|0x00
end_define

begin_comment
comment|/*  * Structures of information for each special character function.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|flag
decl_stmt|;
comment|/* the flags for this function */
name|cc_t
name|val
decl_stmt|;
comment|/* the value of the special character */
block|}
name|slcent
operator|,
typedef|*
name|Slcent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|slcent
name|defset
decl_stmt|;
comment|/* the default settings */
name|slcent
name|current
decl_stmt|;
comment|/* the current settings */
name|cc_t
modifier|*
name|sptr
decl_stmt|;
comment|/* a pointer to the char in */
comment|/* system data structures */
block|}
name|slcfun
operator|,
typedef|*
name|Slcfun
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|DIAGNOSTICS
end_ifdef

begin_comment
comment|/*  * Diagnostics capabilities  */
end_comment

begin_define
define|#
directive|define
name|TD_REPORT
value|0x01
end_define

begin_comment
comment|/* Report operations to client */
end_comment

begin_define
define|#
directive|define
name|TD_EXERCISE
value|0x02
end_define

begin_comment
comment|/* Exercise client's implementation */
end_comment

begin_define
define|#
directive|define
name|TD_NETDATA
value|0x04
end_define

begin_comment
comment|/* Display received data stream */
end_comment

begin_define
define|#
directive|define
name|TD_PTYDATA
value|0x08
end_define

begin_comment
comment|/* Display data passed to pty */
end_comment

begin_define
define|#
directive|define
name|TD_OPTIONS
value|0x10
end_define

begin_comment
comment|/* Report just telnet options */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIAGNOSTICS */
end_comment

begin_comment
comment|/*  * We keep track of each side of the option negotiation.  */
end_comment

begin_define
define|#
directive|define
name|MY_STATE_WILL
value|0x01
end_define

begin_define
define|#
directive|define
name|MY_WANT_STATE_WILL
value|0x02
end_define

begin_define
define|#
directive|define
name|MY_STATE_DO
value|0x04
end_define

begin_define
define|#
directive|define
name|MY_WANT_STATE_DO
value|0x08
end_define

begin_comment
comment|/*  * Macros to check the current state of things  */
end_comment

begin_define
define|#
directive|define
name|my_state_is_do
parameter_list|(
name|opt
parameter_list|)
value|(options[opt]&MY_STATE_DO)
end_define

begin_define
define|#
directive|define
name|my_state_is_will
parameter_list|(
name|opt
parameter_list|)
value|(options[opt]&MY_STATE_WILL)
end_define

begin_define
define|#
directive|define
name|my_want_state_is_do
parameter_list|(
name|opt
parameter_list|)
value|(options[opt]&MY_WANT_STATE_DO)
end_define

begin_define
define|#
directive|define
name|my_want_state_is_will
parameter_list|(
name|opt
parameter_list|)
value|(options[opt]&MY_WANT_STATE_WILL)
end_define

begin_define
define|#
directive|define
name|my_state_is_dont
parameter_list|(
name|opt
parameter_list|)
value|(!my_state_is_do(opt))
end_define

begin_define
define|#
directive|define
name|my_state_is_wont
parameter_list|(
name|opt
parameter_list|)
value|(!my_state_is_will(opt))
end_define

begin_define
define|#
directive|define
name|my_want_state_is_dont
parameter_list|(
name|opt
parameter_list|)
value|(!my_want_state_is_do(opt))
end_define

begin_define
define|#
directive|define
name|my_want_state_is_wont
parameter_list|(
name|opt
parameter_list|)
value|(!my_want_state_is_will(opt))
end_define

begin_define
define|#
directive|define
name|set_my_state_do
parameter_list|(
name|opt
parameter_list|)
value|(options[opt] |= MY_STATE_DO)
end_define

begin_define
define|#
directive|define
name|set_my_state_will
parameter_list|(
name|opt
parameter_list|)
value|(options[opt] |= MY_STATE_WILL)
end_define

begin_define
define|#
directive|define
name|set_my_want_state_do
parameter_list|(
name|opt
parameter_list|)
value|(options[opt] |= MY_WANT_STATE_DO)
end_define

begin_define
define|#
directive|define
name|set_my_want_state_will
parameter_list|(
name|opt
parameter_list|)
value|(options[opt] |= MY_WANT_STATE_WILL)
end_define

begin_define
define|#
directive|define
name|set_my_state_dont
parameter_list|(
name|opt
parameter_list|)
value|(options[opt]&= ~MY_STATE_DO)
end_define

begin_define
define|#
directive|define
name|set_my_state_wont
parameter_list|(
name|opt
parameter_list|)
value|(options[opt]&= ~MY_STATE_WILL)
end_define

begin_define
define|#
directive|define
name|set_my_want_state_dont
parameter_list|(
name|opt
parameter_list|)
value|(options[opt]&= ~MY_WANT_STATE_DO)
end_define

begin_define
define|#
directive|define
name|set_my_want_state_wont
parameter_list|(
name|opt
parameter_list|)
value|(options[opt]&= ~MY_WANT_STATE_WILL)
end_define

begin_comment
comment|/*  * Tricky code here.  What we want to know is if the MY_STATE_WILL  * and MY_WANT_STATE_WILL bits have the same value.  Since the two  * bits are adjacent, a little arithmatic will show that by adding  * in the lower bit, the upper bit will be set if the two bits were  * different, and clear if they were the same.  */
end_comment

begin_define
define|#
directive|define
name|my_will_wont_is_changing
parameter_list|(
name|opt
parameter_list|)
define|\
value|((options[opt]+MY_STATE_WILL)& MY_WANT_STATE_WILL)
end_define

begin_define
define|#
directive|define
name|my_do_dont_is_changing
parameter_list|(
name|opt
parameter_list|)
define|\
value|((options[opt]+MY_STATE_DO)& MY_WANT_STATE_DO)
end_define

begin_comment
comment|/*  * Make everything symetrical  */
end_comment

begin_define
define|#
directive|define
name|HIS_STATE_WILL
value|MY_STATE_DO
end_define

begin_define
define|#
directive|define
name|HIS_WANT_STATE_WILL
value|MY_WANT_STATE_DO
end_define

begin_define
define|#
directive|define
name|HIS_STATE_DO
value|MY_STATE_WILL
end_define

begin_define
define|#
directive|define
name|HIS_WANT_STATE_DO
value|MY_WANT_STATE_WILL
end_define

begin_define
define|#
directive|define
name|his_state_is_do
value|my_state_is_will
end_define

begin_define
define|#
directive|define
name|his_state_is_will
value|my_state_is_do
end_define

begin_define
define|#
directive|define
name|his_want_state_is_do
value|my_want_state_is_will
end_define

begin_define
define|#
directive|define
name|his_want_state_is_will
value|my_want_state_is_do
end_define

begin_define
define|#
directive|define
name|his_state_is_dont
value|my_state_is_wont
end_define

begin_define
define|#
directive|define
name|his_state_is_wont
value|my_state_is_dont
end_define

begin_define
define|#
directive|define
name|his_want_state_is_dont
value|my_want_state_is_wont
end_define

begin_define
define|#
directive|define
name|his_want_state_is_wont
value|my_want_state_is_dont
end_define

begin_define
define|#
directive|define
name|set_his_state_do
value|set_my_state_will
end_define

begin_define
define|#
directive|define
name|set_his_state_will
value|set_my_state_do
end_define

begin_define
define|#
directive|define
name|set_his_want_state_do
value|set_my_want_state_will
end_define

begin_define
define|#
directive|define
name|set_his_want_state_will
value|set_my_want_state_do
end_define

begin_define
define|#
directive|define
name|set_his_state_dont
value|set_my_state_wont
end_define

begin_define
define|#
directive|define
name|set_his_state_wont
value|set_my_state_dont
end_define

begin_define
define|#
directive|define
name|set_his_want_state_dont
value|set_my_want_state_wont
end_define

begin_define
define|#
directive|define
name|set_his_want_state_wont
value|set_my_want_state_dont
end_define

begin_define
define|#
directive|define
name|his_will_wont_is_changing
value|my_do_dont_is_changing
end_define

begin_define
define|#
directive|define
name|his_do_dont_is_changing
value|my_will_wont_is_changing
end_define

end_unit

