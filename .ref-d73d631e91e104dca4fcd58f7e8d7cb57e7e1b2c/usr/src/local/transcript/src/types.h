begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* PostScript type and data structure defs  		Copyright 1983 -- Adobe Systems, Inc. 	    PostScript is a trademark of Adobe Systems, Inc. NOTICE:  All information contained herein or attendant hereto is, and remains, the property of Adobe Systems, Inc.  Many of the intellectual and technical concepts contained herein are proprietary to Adobe Systems, Inc. and may be covered by U.S. and Foreign Patents or Patents Pending or are protected as trade secrets.  Any dissemination of this information or reproduction of this material are strictly forbidden unless prior written permission is obtained from Adobe Systems, Inc.  Original version: Chuck Geschke: January 20, 1983 Edit History: Chuck Geschke: Tue Sep  4 14:16:04 1984 Tom Boynton: Thu Mar  3 15:47:27 1983 Doug Brotz: Wed Jul 11 17:28:07 1984 Ed Taft: Sun Sep 23 15:32:14 1984 End Edit History.  Note: types.h is intended to be usable either as an inclusion in postscript.h or by itself. Nothing in types.h should depend on definitions in any other .h file.  Note: for the moment we depend absolutely on an int being the same as a long int and being at least 32 bits. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|TYPES_H
end_define

begin_comment
comment|/* generally useful macros */
end_comment

begin_define
define|#
directive|define
name|endswitch
value|default:;
end_define

begin_define
define|#
directive|define
name|until
parameter_list|(
name|x
parameter_list|)
value|while (!(x))
end_define

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|x
parameter_list|)
value|((x)<0?-(x):(x))
end_define

begin_if
if|#
directive|if
name|IEEESOFT
end_if

begin_define
define|#
directive|define
name|RtoILOOPHOLE
parameter_list|(
name|r
parameter_list|)
value|(*(integer *)(&(r)))
end_define

begin_define
define|#
directive|define
name|RealEq0
parameter_list|(
name|r
parameter_list|)
value|((RtoILOOPHOLE(r)<<1)==0)
end_define

begin_define
define|#
directive|define
name|RealNe0
parameter_list|(
name|r
parameter_list|)
value|((RtoILOOPHOLE(r)<<1)!=0)
end_define

begin_define
define|#
directive|define
name|RealGt0
parameter_list|(
name|r
parameter_list|)
value|(RtoILOOPHOLE(r)>0)
end_define

begin_define
define|#
directive|define
name|RealGe0
parameter_list|(
name|r
parameter_list|)
value|((RtoILOOPHOLE(r)>=0)||RealEq0(r))
end_define

begin_define
define|#
directive|define
name|RealLt0
parameter_list|(
name|r
parameter_list|)
value|((RtoILOOPHOLE(r)<0)&&RealNe0(r))
end_define

begin_define
define|#
directive|define
name|RealLe0
parameter_list|(
name|r
parameter_list|)
value|(RtoILOOPHOLE(r)<=0)
end_define

begin_else
else|#
directive|else
else|IEEESOFT
end_else

begin_define
define|#
directive|define
name|RealEq0
parameter_list|(
name|r
parameter_list|)
value|((r)==0.0)
end_define

begin_define
define|#
directive|define
name|RealNe0
parameter_list|(
name|r
parameter_list|)
value|((r)!=0.0)
end_define

begin_define
define|#
directive|define
name|RealGt0
parameter_list|(
name|r
parameter_list|)
value|((r)>0.0)
end_define

begin_define
define|#
directive|define
name|RealGe0
parameter_list|(
name|r
parameter_list|)
value|((r)>=0.0)
end_define

begin_define
define|#
directive|define
name|RealLt0
parameter_list|(
name|r
parameter_list|)
value|((r)<0.0)
end_define

begin_define
define|#
directive|define
name|RealLe0
parameter_list|(
name|r
parameter_list|)
value|((r)<=0.0)
end_define

begin_endif
endif|#
directive|endif
endif|IEEESOFT
end_endif

begin_define
define|#
directive|define
name|fabs
parameter_list|(
name|x
parameter_list|)
value|(RealLt0(x)?-(x):(x))
end_define

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)<(b)?(a):(b))
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>(b)?(a):(b))
end_define

begin_define
define|#
directive|define
name|forward
value|extern
end_define

