begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/* **	COPYRIGHT ** **	The Regents of the University of California ** **	1977 ** **	This program material is the property of the **	Regents of the University of California and **	may not be reproduced or disclosed without **	the prior written permission of the owner. */
end_comment

begin_comment
comment|/* **	Version: **		@(#)parser.h	7.1	2/5/81 */
end_comment

begin_define
define|#
directive|define
name|DBUFSIZ
value|2000
end_define

begin_comment
comment|/* size of buffer for dbu commands */
end_comment

begin_define
define|#
directive|define
name|TREEMAX
value|2500
end_define

begin_comment
comment|/* max number of bytes for tree */
end_comment

begin_define
define|#
directive|define
name|MAXATT
value|150
end_define

begin_comment
comment|/* max number of attributes in the att stash */
end_comment

begin_define
define|#
directive|define
name|V6POINT3COMPAT
end_define

begin_define
define|#
directive|define
name|WARN
value|0
end_define

begin_comment
comment|/* for a non fatal error */
end_comment

begin_define
define|#
directive|define
name|FATAL
value|1
end_define

begin_comment
comment|/* for a fatal error */
end_comment

begin_comment
comment|/* mode parameters for range table manipulation */
end_comment

begin_define
define|#
directive|define
name|LOOKREL
value|1
end_define

begin_define
define|#
directive|define
name|LOOKVAR
value|2
end_define

begin_define
define|#
directive|define
name|R_INTERNAL
value|3
end_define

begin_define
define|#
directive|define
name|R_EXTERNAL
value|4
end_define

begin_define
define|#
directive|define
name|RELVUSED
value|01
end_define

begin_comment
comment|/* the first argument in argv which may be an ad hoc flag */
end_comment

begin_define
define|#
directive|define
name|FREEFLAGS
value|6
end_define

begin_comment
comment|/* error numbers */
end_comment

begin_define
define|#
directive|define
name|SUMMARY
value|2000
end_define

begin_comment
comment|/* summary of errors */
end_comment

begin_define
define|#
directive|define
name|TREEOFLO
value|2118
end_define

begin_comment
comment|/* over flow tree buffer */
end_comment

begin_define
define|#
directive|define
name|DBUFOFLO
value|2106
end_define

begin_comment
comment|/* over flow dbu arg buffer */
end_comment

begin_define
define|#
directive|define
name|NOATTRIN
value|2100
end_define

begin_comment
comment|/* attrib not in relation */
end_comment

begin_define
define|#
directive|define
name|CANTUPDATE
value|2107
end_define

begin_comment
comment|/* can't update rel */
end_comment

begin_define
define|#
directive|define
name|NOVBLE
value|2109
end_define

begin_comment
comment|/* vble not declared */
end_comment

begin_define
define|#
directive|define
name|NOPATMAT
value|2120
end_define

begin_comment
comment|/* no pattern matching in tl */
end_comment

begin_define
define|#
directive|define
name|RNGEXIST
value|2117
end_define

begin_comment
comment|/* can't find rel for var */
end_comment

begin_define
define|#
directive|define
name|REPALL
value|2123
end_define

begin_comment
comment|/* x.all on replace */
end_comment

begin_define
define|#
directive|define
name|BADCONSTOP
value|2134
end_define

begin_comment
comment|/* bad constant operator */
end_comment

begin_define
define|#
directive|define
name|INDEXTRA
value|2111
end_define

begin_comment
comment|/* too many atts in key */
end_comment

begin_define
define|#
directive|define
name|RESXTRA
value|2130
end_define

begin_comment
comment|/* too many resdoms in tl */
end_comment

begin_define
define|#
directive|define
name|TARGXTRA
value|2131
end_define

begin_comment
comment|/* tl larger than MAXTUP */
end_comment

begin_define
define|#
directive|define
name|AGGXTRA
value|2132
end_define

begin_comment
comment|/* too many aggs */
end_comment

begin_define
define|#
directive|define
name|MODTYPE
value|2119
end_define

