begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	def.h	4.2	83/08/11	*/
end_comment

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|P
parameter_list|,
name|R
parameter_list|)
value|{if (!(P)) {fprintf(stderr,"failed assertion in routine R: P\n"); abort();}}
end_define

begin_decl_stmt
specifier|extern
name|int
name|routnum
decl_stmt|,
name|routerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|rtnbeg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of chars up to beginnine of curernt routing */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
modifier|*
name|graph
decl_stmt|,
name|nodenum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|stopflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* turns off generation of stop statements */
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|LOGICAL
value|int
end_define

begin_define
define|#
directive|define
name|VERT
value|int
end_define

begin_define
define|#
directive|define
name|DEFINED
parameter_list|(
name|v
parameter_list|)
value|(v>= 0)
end_define

begin_define
define|#
directive|define
name|UNDEFINED
value|-1
end_define

begin_comment
comment|/* node types */
end_comment

begin_define
define|#
directive|define
name|STLNVX
value|0
end_define

begin_define
define|#
directive|define
name|IFVX
value|1
end_define

begin_define
define|#
directive|define
name|DOVX
value|2
end_define

begin_define
define|#
directive|define
name|IOVX
value|3
end_define

begin_define
define|#
directive|define
name|FMTVX
value|4
end_define

begin_define
define|#
directive|define
name|COMPVX
value|5
end_define

begin_define
define|#
directive|define
name|ASVX
value|6
end_define

begin_define
define|#
directive|define
name|ASGOVX
value|7
end_define

begin_define
define|#
directive|define
name|LOOPVX
value|8
end_define

begin_define
define|#
directive|define
name|WHIVX
value|9
end_define

begin_define
define|#
directive|define
name|UNTVX
value|10
end_define

begin_define
define|#
directive|define
name|ITERVX
value|11
end_define

begin_define
define|#
directive|define
name|THENVX
value|12
end_define

begin_define
define|#
directive|define
name|STOPVX
value|13
end_define

begin_define
define|#
directive|define
name|RETVX
value|14
end_define

begin_define
define|#
directive|define
name|DUMVX
value|15
end_define

begin_define
define|#
directive|define
name|GOVX
value|16
end_define

begin_define
define|#
directive|define
name|BRKVX
value|17
end_define

begin_define
define|#
directive|define
name|NXTVX
value|18
end_define

begin_define
define|#
directive|define
name|SWCHVX
value|19
end_define

begin_define
define|#
directive|define
name|ACASVX
value|20
end_define

begin_define
define|#
directive|define
name|ICASVX
value|21
end_define

begin_define
define|#
directive|define
name|TYPENUM
value|22
end_define

