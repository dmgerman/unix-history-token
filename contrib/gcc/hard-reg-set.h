begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Sets (bit vectors) of hard registers, and operations on them.    Copyright (C) 1987, 1992, 1994, 2000 Free Software Foundation, Inc.  This file is part of GCC  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_HARD_REG_SET_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_HARD_REG_SET_H
end_define

begin_comment
comment|/* Define the type of a set of hard registers.  */
end_comment

begin_comment
comment|/* HARD_REG_ELT_TYPE is a typedef of the unsigned integral type which    will be used for hard reg sets, either alone or in an array.     If HARD_REG_SET is a macro, its definition is HARD_REG_ELT_TYPE,    and it has enough bits to represent all the target machine's hard    registers.  Otherwise, it is a typedef for a suitably sized array    of HARD_REG_ELT_TYPEs.  HARD_REG_SET_LONGS is defined as how many.     Note that lots of code assumes that the first part of a regset is    the same format as a HARD_REG_SET.  To help make sure this is true,    we only try the widest integer mode (HOST_WIDE_INT) instead of all the    smaller types.  This approach loses only if there are a very few    registers and then only in the few cases where we have an array of    HARD_REG_SETs, so it needn't be as complex as it used to be.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|HOST_WIDE_INT
name|HARD_REG_ELT_TYPE
typedef|;
end_typedef

begin_if
if|#
directive|if
name|FIRST_PSEUDO_REGISTER
operator|<=
name|HOST_BITS_PER_WIDE_INT
end_if

begin_define
define|#
directive|define
name|HARD_REG_SET
value|HARD_REG_ELT_TYPE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HARD_REG_SET_LONGS
define|\
value|((FIRST_PSEUDO_REGISTER + HOST_BITS_PER_WIDE_INT - 1)	\   / HOST_BITS_PER_WIDE_INT)
end_define

begin_typedef
typedef|typedef
name|HARD_REG_ELT_TYPE
name|HARD_REG_SET
index|[
name|HARD_REG_SET_LONGS
index|]
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HARD_CONST is used to cast a constant to the appropriate type    for use with a HARD_REG_SET.  */
end_comment

begin_define
define|#
directive|define
name|HARD_CONST
parameter_list|(
name|X
parameter_list|)
value|((HARD_REG_ELT_TYPE) (X))
end_define

