begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	mbareg.h	3.2	%H%	*/
end_comment

begin_comment
comment|/*  * VAX Massbus adapter registers  */
end_comment

begin_struct
struct|struct
name|mba_regs
block|{
name|int
name|mba_csr
decl_stmt|;
name|int
name|mba_cr
decl_stmt|;
name|int
name|mba_sr
decl_stmt|;
name|int
name|mba_var
decl_stmt|;
name|int
name|mba_bcr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NOTE:  *	mba_erb at displacement 0x400  *	mba_as at displacement 0x410  *	mba_map at displacement 0x800  */
end_comment

begin_define
define|#
directive|define
name|MBA0
value|0x80064000
end_define

begin_define
define|#
directive|define
name|MBA1
value|0x80066000
end_define

begin_define
define|#
directive|define
name|MBA_ERB
value|0x400
end_define

begin_define
define|#
directive|define
name|MBA_MAP
value|0x800
end_define

begin_define
define|#
directive|define
name|MBA0_MAP
value|(MBA0 + 0x800)
end_define

begin_define
define|#
directive|define
name|MBA1_MAP
value|(MBA1 + 0x800)
end_define

begin_define
define|#
directive|define
name|MBAEBITS
value|0xe0770
end_define

begin_define
define|#
directive|define
name|MBAIE
value|0x4
end_define

end_unit

