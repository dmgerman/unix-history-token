begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD$	 */
end_comment

begin_comment
comment|/* $FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000 Masaru OKI  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PECOFF_EXEC_H_
end_ifndef

begin_define
define|#
directive|define
name|_PECOFF_EXEC_H_
end_define

begin_struct
struct|struct
name|pecoff_dos_filehdr
block|{
name|u_int16_t
name|d_magic
decl_stmt|;
comment|/* +0x00 'MZ' */
name|u_int8_t
name|d_stub
index|[
literal|0x3a
index|]
decl_stmt|;
name|u_int32_t
name|d_peofs
decl_stmt|;
comment|/* +0x3c */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PECOFF_DOS_MAGIC
value|0x5a4d
end_define

begin_define
define|#
directive|define
name|PECOFF_DOS_HDR_SIZE
value|(sizeof(struct pecoff_dos_filehdr))
end_define

begin_define
define|#
directive|define
name|DOS_BADMAG
parameter_list|(
name|dp
parameter_list|)
value|((dp)->d_magic != PECOFF_DOS_MAGIC)
end_define

begin_comment
comment|/*  * COFF file header  */
end_comment

begin_struct
struct|struct
name|coff_filehdr
block|{
name|u_short
name|f_magic
decl_stmt|;
comment|/* magic number */
name|u_short
name|f_nscns
decl_stmt|;
comment|/* # of sections */
name|long
name|f_timdat
decl_stmt|;
comment|/* timestamp */
name|long
name|f_symptr
decl_stmt|;
comment|/* file offset of symbol table */
name|long
name|f_nsyms
decl_stmt|;
comment|/* # of symbol table entries */
name|u_short
name|f_opthdr
decl_stmt|;
comment|/* size of optional header */
name|u_short
name|f_flags
decl_stmt|;
comment|/* flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  * COFF system header  */
end_comment

begin_struct
struct|struct
name|coff_aouthdr
block|{
name|short
name|a_magic
decl_stmt|;
name|short
name|a_vstamp
decl_stmt|;
name|long
name|a_tsize
decl_stmt|;
name|long
name|a_dsize
decl_stmt|;
name|long
name|a_bsize
decl_stmt|;
name|long
name|a_entry
decl_stmt|;
name|long
name|a_tstart
decl_stmt|;
name|long
name|a_dstart
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* magic */
end_comment

begin_define
define|#
directive|define
name|COFF_OMAGIC
value|0407
end_define

begin_comment
comment|/* text not write-protected; data seg is 				 * contiguous with text */
end_comment

begin_define
define|#
directive|define
name|COFF_NMAGIC
value|0410
end_define

begin_comment
comment|/* text is write-protected; data starts at 				 * next seg following text */
end_comment

begin_define
define|#
directive|define
name|COFF_ZMAGIC
value|0413
end_define

begin_comment
comment|/* text and data segs are aligned for direct 				 * paging */
end_comment

begin_define
define|#
directive|define
name|COFF_SMAGIC
value|0443
end_define

begin_comment
comment|/* shared lib */
end_comment

begin_struct
struct|struct
name|pecoff_imghdr
block|{
name|long
name|i_vaddr
decl_stmt|;
name|long
name|i_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pecoff_opthdr
block|{
name|long
name|w_base
decl_stmt|;
name|long
name|w_salign
decl_stmt|;
name|long
name|w_falign
decl_stmt|;
name|long
name|w_osvers
decl_stmt|;
name|long
name|w_imgvers
decl_stmt|;
name|long
name|w_subvers
decl_stmt|;
name|long
name|w_rsvd
decl_stmt|;
name|long
name|w_imgsize
decl_stmt|;
name|long
name|w_hdrsize
decl_stmt|;
name|long
name|w_chksum
decl_stmt|;
name|u_short
name|w_subsys
decl_stmt|;
name|u_short
name|w_dllflags
decl_stmt|;
name|long
name|w_ssize
decl_stmt|;
name|long
name|w_cssize
decl_stmt|;
name|long
name|w_hsize
decl_stmt|;
name|long
name|w_chsize
decl_stmt|;
name|long
name|w_lflag
decl_stmt|;
name|long
name|w_nimghdr
decl_stmt|;
name|struct
name|pecoff_imghdr
name|w_imghdr
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * COFF section header  */
end_comment

begin_struct
struct|struct
name|coff_scnhdr
block|{
name|char
name|s_name
index|[
literal|8
index|]
decl_stmt|;
name|long
name|s_paddr
decl_stmt|;
name|long
name|s_vaddr
decl_stmt|;
name|long
name|s_size
decl_stmt|;
name|long
name|s_scnptr
decl_stmt|;
name|long
name|s_relptr
decl_stmt|;
name|long
name|s_lnnoptr
decl_stmt|;
name|u_short
name|s_nreloc
decl_stmt|;
name|u_short
name|s_nlnno
decl_stmt|;
name|long
name|s_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* s_flags */
end_comment

begin_define
define|#
directive|define
name|COFF_STYP_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|COFF_STYP_DSECT
value|0x01
end_define

begin_define
define|#
directive|define
name|COFF_STYP_NOLOAD
value|0x02
end_define

begin_define
define|#
directive|define
name|COFF_STYP_GROUP
value|0x04
end_define

begin_define
define|#
directive|define
name|COFF_STYP_PAD
value|0x08
end_define

begin_define
define|#
directive|define
name|COFF_STYP_COPY
value|0x10
end_define

begin_define
define|#
directive|define
name|COFF_STYP_TEXT
value|0x20
end_define

begin_define
define|#
directive|define
name|COFF_STYP_DATA
value|0x40
end_define

begin_define
define|#
directive|define
name|COFF_STYP_BSS
value|0x80
end_define

begin_define
define|#
directive|define
name|COFF_STYP_INFO
value|0x200
end_define

begin_define
define|#
directive|define
name|COFF_STYP_OVER
value|0x400
end_define

begin_define
define|#
directive|define
name|COFF_STYP_SHLIB
value|0x800
end_define

begin_comment
comment|/* s_flags for PE */
end_comment

begin_define
define|#
directive|define
name|COFF_STYP_DISCARD
value|0x2000000
end_define

begin_define
define|#
directive|define
name|COFF_STYP_EXEC
value|0x20000000
end_define

begin_define
define|#
directive|define
name|COFF_STYP_READ
value|0x40000000
end_define

begin_define
define|#
directive|define
name|COFF_STYP_WRITE
value|0x80000000
end_define

begin_struct
struct|struct
name|pecoff_args
block|{
name|u_long
name|a_base
decl_stmt|;
name|u_long
name|a_entry
decl_stmt|;
name|u_long
name|a_end
decl_stmt|;
name|u_long
name|a_subsystem
decl_stmt|;
name|struct
name|pecoff_imghdr
name|a_imghdr
index|[
literal|16
index|]
decl_stmt|;
name|u_long
name|a_ldbase
decl_stmt|;
name|u_long
name|a_ldexport
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|COFF_LDPGSZ
value|4096
end_define

begin_define
define|#
directive|define
name|COFF_ALIGN
parameter_list|(
name|a
parameter_list|)
value|((a)& ~(COFF_LDPGSZ - 1))
end_define

begin_define
define|#
directive|define
name|COFF_ROUND
parameter_list|(
name|a
parameter_list|)
value|COFF_ALIGN((a) + COFF_LDPGSZ - 1)
end_define

begin_define
define|#
directive|define
name|COFF_HDR_SIZE
define|\
value|(sizeof(struct coff_filehdr) + sizeof(struct coff_aouthdr))
end_define

begin_define
define|#
directive|define
name|PECOFF_HDR_SIZE
value|(COFF_HDR_SIZE + sizeof(struct pecoff_opthdr))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