begin_comment
comment|/* Define macros SET_HARD_REG_BIT, CLEAR_HARD_REG_BIT and TEST_HARD_REG_BIT    to set, clear or test one bit in a hard reg set of type HARD_REG_SET.    All three take two arguments: the set and the register number.     In the case where sets are arrays of longs, the first argument    is actually a pointer to a long.     Define two macros for initializing a set:    CLEAR_HARD_REG_SET and SET_HARD_REG_SET.    These take just one argument.     Also define macros for copying hard reg sets:    COPY_HARD_REG_SET and COMPL_HARD_REG_SET.    These take two arguments TO and FROM; they read from FROM    and store into TO.  COMPL_HARD_REG_SET complements each bit.     Also define macros for combining hard reg sets:    IOR_HARD_REG_SET and AND_HARD_REG_SET.    These take two arguments TO and FROM; they read from FROM    and combine bitwise into TO.  Define also two variants    IOR_COMPL_HARD_REG_SET and AND_COMPL_HARD_REG_SET    which use the complement of the set FROM.     Also define GO_IF_HARD_REG_SUBSET (X, Y, TO):    if X is a subset of Y, go to TO. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HARD_REG_SET
end_ifdef

begin_define
define|#
directive|define
name|SET_HARD_REG_BIT
parameter_list|(
name|SET
parameter_list|,
name|BIT
parameter_list|)
define|\
value|((SET) |= HARD_CONST (1)<< (BIT))
end_define

begin_define
define|#
directive|define
name|CLEAR_HARD_REG_BIT
parameter_list|(
name|SET
parameter_list|,
name|BIT
parameter_list|)
define|\
value|((SET)&= ~(HARD_CONST (1)<< (BIT)))
end_define

begin_define
define|#
directive|define
name|TEST_HARD_REG_BIT
parameter_list|(
name|SET
parameter_list|,
name|BIT
parameter_list|)
define|\
value|((SET)& (HARD_CONST (1)<< (BIT)))
end_define

begin_define
define|#
directive|define
name|CLEAR_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|)
value|((TO) = HARD_CONST (0))
end_define

begin_define
define|#
directive|define
name|SET_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|)
value|((TO) = ~ HARD_CONST (0))
end_define

begin_define
define|#
directive|define
name|COPY_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
value|((TO) = (FROM))
end_define

begin_define
define|#
directive|define
name|COMPL_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
value|((TO) = ~(FROM))
end_define

begin_define
define|#
directive|define
name|IOR_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
value|((TO) |= (FROM))
end_define

begin_define
define|#
directive|define
name|IOR_COMPL_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
value|((TO) |= ~ (FROM))
end_define

begin_define
define|#
directive|define
name|AND_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
value|((TO)&= (FROM))
end_define

begin_define
define|#
directive|define
name|AND_COMPL_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
value|((TO)&= ~ (FROM))
end_define

begin_define
define|#
directive|define
name|GO_IF_HARD_REG_SUBSET
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|TO
parameter_list|)
value|if (HARD_CONST (0) == ((X)& ~(Y))) goto TO
end_define

begin_define
define|#
directive|define
name|GO_IF_HARD_REG_EQUAL
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|TO
parameter_list|)
value|if ((X) == (Y)) goto TO
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UHOST_BITS_PER_WIDE_INT
value|((unsigned) HOST_BITS_PER_WIDE_INT)
end_define

begin_define
define|#
directive|define
name|SET_HARD_REG_BIT
parameter_list|(
name|SET
parameter_list|,
name|BIT
parameter_list|)
define|\
value|((SET)[(BIT) / UHOST_BITS_PER_WIDE_INT]	\    |= HARD_CONST (1)<< ((BIT) % UHOST_BITS_PER_WIDE_INT))
end_define

begin_define
define|#
directive|define
name|CLEAR_HARD_REG_BIT
parameter_list|(
name|SET
parameter_list|,
name|BIT
parameter_list|)
define|\
value|((SET)[(BIT) / UHOST_BITS_PER_WIDE_INT]	\&= ~(HARD_CONST (1)<< ((BIT) % UHOST_BITS_PER_WIDE_INT)))
end_define

begin_define
define|#
directive|define
name|TEST_HARD_REG_BIT
parameter_list|(
name|SET
parameter_list|,
name|BIT
parameter_list|)
define|\
value|((SET)[(BIT) / UHOST_BITS_PER_WIDE_INT]	\& (HARD_CONST (1)<< ((BIT) % UHOST_BITS_PER_WIDE_INT)))
end_define

begin_if
if|#
directive|if
name|FIRST_PSEUDO_REGISTER
operator|<=
literal|2
operator|*
name|HOST_BITS_PER_WIDE_INT
end_if

begin_define
define|#
directive|define
name|CLEAR_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO);			\      scan_tp_[0] = 0;						\      scan_tp_[1] = 0; } while (0)
end_define

begin_define
define|#
directive|define
name|SET_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO);			\      scan_tp_[0] = -1;						\      scan_tp_[1] = -1; } while (0)
end_define

begin_define
define|#
directive|define
name|COPY_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM);	\      scan_tp_[0] = scan_fp_[0];					\      scan_tp_[1] = scan_fp_[1]; } while (0)
end_define

begin_define
define|#
directive|define
name|COMPL_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      scan_tp_[0] = ~ scan_fp_[0];				\      scan_tp_[1] = ~ scan_fp_[1]; } while (0)
end_define

begin_define
define|#
directive|define
name|AND_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      scan_tp_[0]&= scan_fp_[0];				\      scan_tp_[1]&= scan_fp_[1]; } while (0)
end_define

begin_define
define|#
directive|define
name|AND_COMPL_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      scan_tp_[0]&= ~ scan_fp_[0];				\      scan_tp_[1]&= ~ scan_fp_[1]; } while (0)
end_define

begin_define
define|#
directive|define
name|IOR_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      scan_tp_[0] |= scan_fp_[0];				\      scan_tp_[1] |= scan_fp_[1]; } while (0)
end_define

begin_define
define|#
directive|define
name|IOR_COMPL_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      scan_tp_[0] |= ~ scan_fp_[0];				\      scan_tp_[1] |= ~ scan_fp_[1]; } while (0)
end_define

begin_define
define|#
directive|define
name|GO_IF_HARD_REG_SUBSET
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|TO
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_xp_ = (X), *scan_yp_ = (Y); 	\      if ((0 == (scan_xp_[0]& ~ scan_yp_[0]))			\&& (0 == (scan_xp_[1]& ~ scan_yp_[1])))		\ 	goto TO; } while (0)
end_define

begin_define
define|#
directive|define
name|GO_IF_HARD_REG_EQUAL
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|TO
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_xp_ = (X), *scan_yp_ = (Y); 	\      if ((scan_xp_[0] == scan_yp_[0])				\&& (scan_xp_[1] == scan_yp_[1]))			\ 	goto TO; } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|FIRST_PSEUDO_REGISTER
operator|<=
literal|3
operator|*
name|HOST_BITS_PER_WIDE_INT
end_if

begin_define
define|#
directive|define
name|CLEAR_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO);			\      scan_tp_[0] = 0;						\      scan_tp_[1] = 0;						\      scan_tp_[2] = 0; } while (0)
end_define

begin_define
define|#
directive|define
name|SET_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO);			\      scan_tp_[0] = -1;						\      scan_tp_[1] = -1;						\      scan_tp_[2] = -1; } while (0)
end_define

begin_define
define|#
directive|define
name|COPY_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM);	\      scan_tp_[0] = scan_fp_[0];					\      scan_tp_[1] = scan_fp_[1];					\      scan_tp_[2] = scan_fp_[2]; } while (0)
end_define

begin_define
define|#
directive|define
name|COMPL_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      scan_tp_[0] = ~ scan_fp_[0];				\      scan_tp_[1] = ~ scan_fp_[1];				\      scan_tp_[2] = ~ scan_fp_[2]; } while (0)
end_define

begin_define
define|#
directive|define
name|AND_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      scan_tp_[0]&= scan_fp_[0];				\      scan_tp_[1]&= scan_fp_[1];				\      scan_tp_[2]&= scan_fp_[2]; } while (0)
end_define

begin_define
define|#
directive|define
name|AND_COMPL_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      scan_tp_[0]&= ~ scan_fp_[0];				\      scan_tp_[1]&= ~ scan_fp_[1];				\      scan_tp_[2]&= ~ scan_fp_[2]; } while (0)
end_define

begin_define
define|#
directive|define
name|IOR_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      scan_tp_[0] |= scan_fp_[0];				\      scan_tp_[1] |= scan_fp_[1];				\      scan_tp_[2] |= scan_fp_[2]; } while (0)
end_define

begin_define
define|#
directive|define
name|IOR_COMPL_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      scan_tp_[0] |= ~ scan_fp_[0];				\      scan_tp_[1] |= ~ scan_fp_[1];				\      scan_tp_[2] |= ~ scan_fp_[2]; } while (0)
end_define

begin_define
define|#
directive|define
name|GO_IF_HARD_REG_SUBSET
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|TO
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_xp_ = (X), *scan_yp_ = (Y); 	\      if ((0 == (scan_xp_[0]& ~ scan_yp_[0]))			\&& (0 == (scan_xp_[1]& ~ scan_yp_[1]))		\&& (0 == (scan_xp_[2]& ~ scan_yp_[2])))		\ 	goto TO; } while (0)
end_define

begin_define
define|#
directive|define
name|GO_IF_HARD_REG_EQUAL
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|TO
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_xp_ = (X), *scan_yp_ = (Y); 	\      if ((scan_xp_[0] == scan_yp_[0])				\&& (scan_xp_[1] == scan_yp_[1])			\&& (scan_xp_[2] == scan_yp_[2]))			\ 	goto TO; } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|FIRST_PSEUDO_REGISTER
operator|<=
literal|4
operator|*
name|HOST_BITS_PER_WIDE_INT
end_if

begin_define
define|#
directive|define
name|CLEAR_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO);			\      scan_tp_[0] = 0;						\      scan_tp_[1] = 0;						\      scan_tp_[2] = 0;						\      scan_tp_[3] = 0; } while (0)
end_define

begin_define
define|#
directive|define
name|SET_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO);			\      scan_tp_[0] = -1;						\      scan_tp_[1] = -1;						\      scan_tp_[2] = -1;						\      scan_tp_[3] = -1; } while (0)
end_define

begin_define
define|#
directive|define
name|COPY_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM);	\      scan_tp_[0] = scan_fp_[0];					\      scan_tp_[1] = scan_fp_[1];					\      scan_tp_[2] = scan_fp_[2];					\      scan_tp_[3] = scan_fp_[3]; } while (0)
end_define

begin_define
define|#
directive|define
name|COMPL_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      scan_tp_[0] = ~ scan_fp_[0];				\      scan_tp_[1] = ~ scan_fp_[1];				\      scan_tp_[2] = ~ scan_fp_[2];				\      scan_tp_[3] = ~ scan_fp_[3]; } while (0)
end_define

begin_define
define|#
directive|define
name|AND_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      scan_tp_[0]&= scan_fp_[0];				\      scan_tp_[1]&= scan_fp_[1];				\      scan_tp_[2]&= scan_fp_[2];				\      scan_tp_[3]&= scan_fp_[3]; } while (0)
end_define

begin_define
define|#
directive|define
name|AND_COMPL_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      scan_tp_[0]&= ~ scan_fp_[0];				\      scan_tp_[1]&= ~ scan_fp_[1];				\      scan_tp_[2]&= ~ scan_fp_[2];				\      scan_tp_[3]&= ~ scan_fp_[3]; } while (0)
end_define

begin_define
define|#
directive|define
name|IOR_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      scan_tp_[0] |= scan_fp_[0];				\      scan_tp_[1] |= scan_fp_[1];				\      scan_tp_[2] |= scan_fp_[2];				\      scan_tp_[3] |= scan_fp_[3]; } while (0)
end_define

begin_define
define|#
directive|define
name|IOR_COMPL_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      scan_tp_[0] |= ~ scan_fp_[0];				\      scan_tp_[1] |= ~ scan_fp_[1];				\      scan_tp_[2] |= ~ scan_fp_[2];				\      scan_tp_[3] |= ~ scan_fp_[3]; } while (0)
end_define

begin_define
define|#
directive|define
name|GO_IF_HARD_REG_SUBSET
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|TO
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_xp_ = (X), *scan_yp_ = (Y); 	\      if ((0 == (scan_xp_[0]& ~ scan_yp_[0]))			\&& (0 == (scan_xp_[1]& ~ scan_yp_[1]))		\&& (0 == (scan_xp_[2]& ~ scan_yp_[2]))		\&& (0 == (scan_xp_[3]& ~ scan_yp_[3])))		\ 	goto TO; } while (0)
end_define

begin_define
define|#
directive|define
name|GO_IF_HARD_REG_EQUAL
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|TO
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_xp_ = (X), *scan_yp_ = (Y); 	\      if ((scan_xp_[0] == scan_yp_[0])				\&& (scan_xp_[1] == scan_yp_[1])			\&& (scan_xp_[2] == scan_yp_[2])			\&& (scan_xp_[3] == scan_yp_[3]))			\ 	goto TO; } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FIRST_PSEUDO_REGISTER> 3*HOST_BITS_PER_WIDE_INT */
end_comment

