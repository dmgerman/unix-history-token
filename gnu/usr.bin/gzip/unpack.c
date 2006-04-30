begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* unpack.c -- decompress files in pack format.  * Copyright (C) 1992-1993 Jean-loup Gailly  * This is free software; you can redistribute it and/or modify it under the  * terms of the GNU General Public License, see the file COPYING.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RCSID
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"tailor.h"
end_include

begin_include
include|#
directive|include
file|"gzip.h"
end_include

begin_include
include|#
directive|include
file|"crypt.h"
end_include

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)<= (b) ? (a) : (b))
end_define

begin_comment
comment|/* The arguments must not have side effects. */
end_comment

begin_define
define|#
directive|define
name|MAX_BITLEN
value|25
end_define

begin_comment
comment|/* Maximum length of Huffman codes. (Minor modifications to the code  * would be needed to support 32 bits codes, but pack never generates  * more than 24 bits anyway.)  */
end_comment

begin_define
define|#
directive|define
name|LITERALS
value|256
end_define

begin_comment
comment|/* Number of literals, excluding the End of Block (EOB) code */
end_comment

begin_define
define|#
directive|define
name|MAX_PEEK
value|12
end_define

begin_comment
comment|/* Maximum number of 'peek' bits used to optimize traversal of the  * Huffman tree.  */
end_comment

begin_decl_stmt
name|local
name|ulg
name|orig_len
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* original uncompressed length */
end_comment

begin_decl_stmt
name|local
name|int
name|max_len
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum bit length of Huffman codes */
end_comment

