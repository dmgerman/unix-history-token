begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ntfs.h,v 1.9 1999/10/31 19:45:26 jdolecek Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998, 1999 Semen Ustimenko  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*#define NTFS_DEBUG 1*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_LKM
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_ntfs.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|u_int64_t
name|cn_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int16_t
name|wchar
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_define
define|#
directive|define
name|BBSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|BBOFF
value|((off_t)(0))
end_define

begin_define
define|#
directive|define
name|BBLOCK
value|((daddr_t)(0))
end_define

begin_define
define|#
directive|define
name|NTFS_MFTINO
value|0
end_define

begin_define
define|#
directive|define
name|NTFS_VOLUMEINO
value|3
end_define

begin_define
define|#
directive|define
name|NTFS_ATTRDEFINO
value|4
end_define

begin_define
define|#
directive|define
name|NTFS_ROOTINO
value|5
end_define

begin_define
define|#
directive|define
name|NTFS_BITMAPINO
value|6
end_define

begin_define
define|#
directive|define
name|NTFS_BOOTINO
value|7
end_define

begin_define
define|#
directive|define
name|NTFS_BADCLUSINO
value|8
end_define

begin_define
define|#
directive|define
name|NTFS_UPCASEINO
value|10
end_define

begin_define
define|#
directive|define
name|NTFS_MAXFILENAME
value|255
end_define

begin_struct
struct|struct
name|fixuphdr
block|{
name|u_int32_t
name|fh_magic
decl_stmt|;
name|u_int16_t
name|fh_foff
decl_stmt|;
name|u_int16_t
name|fh_fnum
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NTFS_AF_INRUN
value|0x00000001
end_define

begin_struct
struct|struct
name|attrhdr
block|{
name|u_int32_t
name|a_type
decl_stmt|;
name|u_int32_t
name|reclen
decl_stmt|;
name|u_int8_t
name|a_flag
decl_stmt|;
name|u_int8_t
name|a_namelen
decl_stmt|;
name|u_int8_t
name|a_nameoff
decl_stmt|;
name|u_int8_t
name|reserved1
decl_stmt|;
name|u_int8_t
name|a_compression
decl_stmt|;
name|u_int8_t
name|reserved2
decl_stmt|;
name|u_int16_t
name|a_index
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NTFS_A_STD
value|0x10
end_define

begin_define
define|#
directive|define
name|NTFS_A_ATTRLIST
value|0x20
end_define

begin_define
define|#
directive|define
name|NTFS_A_NAME
value|0x30
end_define

begin_define
define|#
directive|define
name|NTFS_A_VOLUMENAME
value|0x60
end_define

begin_define
define|#
directive|define
name|NTFS_A_DATA
value|0x80
end_define

begin_define
define|#
directive|define
name|NTFS_A_INDXROOT
value|0x90
end_define

begin_define
define|#
directive|define
name|NTFS_A_INDX
value|0xA0
end_define

begin_define
define|#
directive|define
name|NTFS_A_INDXBITMAP
value|0xB0
end_define

begin_define
define|#
directive|define
name|NTFS_MAXATTRNAME
value|255
end_define

begin_struct
struct|struct
name|attr
block|{
name|struct
name|attrhdr
name|a_hdr
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_int16_t
name|a_datalen
decl_stmt|;
name|u_int16_t
name|reserved1
decl_stmt|;
name|u_int16_t
name|a_dataoff
decl_stmt|;
name|u_int16_t
name|a_indexed
decl_stmt|;
block|}
name|a_S_r
struct|;
struct|struct
block|{
name|cn_t
name|a_vcnstart
decl_stmt|;
name|cn_t
name|a_vcnend
decl_stmt|;
name|u_int16_t
name|a_dataoff
decl_stmt|;
name|u_int16_t
name|a_compressalg
decl_stmt|;
name|u_int32_t
name|reserved1
decl_stmt|;
name|u_int64_t
name|a_allocated
decl_stmt|;
name|u_int64_t
name|a_datalen
decl_stmt|;
name|u_int64_t
name|a_initialized
decl_stmt|;
block|}
name|a_S_nr
struct|;
block|}
name|a_S
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|a_r
value|a_S.a_S_r
end_define

begin_define
define|#
directive|define
name|a_nr
value|a_S.a_S_nr
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int64_t
name|t_create
decl_stmt|;
name|u_int64_t
name|t_write
decl_stmt|;
name|u_int64_t
name|t_mftwrite
decl_stmt|;
name|u_int64_t
name|t_access
decl_stmt|;
block|}
name|ntfs_times_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NTFS_FFLAG_RDONLY
value|0x01LL
end_define

