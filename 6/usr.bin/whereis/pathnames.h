begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright © 2002, Jörg Wunsch  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Where to look for libexec and games */
end_comment

begin_define
define|#
directive|define
name|PATH_LIBEXEC
value|"/usr/libexec"
end_define

begin_define
define|#
directive|define
name|PATH_GAMES
value|"/usr/games"
end_define

begin_comment
comment|/* Where to look for sources. */
end_comment

begin_define
define|#
directive|define
name|PATH_SOURCES
define|\
value|"/usr/src/bin:/usr/src/usr.bin:/usr/src/sbin:"		\ "/usr/src/usr.sbin:/usr/src/libexec:"			\ "/usr/src/gnu/bin:/usr/src/gnu/usr.bin:"		\ "/usr/src/gnu/sbin:/usr/src/gnu/usr.sbin:"		\ "/usr/src/gnu/libexec:/usr/src/contrib:"		\ "/usr/src/secure/bin:/usr/src/secure/usr.bin:"		\ "/usr/src/secure/sbin:/usr/src/secure/usr.sbin:"	\ "/usr/src/secure/libexec:/usr/src/crypto:"		\ "/usr/src/games"
end_define

begin_comment
comment|/* Each subdirectory of PATH_PORTS will be appended to PATH_SOURCES. */
end_comment

begin_define
define|#
directive|define
name|PATH_PORTS
value|"/usr/ports"
end_define

begin_comment
comment|/* How to query the current manpath. */
end_comment

begin_define
define|#
directive|define
name|MANPATHCMD
value|"manpath -q"
end_define

begin_comment
comment|/* How to obtain the location of manpages, and how to match this result. */
end_comment

begin_define
define|#
directive|define
name|MANWHEREISCMD
value|"man -S1:8:6 -w %s 2>/dev/null"
end_define

begin_define
define|#
directive|define
name|MANWHEREISALLCMD
value|"man -a -w %s 2>/dev/null"
end_define

begin_define
define|#
directive|define
name|MANWHEREISMATCH
value|"^.* [(]source: (.*)[)]$"
end_define

begin_comment
comment|/* Command used to locate sources that have not been found yet. */
end_comment

begin_define
define|#
directive|define
name|LOCATECMD
value|"locate '*'/%s 2>/dev/null"
end_define

end_unit

