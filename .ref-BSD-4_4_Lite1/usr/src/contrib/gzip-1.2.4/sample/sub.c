begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sub.c   not copyrighted (n) 1993 by Mark Adler */
end_comment

begin_comment
comment|/* version 1.1   11 Jun 1993 */
end_comment

begin_comment
comment|/* sub is a simple filter to preprocess a data file before compression.    It can increase compression for data whose points tend to be close to    the last point.  The output is the difference of successive bytes of    the input.  The add filter is used to undo what sub does.  This could    be used on 8-bit sound or graphics data.     sub can also take an argument to apply this to interleaved sets of    bytes.  For example, if the data are 16-bit sound samples, then you    can use "sub 2" to take differences on the low-byte stream and the    high-byte stream.  (This gives nearly the same effect as subtracting    the 16-bit values, but avoids the complexities of endianess of the    data.)  The concept extends to RGB image data (sub 3), 16-bit stereo    data (sub 4), floating point data (sub 4 or sub 8), etc.     add takes no options, since the number of interleaved byte streams    is put in the first two bytes of the output stream for add to use    (in little-endian format).     Examples:        sub< graph.vga | gzip -9> graph.vga.sgz       sub< phone.snd | gzip -9> phone.snd.sgz       sub 2< audio.snd | gzip -9> audio.snd.sgz       sub 3< picture.rgb | gzip -9> picture.rgb.sgz       sub 4< stereo.snd | gzip -9> stereo.snd.sgz       sub 8< double.data | gzip -9> double.data.sgz     To expand, use the reverse operation, as in:        gunzip< double.data.sgz | add> double.data */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|MAGIC1
value|'S'
end_define

begin_comment
comment|/* sub data */
end_comment

begin_define
define|#
directive|define
name|MAGIC2
value|26
end_define

begin_comment
comment|/* ^Z */
end_comment

begin_define
define|#
directive|define
name|MAX_DIST
value|16384
end_define

begin_decl_stmt
name|char
name|a
index|[
name|MAX_DIST
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last byte buffer for up to MAX_DIST differences */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|int
name|n
init|=
literal|1
decl_stmt|;
comment|/* number of differences */
name|int
name|i
decl_stmt|;
comment|/* difference counter */
name|int
name|c
decl_stmt|;
comment|/* byte from input */
name|int
name|atoi
parameter_list|()
function_decl|;
comment|/* (avoid including stdlib for portability) */
comment|/* process arguments */
if|if
condition|(
name|argc
operator|>
literal|2
condition|)
block|{
name|fputs
argument_list|(
literal|"sub: only one argument needed--# of differences\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
name|n
operator|=
name|atoi
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|<
literal|0
condition|)
name|n
operator|=
operator|-
name|n
expr_stmt|;
comment|/* tolerate "sub -2" */
if|if
condition|(
name|n
operator|==
literal|0
operator|||
name|n
operator|>
name|MAX_DIST
condition|)
block|{
name|fputs
argument_list|(
literal|"sub: incorrect distance\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* initialize last byte */
name|i
operator|=
name|n
expr_stmt|;
do|do
block|{
name|a
index|[
operator|--
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
do|while
condition|(
name|i
condition|)
do|;
comment|/* write differenced data */
name|putchar
argument_list|(
name|MAGIC1
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
name|MAGIC2
argument_list|)
expr_stmt|;
comment|/* magic word for add */
name|putchar
argument_list|(
name|n
operator|&
literal|0xff
argument_list|)
expr_stmt|;
comment|/* so add knows what to do */
name|putchar
argument_list|(
operator|(
name|n
operator|>>
literal|8
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getchar
argument_list|()
operator|)
operator|!=
name|EOF
condition|)
block|{
name|putchar
argument_list|(
operator|(
name|c
operator|-
name|a
index|[
name|i
index|]
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
comment|/* write difference */
name|a
index|[
name|i
operator|++
index|]
operator|=
name|c
expr_stmt|;
comment|/* save last byte */
if|if
condition|(
name|i
operator|==
name|n
condition|)
comment|/* cycle on n differences */
name|i
operator|=
literal|0
expr_stmt|;
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|/* avoid warning */
block|}
end_function

end_unit