begin_define
define|#
directive|define
name|NTFS_FFLAG_HIDDEN
value|0x02LL
end_define

begin_define
define|#
directive|define
name|NTFS_FFLAG_SYSTEM
value|0x04LL
end_define

begin_define
define|#
directive|define
name|NTFS_FFLAG_ARCHIVE
value|0x20LL
end_define

begin_define
define|#
directive|define
name|NTFS_FFLAG_COMPRESSED
value|0x0800LL
end_define

begin_define
define|#
directive|define
name|NTFS_FFLAG_DIR
value|0x10000000LL
end_define

begin_struct
struct|struct
name|attr_name
block|{
name|u_int32_t
name|n_pnumber
decl_stmt|;
comment|/* Parent ntnode */
name|u_int32_t
name|reserved
decl_stmt|;
name|ntfs_times_t
name|n_times
decl_stmt|;
name|u_int64_t
name|n_size
decl_stmt|;
name|u_int64_t
name|n_attrsz
decl_stmt|;
name|u_int64_t
name|n_flag
decl_stmt|;
name|u_int8_t
name|n_namelen
decl_stmt|;
name|u_int8_t
name|n_nametype
decl_stmt|;
name|u_int16_t
name|n_name
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NTFS_IRFLAG_INDXALLOC
value|0x00000001
end_define

begin_struct
struct|struct
name|attr_indexroot
block|{
name|u_int32_t
name|ir_unkn1
decl_stmt|;
comment|/* always 0x30 */
name|u_int32_t
name|ir_unkn2
decl_stmt|;
comment|/* always 0x1 */
name|u_int32_t
name|ir_size
decl_stmt|;
comment|/* ??? */
name|u_int32_t
name|ir_unkn3
decl_stmt|;
comment|/* number of cluster */
name|u_int32_t
name|ir_unkn4
decl_stmt|;
comment|/* always 0x10 */
name|u_int32_t
name|ir_datalen
decl_stmt|;
comment|/* sizeof simething */
name|u_int32_t
name|ir_allocated
decl_stmt|;
comment|/* same as above */
name|u_int16_t
name|ir_flag
decl_stmt|;
comment|/* ?? always 1 */
name|u_int16_t
name|ir_unkn7
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|attr_attrlist
block|{
name|u_int32_t
name|al_type
decl_stmt|;
comment|/* Attribute type */
name|u_int16_t
name|reclen
decl_stmt|;
comment|/* length of this entry */
name|u_int8_t
name|al_namelen
decl_stmt|;
comment|/* Attribute name len */
name|u_int8_t
name|al_nameoff
decl_stmt|;
comment|/* Name offset from entry start */
name|u_int64_t
name|al_vcnstart
decl_stmt|;
comment|/* VCN number */
name|u_int32_t
name|al_inumber
decl_stmt|;
comment|/* Parent ntnode */
name|u_int32_t
name|reserved
decl_stmt|;
name|u_int16_t
name|al_index
decl_stmt|;
comment|/* Attribute index in MFT record */
name|u_int16_t
name|al_name
index|[
literal|1
index|]
decl_stmt|;
comment|/* Name */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NTFS_INDXMAGIC
value|(u_int32_t)(0x58444E49)
end_define

begin_struct
struct|struct
name|attr_indexalloc
block|{
name|struct
name|fixuphdr
name|ia_fixup
decl_stmt|;
name|u_int64_t
name|unknown1
decl_stmt|;
name|cn_t
name|ia_bufcn
decl_stmt|;
name|u_int16_t
name|ia_hdrsize
decl_stmt|;
name|u_int16_t
name|unknown2
decl_stmt|;
name|u_int32_t
name|ia_inuse
decl_stmt|;
name|u_int32_t
name|ia_allocated
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NTFS_IEFLAG_SUBNODE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NTFS_IEFLAG_LAST
value|0x00000002
end_define

begin_struct
struct|struct
name|attr_indexentry
block|{
name|u_int32_t
name|ie_number
decl_stmt|;
name|u_int32_t
name|unknown1
decl_stmt|;
name|u_int16_t
name|reclen
decl_stmt|;
name|u_int16_t
name|ie_size
decl_stmt|;
name|u_int32_t
name|ie_flag
decl_stmt|;
comment|/* 1 - has subnodes, 2 - last */
name|u_int32_t
name|ie_fpnumber
decl_stmt|;
name|u_int32_t
name|unknown2
decl_stmt|;
name|ntfs_times_t
name|ie_ftimes
decl_stmt|;
name|u_int64_t
name|ie_fallocated
decl_stmt|;
name|u_int64_t
name|ie_fsize
decl_stmt|;
name|u_int64_t
name|ie_fflag
decl_stmt|;
name|u_int8_t
name|ie_fnamelen
decl_stmt|;
name|u_int8_t
name|ie_fnametype
decl_stmt|;
name|wchar
name|ie_fname
index|[
name|NTFS_MAXFILENAME
index|]
decl_stmt|;
comment|/* cn_t		ie_bufcn;	 buffer with subnodes */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NTFS_FILEMAGIC
value|(u_int32_t)(0x454C4946)
end_define

begin_define
define|#
directive|define
name|NTFS_FRFLAG_DIR
value|0x0002
end_define

begin_struct
struct|struct
name|filerec
block|{
name|struct
name|fixuphdr
name|fr_fixup
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|8
index|]
decl_stmt|;
name|u_int16_t
name|fr_seqnum
decl_stmt|;
comment|/* Sequence number */
name|u_int16_t
name|fr_nlink
decl_stmt|;
name|u_int16_t
name|fr_attroff
decl_stmt|;
comment|/* offset to attributes */
name|u_int16_t
name|fr_flags
decl_stmt|;
comment|/* 1-nonresident attr, 2-directory */
name|u_int32_t
name|fr_size
decl_stmt|;
comment|/* hdr + attributes */
name|u_int32_t
name|fr_allocated
decl_stmt|;
comment|/* allocated length of record */
name|u_int64_t
name|fr_mainrec
decl_stmt|;
comment|/* main record */
name|u_int16_t
name|fr_attrnum
decl_stmt|;
comment|/* maximum attr number + 1 ??? */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NTFS_ATTRNAME_MAXLEN
value|0x40
end_define

begin_define
define|#
directive|define
name|NTFS_ADFLAG_NONRES
value|0x0080
end_define

begin_comment
comment|/* Attrib can be non resident */
end_comment

begin_define
define|#
directive|define
name|NTFS_ADFLAG_INDEX
value|0x0002
end_define

begin_comment
comment|/* Attrib can be indexed */
end_comment

begin_struct
struct|struct
name|attrdef
block|{
name|wchar
name|ad_name
index|[
name|NTFS_ATTRNAME_MAXLEN
index|]
decl_stmt|;
name|u_int32_t
name|ad_type
decl_stmt|;
name|u_int32_t
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|u_int32_t
name|ad_flag
decl_stmt|;
name|u_int64_t
name|ad_minlen
decl_stmt|;
name|u_int64_t
name|ad_maxlen
decl_stmt|;
comment|/* -1 for nonlimited */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ntvattrdef
block|{
name|char
name|ad_name
index|[
literal|0x40
index|]
decl_stmt|;
name|int
name|ad_namelen
decl_stmt|;
name|u_int32_t
name|ad_type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NTFS_BBID
value|"NTFS    "
end_define

begin_define
define|#
directive|define
name|NTFS_BBIDLEN
value|8
end_define

begin_struct
struct|struct
name|bootfile
block|{
name|u_int8_t
name|reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* asm jmp near ... */
name|u_int8_t
name|bf_sysid
index|[
literal|8
index|]
decl_stmt|;
comment|/* 'NTFS    ' */
name|u_int16_t
name|bf_bps
decl_stmt|;
comment|/* bytes per sector */
name|u_int8_t
name|bf_spc
decl_stmt|;
comment|/* sectors per cluster */
name|u_int8_t
name|reserved2
index|[
literal|7
index|]
decl_stmt|;
comment|/* unused (zeroed) */
name|u_int8_t
name|bf_media
decl_stmt|;
comment|/* media desc. (0xF8) */
name|u_int8_t
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
name|u_int16_t
name|bf_spt
decl_stmt|;
comment|/* sectors per track */
name|u_int16_t
name|bf_heads
decl_stmt|;
comment|/* number of heads */
name|u_int8_t
name|reserver4
index|[
literal|12
index|]
decl_stmt|;
name|u_int64_t
name|bf_spv
decl_stmt|;
comment|/* sectors per volume */
name|cn_t
name|bf_mftcn
decl_stmt|;
comment|/* $MFT cluster number */
name|cn_t
name|bf_mftmirrcn
decl_stmt|;
comment|/* $MFTMirr cn */
name|u_int8_t
name|bf_mftrecsz
decl_stmt|;
comment|/* MFT record size (clust) */
comment|/* 0xF6 inducates 1/4 */
name|u_int32_t
name|bf_ibsz
decl_stmt|;
comment|/* index buffer size */
name|u_int32_t
name|bf_volsn
decl_stmt|;
comment|/* volume ser. num. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NTFS_SYSNODESNUM
value|0x0B
end_define

begin_struct
struct|struct
name|ntfsmount
block|{
name|struct
name|mount
modifier|*
name|ntm_mountp
decl_stmt|;
comment|/* filesystem vfs structure */
name|struct
name|bootfile
name|ntm_bootfile
decl_stmt|;
name|dev_t
name|ntm_dev
decl_stmt|;
comment|/* device mounted */
name|struct
name|vnode
modifier|*
name|ntm_devvp
decl_stmt|;
comment|/* block device mounted vnode */
name|struct
name|vnode
modifier|*
name|ntm_sysvn
index|[
name|NTFS_SYSNODESNUM
index|]
decl_stmt|;
name|u_int32_t
name|ntm_bpmftrec
decl_stmt|;
name|uid_t
name|ntm_uid
decl_stmt|;
name|gid_t
name|ntm_gid
decl_stmt|;
name|mode_t
name|ntm_mode
decl_stmt|;
name|u_long
name|ntm_flag
decl_stmt|;
name|cn_t
name|ntm_cfree
decl_stmt|;
name|struct
name|ntvattrdef
modifier|*
name|ntm_ad
decl_stmt|;
name|int
name|ntm_adnum
decl_stmt|;
name|struct
name|netexport
name|ntm_export
decl_stmt|;
comment|/* export information */
name|wchar
modifier|*
name|ntm_82u
decl_stmt|;
comment|/* 8bit to Unicode */
name|char
modifier|*
modifier|*
name|ntm_u28
decl_stmt|;
comment|/* Unicode to 8 bit */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ntm_mftcn
value|ntm_bootfile.bf_mftcn
end_define

begin_define
define|#
directive|define
name|ntm_mftmirrcn
value|ntm_bootfile.bf_mftmirrcn
end_define

begin_define
define|#
directive|define
name|ntm_mftrecsz
value|ntm_bootfile.bf_mftrecsz
end_define

begin_define
define|#
directive|define
name|ntm_spc
value|ntm_bootfile.bf_spc
end_define

begin_define
define|#
directive|define
name|ntm_bps
value|ntm_bootfile.bf_bps
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_define
define|#
directive|define
name|NTFS_NEXTREC
parameter_list|(
name|s
parameter_list|,
name|type
parameter_list|)
value|((type)(((caddr_t) s) + (s)->reclen))
end_define

begin_comment
comment|/* Convert mount ptr to ntfsmount ptr. */
end_comment

begin_define
define|#
directive|define
name|VFSTONTFS
parameter_list|(
name|mp
parameter_list|)
value|((struct ntfsmount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|VTONT
parameter_list|(
name|v
parameter_list|)
value|FTONT(VTOF(v))
end_define

begin_define
define|#
directive|define
name|VTOF
parameter_list|(
name|v
parameter_list|)
value|((struct fnode *)((v)->v_data))
end_define

begin_define
define|#
directive|define
name|FTOV
parameter_list|(
name|f
parameter_list|)
value|((f)->f_vp)
end_define

begin_define
define|#
directive|define
name|FTONT
parameter_list|(
name|f
parameter_list|)
value|((f)->f_ip)
end_define

begin_define
define|#
directive|define
name|ntfs_cntobn
parameter_list|(
name|cn
parameter_list|)
value|(daddr_t)((cn) * (ntmp->ntm_spc))
end_define

begin_define
define|#
directive|define
name|ntfs_cntob
parameter_list|(
name|cn
parameter_list|)
value|(off_t)((cn) * (ntmp)->ntm_spc * (ntmp)->ntm_bps)
end_define

begin_define
define|#
directive|define
name|ntfs_btocn
parameter_list|(
name|off
parameter_list|)
value|(cn_t)((off) / ((ntmp)->ntm_spc * (ntmp)->ntm_bps))
end_define

begin_define
define|#
directive|define
name|ntfs_btocl
parameter_list|(
name|off
parameter_list|)
value|(cn_t)((off + ntfs_cntob(1) - 1) / ((ntmp)->ntm_spc * (ntmp)->ntm_bps))
end_define

begin_define
define|#
directive|define
name|ntfs_btocnoff
parameter_list|(
name|off
parameter_list|)
value|(off_t)((off) % ((ntmp)->ntm_spc * (ntmp)->ntm_bps))
end_define

begin_define
define|#
directive|define
name|ntfs_bntob
parameter_list|(
name|bn
parameter_list|)
value|(daddr_t)((bn) * (ntmp)->ntm_bps)
end_define

begin_define
define|#
directive|define
name|ntfs_bpbl
value|(daddr_t)((ntmp)->ntm_bps)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NTFSMNT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NTFSNTNODE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NTFSFNODE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NTFSDIR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NTFSNTHASH
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|MALLOC_DEFINE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|M_NTFSNTHASH
value|M_NTFS
end_define

begin_define
define|#
directive|define
name|M_NTFSNTVATTR
value|M_NTFS
end_define

begin_define
define|#
directive|define
name|M_NTFSRDATA
value|M_NTFS
end_define

begin_define
define|#
directive|define
name|M_NTFSRUN
value|M_NTFS
end_define

begin_define
define|#
directive|define
name|M_NTFSDECOMP
value|M_NTFS
end_define

begin_define
define|#
directive|define
name|M_NTFSMNT
value|M_NTFS
end_define

begin_define
define|#
directive|define
name|M_NTFSNTNODE
value|M_NTFS
end_define

begin_define
define|#
directive|define
name|M_NTFSFNODE
value|M_NTFS
end_define

begin_define
define|#
directive|define
name|M_NTFSDIR
value|M_NTFS
end_define

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|vop_t
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|HASHINIT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|hashinit((a), (b), (c), (d))
end_define

begin_define
define|#
directive|define
name|bqrelse
parameter_list|(
name|bp
parameter_list|)
value|brelse(bp)
end_define

begin_define
define|#
directive|define
name|VOP__UNLOCK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|VOP_UNLOCK((a), (b))
end_define

begin_define
define|#
directive|define
name|VGET
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|vget((a), (b))
end_define

begin_define
define|#
directive|define
name|VN_LOCK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|vn_lock((a), (b))
end_define

begin_define
define|#
directive|define
name|LOCKMGR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|lockmgr((a), (b), (c))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !NetBSD */
end_comment

begin_define
define|#
directive|define
name|HASHINIT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|hashinit((a), (b), (d))
end_define

begin_define
define|#
directive|define
name|VOP__UNLOCK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|VOP_UNLOCK((a), (b), (c))
end_define

begin_define
define|#
directive|define
name|VGET
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|vget((a), (b), (c))
end_define

begin_define
define|#
directive|define
name|VN_LOCK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|vn_lock((a), (b), (c))
end_define

begin_define
define|#
directive|define
name|LOCKMGR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|lockmgr((a), (b), (c), NULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NetBSD */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NTFS_DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|dprintf
parameter_list|(
name|a
parameter_list|)
value|printf a
end_define

begin_if
if|#
directive|if
name|NTFS_DEBUG
operator|>
literal|1
end_if

begin_define
define|#
directive|define
name|ddprintf
parameter_list|(
name|a
parameter_list|)
value|printf a
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ddprintf
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dprintf
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ddprintf
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|ntfs_vnodeop_p
decl_stmt|;
end_decl_stmt

end_unit

