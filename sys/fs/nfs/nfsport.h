begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFSPORT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFSPORT_H_
end_define

begin_comment
comment|/*  * In general, I'm not fond of #includes in .h files, but this seems  * to be the cleanest way to handle #include files for the ports.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/dirent.h>
end_include

begin_include
include|#
directive|include
file|<sys/domain.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/filedesc.h>
end_include

begin_include
include|#
directive|include
file|<sys/jail.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lockf.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/namei.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
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
file|<sys/sysproto.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/acl.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_include
include|#
directive|include
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/syscallsubr.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<net/radix.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_pcb.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_fsm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_seq.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_timer.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/in_cksum.h>
end_include

begin_include
include|#
directive|include
file|<crypto/des/des.h>
end_include

begin_include
include|#
directive|include
file|<sys/md5.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpcsec_gss.h>
end_include

begin_comment
comment|/*  * For Darwin, these functions should be "static" when built in a kext.  * (This is always defined as nil otherwise.)  */
end_comment

begin_define
define|#
directive|define
name|APPLESTATIC
end_define

begin_include
include|#
directive|include
file|<ufs/ufs/dir.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/quota.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/inode.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/extattr.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/ufsmount.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<nfs/nfssvc.h>
end_include

begin_include
include|#
directive|include
file|"opt_nfs.h"
end_include

begin_include
include|#
directive|include
file|"opt_ufs.h"
end_include

begin_comment
comment|/*  * These types must be defined before the nfs includes.  */
end_comment

begin_define
define|#
directive|define
name|NFSSOCKADDR_T
value|struct sockaddr *
end_define

begin_define
define|#
directive|define
name|NFSPROC_T
value|struct thread
end_define

begin_define
define|#
directive|define
name|NFSDEV_T
value|dev_t
end_define

begin_define
define|#
directive|define
name|NFSSVCARGS
value|nfssvc_args
end_define

begin_define
define|#
directive|define
name|NFSACL_T
value|struct acl
end_define

begin_comment
comment|/*  * These should be defined as the types used for the corresponding VOP's  * argument type.  */
end_comment

begin_define
define|#
directive|define
name|NFS_ACCESS_ARGS
value|struct vop_access_args
end_define

begin_define
define|#
directive|define
name|NFS_OPEN_ARGS
value|struct vop_open_args
end_define

begin_define
define|#
directive|define
name|NFS_GETATTR_ARGS
value|struct vop_getattr_args
end_define

begin_define
define|#
directive|define
name|NFS_LOOKUP_ARGS
value|struct vop_lookup_args
end_define

begin_define
define|#
directive|define
name|NFS_READDIR_ARGS
value|struct vop_readdir_args
end_define

begin_comment
comment|/*  * Allocate mbufs. Must succeed and never set the mbuf ptr to NULL.  */
end_comment

