begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  *	@(#)machdep.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * hword_t is a 2-byte (`halfword') type, used for (eg) w, l, x commands;  * addr_t is address type, must be unsigned; registers pc, fp, sp  *	(where those exist) are assumed to be of this type, and  *	addresses in the debuggee are of this type;  * expr_t is expression result type, size must be>= size of addr_t and  *	reg_t; must be unsigned; it is treated as the fullword type  *	and should therefore be 4 bytes long;  * sexpr_t is a signed version of expr_t.  *  * SHOULD WORK ON ALLOWING (eg) 1 AND 2 BYTE, OR 4 AND 8 BYTE, ETC, WORDS  */
end_comment

begin_typedef
typedef|typedef
name|u_int
name|addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int
name|expr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|sexpr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|hword_t
typedef|;
end_typedef

begin_comment
comment|/*  * Since values of type addr_t, hword_t, and expr_t must be printed,  * and the varargs mechanism assumes that the programmer has accounted  * for any extension from `small' types (char, short) to `regular' types  * (int), we define the following macros.  Each is supposed to produce  * a (possibly sign-extended) expr_t value:  *  *	SH_ARG	a signed halfword (%d, %q formats)  *	UH_ARG	an unsigned halfword (o, u, x)  *	SF_ARG	a signed fullword (D, Q)   *	UF_ARG	an unsigned fullword (O, U, X)  */
end_comment

begin_define
define|#
directive|define
name|SH_ARG
value|(expr_t)(short)va_arg(ap, int)
end_define

begin_define
define|#
directive|define
name|UH_ARG
value|(expr_t)(unsigned short)va_arg(ap, int)
end_define

begin_define
define|#
directive|define
name|SF_ARG
value|(expr_t)va_arg(ap, int)
end_define

begin_define
define|#
directive|define
name|UF_ARG
value|(expr_t)va_arg(ap, int)
end_define

begin_comment
comment|/*  * bpt_t is used to hold original instructions when their breakpoint  * replacement(s) is/are set.  */
end_comment

begin_typedef
typedef|typedef
name|char
name|bpt_t
typedef|;
end_typedef

begin_comment
comment|/*  * ADDRESS_WRAP is a predicate that returns true if the two addr_t  * arguments are in different spaces.  */
end_comment

begin_define
define|#
directive|define
name|ADDRESS_WRAP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a) ^ (b))>> 30)
end_define

begin_comment
comment|/*  * Struct activation is used for tracing through stack frames.  * It must hold any information needed to locate an activation record  * (variables and parameters) for a function, and must have two fields  * of type addr_t called `a_pc' and `a_fp', the `program counter' and  * the `frame pointer'.  a_pc is used by the expression evaluator to  * find symbols; a_fp is returned as the result from an expression of  * the form `name.' (a routine name, but no local symbol).  * The field a_valid is cleared by a_prev() when there are no more  * activation records on the stack.  */
end_comment

begin_struct
struct|struct
name|activation
block|{
name|int
name|a_valid
decl_stmt|;
comment|/* set iff frame is valid */
name|addr_t
name|a_fp
decl_stmt|;
comment|/* fp */
name|addr_t
name|a_pc
decl_stmt|;
comment|/* pc */
block|}
struct|;
end_struct

begin_comment
comment|/*  * On the tahoe, the frame pointer of a `struct frame' points to the  * frame's fr_savfp field, not to the base address of the frame.  */
end_comment

begin_define
define|#
directive|define
name|FRAMEOFF
value|8
end_define

begin_comment
comment|/* (int)&fr.fr_savfp - (int)&fr */
end_comment

begin_comment
comment|/*  * The reglist structure holds information needed to set and examine  * registers.  It must contain an r_name field; this name must be unique  * across the register set, cannot be a single letter or digit, and  * cannot be a substring of any other register name.  *  * On the Tahoe, we keep an offset into the u. area, either from the  * base of the u. area (in the pcb), or, for those registers that  * are saved by syscalls, in the save area pointed to by u.u_ar0.  * Offsets into the latter region are negative.  *  * We also keep a pointer into the current pcb for use when debugging  * the kernel.  */
end_comment

begin_struct
struct|struct
name|reglist
block|{
name|char
modifier|*
name|r_name
decl_stmt|;
comment|/* name */
name|int
name|r_offset
decl_stmt|;
comment|/* offset into pcb, or from u.u_ar0 */
name|int
modifier|*
name|r_pcbaddr
decl_stmt|;
comment|/* if kcore, address in current pcb */
block|}
struct|;
end_struct

begin_comment
comment|/*  * ispace_reg() is true iff register r points into I-space (usually just PC).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|ispace_reg
parameter_list|(
name|r
parameter_list|)
value|((r) == NULL)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ispace_reg
parameter_list|(
name|r
parameter_list|)
value|0
end_define

begin_comment
comment|/* ispace==dspace on Tahoe */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * getpc() returns as an addr_t the current PC; setpc() sets PC to its  * addr_t argument.  entrypc() returns the addr_t value of the appropriate  * startup PC.  */
end_comment

begin_function_decl
name|addr_t
name|getpc
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|entrypc
parameter_list|()
value|((addr_t)0)
end_define

begin_comment
comment|/* ??? */
end_comment

begin_comment
comment|/*  * INSTACK is true when its argument is a stack address.  It is  * only used for consistency checking and may be overly permissive.  * INKERNEL is true iff its argument is a kernel space address.  */
end_comment

begin_define
define|#
directive|define
name|INSTACK
parameter_list|(
name|a
parameter_list|)
value|(((a)& 0xc0000000) == 0x80000000)
end_define

begin_comment
comment|/* p2 space */
end_comment

begin_define
define|#
directive|define
name|INKERNEL
parameter_list|(
name|a
parameter_list|)
value|(((a)& 0xc0000000) == 0xc0000000)
end_define

begin_comment
comment|/* sys space */
end_comment

end_unit

