begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)defs.h	1.3 (CWI) 86/11/13	*/
end_comment

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|MAXLIN
value|200
end_define

begin_comment
comment|/*  * Maximum columns to be output  */
end_comment

begin_define
define|#
directive|define
name|MAXCOL
value|30
end_define

begin_comment
comment|/*  * MAXCOL is amount of columns to be specified per column  *  *  for relation of MAXCOL and MAXHEAD, see next example:  *	.TS 	l l l		) 	a s s		) Maximum MAXHEAD 	r r n.		) 	----- 	  | 	  Maximum MAXCOL  *  * Every table can be MAXCOL, with in each column MAXHEAD  * specification (lines)  *  * Don't make MAXCOL bigger width adjusting nregs in globals.c (bwk)  */
end_comment

begin_define
define|#
directive|define
name|MAXHEAD
value|44
end_define

begin_define
define|#
directive|define
name|MAXCHS
value|2000
end_define

begin_define
define|#
directive|define
name|MAXRPT
value|100
end_define

begin_define
define|#
directive|define
name|CLLEN
value|10
end_define

begin_define
define|#
directive|define
name|SHORTLINE
value|4
end_define

begin_define
define|#
directive|define
name|ZEROW
value|001
end_define

begin_define
define|#
directive|define
name|HALFUP
value|002
end_define

begin_define
define|#
directive|define
name|CTOP
value|004
end_define

begin_define
define|#
directive|define
name|CDOWN
value|010
end_define

begin_define
define|#
directive|define
name|CLEFT
value|000
end_define

begin_define
define|#
directive|define
name|CMID
value|001
end_define

begin_define
define|#
directive|define
name|CRIGHT
value|002
end_define

begin_define
define|#
directive|define
name|S1
value|31
end_define

begin_define
define|#
directive|define
name|S2
value|32
end_define

begin_define
define|#
directive|define
name|TMP
value|38
end_define

begin_define
define|#
directive|define
name|SF
value|35
end_define

begin_define
define|#
directive|define
name|SL
value|34
end_define

begin_define
define|#
directive|define
name|LSIZE
value|33
end_define

begin_define
define|#
directive|define
name|SIND
value|37
end_define

begin_define
define|#
directive|define
name|SVS
value|36
end_define

begin_define
define|#
directive|define
name|LEFT
value|1
end_define

begin_define
define|#
directive|define
name|RIGHT
value|2
end_define

begin_define
define|#
directive|define
name|THRU
value|3
end_define

begin_define
define|#
directive|define
name|TOP
value|1
end_define

begin_define
define|#
directive|define
name|BOT
value|2
end_define

begin_define
define|#
directive|define
name|MACROS
value|"/usr/lib/tmac.s"
end_define

begin_define
define|#
directive|define
name|PYMACS
value|"/usr/lib/tmac.m"
end_define

begin_comment
comment|/* devices supported */
end_comment

begin_define
define|#
directive|define
name|DEVPSC
value|3
end_define

begin_define
define|#
directive|define
name|DEVVER
value|2
end_define

begin_define
define|#
directive|define
name|HARRIS
value|1
end_define

begin_define
define|#
directive|define
name|CAT
value|0
end_define

begin_struct
struct|struct
name|colstr
block|{
name|char
modifier|*
name|col
decl_stmt|,
modifier|*
name|rcol
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|dprint
value|if(dbg)printf
end_define

end_unit

