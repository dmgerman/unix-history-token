begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFSPROTO_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFSPROTO_H_
end_define

begin_comment
comment|/*  * nfs definitions as per the Version 2, 3 and 4 specs  */
end_comment

begin_comment
comment|/*  * Constants as defined in the NFS Version 2, 3 and 4 specs.  * "NFS: Network File System Protocol Specification" RFC1094  * and in the "NFS: Network File System Version 3 Protocol  * Specification"  */
end_comment

begin_define
define|#
directive|define
name|NFS_PORT
value|2049
end_define

begin_define
define|#
directive|define
name|NFS_PROG
value|100003
end_define

begin_define
define|#
directive|define
name|NFS_CALLBCKPROG
value|0x40000000
end_define

begin_comment
comment|/* V4 only */
end_comment

begin_define
define|#
directive|define
name|NFS_VER2
value|2
end_define

begin_define
define|#
directive|define
name|NFS_VER3
value|3
end_define

begin_define
define|#
directive|define
name|NFS_VER4
value|4
end_define

begin_define
define|#
directive|define
name|NFS_V2MAXDATA
value|8192
end_define

begin_define
define|#
directive|define
name|NFS_MAXDGRAMDATA
value|16384
end_define

begin_define
define|#
directive|define
name|NFS_MAXPATHLEN
value|1024
end_define

begin_define
define|#
directive|define
name|NFS_MAXNAMLEN
value|255
end_define

begin_comment
comment|/*  * Calculating the maximum XDR overhead for an NFS RPC isn't easy.  * NFS_MAXPKTHDR is antiquated and assumes AUTH_SYS over UDP.  * NFS_MAXXDR should be sufficient for all NFS versions over TCP.  * It includes:  * - Maximum RPC message header. It can include 2 400byte authenticators plus  *   a machine name of unlimited length, although it is usually relatively  *   small.  * - XDR overheads for the NFSv4 compound. This can include Owner and  *   Owner_group strings, which are usually fairly small, but are allowed  *   to be up to 1024 bytes each.  * 4096 is overkill, but should always be sufficient.  */
end_comment

begin_define
define|#
directive|define
name|NFS_MAXPKTHDR
value|404
end_define

begin_define
define|#
directive|define
name|NFS_MAXXDR
value|4096
end_define

begin_define
define|#
directive|define
name|NFS_MAXPACKET
value|(NFS_SRVMAXIO + NFS_MAXXDR)
end_define

begin_define
define|#
directive|define
name|NFS_MINPACKET
value|20
end_define

begin_define
define|#
directive|define
name|NFS_FABLKSIZE
value|512
end_define

begin_comment
comment|/* Size in bytes of a block wrt fa_blocks */
end_comment

begin_define
define|#
directive|define
name|NFSV4_MINORVERSION
value|0
end_define

begin_comment
comment|/* V4 Minor version */
end_comment

begin_define
define|#
directive|define
name|NFSV41_MINORVERSION
value|1
end_define

begin_comment
comment|/* V4 Minor version */
end_comment

begin_define
define|#
directive|define
name|NFSV4_CBVERS
value|1
end_define

begin_comment
comment|/* V4 CB Version */
end_comment

begin_define
define|#
directive|define
name|NFSV41_CBVERS
value|4
end_define

begin_comment
comment|/* V4.1 CB Version */
end_comment

begin_define
define|#
directive|define
name|NFSV4_SMALLSTR
value|50
end_define

begin_comment
comment|/* Strings small enough for stack */
end_comment

begin_comment
comment|/*  * This value isn't a fixed value in the RFCs.  * It is the maximum data size supported by NFSv3 or NFSv4 over TCP for  * the server.  It should be set to the I/O size preferred by ZFS or  * MAXBSIZE, whichever is greater.  * ZFS currently prefers 128K.  * It used to be called NFS_MAXDATA, but has been renamed to clarify that  * it refers to server side only and doesn't conflict with the NFS_MAXDATA  * defined in rpcsvc/nfs_prot.h for userland.  */
end_comment

begin_define
define|#
directive|define
name|NFS_SRVMAXIO
value|(128 * 1024)
end_define

begin_comment
comment|/* Stat numbers for rpc returns (version 2, 3 and 4) */
end_comment

begin_comment
comment|/*  * These numbers are hard-wired in the RFCs, so they can't be changed.  * The code currently assumes that the ones< 10000 are the same as  * sys/errno.h and that sys/errno.h will never go as high as 10000.  * If the value in sys/errno.h of any entry listed below is changed,  * the NFS code must be modified to do the mapping between them.  * (You can ignore NFSERR_WFLUSH, since it is never actually used.)  */
end_comment

begin_define
define|#
directive|define
name|NFSERR_OK
value|0
end_define

begin_define
define|#
directive|define
name|NFSERR_PERM
value|1
end_define

begin_define
define|#
directive|define
name|NFSERR_NOENT
value|2
end_define

begin_define
define|#
directive|define
name|NFSERR_IO
value|5
end_define

begin_define
define|#
directive|define
name|NFSERR_NXIO
value|6
end_define

begin_define
define|#
directive|define
name|NFSERR_ACCES
value|13
end_define

begin_define
define|#
directive|define
name|NFSERR_EXIST
value|17
end_define

begin_define
define|#
directive|define
name|NFSERR_XDEV
value|18
end_define

begin_comment
comment|/* Version 3, 4 only */
end_comment

begin_define
define|#
directive|define
name|NFSERR_NODEV
value|19
end_define

begin_define
define|#
directive|define
name|NFSERR_NOTDIR
value|20
end_define

begin_define
define|#
directive|define
name|NFSERR_ISDIR
value|21
end_define

begin_define
define|#
directive|define
name|NFSERR_INVAL
value|22
end_define

begin_comment
comment|/* Version 3, 4 only */
end_comment

begin_define
define|#
directive|define
name|NFSERR_FBIG
value|27
end_define

begin_define
define|#
directive|define
name|NFSERR_NOSPC
value|28
end_define

begin_define
define|#
directive|define
name|NFSERR_ROFS
value|30
end_define

begin_define
define|#
directive|define
name|NFSERR_MLINK
value|31
end_define

begin_comment
comment|/* Version 3, 4 only */
end_comment

begin_define
define|#
directive|define
name|NFSERR_NAMETOL
value|63
end_define

begin_define
define|#
directive|define
name|NFSERR_NOTEMPTY
value|66
end_define

begin_define
define|#
directive|define
name|NFSERR_DQUOT
value|69
end_define

begin_define
define|#
directive|define
name|NFSERR_STALE
value|70
end_define

begin_define
define|#
directive|define
name|NFSERR_REMOTE
value|71
end_define

begin_comment
comment|/* Version 3 only */
end_comment

begin_define
define|#
directive|define
name|NFSERR_WFLUSH
value|99
end_define

begin_comment
comment|/* Version 2 only */
end_comment

begin_define
define|#
directive|define
name|NFSERR_BADHANDLE
value|10001
end_define

begin_comment
comment|/* These are Version 3, 4 only */
end_comment

begin_define
define|#
directive|define
name|NFSERR_NOT_SYNC
value|10002
end_define

begin_comment
comment|/* Version 3 Only */
end_comment

begin_define
define|#
directive|define
name|NFSERR_BAD_COOKIE
value|10003
end_define

begin_define
define|#
directive|define
name|NFSERR_NOTSUPP
value|10004
end_define

begin_define
define|#
directive|define
name|NFSERR_TOOSMALL
value|10005
end_define

begin_define
define|#
directive|define
name|NFSERR_SERVERFAULT
value|10006
end_define

begin_define
define|#
directive|define
name|NFSERR_BADTYPE
value|10007
end_define

begin_define
define|#
directive|define
name|NFSERR_DELAY
value|10008
end_define

begin_comment
comment|/* Called NFSERR_JUKEBOX for V3 */
end_comment

begin_define
define|#
directive|define
name|NFSERR_SAME
value|10009
end_define

begin_comment
comment|/* These are Version 4 only */
end_comment

begin_define
define|#
directive|define
name|NFSERR_DENIED
value|10010
end_define

begin_define
define|#
directive|define
name|NFSERR_EXPIRED
value|10011
end_define

begin_define
define|#
directive|define
name|NFSERR_LOCKED
value|10012
end_define

begin_define
define|#
directive|define
name|NFSERR_GRACE
value|10013
end_define

begin_define
define|#
directive|define
name|NFSERR_FHEXPIRED
value|10014
end_define

begin_define
define|#
directive|define
name|NFSERR_SHAREDENIED
value|10015
end_define

begin_define
define|#
directive|define
name|NFSERR_WRONGSEC
value|10016
end_define

begin_define
define|#
directive|define
name|NFSERR_CLIDINUSE
value|10017
end_define

begin_define
define|#
directive|define
name|NFSERR_RESOURCE
value|10018
end_define

begin_define
define|#
directive|define
name|NFSERR_MOVED
value|10019
end_define

begin_define
define|#
directive|define
name|NFSERR_NOFILEHANDLE
value|10020
end_define

begin_define
define|#
directive|define
name|NFSERR_MINORVERMISMATCH
value|10021
end_define

begin_define
define|#
directive|define
name|NFSERR_STALECLIENTID
value|10022
end_define

begin_define
define|#
directive|define
name|NFSERR_STALESTATEID
value|10023
end_define

begin_define
define|#
directive|define
name|NFSERR_OLDSTATEID
value|10024
end_define

begin_define
define|#
directive|define
name|NFSERR_BADSTATEID
value|10025
end_define

