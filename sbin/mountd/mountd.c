begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Herb Hasler and Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1989, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*not lint*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_comment
comment|/*static char sccsid[] = "From: @(#)mountd.c	8.8 (Berkeley) 2/20/94";*/
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id: mountd.c,v 1.11.2.8 1997/09/30 13:25:35 jlemon Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*not lint*/
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|<rpc/pmap_clnt.h>
end_include

begin_include
include|#
directive|include
file|<rpc/pmap_prot.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ISO
end_ifdef

begin_include
include|#
directive|include
file|<netiso/iso.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<nfs/rpcv2.h>
end_include

begin_include
include|#
directive|include
file|<nfs/nfsproto.h>
end_include

begin_include
include|#
directive|include
file|<nfs/nfs.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Structures for keeping the mount list and export list  */
end_comment

begin_struct
struct|struct
name|mountlist
block|{
name|struct
name|mountlist
modifier|*
name|ml_next
decl_stmt|;
name|char
name|ml_host
index|[
name|RPCMNT_NAMELEN
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|ml_dirp
index|[
name|RPCMNT_PATHLEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dirlist
block|{
name|struct
name|dirlist
modifier|*
name|dp_left
decl_stmt|;
name|struct
name|dirlist
modifier|*
name|dp_right
decl_stmt|;
name|int
name|dp_flag
decl_stmt|;
name|struct
name|hostlist
modifier|*
name|dp_hosts
decl_stmt|;
comment|/* List of hosts this dir exported to */
name|char
name|dp_dirp
index|[
literal|1
index|]
decl_stmt|;
comment|/* Actually malloc'd to size of dir */
block|}
struct|;
end_struct

begin_comment
comment|/* dp_flag bits */
end_comment

begin_define
define|#
directive|define
name|DP_DEFSET
value|0x1
end_define

begin_define
define|#
directive|define
name|DP_HOSTSET
value|0x2
end_define

begin_define
define|#
directive|define
name|DP_KERB
value|0x4
end_define

begin_struct
struct|struct
name|exportlist
block|{
name|struct
name|exportlist
modifier|*
name|ex_next
decl_stmt|;
name|struct
name|dirlist
modifier|*
name|ex_dirl
decl_stmt|;
name|struct
name|dirlist
modifier|*
name|ex_defdir
decl_stmt|;
name|int
name|ex_flag
decl_stmt|;
name|fsid_t
name|ex_fs
decl_stmt|;
name|char
modifier|*
name|ex_fsdir
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ex_flag bits */
end_comment

begin_define
define|#
directive|define
name|EX_LINKED
value|0x1
end_define

begin_struct
struct|struct
name|netmsk
block|{
name|u_long
name|nt_net
decl_stmt|;
name|u_long
name|nt_mask
decl_stmt|;
name|char
modifier|*
name|nt_name
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|grouptypes
block|{
name|struct
name|hostent
modifier|*
name|gt_hostent
decl_stmt|;
name|struct
name|netmsk
name|gt_net
decl_stmt|;
ifdef|#
directive|ifdef
name|ISO
name|struct
name|sockaddr_iso
modifier|*
name|gt_isoaddr
decl_stmt|;
endif|#
directive|endif
block|}
union|;
end_union

begin_struct
struct|struct
name|grouplist
block|{
name|int
name|gr_type
decl_stmt|;
name|union
name|grouptypes
name|gr_ptr
decl_stmt|;
name|struct
name|grouplist
modifier|*
name|gr_next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Group types */
end_comment

begin_define
define|#
directive|define
name|GT_NULL
value|0x0
end_define

begin_define
define|#
directive|define
name|GT_HOST
value|0x1
end_define

begin_define
define|#
directive|define
name|GT_NET
value|0x2
end_define

begin_define
define|#
directive|define
name|GT_ISO
value|0x4
end_define

begin_define
define|#
directive|define
name|GT_IGNORE
value|0x5
end_define

begin_struct
struct|struct
name|hostlist
block|{
name|int
name|ht_flag
decl_stmt|;
comment|/* Uses DP_xx bits */
name|struct
name|grouplist
modifier|*
name|ht_grp
decl_stmt|;
name|struct
name|hostlist
modifier|*
name|ht_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fhreturn
block|{
name|int
name|fhr_flag
decl_stmt|;
name|int
name|fhr_vers
decl_stmt|;
name|nfsfh_t
name|fhr_fh
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Global defs */
end_comment

begin_decl_stmt
name|char
modifier|*
name|add_expdir
name|__P
argument_list|(
operator|(
expr|struct
name|dirlist
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|add_dlist
name|__P
argument_list|(
operator|(
expr|struct
name|dirlist
operator|*
operator|*
operator|,
expr|struct
name|dirlist
operator|*
operator|,
expr|struct
name|grouplist
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|add_mlist
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|check_dirpath
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|check_options
name|__P
argument_list|(
operator|(
expr|struct
name|dirlist
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|chk_host
name|__P
argument_list|(
operator|(
expr|struct
name|dirlist
operator|*
operator|,
name|u_long
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|del_mlist
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|dirlist
modifier|*
name|dirp_search
name|__P
argument_list|(
operator|(
expr|struct
name|dirlist
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_mount
name|__P
argument_list|(
operator|(
expr|struct
name|exportlist
operator|*
operator|,
expr|struct
name|grouplist
operator|*
operator|,
name|int
operator|,
expr|struct
name|ucred
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
expr|struct
name|statfs
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_opt
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|exportlist
operator|*
operator|,
expr|struct
name|grouplist
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|,
expr|struct
name|ucred
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|exportlist
modifier|*
name|ex_search
name|__P
argument_list|(
operator|(
name|fsid_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|exportlist
modifier|*
name|get_exp
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
name|free_dir
name|__P
argument_list|(
operator|(
expr|struct
name|dirlist
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_exp
name|__P
argument_list|(
operator|(
expr|struct
name|exportlist
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_grp
name|__P
argument_list|(
operator|(
expr|struct
name|grouplist
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_host
name|__P
argument_list|(
operator|(
expr|struct
name|hostlist
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_exportlist
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
name|get_host
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|grouplist
operator|*
operator|,
expr|struct
name|grouplist
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|get_num
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|hostlist
modifier|*
name|get_ht
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
name|get_line
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
name|get_mountlist
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
name|get_net
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|netmsk
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|getexp_err
name|__P
argument_list|(
operator|(
expr|struct
name|exportlist
operator|*
operator|,
expr|struct
name|grouplist
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|grouplist
modifier|*
name|get_grp
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
name|hang_dirp
name|__P
argument_list|(
operator|(
expr|struct
name|dirlist
operator|*
operator|,
expr|struct
name|grouplist
operator|*
operator|,
expr|struct
name|exportlist
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mntsrv
name|__P
argument_list|(
operator|(
expr|struct
name|svc_req
operator|*
operator|,
name|SVCXPRT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nextfield
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|out_of_mem
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
name|parsecred
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|ucred
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|put_exlist
name|__P
argument_list|(
operator|(
expr|struct
name|dirlist
operator|*
operator|,
name|XDR
operator|*
operator|,
expr|struct
name|dirlist
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
name|scan_tree
name|__P
argument_list|(
operator|(
expr|struct
name|dirlist
operator|*
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|send_umntall
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
name|umntall_each
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xdr_dir
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xdr_explist
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xdr_fhs
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xdr_mlist
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C library */
end_comment

begin_function_decl
name|int
name|getnetgrent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endnetgrent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setnetgrent
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ISO
end_ifdef

begin_function_decl
name|struct
name|iso_addr
modifier|*
name|iso_addr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|exportlist
modifier|*
name|exphead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mountlist
modifier|*
name|mlhead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|grouplist
modifier|*
name|grphead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|exname
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ucred
name|def_anon
init|=
block|{
literal|1
block|,
operator|(
name|uid_t
operator|)
operator|-
literal|2
block|,
literal|1
block|,
block|{
operator|(
name|gid_t
operator|)
operator|-
literal|2
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|force_v2
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|resvport_only
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dir_only
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opt_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bits for above */
end_comment

begin_define
define|#
directive|define
name|OP_MAPROOT
value|0x01
end_define

begin_define
define|#
directive|define
name|OP_MAPALL
value|0x02
end_define

begin_define
define|#
directive|define
name|OP_KERB
value|0x04
end_define

begin_define
define|#
directive|define
name|OP_MASK
value|0x08
end_define

begin_define
define|#
directive|define
name|OP_NET
value|0x10
end_define

begin_define
define|#
directive|define
name|OP_ISO
value|0x20
end_define

begin_define
define|#
directive|define
name|OP_ALLDIRS
value|0x40
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|int
name|debug
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|SYSLOG
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|syslog
value|SYSLOG
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|debug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Mountd server for NFS mount protocol as described in:  * NFS: Network File System Protocol Specification, RFC1094, Appendix A  * The optional arguments are the exports file name  * default: _PATH_EXPORTS  * and "-n" to allow nonroot mount.  */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|SVCXPRT
modifier|*
name|udptransp
decl_stmt|,
modifier|*
name|tcptransp
decl_stmt|;
name|int
name|c
decl_stmt|;
name|int
name|mib
index|[
literal|3
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|vfsconf
modifier|*
name|vfc
decl_stmt|;
name|vfc
operator|=
name|getvfsbyname
argument_list|(
literal|"nfs"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|vfc
operator|&&
name|vfsisloadable
argument_list|(
literal|"nfs"
argument_list|)
condition|)
block|{
if|if
condition|(
name|vfsload
argument_list|(
literal|"nfs"
argument_list|)
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"vfsload(nfs)"
argument_list|)
expr_stmt|;
name|endvfsent
argument_list|()
expr_stmt|;
comment|/* flush cache */
name|vfc
operator|=
name|getvfsbyname
argument_list|(
literal|"nfs"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|vfc
condition|)
block|{
name|errx
argument_list|(
literal|1
argument_list|,
literal|"NFS support is not available in the running kernel"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* __FreeBSD__ */
while|while
condition|(
operator|(
name|c
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"2dnr"
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'2'
case|:
name|force_v2
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'n'
case|:
name|resvport_only
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'r'
case|:
name|dir_only
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
name|debug
operator|=
name|debug
condition|?
literal|0
else|:
literal|1
expr_stmt|;
break|break;
default|default:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Usage: mountd [-r] [-n] [export_file]\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
name|argc
operator|-=
name|optind
expr_stmt|;
name|argv
operator|+=
name|optind
expr_stmt|;
name|grphead
operator|=
operator|(
expr|struct
name|grouplist
operator|*
operator|)
name|NULL
expr_stmt|;
name|exphead
operator|=
operator|(
expr|struct
name|exportlist
operator|*
operator|)
name|NULL
expr_stmt|;
name|mlhead
operator|=
operator|(
expr|struct
name|mountlist
operator|*
operator|)
name|NULL
expr_stmt|;
if|if
condition|(
name|argc
operator|==
literal|1
condition|)
block|{
name|strncpy
argument_list|(
name|exname
argument_list|,
operator|*
name|argv
argument_list|,
name|MAXPATHLEN
operator|-
literal|1
argument_list|)
expr_stmt|;
name|exname
index|[
name|MAXPATHLEN
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
else|else
name|strcpy
argument_list|(
name|exname
argument_list|,
name|_PATH_EXPORTS
argument_list|)
expr_stmt|;
name|openlog
argument_list|(
literal|"mountd"
argument_list|,
name|LOG_PID
argument_list|,
name|LOG_DAEMON
argument_list|)
expr_stmt|;
if|if
condition|(
name|debug
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Getting export list.\n"
argument_list|)
expr_stmt|;
name|get_exportlist
argument_list|()
expr_stmt|;
if|if
condition|(
name|debug
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Getting mount list.\n"
argument_list|)
expr_stmt|;
name|get_mountlist
argument_list|()
expr_stmt|;
if|if
condition|(
name|debug
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Here we go.\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|debug
operator|==
literal|0
condition|)
block|{
name|daemon
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
block|}
name|signal
argument_list|(
name|SIGHUP
argument_list|,
operator|(
name|void
argument_list|(
argument|*
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
operator|)
name|get_exportlist
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGTERM
argument_list|,
operator|(
name|void
argument_list|(
argument|*
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
operator|)
name|send_umntall
argument_list|)
expr_stmt|;
block|{
name|FILE
modifier|*
name|pidfile
init|=
name|fopen
argument_list|(
name|_PATH_MOUNTDPID
argument_list|,
literal|"w"
argument_list|)
decl_stmt|;
if|if
condition|(
name|pidfile
operator|!=
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|pidfile
argument_list|,
literal|"%d\n"
argument_list|,
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|pidfile
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|resvport_only
condition|)
block|{
name|mib
index|[
literal|0
index|]
operator|=
name|CTL_VFS
expr_stmt|;
name|mib
index|[
literal|1
index|]
operator|=
name|MOUNT_NFS
expr_stmt|;
name|mib
index|[
literal|2
index|]
operator|=
name|NFS_NFSPRIVPORT
expr_stmt|;
if|if
condition|(
name|sysctl
argument_list|(
name|mib
argument_list|,
literal|3
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
operator|&
name|resvport_only
argument_list|,
sizeof|sizeof
argument_list|(
name|resvport_only
argument_list|)
argument_list|)
operator|!=
literal|0
operator|&&
name|errno
operator|!=
name|ENOENT
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"sysctl: %m"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|(
name|udptransp
operator|=
name|svcudp_create
argument_list|(
name|RPC_ANYSOCK
argument_list|)
operator|)
operator|==
name|NULL
operator|||
operator|(
name|tcptransp
operator|=
name|svctcp_create
argument_list|(
name|RPC_ANYSOCK
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Can't create socket"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|pmap_unset
argument_list|(
name|RPCPROG_MNT
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|pmap_unset
argument_list|(
name|RPCPROG_MNT
argument_list|,
literal|3
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|force_v2
condition|)
if|if
condition|(
operator|!
name|svc_register
argument_list|(
name|udptransp
argument_list|,
name|RPCPROG_MNT
argument_list|,
literal|3
argument_list|,
name|mntsrv
argument_list|,
name|IPPROTO_UDP
argument_list|)
operator|||
operator|!
name|svc_register
argument_list|(
name|tcptransp
argument_list|,
name|RPCPROG_MNT
argument_list|,
literal|3
argument_list|,
name|mntsrv
argument_list|,
name|IPPROTO_TCP
argument_list|)
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Can't register mount"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|svc_register
argument_list|(
name|udptransp
argument_list|,
name|RPCPROG_MNT
argument_list|,
literal|1
argument_list|,
name|mntsrv
argument_list|,
name|IPPROTO_UDP
argument_list|)
operator|||
operator|!
name|svc_register
argument_list|(
name|tcptransp
argument_list|,
name|RPCPROG_MNT
argument_list|,
literal|1
argument_list|,
name|mntsrv
argument_list|,
name|IPPROTO_TCP
argument_list|)
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Can't register mount"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|svc_run
argument_list|()
expr_stmt|;
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Mountd died"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * The mount rpc service  */
end_comment

begin_function
name|void
name|mntsrv
parameter_list|(
name|rqstp
parameter_list|,
name|transp
parameter_list|)
name|struct
name|svc_req
modifier|*
name|rqstp
decl_stmt|;
name|SVCXPRT
modifier|*
name|transp
decl_stmt|;
block|{
name|struct
name|exportlist
modifier|*
name|ep
decl_stmt|;
name|struct
name|dirlist
modifier|*
name|dp
decl_stmt|;
name|struct
name|fhreturn
name|fhr
decl_stmt|;
name|struct
name|authunix_parms
modifier|*
name|ucr
decl_stmt|;
name|struct
name|stat
name|stb
decl_stmt|;
name|struct
name|statfs
name|fsb
decl_stmt|;
name|struct
name|hostent
modifier|*
name|hp
decl_stmt|;
name|u_long
name|saddr
decl_stmt|;
name|u_short
name|sport
decl_stmt|;
name|char
name|rpcpath
index|[
name|RPCMNT_PATHLEN
operator|+
literal|1
index|]
decl_stmt|,
name|dirpath
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|int
name|bad
init|=
literal|0
decl_stmt|,
name|defset
decl_stmt|,
name|hostset
decl_stmt|;
name|sigset_t
name|sighup_mask
decl_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|sighup_mask
argument_list|)
expr_stmt|;
name|sigaddset
argument_list|(
operator|&
name|sighup_mask
argument_list|,
name|SIGHUP
argument_list|)
expr_stmt|;
name|saddr
operator|=
name|transp
operator|->
name|xp_raddr
operator|.
name|sin_addr
operator|.
name|s_addr
expr_stmt|;
name|sport
operator|=
name|ntohs
argument_list|(
name|transp
operator|->
name|xp_raddr
operator|.
name|sin_port
argument_list|)
expr_stmt|;
name|hp
operator|=
operator|(
expr|struct
name|hostent
operator|*
operator|)
name|NULL
expr_stmt|;
switch|switch
condition|(
name|rqstp
operator|->
name|rq_proc
condition|)
block|{
case|case
name|NULLPROC
case|:
if|if
condition|(
operator|!
name|svc_sendreply
argument_list|(
name|transp
argument_list|,
name|xdr_void
argument_list|,
operator|(
name|caddr_t
operator|)
name|NULL
argument_list|)
condition|)
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Can't send reply"
argument_list|)
expr_stmt|;
return|return;
case|case
name|RPCMNT_MOUNT
case|:
if|if
condition|(
name|sport
operator|>=
name|IPPORT_RESERVED
operator|&&
name|resvport_only
condition|)
block|{
name|svcerr_weakauth
argument_list|(
name|transp
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|svc_getargs
argument_list|(
name|transp
argument_list|,
name|xdr_dir
argument_list|,
name|rpcpath
argument_list|)
condition|)
block|{
name|svcerr_decode
argument_list|(
name|transp
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 		 * Get the real pathname and make sure it is a directory 		 * or a regular file if the -r option was specified 		 * and it exists. 		 */
if|if
condition|(
name|realpath
argument_list|(
name|rpcpath
argument_list|,
name|dirpath
argument_list|)
operator|==
literal|0
operator|||
name|stat
argument_list|(
name|dirpath
argument_list|,
operator|&
name|stb
argument_list|)
operator|<
literal|0
operator|||
operator|(
operator|!
name|S_ISDIR
argument_list|(
name|stb
operator|.
name|st_mode
argument_list|)
operator|&&
operator|(
name|dir_only
operator|||
operator|!
name|S_ISREG
argument_list|(
name|stb
operator|.
name|st_mode
argument_list|)
operator|)
operator|)
operator|||
name|statfs
argument_list|(
name|dirpath
argument_list|,
operator|&
name|fsb
argument_list|)
operator|<
literal|0
condition|)
block|{
name|chdir
argument_list|(
literal|"/"
argument_list|)
expr_stmt|;
comment|/* Just in case realpath doesn't */
if|if
condition|(
name|debug
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"stat failed on %s\n"
argument_list|,
name|dirpath
argument_list|)
expr_stmt|;
name|bad
operator|=
name|ENOENT
expr_stmt|;
comment|/* We will send error reply later */
block|}
comment|/* Check in the exports list */
name|sigprocmask
argument_list|(
name|SIG_BLOCK
argument_list|,
operator|&
name|sighup_mask
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|ep
operator|=
name|ex_search
argument_list|(
operator|&
name|fsb
operator|.
name|f_fsid
argument_list|)
expr_stmt|;
name|hostset
operator|=
name|defset
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|ep
operator|&&
operator|(
name|chk_host
argument_list|(
name|ep
operator|->
name|ex_defdir
argument_list|,
name|saddr
argument_list|,
operator|&
name|defset
argument_list|,
operator|&
name|hostset
argument_list|)
operator|||
operator|(
operator|(
name|dp
operator|=
name|dirp_search
argument_list|(
name|ep
operator|->
name|ex_dirl
argument_list|,
name|dirpath
argument_list|)
operator|)
operator|&&
name|chk_host
argument_list|(
name|dp
argument_list|,
name|saddr
argument_list|,
operator|&
name|defset
argument_list|,
operator|&
name|hostset
argument_list|)
operator|)
operator|||
operator|(
name|defset
operator|&&
name|scan_tree
argument_list|(
name|ep
operator|->
name|ex_defdir
argument_list|,
name|saddr
argument_list|)
operator|==
literal|0
operator|&&
name|scan_tree
argument_list|(
name|ep
operator|->
name|ex_dirl
argument_list|,
name|saddr
argument_list|)
operator|==
literal|0
operator|)
operator|)
condition|)
block|{
if|if
condition|(
name|bad
condition|)
block|{
if|if
condition|(
operator|!
name|svc_sendreply
argument_list|(
name|transp
argument_list|,
name|xdr_long
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|bad
argument_list|)
condition|)
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Can't send reply"
argument_list|)
expr_stmt|;
name|sigprocmask
argument_list|(
name|SIG_UNBLOCK
argument_list|,
operator|&
name|sighup_mask
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|hostset
operator|&
name|DP_HOSTSET
condition|)
name|fhr
operator|.
name|fhr_flag
operator|=
name|hostset
expr_stmt|;
else|else
name|fhr
operator|.
name|fhr_flag
operator|=
name|defset
expr_stmt|;
name|fhr
operator|.
name|fhr_vers
operator|=
name|rqstp
operator|->
name|rq_vers
expr_stmt|;
comment|/* Get the file handle */
name|bzero
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|fhr
operator|.
name|fhr_fh
argument_list|,
sizeof|sizeof
argument_list|(
name|nfsfh_t
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|getfh
argument_list|(
name|dirpath
argument_list|,
operator|(
name|fhandle_t
operator|*
operator|)
operator|&
name|fhr
operator|.
name|fhr_fh
argument_list|)
operator|<
literal|0
condition|)
block|{
name|bad
operator|=
name|errno
expr_stmt|;
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Can't get fh for %s"
argument_list|,
name|dirpath
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|svc_sendreply
argument_list|(
name|transp
argument_list|,
name|xdr_long
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|bad
argument_list|)
condition|)
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Can't send reply"
argument_list|)
expr_stmt|;
name|sigprocmask
argument_list|(
name|SIG_UNBLOCK
argument_list|,
operator|&
name|sighup_mask
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|svc_sendreply
argument_list|(
name|transp
argument_list|,
name|xdr_fhs
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|fhr
argument_list|)
condition|)
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Can't send reply"
argument_list|)
expr_stmt|;
if|if
condition|(
name|hp
operator|==
name|NULL
condition|)
name|hp
operator|=
name|gethostbyaddr
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|saddr
argument_list|,
sizeof|sizeof
argument_list|(
name|saddr
argument_list|)
argument_list|,
name|AF_INET
argument_list|)
expr_stmt|;
if|if
condition|(
name|hp
condition|)
name|add_mlist
argument_list|(
name|hp
operator|->
name|h_name
argument_list|,
name|dirpath
argument_list|)
expr_stmt|;
else|else
name|add_mlist
argument_list|(
name|inet_ntoa
argument_list|(
name|transp
operator|->
name|xp_raddr
operator|.
name|sin_addr
argument_list|)
argument_list|,
name|dirpath
argument_list|)
expr_stmt|;
if|if
condition|(
name|debug
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Mount successfull.\n"
argument_list|)
expr_stmt|;
block|}
else|else
name|bad
operator|=
name|EACCES
expr_stmt|;
if|if
condition|(
name|bad
operator|&&
operator|!
name|svc_sendreply
argument_list|(
name|transp
argument_list|,
name|xdr_long
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|bad
argument_list|)
condition|)
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Can't send reply"
argument_list|)
expr_stmt|;
name|sigprocmask
argument_list|(
name|SIG_UNBLOCK
argument_list|,
operator|&
name|sighup_mask
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return;
case|case
name|RPCMNT_DUMP
case|:
if|if
condition|(
operator|!
name|svc_sendreply
argument_list|(
name|transp
argument_list|,
name|xdr_mlist
argument_list|,
operator|(
name|caddr_t
operator|)
name|NULL
argument_list|)
condition|)
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Can't send reply"
argument_list|)
expr_stmt|;
return|return;
case|case
name|RPCMNT_UMOUNT
case|:
if|if
condition|(
name|sport
operator|>=
name|IPPORT_RESERVED
operator|&&
name|resvport_only
condition|)
block|{
name|svcerr_weakauth
argument_list|(
name|transp
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|svc_getargs
argument_list|(
name|transp
argument_list|,
name|xdr_dir
argument_list|,
name|dirpath
argument_list|)
condition|)
block|{
name|svcerr_decode
argument_list|(
name|transp
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|svc_sendreply
argument_list|(
name|transp
argument_list|,
name|xdr_void
argument_list|,
operator|(
name|caddr_t
operator|)
name|NULL
argument_list|)
condition|)
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Can't send reply"
argument_list|)
expr_stmt|;
name|hp
operator|=
name|gethostbyaddr
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|saddr
argument_list|,
sizeof|sizeof
argument_list|(
name|saddr
argument_list|)
argument_list|,
name|AF_INET
argument_list|)
expr_stmt|;
if|if
condition|(
name|hp
condition|)
name|del_mlist
argument_list|(
name|hp
operator|->
name|h_name
argument_list|,
name|dirpath
argument_list|)
expr_stmt|;
name|del_mlist
argument_list|(
name|inet_ntoa
argument_list|(
name|transp
operator|->
name|xp_raddr
operator|.
name|sin_addr
argument_list|)
argument_list|,
name|dirpath
argument_list|)
expr_stmt|;
return|return;
case|case
name|RPCMNT_UMNTALL
case|:
if|if
condition|(
name|sport
operator|>=
name|IPPORT_RESERVED
operator|&&
name|resvport_only
condition|)
block|{
name|svcerr_weakauth
argument_list|(
name|transp
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|svc_sendreply
argument_list|(
name|transp
argument_list|,
name|xdr_void
argument_list|,
operator|(
name|caddr_t
operator|)
name|NULL
argument_list|)
condition|)
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Can't send reply"
argument_list|)
expr_stmt|;
name|hp
operator|=
name|gethostbyaddr
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|saddr
argument_list|,
sizeof|sizeof
argument_list|(
name|saddr
argument_list|)
argument_list|,
name|AF_INET
argument_list|)
expr_stmt|;
if|if
condition|(
name|hp
condition|)
name|del_mlist
argument_list|(
name|hp
operator|->
name|h_name
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
name|del_mlist
argument_list|(
name|inet_ntoa
argument_list|(
name|transp
operator|->
name|xp_raddr
operator|.
name|sin_addr
argument_list|)
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
return|return;
case|case
name|RPCMNT_EXPORT
case|:
if|if
condition|(
operator|!
name|svc_sendreply
argument_list|(
name|transp
argument_list|,
name|xdr_explist
argument_list|,
operator|(
name|caddr_t
operator|)
name|NULL
argument_list|)
condition|)
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Can't send reply"
argument_list|)
expr_stmt|;
return|return;
default|default:
name|svcerr_noproc
argument_list|(
name|transp
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
end_function

begin_comment
comment|/*  * Xdr conversion for a dirpath string  */
end_comment

begin_function
name|int
name|xdr_dir
parameter_list|(
name|xdrsp
parameter_list|,
name|dirp
parameter_list|)
name|XDR
modifier|*
name|xdrsp
decl_stmt|;
name|char
modifier|*
name|dirp
decl_stmt|;
block|{
return|return
operator|(
name|xdr_string
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|dirp
argument_list|,
name|RPCMNT_PATHLEN
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Xdr routine to generate file handle reply  */
end_comment

begin_function
name|int
name|xdr_fhs
parameter_list|(
name|xdrsp
parameter_list|,
name|cp
parameter_list|)
name|XDR
modifier|*
name|xdrsp
decl_stmt|;
name|caddr_t
name|cp
decl_stmt|;
block|{
specifier|register
name|struct
name|fhreturn
modifier|*
name|fhrp
init|=
operator|(
expr|struct
name|fhreturn
operator|*
operator|)
name|cp
decl_stmt|;
name|u_long
name|ok
init|=
literal|0
decl_stmt|,
name|len
decl_stmt|,
name|auth
decl_stmt|;
if|if
condition|(
operator|!
name|xdr_long
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|ok
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
switch|switch
condition|(
name|fhrp
operator|->
name|fhr_vers
condition|)
block|{
case|case
literal|1
case|:
return|return
operator|(
name|xdr_opaque
argument_list|(
name|xdrsp
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|fhrp
operator|->
name|fhr_fh
argument_list|,
name|NFSX_V2FH
argument_list|)
operator|)
return|;
case|case
literal|3
case|:
name|len
operator|=
name|NFSX_V3FH
expr_stmt|;
if|if
condition|(
operator|!
name|xdr_long
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|len
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
operator|!
name|xdr_opaque
argument_list|(
name|xdrsp
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|fhrp
operator|->
name|fhr_fh
argument_list|,
name|len
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|fhrp
operator|->
name|fhr_flag
operator|&
name|DP_KERB
condition|)
name|auth
operator|=
name|RPCAUTH_KERB4
expr_stmt|;
else|else
name|auth
operator|=
name|RPCAUTH_UNIX
expr_stmt|;
name|len
operator|=
literal|1
expr_stmt|;
if|if
condition|(
operator|!
name|xdr_long
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|len
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
name|xdr_long
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|auth
argument_list|)
operator|)
return|;
block|}
empty_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|xdr_mlist
parameter_list|(
name|xdrsp
parameter_list|,
name|cp
parameter_list|)
name|XDR
modifier|*
name|xdrsp
decl_stmt|;
name|caddr_t
name|cp
decl_stmt|;
block|{
name|struct
name|mountlist
modifier|*
name|mlp
decl_stmt|;
name|int
name|true
init|=
literal|1
decl_stmt|;
name|int
name|false
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|strp
decl_stmt|;
name|mlp
operator|=
name|mlhead
expr_stmt|;
while|while
condition|(
name|mlp
condition|)
block|{
if|if
condition|(
operator|!
name|xdr_bool
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|true
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|strp
operator|=
operator|&
name|mlp
operator|->
name|ml_host
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|xdr_string
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|strp
argument_list|,
name|RPCMNT_NAMELEN
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|strp
operator|=
operator|&
name|mlp
operator|->
name|ml_dirp
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|xdr_string
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|strp
argument_list|,
name|RPCMNT_PATHLEN
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|mlp
operator|=
name|mlp
operator|->
name|ml_next
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|xdr_bool
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|false
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Xdr conversion for export list  */
end_comment

begin_function
name|int
name|xdr_explist
parameter_list|(
name|xdrsp
parameter_list|,
name|cp
parameter_list|)
name|XDR
modifier|*
name|xdrsp
decl_stmt|;
name|caddr_t
name|cp
decl_stmt|;
block|{
name|struct
name|exportlist
modifier|*
name|ep
decl_stmt|;
name|int
name|false
init|=
literal|0
decl_stmt|;
name|int
name|putdef
decl_stmt|;
name|sigset_t
name|sighup_mask
decl_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|sighup_mask
argument_list|)
expr_stmt|;
name|sigaddset
argument_list|(
operator|&
name|sighup_mask
argument_list|,
name|SIGHUP
argument_list|)
expr_stmt|;
name|sigprocmask
argument_list|(
name|SIG_BLOCK
argument_list|,
operator|&
name|sighup_mask
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|ep
operator|=
name|exphead
expr_stmt|;
while|while
condition|(
name|ep
condition|)
block|{
name|putdef
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|put_exlist
argument_list|(
name|ep
operator|->
name|ex_dirl
argument_list|,
name|xdrsp
argument_list|,
name|ep
operator|->
name|ex_defdir
argument_list|,
operator|&
name|putdef
argument_list|)
condition|)
goto|goto
name|errout
goto|;
if|if
condition|(
name|ep
operator|->
name|ex_defdir
operator|&&
name|putdef
operator|==
literal|0
operator|&&
name|put_exlist
argument_list|(
name|ep
operator|->
name|ex_defdir
argument_list|,
name|xdrsp
argument_list|,
operator|(
expr|struct
name|dirlist
operator|*
operator|)
name|NULL
argument_list|,
operator|&
name|putdef
argument_list|)
condition|)
goto|goto
name|errout
goto|;
name|ep
operator|=
name|ep
operator|->
name|ex_next
expr_stmt|;
block|}
name|sigprocmask
argument_list|(
name|SIG_UNBLOCK
argument_list|,
operator|&
name|sighup_mask
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|xdr_bool
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|false
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
literal|1
operator|)
return|;
name|errout
label|:
name|sigprocmask
argument_list|(
name|SIG_UNBLOCK
argument_list|,
operator|&
name|sighup_mask
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Called from xdr_explist() to traverse the tree and export the  * directory paths.  */
end_comment

begin_function
name|int
name|put_exlist
parameter_list|(
name|dp
parameter_list|,
name|xdrsp
parameter_list|,
name|adp
parameter_list|,
name|putdefp
parameter_list|)
name|struct
name|dirlist
modifier|*
name|dp
decl_stmt|;
name|XDR
modifier|*
name|xdrsp
decl_stmt|;
name|struct
name|dirlist
modifier|*
name|adp
decl_stmt|;
name|int
modifier|*
name|putdefp
decl_stmt|;
block|{
name|struct
name|grouplist
modifier|*
name|grp
decl_stmt|;
name|struct
name|hostlist
modifier|*
name|hp
decl_stmt|;
name|int
name|true
init|=
literal|1
decl_stmt|;
name|int
name|false
init|=
literal|0
decl_stmt|;
name|int
name|gotalldir
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|strp
decl_stmt|;
if|if
condition|(
name|dp
condition|)
block|{
if|if
condition|(
name|put_exlist
argument_list|(
name|dp
operator|->
name|dp_left
argument_list|,
name|xdrsp
argument_list|,
name|adp
argument_list|,
name|putdefp
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
operator|!
name|xdr_bool
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|true
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|strp
operator|=
name|dp
operator|->
name|dp_dirp
expr_stmt|;
if|if
condition|(
operator|!
name|xdr_string
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|strp
argument_list|,
name|RPCMNT_PATHLEN
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|adp
operator|&&
operator|!
name|strcmp
argument_list|(
name|dp
operator|->
name|dp_dirp
argument_list|,
name|adp
operator|->
name|dp_dirp
argument_list|)
condition|)
block|{
name|gotalldir
operator|=
literal|1
expr_stmt|;
operator|*
name|putdefp
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|dp
operator|->
name|dp_flag
operator|&
name|DP_DEFSET
operator|)
operator|==
literal|0
operator|&&
operator|(
name|gotalldir
operator|==
literal|0
operator|||
operator|(
name|adp
operator|->
name|dp_flag
operator|&
name|DP_DEFSET
operator|)
operator|==
literal|0
operator|)
condition|)
block|{
name|hp
operator|=
name|dp
operator|->
name|dp_hosts
expr_stmt|;
while|while
condition|(
name|hp
condition|)
block|{
name|grp
operator|=
name|hp
operator|->
name|ht_grp
expr_stmt|;
if|if
condition|(
name|grp
operator|->
name|gr_type
operator|==
name|GT_HOST
condition|)
block|{
if|if
condition|(
operator|!
name|xdr_bool
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|true
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|strp
operator|=
name|grp
operator|->
name|gr_ptr
operator|.
name|gt_hostent
operator|->
name|h_name
expr_stmt|;
if|if
condition|(
operator|!
name|xdr_string
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|strp
argument_list|,
name|RPCMNT_NAMELEN
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|grp
operator|->
name|gr_type
operator|==
name|GT_NET
condition|)
block|{
if|if
condition|(
operator|!
name|xdr_bool
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|true
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|strp
operator|=
name|grp
operator|->
name|gr_ptr
operator|.
name|gt_net
operator|.
name|nt_name
expr_stmt|;
if|if
condition|(
operator|!
name|xdr_string
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|strp
argument_list|,
name|RPCMNT_NAMELEN
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|hp
operator|=
name|hp
operator|->
name|ht_next
expr_stmt|;
if|if
condition|(
name|gotalldir
operator|&&
name|hp
operator|==
operator|(
expr|struct
name|hostlist
operator|*
operator|)
name|NULL
condition|)
block|{
name|hp
operator|=
name|adp
operator|->
name|dp_hosts
expr_stmt|;
name|gotalldir
operator|=
literal|0
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
operator|!
name|xdr_bool
argument_list|(
name|xdrsp
argument_list|,
operator|&
name|false
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|put_exlist
argument_list|(
name|dp
operator|->
name|dp_right
argument_list|,
name|xdrsp
argument_list|,
name|adp
argument_list|,
name|putdefp
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|LINESIZ
value|10240
end_define

begin_decl_stmt
name|char
name|line
index|[
name|LINESIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|exp_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Get the export list  */
end_comment

begin_function
name|void
name|get_exportlist
parameter_list|()
block|{
name|struct
name|exportlist
modifier|*
name|ep
decl_stmt|,
modifier|*
name|ep2
decl_stmt|;
name|struct
name|grouplist
modifier|*
name|grp
decl_stmt|,
modifier|*
name|tgrp
decl_stmt|;
name|struct
name|exportlist
modifier|*
modifier|*
name|epp
decl_stmt|;
name|struct
name|dirlist
modifier|*
name|dirhead
decl_stmt|;
name|struct
name|statfs
name|fsb
decl_stmt|,
modifier|*
name|fsp
decl_stmt|;
name|struct
name|hostent
modifier|*
name|hpe
decl_stmt|;
name|struct
name|ucred
name|anon
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|endcp
decl_stmt|,
modifier|*
name|dirp
decl_stmt|,
modifier|*
name|hst
decl_stmt|,
modifier|*
name|usr
decl_stmt|,
modifier|*
name|dom
decl_stmt|,
name|savedc
decl_stmt|;
name|int
name|len
decl_stmt|,
name|has_host
decl_stmt|,
name|exflags
decl_stmt|,
name|got_nondir
decl_stmt|,
name|dirplen
decl_stmt|,
name|num
decl_stmt|,
name|i
decl_stmt|,
name|netgrp
decl_stmt|;
comment|/* 	 * First, get rid of the old list 	 */
name|ep
operator|=
name|exphead
expr_stmt|;
while|while
condition|(
name|ep
condition|)
block|{
name|ep2
operator|=
name|ep
expr_stmt|;
name|ep
operator|=
name|ep
operator|->
name|ex_next
expr_stmt|;
name|free_exp
argument_list|(
name|ep2
argument_list|)
expr_stmt|;
block|}
name|exphead
operator|=
operator|(
expr|struct
name|exportlist
operator|*
operator|)
name|NULL
expr_stmt|;
name|grp
operator|=
name|grphead
expr_stmt|;
while|while
condition|(
name|grp
condition|)
block|{
name|tgrp
operator|=
name|grp
expr_stmt|;
name|grp
operator|=
name|grp
operator|->
name|gr_next
expr_stmt|;
name|free_grp
argument_list|(
name|tgrp
argument_list|)
expr_stmt|;
block|}
name|grphead
operator|=
operator|(
expr|struct
name|grouplist
operator|*
operator|)
name|NULL
expr_stmt|;
comment|/* 	 * And delete exports that are in the kernel for all local 	 * file systems. 	 * XXX: Should know how to handle all local exportable file systems 	 *      instead of just MOUNT_UFS. 	 */
name|num
operator|=
name|getmntinfo
argument_list|(
operator|&
name|fsp
argument_list|,
name|MNT_NOWAIT
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|num
condition|;
name|i
operator|++
control|)
block|{
union|union
block|{
name|struct
name|ufs_args
name|ua
decl_stmt|;
name|struct
name|iso_args
name|ia
decl_stmt|;
name|struct
name|mfs_args
name|ma
decl_stmt|;
ifdef|#
directive|ifdef
name|__NetBSD__
name|struct
name|msdosfs_args
name|da
decl_stmt|;
block|}
name|targs
union|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|fsp
operator|->
name|f_fstypename
argument_list|,
name|MOUNT_MFS
argument_list|)
operator|||
operator|!
name|strcmp
argument_list|(
name|fsp
operator|->
name|f_fstypename
argument_list|,
name|MOUNT_UFS
argument_list|)
operator|||
operator|!
name|strcmp
argument_list|(
name|fsp
operator|->
name|f_fstypename
argument_list|,
name|MOUNT_MSDOS
argument_list|)
operator|||
operator|!
name|strcmp
argument_list|(
name|fsp
operator|->
name|f_fstypename
argument_list|,
name|MOUNT_CD9660
argument_list|)
condition|)
block|{
name|targs
operator|.
name|ua
operator|.
name|fspec
operator|=
name|NULL
expr_stmt|;
name|targs
operator|.
name|ua
operator|.
name|export
operator|.
name|ex_flags
operator|=
name|MNT_DELEXPORT
expr_stmt|;
if|if
condition|(
name|mount
argument_list|(
argument|fsp->f_fstypename
argument_list|,
argument|fsp->f_mntonname
argument_list|,
else|#
directive|else
argument|} targs;  		switch (fsp->f_type) { 		case MOUNT_MFS: 		case MOUNT_UFS: 		case MOUNT_CD9660: 		case MOUNT_MSDOS: 			targs.ua.fspec = NULL; 			targs.ua.export.ex_flags = MNT_DELEXPORT; 			if (mount(fsp->f_type, fsp->f_mntonname,
endif|#
directive|endif
argument|fsp->f_flags | MNT_UPDATE, 				  (caddr_t)&targs)<
literal|0
argument|) 				syslog(LOG_ERR,
literal|"Can't delete exports for %s"
argument|, 				       fsp->f_mntonname); 		} 		fsp++; 	}
comment|/* 	 * Read in the exports file and build the list, calling 	 * mount() as we go along to push the export rules into the kernel. 	 */
argument|if ((exp_file = fopen(exname,
literal|"r"
argument|)) == NULL) { 		syslog(LOG_ERR,
literal|"Can't open %s"
argument|, exname); 		exit(
literal|2
argument|); 	} 	dirhead = (struct dirlist *)NULL; 	while (get_line()) { 		if (debug) 			fprintf(stderr,
literal|"Got line %s\n"
argument|,line); 		cp = line; 		nextfield(&cp,&endcp); 		if (*cp ==
literal|'#'
argument|) 			goto nextline;
comment|/* 		 * Set defaults. 		 */
argument|has_host = FALSE; 		anon = def_anon; 		exflags = MNT_EXPORTED; 		got_nondir =
literal|0
argument|; 		opt_flags =
literal|0
argument|; 		ep = (struct exportlist *)NULL;
comment|/* 		 * Create new exports list entry 		 */
argument|len = endcp-cp; 		tgrp = grp = get_grp(); 		while (len>
literal|0
argument|) { 			if (len> RPCMNT_NAMELEN) { 			    getexp_err(ep, tgrp); 			    goto nextline; 			} 			if (*cp ==
literal|'-'
argument|) { 			    if (ep == (struct exportlist *)NULL) { 				getexp_err(ep, tgrp); 				goto nextline; 			    } 			    if (debug) 				fprintf(stderr,
literal|"doing opt %s\n"
argument|, cp); 			    got_nondir =
literal|1
argument|; 			    if (do_opt(&cp,&endcp, ep, grp,&has_host,&exflags,&anon)) { 				getexp_err(ep, tgrp); 				goto nextline; 			    } 			} else if (*cp ==
literal|'/'
argument|) { 			    savedc = *endcp; 			    *endcp =
literal|'\0'
argument|; 			    if (check_dirpath(cp)&& 				statfs(cp,&fsb)>=
literal|0
argument|) { 				if (got_nondir) { 				    syslog(LOG_ERR,
literal|"Dirs must be first"
argument|); 				    getexp_err(ep, tgrp); 				    goto nextline; 				} 				if (ep) { 				    if (ep->ex_fs.val[
literal|0
argument|] != fsb.f_fsid.val[
literal|0
argument|] || 					ep->ex_fs.val[
literal|1
argument|] != fsb.f_fsid.val[
literal|1
argument|]) { 					getexp_err(ep, tgrp); 					goto nextline; 				    } 				} else {
comment|/* 				     * See if this directory is already 				     * in the list. 				     */
argument|ep = ex_search(&fsb.f_fsid); 				    if (ep == (struct exportlist *)NULL) { 					ep = get_exp(); 					ep->ex_fs = fsb.f_fsid; 					ep->ex_fsdir = (char *) 					    malloc(strlen(fsb.f_mntonname) +
literal|1
argument|); 					if (ep->ex_fsdir) 					    strcpy(ep->ex_fsdir, 						fsb.f_mntonname); 					else 					    out_of_mem(); 					if (debug) 					  fprintf(stderr,
literal|"Making new ep fs=0x%x,0x%x\n"
argument|, 					      fsb.f_fsid.val[
literal|0
argument|], 					      fsb.f_fsid.val[
literal|1
argument|]); 				    } else if (debug) 					fprintf(stderr,
literal|"Found ep fs=0x%x,0x%x\n"
argument|, 					    fsb.f_fsid.val[
literal|0
argument|], 					    fsb.f_fsid.val[
literal|1
argument|]); 				}
comment|/* 				 * Add dirpath to export mount point. 				 */
argument|dirp = add_expdir(&dirhead, cp, len); 				dirplen = len; 			    } else { 				getexp_err(ep, tgrp); 				goto nextline; 			    } 			    *endcp = savedc; 			} else { 			    savedc = *endcp; 			    *endcp =
literal|'\0'
argument|; 			    got_nondir =
literal|1
argument|; 			    if (ep == (struct exportlist *)NULL) { 				getexp_err(ep, tgrp); 				goto nextline; 			    }
comment|/* 			     * Get the host or netgroup. 			     */
argument|setnetgrent(cp); 			    netgrp = getnetgrent(&hst,&usr,&dom); 			    do { 				if (has_host) { 				    grp->gr_next = get_grp(); 				    grp = grp->gr_next; 				} 				if (netgrp) { 				    if (get_host(hst, grp, tgrp)) { 					syslog(LOG_ERR,
literal|"Bad host %s in netgroup %s, skipping"
argument|, hst, cp); 					grp->gr_type = GT_IGNORE; 				    } 				} else if (get_host(cp, grp, tgrp)) { 				    syslog(LOG_ERR,
literal|"Bad host %s, skipping"
argument|, cp); 				    grp->gr_type = GT_IGNORE; 				} 				has_host = TRUE; 			    } while (netgrp&& getnetgrent(&hst,&usr,&dom)); 			    endnetgrent(); 			    *endcp = savedc; 			} 			cp = endcp; 			nextfield(&cp,&endcp); 			len = endcp - cp; 		} 		if (check_options(dirhead)) { 			getexp_err(ep, tgrp); 			goto nextline; 		} 		if (!has_host) { 			grp->gr_type = GT_HOST; 			if (debug) 				fprintf(stderr,
literal|"Adding a default entry\n"
argument|);
comment|/* add a default group and make the grp list NULL */
argument|hpe = (struct hostent *)malloc(sizeof(struct hostent)); 			if (hpe == (struct hostent *)NULL) 				out_of_mem(); 			hpe->h_name = strdup(
literal|"Default"
argument|); 			hpe->h_addrtype = AF_INET; 			hpe->h_length = sizeof (u_long); 			hpe->h_addr_list = (char **)NULL; 			grp->gr_ptr.gt_hostent = hpe;
comment|/* 		 * Don't allow a network export coincide with a list of 		 * host(s) on the same line. 		 */
argument|} else if ((opt_flags& OP_NET)&& tgrp->gr_next) { 			getexp_err(ep, tgrp); 			goto nextline;
comment|/* 	         * If an export list was specified on this line, make sure 		 * that we have at least one valid entry, otherwise skip it. 		 */
argument|} else { 			grp = tgrp;         		while (grp&& grp->gr_type == GT_IGNORE) 				grp = grp->gr_next; 			if (! grp) { 			    getexp_err(ep, tgrp); 			    goto nextline; 			} 		}
comment|/* 		 * Loop through hosts, pushing the exports into the kernel. 		 * After loop, tgrp points to the start of the list and 		 * grp points to the last entry in the list. 		 */
argument|grp = tgrp; 		do { 		    if (do_mount(ep, grp, exflags,&anon, dirp, 			dirplen,&fsb)) { 			getexp_err(ep, tgrp); 			goto nextline; 		    } 		} while (grp->gr_next&& (grp = grp->gr_next));
comment|/* 		 * Success. Update the data structures. 		 */
argument|if (has_host) { 			hang_dirp(dirhead, tgrp, ep, opt_flags); 			grp->gr_next = grphead; 			grphead = tgrp; 		} else { 			hang_dirp(dirhead, (struct grouplist *)NULL, ep, 				opt_flags); 			free_grp(grp); 		} 		dirhead = (struct dirlist *)NULL; 		if ((ep->ex_flag& EX_LINKED) ==
literal|0
argument|) { 			ep2 = exphead; 			epp =&exphead;
comment|/* 			 * Insert in the list in alphabetical order. 			 */
argument|while (ep2&& strcmp(ep2->ex_fsdir, ep->ex_fsdir)<
literal|0
argument|) { 				epp =&ep2->ex_next; 				ep2 = ep2->ex_next; 			} 			if (ep2) 				ep->ex_next = ep2; 			*epp = ep; 			ep->ex_flag |= EX_LINKED; 		} nextline: 		if (dirhead) { 			free_dir(dirhead); 			dirhead = (struct dirlist *)NULL; 		} 	} 	fclose(exp_file); }
comment|/*  * Allocate an export list element  */
argument|struct exportlist * get_exp() { 	struct exportlist *ep;  	ep = (struct exportlist *)malloc(sizeof (struct exportlist)); 	if (ep == (struct exportlist *)NULL) 		out_of_mem(); 	bzero((caddr_t)ep, sizeof (struct exportlist)); 	return (ep); }
comment|/*  * Allocate a group list element  */
argument|struct grouplist * get_grp() { 	struct grouplist *gp;  	gp = (struct grouplist *)malloc(sizeof (struct grouplist)); 	if (gp == (struct grouplist *)NULL) 		out_of_mem(); 	bzero((caddr_t)gp, sizeof (struct grouplist)); 	return (gp); }
comment|/*  * Clean up upon an error in get_exportlist().  */
argument|void getexp_err(ep, grp) 	struct exportlist *ep; 	struct grouplist *grp; { 	struct grouplist *tgrp;  	syslog(LOG_ERR,
literal|"Bad exports list line %s"
argument|, line); 	if (ep&& (ep->ex_flag& EX_LINKED) ==
literal|0
argument|) 		free_exp(ep); 	while (grp) { 		tgrp = grp; 		grp = grp->gr_next; 		free_grp(tgrp); 	} }
comment|/*  * Search the export list for a matching fs.  */
argument|struct exportlist * ex_search(fsid) 	fsid_t *fsid; { 	struct exportlist *ep;  	ep = exphead; 	while (ep) { 		if (ep->ex_fs.val[
literal|0
argument|] == fsid->val[
literal|0
argument|]&& 		    ep->ex_fs.val[
literal|1
argument|] == fsid->val[
literal|1
argument|]) 			return (ep); 		ep = ep->ex_next; 	} 	return (ep); }
comment|/*  * Add a directory path to the list.  */
argument|char * add_expdir(dpp, cp, len) 	struct dirlist **dpp; 	char *cp; 	int len; { 	struct dirlist *dp;  	dp = (struct dirlist *)malloc(sizeof (struct dirlist) + len); 	dp->dp_left = *dpp; 	dp->dp_right = (struct dirlist *)NULL; 	dp->dp_flag =
literal|0
argument|; 	dp->dp_hosts = (struct hostlist *)NULL; 	strcpy(dp->dp_dirp, cp); 	*dpp = dp; 	return (dp->dp_dirp); }
comment|/*  * Hang the dir list element off the dirpath binary tree as required  * and update the entry for host.  */
argument|void hang_dirp(dp, grp, ep, flags) 	struct dirlist *dp; 	struct grouplist *grp; 	struct exportlist *ep; 	int flags; { 	struct hostlist *hp; 	struct dirlist *dp2;  	if (flags& OP_ALLDIRS) { 		if (ep->ex_defdir) 			free((caddr_t)dp); 		else 			ep->ex_defdir = dp; 		if (grp == (struct grouplist *)NULL) { 			ep->ex_defdir->dp_flag |= DP_DEFSET; 			if (flags& OP_KERB) 				ep->ex_defdir->dp_flag |= DP_KERB; 		} else while (grp) { 			hp = get_ht(); 			if (flags& OP_KERB) 				hp->ht_flag |= DP_KERB; 			hp->ht_grp = grp; 			hp->ht_next = ep->ex_defdir->dp_hosts; 			ep->ex_defdir->dp_hosts = hp; 			grp = grp->gr_next; 		} 	} else {
comment|/* 		 * Loop throught the directories adding them to the tree. 		 */
argument|while (dp) { 			dp2 = dp->dp_left; 			add_dlist(&ep->ex_dirl, dp, grp, flags); 			dp = dp2; 		} 	} }
comment|/*  * Traverse the binary tree either updating a node that is already there  * for the new directory or adding the new node.  */
argument|void add_dlist(dpp, newdp, grp, flags) 	struct dirlist **dpp; 	struct dirlist *newdp; 	struct grouplist *grp; 	int flags; { 	struct dirlist *dp; 	struct hostlist *hp; 	int cmp;  	dp = *dpp; 	if (dp) { 		cmp = strcmp(dp->dp_dirp, newdp->dp_dirp); 		if (cmp>
literal|0
argument|) { 			add_dlist(&dp->dp_left, newdp, grp, flags); 			return; 		} else if (cmp<
literal|0
argument|) { 			add_dlist(&dp->dp_right, newdp, grp, flags); 			return; 		} else 			free((caddr_t)newdp); 	} else { 		dp = newdp; 		dp->dp_left = (struct dirlist *)NULL; 		*dpp = dp; 	} 	if (grp) {
comment|/* 		 * Hang all of the host(s) off of the directory point. 		 */
argument|do { 			hp = get_ht(); 			if (flags& OP_KERB) 				hp->ht_flag |= DP_KERB; 			hp->ht_grp = grp; 			hp->ht_next = dp->dp_hosts; 			dp->dp_hosts = hp; 			grp = grp->gr_next; 		} while (grp); 	} else { 		dp->dp_flag |= DP_DEFSET; 		if (flags& OP_KERB) 			dp->dp_flag |= DP_KERB; 	} }
comment|/*  * Search for a dirpath on the export point.  */
argument|struct dirlist * dirp_search(dp, dirpath) 	struct dirlist *dp; 	char *dirpath; { 	int cmp;  	if (dp) { 		cmp = strcmp(dp->dp_dirp, dirpath); 		if (cmp>
literal|0
argument|) 			return (dirp_search(dp->dp_left, dirpath)); 		else if (cmp<
literal|0
argument|) 			return (dirp_search(dp->dp_right, dirpath)); 		else 			return (dp); 	} 	return (dp); }
comment|/*  * Scan for a host match in a directory tree.  */
argument|int chk_host(dp, saddr, defsetp, hostsetp) 	struct dirlist *dp; 	u_long saddr; 	int *defsetp; 	int *hostsetp; { 	struct hostlist *hp; 	struct grouplist *grp; 	u_long **addrp;  	if (dp) { 		if (dp->dp_flag& DP_DEFSET) 			*defsetp = dp->dp_flag; 		hp = dp->dp_hosts; 		while (hp) { 			grp = hp->ht_grp; 			switch (grp->gr_type) { 			case GT_HOST: 			    addrp = (u_long **) 				grp->gr_ptr.gt_hostent->h_addr_list; 			    while (*addrp) { 				if (**addrp == saddr) { 				    *hostsetp = (hp->ht_flag | DP_HOSTSET); 				    return (
literal|1
argument|); 				} 				addrp++; 			    } 			    break; 			case GT_NET: 			    if ((saddr& grp->gr_ptr.gt_net.nt_mask) == 				grp->gr_ptr.gt_net.nt_net) { 				*hostsetp = (hp->ht_flag | DP_HOSTSET); 				return (
literal|1
argument|); 			    } 			    break; 			}; 			hp = hp->ht_next; 		} 	} 	return (
literal|0
argument|); }
comment|/*  * Scan tree for a host that matches the address.  */
argument|int scan_tree(dp, saddr) 	struct dirlist *dp; 	u_long saddr; { 	int defset
argument_list|,
argument|hostset;  	if (dp) { 		if (scan_tree(dp->dp_left, saddr)) 			return (
literal|1
argument|); 		if (chk_host(dp, saddr,&defset,&hostset)) 			return (
literal|1
argument|); 		if (scan_tree(dp->dp_right, saddr)) 			return (
literal|1
argument|); 	} 	return (
literal|0
argument|); }
comment|/*  * Traverse the dirlist tree and free it up.  */
argument|void free_dir(dp) 	struct dirlist *dp; {  	if (dp) { 		free_dir(dp->dp_left); 		free_dir(dp->dp_right); 		free_host(dp->dp_hosts); 		free((caddr_t)dp); 	} }
comment|/*  * Parse the option string and update fields.  * Option arguments may either be -<option>=<value> or  * -<option><value>  */
argument|int do_opt(cpp, endcpp, ep, grp, has_hostp, exflagsp, cr) 	char **cpp
argument_list|,
argument|**endcpp; 	struct exportlist *ep; 	struct grouplist *grp; 	int *has_hostp; 	int *exflagsp; 	struct ucred *cr; { 	char *cpoptarg
argument_list|,
argument|*cpoptend; 	char *cp
argument_list|,
argument|*endcp
argument_list|,
argument|*cpopt
argument_list|,
argument|savedc
argument_list|,
argument|savedc2; 	int allflag
argument_list|,
argument|usedarg;  	cpopt = *cpp; 	cpopt++; 	cp = *endcpp; 	savedc = *cp; 	*cp =
literal|'\0'
argument|; 	while (cpopt&& *cpopt) { 		allflag =
literal|1
argument|; 		usedarg = -
literal|2
argument|; 		if (cpoptend = index(cpopt,
literal|','
argument|)) { 			*cpoptend++ =
literal|'\0'
argument|; 			if (cpoptarg = index(cpopt,
literal|'='
argument|)) 				*cpoptarg++ =
literal|'\0'
argument|; 		} else { 			if (cpoptarg = index(cpopt,
literal|'='
argument|)) 				*cpoptarg++ =
literal|'\0'
argument|; 			else { 				*cp = savedc; 				nextfield(&cp,&endcp); 				**endcpp =
literal|'\0'
argument|; 				if (endcp> cp&& *cp !=
literal|'-'
argument|) { 					cpoptarg = cp; 					savedc2 = *endcp; 					*endcp =
literal|'\0'
argument|; 					usedarg =
literal|0
argument|; 				} 			} 		} 		if (!strcmp(cpopt,
literal|"ro"
argument|) || !strcmp(cpopt,
literal|"o"
argument|)) { 			*exflagsp |= MNT_EXRDONLY; 		} else if (cpoptarg&& (!strcmp(cpopt,
literal|"maproot"
argument|) || 		    !(allflag = strcmp(cpopt,
literal|"mapall"
argument|)) || 		    !strcmp(cpopt,
literal|"root"
argument|) || !strcmp(cpopt,
literal|"r"
argument|))) { 			usedarg++; 			parsecred(cpoptarg, cr); 			if (allflag ==
literal|0
argument|) { 				*exflagsp |= MNT_EXPORTANON; 				opt_flags |= OP_MAPALL; 			} else 				opt_flags |= OP_MAPROOT; 		} else if (!strcmp(cpopt,
literal|"kerb"
argument|) || !strcmp(cpopt,
literal|"k"
argument|)) { 			*exflagsp |= MNT_EXKERB; 			opt_flags |= OP_KERB; 		} else if (cpoptarg&& (!strcmp(cpopt,
literal|"mask"
argument|) || 			!strcmp(cpopt,
literal|"m"
argument|))) { 			if (get_net(cpoptarg,&grp->gr_ptr.gt_net,
literal|1
argument|)) { 				syslog(LOG_ERR,
literal|"Bad mask: %s"
argument|, cpoptarg); 				return (
literal|1
argument|); 			} 			usedarg++; 			opt_flags |= OP_MASK; 		} else if (cpoptarg&& (!strcmp(cpopt,
literal|"network"
argument|) || 			!strcmp(cpopt,
literal|"n"
argument|))) { 			if (grp->gr_type != GT_NULL) { 				syslog(LOG_ERR,
literal|"Network/host conflict"
argument|); 				return (
literal|1
argument|); 			} else if (get_net(cpoptarg,&grp->gr_ptr.gt_net,
literal|0
argument|)) { 				syslog(LOG_ERR,
literal|"Bad net: %s"
argument|, cpoptarg); 				return (
literal|1
argument|); 			} 			grp->gr_type = GT_NET; 			*has_hostp =
literal|1
argument|; 			usedarg++; 			opt_flags |= OP_NET; 		} else if (!strcmp(cpopt,
literal|"alldirs"
argument|)) { 			opt_flags |= OP_ALLDIRS;
ifdef|#
directive|ifdef
name|ISO
argument|} else if (cpoptarg&& !strcmp(cpopt,
literal|"iso"
argument|)) { 			if (get_isoaddr(cpoptarg, grp)) { 				syslog(LOG_ERR,
literal|"Bad iso addr: %s"
argument|, cpoptarg); 				return (
literal|1
argument|); 			} 			*has_hostp =
literal|1
argument|; 			usedarg++; 			opt_flags |= OP_ISO;
endif|#
directive|endif
comment|/* ISO */
argument|} else { 			syslog(LOG_ERR,
literal|"Bad opt %s"
argument|, cpopt); 			return (
literal|1
argument|); 		} 		if (usedarg>=
literal|0
argument|) { 			*endcp = savedc2; 			**endcpp = savedc; 			if (usedarg>
literal|0
argument|) { 				*cpp = cp; 				*endcpp = endcp; 			} 			return (
literal|0
argument|); 		} 		cpopt = cpoptend; 	} 	**endcpp = savedc; 	return (
literal|0
argument|); }
comment|/*  * Translate a character string to the corresponding list of network  * addresses for a hostname.  */
argument|int get_host(cp, grp, tgrp) 	char *cp; 	struct grouplist *grp; 	struct grouplist *tgrp; { 	struct grouplist *checkgrp; 	struct hostent *hp
argument_list|,
argument|*nhp; 	char **addrp
argument_list|,
argument|**naddrp; 	struct hostent t_host; 	int i; 	u_long saddr; 	char *aptr[
literal|2
argument|];  	if (grp->gr_type != GT_NULL) 		return (
literal|1
argument|); 	if ((hp = gethostbyname(cp)) == NULL) { 		if (isdigit(*cp)) { 			saddr = inet_addr(cp); 			if (saddr == -
literal|1
argument|) {  				syslog(LOG_ERR,
literal|"Inet_addr failed for %s"
argument|, cp); 				return (
literal|1
argument|); 			} 			if ((hp = gethostbyaddr((caddr_t)&saddr, sizeof (saddr), 				AF_INET)) == NULL) { 				hp =&t_host; 				hp->h_name = cp; 				hp->h_addrtype = AF_INET; 				hp->h_length = sizeof (u_long); 				hp->h_addr_list = aptr; 				aptr[
literal|0
argument|] = (char *)&saddr; 				aptr[
literal|1
argument|] = (char *)NULL; 			} 		} else {  			syslog(LOG_ERR,
literal|"Gethostbyname failed for %s"
argument|, cp); 			return (
literal|1
argument|); 		} 	}
comment|/*          * Sanity check: make sure we don't already have an entry          * for this host in the grouplist.          */
argument|checkgrp = tgrp;         while (checkgrp) { 		if (checkgrp->gr_type == GT_HOST&&                     checkgrp->gr_ptr.gt_hostent != NULL&&                     !strcmp(checkgrp->gr_ptr.gt_hostent->h_name, hp->h_name)) {                         grp->gr_type = GT_IGNORE; 			return(
literal|0
argument|); 		}                 checkgrp = checkgrp->gr_next;         }  	grp->gr_type = GT_HOST; 	nhp = grp->gr_ptr.gt_hostent = (struct hostent *) 		malloc(sizeof(struct hostent)); 	if (nhp == (struct hostent *)NULL) 		out_of_mem(); 	bcopy((caddr_t)hp, (caddr_t)nhp, 		sizeof(struct hostent)); 	i = strlen(hp->h_name)+
literal|1
argument|; 	nhp->h_name = (char *)malloc(i); 	if (nhp->h_name == (char *)NULL) 		out_of_mem(); 	bcopy(hp->h_name, nhp->h_name, i); 	addrp = hp->h_addr_list; 	i =
literal|1
argument|; 	while (*addrp++) 		i++; 	naddrp = nhp->h_addr_list = (char **) 		malloc(i*sizeof(char *)); 	if (naddrp == (char **)NULL) 		out_of_mem(); 	addrp = hp->h_addr_list; 	while (*addrp) { 		*naddrp = (char *) 		    malloc(hp->h_length); 		if (*naddrp == (char *)NULL) 		    out_of_mem(); 		bcopy(*addrp, *naddrp, 			hp->h_length); 		addrp++; 		naddrp++; 	} 	*naddrp = (char *)NULL; 	if (debug) 		fprintf(stderr,
literal|"got host %s\n"
argument|, hp->h_name); 	return (
literal|0
argument|); }
comment|/*  * Free up an exports list component  */
argument|void free_exp(ep) 	struct exportlist *ep; {  	if (ep->ex_defdir) { 		free_host(ep->ex_defdir->dp_hosts); 		free((caddr_t)ep->ex_defdir); 	} 	if (ep->ex_fsdir) 		free(ep->ex_fsdir); 	free_dir(ep->ex_dirl); 	free((caddr_t)ep); }
comment|/*  * Free hosts.  */
argument|void free_host(hp) 	struct hostlist *hp; { 	struct hostlist *hp2;  	while (hp) { 		hp2 = hp; 		hp = hp->ht_next; 		free((caddr_t)hp2); 	} }  struct hostlist * get_ht() { 	struct hostlist *hp;  	hp = (struct hostlist *)malloc(sizeof (struct hostlist)); 	if (hp == (struct hostlist *)NULL) 		out_of_mem(); 	hp->ht_next = (struct hostlist *)NULL; 	hp->ht_flag =
literal|0
argument|; 	return (hp); }
ifdef|#
directive|ifdef
name|ISO
comment|/*  * Translate an iso address.  */
argument|get_isoaddr(cp, grp) 	char *cp; 	struct grouplist *grp; { 	struct iso_addr *isop; 	struct sockaddr_iso *isoaddr;  	if (grp->gr_type != GT_NULL) 		return (
literal|1
argument|); 	if ((isop = iso_addr(cp)) == NULL) { 		syslog(LOG_ERR,
literal|"iso_addr failed, ignored"
argument|); 		return (
literal|1
argument|); 	} 	isoaddr = (struct sockaddr_iso *) 	    malloc(sizeof (struct sockaddr_iso)); 	if (isoaddr == (struct sockaddr_iso *)NULL) 		out_of_mem(); 	bzero((caddr_t)isoaddr, sizeof (struct sockaddr_iso)); 	bcopy((caddr_t)isop, (caddr_t)&isoaddr->siso_addr, 		sizeof (struct iso_addr)); 	isoaddr->siso_len = sizeof (struct sockaddr_iso); 	isoaddr->siso_family = AF_ISO; 	grp->gr_type = GT_ISO; 	grp->gr_ptr.gt_isoaddr = isoaddr; 	return (
literal|0
argument|); }
endif|#
directive|endif
comment|/* ISO */
comment|/*  * Out of memory, fatal  */
argument|void out_of_mem() {  	syslog(LOG_ERR,
literal|"Out of memory"
argument|); 	exit(
literal|2
argument|); }
comment|/*  * Do the mount syscall with the update flag to push the export info into  * the kernel.  */
argument|int do_mount(ep, grp, exflags, anoncrp, dirp, dirplen, fsb) 	struct exportlist *ep; 	struct grouplist *grp; 	int exflags; 	struct ucred *anoncrp; 	char *dirp; 	int dirplen; 	struct statfs *fsb; { 	char *cp = (char *)NULL; 	u_long **addrp; 	int done; 	char savedc =
literal|'\0'
argument|; 	struct sockaddr_in sin
argument_list|,
argument|imask; 	union { 		struct ufs_args ua; 		struct iso_args ia; 		struct mfs_args ma;
ifdef|#
directive|ifdef
name|__NetBSD__
argument|struct msdosfs_args da;
endif|#
directive|endif
argument|} args; 	u_long net;  	args.ua.fspec =
literal|0
argument|; 	args.ua.export.ex_flags = exflags; 	args.ua.export.ex_anon = *anoncrp; 	bzero((char *)&sin, sizeof(sin)); 	bzero((char *)&imask, sizeof(imask)); 	sin.sin_family = AF_INET; 	sin.sin_len = sizeof(sin); 	imask.sin_family = AF_INET; 	imask.sin_len = sizeof(sin); 	if (grp->gr_type == GT_HOST) 		addrp = (u_long **)grp->gr_ptr.gt_hostent->h_addr_list; 	else 		addrp = (u_long **)NULL; 	done = FALSE; 	while (!done) { 		switch (grp->gr_type) { 		case GT_HOST: 			if (addrp) { 				sin.sin_addr.s_addr = **addrp; 				args.ua.export.ex_addrlen = sizeof(sin); 			} else 				args.ua.export.ex_addrlen =
literal|0
argument|; 			args.ua.export.ex_addr = (struct sockaddr *)&sin; 			args.ua.export.ex_masklen =
literal|0
argument|; 			break; 		case GT_NET: 			if (grp->gr_ptr.gt_net.nt_mask) 			    imask.sin_addr.s_addr = grp->gr_ptr.gt_net.nt_mask; 			else { 			    net = ntohl(grp->gr_ptr.gt_net.nt_net); 			    if (IN_CLASSA(net)) 				imask.sin_addr.s_addr = inet_addr(
literal|"255.0.0.0"
argument|); 			    else if (IN_CLASSB(net)) 				imask.sin_addr.s_addr = 				    inet_addr(
literal|"255.255.0.0"
argument|); 			    else 				imask.sin_addr.s_addr = 				    inet_addr(
literal|"255.255.255.0"
argument|); 			    grp->gr_ptr.gt_net.nt_mask = imask.sin_addr.s_addr; 			} 			sin.sin_addr.s_addr = grp->gr_ptr.gt_net.nt_net; 			args.ua.export.ex_addr = (struct sockaddr *)&sin; 			args.ua.export.ex_addrlen = sizeof (sin); 			args.ua.export.ex_mask = (struct sockaddr *)&imask; 			args.ua.export.ex_masklen = sizeof (imask); 			break;
ifdef|#
directive|ifdef
name|ISO
argument|case GT_ISO: 			args.ua.export.ex_addr = 				(struct sockaddr *)grp->gr_ptr.gt_isoaddr; 			args.ua.export.ex_addrlen = 				sizeof(struct sockaddr_iso); 			args.ua.export.ex_masklen =
literal|0
argument|; 			break;
endif|#
directive|endif
comment|/* ISO */
argument|case GT_IGNORE: 			return(
literal|0
argument|); 			break; 		default: 			syslog(LOG_ERR,
literal|"Bad grouptype"
argument|); 			if (cp) 				*cp = savedc; 			return (
literal|1
argument|); 		};
comment|/* 		 * XXX: 		 * Maybe I should just use the fsb->f_mntonname path instead 		 * of looping back up the dirp to the mount point?? 		 * Also, needs to know how to export all types of local 		 * exportable file systems and not just MOUNT_UFS. 		 */
ifdef|#
directive|ifdef
name|__NetBSD__
argument|while (mount(fsb->f_fstypename, dirp,
else|#
directive|else
argument|while (mount(fsb->f_type, dirp,
endif|#
directive|endif
argument|fsb->f_flags | MNT_UPDATE, (caddr_t)&args)<
literal|0
argument|) { 			if (cp) 				*cp-- = savedc; 			else 				cp = dirp + dirplen -
literal|1
argument|; 			if (errno == EPERM) { 				syslog(LOG_ERR,
literal|"Can't change attributes for %s.\n"
argument|, dirp); 				return (
literal|1
argument|); 			} 			if (opt_flags& OP_ALLDIRS) { 				syslog(LOG_ERR,
literal|"Could not remount %s: %m"
argument|, 					dirp); 				return (
literal|1
argument|); 			}
comment|/* back up over the last component */
argument|while (*cp ==
literal|'/'
argument|&& cp> dirp) 				cp--; 			while (*(cp -
literal|1
argument|) !=
literal|'/'
argument|&& cp> dirp) 				cp--; 			if (cp == dirp) { 				if (debug) 					fprintf(stderr,
literal|"mnt unsucc\n"
argument|); 				syslog(LOG_ERR,
literal|"Can't export %s"
argument|, dirp); 				return (
literal|1
argument|); 			} 			savedc = *cp; 			*cp =
literal|'\0'
argument|; 		} 		if (addrp) { 			++addrp; 			if (*addrp == (u_long *)NULL) 				done = TRUE; 		} else 			done = TRUE; 	} 	if (cp) 		*cp = savedc; 	return (
literal|0
argument|); }
comment|/*  * Translate a net address.  */
argument|int get_net(cp, net, maskflg) 	char *cp; 	struct netmsk *net; 	int maskflg; { 	struct netent *np; 	long netaddr; 	struct in_addr inetaddr, inetaddr2; 	char *name;  	if (isdigit(*cp)&& ((netaddr = inet_network(cp)) != -
literal|1
argument|)) { 		inetaddr = inet_makeaddr(netaddr,
literal|0
argument|);
comment|/* 		 * Due to arbritrary subnet masks, you don't know how many 		 * bits to shift the address to make it into a network, 		 * however you do know how to make a network address into 		 * a host with host == 0 and then compare them. 		 * (What a pest) 		 */
argument|if (!maskflg) { 			setnetent(
literal|0
argument|); 			while (np = getnetent()) { 				inetaddr2 = inet_makeaddr(np->n_net,
literal|0
argument|); 				if (inetaddr2.s_addr == inetaddr.s_addr) 					break; 			} 			endnetent(); 		} 	} else if ((np = getnetbyname(cp)) != NULL) { 		inetaddr = inet_makeaddr(np->n_net,
literal|0
argument|); 	} else 		return (
literal|1
argument|);  	if (maskflg) 		net->nt_mask = inetaddr.s_addr; 	else { 		if (np) 			name = np->n_name; 		else 			name = inet_ntoa(inetaddr); 		net->nt_name = (char *)malloc(strlen(name) +
literal|1
argument|); 		if (net->nt_name == (char *)NULL) 			out_of_mem(); 		strcpy(net->nt_name, name); 		net->nt_net = inetaddr.s_addr; 	} 	return (
literal|0
argument|); }
comment|/*  * Parse out the next white space separated field  */
argument|void nextfield(cp, endcp) 	char **cp; 	char **endcp; { 	char *p;  	p = *cp; 	while (*p ==
literal|' '
argument||| *p ==
literal|'\t'
argument|) 		p++; 	if (*p ==
literal|'\n'
argument||| *p ==
literal|'\0'
argument|) 		*cp = *endcp = p; 	else { 		*cp = p++; 		while (*p !=
literal|' '
argument|&& *p !=
literal|'\t'
argument|&& *p !=
literal|'\n'
argument|&& *p !=
literal|'\0'
argument|) 			p++; 		*endcp = p; 	} }
comment|/*  * Get an exports file line. Skip over blank lines and handle line  * continuations.  */
argument|int get_line() { 	char *p, *cp; 	int len; 	int totlen, cont_line;
comment|/* 	 * Loop around ignoring blank lines and getting all continuation lines. 	 */
argument|p = line; 	totlen =
literal|0
argument|; 	do { 		if (fgets(p, LINESIZ - totlen, exp_file) == NULL) 			return (
literal|0
argument|); 		len = strlen(p); 		cp = p + len -
literal|1
argument|; 		cont_line =
literal|0
argument|; 		while (cp>= p&& 		    (*cp ==
literal|' '
argument||| *cp ==
literal|'\t'
argument||| *cp ==
literal|'\n'
argument||| *cp ==
literal|'\\'
argument|)) { 			if (*cp ==
literal|'\\'
argument|) 				cont_line =
literal|1
argument|; 			cp--; 			len--; 		} 		*++cp =
literal|'\0'
argument|; 		if (len>
literal|0
argument|) { 			totlen += len; 			if (totlen>= LINESIZ) { 				syslog(LOG_ERR,
literal|"Exports line too long"
argument|); 				exit(
literal|2
argument|); 			} 			p = cp; 		} 	} while (totlen ==
literal|0
argument||| cont_line); 	return (
literal|1
argument|); }
comment|/*  * Parse a description of a credential.  */
argument|void parsecred(namelist, cr) 	char *namelist; 	struct ucred *cr; { 	char *name; 	int cnt; 	char *names; 	struct passwd *pw; 	struct group *gr; 	int ngroups, groups[NGROUPS +
literal|1
argument|];
comment|/* 	 * Set up the unpriviledged user. 	 */
argument|cr->cr_ref =
literal|1
argument|; 	cr->cr_uid = -
literal|2
argument|; 	cr->cr_groups[
literal|0
argument|] = -
literal|2
argument|; 	cr->cr_ngroups =
literal|1
argument|;
comment|/* 	 * Get the user's password table entry. 	 */
argument|names = strsep(&namelist,
literal|" \t\n"
argument|); 	name = strsep(&names,
literal|":"
argument|); 	if (isdigit(*name) || *name ==
literal|'-'
argument|) 		pw = getpwuid(atoi(name)); 	else 		pw = getpwnam(name);
comment|/* 	 * Credentials specified as those of a user. 	 */
argument|if (names == NULL) { 		if (pw == NULL) { 			syslog(LOG_ERR,
literal|"Unknown user: %s"
argument|, name); 			return; 		} 		cr->cr_uid = pw->pw_uid; 		ngroups = NGROUPS +
literal|1
argument|; 		if (getgrouplist(pw->pw_name, pw->pw_gid, groups,&ngroups)) 			syslog(LOG_ERR,
literal|"Too many groups"
argument|);
comment|/* 		 * Convert from int's to gid_t's and compress out duplicate 		 */
argument|cr->cr_ngroups = ngroups -
literal|1
argument|; 		cr->cr_groups[
literal|0
argument|] = groups[
literal|0
argument|]; 		for (cnt =
literal|2
argument|; cnt< ngroups; cnt++) 			cr->cr_groups[cnt -
literal|1
argument|] = groups[cnt]; 		return; 	}
comment|/* 	 * Explicit credential specified as a colon separated list: 	 *	uid:gid:gid:... 	 */
argument|if (pw != NULL) 		cr->cr_uid = pw->pw_uid; 	else if (isdigit(*name) || *name ==
literal|'-'
argument|) 		cr->cr_uid = atoi(name); 	else { 		syslog(LOG_ERR,
literal|"Unknown user: %s"
argument|, name); 		return; 	} 	cr->cr_ngroups =
literal|0
argument|; 	while (names != NULL&& *names !=
literal|'\0'
argument|&& cr->cr_ngroups< NGROUPS) { 		name = strsep(&names,
literal|":"
argument|); 		if (isdigit(*name) || *name ==
literal|'-'
argument|) { 			cr->cr_groups[cr->cr_ngroups++] = atoi(name); 		} else { 			if ((gr = getgrnam(name)) == NULL) { 				syslog(LOG_ERR,
literal|"Unknown group: %s"
argument|, name); 				continue; 			} 			cr->cr_groups[cr->cr_ngroups++] = gr->gr_gid; 		} 	} 	if (names != NULL&& *names !=
literal|'\0'
argument|&& cr->cr_ngroups == NGROUPS) 		syslog(LOG_ERR,
literal|"Too many groups"
argument|); }
define|#
directive|define
name|STRSIZ
value|(RPCMNT_NAMELEN+RPCMNT_PATHLEN+50)
comment|/*  * Routines that maintain the remote mounttab  */
argument|void get_mountlist() { 	struct mountlist *mlp, **mlpp; 	char *eos, *dirp; 	int len; 	char str[STRSIZ]; 	FILE *mlfile;  	if ((mlfile = fopen(_PATH_RMOUNTLIST,
literal|"r"
argument|)) == NULL) { 		syslog(LOG_ERR,
literal|"Can't open %s"
argument|, _PATH_RMOUNTLIST); 		return; 	} 	mlpp =&mlhead; 	while (fgets(str, STRSIZ, mlfile) != NULL) { 		if ((dirp = index(str,
literal|'\t'
argument|)) == NULL&& 		    (dirp = index(str,
literal|' '
argument|)) == NULL) 			continue; 		mlp = (struct mountlist *)malloc(sizeof (*mlp)); 		len = dirp-str; 		if (len> RPCMNT_NAMELEN) 			len = RPCMNT_NAMELEN; 		bcopy(str, mlp->ml_host, len); 		mlp->ml_host[len] =
literal|'\0'
argument|; 		while (*dirp ==
literal|'\t'
argument||| *dirp ==
literal|' '
argument|) 			dirp++; 		if ((eos = index(dirp,
literal|'\t'
argument|)) == NULL&& 		    (eos = index(dirp,
literal|' '
argument|)) == NULL&& 		    (eos = index(dirp,
literal|'\n'
argument|)) == NULL) 			len = strlen(dirp); 		else 			len = eos-dirp; 		if (len> RPCMNT_PATHLEN) 			len = RPCMNT_PATHLEN; 		bcopy(dirp, mlp->ml_dirp, len); 		mlp->ml_dirp[len] =
literal|'\0'
argument|; 		mlp->ml_next = (struct mountlist *)NULL; 		*mlpp = mlp; 		mlpp =&mlp->ml_next; 	} 	fclose(mlfile); }  void del_mlist(hostp, dirp) 	char *hostp, *dirp; { 	struct mountlist *mlp, **mlpp; 	struct mountlist *mlp2; 	FILE *mlfile; 	int fnd =
literal|0
argument|;  	mlpp =&mlhead; 	mlp = mlhead; 	while (mlp) { 		if (!strcmp(mlp->ml_host, hostp)&& 		    (!dirp || !strcmp(mlp->ml_dirp, dirp))) { 			fnd =
literal|1
argument|; 			mlp2 = mlp; 			*mlpp = mlp = mlp->ml_next; 			free((caddr_t)mlp2); 		} else { 			mlpp =&mlp->ml_next; 			mlp = mlp->ml_next; 		} 	} 	if (fnd) { 		if ((mlfile = fopen(_PATH_RMOUNTLIST,
literal|"w"
argument|)) == NULL) { 			syslog(LOG_ERR,
literal|"Can't update %s"
argument|, _PATH_RMOUNTLIST); 			return; 		} 		mlp = mlhead; 		while (mlp) { 			fprintf(mlfile,
literal|"%s %s\n"
argument|, mlp->ml_host, mlp->ml_dirp); 			mlp = mlp->ml_next; 		} 		fclose(mlfile); 	} }  void add_mlist(hostp, dirp) 	char *hostp, *dirp; { 	struct mountlist *mlp, **mlpp; 	FILE *mlfile;  	mlpp =&mlhead; 	mlp = mlhead; 	while (mlp) { 		if (!strcmp(mlp->ml_host, hostp)&& !strcmp(mlp->ml_dirp, dirp)) 			return; 		mlpp =&mlp->ml_next; 		mlp = mlp->ml_next; 	} 	mlp = (struct mountlist *)malloc(sizeof (*mlp)); 	strncpy(mlp->ml_host, hostp, RPCMNT_NAMELEN); 	mlp->ml_host[RPCMNT_NAMELEN] =
literal|'\0'
argument|; 	strncpy(mlp->ml_dirp, dirp, RPCMNT_PATHLEN); 	mlp->ml_dirp[RPCMNT_PATHLEN] =
literal|'\0'
argument|; 	mlp->ml_next = (struct mountlist *)NULL; 	*mlpp = mlp; 	if ((mlfile = fopen(_PATH_RMOUNTLIST,
literal|"a"
argument|)) == NULL) { 		syslog(LOG_ERR,
literal|"Can't update %s"
argument|, _PATH_RMOUNTLIST); 		return; 	} 	fprintf(mlfile,
literal|"%s %s\n"
argument|, mlp->ml_host, mlp->ml_dirp); 	fclose(mlfile); }
comment|/*  * This function is called via. SIGTERM when the system is going down.  * It sends a broadcast RPCMNT_UMNTALL.  */
argument|void send_umntall() { 	(void) clnt_broadcast(RPCPROG_MNT, RPCMNT_VER1, RPCMNT_UMNTALL, 		xdr_void, (caddr_t)
literal|0
argument|, xdr_void, (caddr_t)
literal|0
argument|, umntall_each); 	exit(
literal|0
argument|); }  int umntall_each(resultsp, raddr) 	caddr_t resultsp; 	struct sockaddr_in *raddr; { 	return (
literal|1
argument|); }
comment|/*  * Free up a group list.  */
argument|void free_grp(grp) 	struct grouplist *grp; { 	char **addrp;  	if (grp->gr_type == GT_HOST) { 		if (grp->gr_ptr.gt_hostent->h_name) { 			addrp = grp->gr_ptr.gt_hostent->h_addr_list; 			while (addrp&& *addrp) 				free(*addrp++); 			free((caddr_t)grp->gr_ptr.gt_hostent->h_addr_list); 			free(grp->gr_ptr.gt_hostent->h_name); 		} 		free((caddr_t)grp->gr_ptr.gt_hostent); 	} else if (grp->gr_type == GT_NET) { 		if (grp->gr_ptr.gt_net.nt_name) 			free(grp->gr_ptr.gt_net.nt_name); 	}
ifdef|#
directive|ifdef
name|ISO
argument|else if (grp->gr_type == GT_ISO) 		free((caddr_t)grp->gr_ptr.gt_isoaddr);
endif|#
directive|endif
argument|free((caddr_t)grp); }
ifdef|#
directive|ifdef
name|DEBUG
argument|void SYSLOG(int pri, const char *fmt, ...) { 	va_list ap;  	va_start(ap, fmt); 	vfprintf(stderr, fmt, ap); 	va_end(ap); }
endif|#
directive|endif
comment|/* DEBUG */
comment|/*  * Check options for consistency.  */
argument|int check_options(dp) 	struct dirlist *dp; {  	if (dp == (struct dirlist *)NULL) 	    return (
literal|1
argument|); 	if ((opt_flags& (OP_MAPROOT | OP_MAPALL)) == (OP_MAPROOT | OP_MAPALL) || 	    (opt_flags& (OP_MAPROOT | OP_KERB)) == (OP_MAPROOT | OP_KERB) || 	    (opt_flags& (OP_MAPALL | OP_KERB)) == (OP_MAPALL | OP_KERB)) { 	    syslog(LOG_ERR,
literal|"-mapall, -maproot and -kerb mutually exclusive"
argument|); 	    return (
literal|1
argument|); 	} 	if ((opt_flags& OP_MASK)&& (opt_flags& OP_NET) ==
literal|0
argument|) { 	    syslog(LOG_ERR,
literal|"-mask requires -net"
argument|); 	    return (
literal|1
argument|); 	} 	if ((opt_flags& (OP_NET | OP_ISO)) == (OP_NET | OP_ISO)) { 	    syslog(LOG_ERR,
literal|"-net and -iso mutually exclusive"
argument|); 	    return (
literal|1
argument|); 	} 	if ((opt_flags& OP_ALLDIRS)&& dp->dp_left) { 	    syslog(LOG_ERR,
literal|"-alldir has multiple directories"
argument|); 	    return (
literal|1
argument|); 	} 	return (
literal|0
argument|); }
comment|/*  * Check an absolute directory path for any symbolic links. Return true  * if no symbolic links are found.  */
argument|int check_dirpath(dirp) 	char *dirp; { 	char *cp; 	int ret =
literal|1
argument|; 	struct stat sb;  	cp = dirp +
literal|1
argument|; 	while (*cp&& ret) { 		if (*cp ==
literal|'/'
argument|) { 			*cp =
literal|'\0'
argument|; 			if (lstat(dirp,&sb)<
literal|0
argument||| !S_ISDIR(sb.st_mode)) 				ret =
literal|0
argument|; 			*cp =
literal|'/'
argument|; 		} 		cp++; 	} 	if (lstat(dirp,&sb)<
literal|0
argument||| !S_ISDIR(sb.st_mode)) 		ret =
literal|0
argument|; 	return (ret); }
comment|/*  * Just translate an ascii string to an integer.  */
argument|int get_num(cp) 	register char *cp; { 	register int res =
literal|0
argument|;  	while (*cp) { 		if (*cp<
literal|'0'
argument||| *cp>
literal|'9'
argument|) 			return (-
literal|1
argument|); 		res = res *
literal|10
argument|+ (*cp++ -
literal|'0'
argument|); 	} 	return (res); }
end_function

end_unit

