begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)lmanifest.h	1.2	(Berkeley)	3/29/83  */
end_comment

begin_comment
comment|/*	the key: 	LDI	defined and initialized: storage set aside 	LIB	defined on a library 	LDC	defined as a common region on UNIX 	LDX	defined by an extern: if ! pflag, same as LDI 	LRV	function returns a value 	LUV	function used in a value context 	LUE	function used in effects context 	LUM	mentioned somewhere other than at the declaration 	LST	defined as a static 	*/
end_comment

begin_define
define|#
directive|define
name|LDI
value|0001
end_define

begin_define
define|#
directive|define
name|LIB
value|0002
end_define

begin_define
define|#
directive|define
name|LDC
value|0004
end_define

begin_define
define|#
directive|define
name|LDX
value|0010
end_define

begin_define
define|#
directive|define
name|LRV
value|0020
end_define

begin_define
define|#
directive|define
name|LUV
value|0040
end_define

begin_define
define|#
directive|define
name|LUE
value|0100
end_define

begin_define
define|#
directive|define
name|LUM
value|0200
end_define

begin_define
define|#
directive|define
name|LST
value|0400
end_define

begin_define
define|#
directive|define
name|LFN
value|01000
end_define

begin_comment
comment|/* filename record */
end_comment

begin_comment
comment|/* number of chars in NAME, and filename */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FLEXNAMES
end_ifndef

begin_define
define|#
directive|define
name|LCHNM
value|8
end_define

begin_define
define|#
directive|define
name|LFNM
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|ty
block|{
name|TWORD
name|aty
decl_stmt|;
name|short
name|extra
decl_stmt|;
name|short
name|extra1
decl_stmt|;
block|}
name|ATYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|X_NONAME
value|0x8000
end_define

begin_comment
comment|/* for extra1, if structure has no name */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|line
block|{
name|short
name|decflag
decl_stmt|;
ifndef|#
directive|ifndef
name|FLEXNAMES
name|char
name|name
index|[
name|LCHNM
index|]
decl_stmt|;
else|#
directive|else
name|char
modifier|*
name|name
decl_stmt|;
endif|#
directive|endif
name|short
name|nargs
decl_stmt|;
name|short
name|fline
decl_stmt|;
name|ATYPE
name|type
decl_stmt|;
block|}
name|LINE
typedef|;
end_typedef

begin_union
union|union
name|rec
block|{
name|struct
name|line
name|l
decl_stmt|;
struct|struct
block|{
name|short
name|decflag
decl_stmt|;
ifndef|#
directive|ifndef
name|FLEXNAMES
name|char
name|fn
index|[
name|LFNM
index|]
decl_stmt|;
else|#
directive|else
name|char
modifier|*
name|fn
decl_stmt|;
endif|#
directive|endif
block|}
name|f
struct|;
block|}
union|;
end_union

end_unit

