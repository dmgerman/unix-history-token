begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998, 1999 Semen Ustimenko (semenu@FreeBSD.org)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*#define HPFS_DEBUG 10*/
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|lsn_t
typedef|;
end_typedef

begin_comment
comment|/* Logical Sector Number */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|lsn_t
name|lsn1
decl_stmt|;
name|lsn_t
name|lsn2
decl_stmt|;
block|}
name|rsp_t
typedef|;
end_typedef

begin_comment
comment|/* Redundant Sector Pointer */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|cnt
decl_stmt|;
name|lsn_t
name|lsn
decl_stmt|;
block|}
name|sptr_t
typedef|;
end_typedef

begin_comment
comment|/* Storage Pointer */
end_comment

begin_define
define|#
directive|define
name|SUBLOCK
value|0x10
end_define

begin_define
define|#
directive|define
name|SUSIZE
value|DEV_BSIZE
end_define

begin_define
define|#
directive|define
name|SPBLOCK
value|0x11
end_define

begin_define
define|#
directive|define
name|SPSIZE
value|DEV_BSIZE
end_define

begin_define
define|#
directive|define
name|BMSIZE
value|(4 * DEV_BSIZE)
end_define

begin_define
define|#
directive|define
name|HPFS_MAXFILENAME
value|255
end_define

begin_define
define|#
directive|define
name|SU_MAGIC
value|((u_int64_t)0xFA53E9C5F995E849)
end_define

