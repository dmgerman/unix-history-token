begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	scnhdr.h	1.1	87/11/15	*/
end_comment

begin_comment
comment|/*	@(#)scnhdr.h	2.2 12/15/82	*/
end_comment

begin_struct
struct|struct
name|scnhdr
block|{
name|char
name|s_name
index|[
literal|8
index|]
decl_stmt|;
comment|/* section name */
name|long
name|s_paddr
decl_stmt|;
comment|/* physical address */
name|long
name|s_vaddr
decl_stmt|;
comment|/* virtual address */
name|long
name|s_size
decl_stmt|;
comment|/* section size */
name|long
name|s_scnptr
decl_stmt|;
comment|/* file ptr to raw data for section */
name|long
name|s_relptr
decl_stmt|;
comment|/* file ptr to relocation */
name|long
name|s_lnnoptr
decl_stmt|;
comment|/* file ptr to line numbers */
name|unsigned
name|short
name|s_nreloc
decl_stmt|;
comment|/* number of relocation entries */
name|unsigned
name|short
name|s_nlnno
decl_stmt|;
comment|/* number of line number entries */
name|long
name|s_flags
decl_stmt|;
comment|/* flags */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCNHDR
value|struct scnhdr
end_define

begin_define
define|#
directive|define
name|SCNHSZ
value|sizeof(SCNHDR)
end_define

begin_comment
comment|/*  * Define constants for names of "special" sections  */
end_comment

begin_define
define|#
directive|define
name|_TEXT
value|".text"
end_define

begin_define
define|#
directive|define
name|_DATA
value|".data"
end_define

begin_define
define|#
directive|define
name|_BSS
value|".bss"
end_define

begin_define
define|#
directive|define
name|_TV
value|".tv"
end_define

begin_comment
comment|/*  * The low 4 bits of s_flags is used as a section "type"  */
end_comment

begin_define
define|#
directive|define
name|STYP_REG
value|0x00
end_define

begin_comment
comment|/* "regular" section: 						allocated, relocated, loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_DSECT
value|0x01
end_define

begin_comment
comment|/* "dummy" section: 						not allocated, relocated, 						not loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_NOLOAD
value|0x02
end_define

begin_comment
comment|/* "noload" section: 						allocated, relocated, 						 not loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_GROUP
value|0x04
end_define

begin_comment
comment|/* "grouped" section: 						formed of input sections */
end_comment

begin_define
define|#
directive|define
name|STYP_PAD
value|0x08
end_define

begin_comment
comment|/* "padding" section: 						not allocated, not relocated, 						 loaded */
end_comment

begin_define
define|#
directive|define
name|STYP_COPY
value|0x10
end_define

begin_comment
comment|/* "copy" section: 						for decision function used 						by field update;  not 						allocated, not relocated, 						loaded;  reloc& lineno 						entries processed normally */
end_comment

begin_define
define|#
directive|define
name|STYP_TEXT
value|0x20
end_define

begin_comment
comment|/* section contains text only */
end_comment

begin_define
define|#
directive|define
name|STYP_DATA
value|0x40
end_define

begin_comment
comment|/* section contains data only */
end_comment

begin_define
define|#
directive|define
name|STYP_BSS
value|0x80
end_define

begin_comment
comment|/* section contains bss only */
end_comment

begin_comment
comment|/*  *  In a minimal file or an update file, a new function  *  (as compared with a replaced function) is indicated by S_NEWFCN  */
end_comment

begin_define
define|#
directive|define
name|S_NEWFCN
value|0x10
end_define

begin_comment
comment|/*  * In 3b Update Files (output of ogen), sections which appear in SHARED  * segments of the Pfile will have the S_SHRSEG flag set by ogen, to inform  * dufr that updating 1 copy of the proc. will update all process invocations.  */
end_comment

begin_define
define|#
directive|define
name|S_SHRSEG
value|0x20
end_define

end_unit