begin_define
define|#
directive|define
name|NFSERR_BADSEQID
value|10026
end_define

begin_define
define|#
directive|define
name|NFSERR_NOTSAME
value|10027
end_define

begin_define
define|#
directive|define
name|NFSERR_LOCKRANGE
value|10028
end_define

begin_define
define|#
directive|define
name|NFSERR_SYMLINK
value|10029
end_define

begin_define
define|#
directive|define
name|NFSERR_RESTOREFH
value|10030
end_define

begin_define
define|#
directive|define
name|NFSERR_LEASEMOVED
value|10031
end_define

begin_define
define|#
directive|define
name|NFSERR_ATTRNOTSUPP
value|10032
end_define

begin_define
define|#
directive|define
name|NFSERR_NOGRACE
value|10033
end_define

begin_define
define|#
directive|define
name|NFSERR_RECLAIMBAD
value|10034
end_define

begin_define
define|#
directive|define
name|NFSERR_RECLAIMCONFLICT
value|10035
end_define

begin_define
define|#
directive|define
name|NFSERR_BADXDR
value|10036
end_define

begin_define
define|#
directive|define
name|NFSERR_LOCKSHELD
value|10037
end_define

begin_define
define|#
directive|define
name|NFSERR_OPENMODE
value|10038
end_define

begin_define
define|#
directive|define
name|NFSERR_BADOWNER
value|10039
end_define

begin_define
define|#
directive|define
name|NFSERR_BADCHAR
value|10040
end_define

begin_define
define|#
directive|define
name|NFSERR_BADNAME
value|10041
end_define

begin_define
define|#
directive|define
name|NFSERR_BADRANGE
value|10042
end_define

begin_define
define|#
directive|define
name|NFSERR_LOCKNOTSUPP
value|10043
end_define

begin_define
define|#
directive|define
name|NFSERR_OPILLEGAL
value|10044
end_define

begin_define
define|#
directive|define
name|NFSERR_DEADLOCK
value|10045
end_define

begin_define
define|#
directive|define
name|NFSERR_FILEOPEN
value|10046
end_define

begin_define
define|#
directive|define
name|NFSERR_ADMINREVOKED
value|10047
end_define

begin_define
define|#
directive|define
name|NFSERR_CBPATHDOWN
value|10048
end_define

begin_comment
comment|/* NFSv4.1 specific errors. */
end_comment

begin_define
define|#
directive|define
name|NFSERR_BADIOMODE
value|10049
end_define

begin_define
define|#
directive|define
name|NFSERR_BADLAYOUT
value|10050
end_define

begin_define
define|#
directive|define
name|NFSERR_BADSESSIONDIGEST
value|10051
end_define

begin_define
define|#
directive|define
name|NFSERR_BADSESSION
value|10052
end_define

begin_define
define|#
directive|define
name|NFSERR_BADSLOT
value|10053
end_define

begin_define
define|#
directive|define
name|NFSERR_COMPLETEALREADY
value|10054
end_define

begin_define
define|#
directive|define
name|NFSERR_NOTBNDTOSESS
value|10055
end_define

begin_define
define|#
directive|define
name|NFSERR_DELEGALREADYWANT
value|10056
end_define

begin_define
define|#
directive|define
name|NFSERR_BACKCHANBUSY
value|10057
end_define

begin_define
define|#
directive|define
name|NFSERR_LAYOUTTRYLATER
value|10058
end_define

begin_define
define|#
directive|define
name|NFSERR_LAYOUTUNAVAIL
value|10059
end_define

begin_define
define|#
directive|define
name|NFSERR_NOMATCHLAYOUT
value|10060
end_define

begin_define
define|#
directive|define
name|NFSERR_RECALLCONFLICT
value|10061
end_define

begin_define
define|#
directive|define
name|NFSERR_UNKNLAYOUTTYPE
value|10062
end_define

begin_define
define|#
directive|define
name|NFSERR_SEQMISORDERED
value|10063
end_define

begin_define
define|#
directive|define
name|NFSERR_SEQUENCEPOS
value|10064
end_define

begin_define
define|#
directive|define
name|NFSERR_REQTOOBIG
value|10065
end_define

begin_define
define|#
directive|define
name|NFSERR_REPTOOBIG
value|10066
end_define

begin_define
define|#
directive|define
name|NFSERR_REPTOOBIGTOCACHE
value|10067
end_define

begin_define
define|#
directive|define
name|NFSERR_RETRYUNCACHEDREP
value|10068
end_define

begin_define
define|#
directive|define
name|NFSERR_UNSAFECOMPOUND
value|10069
end_define

begin_define
define|#
directive|define
name|NFSERR_TOOMANYOPS
value|10070
end_define

begin_define
define|#
directive|define
name|NFSERR_OPNOTINSESS
value|10071
end_define

begin_define
define|#
directive|define
name|NFSERR_HASHALGUNSUPP
value|10072
end_define

begin_define
define|#
directive|define
name|NFSERR_CLIENTIDBUSY
value|10074
end_define

begin_define
define|#
directive|define
name|NFSERR_PNFSIOHOLE
value|10075
end_define

begin_define
define|#
directive|define
name|NFSERR_SEQFALSERETRY
value|10076
end_define

begin_define
define|#
directive|define
name|NFSERR_BADHIGHSLOT
value|10077
end_define

begin_define
define|#
directive|define
name|NFSERR_DEADSESSION
value|10078
end_define

begin_define
define|#
directive|define
name|NFSERR_ENCRALGUNSUPP
value|10079
end_define

begin_define
define|#
directive|define
name|NFSERR_PNFSNOLAYOUT
value|10080
end_define

begin_define
define|#
directive|define
name|NFSERR_NOTONLYOP
value|10081
end_define

begin_define
define|#
directive|define
name|NFSERR_WRONGCRED
value|10082
end_define

begin_define
define|#
directive|define
name|NFSERR_WRONGTYPE
value|10083
end_define

begin_define
define|#
directive|define
name|NFSERR_DIRDELEGUNAVAIL
value|10084
end_define

begin_define
define|#
directive|define
name|NFSERR_REJECTDELEG
value|10085
end_define

begin_define
define|#
directive|define
name|NFSERR_RETURNCONFLICT
value|10086
end_define

begin_define
define|#
directive|define
name|NFSERR_DELEGREVOKED
value|10087
end_define

begin_define
define|#
directive|define
name|NFSERR_STALEWRITEVERF
value|30001
end_define

begin_comment
comment|/* Fake return for nfs_commit() */
end_comment

begin_define
define|#
directive|define
name|NFSERR_DONTREPLY
value|30003
end_define

begin_comment
comment|/* Don't process request */
end_comment

begin_define
define|#
directive|define
name|NFSERR_RETVOID
value|30004
end_define

begin_comment
comment|/* Return void, not error */
end_comment

begin_define
define|#
directive|define
name|NFSERR_REPLYFROMCACHE
value|30005
end_define

begin_comment
comment|/* Reply from recent request cache */
end_comment

begin_define
define|#
directive|define
name|NFSERR_STALEDONTRECOVER
value|30006
end_define

begin_comment
comment|/* Don't initiate recovery */
end_comment

begin_define
define|#
directive|define
name|NFSERR_RPCERR
value|0x40000000
end_define

begin_comment
comment|/* Mark an RPC layer error */
end_comment

begin_define
define|#
directive|define
name|NFSERR_AUTHERR
value|0x80000000
end_define

begin_comment
comment|/* Mark an authentication error */
end_comment

begin_define
define|#
directive|define
name|NFSERR_RPCMISMATCH
value|(NFSERR_RPCERR | RPC_MISMATCH)
end_define

begin_define
define|#
directive|define
name|NFSERR_PROGUNAVAIL
value|(NFSERR_RPCERR | RPC_PROGUNAVAIL)
end_define

begin_define
define|#
directive|define
name|NFSERR_PROGMISMATCH
value|(NFSERR_RPCERR | RPC_PROGMISMATCH)
end_define

begin_define
define|#
directive|define
name|NFSERR_PROGNOTV4
value|(NFSERR_RPCERR | 0xffff)
end_define

begin_define
define|#
directive|define
name|NFSERR_PROCUNAVAIL
value|(NFSERR_RPCERR | RPC_PROCUNAVAIL)
end_define

begin_define
define|#
directive|define
name|NFSERR_GARBAGE
value|(NFSERR_RPCERR | RPC_GARBAGE)
end_define

begin_comment
comment|/* Sizes in bytes of various nfs rpc components */
end_comment

begin_define
define|#
directive|define
name|NFSX_UNSIGNED
value|4
end_define

begin_define
define|#
directive|define
name|NFSX_HYPER
value|(2 * NFSX_UNSIGNED)
end_define

begin_comment
comment|/* specific to NFS Version 2 */
end_comment

begin_define
define|#
directive|define
name|NFSX_V2FH
value|32
end_define

begin_define
define|#
directive|define
name|NFSX_V2FATTR
value|68
end_define

begin_define
define|#
directive|define
name|NFSX_V2SATTR
value|32
end_define

begin_define
define|#
directive|define
name|NFSX_V2COOKIE
value|4
end_define

begin_define
define|#
directive|define
name|NFSX_V2STATFS
value|20
end_define

begin_comment
comment|/* specific to NFS Version 3 */
end_comment

begin_define
define|#
directive|define
name|NFSX_V3FHMAX
value|64
end_define

begin_comment
comment|/* max. allowed by protocol */
end_comment

