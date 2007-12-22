begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: pathnames.h,v 1.7 2004/04/25 18:40:42 beck Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 2002 Chris Kuethe (ckuethe@ualberta.ca)  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|PATH_CONFFILE
value|"/etc/authpf/authpf.conf"
end_define

begin_define
define|#
directive|define
name|PATH_ALLOWFILE
value|"/etc/authpf/authpf.allow"
end_define

begin_define
define|#
directive|define
name|PATH_PFRULES
value|"/etc/authpf/authpf.rules"
end_define

begin_define
define|#
directive|define
name|PATH_PROBLEM
value|"/etc/authpf/authpf.problem"
end_define

begin_define
define|#
directive|define
name|PATH_MESSAGE
value|"/etc/authpf/authpf.message"
end_define

begin_define
define|#
directive|define
name|PATH_USER_DIR
value|"/etc/authpf/users"
end_define

begin_define
define|#
directive|define
name|PATH_BAN_DIR
value|"/etc/authpf/banned"
end_define

begin_define
define|#
directive|define
name|PATH_DEVFILE
value|"/dev/pf"
end_define

begin_define
define|#
directive|define
name|PATH_PIDFILE
value|"/var/authpf"
end_define

begin_define
define|#
directive|define
name|PATH_AUTHPF_SHELL
value|"/usr/sbin/authpf"
end_define

begin_define
define|#
directive|define
name|PATH_PFCTL
value|"/sbin/pfctl"
end_define

end_unit