begin_define
define|#
directive|define
name|CLEAR_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO);			\      int i;							\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        *scan_tp_++ = 0; } while (0)
end_define

begin_define
define|#
directive|define
name|SET_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO);			\      int i;							\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        *scan_tp_++ = -1; } while (0)
end_define

begin_define
define|#
directive|define
name|COPY_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      int i;							\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        *scan_tp_++ = *scan_fp_++; } while (0)
end_define

begin_define
define|#
directive|define
name|COMPL_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      int i;							\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        *scan_tp_++ = ~ *scan_fp_++; } while (0)
end_define

begin_define
define|#
directive|define
name|AND_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      int i;							\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        *scan_tp_++&= *scan_fp_++; } while (0)
end_define

begin_define
define|#
directive|define
name|AND_COMPL_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      int i;							\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        *scan_tp_++&= ~ *scan_fp_++; } while (0)
end_define

begin_define
define|#
directive|define
name|IOR_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      int i;							\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        *scan_tp_++ |= *scan_fp_++; } while (0)
end_define

begin_define
define|#
directive|define
name|IOR_COMPL_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_tp_ = (TO), *scan_fp_ = (FROM); 	\      int i;							\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        *scan_tp_++ |= ~ *scan_fp_++; } while (0)
end_define

begin_define
define|#
directive|define
name|GO_IF_HARD_REG_SUBSET
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|TO
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_xp_ = (X), *scan_yp_ = (Y); 	\      int i;							\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        if (0 != (*scan_xp_++& ~ *scan_yp_++)) break;		\      if (i == HARD_REG_SET_LONGS) goto TO; } while (0)
end_define