begin_define
define|#
directive|define
name|NFSX_V3FATTR
value|84
end_define

begin_define
define|#
directive|define
name|NFSX_V3SATTR
value|60
end_define

begin_comment
comment|/* max. all fields filled in */
end_comment

begin_define
define|#
directive|define
name|NFSX_V3SRVSATTR
value|(sizeof (struct nfsv3_sattr))
end_define

begin_define
define|#
directive|define
name|NFSX_V3POSTOPATTR
value|(NFSX_V3FATTR + NFSX_UNSIGNED)
end_define

begin_define
define|#
directive|define
name|NFSX_V3WCCDATA
value|(NFSX_V3POSTOPATTR + 8 * NFSX_UNSIGNED)
end_define

begin_define
define|#
directive|define
name|NFSX_V3STATFS
value|52
end_define

begin_define
define|#
directive|define
name|NFSX_V3FSINFO
value|48
end_define

begin_define
define|#
directive|define
name|NFSX_V3PATHCONF
value|24
end_define

begin_comment
comment|/* specific to NFS Version 4 */
end_comment

begin_define
define|#
directive|define
name|NFSX_V4FHMAX
value|128
end_define

begin_define
define|#
directive|define
name|NFSX_V4FSID
value|(2 * NFSX_HYPER)
end_define

begin_define
define|#
directive|define
name|NFSX_V4SPECDATA
value|(2 * NFSX_UNSIGNED)
end_define

begin_define
define|#
directive|define
name|NFSX_V4TIME
value|(NFSX_HYPER + NFSX_UNSIGNED)
end_define

begin_define
define|#
directive|define
name|NFSX_V4SETTIME
value|(NFSX_UNSIGNED + NFSX_V4TIME)
end_define

begin_define
define|#
directive|define
name|NFSX_V4SESSIONID
value|16
end_define

begin_define
define|#
directive|define
name|NFSX_V4DEVICEID
value|16
end_define

begin_comment
comment|/* sizes common to multiple NFS versions */
end_comment

begin_define
define|#
directive|define
name|NFSX_FHMAX
value|(NFSX_V4FHMAX)
end_define

begin_define
define|#
directive|define
name|NFSX_MYFH
value|(sizeof (fhandle_t))
end_define

begin_comment
comment|/* size this server uses */
end_comment

begin_define
define|#
directive|define
name|NFSX_VERF
value|8
end_define

begin_define
define|#
directive|define
name|NFSX_STATEIDOTHER
value|12
end_define

begin_define
define|#
directive|define
name|NFSX_STATEID
value|(NFSX_UNSIGNED + NFSX_STATEIDOTHER)
end_define

begin_define
define|#
directive|define
name|NFSX_GSSH
value|12
end_define

begin_comment
comment|/* variants for multiple versions */
end_comment

begin_define
define|#
directive|define
name|NFSX_STATFS
parameter_list|(
name|v3
parameter_list|)
value|((v3) ? NFSX_V3STATFS : NFSX_V2STATFS)
end_define

begin_comment
comment|/* nfs rpc procedure numbers (before version mapping) */
end_comment

begin_define
define|#
directive|define
name|NFSPROC_NULL
value|0
end_define

begin_define
define|#
directive|define
name|NFSPROC_GETATTR
value|1
end_define

begin_define
define|#
directive|define
name|NFSPROC_SETATTR
value|2
end_define

begin_define
define|#
directive|define
name|NFSPROC_LOOKUP
value|3
end_define

begin_define
define|#
directive|define
name|NFSPROC_ACCESS
value|4
end_define

begin_define
define|#
directive|define
name|NFSPROC_READLINK
value|5
end_define

begin_define
define|#
directive|define
name|NFSPROC_READ
value|6
end_define

begin_define
define|#
directive|define
name|NFSPROC_WRITE
value|7
end_define

begin_define
define|#
directive|define
name|NFSPROC_CREATE
value|8
end_define

begin_define
define|#
directive|define
name|NFSPROC_MKDIR
value|9
end_define

begin_define
define|#
directive|define
name|NFSPROC_SYMLINK
value|10
end_define

begin_define
define|#
directive|define
name|NFSPROC_MKNOD
value|11
end_define

begin_define
define|#
directive|define
name|NFSPROC_REMOVE
value|12
end_define

begin_define
define|#
directive|define
name|NFSPROC_RMDIR
value|13
end_define

begin_define
define|#
directive|define
name|NFSPROC_RENAME
value|14
end_define

begin_define
define|#
directive|define
name|NFSPROC_LINK
value|15
end_define

begin_define
define|#
directive|define
name|NFSPROC_READDIR
value|16
end_define

begin_define
define|#
directive|define
name|NFSPROC_READDIRPLUS
value|17
end_define

begin_define
define|#
directive|define
name|NFSPROC_FSSTAT
value|18
end_define

begin_define
define|#
directive|define
name|NFSPROC_FSINFO
value|19
end_define

begin_define
define|#
directive|define
name|NFSPROC_PATHCONF
value|20
end_define

begin_define
define|#
directive|define
name|NFSPROC_COMMIT
value|21
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

begin_define
define|#
directive|define
name|NFSPROC_OPENLAYGET
value|54
end_define

begin_define
define|#
directive|define
name|NFSPROC_CREATELAYGET
value|55
end_define

begin_comment
comment|/*  * Must be defined as one higher than the last NFSv4.1 Proc# above.  */
end_comment

begin_define
define|#
directive|define
name|NFSV41_NPROCS
value|56
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NFS_V3NPROCS */
end_comment

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

begin_comment
comment|/*  * NFSPROC_NOOP is a fake op# that can't be the same as any V2/3/4 Procedure  * or Operation#. Since the NFS V4 Op #s go higher, use NFSV42_NOPS, which  * is one greater than the highest Op#.  */
end_comment

begin_define
define|#
directive|define
name|NFSPROC_NOOP
value|NFSV42_NOPS
end_define

begin_comment
comment|/* Actual Version 2 procedure numbers */
end_comment

begin_define
define|#
directive|define
name|NFSV2PROC_NULL
value|0
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_GETATTR
value|1
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_SETATTR
value|2
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_NOOP
value|3
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_ROOT
value|NFSV2PROC_NOOP
end_define

begin_comment
comment|/* Obsolete */
end_comment

begin_define
define|#
directive|define
name|NFSV2PROC_LOOKUP
value|4
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_READLINK
value|5
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_READ
value|6
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_WRITECACHE
value|NFSV2PROC_NOOP
end_define

begin_comment
comment|/* Obsolete */
end_comment

begin_define
define|#
directive|define
name|NFSV2PROC_WRITE
value|8
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_CREATE
value|9
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_REMOVE
value|10
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_RENAME
value|11
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_LINK
value|12
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_SYMLINK
value|13
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_MKDIR
value|14
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_RMDIR
value|15
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_READDIR
value|16
end_define

begin_define
define|#
directive|define
name|NFSV2PROC_STATFS
value|17
end_define

begin_comment
comment|/*  * V4 Procedure numbers  */
end_comment

begin_define
define|#
directive|define
name|NFSV4PROC_COMPOUND
value|1
end_define

begin_define
define|#
directive|define
name|NFSV4PROC_CBNULL
value|0
end_define

begin_define
define|#
directive|define
name|NFSV4PROC_CBCOMPOUND
value|1
end_define

begin_comment
comment|/*  * Constants used by the Version 3 and 4 protocols for various RPCs  */
end_comment

begin_define
define|#
directive|define
name|NFSV3SATTRTIME_DONTCHANGE
value|0
end_define

begin_define
define|#
directive|define
name|NFSV3SATTRTIME_TOSERVER
value|1
end_define

begin_define
define|#
directive|define
name|NFSV3SATTRTIME_TOCLIENT
value|2
end_define

begin_define
define|#
directive|define
name|NFSV4SATTRTIME_TOSERVER
value|0
end_define

begin_define
define|#
directive|define
name|NFSV4SATTRTIME_TOCLIENT
value|1
end_define

begin_define
define|#
directive|define
name|NFSV4LOCKT_READ
value|1
end_define

begin_define
define|#
directive|define
name|NFSV4LOCKT_WRITE
value|2
end_define

begin_define
define|#
directive|define
name|NFSV4LOCKT_READW
value|3
end_define

begin_define
define|#
directive|define
name|NFSV4LOCKT_WRITEW
value|4
end_define

begin_define
define|#
directive|define
name|NFSV4LOCKT_RELEASE
value|5
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_NOCREATE
value|0
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_CREATE
value|1
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_CLAIMNULL
value|0
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_CLAIMPREVIOUS
value|1
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_CLAIMDELEGATECUR
value|2
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_CLAIMDELEGATEPREV
value|3
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_CLAIMFH
value|4
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_CLAIMDELEGATECURFH
value|5
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_CLAIMDELEGATEPREVFH
value|6
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_DELEGATENONE
value|0
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_DELEGATEREAD
value|1
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_DELEGATEWRITE
value|2
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_DELEGATENONEEXT
value|3
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_LIMITSIZE
value|1
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_LIMITBLOCKS
value|2
end_define

begin_comment
comment|/*  * Nfs V4 ACE stuff  */
end_comment