begin_define
define|#
directive|define
name|private
value|static
end_define

begin_define
define|#
directive|define
name|public
end_define

begin_define
define|#
directive|define
name|global
value|extern
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|boolean
typedef|;
end_typedef

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_typedef
typedef|typedef
name|long
name|int
name|word
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|word
modifier|*
name|wordptr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|procedure
value|integer
end_define

begin_comment
comment|/* actually void */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|character
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|character
modifier|*
name|string
typedef|,
modifier|*
name|charptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|int
name|integer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|real
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|longreal
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|int
name|cardinal
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|longcardinal
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|integer
name|Fixed
typedef|;
end_typedef

begin_comment
comment|/*  16 bits of integer, 16 bits of fraction */
end_comment

begin_typedef
typedef|typedef
name|integer
function_decl|(
modifier|*
name|PIntProc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|/* pointer to procedure returning integer */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STREAM_H
end_ifdef

begin_typedef
typedef|typedef
name|StmRec
modifier|*
name|StreamHandle
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
endif|STREAM_H
end_endif

begin_define
define|#
directive|define
name|MAXlevel
value|15
end_define

begin_comment
comment|/* max save level */
end_comment

begin_define
define|#
directive|define
name|MAXexecLevel
value|10
end_define

begin_comment
comment|/* max recursion level of psExecute */
end_comment

begin_define
define|#
directive|define
name|MAXinteger
value|017777777777
end_define

begin_define
define|#
directive|define
name|MINinteger
value|020000000000
end_define

begin_define
define|#
directive|define
name|MAXunsignedinteger
value|((unsigned)037777777777)
end_define

begin_define
define|#
directive|define
name|MAXcardinal
value|0177777
end_define

begin_define
define|#
directive|define
name|MAXlongcardinal
value|037777777777
end_define

begin_define
define|#
directive|define
name|MAXdctLength
value|2000
end_define

begin_define
define|#
directive|define
name|MAXnameLength
value|127
end_define

begin_define
define|#
directive|define
name|MAXnumeralString
value|35
end_define

begin_comment
comment|/* must be at least 32 on a VAX */
end_comment

begin_define
define|#
directive|define
name|MAXtimeString
value|24
end_define

begin_comment
comment|/* must be at least 24 on UNIX */
end_comment

begin_define
define|#
directive|define
name|MAXstringLength
value|MAXcardinal
end_define

begin_define
define|#
directive|define
name|MAXarrayLength
value|MAXcardinal
end_define

begin_define
define|#
directive|define
name|MAXdctCount
value|MAXcardinal
end_define

begin_define
define|#
directive|define
name|MAXcmdIndex
value|10000
end_define

begin_comment
comment|/* to distinguish cmd index from raw PC */
end_comment

begin_define
define|#
directive|define
name|NUL
value|'\0'
end_define

begin_define
define|#
directive|define
name|chPerPg
value|1024
end_define

begin_comment
comment|/* VAX specific */
end_comment

begin_define
define|#
directive|define
name|chPerWd
value|4
end_define

begin_define
define|#
directive|define
name|wdPerPg
value|chPerPg/chPerWd
end_define

begin_comment
comment|/* the following defs are for relative pointers into PS VM */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|Offset
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Offset
name|StrOffset
typedef|,
name|ArrayOffset
typedef|,
name|DictOffset
typedef|,
name|KeyValOffset
typedef|,
name|NameOffset
typedef|,
name|SROoffset
typedef|,
name|SRCoffset
typedef|,
name|SRDoffset
typedef|,
name|SRoffset
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NIL
value|NULL
end_define

begin_comment
comment|/* the definition of basic PostScript objects */
end_comment

begin_define
define|#
directive|define
name|nullObj
value|0
end_define

begin_define
define|#
directive|define
name|intObj
value|1
end_define

begin_define
define|#
directive|define
name|realObj
value|2
end_define

begin_define
define|#
directive|define
name|nameObj
value|3
end_define

begin_define
define|#
directive|define
name|boolObj
value|4
end_define

begin_define
define|#
directive|define
name|strObj
value|5
end_define

begin_define
define|#
directive|define
name|stmObj
value|6
end_define

begin_define
define|#
directive|define
name|cmdObj
value|7
end_define

begin_define
define|#
directive|define
name|dictObj
value|8
end_define

begin_define
define|#
directive|define
name|arrayObj
value|9
end_define

begin_define
define|#
directive|define
name|markObj
value|10
end_define

begin_define
define|#
directive|define
name|saveObj
value|11
end_define

begin_define
define|#
directive|define
name|fontObj
value|12
end_define

begin_define
define|#
directive|define
name|nObTypes
value|13
end_define

begin_define
define|#
directive|define
name|nBitVectorBits
value|32
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|BitVector
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Level
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|Access
typedef|;
end_typedef

begin_define
define|#
directive|define
name|nAccess
value|0
end_define

begin_define
define|#
directive|define
name|rAccess
value|1
end_define

begin_define
define|#
directive|define
name|wAccess
value|2
end_define

begin_define
define|#
directive|define
name|xAccess
value|4
end_define

begin_define
define|#
directive|define
name|aAccess
value|7
end_define

begin_define
define|#
directive|define
name|Lobj
value|0
end_define

begin_comment
comment|/* tag for literal object */
end_comment

begin_define
define|#
directive|define
name|Xobj
value|1
end_define

begin_comment
comment|/* tag for executable object */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|object
block|{
name|cardinal
name|tag
range|:
literal|1
decl_stmt|;
name|Access
name|access
range|:
literal|3
decl_stmt|;
name|cardinal
name|type
range|:
literal|4
decl_stmt|;
name|Level
name|level
decl_stmt|;
name|cardinal
name|length
decl_stmt|;
union|union
block|{
comment|/*null*/
name|int
name|nullval
decl_stmt|;
comment|/*int*/
name|integer
name|ival
decl_stmt|;
comment|/*real*/
name|real
name|rval
decl_stmt|;
comment|/*name*/
name|NameOffset
name|nmval
decl_stmt|;
comment|/*bool*/
name|boolean
name|bval
decl_stmt|;
comment|/*str*/
name|StrOffset
name|strval
decl_stmt|;
comment|/*stm*/
name|integer
name|stmval
decl_stmt|;
comment|/*cmd*/
name|NameOffset
name|cmdval
decl_stmt|;
comment|/*dict*/
name|DictOffset
name|dictval
decl_stmt|;
comment|/*array*/
name|ArrayOffset
name|arrayval
decl_stmt|;
comment|/*mark*/
name|int
name|markval
decl_stmt|;
comment|/*save*/
name|int
name|saveval
decl_stmt|;
comment|/*font*/
name|int
name|fontval
decl_stmt|;
block|}
name|val
union|;
block|}
name|Object
operator|,
typedef|*
name|PObject
operator|,
name|NullObj
operator|,
typedef|*
name|PNullObj
operator|,
name|IntObj
operator|,
typedef|*
name|PIntObj
operator|,
name|RealObj
operator|,
typedef|*
name|PRealObj
operator|,
name|NameObj
operator|,
typedef|*
name|PNameObj
operator|,
name|BoolObj
operator|,
typedef|*
name|PBoolObj
operator|,
name|StrObj
operator|,
typedef|*
name|PStrObj
operator|,
name|StmObj
operator|,
typedef|*
name|PStmObj
operator|,
name|CmdObj
operator|,
typedef|*
name|PCmdObj
operator|,
name|DictObj
operator|,
typedef|*
name|PDictObj
operator|,
name|AryObj
operator|,
typedef|*
name|PAryObj
operator|,
name|MarkObj
operator|,
typedef|*
name|PMarkObj
operator|,
name|SaveObj
operator|,
typedef|*
name|PSaveObj
operator|,
name|FontObj
operator|,
typedef|*
name|PFontObj
typedef|;
end_typedef

begin_comment
comment|/* following macros are useful for contructing Objects */
end_comment

begin_define
define|#
directive|define
name|LNullObj
parameter_list|(
name|o
parameter_list|)
value|o = iLNullObj; o.level=LEVEL
end_define

begin_define
define|#
directive|define
name|LIntObj
parameter_list|(
name|o
parameter_list|,
name|v
parameter_list|)
value|o = iLIntObj; o.level=LEVEL; o.val.ival=v
end_define

begin_define
define|#
directive|define
name|LRealObj
parameter_list|(
name|o
parameter_list|,
name|v
parameter_list|)
value|o = iLRealObj; o.level=LEVEL; o.val.rval=v
end_define

begin_define
define|#
directive|define
name|LNameObj
parameter_list|(
name|o
parameter_list|,
name|v
parameter_list|)
value|o = iLNameObj; o.level=LEVEL; o.val.nmval=v
end_define

begin_define
define|#
directive|define
name|LBoolObj
parameter_list|(
name|o
parameter_list|,
name|v
parameter_list|)
value|o = iLBoolObj; o.level=LEVEL; o.val.bval=v
end_define

begin_define
define|#
directive|define
name|LStrObj
parameter_list|(
name|o
parameter_list|,
name|l
parameter_list|,
name|v
parameter_list|)
value|o = iLStrObj; o.level=LEVEL; o.length=l; o.val.strval=v
end_define

begin_define
define|#
directive|define
name|LStmObj
parameter_list|(
name|o
parameter_list|,
name|i
parameter_list|,
name|s
parameter_list|)
value|o = iLStmObj; o.level=LEVEL; o.length=i; o.val.stmval=s
end_define

begin_define
define|#
directive|define
name|LDictObj
parameter_list|(
name|o
parameter_list|,
name|v
parameter_list|)
value|o = iLDictObj; o.level=LEVEL; o.val.dictval=v
end_define

begin_define
define|#
directive|define
name|LAryObj
parameter_list|(
name|o
parameter_list|,
name|l
parameter_list|,
name|v
parameter_list|)
value|o = iLAryObj; o.level=LEVEL; o.length=l; o.val.arrayval=v
end_define

begin_define
define|#
directive|define
name|LMarkObj
parameter_list|(
name|o
parameter_list|)
value|o = iLMarkObj; o.level=LEVEL
end_define

begin_define
define|#
directive|define
name|LSaveObj
parameter_list|(
name|o
parameter_list|,
name|v
parameter_list|)
value|o = iLSaveObj; o.level=LEVEL; o.val.saveval=v
end_define

begin_define
define|#
directive|define
name|LFontObj
parameter_list|(
name|o
parameter_list|,
name|v
parameter_list|)
value|o = iLFontObj; o.level=LEVEL; o.val.fontval=v
end_define

begin_define
define|#
directive|define
name|XNameObj
parameter_list|(
name|o
parameter_list|,
name|v
parameter_list|)
value|o = iXNameObj; o.level=LEVEL; o.val.nmval=v
end_define

begin_define
define|#
directive|define
name|XStrObj
parameter_list|(
name|o
parameter_list|,
name|l
parameter_list|,
name|v
parameter_list|)
value|o = iXStrObj; o.level=LEVEL; o.length=l; o.val.strval=v
end_define

begin_define
define|#
directive|define
name|XCmdObj
parameter_list|(
name|o
parameter_list|,
name|i
parameter_list|,
name|v
parameter_list|)
value|o = iXCmdObj; o.level=LEVEL; o.val.cmdval=i; o.length=v
end_define

begin_define
define|#
directive|define
name|XAryObj
parameter_list|(
name|o
parameter_list|,
name|l
parameter_list|,
name|v
parameter_list|)
value|o = iXAryObj; o.level=LEVEL; o.length=l; o.val.arrayval=v
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LEVEL
end_ifndef

begin_define
define|#
directive|define
name|LEVEL
value|level
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|NullObj
name|iLNullObj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|IntObj
name|iLIntObj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|RealObj
name|iLRealObj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NameObj
name|iLNameObj
decl_stmt|,
name|iXNameObj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BoolObj
name|iLBoolObj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|StrObj
name|iLStrObj
decl_stmt|,
name|iXStrObj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|StmObj
name|iLStmObj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CmdObj
name|iXCmdObj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|DictObj
name|iLDictObj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|AryObj
name|iLAryObj
decl_stmt|,
name|iXAryObj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MarkObj
name|iLMarkObj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SaveObj
name|iLSaveObj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FontObj
name|iLFontObj
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* graphics data types */
end_comment

begin_typedef
typedef|typedef
name|real
name|Component
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Component
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|Cd
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|integer
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|DevCd
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|real
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|,
name|tx
decl_stmt|,
name|ty
decl_stmt|;
block|}
name|Mtx
operator|,
typedef|*
name|PMtx
typedef|;
end_typedef

begin_comment
comment|/* initialization */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|init
block|,
name|romreg
block|,
name|ramreg
block|}
name|InitReason
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
endif|TYPES_H
end_endif

end_unit