begin_comment
comment|/* type conflict for MOD */
end_comment

begin_define
define|#
directive|define
name|CONCATTYPE
value|2121
end_define

begin_comment
comment|/* type conflict for CONCAT */
end_comment

begin_define
define|#
directive|define
name|AVGTYPE
value|2125
end_define

begin_comment
comment|/* type conflict for AVG(U) */
end_comment

begin_define
define|#
directive|define
name|SUMTYPE
value|2126
end_define

begin_comment
comment|/* type conflict for SUM(U) */
end_comment

begin_define
define|#
directive|define
name|FOPTYPE
value|2127
end_define

begin_comment
comment|/* type conflict for func ops */
end_comment

begin_define
define|#
directive|define
name|UOPTYPE
value|2128
end_define

begin_comment
comment|/* type conflict for unary ops */
end_comment

begin_define
define|#
directive|define
name|NUMTYPE
value|2129
end_define

begin_comment
comment|/* type conflict for numeric ops */
end_comment

begin_define
define|#
directive|define
name|RELTYPE
value|2133
end_define

begin_comment
comment|/* type conflict for relatv op */
end_comment

begin_define
define|#
directive|define
name|RESTYPE
value|2103
end_define

begin_comment
comment|/* result type mismatch w/expr */
end_comment

begin_define
define|#
directive|define
name|RESAPPEX
value|2108
end_define

begin_comment
comment|/* append res rel not exist */
end_comment

begin_define
define|#
directive|define
name|RESEXIST
value|2135
end_define

begin_comment
comment|/* result rel already exists */
end_comment

begin_define
define|#
directive|define
name|NXTCMDERR
value|2500
end_define

begin_comment
comment|/* misspelt where problem */
end_comment

begin_define
define|#
directive|define
name|NOQRYMOD
value|2139
end_define

begin_comment
comment|/* no qrymod in database */
end_comment

begin_define
define|#
directive|define
name|BADHOURS
value|2136
end_define

begin_comment
comment|/* no such hour */
end_comment

begin_define
define|#
directive|define
name|BADMINS
value|2137
end_define

begin_comment
comment|/* no such minute */
end_comment

begin_define
define|#
directive|define
name|BAD24TIME
value|2138
end_define

begin_comment
comment|/* only 24:00 can be used */
end_comment

begin_comment
comment|/* -- ASSORTED DATA STRUCTURES -- */
end_comment

begin_struct
struct|struct
name|atstash
comment|/* attribute table */
block|{
name|char
name|atbid
decl_stmt|;
comment|/* attribute number */
name|char
name|atbfrmt
decl_stmt|;
comment|/* attribute form type */
name|char
name|atbfrml
decl_stmt|;
comment|/* attribute form length */
name|char
name|atbname
index|[
name|MAXNAME
index|]
decl_stmt|;
comment|/* attribute name */
name|struct
name|atstash
modifier|*
name|atbnext
decl_stmt|;
comment|/* pointer to next entry in chain */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|parrng
comment|/* auxiliary range table */
block|{
name|DESC
name|vardesc
decl_stmt|;
name|struct
name|parrng
modifier|*
name|frontpt
decl_stmt|;
name|struct
name|parrng
modifier|*
name|backpt
decl_stmt|;
name|struct
name|atstash
modifier|*
name|attlist
decl_stmt|;
comment|/* head of attrib list for this reln */
name|int
name|relvused
decl_stmt|;
comment|/* whether variable in use */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|parrng
name|PARRNG
typedef|;
end_typedef

begin_struct
struct|struct
name|constop
comment|/* constant operator lookup table */
block|{
name|char
modifier|*
name|copname
decl_stmt|;
comment|/* string name for identification */
name|int
name|copnum
decl_stmt|;
comment|/* op number */
name|char
name|coptype
decl_stmt|;
comment|/* op result type for formating */
name|char
name|coplen
decl_stmt|;
comment|/* op result length for formatting */
block|}
struct|;
end_struct

end_unit