begin_define
define|#
directive|define
name|NFSV4ACE_ALLOWEDTYPE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_DENIEDTYPE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_AUDITTYPE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_ALARMTYPE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_SUPALLOWED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_SUPDENIED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_SUPAUDIT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_SUPALARM
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_SUPTYPES
value|(NFSV4ACE_SUPALLOWED | NFSV4ACE_SUPDENIED)
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_FILEINHERIT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_DIRECTORYINHERIT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_NOPROPAGATEINHERIT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_INHERITONLY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_SUCCESSFULACCESS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_FAILEDACCESS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_IDENTIFIERGROUP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_READDATA
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_LISTDIRECTORY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_WRITEDATA
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_ADDFILE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_APPENDDATA
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_ADDSUBDIRECTORY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_READNAMEDATTR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_WRITENAMEDATTR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_EXECUTE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_SEARCH
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_DELETECHILD
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_READATTRIBUTES
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_WRITEATTRIBUTES
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_DELETE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_READACL
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_WRITEACL
value|0x00040000
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_WRITEOWNER
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_SYNCHRONIZE
value|0x00100000
end_define

begin_comment
comment|/*  * Here are the mappings between mode bits and acl mask bits for  * directories and other files.  * (Named attributes have not been included, since named attributes are  *  not yet supported.)  * The mailing list seems to indicate that NFSV4ACE_EXECUTE refers to  * searching a directory, although I can't find a statement of that in  * the RFC.  */
end_comment

begin_define
define|#
directive|define
name|NFSV4ACE_ALLFILESMASK
value|(NFSV4ACE_READATTRIBUTES | NFSV4ACE_READACL)
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_OWNERMASK
value|(NFSV4ACE_WRITEATTRIBUTES | NFSV4ACE_WRITEACL)
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_DIRREADMASK
value|NFSV4ACE_LISTDIRECTORY
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_DIREXECUTEMASK
value|NFSV4ACE_EXECUTE
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_DIRWRITEMASK
value|(NFSV4ACE_ADDFILE | 			\ 		NFSV4ACE_ADDSUBDIRECTORY | NFSV4ACE_DELETECHILD)
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_READMASK
value|NFSV4ACE_READDATA
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_WRITEMASK
value|(NFSV4ACE_WRITEDATA | NFSV4ACE_APPENDDATA)
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_EXECUTEMASK
value|NFSV4ACE_EXECUTE
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_ALLFILEBITS
value|(NFSV4ACE_READMASK | NFSV4ACE_WRITEMASK | \ 	NFSV4ACE_EXECUTEMASK | NFSV4ACE_SYNCHRONIZE)
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_ALLDIRBITS
value|(NFSV4ACE_DIRREADMASK | 		\ 	NFSV4ACE_DIRWRITEMASK | NFSV4ACE_DIREXECUTEMASK)
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_AUDITMASK
value|0x0
end_define

begin_comment
comment|/*  * These GENERIC masks are not used and are no longer believed to be useful.  */
end_comment

begin_define
define|#
directive|define
name|NFSV4ACE_GENERICREAD
value|0x00120081
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_GENERICWRITE
value|0x00160106
end_define

begin_define
define|#
directive|define
name|NFSV4ACE_GENERICEXECUTE
value|0x001200a0
end_define

begin_define
define|#
directive|define
name|NFSSTATEID_PUTALLZERO
value|0
end_define

begin_define
define|#
directive|define
name|NFSSTATEID_PUTALLONE
value|1
end_define

begin_define
define|#
directive|define
name|NFSSTATEID_PUTSTATEID
value|2
end_define

begin_define
define|#
directive|define
name|NFSSTATEID_PUTSEQIDZERO
value|3
end_define

begin_comment
comment|/*  * Bits for share access and deny.  */
end_comment

begin_define
define|#
directive|define
name|NFSV4OPEN_ACCESSREAD
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_ACCESSWRITE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_ACCESSBOTH
value|0x00000003
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_WANTDELEGMASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_WANTREADDELEG
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_WANTWRITEDELEG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_WANTANYDELEG
value|0x00000300
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_WANTNODELEG
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_WANTCANCEL
value|0x00000500
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_WANTSIGNALDELEG
value|0x00010000
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_WANTPUSHDELEG
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_DENYNONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_DENYREAD
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_DENYWRITE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_DENYBOTH
value|0x00000003
end_define

begin_comment
comment|/*  * Delegate_none_ext reply values.  */
end_comment

begin_define
define|#
directive|define
name|NFSV4OPEN_NOTWANTED
value|0
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_CONTENTION
value|1
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_RESOURCE
value|2
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_NOTSUPPFTYPE
value|3
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_NOTSUPPWRITEFTYPE
value|4
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_NOTSUPPUPGRADE
value|5
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_NOTSUPPDOWNGRADE
value|6
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_CANCELLED
value|7
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_ISDIR
value|8
end_define

begin_comment
comment|/*  * Open result flags  * (The first four are in the spec. The rest are used internally.)  */
end_comment

begin_define
define|#
directive|define
name|NFSV4OPEN_RESULTCONFIRM
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_LOCKTYPEPOSIX
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_PRESERVEUNLINKED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_MAYNOTIFYLOCK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_RFLAGS
define|\
value|(NFSV4OPEN_RESULTCONFIRM | NFSV4OPEN_LOCKTYPEPOSIX |		\     NFSV4OPEN_PRESERVEUNLINKED | NFSV4OPEN_MAYNOTIFYLOCK)
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_RECALL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_READDELEGATE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_WRITEDELEGATE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_WDRESOURCE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_WDCONTENTION
value|0x00100000
end_define

begin_define
define|#
directive|define
name|NFSV4OPEN_WDNOTWANTED
value|0x00200000
end_define

begin_comment
comment|/*  * NFS V4 File Handle types  */
end_comment

begin_define
define|#
directive|define
name|NFSV4FHTYPE_PERSISTENT
value|0x0
end_define

begin_define
define|#
directive|define
name|NFSV4FHTYPE_NOEXPIREWITHOPEN
value|0x1
end_define

begin_define
define|#
directive|define
name|NFSV4FHTYPE_VOLATILEANY
value|0x2
end_define

begin_define
define|#
directive|define
name|NFSV4FHTYPE_VOLATILEMIGRATE
value|0x4
end_define

begin_define
define|#
directive|define
name|NFSV4FHTYPE_VOLATILERENAME
value|0x8
end_define

begin_comment
comment|/*  * Maximum size of V4 opaque strings.  */
end_comment

begin_define
define|#
directive|define
name|NFSV4_OPAQUELIMIT
value|1024
end_define

begin_comment
comment|/*  * These are the same for V3 and V4.  */
end_comment

begin_define
define|#
directive|define
name|NFSACCESS_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|NFSACCESS_LOOKUP
value|0x02
end_define

begin_define
define|#
directive|define
name|NFSACCESS_MODIFY
value|0x04
end_define

begin_define
define|#
directive|define
name|NFSACCESS_EXTEND
value|0x08
end_define

begin_define
define|#
directive|define
name|NFSACCESS_DELETE
value|0x10
end_define

begin_define
define|#
directive|define
name|NFSACCESS_EXECUTE
value|0x20
end_define

begin_define
define|#
directive|define
name|NFSWRITE_UNSTABLE
value|0
end_define

begin_define
define|#
directive|define
name|NFSWRITE_DATASYNC
value|1
end_define

begin_define
define|#
directive|define
name|NFSWRITE_FILESYNC
value|2
end_define

begin_define
define|#
directive|define
name|NFSCREATE_UNCHECKED
value|0
end_define

begin_define
define|#
directive|define
name|NFSCREATE_GUARDED
value|1
end_define

begin_define
define|#
directive|define
name|NFSCREATE_EXCLUSIVE
value|2
end_define

begin_define
define|#
directive|define
name|NFSCREATE_EXCLUSIVE41
value|3
end_define

begin_define
define|#
directive|define
name|NFSV3FSINFO_LINK
value|0x01
end_define

begin_define
define|#
directive|define
name|NFSV3FSINFO_SYMLINK
value|0x02
end_define

begin_define
define|#
directive|define
name|NFSV3FSINFO_HOMOGENEOUS
value|0x08
end_define

begin_define
define|#
directive|define
name|NFSV3FSINFO_CANSETTIME
value|0x10
end_define

begin_comment
comment|/* Flags for Exchange ID */
end_comment

begin_define
define|#
directive|define
name|NFSV4EXCH_SUPPMOVEDREFER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NFSV4EXCH_SUPPMOVEDMIGR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NFSV4EXCH_BINDPRINCSTATEID
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NFSV4EXCH_USENONPNFS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|NFSV4EXCH_USEPNFSMDS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NFSV4EXCH_USEPNFSDS
value|0x00040000
end_define

begin_define
define|#
directive|define
name|NFSV4EXCH_MASKPNFS
value|0x00070000
end_define

begin_define
define|#
directive|define
name|NFSV4EXCH_UPDCONFIRMEDRECA
value|0x40000000
end_define

begin_define
define|#
directive|define
name|NFSV4EXCH_CONFIRMEDR
value|0x80000000
end_define

begin_comment
comment|/* State Protects */
end_comment

begin_define
define|#
directive|define
name|NFSV4EXCH_SP4NONE
value|0
end_define

begin_define
define|#
directive|define
name|NFSV4EXCH_SP4MACHCRED
value|1
end_define

begin_define
define|#
directive|define
name|NFSV4EXCH_SP4SSV
value|2
end_define

begin_comment
comment|/* Flags for Create Session */
end_comment

begin_define
define|#
directive|define
name|NFSV4CRSESS_PERSIST
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NFSV4CRSESS_CONNBACKCHAN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NFSV4CRSESS_CONNRDMA
value|0x00000004
end_define

begin_comment
comment|/* Flags for Sequence */
end_comment