begin_define
define|#
directive|define
name|GO_IF_HARD_REG_EQUAL
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|TO
parameter_list|)
define|\
value|do { HARD_REG_ELT_TYPE *scan_xp_ = (X), *scan_yp_ = (Y); 	\      int i;							\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        if (*scan_xp_++ != *scan_yp_++) break;			\      if (i == HARD_REG_SET_LONGS) goto TO; } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define some standard sets of registers.  */
end_comment

begin_comment
comment|/* Indexed by hard register number, contains 1 for registers    that are fixed use (stack pointer, pc, frame pointer, etc.).    These are the registers that cannot be used to allocate    a pseudo reg whose life does not cross calls.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|fixed_regs
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The same info as a HARD_REG_SET.  */
end_comment

begin_decl_stmt
specifier|extern
name|HARD_REG_SET
name|fixed_reg_set
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indexed by hard register number, contains 1 for registers    that are fixed use or are clobbered by function calls.    These are the registers that cannot be used to allocate    a pseudo reg whose life crosses calls.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|call_used_regs
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The same info as a HARD_REG_SET.  */
end_comment

begin_decl_stmt
specifier|extern
name|HARD_REG_SET
name|call_used_reg_set
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Registers that we don't want to caller save.  */
end_comment

begin_decl_stmt
specifier|extern
name|HARD_REG_SET
name|losing_caller_save_reg_set
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indexed by hard register number, contains 1 for registers that are    fixed use -- i.e. in fixed_regs -- or a function value return register    or STRUCT_VALUE_REGNUM or STATIC_CHAIN_REGNUM.  These are the    registers that cannot hold quantities across calls even if we are    willing to save and restore them.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|call_fixed_regs
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The same info as a HARD_REG_SET.  */
end_comment