begin_decl_stmt
name|local
name|uch
name|literal
index|[
name|LITERALS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The literal bytes present in the Huffman tree. The EOB code is not  * represented.  */
end_comment

begin_decl_stmt
name|local
name|int
name|lit_base
index|[
name|MAX_BITLEN
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* All literals of a given bit length are contiguous in literal[] and  * have contiguous codes. literal[code+lit_base[len]] is the literal  * for a code of len bits.  */
end_comment

begin_decl_stmt
name|local
name|int
name|leaves
index|[
name|MAX_BITLEN
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of leaves for each bit length */
end_comment

begin_decl_stmt
name|local
name|int
name|parents
index|[
name|MAX_BITLEN
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of parents for each bit length */
end_comment

begin_decl_stmt
name|local
name|int
name|peek_bits
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of peek bits currently used */
end_comment

begin_comment
comment|/* local uch prefix_len[1<< MAX_PEEK]; */
end_comment

begin_define
define|#
directive|define
name|prefix_len
value|outbuf
end_define

begin_comment
comment|/* For each bit pattern b of peek_bits bits, prefix_len[b] is the length  * of the Huffman code starting with a prefix of b (upper bits), or 0  * if all codes of prefix b have more than peek_bits bits. It is not  * necessary to have a huge table (large MAX_PEEK) because most of the  * codes encountered in the input stream are short codes (by construction).  * So for most codes a single lookup will be necessary.  */
end_comment

begin_if
if|#
directive|if
operator|(
literal|1
operator|<<
name|MAX_PEEK
operator|)
operator|>
name|OUTBUFSIZ
end_if

begin_decl_stmt
name|error
name|cannot
name|overlay
name|prefix_len
name|and
name|outbuf
endif|#
directive|endif
name|local
name|ulg
name|bitbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bits are added on the low part of bitbuf and read from the high part. */
end_comment

begin_decl_stmt
name|local
name|int
name|valid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of valid bits in bitbuf */
end_comment

begin_comment
comment|/* all bits above the last valid bit are always zero */
end_comment

begin_comment
comment|/* Set code to the next 'bits' input bits without skipping them. code  * must be the name of a simple variable and bits must not have side effects.  * IN assertions: bits<= 25 (so that we still have room for an extra byte  * when valid is only 24), and mask = (1<<bits)-1.  */
end_comment

begin_define
define|#
directive|define
name|look_bits
parameter_list|(
name|code
parameter_list|,
name|bits
parameter_list|,
name|mask
parameter_list|)
define|\
value|{ \   while (valid< (bits)) bitbuf = (bitbuf<<8) | (ulg)get_byte(), valid += 8; \   code = (bitbuf>> (valid-(bits)))& (mask); \ }
end_define

begin_comment
comment|/* Skip the given number of bits (after having peeked at them): */
end_comment

begin_define
define|#
directive|define
name|skip_bits
parameter_list|(
name|bits
parameter_list|)
value|(valid -= (bits))
end_define

begin_define
define|#
directive|define
name|clear_bitbuf
parameter_list|()
value|(valid = 0, bitbuf = 0)
end_define

begin_comment
comment|/* Local functions */
end_comment

begin_decl_stmt
name|local
name|void
name|read_tree
name|OF
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|local
name|void
name|build_tree
name|OF
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ===========================================================================  * Read the Huffman tree.  */
end_comment

begin_function
name|local
name|void
name|read_tree
parameter_list|()
block|{
name|int
name|len
decl_stmt|;
comment|/* bit length */
name|int
name|base
decl_stmt|;
comment|/* base offset for a sequence of leaves */
name|int
name|n
decl_stmt|;
comment|/* Read the original input size, MSB first */
name|orig_len
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|n
operator|=
literal|1
init|;
name|n
operator|<=
literal|4
condition|;
name|n
operator|++
control|)
name|orig_len
operator|=
operator|(
name|orig_len
operator|<<
literal|8
operator|)
operator||
operator|(
name|ulg
operator|)
name|get_byte
argument_list|()
expr_stmt|;
name|max_len
operator|=
operator|(
name|int
operator|)
name|get_byte
argument_list|()
expr_stmt|;
comment|/* maximum bit length of Huffman codes */
if|if
condition|(
name|max_len
operator|>
name|MAX_BITLEN
condition|)
block|{
name|error
argument_list|(
literal|"invalid compressed data -- Huffman code> 32 bits"
argument_list|)
expr_stmt|;
block|}
comment|/* Get the number of leaves at each bit length */
name|n
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|len
operator|=
literal|1
init|;
name|len
operator|<=
name|max_len
condition|;
name|len
operator|++
control|)
block|{
name|leaves
index|[
name|len
index|]
operator|=
operator|(
name|int
operator|)
name|get_byte
argument_list|()
expr_stmt|;
name|n
operator|+=
name|leaves
index|[
name|len
index|]
expr_stmt|;
block|}
if|if
condition|(
name|n
operator|>
name|LITERALS
condition|)
block|{
name|error
argument_list|(
literal|"too many leaves in Huffman tree"
argument_list|)
expr_stmt|;
block|}
name|Trace
argument_list|(
operator|(
name|stderr
operator|,
literal|"orig_len %ld, max_len %d, leaves %d\n"
operator|,
name|orig_len
operator|,
name|max_len
operator|,
name|n
operator|)
argument_list|)
expr_stmt|;
comment|/* There are at least 2 and at most 256 leaves of length max_len.      * (Pack arbitrarily rejects empty files and files consisting of      * a single byte even repeated.) To fit the last leaf count in a      * byte, it is offset by 2. However, the last literal is the EOB      * code, and is not transmitted explicitly in the tree, so we must      * adjust here by one only.      */
name|leaves
index|[
name|max_len
index|]
operator|++
expr_stmt|;
comment|/* Now read the leaves themselves */
name|base
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|len
operator|=
literal|1
init|;
name|len
operator|<=
name|max_len
condition|;
name|len
operator|++
control|)
block|{
comment|/* Remember where the literals of this length start in literal[] : */
name|lit_base
index|[
name|len
index|]
operator|=
name|base
expr_stmt|;
comment|/* And read the literals: */
for|for
control|(
name|n
operator|=
name|leaves
index|[
name|len
index|]
init|;
name|n
operator|>
literal|0
condition|;
name|n
operator|--
control|)
block|{
name|literal
index|[
name|base
operator|++
index|]
operator|=
operator|(
name|uch
operator|)
name|get_byte
argument_list|()
expr_stmt|;
block|}
block|}
name|leaves
index|[
name|max_len
index|]
operator|++
expr_stmt|;
comment|/* Now include the EOB code in the Huffman tree */
block|}
end_function

begin_comment
comment|/* ===========================================================================  * Build the Huffman tree and the prefix table.  */
end_comment

begin_function
name|local
name|void
name|build_tree
parameter_list|()
block|{
name|int
name|nodes
init|=
literal|0
decl_stmt|;
comment|/* number of nodes (parents+leaves) at current bit length */
name|int
name|len
decl_stmt|;
comment|/* current bit length */
name|uch
modifier|*
name|prefixp
decl_stmt|;
comment|/* pointer in prefix_len */
for|for
control|(
name|len
operator|=
name|max_len
init|;
name|len
operator|>=
literal|1
condition|;
name|len
operator|--
control|)
block|{
comment|/* The number of parent nodes at this level is half the total 	 * number of nodes at parent level: 	 */
name|nodes
operator|>>=
literal|1
expr_stmt|;
name|parents
index|[
name|len
index|]
operator|=
name|nodes
expr_stmt|;
comment|/* Update lit_base by the appropriate bias to skip the parent nodes 	 * (which are not represented in the literal array): 	 */
name|lit_base
index|[
name|len
index|]
operator|-=
name|nodes
expr_stmt|;
comment|/* Restore nodes to be parents+leaves: */
name|nodes
operator|+=
name|leaves
index|[
name|len
index|]
expr_stmt|;
block|}
comment|/* Construct the prefix table, from shortest leaves to longest ones.      * The shortest code is all ones, so we start at the end of the table.      */
name|peek_bits
operator|=
name|MIN
argument_list|(
name|max_len
argument_list|,
name|MAX_PEEK
argument_list|)
expr_stmt|;
name|prefixp
operator|=
operator|&
name|prefix_len
index|[
literal|1
operator|<<
name|peek_bits
index|]
expr_stmt|;
for|for
control|(
name|len
operator|=
literal|1
init|;
name|len
operator|<=
name|peek_bits
condition|;
name|len
operator|++
control|)
block|{
name|int
name|prefixes
init|=
name|leaves
index|[
name|len
index|]
operator|<<
operator|(
name|peek_bits
operator|-
name|len
operator|)
decl_stmt|;
comment|/* may be 0 */
while|while
condition|(
name|prefixes
operator|--
condition|)
operator|*
operator|--
name|prefixp
operator|=
operator|(
name|uch
operator|)
name|len
expr_stmt|;
block|}
comment|/* The length of all other codes is unknown: */
while|while
condition|(
name|prefixp
operator|>
name|prefix_len
condition|)
operator|*
operator|--
name|prefixp
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ===========================================================================  * Unpack in to out.  This routine does not support the old pack format  * with magic header \037\037.  *  * IN assertions: the buffer inbuf contains already the beginning of  *   the compressed data, from offsets inptr to insize-1 included.  *   The magic header has already been checked. The output buffer is cleared.  */
end_comment

begin_function
name|int
name|unpack
parameter_list|(
name|in
parameter_list|,
name|out
parameter_list|)
name|int
name|in
decl_stmt|,
name|out
decl_stmt|;
comment|/* input and output file descriptors */
block|{
name|int
name|len
decl_stmt|;
comment|/* Bit length of current code */
name|unsigned
name|eob
decl_stmt|;
comment|/* End Of Block code */
specifier|register
name|unsigned
name|peek
decl_stmt|;
comment|/* lookahead bits */
name|unsigned
name|peek_mask
decl_stmt|;
comment|/* Mask for peek_bits bits */
name|ifd
operator|=
name|in
expr_stmt|;
name|ofd
operator|=
name|out
expr_stmt|;
name|read_tree
argument_list|()
expr_stmt|;
comment|/* Read the Huffman tree */
name|build_tree
argument_list|()
expr_stmt|;
comment|/* Build the prefix table */
name|clear_bitbuf
argument_list|()
expr_stmt|;
comment|/* Initialize bit input */
name|peek_mask
operator|=
operator|(
literal|1
operator|<<
name|peek_bits
operator|)
operator|-
literal|1
expr_stmt|;
comment|/* The eob code is the largest code among all leaves of maximal length: */
name|eob
operator|=
name|leaves
index|[
name|max_len
index|]
operator|-
literal|1
expr_stmt|;
name|Trace
argument_list|(
operator|(
name|stderr
operator|,
literal|"eob %d %x\n"
operator|,
name|max_len
operator|,
name|eob
operator|)
argument_list|)
expr_stmt|;
comment|/* Decode the input data: */
for|for
control|(
init|;
condition|;
control|)
block|{
comment|/* Since eob is the longest code and not shorter than max_len,          * we can peek at max_len bits without having the risk of reading          * beyond the end of file. 	 */
name|look_bits
argument_list|(
name|peek
argument_list|,
name|peek_bits
argument_list|,
name|peek_mask
argument_list|)
expr_stmt|;
name|len
operator|=
name|prefix_len
index|[
name|peek
index|]
expr_stmt|;
if|if
condition|(
name|len
operator|>
literal|0
condition|)
block|{
name|peek
operator|>>=
name|peek_bits
operator|-
name|len
expr_stmt|;
comment|/* discard the extra bits */
block|}
else|else
block|{
comment|/* Code of more than peek_bits bits, we must traverse the tree */
name|ulg
name|mask
init|=
name|peek_mask
decl_stmt|;
name|len
operator|=
name|peek_bits
expr_stmt|;
do|do
block|{
name|len
operator|++
operator|,
name|mask
operator|=
operator|(
name|mask
operator|<<
literal|1
operator|)
operator|+
literal|1
expr_stmt|;
name|look_bits
argument_list|(
name|peek
argument_list|,
name|len
argument_list|,
name|mask
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|peek
operator|<
operator|(
name|unsigned
operator|)
name|parents
index|[
name|len
index|]
condition|)
do|;
comment|/* loop as long as peek is a parent node */
block|}
comment|/* At this point, peek is the next complete code, of len bits */
if|if
condition|(
name|peek
operator|==
name|eob
operator|&&
name|len
operator|==
name|max_len
condition|)
break|break;
comment|/* end of file? */
name|put_ubyte
argument_list|(
name|literal
index|[
name|peek
operator|+
name|lit_base
index|[
name|len
index|]
index|]
argument_list|)
expr_stmt|;
name|Tracev
argument_list|(
operator|(
name|stderr
operator|,
literal|"%02d %04x %c\n"
operator|,
name|len
operator|,
name|peek
operator|,
name|literal
index|[
name|peek
operator|+
name|lit_base
index|[
name|len
index|]
index|]
operator|)
argument_list|)
expr_stmt|;
name|skip_bits
argument_list|(
name|len
argument_list|)
expr_stmt|;
block|}
comment|/* for (;;) */
name|flush_window
argument_list|()
expr_stmt|;
name|Trace
argument_list|(
operator|(
name|stderr
operator|,
literal|"bytes_out %ld\n"
operator|,
name|bytes_out
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|orig_len
operator|!=
operator|(
name|ulg
operator|)
name|bytes_out
condition|)
block|{
name|error
argument_list|(
literal|"invalid compressed data--length error"
argument_list|)
expr_stmt|;
block|}
return|return
name|OK
return|;
block|}
end_function

end_unit

