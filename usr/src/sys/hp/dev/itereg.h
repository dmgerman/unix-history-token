begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: itereg.h 1.2 89/08/25$  *  *	@(#)itereg.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|REGADDR
value|ip->regbase
end_define

begin_define
define|#
directive|define
name|FBBASE
value|((volatile u_char *)ip->fbbase)
end_define

begin_define
define|#
directive|define
name|FONTROM
value|((u_char *)(REGADDR+0x3B))
end_define

begin_define
define|#
directive|define
name|ITEREGS
value|((struct iteregs *)(REGADDR))
end_define

begin_comment
comment|/*  * All of the HP displays use the same font ROM setup. These structures  * are used to get at them.  */
end_comment

begin_struct
struct|struct
name|iteregs
block|{
name|u_short
name|reset
decl_stmt|;
name|u_short
name|interrupt
decl_stmt|;
name|u_char
label|:
literal|8
operator|,
name|fbwidth_h
operator|,
operator|:
literal|8
operator|,
name|fbwidth_l
operator|,
operator|:
literal|8
operator|,
name|fbheight_h
operator|,
operator|:
literal|8
operator|,
name|fbheight_l
operator|,
operator|:
literal|8
operator|,
name|dispwidth_h
operator|,
operator|:
literal|8
operator|,
name|dispwidth_l
operator|,
operator|:
literal|8
operator|,
name|dispheight_h
operator|,
operator|:
literal|8
operator|,
name|dispheight_l
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fontinfo
block|{
name|u_char
name|nfonts
decl_stmt|,
range|:
literal|8
decl_stmt|,
name|fontid
decl_stmt|,
range|:
literal|8
decl_stmt|,
name|haddr
decl_stmt|,
range|:
literal|8
decl_stmt|,
name|laddr
decl_stmt|,
range|:
literal|8
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|font
block|{
name|u_char
name|fh
decl_stmt|,
range|:
literal|8
decl_stmt|,
name|fw
decl_stmt|;
name|u_char
name|pad
index|[
literal|7
index|]
decl_stmt|,
name|data
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|draw_cursor
parameter_list|(
name|ip
parameter_list|)
value|{ \ 	WINDOWMOVER(ip, ip->cblanky, ip->cblankx, \ 		    ip->cury * ip->ftheight, \ 		    ip->curx * ip->ftwidth, \ 		    ip->ftheight, ip->ftwidth, RR_XOR); \         ip->cursorx = ip->curx; \ 	ip->cursory = ip->cury; }
end_define

begin_define
define|#
directive|define
name|erase_cursor
parameter_list|(
name|ip
parameter_list|)
define|\
value|WINDOWMOVER(ip, ip->cblanky, ip->cblankx, \ 		    ip->cursory * ip->ftheight, \ 		    ip->cursorx * ip->ftwidth, \ 		    ip->ftheight, ip->ftwidth, RR_XOR);
end_define

end_unit