begin_define
define|#
directive|define
name|NFSMGET
parameter_list|(
name|m
parameter_list|)
value|do { 					\ 		MGET((m), M_WAITOK, MT_DATA); 			\ 		while ((m) == NULL ) { 				\ 			(void) nfs_catnap(PZERO, 0, "nfsmget");	\ 			MGET((m), M_WAITOK, MT_DATA); 		\ 		} 						\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NFSMGETHDR
parameter_list|(
name|m
parameter_list|)
value|do { 					\ 		MGETHDR((m), M_WAITOK, MT_DATA);		\ 		while ((m) == NULL ) { 				\ 			(void) nfs_catnap(PZERO, 0, "nfsmget");	\ 			MGETHDR((m), M_WAITOK, MT_DATA); 	\ 		} 						\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NFSMCLGET
parameter_list|(
name|m
parameter_list|,
name|w
parameter_list|)
value|do { 					\ 		MGET((m), M_WAITOK, MT_DATA); 			\ 		while ((m) == NULL ) { 				\ 			(void) nfs_catnap(PZERO, 0, "nfsmget");	\ 			MGET((m), M_WAITOK, MT_DATA); 		\ 		} 						\ 		MCLGET((m), (w));				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NFSMCLGETHDR
parameter_list|(
name|m
parameter_list|,
name|w
parameter_list|)
value|do { 				\ 		MGETHDR((m), M_WAITOK, MT_DATA);		\ 		while ((m) == NULL ) { 				\ 			(void) nfs_catnap(PZERO, 0, "nfsmget");	\ 			MGETHDR((m), M_WAITOK, MT_DATA); 	\ 		} 						\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NFSMTOD
value|mtod
end_define

begin_comment
comment|/*  * Client side constant for size of a lockowner name.  */
end_comment

begin_define
define|#
directive|define
name|NFSV4CL_LOCKNAMELEN
value|12
end_define

begin_comment
comment|/*  * Type for a mutex lock.  */
end_comment

begin_define
define|#
directive|define
name|NFSMUTEX_T
value|struct mtx
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * NFSv4 Operation numbers.  */
end_comment

begin_define
define|#
directive|define
name|NFSV4OP_ACCESS
value|3
end_define

begin_define
define|#
directive|define
name|NFSV4OP_CLOSE
value|4
end_define

begin_define
define|#
directive|define
name|NFSV4OP_COMMIT
value|5
end_define

begin_define
define|#
directive|define
name|NFSV4OP_CREATE
value|6
end_define

begin_define
define|#
directive|define
name|NFSV4OP_DELEGPURGE
value|7
end_define

begin_define
define|#
directive|define
name|NFSV4OP_DELEGRETURN
value|8
end_define

begin_define
define|#
directive|define
name|NFSV4OP_GETATTR
value|9
end_define

begin_define
define|#
directive|define
name|NFSV4OP_GETFH
value|10
end_define

begin_define
define|#
directive|define
name|NFSV4OP_LINK
value|11
end_define

begin_define
define|#
directive|define
name|NFSV4OP_LOCK
value|12
end_define

begin_define
define|#
directive|define
name|NFSV4OP_LOCKT
value|13
end_define

begin_define
define|#
directive|define
name|NFSV4OP_LOCKU
value|14
end_define

begin_define
define|#
directive|define
name|NFSV4OP_LOOKUP
value|15
end_define

begin_define
define|#
directive|define
name|NFSV4OP_LOOKUPP
value|16
end_define

begin_define
define|#
directive|define
name|NFSV4OP_NVERIFY
value|17
end_define

begin_define
define|#
directive|define
name|NFSV4OP_OPEN
value|18
end_define

begin_define
define|#
directive|define
name|NFSV4OP_OPENATTR
value|19
end_define

begin_define
define|#
directive|define
name|NFSV4OP_OPENCONFIRM
value|20
end_define

begin_define
define|#
directive|define
name|NFSV4OP_OPENDOWNGRADE
value|21
end_define

begin_define
define|#
directive|define
name|NFSV4OP_PUTFH
value|22
end_define

begin_define
define|#
directive|define
name|NFSV4OP_PUTPUBFH
value|23
end_define

begin_define
define|#
directive|define
name|NFSV4OP_PUTROOTFH
value|24
end_define

begin_define
define|#
directive|define
name|NFSV4OP_READ
value|25
end_define

begin_define
define|#
directive|define
name|NFSV4OP_READDIR
value|26
end_define

begin_define
define|#
directive|define
name|NFSV4OP_READLINK
value|27
end_define

begin_define
define|#
directive|define
name|NFSV4OP_REMOVE
value|28
end_define

begin_define
define|#
directive|define
name|NFSV4OP_RENAME
value|29
end_define

begin_define
define|#
directive|define
name|NFSV4OP_RENEW
value|30
end_define

begin_define
define|#
directive|define
name|NFSV4OP_RESTOREFH
value|31
end_define

begin_define
define|#
directive|define
name|NFSV4OP_SAVEFH
value|32
end_define

begin_define
define|#
directive|define
name|NFSV4OP_SECINFO
value|33
end_define

begin_define
define|#
directive|define
name|NFSV4OP_SETATTR
value|34
end_define

begin_define
define|#
directive|define
name|NFSV4OP_SETCLIENTID
value|35
end_define

begin_define
define|#
directive|define
name|NFSV4OP_SETCLIENTIDCFRM
value|36
end_define

begin_define
define|#
directive|define
name|NFSV4OP_VERIFY
value|37
end_define

begin_define
define|#
directive|define
name|NFSV4OP_WRITE
value|38
end_define

begin_define
define|#
directive|define
name|NFSV4OP_RELEASELCKOWN
value|39
end_define

begin_comment
comment|/*  * Must be one greater than the last Operation#.  */
end_comment

begin_define
define|#
directive|define
name|NFSV4OP_NOPS
value|40
end_define

begin_comment
comment|/*  * Additional Ops for NFSv4.1.  */
end_comment

begin_define
define|#
directive|define
name|NFSV4OP_BACKCHANNELCTL
value|40
end_define

begin_define
define|#
directive|define
name|NFSV4OP_BINDCONNTOSESS
value|41
end_define

begin_define
define|#
directive|define
name|NFSV4OP_EXCHANGEID
value|42
end_define

begin_define
define|#
directive|define
name|NFSV4OP_CREATESESSION
value|43
end_define

begin_define
define|#
directive|define
name|NFSV4OP_DESTROYSESSION
value|44
end_define

begin_define
define|#
directive|define
name|NFSV4OP_FREESTATEID
value|45
end_define

begin_define
define|#
directive|define
name|NFSV4OP_GETDIRDELEG
value|46
end_define

begin_define
define|#
directive|define
name|NFSV4OP_GETDEVINFO
value|47
end_define

begin_define
define|#
directive|define
name|NFSV4OP_GETDEVLIST
value|48
end_define

begin_define
define|#
directive|define
name|NFSV4OP_LAYOUTCOMMIT
value|49
end_define

begin_define
define|#
directive|define
name|NFSV4OP_LAYOUTGET
value|50
end_define

begin_define
define|#
directive|define
name|NFSV4OP_LAYOUTRETURN
value|51
end_define

begin_define
define|#
directive|define
name|NFSV4OP_SECINFONONAME
value|52
end_define

begin_define
define|#
directive|define
name|NFSV4OP_SEQUENCE
value|53
end_define

begin_define
define|#
directive|define
name|NFSV4OP_SETSSV
value|54
end_define

begin_define
define|#
directive|define
name|NFSV4OP_TESTSTATEID
value|55
end_define

begin_define
define|#
directive|define
name|NFSV4OP_WANTDELEG
value|56
end_define

begin_define
define|#
directive|define
name|NFSV4OP_DESTROYCLIENTID
value|57
end_define

begin_define
define|#
directive|define
name|NFSV4OP_RECLAIMCOMPL
value|58
end_define

begin_comment
comment|/*  * Must be one more than last op#.  * NFSv4.2 isn't implemented yet, but define the op# limit for it.  */
end_comment

begin_define
define|#
directive|define
name|NFSV41_NOPS
value|59
end_define

begin_define
define|#
directive|define
name|NFSV42_NOPS
value|72
end_define

begin_comment
comment|/* Quirky case if the illegal op code */
end_comment

begin_define
define|#
directive|define
name|NFSV4OP_OPILLEGAL
value|10044
end_define

begin_comment
comment|/*  * Fake NFSV4OP_xxx used for nfsstat. Start at NFSV42_NOPS.  */
end_comment

begin_define
define|#
directive|define
name|NFSV4OP_SYMLINK
value|(NFSV42_NOPS)
end_define

begin_define
define|#
directive|define
name|NFSV4OP_MKDIR
value|(NFSV42_NOPS + 1)
end_define

begin_define
define|#
directive|define
name|NFSV4OP_RMDIR
value|(NFSV42_NOPS + 2)
end_define

begin_define
define|#
directive|define
name|NFSV4OP_READDIRPLUS
value|(NFSV42_NOPS + 3)
end_define

begin_define
define|#
directive|define
name|NFSV4OP_MKNOD
value|(NFSV42_NOPS + 4)
end_define

begin_define
define|#
directive|define
name|NFSV4OP_FSSTAT
value|(NFSV42_NOPS + 5)
end_define

begin_define
define|#
directive|define
name|NFSV4OP_FSINFO
value|(NFSV42_NOPS + 6)
end_define

begin_define
define|#
directive|define
name|NFSV4OP_PATHCONF
value|(NFSV42_NOPS + 7)
end_define

begin_define
define|#
directive|define
name|NFSV4OP_V3CREATE
value|(NFSV42_NOPS + 8)
end_define

begin_comment
comment|/*  * This is the count of the fake operations listed above.  */
end_comment

begin_define
define|#
directive|define
name|NFSV4OP_FAKENOPS
value|9
end_define

begin_comment
comment|/*  * and the Callback OPs  */
end_comment

begin_define
define|#
directive|define
name|NFSV4OP_CBGETATTR
value|3
end_define

begin_define
define|#
directive|define
name|NFSV4OP_CBRECALL
value|4
end_define

begin_comment
comment|/*  * Must be one greater than the last Callback Operation# for NFSv4.0.  */
end_comment

begin_define
define|#
directive|define
name|NFSV4OP_CBNOPS
value|5
end_define

begin_comment
comment|/*  * Additional Callback Ops for NFSv4.1 only.  */
end_comment

begin_define
define|#
directive|define
name|NFSV4OP_CBLAYOUTRECALL
value|5
end_define

begin_define
define|#
directive|define
name|NFSV4OP_CBNOTIFY
value|6
end_define

begin_define
define|#
directive|define
name|NFSV4OP_CBPUSHDELEG
value|7
end_define

begin_define
define|#
directive|define
name|NFSV4OP_CBRECALLANY
value|8
end_define

begin_define
define|#
directive|define
name|NFSV4OP_CBRECALLOBJAVAIL
value|9
end_define

begin_define
define|#
directive|define
name|NFSV4OP_CBRECALLSLOT
value|10
end_define

begin_define
define|#
directive|define
name|NFSV4OP_CBSEQUENCE
value|11
end_define

begin_define
define|#
directive|define
name|NFSV4OP_CBWANTCANCELLED
value|12
end_define

begin_define
define|#
directive|define
name|NFSV4OP_CBNOTIFYLOCK
value|13
end_define

begin_define
define|#
directive|define
name|NFSV4OP_CBNOTIFYDEVID
value|14
end_define

begin_define
define|#
directive|define
name|NFSV41_CBNOPS
value|15
end_define

begin_define
define|#
directive|define
name|NFSV42_CBNOPS
value|16
end_define

begin_comment
comment|/*  * The lower numbers -> 21 are used by NFSv2 and v3. These define higher  * numbers used by NFSv4.  * NFS_V3NPROCS is one greater than the last V3 op and NFS_NPROCS is  * one greater than the last number.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_V3NPROCS
end_ifndef

begin_define
define|#
directive|define
name|NFS_V3NPROCS
value|22
end_define

begin_define
define|#
directive|define
name|NFSPROC_LOOKUPP
value|22
end_define

begin_define
define|#
directive|define
name|NFSPROC_SETCLIENTID
value|23
end_define

begin_define
define|#
directive|define
name|NFSPROC_SETCLIENTIDCFRM
value|24
end_define

begin_define
define|#
directive|define
name|NFSPROC_LOCK
value|25
end_define

begin_define
define|#
directive|define
name|NFSPROC_LOCKU
value|26
end_define

begin_define
define|#
directive|define
name|NFSPROC_OPEN
value|27
end_define

begin_define
define|#
directive|define
name|NFSPROC_CLOSE
value|28
end_define

begin_define
define|#
directive|define
name|NFSPROC_OPENCONFIRM
value|29
end_define

begin_define
define|#
directive|define
name|NFSPROC_LOCKT
value|30
end_define

begin_define
define|#
directive|define
name|NFSPROC_OPENDOWNGRADE
value|31
end_define

begin_define
define|#
directive|define
name|NFSPROC_RENEW
value|32
end_define

begin_define
define|#
directive|define
name|NFSPROC_PUTROOTFH
value|33
end_define

begin_define
define|#
directive|define
name|NFSPROC_RELEASELCKOWN
value|34
end_define

begin_define
define|#
directive|define
name|NFSPROC_DELEGRETURN
value|35
end_define

begin_define
define|#
directive|define
name|NFSPROC_RETDELEGREMOVE
value|36
end_define

begin_define
define|#
directive|define
name|NFSPROC_RETDELEGRENAME1
value|37
end_define

begin_define
define|#
directive|define
name|NFSPROC_RETDELEGRENAME2
value|38
end_define

begin_define
define|#
directive|define
name|NFSPROC_GETACL
value|39
end_define

begin_define
define|#
directive|define
name|NFSPROC_SETACL
value|40
end_define

begin_comment
comment|/*  * Must be defined as one higher than the last Proc# above.  */
end_comment

begin_define
define|#
directive|define
name|NFSV4_NPROCS
value|41
end_define

begin_comment
comment|/* Additional procedures for NFSv4.1. */
end_comment

begin_define
define|#
directive|define
name|NFSPROC_EXCHANGEID
value|41
end_define

begin_define
define|#
directive|define
name|NFSPROC_CREATESESSION
value|42
end_define

begin_define
define|#
directive|define
name|NFSPROC_DESTROYSESSION
value|43
end_define

begin_define
define|#
directive|define
name|NFSPROC_DESTROYCLIENT
value|44
end_define

begin_define
define|#
directive|define
name|NFSPROC_FREESTATEID
value|45
end_define

begin_define
define|#
directive|define
name|NFSPROC_LAYOUTGET
value|46
end_define

begin_define
define|#
directive|define
name|NFSPROC_GETDEVICEINFO
value|47
end_define

begin_define
define|#
directive|define
name|NFSPROC_LAYOUTCOMMIT
value|48
end_define

begin_define
define|#
directive|define
name|NFSPROC_LAYOUTRETURN
value|49
end_define

begin_define
define|#
directive|define
name|NFSPROC_RECLAIMCOMPL
value|50
end_define

begin_define
define|#
directive|define
name|NFSPROC_WRITEDS
value|51
end_define

begin_define
define|#
directive|define
name|NFSPROC_READDS
value|52
end_define

begin_define
define|#
directive|define
name|NFSPROC_COMMITDS
value|53
end_define

begin_comment
comment|/*  * Must be defined as one higher than the last NFSv4.1 Proc# above.  */
end_comment

begin_define
define|#
directive|define
name|NFSV41_NPROCS
value|54
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NFS_V3NPROCS */
end_comment

begin_comment
comment|/*  * New stats structure.  * The vers field will be set to NFSSTATS_V1 by the caller.  */
end_comment

begin_define
define|#
directive|define
name|NFSSTATS_V1
value|1
end_define

begin_struct
struct|struct
name|nfsstatsv1
block|{
name|int
name|vers
decl_stmt|;
comment|/* Set to version requested by caller. */
name|uint64_t
name|attrcache_hits
decl_stmt|;
name|uint64_t
name|attrcache_misses
decl_stmt|;
name|uint64_t
name|lookupcache_hits
decl_stmt|;
name|uint64_t
name|lookupcache_misses
decl_stmt|;
name|uint64_t
name|direofcache_hits
decl_stmt|;
name|uint64_t
name|direofcache_misses
decl_stmt|;
name|uint64_t
name|accesscache_hits
decl_stmt|;
name|uint64_t
name|accesscache_misses
decl_stmt|;
name|uint64_t
name|biocache_reads
decl_stmt|;
name|uint64_t
name|read_bios
decl_stmt|;
name|uint64_t
name|read_physios
decl_stmt|;
name|uint64_t
name|biocache_writes
decl_stmt|;
name|uint64_t
name|write_bios
decl_stmt|;
name|uint64_t
name|write_physios
decl_stmt|;
name|uint64_t
name|biocache_readlinks
decl_stmt|;
name|uint64_t
name|readlink_bios
decl_stmt|;
name|uint64_t
name|biocache_readdirs
decl_stmt|;
name|uint64_t
name|readdir_bios
decl_stmt|;
name|uint64_t
name|rpccnt
index|[
name|NFSV41_NPROCS
operator|+
literal|15
index|]
decl_stmt|;
name|uint64_t
name|rpcretries
decl_stmt|;
name|uint64_t
name|srvrpccnt
index|[
name|NFSV42_NOPS
operator|+
name|NFSV4OP_FAKENOPS
index|]
decl_stmt|;
name|uint64_t
name|srvrpc_errs
decl_stmt|;
name|uint64_t
name|srv_errs
decl_stmt|;
name|uint64_t
name|rpcrequests
decl_stmt|;
name|uint64_t
name|rpctimeouts
decl_stmt|;
name|uint64_t
name|rpcunexpected
decl_stmt|;
name|uint64_t
name|rpcinvalid
decl_stmt|;
name|uint64_t
name|srvcache_inproghits
decl_stmt|;
name|uint64_t
name|srvcache_idemdonehits
decl_stmt|;
name|uint64_t
name|srvcache_nonidemdonehits
decl_stmt|;
name|uint64_t
name|srvcache_misses
decl_stmt|;
name|uint64_t
name|srvcache_tcppeak
decl_stmt|;
name|int
name|srvcache_size
decl_stmt|;
comment|/* Updated by atomic_xx_int(). */
name|uint64_t
name|srvclients
decl_stmt|;
name|uint64_t
name|srvopenowners
decl_stmt|;
name|uint64_t
name|srvopens
decl_stmt|;
name|uint64_t
name|srvlockowners
decl_stmt|;
name|uint64_t
name|srvlocks
decl_stmt|;
name|uint64_t
name|srvdelegates
decl_stmt|;
name|uint64_t
name|cbrpccnt
index|[
name|NFSV42_CBNOPS
index|]
decl_stmt|;
name|uint64_t
name|clopenowners
decl_stmt|;
name|uint64_t
name|clopens
decl_stmt|;
name|uint64_t
name|cllockowners
decl_stmt|;
name|uint64_t
name|cllocks
decl_stmt|;
name|uint64_t
name|cldelegates
decl_stmt|;
name|uint64_t
name|cllocalopenowners
decl_stmt|;
name|uint64_t
name|cllocalopens
decl_stmt|;
name|uint64_t
name|cllocallockowners
decl_stmt|;
name|uint64_t
name|cllocallocks
decl_stmt|;
name|uint64_t
name|srvstartcnt
decl_stmt|;
name|uint64_t
name|srvdonecnt
decl_stmt|;
name|uint64_t
name|srvbytes
index|[
name|NFSV42_NOPS
operator|+
name|NFSV4OP_FAKENOPS
index|]
decl_stmt|;
name|uint64_t
name|srvops
index|[
name|NFSV42_NOPS
operator|+
name|NFSV4OP_FAKENOPS
index|]
decl_stmt|;
name|struct
name|bintime
name|srvduration
index|[
name|NFSV42_NOPS
operator|+
name|NFSV4OP_FAKENOPS
index|]
decl_stmt|;
name|struct
name|bintime
name|busyfrom
decl_stmt|;
name|struct
name|bintime
name|busytime
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Old stats structure.  */
end_comment

begin_struct
struct|struct
name|ext_nfsstats
block|{
name|int
name|attrcache_hits
decl_stmt|;
name|int
name|attrcache_misses
decl_stmt|;
name|int
name|lookupcache_hits
decl_stmt|;
name|int
name|lookupcache_misses
decl_stmt|;
name|int
name|direofcache_hits
decl_stmt|;
name|int
name|direofcache_misses
decl_stmt|;
name|int
name|accesscache_hits
decl_stmt|;
name|int
name|accesscache_misses
decl_stmt|;
name|int
name|biocache_reads
decl_stmt|;
name|int
name|read_bios
decl_stmt|;
name|int
name|read_physios
decl_stmt|;
name|int
name|biocache_writes
decl_stmt|;
name|int
name|write_bios
decl_stmt|;
name|int
name|write_physios
decl_stmt|;
name|int
name|biocache_readlinks
decl_stmt|;
name|int
name|readlink_bios
decl_stmt|;
name|int
name|biocache_readdirs
decl_stmt|;
name|int
name|readdir_bios
decl_stmt|;
name|int
name|rpccnt
index|[
name|NFSV4_NPROCS
index|]
decl_stmt|;
name|int
name|rpcretries
decl_stmt|;
name|int
name|srvrpccnt
index|[
name|NFSV4OP_NOPS
operator|+
name|NFSV4OP_FAKENOPS
index|]
decl_stmt|;
name|int
name|srvrpc_errs
decl_stmt|;
name|int
name|srv_errs
decl_stmt|;
name|int
name|rpcrequests
decl_stmt|;
name|int
name|rpctimeouts
decl_stmt|;
name|int
name|rpcunexpected
decl_stmt|;
name|int
name|rpcinvalid
decl_stmt|;
name|int
name|srvcache_inproghits
decl_stmt|;
name|int
name|srvcache_idemdonehits
decl_stmt|;
name|int
name|srvcache_nonidemdonehits
decl_stmt|;
name|int
name|srvcache_misses
decl_stmt|;
name|int
name|srvcache_tcppeak
decl_stmt|;
name|int
name|srvcache_size
decl_stmt|;
name|int
name|srvclients
decl_stmt|;
name|int
name|srvopenowners
decl_stmt|;
name|int
name|srvopens
decl_stmt|;
name|int
name|srvlockowners
decl_stmt|;
name|int
name|srvlocks
decl_stmt|;
name|int
name|srvdelegates
decl_stmt|;
name|int
name|cbrpccnt
index|[
name|NFSV4OP_CBNOPS
index|]
decl_stmt|;
name|int
name|clopenowners
decl_stmt|;
name|int
name|clopens
decl_stmt|;
name|int
name|cllockowners
decl_stmt|;
name|int
name|cllocks
decl_stmt|;
name|int
name|cldelegates
decl_stmt|;
name|int
name|cllocalopenowners
decl_stmt|;
name|int
name|cllocalopens
decl_stmt|;
name|int
name|cllocallockowners
decl_stmt|;
name|int
name|cllocallocks
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Define NFS_NPROCS as NFSV4_NPROCS for the experimental kernel code.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_NPROCS
end_ifndef

begin_define
define|#
directive|define
name|NFS_NPROCS
value|NFSV4_NPROCS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<fs/nfs/nfskpiport.h>
end_include

begin_include
include|#
directive|include
file|<fs/nfs/nfsdport.h>
end_include

begin_include
include|#
directive|include
file|<fs/nfs/rpcv2.h>
end_include

begin_include
include|#
directive|include
file|<fs/nfs/nfsproto.h>
end_include

begin_include
include|#
directive|include
file|<fs/nfs/nfs.h>
end_include

begin_include
include|#
directive|include
file|<fs/nfs/nfsclstate.h>
end_include

begin_include
include|#
directive|include
file|<fs/nfs/nfs_var.h>
end_include

begin_include
include|#
directive|include
file|<fs/nfs/nfsm_subs.h>
end_include

begin_include
include|#
directive|include
file|<fs/nfs/nfsrvcache.h>
end_include

begin_include
include|#
directive|include
file|<fs/nfs/nfsrvstate.h>
end_include

begin_include
include|#
directive|include
file|<fs/nfs/xdr_subs.h>
end_include

begin_include
include|#
directive|include
file|<fs/nfs/nfscl.h>
end_include

begin_include
include|#
directive|include
file|<nfsclient/nfsargs.h>
end_include

begin_include
include|#
directive|include
file|<fs/nfsclient/nfsmount.h>
end_include

begin_comment
comment|/*  * Just to keep nfs_var.h happy.  */
end_comment

begin_struct
struct|struct
name|nfs_vattr
block|{
name|int
name|junk
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfsvattr
block|{
name|struct
name|vattr
name|na_vattr
decl_stmt|;
name|nfsattrbit_t
name|na_suppattr
decl_stmt|;
name|u_int32_t
name|na_mntonfileno
decl_stmt|;
name|u_int64_t
name|na_filesid
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|na_type
value|na_vattr.va_type
end_define

begin_define
define|#
directive|define
name|na_mode
value|na_vattr.va_mode
end_define

begin_define
define|#
directive|define
name|na_nlink
value|na_vattr.va_nlink
end_define

begin_define
define|#
directive|define
name|na_uid
value|na_vattr.va_uid
end_define

begin_define
define|#
directive|define
name|na_gid
value|na_vattr.va_gid
end_define

begin_define
define|#
directive|define
name|na_fsid
value|na_vattr.va_fsid
end_define

begin_define
define|#
directive|define
name|na_fileid
value|na_vattr.va_fileid
end_define

begin_define
define|#
directive|define
name|na_size
value|na_vattr.va_size
end_define

begin_define
define|#
directive|define
name|na_blocksize
value|na_vattr.va_blocksize
end_define

begin_define
define|#
directive|define
name|na_atime
value|na_vattr.va_atime
end_define

begin_define
define|#
directive|define
name|na_mtime
value|na_vattr.va_mtime
end_define

begin_define
define|#
directive|define
name|na_ctime
value|na_vattr.va_ctime
end_define

begin_define
define|#
directive|define
name|na_gen
value|na_vattr.va_gen
end_define

begin_define
define|#
directive|define
name|na_flags
value|na_vattr.va_flags
end_define

begin_define
define|#
directive|define
name|na_rdev
value|na_vattr.va_rdev
end_define

begin_define
define|#
directive|define
name|na_bytes
value|na_vattr.va_bytes
end_define

begin_define
define|#
directive|define
name|na_filerev
value|na_vattr.va_filerev
end_define

begin_define
define|#
directive|define
name|na_vaflags
value|na_vattr.va_vaflags
end_define

begin_include
include|#
directive|include
file|<fs/nfsclient/nfsnode.h>
end_include

begin_comment
comment|/*  * This is the header structure used for the lists, etc. (It has the  * above record in it.  */
end_comment

begin_struct
struct|struct
name|nfsrv_stablefirst
block|{
name|LIST_HEAD
argument_list|(
argument_list|,
argument|nfsrv_stable
argument_list|)
name|nsf_head
expr_stmt|;
comment|/* Head of nfsrv_stable list */
name|time_t
name|nsf_eograce
decl_stmt|;
comment|/* Time grace period ends */
name|time_t
modifier|*
name|nsf_bootvals
decl_stmt|;
comment|/* Previous boottime values */
name|struct
name|file
modifier|*
name|nsf_fp
decl_stmt|;
comment|/* File table pointer */
name|u_char
name|nsf_flags
decl_stmt|;
comment|/* NFSNSF_ flags */
name|struct
name|nfsf_rec
name|nsf_rec
decl_stmt|;
comment|/* and above first record */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nsf_lease
value|nsf_rec.lease
end_define

begin_define
define|#
directive|define
name|nsf_numboots
value|nsf_rec.numboots
end_define

begin_comment
comment|/* NFSNSF_xxx flags */
end_comment

begin_define
define|#
directive|define
name|NFSNSF_UPDATEDONE
value|0x01
end_define

begin_define
define|#
directive|define
name|NFSNSF_GRACEOVER
value|0x02
end_define

begin_define
define|#
directive|define
name|NFSNSF_NEEDLOCK
value|0x04
end_define

begin_define
define|#
directive|define
name|NFSNSF_EXPIREDCLIENT
value|0x08
end_define

begin_define
define|#
directive|define
name|NFSNSF_NOOPENS
value|0x10
end_define

begin_define
define|#
directive|define
name|NFSNSF_OK
value|0x20
end_define

begin_comment
comment|/*  * Maximum number of boot times allowed in record. Although there is  * really no need for a fixed upper bound, this serves as a sanity check  * for a corrupted file.  */
end_comment

begin_define
define|#
directive|define
name|NFSNSF_MAXNUMBOOTS
value|10000
end_define

begin_comment
comment|/*  * This structure defines the other records in the file. The  * nst_client array is actually the size of the client string name.  */
end_comment

begin_struct
struct|struct
name|nfst_rec
block|{
name|u_int16_t
name|len
decl_stmt|;
name|u_char
name|flag
decl_stmt|;
name|u_char
name|client
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* and the values for flag */
end_comment

begin_define
define|#
directive|define
name|NFSNST_NEWSTATE
value|0x1
end_define

begin_define
define|#
directive|define
name|NFSNST_REVOKE
value|0x2
end_define

begin_define
define|#
directive|define
name|NFSNST_GOTSTATE
value|0x4
end_define

begin_comment
comment|/*  * This structure is linked onto nfsrv_stablefirst for the duration of  * reclaim.  */
end_comment

begin_struct
struct|struct
name|nfsrv_stable
block|{
name|LIST_ENTRY
argument_list|(
argument|nfsrv_stable
argument_list|)
name|nst_list
expr_stmt|;
name|struct
name|nfsclient
modifier|*
name|nst_clp
decl_stmt|;
name|struct
name|nfst_rec
name|nst_rec
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nst_timestamp
value|nst_rec.timestamp
end_define

begin_define
define|#
directive|define
name|nst_len
value|nst_rec.len
end_define

begin_define
define|#
directive|define
name|nst_flag
value|nst_rec.flag
end_define

begin_define
define|#
directive|define
name|nst_client
value|nst_rec.client
end_define

begin_comment
comment|/*  * At some point the server will run out of kernel storage for  * state structures. For FreeBSD5.2, this results in a panic  * kmem_map is full. It happens at well over 1000000 opens plus  * locks on a PIII-800 with 256Mbytes, so that is where I've set  * the limit. If your server panics due to too many opens/locks,  * decrease the size of NFSRV_V4STATELIMIT. If you find the server  * returning NFS4ERR_RESOURCE a lot and have lots of memory, try  * increasing it.  */
end_comment

begin_define
define|#
directive|define
name|NFSRV_V4STATELIMIT
value|500000
end_define

begin_comment
comment|/* Max # of Opens + Locks */
end_comment

begin_comment
comment|/*  * The type required differs with BSDen (just the second arg).  */
end_comment

begin_function_decl
name|void
name|nfsrvd_rcv
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Macros for handling socket addresses. (Hopefully this makes the code  * more portable, since I've noticed some 'BSD don't have sockaddrs in  * mbufs any more.)  */
end_comment

begin_define
define|#
directive|define
name|NFSSOCKADDR
parameter_list|(
name|a
parameter_list|,
name|t
parameter_list|)
value|((t)(a))
end_define

begin_define
define|#
directive|define
name|NFSSOCKADDRALLOC
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\ 	MALLOC((a), struct sockaddr *, sizeof (struct sockaddr), \ 	    M_SONAME, M_WAITOK); 				\ 	NFSBZERO((a), sizeof (struct sockaddr)); 		\     } while (0)
end_define

begin_define
define|#
directive|define
name|NFSSOCKADDRSIZE
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|((a)->sa_len = (s))
end_define

begin_define
define|#
directive|define
name|NFSSOCKADDRFREE
parameter_list|(
name|a
parameter_list|)
define|\
value|do { 							\ 		if (a) 						\ 			FREE((caddr_t)(a), M_SONAME); 		\ 	} while (0)
end_define

begin_comment
comment|/*  * These should be defined as a process or thread structure, as required  * for signal handling, etc.  */
end_comment

begin_define
define|#
directive|define
name|NFSNEWCRED
parameter_list|(
name|c
parameter_list|)
value|(crdup(c))
end_define

begin_define
define|#
directive|define
name|NFSPROCCRED
parameter_list|(
name|p
parameter_list|)
value|((p)->td_ucred)
end_define

begin_define
define|#
directive|define
name|NFSFREECRED
parameter_list|(
name|c
parameter_list|)
value|(crfree(c))
end_define

begin_define
define|#
directive|define
name|NFSUIOPROC
parameter_list|(
name|u
parameter_list|,
name|p
parameter_list|)
value|((u)->uio_td = NULL)
end_define

begin_define
define|#
directive|define
name|NFSPROCP
parameter_list|(
name|p
parameter_list|)
value|((p)->td_proc)
end_define

begin_comment
comment|/*  * Define these so that cn_hash and its length is ignored.  */
end_comment

begin_define
define|#
directive|define
name|NFSCNHASHZERO
parameter_list|(
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NFSCNHASH
parameter_list|(
name|c
parameter_list|,
name|v
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NCHNAMLEN
value|9999999
end_define

begin_comment
comment|/*  * These macros are defined to initialize and set the timer routine.  */
end_comment

begin_define
define|#
directive|define
name|NFS_TIMERINIT
define|\
value|newnfs_timer(NULL)
end_define

begin_comment
comment|/*  * Handle SMP stuff:  */
end_comment

begin_define
define|#
directive|define
name|NFSSTATESPINLOCK
value|extern struct mtx nfs_state_mutex
end_define

begin_define
define|#
directive|define
name|NFSLOCKSTATE
parameter_list|()
value|mtx_lock(&nfs_state_mutex)
end_define

begin_define
define|#
directive|define
name|NFSUNLOCKSTATE
parameter_list|()
value|mtx_unlock(&nfs_state_mutex)
end_define

begin_define
define|#
directive|define
name|NFSSTATEMUTEXPTR
value|(&nfs_state_mutex)
end_define

begin_define
define|#
directive|define
name|NFSREQSPINLOCK
value|extern struct mtx nfs_req_mutex
end_define

begin_define
define|#
directive|define
name|NFSLOCKREQ
parameter_list|()
value|mtx_lock(&nfs_req_mutex)
end_define

begin_define
define|#
directive|define
name|NFSUNLOCKREQ
parameter_list|()
value|mtx_unlock(&nfs_req_mutex)
end_define

begin_define
define|#
directive|define
name|NFSSOCKMUTEX
value|extern struct mtx nfs_slock_mutex
end_define

begin_define
define|#
directive|define
name|NFSSOCKMUTEXPTR
value|(&nfs_slock_mutex)
end_define

begin_define
define|#
directive|define
name|NFSLOCKSOCK
parameter_list|()
value|mtx_lock(&nfs_slock_mutex)
end_define

begin_define
define|#
directive|define
name|NFSUNLOCKSOCK
parameter_list|()
value|mtx_unlock(&nfs_slock_mutex)
end_define

begin_define
define|#
directive|define
name|NFSNAMEIDMUTEX
value|extern struct mtx nfs_nameid_mutex
end_define

begin_define
define|#
directive|define
name|NFSLOCKNAMEID
parameter_list|()
value|mtx_lock(&nfs_nameid_mutex)
end_define

begin_define
define|#
directive|define
name|NFSUNLOCKNAMEID
parameter_list|()
value|mtx_unlock(&nfs_nameid_mutex)
end_define

begin_define
define|#
directive|define
name|NFSNAMEIDREQUIRED
parameter_list|()
value|mtx_assert(&nfs_nameid_mutex, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|NFSCLSTATEMUTEX
value|extern struct mtx nfs_clstate_mutex
end_define

begin_define
define|#
directive|define
name|NFSCLSTATEMUTEXPTR
value|(&nfs_clstate_mutex)
end_define

begin_define
define|#
directive|define
name|NFSLOCKCLSTATE
parameter_list|()
value|mtx_lock(&nfs_clstate_mutex)
end_define

begin_define
define|#
directive|define
name|NFSUNLOCKCLSTATE
parameter_list|()
value|mtx_unlock(&nfs_clstate_mutex)
end_define

begin_define
define|#
directive|define
name|NFSDLOCKMUTEX
value|extern struct mtx newnfsd_mtx
end_define

begin_define
define|#
directive|define
name|NFSDLOCKMUTEXPTR
value|(&newnfsd_mtx)
end_define

begin_define
define|#
directive|define
name|NFSD_LOCK
parameter_list|()
value|mtx_lock(&newnfsd_mtx)
end_define

begin_define
define|#
directive|define
name|NFSD_UNLOCK
parameter_list|()
value|mtx_unlock(&newnfsd_mtx)
end_define

begin_define
define|#
directive|define
name|NFSD_LOCK_ASSERT
parameter_list|()
value|mtx_assert(&newnfsd_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|NFSD_UNLOCK_ASSERT
parameter_list|()
value|mtx_assert(&newnfsd_mtx, MA_NOTOWNED)
end_define

begin_define
define|#
directive|define
name|NFSV4ROOTLOCKMUTEX
value|extern struct mtx nfs_v4root_mutex
end_define

begin_define
define|#
directive|define
name|NFSV4ROOTLOCKMUTEXPTR
value|(&nfs_v4root_mutex)
end_define

begin_define
define|#
directive|define
name|NFSLOCKV4ROOTMUTEX
parameter_list|()
value|mtx_lock(&nfs_v4root_mutex)
end_define

begin_define
define|#
directive|define
name|NFSUNLOCKV4ROOTMUTEX
parameter_list|()
value|mtx_unlock(&nfs_v4root_mutex)
end_define

begin_define
define|#
directive|define
name|NFSLOCKNODE
parameter_list|(
name|n
parameter_list|)
value|mtx_lock(&((n)->n_mtx))
end_define

begin_define
define|#
directive|define
name|NFSUNLOCKNODE
parameter_list|(
name|n
parameter_list|)
value|mtx_unlock(&((n)->n_mtx))
end_define

begin_define
define|#
directive|define
name|NFSLOCKMNT
parameter_list|(
name|m
parameter_list|)
value|mtx_lock(&((m)->nm_mtx))
end_define

begin_define
define|#
directive|define
name|NFSUNLOCKMNT
parameter_list|(
name|m
parameter_list|)
value|mtx_unlock(&((m)->nm_mtx))
end_define

begin_define
define|#
directive|define
name|NFSLOCKREQUEST
parameter_list|(
name|r
parameter_list|)
value|mtx_lock(&((r)->r_mtx))
end_define

begin_define
define|#
directive|define
name|NFSUNLOCKREQUEST
parameter_list|(
name|r
parameter_list|)
value|mtx_unlock(&((r)->r_mtx))
end_define

begin_define
define|#
directive|define
name|NFSPROCLISTLOCK
parameter_list|()
value|sx_slock(&allproc_lock)
end_define

begin_define
define|#
directive|define
name|NFSPROCLISTUNLOCK
parameter_list|()
value|sx_sunlock(&allproc_lock)
end_define

begin_define
define|#
directive|define
name|NFSLOCKSOCKREQ
parameter_list|(
name|r
parameter_list|)
value|mtx_lock(&((r)->nr_mtx))
end_define

begin_define
define|#
directive|define
name|NFSUNLOCKSOCKREQ
parameter_list|(
name|r
parameter_list|)
value|mtx_unlock(&((r)->nr_mtx))
end_define

begin_define
define|#
directive|define
name|NFSLOCKDS
parameter_list|(
name|d
parameter_list|)
value|mtx_lock(&((d)->nfsclds_mtx))
end_define

begin_define
define|#
directive|define
name|NFSUNLOCKDS
parameter_list|(
name|d
parameter_list|)
value|mtx_unlock(&((d)->nfsclds_mtx))
end_define

begin_define
define|#
directive|define
name|NFSSESSIONMUTEXPTR
parameter_list|(
name|s
parameter_list|)
value|(&((s)->mtx))
end_define

begin_define
define|#
directive|define
name|NFSLOCKSESSION
parameter_list|(
name|s
parameter_list|)
value|mtx_lock(&((s)->mtx))
end_define

begin_define
define|#
directive|define
name|NFSUNLOCKSESSION
parameter_list|(
name|s
parameter_list|)
value|mtx_unlock(&((s)->mtx))
end_define

begin_comment
comment|/*  * Use these macros to initialize/free a mutex.  */
end_comment

begin_define
define|#
directive|define
name|NFSINITSOCKMUTEX
parameter_list|(
name|m
parameter_list|)
value|mtx_init((m), "nfssock", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|NFSFREEMUTEX
parameter_list|(
name|m
parameter_list|)
value|mtx_destroy((m))
end_define

begin_function_decl
name|int
name|nfsmsleep
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * And weird vm stuff in the nfs server.  */
end_comment

begin_define
define|#
directive|define
name|PDIRUNLOCK
value|0x0
end_define

begin_define
define|#
directive|define
name|MAX_COMMIT_COUNT
value|(1024 * 1024)
end_define

begin_comment
comment|/*  * Define these to handle the type of va_rdev.  */
end_comment

begin_define
define|#
directive|define
name|NFSMAKEDEV
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
value|makedev((m), (n))
end_define

begin_define
define|#
directive|define
name|NFSMAJOR
parameter_list|(
name|d
parameter_list|)
value|major(d)
end_define

begin_define
define|#
directive|define
name|NFSMINOR
parameter_list|(
name|d
parameter_list|)
value|minor(d)
end_define

begin_comment
comment|/*  * Define this to be the macro that returns the minimum size required  * for a directory entry.  */
end_comment

begin_define
define|#
directive|define
name|DIRENT_SIZE
parameter_list|(
name|dp
parameter_list|)
value|GENERIC_DIRSIZ(dp)
end_define

begin_comment
comment|/*  * The vnode tag for nfsv4root.  */
end_comment

begin_define
define|#
directive|define
name|VT_NFSV4ROOT
value|"nfsv4root"
end_define

begin_comment
comment|/*  * Define whatever it takes to do a vn_rdwr().  */
end_comment

begin_define
define|#
directive|define
name|NFSD_RDWR
parameter_list|(
name|r
parameter_list|,
name|v
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|,
name|o
parameter_list|,
name|s
parameter_list|,
name|i
parameter_list|,
name|c
parameter_list|,
name|a
parameter_list|,
name|p
parameter_list|)
define|\
value|vn_rdwr((r), (v), (b), (l), (o), (s), (i), (c), NULL, (a), (p))
end_define

begin_comment
comment|/*  * Macros for handling memory for different BSDen.  * NFSBCOPY(src, dst, len) - copies len bytes, non-overlapping  * NFSOVBCOPY(src, dst, len) - ditto, but data areas might overlap  * NFSBCMP(cp1, cp2, len) - compare len bytes, return 0 if same  * NFSBZERO(cp, len) - set len bytes to 0x0  */
end_comment

begin_define
define|#
directive|define
name|NFSBCOPY
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|l
parameter_list|)
value|bcopy((s), (d), (l))
end_define

begin_define
define|#
directive|define
name|NFSOVBCOPY
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|l
parameter_list|)
value|ovbcopy((s), (d), (l))
end_define

begin_define
define|#
directive|define
name|NFSBCMP
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|l
parameter_list|)
value|bcmp((s), (d), (l))
end_define

begin_define
define|#
directive|define
name|NFSBZERO
parameter_list|(
name|s
parameter_list|,
name|l
parameter_list|)
value|bzero((s), (l))
end_define

begin_comment
comment|/*  * Some queue.h files don't have these dfined in them.  */
end_comment

begin_define
define|#
directive|define
name|LIST_END
parameter_list|(
name|head
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|SLIST_END
parameter_list|(
name|head
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|TAILQ_END
parameter_list|(
name|head
parameter_list|)
value|NULL
end_define

begin_comment
comment|/*  * This must be defined to be a global variable that increments once  * per second, but never stops or goes backwards, even when a "date"  * command changes the TOD clock. It is used for delta times for  * leases, etc.  */
end_comment

begin_define
define|#
directive|define
name|NFSD_MONOSEC
value|time_uptime
end_define

begin_comment
comment|/*  * Declare the malloc types.  */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSRVCACHE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSDCLIENT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSDSTATE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSDLOCK
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSDLOCKFILE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSSTRING
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSUSERGROUP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSDREQ
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSFH
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSCLOWNER
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSCLOPEN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSCLDELEG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSCLCLIENT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSCLLOCKOWNER
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSCLLOCK
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSDIROFF
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSV4NODE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSDIRECTIO
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSMNT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSDROLLBACK
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSLAYOUT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSFLAYOUT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSDEVINFO
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSSOCKREQ
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSCLDS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSLAYRECALL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NEWNFSDSESSION
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|M_NFSRVCACHE
value|M_NEWNFSRVCACHE
end_define

begin_define
define|#
directive|define
name|M_NFSDCLIENT
value|M_NEWNFSDCLIENT
end_define

begin_define
define|#
directive|define
name|M_NFSDSTATE
value|M_NEWNFSDSTATE
end_define

begin_define
define|#
directive|define
name|M_NFSDLOCK
value|M_NEWNFSDLOCK
end_define

begin_define
define|#
directive|define
name|M_NFSDLOCKFILE
value|M_NEWNFSDLOCKFILE
end_define

begin_define
define|#
directive|define
name|M_NFSSTRING
value|M_NEWNFSSTRING
end_define

begin_define
define|#
directive|define
name|M_NFSUSERGROUP
value|M_NEWNFSUSERGROUP
end_define

begin_define
define|#
directive|define
name|M_NFSDREQ
value|M_NEWNFSDREQ
end_define

begin_define
define|#
directive|define
name|M_NFSFH
value|M_NEWNFSFH
end_define

begin_define
define|#
directive|define
name|M_NFSCLOWNER
value|M_NEWNFSCLOWNER
end_define

begin_define
define|#
directive|define
name|M_NFSCLOPEN
value|M_NEWNFSCLOPEN
end_define

begin_define
define|#
directive|define
name|M_NFSCLDELEG
value|M_NEWNFSCLDELEG
end_define

begin_define
define|#
directive|define
name|M_NFSCLCLIENT
value|M_NEWNFSCLCLIENT
end_define

begin_define
define|#
directive|define
name|M_NFSCLLOCKOWNER
value|M_NEWNFSCLLOCKOWNER
end_define

begin_define
define|#
directive|define
name|M_NFSCLLOCK
value|M_NEWNFSCLLOCK
end_define

begin_define
define|#
directive|define
name|M_NFSDIROFF
value|M_NEWNFSDIROFF
end_define

begin_define
define|#
directive|define
name|M_NFSV4NODE
value|M_NEWNFSV4NODE
end_define

begin_define
define|#
directive|define
name|M_NFSDIRECTIO
value|M_NEWNFSDIRECTIO
end_define

begin_define
define|#
directive|define
name|M_NFSDROLLBACK
value|M_NEWNFSDROLLBACK
end_define

begin_define
define|#
directive|define
name|M_NFSLAYOUT
value|M_NEWNFSLAYOUT
end_define

begin_define
define|#
directive|define
name|M_NFSFLAYOUT
value|M_NEWNFSFLAYOUT
end_define

begin_define
define|#
directive|define
name|M_NFSDEVINFO
value|M_NEWNFSDEVINFO
end_define

begin_define
define|#
directive|define
name|M_NFSSOCKREQ
value|M_NEWNFSSOCKREQ
end_define

begin_define
define|#
directive|define
name|M_NFSCLDS
value|M_NEWNFSCLDS
end_define

begin_define
define|#
directive|define
name|M_NFSLAYRECALL
value|M_NEWNFSLAYRECALL
end_define

begin_define
define|#
directive|define
name|M_NFSDSESSION
value|M_NEWNFSDSESSION
end_define

begin_define
define|#
directive|define
name|NFSINT_SIGMASK
parameter_list|(
name|set
parameter_list|)
define|\
value|(SIGISMEMBER(set, SIGINT) || SIGISMEMBER(set, SIGTERM) ||	\ 	 SIGISMEMBER(set, SIGHUP) || SIGISMEMBER(set, SIGKILL) ||	\ 	 SIGISMEMBER(set, SIGQUIT))
end_define

begin_comment
comment|/*  * Convert a quota block count to byte count.  */
end_comment

begin_define
define|#
directive|define
name|NFSQUOTABLKTOBYTE
parameter_list|(
name|q
parameter_list|,
name|b
parameter_list|)
value|(q) *= (b)
end_define

begin_comment
comment|/*  * Define this as the largest file size supported. (It should probably  * be available via a VFS_xxx Op, but it isn't.  */
end_comment

begin_define
define|#
directive|define
name|NFSRV_MAXFILESIZE
value|((u_int64_t)0x800000000000)
end_define

begin_comment
comment|/*  * Set this macro to index() or strchr(), whichever is supported.  */
end_comment

begin_define
define|#
directive|define
name|STRCHR
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|strchr((s), (c))
end_define

begin_comment
comment|/*  * Set the n_time in the client write rpc, as required.  */
end_comment

begin_define
define|#
directive|define
name|NFSWRITERPC_SETTIME
parameter_list|(
name|w
parameter_list|,
name|n
parameter_list|,
name|a
parameter_list|,
name|v4
parameter_list|)
define|\
value|do {								\ 		if (w) {						\ 			mtx_lock(&((n)->n_mtx));			\ 			(n)->n_mtime = (a)->na_mtime;			\ 			if (v4)						\ 				(n)->n_change = (a)->na_filerev;	\ 			mtx_unlock(&((n)->n_mtx));			\ 		}							\ 	} while (0)
end_define

begin_comment
comment|/*  * Fake value, just to make the client work.  */
end_comment

begin_define
define|#
directive|define
name|NFS_LATTR_NOSHRINK
value|1
end_define

begin_comment
comment|/*  * Prototypes for functions where the arguments vary for different ports.  */
end_comment

begin_function_decl
name|int
name|nfscl_loadattrcache
parameter_list|(
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|,
name|struct
name|nfsvattr
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|newnfs_realign
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * If the port runs on an SMP box that can enforce Atomic ops with low  * overheads, define these as atomic increments/decrements. If not,  * don't worry about it, since these are used for stats that can be  * "out by one" without disastrous consequences.  */
end_comment

begin_define
define|#
directive|define
name|NFSINCRGLOBAL
parameter_list|(
name|a
parameter_list|)
value|((a)++)
end_define

begin_comment
comment|/*  * Assorted funky stuff to make things work under Darwin8.  */
end_comment

begin_comment
comment|/*  * These macros checks for a field in vattr being set.  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRISSET
parameter_list|(
name|t
parameter_list|,
name|v
parameter_list|,
name|a
parameter_list|)
value|((v)->a != (t)VNOVAL)
end_define

begin_define
define|#
directive|define
name|NFSATTRISSETTIME
parameter_list|(
name|v
parameter_list|,
name|a
parameter_list|)
value|((v)->a.tv_sec != VNOVAL)
end_define

begin_comment
comment|/*  * Manipulate mount flags.  */
end_comment

begin_define
define|#
directive|define
name|NFSSTA_HASWRITEVERF
value|0x00040000
end_define

begin_comment
comment|/* Has write verifier */
end_comment

begin_define
define|#
directive|define
name|NFSSTA_GOTFSINFO
value|0x00100000
end_define

begin_comment
comment|/* Got the fsinfo */
end_comment

begin_define
define|#
directive|define
name|NFSSTA_OPENMODE
value|0x00200000
end_define

begin_comment
comment|/* Must use correct open mode */
end_comment

begin_define
define|#
directive|define
name|NFSSTA_NOLAYOUTCOMMIT
value|0x04000000
end_define

begin_comment
comment|/* Don't do LayoutCommit */
end_comment

begin_define
define|#
directive|define
name|NFSSTA_SESSPERSIST
value|0x08000000
end_define

begin_comment
comment|/* Has a persistent session */
end_comment

begin_define
define|#
directive|define
name|NFSSTA_TIMEO
value|0x10000000
end_define

begin_comment
comment|/* Experiencing a timeout */
end_comment

begin_define
define|#
directive|define
name|NFSSTA_LOCKTIMEO
value|0x20000000
end_define

begin_comment
comment|/* Experiencing a lockd timeout */
end_comment

begin_define
define|#
directive|define
name|NFSSTA_HASSETFSID
value|0x40000000
end_define

begin_comment
comment|/* Has set the fsid */
end_comment

begin_define
define|#
directive|define
name|NFSSTA_PNFS
value|0x80000000
end_define

begin_comment
comment|/* pNFS is enabled */
end_comment

begin_define
define|#
directive|define
name|NFSHASNFSV3
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_flag& NFSMNT_NFSV3)
end_define

begin_define
define|#
directive|define
name|NFSHASNFSV4
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_flag& NFSMNT_NFSV4)
end_define

begin_define
define|#
directive|define
name|NFSHASNFSV4N
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_minorvers> 0)
end_define

begin_define
define|#
directive|define
name|NFSHASNFSV3OR4
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_flag& (NFSMNT_NFSV3 | NFSMNT_NFSV4))
end_define

begin_define
define|#
directive|define
name|NFSHASGOTFSINFO
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_state& NFSSTA_GOTFSINFO)
end_define

begin_define
define|#
directive|define
name|NFSHASHASSETFSID
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_state& NFSSTA_HASSETFSID)
end_define

begin_define
define|#
directive|define
name|NFSHASSTRICT3530
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_flag& NFSMNT_STRICT3530)
end_define

begin_define
define|#
directive|define
name|NFSHASWRITEVERF
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_state& NFSSTA_HASWRITEVERF)
end_define

begin_define
define|#
directive|define
name|NFSHASINT
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_flag& NFSMNT_INT)
end_define

begin_define
define|#
directive|define
name|NFSHASSOFT
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_flag& NFSMNT_SOFT)
end_define

begin_define
define|#
directive|define
name|NFSHASINTORSOFT
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_flag& (NFSMNT_INT | NFSMNT_SOFT))
end_define

begin_define
define|#
directive|define
name|NFSHASDUMBTIMR
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_flag& NFSMNT_DUMBTIMR)
end_define

begin_define
define|#
directive|define
name|NFSHASNOCONN
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_flag& NFSMNT_MNTD)
end_define

begin_define
define|#
directive|define
name|NFSHASKERB
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_flag& NFSMNT_KERB)
end_define

begin_define
define|#
directive|define
name|NFSHASALLGSSNAME
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_flag& NFSMNT_ALLGSSNAME)
end_define

begin_define
define|#
directive|define
name|NFSHASINTEGRITY
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_flag& NFSMNT_INTEGRITY)
end_define

