begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	text.h	4.4	81/03/09	*/
end_comment

begin_comment
comment|/*  * Text structure.  * One allocated per pure  * procedure on swap device.  * Manipulated by text.c  */
end_comment

begin_define
define|#
directive|define
name|NXDAD
value|12
end_define

begin_comment
comment|/* param.h:MAXTSIZ / dmap.h:DMTEXT */
end_comment

begin_struct
struct|struct
name|text
block|{
name|swblk_t
name|x_daddr
index|[
name|NXDAD
index|]
decl_stmt|;
comment|/* disk addresses of DMTEXT-page segments */
name|swblk_t
name|x_ptdaddr
decl_stmt|;
comment|/* disk address of page table */
name|size_t
name|x_size
decl_stmt|;
comment|/* size (clicks) */
name|struct
name|proc
modifier|*
name|x_caddr
decl_stmt|;
comment|/* ptr to linked proc, if loaded */
name|struct
name|inode
modifier|*
name|x_iptr
decl_stmt|;
comment|/* inode of prototype */
name|short
name|x_rssize
decl_stmt|;
name|short
name|x_swrss
decl_stmt|;
name|char
name|x_count
decl_stmt|;
comment|/* reference count */
name|char
name|x_ccount
decl_stmt|;
comment|/* number of loaded references */
name|char
name|x_flag
decl_stmt|;
comment|/* traced, written flags */
name|char
name|x_slptime
decl_stmt|;
name|short
name|x_poip
decl_stmt|;
comment|/* page out in progress count */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|text
modifier|*
name|text
decl_stmt|,
modifier|*
name|textNTEXT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ntext
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XTRC
value|01
end_define

begin_comment
comment|/* Text may be written, exclusive use */
end_comment

begin_define
define|#
directive|define
name|XWRIT
value|02
end_define

begin_comment
comment|/* Text written into, must swap out */
end_comment

begin_define
define|#
directive|define
name|XLOAD
value|04
end_define

begin_comment
comment|/* Currently being read from file */
end_comment

begin_define
define|#
directive|define
name|XLOCK
value|010
end_define

begin_comment
comment|/* Being swapped in or out */
end_comment

begin_define
define|#
directive|define
name|XWANT
value|020
end_define

begin_comment
comment|/* Wanted for swapping */
end_comment

begin_define
define|#
directive|define
name|XPAGI
value|040
end_define

begin_comment
comment|/* Page in on demand from inode */
end_comment

end_unit