begin_struct
struct|struct
name|sublock
block|{
name|u_int64_t
name|su_magic
decl_stmt|;
name|u_int8_t
name|su_hpfsver
decl_stmt|;
name|u_int8_t
name|su_fnctver
decl_stmt|;
name|u_int16_t
name|unused
decl_stmt|;
name|lsn_t
name|su_rootfno
decl_stmt|;
comment|/* Root Fnode */
name|u_int32_t
name|su_btotal
decl_stmt|;
comment|/* Total blocks */
name|u_int32_t
name|su_badbtotal
decl_stmt|;
comment|/* Bad Sectors total */
name|rsp_t
name|su_bitmap
decl_stmt|;
name|rsp_t
name|su_badbl
decl_stmt|;
name|u_long
name|su_chkdskdate
decl_stmt|;
name|u_long
name|su_dskoptdate
decl_stmt|;
name|u_int32_t
name|su_dbbsz
decl_stmt|;
comment|/* Sectors in DirBlock Band */
name|lsn_t
name|su_dbbstart
decl_stmt|;
name|lsn_t
name|su_dbbend
decl_stmt|;
name|lsn_t
name|su_dbbbitmap
decl_stmt|;
name|char
name|su_volname
index|[
literal|0x20
index|]
decl_stmt|;
name|lsn_t
name|su_uidt
decl_stmt|;
comment|/* Ptr to User ID Table (8 sect) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SP_MAGIC
value|((u_int64_t)0xFA5229C5F9911849)
end_define

begin_define
define|#
directive|define
name|SP_DIRTY
value|0x0001
end_define

begin_define
define|#
directive|define
name|SP_SPDBINUSE
value|0x0002
end_define

begin_define
define|#
directive|define
name|SP_HFINUSE
value|0x0004
end_define

begin_define
define|#
directive|define
name|SP_BADSECT
value|0x0008
end_define

begin_define
define|#
directive|define
name|SP_BADBMBL
value|0x0010
end_define

begin_define
define|#
directive|define
name|SP_FASTFRMT
value|0x0020
end_define

begin_define
define|#
directive|define
name|SP_OLDHPFS
value|0x0080
end_define

begin_define
define|#
directive|define
name|SP_IDASD
value|0x0100
end_define

begin_define
define|#
directive|define
name|SP_RDASD
value|0x0200
end_define

begin_define
define|#
directive|define
name|SP_DASD
value|0x0400
end_define

begin_define
define|#
directive|define
name|SP_MMACTIVE
value|0x0800
end_define

begin_define
define|#
directive|define
name|SP_DCEACLS
value|0x1000
end_define

begin_define
define|#
directive|define
name|SP_DSADDIRTY
value|0x2000
end_define

begin_struct
struct|struct
name|spblock
block|{
name|u_int64_t
name|sp_magic
decl_stmt|;
name|u_int16_t
name|sp_flag
decl_stmt|;
name|u_int8_t
name|sp_mmcontf
decl_stmt|;
name|u_int8_t
name|unused
decl_stmt|;
name|lsn_t
name|sp_hf
decl_stmt|;
comment|/* HotFix list */
name|u_int32_t
name|sp_hfinuse
decl_stmt|;
comment|/* HotFixes in use */
name|u_int32_t
name|sp_hfavail
decl_stmt|;
comment|/* HotFixes available */
name|u_int32_t
name|sp_spdbavail
decl_stmt|;
comment|/* Spare DirBlocks available */
name|u_int32_t
name|sp_spdbmax
decl_stmt|;
comment|/* Spare DirBlocks maximum */
name|lsn_t
name|sp_cpi
decl_stmt|;
name|u_int32_t
name|sp_cpinum
decl_stmt|;
name|u_int32_t
name|sp_suchecksum
decl_stmt|;
name|u_int32_t
name|sp_spchecksum
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|0x3C
index|]
decl_stmt|;
name|lsn_t
name|sp_spdb
index|[
literal|0x65
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DE_SPECIAL
value|0x0001
end_define

begin_define
define|#
directive|define
name|DE_ACL
value|0x0002
end_define

begin_define
define|#
directive|define
name|DE_DOWN
value|0x0004
end_define

begin_define
define|#
directive|define
name|DE_END
value|0x0008
end_define

begin_define
define|#
directive|define
name|DE_EALIST
value|0x0010
end_define

begin_define
define|#
directive|define
name|DE_EPERM
value|0x0020
end_define

begin_define
define|#
directive|define
name|DE_EXPLACL
value|0x0040
end_define

begin_define
define|#
directive|define
name|DE_NEEDEA
value|0x0080
end_define

begin_define
define|#
directive|define
name|DE_RONLY
value|0x0100
end_define

begin_define
define|#
directive|define
name|DE_HIDDEN
value|0x0200
end_define

begin_define
define|#
directive|define
name|DE_SYSTEM
value|0x0400
end_define

begin_define
define|#
directive|define
name|DE_VOLLABEL
value|0x0800
end_define

begin_define
define|#
directive|define
name|DE_DIR
value|0x1000
end_define

begin_define
define|#
directive|define
name|DE_ARCHIV
value|0x2000
end_define

begin_define
define|#
directive|define
name|DE_DOWNLSN
parameter_list|(
name|dep
parameter_list|)
value|(*(lsn_t *)((caddr_t)(dep) + (dep)->de_reclen - sizeof(lsn_t)))
end_define

begin_define
define|#
directive|define
name|DE_NEXTDE
parameter_list|(
name|dep
parameter_list|)
value|((struct hpfsdirent *)((caddr_t)(dep) + (dep)->de_reclen))
end_define

begin_typedef
typedef|typedef
struct|struct
name|hpfsdirent
block|{
name|u_int16_t
name|de_reclen
decl_stmt|;
name|u_int16_t
name|de_flag
decl_stmt|;
name|lsn_t
name|de_fnode
decl_stmt|;
name|u_long
name|de_mtime
decl_stmt|;
name|u_int32_t
name|de_size
decl_stmt|;
name|u_long
name|de_atime
decl_stmt|;
name|u_long
name|de_ctime
decl_stmt|;
name|u_int32_t
name|de_ealen
decl_stmt|;
name|u_int8_t
name|de_flexflag
decl_stmt|;
name|u_int8_t
name|de_cpid
decl_stmt|;
name|u_int8_t
name|de_namelen
decl_stmt|;
name|char
name|de_name
index|[
literal|1
index|]
decl_stmt|;
comment|/*	...		de_flex; */
comment|/*	lsn_t		de_down; */
block|}
name|hpfsdirent_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|D_BSIZE
value|(DEV_BSIZE*4)
end_define

begin_define
define|#
directive|define
name|D_MAGIC
value|0x77E40AAE
end_define

begin_define
define|#
directive|define
name|D_DIRENT
parameter_list|(
name|dbp
parameter_list|)
value|((hpfsdirent_t *)((caddr_t)dbp + sizeof(dirblk_t)))
end_define

begin_define
define|#
directive|define
name|D_DE
parameter_list|(
name|dbp
parameter_list|,
name|deoff
parameter_list|)
value|((hpfsdirent_t *)((caddr_t)dbp + sizeof(dirblk_t) + (deoff)))
end_define

begin_typedef
typedef|typedef
struct|struct
name|dirblk
block|{
name|u_int32_t
name|d_magic
decl_stmt|;
name|u_int32_t
name|d_freeoff
decl_stmt|;
comment|/* Offset of first free byte */
name|u_int32_t
name|d_chcnt
decl_stmt|;
comment|/* Change count */
name|lsn_t
name|d_parent
decl_stmt|;
name|lsn_t
name|d_self
decl_stmt|;
block|}
name|dirblk_t
typedef|;
end_typedef

begin_comment
comment|/*  * Allocation Block (ALBLK)  */
end_comment

begin_define
define|#
directive|define
name|AB_HBOFFEO
value|0x01
end_define

begin_define
define|#
directive|define
name|AB_FNPARENT
value|0x20
end_define

begin_define
define|#
directive|define
name|AB_SUGGBSCH
value|0x40
end_define

begin_define
define|#
directive|define
name|AB_NODES
value|0x80
end_define

begin_define
define|#
directive|define
name|AB_ALLEAF
parameter_list|(
name|abp
parameter_list|)
value|((alleaf_t *)((caddr_t)(abp) + sizeof(alblk_t)))
end_define

begin_define
define|#
directive|define
name|AB_ALNODE
parameter_list|(
name|abp
parameter_list|)
value|((alnode_t *)((caddr_t)(abp) + sizeof(alblk_t)))
end_define

begin_define
define|#
directive|define
name|AB_FREEALP
parameter_list|(
name|abp
parameter_list|)
value|((alleaf_t *)((caddr_t)(abp) + (abp)->ab_freeoff))
end_define

begin_define
define|#
directive|define
name|AB_FREEANP
parameter_list|(
name|abp
parameter_list|)
value|((alnode_t *)((caddr_t)(abp) + (abp)->ab_freeoff))
end_define

begin_define
define|#
directive|define
name|AB_LASTALP
parameter_list|(
name|abp
parameter_list|)
value|(AB_ALLEAF(abp) + (abp)->ab_busycnt - 1)
end_define

begin_define
define|#
directive|define
name|AB_LASTANP
parameter_list|(
name|abp
parameter_list|)
value|(AB_ALNODE(abp) + (abp)->ab_busycnt - 1)
end_define

begin_define
define|#
directive|define
name|AB_ADDNREC
parameter_list|(
name|abp
parameter_list|,
name|sz
parameter_list|,
name|n
parameter_list|)
value|{		\ 	(abp)->ab_busycnt += (n);		\ 	(abp)->ab_freecnt -= (n);		\ 	(abp)->ab_freeoff += (n) * (sz);	\ }
end_define

begin_define
define|#
directive|define
name|AB_RMNREC
parameter_list|(
name|abp
parameter_list|,
name|sz
parameter_list|,
name|n
parameter_list|)
value|{	\ 	(abp)->ab_busycnt -= (n);		\ 	(abp)->ab_freecnt += (n);		\ 	(abp)->ab_freeoff -= (n) * (sz);\ }
end_define

begin_define
define|#
directive|define
name|AB_ADDAL
parameter_list|(
name|abp
parameter_list|)
value|AB_ADDNREC(abp,sizeof(alleaf_t), 1)
end_define

begin_define
define|#
directive|define
name|AB_ADDAN
parameter_list|(
name|abp
parameter_list|)
value|AB_ADDNREC(abp,sizeof(alnode_t), 1)
end_define

begin_define
define|#
directive|define
name|AB_RMAL
parameter_list|(
name|abp
parameter_list|)
value|AB_RMNREC(abp,sizeof(alleaf_t), 1)
end_define

begin_define
define|#
directive|define
name|AB_RMAN
parameter_list|(
name|abp
parameter_list|)
value|AB_RMNREC(abp,sizeof(alnode_t), 1)
end_define

begin_typedef
typedef|typedef
struct|struct
name|alblk
block|{
name|u_int8_t
name|ab_flag
decl_stmt|;
name|u_int8_t
name|ab_res
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|ab_freecnt
decl_stmt|;
name|u_int8_t
name|ab_busycnt
decl_stmt|;
name|u_int16_t
name|ab_freeoff
decl_stmt|;
block|}
name|alblk_t
typedef|;
end_typedef

begin_comment
comment|/*  * FNode  */
end_comment

begin_define
define|#
directive|define
name|FNODESIZE
value|DEV_BSIZE
end_define

begin_define
define|#
directive|define
name|FN_MAGIC
value|0xF7E40AAE
end_define

begin_struct
struct|struct
name|fnode
block|{
name|u_int32_t
name|fn_magic
decl_stmt|;
name|u_int64_t
name|fn_readhist
decl_stmt|;
name|u_int8_t
name|fn_namelen
decl_stmt|;
name|char
name|fn_name
index|[
literal|0xF
index|]
decl_stmt|;
comment|/* First 15 symbols or less */
name|lsn_t
name|fn_parent
decl_stmt|;
name|sptr_t
name|fn_extacl
decl_stmt|;
name|u_int16_t
name|fn_acllen
decl_stmt|;
name|u_int8_t
name|fn_extaclflag
decl_stmt|;
name|u_int8_t
name|fn_histbitcount
decl_stmt|;
name|sptr_t
name|fn_extea
decl_stmt|;
name|u_int16_t
name|fn_ealen
decl_stmt|;
comment|/* Len of EAs in Fnode */
name|u_int8_t
name|fn_exteaflag
decl_stmt|;
comment|/* EAs in exteas */
name|u_int8_t
name|fn_flag
decl_stmt|;
name|alblk_t
name|fn_ab
decl_stmt|;
name|u_int8_t
name|fn_abd
index|[
literal|0x60
index|]
decl_stmt|;
name|u_int32_t
name|fn_size
decl_stmt|;
name|u_int32_t
name|fn_reqea
decl_stmt|;
name|u_int8_t
name|fn_uid
index|[
literal|0x10
index|]
decl_stmt|;
name|u_int16_t
name|fn_intoff
decl_stmt|;
name|u_int8_t
name|fn_1dasdthr
decl_stmt|;
name|u_int8_t
name|fn_dasdthr
decl_stmt|;
name|u_int32_t
name|fn_dasdlim
decl_stmt|;
name|u_int32_t
name|fn_dasdusage
decl_stmt|;
name|u_int8_t
name|fn_int
index|[
literal|0x13c
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EA_NAME
parameter_list|(
name|eap
parameter_list|)
value|((char *)(((caddr_t)(eap)) + sizeof(struct ea)))
end_define

begin_struct
struct|struct
name|ea
block|{
name|u_int8_t
name|ea_type
decl_stmt|;
comment|/* 0 - plain val */
comment|/* 1 - sptr to val */
comment|/* 3 - lsn point to AlSec, cont. val */
name|u_int8_t
name|ea_namelen
decl_stmt|;
name|u_int16_t
name|ea_vallen
decl_stmt|;
comment|/*u_int8_t	ea_name[]; */
comment|/*u_int8_t	ea_val[]; */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Allocation Block Data (ALNODE)  *  * NOTE: AlNodes are used when there are too many fragments  * to represent the data in the AlBlk  */
end_comment

begin_define
define|#
directive|define
name|AN_SET
parameter_list|(
name|anp
parameter_list|,
name|nextoff
parameter_list|,
name|lsn
parameter_list|)
value|{	\ 	(anp)->an_nextoff = (nextoff); 		\ 	(anp)->an_lsn = (lsn); 			\ }
end_define

begin_typedef
typedef|typedef
struct|struct
name|alnode
block|{
name|u_int32_t
name|an_nextoff
decl_stmt|;
comment|/* next node offset in blocks */
name|lsn_t
name|an_lsn
decl_stmt|;
comment|/* position of AlSec structure */
block|}
name|alnode_t
typedef|;
end_typedef

begin_comment
comment|/*  * Allocaion  Block Data (ALLEAF)  *  * NOTE: Leaves are used to point at contiguous block of data  * (a fragment or an "extent");  */
end_comment

begin_define
define|#
directive|define
name|AL_SET
parameter_list|(
name|alp
parameter_list|,
name|off
parameter_list|,
name|len
parameter_list|,
name|lsn
parameter_list|)
value|{	\ 	(alp)->al_off = (off); 			\ 	(alp)->al_len = (len); 			\ 	(alp)->al_lsn = (lsn); 			\ }
end_define

begin_typedef
typedef|typedef
struct|struct
name|alleaf
block|{
name|u_int32_t
name|al_off
decl_stmt|;
comment|/* offset in blocks */
name|u_int32_t
name|al_len
decl_stmt|;
comment|/* len in blocks */
name|lsn_t
name|al_lsn
decl_stmt|;
comment|/* phys position */
block|}
name|alleaf_t
typedef|;
end_typedef

begin_comment
comment|/*  * Allocation Sector  *  * NOTE: AlSecs  are not  initialized before use, so they ussually  * look full of junk. Use the AlBlk  tto validate the data.  */
end_comment

begin_define
define|#
directive|define
name|AS_MAGIC
value|0x37E40AAE
end_define

begin_typedef
typedef|typedef
struct|struct
name|alsec
block|{
name|u_int32_t
name|as_magic
decl_stmt|;
name|lsn_t
name|as_self
decl_stmt|;
name|lsn_t
name|as_parent
decl_stmt|;
name|alblk_t
name|as_ab
decl_stmt|;
name|u_int8_t
name|as_abd
index|[
literal|0x1E0
index|]
decl_stmt|;
block|}
name|alsec_t
typedef|;
end_typedef

begin_comment
comment|/*  * Code Page structures  */
end_comment

begin_struct
struct|struct
name|cpdblk
block|{
name|u_int16_t
name|b_country
decl_stmt|;
comment|/* Country code */
name|u_int16_t
name|b_cpid
decl_stmt|;
comment|/* CP ID */
name|u_int16_t
name|b_dbcscnt
decl_stmt|;
comment|/* Count of DBCS ranges in CP */
name|char
name|b_upcase
index|[
literal|0x80
index|]
decl_stmt|;
comment|/* Case conversion table */
name|u_int16_t
name|b_dbcsrange
decl_stmt|;
comment|/* Start/End DBCS range pairs */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CPD_MAGIC
value|((u_int32_t)0x894521F7)
end_define

begin_struct
struct|struct
name|cpdsec
block|{
name|u_int32_t
name|d_magic
decl_stmt|;
name|u_int16_t
name|d_cpcnt
decl_stmt|;
comment|/* CP Data count */
name|u_int16_t
name|d_cpfirst
decl_stmt|;
comment|/* Index of first CP Data */
name|u_int32_t
name|d_checksum
index|[
literal|3
index|]
decl_stmt|;
comment|/* CP Data checksumms */
name|u_int16_t
name|d_offset
index|[
literal|3
index|]
decl_stmt|;
comment|/* Offsets of CP Data blocks */
name|struct
name|cpdblk
name|d_cpdblk
index|[
literal|3
index|]
decl_stmt|;
comment|/* Array of CP Data Blocks */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpiblk
block|{
name|u_int16_t
name|b_country
decl_stmt|;
comment|/* Country code */
name|u_int16_t
name|b_cpid
decl_stmt|;
comment|/* CP ID */
name|u_int32_t
name|b_checksum
decl_stmt|;
name|lsn_t
name|b_cpdsec
decl_stmt|;
comment|/* Pointer to CP Data Sector */
name|u_int16_t
name|b_vcpid
decl_stmt|;
comment|/* Volume spec. CP ID */
name|u_int16_t
name|b_dbcscnt
decl_stmt|;
comment|/* Count of DBCS ranges in CP */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CPI_MAGIC
value|((u_int32_t)0x494521F7)
end_define

begin_struct
struct|struct
name|cpisec
block|{
name|u_int32_t
name|s_magic
decl_stmt|;
name|u_int32_t
name|s_cpicnt
decl_stmt|;
comment|/* Count of CPI's in this sector */
name|u_int32_t
name|s_cpifirst
decl_stmt|;
comment|/* Index of first CPI in this sector */
name|lsn_t
name|s_next
decl_stmt|;
comment|/* Pointer to next CPI Sector */
name|struct
name|cpiblk
name|s_cpi
index|[
literal|0x1F
index|]
decl_stmt|;
comment|/* Array of CPI blocks */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hpfsmount
block|{
name|struct
name|sublock
name|hpm_su
decl_stmt|;
name|struct
name|spblock
name|hpm_sp
decl_stmt|;
name|struct
name|mount
modifier|*
name|hpm_mp
decl_stmt|;
name|struct
name|vnode
modifier|*
name|hpm_devvp
decl_stmt|;
name|dev_t
name|hpm_dev
decl_stmt|;
name|uid_t
name|hpm_uid
decl_stmt|;
name|gid_t
name|hpm_gid
decl_stmt|;
name|mode_t
name|hpm_mode
decl_stmt|;
name|lsn_t
modifier|*
name|hpm_bmind
decl_stmt|;
name|struct
name|cpdblk
modifier|*
name|hpm_cpdblk
decl_stmt|;
comment|/* Array of CP Data Blocks */
name|u_char
name|hpm_u2d
index|[
literal|0x80
index|]
decl_stmt|;
comment|/* Unix to DOS Table*/
name|u_char
name|hpm_d2u
index|[
literal|0x80
index|]
decl_stmt|;
comment|/* DOS to Unix Table*/
name|u_long
name|hpm_bavail
decl_stmt|;
comment|/* Blocks available */
name|u_long
name|hpm_dbnum
decl_stmt|;
comment|/* Data Band number */
name|u_int8_t
modifier|*
name|hpm_bitmap
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|H_HASHED
value|0x0001
end_define

begin_comment
comment|/* Present in hash */
end_comment

begin_define
define|#
directive|define
name|H_PARVALID
value|0x0002
end_define

begin_comment
comment|/* parent info is valid */
end_comment

begin_define
define|#
directive|define
name|H_CHANGE
value|0x0004
end_define

begin_comment
comment|/* node date was changed */
end_comment

begin_define
define|#
directive|define
name|H_PARCHANGE
value|0x0008
end_define

begin_comment
comment|/* parent node date was changed */
end_comment

begin_define
define|#
directive|define
name|H_INVAL
value|0x0010
end_define

begin_comment
comment|/* Invalid node */
end_comment

begin_struct
struct|struct
name|hpfsnode
block|{
name|struct
name|lock
name|h_lock
decl_stmt|;
comment|/* Must be first, for std vops */
name|struct
name|mtx
name|h_interlock
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|hpfsnode
argument_list|)
name|h_hash
expr_stmt|;
name|struct
name|hpfsmount
modifier|*
name|h_hpmp
decl_stmt|;
name|struct
name|fnode
name|h_fn
decl_stmt|;
name|struct
name|vnode
modifier|*
name|h_vp
decl_stmt|;
name|struct
name|vnode
modifier|*
name|h_devvp
decl_stmt|;
name|dev_t
name|h_dev
decl_stmt|;
name|lsn_t
name|h_no
decl_stmt|;
name|uid_t
name|h_uid
decl_stmt|;
name|gid_t
name|h_gid
decl_stmt|;
name|mode_t
name|h_mode
decl_stmt|;
name|u_int32_t
name|h_flag
decl_stmt|;
comment|/* parent dir information */
name|u_long
name|h_mtime
decl_stmt|;
name|u_long
name|h_atime
decl_stmt|;
name|u_long
name|h_ctime
decl_stmt|;
name|char
name|h_name
index|[
name|HPFS_MAXFILENAME
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Used to speedup dirent */
name|int
name|h_namelen
decl_stmt|;
comment|/* lookup */
block|}
struct|;
end_struct

begin_comment
comment|/* This overlays the fid structure (see<sys/mount.h>) */
end_comment

begin_struct
struct|struct
name|hpfid
block|{
name|u_int16_t
name|hpfid_len
decl_stmt|;
comment|/* Length of structure. */
name|u_int16_t
name|hpfid_pad
decl_stmt|;
comment|/* Force 32-bit alignment. */
name|lsn_t
name|hpfid_ino
decl_stmt|;
comment|/* File number (ino). */
name|int32_t
name|hpfid_gen
decl_stmt|;
comment|/* Generation number. */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HPFS_DEBUG
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
name|HPFS_DEBUG
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

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|300000
end_if

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_HPFSMNT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_HPFSNO
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VFSTOHPFS
parameter_list|(
name|mp
parameter_list|)
value|((struct hpfsmount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|VTOHP
parameter_list|(
name|v
parameter_list|)
value|((struct hpfsnode *)((v)->v_data))
end_define

begin_define
define|#
directive|define
name|HPTOV
parameter_list|(
name|h
parameter_list|)
value|((struct vnode *)((h)->h_vp))
end_define

begin_define
define|#
directive|define
name|FID
parameter_list|(
name|f
parameter_list|)
value|(*((lsn_t *)(f)->fid_data))
end_define

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|hpfs_vnodeop_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hash routines, too small to be separate header */
end_comment

begin_function_decl
name|void
name|hpfs_hphashinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hpfs_hphashdestroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hpfsnode
modifier|*
name|hpfs_hphashlookup
parameter_list|(
name|dev_t
parameter_list|,
name|lsn_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hpfsnode
modifier|*
name|hpfs_hphashget
parameter_list|(
name|dev_t
parameter_list|,
name|lsn_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hpfs_hphashvget
parameter_list|(
name|dev_t
parameter_list|,
name|lsn_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hpfs_hphashins
parameter_list|(
specifier|register
name|struct
name|hpfsnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hpfs_hphashrem
parameter_list|(
specifier|register
name|struct
name|hpfsnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|lock
name|hpfs_hphash_lock
decl_stmt|;
end_decl_stmt

end_unit

