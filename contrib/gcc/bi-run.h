begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Bytecode Interpreter.    Copyright (C) 1993, 1994 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|MAXLITERALS
value|5
end_define

begin_struct
struct|struct
name|arityvec
block|{
name|char
name|ninputs
decl_stmt|;
name|char
name|noutputs
decl_stmt|;
name|char
name|nliterals
decl_stmt|;
name|char
name|literals
index|[
name|MAXLITERALS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|argtype
block|{
name|int
name|modealign
decl_stmt|;
comment|/* Argument mode:alignment */
name|int
name|size
decl_stmt|;
comment|/* Argument size, in bytes */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|callinfo
block|{
name|int
name|nargs
decl_stmt|;
comment|/* Number of arguments in call */
name|struct
name|argtype
name|retvaltype
decl_stmt|;
comment|/* Type of return value */
name|struct
name|argtype
name|argtypes
index|[
literal|1
index|]
decl_stmt|;
comment|/* Argument types */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure describing a bytecode function.  If this changes, we also    need to change expand_function_end () in bc-trans.c  */
end_comment

begin_struct
struct|struct
name|bytecode
block|{
name|int
name|stacksize
decl_stmt|;
comment|/* Depth required of evaluation stack.  */
name|int
name|localsize
decl_stmt|;
comment|/* Size in bytes of local variables.  */
name|unsigned
name|char
modifier|*
name|pc0
decl_stmt|;
comment|/* Initial program counter. */
name|void
modifier|*
modifier|*
name|ptrlit
decl_stmt|;
comment|/* Vector of (relocatable) pointer literals. */
name|struct
name|callinfo
modifier|*
name|callinfo
decl_stmt|;
comment|/* Vector of procedure call type info. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INTERP_BPC
value|8
end_define

begin_comment
comment|/* Bits per char */
end_comment

begin_define
define|#
directive|define
name|INTERP_BPI
define|\
value|(sizeof (int) * INTERP_BPC)
end_define

begin_comment
comment|/* Bits per int */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|min
end_ifndef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|L
parameter_list|,
name|R
parameter_list|)
value|((L)< (R) ? (L) : (R))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bit field operations. */
end_comment

begin_comment
comment|/* Low (high) mask: int with low (high) N bits set */
end_comment

begin_define
define|#
directive|define
name|LM
parameter_list|(
name|N
parameter_list|)
value|((1<< (N)) - 1)
end_define

begin_define
define|#
directive|define
name|HM
parameter_list|(
name|N
parameter_list|)
value|((~LM (INTERP_BPI - (N))))
end_define

begin_comment
comment|/* Sign-extend SIZE low bits of VALUE to integer (typeof VALUE)    Signed bitfields are loaded from memory by the sxloadBI instruction,    which first retrieves the bitfield with XFIELD and then sign extends    it to an SItype. */
end_comment

begin_define
define|#
directive|define
name|EXTEND
parameter_list|(
name|SIZE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|({ SUtype value = (SUtype) (VALUE);					      \     (value& (1<< ((SIZE) - 1)) ? value | ~LM (SIZE) : value); })
end_define

begin_comment
comment|/* Given OFFSET:SIZE for  a bitfield, calculate:     [1] BYTE_OFFSET  = the byte offset of the bit field.    [2] BIT_OFFSET   = the bit offset of the bit field (less than INTERP_BPC).    [3] NBYTES       = the number of integral bytes in the bit field.    [4] TRAILING_BITS= the number of trailing bits (less than INTERP_BPC).      ,        ,        ,        ,        ,    (memory bytes)                     ----------------        (bitfield)    |        |       ||        |    |        (divisions)         ^         ^       ^      ^         |         |       |      |__ [4]  (bits)         |         |       |_________ [3]  (bytes)         |         |_________________ [2]  (bits)         |___________________________ [1]  (bytes)      The above applies to BYTE_LOW_ENDIAN machines. In BYTE_BIG_ENDIAN machines, the    bit numbering is reversed (i.e. bit 0 is the sign bit).     (All right, so I drew this to keep my tongue in cheek while writing the code below,     not because I'm into ASCII art.) */
end_comment

begin_define
define|#
directive|define
name|BI_PARAMS
parameter_list|(
name|OFFSET
parameter_list|,
name|SIZE
parameter_list|,
name|BYTE_OFFSET
parameter_list|,
name|BIT_OFFSET
parameter_list|,
name|NBYTES
parameter_list|,
name|TRAILING_BITS
parameter_list|)
define|\
value|{ BYTE_OFFSET = (OFFSET) / (INTERP_BPC);				\     BIT_OFFSET = (OFFSET) % (INTERP_BPC);				\     NBYTES = ((SIZE) - (INTERP_BPC - (BIT_OFFSET))) / INTERP_BPC;	\     if ((NBYTES)< 0 || ((NBYTES)> 64)) 				\       NBYTES = 0;				 			\     if ((SIZE) + (BIT_OFFSET)<= INTERP_BPC)				\       TRAILING_BITS = 0;						\     else								\       TRAILING_BITS = ((SIZE) - (INTERP_BPC - (BIT_OFFSET))) % INTERP_BPC; }
end_define

begin_comment
comment|/* SHIFT_IN_BITS retrieves NBITS bits from SOURCE and shifts into    DEST. The bit field starts OFFSET bits into SOURCE.     OR_IN_BITS copies the NBITS low bits from VALUE into a the bitfield in    DEST offset by OFFSET bits. */
end_comment

begin_define
define|#
directive|define
name|SHIFT_IN_BITS
parameter_list|(
name|DEST
parameter_list|,
name|SOURCE
parameter_list|,
name|OFFSET
parameter_list|,
name|NBITS
parameter_list|)
define|\
value|(DEST = ((DEST)<< (NBITS))					\    | (LM ((NBITS))						\& ((SOURCE)						\>> (BYTES_BIG_ENDIAN					\ 	     ? (INTERP_BPC - (OFFSET) - (NBITS))		\ 	     : (OFFSET)))))
end_define

begin_define
define|#
directive|define
name|OR_IN_BITS
parameter_list|(
name|DEST
parameter_list|,
name|VALUE
parameter_list|,
name|OFFSET
parameter_list|,
name|NBITS
parameter_list|)
define|\
value|(DEST = ((DEST)& ~(LM ((NBITS))				\<< (BIG_ENDIAN				\ 			  ? (INTERP_BPC - (OFFSET) - (NBITS))	\ 			  : (OFFSET)))				\    | (((VALUE)& LM ((NBITS)))					\<< (BIG_ENDIAN						\ 	  ? (INTERP_BPC - (OFFSET) - (NBITS))			\ 	  : (OFFSET)))))
end_define

begin_comment
comment|/* Procedure call; arguments are a pointer to the function to be called,    a pointer to a place to store the return value, a pointer to a vector    describing the type of procedure call, and the interpreter's stack pointer,    which will point to the first of the arguments at this point.  */
end_comment

begin_define
define|#
directive|define
name|CALL
parameter_list|(
name|FUNC
parameter_list|,
name|CALLDESC
parameter_list|,
name|RETVAL
parameter_list|,
name|SP
parameter_list|)
value|__call(FUNC, CALLDESC, RETVAL, SP)
end_define

begin_comment
comment|/* Procedure return; arguments are a pointer to the calldesc for this    function, and a pointer to the place where the value to be returned    may be found.  Generally the MACHARGS above contain a machine dependent    cookie that is used to determine where to jump to.  */
end_comment

begin_define
define|#
directive|define
name|PROCRET
parameter_list|(
name|CALLDESC
parameter_list|,
name|RETVAL
parameter_list|)
value|return
end_define

end_unit

