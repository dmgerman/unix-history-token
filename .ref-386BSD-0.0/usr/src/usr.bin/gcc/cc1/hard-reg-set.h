begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Sets (bit vectors) of hard registers, and operations on them.    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GNU CC  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Define the type of a set of hard registers.  */
end_comment

begin_comment
comment|/* If HARD_REG_SET is a macro, its definition is a scalar type    that has enough bits for all the target machine's hard registers.    Otherwise, it is a typedef for a suitable array of longs,    and HARD_REG_SET_LONGS is how many.  */
end_comment

begin_if
if|#
directive|if
name|FIRST_PSEUDO_REGISTER
operator|<=
name|HOST_BITS_PER_CHAR
end_if

begin_define
define|#
directive|define
name|HARD_REG_SET
value|char
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
name|HOST_BITS_PER_SHORT
end_if

begin_define
define|#
directive|define
name|HARD_REG_SET
value|short
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
name|HOST_BITS_PER_INT
end_if

begin_define
define|#
directive|define
name|HARD_REG_SET
value|int
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
name|HOST_BITS_PER_LONG
end_if

begin_define
define|#
directive|define
name|HARD_REG_SET
value|long
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
value|((FIRST_PSEUDO_REGISTER + HOST_BITS_PER_LONG - 1) / HOST_BITS_PER_LONG)
end_define

begin_typedef
typedef|typedef
name|long
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
value|((SET) |= 1<< (BIT))
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
value|((SET)&= ~(1<< (BIT)))
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
value|((SET)& (1<< (BIT)))
end_define

begin_define
define|#
directive|define
name|CLEAR_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|)
value|((TO) = 0)
end_define

begin_define
define|#
directive|define
name|SET_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|)
value|((TO) = -1)
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
value|if (0 == ((X)& ~(Y))) goto TO
end_define

begin_else
else|#
directive|else
end_else

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
value|((SET)[(BIT) / HOST_BITS_PER_LONG] |= 1<< ((BIT) % HOST_BITS_PER_LONG))
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
value|((SET)[(BIT) / HOST_BITS_PER_LONG]&= ~(1<< ((BIT) % HOST_BITS_PER_LONG)))
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
value|((SET)[(BIT) / HOST_BITS_PER_LONG]& (1<< ((BIT) % HOST_BITS_PER_LONG)))
end_define

begin_define
define|#
directive|define
name|CLEAR_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|)
define|\
value|do { register long *scan_tp_ = (TO);				\      register int i;						\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        *scan_tp_++ = 0; } while (0)
end_define

begin_define
define|#
directive|define
name|SET_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|)
define|\
value|do { register long *scan_tp_ = (TO);				\      register int i;						\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        *scan_tp_++ = -1; } while (0)
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
value|do { register long *scan_tp_ = (TO), *scan_fp_ = (FROM);	\      register int i;						\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        *scan_tp_++ = *scan_fp_++; } while (0)
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
value|do { register long *scan_tp_ = (TO), *scan_fp_ = (FROM);	\      register int i;						\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        *scan_tp_++ = ~ *scan_fp_++; } while (0)
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
value|do { register long *scan_tp_ = (TO), *scan_fp_ = (FROM);	\      register int i;						\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        *scan_tp_++&= *scan_fp_++; } while (0)
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
value|do { register long *scan_tp_ = (TO), *scan_fp_ = (FROM);	\      register int i;						\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        *scan_tp_++&= ~ *scan_fp_++; } while (0)
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
value|do { register long *scan_tp_ = (TO), *scan_fp_ = (FROM);	\      register int i;						\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        *scan_tp_++ |= *scan_fp_++; } while (0)
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
value|do { register long *scan_tp_ = (TO), *scan_fp_ = (FROM);	\      register int i;						\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        *scan_tp_++ |= ~ *scan_fp_++; } while (0)
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
value|do { register long *scan_xp_ = (X), *scan_yp_ = (Y);		\      register int i;						\      for (i = 0; i< HARD_REG_SET_LONGS; i++)			\        if (0 != (*scan_xp_++& ~*scan_yp_++)) break;		\      if (i == HARD_REG_SET_LONGS) goto TO; } while (0)
end_define

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
comment|/* For each reg class, a HARD_REG_SET saying which registers are in it.  */
end_comment

begin_decl_stmt
specifier|extern
name|HARD_REG_SET
name|reg_class_contents
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For each reg class, number of regs it contains.  */
end_comment

begin_decl_stmt
specifier|extern
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

end_unit

