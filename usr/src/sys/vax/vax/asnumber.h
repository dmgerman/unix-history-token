begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)asnumber.h	5.1 (Berkeley) 4/30/85  */
end_comment

begin_union
union|union
name|Ib_int
block|{
comment|/* byte */
name|u_char
name|Ib_uchar
index|[
literal|1
index|]
decl_stmt|;
name|char
name|Ichar
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|Iw_int
block|{
comment|/* word */
name|u_char
name|Iw_uchar
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|Iw_ushort
index|[
literal|1
index|]
decl_stmt|;
name|short
name|Iw_short
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|Il_int
block|{
comment|/* long word */
name|u_char
name|Il_uchar
index|[
literal|4
index|]
decl_stmt|;
name|u_short
name|Il_ushort
index|[
literal|2
index|]
decl_stmt|;
name|u_int
name|Il_ulong
index|[
literal|1
index|]
decl_stmt|;
name|int
name|Il_long
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|Iq_int
block|{
comment|/* quad word */
name|u_char
name|Iq_uchar
index|[
literal|8
index|]
decl_stmt|;
name|u_short
name|Iq_ushort
index|[
literal|4
index|]
decl_stmt|;
name|u_int
name|Iq_ulong
index|[
literal|2
index|]
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|Io_int
block|{
comment|/* octal word */
name|u_char
name|Io_uchar
index|[
literal|16
index|]
decl_stmt|;
name|u_short
name|Io_ushort
index|[
literal|8
index|]
decl_stmt|;
name|u_int
name|Io_ulong
index|[
literal|4
index|]
decl_stmt|;
name|union
name|Iq_int
name|Io_quad
index|[
literal|2
index|]
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|Ff_float
block|{
name|u_char
name|Ff_uchar
index|[
literal|4
index|]
decl_stmt|;
name|u_short
name|Ff_ushort
index|[
literal|2
index|]
decl_stmt|;
name|u_int
name|Ff_ulong
index|[
literal|1
index|]
decl_stmt|;
name|float
name|Ff_value
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|Fd_float
block|{
name|u_char
name|Fd_uchar
index|[
literal|8
index|]
decl_stmt|;
name|u_short
name|Fd_ushort
index|[
literal|4
index|]
decl_stmt|;
name|u_int
name|Fd_ulong
index|[
literal|2
index|]
decl_stmt|;
name|double
name|Fd_value
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|Fg_float
block|{
name|u_char
name|Fg_uchar
index|[
literal|8
index|]
decl_stmt|;
name|u_short
name|Fg_ushort
index|[
literal|4
index|]
decl_stmt|;
name|u_int
name|Fg_ulong
index|[
literal|2
index|]
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|Fh_float
block|{
name|u_char
name|Fh_uchar
index|[
literal|16
index|]
decl_stmt|;
name|u_short
name|Fh_ushort
index|[
literal|8
index|]
decl_stmt|;
name|u_int
name|Fh_ulong
index|[
literal|4
index|]
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|as_number
block|{
union|union
block|{
name|union
name|Ib_int
name|numIb_int
decl_stmt|;
name|union
name|Iw_int
name|numIw_int
decl_stmt|;
name|union
name|Il_int
name|numIl_int
decl_stmt|;
name|union
name|Iq_int
name|numIq_int
decl_stmt|;
name|union
name|Io_int
name|numIo_int
decl_stmt|;
name|union
name|Ff_float
name|numFf_float
decl_stmt|;
name|union
name|Fd_float
name|numFd_float
decl_stmt|;
name|union
name|Fg_float
name|numFg_float
decl_stmt|;
name|union
name|Fh_float
name|numFh_float
decl_stmt|;
block|}
name|num_num
union|;
name|char
name|num_tag
decl_stmt|;
comment|/* the key field: TYPB..TYPUNPACKED */
name|char
name|num_sign
decl_stmt|;
comment|/* when unpacked, the sign */
name|short
name|num_exponent
decl_stmt|;
comment|/* when unpacked, the unexcessed exp */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|as_number
name|Bignum
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|Bignum
name|Znumber
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one all zero'ed out */
end_comment

begin_define
define|#
directive|define
name|num_uchar
value|num_num.numIq_int.Iq_uchar
end_define

begin_define
define|#
directive|define
name|num_uint
value|num_num.numIq_int.Iq_ulong
end_define

begin_define
define|#
directive|define
name|num_ulong
value|num_num.numIq_int.Iq_ulong
end_define

begin_define
define|#
directive|define
name|num_ushort
value|num_num.numIq_int.Iq_ushort
end_define

begin_comment
comment|/*  *	The following definitions must all be consistent.  *	They define the granularity of working on longs, quad and octal  *	words. Currently, the granularity is as large as it can be: 32 bits  *	in a chunk.  */
end_comment

begin_define
define|#
directive|define
name|CH_N
value|4
end_define

begin_comment
comment|/* number of pieces */
end_comment

begin_define
define|#
directive|define
name|CH_BITS
value|32
end_define

begin_comment
comment|/* number of bits per piece */
end_comment

begin_define
define|#
directive|define
name|CH_FIELD
parameter_list|(
name|x
parameter_list|)
value|((x).num_num.numIo_int.Io_ulong)
end_define

begin_typedef
typedef|typedef
name|u_int
modifier|*
name|chptr
typedef|;
end_typedef

begin_comment
comment|/* basic data type */
end_comment

begin_define
define|#
directive|define
name|SIGNBIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|HOC
value|(CH_N - 1)
end_define

begin_comment
comment|/* high order chunk */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|MAXINT_1
value|((unsigned)(1<<(CH_BITS - 1)))
end_define

begin_define
define|#
directive|define
name|MAXINT_10
value|((unsigned)((MAXINT_1/(unsigned)10)))
end_define

begin_define
define|#
directive|define
name|MAXINT_5
value|((unsigned)((MAXINT_1/(unsigned)5)))
end_define

begin_else
else|#
directive|else
else|not 0
end_else

begin_comment
comment|/*  *	These values were computed using dc, so are exact.  *	Only MAXINT_10 and MAXINT_5 are used in the programs.  */
end_comment

begin_define
define|#
directive|define
name|MAXINT_1
value|2147483648
end_define

begin_define
define|#
directive|define
name|MAXINT_10
value|214748364
end_define

begin_define
define|#
directive|define
name|MAXINT_5
value|429496729
end_define

begin_endif
endif|#
directive|endif
endif|not 0
end_endif

begin_function_decl
name|Bignum
name|as_atoi
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* converts string to integer */
end_comment

begin_function_decl
name|Bignum
name|as_atof
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* converts string to float */
end_comment

begin_function_decl
name|Bignum
name|bigatof
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* converts string to float */
end_comment

begin_function_decl
name|Bignum
name|floatconvert
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* converts amongst float #s */
end_comment

begin_function_decl
name|Bignum
name|intconvert
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* converts amongst float #s */
end_comment

begin_function_decl
name|Bignum
name|bignumconvert
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* converts amongst float #s */
end_comment

begin_function_decl
name|Bignum
name|bignumpack
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* converts UNPACKED bignum to bignum */
end_comment

begin_function_decl
name|Bignum
name|bignumunpack
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* converts bignum to UNPACKED bignum */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  *	Definitions for overflows.  */
end_comment

begin_typedef
typedef|typedef
name|u_int
name|Ovf
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OVF_ADDV
value|(1<<0)
end_define

begin_comment
comment|/* integer: adding two vectors overflowed */
end_comment

begin_define
define|#
directive|define
name|OVF_LSHIFT
value|(1<<1)
end_define

begin_comment
comment|/* integer: left shifting a vector lost bits */
end_comment

begin_define
define|#
directive|define
name|OVF_POSOVF
value|(1<<2)
end_define

begin_comment
comment|/* integer: positive number overflowed */
end_comment

begin_define
define|#
directive|define
name|OVF_MAXINT
value|(1<<3)
end_define

begin_comment
comment|/* integer: the number was the maxint + 1*/
end_comment

begin_define
define|#
directive|define
name|OVF_F
value|(1<<4)
end_define

begin_comment
comment|/* float: F overflow */
end_comment

begin_define
define|#
directive|define
name|OVF_D
value|(1<<5)
end_define

begin_comment
comment|/* float: D overflow */
end_comment

begin_define
define|#
directive|define
name|OVF_G
value|(1<<6)
end_define

begin_comment
comment|/* float: G overflow */
end_comment

begin_define
define|#
directive|define
name|OVF_H
value|(1<<7)
end_define

begin_comment
comment|/* float: H overflow */
end_comment

begin_define
define|#
directive|define
name|OVF_OVERFLOW
value|(1<<9)
end_define

begin_comment
comment|/* overflow in conversion */
end_comment

begin_define
define|#
directive|define
name|OVF_UNDERFLOW
value|(1<<10)
end_define

begin_comment
comment|/* underflow in conversion */
end_comment

begin_function_decl
name|Ovf
name|posovf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Ovf
name|numclear
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Ovf
name|numshift
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Ovf
name|numaddv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Ovf
name|numaddd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Ovf
name|num1comp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Ovf
name|numnegate
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/*  *	Definitions to unpack big numbers numbers into  *	a 128 bit fraction and 16 bit excess-free exponent,  *	and an 8 copy bits for the sign.  *  *	The fraction is represented as a normalized binary number,  *	128 bits long, with the binary point between bits 127 and the  *	hypothetical 128'th bit.  This hypothetical 128'th bit  *	is always assumed to be one.  */
end_comment

begin_comment
comment|/*  *	A map entry is NOTAKE if the corresponding byte is  *	not to be taken  *  *	The maps are for going from packed to unpacked format (b_up)  *	and from unpacked to packed format (b_p)  *	for the mantissa (b_upmmap) and for the exponent(b_upemap)  *  *	byte #i in the packed number goes to byte #b_upmmap[i] in the unpacked  */
end_comment

begin_define
define|#
directive|define
name|NOTAKE
value|-1
end_define

begin_struct
struct|struct
name|ty_bigdesc
block|{
name|char
name|b_upmmap
index|[
literal|16
index|]
decl_stmt|;
comment|/* byte x of float goes to up_mmap[x] in mant */
name|char
name|b_pmmap
index|[
literal|16
index|]
decl_stmt|;
comment|/* inverse of upmmap */
name|char
name|b_upemap
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte x of float goes to up_emap[x] in exp */
name|char
name|b_pemap
index|[
literal|2
index|]
decl_stmt|;
comment|/* inverse of upemap */
name|char
name|b_mlshift
decl_stmt|;
comment|/* left shift quantity to justify to left */
name|char
name|b_ershift
decl_stmt|;
comment|/* right shift quantity to r justify exponent */
name|short
name|b_msigbits
decl_stmt|;
comment|/* # sig bits in mantissa */
name|char
name|b_esigbits
decl_stmt|;
comment|/* # sig bits in exponent */
name|short
name|b_eexcess
decl_stmt|;
comment|/* exponent excess */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ty_bigdesc
name|ty_bigdesc
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Bit manipulations  */
end_comment

begin_define
define|#
directive|define
name|ONES
parameter_list|(
name|n
parameter_list|)
value|((1<< (n)) - 1)
end_define

begin_comment
comment|/*  *	Assertions  */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|x
parameter_list|,
name|str
parameter_list|)
value|if (!(x)) panic("%s%s\n", "x", str)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|x
parameter_list|,
name|str
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