begin_decl_stmt
specifier|extern
name|HARD_REG_SET
name|call_fixed_reg_set
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indexed by hard register number, contains 1 for registers    that are being used for global register decls.    These must be exempt from ordinary flow analysis    and are also considered fixed.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|global_regs
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Contains 1 for registers that are set or clobbered by calls.  */
end_comment

begin_comment
comment|/* ??? Ideally, this would be just call_used_regs plus global_regs, but    for someone's bright idea to have call_used_regs strictly include    fixed_regs.  Which leaves us guessing as to the set of fixed_regs    that are actually preserved.  We know for sure that those associated    with the local stack frame are safe, but scant others.  */
end_comment

begin_decl_stmt
specifier|extern
name|HARD_REG_SET
name|regs_invalidated_by_call
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|REG_ALLOC_ORDER
end_ifdef

begin_comment
comment|/* Table of register numbers in the order in which to try to use them.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|reg_alloc_order
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The inverse of reg_alloc_order.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inv_reg_alloc_order
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For each reg class, a HARD_REG_SET saying which registers are in it.  */
end_comment

begin_decl_stmt
specifier|extern
name|HARD_REG_SET
name|reg_class_contents
index|[
name|N_REG_CLASSES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For each reg class, number of regs it contains.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|reg_class_size
index|[
name|N_REG_CLASSES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For each reg class, table listing all the containing classes.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
name|reg_class_superclasses
index|[
name|N_REG_CLASSES
index|]
index|[
name|N_REG_CLASSES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For each reg class, table listing all the classes contained in it.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
name|reg_class_subclasses
index|[
name|N_REG_CLASSES
index|]
index|[
name|N_REG_CLASSES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For each pair of reg classes,    a largest reg class contained in their union.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
name|reg_class_subunion
index|[
name|N_REG_CLASSES
index|]
index|[
name|N_REG_CLASSES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For each pair of reg classes,    the smallest reg class that contains their union.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
name|reg_class_superunion
index|[
name|N_REG_CLASSES
index|]
index|[
name|N_REG_CLASSES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of non-fixed registers.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|n_non_fixed_regs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Vector indexed by hardware reg giving its name.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|reg_names
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_HARD_REG_SET_H */
end_comment

end_unit