begin_define
define|#
directive|define
name|NFSV4SEQ_CBPATHDOWN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NFSV4SEQ_CBGSSCONTEXPIRING
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NFSV4SEQ_CBGSSCONTEXPIRED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NFSV4SEQ_EXPIREDALLSTATEREVOKED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NFSV4SEQ_EXPIREDSOMESTATEREVOKED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NFSV4SEQ_ADMINSTATEREVOKED
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NFSV4SEQ_RECALLABLESTATEREVOKED
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NFSV4SEQ_LEASEMOVED
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NFSV4SEQ_RESTARTRECLAIMNEEDED
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NFSV4SEQ_CBPATHDOWNSESSION
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NFSV4SEQ_BACKCHANNELFAULT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NFSV4SEQ_DEVIDCHANGED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|NFSV4SEQ_DEVIDDELETED
value|0x00001000
end_define

begin_comment
comment|/* Flags for Layout. */
end_comment

begin_define
define|#
directive|define
name|NFSLAYOUTRETURN_FILE
value|1
end_define

begin_define
define|#
directive|define
name|NFSLAYOUTRETURN_FSID
value|2
end_define

begin_define
define|#
directive|define
name|NFSLAYOUTRETURN_ALL
value|3
end_define

begin_define
define|#
directive|define
name|NFSLAYOUT_NFSV4_1_FILES
value|0x1
end_define

begin_define
define|#
directive|define
name|NFSLAYOUT_OSD2_OBJECTS
value|0x2
end_define

begin_define
define|#
directive|define
name|NFSLAYOUT_BLOCK_VOLUME
value|0x3
end_define

begin_define
define|#
directive|define
name|NFSLAYOUTIOMODE_READ
value|1
end_define

begin_define
define|#
directive|define
name|NFSLAYOUTIOMODE_RW
value|2
end_define

begin_define
define|#
directive|define
name|NFSLAYOUTIOMODE_ANY
value|3
end_define

begin_comment
comment|/* Flags for Get Device Info. */
end_comment

begin_define
define|#
directive|define
name|NFSDEVICEIDNOTIFY_CHANGEBIT
value|0x1
end_define

begin_define
define|#
directive|define
name|NFSDEVICEIDNOTIFY_DELETEBIT
value|0x2
end_define

begin_comment
comment|/* Flags for File Layout. */
end_comment

begin_define
define|#
directive|define
name|NFSFLAYUTIL_DENSE
value|0x1
end_define

begin_define
define|#
directive|define
name|NFSFLAYUTIL_COMMIT_THRU_MDS
value|0x2
end_define

begin_comment
comment|/* Conversion macros */
end_comment

begin_define
define|#
directive|define
name|vtonfsv2_mode
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|)
define|\
value|txdr_unsigned(((t) == VFIFO) ? MAKEIMODE(VCHR, (m)) : 	\ 				MAKEIMODE((t), (m)))
end_define

begin_define
define|#
directive|define
name|vtonfsv34_mode
parameter_list|(
name|m
parameter_list|)
value|txdr_unsigned((m)& 07777)
end_define

begin_define
define|#
directive|define
name|nfstov_mode
parameter_list|(
name|a
parameter_list|)
value|(fxdr_unsigned(u_int16_t, (a))&07777)
end_define

begin_define
define|#
directive|define
name|vtonfsv2_type
parameter_list|(
name|a
parameter_list|)
value|(((u_int32_t)(a))>= 9 ? txdr_unsigned(NFNON) : \ 		txdr_unsigned(newnfsv2_type[((u_int32_t)(a))]))
end_define

begin_define
define|#
directive|define
name|vtonfsv34_type
parameter_list|(
name|a
parameter_list|)
value|(((u_int32_t)(a))>= 9 ? txdr_unsigned(NFNON) : \ 		txdr_unsigned(nfsv34_type[((u_int32_t)(a))]))
end_define

begin_define
define|#
directive|define
name|nfsv2tov_type
parameter_list|(
name|a
parameter_list|)
value|newnv2tov_type[fxdr_unsigned(u_int32_t,(a))&0x7]
end_define

begin_define
define|#
directive|define
name|nfsv34tov_type
parameter_list|(
name|a
parameter_list|)
value|nv34tov_type[fxdr_unsigned(u_int32_t,(a))&0x7]
end_define

begin_define
define|#
directive|define
name|vtonfs_dtype
parameter_list|(
name|a
parameter_list|)
value|(((u_int32_t)(a))>= 9 ? IFTODT(VTTOIF(VNON)) : \ 			 IFTODT(VTTOIF(a)))
end_define

begin_comment
comment|/* File types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NFNON
init|=
literal|0
block|,
name|NFREG
init|=
literal|1
block|,
name|NFDIR
init|=
literal|2
block|,
name|NFBLK
init|=
literal|3
block|,
name|NFCHR
init|=
literal|4
block|,
name|NFLNK
init|=
literal|5
block|,
name|NFSOCK
init|=
literal|6
block|,
name|NFFIFO
init|=
literal|7
block|,
name|NFATTRDIR
init|=
literal|8
block|,
name|NFNAMEDATTR
init|=
literal|9
block|}
name|nfstype
typedef|;
end_typedef

begin_comment
comment|/* Structs for common parts of the rpc's */
end_comment