begin_define
define|#
directive|define
name|NFSHASPRIVACY
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_flag& NFSMNT_PRIVACY)
end_define

begin_define
define|#
directive|define
name|NFSSETWRITEVERF
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_state |= NFSSTA_HASWRITEVERF)
end_define

begin_define
define|#
directive|define
name|NFSSETHASSETFSID
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_state |= NFSSTA_HASSETFSID)
end_define

begin_define
define|#
directive|define
name|NFSHASPNFSOPT
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_flag& NFSMNT_PNFS)
end_define

begin_define
define|#
directive|define
name|NFSHASNOLAYOUTCOMMIT
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_state& NFSSTA_NOLAYOUTCOMMIT)
end_define

begin_define
define|#
directive|define
name|NFSHASSESSPERSIST
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_state& NFSSTA_SESSPERSIST)
end_define

begin_define
define|#
directive|define
name|NFSHASPNFS
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_state& NFSSTA_PNFS)
end_define

begin_define
define|#
directive|define
name|NFSHASOPENMODE
parameter_list|(
name|n
parameter_list|)
value|((n)->nm_state& NFSSTA_OPENMODE)
end_define

begin_define
define|#
directive|define
name|NFSHASONEOPENOWN
parameter_list|(
name|n
parameter_list|)
value|(((n)->nm_flag& NFSMNT_ONEOPENOWN) != 0&&	\ 				    (n)->nm_minorvers> 0)
end_define

