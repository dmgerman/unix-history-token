begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1980 Regents of the University of California */
end_comment

begin_comment
comment|/* "@(#)asscan.h 4.3 8/15/80" */
end_comment

begin_comment
comment|/*  *	The character scanner is called to fill up one token buffer  *  *	However, once the tokens are filled up by the  *	character scanner, they are used in both the first and the second  *	pass.  Holes created by .stab removal are replaced  *	with 'skip' tokens that direct the second pass to ignore the  *	following tokens.  */
end_comment

begin_define
define|#
directive|define
name|TOKBUFLG
value|BUFSIZ
end_define

begin_define
define|#
directive|define
name|MAXVAX
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
value|TOKBUFLG -\ 		sizeof(int) -\ 		sizeof (struct tokbufdesc *) -\ 		MAXVAX - SAFETY
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
name|MAXVAX
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
name|char
name|toktype
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
name|short
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
name|pchar
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|*ptr++  = val
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
value|*ptr++  = val
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
value|*(short *)ptr=val,	ptr += sizeof(short)
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
value|*(unsigned short *)ptr=val,	ptr += sizeof(short)
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
value|*(int *)ptr  = val,	ptr += sizeof(int)
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
value|*(unsigned int *)ptr=val,	ptr += sizeof(int)
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
value|*(long *)ptr  = val,	ptr += sizeof(long)
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
value|*(unsigned long *)ptr=val,	ptr += sizeof(long)
end_define

begin_define
define|#
directive|define
name|pfloat
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|*(float *)ptr  = val,	ptr += sizeof (float)
end_define

begin_define
define|#
directive|define
name|pdouble
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|*(double *)ptr  = val,	ptr += sizeof (double)
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
value|*(int *)ptr  = (val),	ptr += sizeof(ptrall)
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
value|*ptr++  = val
end_define

begin_define
define|#
directive|define
name|pstrlg
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|)
value|*(lgtype *)ptr  = val,	ptr += sizeof(short)
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
value|*(lgtype *)ptr  = val,	ptr += sizeof(short)
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
value|val = *ptr++
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
value|val = *ptr++
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
value|val = *(short *)ptr , ptr += sizeof (short)
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
value|val = *(unsigned short *)ptr , ptr += sizeof (short)
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
value|val = *(int *)ptr, ptr += sizeof (int)
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
value|val = *(unsigend int *)ptr, ptr += sizeof (int)
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
value|val = *(long *)ptr, ptr += sizeof (long)
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
value|val = *(unsigned long *)ptr, ptr += sizeof (long)
end_define

begin_define
define|#
directive|define
name|gfloat
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|val = *(float *)ptr, ptr += sizeof (float)
end_define

begin_define
define|#
directive|define
name|gdouble
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|val = *(double *)ptr, ptr += sizeof (double)
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
value|val = *(int *)ptr, ptr += sizeof (ptrall)
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
value|val = *ptr++
end_define

begin_define
define|#
directive|define
name|gstrlg
parameter_list|(
name|val
parameter_list|,
name|ptr
parameter_list|)
value|val = *(lgtype *)ptr, ptr += sizeof (short)
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
value|val = *(lgtype *)ptr, ptr += sizeof (short)
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

begin_comment
comment|/*  *	Strings are known for their characters and for their length.  *	We cannot use a normal zero termination byte, because strings  *	can contain anything.  *  *	We have two "strings", so that an input string that is too long can be  *	split across two string buffers, and not confuse the yacc grammar.  *	(This is probably superflous)  *  *	We have a third string of nulls so that the .skip can be   *	handled in the same way as strings.  */
end_comment

begin_define
define|#
directive|define
name|MAXSTRLG
value|127
end_define

begin_struct
struct|struct
name|strdesc
block|{
name|char
name|str_lg
decl_stmt|;
name|char
name|str
index|[
name|MAXSTRLG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|strdesc
name|strbuf
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|strdesc
modifier|*
name|strptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*points to the current string*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|strno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*the current string being filled*/
end_comment

begin_function_decl
name|char
modifier|*
name|savestr
parameter_list|()
function_decl|;
end_function_decl

end_unit