begin_struct
struct|struct
name|nfsv2_time
block|{
name|u_int32_t
name|nfsv2_sec
decl_stmt|;
name|u_int32_t
name|nfsv2_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nfsv2_time
name|nfstime2
typedef|;
end_typedef

begin_struct
struct|struct
name|nfsv3_time
block|{
name|u_int32_t
name|nfsv3_sec
decl_stmt|;
name|u_int32_t
name|nfsv3_nsec
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nfsv3_time
name|nfstime3
typedef|;
end_typedef

begin_struct
struct|struct
name|nfsv4_time
block|{
name|u_int32_t
name|nfsv4_highsec
decl_stmt|;
name|u_int32_t
name|nfsv4_sec
decl_stmt|;
name|u_int32_t
name|nfsv4_nsec
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nfsv4_time
name|nfstime4
typedef|;
end_typedef

begin_comment
comment|/*  * Quads are defined as arrays of 2 longs to ensure dense packing for the  * protocol and to facilitate xdr conversion.  */
end_comment

begin_struct
struct|struct
name|nfs_uquad
block|{
name|u_int32_t
name|nfsuquad
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nfs_uquad
name|nfsuint64
typedef|;
end_typedef

begin_comment
comment|/*  * Used to convert between two u_longs and a u_quad_t.  */
end_comment

begin_union
union|union
name|nfs_quadconvert
block|{
name|u_int32_t
name|lval
index|[
literal|2
index|]
decl_stmt|;
name|u_quad_t
name|qval
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|nfs_quadconvert
name|nfsquad_t
typedef|;
end_typedef

begin_comment
comment|/*  * NFS Version 3 special file number.  */
end_comment

begin_struct
struct|struct
name|nfsv3_spec
block|{
name|u_int32_t
name|specdata1
decl_stmt|;
name|u_int32_t
name|specdata2
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nfsv3_spec
name|nfsv3spec
typedef|;
end_typedef

begin_comment
comment|/*  * File attributes and setable attributes. These structures cover both  * NFS version 2 and the version 3 protocol. Note that the union is only  * used so that one pointer can refer to both variants. These structures  * go out on the wire and must be densely packed, so no quad data types  * are used. (all fields are longs or u_longs or structures of same)  * NB: You can't do sizeof(struct nfs_fattr), you must use the  *     NFSX_FATTR(v3) macro.  */
end_comment

begin_struct
struct|struct
name|nfs_fattr
block|{
name|u_int32_t
name|fa_type
decl_stmt|;
name|u_int32_t
name|fa_mode
decl_stmt|;
name|u_int32_t
name|fa_nlink
decl_stmt|;
name|u_int32_t
name|fa_uid
decl_stmt|;
name|u_int32_t
name|fa_gid
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_int32_t
name|nfsv2fa_size
decl_stmt|;
name|u_int32_t
name|nfsv2fa_blocksize
decl_stmt|;
name|u_int32_t
name|nfsv2fa_rdev
decl_stmt|;
name|u_int32_t
name|nfsv2fa_blocks
decl_stmt|;
name|u_int32_t
name|nfsv2fa_fsid
decl_stmt|;
name|u_int32_t
name|nfsv2fa_fileid
decl_stmt|;
name|nfstime2
name|nfsv2fa_atime
decl_stmt|;
name|nfstime2
name|nfsv2fa_mtime
decl_stmt|;
name|nfstime2
name|nfsv2fa_ctime
decl_stmt|;
block|}
name|fa_nfsv2
struct|;
struct|struct
block|{
name|nfsuint64
name|nfsv3fa_size
decl_stmt|;
name|nfsuint64
name|nfsv3fa_used
decl_stmt|;
name|nfsv3spec
name|nfsv3fa_rdev
decl_stmt|;
name|nfsuint64
name|nfsv3fa_fsid
decl_stmt|;
name|nfsuint64
name|nfsv3fa_fileid
decl_stmt|;
name|nfstime3
name|nfsv3fa_atime
decl_stmt|;
name|nfstime3
name|nfsv3fa_mtime
decl_stmt|;
name|nfstime3
name|nfsv3fa_ctime
decl_stmt|;
block|}
name|fa_nfsv3
struct|;
block|}
name|fa_un
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* and some ugly defines for accessing union components */
end_comment

begin_define
define|#
directive|define
name|fa2_size
value|fa_un.fa_nfsv2.nfsv2fa_size
end_define

begin_define
define|#
directive|define
name|fa2_blocksize
value|fa_un.fa_nfsv2.nfsv2fa_blocksize
end_define

begin_define
define|#
directive|define
name|fa2_rdev
value|fa_un.fa_nfsv2.nfsv2fa_rdev
end_define

begin_define
define|#
directive|define
name|fa2_blocks
value|fa_un.fa_nfsv2.nfsv2fa_blocks
end_define

begin_define
define|#
directive|define
name|fa2_fsid
value|fa_un.fa_nfsv2.nfsv2fa_fsid
end_define

begin_define
define|#
directive|define
name|fa2_fileid
value|fa_un.fa_nfsv2.nfsv2fa_fileid
end_define

begin_define
define|#
directive|define
name|fa2_atime
value|fa_un.fa_nfsv2.nfsv2fa_atime
end_define

begin_define
define|#
directive|define
name|fa2_mtime
value|fa_un.fa_nfsv2.nfsv2fa_mtime
end_define

begin_define
define|#
directive|define
name|fa2_ctime
value|fa_un.fa_nfsv2.nfsv2fa_ctime
end_define

begin_define
define|#
directive|define
name|fa3_size
value|fa_un.fa_nfsv3.nfsv3fa_size
end_define

begin_define
define|#
directive|define
name|fa3_used
value|fa_un.fa_nfsv3.nfsv3fa_used
end_define

begin_define
define|#
directive|define
name|fa3_rdev
value|fa_un.fa_nfsv3.nfsv3fa_rdev
end_define

begin_define
define|#
directive|define
name|fa3_fsid
value|fa_un.fa_nfsv3.nfsv3fa_fsid
end_define

begin_define
define|#
directive|define
name|fa3_fileid
value|fa_un.fa_nfsv3.nfsv3fa_fileid
end_define

begin_define
define|#
directive|define
name|fa3_atime
value|fa_un.fa_nfsv3.nfsv3fa_atime
end_define

begin_define
define|#
directive|define
name|fa3_mtime
value|fa_un.fa_nfsv3.nfsv3fa_mtime
end_define

begin_define
define|#
directive|define
name|fa3_ctime
value|fa_un.fa_nfsv3.nfsv3fa_ctime
end_define

begin_struct
struct|struct
name|nfsv2_sattr
block|{
name|u_int32_t
name|sa_mode
decl_stmt|;
name|u_int32_t
name|sa_uid
decl_stmt|;
name|u_int32_t
name|sa_gid
decl_stmt|;
name|u_int32_t
name|sa_size
decl_stmt|;
name|nfstime2
name|sa_atime
decl_stmt|;
name|nfstime2
name|sa_mtime
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NFS Version 3 sattr structure for the new node creation case.  */
end_comment

begin_struct
struct|struct
name|nfsv3_sattr
block|{
name|u_int32_t
name|sa_modetrue
decl_stmt|;
name|u_int32_t
name|sa_mode
decl_stmt|;
name|u_int32_t
name|sa_uidfalse
decl_stmt|;
name|u_int32_t
name|sa_gidfalse
decl_stmt|;
name|u_int32_t
name|sa_sizefalse
decl_stmt|;
name|u_int32_t
name|sa_atimetype
decl_stmt|;
name|nfstime3
name|sa_atime
decl_stmt|;
name|u_int32_t
name|sa_mtimetype
decl_stmt|;
name|nfstime3
name|sa_mtime
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The attribute bits used for V4.  * NFSATTRBIT_xxx defines the attribute# (and its bit position)  * NFSATTRBM_xxx is a 32bit mask with the correct bit set within the  *	appropriate 32bit word.  * NFSATTRBIT_MAX is one greater than the largest NFSATTRBIT_xxx  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_SUPPORTEDATTRS
value|0
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_FHEXPIRETYPE
value|2
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_CHANGE
value|3
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_LINKSUPPORT
value|5
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_SYMLINKSUPPORT
value|6
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_NAMEDATTR
value|7
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_FSID
value|8
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_UNIQUEHANDLES
value|9
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_LEASETIME
value|10
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_RDATTRERROR
value|11
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_ACL
value|12
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_ACLSUPPORT
value|13
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_ARCHIVE
value|14
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_CANSETTIME
value|15
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_CASEINSENSITIVE
value|16
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_CASEPRESERVING
value|17
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_CHOWNRESTRICTED
value|18
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_FILEHANDLE
value|19
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_FILEID
value|20
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_FILESAVAIL
value|21
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_FILESFREE
value|22
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_FILESTOTAL
value|23
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_FSLOCATIONS
value|24
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_HIDDEN
value|25
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_HOMOGENEOUS
value|26
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_MAXFILESIZE
value|27
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_MAXLINK
value|28
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_MAXNAME
value|29
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_MAXREAD
value|30
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_MAXWRITE
value|31
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_MIMETYPE
value|32
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_MODE
value|33
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_NOTRUNC
value|34
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_NUMLINKS
value|35
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_OWNER
value|36
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_OWNERGROUP
value|37
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_QUOTAHARD
value|38
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_QUOTASOFT
value|39
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_QUOTAUSED
value|40
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_RAWDEV
value|41
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_SPACEAVAIL
value|42
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_SPACEFREE
value|43
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_SPACETOTAL
value|44
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_SPACEUSED
value|45
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_SYSTEM
value|46
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_TIMEACCESS
value|47
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_TIMEACCESSSET
value|48
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_TIMEBACKUP
value|49
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_TIMECREATE
value|50
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_TIMEDELTA
value|51
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_TIMEMETADATA
value|52
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_TIMEMODIFY
value|53
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_TIMEMODIFYSET
value|54
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_MOUNTEDONFILEID
value|55
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_DIRNOTIFDELAY
value|56
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_DIRENTNOTIFDELAY
value|57
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_DACL
value|58
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_SACL
value|59
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_CHANGEPOLICY
value|60
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_FSSTATUS
value|61
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_FSLAYOUTTYPE
value|62
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_LAYOUTHINT
value|63
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_LAYOUTTYPE
value|64
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_LAYOUTBLKSIZE
value|65
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_LAYOUTALIGNMENT
value|66
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_FSLOCATIONSINFO
value|67
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_MDSTHRESHOLD
value|68
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_RETENTIONGET
value|69
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_RETENTIONSET
value|70
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_RETENTEVTGET
value|71
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_RETENTEVTSET
value|72
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_RETENTIONHOLD
value|73
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_MODESETMASKED
value|74
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_SUPPATTREXCLCREAT
value|75
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_FSCHARSETCAP
value|76
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_SUPPORTEDATTRS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_TYPE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_FHEXPIRETYPE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_CHANGE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_SIZE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_LINKSUPPORT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_SYMLINKSUPPORT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_NAMEDATTR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_FSID
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_UNIQUEHANDLES
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_LEASETIME
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_RDATTRERROR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_ACL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_ACLSUPPORT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_ARCHIVE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_CANSETTIME
value|0x00008000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_CASEINSENSITIVE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_CASEPRESERVING
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_CHOWNRESTRICTED
value|0x00040000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_FILEHANDLE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_FILEID
value|0x00100000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_FILESAVAIL
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_FILESFREE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_FILESTOTAL
value|0x00800000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_FSLOCATIONS
value|0x01000000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_HIDDEN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_HOMOGENEOUS
value|0x04000000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_MAXFILESIZE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_MAXLINK
value|0x10000000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_MAXNAME
value|0x20000000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_MAXREAD
value|0x40000000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_MAXWRITE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_MIMETYPE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_MODE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_NOTRUNC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_NUMLINKS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_OWNER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_OWNERGROUP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_QUOTAHARD
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_QUOTASOFT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_QUOTAUSED
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_RAWDEV
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_SPACEAVAIL
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_SPACEFREE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_SPACETOTAL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_SPACEUSED
value|0x00002000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_SYSTEM
value|0x00004000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_TIMEACCESS
value|0x00008000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_TIMEACCESSSET
value|0x00010000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_TIMEBACKUP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_TIMECREATE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_TIMEDELTA
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_TIMEMETADATA
value|0x00100000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_TIMEMODIFY
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_TIMEMODIFYSET
value|0x00400000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_MOUNTEDONFILEID
value|0x00800000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_DIRNOTIFDELAY
value|0x01000000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_DIRENTNOTIFDELAY
value|0x02000000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_DACL
value|0x04000000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_SACL
value|0x08000000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_CHANGEPOLICY
value|0x10000000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_FSSTATUS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_FSLAYOUTTYPE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_LAYOUTHINT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_LAYOUTTYPE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_LAYOUTBLKSIZE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_LAYOUTALIGNMENT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_FSLOCATIONSINFO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_MDSTHRESHOLD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_RETENTIONGET
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_RETENTIONSET
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_RETENTEVTGET
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_RETENTEVTSET
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_RETENTIONHOLD
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_MODESETMASKED
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_SUPPATTREXCLCREAT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|NFSATTRBM_FSCHARSETCAP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_MAX
value|77
end_define

begin_comment
comment|/*  * Sets of attributes that are supported, by words in the bitmap.  */
end_comment

begin_comment
comment|/*  * NFSATTRBIT_SUPPORTED - SUPP0 - bits 0<->31  *			  SUPP1 - bits 32<->63  *			  SUPP2 - bits 64<->95  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_SUPP0
define|\
value|(NFSATTRBM_SUPPORTEDATTRS |					\  	NFSATTRBM_TYPE |						\  	NFSATTRBM_FHEXPIRETYPE |					\  	NFSATTRBM_CHANGE |						\  	NFSATTRBM_SIZE |						\  	NFSATTRBM_LINKSUPPORT |						\  	NFSATTRBM_SYMLINKSUPPORT |					\  	NFSATTRBM_NAMEDATTR |						\  	NFSATTRBM_FSID |						\  	NFSATTRBM_UNIQUEHANDLES |					\  	NFSATTRBM_LEASETIME |						\  	NFSATTRBM_RDATTRERROR |						\  	NFSATTRBM_ACL |							\  	NFSATTRBM_ACLSUPPORT |						\  	NFSATTRBM_CANSETTIME |						\  	NFSATTRBM_CASEINSENSITIVE |					\  	NFSATTRBM_CASEPRESERVING |					\  	NFSATTRBM_CHOWNRESTRICTED |					\  	NFSATTRBM_FILEHANDLE |						\  	NFSATTRBM_FILEID |						\  	NFSATTRBM_FILESAVAIL |						\  	NFSATTRBM_FILESFREE |						\  	NFSATTRBM_FILESTOTAL |						\ 	NFSATTRBM_FSLOCATIONS |						\  	NFSATTRBM_HOMOGENEOUS |						\  	NFSATTRBM_MAXFILESIZE |						\  	NFSATTRBM_MAXLINK |						\  	NFSATTRBM_MAXNAME |						\  	NFSATTRBM_MAXREAD |						\  	NFSATTRBM_MAXWRITE)
end_define

begin_comment
comment|/*  * NFSATTRBIT_S1 - subset of SUPP1 - OR of the following bits:  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_S1
define|\
value|(NFSATTRBM_MODE |						\  	NFSATTRBM_NOTRUNC |						\  	NFSATTRBM_NUMLINKS |						\  	NFSATTRBM_OWNER |						\  	NFSATTRBM_OWNERGROUP |						\  	NFSATTRBM_RAWDEV |						\  	NFSATTRBM_SPACEAVAIL |						\  	NFSATTRBM_SPACEFREE |						\  	NFSATTRBM_SPACETOTAL |						\  	NFSATTRBM_SPACEUSED |						\  	NFSATTRBM_TIMEACCESS |						\  	NFSATTRBM_TIMEDELTA |						\  	NFSATTRBM_TIMEMETADATA |					\  	NFSATTRBM_TIMEMODIFY |						\  	NFSATTRBM_MOUNTEDONFILEID |					\ 	NFSATTRBM_QUOTAHARD |                        			\     	NFSATTRBM_QUOTASOFT |                        			\     	NFSATTRBM_QUOTAUSED)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|QUOTA
end_ifdef

begin_comment
comment|/*  * If QUOTA OR in NFSATTRBIT_QUOTAHARD, NFSATTRBIT_QUOTASOFT and  * NFSATTRBIT_QUOTAUSED.  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_SUPP1
value|(NFSATTRBIT_S1 |			\ 				NFSATTRBM_QUOTAHARD |			\ 				NFSATTRBM_QUOTASOFT |			\ 				NFSATTRBM_QUOTAUSED)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NFSATTRBIT_SUPP1
value|NFSATTRBIT_S1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NFSATTRBIT_SUPP2
value|NFSATTRBM_SUPPATTREXCLCREAT
end_define

begin_comment
comment|/*  * NFSATTRBIT_SUPPSETONLY is the OR of NFSATTRBIT_TIMEACCESSSET and  * NFSATTRBIT_TIMEMODIFYSET.  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_SUPPSETONLY
value|(NFSATTRBM_TIMEACCESSSET |		\ 				 NFSATTRBM_TIMEMODIFYSET)
end_define

begin_comment
comment|/*  * NFSATTRBIT_SETABLE - SETABLE0 - bits 0<->31  *			SETABLE1 - bits 32<->63  *			SETABLE2 - bits 64<->95  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_SETABLE0
define|\
value|(NFSATTRBM_SIZE |						\ 	NFSATTRBM_ACL)
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_SETABLE1
define|\
value|(NFSATTRBM_MODE |						\  	NFSATTRBM_OWNER |						\  	NFSATTRBM_OWNERGROUP |						\  	NFSATTRBM_TIMEACCESSSET |					\  	NFSATTRBM_TIMEMODIFYSET)
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_SETABLE2
value|0
end_define

begin_comment
comment|/*  * Set of attributes that the getattr vnode op needs.  * OR of the following bits.  * NFSATTRBIT_GETATTR0 - bits 0<->31  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_GETATTR0
define|\
value|(NFSATTRBM_SUPPORTEDATTRS |					\  	NFSATTRBM_TYPE |						\  	NFSATTRBM_CHANGE |						\  	NFSATTRBM_SIZE |						\  	NFSATTRBM_FSID |						\  	NFSATTRBM_FILEID |						\  	NFSATTRBM_MAXREAD)
end_define

begin_comment
comment|/*  * NFSATTRBIT_GETATTR1 - bits 32<->63  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_GETATTR1
define|\
value|(NFSATTRBM_MODE |						\  	NFSATTRBM_NUMLINKS |						\  	NFSATTRBM_OWNER |						\  	NFSATTRBM_OWNERGROUP |						\  	NFSATTRBM_RAWDEV |						\  	NFSATTRBM_SPACEUSED |						\  	NFSATTRBM_TIMEACCESS |						\  	NFSATTRBM_TIMEMETADATA |					\  	NFSATTRBM_TIMEMODIFY)
end_define

begin_comment
comment|/*  * NFSATTRBIT_GETATTR2 - bits 64<->95  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_GETATTR2
value|0
end_define

begin_comment
comment|/*  * Subset of the above that the Write RPC gets.  * OR of the following bits.  * NFSATTRBIT_WRITEGETATTR0 - bits 0<->31  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_WRITEGETATTR0
define|\
value|(NFSATTRBM_SUPPORTEDATTRS |					\  	NFSATTRBM_TYPE |						\  	NFSATTRBM_CHANGE |						\  	NFSATTRBM_SIZE |						\  	NFSATTRBM_FSID |						\  	NFSATTRBM_FILEID |						\  	NFSATTRBM_MAXREAD)
end_define

begin_comment
comment|/*  * NFSATTRBIT_WRITEGETATTR1 - bits 32<->63  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_WRITEGETATTR1
define|\
value|(NFSATTRBM_MODE |						\  	NFSATTRBM_NUMLINKS |						\  	NFSATTRBM_RAWDEV |						\  	NFSATTRBM_SPACEUSED |						\  	NFSATTRBM_TIMEACCESS |						\  	NFSATTRBM_TIMEMETADATA |					\  	NFSATTRBM_TIMEMODIFY)
end_define

begin_comment
comment|/*  * NFSATTRBIT_WRITEGETATTR2 - bits 64<->95  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_WRITEGETATTR2
value|0
end_define

begin_comment
comment|/*  * Set of attributes that the wccattr operation op needs.  * OR of the following bits.  * NFSATTRBIT_WCCATTR0 - bits 0<->31  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_WCCATTR0
value|0
end_define

begin_comment
comment|/*  * NFSATTRBIT_WCCATTR1 - bits 32<->63  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_WCCATTR1
define|\
value|(NFSATTRBM_TIMEMODIFY)
end_define

begin_comment
comment|/*  * NFSATTRBIT_WCCATTR2 - bits 64<->95  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_WCCATTR2
value|0
end_define

begin_comment
comment|/*  * NFSATTRBIT_CBGETATTR0 - bits 0<->31  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_CBGETATTR0
value|(NFSATTRBM_CHANGE | NFSATTRBM_SIZE)
end_define

begin_comment
comment|/*  * NFSATTRBIT_CBGETATTR1 - bits 32<->63  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_CBGETATTR1
value|0x0
end_define

begin_comment
comment|/*  * NFSATTRBIT_CBGETATTR2 - bits 64<->95  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_CBGETATTR2
value|0x0
end_define

begin_comment
comment|/*  * Sets of attributes that require a VFS_STATFS() call to get the  * values of.  * NFSATTRBIT_STATFS0 - bits 0<->31  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_STATFS0
define|\
value|(NFSATTRBM_LINKSUPPORT |					\ 	NFSATTRBM_SYMLINKSUPPORT |					\ 	NFSATTRBM_CANSETTIME |						\  	NFSATTRBM_FILESAVAIL |						\  	NFSATTRBM_FILESFREE |						\  	NFSATTRBM_FILESTOTAL |						\  	NFSATTRBM_HOMOGENEOUS |						\  	NFSATTRBM_MAXFILESIZE |						\ 	NFSATTRBM_MAXNAME |						\ 	NFSATTRBM_MAXREAD |						\ 	NFSATTRBM_MAXWRITE)
end_define

begin_comment
comment|/*  * NFSATTRBIT_STATFS1 - bits 32<->63  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_STATFS1
define|\
value|(NFSATTRBM_QUOTAHARD |						\  	NFSATTRBM_QUOTASOFT |						\  	NFSATTRBM_QUOTAUSED |						\  	NFSATTRBM_SPACEAVAIL |						\  	NFSATTRBM_SPACEFREE |						\  	NFSATTRBM_SPACETOTAL |						\  	NFSATTRBM_SPACEUSED |						\ 	NFSATTRBM_TIMEDELTA)
end_define

begin_comment
comment|/*  * NFSATTRBIT_STATFS2 - bits 64<->95  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_STATFS2
value|0
end_define

begin_comment
comment|/*  * These are the bits that are needed by the nfs_statfs() call.  * (The regular getattr bits are or'd in so the vnode gets the correct  *  type, etc.)  * NFSGETATTRBIT_STATFS0 - bits 0<->31  */
end_comment

begin_define
define|#
directive|define
name|NFSGETATTRBIT_STATFS0
value|(NFSATTRBIT_GETATTR0 |			\ 				NFSATTRBM_LINKSUPPORT |			\ 				NFSATTRBM_SYMLINKSUPPORT |		\ 				NFSATTRBM_CANSETTIME |			\ 				NFSATTRBM_FILESFREE |			\ 				NFSATTRBM_FILESTOTAL |			\ 				NFSATTRBM_HOMOGENEOUS |			\ 				NFSATTRBM_MAXFILESIZE |			\ 				NFSATTRBM_MAXNAME |			\ 				NFSATTRBM_MAXREAD |			\ 				NFSATTRBM_MAXWRITE)
end_define

begin_comment
comment|/*  * NFSGETATTRBIT_STATFS1 - bits 32<->63  */
end_comment

begin_define
define|#
directive|define
name|NFSGETATTRBIT_STATFS1
value|(NFSATTRBIT_GETATTR1 |			\ 				NFSATTRBM_SPACEAVAIL |			\ 				NFSATTRBM_SPACEFREE |			\ 				NFSATTRBM_SPACETOTAL |			\ 				NFSATTRBM_TIMEDELTA)
end_define

begin_comment
comment|/*  * NFSGETATTRBIT_STATFS2 - bits 64<->95  */
end_comment

begin_define
define|#
directive|define
name|NFSGETATTRBIT_STATFS2
value|0
end_define

begin_comment
comment|/*  * Set of attributes for the equivalent of an nfsv3 pathconf rpc.  * NFSGETATTRBIT_PATHCONF0 - bits 0<->31  */
end_comment

begin_define
define|#
directive|define
name|NFSGETATTRBIT_PATHCONF0
value|(NFSATTRBIT_GETATTR0 |			\ 			 	NFSATTRBM_CASEINSENSITIVE |		\ 			 	NFSATTRBM_CASEPRESERVING |		\ 			 	NFSATTRBM_CHOWNRESTRICTED |		\ 			 	NFSATTRBM_MAXLINK |			\ 			 	NFSATTRBM_MAXNAME)
end_define

begin_comment
comment|/*  * NFSGETATTRBIT_PATHCONF1 - bits 32<->63  */
end_comment

begin_define
define|#
directive|define
name|NFSGETATTRBIT_PATHCONF1
value|(NFSATTRBIT_GETATTR1 |			\ 				NFSATTRBM_NOTRUNC)
end_define

begin_comment
comment|/*  * NFSGETATTRBIT_PATHCONF2 - bits 64<->95  */
end_comment

begin_define
define|#
directive|define
name|NFSGETATTRBIT_PATHCONF2
value|0
end_define

begin_comment
comment|/*  * Sets of attributes required by readdir and readdirplus.  * NFSATTRBIT_READDIRPLUS0	(NFSATTRBIT_GETATTR0 | NFSATTRBIT_FILEHANDLE |  *				 NFSATTRBIT_RDATTRERROR)  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_READDIRPLUS0
value|(NFSATTRBIT_GETATTR0 | NFSATTRBM_FILEHANDLE | \ 				NFSATTRBM_RDATTRERROR)
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_READDIRPLUS1
value|NFSATTRBIT_GETATTR1
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_READDIRPLUS2
value|0
end_define

begin_comment
comment|/*  * Set of attributes supported by Referral vnodes.  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_REFERRAL0
value|(NFSATTRBM_TYPE | NFSATTRBM_FSID |	\ 	NFSATTRBM_RDATTRERROR | NFSATTRBM_FSLOCATIONS)
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_REFERRAL1
value|NFSATTRBM_MOUNTEDONFILEID
end_define

begin_define
define|#
directive|define
name|NFSATTRBIT_REFERRAL2
value|0
end_define

begin_comment
comment|/*  * Structure for data handled by the statfs rpc. Since some fields are  * u_int64_t, this cannot be used for copying data on/off the wire, due  * to alignment concerns.  */
end_comment

begin_struct
struct|struct
name|nfsstatfs
block|{
union|union
block|{
struct|struct
block|{
name|u_int32_t
name|nfsv2sf_tsize
decl_stmt|;
name|u_int32_t
name|nfsv2sf_bsize
decl_stmt|;
name|u_int32_t
name|nfsv2sf_blocks
decl_stmt|;
name|u_int32_t
name|nfsv2sf_bfree
decl_stmt|;
name|u_int32_t
name|nfsv2sf_bavail
decl_stmt|;
block|}
name|sf_nfsv2
struct|;
struct|struct
block|{
name|u_int64_t
name|nfsv3sf_tbytes
decl_stmt|;
name|u_int64_t
name|nfsv3sf_fbytes
decl_stmt|;
name|u_int64_t
name|nfsv3sf_abytes
decl_stmt|;
name|u_int64_t
name|nfsv3sf_tfiles
decl_stmt|;
name|u_int64_t
name|nfsv3sf_ffiles
decl_stmt|;
name|u_int64_t
name|nfsv3sf_afiles
decl_stmt|;
name|u_int32_t
name|nfsv3sf_invarsec
decl_stmt|;
block|}
name|sf_nfsv3
struct|;
block|}
name|sf_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sf_tsize
value|sf_un.sf_nfsv2.nfsv2sf_tsize
end_define

begin_define
define|#
directive|define
name|sf_bsize
value|sf_un.sf_nfsv2.nfsv2sf_bsize
end_define

begin_define
define|#
directive|define
name|sf_blocks
value|sf_un.sf_nfsv2.nfsv2sf_blocks
end_define

begin_define
define|#
directive|define
name|sf_bfree
value|sf_un.sf_nfsv2.nfsv2sf_bfree
end_define

begin_define
define|#
directive|define
name|sf_bavail
value|sf_un.sf_nfsv2.nfsv2sf_bavail
end_define

begin_define
define|#
directive|define
name|sf_tbytes
value|sf_un.sf_nfsv3.nfsv3sf_tbytes
end_define

begin_define
define|#
directive|define
name|sf_fbytes
value|sf_un.sf_nfsv3.nfsv3sf_fbytes
end_define

begin_define
define|#
directive|define
name|sf_abytes
value|sf_un.sf_nfsv3.nfsv3sf_abytes
end_define

begin_define
define|#
directive|define
name|sf_tfiles
value|sf_un.sf_nfsv3.nfsv3sf_tfiles
end_define

begin_define
define|#
directive|define
name|sf_ffiles
value|sf_un.sf_nfsv3.nfsv3sf_ffiles
end_define

begin_define
define|#
directive|define
name|sf_afiles
value|sf_un.sf_nfsv3.nfsv3sf_afiles
end_define

begin_define
define|#
directive|define
name|sf_invarsec
value|sf_un.sf_nfsv3.nfsv3sf_invarsec
end_define

begin_comment
comment|/*  * Now defined using u_int64_t for the 64 bit field(s).  * (Cannot be used to move data on/off the wire, due to alignment concerns.)  */
end_comment

begin_struct
struct|struct
name|nfsfsinfo
block|{
name|u_int32_t
name|fs_rtmax
decl_stmt|;
name|u_int32_t
name|fs_rtpref
decl_stmt|;
name|u_int32_t
name|fs_rtmult
decl_stmt|;
name|u_int32_t
name|fs_wtmax
decl_stmt|;
name|u_int32_t
name|fs_wtpref
decl_stmt|;
name|u_int32_t
name|fs_wtmult
decl_stmt|;
name|u_int32_t
name|fs_dtpref
decl_stmt|;
name|u_int64_t
name|fs_maxfilesize
decl_stmt|;
name|struct
name|timespec
name|fs_timedelta
decl_stmt|;
name|u_int32_t
name|fs_properties
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bits for fs_properties  */
end_comment

begin_define
define|#
directive|define
name|NFSV3_FSFLINK
value|0x1
end_define

begin_define
define|#
directive|define
name|NFSV3_FSFSYMLINK
value|0x2
end_define

begin_define
define|#
directive|define
name|NFSV3_FSFHOMOGENEOUS
value|0x4
end_define

begin_define
define|#
directive|define
name|NFSV3_FSFCANSETTIME
value|0x8
end_define

begin_comment
comment|/*  * Yikes, overload fs_rtmult as fs_maxname for V4.  */
end_comment

begin_define
define|#
directive|define
name|fs_maxname
value|fs_rtmult
end_define

begin_struct
struct|struct
name|nfsv3_pathconf
block|{
name|u_int32_t
name|pc_linkmax
decl_stmt|;
name|u_int32_t
name|pc_namemax
decl_stmt|;
name|u_int32_t
name|pc_notrunc
decl_stmt|;
name|u_int32_t
name|pc_chownrestricted
decl_stmt|;
name|u_int32_t
name|pc_caseinsensitive
decl_stmt|;
name|u_int32_t
name|pc_casepreserving
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NFS V4 data structures.  */
end_comment

begin_struct
struct|struct
name|nfsv4stateid
block|{
name|u_int32_t
name|seqid
decl_stmt|;
name|u_int32_t
name|other
index|[
name|NFSX_STATEIDOTHER
operator|/
name|NFSX_UNSIGNED
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nfsv4stateid
name|nfsv4stateid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NFS_NFSPROTO_H_ */
end_comment

end_unit