begin_comment
comment|/*  * Gets the stats field out of the mount structure.  */
end_comment

begin_define
define|#
directive|define
name|vfs_statfs
parameter_list|(
name|m
parameter_list|)
value|(&((m)->mnt_stat))
end_define

begin_comment
comment|/*  * Set boottime.  */
end_comment

begin_define
define|#
directive|define
name|NFSSETBOOTTIME
parameter_list|(
name|b
parameter_list|)
value|(getboottime(&b))
end_define

begin_comment
comment|/*  * The size of directory blocks in the buffer cache.  * MUST BE in the range of PAGE_SIZE<= NFS_DIRBLKSIZ<= MAXBSIZE!!  */
end_comment

begin_define
define|#
directive|define
name|NFS_DIRBLKSIZ
value|(16 * DIRBLKSIZ)
end_define

begin_comment
comment|/* Must be a multiple of DIRBLKSIZ */
end_comment

begin_comment
comment|/*  * Define these macros to access mnt_flag fields.  */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RDONLY
parameter_list|(
name|m
parameter_list|)
value|((m)->mnt_flag& MNT_RDONLY)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Define a structure similar to ufs_args for use in exporting the V4 root.  */
end_comment

begin_struct
struct|struct
name|nfsex_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
name|struct
name|export_args
name|export
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * These export flags should be defined, but there are no bits left.  * Maybe a separate mnt_exflag field could be added or the mnt_flag  * field increased to 64 bits?  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MNT_EXSTRICTACCESS
end_ifndef

