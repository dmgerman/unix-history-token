begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* enumerate.c  *  * Copyright (c) 1984, 1985 Xerox Corp.  *  *  Define the functions used in parse.c.  *  *  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|octal
value|0
end_define

begin_define
define|#
directive|define
name|hex
value|1
end_define

begin_define
define|#
directive|define
name|decimal
value|2
end_define

begin_define
define|#
directive|define
name|character
value|3
end_define

begin_decl_stmt
specifier|extern
name|long
name|filepos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|fp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|verbose
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_macro
name|header
argument_list|(
argument|string
argument_list|,
argument|resheader
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|string
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) header: %s\n"
argument_list|,
name|filepos
argument_list|,
name|string
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_makevec
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) makevec\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_do
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) do\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_pop
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) pop\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_copy
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) copy\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_dup
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) dup\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_roll
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) roll\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_exch
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) exch\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_nop
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) nop\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_translate
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) translate\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_rotate
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) rotate\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_scale
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) scale\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_scale2
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) scale2\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_concat
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) concat\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_makepixelarray
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) makepixelarray\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_extractpixelarray
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) extractpixelarray\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_finddecompressor
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) finddecompressor\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_makegray
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) makegray\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_findcolor
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) findcolor\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_findcoloroperator
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) findcoloroperator\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_findcolormodeloperator
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) findcolormodeloperator\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_beginblock
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) beginblock\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_endblock
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) endblock\n"
argument_list|,
name|filepos
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|op_unknown
argument_list|(
argument|op
argument_list|)
end_macro

begin_decl_stmt
name|int
name|op
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) unknown operator: %u\n"
argument_list|,
name|filepos
argument_list|,
name|op
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|seq_adaptivepixel
argument_list|(
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) sequence adaptive pixel vector, %u bytes:\n"
argument_list|,
name|filepos
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|printbytes
argument_list|(
name|len
argument_list|,
name|decimal
argument_list|,
name|verbose
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|seq_comment
argument_list|(
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) sequence comment, %u bytes:\n"
argument_list|,
name|filepos
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|printbytes
argument_list|(
name|len
argument_list|,
name|character
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|seq_compressedpixel
argument_list|(
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) sequence compressed pixel vector, %u bytes:\n"
argument_list|,
name|filepos
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|printbytes
argument_list|(
name|len
argument_list|,
name|decimal
argument_list|,
name|verbose
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|seq_continued
argument_list|(
argument|len
argument_list|,
argument|last
argument_list|)
end_macro

begin_decl_stmt
name|int
name|len
decl_stmt|,
name|last
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) sequence continued, %u bytes:\n"
argument_list|,
name|filepos
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|printbytes
argument_list|(
name|len
argument_list|,
name|decimal
argument_list|,
name|verbose
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|seq_identifier
argument_list|(
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) sequence identifier, %u bytes:\n"
argument_list|,
name|filepos
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|printbytes
argument_list|(
name|len
argument_list|,
name|character
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|seq_insertfile
argument_list|(
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) sequence insert file, %u bytes:\n"
argument_list|,
name|filepos
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|printbytes
argument_list|(
name|len
argument_list|,
name|character
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|seq_integer
argument_list|(
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) sequence integer, %u bytes:\n"
argument_list|,
name|filepos
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|printbytes
argument_list|(
name|len
argument_list|,
name|decimal
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|seq_largevector
argument_list|(
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) sequence large vector, %u bytes:\n"
argument_list|,
name|filepos
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|printbytes
argument_list|(
name|len
argument_list|,
name|decimal
argument_list|,
name|verbose
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|seq_packedpixel
argument_list|(
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) sequence packed pixel vector, %u bytes:\n"
argument_list|,
name|filepos
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|printbytes
argument_list|(
name|len
argument_list|,
name|decimal
argument_list|,
name|verbose
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|seq_rational
argument_list|(
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) sequence rational, %u bytes:\n"
argument_list|,
name|filepos
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|printbytes
argument_list|(
name|len
argument_list|,
name|decimal
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|seq_string
argument_list|(
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) sequence string, %u bytes:\n"
argument_list|,
name|filepos
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|printbytes
argument_list|(
name|len
argument_list|,
name|character
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|seq_unknown
argument_list|(
argument|type
argument_list|,
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|int
name|type
decl_stmt|,
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) unknown sequence, %u bytes:\n"
argument_list|,
name|filepos
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|printbytes
argument_list|(
name|len
argument_list|,
name|decimal
argument_list|,
name|verbose
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|shortnum
argument_list|(
argument|number
argument_list|)
end_macro

begin_decl_stmt
name|int
name|number
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"(%u) %d\n"
argument_list|,
name|filepos
argument_list|,
name|number
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|printbytes
argument_list|(
argument|len
argument_list|,
argument|format
argument_list|,
argument|v
argument_list|)
end_macro

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|n
decl_stmt|,
name|c
decl_stmt|;
if|if
condition|(
name|v
operator|==
literal|0
condition|)
block|{
name|fseek
argument_list|(
name|fp
argument_list|,
name|len
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return;
block|}
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|len
condition|;
name|n
operator|++
control|)
block|{
name|c
operator|=
name|getc
argument_list|(
name|fp
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|octal
case|:
name|printf
argument_list|(
literal|"%o "
argument_list|,
name|c
argument_list|)
expr_stmt|;
break|break;
case|case
name|hex
case|:
name|printf
argument_list|(
literal|"%x "
argument_list|,
name|c
argument_list|)
expr_stmt|;
break|break;
case|case
name|decimal
case|:
name|printf
argument_list|(
literal|"%u "
argument_list|,
name|c
argument_list|)
expr_stmt|;
break|break;
case|case
name|character
case|:
name|printf
argument_list|(
literal|"%c "
argument_list|,
name|c
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
operator|(
name|n
operator|%
literal|8
operator|)
operator|==
literal|7
condition|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Change Log  *  * K. Knox, 28-Mar-85 15:01:49, Created first version.  *  *  *  */
end_comment

end_unit

