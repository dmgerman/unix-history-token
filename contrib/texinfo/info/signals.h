begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* signals.h -- Header to include system dependent signal definitions.    $Id: signals.h,v 1.3 1997/07/15 18:35:59 karl Exp $     This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1993, 94, 95, 97 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFO_SIGNALS_H
end_ifndef

begin_define
define|#
directive|define
name|INFO_SIGNALS_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/* For sysV68 --phdm@info.ucl.ac.be.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SIGCHLD
argument_list|)
operator|&&
name|defined
argument_list|(
name|SIGCLD
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGCHLD
value|SIGCLD
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
name|HAVE_SIGPROCMASK
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|sigmask
argument_list|)
end_if

begin_define
define|#
directive|define
name|sigmask
parameter_list|(
name|x
parameter_list|)
value|(1<< ((x)-1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_SIGPROCMASK&& !sigmask */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SIGPROCMASK
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SIG_BLOCK
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIG_UNBLOCK
value|1
end_define

begin_define
define|#
directive|define
name|SIG_BLOCK
value|2
end_define

begin_define
define|#
directive|define
name|SIG_SETMASK
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIG_BLOCK */
end_comment

begin_comment
comment|/* Type of a signal set. */
end_comment

begin_define
define|#
directive|define
name|sigset_t
value|int
end_define

begin_comment
comment|/* Make SET have no signals in it. */
end_comment

begin_define
define|#
directive|define
name|sigemptyset
parameter_list|(
name|set
parameter_list|)
value|(*(set) = (sigset_t)0x0)
end_define

begin_comment
comment|/* Make SET have the full range of signal specifications possible. */
end_comment

begin_define
define|#
directive|define
name|sigfillset
parameter_list|(
name|set
parameter_list|)
value|(*(set) = (sigset_t)0xffffffffff)
end_define

begin_comment
comment|/* Add SIG to the contents of SET. */
end_comment

begin_define
define|#
directive|define
name|sigaddset
parameter_list|(
name|set
parameter_list|,
name|sig
parameter_list|)
value|*(set) |= sigmask (sig)
end_define

begin_comment
comment|/* Delete SIG from the contents of SET. */
end_comment

begin_define
define|#
directive|define
name|sigdelset
parameter_list|(
name|set
parameter_list|,
name|sig
parameter_list|)
value|*(set)&= ~(sigmask (sig))
end_define

begin_comment
comment|/* Tell if SET contains SIG. */
end_comment

begin_define
define|#
directive|define
name|sigismember
parameter_list|(
name|set
parameter_list|,
name|sig
parameter_list|)
value|(*(set)& (sigmask (sig)))
end_define

begin_comment
comment|/* Suspend the process until the reception of one of the signals    not present in SET. */
end_comment

begin_define
define|#
directive|define
name|sigsuspend
parameter_list|(
name|set
parameter_list|)
value|sigpause (*(set))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_SIGPROCMASK */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SIGPROCMASK
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_SIGSETMASK
argument_list|)
end_if

begin_comment
comment|/* These definitions are used both in POSIX and non-POSIX implementations. */
end_comment

begin_define
define|#
directive|define
name|BLOCK_SIGNAL
parameter_list|(
name|sig
parameter_list|)
define|\
value|do { \     sigset_t nvar, ovar; \     sigemptyset (&nvar); \     sigemptyset (&ovar); \     sigaddset (&nvar, sig); \     sigprocmask (SIG_BLOCK,&nvar,&ovar); \   } while (0)
end_define

begin_define
define|#
directive|define
name|UNBLOCK_SIGNAL
parameter_list|(
name|sig
parameter_list|)
define|\
value|do { \     sigset_t nvar, ovar; \     sigemptyset (&ovar); \     sigemptyset (&nvar); \     sigaddset (&nvar, sig); \     sigprocmask (SIG_UNBLOCK,&nvar,&ovar); \   } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_SIGPROCMASK&& !HAVE_SIGSETMASK */
end_comment

begin_define
define|#
directive|define
name|BLOCK_SIGNAL
parameter_list|(
name|sig
parameter_list|)
end_define

begin_define
define|#
directive|define
name|UNBLOCK_SIGNAL
parameter_list|(
name|sig
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_SIGPROCMASK&& !HAVE_SIGSETMASK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not INFO_SIGNALS_H */
end_comment

end_unit

