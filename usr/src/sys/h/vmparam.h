begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vmparam.h	4.1	11/9/80	*/
end_comment

begin_comment
comment|/*  * Machine dependent constants  */
end_comment

begin_define
define|#
directive|define
name|NBBY
value|8
end_define

begin_comment
comment|/* number of bits in a byte */
end_comment

begin_define
define|#
directive|define
name|NBPG
value|512
end_define

begin_comment
comment|/* number of bytes per page */
end_comment

begin_define
define|#
directive|define
name|PGSHIFT
value|9
end_define

begin_comment
comment|/* LOG2(NBPG) */
end_comment

begin_define
define|#
directive|define
name|NPTEPG
value|(NBPG/(sizeof (struct pte)))
end_define

begin_comment
comment|/* number of ptes per page */
end_comment

begin_define
define|#
directive|define
name|PGOFSET
value|(NBPG-1)
end_define

begin_comment
comment|/* byte offset into page */
end_comment

begin_define
define|#
directive|define
name|CLOFSET
value|(CLSIZE*NBPG-1)
end_define

begin_comment
comment|/* for clusters, like PGOFSET */
end_comment

begin_define
define|#
directive|define
name|USRSTACK
value|(0x80000000-UPAGES*NBPG)
end_define

begin_comment
comment|/* Start of user stack */
end_comment

begin_define
define|#
directive|define
name|P1TOP
value|0x200000
end_define

begin_comment
comment|/* boundary between P0 and P1 regions */
end_comment

begin_define
define|#
directive|define
name|AST
value|0x04000000
end_define

begin_comment
comment|/* ast level */
end_comment

begin_comment
comment|/*  * Virtual memory related constants  *  * note: USRPTSIZE is well known in locore.s  */
end_comment

begin_define
define|#
directive|define
name|SLOP
value|16
end_define

begin_define
define|#
directive|define
name|MAXTSIZ
value|(6*2048-SLOP)
end_define

begin_comment
comment|/* max text size (clicks) */
end_comment

begin_define
define|#
directive|define
name|MAXDSIZ
value|(11*1024-16-SLOP)
end_define

begin_comment
comment|/* max data size (clicks) */
end_comment

begin_define
define|#
directive|define
name|MAXSSIZ
value|(11*1024-16-SLOP)
end_define

begin_comment
comment|/* max stack size (clicks) */
end_comment

begin_define
define|#
directive|define
name|USRPTSIZE
value|(8*NPTEPG)
end_define

begin_comment
comment|/* max number of pages of page tables 					   for resident processes, this is 					   known in locore.s */
end_comment

end_unit

