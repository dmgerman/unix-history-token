begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)mode.h	1.1 */
end_comment

begin_comment
comment|/*  *	UNIX shell  *	S. R. Bourne  *	Rewritten by David Korn  *  */
end_comment

begin_comment
comment|/* command tree for tretyp */
end_comment

begin_define
define|#
directive|define
name|COMBITS
value|4
end_define

begin_define
define|#
directive|define
name|COMMSK
value|((1<<COMBITS)-1)
end_define

begin_define
define|#
directive|define
name|COMSCAN
value|(01<<COMBITS)
end_define

begin_define
define|#
directive|define
name|FPRS
value|(01<<COMBITS)
end_define

begin_define
define|#
directive|define
name|FINT
value|(02<<COMBITS)
end_define

begin_define
define|#
directive|define
name|FAMP
value|(04<<COMBITS)
end_define

begin_define
define|#
directive|define
name|FTMP
value|(010<<COMBITS)
end_define

begin_define
define|#
directive|define
name|FPIN
value|(020<<COMBITS)
end_define

begin_define
define|#
directive|define
name|FPOU
value|(040<<COMBITS)
end_define

begin_define
define|#
directive|define
name|FPCL
value|(0100<<COMBITS)
end_define

begin_define
define|#
directive|define
name|FCMD
value|(0200<<COMBITS)
end_define

begin_define
define|#
directive|define
name|FCOMSUB
value|(0400<<COMBITS)
end_define

begin_define
define|#
directive|define
name|TCOM
value|0
end_define

begin_define
define|#
directive|define
name|TPAR
value|1
end_define

begin_define
define|#
directive|define
name|TFIL
value|2
end_define

begin_define
define|#
directive|define
name|TLST
value|3
end_define

begin_define
define|#
directive|define
name|TIF
value|4
end_define

begin_define
define|#
directive|define
name|TWH
value|5
end_define

begin_define
define|#
directive|define
name|TUN
value|6
end_define

begin_define
define|#
directive|define
name|TSW
value|7
end_define

begin_define
define|#
directive|define
name|TAND
value|8
end_define

begin_define
define|#
directive|define
name|TORF
value|9
end_define

begin_define
define|#
directive|define
name|TFORK
value|10
end_define

begin_define
define|#
directive|define
name|TFOR
value|11
end_define

begin_define
define|#
directive|define
name|TSELECT
value|12
end_define

begin_define
define|#
directive|define
name|TTIME
value|13
end_define

begin_define
define|#
directive|define
name|TSETIO
value|14
end_define

begin_define
define|#
directive|define
name|TPROC
value|15
end_define

begin_comment
comment|/* heap storage */
end_comment

begin_comment
comment|/* this node is a proforma for those that follow */
end_comment

begin_struct
struct|struct
name|trenod
block|{
name|int
name|tretyp
decl_stmt|;
name|IOPTR
name|treio
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dolnod
block|{
name|DOLPTR
name|dolnxt
decl_stmt|;
name|int
name|doluse
decl_stmt|;
name|char
modifier|*
name|dolarg
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|forknod
block|{
name|int
name|forktyp
decl_stmt|;
name|IOPTR
name|forkio
decl_stmt|;
name|TREPTR
name|forktre
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|comnod
block|{
name|int
name|comtyp
decl_stmt|;
name|IOPTR
name|comio
decl_stmt|;
name|ARGPTR
name|comarg
decl_stmt|;
name|ARGPTR
name|comset
decl_stmt|;
name|int
name|comline
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ifnod
block|{
name|int
name|iftyp
decl_stmt|;
name|TREPTR
name|iftre
decl_stmt|;
name|TREPTR
name|thtre
decl_stmt|;
name|TREPTR
name|eltre
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|whnod
block|{
name|int
name|whtyp
decl_stmt|;
name|TREPTR
name|whtre
decl_stmt|;
name|TREPTR
name|dotre
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fornod
block|{
name|int
name|fortyp
decl_stmt|;
name|TREPTR
name|fortre
decl_stmt|;
name|char
modifier|*
name|fornam
decl_stmt|;
name|COMPTR
name|forlst
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|swnod
block|{
name|int
name|swtyp
decl_stmt|;
name|char
modifier|*
name|swarg
decl_stmt|;
name|REGPTR
name|swlst
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|regnod
block|{
name|ARGPTR
name|regptr
decl_stmt|;
name|TREPTR
name|regcom
decl_stmt|;
name|REGPTR
name|regnxt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|parnod
block|{
name|int
name|partyp
decl_stmt|;
name|TREPTR
name|partre
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lstnod
block|{
name|int
name|lsttyp
decl_stmt|;
name|TREPTR
name|lstlef
decl_stmt|;
name|TREPTR
name|lstrit
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|procnod
block|{
name|int
name|proctyp
decl_stmt|;
name|BLKPTR
name|proctre
decl_stmt|;
name|char
modifier|*
name|procnam
decl_stmt|;
name|long
name|procloc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FORKTYPE
value|(sizeof(struct forknod))
end_define

begin_define
define|#
directive|define
name|COMTYPE
value|(sizeof(struct comnod))
end_define

begin_define
define|#
directive|define
name|IFTYPE
value|(sizeof(struct ifnod))
end_define

begin_define
define|#
directive|define
name|WHTYPE
value|(sizeof(struct whnod))
end_define

begin_define
define|#
directive|define
name|FORTYPE
value|(sizeof(struct fornod))
end_define

begin_define
define|#
directive|define
name|SWTYPE
value|(sizeof(struct swnod))
end_define

begin_define
define|#
directive|define
name|REGTYPE
value|(sizeof(struct regnod))
end_define

begin_define
define|#
directive|define
name|PARTYPE
value|(sizeof(struct parnod))
end_define

begin_define
define|#
directive|define
name|LSTTYPE
value|(sizeof(struct lstnod))
end_define

begin_define
define|#
directive|define
name|DOLTYPE
value|(sizeof(struct dolnod))
end_define

begin_define
define|#
directive|define
name|PROCTYPE
value|(sizeof(struct procnod))
end_define

end_unit