begin_define
define|#
directive|define
name|MNT_EXSTRICTACCESS
value|0x0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MNT_EXV4ONLY
end_ifndef

begin_define
define|#
directive|define
name|MNT_EXV4ONLY
value|0x0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Define this to invalidate the attribute cache for the nfs node.  */
end_comment

begin_define
define|#
directive|define
name|NFSINVALATTRCACHE
parameter_list|(
name|n
parameter_list|)
value|((n)->n_attrstamp = 0)
end_define

begin_comment
comment|/* Used for FreeBSD only */
end_comment

begin_function_decl
name|void
name|nfsd_mntinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Define these for vnode lock/unlock ops.  *  * These are good abstractions to macro out, so that they can be added to  * later, for debugging or stats, etc.  */
end_comment

begin_define
define|#
directive|define
name|NFSVOPLOCK
parameter_list|(
name|v
parameter_list|,
name|f
parameter_list|)
value|vn_lock((v), (f))
end_define

begin_define
define|#
directive|define
name|NFSVOPUNLOCK
parameter_list|(
name|v
parameter_list|,
name|f
parameter_list|)
value|VOP_UNLOCK((v), (f))
end_define

begin_define
define|#
directive|define
name|NFSVOPISLOCKED
parameter_list|(
name|v
parameter_list|)
value|VOP_ISLOCKED((v))
end_define

