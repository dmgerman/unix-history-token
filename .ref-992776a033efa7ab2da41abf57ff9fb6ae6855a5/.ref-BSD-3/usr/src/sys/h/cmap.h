begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	cmap.h	2.1	1/5/80	*/
end_comment

begin_comment
comment|/*  * core map entry  *  * N.B.: sizeof (struct cmap) is well known in cmap.m  */
end_comment

begin_struct
struct|struct
name|cmap
block|{
name|unsigned
name|int
name|c_next
range|:
literal|14
decl_stmt|,
comment|/* index of next free list entry */
name|c_page
range|:
literal|17
decl_stmt|,
comment|/* virtual page number in segment */
name|c_intrans
range|:
literal|1
decl_stmt|,
comment|/* intransit bit */
name|c_prev
range|:
literal|14
decl_stmt|,
comment|/* index of previous free list entry */
name|c_ndx
range|:
literal|10
decl_stmt|,
comment|/* index of owner proc or text */
name|c_flag
range|:
literal|8
decl_stmt|;
comment|/* flags */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CMHEAD
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|cmap
modifier|*
name|cmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cmap
modifier|*
name|ecmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|firstfree
decl_stmt|,
name|maxfree
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bits defined in c_flag */
end_comment

begin_define
define|#
directive|define
name|MTEXT
value|0x01
end_define

begin_comment
comment|/* belongs to shared text segment */
end_comment

begin_define
define|#
directive|define
name|MDATA
value|0x02
end_define

begin_comment
comment|/* belongs to data segment */
end_comment

begin_define
define|#
directive|define
name|MSTACK
value|0x04
end_define

begin_comment
comment|/* belongs to stack segment */
end_comment

begin_define
define|#
directive|define
name|MSYS
value|0x08
end_define

begin_comment
comment|/* allocated to u area */
end_comment

begin_define
define|#
directive|define
name|MGONE
value|0x10
end_define

begin_comment
comment|/* associated page has been released */
end_comment

begin_define
define|#
directive|define
name|MFREE
value|0x20
end_define

begin_comment
comment|/* on the free list */
end_comment

begin_define
define|#
directive|define
name|MLOCK
value|0x40
end_define

begin_comment
comment|/* locked for raw i/o or pagein */
end_comment

begin_define
define|#
directive|define
name|MWANT
value|0x80
end_define

begin_comment
comment|/* wanted */
end_comment

begin_define
define|#
directive|define
name|pgtocm
parameter_list|(
name|x
parameter_list|)
value|((((x)-firstfree) / CLSIZE) + 1)
end_define

begin_define
define|#
directive|define
name|cmtopg
parameter_list|(
name|x
parameter_list|)
value|((((x)-1) * CLSIZE) + firstfree)
end_define

end_unit

