begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Copyright (c) 1982 Regents of the University of California  *	@(#)asscan.h 4.9 6/30/83  */
end_comment

begin_comment
comment|/*  *	The character scanner is called to fill up one token buffer  *  *	However, once the tokens are filled up by the  *	character scanner, they are used in both the first and the second  *	pass.  Holes created by .stab removal are replaced  *	with 'skip' tokens that direct the second pass to ignore the  *	following tokens.  */
end_comment

begin_define
define|#
directive|define
name|TOKBUFLG
value|4096
end_define

begin_define
define|#
directive|define
name|MAXTAHOE
value|32
end_define

begin_define
define|#
directive|define
name|SAFETY
value|16
end_define

begin_define
define|#
directive|define
name|AVAILTOKS
value|TOKBUFLG -\ 		sizeof(int) -\ 		sizeof (struct tokbufdesc *) -\ 		MAXTAHOE - SAFETY
end_define

begin_struct
struct|struct
name|tokbufdesc
block|{
name|int
name|tok_count
decl_stmt|;
comment|/*absolute byte length*/
name|struct
name|tokbufdesc
modifier|*
name|tok_next
decl_stmt|;
name|char
name|toks
index|[
name|AVAILTOKS
index|]
decl_stmt|;
name|char
name|bufovf
index|[
name|MAXTAHOE
operator|+
name|SAFETY
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Definitions for handling tokens in the intermediate file  *	buffers.  *  *	We want to have the compiler produce the efficient auto increment  *	instruction for stepping through the buffer of tokens.  We must  *	fool the type checker into thinking that a pointer can point  *	to various size things.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|inttoktype
typedef|;
end_typedef

begin_comment
comment|/* typedef char inttoktype; */
end_comment

begin_typedef
typedef|typedef
name|char
name|bytetoktype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|ptrall
typedef|;
end_typedef

begin_comment
comment|/*all uses will be type cast*/
end_comment

begin_typedef
typedef|typedef
name|u_short
name|lgtype
typedef|;
end_typedef

begin_comment
comment|/*for storing length of strings or skiping*/
end_comment

begin_comment
comment|/*  *	defintions for putting various typed values  *	into the intermediate buffers  *	ptr will ALWAYS be of type ptrall  */
end_comment

begin_define
define|#
directive|define
name|ptype
parameter_list|(
name|type
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|)
define|\
value|(ptr) = (char *)((int)((ptr) + sizeof(type)-1)&~(sizeof(type)-1)), \ 		*(type *)(ptr) = (val),	(ptr) += sizeof(type)
end_define

begin_define
define|#
directive|define
name|pchar
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|*(ptr)++  = (val)
end_define

begin_define
define|#
directive|define
name|puchar
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|*(ptr)++  = (val)
end_define

begin_define
define|#
directive|define
name|pshort
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|ptype (short, ptr, val)
end_define

begin_define
define|#
directive|define
name|plgtype
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|ptype (lgtype, ptr, val)
end_define

begin_define
define|#
directive|define
name|pushort
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|ptype (u_short, ptr, val)
end_define

begin_define
define|#
directive|define
name|pint
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|ptype (int, ptr, val)
end_define

begin_define
define|#
directive|define
name|puint
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|ptype (u_int, ptr, val)
end_define

begin_define
define|#
directive|define
name|plong
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|ptype (long, ptr, val)
end_define

begin_define
define|#
directive|define
name|pulong
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|ptype (u_int, ptr, val)
end_define

begin_define
define|#
directive|define
name|pnumber
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|ptype (Bignum, ptr, val)
end_define

begin_define
define|#
directive|define
name|pptr
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|ptype (int, ptr, val)
end_define

begin_define
define|#
directive|define
name|popcode
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|*(ptr)++  = (val)
end_define

begin_define
define|#
directive|define
name|ptoken
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|*(ptr)++  = (val)
end_define

begin_define
define|#
directive|define
name|pskiplg
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|ptype (lgtype, ptr, val)
end_define

begin_define
define|#
directive|define
name|gtype
parameter_list|(
name|type
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|)
define|\
value|(ptr) = (char *)((int)((ptr) + sizeof(type)-1)&~(sizeof(type)-1)), \ 		(val) = *(type *)(ptr)  ,	(ptr) += sizeof(type)
end_define

begin_define
define|#
directive|define
name|gchar
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|(val) = *(ptr)++
end_define

begin_define
define|#
directive|define
name|guchar
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|(val) = *(ptr)++
end_define

begin_define
define|#
directive|define
name|gshort
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|gtype (short, ptr, val)
end_define

begin_define
define|#
directive|define
name|glgtype
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|gtype (lgtype, ptr, val)
end_define

begin_define
define|#
directive|define
name|gushort
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|gtype (u_short, ptr, val)
end_define

begin_define
define|#
directive|define
name|gint
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|gtype (int, ptr, val)
end_define

begin_define
define|#
directive|define
name|guint
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|gtype (u_int, ptr, val)
end_define

begin_define
define|#
directive|define
name|glong
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|gtype (long, ptr, val)
end_define

begin_define
define|#
directive|define
name|gulong
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|gtype (u_int, ptr, val)
end_define

begin_define
define|#
directive|define
name|gnumber
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|gtype (Bignum, ptr, val)
end_define

begin_define
define|#
directive|define
name|gptr
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|gtype (int, ptr, val)
end_define

begin_define
define|#
directive|define
name|gopcode
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|(val) = *(ptr)++
end_define

begin_define
define|#
directive|define
name|gtoken
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|(val) = *(ptr)++
end_define

begin_define
define|#
directive|define
name|gskiplg
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|gtype (lgtype, ptr, val)
end_define

begin_decl_stmt
specifier|extern
name|ptrall
name|tokptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*the next token to consume, call by copy*/
end_comment

begin_decl_stmt
specifier|extern
name|ptrall
name|tokub
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current upper bound in the current buffer*/
end_comment

end_unit