begin_comment
comment|/*  * Define ncl_hash().  */
end_comment

begin_define
define|#
directive|define
name|ncl_hash
parameter_list|(
name|f
parameter_list|,
name|l
parameter_list|)
value|(fnv_32_buf((f), (l), FNV1_32_INIT))
end_define

begin_function_decl
name|int
name|newnfs_iosize
parameter_list|(
name|struct
name|nfsmount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|newnfs_vncmpf
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_MINDIRATTRTIMO
end_ifndef

begin_define
define|#
directive|define
name|NFS_MINDIRATTRTIMO
value|3
end_define

begin_comment
comment|/* VDIR attrib cache timeout in sec */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_MAXDIRATTRTIMO
end_ifndef

begin_define
define|#
directive|define
name|NFS_MAXDIRATTRTIMO
value|60
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Nfs outstanding request list element  */
end_comment

begin_struct
struct|struct
name|nfsreq
block|{
name|TAILQ_ENTRY
argument_list|(
argument|nfsreq
argument_list|)
name|r_chain
expr_stmt|;
name|u_int32_t
name|r_flags
decl_stmt|;
comment|/* flags on request, see below */
name|struct
name|nfsmount
modifier|*
name|r_nmp
decl_stmt|;
comment|/* Client mnt ptr */
name|struct
name|mtx
name|r_mtx
decl_stmt|;
comment|/* Mutex lock for this structure */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_MAXBSIZE
end_ifndef

begin_define
define|#
directive|define
name|NFS_MAXBSIZE
value|MAXBCACHEBUF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This macro checks to see if issuing of delegations is allowed for this  * vnode.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VV_DISABLEDELEG
end_ifdef

begin_define
define|#
directive|define
name|NFSVNO_DELEGOK
parameter_list|(
name|v
parameter_list|)
define|\
value|((v) == NULL || ((v)->v_vflag& VV_DISABLEDELEG) == 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NFSVNO_DELEGOK
parameter_list|(
name|v
parameter_list|)
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Name used by getnewvnode() to describe filesystem, "nfs".  * For performance reasons it is useful to have the same string  * used in both places that call getnewvnode().  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|nfs_vnode_tag
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NFS_NFSPORT_H */
end_comment

end_unit