begin_decl_stmt
specifier|extern
name|int
name|hascom
index|[
name|TYPENUM
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* FALSE for types with no comments, 2 otherwise */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nonarcs
index|[
name|TYPENUM
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of wds per node other than arcs */
end_comment

begin_decl_stmt
specifier|extern
name|VERT
modifier|*
name|arc
argument_list|()
decl_stmt|,
modifier|*
name|lchild
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|vxpart
argument_list|()
decl_stmt|,
modifier|*
name|negpart
argument_list|()
decl_stmt|,
modifier|*
name|predic
argument_list|()
decl_stmt|,
modifier|*
name|expres
argument_list|()
decl_stmt|,
modifier|*
name|level
argument_list|()
decl_stmt|,
modifier|*
name|stlfmt
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* node parts */
end_comment

begin_define
define|#
directive|define
name|FIXED
value|4
end_define

begin_comment
comment|/* number of wds needed in every node */
end_comment

begin_define
define|#
directive|define
name|NTYPE
parameter_list|(
name|v
parameter_list|)
value|graph[v][0]
end_define

begin_define
define|#
directive|define
name|BEGCOM
parameter_list|(
name|v
parameter_list|)
value|graph[v][1]
end_define

begin_define
define|#
directive|define
name|RSIB
parameter_list|(
name|v
parameter_list|)
value|graph[v][2]
end_define

begin_define
define|#
directive|define
name|REACH
parameter_list|(
name|v
parameter_list|)
value|graph[v][3]
end_define

begin_define
define|#
directive|define
name|LCHILD
parameter_list|(
name|v
parameter_list|,
name|i
parameter_list|)
value|*lchild(v,i)
end_define

begin_define
define|#
directive|define
name|CHILDNUM
parameter_list|(
name|v
parameter_list|)
value|childper[NTYPE(v)]
end_define

begin_define
define|#
directive|define
name|ARC
parameter_list|(
name|v
parameter_list|,
name|i
parameter_list|)
value|*arc(v,i)
end_define

begin_define
define|#
directive|define
name|ARCNUM
parameter_list|(
name|v
parameter_list|)
value|*((arcsper[NTYPE(v)]>= 0) ?&arcsper[NTYPE(v)]:&graph[v][-arcsper[NTYPE(v)]])
end_define

begin_comment
comment|/* STLNVX, FMTVX parts */
end_comment

begin_define
define|#
directive|define
name|BEGCODE
parameter_list|(
name|v
parameter_list|)
value|*stlfmt(v,0)
end_define

begin_comment
comment|/* 1st char of line on disk or address of string */
end_comment

begin_define
define|#
directive|define
name|ONDISK
parameter_list|(
name|v
parameter_list|)
value|*stlfmt(v,1)
end_define

begin_comment
comment|/* FALSE if in core,# of lines on disk otherwise */
end_comment

begin_define
define|#
directive|define
name|CODELINES
parameter_list|(
name|v
parameter_list|)
value|*vxpart(v,STLNVX,2)
end_define

begin_comment
comment|/* # of statements stored in node */
end_comment

begin_comment
comment|/* IOVX parts */
end_comment

begin_define
define|#
directive|define
name|FMTREF
parameter_list|(
name|v
parameter_list|)
value|*vxpart(v,IOVX,0)
end_define

begin_comment
comment|/* FMTVX associated with i/o statememt */
end_comment

begin_define
define|#
directive|define
name|PRERW
parameter_list|(
name|v
parameter_list|)
value|*vxpart(v,IOVX,1)
end_define

begin_comment
comment|/* string occurring in i/o statement before parts with labels */
end_comment

begin_define
define|#
directive|define
name|POSTRW
parameter_list|(
name|v
parameter_list|)
value|*vxpart(v,IOVX,2)
end_define

begin_comment
comment|/* string occurring in i/o statement after parts wih labels */
end_comment

begin_define
define|#
directive|define
name|ENDEQ
value|1
end_define

begin_comment
comment|/* arc number associated with endeq */
end_comment

begin_define
define|#
directive|define
name|ERREQ
value|2
end_define

begin_comment
comment|/* arc number associated wth erreq */
end_comment

begin_comment
comment|/* ITERVX parts */
end_comment

begin_define
define|#
directive|define
name|NXT
parameter_list|(
name|v
parameter_list|)
value|*vxpart(v,ITERVX,0)
end_define

begin_comment
comment|/* THENVX containing condition for iteration for WHILE or UNTIL */
end_comment

begin_define
define|#
directive|define
name|FATH
parameter_list|(
name|v
parameter_list|)
value|*vxpart(v,ITERVX,1)
end_define

begin_comment
comment|/* father of v */
end_comment

begin_define
define|#
directive|define
name|LPRED
parameter_list|(
name|v
parameter_list|)
value|*vxpart(v,ITERVX,2)
end_define

begin_comment
comment|/* loop predicate for WHILE, UNTIL */
end_comment

begin_comment
comment|/*DOVX parts */
end_comment

begin_define
define|#
directive|define
name|INC
parameter_list|(
name|v
parameter_list|)
value|*vxpart(v,DOVX,0)
end_define

begin_comment
comment|/* string for iteration condition of DO */
end_comment

begin_comment
comment|/* IFVX,THENVX parts */
end_comment

begin_define
define|#
directive|define
name|PRED
parameter_list|(
name|v
parameter_list|)
value|*predic(v)
end_define

begin_comment
comment|/* string containing predicate */
end_comment

begin_define
define|#
directive|define
name|NEG
parameter_list|(
name|v
parameter_list|)
value|*negpart(v)
end_define

begin_comment
comment|/* TRUE if predicate negated */
end_comment

begin_define
define|#
directive|define
name|THEN
value|0
end_define

begin_comment
comment|/* arc number of true branch */
end_comment

begin_define
define|#
directive|define
name|ELSE
value|1
end_define

begin_comment
comment|/* arc number of false branch */
end_comment

begin_comment
comment|/* miscellaneous parts */
end_comment

begin_define
define|#
directive|define
name|EXP
parameter_list|(
name|v
parameter_list|)
value|*expres(v)
end_define

begin_comment
comment|/* expression - ASVX, COMPVX, ASGOVX, SWCHVX, ICASVX */
end_comment

begin_define
define|#
directive|define
name|LABREF
parameter_list|(
name|v
parameter_list|)
value|*vxpart(v,ASVX,1)
end_define

begin_comment
comment|/* node referred to by label in ASSIGN statement */
end_comment

begin_comment
comment|/* BRKVX, NXTVX parts */
end_comment

begin_define
define|#
directive|define
name|LEVEL
parameter_list|(
name|v
parameter_list|)
value|*level(v)
end_define

begin_comment
comment|/* also COMPVX, ASGOVX, SWCHVX, and DUMVX contain wd for number of arcs */
end_comment

begin_comment
comment|/* location of this wd specified by negative entry in arcsper */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arcsper
index|[
name|TYPENUM
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* also nodes contain wds for children as specified by childper */
end_comment

begin_extern
extern|extern childper[TYPENUM];
end_extern

begin_comment
comment|/* switches */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|intcase
decl_stmt|,
name|arbcase
decl_stmt|,
name|whiloop
decl_stmt|,
name|invelse
decl_stmt|,
name|exitsize
decl_stmt|,
name|maxnode
decl_stmt|,
name|maxhash
decl_stmt|,
name|progress
decl_stmt|,
name|labinit
decl_stmt|,
name|labinc
decl_stmt|,
name|inputform
decl_stmt|,
name|debug
decl_stmt|,
name|levbrk
decl_stmt|,
name|levnxt
decl_stmt|,
name|mkunt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* arrays */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|after
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|typename
index|[]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|list
block|{
name|VERT
name|elt
decl_stmt|;
name|struct
name|list
modifier|*
name|nxtlist
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|list
modifier|*
name|append
argument_list|()
decl_stmt|,
modifier|*
name|consl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|VERT
name|retvert
decl_stmt|,
name|stopvert
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* specifies unique return and stop vertices */
end_comment

begin_decl_stmt
specifier|extern
name|VERT
name|START
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|progtype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* type of program - main or sub or blockdata */
end_comment

begin_define
define|#
directive|define
name|sub
value|1
end_define

begin_define
define|#
directive|define
name|blockdata
value|2
end_define

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|infd
decl_stmt|,
modifier|*
name|debfd
decl_stmt|,
modifier|*
name|outfd
decl_stmt|;
end_decl_stmt

end_unit

